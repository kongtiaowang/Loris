import ProgressBar from 'ProgressBar';

/**
 * Imaging Upload Form
 *
 * Form component allowing to upload MRI images to LORIS
 *
 * @author Alex Ilea
 * @author Victoria Foing
 * @version 1.0.0
 * @since 2017/04/01
 *
 */
class UploadForm extends React.Component {

  constructor(props) {
    super(props);

    const form = JSON.parse(JSON.stringify(this.props.form));

    this.state = {
      formData: {},
      form: form,
      hasError: {},
      errorMessage: {},
      uploadProgress: -1
    };

    this.onFormChange = this.onFormChange.bind(this);
    this.getDisabledStatus = this.getDisabledStatus.bind(this);
    this.submitForm = this.submitForm.bind(this);
    this.uploadFile = this.uploadFile.bind(this);
  }

  componentDidMount() {
    // Disable fields on initial load
    this.onFormChange(this.state.form.imagingUploadType.name, null);
  }

  /*
   Updates values in formData
   Deletes CandID, PSCID, and VisitLabel values if imagingUploadType is not set to 'Subject'
   */
  onFormChange(field, value) {
    if (!field) return;

    const form = JSON.parse(JSON.stringify(this.state.form));
    const formData = Object.assign({}, this.state.formData);

    if (field === 'imagingUploadType') {
      if (value !== 'Subject') {
        delete formData.candID;
        delete formData.pSCID;
        delete formData.visitLabel;
      }
    }

    formData[field] = value;

    this.setState({
      form: form,
      formData: formData,
      hasError: {},
      errorMessage: {},
      uploadProgress: -1
    });
  }

  /*
   Returns false if imagingUploadType is set to 'Subject', and true otherwise
   Result disables the element that calls the function
   */
  getDisabledStatus(imagingUploadType) {
    if (imagingUploadType === 'Subject') {
      return false;
    }
    return true;
  }

  submitForm() {
    // Validate required fields
    const data = this.state.formData;
    if (!data.mri_file || !data.imagingUploadType) {
      return;
    }

    if (data.imagingUploadType === 'Subject' && (!data.candID || !data.pSCID || !data.visitLabel)) {
      return;
    }

    // Checks if a file with a given fileName has already been uploaded
    const fileName = data.mri_file.name;
    const mriFile = this.props.mriList.find(
      mriFile => mriFile.fileName.indexOf(fileName) > -1
    );

    // New File
    if (!mriFile) {
      this.uploadFile();
      return;
    }

    // File uploaded and completed mri pipeline
    if (mriFile.status === "Success") {
      swal({
        title: "File already exists!",
        text: "A file with this name has already successfully passed the MRI pipeline!\n",
        type: "error",
        confirmButtonText: 'OK'
      });
      return;
    }

    // File in the middle of insertion pipeline
    if (mriFile.status === "In Progress...") {
      swal({
        title: "File is currently processing!",
        text: "A file with this name is currently going through the MRI pipeline!\n",
        type: "error",
        confirmButtonText: 'OK'
      });
      return;
    }

    // File uploaded but failed during mri pipeline
    if (mriFile.status === "Failure") {
      swal({
        title: "Are you sure?",
        text: "A file with this name already exists!\n Would you like to override existing file?",
        type: "warning",
        showCancelButton: true,
        confirmButtonText: 'Yes, I am sure!',
        cancelButtonText: "No, cancel it!"
      }, function(isConfirm) {
        if (isConfirm) {
          this.uploadFile(true);
        } else {
          swal("Cancelled", "Your imaginary file is safe :)", "error");
        }
      }.bind(this));
    }

    // Pipeline has not been triggered yet
    if (mriFile.status === "Not Started") {
      swal({
        title: "Are you sure?",
        text: "A file with this name has been uploaded but has not yet started the MRI pipeline." +
          "\n Would you like to override the existing file?",
        type: "warning",
        showCancelButton: true,
        confirmButtonText: 'Yes, I am sure!',
        cancelButtonText: 'No, cancel it!'
      }, function(isConfirm) {
        if (isConfirm) {
          this.uploadFile(true);
        } else {
          swal("Cancelled", "Your upload has been cancelled.", "error");
        }
      }.bind(this));
    }

    return;
  }

  /*
   Uploads file to the server, listening to the progress
   in order to get the percentage uploaded as value for the progress bar
   */
  uploadFile(overwriteFile) {
    const formData = this.state.formData;
    let formObj = new FormData();
    for (let key in formData) {
      if (formData[key] !== "") {
        formObj.append(key, formData[key]);
      }
    }
    formObj.append("fire_away", "Upload");
    if (overwriteFile) {
      formObj.append("overwrite", true);
    }

    $.ajax({
      type: 'POST',
      url: loris.BaseURL + "/imaging_uploader/",
      data: formObj,
      cache: false,
      contentType: false,
      processData: false,
      xhr: function() {
        const xhr = new window.XMLHttpRequest();
        xhr.upload.addEventListener("progress", function(evt) {
          if (evt.lengthComputable) {
            const percentage = Math.round((evt.loaded / evt.total) * 100);
            this.setState({uploadProgress: percentage});
          }
        }.bind(this), false);
        return xhr;
      }.bind(this),
      // Upon successful upload:
      // - Resets errorMessage and hasError so no errors are displayed on form
      // - Displays pop up window with success message
      // - Returns to Browse tab
      success: data => {
        let errorMessage = this.state.errorMessage;
        let hasError = this.state.hasError;
        for (let i in errorMessage) {
          if (errorMessage.hasOwnProperty(i)) {
            errorMessage[i] = "";
            hasError[i] = false;
          }
        }
        this.setState({errorMessage: errorMessage, hasError: hasError});
        swal({
          title: "Upload Successful!",
          type: "success"
        }, function() {
          window.location.assign(loris.BaseURL + "/imaging_uploader/");
        });
      },
      // Upon errors in upload:
      // - Displays pop up window with submission error message
      // - Updates errorMessage and hasError so relevant errors are displayed on form
      // - Returns to Upload tab
      error: (error, textStatus, errorThrown) => {
        swal({
          title: "Submission error!",
          type: "error"
        });
        let errorMessage = this.state.errorMessage;
        let hasError = this.state.hasError;
        errorMessage = (error.responseJSON || {}).errors || 'Submission error!';
        for (let i in errorMessage) {
          if (errorMessage.hasOwnProperty(i)) {
            errorMessage[i] = errorMessage[i].toString();
            if (errorMessage[i].length) {
              hasError[i] = true;
            } else {
              hasError[i] = false;
            }
          }
        }
        this.setState({uploadProgress: -1, errorMessage: errorMessage, hasError: hasError});
      }
    });
  }

