import StaticDataTable from 'jsx/StaticDataTable';
/**
 * New Profile Form
 *
 * Create a parent portal form
 *
 * @author  Shen Wang
 * @version 1.0.0
 */
class ViewSurveysIndex extends React.Component {
  /**
   * @constructor
   * @param {object} props - React Component properties
   */
  constructor(props) {
    super(props);
    this.state = {
      data: {},
      error: false,
      isLoaded: false,
    };
    this.fetchData = this.fetchData.bind(this);
    this.formatColumn = this.formatColumn.bind(this);
  }
 /**
   * Called by React when the component has been rendered on the page.
   */
  componentDidMount() {
    this.fetchData()
      .then(() => this.setState({isLoaded: true}));
  }
  /**
   * Retrieve data from the provided URL and save it in state
   * Additionally add hiddenHeaders to global loris variable
   * for easy access by columnFormatter.
   *
   * @return {object}
   */
  fetchData() {
    return fetch(this.props.dataURL, {credentials: 'same-origin'})
      .then((resp) => resp.json())
      .then((data) => this.setState({data}))
      .catch((error) => {
        this.setState({error: true});
        console.error(error);
      });
  }
  /**
   * Renders the React component.
   *
   * @return {JSX} - React markup for the component
   */
  /**
   * Format column
   *
   * @param {string} column
   * @param {*} cell
   * @param {object} rowData
   * @param {string[]} rowHeaders
   *
   */
  formatColumn(column, cell, rowData, rowHeaders) {
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
     return (
          <StaticDataTable
            Data= {this.state.data.Data}
            Headers={[
              'PSCID',
              'DCCID',
              'Visit Label',
              'Site',
              'DOB',
              'Sex',
              'Output Type',
              'Subproject',
              'dfdsa',
            ]}

            getFormattedCell={this.formatColumn}
          />
     );
  }
}
window.addEventListener('load', () => {
const urlParams = new URLSearchParams(window.location.search);
const parentid = urlParams.get('id');
  ReactDOM.render(
    <ViewSurveysIndex
      parentID = {parentid}
      dataURL={`${loris.BaseURL}/survey_accounts/?format=json`}
    />,
    document.getElementById('lorisworkspace')
  );
});
