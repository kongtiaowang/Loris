/* eslint-disable */
import React, { Component } from 'react';
import swal from 'sweetalert2';
import {decode} from 'html-entities';
import Modal from 'Modal';
import VisitCompleteForm from './VisitCompleteForm';

/**
 * A VisitInstrumentList is a type of React component which displays
 * a visit. Clicking on the visit expands to display or hide all instruments
 * in that visit and their data entry status.
 *
 * The instruments themselves link to the data entry, and the visit goes
 * to the timepoint_list page.
 */
class VisitInstrumentList extends Component {
  /**
   * Construct the VisitInstrumentList
   *
   * @param {object} props - React props
   */
  constructor(props) {
    super(props);
    this.state = {
      expanded: true,
      hover: false,
      show: false,
      VisitStatus: null,
      Instrument_Not_Completed_Reason_options: null,
    };
    this.toggleHover = this.toggleHover.bind(this);
    this.componentDidMount = this.componentDidMount.bind(this);
    this.getInstruments = this.getInstruments.bind(this);
    this.getInstrument_Not_Completed_Reason_Options = this.getInstrument_Not_Completed_Reason_Options.bind(this);
    this.calcAge = this.calcAge.bind(this);
    this.getVisitStatus = this.getVisitStatus.bind(this);
    //NewCode
    this.showModal = this.showModal.bind(this);
    this.hideModal = this.hideModal.bind(this);
   // End
  }
// New Code
  showModal = () => {
    this.setState({ show: true });
  };

  hideModal = () => {
    this.setState({ show: false });
  };
//End
  /**
   * Toggle determine whether this item is being hovered over.
   * This is used for styling the background.
   */
  toggleHover() {
    this.setState({ hover: !this.state.hover });
  }

  /**
   * Calculate the age at a visit.
   *
   * @param {string} dob - The date of birth as a string
   * @param {string} visit - The visit date as a string
   *
   * @return {string} - A human readable description of the age
   */
  calcAge(dob, visit) {
    let dobdate = new Date(dob);
    let vdate = new Date(visit);
    let years = vdate.getFullYear() - dobdate.getFullYear();
    let months = years * 12 + vdate.getMonth() - dobdate.getMonth();
    if (months <= 36) {
      return months + ' months old';
    }
    return years + ' years old';
  }

  /**
   * Toggle whether instruments are displayed.
   */
  toggleExpanded() {
    // Only get the instruments the first time, otherwise just reuse
    // what the data from state.
    if (!this.state.expanded === true && !this.state.instruments) {
      this.getInstruments();
    }
    this.setState({ expanded: !this.state.expanded });
  }

  componentDidMount() {
    console.log('mount');
    this.getInstruments();
    this.getInstrument_Not_Completed_Reason_Options();
    this.getVisitStatus();
    const container = document.querySelector('.swal2-container');
    if (container) {
      container.style.zIndex = 20000;
    }
    window.addEventListener('focus', () => {
      this.getInstruments();
    });
  }

  /**
   * Get a list of instruments and their data entry completion percentage.
   *
   * The list of instruments will be stored in the component's state.
   */
  getInstruments() {
    console.log('get instruments');
    fetch(
      this.props.BaseURL +
        '/instruments/visitsummary?CandID=' +
        this.props.Candidate.Meta.CandID +
        '&VisitLabel=' +
        this.props.Visit.Meta.Visit
    )
      .then((response) => response.json())
      .then((json) => {
        this.setState({ instruments: json });
      });
  }

