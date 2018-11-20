import React from 'react';

import {Tabs, TabPane} from 'Tabs';
import FilterableDataTable from 'FilterableDataTable';

class QualityControlIndex extends React.Component {
  constructor(props) {
    loris.hiddenHeaders = ['CommentID', 'TarchiveID'];

    super(props);
    this.state = {
      isLoadedImg: false,
      isLoadedBehavioral: false,
      imgFilter: {},
      behavioralFilter: {},
    };
    this.fetchData = this.fetchData.bind(this);
    this.updateBehavioralFilter = this.updateBehavioralFilter.bind(this);
    this.updateImgFilter = this.updateImgFilter.bind(this);
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
      let result = <td>{cell}</td>;
      switch (column) {
          case 'MRI Parameter Form':
              let mpfURL = loris.BaseURL + '/mri_parameter_form/?commentID=' +
                  row.CommentID + '&sessionID=' + row['Session ID'] +
                  '&candID=' + row.DCCID;
              result = <td> <a href={mpfURL}>{cell}</a> </td>;
          case 'Scan Location':
            if (cell == 'In Imaging Browser') {
              let imgURL = loris.BaseURL + '/imaging_browser/viewSession/?sessionID=' +
                  row['Session ID'];
              result = <td><a href={imgURL}>{cell}</a></td>;
            }
          case 'Tarchive':
            if (cell == 'In DICOM') {
                let tarchiveURL = loris.BaseURL +
                    '/dicom_archive/viewDetails/?tarchiveID=' + row.TarchiveID;
                return <td><a href = {tarchiveURL}>{cell}</a></td>;
            } else {
              result = <td>Missing</td>;
            }
      }
      return result;
  }

  componentDidMount() {
    this.fetchData('imaging');
    this.fetchData('behavioral');
  }
  fetchData(flag) {
    if (flag === 'imaging') {
      $.ajax(this.props.ImgDataURL, {
        method: 'GET',
        dataType: 'json',
        success: function(data) {
          this.setState({
            ImgData: data,
            isLoadedImg: true,
          });
        }.bind(this),
      });
    } else if (flag === 'behavioral') {
      $.ajax(this.props.BehavioralDataURL, {
        method: 'GET',
        dataType: 'json',
        success: function(data) {
          this.setState({
            BehavioralData: data,
            isLoadedBehavioral: true,
          });
        }.bind(this),
      });
    }
  }
  updateImgFilter(filter) {
    this.setState({
      imgFilter: filter,
      filter: filter,
    });
  }
  updateBehavioralFilter(filter) {
    this.setState({
      behavioralFilter: filter,
      filter: filter,
    });
  }
  render() {
    if (!this.state.isLoadedBehavioral || !this.state.isLoadedImg) {
      return (
      <button className="btn-info has-spinner">
        Loading
        <span
          className="glyphicon glyphicon-refresh glyphicon-refresh-animate">
        </span>
      </button>
      );
    }
    let tabList = [
      {id: 'behavioral', label: 'Behavioral'},
      {id: 'imaging', label: 'Imaging'},
    ];


    let tab0 = (
        <TabPane TabId={tabList[0].id}>
          <FilterableDataTable
                  name="quality_control_behavioural"
                  data={this.state.BehavioralData.Data}
                  fields={this.state.BehavioralData.form}
                  filter={this.state.behavioralFilter}
                  getFormattedCell={this.formatColumn}
          />
        </TabPane>
    );

    let tab1 = (
        <TabPane TabId={tabList[1].id}>
            <FilterableDataTable
                name="quality_control"
                data={this.state.ImgData.Data}
                fields={this.state.ImgData.Data}
                filter={this.state.imgFilter}
                getFormattedCell={this.formatColumn}
            />
        </TabPane>
    );
    return (
        <div>
            <Tabs id = "TabPanes" tabs={tabList} defaultTab={tabList[0].id}
                  updateURL={true}>
                {tab0}
                {tab1}
            </Tabs>
        </div>
    );
  }
}
$(function() {
  const qualityControlIndex = (
      <div className="page-qualityControl">
          <QualityControlIndex
              ImgDataURL={`${loris.BaseURL}/quality_control/?format=json`}
              BehavioralDataURL = {`${loris.BaseURL}/quality_control/?submenu=quality_control_behavioral&format=json`}/>
      </div>
    );
  ReactDOM.render(qualityControlIndex, document.getElementById('lorisworkspace'));
});
