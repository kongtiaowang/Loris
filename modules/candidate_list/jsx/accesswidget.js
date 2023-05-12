/* eslint-disable */
/*
import React, {Component} from 'react';

 * Open Profile Form
 *
 * Module component rendering the Open Profile Form
 *
 
class AccessWidget extends Component {
    this.state = {
      data: {},
      error: false,
      isLoaded: false,
      formData: {
        DCCID: null,
        PSCID: null,
        Session: null,
        SessionFieldOptions: {},
      }
    }
  render() {
    return <h1>Hello, {this.props.name}</h1>;
  }
}	
export default AccessWidget;
*/
import React, { useState } from 'react';

function AccessWidget() {
  const [PSCID, setPSCID] = useState('');
  const [DCCID, setDCCID] = useState('');	
  const [Visit,setVisit] = useState([]);	
  const [textInputValue, setTextInputValue] = useState('');
  const [dropdownValue, setDropdownValue] = useState([]);
  const [responseData, setResponseData] = useState(null);
  const [error, setError] = useState('');
  const [form, setForm] = useState('');

  function handleDccidInputChange(event) {
    setDCCID(event.target.value);
    fetchDataForm('DCCID',event.target.value);	  
  }
  function handlePscidInputChange(event) {
    setPSCID(event.target.value);
    fetchDataForm('PSCID',event.target.value);
 
  }

  function handleDropdownChange(event) {
    setVisit(event.target.value);
  }
  function fetchDataForm(type, value) {
    return fetch(loris.BaseURL+'/candidate_list/CandidateUtil/'+type+'/'+value, {
      method: 'GET',
      cache: 'no-cache',
      credentials: 'same-origin',
      })
      .then((resp) => resp.json())
      .then((data) => {
       if (type === 'DCCID' ) {
	  setPSCID(data['PSCID']);     
         //this.setState({formData: {...this.state.formData, PSCID: data['PSCID']}});
      } 
       if (type === 'PSCID' ) {
	  setDCCID(data['DCCID']);
     
        // this.setState({formData: {...this.state.formData, DCCID: data['DCCID']}});
      }
	      console.log(data['visit_label']);
	  setDropdownValue(data['visit_label']);
        // this.setState({formData: {...this.state.formData, SessionFieldOptions: data['Session']}});
      })
      .catch((error) => {
        this.setState({error: true});
        console.error(error);
      });
  }
  async function handleGoButtonClick() {
    const response = await fetch('path/to/php/backend', {
      method: 'POST',
      headers: {
        'Content-Type': 'application/json'
      },
      body: JSON.stringify({
        inputValue: textInputValue,
        dropdownValue: dropdownValue
      })
    });

    const data = await response.json();
    setResponseData(data);
  }
  const errorDiv = error == '' ? null : <div className="error">{error}</div>;

  return (
    <div>
      <h4 style={{ color: '#064785', marginTop: '5px', marginBottom: '15px' }}>
	  Linking to REDCap
      </h4>
      <form onSubmit={handleGoButtonClick}>
        <div className="form-group">
          <label htmlFor="candidinput">CandID</label>
          <input
            type="text"
            className="form-control"
            id="candidinput"
            placeholder="Enter CandID"
	    value={DCCID} 
	    onChange={handleDccidInputChange}
          />
        </div>
        <div className="form-group">
          <label htmlFor="pscidinput">PSCID</label>
          <input
            type="text"
            className="form-control"
            id="pscidinput"
            placeholder="Enter PSCID"
           value={PSCID}
            onChange={handlePscidInputChange}	  
          />
        </div>
        <div className="form-group">
          <label htmlFor="visitinput">Visit Label</label>	  
          <select name="visit" 
	         className="form-control"  
	         value={Visit}
	         onChange={handleDropdownChange}>
            <option value="">--Please choose an item--</option>
            {Object.keys(dropdownValue).map((key) => (
          <option key={key} value={key}>
            {dropdownValue[key]}
          </option>
            ))}
         </select>
        </div>	  
        {errorDiv}
        <button
          type="submit"
          className="btn btn-primary"
          style={{ marginBottom: '5px' }}
        >
	Launch Visit 
        </button>
      </form>
    </div>	  
  );
}
export default AccessWidget;

