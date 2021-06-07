import React, {Component} from 'react';
import FilterableDataTable from 'FilterableDataTable';
import Modal from './Modal';

/**
 * Module designed for Bob McKinstry to simplify data entry for Final Radiological Form. The module lists all candidates
 * who have obtained either a T1 or T2 scan and do not have any data imputed for the Final Radiological From. The table
 * is an inline form to simplify data entry for normal based scans, prompting for more data entry via a popup when not
 * normal. This module will make calls to automatically input the data taken as well as the examiner. It will also
 * prompt for the examiner to complete the form which will call to mark the form as complete, removing it from the list.
 */
class Bobdule extends Component {
  constructor(props) {
    super(props);

    this.state = {
      data: [],
      visitOptions: {},
      error: false,
      isLoaded: false,
      formURL: '',
    };

    this.fetchData = this.fetchData.bind(this);
    this.handleData = this.handleData.bind(this);
    this.formatColumn = this.formatColumn.bind(this);
    this.updateRating = this.updateRating.bind(this);
    this.actionClick = this.actionClick.bind(this);
    this.closeModal = this.closeModal.bind(this);
  }

  componentDidMount() {
    this.fetchData();
  }

  /**
   * Call to retrieve all none complete Final Radiological Forms where the candidate has either a T1 or T2 scan.
   */
  fetchData() {
    fetch(`${loris.BaseURL}/bobdule/?format=json`, {credentials: 'same-origin'})
      .then((resp) => resp.json())
      .then((data) => this.handleData(data.Data))
      .catch((error) => {
        this.setState({error: true});
        console.error(error);
      });
  }

  /**
   * Map the received data and store it in the state.
   *
   * @param {object} data the data received from the api
   */
  handleData(data) {
    const visitOptions = {};
    const formatted = data.map((row, i) => {
      // Create a list of all possible visits to be used by visit filter dropdown.
      if (!visitOptions[row[4]]) {
        visitOptions[row[4]] = row[4];
      }

      // First 8 row items are 1 to 1 mapping, store them in new array.
      const formattedRow = row.splice(0, 7);
      formattedRow[5] = formattedRow[6] ? formattedRow[5] : 'no';
      formattedRow[6] = formattedRow[6] ? formattedRow[6] : 'no';

      // Map the remaining rows related to the scan rating, storing them as a single JSON string to use at render.
      const rating = {
        'normal': {
          'value': row[0] ? row[0] : 'no',
          'comment': '',
        },
        'atypical': {
          'value': row[1] ? row[1] : 'no',
          'comment': '',
        },
        'abnormal': {
          'value': row[2] ? row[2] : 'no',
          'comment': '',
        },
      };
      formattedRow.push(JSON.stringify(rating));
      formattedRow.push(i);
      return formattedRow;
    });
    this.setState({
      data: formatted,
      visitOptions: visitOptions,
    });
  }

  /**
   * Update the stored state for the modify rating.
   *
   * @param {object} event  the event triggered
   * @param {int} index     the row index in the table
   * @param {boolean} check whether or not the value is for the checkbox or comment
   */
  updateRating(event, index, check) {
    const target = event.target;
    const value = target.checked;
    const name = check ? target.name : target.name.split('_')[0];

    this.setState((state) => {
      const data = state.data;
      const ratings = JSON.parse(data[index][7]);
      if (check) {
        ratings[name].value = value ? 'yes' : 'no';
      } else {
        ratings[name].comment = target.value;
      }
      data[index][7] = JSON.stringify(ratings);
      state.data = data;
      return state;
    });
  }

