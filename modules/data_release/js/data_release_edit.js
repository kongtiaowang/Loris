/**
 * Script for the Data release module with edit permissions
 *
 * @author Jean-Michel Raoult <jean-michel.raoult.comtl@ssss.gouv.qc.ca>
 */

'use strict';
let categoriesList;
let documentsList;
let versionsList;
/**
 *
 * Object to manage the upload process.
 * @param {number} maxSize  Maximum file size before chunking in bytes
 * @constructor
 */
function UploadObject(maxSize) {
  //
  // Size constraints
  //
  // Maximum size before chunking
  this.maxSize = maxSize;
  // Size of the chunks to be sent
  this.chunkSize = 500 * 1024 * 1024;
  //
  // Page elements
  //
  // ID for upload modal panel
  this.uploadPanel = '#upload-panel';
  // ID for progress bar modal panel
  this.progressPanel = '#progress-bar-modal';
  // ID for the progress bar for upload
  this.uploadBar = '#upload-progress-bar';
  // ID for the progress abr for stitching
  this.stitchingBar = '#stitching-progress-bar';
  // URL for requests (using LORIS helper object)
  this.URL = loris.BaseURL + '/data_release/ajax/FileUpload.php';
  // File Form ID
  this.form = '#upload_version';
  // File upload control
  this.file = '#UploadedFile';
  //
  // Member Functions
  //
  // Initialize the object
  this.init = function(filename, size) {
    // Set the object filename property
    this.filename = filename;
    // Set the objet file size property
    this.size = size;
    // Get handle on the file's blob
    this.file = $(this.file)[0].files[0];
    // If the size of the file is larger than the maximum
    if (this.size > this.maxSize) {
      // Initialize both the current stitch and chunk indices
      this.currentChunk = 0;
      this.currentStitch = 0;
      // Calculate the index of the last chunk
      this.lastChunk = Math.floor(this.size / this.maxSize);
      // Set the upload type to chunk
      this.uploadType = 'chunk';
      // Hide the modal upload menu
      $(this.uploadPanel).modal('hide');
      // Show the modal progress bars
      $(this.progressPanel).modal('show');
      // Set both the upload and stitching bars to 0
      this.adjustProgressBar(this.uploadBar, 0);
      this.adjustProgressBar(this.stitchingBar, 0);
      // If the file is smaller than the maximum
    } else {
      // Set upload to whole
      this.uploadType = 'whole';
    }
  };
  // Start the upload process
  this.start = function() {
    // Check if the upload is possible
    this.isFileUploadPossible();
  };
  // Checks if the file upload is possible
  this.isFileUploadPossible = function() {
    // Send a request to check if the file already exists
    $.ajax({
      url: this.URL,
      type: 'GET',
      data: {
        action: 'FileExists',
        FileName: this.filename
      },
      cache: false,
      contentType: 'application/json'
    })
      // If the file already exists
      .success(function() {
        // Prompt that the upload is not possible
        swal({
          title: 'File Already Exists',
          text: 'The file ' + this.filename + ' already exists in the data ' +
            'releases.\nPlease select a file that doesn\'t already exists.',
          type: 'error'
        }, function() {
          // Hide the modal progress bars
          $(this.progressPanel).modal('hide');
          // Show the modal upload menu
          $(this.uploadPanel).modal('show');
        }.bind(this));
      }.bind(this))
      // If there's an error
      .error(function(response) {
        // Process in function of the error code
        switch (response.status) {
          // If the file wasn't found, which means the upload is possible
          case 404:
            // If the upload type is whole
            if (this.uploadType === 'whole') {
              // Upload the file
              this.uploadFile();
              // If the upload type is chunked
            } else {
              // Check for partial data
              this.hasPartialData();
            }
            break;
          // Both bad requests and unimplemented requests are treated the same
          case 400:
          case 501:
            swal({
              title: response.statusText + ' Error',
              text: response.responseText,
              type: 'error'
            });
            break;
          // In case of other error codes, generate a generic prompt
          default:
            swal({
              title: 'Unknown Error',
              text: response.status + ': ' + response.statusText +
                '\n' + response.responseText,
              type: 'error'
            });
            break;
        }
      }.bind(this));
  };
  // Upload a whole file
  this.uploadFile = function() {
    // Generate a formdata object using the file upload's form
    let form = new FormData($(this.form)[0]);
    // Append the action required to the formdata object
    form.append('action', 'UploadVersion');
    // Upload the file
    $.ajax({
      url: this.URL,
      type: 'POST',
      data: form,
      cache: false,
      processData: false,
      contentType: false
    })
      // If the file was successfully uploaded
      .success(function() {
        // Prompt with the filename that the upload worked
        swal({
          title: 'File Uploaded',
          text: 'The file ' + this.filename + ' was successfully uploaded.',
          type: 'success'
        }, function() {
          // When the prompt is closed, reload the page
          location.reload();
        });
      }.bind(this))
      // If there was an error
      .error(function(response) {
        // Process based on the error code
        switch (response.status) {
          // If there was a 500 error, prompt the response
          case 500:
            swal({
              title: response.statusText + ' Error',
              text: response.responseText,
              type: 'error'
            });
            break;
          // If there was an unexpected error, prompt the generic information
          default:
            swal({
              title: 'Unknown Error',
              text: response.status + ': ' + response.statusText +
                '\n' + response.responseText,
              type: 'error'
            });
            break;
        }
      });
  };
  // Check for the partial data of a previous chunk upload
  this.hasPartialData = function() {
    // Request a check on the partial data
    $.ajax({
      url: this.URL,
      type: 'GET',
      data: {
        action: 'PartialDataExists',
        FileName: this.filename
      },
      cache: false,
      contentType: 'application/json',
      dataType: 'json'
    })
      // If partial data was found
      .success(function(data) {
        // Prompt whether the transfer should resume or restart
        swal({
          title: 'Partial data found',
          text: 'There is already partial data from the ' + this.filename +
            ' file on the server. Do you want to resume from chunk ' +
            Number.parseInt(data.lastChunk, 10) + ' or do you want ' +
            'to start from scratch?',
          type: 'warning',
          showCancelButton: true,
          cancelButtonText: 'Restart',
          confirmButtonText: 'Resume',
          closeOnCancel: true,
          closeOnConfirm: true,
          closeOnEscape: true
        }, function(resuming) {
          // If the transfer must resume
          if (resuming) {
            // Set the current chunk to the index after the latest existing
            // chunk
            this.currentChunk = Number.parseInt(data.lastChunk, 10) + 1;
            // Calculate the upload progress
            let progress = Math.round(
              ((this.currentChunk) / (this.lastChunk + 1)) * 100
            );
            // Update the upload progress bar
            this.adjustProgressBar(this.uploadBar, progress);
            // Upload the next chunk
            this.uploadChunk();
            // If the transfer must restart
          } else {
            // Erase the existing partial data
            this.erasePartialData();
          }
        }.bind(this));
      }.bind(this))
      // If an error was returned
      .error(function(response) {
        // process based on the error code
        switch (response.status) {
          // If no data was found
          case 404:
            // Start uploading chunks
            this.uploadChunk();
            break;
          // If there's a bad or unimplemented request
          case 400:
          case 501:
            // Prompt the error
            swal({
              title: response.statusText + ' Error',
              text: response.responseText,
              type: 'error'
            });
            break;
          // If there was an unexpected error
          default:
            // Prompt a generic error message
            swal({
              title: 'Unknown Error',
              text: response.status + ': ' + response.statusText +
                '\n' + response.responseText,
              type: 'error'
            });
            break;
        }
      }.bind(this));
  };
  // Adjust the bootstrap progress bar tied to the provided ID
  this.adjustProgressBar = function(id, value) {
    $(id).attr('aria-valuenow', value);
    $(id).css('width', value + '%');
    $(id).text(value + '%');
  };
  // Erase existing partial data
  this.erasePartialData = function() {
    // Send a request for partial data erasure
    $.ajax({
      url: this.URL,
      type: 'GET',
      data: {
        action: 'DeletePartialData',
        FileName: this.filename
      },
      cache: false,
      contentType: 'application/json',
      dataType: 'json'
    })
      // If the request was successful
      .success(function(data) {
        // Set a timeout to avoid SweetAlert interference
        setTimeout(function() {
          // Prompt that the data was successfully erased
          swal({
            title: 'Partial Data Erased',
            text: 'The partial data for the ' + data.FileName + ' file was ' +
              'successfully erased.',
            type: 'success',
            showCancelButton: false,
            showConfirmButton: true
          }, function() {
            // When the prompt is closed, start uploading chunks
            this.uploadChunk();
          }.bind(this));
        }.bind(this), 100);
      }.bind(this))
      // If there was an error
      .error(function(response) {
        // Process based on error codes
        switch (response.status) {
          // If no data was found
          case 404:
            // Prompt the information
            swal({
              title: 'File not Found',
              text: 'The partial data for the file specified is not found.',
              type: 'error'
            });
            break;
          // If it was a bad or unimplemented request
          case 400:
          case 501:
            // Prompt the error
            swal({
              title: response.statusText + ' Error',
              text: response.responseText,
              type: 'error'
            });
            break;
          // If it was an unexpected error
          default:
            // Prompt a generic error message
            swal({
              title: 'Unknown Error',
              text: response.status + ': ' + response.statusText +
                '\n' + response.responseText,
              type: 'error'
            });
            break;
        }
      });
  };
  // Upload the current chunk and adjust the next current chunk
  // based on the value of the missing parameter
  this.uploadChunk = function(missing = false) {
    // If the current chunk is not the last one
    if (this.currentChunk <= this.lastChunk) {
      // Calculate the current pointer's position
      let position = this.currentChunk * this.chunkSize;
      // Slice the file from the pointer for a length
      // of chunk
      let chunk = this.file.slice(
        position, this.currentChunk === this.lastChunk ?
          undefined :
          (position + this.chunkSize)
      );
      // Create an instance of the FileReader
      let reader = new FileReader();
      // When the reader is ready
      reader.onload = function() {
        // Create a formdata object from the file upload's form
        let form = new FormData($(this.form)[0]);
        // Add the action
        form.append('action', 'UploadChunk');
        // Add the current chunk
        form.append('Chunk', this.currentChunk.toString(10));
        // Add the last chunk
        form.append('LastChunk', this.lastChunk.toString(10));
        // Delete the whole file
        form.delete('UploadedFile');
        // Append the chunk instead
        form.append('UploadedFile',
          new File([reader.result], this.filename));
        // Send the request with the formdata to the server
        $.ajax({
          url: this.URL,
          type: 'POST',
          data: form,
          cache: false,
          processData: false,
          contentType: false
        })
          // If the chunk was successfully uploaded
          .success(function() {
            // Calculate the progress
            let progress = Math.round(
              ((this.currentChunk + 1) / (this.lastChunk + 1)) * 100
            );
            // Update the upload progress bar
            this.adjustProgressBar(this.uploadBar, progress);
            // If it was a missing chunk, set the current chunk to the end
            if (missing) {
              this.currentChunk = this.lastChunk + 1;
              // If it was a regular chunk, set the current chunk to the next
              // one
            } else {
              this.currentChunk += 1;
            }
            // Upload the current chunk
            this.uploadChunk();
          }.bind(this))
          // If there was an error
          .error(function(response) {
            // Process based on error code
            switch (response.status) {
              // If there was an error in the server
              case 500:
                // Prompt the server error
                swal({
                  title: response.statusText + ' Error',
                  text: response.responseText,
                  type: 'error'
                });
                break;
              // If the server timed out
              case 504:
                // Prompt for the user to reload the page
                // Note: the reload is not done automatically here to naturally
                // allow for more time for the upload to complete, server-side
                swal({
                  title: 'Server Timeout',
                  text: 'The server timed-out while uploading the chunk. ' +
                    'Reload the page to resume the upload.',
                  type: 'error'
                });
                break;
              // If there was an unexpected error
              default:
                // Prompt the error info in a generic prompt
                swal({
                  title: 'Unknown Error',
                  text: response.status + ': ' + response.statusText +
                    '\n' + response.responseText,
                  type: 'error'
                });
                break;
            }
          });
      }.bind(this);
      // Start reading the file to generate the chunk
      reader.readAsArrayBuffer(chunk);
      // If the last chunk has been uploaded
    } else {
      // Send a request to check for missing chunks
      $.ajax({
        url: this.URL,
        type: 'GET',
        data: {
          action: 'MissingChunks',
          FileName: this.filename
        },
        cache: false,
        contentType: 'application/json',
        dataType: 'json'
      })
        // If the request was successful
        .success(function(data) {
          // If there were no missing chunks (the response doesn't include
          // a MissingChunk value)
          if (typeof data.MissingChunk === 'undefined') {
            // Set a timeout to avoid SweetAlert interferences
            setTimeout(function() {
              // Prompt that no missing chunks were found
              swal({
                title: 'No Missing Chunks',
                text: 'No missing chunks were found for file ' + data.FileName,
                type: 'success',
                showCancelButton: false,
                showConfirmButton: true
              }, function() {
                // When the prompt is closed, start stitching the file
                this.stitchFile();
              }.bind(this));
            }.bind(this), 100, data);
            // If a missing chunk was found
          } else {
            // Set a timeout to avoid SweetAlert interferences
            setTimeout(function() {
              // Prompt that missing chunks were found
              swal({
                title: 'Found Missing Chunk',
                text: 'The chunk indexed ' + data.MissingChunk + ' is missing.',
                type: 'error',
                showCancelButton: true,
                showConfirmButton: true,
                cancelButtonText: 'Cancel Operation',
                confirmButtonText: 'Upload Missing Chunk'
              }, function() {
                // When the prompt is closed, set the current chunk to the
                // missing value
                this.currentChunk = Number.parseInt(data.MissingChunk, 10);
                // Upload the missing chunk with the proper parameter set
                this.uploadChunk(true);
              }.bind(this));
            }.bind(this), 100, data);
          }
        }.bind(this))
        // If the request returned an error
        .error(function(response) {
          // Process based on the error code
          switch (response.status) {
            // If no chunks were found
            case 404:
              // Prompt that the data wasn't found
              swal({
                title: 'Chunks not Found',
                text: 'There are no chunks associated with the file provided.',
                type: 'error'
              });
              break;
            // If it was a bad or unimplemented request
            case 400:
            case 501:
              // Prompt the error message
              swal({
                title: response.statusText + ' Error',
                text: response.responseText,
                type: 'error'
              });
              break;
            // If it was an unexpected error
            default:
              // Prompt a generic error message
              swal({
                title: 'Unknown Error',
                text: response.status + ': ' + response.statusText +
                  '\n' + response.responseText,
                type: 'error'
              });
              break;
          }
        });
    }
  };
  // Start or continue stitching a file
  this.stitchFile = function() {
    // Generate a formdata object from the file upload's form
    let form = new FormData($(this.form)[0]);
    // Add the action and the filename
    form.append('action', 'StitchFile');
    form.append('FileName', this.filename);
    // Remove the file
    form.delete('UploadedFile');
    // Send the request to stitch to the server
    $.ajax({
      url: this.URL,
      type: 'POST',
      data: form,
      cache: false,
      processData: false,
      dataType: 'json',
      contentType: false
    })
      // If the stitching was successful
      .success(function(data) {
        // If the response didn't include the filename, it means
        // there's still stitching to do
        if (typeof data.FileName === 'undefined') {
          // Calculate the current stitch based on the returned index
          // of the chunk that was stitched
          this.currentStitch = Number.parseInt(data.Chunk, 10);
          // Calculate the stitching progress
          let progress = Math.round(
            ((this.currentStitch + 1) / (this.lastChunk + 1)) * 100
          );
          // Adjust the stitching progress bar
          this.adjustProgressBar(this.stitchingBar, progress);
          // Start stitching another chunk
          this.stitchFile();
          // If the filename was returned, meaning the stitching is done
        } else {
          // Adjust the stitching progress bar to complete
          this.adjustProgressBar(this.stitchingBar, 100);
          // Prompt that the stitching is complete
          swal({
            title: 'File Stitching',
            text: 'File ' + data.FileName + ' was successfully stitched and' +
              ' registered.',
            type: 'success',
            showCancelButton: false,
            showConfirmButton: true
          }, function() {
            // When the prompt is closed, reload the page
            location.reload();
          });
        }
      }.bind(this))
      // If there was an error
      .error(function(response) {
        // Process based on error code
        switch (response.status) {
          // If no chunks were found to be stitched
          case 404:
            // Prompt about the missing files
            swal({
              title: 'Chunks not Found',
              text: 'There are no chunks associated with the file provided.',
              type: 'error'
            });
            break;
          // If the request was bad or unimplemented
          case 400:
          case 501:
            // Prompt the error
            swal({
              title: response.statusText + ' Error',
              text: response.responseText,
              type: 'error'
            });
            break;
          // If the request timed-out
          case 504:
            // Prompt that the request timed-out
            swal({
              title: 'Server timeout',
              text: 'The server is still stitching in the background but the ' +
                'timeout for a response has been reached.',
              confirmButtonText: 'Query Server for Update',
              type: 'error'
            }, function() {
              // When the prompt is closed, start checking if the stitching
              // is done
              this.isStitching();
            }.bind(this));
            break;
          // If the error was unexpected
          default:
            // Prompt the generic error
            swal({
              title: 'Unknown Error',
              text: response.status + ': ' + response.statusText +
                '\n' + response.responseText,
              type: 'error'
            });
            break;
        }
      }.bind(this));
  };
  // Check whether the stitching is still running on the server
  this.isStitching = function() {
    // Request the stitching completion from the server
    $.ajax({
      url: this.URL,
      type: 'GET',
      data: {
        action: 'IsStitching',
        FileName: this.filename
      },
      cache: false,
      contentType: 'application/json',
      dataType: 'json'
    })
      // If the stitching is done
      .success(function() {
        // Calculate the stitching progress
        let progress = Math.round(
          ((this.currentStitch + 1) / (this.lastChunk + 1)) * 100
        );
        // Update the current stitch value
        this.currentStitch += 1;
        // Update the stitching progress bar
        this.adjustProgressBar(this.stitchingBar, progress);
        // Set a timeout to prevent SweetAlert interferences
        setTimeout(function() {
          // Prompt the user that the stitching is complete
          swal({
            title: 'Stitching Complete',
            text: 'The pending stitching is completed.',
            type: 'success',
            showCancelButton: false,
            showConfirmButton: true,
            confirmButtonText: 'Resume Stitching'
          }, function() {
            // When the prompt closes, start stitching the next chunk
            this.stitchFile();
          }.bind(this));
        }.bind(this), 100);
      }.bind(this))
      // If there was an error
      .error(function(response) {
        // Process based on error codes
        switch (response.status) {
          // If the request was bad
          case 400:
            // Prompt the user that the filename was invalid
            swal({
              title: 'Invalid Filename',
              text: 'The filename provided is invalid.',
              type: 'error'
            });
            break;
          // If the server is unavailable or the request timed-out
          case 503:
          case 504:
            // Prompt the user that the server is still stitching
            swal({
              title: 'Still Stitching',
              text: 'The file is still stitching. Check again?',
              type: 'error',
              timer: 2000
            }, function() {
              // When the prompt closes, ask again if the server is still
              // stitching
              this.isStitching();
            }.bind(this));
            break;
          // If the error was unexpected
          default:
            // Prompt the information in a generic error message
            swal({
              title: 'Unknown Error',
              text: response.status + ': ' + response.statusText +
                '\n' + response.responseText,
              type: 'error'
            });
            break;
        }
      }.bind(this));
  };
}

