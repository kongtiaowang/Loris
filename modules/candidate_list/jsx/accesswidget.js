/* eslint-disable */
import React, { useState } from 'react';
import Swal from 'sweetalert2';

function AccessWidget() {
  const [PSCID, setPSCID] = useState('');
  const [DCCID, setDCCID] = useState('');	
  const [Visit,setVisit] = useState([]);	
  const [textInputValue, setTextInputValue] = useState('');
  const [dropdownValue, setDropdownValue] = useState([]);
  const [responseData, setResponseData] = useState(null);
  const [error, setError] = useState('');
  const [form, setForm] = useState('');
  const [stage, setStage] = useState('');
  const [sessionIDS, setSessionIDS] = useState([]);
  const [sessionID, setSessionID] = useState('');
	

  function handleDccidInputChange(event) {
    setDCCID(event.target.value);
    setVisit('');
    setSessionID('');	  
    fetchDataForm('DCCID',event.target.value);	  
  }
  function handlePscidInputChange(event) {
    setPSCID(event.target.value);
	      setVisit('');
	  setSessionID('');
    fetchDataForm('PSCID',event.target.value);
  }

  function handleDropdownChange(event) {
    setVisit(event.target.value);
    setStage(dropdownValue[event.target.value]);
    setSessionID(sessionIDS[event.target.value]);
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
      //	  setPSCID(data['PSCID']);
      } 
       if (type === 'PSCID' ) {
      //	  setDCCID(data['DCCID']);
      }
	      console.log(data['visit_label']);
	  setDropdownValue(data['visit_label']);
	  setSessionIDS(data['session']);    
        // this.setState({formData: {...this.state.formData, SessionFieldOptions: data['Session']}});
      })
      .catch((error) => {
   //     this.setState({error: true});
        console.error(error);
      });
  }

const sleep = (milliseconds) => {
  return new Promise((resolve) => setTimeout(resolve, milliseconds));
};
	
  const handleSubmit = (event) => {
    event.preventDefault();
	  if (typeof Visit !== 'undefined' && Visit === '') {
		  console.log(dropdownValue);
               if (Array.isArray(dropdownValue) && dropdownValue.length === 0) {	 
		       setError("Invalidate CanID/PSCID");
	       } else {setError("Missing Visit Label!"); }
          } else {
                setError("");
		  if (stage === "Not Started") {
////////////// handle swal
		  //
		           console.log(stage);
console.log(sessionID);
  Swal.fire({
    title: 'Confirmation',
    text: 'This candidate has not started the visit yet! Please choose a method to insert the instrument battery!',
    icon: 'question',
    showCancelButton: true,
    confirmButtonText: 'Automatic',
    cancelButtonText: 'Manual'
  }).then((result) => {
	  console.log(result);
    if (result.value === true) {
      // User clicked "Yes"
	    // todo insert instrument battery!!!!!
fetch(loris.BaseURL+'/candidate_list/CandidateUtil/', {
      method: 'POST',
      cache: 'no-cache',
      credentials: 'same-origin',
      body: JSON.stringify({
        DCCID,
        PSCID,
        Visit,
	sessionID
      }),
      }).then((response) =>response.text())
      .then((data) => {
      console.log(data);
 window.location.href =  loris.BaseURL+"/portal?CandID="+DCCID+"&VisitLabel="+Visit;	      
      })
      .catch((error) => {
   //     this.setState({error: true});
        console.error(error);
      });	    
	    
    
	    
	    
	    // todo end
    } else {
      // User clicked "No"	    
	    window.location.href =  loris.BaseURL+"/next_stage/?CandID="+DCCID+"&sessionID="+sessionID+"&identifier="+sessionID;
    }
  });
           } else {
////////////// swal end
                window.location.href =  loris.BaseURL+"/portal?CandID="+DCCID+"&VisitLabel="+Visit;
		  }
	  }


          console.log(error);
   // window.location.href =  loris.BaseURL+"/portal?CandID="+DCCID+"&VisitLabel="+Visit;
  };
  const errorDiv = error == '' ? null : <div className="error">{error}</div>;

  return (
    <div>
      <h4 style={{ color: '#064785', marginTop: '5px', marginBottom: '15px' }}>
	  Linking to REDCap
      </h4>
      <form onSubmit={handleSubmit}>
	  {errorDiv}
        <div className="form-group">
          <label htmlFor="candidinput">CandID</label>
          <input
            type="text"
            className="form-control"
            id="candidinput"
            placeholder="Enter CandID"
	    value={DCCID}
	    onChange={handleDccidInputChange}
	    required
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
	    required
          />
        </div>
        <div className="form-group">
          <label htmlFor="visitinput">Visit Label</label>	  
          <select name="visit" 
	         className="form-control"  
	         value={Visit}
	         onChange={handleDropdownChange}>
            <option value="">--Please choose a Visit Label--</option>
            {Object.keys(dropdownValue).map((key) => (
          <option key={key} value={key}>
		    {key}
          </option>
            ))}
         </select>
        </div>	  
        {errorDiv}
        <button
          className="btn btn-primary"
          style={{ marginBottom: '5px' }}
	  type="submit"
	  >
   	Launch Visit 
        </button>
      </form>
    </div>	  
  );
}
export default AccessWidget;

