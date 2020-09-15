import StaticDataTable from 'StaticDataTable';

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
  }
 /**
   * Called by React when the component has been rendered on the page.
   * @return {JSX} - React markup for the component
   */
  render() {
    // If error occurs, return a message.
     return (
          <StaticDataTable
            Data= {this.props.data}
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
            Hide={{rowsPerPage: true, downloadCSV: true, defaultColumn: true}}
            getFormattedCell={this.formatColumn}
          />
     );
  }
}
export default ViewSurveysIndex;