// When the document is ready
$(document).ready(function() {
  // If the URL includes hashes, adjust scroll height
  adjustScrollForTargetedLinks();
  // Add Tooltips
  addTooltips();
  // Add listeners for the categories modal
  addCategoriesListeners();
  // Add listeners for the documents modal
  addDocumentsListeners();
  // Add listeners for the versions modal
  addVersionsListeners();
  // Add listeners for the upload modal
  addFileUploadListeners();
});

/**
 * Add listeners for the controls of the category editing modal menu.
 */
function addCategoriesListeners() {
  // Add listener for changes to the select input
  addCategoriesSelectListener();
  // Add listener for the category add/edit submit button
  addCategoryAddEditSubmitButtonListener();
  // Add listener for the category delete submit button
  addCategoryDeleteSubmitButtonListener();
  // Add listener for parents
  addCategoryParentInputListener();
  // Trigger a change event on the select control to set the values
  // of the category controls when loading the page
  $('#categoriesEditSelect').trigger('change');
}

/**
 * Add a listener which implements the behavior for the select control of
 * the category editing modal menu.
 */
function addCategoriesSelectListener() {
  // When the select control changes value
  $('#categoriesEditSelect').on('change', document, function() {
    // Clear the fields
    $('#categories-edit-fields-container > ' +
      'div.field-container > input').each(function() {
        $(this).val('');
      });
    // Get the new value for the category id
    let category = $('#categoriesEditSelect').val();
    // Get a handle on the submit button of the category edit modal menu
    let submitCategoryEditButton = $('#submit-category-edit');
    // If the value doesn't match the new category setting
    if (category === '') {
      // Add blank space to the parents field
      $('#CategoryParentsTextInput').val(' ');
      // Change the submit button to adding new category
      submitCategoryEditButton.html('Add New Category');
      submitCategoryEditButton.prop('value', 'addCategory');
      // Disable the submit button for deleting a category
      $('#submit-category-delete').prop('disabled', true);
    } else {
      // Set the fields to the values matching the category selected
      $('#CategoryNameTextInput').val(categoriesList[category].Name);
      $('#CategoryParentsTextInput')
        .val(categoriesList[category].Parents === null ?
          ' ' :
          categoriesList[category].Parents);
      $('#CategoryDisplayOrderTextInput')
        .val(categoriesList[category].DisplayOrder);
      // Set the submit button to the proper text and value for an edit
      submitCategoryEditButton.html('Save Changes');
      submitCategoryEditButton.prop('value', 'editCategory');
      // Enable the delete category button
      $('#submit-category-delete').removeAttr('disabled');
    }
  });
}

