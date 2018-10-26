/**
 * New Profile Form
 *  
 * Create a new proflie form 
 *
 * @author Shen Wang
 * @version 1.0.0
 *
 * */
class NewProfileForm extends React.Component {
  constructor(props) {
    super(props);
     this.state = {
      Data: {
          gender:{
                 'male': "Male",
                 'female': "Female"
          }
      },
      formData: {},
      isLoaded: false,
     }
    this.handleSubmit = this.handleSubmit.bind(this);
    this.setFormData = this.setFormData.bind(this);
   }


  validate() {
    const data = this.state.formData;
    let isError = false;
    if (data.dateTaken !== data.dateTakenConfirm)
    {
        isError = true;
    } 
      return isError; 
  }


  /**
   * Handles form submission
   * @param {event} e - Form submition event
   */
  handleSubmit(e) {
    e.preventDefault();
    const err = this.validate();    
    if (!err){
    console.log(this.state.formData);
    }
  }

  /**
   * Set the form data based on state values of child elements/componenets
   *
   * @param {string} formElement - name of the selected element
   * @param {string} value - selected value for corresponding form element
   */
  setFormData(formElement, value) {

    var formData = this.state.formData;
    formData[formElement] = value;

    this.setState({
      formData: formData
    });
  }

     render(){

       return (
        <FormElement
          name="newProfileForm"
          onSubmit={this.handleSubmit}
          ref="form"
        >
          <DateElement
            name="dateTaken"
            label="Date of Birth"
            minYear="2000"
            maxYear="2017"
            onUserInput={this.setFormData}
            ref="dateTaken1"
            value={this.state.formData.dateTaken}
          />
          <DateElement
            name="dateTakenConfirm"
            label="Date of Birth Confirm"
            minYear="2000"
            maxYear="2017"
            onUserInput={this.setFormData}
            ref="dateTaken2"
            value={this.state.formData.dateTakenConfirm}
          />
          <SelectElement
            name="gender"
            label="Gender"
            options={this.state.Data.gender}
            onUserInput={this.setFormData}
            ref="gender"
            value={this.state.formData.gender}
          />
          <TextareaElement
            name="pscid"
            label="PSCID"
            onUserInput={this.setFormData}
            ref="pscid"
            value={this.state.formData.pscid}
          />
          <ButtonElement label="Create" />
        </FormElement>
       );
     }

}
export default NewProfileForm;