  /**
   * Get a list of instruments and their data entry completion percentage.
   *
   * The list of instruments will be stored in the component's state.
   */
  getInstrument_Not_Completed_Reason_Options() {
    console.log('get Instrument_Not_Completed_Reason options');
    fetch(
      this.props.BaseURL +
        '/portal/portal_util?data=get_instrument_incomplete_reasons_option'
    )
      .then((response) => response.json())
      .then((json) => {
	      //console.log(json.instrument_incomplete_reasons_option);
        this.setState({Instrument_Not_Completed_Reason_options: json.instrument_incomplete_reasons_option});
      });
	  console.log(this.state.Instrument_Not_Completed_Reason_options);
  }
  getVisitStatus() {
    console.log('get Visit Completion Status');
    fetch(
        this.props.BaseURL +
        '/portal/portal_util' +
        '?candID=' +
        this.props.Candidate.Meta.CandID +
        '&session=' +
        this.props.Visit.Meta.Visit +
        '&data=get_visit_status'
    )
        .then((response) => response.json())
        .then((json) => {
          const visit_completed=json[0].Visit_completed;
          this.setState({ VisitStatus: visit_completed }, () => {
            console.log(this.state.VisitStatus);
          });
        });
  }
  /**
   * React lifecycle method. Render the component
   *
   * @return {object} - The rendered JSX
   */
  render() {
    let style = {
      marginBottom: '0.5%',
      marginRight: '0.5%',
      textAlign: 'center',
      boxSizing: 'border-box',
      transition: 'flex 0.3s, width 0.3s ease-out, height 0.3s ease-out',
      width: '98%',
      marginBottom: '1ex',
      backgroundColor: 'transparent',
    };
    let qrModal = null;

    let vstatus = 'Not Started';
    let bg = '#ea9999';
    if (this.props.Visit.Stages.Approval) {
      vstatus = 'Approval - ' + this.props.Visit.Stages.Approval.Status;
      bg = '#b6d7a8';
    } else if (this.props.Visit.Stages.Visit) {
      vstatus = 'Visit - ' + this.props.Visit.Stages.Visit.Status;
      bg = '#ffe599';
    } else if (this.props.Visit.Stages.Screening) {
      vstatus = 'Screening - ' + this.props.Visit.Stages.Screening.Status;
      bg = '#f9cb9c';
    }
    let inperson_visit_status='In Progress';
    const { VisitStatus } = this.state;
    const visit_status = VisitStatus;
    // Check if count is greater than 5
    if (visit_status == 'Y') {
      inperson_visit_status = 'Completed';
      bg = '#b6d7a8';
    }

// New Code
    let modal= (
      <Modal show={this.state.show}
                        onClose={() => this.hideModal()
                        }>
      <VisitCompleteForm  onSaveForm={this.hideModal}
                          viewFinalPage={this.componentDidMount}
    candId={this.props.Candidate.Meta.CandID}
    session={this.props.Visit.Meta.Visit}
    Instrument_Not_Completed_Reason={this.state.Instrument_Not_Completed_Reason_options}
    />
    </Modal>
    );
//End
    let clickEnabled = true;
    if (!this.state.expanded) {
      if (vstatus === 'Not Started') {
        style.cursor = 'not-allowed';
        clickEnabled = false;
      } else {
        style.cursor = 'pointer';
      }
      if (this.state.hover) {
        style.backgroundColor = 'rgb(235, 235, 235)';
      }
    }
    if (this.props.VisitLabel !== this.props.Visit.Meta.Visit) {
      // Only allow expanding the active visit.
      clickEnabled = false;
    }

    let flexcontainer = {
      display: 'flex',
      flexDirection: 'row',
      flexWrap: 'nowrap',
      width: '100%',
      height: '100%',
      alignItems: 'flex-start',
      border: '1px solid #E4EBF2',
      borderTopRightRadius: '10px',
      borderBottomRightRadius: '10px',
      alignItems: 'center',
       zIndex:'11',
    };
    flexcontainer.justifyContent = 'flex-start';

    let center = {
      display: 'flex',
      width: '12%',
      height: '100%',
      alignItems: 'center',
      justifyContent: 'center',
	     zIndex:'inherit',
    };

    const termstyle = { paddingLeft: '2em', paddingRight: '2em' };

    let instruments = null;
    if (!this.state.instruments) {
      instruments = 'Loading...';
    } else {
      instruments = this.state.instruments.map((instrument) => {
        let conflicterror = null;
        const ScanQR = (testname, linkURI) => {
          const onScan = (value) => {
            try {
              const obj = JSON.parse(value);
              console.log(obj);
              // Check VL and PSCID match
              if (
                obj.PSCID !== this.props.Candidate.Meta.PSCID ||
                obj.VisitLabel !== this.props.Visit.Meta.Visit
              ) {
                swal.fire({
                  title: 'Invalid Code',
                  icon: 'error',
                  html: '<p>Scanned code does not match. Please contact your study administrator.</p>',
                });
              } else {
                swal
                  .fire({
                    title: testname,
                    icon: 'info',
                    html:
                      '<p>You will be directed to ' +
                      testname +
                      ' in a new window. Once you are finished, return here to continue with your visit.</p>',
                  })
                  .then(() => {
                    window.open(linkURI);
                  });
              }
            } catch (err) {
              console.log(err);
            }
          };
        };

        if (instrument.NumOfConflict != 0) {
          conflicterror = (
            <a
              href={
                this.props.BaseURL +
                '/conflict_resolver/?candidateID=' +
                this.props.Candidate.Meta.CandID +
                '&instrument=' +
                instrument.Test_name +
                '&visitLabel=' +
                this.props.Visit.Meta.Visit
              }
            >
              <i
                style={{ color: 'red' }}
                className="fas fa-exclamation-triangle"
              ></i>
            </a>
          );
        }
        const linkURI = decode(instrument.ExternalDataEntryURL)
          ? decode(instrument.ExternalDataEntryURL)
          : this.props.BaseURL +
            '/instruments/' +
            instrument.Test_name +
            '?commentID=' +
            instrument.CommentID +
           '&candID=' +
           this.props.Candidate.Meta.CandID +
          '&sessionID=' +
           this.props.Visit.Meta.Visit;
        return (
          <tr key={instrument.Test_name}>
            <td style={{ textAlign: 'left' }}>
              <span href={linkURI}>{instrument.Full_name}</span>
            </td>
            <td>
              <progress value={instrument.Completion} max="100">
                {instrument.Completion + '%'}
              </progress>
            </td>
            <td>
              <a href={linkURI}>
                link to access
              </a>
            </td>
          </tr>
        );
      });

      if (this.state.instruments.length === 0) {
        instruments = (
          <div>{'Visit has no registered instruments in test battery.'}</div>
        );
      } else {
        instruments = (
          <div>
            <h5>Instruments</h5>
            <table
              className="table table-hover table-bordered"
              style={{ width: '95%' }}
            >
              <thead>
                <tr>
                  <th>Instrument</th>
                  <th style={{ textAlign: 'center' }}>Completion</th>
                  <th style={{ textAlign: 'center' }}>Action</th>
                </tr>
              </thead>
              <tbody>{instruments}</tbody>
            </table>
          </div>
        );
      }
    }
    if (!this.state.expanded || vstatus === 'Not Started') {
      instruments = null;
    }

    // We don't show the visit date of age if it's not possible because
    // the visit wasn't started.
    let vdate = null;
    let vage = null;
    if (this.props.Visit.Stages.Visit) {
      vdate = (
        <div style={termstyle}>
          <dt>Date Of Visit</dt>
          <dd>{this.props.Visit.Stages.Visit.Date}</dd>
        </div>
      );
      vage = (
        <div style={termstyle}>
          <dt>Age</dt>
          <dd>
            {this.calcAge(
              this.props.Candidate.Meta.DoB,
              this.props.Visit.Stages.Visit.Date
            )}
          </dd>
        </div>
      );
    }
    const defliststyle = {
      display: 'flex',
      flexDirection: 'row',
      flexWrap: 'wrap',
      width: '100%',
      justifyContent: 'space-between',
      margin: 0,
      padding: '1ex',
    };

    let visitLink;
    if (this.props.VisitMap) {
      visitLink = (
        <a
          href={
            this.props.BaseURL +
            '/instrument_list/?candID=' +
            this.props.Candidate.Meta.CandID +
            '&sessionID=' +
            this.props.VisitMap[this.props.Visit.Meta.Visit]
          }
        >
          {this.props.Visit.Meta.Visit}
        </a>
      );
    } else {
      visitLink = <span>{this.props.Visit.Meta.Visit}</span>;
    }
    return (
      <div
        style={style}
        onClick={clickEnabled ? this.toggleExpanded : null}
        onMouseEnter={this.toggleHover}
        onMouseLeave={this.toggleHover}
      >
        <div style={flexcontainer}>
          <div style={{ background: bg, width: '1%', height: '100%' }}></div>
          <div style={center}>
            <h4 style={{ width: '100%', padding: 0, margin: 0 }}>
              {visitLink}
            </h4>
          </div>
          <div>
            <dl style={defliststyle}>
              <div style={termstyle}>
                <dt>Subproject</dt>
                <dd>{this.props.Visit.Meta.Battery}</dd>
              </div>
              <div style={termstyle}>
                <dt>Site</dt>
                <dd>{this.props.Visit.Meta.Site}</dd>
              </div>
              {vdate}
              {vage}
              {/*} <div style={termstyle}>
                <dt>Status</dt>
                <dd>{vstatus}</dd>
              </div>*/}
              <div style={termstyle}>
                <dt>In Person Visit Status</dt>
                <dd>{inperson_visit_status}</dd>
              </div>
            </dl>
            {instruments}
          </div>
          {VisitStatus == 'N' && (
          <div className="mb" style={{zIndex: 1}}>
            {modal}
            <button type="button" onClick={this.showModal}>
              Mark In Person Visit As Complete
            </button>
        </div>
          )}
          {VisitStatus == 'Y' && (
              <div className="mb" style={{zIndex: 1}}>
                {modal}
                <button type="button" onClick={this.showModal}>
                  Recheck Visit Completed Form
                </button>
              </div>
          )}
        </div>
      </div>
    );
  }
}

export default VisitInstrumentList;
