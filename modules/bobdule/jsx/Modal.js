/**
 * This file contains the React Component for a Modal Window.
 *
 * @author Henri Rabalais
 * @version 1.1.0
 *
 */
import React, {Component} from 'react';
import PropTypes from 'prop-types';
import swal from 'sweetalert2';

/**
 * Modal Component.
 * React wrapper for a Modal Window. Allows to dynamically toggle a Modal
 * window.
 *
 * ================================================
 * Usage:
 * - Wrap the contents to be displayed by the Modal Window by the
 *   Modal Component.
 * - Use the 'title' prop to set a title for the Modal Component.
 * - Use the 'onSubmit' prop to set a submission *promise* object for the
 *   Modal's contents.
 * - Use the 'onClose' prop to set a function that triggers upon Modal closure.
 * - Use the 'throwWarning' prop to throw a warning upon closure of the
 *   Modal Window.
 * =================================================
 *
 */
class Modal extends Component {
  constructor() {
    super();

    this.handleClose = this.handleClose.bind(this);
  }

  handleClose() {
    if (this.props.throwWarning) {
      swal({
        title: 'Are You Sure?',
        text: 'Leaving the form will result in the loss of any information ' +
          'entered.',
        type: 'warning',
        showCancelButton: true,
        confirmButtonText: 'Proceed',
        cancelButtonText: 'Cancel',
      }).then((result) => result.value && this.props.onClose());
    } else {
      this.props.onClose();
    }
  }

  render() {
    const {
      show,
      children,
      candID,
      site,
      previous,
    } = this.props;

    const headerStyle = {
      display: 'flex',
      flexDirection: 'row',
      alignItems: 'center',
      height: '40px',
      borderTopRightRadius: '10',
      fontSize: 24,
      padding: 35,
      borderBottom: '1px solid #DDDDDD',
    };

    const glyphStyle = {
      marginLeft: 'auto',
      cursor: 'pointer',
    };

    const bodyStyle = {
      padding: 15,
      height: 'calc(100% - 130px)',
      overflow: 'auto',
    };

    const modalContainer = {
      display: 'block',
      position: 'fixed',
      zIndex: 9999,
      paddingTop: '100px',
      left: 0,
      top: 0,
      width: '100%',
      height: '100%',
      overflow: 'auto',
      backgroundColor: 'rgba(0,0,0,0.7)',
      visibility: show ? 'visible' : 'hidden',
    };

    const modalContent = {
      opacity: show ? 1 : 0,
      top: show ? 0 : '-300px',
      position: 'relative',
      backgroundColor: '#fefefe',
      borderRadius: '7px',
      margin: 'auto',
      padding: 0,
      border: '1px solid #888',
      width: '90%',
      height: '90%',
      boxShadow: '0 4px 8px 0 rbga(0,0,0,0.2), 0 6px 20px 0 rgba(0,0,0,0.19)',
      transition: 'top 0.4s, opacity 0.4s',
    };

    const renderChildren = () => show && children;

    const footerStyle = {
      borderTop: '1px solid #DDDDDD',
      display: 'flex',
      flexDirection: 'row-reverse',
      alignItems: 'center',
      height: '60px',
      padding: '10px 35px 10px 35px',
    };

    const previousList = Object.keys(previous).map((visit) => {
      const url = `${loris.BaseURL}/final_radiological_review/compare_reviews/?identifier=${previous[visit]}`;
      return (
        <li key={visit}><a href={url} target="_blank">{visit}</a></li>
      );
    });
    const siteURL = `${loris.BaseURL}/instruments/Radiology_Review_VSA/?commentID=${site.commentID}&sessionID=${site.sessionID}&candID=${candID}`;

    return (
      <div style={modalContainer} onClick={this.handleClose}>
        <div
          style={modalContent}
          onClick={(e) => e.stopPropagation()}
        >
          <div style={headerStyle}>
            {`DCCID: ${candID}`}
            <span style={glyphStyle} onClick={this.handleClose}>
              ×
            </span>
          </div>
          <div style={bodyStyle}>
            {renderChildren()}
          </div>
          <div style={footerStyle}>
            <div className="btn-group dropup">
              <button type="button" className="btn btn-default dropdown-toggle" data-toggle="dropdown"
                      aria-haspopup="true" aria-expanded="false">
                View Other Reviews <span className="caret"></span>
              </button>
              <ul className="dropdown-menu">
                <li>
                  <a href={siteURL} target="_blank">Site</a>
                </li>
                {previousList}
              </ul>
            </div>
          </div>
        </div>
      </div>
    );
  }
}

Modal.propTypes = {
  title: PropTypes.string,
  onSubmit: PropTypes.object,
  onClose: PropTypes.func.isRequired,
  show: PropTypes.bool.isRequired,
  throwWarning: PropTypes.bool,
};

Modal.defaultProps = {
  throwWarning: false,
};

export default Modal;