  /**
   * Row action clicked, handle it based on action type.
   *
   * @param {string} type the action type
   * @param {object} row  the row data
   */
  actionClick(type, row) {
    const url = `${loris.BaseURL}/instruments/final_radiological_review_VSA/?commentID=${row['CommentID']}&sessionID=${row['SessionID']}&candID=${row['Candidate ID']}`;
    if (type === 'Launch Form' || type === 'Save and Complete') {
      const rating = JSON.parse(row['Rating']);

      const formData = new FormData();
      formData.append('Date_taken', new Date().toLocaleDateString('en-CA'));
      formData.append('reviewed', 'Bob McKinstry ');
      formData.append('clinical_mri', row['Recommend Referral for Clinical MRI']);
      formData.append('clinical_follow', row['Recommend Clinical Follow up']);
      formData.append('subtest_1_1_check', rating['normal'].value);
      formData.append('subtest_1_1_comment', rating['normal'].comment);
      formData.append('subtest_1_2_check', rating['atypical'].value);
      formData.append('subtest_1_2_comment', rating['atypical'].comment);
      formData.append('subtest_1_3_check', rating['abnormal'].value);
      formData.append('subtest_1_3_comment', rating['abnormal'].comment);
      formData.append('candID', row['Candidate ID']);
      formData.append('sessionID', row['SessionID']);
      formData.append('commentID', row['CommentID']);
      formData.append('test_name', 'final_radiological_review_VSA');
      formData.append('page', '');
      formData.append('subtest', '');
      formData.append('fire_away', 'Save Data');

      // Save the current inputted data.
      const post = fetch(url, {
        credentials: 'same-origin',
        method: 'post',
        body: formData,
      }).catch((error) => {
          this.setState({error: true});
          console.error(error);
        });

      if (type === 'Launch Form') {
        // If action is launch form, launch the form.
        post.then(() => {
          this.setState({
            formURL: url,
          });
        });
      } else {
        // Else mark the data as complete.
        post.then(() => this.markComplete(row));
      }
    } else if (type === 'Mark Complete') {
      this.markComplete(row);
    }
  }

  /**
   * Call to mark the row data as complete.
   *
   * @param {object} row the row data.
   */
  markComplete(row) {
    const formData = new FormData();
    formData.append('candID', row['Candidate ID']);
    formData.append('sessionID', row['SessionID']);
    formData.append('commentID', row['CommentID']);
    formData.append('test_name', 'final_radiological_review_VSA');
    formData.append('setAdministration', 'All');
    formData.append('setValidity', 'Valid');
    formData.append('setDataEntry', 'Complete');

    fetch(`${loris.BaseURL}/bobdule/?format=json`, {
      credentials: 'same-origin',
      method: 'post',
      body: formData,
    }).then((resp) => resp.json())
      .then((data) => this.handleData(data.Data))
      .catch((error) => {
        this.setState({error: true});
        console.error(error);
      });
  }

  /**
   * Close the modal and refetch the new data.
   */
  closeModal() {
    this.setState({
      formURL: '',
    });
    this.fetchData();
  }