/**
 * Add a listener which implements the behavior needed for the submit
 * button of the category modal menu that allows for edit
 * and add operations.
 */
function addCategoryAddEditSubmitButtonListener() {
  // When the button is clicked
  $('#submit-category-edit').on('click', function(e) {
    // Get the values of the category currently displayed
    let name = $('#CategoryNameTextInput').val();
    let parents = $('#CategoryParentsTextInput').val();
    // Find all the matching categories to the category currently displayed
    let matchingCategories = Object.keys(categoriesList)
      .filter(function(categoryID) {
        if (categoriesList[categoryID].Name === name &&
          (categoriesList[categoryID].Parents === null && parents === " " ||
            categoriesList[categoryID].Parents === parents)) {
          return categoryID;
        }
      });
    // If there is a matching category and the action is to add a category
    if (
      matchingCategories.length > 0 &&
      $('#submit-category-edit').prop('value') === 'addCategory') {
      // Prompt an alert that the category already exists
      window.alert(
        'The category ' +
        categoriesList[matchingCategories[0]].Name +
        ' for parents ' +
        categoriesList[matchingCategories[0]].Parents +
        ' already exists. Please create a unique category.'
      );
      // Prevent the submission of the form
      e.preventDefault();
      // Return a false value
      return false;
    }
  });
}

