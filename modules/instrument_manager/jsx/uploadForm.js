import React, {Component} from 'react';
import PropTypes from 'prop-types';
import swal from 'sweetalert2';
import {FileElement} from 'jsx/Form';

/**
 * Instrument Upload Form component
 */
class InstrumentUploadForm extends Component {
  /**
   * @constructor
   * @param {object} props - React Component properties
   */
  constructor(props) {
    super(props);

    this.state = {
      data: {},
      selectedFile: null,
    };

    this.fileSelected = this.fileSelected.bind(this);
    this.upload = this.upload.bind(this);
  }

  /**
   * Update selectedFile on file selection
   *
   * @param {string} element - Element name
   * @param {string} file
   */
  fileSelected(element, file) {
    this.setState({
      selectedFile: file,
    });
  }

  /**
   * Upload instrument
   */
  upload() {
    const data = new FormData();
    data.append('install_file', this.state.selectedFile);

    fetch(this.props.action, {
      method: 'POST',
      credentials: 'same-origin',
      body: data,
    })
      .then((resp) => {
        if (resp.status == 201) {
          swal.fire({
            title: 'Installation Successful!',
            type: 'success',
          }).then(function() {
            window.location.assign(loris.BaseURL + '/instrument_manager/');
          });
        }
        return resp.json();
      })
      .then((data) => {
        if (data.message) {
          swal.fire({
            title: 'Upload Successful!',
            type: 'success',
            text: data.message,
          }).then(function() {
            window.location.assign(loris.BaseURL + '/instrument_manager/');
          });
        }
        if (data.error) {
          swal.fire({
            title: 'An error occurred',
            type: 'error',
            text: data.error,
          });
        }
      })
      .catch((error) => {
        this.setState({error: true});
      });
  }

  /**
   * Renders the React component.
   *
   * @return {JSX} - React markup for the component
   */
  render() {
    const disabled = () => this.state.selectedFile === null;

    return (
      <div className="row">
        <div className="col-xs-4">
          <div className="panel panel-primary">
            <div className="panel-heading">Upload Instrument</div>
            <div className="panel-body">
              <div className="col-xs-12">
                <FileElement
                  name='install_file'
                  label='Instrument file'
                  onUserInput={this.fileSelected}
                  value={this.state.selectedFile}
                />
                <button
                  className="btn btn-default"
                  onClick={this.upload}
                  disabled={disabled()}
                >
                  Install
                </button>
              </div>
            </div>
          </div>
        </div>
      </div>
    );
  }
}

InstrumentUploadForm.propTypes = {
  action: PropTypes.string.isRequired,
};

export default InstrumentUploadForm;