  render() {
    // Bind form elements to formData
    const form = this.state.form;
    form.imagingUploadType.value = this.state.formData.imagingUploadType;
    form.candID.value = this.state.formData.candID;
    form.pSCID.value = this.state.formData.pSCID;
    form.visitLabel.value = this.state.formData.visitLabel;
    form.mri_file.value = this.state.formData.mri_file;

    // Hide button when progress bar is shown
    const btnClass = (
      (this.state.uploadProgress > -1) ? "btn btn-primary hide" : undefined
    );

    const notes = (
        <span>
          File cannot exceed {this.props.maxUploadSize}<br/>
          File must be of type .tgz or tar.gz or .zip<br/>
          <br/>
          For files that are <u>Subject Scans</u>, file name must begin with
          <b> [PSCID]_[CandID]_[Visit Label]</b><br/>
          For example, for CandID <i>100000</i>, PSCID <i>ABC123</i>, and
          Visit Label <i>V1</i> the file name should be prefixed by:
          <b> ABC123_100000_V1</b><br/>
          <br/>
          For <u>inter-scanner reliability scans</u>, the file name (without extension) must be of the form:<br/>
          <b> [site]_interscan_[subject initials]_[scanner name]_[scanner_location]_[date][scan number] </b><br/>
          where<br/>
          <ul>
            <li>[site] is the three-letter site abbreviation</li>
            <li>[subject initials] are the subject's initials (three letters)</li>
            <li>[scanner name] is the name of the scanner</li>
            <li>[scanner location] three-letter scanner location</li>
            <li>[date] is the scan acquisition date in format YYYYMMDD</li>
            <li>[scan number] is an optional string of the form '_scan1' for multi-part scans</li>
          </ul>
          All the file name parts are case-insensitive. Example of a valid file name:<br/>
          UNC_interscan_BEA_trio_HOS_20190324_scan2.tar.gz
        </span>
    );

    // Returns individual form elements
    // For CandID, PSCID, and Visit Label, disabled and required
    // are updated depending on imagingUploadType value
    // For all elements, hasError and errorMessage
    // are updated depending on what values are submitted
    return (
      <div className="row">
        <div className="col-md-7">
          <h3>Upload an imaging scan</h3>
          <br/>
          <FormElement
            name="upload_form"
            fileUpload={true}
          >
            <SelectElement
              name="imagingUploadType"
              label="Imaging Upload Type"
              options={this.props.form.imagingUploadType.options}
              onUserInput={this.onFormChange}
              required={true}
              hasError={this.state.hasError.imagingUploadType}
              errorMessage={this.state.errorMessage.imagingUploadType}
              value={this.state.formData.imagingUploadType}
            />
            <TextboxElement
              name="candID"
              label="CandID"
              onUserInput={this.onFormChange}
              disabled={this.getDisabledStatus(this.state.formData.imagingUploadType)}
              required={!this.getDisabledStatus(this.state.formData.imagingUploadType)}
              hasError={this.state.hasError.candID}
              errorMessage={this.state.errorMessage.candID}
              value={this.state.formData.candID}
            />
            <TextboxElement
              name="pSCID"
              label="PSCID"
              onUserInput={this.onFormChange}
              disabled={this.getDisabledStatus(this.state.formData.imagingUploadType)}
              required={!this.getDisabledStatus(this.state.formData.imagingUploadType)}
              hasError={this.state.hasError.pSCID}
              errorMessage={this.state.errorMessage.pSCID}
              value={this.state.formData.pSCID}
            />
            <SelectElement
              name="visitLabel"
              label="Visit Label"
              options={this.props.form.visitLabel.options}
              onUserInput={this.onFormChange}
              disabled={this.getDisabledStatus(this.state.formData.imagingUploadType)}
              required={!this.getDisabledStatus(this.state.formData.imagingUploadType)}
              hasError={this.state.hasError.visitLabel}
              errorMessage={this.state.errorMessage.visitLabel}
              value={this.state.formData.visitLabel}
            />
            <FileElement
              name="mri_file"
              label="File to Upload"
              onUserInput={this.onFormChange}
              required={true}
              hasError={this.state.hasError.mri_file}
              errorMessage={this.state.errorMessage.mri_file}
              value={this.state.formData.mri_file}
            />
            <StaticElement
              label="Notes"
              text={notes}
            />
            <div className="row">
              <div className="col-sm-9 col-sm-offset-3">
                <ProgressBar value={this.state.uploadProgress}/>
              </div>
            </div>
            <ButtonElement
              onUserInput={this.submitForm}
              buttonClass={btnClass}
            />
          </FormElement>
        </div>
      </div>
    );
  }
}

UploadForm.propTypes = {};
UploadForm.defaultProps = {};

export default UploadForm;
