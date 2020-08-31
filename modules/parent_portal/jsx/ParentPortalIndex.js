/**
 * New Profile Form
 *
 * Create a parent portal form
 *
 * @author  Shen Wang
 * @version 1.0.0
 */
class ParentPortalIndex extends React.Component {
  /**
   * @constructor
   * @param {object} props - React Component properties
   */
  constructor(props) {
    super(props);
    this.state = {
      configData: {},
      formData: {},
      isLoaded: false,
      error: false,
      submitDisabled: false,
    };
    this.handleSubmit = this.handleSubmit.bind(this);
  }

  /**
   * Called by React when the component has been rendered on the page.
   */
  componentDidMount() {
  }

  /**
   * Retrieve data from the provided URL and save it in state
   *
   * @return {object}
   */
  /**
   * It checks the date of birth and Expected Date of Confinement,
   * the date fields must match.
   * If match, this function will return true.
   *
   * @return {boolean}
   */
  validateMatchDate() {
    let validate = false;
    const formData = this.state.formData;
    if (formData.dobDate !== formData.dobDateConfirm) {
      swal.fire('Error!', 'Date of Birth fields must match', 'error');
    } else if (this.state.configData['edc'] === 'true' &&
         (formData.edcDate !== formData.edcDateConfirm)
    ) {
      swal.fire('Error!', 'EDC fields must match', 'error');
    } else {
      validate = true;
    }
    return validate;
  }

  /**
   * Handles form submission
   *
   * @param {event} e - Form submission event
   */
  handleSubmit(e) {
    e.preventDefault();
  }

  /**
   * Renders the React component.
   *
   * @return {JSX} - React markup for the component
   */
  render() {
    // If error occurs, return a message.
    if (this.state.error) {
      return <h3>An error occured while loading the page.</h3>;
    }
    // Waiting for async data to load
    if (!this.state.isLoaded) {
      return <Loader/>;
    }
     return (
      <FormElement
          name = "newProfileForm"
          onSubmit = {this.handleSubmit}
        >
          <TextElement
            name = "dobDate"
            label = "Date of Birth"
          />
          <TextElement
            name = "dobDateConfirm"
            label = "Date of Birth Confirm"
          />
          <ButtonElement
            name = "fire_away"
            label = "Create"
            id = "button"
            type = "submit"
          />
        </FormElement>
     );
  }
}
window.addEventListener('load', () => {
  ReactDOM.render(
    <ParentPortalIndex
      dataURL = {`${loris.BaseURL}/parent_portal/?format=json`}
      submitURL = {`${loris.BaseURL}/parent_portal/`}
    />,
    document.getElementById('lorisworkspace')
  );
});
