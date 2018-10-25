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
      Data: {},
      formData: {},
      isLoaded: false,
     }
    this.handleSubmit = this.handleSubmit.bind(this);
    this.setFormData = this.setFormData.bind(this);
   }
  /**
   * Handles form submission
   * @param {event} e - Form submition event
   */
  handleSubmit(e) {
    e.preventDefault();
    
    console.log(this.state.formData);
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
            ref="dateTaken"
            value={this.state.formData.dateTaken}
          />
          <ButtonElement label="Create" />
        </FormElement>
       );
     }

}
export default NewProfileForm;