/**
 * Add a listener which implements the behavior needed for the submit
 * button of the category modal menu that allows for delete operations.
 */
function addCategoryDeleteSubmitButtonListener() {
  // When the button is clicked
  $('#submit-category-delete').on('click', function(e) {
    // Get the current categoryID
    let categoryID = $('#categoriesEditSelect').val();
    // If the category selected matches the new category settings
    if (categoryID === "") {
      // Prompt an alert
      window.alert('You cannot delete a category that doesn\'t exist.\n' +
        ' Please select an appropriate category.');
      // Prevent the submission behavior
      e.preventDefault();
      // Return error
      return false;
    }
    // Find all categories which use the current category as a parent
    let matchingCategories = Object.keys(categoriesList)
      .filter(function(ID) {
        if (categoriesList[ID].Parents !== null && (categoriesList[ID].Parents).search(categoryID) !== -1) {
          return ID;
        }
      });
    if (matchingCategories.length > 0) {
      // Prompt an alert
      window.alert('You cannot delete the ' + categoriesList[categoryID].Name +
        ' category because other categories use it as a parent. Delete the ' +
        'children then you\'ll be able to delete the category.');
      // Prevent the submission behavior
      e.preventDefault();
      // Return error
      return false;
    }
    // Prompt a confirmation of the deletion operation
    let confirmation = window.confirm('Are you sure you want to delete ' +
      'the ' + categoriesList[categoryID].Name + '?');
    // If deletion not confirmed
    if (!confirmation) {
      // Prevent the submission of the form
      e.preventDefault();
      // Return error
      return false;
    }
  });
}

