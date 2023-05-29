/* eslint-disable */
import React, { useState, useEffect } from 'react';
import FormTable from './FormTable';
import swal from 'sweetalert2';

/**
 * VisitCompleteForm Component
 *
 * @param {*} propsFom
 * @returns
 */
export default function VisitCompleteForm(props) {
  const [formData, setFormData] = useState(undefined);
  const [rows, setRows] = useState([]);
  const [canSave, setCanSave] = useState(true);
  const [formErrors, setFormErrors] = useState(undefined);
  const [isChecked, setIsChecked] = useState(false);
  const handleCheckboxChange = (e) => {
    setIsChecked(e.target.checked);
  }

  const options = new Object();
  options['All'] = 'All';
  options['None'] = 'None';
  options['Partial'] = 'Partial';



  const options2 = new Object();
  options2['In Progress'] = 'In Progress';
  options2['Complete'] = 'Complete';


  const options3 = props.Instrument_Not_Completed_Reason;


const opt3 = {};
for (const key in options3) {
  const value = options3[key];
  opt3[value] = value;
}


  /**
   * On page load
   */
  useEffect(() => {
    fetchData();
  }, []);

  /**
   * Fetches Instrument Completion Relalated fields from the database
   * This function is called on page load and after each successful form submission
   */
  function fetchData() {
    setCanSave(true);
    const url =
      loris.BaseURL +
      '/portal/portal_util' +
      '?candID=' +
      props.candId +
      '&session=' +
      props.session +
      '&data=VisitCompletion';

    fetch(url)
      .then((response) => response.json())
      .then((data) => {
        let tmp = [];
        for (let i = 0; i < data.length; i++) {
          tmp[i] = {
            Administration: '',
            Data_entry: '',
            Administration_incomplete_reason: '',
            Administration_incomplete_reason_other: '',
          };
        }

        setFormErrors(tmp);
	    setFormData(data);

      });
  }

  /**
   * Populates the table rows with field elements
   * Runs when formData or formErrors are updated
   */
  useEffect(() => {
    let tmpRows = [];

    if (formData !== undefined) {
      for (let i = 0; i < formData.length; i++) {
        let rowData = formData[i];
        let rowErrors = formErrors[i];
        let date, time;

        tmpRows.push(
        <tr key={rowData.CommentID}>
          <td className="xs-col">{i + 1}</td>
          <td>{rowData.Instrument}</td>
        <td className="sm-col">
          <SelectElement
                name={`instr_row_${i}_instrument_${rowData.CommentID}_Administration`}
                options={options}
                onUserInput={onUserInput}
                sortByValue={false}
                value={options[rowData.Administration]}
                hasError={rowErrors.Administration != ''}
                errorMessage={rowErrors.Administration}
        />
        </td>
          <td className="sm-col">
            <SelectElement
                name={`instr_row_${i}_instrument_${rowData.CommentID}_Data_entry`}
                options={options2}
                onUserInput={onUserInput}
                sortByValue={false}
                value={
                  rowData.Administration == 'None'
                      ? null
                      : options2[rowData.Data_entry]
                }
                disabled={
                    options[rowData.Administration] =='None'
                }
                hasError={rowErrors.Data_entry != ''}
                errorMessage={rowErrors.Data_entry}
            />
          </td>
          <td className="sm-col">
            <SelectElement
                name={`instr_row_${i}_instrument_${rowData.CommentID}_Administration_incomplete_reason`}
                options={opt3}
                onUserInput={onUserInput}
                sortByValue={false}
                value={
                  rowData.Administration == 'All'
                      ? null
                      : opt3[rowData.Administration_incomplete_reason]
                }
                disabled={
                  options[rowData.Administration] =='All'
                }
                hasError={rowErrors.Administration_incomplete_reason != ''}
                errorMessage={rowErrors.Administration_incomplete_reason}
            />
          </td>
          <td className="lrg-col">
            <TextboxElement
                name={`instr_row_${i}_instrument_${rowData.CommentID}_Administration_incomplete_reason_other`}
                onUserInput={onUserInput}
                value={
                  rowData.Administration_incomplete_reason != 'Other'|| options[rowData.Administration] =='All'
                      ? null
                      : rowData.Administration_incomplete_reason_other
                }
                disabled={
                    opt3[rowData.Administration_incomplete_reason] != 'Other' ||
                    options[rowData.Administration] =='All'
                }
                hasError={rowErrors.Administration_incomplete_reason_other != ''}
                errorMessage={rowErrors.Administration_incomplete_reason_other}
            />
          </td>

        </tr>
      );
      }
    }

    setRows(tmpRows);
  }, [formData, formErrors]);

  /**
   * Updates formData state on user input
   *
   * @param {*} formElement name attribute of element
   * @param {*} value user input
   */
  function onUserInput(formElement, value) {
    setCanSave(true);

    let i = formElement.split('_')[2];
    // let id = formElement.split('_')[3];
    let formDataCopy = [...formData];
    let rowDataCopy = { ...formDataCopy[i] };

    if (formElement.endsWith('_Administration')) {
      rowDataCopy['Administration'] = value;
      if (value == 'All') {
        rowDataCopy['Administration_incomplete_reason'] = null;
        rowDataCopy['Administration_incomplete_reason_other'] = null;
      } if (value == 'None') {
        rowDataCopy['Data_entry'] = null;
      }
    }
    if (formElement.endsWith('_Administration_incomplete_reason')) {
      rowDataCopy['Administration_incomplete_reason'] = value;
    }
    if (formElement.endsWith('_Administration_incomplete_reason_other')) {
      rowDataCopy['Administration_incomplete_reason_other'] = value;
    }
    if (formElement.includes('_Data_entry')) {
      rowDataCopy['Data_entry'] = value;
    }

console.log(rowDataCopy);
    formDataCopy[i] = rowDataCopy;
    setFormData(formDataCopy);
  }

  /**
   * Called when user clicks Save button
   *
   * @param {*} e
   */
  function handleSubmit(e) {
    try {
      trySaveForm();
    } catch (e) {
     // console.log(e);
    }
  }

  /**
   * Resets formErrors state
   */
  function resetErrors() {
    for (let i = 0; i < formData.length; i++) {
      formErrors[i] = {
        Administration: '',
        Data_entry: '',
        Administration_incomplete_reason: '',
        Administration_incomplete_reason_other: '',
      };
    }
  }

  /**
   * Checks if form has errors
   *
   * @returns {Array} of strings or empty array
   */
  function getFormErrors() {
    let errorMessagesArr = [];
    let formErrorsCopy = [...formErrors];

    for (let i = 0; i < formData.length; i++) {
      let rowData = formData[i];
      let rowErrorsCopy = formErrorsCopy[i];

      if (!rowData.Administration) {
        rowErrorsCopy['Administration'] = 'Required.';
        errorMessagesArr.push(`Administration is Required at Row ${i + 1}`);
      } else if (rowData.Administration =='All' && rowData.Data_entry !='Complete') {
        rowErrorsCopy['Data_entry'] = 'Data Entry Should be Complete for Administration set to All.';
         errorMessagesArr.push(`Data Entry Should be Complete for Administration set to All at Row ${i + 1}`);
       } else if (rowData.Administration !='All' && !rowData.Administration_incomplete_reason) {
        rowErrorsCopy['Administration_incomplete_reason'] = 'Required.';
        errorMessagesArr.push(`Instrument Incomplete Reason is Required at Row ${i + 1}`);
      } else if (rowData.Administration_incomplete_reason=='Other' && !rowData.Administration_incomplete_reason_other ) {
        rowErrorsCopy['Administration_incomplete_reason_other'] = 'Required.';
        errorMessagesArr.push(`Instrument Incomplete Other Reason is Required at Row ${i + 1}`);
      }
      formErrorsCopy[i] = rowErrorsCopy;
    }
console.log(formErrorsCopy);
    setFormErrors(formErrorsCopy);
    return errorMessagesArr;
  }

  /**
   * If there are any errors, display error swal
   * If there are no errors, try to PUT data
   */
  function trySaveForm() {
    resetErrors();

    const swalErrorArr = getFormErrors();

    if (swalErrorArr.length > 0) {
      let swalErrorStr = swalErrorArr.join('<br>');

      swal.fire({
        title: 'Cannot Save Form',
        html: swalErrorStr,
        type: 'error',
        confirmButtonText: 'OK',
      });
    }
    else if (!isChecked) {
      swal.fire({
        title: 'Confirmation Needed!',
        text: 'Please check the box if have you have checked both your email,\n' +
            'and the LORIS Issue Tracker for any CRF\'s for this visit !',
        icon: 'warning',
        customClass: {
          title: 'my-title-class',
          content: 'my-content-class',
        },
      });
    }
    else {
      let tmp = [];

      for (let i = 0; i < formData.length; i++) {
        let rowData = formData[i];

        // Required Fields
        tmp.push(
          `${rowData.CommentID}_Administration=${rowData.Administration}`
        );
        if (rowData.Administration == 'All') {
          tmp.push(
              `${rowData.CommentID}_Data_entry=${rowData.Data_entry}`
          );
        }

        if (rowData.Administration != 'All') {
          tmp.push(`${rowData.CommentID}_Administration_incomplete_reason=${rowData.Administration_incomplete_reason}`);
        }
        if (rowData.Administration_incomplete_reason =='Other') {
            tmp.push(
              `${rowData.CommentID}_Administration_incomplete_reason_other=${rowData.Administration_incomplete_reason_other}`
            );
        }
      }

      const putUrl =
        loris.BaseURL + '/portal/visit_complete';

      let body = [
        'candID=' + props.candId,
        'session=' + props.session,
        'update=UpdateVisitComplete',
      ];

      body = body.concat(tmp).join('&');

      fetch(loris.BaseURL +
          '/portal/visit_complete', {
        method: 'POST',
        cache: 'no-cache',
        credentials: 'same-origin',
        body: JSON.stringify(body),
        headers: {
          'Content-Type': 'application/json'
        },		  
      })
        .then((response) => {
          if (response.status != 200) {

            swal.fire(
              `${response.status} ${response.statusText}`,
              'The Form Was Not Saved.',
              'error'
            );
          } else {
            swal.fire({
              title: 'Success!',
              text: 'This Visit is Marked As Complete. Thank you!',
              type: 'success',
              confirmButtonText: 'OK'}).then(() => {
              // Callback function to close modal
              props.onSaveForm();
              props.viewFinalPage();
            });
            //fetchData();

            //window.location.href = loris.BaseURL + '/';
          }
        })
        .catch((err) => {
          console.log(err);
          swal.fire({
            title: 'Error!',
            text: 'Something went wrong.',
            type: 'error',
            confirmButtonText: 'OK',
          });
        });
    }
  }

  /**
   * Exists to get rid of console warnings
   */
  function callBack() {
    console.log('callBack');
	  //trySaveForm();
  }
  const styles = {
    zIndex: 1, // set the z-index to 2
  };
  return (
    <div className="VisitCompleteForm" style={styles}>
    <div></div>
    <FormElement
  className="FormElement"
  name="form"
  fileUpload={false}
  onUserInput={onUserInput}
  onSubmit={callBack}
  >
  {rows === [] ? null : (
    <FormTable name="visitCompleteForm" columns={columns} rows={rows} />
)}
      <label>Please confirm you have checked both your email,
        and the LORIS Issue Tracker for any CRF's for this visit </label>
<label>
  <input
      type ="checkbox"
      checked={isChecked}
      onChange={handleCheckboxChange}
  />
  Yes, I confirm I have checked
</label>
<button
  onClick={handleSubmit}
  className="btn btn-primary"
  disabled={!canSave}
>
  Save
  </button>
  </FormElement>
  </div>
);
}

const columns = [
  {
    id: 0,
    name: 'index',
    label: 'No. ',
    type: 'static',
  },
  {
    id: 1,
    name: 'sample',
    label: 'Instrument ',
    type: 'static',
  },
  {
    id: 2,
    name: 'administration',
    label: 'Administration',
    type: 'select',
  },
  {
    id: 3,
    name: 'Data_entry',
    label: 'Data Entry',
    type: 'select',
  },
  {
    id: 4,
    name: 'Admiministration_incomplete_reason',
    label: 'Instrument Not Completed Reason',
    type: 'select',
  },
  {
    id: 5,
    name: 'Admiministration_incomplete_reason_other',
    label: 'Instrument Not Completed Other Reason',
    type: 'text',
  },



];
