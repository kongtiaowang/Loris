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
      data: {
      },
      configData:{},
      formData: {},
      isLoaded: false,
     }
    this.handleSubmit = this.handleSubmit.bind(this);
    this.setFormData = this.setFormData.bind(this);
    this.fetchData = this.fetchData.bind(this);
   }

  /**
   * Retrive data from the provided URL and save it in state
   * Additionaly add hiddenHeaders to global loris vairable
   * for easy access by columnFormatter.
   */
  fetchData() {
    $.ajax(loris.BaseURL + '/new_profile/ajax/getConfig.php', {
      method: "GET",
      dataType: 'json',
      success: data => {
        // FIXME: Remove the following line of code as soon as hiddenHeaders is
        // accepted as a prop by the StaticDataTable Component.
        this.setState({
          configData: data,
          isLoaded: true
        });
      },
      error: error => console.error(error)
    });
  }

  componentWillMount() {
    this.fetchData();
  }
 
  validate() {
    const data = this.state.formData;
    let isError = false;
    if (data.dateTaken !== data.dateTakenConfirm)
    {
        isError = true;
    }
    let decError = false;
    if (this.state.configData['edc'] === 'true' && 
        data.edcDateTaken !== data.edcDateTakenConfirm)
    {
       decError = true;
    }     
     return isError || decError; 
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
    console.log("yeah!");
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
     console.log(this.state);
     var edc = null;
     if (this.state.configData['edc'] === 'true')
     {
       edc =
          <div>
          <DateElement
            name="edcDateTaken"
            label="Expected Date of Confinement"
            minYear="2000"
            maxYear="2017"
            onUserInput={this.setFormData}
            ref="edcDateTaken1"
            value={this.state.formData.edcDateTaken}
            required={true}
          /> 
          <DateElement
            name="edcDateTakenConfirm"
            label="Confirm EDC"
            minYear="2000"
            maxYear="2017"
            onUserInput={this.setFormData}
            ref="edcDateTaken2"
            value={this.state.formData.edcDateTakenConfirm}
            required={true}
          />
          </div>;
     }
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
            required={true}
          />
          <DateElement
            name="dateTakenConfirm"
            label="Date of Birth Confirm"
            minYear="2000"
            maxYear="2017"
            onUserInput={this.setFormData}
            ref="dateTaken2"
            value={this.state.formData.dateTakenConfirm}
            required={true}
          />
          {edc}
          <SelectElement
            name="gender"
            label="Gender"
            options={this.state.configData.gender}
            onUserInput={this.setFormData}
            ref="gender"
            value={this.state.formData.gender}
            required={true}
          />
          <SelectElement
            name="site"
            label="Site"
            options={this.state.configData.gender}
            onUserInput={this.setFormData}
            ref="site"
            value={this.state.formData.site}
            required={true}
          />
          <SelectElement
            name="project"
            label="Project"
            options={this.state.configData.gender}
            onUserInput={this.setFormData}
            ref="project"
            value={this.state.formData.project}
            required={true}
          />
          <ButtonElement label="Create" />
        </FormElement>
       );
     }

}
export default NewProfileForm;