/**
 * Listener on the parents input of the category modal menu which
 * trims the extra whitespace when a character has been added to
 * be compatible with the field validation.
 */
function addCategoryParentInputListener() {
  $('#CategoryParentsTextInput').on('change focusout', function() {
    let parentsValue = $('#CategoryParentsTextInput').val();
    if (parentsValue.length > 1) {
      $('#CategoryParentsTextInput').val($.trim(parentsValue));
    }
  });
}

/**
 * Wrapper function which adds the necessary listeners for the
 * functionality of the documents modal menu
 */
function addDocumentsListeners() {
  // Add listener for changes to the select input
  addDocumentsSelectListener();
  // Trigger a change event on the select control to set the values
  // of the document controls when loading the page
  $('#DataReleaseDocumentID').trigger('change');
}

/**
 * Function which adds a listener on changes to the select
 * element of the documents' modal menu.
 */
function addDocumentsSelectListener() {
  // When the select control changes value
  $('#DataReleaseDocumentID').on('change', document, function() {
    // Clear the fields
    $('#documents-edit-fields-container > div.field-container > input, ' +
      '#documents-edit-fields-container > div.field-container > textarea').each(
        function() {
          $(this).val('');
        });
    // Clear the radio buttons
    $('.documents-category-checkboxes-container > ' +
      '.category-container > ' +
      'input[type=radio]').prop('checked', false);
    // Check the checkbox
    $('#DocumentDisplayLatestCheckboxInput').prop('checked', true);
    // Clear the info section
    $('.info-table-container > ' +
      'p:last-child, .info-table-container >' +
      ' ul:last-child').remove();
    // Get the new value for the document id
    let documentID = $('#DataReleaseDocumentID').val();
    // Get a handle on the submit button of the document edit modal menu
    let submitDocumentEditButton = $('#submit-document-edit');
    // If the value doesn't match the new document setting
    if (documentID === '') {
      // Add empty info node
      $('.info-table-container')
        .append($('<p></p>')
          .addClass('col-md-12')
          .html('No versions associated with the document.'));
      // Change the submit button to adding new version
      submitDocumentEditButton.html('Add New Document');
      submitDocumentEditButton.prop('value', 'addDocument');
      // Disable the submit button for deleting a document
      $('#submit-document-delete').prop('disabled', true);
    } else {
      // Set the fields to the values matching the document selected
      $('#DocumentDisplayNameTextInput')
        .val(documentsList[documentID].DisplayName);
      $('#DocumentDisplayLatestCheckboxInput')
        .prop('checked', documentsList[documentID].displayLatest === '1');
      $('#DocumentDescriptionTextareaInput')
        .val(documentsList[documentID].Description);
      $('#categoryID_' + documentsList[documentID].DataReleaseCategoryID)
        .prop('checked', true);
      // If no versions are specified
      if (!documentsList[documentID].hasOwnProperty('Versions') ||
        Object.keys(documentsList[documentID].Versions).length === 0) {
        // Add empty info node
        $('.info-table-container')
          .append($('<p></p>')
            .addClass('col-md-12')
            .html('No versions associated with the document.'));
        // If versions are specified
      } else {
        let infoNode = $('<ul></ul>').addClass('col-md-12');
        Object.keys(documentsList[documentID].Versions)
          .forEach(function(versionID) {
            infoNode.append($('<li>' +
              documentsList[documentID].Versions[versionID].FileName +
              '</li>'));
          });
        $('.info-table-container').append(infoNode);
      }
      // Set the submit button to the proper text and value for an edit
      submitDocumentEditButton.html('Save Changes');
      submitDocumentEditButton.prop('value', 'editDocument');
      // Enable the delete document button
      $('#submit-document-delete').removeAttr('disabled');
    }
  });
}

