import React, {Component} from 'react';

import Loader from 'Loader';
import FilterableDataTable from 'FilterableDataTable';


export class App extends Component {
  constructor(props) {
    super(props);

    this.state = {
      data: {},
      fieldOptions: {},
      error: false,
      isLoaded: false,
    };

    this.fetchData = this.fetchData.bind(this);
    this.formatColumn = this.formatColumn.bind(this);
    this.mapColumn = this.mapColumn.bind(this);
  }

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
      .then((data) => {
                       this.setState({data: data.data, fieldOptions: data.fieldOptions});
                       console.log(data.data);
      }).catch((error) => {
        this.setState({error: true});
        console.error(error);
      });
  }

  /**
   * Modify value of specified column cells in the Data Table component
   *
   * @param {string} column - column name
   * @param {string} value - cell value
   *
   * @return {string} a mapped value for the table cell at a given column
   */
  mapColumn(column, value) {
        return value;
  }

  /**
   * Modify behaviour of specified column cells in the Data Table component
   *
   * @param {string} column - column name
   * @param {string} cell - cell content
   * @param {object} row - row content indexed by column
   *
   * @return {*} a formated table cell for a given column
   */
  formatColumn(column, cell, row) {
    cell = this.mapColumn(column, cell);
    // Set class to 'bg-danger' if file is hidden.
    let result = <td>{cell}</td>;
    return result;
  }

  render() {
    // If error occurs, return a message.
    // XXX: Replace this with a UI component for 500 errors.
    if (this.state.error) {
      return <h3>An error occured while loading the page.</h3>;
    }

    // Waiting for async data to load
    if (!this.state.isLoaded) {
      return <Loader/>;
    }

   /**
    * XXX: Currently, the order of these fields MUST match the order of the
    * queried columns in _setupVariables() in media.class.inc
    */
    let fields = [
      {label: 'appointmentID', show: true, filter: {
        name: 'AppointmentID',
        type: 'text',
      }},
      {label: 'date', show: true},
      {label: 'date1', show: false, filter: {
        name: 'date',
        type: 'text',
      }},
    ];

    return (
          <FilterableDataTable
            name="schedule"
            data={this.state.data}
            fields={fields}
            getFormattedCell={this.formatColumn}
            getMappedCell={this.mapColumn}
          />
    );
  }
}