  /**
   * Format the column data.
   *
   * @param {string} column the column to format
   * @param {string} cell   the cell to format
   * @param {object} row    the row data
   * @return {JSX.Element} the formatted cell
   */
  formatColumn(column, cell, row) {
    const result = <td>{cell}</td>;

    switch (column) {
      case 'Candidate ID':
        // Candidate ID column, render as a link to launch form in new tab.
        return (
          <td>
            <a href={`${loris.BaseURL}/instruments/final_radiological_review_VSA/?commentID=${row['CommentID']}&sessionID=${row['SessionID']}&candID=${row['Candidate ID']}`} target="_blank">
              {cell}
            </a>
          </td>
        );
      case 'Recommend Referral for Clinical MRI':
      case 'Recommend Clinical Follow up':
        // Referral or Clinical column. If data not yet submitted return as checkbox else display submitted value.
        return row['date'] ? result : (
          <td>
            <div className='form-check'>
              <input className='form-check-input position-static' type='checkbox' />
            </div>
          </td>
        );
      case 'Rating':
        // Rating column, parse JSON value rendering as a checkbox for each rating value if data not yet submitted, else
        // display submitted values and string.
        const ratings = JSON.parse(cell);
        if (row['date']) {
          const enabled = [];
          if (ratings['normal'].value === 'yes') {
            enabled.push('Normal');
          }
          if (ratings['atypical'].value === 'yes') {
            enabled.push('Atypical');
          }
          if (ratings['abnormal'].value === 'yes') {
            enabled.push('Abnormal');
          }
          return (
            <td>{enabled.join(', ')}</td>
          );
        }

        return (
          <td>
            <form>
              <div className="form-row align-items-center" style={{'paddingBottom': '20px'}}>
                <div className='form-check form-check-inline'>
                  <input
                    className='form-check-input'
                    name='normal'
                    type='checkbox'
                    checked={ratings['normal'].value === 'yes'}
                    onChange={(event) => this.updateRating(event, row['Action'], true)}
                  />
                  <label className="form-check-label" style={{'paddingLeft': '10px'}}>Normal</label>
                </div>
                <textarea
                  className="form-control"
                  name='normal_comment'
                  value={ratings['normal'].comment}
                  onChange={(event) => this.updateRating(event, row['Action'], false)}
                />
              </div>
              <div className="form-row align-items-center" style={{'paddingBottom': '20px'}}>
                <div className="form-check form-check-inline">
                  <input
                    className='form-check-input'
                    name='atypical' type='checkbox'
                    checked={ratings['atypical'].value === 'yes'}
                    onChange={(event) => this.updateRating(event, row['Action'], true)}
                  />
                  <label className='form-check-label' style={{'paddingLeft': '10px'}}>Atypical</label>
                </div>
                <textarea
                  className="form-control"
                  name='atypical_comment'
                  value={ratings['atypical'].comment}
                  onChange={(event) => this.updateRating(event, row['Action'], false)}
                />
              </div>
              <div className="form-row align-items-center">
                <div className="form-check form-check-inline">
                  <input
                    className='form-check-input'
                    name='abnormal' type='checkbox'
                    checked={ratings['abnormal'].value === 'yes'}
                    onChange={(event) => this.updateRating(event, row['Action'], true)}
                  />
                  <label className='form-check-label' style={{'paddingLeft': '10px'}}>Abnormal</label>
                </div>
                <textarea
                  className="form-control"
                  name='abnormal_comment'
                  value={ratings['abnormal'].comment}
                  onChange={(event) => this.updateRating(event, row['Action'], false)}
                />
              </div>
            </form>
          </td>
        );
      case 'Action':
        // Action column, display action based on row data.
        const rating = JSON.parse(row['Rating']);
        let label;
        if (row['date']) {
          // Data has been submitted, display action to mark form as complete.
          label = 'Mark Complete';
        } else if (rating['atypical'].value === 'yes' || rating['abnormal'].value === 'yes') {
          // User has selected an none normal rating, display action to launch form for more data to be submitted.
          label = 'Launch Form';
        } else if (rating['normal'].value === 'yes') {
          // Normal rating selected, display action to save and complete the form.
          label = 'Save and Complete';
        }

        if (label) {
          return (
            <td>
              <button
                type='button'
                className='btn btn-primary'
                onClick={() => this.actionClick(label, row)}
              >
                {label}
              </button>
            </td>
          );
        }
        return <td></td>;
      default:
        return result;
    }
  }

  render() {
    const fields = [
      {
        label: 'CommentID',
        show: false,
      },
      {
        label: 'SessionID',
        show: false,
      },
      {
        label: 'date',
        show: false,
      },
      {
        label: 'Candidate ID',
        show: true,
        filter: {
          name: 'candID',
          type: 'text',
        },
      },
      {
        label: 'Visit',
        show: true,
        filter: {
          name: 'candID',
          type: 'select',
          options: this.state.visitOptions,
        },
      },
      {
        label: 'Recommend Referral for Clinical MRI',
        show: true,
      },
      {
        label: 'Recommend Clinical Follow up',
        show: true,
      },
      {
        label: 'Rating',
        show: true,
      },
      {
        label: 'Action',
        show: true,
      },
    ];

    const style = {
      overflow: 'hidden',
      height: '100%',
      width: '100%',
    };

    return (
      <div>
        <FilterableDataTable
          name={'bobdule_table'}
          data={this.state.data}
          fields={fields}
          getFormattedCell={this.formatColumn}
        />
        <Modal show={this.state.formURL !== ''} onClose={this.closeModal}>
          <iframe src={this.state.formURL} style={style} height="100%" width="100%"/>
        </Modal>
      </div>
    );
  }
}

window.addEventListener('load', () => {
  ReactDOM.render(
    <Bobdule />,
    document.getElementById('lorisworkspace')
  );
});