/**
 * Wrapper function to add the listeners necessary for the
 * functionality of the versions modal menu.
 */
function addVersionsListeners() {
  // Add listener for changes to the select input
  addVersionsSelectListener();
  // Add listener for submit event on delete button
  addVersionsDeleteButtonListener();
  // Trigger a change event on the select control to set the values
  // of the document controls when loading the page
  $('#DataReleaseID').trigger('change');
}

/**
 * Function which adds a listener for the delete
 * button of the versions' modal menu.
 */
function addVersionsDeleteButtonListener() {
  // When the button is clicked
  $('#submit-version-delete').on('click', function(e) {
    // Get the current versionID
    let versionID = $('#DataReleaseID').val();
    // Prompt a confirmation of the deletion operation
    let confirmation = window.confirm('Are you sure you want to delete ' +
      'version ' + versionsList[versionID].FileName + '?');
    // If deletion not confirmed
    if (!confirmation) {
      // Prevent the submission of the form
      e.preventDefault();
      // Return error
      return false;
    }
  });
}

/**
 * Function which adds a listener for changes to the select
 * element of the versions' modal menu.
 */
function addVersionsSelectListener() {
  // When the select control changes value
  $('#DataReleaseID').on('change', document, function() {
    // Clear the fields
    $('#versions-edit-fields-container > div.field-container > input, ' +
      '#versions-edit-fields-container > div.field-container > textarea, ' +
      '#versions-edit-fields-container > div.field-container > select').each(
      function() {
        $(this).val('');
      });
    // Get the new value for the document id
    let versionID = $('#DataReleaseID').val();
    // If the value doesn't match the new document setting
    if (versionID !== '' && versionID !== null) {
      // Set the fields to the values matching the document selected
      $('#VersionDisplayNameTextInput')
        .val(versionsList[versionID].DisplayName);
      $('#VersionFileNameTextInput').val(versionsList[versionID].FileName);
      $('#VersionAuthorTextInput')
        .val(versionsList[versionID].Author === null ?
          "" :
          versionsList[versionID].Author);
      $('#VersionReferencePaperTextInput')
        .val(versionsList[versionID].ReferencePaper === null ?
          "" :
          versionsList[versionID].ReferencePaper);
      $('#VersionUploadDateTextInput').val(versionsList[versionID].UploadDate);
      $('#VersionDescriptionTextareaInput')
        .val(versionsList[versionID].Description === null ?
          "" :
          versionsList[versionID].Description);
      $('#VersionsDocumentSelectInput')
        .val(versionsList[versionID].DataReleaseDocumentID === null ?
          "" :
          versionsList[versionID].DataReleaseDocumentID);
    }
  });
}

/**
 * Wrapper function for adding the necessary listener for the
 * file upload modal menu
 */
function addFileUploadListeners() {
  // Add File Upload submit button listener
  addFileUploadSubmitButtonListener();
}

/**
 * Listener for the file upload menu's form submission.
 */
function addFileUploadSubmitButtonListener() {
  // When the form is submitted
  $('#upload_version').on('submit', function(e) {
    // Prevent the default
    e.preventDefault();
    // Create an instance of the upload object with a maxsize before chunking
    let uploadObject = new UploadObject(524288000);
    // Get a handle on the file input element's first file
    let fileInput = $('#UploadedFile')[0].files[0];
    // Initialize the upload using the data from the file input
    uploadObject.init(
      fileInput.name,
      fileInput.size);
    // Start the upload
    uploadObject.start();
  });
}

/**
 * Convenience function which detects the presence of hashes in the
 * URL and scrolls to the proper height. Useful because of the header
 * used in the layout.
 */
function adjustScrollForTargetedLinks() {
  // If the address has a hash
  if (window.location.hash !== '') {
    // Adjust scroll height to the element specified
    $(window.location.hash).get(0).scrollIntoView();
  }
}

/**
 * Function which uses the data field defined in each file download link
 * to generate a custom HTML bootstrap tooltip and clears the fields afterwards.
 */
function addTooltips() {
  // For each file download link
  $('a.latest-links, a.historical-links').each(function() {
    // Set the tooltip to HTML and place it to the right
    $(this).tooltip({
      html: true,
      placement: 'right',
      container: 'body'
    });
    // Start building the HTML tooltip with the date
    let htmlTip = '<span class="bold">Upload Date: </span> ' +
      '<span class="tooltip-document-data">' + $(this).attr('latest-uploadDate') +
      '</span><br/>';
    // Add the filename to the HTML tooltip
    htmlTip += '<span class="bold">Filename: </span> ' +
      '<span class="tooltip-document-data">' + $(this).attr('latest-filename') +
      '</span><br/>';
    // If the file description is defined, add it to the tooltip
    if ($(this).attr('latest-description') !== undefined) {
      htmlTip += '<span class="bold">Description: </span> ' +
        '<span class="tooltip-document-data">' + $(this).attr('latest-description') +
        '</span><br/>';
    }
    // If the file author is defined, add it to the tooltip
    if ($(this).attr('latest-author') !== undefined) {
      htmlTip += '<span class="bold">Author: </span> ' +
        '<span class="tooltip-document-data">' + $(this).attr('latest-author') +
        '</span><br/>';
    }
    // If the reference paper is defined, add it to the tooltip
    if ($(this).attr('latest-reference') !== undefined) {
      htmlTip += '<span class="bold">Reference Paper: </span> ' +
        '<span class="tooltip-document-data">' +
        $(this).attr('latest-reference') +
        '</span><br/>';
    }
    // Clear the data field from the link element
    $(this).removeAttr(
      'latest-uploadDate latest-filename latest-description latest-author ' +
      'latest-reference');
    // Set a listener on the tooltip for the show event
    $(this).on('show.bs.tooltip', function(e) {
      // Set the text to the defined tooltip text
      $(e.target).attr('data-original-title', htmlTip);
    });
  });
}
