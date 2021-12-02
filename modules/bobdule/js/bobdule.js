window["lorisjs"] = window["lorisjs"] || {}; window["lorisjs"]["bobdule"] = window["lorisjs"]["bobdule"] || {}; window["lorisjs"]["bobdule"]["bobdule"] =
/******/ (function(modules) { // webpackBootstrap
/******/ 	// The module cache
/******/ 	var installedModules = {};
/******/
/******/ 	// The require function
/******/ 	function __webpack_require__(moduleId) {
/******/
/******/ 		// Check if module is in cache
/******/ 		if(installedModules[moduleId]) {
/******/ 			return installedModules[moduleId].exports;
/******/ 		}
/******/ 		// Create a new module (and put it into the cache)
/******/ 		var module = installedModules[moduleId] = {
/******/ 			i: moduleId,
/******/ 			l: false,
/******/ 			exports: {}
/******/ 		};
/******/
/******/ 		// Execute the module function
/******/ 		modules[moduleId].call(module.exports, module, module.exports, __webpack_require__);
/******/
/******/ 		// Flag the module as loaded
/******/ 		module.l = true;
/******/
/******/ 		// Return the exports of the module
/******/ 		return module.exports;
/******/ 	}
/******/
/******/
/******/ 	// expose the modules object (__webpack_modules__)
/******/ 	__webpack_require__.m = modules;
/******/
/******/ 	// expose the module cache
/******/ 	__webpack_require__.c = installedModules;
/******/
/******/ 	// define getter function for harmony exports
/******/ 	__webpack_require__.d = function(exports, name, getter) {
/******/ 		if(!__webpack_require__.o(exports, name)) {
/******/ 			Object.defineProperty(exports, name, { enumerable: true, get: getter });
/******/ 		}
/******/ 	};
/******/
/******/ 	// define __esModule on exports
/******/ 	__webpack_require__.r = function(exports) {
/******/ 		if(typeof Symbol !== 'undefined' && Symbol.toStringTag) {
/******/ 			Object.defineProperty(exports, Symbol.toStringTag, { value: 'Module' });
/******/ 		}
/******/ 		Object.defineProperty(exports, '__esModule', { value: true });
/******/ 	};
/******/
/******/ 	// create a fake namespace object
/******/ 	// mode & 1: value is a module id, require it
/******/ 	// mode & 2: merge all properties of value into the ns
/******/ 	// mode & 4: return value when already ns object
/******/ 	// mode & 8|1: behave like require
/******/ 	__webpack_require__.t = function(value, mode) {
/******/ 		if(mode & 1) value = __webpack_require__(value);
/******/ 		if(mode & 8) return value;
/******/ 		if((mode & 4) && typeof value === 'object' && value && value.__esModule) return value;
/******/ 		var ns = Object.create(null);
/******/ 		__webpack_require__.r(ns);
/******/ 		Object.defineProperty(ns, 'default', { enumerable: true, value: value });
/******/ 		if(mode & 2 && typeof value != 'string') for(var key in value) __webpack_require__.d(ns, key, function(key) { return value[key]; }.bind(null, key));
/******/ 		return ns;
/******/ 	};
/******/
/******/ 	// getDefaultExport function for compatibility with non-harmony modules
/******/ 	__webpack_require__.n = function(module) {
/******/ 		var getter = module && module.__esModule ?
/******/ 			function getDefault() { return module['default']; } :
/******/ 			function getModuleExports() { return module; };
/******/ 		__webpack_require__.d(getter, 'a', getter);
/******/ 		return getter;
/******/ 	};
/******/
/******/ 	// Object.prototype.hasOwnProperty.call
/******/ 	__webpack_require__.o = function(object, property) { return Object.prototype.hasOwnProperty.call(object, property); };
/******/
/******/ 	// __webpack_public_path__
/******/ 	__webpack_require__.p = "";
/******/
/******/
/******/ 	// Load entry module and return exports
/******/ 	return __webpack_require__(__webpack_require__.s = 0);
/******/ })
/************************************************************************/
/******/ ([
/* 0 */
/***/ (function(module, __webpack_exports__, __webpack_require__) {

"use strict";
__webpack_require__.r(__webpack_exports__);
/* harmony import */ var _babel_runtime_helpers_classCallCheck__WEBPACK_IMPORTED_MODULE_0__ = __webpack_require__(1);
/* harmony import */ var _babel_runtime_helpers_classCallCheck__WEBPACK_IMPORTED_MODULE_0___default = /*#__PURE__*/__webpack_require__.n(_babel_runtime_helpers_classCallCheck__WEBPACK_IMPORTED_MODULE_0__);
/* harmony import */ var _babel_runtime_helpers_createClass__WEBPACK_IMPORTED_MODULE_1__ = __webpack_require__(2);
/* harmony import */ var _babel_runtime_helpers_createClass__WEBPACK_IMPORTED_MODULE_1___default = /*#__PURE__*/__webpack_require__.n(_babel_runtime_helpers_createClass__WEBPACK_IMPORTED_MODULE_1__);
/* harmony import */ var _babel_runtime_helpers_assertThisInitialized__WEBPACK_IMPORTED_MODULE_2__ = __webpack_require__(3);
/* harmony import */ var _babel_runtime_helpers_assertThisInitialized__WEBPACK_IMPORTED_MODULE_2___default = /*#__PURE__*/__webpack_require__.n(_babel_runtime_helpers_assertThisInitialized__WEBPACK_IMPORTED_MODULE_2__);
/* harmony import */ var _babel_runtime_helpers_inherits__WEBPACK_IMPORTED_MODULE_3__ = __webpack_require__(4);
/* harmony import */ var _babel_runtime_helpers_inherits__WEBPACK_IMPORTED_MODULE_3___default = /*#__PURE__*/__webpack_require__.n(_babel_runtime_helpers_inherits__WEBPACK_IMPORTED_MODULE_3__);
/* harmony import */ var _babel_runtime_helpers_possibleConstructorReturn__WEBPACK_IMPORTED_MODULE_4__ = __webpack_require__(6);
/* harmony import */ var _babel_runtime_helpers_possibleConstructorReturn__WEBPACK_IMPORTED_MODULE_4___default = /*#__PURE__*/__webpack_require__.n(_babel_runtime_helpers_possibleConstructorReturn__WEBPACK_IMPORTED_MODULE_4__);
/* harmony import */ var _babel_runtime_helpers_getPrototypeOf__WEBPACK_IMPORTED_MODULE_5__ = __webpack_require__(8);
/* harmony import */ var _babel_runtime_helpers_getPrototypeOf__WEBPACK_IMPORTED_MODULE_5___default = /*#__PURE__*/__webpack_require__.n(_babel_runtime_helpers_getPrototypeOf__WEBPACK_IMPORTED_MODULE_5__);
/* harmony import */ var react__WEBPACK_IMPORTED_MODULE_6__ = __webpack_require__(9);
/* harmony import */ var react__WEBPACK_IMPORTED_MODULE_6___default = /*#__PURE__*/__webpack_require__.n(react__WEBPACK_IMPORTED_MODULE_6__);
/* harmony import */ var FilterableDataTable__WEBPACK_IMPORTED_MODULE_7__ = __webpack_require__(10);
/* harmony import */ var _Modal__WEBPACK_IMPORTED_MODULE_8__ = __webpack_require__(34);
/* harmony import */ var _DirectEntry__WEBPACK_IMPORTED_MODULE_9__ = __webpack_require__(36);







function _createSuper(Derived) { var hasNativeReflectConstruct = _isNativeReflectConstruct(); return function _createSuperInternal() { var Super = _babel_runtime_helpers_getPrototypeOf__WEBPACK_IMPORTED_MODULE_5___default()(Derived), result; if (hasNativeReflectConstruct) { var NewTarget = _babel_runtime_helpers_getPrototypeOf__WEBPACK_IMPORTED_MODULE_5___default()(this).constructor; result = Reflect.construct(Super, arguments, NewTarget); } else { result = Super.apply(this, arguments); } return _babel_runtime_helpers_possibleConstructorReturn__WEBPACK_IMPORTED_MODULE_4___default()(this, result); }; }

function _isNativeReflectConstruct() { if (typeof Reflect === "undefined" || !Reflect.construct) return false; if (Reflect.construct.sham) return false; if (typeof Proxy === "function") return true; try { Boolean.prototype.valueOf.call(Reflect.construct(Boolean, [], function () {})); return true; } catch (e) { return false; } }





/**
 * Module designed for Bob McKinstry to simplify data entry for Final Radiological Form. The module lists all candidates
 * who have obtained either a T1 or T2 scan and do not have any data imputed for the Final Radiological From. The table
 * is an inline form to simplify data entry for normal based scans, prompting for more data entry via a popup when not
 * normal. This module will make calls to automatically input the data taken as well as the examiner. It will also
 * prompt for the examiner to complete the form which will call to mark the form as complete, removing it from the list.
 */

var Bobdule = /*#__PURE__*/function (_Component) {
  _babel_runtime_helpers_inherits__WEBPACK_IMPORTED_MODULE_3___default()(Bobdule, _Component);

  var _super = _createSuper(Bobdule);

  function Bobdule(props) {
    var _this;

    _babel_runtime_helpers_classCallCheck__WEBPACK_IMPORTED_MODULE_0___default()(this, Bobdule);

    _this = _super.call(this, props);
    _this.state = {
      data: [],
      visitOptions: {},
      error: false,
      isLoaded: false,
      commentID: '',
      currentTable: 'incomplete',
      permission: 'view',
      candID: '',
      visit: '',
      site: {},
      previous: {}
    };
    _this.fetchData = _this.fetchData.bind(_babel_runtime_helpers_assertThisInitialized__WEBPACK_IMPORTED_MODULE_2___default()(_this));
    _this.handleData = _this.handleData.bind(_babel_runtime_helpers_assertThisInitialized__WEBPACK_IMPORTED_MODULE_2___default()(_this));
    _this.toggleTable = _this.toggleTable.bind(_babel_runtime_helpers_assertThisInitialized__WEBPACK_IMPORTED_MODULE_2___default()(_this));
    _this.formatColumn = _this.formatColumn.bind(_babel_runtime_helpers_assertThisInitialized__WEBPACK_IMPORTED_MODULE_2___default()(_this));
    _this.updateRecommend = _this.updateRecommend.bind(_babel_runtime_helpers_assertThisInitialized__WEBPACK_IMPORTED_MODULE_2___default()(_this));
    _this.updateRating = _this.updateRating.bind(_babel_runtime_helpers_assertThisInitialized__WEBPACK_IMPORTED_MODULE_2___default()(_this));
    _this.actionClick = _this.actionClick.bind(_babel_runtime_helpers_assertThisInitialized__WEBPACK_IMPORTED_MODULE_2___default()(_this));
    _this.closeModal = _this.closeModal.bind(_babel_runtime_helpers_assertThisInitialized__WEBPACK_IMPORTED_MODULE_2___default()(_this));
    return _this;
  }

  _babel_runtime_helpers_createClass__WEBPACK_IMPORTED_MODULE_1___default()(Bobdule, [{
    key: "componentDidMount",
    value: function componentDidMount() {
      this.fetchData('incomplete');
    }
    /**
     * Call to retrieve all none complete Final Radiological Forms where the candidate has either a T1 or T2 scan.
     *
     * @param {string} status whether view incomplete or complete reviews.
     */

  }, {
    key: "fetchData",
    value: function fetchData(status) {
      var _this2 = this;

      fetch("".concat(loris.BaseURL, "/bobdule/?format=json&status=").concat(status), {
        credentials: 'same-origin'
      }).then(function (resp) {
        return resp.json();
      }).then(function (data) {
        return _this2.handleData(data.Data, data.permission);
      })["catch"](function (error) {
        _this2.setState({
          error: true
        });

        console.error(error);
      });
    }
    /**
     * Map the received data and store it in the state.
     *
     * @param {object} data       the data received from the api
     * @param {string} permission if the user can view or edit the module
     */

  }, {
    key: "handleData",
    value: function handleData(data, permission) {
      var visitOptions = {};
      var formatted = data.map(function (row, i) {
        // Create a list of all possible visits to be used by visit filter dropdown.
        if (!visitOptions[row[4]]) {
          visitOptions[row[4]] = row[4];
        } // First 8 row items are 1 to 1 mapping, store them in new array.


        var formattedRow = row.splice(0, 7);
        formattedRow[5] = formattedRow[6] ? formattedRow[5] : 'no';
        formattedRow[6] = formattedRow[6] ? formattedRow[6] : 'no'; // Map the remaining rows related to the scan rating, storing them as a single JSON string to use at render.

        var rating = {
          'normal': {
            'value': row[0] ? row[0] : 'no',
            'comment': ''
          },
          'atypical': {
            'value': row[1] ? row[1] : 'no',
            'comment': ''
          },
          'abnormal': {
            'value': row[2] ? row[2] : 'no',
            'comment': ''
          }
        };
        formattedRow.push(JSON.stringify(rating));
        formattedRow.push(i);
        return formattedRow;
      });
      this.setState({
        data: formatted,
        visitOptions: visitOptions,
        permission: permission
      });
    }
  }, {
    key: "toggleTable",
    value: function toggleTable() {
      this.fetchData(this.state.currentTable === 'incomplete' ? 'complete' : 'incomplete');
      this.setState(function (state) {
        return {
          currentTable: state.currentTable === 'incomplete' ? 'complete' : 'incomplete'
        };
      });
    }
    /**
     * Update the stored state for the modified recommendation.
     *
     * @param {object} event  the event triggered
     * @param {int} index     the row index in the table
     */

  }, {
    key: "updateRecommend",
    value: function updateRecommend(event, index) {
      var target = event.target;
      var value = target.checked;
      var name = target.name;
      this.setState(function (state) {
        var data = state.data;
        var column = name === 'Recommend Referral for Clinical MRI' ? 5 : 6;
        data[index][column] = value ? 'yes' : 'no';
        state.data = data;
        return state;
      });
    }
    /**
     * Update the stored state for the modified rating.
     *
     * @param {object} event  the event triggered
     * @param {int} index     the row index in the table
     * @param {boolean} check whether or not the value is for the checkbox or comment
     */

  }, {
    key: "updateRating",
    value: function updateRating(event, index, check) {
      var target = event.target;
      var value = target.checked;
      var name = check ? target.name : target.name.split('_')[0];
      this.setState(function (state) {
        var data = state.data;
        var ratings = JSON.parse(data[index][7]);

        if (check) {
          ratings[name].value = value ? 'yes' : 'no';
        } else {
          ratings[name].comment = target.value;
        }

        data[index][7] = JSON.stringify(ratings);
        state.data = data;
        return state;
      });
    }
    /**
     * Row action clicked, handle it based on action type.
     *
     * @param {string} type the action type
     * @param {object} row  the row data
     */

  }, {
    key: "actionClick",
    value: function actionClick(type, row) {
      var _this3 = this;

      var url = "".concat(loris.BaseURL, "/instruments/final_radiological_review_VSA/?commentID=").concat(row['CommentID'], "&sessionID=").concat(row['SessionID'], "&candID=").concat(row['Candidate ID']);

      if (type === 'Launch Form' || type === 'Save and Complete') {
        var rating = JSON.parse(row['Rating']);
        var formData = new FormData();
        formData.append('Date_taken', new Date().toLocaleDateString('en-CA'));
        formData.append('reviewed', 'Bob McKinstry ');
        formData.append('clinical_mri', row['Recommend Referral for Clinical MRI']);
        formData.append('clinical_follow', row['Recommend Clinical Follow up']);
        formData.append('subtest_1_1_check', rating['normal'].value);
        formData.append('subtest_1_1_comment', rating['normal'].comment);
        formData.append('subtest_1_2_check', rating['atypical'].value);
        formData.append('subtest_1_2_comment', rating['atypical'].comment);
        formData.append('subtest_1_3_check', rating['abnormal'].value);
        formData.append('subtest_1_3_comment', rating['abnormal'].comment);
        formData.append('candID', row['Candidate ID']);
        formData.append('sessionID', row['SessionID']);
        formData.append('commentID', row['CommentID']);
        formData.append('test_name', 'final_radiological_review_VSA');
        formData.append('page', '');
        formData.append('subtest', '');
        formData.append('fire_away', 'Save Data'); // Save the current inputted data.

        var post = fetch(url, {
          credentials: 'same-origin',
          method: 'post',
          body: formData
        })["catch"](function (error) {
          _this3.setState({
            error: true
          });

          console.error(error);
        });

        if (type === 'Launch Form') {
          // If action is launch form, launch the form.
          post.then(function () {
            fetch("".concat(loris.BaseURL, "/bobdule/other_reviews/?format=json&candID=").concat(row['Candidate ID'], "&visit=").concat(row['Visit']), {
              credentials: 'same-origin'
            }).then(function (resp) {
              return resp.json();
            }).then(function (data) {
              _this3.setState({
                site: data.site,
                previous: data.previous,
                commentID: row['CommentID'],
                candID: row['Candidate ID'],
                visit: row['Visit']
              });
            })["catch"](function (error) {
              console.error(error);
            });
          });
        } else {
          // Else mark the data as complete.
          post.then(function () {
            return _this3.markComplete(row);
          });
        }
      } else if (type === 'Mark Complete') {
        this.markComplete(row);
      }
    }
    /**
     * Call to mark the row data as complete.
     *
     * @param {object} row the row data.
     */

  }, {
    key: "markComplete",
    value: function markComplete(row) {
      var _this4 = this;

      var formData = new FormData();
      formData.append('candID', row['Candidate ID']);
      formData.append('sessionID', row['SessionID']);
      formData.append('commentID', row['CommentID']);
      formData.append('test_name', 'final_radiological_review_VSA');
      formData.append('setAdministration', 'All');
      formData.append('setValidity', 'Valid');
      formData.append('setDataEntry', 'Complete');
      fetch("".concat(loris.BaseURL, "/bobdule/?format=json"), {
        credentials: 'same-origin',
        method: 'post',
        body: formData
      }).then(function (resp) {
        return resp.json();
      }).then(function (data) {
        return _this4.handleData(data.Data);
      })["catch"](function (error) {
        _this4.setState({
          error: true
        });

        console.error(error);
      });
    }
    /**
     * Close the modal and refetch the new data.
     */

  }, {
    key: "closeModal",
    value: function closeModal() {
      this.setState({
        commentID: '',
        candID: ''
      });
      this.fetchData();
    }
    /**
     * Format the column data.
     *
     * @param {string} column the column to format
     * @param {string} cell   the cell to format
     * @param {object} row    the row data
     * @return {JSX.Element} the formatted cell
     */

  }, {
    key: "formatColumn",
    value: function formatColumn(column, cell, row) {
      var _this5 = this;

      var result = /*#__PURE__*/react__WEBPACK_IMPORTED_MODULE_6___default.a.createElement("td", null, cell);
      var canEdit = this.state.permission === 'edit' && this.state.currentTable === 'incomplete';

      switch (column) {
        case 'Candidate ID':
          // Candidate ID column, render as a link to launch form in new tab.
          return /*#__PURE__*/react__WEBPACK_IMPORTED_MODULE_6___default.a.createElement("td", null, /*#__PURE__*/react__WEBPACK_IMPORTED_MODULE_6___default.a.createElement("a", {
            href: "".concat(loris.BaseURL, "/instruments/final_radiological_review_VSA/?commentID=").concat(row['CommentID'], "&sessionID=").concat(row['SessionID'], "&candID=").concat(row['Candidate ID']),
            target: "_blank"
          }, cell));

        case 'Recommend Referral for Clinical MRI':
        case 'Recommend Clinical Follow up':
          // Referral or Clinical column. If data not yet submitted or the user can edit
          // return as checkbox else display submitted value.
          return row['date'] || !canEdit ? result : /*#__PURE__*/react__WEBPACK_IMPORTED_MODULE_6___default.a.createElement("td", null, /*#__PURE__*/react__WEBPACK_IMPORTED_MODULE_6___default.a.createElement("div", {
            className: "form-check"
          }, /*#__PURE__*/react__WEBPACK_IMPORTED_MODULE_6___default.a.createElement("input", {
            className: "form-check-input position-static",
            type: "checkbox",
            name: column,
            onChange: function onChange(event) {
              return _this5.updateRecommend(event, row['Action']);
            }
          })));

        case 'Rating':
          // Rating column, parse JSON value rendering as a checkbox for each rating value if data not yet submitted, else
          // display submitted values and string.
          var ratings = JSON.parse(cell);

          if (row['date'] || !canEdit) {
            var enabled = [];

            if (ratings['normal'].value === 'yes') {
              enabled.push('Normal');
            }

            if (ratings['atypical'].value === 'yes') {
              enabled.push('Atypical');
            }

            if (ratings['abnormal'].value === 'yes') {
              enabled.push('Abnormal');
            }

            return /*#__PURE__*/react__WEBPACK_IMPORTED_MODULE_6___default.a.createElement("td", null, enabled.join(', '));
          }

          return /*#__PURE__*/react__WEBPACK_IMPORTED_MODULE_6___default.a.createElement("td", null, /*#__PURE__*/react__WEBPACK_IMPORTED_MODULE_6___default.a.createElement("form", null, /*#__PURE__*/react__WEBPACK_IMPORTED_MODULE_6___default.a.createElement("div", {
            className: "form-row align-items-center",
            style: {
              'paddingBottom': '20px'
            }
          }, /*#__PURE__*/react__WEBPACK_IMPORTED_MODULE_6___default.a.createElement("div", {
            className: "form-check form-check-inline"
          }, /*#__PURE__*/react__WEBPACK_IMPORTED_MODULE_6___default.a.createElement("input", {
            className: "form-check-input",
            name: "normal",
            type: "checkbox",
            checked: ratings['normal'].value === 'yes',
            onChange: function onChange(event) {
              return _this5.updateRating(event, row['Action'], true);
            }
          }), /*#__PURE__*/react__WEBPACK_IMPORTED_MODULE_6___default.a.createElement("label", {
            className: "form-check-label",
            style: {
              'paddingLeft': '10px'
            }
          }, "Normal")), /*#__PURE__*/react__WEBPACK_IMPORTED_MODULE_6___default.a.createElement("textarea", {
            className: "form-control",
            name: "normal_comment",
            value: ratings['normal'].comment,
            onChange: function onChange(event) {
              return _this5.updateRating(event, row['Action'], false);
            }
          })), /*#__PURE__*/react__WEBPACK_IMPORTED_MODULE_6___default.a.createElement("div", {
            className: "form-row align-items-center",
            style: {
              'paddingBottom': '20px'
            }
          }, /*#__PURE__*/react__WEBPACK_IMPORTED_MODULE_6___default.a.createElement("div", {
            className: "form-check form-check-inline"
          }, /*#__PURE__*/react__WEBPACK_IMPORTED_MODULE_6___default.a.createElement("input", {
            className: "form-check-input",
            name: "atypical",
            type: "checkbox",
            checked: ratings['atypical'].value === 'yes',
            onChange: function onChange(event) {
              return _this5.updateRating(event, row['Action'], true);
            }
          }), /*#__PURE__*/react__WEBPACK_IMPORTED_MODULE_6___default.a.createElement("label", {
            className: "form-check-label",
            style: {
              'paddingLeft': '10px'
            }
          }, "Atypical")), /*#__PURE__*/react__WEBPACK_IMPORTED_MODULE_6___default.a.createElement("textarea", {
            className: "form-control",
            name: "atypical_comment",
            value: ratings['atypical'].comment,
            onChange: function onChange(event) {
              return _this5.updateRating(event, row['Action'], false);
            }
          })), /*#__PURE__*/react__WEBPACK_IMPORTED_MODULE_6___default.a.createElement("div", {
            className: "form-row align-items-center"
          }, /*#__PURE__*/react__WEBPACK_IMPORTED_MODULE_6___default.a.createElement("div", {
            className: "form-check form-check-inline"
          }, /*#__PURE__*/react__WEBPACK_IMPORTED_MODULE_6___default.a.createElement("input", {
            className: "form-check-input",
            name: "abnormal",
            type: "checkbox",
            checked: ratings['abnormal'].value === 'yes',
            onChange: function onChange(event) {
              return _this5.updateRating(event, row['Action'], true);
            }
          }), /*#__PURE__*/react__WEBPACK_IMPORTED_MODULE_6___default.a.createElement("label", {
            className: "form-check-label",
            style: {
              'paddingLeft': '10px'
            }
          }, "Abnormal")), /*#__PURE__*/react__WEBPACK_IMPORTED_MODULE_6___default.a.createElement("textarea", {
            className: "form-control",
            name: "abnormal_comment",
            value: ratings['abnormal'].comment,
            onChange: function onChange(event) {
              return _this5.updateRating(event, row['Action'], false);
            }
          }))));

        case 'Action':
          // Action column, display action based on row data.
          var rating = JSON.parse(row['Rating']);
          var label;

          if (row['date']) {
            // Data has been submitted, display action to mark form as complete.
            label = 'Mark Complete';
          } else if (rating['atypical'].value === 'yes' || rating['abnormal'].value === 'yes') {
            // User has selected an none normal rating, display action to launch form for more data to be submitted.
            label = 'Launch Form';
          } else if (rating['normal'].value === 'yes') {
            // Normal rating selected, display action to save and complete the form.
            label = 'Save and Complete';
          }

          if (label && canEdit) {
            return /*#__PURE__*/react__WEBPACK_IMPORTED_MODULE_6___default.a.createElement("td", null, /*#__PURE__*/react__WEBPACK_IMPORTED_MODULE_6___default.a.createElement("button", {
              type: "button",
              className: "btn btn-primary",
              onClick: function onClick() {
                return _this5.actionClick(label, row);
              }
            }, label), label === 'Mark Complete' && (rating['atypical'].value === 'yes' || rating['abnormal'].value === 'yes') && /*#__PURE__*/react__WEBPACK_IMPORTED_MODULE_6___default.a.createElement("button", {
              type: "button",
              className: "btn btn-primary",
              onClick: function onClick() {
                return _this5.actionClick('Launch Form', row);
              }
            }, "Launch Form"));
          }

          return /*#__PURE__*/react__WEBPACK_IMPORTED_MODULE_6___default.a.createElement("td", null);

        default:
          return result;
      }
    }
  }, {
    key: "render",
    value: function render() {
      var _this$state = this.state,
          currentTable = _this$state.currentTable,
          permission = _this$state.permission;
      var fields = [{
        label: 'CommentID',
        show: false
      }, {
        label: 'SessionID',
        show: false
      }, {
        label: 'date',
        show: false
      }, {
        label: 'Candidate ID',
        show: true,
        filter: {
          name: 'candID',
          type: 'text'
        }
      }, {
        label: 'Visit',
        show: true,
        filter: {
          name: 'candID',
          type: 'select',
          options: this.state.visitOptions
        }
      }, {
        label: 'Recommend Referral for Clinical MRI',
        show: currentTable === 'complete' || permission === 'edit'
      }, {
        label: 'Recommend Clinical Follow up',
        show: currentTable === 'complete' || permission === 'edit'
      }, {
        label: 'Rating',
        show: currentTable === 'complete' || permission === 'edit'
      }, {
        label: 'Action',
        show: currentTable === 'incomplete' && permission === 'edit'
      }];
      var actions = [{
        label: this.state.currentTable === 'incomplete' ? 'View Completed' : 'View Incomplete',
        action: this.toggleTable
      }];
      return /*#__PURE__*/react__WEBPACK_IMPORTED_MODULE_6___default.a.createElement("div", null, /*#__PURE__*/react__WEBPACK_IMPORTED_MODULE_6___default.a.createElement(FilterableDataTable__WEBPACK_IMPORTED_MODULE_7__["default"], {
        name: 'bobdule_table',
        data: this.state.data,
        fields: fields,
        getFormattedCell: this.formatColumn,
        actions: actions
      }), /*#__PURE__*/react__WEBPACK_IMPORTED_MODULE_6___default.a.createElement(_Modal__WEBPACK_IMPORTED_MODULE_8__["default"], {
        show: this.state.commentID !== '',
        onClose: this.closeModal,
        candID: this.state.candID,
        visit: this.state.visit,
        site: this.state.site,
        previous: this.state.previous
      }, /*#__PURE__*/react__WEBPACK_IMPORTED_MODULE_6___default.a.createElement(_DirectEntry__WEBPACK_IMPORTED_MODULE_9__["default"], {
        commentID: this.state.commentID,
        close: this.closeModal
      })));
    }
  }]);

  return Bobdule;
}(react__WEBPACK_IMPORTED_MODULE_6__["Component"]);

window.addEventListener('load', function () {
  ReactDOM.render( /*#__PURE__*/react__WEBPACK_IMPORTED_MODULE_6___default.a.createElement(Bobdule, null), document.getElementById('lorisworkspace'));
});

/***/ }),
/* 1 */
/***/ (function(module, exports) {

function _classCallCheck(instance, Constructor) {
  if (!(instance instanceof Constructor)) {
    throw new TypeError("Cannot call a class as a function");
  }
}

module.exports = _classCallCheck;
module.exports["default"] = module.exports, module.exports.__esModule = true;

/***/ }),
/* 2 */
/***/ (function(module, exports) {

function _defineProperties(target, props) {
  for (var i = 0; i < props.length; i++) {
    var descriptor = props[i];
    descriptor.enumerable = descriptor.enumerable || false;
    descriptor.configurable = true;
    if ("value" in descriptor) descriptor.writable = true;
    Object.defineProperty(target, descriptor.key, descriptor);
  }
}

function _createClass(Constructor, protoProps, staticProps) {
  if (protoProps) _defineProperties(Constructor.prototype, protoProps);
  if (staticProps) _defineProperties(Constructor, staticProps);
  return Constructor;
}

module.exports = _createClass;
module.exports["default"] = module.exports, module.exports.__esModule = true;

/***/ }),
/* 3 */
/***/ (function(module, exports) {

function _assertThisInitialized(self) {
  if (self === void 0) {
    throw new ReferenceError("this hasn't been initialised - super() hasn't been called");
  }

  return self;
}

module.exports = _assertThisInitialized;
module.exports["default"] = module.exports, module.exports.__esModule = true;

/***/ }),
/* 4 */
/***/ (function(module, exports, __webpack_require__) {

var setPrototypeOf = __webpack_require__(5);

function _inherits(subClass, superClass) {
  if (typeof superClass !== "function" && superClass !== null) {
    throw new TypeError("Super expression must either be null or a function");
  }

  subClass.prototype = Object.create(superClass && superClass.prototype, {
    constructor: {
      value: subClass,
      writable: true,
      configurable: true
    }
  });
  if (superClass) setPrototypeOf(subClass, superClass);
}

module.exports = _inherits;
module.exports["default"] = module.exports, module.exports.__esModule = true;

/***/ }),
/* 5 */
/***/ (function(module, exports) {

function _setPrototypeOf(o, p) {
  module.exports = _setPrototypeOf = Object.setPrototypeOf || function _setPrototypeOf(o, p) {
    o.__proto__ = p;
    return o;
  };

  module.exports["default"] = module.exports, module.exports.__esModule = true;
  return _setPrototypeOf(o, p);
}

module.exports = _setPrototypeOf;
module.exports["default"] = module.exports, module.exports.__esModule = true;

/***/ }),
/* 6 */
/***/ (function(module, exports, __webpack_require__) {

var _typeof = __webpack_require__(7)["default"];

var assertThisInitialized = __webpack_require__(3);

function _possibleConstructorReturn(self, call) {
  if (call && (_typeof(call) === "object" || typeof call === "function")) {
    return call;
  } else if (call !== void 0) {
    throw new TypeError("Derived constructors may only return object or undefined");
  }

  return assertThisInitialized(self);
}

module.exports = _possibleConstructorReturn;
module.exports["default"] = module.exports, module.exports.__esModule = true;

/***/ }),
/* 7 */
/***/ (function(module, exports) {

function _typeof(obj) {
  "@babel/helpers - typeof";

  if (typeof Symbol === "function" && typeof Symbol.iterator === "symbol") {
    module.exports = _typeof = function _typeof(obj) {
      return typeof obj;
    };

    module.exports["default"] = module.exports, module.exports.__esModule = true;
  } else {
    module.exports = _typeof = function _typeof(obj) {
      return obj && typeof Symbol === "function" && obj.constructor === Symbol && obj !== Symbol.prototype ? "symbol" : typeof obj;
    };

    module.exports["default"] = module.exports, module.exports.__esModule = true;
  }

  return _typeof(obj);
}

module.exports = _typeof;
module.exports["default"] = module.exports, module.exports.__esModule = true;

/***/ }),
/* 8 */
/***/ (function(module, exports) {

function _getPrototypeOf(o) {
  module.exports = _getPrototypeOf = Object.setPrototypeOf ? Object.getPrototypeOf : function _getPrototypeOf(o) {
    return o.__proto__ || Object.getPrototypeOf(o);
  };
  module.exports["default"] = module.exports, module.exports.__esModule = true;
  return _getPrototypeOf(o);
}

module.exports = _getPrototypeOf;
module.exports["default"] = module.exports, module.exports.__esModule = true;

/***/ }),
/* 9 */
/***/ (function(module, exports) {

(function() { module.exports = window["React"]; }());

/***/ }),
/* 10 */
/***/ (function(module, __webpack_exports__, __webpack_require__) {

"use strict";
__webpack_require__.r(__webpack_exports__);
/* harmony import */ var _babel_runtime_helpers_slicedToArray__WEBPACK_IMPORTED_MODULE_0__ = __webpack_require__(11);
/* harmony import */ var _babel_runtime_helpers_slicedToArray__WEBPACK_IMPORTED_MODULE_0___default = /*#__PURE__*/__webpack_require__.n(_babel_runtime_helpers_slicedToArray__WEBPACK_IMPORTED_MODULE_0__);
/* harmony import */ var _babel_runtime_helpers_classCallCheck__WEBPACK_IMPORTED_MODULE_1__ = __webpack_require__(1);
/* harmony import */ var _babel_runtime_helpers_classCallCheck__WEBPACK_IMPORTED_MODULE_1___default = /*#__PURE__*/__webpack_require__.n(_babel_runtime_helpers_classCallCheck__WEBPACK_IMPORTED_MODULE_1__);
/* harmony import */ var _babel_runtime_helpers_createClass__WEBPACK_IMPORTED_MODULE_2__ = __webpack_require__(2);
/* harmony import */ var _babel_runtime_helpers_createClass__WEBPACK_IMPORTED_MODULE_2___default = /*#__PURE__*/__webpack_require__.n(_babel_runtime_helpers_createClass__WEBPACK_IMPORTED_MODULE_2__);
/* harmony import */ var _babel_runtime_helpers_assertThisInitialized__WEBPACK_IMPORTED_MODULE_3__ = __webpack_require__(3);
/* harmony import */ var _babel_runtime_helpers_assertThisInitialized__WEBPACK_IMPORTED_MODULE_3___default = /*#__PURE__*/__webpack_require__.n(_babel_runtime_helpers_assertThisInitialized__WEBPACK_IMPORTED_MODULE_3__);
/* harmony import */ var _babel_runtime_helpers_inherits__WEBPACK_IMPORTED_MODULE_4__ = __webpack_require__(4);
/* harmony import */ var _babel_runtime_helpers_inherits__WEBPACK_IMPORTED_MODULE_4___default = /*#__PURE__*/__webpack_require__.n(_babel_runtime_helpers_inherits__WEBPACK_IMPORTED_MODULE_4__);
/* harmony import */ var _babel_runtime_helpers_possibleConstructorReturn__WEBPACK_IMPORTED_MODULE_5__ = __webpack_require__(6);
/* harmony import */ var _babel_runtime_helpers_possibleConstructorReturn__WEBPACK_IMPORTED_MODULE_5___default = /*#__PURE__*/__webpack_require__.n(_babel_runtime_helpers_possibleConstructorReturn__WEBPACK_IMPORTED_MODULE_5__);
/* harmony import */ var _babel_runtime_helpers_getPrototypeOf__WEBPACK_IMPORTED_MODULE_6__ = __webpack_require__(8);
/* harmony import */ var _babel_runtime_helpers_getPrototypeOf__WEBPACK_IMPORTED_MODULE_6___default = /*#__PURE__*/__webpack_require__.n(_babel_runtime_helpers_getPrototypeOf__WEBPACK_IMPORTED_MODULE_6__);
/* harmony import */ var react__WEBPACK_IMPORTED_MODULE_7__ = __webpack_require__(9);
/* harmony import */ var react__WEBPACK_IMPORTED_MODULE_7___default = /*#__PURE__*/__webpack_require__.n(react__WEBPACK_IMPORTED_MODULE_7__);
/* harmony import */ var prop_types__WEBPACK_IMPORTED_MODULE_8__ = __webpack_require__(17);
/* harmony import */ var prop_types__WEBPACK_IMPORTED_MODULE_8___default = /*#__PURE__*/__webpack_require__.n(prop_types__WEBPACK_IMPORTED_MODULE_8__);
/* harmony import */ var jsx_Panel__WEBPACK_IMPORTED_MODULE_9__ = __webpack_require__(24);
/* harmony import */ var jsx_Tabs__WEBPACK_IMPORTED_MODULE_10__ = __webpack_require__(26);
/* harmony import */ var jsx_DataTable__WEBPACK_IMPORTED_MODULE_11__ = __webpack_require__(27);
/* harmony import */ var jsx_Filter__WEBPACK_IMPORTED_MODULE_12__ = __webpack_require__(33);








function _createSuper(Derived) { var hasNativeReflectConstruct = _isNativeReflectConstruct(); return function _createSuperInternal() { var Super = _babel_runtime_helpers_getPrototypeOf__WEBPACK_IMPORTED_MODULE_6___default()(Derived), result; if (hasNativeReflectConstruct) { var NewTarget = _babel_runtime_helpers_getPrototypeOf__WEBPACK_IMPORTED_MODULE_6___default()(this).constructor; result = Reflect.construct(Super, arguments, NewTarget); } else { result = Super.apply(this, arguments); } return _babel_runtime_helpers_possibleConstructorReturn__WEBPACK_IMPORTED_MODULE_5___default()(this, result); }; }

function _isNativeReflectConstruct() { if (typeof Reflect === "undefined" || !Reflect.construct) return false; if (Reflect.construct.sham) return false; if (typeof Proxy === "function") return true; try { Boolean.prototype.valueOf.call(Reflect.construct(Boolean, [], function () {})); return true; } catch (e) { return false; } }







/**
 * FilterableDataTable component.
 * A wrapper for all datatables that handles filtering.
 *
 * Handles the updating and clearing of the filter state based on changes sent
 * from the FitlerForm.
 *
 * Passes the Filter to the Datatable.
 *
 * Deprecates Filter Form.
 */

var FilterableDataTable = /*#__PURE__*/function (_Component) {
  _babel_runtime_helpers_inherits__WEBPACK_IMPORTED_MODULE_4___default()(FilterableDataTable, _Component);

  var _super = _createSuper(FilterableDataTable);

  function FilterableDataTable(props) {
    var _this;

    _babel_runtime_helpers_classCallCheck__WEBPACK_IMPORTED_MODULE_1___default()(this, FilterableDataTable);

    _this = _super.call(this, props);
    _this.state = {
      filters: {}
    };
    _this.updateFilters = _this.updateFilters.bind(_babel_runtime_helpers_assertThisInitialized__WEBPACK_IMPORTED_MODULE_3___default()(_this));
    _this.clearFilters = _this.clearFilters.bind(_babel_runtime_helpers_assertThisInitialized__WEBPACK_IMPORTED_MODULE_3___default()(_this));
    _this.addFilter = _this.addFilter.bind(_babel_runtime_helpers_assertThisInitialized__WEBPACK_IMPORTED_MODULE_3___default()(_this));
    _this.removeFilter = _this.removeFilter.bind(_babel_runtime_helpers_assertThisInitialized__WEBPACK_IMPORTED_MODULE_3___default()(_this));
    return _this;
  }
  /**
   * Updates filter state
   *
   * @param {object} filters
   */


  _babel_runtime_helpers_createClass__WEBPACK_IMPORTED_MODULE_2___default()(FilterableDataTable, [{
    key: "updateFilters",
    value: function updateFilters(filters) {
      this.updateQueryParams(filters);
      this.setState({
        filters: filters
      });
    }
    /**
     * Updates URL Query Params
     *
     * @param {object} filters
     */

  }, {
    key: "updateQueryParams",
    value: function updateQueryParams(filters) {
      var searchParams = new URLSearchParams();
      Object.entries(filters).forEach(function (_ref) {
        var _ref2 = _babel_runtime_helpers_slicedToArray__WEBPACK_IMPORTED_MODULE_0___default()(_ref, 2),
            name = _ref2[0],
            filter = _ref2[1];

        if (filter.value.constructor === Array) {
          filter.value.forEach(function (v) {
            return searchParams.append(name, v);
          });
        } else {
          searchParams.set(name, filter.value);
        }
      });
      history.replaceState({}, '', "?".concat(searchParams.toString()));
    }
    /**
     * Add new filter to the filter object
     *
     * @param {string} name
     * @param {*}      value
     * @param {bool}   exactMatch
     */

  }, {
    key: "addFilter",
    value: function addFilter(name, value, exactMatch) {
      var filters = this.state.filters;
      filters[name] = {
        value: value,
        exactMatch: exactMatch
      };
      this.updateFilters(filters);
    }
    /**
     * Remove filter from the filter object
     *
     * @param {string} name
     */

  }, {
    key: "removeFilter",
    value: function removeFilter(name) {
      var filters = this.state.filters;
      delete filters[name];
      this.updateFilters(filters);
    }
    /**
     * Sets Filter to empty object
     */

  }, {
    key: "clearFilters",
    value: function clearFilters() {
      this.updateFilters({});
    }
  }, {
    key: "render",
    value: function render() {
      var _this2 = this;

      var filter = /*#__PURE__*/react__WEBPACK_IMPORTED_MODULE_7___default.a.createElement(jsx_Filter__WEBPACK_IMPORTED_MODULE_12__["default"], {
        name: this.props.name + '_filter',
        id: this.props.name + '_filter',
        columns: this.props.columns,
        filters: this.state.filters,
        fields: this.props.fields,
        addFilter: this.addFilter,
        removeFilter: this.removeFilter,
        clearFilters: this.clearFilters
      });
      var dataTable = /*#__PURE__*/react__WEBPACK_IMPORTED_MODULE_7___default.a.createElement(jsx_DataTable__WEBPACK_IMPORTED_MODULE_11__["default"], {
        data: this.props.data,
        fields: this.props.fields,
        filters: this.state.filters,
        actions: this.props.actions,
        getFormattedCell: this.props.getFormattedCell,
        getMappedCell: this.props.getMappedCell,
        folder: this.props.folder,
        nullTableShow: this.props.nullTableShow
      });

      var filterPresets = function filterPresets() {
        if (_this2.props.filterPresets) {
          var tabPanes = _this2.props.filterPresets.map(function (preset) {
            return /*#__PURE__*/react__WEBPACK_IMPORTED_MODULE_7___default.a.createElement(jsx_Tabs__WEBPACK_IMPORTED_MODULE_10__["TabPane"], {
              TabId: preset.label,
              key: preset.label
            });
          });

          var tabs = _this2.props.filterPresets.map(function (preset) {
            return {
              id: preset.label,
              label: preset.label
            };
          });

          return /*#__PURE__*/react__WEBPACK_IMPORTED_MODULE_7___default.a.createElement(jsx_Tabs__WEBPACK_IMPORTED_MODULE_10__["Tabs"], {
            tabs: tabs,
            updateURL: true,
            onTabChange: function onTabChange(tabId) {
              var active = _this2.props.filterPresets.find(function (preset) {
                return preset.label === tabId;
              });

              _this2.updateFilters(active.filter);
            }
          }, tabPanes);
        }

        ;
      };

      return /*#__PURE__*/react__WEBPACK_IMPORTED_MODULE_7___default.a.createElement(jsx_Panel__WEBPACK_IMPORTED_MODULE_9__["default"], {
        title: this.props.title
      }, filter, this.props.children, filterPresets(), dataTable);
    }
  }]);

  return FilterableDataTable;
}(react__WEBPACK_IMPORTED_MODULE_7__["Component"]);

FilterableDataTable.defaultProps = {
  columns: 3
};
FilterableDataTable.propTypes = {
  name: prop_types__WEBPACK_IMPORTED_MODULE_8___default.a.string.isRequired,
  title: prop_types__WEBPACK_IMPORTED_MODULE_8___default.a.string,
  data: prop_types__WEBPACK_IMPORTED_MODULE_8___default.a.array.isRequired,
  filterPresets: prop_types__WEBPACK_IMPORTED_MODULE_8___default.a.object,
  fields: prop_types__WEBPACK_IMPORTED_MODULE_8___default.a.array.isRequired,
  columns: prop_types__WEBPACK_IMPORTED_MODULE_8___default.a.number,
  getFormattedCell: prop_types__WEBPACK_IMPORTED_MODULE_8___default.a.func,
  actions: prop_types__WEBPACK_IMPORTED_MODULE_8___default.a.array
};
/* harmony default export */ __webpack_exports__["default"] = (FilterableDataTable);

/***/ }),
/* 11 */
/***/ (function(module, exports, __webpack_require__) {

var arrayWithHoles = __webpack_require__(12);

var iterableToArrayLimit = __webpack_require__(13);

var unsupportedIterableToArray = __webpack_require__(14);

var nonIterableRest = __webpack_require__(16);

function _slicedToArray(arr, i) {
  return arrayWithHoles(arr) || iterableToArrayLimit(arr, i) || unsupportedIterableToArray(arr, i) || nonIterableRest();
}

module.exports = _slicedToArray;
module.exports["default"] = module.exports, module.exports.__esModule = true;

/***/ }),
/* 12 */
/***/ (function(module, exports) {

function _arrayWithHoles(arr) {
  if (Array.isArray(arr)) return arr;
}

module.exports = _arrayWithHoles;
module.exports["default"] = module.exports, module.exports.__esModule = true;

/***/ }),
/* 13 */
/***/ (function(module, exports) {

function _iterableToArrayLimit(arr, i) {
  var _i = arr == null ? null : typeof Symbol !== "undefined" && arr[Symbol.iterator] || arr["@@iterator"];

  if (_i == null) return;
  var _arr = [];
  var _n = true;
  var _d = false;

  var _s, _e;

  try {
    for (_i = _i.call(arr); !(_n = (_s = _i.next()).done); _n = true) {
      _arr.push(_s.value);

      if (i && _arr.length === i) break;
    }
  } catch (err) {
    _d = true;
    _e = err;
  } finally {
    try {
      if (!_n && _i["return"] != null) _i["return"]();
    } finally {
      if (_d) throw _e;
    }
  }

  return _arr;
}

module.exports = _iterableToArrayLimit;
module.exports["default"] = module.exports, module.exports.__esModule = true;

/***/ }),
/* 14 */
/***/ (function(module, exports, __webpack_require__) {

var arrayLikeToArray = __webpack_require__(15);

function _unsupportedIterableToArray(o, minLen) {
  if (!o) return;
  if (typeof o === "string") return arrayLikeToArray(o, minLen);
  var n = Object.prototype.toString.call(o).slice(8, -1);
  if (n === "Object" && o.constructor) n = o.constructor.name;
  if (n === "Map" || n === "Set") return Array.from(o);
  if (n === "Arguments" || /^(?:Ui|I)nt(?:8|16|32)(?:Clamped)?Array$/.test(n)) return arrayLikeToArray(o, minLen);
}

module.exports = _unsupportedIterableToArray;
module.exports["default"] = module.exports, module.exports.__esModule = true;

/***/ }),
/* 15 */
/***/ (function(module, exports) {

function _arrayLikeToArray(arr, len) {
  if (len == null || len > arr.length) len = arr.length;

  for (var i = 0, arr2 = new Array(len); i < len; i++) {
    arr2[i] = arr[i];
  }

  return arr2;
}

module.exports = _arrayLikeToArray;
module.exports["default"] = module.exports, module.exports.__esModule = true;

/***/ }),
/* 16 */
/***/ (function(module, exports) {

function _nonIterableRest() {
  throw new TypeError("Invalid attempt to destructure non-iterable instance.\nIn order to be iterable, non-array objects must have a [Symbol.iterator]() method.");
}

module.exports = _nonIterableRest;
module.exports["default"] = module.exports, module.exports.__esModule = true;

/***/ }),
/* 17 */
/***/ (function(module, exports, __webpack_require__) {

/**
 * Copyright (c) 2013-present, Facebook, Inc.
 *
 * This source code is licensed under the MIT license found in the
 * LICENSE file in the root directory of this source tree.
 */

if (true) {
  var ReactIs = __webpack_require__(18);

  // By explicitly using `prop-types` you are opting into new development behavior.
  // http://fb.me/prop-types-in-prod
  var throwOnDirectAccess = true;
  module.exports = __webpack_require__(20)(ReactIs.isElement, throwOnDirectAccess);
} else {}


/***/ }),
/* 18 */
/***/ (function(module, exports, __webpack_require__) {

"use strict";


if (false) {} else {
  module.exports = __webpack_require__(19);
}


/***/ }),
/* 19 */
/***/ (function(module, exports, __webpack_require__) {

"use strict";
/** @license React v16.13.1
 * react-is.development.js
 *
 * Copyright (c) Facebook, Inc. and its affiliates.
 *
 * This source code is licensed under the MIT license found in the
 * LICENSE file in the root directory of this source tree.
 */





if (true) {
  (function() {
'use strict';

// The Symbol used to tag the ReactElement-like types. If there is no native Symbol
// nor polyfill, then a plain number is used for performance.
var hasSymbol = typeof Symbol === 'function' && Symbol.for;
var REACT_ELEMENT_TYPE = hasSymbol ? Symbol.for('react.element') : 0xeac7;
var REACT_PORTAL_TYPE = hasSymbol ? Symbol.for('react.portal') : 0xeaca;
var REACT_FRAGMENT_TYPE = hasSymbol ? Symbol.for('react.fragment') : 0xeacb;
var REACT_STRICT_MODE_TYPE = hasSymbol ? Symbol.for('react.strict_mode') : 0xeacc;
var REACT_PROFILER_TYPE = hasSymbol ? Symbol.for('react.profiler') : 0xead2;
var REACT_PROVIDER_TYPE = hasSymbol ? Symbol.for('react.provider') : 0xeacd;
var REACT_CONTEXT_TYPE = hasSymbol ? Symbol.for('react.context') : 0xeace; // TODO: We don't use AsyncMode or ConcurrentMode anymore. They were temporary
// (unstable) APIs that have been removed. Can we remove the symbols?

var REACT_ASYNC_MODE_TYPE = hasSymbol ? Symbol.for('react.async_mode') : 0xeacf;
var REACT_CONCURRENT_MODE_TYPE = hasSymbol ? Symbol.for('react.concurrent_mode') : 0xeacf;
var REACT_FORWARD_REF_TYPE = hasSymbol ? Symbol.for('react.forward_ref') : 0xead0;
var REACT_SUSPENSE_TYPE = hasSymbol ? Symbol.for('react.suspense') : 0xead1;
var REACT_SUSPENSE_LIST_TYPE = hasSymbol ? Symbol.for('react.suspense_list') : 0xead8;
var REACT_MEMO_TYPE = hasSymbol ? Symbol.for('react.memo') : 0xead3;
var REACT_LAZY_TYPE = hasSymbol ? Symbol.for('react.lazy') : 0xead4;
var REACT_BLOCK_TYPE = hasSymbol ? Symbol.for('react.block') : 0xead9;
var REACT_FUNDAMENTAL_TYPE = hasSymbol ? Symbol.for('react.fundamental') : 0xead5;
var REACT_RESPONDER_TYPE = hasSymbol ? Symbol.for('react.responder') : 0xead6;
var REACT_SCOPE_TYPE = hasSymbol ? Symbol.for('react.scope') : 0xead7;

function isValidElementType(type) {
  return typeof type === 'string' || typeof type === 'function' || // Note: its typeof might be other than 'symbol' or 'number' if it's a polyfill.
  type === REACT_FRAGMENT_TYPE || type === REACT_CONCURRENT_MODE_TYPE || type === REACT_PROFILER_TYPE || type === REACT_STRICT_MODE_TYPE || type === REACT_SUSPENSE_TYPE || type === REACT_SUSPENSE_LIST_TYPE || typeof type === 'object' && type !== null && (type.$$typeof === REACT_LAZY_TYPE || type.$$typeof === REACT_MEMO_TYPE || type.$$typeof === REACT_PROVIDER_TYPE || type.$$typeof === REACT_CONTEXT_TYPE || type.$$typeof === REACT_FORWARD_REF_TYPE || type.$$typeof === REACT_FUNDAMENTAL_TYPE || type.$$typeof === REACT_RESPONDER_TYPE || type.$$typeof === REACT_SCOPE_TYPE || type.$$typeof === REACT_BLOCK_TYPE);
}

function typeOf(object) {
  if (typeof object === 'object' && object !== null) {
    var $$typeof = object.$$typeof;

    switch ($$typeof) {
      case REACT_ELEMENT_TYPE:
        var type = object.type;

        switch (type) {
          case REACT_ASYNC_MODE_TYPE:
          case REACT_CONCURRENT_MODE_TYPE:
          case REACT_FRAGMENT_TYPE:
          case REACT_PROFILER_TYPE:
          case REACT_STRICT_MODE_TYPE:
          case REACT_SUSPENSE_TYPE:
            return type;

          default:
            var $$typeofType = type && type.$$typeof;

            switch ($$typeofType) {
              case REACT_CONTEXT_TYPE:
              case REACT_FORWARD_REF_TYPE:
              case REACT_LAZY_TYPE:
              case REACT_MEMO_TYPE:
              case REACT_PROVIDER_TYPE:
                return $$typeofType;

              default:
                return $$typeof;
            }

        }

      case REACT_PORTAL_TYPE:
        return $$typeof;
    }
  }

  return undefined;
} // AsyncMode is deprecated along with isAsyncMode

var AsyncMode = REACT_ASYNC_MODE_TYPE;
var ConcurrentMode = REACT_CONCURRENT_MODE_TYPE;
var ContextConsumer = REACT_CONTEXT_TYPE;
var ContextProvider = REACT_PROVIDER_TYPE;
var Element = REACT_ELEMENT_TYPE;
var ForwardRef = REACT_FORWARD_REF_TYPE;
var Fragment = REACT_FRAGMENT_TYPE;
var Lazy = REACT_LAZY_TYPE;
var Memo = REACT_MEMO_TYPE;
var Portal = REACT_PORTAL_TYPE;
var Profiler = REACT_PROFILER_TYPE;
var StrictMode = REACT_STRICT_MODE_TYPE;
var Suspense = REACT_SUSPENSE_TYPE;
var hasWarnedAboutDeprecatedIsAsyncMode = false; // AsyncMode should be deprecated

function isAsyncMode(object) {
  {
    if (!hasWarnedAboutDeprecatedIsAsyncMode) {
      hasWarnedAboutDeprecatedIsAsyncMode = true; // Using console['warn'] to evade Babel and ESLint

      console['warn']('The ReactIs.isAsyncMode() alias has been deprecated, ' + 'and will be removed in React 17+. Update your code to use ' + 'ReactIs.isConcurrentMode() instead. It has the exact same API.');
    }
  }

  return isConcurrentMode(object) || typeOf(object) === REACT_ASYNC_MODE_TYPE;
}
function isConcurrentMode(object) {
  return typeOf(object) === REACT_CONCURRENT_MODE_TYPE;
}
function isContextConsumer(object) {
  return typeOf(object) === REACT_CONTEXT_TYPE;
}
function isContextProvider(object) {
  return typeOf(object) === REACT_PROVIDER_TYPE;
}
function isElement(object) {
  return typeof object === 'object' && object !== null && object.$$typeof === REACT_ELEMENT_TYPE;
}
function isForwardRef(object) {
  return typeOf(object) === REACT_FORWARD_REF_TYPE;
}
function isFragment(object) {
  return typeOf(object) === REACT_FRAGMENT_TYPE;
}
function isLazy(object) {
  return typeOf(object) === REACT_LAZY_TYPE;
}
function isMemo(object) {
  return typeOf(object) === REACT_MEMO_TYPE;
}
function isPortal(object) {
  return typeOf(object) === REACT_PORTAL_TYPE;
}
function isProfiler(object) {
  return typeOf(object) === REACT_PROFILER_TYPE;
}
function isStrictMode(object) {
  return typeOf(object) === REACT_STRICT_MODE_TYPE;
}
function isSuspense(object) {
  return typeOf(object) === REACT_SUSPENSE_TYPE;
}

exports.AsyncMode = AsyncMode;
exports.ConcurrentMode = ConcurrentMode;
exports.ContextConsumer = ContextConsumer;
exports.ContextProvider = ContextProvider;
exports.Element = Element;
exports.ForwardRef = ForwardRef;
exports.Fragment = Fragment;
exports.Lazy = Lazy;
exports.Memo = Memo;
exports.Portal = Portal;
exports.Profiler = Profiler;
exports.StrictMode = StrictMode;
exports.Suspense = Suspense;
exports.isAsyncMode = isAsyncMode;
exports.isConcurrentMode = isConcurrentMode;
exports.isContextConsumer = isContextConsumer;
exports.isContextProvider = isContextProvider;
exports.isElement = isElement;
exports.isForwardRef = isForwardRef;
exports.isFragment = isFragment;
exports.isLazy = isLazy;
exports.isMemo = isMemo;
exports.isPortal = isPortal;
exports.isProfiler = isProfiler;
exports.isStrictMode = isStrictMode;
exports.isSuspense = isSuspense;
exports.isValidElementType = isValidElementType;
exports.typeOf = typeOf;
  })();
}


/***/ }),
/* 20 */
/***/ (function(module, exports, __webpack_require__) {

"use strict";
/**
 * Copyright (c) 2013-present, Facebook, Inc.
 *
 * This source code is licensed under the MIT license found in the
 * LICENSE file in the root directory of this source tree.
 */



var ReactIs = __webpack_require__(18);
var assign = __webpack_require__(21);

var ReactPropTypesSecret = __webpack_require__(22);
var checkPropTypes = __webpack_require__(23);

var has = Function.call.bind(Object.prototype.hasOwnProperty);
var printWarning = function() {};

if (true) {
  printWarning = function(text) {
    var message = 'Warning: ' + text;
    if (typeof console !== 'undefined') {
      console.error(message);
    }
    try {
      // --- Welcome to debugging React ---
      // This error was thrown as a convenience so that you can use this stack
      // to find the callsite that caused this warning to fire.
      throw new Error(message);
    } catch (x) {}
  };
}

function emptyFunctionThatReturnsNull() {
  return null;
}

module.exports = function(isValidElement, throwOnDirectAccess) {
  /* global Symbol */
  var ITERATOR_SYMBOL = typeof Symbol === 'function' && Symbol.iterator;
  var FAUX_ITERATOR_SYMBOL = '@@iterator'; // Before Symbol spec.

  /**
   * Returns the iterator method function contained on the iterable object.
   *
   * Be sure to invoke the function with the iterable as context:
   *
   *     var iteratorFn = getIteratorFn(myIterable);
   *     if (iteratorFn) {
   *       var iterator = iteratorFn.call(myIterable);
   *       ...
   *     }
   *
   * @param {?object} maybeIterable
   * @return {?function}
   */
  function getIteratorFn(maybeIterable) {
    var iteratorFn = maybeIterable && (ITERATOR_SYMBOL && maybeIterable[ITERATOR_SYMBOL] || maybeIterable[FAUX_ITERATOR_SYMBOL]);
    if (typeof iteratorFn === 'function') {
      return iteratorFn;
    }
  }

  /**
   * Collection of methods that allow declaration and validation of props that are
   * supplied to React components. Example usage:
   *
   *   var Props = require('ReactPropTypes');
   *   var MyArticle = React.createClass({
   *     propTypes: {
   *       // An optional string prop named "description".
   *       description: Props.string,
   *
   *       // A required enum prop named "category".
   *       category: Props.oneOf(['News','Photos']).isRequired,
   *
   *       // A prop named "dialog" that requires an instance of Dialog.
   *       dialog: Props.instanceOf(Dialog).isRequired
   *     },
   *     render: function() { ... }
   *   });
   *
   * A more formal specification of how these methods are used:
   *
   *   type := array|bool|func|object|number|string|oneOf([...])|instanceOf(...)
   *   decl := ReactPropTypes.{type}(.isRequired)?
   *
   * Each and every declaration produces a function with the same signature. This
   * allows the creation of custom validation functions. For example:
   *
   *  var MyLink = React.createClass({
   *    propTypes: {
   *      // An optional string or URI prop named "href".
   *      href: function(props, propName, componentName) {
   *        var propValue = props[propName];
   *        if (propValue != null && typeof propValue !== 'string' &&
   *            !(propValue instanceof URI)) {
   *          return new Error(
   *            'Expected a string or an URI for ' + propName + ' in ' +
   *            componentName
   *          );
   *        }
   *      }
   *    },
   *    render: function() {...}
   *  });
   *
   * @internal
   */

  var ANONYMOUS = '<<anonymous>>';

  // Important!
  // Keep this list in sync with production version in `./factoryWithThrowingShims.js`.
  var ReactPropTypes = {
    array: createPrimitiveTypeChecker('array'),
    bool: createPrimitiveTypeChecker('boolean'),
    func: createPrimitiveTypeChecker('function'),
    number: createPrimitiveTypeChecker('number'),
    object: createPrimitiveTypeChecker('object'),
    string: createPrimitiveTypeChecker('string'),
    symbol: createPrimitiveTypeChecker('symbol'),

    any: createAnyTypeChecker(),
    arrayOf: createArrayOfTypeChecker,
    element: createElementTypeChecker(),
    elementType: createElementTypeTypeChecker(),
    instanceOf: createInstanceTypeChecker,
    node: createNodeChecker(),
    objectOf: createObjectOfTypeChecker,
    oneOf: createEnumTypeChecker,
    oneOfType: createUnionTypeChecker,
    shape: createShapeTypeChecker,
    exact: createStrictShapeTypeChecker,
  };

  /**
   * inlined Object.is polyfill to avoid requiring consumers ship their own
   * https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Global_Objects/Object/is
   */
  /*eslint-disable no-self-compare*/
  function is(x, y) {
    // SameValue algorithm
    if (x === y) {
      // Steps 1-5, 7-10
      // Steps 6.b-6.e: +0 != -0
      return x !== 0 || 1 / x === 1 / y;
    } else {
      // Step 6.a: NaN == NaN
      return x !== x && y !== y;
    }
  }
  /*eslint-enable no-self-compare*/

  /**
   * We use an Error-like object for backward compatibility as people may call
   * PropTypes directly and inspect their output. However, we don't use real
   * Errors anymore. We don't inspect their stack anyway, and creating them
   * is prohibitively expensive if they are created too often, such as what
   * happens in oneOfType() for any type before the one that matched.
   */
  function PropTypeError(message) {
    this.message = message;
    this.stack = '';
  }
  // Make `instanceof Error` still work for returned errors.
  PropTypeError.prototype = Error.prototype;

  function createChainableTypeChecker(validate) {
    if (true) {
      var manualPropTypeCallCache = {};
      var manualPropTypeWarningCount = 0;
    }
    function checkType(isRequired, props, propName, componentName, location, propFullName, secret) {
      componentName = componentName || ANONYMOUS;
      propFullName = propFullName || propName;

      if (secret !== ReactPropTypesSecret) {
        if (throwOnDirectAccess) {
          // New behavior only for users of `prop-types` package
          var err = new Error(
            'Calling PropTypes validators directly is not supported by the `prop-types` package. ' +
            'Use `PropTypes.checkPropTypes()` to call them. ' +
            'Read more at http://fb.me/use-check-prop-types'
          );
          err.name = 'Invariant Violation';
          throw err;
        } else if ( true && typeof console !== 'undefined') {
          // Old behavior for people using React.PropTypes
          var cacheKey = componentName + ':' + propName;
          if (
            !manualPropTypeCallCache[cacheKey] &&
            // Avoid spamming the console because they are often not actionable except for lib authors
            manualPropTypeWarningCount < 3
          ) {
            printWarning(
              'You are manually calling a React.PropTypes validation ' +
              'function for the `' + propFullName + '` prop on `' + componentName  + '`. This is deprecated ' +
              'and will throw in the standalone `prop-types` package. ' +
              'You may be seeing this warning due to a third-party PropTypes ' +
              'library. See https://fb.me/react-warning-dont-call-proptypes ' + 'for details.'
            );
            manualPropTypeCallCache[cacheKey] = true;
            manualPropTypeWarningCount++;
          }
        }
      }
      if (props[propName] == null) {
        if (isRequired) {
          if (props[propName] === null) {
            return new PropTypeError('The ' + location + ' `' + propFullName + '` is marked as required ' + ('in `' + componentName + '`, but its value is `null`.'));
          }
          return new PropTypeError('The ' + location + ' `' + propFullName + '` is marked as required in ' + ('`' + componentName + '`, but its value is `undefined`.'));
        }
        return null;
      } else {
        return validate(props, propName, componentName, location, propFullName);
      }
    }

    var chainedCheckType = checkType.bind(null, false);
    chainedCheckType.isRequired = checkType.bind(null, true);

    return chainedCheckType;
  }

  function createPrimitiveTypeChecker(expectedType) {
    function validate(props, propName, componentName, location, propFullName, secret) {
      var propValue = props[propName];
      var propType = getPropType(propValue);
      if (propType !== expectedType) {
        // `propValue` being instance of, say, date/regexp, pass the 'object'
        // check, but we can offer a more precise error message here rather than
        // 'of type `object`'.
        var preciseType = getPreciseType(propValue);

        return new PropTypeError('Invalid ' + location + ' `' + propFullName + '` of type ' + ('`' + preciseType + '` supplied to `' + componentName + '`, expected ') + ('`' + expectedType + '`.'));
      }
      return null;
    }
    return createChainableTypeChecker(validate);
  }

  function createAnyTypeChecker() {
    return createChainableTypeChecker(emptyFunctionThatReturnsNull);
  }

  function createArrayOfTypeChecker(typeChecker) {
    function validate(props, propName, componentName, location, propFullName) {
      if (typeof typeChecker !== 'function') {
        return new PropTypeError('Property `' + propFullName + '` of component `' + componentName + '` has invalid PropType notation inside arrayOf.');
      }
      var propValue = props[propName];
      if (!Array.isArray(propValue)) {
        var propType = getPropType(propValue);
        return new PropTypeError('Invalid ' + location + ' `' + propFullName + '` of type ' + ('`' + propType + '` supplied to `' + componentName + '`, expected an array.'));
      }
      for (var i = 0; i < propValue.length; i++) {
        var error = typeChecker(propValue, i, componentName, location, propFullName + '[' + i + ']', ReactPropTypesSecret);
        if (error instanceof Error) {
          return error;
        }
      }
      return null;
    }
    return createChainableTypeChecker(validate);
  }

  function createElementTypeChecker() {
    function validate(props, propName, componentName, location, propFullName) {
      var propValue = props[propName];
      if (!isValidElement(propValue)) {
        var propType = getPropType(propValue);
        return new PropTypeError('Invalid ' + location + ' `' + propFullName + '` of type ' + ('`' + propType + '` supplied to `' + componentName + '`, expected a single ReactElement.'));
      }
      return null;
    }
    return createChainableTypeChecker(validate);
  }

  function createElementTypeTypeChecker() {
    function validate(props, propName, componentName, location, propFullName) {
      var propValue = props[propName];
      if (!ReactIs.isValidElementType(propValue)) {
        var propType = getPropType(propValue);
        return new PropTypeError('Invalid ' + location + ' `' + propFullName + '` of type ' + ('`' + propType + '` supplied to `' + componentName + '`, expected a single ReactElement type.'));
      }
      return null;
    }
    return createChainableTypeChecker(validate);
  }

  function createInstanceTypeChecker(expectedClass) {
    function validate(props, propName, componentName, location, propFullName) {
      if (!(props[propName] instanceof expectedClass)) {
        var expectedClassName = expectedClass.name || ANONYMOUS;
        var actualClassName = getClassName(props[propName]);
        return new PropTypeError('Invalid ' + location + ' `' + propFullName + '` of type ' + ('`' + actualClassName + '` supplied to `' + componentName + '`, expected ') + ('instance of `' + expectedClassName + '`.'));
      }
      return null;
    }
    return createChainableTypeChecker(validate);
  }

  function createEnumTypeChecker(expectedValues) {
    if (!Array.isArray(expectedValues)) {
      if (true) {
        if (arguments.length > 1) {
          printWarning(
            'Invalid arguments supplied to oneOf, expected an array, got ' + arguments.length + ' arguments. ' +
            'A common mistake is to write oneOf(x, y, z) instead of oneOf([x, y, z]).'
          );
        } else {
          printWarning('Invalid argument supplied to oneOf, expected an array.');
        }
      }
      return emptyFunctionThatReturnsNull;
    }

    function validate(props, propName, componentName, location, propFullName) {
      var propValue = props[propName];
      for (var i = 0; i < expectedValues.length; i++) {
        if (is(propValue, expectedValues[i])) {
          return null;
        }
      }

      var valuesString = JSON.stringify(expectedValues, function replacer(key, value) {
        var type = getPreciseType(value);
        if (type === 'symbol') {
          return String(value);
        }
        return value;
      });
      return new PropTypeError('Invalid ' + location + ' `' + propFullName + '` of value `' + String(propValue) + '` ' + ('supplied to `' + componentName + '`, expected one of ' + valuesString + '.'));
    }
    return createChainableTypeChecker(validate);
  }

  function createObjectOfTypeChecker(typeChecker) {
    function validate(props, propName, componentName, location, propFullName) {
      if (typeof typeChecker !== 'function') {
        return new PropTypeError('Property `' + propFullName + '` of component `' + componentName + '` has invalid PropType notation inside objectOf.');
      }
      var propValue = props[propName];
      var propType = getPropType(propValue);
      if (propType !== 'object') {
        return new PropTypeError('Invalid ' + location + ' `' + propFullName + '` of type ' + ('`' + propType + '` supplied to `' + componentName + '`, expected an object.'));
      }
      for (var key in propValue) {
        if (has(propValue, key)) {
          var error = typeChecker(propValue, key, componentName, location, propFullName + '.' + key, ReactPropTypesSecret);
          if (error instanceof Error) {
            return error;
          }
        }
      }
      return null;
    }
    return createChainableTypeChecker(validate);
  }

  function createUnionTypeChecker(arrayOfTypeCheckers) {
    if (!Array.isArray(arrayOfTypeCheckers)) {
       true ? printWarning('Invalid argument supplied to oneOfType, expected an instance of array.') : undefined;
      return emptyFunctionThatReturnsNull;
    }

    for (var i = 0; i < arrayOfTypeCheckers.length; i++) {
      var checker = arrayOfTypeCheckers[i];
      if (typeof checker !== 'function') {
        printWarning(
          'Invalid argument supplied to oneOfType. Expected an array of check functions, but ' +
          'received ' + getPostfixForTypeWarning(checker) + ' at index ' + i + '.'
        );
        return emptyFunctionThatReturnsNull;
      }
    }

    function validate(props, propName, componentName, location, propFullName) {
      for (var i = 0; i < arrayOfTypeCheckers.length; i++) {
        var checker = arrayOfTypeCheckers[i];
        if (checker(props, propName, componentName, location, propFullName, ReactPropTypesSecret) == null) {
          return null;
        }
      }

      return new PropTypeError('Invalid ' + location + ' `' + propFullName + '` supplied to ' + ('`' + componentName + '`.'));
    }
    return createChainableTypeChecker(validate);
  }

  function createNodeChecker() {
    function validate(props, propName, componentName, location, propFullName) {
      if (!isNode(props[propName])) {
        return new PropTypeError('Invalid ' + location + ' `' + propFullName + '` supplied to ' + ('`' + componentName + '`, expected a ReactNode.'));
      }
      return null;
    }
    return createChainableTypeChecker(validate);
  }

  function createShapeTypeChecker(shapeTypes) {
    function validate(props, propName, componentName, location, propFullName) {
      var propValue = props[propName];
      var propType = getPropType(propValue);
      if (propType !== 'object') {
        return new PropTypeError('Invalid ' + location + ' `' + propFullName + '` of type `' + propType + '` ' + ('supplied to `' + componentName + '`, expected `object`.'));
      }
      for (var key in shapeTypes) {
        var checker = shapeTypes[key];
        if (!checker) {
          continue;
        }
        var error = checker(propValue, key, componentName, location, propFullName + '.' + key, ReactPropTypesSecret);
        if (error) {
          return error;
        }
      }
      return null;
    }
    return createChainableTypeChecker(validate);
  }

  function createStrictShapeTypeChecker(shapeTypes) {
    function validate(props, propName, componentName, location, propFullName) {
      var propValue = props[propName];
      var propType = getPropType(propValue);
      if (propType !== 'object') {
        return new PropTypeError('Invalid ' + location + ' `' + propFullName + '` of type `' + propType + '` ' + ('supplied to `' + componentName + '`, expected `object`.'));
      }
      // We need to check all keys in case some are required but missing from
      // props.
      var allKeys = assign({}, props[propName], shapeTypes);
      for (var key in allKeys) {
        var checker = shapeTypes[key];
        if (!checker) {
          return new PropTypeError(
            'Invalid ' + location + ' `' + propFullName + '` key `' + key + '` supplied to `' + componentName + '`.' +
            '\nBad object: ' + JSON.stringify(props[propName], null, '  ') +
            '\nValid keys: ' +  JSON.stringify(Object.keys(shapeTypes), null, '  ')
          );
        }
        var error = checker(propValue, key, componentName, location, propFullName + '.' + key, ReactPropTypesSecret);
        if (error) {
          return error;
        }
      }
      return null;
    }

    return createChainableTypeChecker(validate);
  }

  function isNode(propValue) {
    switch (typeof propValue) {
      case 'number':
      case 'string':
      case 'undefined':
        return true;
      case 'boolean':
        return !propValue;
      case 'object':
        if (Array.isArray(propValue)) {
          return propValue.every(isNode);
        }
        if (propValue === null || isValidElement(propValue)) {
          return true;
        }

        var iteratorFn = getIteratorFn(propValue);
        if (iteratorFn) {
          var iterator = iteratorFn.call(propValue);
          var step;
          if (iteratorFn !== propValue.entries) {
            while (!(step = iterator.next()).done) {
              if (!isNode(step.value)) {
                return false;
              }
            }
          } else {
            // Iterator will provide entry [k,v] tuples rather than values.
            while (!(step = iterator.next()).done) {
              var entry = step.value;
              if (entry) {
                if (!isNode(entry[1])) {
                  return false;
                }
              }
            }
          }
        } else {
          return false;
        }

        return true;
      default:
        return false;
    }
  }

  function isSymbol(propType, propValue) {
    // Native Symbol.
    if (propType === 'symbol') {
      return true;
    }

    // falsy value can't be a Symbol
    if (!propValue) {
      return false;
    }

    // 19.4.3.5 Symbol.prototype[@@toStringTag] === 'Symbol'
    if (propValue['@@toStringTag'] === 'Symbol') {
      return true;
    }

    // Fallback for non-spec compliant Symbols which are polyfilled.
    if (typeof Symbol === 'function' && propValue instanceof Symbol) {
      return true;
    }

    return false;
  }

  // Equivalent of `typeof` but with special handling for array and regexp.
  function getPropType(propValue) {
    var propType = typeof propValue;
    if (Array.isArray(propValue)) {
      return 'array';
    }
    if (propValue instanceof RegExp) {
      // Old webkits (at least until Android 4.0) return 'function' rather than
      // 'object' for typeof a RegExp. We'll normalize this here so that /bla/
      // passes PropTypes.object.
      return 'object';
    }
    if (isSymbol(propType, propValue)) {
      return 'symbol';
    }
    return propType;
  }

  // This handles more types than `getPropType`. Only used for error messages.
  // See `createPrimitiveTypeChecker`.
  function getPreciseType(propValue) {
    if (typeof propValue === 'undefined' || propValue === null) {
      return '' + propValue;
    }
    var propType = getPropType(propValue);
    if (propType === 'object') {
      if (propValue instanceof Date) {
        return 'date';
      } else if (propValue instanceof RegExp) {
        return 'regexp';
      }
    }
    return propType;
  }

  // Returns a string that is postfixed to a warning about an invalid type.
  // For example, "undefined" or "of type array"
  function getPostfixForTypeWarning(value) {
    var type = getPreciseType(value);
    switch (type) {
      case 'array':
      case 'object':
        return 'an ' + type;
      case 'boolean':
      case 'date':
      case 'regexp':
        return 'a ' + type;
      default:
        return type;
    }
  }

  // Returns class name of the object, if any.
  function getClassName(propValue) {
    if (!propValue.constructor || !propValue.constructor.name) {
      return ANONYMOUS;
    }
    return propValue.constructor.name;
  }

  ReactPropTypes.checkPropTypes = checkPropTypes;
  ReactPropTypes.resetWarningCache = checkPropTypes.resetWarningCache;
  ReactPropTypes.PropTypes = ReactPropTypes;

  return ReactPropTypes;
};


/***/ }),
/* 21 */
/***/ (function(module, exports, __webpack_require__) {

"use strict";
/*
object-assign
(c) Sindre Sorhus
@license MIT
*/


/* eslint-disable no-unused-vars */
var getOwnPropertySymbols = Object.getOwnPropertySymbols;
var hasOwnProperty = Object.prototype.hasOwnProperty;
var propIsEnumerable = Object.prototype.propertyIsEnumerable;

function toObject(val) {
	if (val === null || val === undefined) {
		throw new TypeError('Object.assign cannot be called with null or undefined');
	}

	return Object(val);
}

function shouldUseNative() {
	try {
		if (!Object.assign) {
			return false;
		}

		// Detect buggy property enumeration order in older V8 versions.

		// https://bugs.chromium.org/p/v8/issues/detail?id=4118
		var test1 = new String('abc');  // eslint-disable-line no-new-wrappers
		test1[5] = 'de';
		if (Object.getOwnPropertyNames(test1)[0] === '5') {
			return false;
		}

		// https://bugs.chromium.org/p/v8/issues/detail?id=3056
		var test2 = {};
		for (var i = 0; i < 10; i++) {
			test2['_' + String.fromCharCode(i)] = i;
		}
		var order2 = Object.getOwnPropertyNames(test2).map(function (n) {
			return test2[n];
		});
		if (order2.join('') !== '0123456789') {
			return false;
		}

		// https://bugs.chromium.org/p/v8/issues/detail?id=3056
		var test3 = {};
		'abcdefghijklmnopqrst'.split('').forEach(function (letter) {
			test3[letter] = letter;
		});
		if (Object.keys(Object.assign({}, test3)).join('') !==
				'abcdefghijklmnopqrst') {
			return false;
		}

		return true;
	} catch (err) {
		// We don't expect any of the above to throw, but better to be safe.
		return false;
	}
}

module.exports = shouldUseNative() ? Object.assign : function (target, source) {
	var from;
	var to = toObject(target);
	var symbols;

	for (var s = 1; s < arguments.length; s++) {
		from = Object(arguments[s]);

		for (var key in from) {
			if (hasOwnProperty.call(from, key)) {
				to[key] = from[key];
			}
		}

		if (getOwnPropertySymbols) {
			symbols = getOwnPropertySymbols(from);
			for (var i = 0; i < symbols.length; i++) {
				if (propIsEnumerable.call(from, symbols[i])) {
					to[symbols[i]] = from[symbols[i]];
				}
			}
		}
	}

	return to;
};


/***/ }),
/* 22 */
/***/ (function(module, exports, __webpack_require__) {

"use strict";
/**
 * Copyright (c) 2013-present, Facebook, Inc.
 *
 * This source code is licensed under the MIT license found in the
 * LICENSE file in the root directory of this source tree.
 */



var ReactPropTypesSecret = 'SECRET_DO_NOT_PASS_THIS_OR_YOU_WILL_BE_FIRED';

module.exports = ReactPropTypesSecret;


/***/ }),
/* 23 */
/***/ (function(module, exports, __webpack_require__) {

"use strict";
/**
 * Copyright (c) 2013-present, Facebook, Inc.
 *
 * This source code is licensed under the MIT license found in the
 * LICENSE file in the root directory of this source tree.
 */



var printWarning = function() {};

if (true) {
  var ReactPropTypesSecret = __webpack_require__(22);
  var loggedTypeFailures = {};
  var has = Function.call.bind(Object.prototype.hasOwnProperty);

  printWarning = function(text) {
    var message = 'Warning: ' + text;
    if (typeof console !== 'undefined') {
      console.error(message);
    }
    try {
      // --- Welcome to debugging React ---
      // This error was thrown as a convenience so that you can use this stack
      // to find the callsite that caused this warning to fire.
      throw new Error(message);
    } catch (x) {}
  };
}

/**
 * Assert that the values match with the type specs.
 * Error messages are memorized and will only be shown once.
 *
 * @param {object} typeSpecs Map of name to a ReactPropType
 * @param {object} values Runtime values that need to be type-checked
 * @param {string} location e.g. "prop", "context", "child context"
 * @param {string} componentName Name of the component for error messages.
 * @param {?Function} getStack Returns the component stack.
 * @private
 */
function checkPropTypes(typeSpecs, values, location, componentName, getStack) {
  if (true) {
    for (var typeSpecName in typeSpecs) {
      if (has(typeSpecs, typeSpecName)) {
        var error;
        // Prop type validation may throw. In case they do, we don't want to
        // fail the render phase where it didn't fail before. So we log it.
        // After these have been cleaned up, we'll let them throw.
        try {
          // This is intentionally an invariant that gets caught. It's the same
          // behavior as without this statement except with a better message.
          if (typeof typeSpecs[typeSpecName] !== 'function') {
            var err = Error(
              (componentName || 'React class') + ': ' + location + ' type `' + typeSpecName + '` is invalid; ' +
              'it must be a function, usually from the `prop-types` package, but received `' + typeof typeSpecs[typeSpecName] + '`.'
            );
            err.name = 'Invariant Violation';
            throw err;
          }
          error = typeSpecs[typeSpecName](values, typeSpecName, componentName, location, null, ReactPropTypesSecret);
        } catch (ex) {
          error = ex;
        }
        if (error && !(error instanceof Error)) {
          printWarning(
            (componentName || 'React class') + ': type specification of ' +
            location + ' `' + typeSpecName + '` is invalid; the type checker ' +
            'function must return `null` or an `Error` but returned a ' + typeof error + '. ' +
            'You may have forgotten to pass an argument to the type checker ' +
            'creator (arrayOf, instanceOf, objectOf, oneOf, oneOfType, and ' +
            'shape all require an argument).'
          );
        }
        if (error instanceof Error && !(error.message in loggedTypeFailures)) {
          // Only monitor this failure once because there tends to be a lot of the
          // same error.
          loggedTypeFailures[error.message] = true;

          var stack = getStack ? getStack() : '';

          printWarning(
            'Failed ' + location + ' type: ' + error.message + (stack != null ? stack : '')
          );
        }
      }
    }
  }
}

/**
 * Resets warning cache when testing.
 *
 * @private
 */
checkPropTypes.resetWarningCache = function() {
  if (true) {
    loggedTypeFailures = {};
  }
}

module.exports = checkPropTypes;


/***/ }),
/* 24 */
/***/ (function(module, __webpack_exports__, __webpack_require__) {

"use strict";
__webpack_require__.r(__webpack_exports__);
/* harmony import */ var _babel_runtime_helpers_defineProperty__WEBPACK_IMPORTED_MODULE_0__ = __webpack_require__(25);
/* harmony import */ var _babel_runtime_helpers_defineProperty__WEBPACK_IMPORTED_MODULE_0___default = /*#__PURE__*/__webpack_require__.n(_babel_runtime_helpers_defineProperty__WEBPACK_IMPORTED_MODULE_0__);
/* harmony import */ var _babel_runtime_helpers_classCallCheck__WEBPACK_IMPORTED_MODULE_1__ = __webpack_require__(1);
/* harmony import */ var _babel_runtime_helpers_classCallCheck__WEBPACK_IMPORTED_MODULE_1___default = /*#__PURE__*/__webpack_require__.n(_babel_runtime_helpers_classCallCheck__WEBPACK_IMPORTED_MODULE_1__);
/* harmony import */ var _babel_runtime_helpers_createClass__WEBPACK_IMPORTED_MODULE_2__ = __webpack_require__(2);
/* harmony import */ var _babel_runtime_helpers_createClass__WEBPACK_IMPORTED_MODULE_2___default = /*#__PURE__*/__webpack_require__.n(_babel_runtime_helpers_createClass__WEBPACK_IMPORTED_MODULE_2__);
/* harmony import */ var _babel_runtime_helpers_assertThisInitialized__WEBPACK_IMPORTED_MODULE_3__ = __webpack_require__(3);
/* harmony import */ var _babel_runtime_helpers_assertThisInitialized__WEBPACK_IMPORTED_MODULE_3___default = /*#__PURE__*/__webpack_require__.n(_babel_runtime_helpers_assertThisInitialized__WEBPACK_IMPORTED_MODULE_3__);
/* harmony import */ var _babel_runtime_helpers_inherits__WEBPACK_IMPORTED_MODULE_4__ = __webpack_require__(4);
/* harmony import */ var _babel_runtime_helpers_inherits__WEBPACK_IMPORTED_MODULE_4___default = /*#__PURE__*/__webpack_require__.n(_babel_runtime_helpers_inherits__WEBPACK_IMPORTED_MODULE_4__);
/* harmony import */ var _babel_runtime_helpers_possibleConstructorReturn__WEBPACK_IMPORTED_MODULE_5__ = __webpack_require__(6);
/* harmony import */ var _babel_runtime_helpers_possibleConstructorReturn__WEBPACK_IMPORTED_MODULE_5___default = /*#__PURE__*/__webpack_require__.n(_babel_runtime_helpers_possibleConstructorReturn__WEBPACK_IMPORTED_MODULE_5__);
/* harmony import */ var _babel_runtime_helpers_getPrototypeOf__WEBPACK_IMPORTED_MODULE_6__ = __webpack_require__(8);
/* harmony import */ var _babel_runtime_helpers_getPrototypeOf__WEBPACK_IMPORTED_MODULE_6___default = /*#__PURE__*/__webpack_require__.n(_babel_runtime_helpers_getPrototypeOf__WEBPACK_IMPORTED_MODULE_6__);
/* harmony import */ var react__WEBPACK_IMPORTED_MODULE_7__ = __webpack_require__(9);
/* harmony import */ var react__WEBPACK_IMPORTED_MODULE_7___default = /*#__PURE__*/__webpack_require__.n(react__WEBPACK_IMPORTED_MODULE_7__);
/* harmony import */ var prop_types__WEBPACK_IMPORTED_MODULE_8__ = __webpack_require__(17);
/* harmony import */ var prop_types__WEBPACK_IMPORTED_MODULE_8___default = /*#__PURE__*/__webpack_require__.n(prop_types__WEBPACK_IMPORTED_MODULE_8__);








function ownKeys(object, enumerableOnly) { var keys = Object.keys(object); if (Object.getOwnPropertySymbols) { var symbols = Object.getOwnPropertySymbols(object); if (enumerableOnly) { symbols = symbols.filter(function (sym) { return Object.getOwnPropertyDescriptor(object, sym).enumerable; }); } keys.push.apply(keys, symbols); } return keys; }

function _objectSpread(target) { for (var i = 1; i < arguments.length; i++) { var source = arguments[i] != null ? arguments[i] : {}; if (i % 2) { ownKeys(Object(source), true).forEach(function (key) { _babel_runtime_helpers_defineProperty__WEBPACK_IMPORTED_MODULE_0___default()(target, key, source[key]); }); } else if (Object.getOwnPropertyDescriptors) { Object.defineProperties(target, Object.getOwnPropertyDescriptors(source)); } else { ownKeys(Object(source)).forEach(function (key) { Object.defineProperty(target, key, Object.getOwnPropertyDescriptor(source, key)); }); } } return target; }

function _createSuper(Derived) { var hasNativeReflectConstruct = _isNativeReflectConstruct(); return function _createSuperInternal() { var Super = _babel_runtime_helpers_getPrototypeOf__WEBPACK_IMPORTED_MODULE_6___default()(Derived), result; if (hasNativeReflectConstruct) { var NewTarget = _babel_runtime_helpers_getPrototypeOf__WEBPACK_IMPORTED_MODULE_6___default()(this).constructor; result = Reflect.construct(Super, arguments, NewTarget); } else { result = Super.apply(this, arguments); } return _babel_runtime_helpers_possibleConstructorReturn__WEBPACK_IMPORTED_MODULE_5___default()(this, result); }; }

function _isNativeReflectConstruct() { if (typeof Reflect === "undefined" || !Reflect.construct) return false; if (Reflect.construct.sham) return false; if (typeof Proxy === "function") return true; try { Boolean.prototype.valueOf.call(Reflect.construct(Boolean, [], function () {})); return true; } catch (e) { return false; } }

/**
 * This file contains React component for Panel
 *
 * @author Alex I.
 * @version 1.0.0
 *
 */


/**
 * Panel component
 * Wraps children in a collapsible bootstrap panel
 */

var Panel = /*#__PURE__*/function (_Component) {
  _babel_runtime_helpers_inherits__WEBPACK_IMPORTED_MODULE_4___default()(Panel, _Component);

  var _super = _createSuper(Panel);

  /**
   * Construct the React component
   *
   * @param {array} props - The React props
   */
  function Panel(props) {
    var _this;

    _babel_runtime_helpers_classCallCheck__WEBPACK_IMPORTED_MODULE_1___default()(this, Panel);

    _this = _super.call(this, props);
    _this.state = {
      collapsed: _this.props.initCollapsed
    }; // Initialize panel class based on collapsed status

    _this.panelClass = _this.props.initCollapsed ? 'panel-collapse collapse' : 'panel-collapse collapse in';
    _this.toggleCollapsed = _this.toggleCollapsed.bind(_babel_runtime_helpers_assertThisInitialized__WEBPACK_IMPORTED_MODULE_3___default()(_this));
    return _this;
  }
  /**
   * Toggle whether this Panel is displayed as collapsed
   */


  _babel_runtime_helpers_createClass__WEBPACK_IMPORTED_MODULE_2___default()(Panel, [{
    key: "toggleCollapsed",
    value: function toggleCollapsed() {
      this.setState({
        collapsed: !this.state.collapsed
      });
    }
    /**
     * Render the React component
     *
     * @return {object}
     */

  }, {
    key: "render",
    value: function render() {
      // Change arrow direction based on collapse status
      var glyphClass = this.state.collapsed ? 'glyphicon pull-right glyphicon-chevron-down' : 'glyphicon pull-right glyphicon-chevron-up'; // Add panel header, if title is set

      var panelHeading = this.props.title ? /*#__PURE__*/react__WEBPACK_IMPORTED_MODULE_7___default.a.createElement("div", {
        className: "panel-heading",
        onClick: this.toggleCollapsed,
        "data-toggle": "collapse",
        "data-target": '#' + this.props.id,
        style: {
          cursor: 'pointer',
          height: '3em'
        }
      }, this.props.title, /*#__PURE__*/react__WEBPACK_IMPORTED_MODULE_7___default.a.createElement("span", {
        className: glyphClass
      })) : '';
      return /*#__PURE__*/react__WEBPACK_IMPORTED_MODULE_7___default.a.createElement("div", {
        className: "panel panel-primary",
        style: {
          height: this.props.panelSize
        }
      }, panelHeading, /*#__PURE__*/react__WEBPACK_IMPORTED_MODULE_7___default.a.createElement("div", {
        id: this.props.id,
        className: this.panelClass,
        role: "tabpanel",
        style: {
          height: 'calc(100% - 3em)'
        }
      }, /*#__PURE__*/react__WEBPACK_IMPORTED_MODULE_7___default.a.createElement("div", {
        className: "panel-body",
        style: _objectSpread(_objectSpread({}, this.props.style), {}, {
          height: this.props.height
        })
      }, this.props.children)));
    }
  }]);

  return Panel;
}(react__WEBPACK_IMPORTED_MODULE_7__["Component"]);

Panel.propTypes = {
  id: prop_types__WEBPACK_IMPORTED_MODULE_8___default.a.string,
  height: prop_types__WEBPACK_IMPORTED_MODULE_8___default.a.string,
  title: prop_types__WEBPACK_IMPORTED_MODULE_8___default.a.string
};
Panel.defaultProps = {
  initCollapsed: false,
  id: 'default-panel',
  height: '100%'
};
/* harmony default export */ __webpack_exports__["default"] = (Panel);

/***/ }),
/* 25 */
/***/ (function(module, exports) {

function _defineProperty(obj, key, value) {
  if (key in obj) {
    Object.defineProperty(obj, key, {
      value: value,
      enumerable: true,
      configurable: true,
      writable: true
    });
  } else {
    obj[key] = value;
  }

  return obj;
}

module.exports = _defineProperty;
module.exports["default"] = module.exports, module.exports.__esModule = true;

/***/ }),
/* 26 */
/***/ (function(module, __webpack_exports__, __webpack_require__) {

"use strict";
__webpack_require__.r(__webpack_exports__);
/* harmony export (binding) */ __webpack_require__.d(__webpack_exports__, "Tabs", function() { return Tabs; });
/* harmony export (binding) */ __webpack_require__.d(__webpack_exports__, "VerticalTabs", function() { return VerticalTabs; });
/* harmony export (binding) */ __webpack_require__.d(__webpack_exports__, "TabPane", function() { return TabPane; });
/* harmony import */ var _babel_runtime_helpers_classCallCheck__WEBPACK_IMPORTED_MODULE_0__ = __webpack_require__(1);
/* harmony import */ var _babel_runtime_helpers_classCallCheck__WEBPACK_IMPORTED_MODULE_0___default = /*#__PURE__*/__webpack_require__.n(_babel_runtime_helpers_classCallCheck__WEBPACK_IMPORTED_MODULE_0__);
/* harmony import */ var _babel_runtime_helpers_createClass__WEBPACK_IMPORTED_MODULE_1__ = __webpack_require__(2);
/* harmony import */ var _babel_runtime_helpers_createClass__WEBPACK_IMPORTED_MODULE_1___default = /*#__PURE__*/__webpack_require__.n(_babel_runtime_helpers_createClass__WEBPACK_IMPORTED_MODULE_1__);
/* harmony import */ var _babel_runtime_helpers_assertThisInitialized__WEBPACK_IMPORTED_MODULE_2__ = __webpack_require__(3);
/* harmony import */ var _babel_runtime_helpers_assertThisInitialized__WEBPACK_IMPORTED_MODULE_2___default = /*#__PURE__*/__webpack_require__.n(_babel_runtime_helpers_assertThisInitialized__WEBPACK_IMPORTED_MODULE_2__);
/* harmony import */ var _babel_runtime_helpers_inherits__WEBPACK_IMPORTED_MODULE_3__ = __webpack_require__(4);
/* harmony import */ var _babel_runtime_helpers_inherits__WEBPACK_IMPORTED_MODULE_3___default = /*#__PURE__*/__webpack_require__.n(_babel_runtime_helpers_inherits__WEBPACK_IMPORTED_MODULE_3__);
/* harmony import */ var _babel_runtime_helpers_possibleConstructorReturn__WEBPACK_IMPORTED_MODULE_4__ = __webpack_require__(6);
/* harmony import */ var _babel_runtime_helpers_possibleConstructorReturn__WEBPACK_IMPORTED_MODULE_4___default = /*#__PURE__*/__webpack_require__.n(_babel_runtime_helpers_possibleConstructorReturn__WEBPACK_IMPORTED_MODULE_4__);
/* harmony import */ var _babel_runtime_helpers_getPrototypeOf__WEBPACK_IMPORTED_MODULE_5__ = __webpack_require__(8);
/* harmony import */ var _babel_runtime_helpers_getPrototypeOf__WEBPACK_IMPORTED_MODULE_5___default = /*#__PURE__*/__webpack_require__.n(_babel_runtime_helpers_getPrototypeOf__WEBPACK_IMPORTED_MODULE_5__);
/* harmony import */ var react__WEBPACK_IMPORTED_MODULE_6__ = __webpack_require__(9);
/* harmony import */ var react__WEBPACK_IMPORTED_MODULE_6___default = /*#__PURE__*/__webpack_require__.n(react__WEBPACK_IMPORTED_MODULE_6__);
/* harmony import */ var prop_types__WEBPACK_IMPORTED_MODULE_7__ = __webpack_require__(17);
/* harmony import */ var prop_types__WEBPACK_IMPORTED_MODULE_7___default = /*#__PURE__*/__webpack_require__.n(prop_types__WEBPACK_IMPORTED_MODULE_7__);







function _createSuper(Derived) { var hasNativeReflectConstruct = _isNativeReflectConstruct(); return function _createSuperInternal() { var Super = _babel_runtime_helpers_getPrototypeOf__WEBPACK_IMPORTED_MODULE_5___default()(Derived), result; if (hasNativeReflectConstruct) { var NewTarget = _babel_runtime_helpers_getPrototypeOf__WEBPACK_IMPORTED_MODULE_5___default()(this).constructor; result = Reflect.construct(Super, arguments, NewTarget); } else { result = Super.apply(this, arguments); } return _babel_runtime_helpers_possibleConstructorReturn__WEBPACK_IMPORTED_MODULE_4___default()(this, result); }; }

function _isNativeReflectConstruct() { if (typeof Reflect === "undefined" || !Reflect.construct) return false; if (Reflect.construct.sham) return false; if (typeof Proxy === "function") return true; try { Boolean.prototype.valueOf.call(Reflect.construct(Boolean, [], function () {})); return true; } catch (e) { return false; } }

/**
 * This file contains React components for Tabs component.
 *
 * @author Loris Team
 * @version 1.1.0
 *
 */


/**
 * Tabs Component.
 * React wrapper for Bootstrap tabs. Allows to dynamically render tabs
 * and corresponding tab panes.
 *
 * ================================================
 * Usage:
 *
 * 1. Define an array of tabs with IDs and labels
 *
 * `let tabList = [{id: "tab1", label: "This is tab title"}];`
 *
 * 2. Pass tabList as <Tab> property and <TabPane> as child
 *  ```
 * <Tabs tabs={tabList} defaultTab="tab1">
 *   <TabPane TabId={tabList[0].id}>
 *     // Tab content goes here
 *   </TabPane>
 * </Tabs>
 * ```
 * =================================================
 *
 */

var Tabs = /*#__PURE__*/function (_Component) {
  _babel_runtime_helpers_inherits__WEBPACK_IMPORTED_MODULE_3___default()(Tabs, _Component);

  var _super = _createSuper(Tabs);

  /**
   * Construct a Tabs react component
   *
   * @param {array} props - The React props
   */
  function Tabs(props) {
    var _this;

    _babel_runtime_helpers_classCallCheck__WEBPACK_IMPORTED_MODULE_0___default()(this, Tabs);

    _this = _super.call(this, props);
    var hash = window.location.hash;
    var activeTab = '';
    /**
     * Determine the initial active tab in this order
     * 1. Try to infer from the URL, otherwise
     * 2. Try to infer from the defaultTab prop, otherwise
     * 3. Set to be the first tab of the list
     */

    if (_this.props.updateURL && hash) {
      activeTab = hash.substr(1);
    } else if (_this.props.defaultTab) {
      activeTab = _this.props.defaultTab;
    } else if (_this.props.tabs.length > 0) {
      activeTab = _this.props.tabs[0].id;
    }

    _this.state = {
      activeTab: activeTab
    };
    _this.handleClick = _this.handleClick.bind(_babel_runtime_helpers_assertThisInitialized__WEBPACK_IMPORTED_MODULE_2___default()(_this));
    _this.getTabs = _this.getTabs.bind(_babel_runtime_helpers_assertThisInitialized__WEBPACK_IMPORTED_MODULE_2___default()(_this));
    _this.getTabPanes = _this.getTabPanes.bind(_babel_runtime_helpers_assertThisInitialized__WEBPACK_IMPORTED_MODULE_2___default()(_this));
    return _this;
  }
  /**
   * Handle clicks on a tab header to change the active
   * tab. If this.props.updateURL is set, update the window
   * URL and scroll to the top of the page.
   *
   * @param {int} tabId -- The tab clicked on
   * @param {Event} e -- The click event
   */


  _babel_runtime_helpers_createClass__WEBPACK_IMPORTED_MODULE_1___default()(Tabs, [{
    key: "handleClick",
    value: function handleClick(tabId, e) {
      this.setState({
        activeTab: tabId
      });
      this.props.onTabChange(tabId); // Add tab href to URL querystring and scroll the page to top

      if (this.props.updateURL) {
        var scrollDistance = $('body').scrollTop() || $('html').scrollTop();
        window.location.hash = e.target.hash;
        $('html,body').scrollTop(scrollDistance);
      }
    }
    /**
     * Return a list of components for the tab links.
     *
     * @return {array} -- An array of JSX components to represent
     *                    the tab's title
     */

  }, {
    key: "getTabs",
    value: function getTabs() {
      var tabs = this.props.tabs.map(function (tab) {
        var tabClass = this.state.activeTab === tab.id ? 'active' : null;
        var href = '#' + tab.id;
        var tabID = 'tab-' + tab.id;
        return /*#__PURE__*/react__WEBPACK_IMPORTED_MODULE_6___default.a.createElement("li", {
          role: "presentation",
          className: tabClass,
          key: tab.id
        }, /*#__PURE__*/react__WEBPACK_IMPORTED_MODULE_6___default.a.createElement("a", {
          id: tabID,
          href: href,
          role: "tab",
          "data-toggle": "tab",
          onClick: this.handleClick.bind(null, tab.id)
        }, tab.label));
      }.bind(this));
      return tabs;
    }
    /**
     * Return the body of the active tab.
     *
     * @return {object} -- A JSX component of the active tab panel.
     */

  }, {
    key: "getTabPanes",
    value: function getTabPanes() {
      var tabPanes = react__WEBPACK_IMPORTED_MODULE_6___default.a.Children.map(this.props.children, function (child, key) {
        if (child) {
          return /*#__PURE__*/react__WEBPACK_IMPORTED_MODULE_6___default.a.cloneElement(child, {
            activeTab: this.state.activeTab,
            key: key
          });
        }
      }.bind(this));
      return tabPanes;
    }
    /**
     * React lifecycle method
     *
     * @return {object} -- The rendered JSX component
     */

  }, {
    key: "render",
    value: function render() {
      var tabs = this.getTabs();
      var tabPanes = this.getTabPanes();
      var tabStyle = {
        marginLeft: 0,
        marginBottom: '5px'
      };
      return /*#__PURE__*/react__WEBPACK_IMPORTED_MODULE_6___default.a.createElement("div", null, /*#__PURE__*/react__WEBPACK_IMPORTED_MODULE_6___default.a.createElement("ul", {
        className: "nav nav-tabs",
        role: "tablist",
        style: tabStyle
      }, tabs), /*#__PURE__*/react__WEBPACK_IMPORTED_MODULE_6___default.a.createElement("div", {
        className: "tab-content"
      }, tabPanes));
    }
  }]);

  return Tabs;
}(react__WEBPACK_IMPORTED_MODULE_6__["Component"]);

Tabs.propTypes = {
  tabs: prop_types__WEBPACK_IMPORTED_MODULE_7___default.a.array.isRequired,
  defaultTab: prop_types__WEBPACK_IMPORTED_MODULE_7___default.a.string,
  updateURL: prop_types__WEBPACK_IMPORTED_MODULE_7___default.a.bool
};
Tabs.defaultProps = {
  onTabChange: function onTabChange() {},
  // Set updateURL to default to true but allow for change
  // Nested tabs should set this variable to false
  updateURL: true
};
/**
 * VerticalTabs is a React component which dynamically renders
 * a set of vertical tabs corresponding to tab panes.
 */

var VerticalTabs = /*#__PURE__*/function (_Component2) {
  _babel_runtime_helpers_inherits__WEBPACK_IMPORTED_MODULE_3___default()(VerticalTabs, _Component2);

  var _super2 = _createSuper(VerticalTabs);

  /**
   * Construct the Component
   *
   * @param {array} props - array of React props
   */
  function VerticalTabs(props) {
    var _this2;

    _babel_runtime_helpers_classCallCheck__WEBPACK_IMPORTED_MODULE_0___default()(this, VerticalTabs);

    _this2 = _super2.call(this, props);
    var hash = window.location.hash;
    var activeTab = '';
    /**
     * Determine the initial active tab in this order
     * 1. Try to infer from the URL, otherwise
     * 2. Try to infer from the defaultTab prop, otherwise
     * 3. Set to be the first tab of the list
     */

    if (_this2.props.updateURL && hash) {
      activeTab = hash.substr(1);
    } else if (_this2.props.defaultTab) {
      activeTab = _this2.props.defaultTab;
    } else if (_this2.props.tabs.length > 0) {
      activeTab = _this2.props.tabs[0].id;
    }

    _this2.state = {
      activeTab: activeTab
    };
    _this2.handleClick = _this2.handleClick.bind(_babel_runtime_helpers_assertThisInitialized__WEBPACK_IMPORTED_MODULE_2___default()(_this2));
    _this2.getTabs = _this2.getTabs.bind(_babel_runtime_helpers_assertThisInitialized__WEBPACK_IMPORTED_MODULE_2___default()(_this2));
    _this2.getTabPanes = _this2.getTabPanes.bind(_babel_runtime_helpers_assertThisInitialized__WEBPACK_IMPORTED_MODULE_2___default()(_this2));
    return _this2;
  }
  /**
   * Handle clicks on a tab header to change the active
   * tab. If this.props.updateURL is set, update the window
   * URL and scroll to the top of the page.
   *
   * @param {int} tabId -- The tab clicked on
   * @param {Event} e -- The click event
   */


  _babel_runtime_helpers_createClass__WEBPACK_IMPORTED_MODULE_1___default()(VerticalTabs, [{
    key: "handleClick",
    value: function handleClick(tabId, e) {
      this.setState({
        activeTab: tabId
      });
      this.props.onTabChange(tabId); // Add tab href to URL querystring and scroll the page to top

      if (this.props.updateURL) {
        var scrollDistance = $('body').scrollTop() || $('html').scrollTop();
        window.location.hash = e.target.hash;
        $('html,body').scrollTop(scrollDistance);
      }
    }
    /**
     * Return a list of components for the tab links.
     *
     * @return {array} -- An array of JSX components to represent
     *                    the tab's title
     */

  }, {
    key: "getTabs",
    value: function getTabs() {
      var tabs = this.props.tabs.map(function (tab) {
        var tabClass = this.state.activeTab === tab.id ? 'active' : null;
        var href = '#' + tab.id;
        var tabID = 'tab-' + tab.id;
        return /*#__PURE__*/react__WEBPACK_IMPORTED_MODULE_6___default.a.createElement("li", {
          role: "presentation",
          className: tabClass,
          key: tab.id
        }, /*#__PURE__*/react__WEBPACK_IMPORTED_MODULE_6___default.a.createElement("a", {
          id: tabID,
          href: href,
          role: "tab",
          "data-toggle": "tab",
          onClick: this.handleClick.bind(null, tab.id)
        }, tab.label));
      }.bind(this));
      return tabs;
    }
    /**
     * Return the body of the active tab.
     *
     * @return {object} -- A JSX component of the active tab panel.
     */

  }, {
    key: "getTabPanes",
    value: function getTabPanes() {
      var tabPanes = react__WEBPACK_IMPORTED_MODULE_6___default.a.Children.map(this.props.children, function (child, key) {
        if (child) {
          return /*#__PURE__*/react__WEBPACK_IMPORTED_MODULE_6___default.a.cloneElement(child, {
            activeTab: this.state.activeTab,
            key: key
          });
        }
      }.bind(this));
      return tabPanes;
    }
    /**
     * React lifecycle method
     *
     * @return {object}
     */

  }, {
    key: "render",
    value: function render() {
      var tabs = this.getTabs();
      var tabPanes = this.getTabPanes();
      var tabStyle = {
        marginLeft: 0,
        marginBottom: '5px'
      };
      return /*#__PURE__*/react__WEBPACK_IMPORTED_MODULE_6___default.a.createElement("div", null, /*#__PURE__*/react__WEBPACK_IMPORTED_MODULE_6___default.a.createElement("div", {
        className: "tabbable col-md-3 col-sm-3"
      }, /*#__PURE__*/react__WEBPACK_IMPORTED_MODULE_6___default.a.createElement("ul", {
        className: "nav nav-pills nav-stacked",
        role: "tablist",
        style: tabStyle
      }, tabs)), /*#__PURE__*/react__WEBPACK_IMPORTED_MODULE_6___default.a.createElement("div", {
        className: "tab-content col-md-9 col-sm-9"
      }, tabPanes));
    }
  }]);

  return VerticalTabs;
}(react__WEBPACK_IMPORTED_MODULE_6__["Component"]);

VerticalTabs.propTypes = {
  tabs: prop_types__WEBPACK_IMPORTED_MODULE_7___default.a.array.isRequired,
  defaultTab: prop_types__WEBPACK_IMPORTED_MODULE_7___default.a.string,
  updateURL: prop_types__WEBPACK_IMPORTED_MODULE_7___default.a.bool
};
VerticalTabs.defaultProps = {
  onTabChange: function onTabChange() {},
  // Set updateURL to default to true but allow for change
  // Nested tabs should set this variable to false
  updateURL: true
};
/**
 * TabPane component.
 * Used to wrap content for every tab.
 */

var TabPane = /*#__PURE__*/function (_Component3) {
  _babel_runtime_helpers_inherits__WEBPACK_IMPORTED_MODULE_3___default()(TabPane, _Component3);

  var _super3 = _createSuper(TabPane);

  function TabPane() {
    _babel_runtime_helpers_classCallCheck__WEBPACK_IMPORTED_MODULE_0___default()(this, TabPane);

    return _super3.apply(this, arguments);
  }

  _babel_runtime_helpers_createClass__WEBPACK_IMPORTED_MODULE_1___default()(TabPane, [{
    key: "render",
    value:
    /**
     * React lifecycle method
     *
     * @return {object}
     */
    function render() {
      var classList = 'tab-pane';
      var title;

      if (this.props.TabId === this.props.activeTab) {
        classList += ' active';
      }

      if (this.props.Title) {
        title = /*#__PURE__*/react__WEBPACK_IMPORTED_MODULE_6___default.a.createElement("h1", null, this.props.Title);
      }

      return /*#__PURE__*/react__WEBPACK_IMPORTED_MODULE_6___default.a.createElement("div", {
        role: "tabpanel",
        className: classList,
        id: this.props.TabId
      }, title, this.props.children);
    }
  }]);

  return TabPane;
}(react__WEBPACK_IMPORTED_MODULE_6__["Component"]);

TabPane.propTypes = {
  TabId: prop_types__WEBPACK_IMPORTED_MODULE_7___default.a.string.isRequired,
  Title: prop_types__WEBPACK_IMPORTED_MODULE_7___default.a.string,
  activeTab: prop_types__WEBPACK_IMPORTED_MODULE_7___default.a.string
};


/***/ }),
/* 27 */
/***/ (function(module, __webpack_exports__, __webpack_require__) {

"use strict";
__webpack_require__.r(__webpack_exports__);
/* harmony import */ var _babel_runtime_helpers_typeof__WEBPACK_IMPORTED_MODULE_0__ = __webpack_require__(7);
/* harmony import */ var _babel_runtime_helpers_typeof__WEBPACK_IMPORTED_MODULE_0___default = /*#__PURE__*/__webpack_require__.n(_babel_runtime_helpers_typeof__WEBPACK_IMPORTED_MODULE_0__);
/* harmony import */ var _babel_runtime_helpers_classCallCheck__WEBPACK_IMPORTED_MODULE_1__ = __webpack_require__(1);
/* harmony import */ var _babel_runtime_helpers_classCallCheck__WEBPACK_IMPORTED_MODULE_1___default = /*#__PURE__*/__webpack_require__.n(_babel_runtime_helpers_classCallCheck__WEBPACK_IMPORTED_MODULE_1__);
/* harmony import */ var _babel_runtime_helpers_createClass__WEBPACK_IMPORTED_MODULE_2__ = __webpack_require__(2);
/* harmony import */ var _babel_runtime_helpers_createClass__WEBPACK_IMPORTED_MODULE_2___default = /*#__PURE__*/__webpack_require__.n(_babel_runtime_helpers_createClass__WEBPACK_IMPORTED_MODULE_2__);
/* harmony import */ var _babel_runtime_helpers_assertThisInitialized__WEBPACK_IMPORTED_MODULE_3__ = __webpack_require__(3);
/* harmony import */ var _babel_runtime_helpers_assertThisInitialized__WEBPACK_IMPORTED_MODULE_3___default = /*#__PURE__*/__webpack_require__.n(_babel_runtime_helpers_assertThisInitialized__WEBPACK_IMPORTED_MODULE_3__);
/* harmony import */ var _babel_runtime_helpers_inherits__WEBPACK_IMPORTED_MODULE_4__ = __webpack_require__(4);
/* harmony import */ var _babel_runtime_helpers_inherits__WEBPACK_IMPORTED_MODULE_4___default = /*#__PURE__*/__webpack_require__.n(_babel_runtime_helpers_inherits__WEBPACK_IMPORTED_MODULE_4__);
/* harmony import */ var _babel_runtime_helpers_possibleConstructorReturn__WEBPACK_IMPORTED_MODULE_5__ = __webpack_require__(6);
/* harmony import */ var _babel_runtime_helpers_possibleConstructorReturn__WEBPACK_IMPORTED_MODULE_5___default = /*#__PURE__*/__webpack_require__.n(_babel_runtime_helpers_possibleConstructorReturn__WEBPACK_IMPORTED_MODULE_5__);
/* harmony import */ var _babel_runtime_helpers_getPrototypeOf__WEBPACK_IMPORTED_MODULE_6__ = __webpack_require__(8);
/* harmony import */ var _babel_runtime_helpers_getPrototypeOf__WEBPACK_IMPORTED_MODULE_6___default = /*#__PURE__*/__webpack_require__.n(_babel_runtime_helpers_getPrototypeOf__WEBPACK_IMPORTED_MODULE_6__);
/* harmony import */ var react__WEBPACK_IMPORTED_MODULE_7__ = __webpack_require__(9);
/* harmony import */ var react__WEBPACK_IMPORTED_MODULE_7___default = /*#__PURE__*/__webpack_require__.n(react__WEBPACK_IMPORTED_MODULE_7__);
/* harmony import */ var prop_types__WEBPACK_IMPORTED_MODULE_8__ = __webpack_require__(17);
/* harmony import */ var prop_types__WEBPACK_IMPORTED_MODULE_8___default = /*#__PURE__*/__webpack_require__.n(prop_types__WEBPACK_IMPORTED_MODULE_8__);
/* harmony import */ var jsx_PaginationLinks__WEBPACK_IMPORTED_MODULE_9__ = __webpack_require__(28);
/* harmony import */ var react_addons_create_fragment__WEBPACK_IMPORTED_MODULE_10__ = __webpack_require__(29);
/* harmony import */ var react_addons_create_fragment__WEBPACK_IMPORTED_MODULE_10___default = /*#__PURE__*/__webpack_require__.n(react_addons_create_fragment__WEBPACK_IMPORTED_MODULE_10__);








function _createSuper(Derived) { var hasNativeReflectConstruct = _isNativeReflectConstruct(); return function _createSuperInternal() { var Super = _babel_runtime_helpers_getPrototypeOf__WEBPACK_IMPORTED_MODULE_6___default()(Derived), result; if (hasNativeReflectConstruct) { var NewTarget = _babel_runtime_helpers_getPrototypeOf__WEBPACK_IMPORTED_MODULE_6___default()(this).constructor; result = Reflect.construct(Super, arguments, NewTarget); } else { result = Super.apply(this, arguments); } return _babel_runtime_helpers_possibleConstructorReturn__WEBPACK_IMPORTED_MODULE_5___default()(this, result); }; }

function _isNativeReflectConstruct() { if (typeof Reflect === "undefined" || !Reflect.construct) return false; if (Reflect.construct.sham) return false; if (typeof Proxy === "function") return true; try { Boolean.prototype.valueOf.call(Reflect.construct(Boolean, [], function () {})); return true; } catch (e) { return false; } }





/**
 * Data Table component
 * Displays a set of data that is receives via props.
 */

var DataTable = /*#__PURE__*/function (_Component) {
  _babel_runtime_helpers_inherits__WEBPACK_IMPORTED_MODULE_4___default()(DataTable, _Component);

  var _super = _createSuper(DataTable);

  function DataTable(props) {
    var _this;

    _babel_runtime_helpers_classCallCheck__WEBPACK_IMPORTED_MODULE_1___default()(this, DataTable);

    _this = _super.call(this, props);
    _this.state = {
      page: {
        number: 1,
        rows: 20
      },
      sort: {
        column: -1,
        ascending: true
      }
    };
    _this.changePage = _this.changePage.bind(_babel_runtime_helpers_assertThisInitialized__WEBPACK_IMPORTED_MODULE_3___default()(_this));
    _this.setSortColumn = _this.setSortColumn.bind(_babel_runtime_helpers_assertThisInitialized__WEBPACK_IMPORTED_MODULE_3___default()(_this));
    _this.updateSortColumn = _this.updateSortColumn.bind(_babel_runtime_helpers_assertThisInitialized__WEBPACK_IMPORTED_MODULE_3___default()(_this));
    _this.toggleSortOrder = _this.toggleSortOrder.bind(_babel_runtime_helpers_assertThisInitialized__WEBPACK_IMPORTED_MODULE_3___default()(_this));
    _this.updatePageNumber = _this.updatePageNumber.bind(_babel_runtime_helpers_assertThisInitialized__WEBPACK_IMPORTED_MODULE_3___default()(_this));
    _this.updatePageRows = _this.updatePageRows.bind(_babel_runtime_helpers_assertThisInitialized__WEBPACK_IMPORTED_MODULE_3___default()(_this));
    _this.downloadCSV = _this.downloadCSV.bind(_babel_runtime_helpers_assertThisInitialized__WEBPACK_IMPORTED_MODULE_3___default()(_this));
    _this.getFilteredRowIndexes = _this.getFilteredRowIndexes.bind(_babel_runtime_helpers_assertThisInitialized__WEBPACK_IMPORTED_MODULE_3___default()(_this));
    _this.sortRows = _this.sortRows.bind(_babel_runtime_helpers_assertThisInitialized__WEBPACK_IMPORTED_MODULE_3___default()(_this));
    _this.hasFilterKeyword = _this.hasFilterKeyword.bind(_babel_runtime_helpers_assertThisInitialized__WEBPACK_IMPORTED_MODULE_3___default()(_this));
    _this.renderActions = _this.renderActions.bind(_babel_runtime_helpers_assertThisInitialized__WEBPACK_IMPORTED_MODULE_3___default()(_this));
    return _this;
  }

  _babel_runtime_helpers_createClass__WEBPACK_IMPORTED_MODULE_2___default()(DataTable, [{
    key: "changePage",
    value: function changePage(i) {
      var page = this.state.page;
      page.number = i;
      this.setState({
        page: page
      });
    }
  }, {
    key: "setSortColumn",
    value: function setSortColumn(column) {
      if (this.state.sort.column === column) {
        this.toggleSortOrder();
      } else {
        this.updateSortColumn(column);
      }
    }
  }, {
    key: "updateSortColumn",
    value: function updateSortColumn(column) {
      var sort = this.state.sort;
      sort.column = column;
      this.setState({
        sort: sort
      });
    }
  }, {
    key: "toggleSortOrder",
    value: function toggleSortOrder() {
      var sort = this.state.sort;
      sort.ascending = !sort.ascending;
      this.setState({
        sort: sort
      });
    }
    /**
     * Updates page state
     *
     * @param {int} number of page
     */

  }, {
    key: "updatePageNumber",
    value: function updatePageNumber(number) {
      var page = this.sate.page;
      page.number = number;
      this.setState({
        page: page
      });
    }
    /**
     * Update number of rows per page
     *
     * @param {object} e event from which to abstract value
     */

  }, {
    key: "updatePageRows",
    value: function updatePageRows(e) {
      var page = Object.assign({}, this.state.page);
      page.rows = e.target.value;
      page.number = 1;
      this.setState({
        page: page
      });
    }
  }, {
    key: "downloadCSV",
    value: function downloadCSV(filteredRowIndexes) {
      var _this2 = this;

      var csvData = filteredRowIndexes.map(function (id) {
        return _this2.props.data[id];
      }); // Map cell data to proper values if applicable.

      if (this.props.getMappedCell) {
        csvData = csvData.map(function (row, i) {
          return _this2.props.fields.map(function (field, j) {
            return _this2.props.getMappedCell(field.label, row[j]);
          });
        });
      }

      var csvworker = new Worker(loris.BaseURL + '/js/workers/savecsv.js');
      csvworker.addEventListener('message', function (e) {
        var dataURL;
        var dataDate;
        var link;

        if (e.data.cmd === 'SaveCSV') {
          dataDate = new Date().toISOString();
          dataURL = window.URL.createObjectURL(e.data.message);
          link = document.createElement('a');
          link.download = 'data-' + dataDate + '.csv';
          link.type = 'text/csv';
          link.href = dataURL;
          document.body.appendChild(link);
          $(link)[0].click();
          document.body.removeChild(link);
        }
      });
      var headerList = this.props.fields.map(function (field) {
        return field.label;
      });
      csvworker.postMessage({
        cmd: 'SaveFile',
        data: csvData,
        headers: headerList,
        identifiers: this.props.RowNameMap
      });
    }
  }, {
    key: "getFilteredRowIndexes",
    value: function getFilteredRowIndexes() {
      var useKeyword = false;
      var filterValuesCount = Object.keys(this.props.filters).length;
      var tableData = this.props.data;
      var fieldData = this.props.fields;
      var filteredIndexes = []; // If there are no filters set, use all the data.

      var hasFilters = filterValuesCount !== 0;

      if (hasFilters === false) {
        for (var i = 0; i < tableData.length; i++) {
          filteredIndexes.push(i);
        }

        return filteredIndexes;
      }

      if (this.props.filters.keyword) {
        useKeyword = true;
      }

      if (useKeyword) {
        filterValuesCount -= 1;
      }

      for (var _i = 0; _i < tableData.length; _i++) {
        var headerCount = 0;
        var keywordMatch = 0;

        for (var j = 0; j < fieldData.length; j++) {
          var data = tableData[_i] ? tableData[_i][j] : null;

          if (this.hasFilterKeyword((fieldData[j].filter || {}).name, data)) {
            headerCount++;
          }

          if (useKeyword) {
            if (this.hasFilterKeyword('keyword', data)) {
              keywordMatch++;
            }
          }
        }

        if (headerCount === filterValuesCount && (useKeyword === true && keywordMatch > 0 || useKeyword === false && keywordMatch === 0)) {
          filteredIndexes.push(_i);
        }
      }

      return filteredIndexes;
    }
  }, {
    key: "sortRows",
    value: function sortRows(rowIndexes) {
      var _this3 = this;

      var index = [];

      for (var i = 0; i < rowIndexes.length; i++) {
        var idx = rowIndexes[i];
        var val = this.props.data[idx][this.state.sort.column] || undefined; // If sortColumn is equal to default No. column, set value to be
        // index + 1

        if (this.state.sort.column === -1) {
          val = idx + 1;
        }

        var isString = typeof val === 'string' || val instanceof String;
        var isNumber = !isNaN(val) && _babel_runtime_helpers_typeof__WEBPACK_IMPORTED_MODULE_0___default()(val) !== 'object';

        if (val === '.') {
          // hack to handle non-existent items in DQT
          val = null;
        } else if (isNumber) {
          // perform type conversion (from string to int/float)
          val = Number(val);
        } else if (isString) {
          // if string with text convert to lowercase
          val = val.toLowerCase();
        } else if (Array.isArray(val)) {
          val = val.join(', ');
        } else {
          val = undefined;
        }

        if (this.props.RowNameMap) {
          index.push({
            RowIdx: idx,
            Value: val,
            Content: this.props.RowNameMap[idx]
          });
        } else {
          index.push({
            RowIdx: idx,
            Value: val,
            Content: idx + 1
          });
        }
      }

      index.sort(function (a, b) {
        if (_this3.state.sort.ascending) {
          if (a.Value === b.Value) {
            // If all values are equal, sort by rownum
            if (a.RowIdx < b.RowIdx) return -1;
            if (a.RowIdx > b.RowIdx) return 1;
          } // Check if null values


          if (a.Value === null || typeof a.Value === 'undefined') return -1;
          if (b.Value === null || typeof b.Value === 'undefined') return 1; // Sort by value

          if (a.Value < b.Value) return -1;
          if (a.Value > b.Value) return 1;
        } else {
          if (a.Value === b.Value) {
            // If all values are equal, sort by rownum
            if (a.RowIdx < b.RowIdx) return 1;
            if (a.RowIdx > b.RowIdx) return -1;
          } // Check if null values


          if (a.Value === null || typeof a.Value === 'undefined') return 1;
          if (b.Value === null || typeof b.Value === 'undefined') return -1; // Sort by value

          if (a.Value < b.Value) return 1;
          if (a.Value > b.Value) return -1;
        } // They're equal..


        return 0;
      });
      return index;
    }
    /**
     * Searches for the filter keyword in the column cell
     *
     * Note: Search is case-insensitive.
     *
     * @param {string} name field name
     * @param {string} data search string
     * @return {boolean} true, if filter value is found to be a substring
     * of one of the column values, false otherwise.
     */

  }, {
    key: "hasFilterKeyword",
    value: function hasFilterKeyword(name, data) {
      var filterData = null;
      var exactMatch = false;
      var opposite = false;
      var result = false;
      var searchKey = null;
      var searchString = null;

      if (this.props.filters[name]) {
        filterData = this.props.filters[name].value;
        exactMatch = this.props.filters[name].exactMatch;
        opposite = this.props.filters[name].opposite;
      } // Handle null inputs


      if (filterData === null || data === null) {
        return false;
      } // Handle numeric inputs


      if (typeof filterData === 'number') {
        var intData = Number.parseInt(data, 10);
        result = filterData === intData;
      } // Handle string inputs


      if (typeof filterData === 'string') {
        searchKey = filterData.toLowerCase();

        switch (_babel_runtime_helpers_typeof__WEBPACK_IMPORTED_MODULE_0___default()(data)) {
          case 'object':
            // Handles the case where the data is an array (typeof 'object')
            // and you want to search through it for
            // the string you are filtering by
            var searchArray = data.map(function (e) {
              return e.toLowerCase();
            });

            if (exactMatch) {
              result = searchArray.includes(searchKey);
            } else {
              result = searchArray.find(function (e) {
                return e.indexOf(searchKey) > -1;
              }) !== undefined;
            }

            break;

          default:
            searchString = data ? data.toString().toLowerCase() : '';

            if (exactMatch) {
              result = searchString === searchKey;
            } else if (opposite) {
              result = searchString !== searchKey;
            } else {
              result = searchString.indexOf(searchKey) > -1;
            }

            break;
        }
      } // Handle boolean inputs


      if (typeof filterData === 'boolean') {
        result = filterData === data;
      } // Handle array inputs for multiselects


      if (_babel_runtime_helpers_typeof__WEBPACK_IMPORTED_MODULE_0___default()(filterData) === 'object') {
        var match = false;

        for (var i = 0; i < filterData.length; i += 1) {
          searchKey = filterData[i].toLowerCase();
          searchString = data ? data.toString().toLowerCase() : '';

          var _searchArray = searchString.split(',');

          match = _searchArray.includes(searchKey);

          if (match) {
            result = true;
          }
        }
      }

      return result;
    }
  }, {
    key: "componentDidMount",
    value: function componentDidMount() {
      $('.dynamictable').DynamicTable();
    }
  }, {
    key: "renderActions",
    value: function renderActions() {
      if (this.props.actions) {
        return this.props.actions.map(function (action, key) {
          if (action.show !== false) {
            return /*#__PURE__*/react__WEBPACK_IMPORTED_MODULE_7___default.a.createElement(CTA, {
              key: key,
              label: action.label,
              onUserInput: action.action
            });
          }
        });
      }
    }
  }, {
    key: "render",
    value: function render() {
      var _this4 = this;

      if ((this.props.data === null || this.props.data.length === 0) && !this.props.nullTableShow) {
        return /*#__PURE__*/react__WEBPACK_IMPORTED_MODULE_7___default.a.createElement("div", null, /*#__PURE__*/react__WEBPACK_IMPORTED_MODULE_7___default.a.createElement("div", {
          className: "row"
        }, /*#__PURE__*/react__WEBPACK_IMPORTED_MODULE_7___default.a.createElement("div", {
          className: "col-xs-12"
        }, /*#__PURE__*/react__WEBPACK_IMPORTED_MODULE_7___default.a.createElement("div", {
          className: "pull-right",
          style: {
            marginRight: '10px'
          }
        }, this.renderActions()))), /*#__PURE__*/react__WEBPACK_IMPORTED_MODULE_7___default.a.createElement("div", {
          className: "alert alert-info no-result-found-panel"
        }, /*#__PURE__*/react__WEBPACK_IMPORTED_MODULE_7___default.a.createElement("strong", null, "No result found.")));
      }

      var rowsPerPage = this.state.page.rows;
      var headers = this.props.hide.defaultColumn === true ? [] : [/*#__PURE__*/react__WEBPACK_IMPORTED_MODULE_7___default.a.createElement("th", {
        key: "th_col_0",
        onClick: function onClick() {
          _this4.setSortColumn(-1);
        }
      }, this.props.rowNumLabel)];

      var _loop = function _loop(i) {
        if (_this4.props.fields[i].show === true) {
          var colIndex = i + 1;

          if (_this4.props.fields[i].freezeColumn === true) {
            headers.push( /*#__PURE__*/react__WEBPACK_IMPORTED_MODULE_7___default.a.createElement("th", {
              key: 'th_col_' + colIndex,
              id: _this4.props.freezeColumn,
              onClick: function onClick() {
                _this4.setSortColumn(i);
              }
            }, _this4.props.fields[i].label));
          } else {
            headers.push( /*#__PURE__*/react__WEBPACK_IMPORTED_MODULE_7___default.a.createElement("th", {
              key: 'th_col_' + colIndex,
              onClick: function onClick() {
                _this4.setSortColumn(i);
              }
            }, _this4.props.fields[i].label));
          }
        }
      };

      for (var i = 0; i < this.props.fields.length; i += 1) {
        _loop(i);
      }

      var rows = [];
      var filteredRowIndexes = this.getFilteredRowIndexes();
      var filteredCount = filteredRowIndexes.length;
      var index = this.sortRows(filteredRowIndexes);
      var currentPageRow = rowsPerPage * (this.state.page.number - 1);

      if (this.props.filters.keyword) {
        useKeyword = true;
      } // Format each cell for the data table.


      var _loop2 = function _loop2(_i2) {
        var rowIndex = index[_i2].RowIdx;
        var rowData = _this4.props.data[rowIndex];
        var curRow = []; // Iterates through headers to populate row columns
        // with corresponding data

        var _loop3 = function _loop3(j) {
          if (_this4.props.fields[j].show === false) {
            return "continue";
          }

          var celldata = rowData[j];
          var cell = null;
          var row = {};

          _this4.props.fields.forEach(function (field, k) {
            return row[field.label] = rowData[k];
          }); // Get custom cell formatting if available


          if (_this4.props.getFormattedCell) {
            cell = _this4.props.getFormattedCell(_this4.props.fields[j].label, celldata, row);
          }

          if (cell !== null) {
            curRow.push( /*#__PURE__*/react__WEBPACK_IMPORTED_MODULE_7___default.a.cloneElement(cell, {
              key: 'td_col_' + j
            }));
          } else {
            curRow.push(react_addons_create_fragment__WEBPACK_IMPORTED_MODULE_10___default()({
              celldata: celldata
            }));
          }
        };

        for (var j = 0; j < _this4.props.fields.length; j += 1) {
          var _ret = _loop3(j);

          if (_ret === "continue") continue;
        }

        var rowIndexDisplay = index[_i2].Content;
        rows.push( /*#__PURE__*/react__WEBPACK_IMPORTED_MODULE_7___default.a.createElement("tr", {
          key: 'tr_' + rowIndex,
          colSpan: headers.length
        }, /*#__PURE__*/react__WEBPACK_IMPORTED_MODULE_7___default.a.createElement("td", {
          key: 'td_' + rowIndex
        }, rowIndexDisplay), curRow));
      };

      for (var _i2 = currentPageRow; _i2 < filteredCount && rows.length < rowsPerPage; _i2++) {
        _loop2(_i2);
      }

      var rowsPerPageDropdown = /*#__PURE__*/react__WEBPACK_IMPORTED_MODULE_7___default.a.createElement("select", {
        className: "input-sm perPage",
        onChange: this.updatePageRows,
        value: this.state.page.rows
      }, /*#__PURE__*/react__WEBPACK_IMPORTED_MODULE_7___default.a.createElement("option", null, "20"), /*#__PURE__*/react__WEBPACK_IMPORTED_MODULE_7___default.a.createElement("option", null, "50"), /*#__PURE__*/react__WEBPACK_IMPORTED_MODULE_7___default.a.createElement("option", null, "100"), /*#__PURE__*/react__WEBPACK_IMPORTED_MODULE_7___default.a.createElement("option", null, "1000"), /*#__PURE__*/react__WEBPACK_IMPORTED_MODULE_7___default.a.createElement("option", null, "5000"), /*#__PURE__*/react__WEBPACK_IMPORTED_MODULE_7___default.a.createElement("option", null, "10000"));
      var header = this.props.hide.rowsPerPage === true ? '' : /*#__PURE__*/react__WEBPACK_IMPORTED_MODULE_7___default.a.createElement("div", {
        className: "table-header"
      }, /*#__PURE__*/react__WEBPACK_IMPORTED_MODULE_7___default.a.createElement("div", {
        className: "row"
      }, /*#__PURE__*/react__WEBPACK_IMPORTED_MODULE_7___default.a.createElement("div", {
        style: {
          display: 'flex',
          justifyContent: 'space-between',
          alignItems: 'center',
          flexWrap: 'wrap',
          padding: '5px 15px'
        }
      }, /*#__PURE__*/react__WEBPACK_IMPORTED_MODULE_7___default.a.createElement("div", {
        style: {
          order: '1',
          padding: '5px 0'
        }
      }, rows.length, " rows displayed of ", filteredCount, ". (Maximum rows per page: ", rowsPerPageDropdown, ")"), /*#__PURE__*/react__WEBPACK_IMPORTED_MODULE_7___default.a.createElement("div", {
        style: {
          order: '2',
          display: 'flex',
          justifyContent: 'flex-end',
          alignItems: 'center',
          flexWrap: 'wrap',
          padding: '5px 0',
          marginLeft: 'auto'
        }
      }, this.renderActions(), /*#__PURE__*/react__WEBPACK_IMPORTED_MODULE_7___default.a.createElement("button", {
        className: "btn btn-primary",
        onClick: this.downloadCSV.bind(null, filteredRowIndexes)
      }, "Download Table as CSV"), /*#__PURE__*/react__WEBPACK_IMPORTED_MODULE_7___default.a.createElement(jsx_PaginationLinks__WEBPACK_IMPORTED_MODULE_9__["default"], {
        Total: filteredCount,
        onChangePage: this.changePage,
        RowsPerPage: rowsPerPage,
        Active: this.state.page.number
      })))));
      var footer = this.props.hide.downloadCSV === true ? '' : /*#__PURE__*/react__WEBPACK_IMPORTED_MODULE_7___default.a.createElement("div", null, /*#__PURE__*/react__WEBPACK_IMPORTED_MODULE_7___default.a.createElement("div", {
        className: "row"
      }, /*#__PURE__*/react__WEBPACK_IMPORTED_MODULE_7___default.a.createElement("div", {
        style: {
          display: 'flex',
          justifyContent: 'space-between',
          alignItems: 'center',
          flexWrap: 'wrap',
          padding: '5px 15px'
        }
      }, /*#__PURE__*/react__WEBPACK_IMPORTED_MODULE_7___default.a.createElement("div", {
        style: {
          order: '1',
          padding: '5px 0'
        }
      }, rows.length, " rows displayed of ", filteredCount, ". (Maximum rows per page: ", rowsPerPageDropdown, ")"), /*#__PURE__*/react__WEBPACK_IMPORTED_MODULE_7___default.a.createElement("div", {
        style: {
          order: '2',
          padding: '5px 0',
          marginLeft: 'auto'
        }
      }, /*#__PURE__*/react__WEBPACK_IMPORTED_MODULE_7___default.a.createElement(jsx_PaginationLinks__WEBPACK_IMPORTED_MODULE_9__["default"], {
        Total: filteredCount,
        onChangePage: this.changePage,
        RowsPerPage: rowsPerPage,
        Active: this.state.page.number
      })))));
      return /*#__PURE__*/react__WEBPACK_IMPORTED_MODULE_7___default.a.createElement("div", {
        style: {
          margin: '14px'
        }
      }, header, /*#__PURE__*/react__WEBPACK_IMPORTED_MODULE_7___default.a.createElement("table", {
        className: "table table-hover table-primary table-bordered dynamictable",
        id: "dynamictable"
      }, /*#__PURE__*/react__WEBPACK_IMPORTED_MODULE_7___default.a.createElement("thead", null, /*#__PURE__*/react__WEBPACK_IMPORTED_MODULE_7___default.a.createElement("tr", {
        className: "info"
      }, headers)), this.props.folder, /*#__PURE__*/react__WEBPACK_IMPORTED_MODULE_7___default.a.createElement("tbody", null, rows)), footer);
    }
  }]);

  return DataTable;
}(react__WEBPACK_IMPORTED_MODULE_7__["Component"]);

DataTable.propTypes = {
  data: prop_types__WEBPACK_IMPORTED_MODULE_8___default.a.array.isRequired,
  rowNumLabel: prop_types__WEBPACK_IMPORTED_MODULE_8___default.a.string,
  // Function of which returns a JSX element for a table cell, takes
  // parameters of the form: func(ColumnName, CellData, EntireRowData)
  getFormattedCell: prop_types__WEBPACK_IMPORTED_MODULE_8___default.a.func,
  onSort: prop_types__WEBPACK_IMPORTED_MODULE_8___default.a.func,
  actions: prop_types__WEBPACK_IMPORTED_MODULE_8___default.a.array,
  hide: prop_types__WEBPACK_IMPORTED_MODULE_8___default.a.object,
  nullTableShow: prop_types__WEBPACK_IMPORTED_MODULE_8___default.a.bool
};
DataTable.defaultProps = {
  headers: [],
  data: {},
  rowNumLabel: 'No.',
  filters: {},
  hide: {
    rowsPerPage: false,
    downloadCSV: false,
    defaultColumn: false
  },
  nullTableShow: false
};
/* harmony default export */ __webpack_exports__["default"] = (DataTable);

/***/ }),
/* 28 */
/***/ (function(module, __webpack_exports__, __webpack_require__) {

"use strict";
__webpack_require__.r(__webpack_exports__);
/* harmony import */ var _babel_runtime_helpers_classCallCheck__WEBPACK_IMPORTED_MODULE_0__ = __webpack_require__(1);
/* harmony import */ var _babel_runtime_helpers_classCallCheck__WEBPACK_IMPORTED_MODULE_0___default = /*#__PURE__*/__webpack_require__.n(_babel_runtime_helpers_classCallCheck__WEBPACK_IMPORTED_MODULE_0__);
/* harmony import */ var _babel_runtime_helpers_createClass__WEBPACK_IMPORTED_MODULE_1__ = __webpack_require__(2);
/* harmony import */ var _babel_runtime_helpers_createClass__WEBPACK_IMPORTED_MODULE_1___default = /*#__PURE__*/__webpack_require__.n(_babel_runtime_helpers_createClass__WEBPACK_IMPORTED_MODULE_1__);
/* harmony import */ var _babel_runtime_helpers_assertThisInitialized__WEBPACK_IMPORTED_MODULE_2__ = __webpack_require__(3);
/* harmony import */ var _babel_runtime_helpers_assertThisInitialized__WEBPACK_IMPORTED_MODULE_2___default = /*#__PURE__*/__webpack_require__.n(_babel_runtime_helpers_assertThisInitialized__WEBPACK_IMPORTED_MODULE_2__);
/* harmony import */ var _babel_runtime_helpers_inherits__WEBPACK_IMPORTED_MODULE_3__ = __webpack_require__(4);
/* harmony import */ var _babel_runtime_helpers_inherits__WEBPACK_IMPORTED_MODULE_3___default = /*#__PURE__*/__webpack_require__.n(_babel_runtime_helpers_inherits__WEBPACK_IMPORTED_MODULE_3__);
/* harmony import */ var _babel_runtime_helpers_possibleConstructorReturn__WEBPACK_IMPORTED_MODULE_4__ = __webpack_require__(6);
/* harmony import */ var _babel_runtime_helpers_possibleConstructorReturn__WEBPACK_IMPORTED_MODULE_4___default = /*#__PURE__*/__webpack_require__.n(_babel_runtime_helpers_possibleConstructorReturn__WEBPACK_IMPORTED_MODULE_4__);
/* harmony import */ var _babel_runtime_helpers_getPrototypeOf__WEBPACK_IMPORTED_MODULE_5__ = __webpack_require__(8);
/* harmony import */ var _babel_runtime_helpers_getPrototypeOf__WEBPACK_IMPORTED_MODULE_5___default = /*#__PURE__*/__webpack_require__.n(_babel_runtime_helpers_getPrototypeOf__WEBPACK_IMPORTED_MODULE_5__);
/* harmony import */ var react__WEBPACK_IMPORTED_MODULE_6__ = __webpack_require__(9);
/* harmony import */ var react__WEBPACK_IMPORTED_MODULE_6___default = /*#__PURE__*/__webpack_require__.n(react__WEBPACK_IMPORTED_MODULE_6__);
/* harmony import */ var prop_types__WEBPACK_IMPORTED_MODULE_7__ = __webpack_require__(17);
/* harmony import */ var prop_types__WEBPACK_IMPORTED_MODULE_7___default = /*#__PURE__*/__webpack_require__.n(prop_types__WEBPACK_IMPORTED_MODULE_7__);







function _createSuper(Derived) { var hasNativeReflectConstruct = _isNativeReflectConstruct(); return function _createSuperInternal() { var Super = _babel_runtime_helpers_getPrototypeOf__WEBPACK_IMPORTED_MODULE_5___default()(Derived), result; if (hasNativeReflectConstruct) { var NewTarget = _babel_runtime_helpers_getPrototypeOf__WEBPACK_IMPORTED_MODULE_5___default()(this).constructor; result = Reflect.construct(Super, arguments, NewTarget); } else { result = Super.apply(this, arguments); } return _babel_runtime_helpers_possibleConstructorReturn__WEBPACK_IMPORTED_MODULE_4___default()(this, result); }; }

function _isNativeReflectConstruct() { if (typeof Reflect === "undefined" || !Reflect.construct) return false; if (Reflect.construct.sham) return false; if (typeof Proxy === "function") return true; try { Boolean.prototype.valueOf.call(Reflect.construct(Boolean, [], function () {})); return true; } catch (e) { return false; } }

/* exported RPaginationLinks */



var PaginationLinks = /*#__PURE__*/function (_Component) {
  _babel_runtime_helpers_inherits__WEBPACK_IMPORTED_MODULE_3___default()(PaginationLinks, _Component);

  var _super = _createSuper(PaginationLinks);

  function PaginationLinks(props) {
    var _this;

    _babel_runtime_helpers_classCallCheck__WEBPACK_IMPORTED_MODULE_0___default()(this, PaginationLinks);

    _this = _super.call(this, props);
    _this.state = {};
    _this.changePage = _this.changePage.bind(_babel_runtime_helpers_assertThisInitialized__WEBPACK_IMPORTED_MODULE_2___default()(_this));
    return _this;
  }

  _babel_runtime_helpers_createClass__WEBPACK_IMPORTED_MODULE_1___default()(PaginationLinks, [{
    key: "componentDidUpdate",
    value: function componentDidUpdate(prevProps) {
      if (this.props.Total < prevProps.Total) {
        this.props.onChangePage(1);
      }
    }
  }, {
    key: "changePage",
    value: function changePage(i) {
      return function (evt) {
        // Don't jump to the top of the page
        evt.preventDefault();

        if (this.props.onChangePage) {
          this.props.onChangePage(i);
        }
      }.bind(this);
    }
  }, {
    key: "render",
    value: function render() {
      var rowsPerPage = this.props.RowsPerPage;
      var pageLinks = [];
      var classList;
      var lastPage = Math.ceil(this.props.Total / rowsPerPage);
      var startPage = Math.max(1, this.props.Active - 3);
      var lastShownPage = Math.min(this.props.Active + 3, lastPage);

      if (this.props.Total === 0) {
        return /*#__PURE__*/react__WEBPACK_IMPORTED_MODULE_6___default.a.createElement("div", null);
      }

      if (this.props.Total < this.props.RowsPerPage) {
        return /*#__PURE__*/react__WEBPACK_IMPORTED_MODULE_6___default.a.createElement("div", null);
      }

      if (lastShownPage - startPage <= 7) {
        lastShownPage = startPage + 6;

        if (lastShownPage > lastPage) {
          lastShownPage = lastPage;
          startPage = lastPage - 6;
        }
      }

      if (startPage > 1) {
        pageLinks.push( /*#__PURE__*/react__WEBPACK_IMPORTED_MODULE_6___default.a.createElement("li", {
          key: 'table_page_beginning_' + startPage.toString(),
          onClick: this.changePage(1)
        }, /*#__PURE__*/react__WEBPACK_IMPORTED_MODULE_6___default.a.createElement("a", {
          href: "#"
        }, "\xAB")));
      }

      if (startPage < 1) {
        startPage = 1;
      }

      if (lastShownPage < 1) {
        lastShownPage = 1;
      } // If there is only 1 page, don't display pagination links


      if (startPage === lastShownPage) {
        return /*#__PURE__*/react__WEBPACK_IMPORTED_MODULE_6___default.a.createElement("div", null);
      }

      for (var i = startPage; i <= lastShownPage; i += 1) {
        classList = '';

        if (this.props.Active === i) {
          classList = 'active';
        }

        pageLinks.push( /*#__PURE__*/react__WEBPACK_IMPORTED_MODULE_6___default.a.createElement("li", {
          key: 'table_page_' + i.toString(),
          onClick: this.changePage(i),
          className: classList
        }, /*#__PURE__*/react__WEBPACK_IMPORTED_MODULE_6___default.a.createElement("a", {
          href: "#"
        }, i)));
      }

      if (lastShownPage !== lastPage) {
        pageLinks.push( /*#__PURE__*/react__WEBPACK_IMPORTED_MODULE_6___default.a.createElement("li", {
          key: 'table_page_more_' + lastShownPage.toString(),
          onClick: this.changePage(lastPage)
        }, /*#__PURE__*/react__WEBPACK_IMPORTED_MODULE_6___default.a.createElement("a", {
          href: "#"
        }, "\xBB")));
      }

      return /*#__PURE__*/react__WEBPACK_IMPORTED_MODULE_6___default.a.createElement("ul", {
        className: "pagination pagination-table"
      }, pageLinks);
    }
  }]);

  return PaginationLinks;
}(react__WEBPACK_IMPORTED_MODULE_6__["Component"]);

PaginationLinks.propTypes = {
  onChangePage: prop_types__WEBPACK_IMPORTED_MODULE_7___default.a.func,
  Total: prop_types__WEBPACK_IMPORTED_MODULE_7___default.a.number.isRequired
};
PaginationLinks.defaultProps = {
  RowsPerPage: 10,
  Active: 1
};
var RPaginationLinks = /*#__PURE__*/react__WEBPACK_IMPORTED_MODULE_6___default.a.createFactory(PaginationLinks);
window.PaginationLinks = PaginationLinks;
window.RPaginationLinks = RPaginationLinks;
/* harmony default export */ __webpack_exports__["default"] = (PaginationLinks);

/***/ }),
/* 29 */
/***/ (function(module, exports, __webpack_require__) {

"use strict";
/**
 * Copyright (c) 2015-present, Facebook, Inc.
 *
 * This source code is licensed under the MIT license found in the
 * LICENSE file in the root directory of this source tree.
 */



var React = __webpack_require__(9);

var REACT_ELEMENT_TYPE =
  (typeof Symbol === 'function' && Symbol.for && Symbol.for('react.element')) ||
  0xeac7;

var emptyFunction = __webpack_require__(30);
var invariant = __webpack_require__(31);
var warning = __webpack_require__(32);

var SEPARATOR = '.';
var SUBSEPARATOR = ':';

var didWarnAboutMaps = false;

var ITERATOR_SYMBOL = typeof Symbol === 'function' && Symbol.iterator;
var FAUX_ITERATOR_SYMBOL = '@@iterator'; // Before Symbol spec.

function getIteratorFn(maybeIterable) {
  var iteratorFn =
    maybeIterable &&
    ((ITERATOR_SYMBOL && maybeIterable[ITERATOR_SYMBOL]) ||
      maybeIterable[FAUX_ITERATOR_SYMBOL]);
  if (typeof iteratorFn === 'function') {
    return iteratorFn;
  }
}

function escape(key) {
  var escapeRegex = /[=:]/g;
  var escaperLookup = {
    '=': '=0',
    ':': '=2'
  };
  var escapedString = ('' + key).replace(escapeRegex, function(match) {
    return escaperLookup[match];
  });

  return '$' + escapedString;
}

function getComponentKey(component, index) {
  // Do some typechecking here since we call this blindly. We want to ensure
  // that we don't block potential future ES APIs.
  if (component && typeof component === 'object' && component.key != null) {
    // Explicit key
    return escape(component.key);
  }
  // Implicit key determined by the index in the set
  return index.toString(36);
}

function traverseAllChildrenImpl(
  children,
  nameSoFar,
  callback,
  traverseContext
) {
  var type = typeof children;

  if (type === 'undefined' || type === 'boolean') {
    // All of the above are perceived as null.
    children = null;
  }

  if (
    children === null ||
    type === 'string' ||
    type === 'number' ||
    // The following is inlined from ReactElement. This means we can optimize
    // some checks. React Fiber also inlines this logic for similar purposes.
    (type === 'object' && children.$$typeof === REACT_ELEMENT_TYPE)
  ) {
    callback(
      traverseContext,
      children,
      // If it's the only child, treat the name as if it was wrapped in an array
      // so that it's consistent if the number of children grows.
      nameSoFar === '' ? SEPARATOR + getComponentKey(children, 0) : nameSoFar
    );
    return 1;
  }

  var child;
  var nextName;
  var subtreeCount = 0; // Count of children found in the current subtree.
  var nextNamePrefix = nameSoFar === '' ? SEPARATOR : nameSoFar + SUBSEPARATOR;

  if (Array.isArray(children)) {
    for (var i = 0; i < children.length; i++) {
      child = children[i];
      nextName = nextNamePrefix + getComponentKey(child, i);
      subtreeCount += traverseAllChildrenImpl(
        child,
        nextName,
        callback,
        traverseContext
      );
    }
  } else {
    var iteratorFn = getIteratorFn(children);
    if (iteratorFn) {
      if (true) {
        // Warn about using Maps as children
        if (iteratorFn === children.entries) {
          warning(
            didWarnAboutMaps,
            'Using Maps as children is unsupported and will likely yield ' +
              'unexpected results. Convert it to a sequence/iterable of keyed ' +
              'ReactElements instead.'
          );
          didWarnAboutMaps = true;
        }
      }

      var iterator = iteratorFn.call(children);
      var step;
      var ii = 0;
      while (!(step = iterator.next()).done) {
        child = step.value;
        nextName = nextNamePrefix + getComponentKey(child, ii++);
        subtreeCount += traverseAllChildrenImpl(
          child,
          nextName,
          callback,
          traverseContext
        );
      }
    } else if (type === 'object') {
      var addendum = '';
      if (true) {
        addendum =
          ' If you meant to render a collection of children, use an array ' +
          'instead or wrap the object using createFragment(object) from the ' +
          'React add-ons.';
      }
      var childrenString = '' + children;
      invariant(
        false,
        'Objects are not valid as a React child (found: %s).%s',
        childrenString === '[object Object]'
          ? 'object with keys {' + Object.keys(children).join(', ') + '}'
          : childrenString,
        addendum
      );
    }
  }

  return subtreeCount;
}

function traverseAllChildren(children, callback, traverseContext) {
  if (children == null) {
    return 0;
  }

  return traverseAllChildrenImpl(children, '', callback, traverseContext);
}

var userProvidedKeyEscapeRegex = /\/+/g;
function escapeUserProvidedKey(text) {
  return ('' + text).replace(userProvidedKeyEscapeRegex, '$&/');
}

function cloneAndReplaceKey(oldElement, newKey) {
  return React.cloneElement(
    oldElement,
    {key: newKey},
    oldElement.props !== undefined ? oldElement.props.children : undefined
  );
}

var DEFAULT_POOL_SIZE = 10;
var DEFAULT_POOLER = oneArgumentPooler;

var oneArgumentPooler = function(copyFieldsFrom) {
  var Klass = this;
  if (Klass.instancePool.length) {
    var instance = Klass.instancePool.pop();
    Klass.call(instance, copyFieldsFrom);
    return instance;
  } else {
    return new Klass(copyFieldsFrom);
  }
};

var addPoolingTo = function addPoolingTo(CopyConstructor, pooler) {
  // Casting as any so that flow ignores the actual implementation and trusts
  // it to match the type we declared
  var NewKlass = CopyConstructor;
  NewKlass.instancePool = [];
  NewKlass.getPooled = pooler || DEFAULT_POOLER;
  if (!NewKlass.poolSize) {
    NewKlass.poolSize = DEFAULT_POOL_SIZE;
  }
  NewKlass.release = standardReleaser;
  return NewKlass;
};

var standardReleaser = function standardReleaser(instance) {
  var Klass = this;
  invariant(
    instance instanceof Klass,
    'Trying to release an instance into a pool of a different type.'
  );
  instance.destructor();
  if (Klass.instancePool.length < Klass.poolSize) {
    Klass.instancePool.push(instance);
  }
};

var fourArgumentPooler = function fourArgumentPooler(a1, a2, a3, a4) {
  var Klass = this;
  if (Klass.instancePool.length) {
    var instance = Klass.instancePool.pop();
    Klass.call(instance, a1, a2, a3, a4);
    return instance;
  } else {
    return new Klass(a1, a2, a3, a4);
  }
};

function MapBookKeeping(mapResult, keyPrefix, mapFunction, mapContext) {
  this.result = mapResult;
  this.keyPrefix = keyPrefix;
  this.func = mapFunction;
  this.context = mapContext;
  this.count = 0;
}
MapBookKeeping.prototype.destructor = function() {
  this.result = null;
  this.keyPrefix = null;
  this.func = null;
  this.context = null;
  this.count = 0;
};
addPoolingTo(MapBookKeeping, fourArgumentPooler);

function mapSingleChildIntoContext(bookKeeping, child, childKey) {
  var result = bookKeeping.result;
  var keyPrefix = bookKeeping.keyPrefix;
  var func = bookKeeping.func;
  var context = bookKeeping.context;

  var mappedChild = func.call(context, child, bookKeeping.count++);
  if (Array.isArray(mappedChild)) {
    mapIntoWithKeyPrefixInternal(
      mappedChild,
      result,
      childKey,
      emptyFunction.thatReturnsArgument
    );
  } else if (mappedChild != null) {
    if (React.isValidElement(mappedChild)) {
      mappedChild = cloneAndReplaceKey(
        mappedChild,
        // Keep both the (mapped) and old keys if they differ, just as
        // traverseAllChildren used to do for objects as children
        keyPrefix +
          (mappedChild.key && (!child || child.key !== mappedChild.key)
            ? escapeUserProvidedKey(mappedChild.key) + '/'
            : '') +
          childKey
      );
    }
    result.push(mappedChild);
  }
}

function mapIntoWithKeyPrefixInternal(children, array, prefix, func, context) {
  var escapedPrefix = '';
  if (prefix != null) {
    escapedPrefix = escapeUserProvidedKey(prefix) + '/';
  }
  var traverseContext = MapBookKeeping.getPooled(
    array,
    escapedPrefix,
    func,
    context
  );
  traverseAllChildren(children, mapSingleChildIntoContext, traverseContext);
  MapBookKeeping.release(traverseContext);
}

var numericPropertyRegex = /^\d+$/;

var warnedAboutNumeric = false;

function createReactFragment(object) {
  if (typeof object !== 'object' || !object || Array.isArray(object)) {
    warning(
      false,
      'React.addons.createFragment only accepts a single object. Got: %s',
      object
    );
    return object;
  }
  if (React.isValidElement(object)) {
    warning(
      false,
      'React.addons.createFragment does not accept a ReactElement ' +
        'without a wrapper object.'
    );
    return object;
  }

  invariant(
    object.nodeType !== 1,
    'React.addons.createFragment(...): Encountered an invalid child; DOM ' +
      'elements are not valid children of React components.'
  );

  var result = [];

  for (var key in object) {
    if (true) {
      if (!warnedAboutNumeric && numericPropertyRegex.test(key)) {
        warning(
          false,
          'React.addons.createFragment(...): Child objects should have ' +
            'non-numeric keys so ordering is preserved.'
        );
        warnedAboutNumeric = true;
      }
    }
    mapIntoWithKeyPrefixInternal(
      object[key],
      result,
      key,
      emptyFunction.thatReturnsArgument
    );
  }

  return result;
}

module.exports = createReactFragment;


/***/ }),
/* 30 */
/***/ (function(module, exports, __webpack_require__) {

"use strict";


/**
 * Copyright (c) 2013-present, Facebook, Inc.
 *
 * This source code is licensed under the MIT license found in the
 * LICENSE file in the root directory of this source tree.
 *
 * 
 */

function makeEmptyFunction(arg) {
  return function () {
    return arg;
  };
}

/**
 * This function accepts and discards inputs; it has no side effects. This is
 * primarily useful idiomatically for overridable function endpoints which
 * always need to be callable, since JS lacks a null-call idiom ala Cocoa.
 */
var emptyFunction = function emptyFunction() {};

emptyFunction.thatReturns = makeEmptyFunction;
emptyFunction.thatReturnsFalse = makeEmptyFunction(false);
emptyFunction.thatReturnsTrue = makeEmptyFunction(true);
emptyFunction.thatReturnsNull = makeEmptyFunction(null);
emptyFunction.thatReturnsThis = function () {
  return this;
};
emptyFunction.thatReturnsArgument = function (arg) {
  return arg;
};

module.exports = emptyFunction;

/***/ }),
/* 31 */
/***/ (function(module, exports, __webpack_require__) {

"use strict";
/**
 * Copyright (c) 2013-present, Facebook, Inc.
 *
 * This source code is licensed under the MIT license found in the
 * LICENSE file in the root directory of this source tree.
 *
 */



/**
 * Use invariant() to assert state which your program assumes to be true.
 *
 * Provide sprintf-style format (only %s is supported) and arguments
 * to provide information about what broke and what you were
 * expecting.
 *
 * The invariant message will be stripped in production, but the invariant
 * will remain to ensure logic does not differ in production.
 */

var validateFormat = function validateFormat(format) {};

if (true) {
  validateFormat = function validateFormat(format) {
    if (format === undefined) {
      throw new Error('invariant requires an error message argument');
    }
  };
}

function invariant(condition, format, a, b, c, d, e, f) {
  validateFormat(format);

  if (!condition) {
    var error;
    if (format === undefined) {
      error = new Error('Minified exception occurred; use the non-minified dev environment ' + 'for the full error message and additional helpful warnings.');
    } else {
      var args = [a, b, c, d, e, f];
      var argIndex = 0;
      error = new Error(format.replace(/%s/g, function () {
        return args[argIndex++];
      }));
      error.name = 'Invariant Violation';
    }

    error.framesToPop = 1; // we don't care about invariant's own frame
    throw error;
  }
}

module.exports = invariant;

/***/ }),
/* 32 */
/***/ (function(module, exports, __webpack_require__) {

"use strict";
/**
 * Copyright (c) 2014-present, Facebook, Inc.
 *
 * This source code is licensed under the MIT license found in the
 * LICENSE file in the root directory of this source tree.
 *
 */



var emptyFunction = __webpack_require__(30);

/**
 * Similar to invariant but only logs a warning if the condition is not met.
 * This can be used to log issues in development environments in critical
 * paths. Removing the logging code for production environments will keep the
 * same logic and follow the same code paths.
 */

var warning = emptyFunction;

if (true) {
  var printWarning = function printWarning(format) {
    for (var _len = arguments.length, args = Array(_len > 1 ? _len - 1 : 0), _key = 1; _key < _len; _key++) {
      args[_key - 1] = arguments[_key];
    }

    var argIndex = 0;
    var message = 'Warning: ' + format.replace(/%s/g, function () {
      return args[argIndex++];
    });
    if (typeof console !== 'undefined') {
      console.error(message);
    }
    try {
      // --- Welcome to debugging React ---
      // This error was thrown as a convenience so that you can use this stack
      // to find the callsite that caused this warning to fire.
      throw new Error(message);
    } catch (x) {}
  };

  warning = function warning(condition, format) {
    if (format === undefined) {
      throw new Error('`warning(condition, format, ...args)` requires a warning ' + 'message argument');
    }

    if (format.indexOf('Failed Composite propType: ') === 0) {
      return; // Ignore CompositeComponent proptype check.
    }

    if (!condition) {
      for (var _len2 = arguments.length, args = Array(_len2 > 2 ? _len2 - 2 : 0), _key2 = 2; _key2 < _len2; _key2++) {
        args[_key2 - 2] = arguments[_key2];
      }

      printWarning.apply(undefined, [format].concat(args));
    }
  };
}

module.exports = warning;

/***/ }),
/* 33 */
/***/ (function(module, __webpack_exports__, __webpack_require__) {

"use strict";
__webpack_require__.r(__webpack_exports__);
/* harmony import */ var react__WEBPACK_IMPORTED_MODULE_0__ = __webpack_require__(9);
/* harmony import */ var react__WEBPACK_IMPORTED_MODULE_0___default = /*#__PURE__*/__webpack_require__.n(react__WEBPACK_IMPORTED_MODULE_0__);
/* harmony import */ var prop_types__WEBPACK_IMPORTED_MODULE_1__ = __webpack_require__(17);
/* harmony import */ var prop_types__WEBPACK_IMPORTED_MODULE_1___default = /*#__PURE__*/__webpack_require__.n(prop_types__WEBPACK_IMPORTED_MODULE_1__);


/**
 * Filter component.
 * A wrapper for form elements inside a selection filter.
 *
 * Constructs filter fields based on this.props.fields configuration object
 *
 * Alters the filter object and sends it to parent on every update.
 *
 * @param {props} props
 * @return {jsx}
 *
 */

function Filter(props) {
  /**
   * Takes query params from url and triggers an update of the fields that are
   * associated with those params, if they exist.
   */
  Object(react__WEBPACK_IMPORTED_MODULE_0__["useEffect"])(function () {
    var searchParams = new URLSearchParams(location.search);
    searchParams.forEach(function (value, name) {
      // This checks to make sure the filter actually exists
      if (props.fields.find(function (field) {
        return (field.filter || {}).name == name;
      })) {
        onFieldUpdate(name, searchParams.getAll(name));
      }
    });
  }, []);
  /**
   * Sets filter object to reflect values of input fields.
   *
   * @param {string} name - form element type (i.e component name)
   * @param {string} value - the name of the form element
   */

  var onFieldUpdate = function onFieldUpdate(name, value) {
    var _JSON$parse = JSON.parse(JSON.stringify(props)),
        fields = _JSON$parse.fields;

    var type = fields.find(function (field) {
      return (field.filter || {}).name == name;
    }).filter.type;
    var exactMatch = !(type === 'text' || type === 'date');

    if (value === null || value === '' || value.constructor === Array && value.length === 0) {
      props.removeFilter(name);
    } else {
      props.addFilter(name, value, exactMatch);
    }
  };
  /**
   * Renders the filters based on the defined fields.
   *
   * @return {array}
   */


  var renderFilterFields = function renderFilterFields() {
    return props.fields.reduce(function (result, field) {
      var filter = field.filter;

      if (filter && filter.hide !== true) {
        var element;

        switch (filter.type) {
          case 'text':
            element = /*#__PURE__*/react__WEBPACK_IMPORTED_MODULE_0___default.a.createElement(TextboxElement, null);
            break;

          case 'select':
            element = /*#__PURE__*/react__WEBPACK_IMPORTED_MODULE_0___default.a.createElement(SelectElement, {
              options: filter.options,
              sortByValue: filter.sortByValue
            });
            break;

          case 'multiselect':
            element = /*#__PURE__*/react__WEBPACK_IMPORTED_MODULE_0___default.a.createElement(SelectElement, {
              options: filter.options,
              multiple: true,
              emptyOption: false
            });
            break;

          case 'numeric':
            element = /*#__PURE__*/react__WEBPACK_IMPORTED_MODULE_0___default.a.createElement(NumericElement, {
              options: filter.options
            });
            break;

          case 'date':
            element = /*#__PURE__*/react__WEBPACK_IMPORTED_MODULE_0___default.a.createElement(DateElement, null);
            break;

          case 'checkbox':
            element = /*#__PURE__*/react__WEBPACK_IMPORTED_MODULE_0___default.a.createElement(CheckboxElement, null);
            break;

          default:
            element = /*#__PURE__*/react__WEBPACK_IMPORTED_MODULE_0___default.a.createElement(TextboxElement, null);
        } // The value prop has to default to false if the first two options
        // are undefined so that the checkbox component is a controlled input
        // element with a starting default value


        result.push( /*#__PURE__*/react__WEBPACK_IMPORTED_MODULE_0___default.a.cloneElement(element, {
          key: filter.name,
          name: filter.name,
          label: field.label,
          value: (props.filters[filter.name] || {}).value || false,
          onUserInput: onFieldUpdate
        }));
      }

      return result;
    }, []);
  };

  return /*#__PURE__*/react__WEBPACK_IMPORTED_MODULE_0___default.a.createElement(FormElement, {
    id: props.id,
    name: props.name
  }, /*#__PURE__*/react__WEBPACK_IMPORTED_MODULE_0___default.a.createElement(FieldsetElement, {
    columns: props.columns,
    legend: props.title
  }, renderFilterFields(), /*#__PURE__*/react__WEBPACK_IMPORTED_MODULE_0___default.a.createElement(ButtonElement, {
    label: "Clear Filters",
    type: "reset",
    onUserInput: props.clearFilters
  })));
}

Filter.defaultProps = {
  id: null,
  clearFilter: function clearFilter() {
    console.warn('onUpdate() callback is not set!');
  },
  columns: 1
};
Filter.propTypes = {
  filters: prop_types__WEBPACK_IMPORTED_MODULE_1___default.a.object.isRequired,
  clearFilter: prop_types__WEBPACK_IMPORTED_MODULE_1___default.a.func.isRequired,
  id: prop_types__WEBPACK_IMPORTED_MODULE_1___default.a.string,
  name: prop_types__WEBPACK_IMPORTED_MODULE_1___default.a.string,
  columns: prop_types__WEBPACK_IMPORTED_MODULE_1___default.a.number,
  title: prop_types__WEBPACK_IMPORTED_MODULE_1___default.a.string,
  fields: prop_types__WEBPACK_IMPORTED_MODULE_1___default.a.array.isRequired
};
/* harmony default export */ __webpack_exports__["default"] = (Filter);

/***/ }),
/* 34 */
/***/ (function(module, __webpack_exports__, __webpack_require__) {

"use strict";
__webpack_require__.r(__webpack_exports__);
/* harmony import */ var _babel_runtime_helpers_classCallCheck__WEBPACK_IMPORTED_MODULE_0__ = __webpack_require__(1);
/* harmony import */ var _babel_runtime_helpers_classCallCheck__WEBPACK_IMPORTED_MODULE_0___default = /*#__PURE__*/__webpack_require__.n(_babel_runtime_helpers_classCallCheck__WEBPACK_IMPORTED_MODULE_0__);
/* harmony import */ var _babel_runtime_helpers_createClass__WEBPACK_IMPORTED_MODULE_1__ = __webpack_require__(2);
/* harmony import */ var _babel_runtime_helpers_createClass__WEBPACK_IMPORTED_MODULE_1___default = /*#__PURE__*/__webpack_require__.n(_babel_runtime_helpers_createClass__WEBPACK_IMPORTED_MODULE_1__);
/* harmony import */ var _babel_runtime_helpers_assertThisInitialized__WEBPACK_IMPORTED_MODULE_2__ = __webpack_require__(3);
/* harmony import */ var _babel_runtime_helpers_assertThisInitialized__WEBPACK_IMPORTED_MODULE_2___default = /*#__PURE__*/__webpack_require__.n(_babel_runtime_helpers_assertThisInitialized__WEBPACK_IMPORTED_MODULE_2__);
/* harmony import */ var _babel_runtime_helpers_inherits__WEBPACK_IMPORTED_MODULE_3__ = __webpack_require__(4);
/* harmony import */ var _babel_runtime_helpers_inherits__WEBPACK_IMPORTED_MODULE_3___default = /*#__PURE__*/__webpack_require__.n(_babel_runtime_helpers_inherits__WEBPACK_IMPORTED_MODULE_3__);
/* harmony import */ var _babel_runtime_helpers_possibleConstructorReturn__WEBPACK_IMPORTED_MODULE_4__ = __webpack_require__(6);
/* harmony import */ var _babel_runtime_helpers_possibleConstructorReturn__WEBPACK_IMPORTED_MODULE_4___default = /*#__PURE__*/__webpack_require__.n(_babel_runtime_helpers_possibleConstructorReturn__WEBPACK_IMPORTED_MODULE_4__);
/* harmony import */ var _babel_runtime_helpers_getPrototypeOf__WEBPACK_IMPORTED_MODULE_5__ = __webpack_require__(8);
/* harmony import */ var _babel_runtime_helpers_getPrototypeOf__WEBPACK_IMPORTED_MODULE_5___default = /*#__PURE__*/__webpack_require__.n(_babel_runtime_helpers_getPrototypeOf__WEBPACK_IMPORTED_MODULE_5__);
/* harmony import */ var react__WEBPACK_IMPORTED_MODULE_6__ = __webpack_require__(9);
/* harmony import */ var react__WEBPACK_IMPORTED_MODULE_6___default = /*#__PURE__*/__webpack_require__.n(react__WEBPACK_IMPORTED_MODULE_6__);
/* harmony import */ var prop_types__WEBPACK_IMPORTED_MODULE_7__ = __webpack_require__(17);
/* harmony import */ var prop_types__WEBPACK_IMPORTED_MODULE_7___default = /*#__PURE__*/__webpack_require__.n(prop_types__WEBPACK_IMPORTED_MODULE_7__);
/* harmony import */ var sweetalert2__WEBPACK_IMPORTED_MODULE_8__ = __webpack_require__(35);
/* harmony import */ var sweetalert2__WEBPACK_IMPORTED_MODULE_8___default = /*#__PURE__*/__webpack_require__.n(sweetalert2__WEBPACK_IMPORTED_MODULE_8__);







function _createSuper(Derived) { var hasNativeReflectConstruct = _isNativeReflectConstruct(); return function _createSuperInternal() { var Super = _babel_runtime_helpers_getPrototypeOf__WEBPACK_IMPORTED_MODULE_5___default()(Derived), result; if (hasNativeReflectConstruct) { var NewTarget = _babel_runtime_helpers_getPrototypeOf__WEBPACK_IMPORTED_MODULE_5___default()(this).constructor; result = Reflect.construct(Super, arguments, NewTarget); } else { result = Super.apply(this, arguments); } return _babel_runtime_helpers_possibleConstructorReturn__WEBPACK_IMPORTED_MODULE_4___default()(this, result); }; }

function _isNativeReflectConstruct() { if (typeof Reflect === "undefined" || !Reflect.construct) return false; if (Reflect.construct.sham) return false; if (typeof Proxy === "function") return true; try { Boolean.prototype.valueOf.call(Reflect.construct(Boolean, [], function () {})); return true; } catch (e) { return false; } }

/**
 * This file contains the React Component for a Modal Window.
 *
 * @author Henri Rabalais
 * @version 1.1.0
 *
 */



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

var Modal = /*#__PURE__*/function (_Component) {
  _babel_runtime_helpers_inherits__WEBPACK_IMPORTED_MODULE_3___default()(Modal, _Component);

  var _super = _createSuper(Modal);

  function Modal() {
    var _this;

    _babel_runtime_helpers_classCallCheck__WEBPACK_IMPORTED_MODULE_0___default()(this, Modal);

    _this = _super.call(this);
    _this.handleClose = _this.handleClose.bind(_babel_runtime_helpers_assertThisInitialized__WEBPACK_IMPORTED_MODULE_2___default()(_this));
    return _this;
  }

  _babel_runtime_helpers_createClass__WEBPACK_IMPORTED_MODULE_1___default()(Modal, [{
    key: "handleClose",
    value: function handleClose() {
      var _this2 = this;

      if (this.props.throwWarning) {
        sweetalert2__WEBPACK_IMPORTED_MODULE_8___default()({
          title: 'Are You Sure?',
          text: 'Leaving the form will result in the loss of any information ' + 'entered.',
          type: 'warning',
          showCancelButton: true,
          confirmButtonText: 'Proceed',
          cancelButtonText: 'Cancel'
        }).then(function (result) {
          return result.value && _this2.props.onClose();
        });
      } else {
        this.props.onClose();
      }
    }
  }, {
    key: "render",
    value: function render() {
      var _this$props = this.props,
          show = _this$props.show,
          children = _this$props.children,
          candID = _this$props.candID,
          site = _this$props.site,
          previous = _this$props.previous;
      var headerStyle = {
        display: 'flex',
        flexDirection: 'row',
        alignItems: 'center',
        height: '40px',
        borderTopRightRadius: '10',
        fontSize: 24,
        padding: 35,
        borderBottom: '1px solid #DDDDDD'
      };
      var glyphStyle = {
        marginLeft: 'auto',
        cursor: 'pointer'
      };
      var bodyStyle = {
        padding: 15,
        height: 'calc(100% - 130px)',
        overflow: 'auto'
      };
      var modalContainer = {
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
        visibility: show ? 'visible' : 'hidden'
      };
      var modalContent = {
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
        transition: 'top 0.4s, opacity 0.4s'
      };

      var renderChildren = function renderChildren() {
        return show && children;
      };

      var footerStyle = {
        borderTop: '1px solid #DDDDDD',
        display: 'flex',
        flexDirection: 'row-reverse',
        alignItems: 'center',
        height: '60px',
        padding: '10px 35px 10px 35px'
      };
      var previousList = Object.keys(previous).map(function (visit) {
        var url = "".concat(loris.BaseURL, "/final_radiological_review/compare_reviews/?identifier=").concat(previous[visit]);
        return /*#__PURE__*/react__WEBPACK_IMPORTED_MODULE_6___default.a.createElement("li", {
          key: visit
        }, /*#__PURE__*/react__WEBPACK_IMPORTED_MODULE_6___default.a.createElement("a", {
          href: url,
          target: "_blank"
        }, visit));
      });
      var siteURL = "".concat(loris.BaseURL, "/instruments/Radiology_Review_VSA/?commentID=").concat(site.commentID, "&sessionID=").concat(site.sessionID, "&candID=").concat(candID);
      return /*#__PURE__*/react__WEBPACK_IMPORTED_MODULE_6___default.a.createElement("div", {
        style: modalContainer,
        onClick: this.handleClose
      }, /*#__PURE__*/react__WEBPACK_IMPORTED_MODULE_6___default.a.createElement("div", {
        style: modalContent,
        onClick: function onClick(e) {
          return e.stopPropagation();
        }
      }, /*#__PURE__*/react__WEBPACK_IMPORTED_MODULE_6___default.a.createElement("div", {
        style: headerStyle
      }, "DCCID: ".concat(candID), /*#__PURE__*/react__WEBPACK_IMPORTED_MODULE_6___default.a.createElement("span", {
        style: glyphStyle,
        onClick: this.handleClose
      }, "\xD7")), /*#__PURE__*/react__WEBPACK_IMPORTED_MODULE_6___default.a.createElement("div", {
        style: bodyStyle
      }, renderChildren()), /*#__PURE__*/react__WEBPACK_IMPORTED_MODULE_6___default.a.createElement("div", {
        style: footerStyle
      }, /*#__PURE__*/react__WEBPACK_IMPORTED_MODULE_6___default.a.createElement("div", {
        className: "btn-group dropup"
      }, /*#__PURE__*/react__WEBPACK_IMPORTED_MODULE_6___default.a.createElement("button", {
        type: "button",
        className: "btn btn-default dropdown-toggle",
        "data-toggle": "dropdown",
        "aria-haspopup": "true",
        "aria-expanded": "false"
      }, "View Other Reviews ", /*#__PURE__*/react__WEBPACK_IMPORTED_MODULE_6___default.a.createElement("span", {
        className: "caret"
      })), /*#__PURE__*/react__WEBPACK_IMPORTED_MODULE_6___default.a.createElement("ul", {
        className: "dropdown-menu"
      }, /*#__PURE__*/react__WEBPACK_IMPORTED_MODULE_6___default.a.createElement("li", null, /*#__PURE__*/react__WEBPACK_IMPORTED_MODULE_6___default.a.createElement("a", {
        href: siteURL,
        target: "_blank"
      }, "Site")), previousList)))));
    }
  }]);

  return Modal;
}(react__WEBPACK_IMPORTED_MODULE_6__["Component"]);

Modal.propTypes = {
  title: prop_types__WEBPACK_IMPORTED_MODULE_7___default.a.string,
  onSubmit: prop_types__WEBPACK_IMPORTED_MODULE_7___default.a.object,
  onClose: prop_types__WEBPACK_IMPORTED_MODULE_7___default.a.func.isRequired,
  show: prop_types__WEBPACK_IMPORTED_MODULE_7___default.a.bool.isRequired,
  throwWarning: prop_types__WEBPACK_IMPORTED_MODULE_7___default.a.bool
};
Modal.defaultProps = {
  throwWarning: false
};
/* harmony default export */ __webpack_exports__["default"] = (Modal);

/***/ }),
/* 35 */
/***/ (function(module, exports, __webpack_require__) {

/*!
* sweetalert2 v8.19.0
* Released under the MIT License.
*/
(function (global, factory) {
	 true ? module.exports = factory() :
	undefined;
}(this, (function () { 'use strict';

function _typeof(obj) {
  if (typeof Symbol === "function" && typeof Symbol.iterator === "symbol") {
    _typeof = function (obj) {
      return typeof obj;
    };
  } else {
    _typeof = function (obj) {
      return obj && typeof Symbol === "function" && obj.constructor === Symbol && obj !== Symbol.prototype ? "symbol" : typeof obj;
    };
  }

  return _typeof(obj);
}

function _classCallCheck(instance, Constructor) {
  if (!(instance instanceof Constructor)) {
    throw new TypeError("Cannot call a class as a function");
  }
}

function _defineProperties(target, props) {
  for (var i = 0; i < props.length; i++) {
    var descriptor = props[i];
    descriptor.enumerable = descriptor.enumerable || false;
    descriptor.configurable = true;
    if ("value" in descriptor) descriptor.writable = true;
    Object.defineProperty(target, descriptor.key, descriptor);
  }
}

function _createClass(Constructor, protoProps, staticProps) {
  if (protoProps) _defineProperties(Constructor.prototype, protoProps);
  if (staticProps) _defineProperties(Constructor, staticProps);
  return Constructor;
}

function _extends() {
  _extends = Object.assign || function (target) {
    for (var i = 1; i < arguments.length; i++) {
      var source = arguments[i];

      for (var key in source) {
        if (Object.prototype.hasOwnProperty.call(source, key)) {
          target[key] = source[key];
        }
      }
    }

    return target;
  };

  return _extends.apply(this, arguments);
}

function _inherits(subClass, superClass) {
  if (typeof superClass !== "function" && superClass !== null) {
    throw new TypeError("Super expression must either be null or a function");
  }

  subClass.prototype = Object.create(superClass && superClass.prototype, {
    constructor: {
      value: subClass,
      writable: true,
      configurable: true
    }
  });
  if (superClass) _setPrototypeOf(subClass, superClass);
}

function _getPrototypeOf(o) {
  _getPrototypeOf = Object.setPrototypeOf ? Object.getPrototypeOf : function _getPrototypeOf(o) {
    return o.__proto__ || Object.getPrototypeOf(o);
  };
  return _getPrototypeOf(o);
}

function _setPrototypeOf(o, p) {
  _setPrototypeOf = Object.setPrototypeOf || function _setPrototypeOf(o, p) {
    o.__proto__ = p;
    return o;
  };

  return _setPrototypeOf(o, p);
}

function isNativeReflectConstruct() {
  if (typeof Reflect === "undefined" || !Reflect.construct) return false;
  if (Reflect.construct.sham) return false;
  if (typeof Proxy === "function") return true;

  try {
    Date.prototype.toString.call(Reflect.construct(Date, [], function () {}));
    return true;
  } catch (e) {
    return false;
  }
}

function _construct(Parent, args, Class) {
  if (isNativeReflectConstruct()) {
    _construct = Reflect.construct;
  } else {
    _construct = function _construct(Parent, args, Class) {
      var a = [null];
      a.push.apply(a, args);
      var Constructor = Function.bind.apply(Parent, a);
      var instance = new Constructor();
      if (Class) _setPrototypeOf(instance, Class.prototype);
      return instance;
    };
  }

  return _construct.apply(null, arguments);
}

function _assertThisInitialized(self) {
  if (self === void 0) {
    throw new ReferenceError("this hasn't been initialised - super() hasn't been called");
  }

  return self;
}

function _possibleConstructorReturn(self, call) {
  if (call && (typeof call === "object" || typeof call === "function")) {
    return call;
  }

  return _assertThisInitialized(self);
}

function _superPropBase(object, property) {
  while (!Object.prototype.hasOwnProperty.call(object, property)) {
    object = _getPrototypeOf(object);
    if (object === null) break;
  }

  return object;
}

function _get(target, property, receiver) {
  if (typeof Reflect !== "undefined" && Reflect.get) {
    _get = Reflect.get;
  } else {
    _get = function _get(target, property, receiver) {
      var base = _superPropBase(target, property);

      if (!base) return;
      var desc = Object.getOwnPropertyDescriptor(base, property);

      if (desc.get) {
        return desc.get.call(receiver);
      }

      return desc.value;
    };
  }

  return _get(target, property, receiver || target);
}

var consolePrefix = 'SweetAlert2:';
/**
 * Filter the unique values into a new array
 * @param arr
 */

var uniqueArray = function uniqueArray(arr) {
  var result = [];

  for (var i = 0; i < arr.length; i++) {
    if (result.indexOf(arr[i]) === -1) {
      result.push(arr[i]);
    }
  }

  return result;
};
/**
 * Returns the array ob object values (Object.values isn't supported in IE11)
 * @param obj
 */

var objectValues = function objectValues(obj) {
  return Object.keys(obj).map(function (key) {
    return obj[key];
  });
};
/**
 * Convert NodeList to Array
 * @param nodeList
 */

var toArray = function toArray(nodeList) {
  return Array.prototype.slice.call(nodeList);
};
/**
 * Standardise console warnings
 * @param message
 */

var warn = function warn(message) {
  console.warn("".concat(consolePrefix, " ").concat(message));
};
/**
 * Standardise console errors
 * @param message
 */

var error = function error(message) {
  console.error("".concat(consolePrefix, " ").concat(message));
};
/**
 * Private global state for `warnOnce`
 * @type {Array}
 * @private
 */

var previousWarnOnceMessages = [];
/**
 * Show a console warning, but only if it hasn't already been shown
 * @param message
 */

var warnOnce = function warnOnce(message) {
  if (!(previousWarnOnceMessages.indexOf(message) !== -1)) {
    previousWarnOnceMessages.push(message);
    warn(message);
  }
};
/**
 * Show a one-time console warning about deprecated params/methods
 */

var warnAboutDepreation = function warnAboutDepreation(deprecatedParam, useInstead) {
  warnOnce("\"".concat(deprecatedParam, "\" is deprecated and will be removed in the next major release. Please use \"").concat(useInstead, "\" instead."));
};
/**
 * If `arg` is a function, call it (with no arguments or context) and return the result.
 * Otherwise, just pass the value through
 * @param arg
 */

var callIfFunction = function callIfFunction(arg) {
  return typeof arg === 'function' ? arg() : arg;
};
var isPromise = function isPromise(arg) {
  return arg && Promise.resolve(arg) === arg;
};

var DismissReason = Object.freeze({
  cancel: 'cancel',
  backdrop: 'backdrop',
  close: 'close',
  esc: 'esc',
  timer: 'timer'
});

var argsToParams = function argsToParams(args) {
  var params = {};

  switch (_typeof(args[0])) {
    case 'object':
      _extends(params, args[0]);

      break;

    default:
      ['title', 'html', 'type'].forEach(function (name, index) {
        switch (_typeof(args[index])) {
          case 'string':
            params[name] = args[index];
            break;

          case 'undefined':
            break;

          default:
            error("Unexpected type of ".concat(name, "! Expected \"string\", got ").concat(_typeof(args[index])));
        }
      });
  }

  return params;
};

var swalPrefix = 'swal2-';
var prefix = function prefix(items) {
  var result = {};

  for (var i in items) {
    result[items[i]] = swalPrefix + items[i];
  }

  return result;
};
var swalClasses = prefix(['container', 'shown', 'height-auto', 'iosfix', 'popup', 'modal', 'no-backdrop', 'toast', 'toast-shown', 'toast-column', 'show', 'hide', 'noanimation', 'close', 'title', 'header', 'content', 'actions', 'confirm', 'cancel', 'footer', 'icon', 'image', 'input', 'file', 'range', 'select', 'radio', 'checkbox', 'label', 'textarea', 'inputerror', 'validation-message', 'progress-steps', 'active-progress-step', 'progress-step', 'progress-step-line', 'loading', 'styled', 'top', 'top-start', 'top-end', 'top-left', 'top-right', 'center', 'center-start', 'center-end', 'center-left', 'center-right', 'bottom', 'bottom-start', 'bottom-end', 'bottom-left', 'bottom-right', 'grow-row', 'grow-column', 'grow-fullscreen', 'rtl']);
var iconTypes = prefix(['success', 'warning', 'info', 'question', 'error']);

var states = {
  previousBodyPadding: null
};
var hasClass = function hasClass(elem, className) {
  return elem.classList.contains(className);
};

var removeCustomClasses = function removeCustomClasses(elem) {
  toArray(elem.classList).forEach(function (className) {
    if (!(objectValues(swalClasses).indexOf(className) !== -1) && !(objectValues(iconTypes).indexOf(className) !== -1)) {
      elem.classList.remove(className);
    }
  });
};

var applyCustomClass = function applyCustomClass(elem, customClass, className) {
  removeCustomClasses(elem);

  if (customClass && customClass[className]) {
    if (typeof customClass[className] !== 'string' && !customClass[className].forEach) {
      return warn("Invalid type of customClass.".concat(className, "! Expected string or iterable object, got \"").concat(_typeof(customClass[className]), "\""));
    }

    addClass(elem, customClass[className]);
  }
};
function getInput(content, inputType) {
  if (!inputType) {
    return null;
  }

  switch (inputType) {
    case 'select':
    case 'textarea':
    case 'file':
      return getChildByClass(content, swalClasses[inputType]);

    case 'checkbox':
      return content.querySelector(".".concat(swalClasses.checkbox, " input"));

    case 'radio':
      return content.querySelector(".".concat(swalClasses.radio, " input:checked")) || content.querySelector(".".concat(swalClasses.radio, " input:first-child"));

    case 'range':
      return content.querySelector(".".concat(swalClasses.range, " input"));

    default:
      return getChildByClass(content, swalClasses.input);
  }
}
var focusInput = function focusInput(input) {
  input.focus(); // place cursor at end of text in text input

  if (input.type !== 'file') {
    // http://stackoverflow.com/a/2345915
    var val = input.value;
    input.value = '';
    input.value = val;
  }
};
var toggleClass = function toggleClass(target, classList, condition) {
  if (!target || !classList) {
    return;
  }

  if (typeof classList === 'string') {
    classList = classList.split(/\s+/).filter(Boolean);
  }

  classList.forEach(function (className) {
    if (target.forEach) {
      target.forEach(function (elem) {
        condition ? elem.classList.add(className) : elem.classList.remove(className);
      });
    } else {
      condition ? target.classList.add(className) : target.classList.remove(className);
    }
  });
};
var addClass = function addClass(target, classList) {
  toggleClass(target, classList, true);
};
var removeClass = function removeClass(target, classList) {
  toggleClass(target, classList, false);
};
var getChildByClass = function getChildByClass(elem, className) {
  for (var i = 0; i < elem.childNodes.length; i++) {
    if (hasClass(elem.childNodes[i], className)) {
      return elem.childNodes[i];
    }
  }
};
var applyNumericalStyle = function applyNumericalStyle(elem, property, value) {
  if (value || parseInt(value) === 0) {
    elem.style[property] = typeof value === 'number' ? value + 'px' : value;
  } else {
    elem.style.removeProperty(property);
  }
};
var show = function show(elem) {
  var display = arguments.length > 1 && arguments[1] !== undefined ? arguments[1] : 'flex';
  elem.style.opacity = '';
  elem.style.display = display;
};
var hide = function hide(elem) {
  elem.style.opacity = '';
  elem.style.display = 'none';
};
var toggle = function toggle(elem, condition, display) {
  condition ? show(elem, display) : hide(elem);
}; // borrowed from jquery $(elem).is(':visible') implementation

var isVisible = function isVisible(elem) {
  return !!(elem && (elem.offsetWidth || elem.offsetHeight || elem.getClientRects().length));
};
var isScrollable = function isScrollable(elem) {
  return !!(elem.scrollHeight > elem.clientHeight);
}; // borrowed from https://stackoverflow.com/a/46352119

var hasCssAnimation = function hasCssAnimation(elem) {
  var style = window.getComputedStyle(elem);
  var animDuration = parseFloat(style.getPropertyValue('animation-duration') || '0');
  var transDuration = parseFloat(style.getPropertyValue('transition-duration') || '0');
  return animDuration > 0 || transDuration > 0;
};
var contains = function contains(haystack, needle) {
  if (typeof haystack.contains === 'function') {
    return haystack.contains(needle);
  }
};

var getContainer = function getContainer() {
  return document.body.querySelector('.' + swalClasses.container);
};
var elementBySelector = function elementBySelector(selectorString) {
  var container = getContainer();
  return container ? container.querySelector(selectorString) : null;
};

var elementByClass = function elementByClass(className) {
  return elementBySelector('.' + className);
};

var getPopup = function getPopup() {
  return elementByClass(swalClasses.popup);
};
var getIcons = function getIcons() {
  var popup = getPopup();
  return toArray(popup.querySelectorAll('.' + swalClasses.icon));
};
var getIcon = function getIcon() {
  var visibleIcon = getIcons().filter(function (icon) {
    return isVisible(icon);
  });
  return visibleIcon.length ? visibleIcon[0] : null;
};
var getTitle = function getTitle() {
  return elementByClass(swalClasses.title);
};
var getContent = function getContent() {
  return elementByClass(swalClasses.content);
};
var getImage = function getImage() {
  return elementByClass(swalClasses.image);
};
var getProgressSteps = function getProgressSteps() {
  return elementByClass(swalClasses['progress-steps']);
};
var getValidationMessage = function getValidationMessage() {
  return elementByClass(swalClasses['validation-message']);
};
var getConfirmButton = function getConfirmButton() {
  return elementBySelector('.' + swalClasses.actions + ' .' + swalClasses.confirm);
};
var getCancelButton = function getCancelButton() {
  return elementBySelector('.' + swalClasses.actions + ' .' + swalClasses.cancel);
};
var getActions = function getActions() {
  return elementByClass(swalClasses.actions);
};
var getHeader = function getHeader() {
  return elementByClass(swalClasses.header);
};
var getFooter = function getFooter() {
  return elementByClass(swalClasses.footer);
};
var getCloseButton = function getCloseButton() {
  return elementByClass(swalClasses.close);
}; // https://github.com/jkup/focusable/blob/master/index.js

var focusable = "\n  a[href],\n  area[href],\n  input:not([disabled]),\n  select:not([disabled]),\n  textarea:not([disabled]),\n  button:not([disabled]),\n  iframe,\n  object,\n  embed,\n  [tabindex=\"0\"],\n  [contenteditable],\n  audio[controls],\n  video[controls],\n  summary\n";
var getFocusableElements = function getFocusableElements() {
  var focusableElementsWithTabindex = toArray(getPopup().querySelectorAll('[tabindex]:not([tabindex="-1"]):not([tabindex="0"])')) // sort according to tabindex
  .sort(function (a, b) {
    a = parseInt(a.getAttribute('tabindex'));
    b = parseInt(b.getAttribute('tabindex'));

    if (a > b) {
      return 1;
    } else if (a < b) {
      return -1;
    }

    return 0;
  });
  var otherFocusableElements = toArray(getPopup().querySelectorAll(focusable)).filter(function (el) {
    return el.getAttribute('tabindex') !== '-1';
  });
  return uniqueArray(focusableElementsWithTabindex.concat(otherFocusableElements)).filter(function (el) {
    return isVisible(el);
  });
};
var isModal = function isModal() {
  return !isToast() && !document.body.classList.contains(swalClasses['no-backdrop']);
};
var isToast = function isToast() {
  return document.body.classList.contains(swalClasses['toast-shown']);
};
var isLoading = function isLoading() {
  return getPopup().hasAttribute('data-loading');
};

// Detect Node env
var isNodeEnv = function isNodeEnv() {
  return typeof window === 'undefined' || typeof document === 'undefined';
};

var sweetHTML = "\n <div aria-labelledby=\"".concat(swalClasses.title, "\" aria-describedby=\"").concat(swalClasses.content, "\" class=\"").concat(swalClasses.popup, "\" tabindex=\"-1\">\n   <div class=\"").concat(swalClasses.header, "\">\n     <ul class=\"").concat(swalClasses['progress-steps'], "\"></ul>\n     <div class=\"").concat(swalClasses.icon, " ").concat(iconTypes.error, "\">\n       <span class=\"swal2-x-mark\"><span class=\"swal2-x-mark-line-left\"></span><span class=\"swal2-x-mark-line-right\"></span></span>\n     </div>\n     <div class=\"").concat(swalClasses.icon, " ").concat(iconTypes.question, "\"></div>\n     <div class=\"").concat(swalClasses.icon, " ").concat(iconTypes.warning, "\"></div>\n     <div class=\"").concat(swalClasses.icon, " ").concat(iconTypes.info, "\"></div>\n     <div class=\"").concat(swalClasses.icon, " ").concat(iconTypes.success, "\">\n       <div class=\"swal2-success-circular-line-left\"></div>\n       <span class=\"swal2-success-line-tip\"></span> <span class=\"swal2-success-line-long\"></span>\n       <div class=\"swal2-success-ring\"></div> <div class=\"swal2-success-fix\"></div>\n       <div class=\"swal2-success-circular-line-right\"></div>\n     </div>\n     <img class=\"").concat(swalClasses.image, "\" />\n     <h2 class=\"").concat(swalClasses.title, "\" id=\"").concat(swalClasses.title, "\"></h2>\n     <button type=\"button\" class=\"").concat(swalClasses.close, "\"></button>\n   </div>\n   <div class=\"").concat(swalClasses.content, "\">\n     <div id=\"").concat(swalClasses.content, "\"></div>\n     <input class=\"").concat(swalClasses.input, "\" />\n     <input type=\"file\" class=\"").concat(swalClasses.file, "\" />\n     <div class=\"").concat(swalClasses.range, "\">\n       <input type=\"range\" />\n       <output></output>\n     </div>\n     <select class=\"").concat(swalClasses.select, "\"></select>\n     <div class=\"").concat(swalClasses.radio, "\"></div>\n     <label for=\"").concat(swalClasses.checkbox, "\" class=\"").concat(swalClasses.checkbox, "\">\n       <input type=\"checkbox\" />\n       <span class=\"").concat(swalClasses.label, "\"></span>\n     </label>\n     <textarea class=\"").concat(swalClasses.textarea, "\"></textarea>\n     <div class=\"").concat(swalClasses['validation-message'], "\" id=\"").concat(swalClasses['validation-message'], "\"></div>\n   </div>\n   <div class=\"").concat(swalClasses.actions, "\">\n     <button type=\"button\" class=\"").concat(swalClasses.confirm, "\">OK</button>\n     <button type=\"button\" class=\"").concat(swalClasses.cancel, "\">Cancel</button>\n   </div>\n   <div class=\"").concat(swalClasses.footer, "\">\n   </div>\n </div>\n").replace(/(^|\n)\s*/g, '');

var resetOldContainer = function resetOldContainer() {
  var oldContainer = getContainer();

  if (!oldContainer) {
    return;
  }

  oldContainer.parentNode.removeChild(oldContainer);
  removeClass([document.documentElement, document.body], [swalClasses['no-backdrop'], swalClasses['toast-shown'], swalClasses['has-column']]);
};

var oldInputVal; // IE11 workaround, see #1109 for details

var resetValidationMessage = function resetValidationMessage(e) {
  if (Swal.isVisible() && oldInputVal !== e.target.value) {
    Swal.resetValidationMessage();
  }

  oldInputVal = e.target.value;
};

var addInputChangeListeners = function addInputChangeListeners() {
  var content = getContent();
  var input = getChildByClass(content, swalClasses.input);
  var file = getChildByClass(content, swalClasses.file);
  var range = content.querySelector(".".concat(swalClasses.range, " input"));
  var rangeOutput = content.querySelector(".".concat(swalClasses.range, " output"));
  var select = getChildByClass(content, swalClasses.select);
  var checkbox = content.querySelector(".".concat(swalClasses.checkbox, " input"));
  var textarea = getChildByClass(content, swalClasses.textarea);
  input.oninput = resetValidationMessage;
  file.onchange = resetValidationMessage;
  select.onchange = resetValidationMessage;
  checkbox.onchange = resetValidationMessage;
  textarea.oninput = resetValidationMessage;

  range.oninput = function (e) {
    resetValidationMessage(e);
    rangeOutput.value = range.value;
  };

  range.onchange = function (e) {
    resetValidationMessage(e);
    range.nextSibling.value = range.value;
  };
};

var getTarget = function getTarget(target) {
  return typeof target === 'string' ? document.querySelector(target) : target;
};

var setupAccessibility = function setupAccessibility(params) {
  var popup = getPopup();
  popup.setAttribute('role', params.toast ? 'alert' : 'dialog');
  popup.setAttribute('aria-live', params.toast ? 'polite' : 'assertive');

  if (!params.toast) {
    popup.setAttribute('aria-modal', 'true');
  }
};

var setupRTL = function setupRTL(targetElement) {
  if (window.getComputedStyle(targetElement).direction === 'rtl') {
    addClass(getContainer(), swalClasses.rtl);
  }
};
/*
 * Add modal + backdrop to DOM
 */


var init = function init(params) {
  // Clean up the old popup container if it exists
  resetOldContainer();
  /* istanbul ignore if */

  if (isNodeEnv()) {
    error('SweetAlert2 requires document to initialize');
    return;
  }

  var container = document.createElement('div');
  container.className = swalClasses.container;
  container.innerHTML = sweetHTML;
  var targetElement = getTarget(params.target);
  targetElement.appendChild(container);
  setupAccessibility(params);
  setupRTL(targetElement);
  addInputChangeListeners();
};

var parseHtmlToContainer = function parseHtmlToContainer(param, target) {
  // DOM element
  if (param instanceof HTMLElement) {
    target.appendChild(param); // JQuery element(s)
  } else if (_typeof(param) === 'object') {
    handleJqueryElem(target, param); // Plain string
  } else if (param) {
    target.innerHTML = param;
  }
};

var handleJqueryElem = function handleJqueryElem(target, elem) {
  target.innerHTML = '';

  if (0 in elem) {
    for (var i = 0; i in elem; i++) {
      target.appendChild(elem[i].cloneNode(true));
    }
  } else {
    target.appendChild(elem.cloneNode(true));
  }
};

var animationEndEvent = function () {
  // Prevent run in Node env

  /* istanbul ignore if */
  if (isNodeEnv()) {
    return false;
  }

  var testEl = document.createElement('div');
  var transEndEventNames = {
    WebkitAnimation: 'webkitAnimationEnd',
    OAnimation: 'oAnimationEnd oanimationend',
    animation: 'animationend'
  };

  for (var i in transEndEventNames) {
    if (Object.prototype.hasOwnProperty.call(transEndEventNames, i) && typeof testEl.style[i] !== 'undefined') {
      return transEndEventNames[i];
    }
  }

  return false;
}();

// Measure width of scrollbar
// https://github.com/twbs/bootstrap/blob/master/js/modal.js#L279-L286
var measureScrollbar = function measureScrollbar() {
  var supportsTouch = 'ontouchstart' in window || navigator.msMaxTouchPoints;

  if (supportsTouch) {
    return 0;
  }

  var scrollDiv = document.createElement('div');
  scrollDiv.style.width = '50px';
  scrollDiv.style.height = '50px';
  scrollDiv.style.overflow = 'scroll';
  document.body.appendChild(scrollDiv);
  var scrollbarWidth = scrollDiv.offsetWidth - scrollDiv.clientWidth;
  document.body.removeChild(scrollDiv);
  return scrollbarWidth;
};

var renderActions = function renderActions(instance, params) {
  var actions = getActions();
  var confirmButton = getConfirmButton();
  var cancelButton = getCancelButton(); // Actions (buttons) wrapper

  if (!params.showConfirmButton && !params.showCancelButton) {
    hide(actions);
  } // Custom class


  applyCustomClass(actions, params.customClass, 'actions'); // Render confirm button

  renderButton(confirmButton, 'confirm', params); // render Cancel Button

  renderButton(cancelButton, 'cancel', params);

  if (params.buttonsStyling) {
    handleButtonsStyling(confirmButton, cancelButton, params);
  } else {
    removeClass([confirmButton, cancelButton], swalClasses.styled);
    confirmButton.style.backgroundColor = confirmButton.style.borderLeftColor = confirmButton.style.borderRightColor = '';
    cancelButton.style.backgroundColor = cancelButton.style.borderLeftColor = cancelButton.style.borderRightColor = '';
  }

  if (params.reverseButtons) {
    confirmButton.parentNode.insertBefore(cancelButton, confirmButton);
  }
};

function handleButtonsStyling(confirmButton, cancelButton, params) {
  addClass([confirmButton, cancelButton], swalClasses.styled); // Buttons background colors

  if (params.confirmButtonColor) {
    confirmButton.style.backgroundColor = params.confirmButtonColor;
  }

  if (params.cancelButtonColor) {
    cancelButton.style.backgroundColor = params.cancelButtonColor;
  } // Loading state


  var confirmButtonBackgroundColor = window.getComputedStyle(confirmButton).getPropertyValue('background-color');
  confirmButton.style.borderLeftColor = confirmButtonBackgroundColor;
  confirmButton.style.borderRightColor = confirmButtonBackgroundColor;
}

function renderButton(button, buttonType, params) {
  toggle(button, params['showC' + buttonType.substring(1) + 'Button'], 'inline-block');
  button.innerHTML = params[buttonType + 'ButtonText']; // Set caption text

  button.setAttribute('aria-label', params[buttonType + 'ButtonAriaLabel']); // ARIA label
  // Add buttons custom classes

  button.className = swalClasses[buttonType];
  applyCustomClass(button, params.customClass, buttonType + 'Button');
  addClass(button, params[buttonType + 'ButtonClass']);
}

function handleBackdropParam(container, backdrop) {
  if (typeof backdrop === 'string') {
    container.style.background = backdrop;
  } else if (!backdrop) {
    addClass([document.documentElement, document.body], swalClasses['no-backdrop']);
  }
}

function handlePositionParam(container, position) {
  if (position in swalClasses) {
    addClass(container, swalClasses[position]);
  } else {
    warn('The "position" parameter is not valid, defaulting to "center"');
    addClass(container, swalClasses.center);
  }
}

function handleGrowParam(container, grow) {
  if (grow && typeof grow === 'string') {
    var growClass = 'grow-' + grow;

    if (growClass in swalClasses) {
      addClass(container, swalClasses[growClass]);
    }
  }
}

var renderContainer = function renderContainer(instance, params) {
  var container = getContainer();

  if (!container) {
    return;
  }

  handleBackdropParam(container, params.backdrop);

  if (!params.backdrop && params.allowOutsideClick) {
    warn('"allowOutsideClick" parameter requires `backdrop` parameter to be set to `true`');
  }

  handlePositionParam(container, params.position);
  handleGrowParam(container, params.grow); // Custom class

  applyCustomClass(container, params.customClass, 'container');

  if (params.customContainerClass) {
    // @deprecated
    addClass(container, params.customContainerClass);
  }
};

/**
 * This module containts `WeakMap`s for each effectively-"private  property" that a `Swal` has.
 * For example, to set the private property "foo" of `this` to "bar", you can `privateProps.foo.set(this, 'bar')`
 * This is the approach that Babel will probably take to implement private methods/fields
 *   https://github.com/tc39/proposal-private-methods
 *   https://github.com/babel/babel/pull/7555
 * Once we have the changes from that PR in Babel, and our core class fits reasonable in *one module*
 *   then we can use that language feature.
 */
var privateProps = {
  promise: new WeakMap(),
  innerParams: new WeakMap(),
  domCache: new WeakMap()
};

var inputTypes = ['input', 'file', 'range', 'select', 'radio', 'checkbox', 'textarea'];
var renderInput = function renderInput(instance, params) {
  var content = getContent();
  var innerParams = privateProps.innerParams.get(instance);
  var rerender = !innerParams || params.input !== innerParams.input;
  inputTypes.forEach(function (inputType) {
    var inputClass = swalClasses[inputType];
    var inputContainer = getChildByClass(content, inputClass); // set attributes

    setAttributes(inputType, params.inputAttributes); // set class

    inputContainer.className = inputClass;

    if (rerender) {
      hide(inputContainer);
    }
  });

  if (params.input) {
    if (rerender) {
      showInput(params);
    } // set custom class


    setCustomClass(params);
  }
};

var showInput = function showInput(params) {
  if (!renderInputType[params.input]) {
    return error("Unexpected type of input! Expected \"text\", \"email\", \"password\", \"number\", \"tel\", \"select\", \"radio\", \"checkbox\", \"textarea\", \"file\" or \"url\", got \"".concat(params.input, "\""));
  }

  var inputContainer = getInputContainer(params.input);
  var input = renderInputType[params.input](inputContainer, params);
  show(input); // input autofocus

  setTimeout(function () {
    focusInput(input);
  });
};

var removeAttributes = function removeAttributes(input) {
  for (var i = 0; i < input.attributes.length; i++) {
    var attrName = input.attributes[i].name;

    if (!(['type', 'value', 'style'].indexOf(attrName) !== -1)) {
      input.removeAttribute(attrName);
    }
  }
};

var setAttributes = function setAttributes(inputType, inputAttributes) {
  var input = getInput(getContent(), inputType);

  if (!input) {
    return;
  }

  removeAttributes(input);

  for (var attr in inputAttributes) {
    // Do not set a placeholder for <input type="range">
    // it'll crash Edge, #1298
    if (inputType === 'range' && attr === 'placeholder') {
      continue;
    }

    input.setAttribute(attr, inputAttributes[attr]);
  }
};

var setCustomClass = function setCustomClass(params) {
  var inputContainer = getInputContainer(params.input);

  if (params.inputClass) {
    addClass(inputContainer, params.inputClass);
  }

  if (params.customClass) {
    addClass(inputContainer, params.customClass.input);
  }
};

var setInputPlaceholder = function setInputPlaceholder(input, params) {
  if (!input.placeholder || params.inputPlaceholder) {
    input.placeholder = params.inputPlaceholder;
  }
};

var getInputContainer = function getInputContainer(inputType) {
  var inputClass = swalClasses[inputType] ? swalClasses[inputType] : swalClasses.input;
  return getChildByClass(getContent(), inputClass);
};

var renderInputType = {};

renderInputType.text = renderInputType.email = renderInputType.password = renderInputType.number = renderInputType.tel = renderInputType.url = function (input, params) {
  if (typeof params.inputValue === 'string' || typeof params.inputValue === 'number') {
    input.value = params.inputValue;
  } else if (!isPromise(params.inputValue)) {
    warn("Unexpected type of inputValue! Expected \"string\", \"number\" or \"Promise\", got \"".concat(_typeof(params.inputValue), "\""));
  }

  setInputPlaceholder(input, params);
  input.type = params.input;
  return input;
};

renderInputType.file = function (input, params) {
  setInputPlaceholder(input, params);
  return input;
};

renderInputType.range = function (range, params) {
  var rangeInput = range.querySelector('input');
  var rangeOutput = range.querySelector('output');
  rangeInput.value = params.inputValue;
  rangeInput.type = params.input;
  rangeOutput.value = params.inputValue;
  return range;
};

renderInputType.select = function (select, params) {
  select.innerHTML = '';

  if (params.inputPlaceholder) {
    var placeholder = document.createElement('option');
    placeholder.innerHTML = params.inputPlaceholder;
    placeholder.value = '';
    placeholder.disabled = true;
    placeholder.selected = true;
    select.appendChild(placeholder);
  }

  return select;
};

renderInputType.radio = function (radio) {
  radio.innerHTML = '';
  return radio;
};

renderInputType.checkbox = function (checkboxContainer, params) {
  var checkbox = getInput(getContent(), 'checkbox');
  checkbox.value = 1;
  checkbox.id = swalClasses.checkbox;
  checkbox.checked = Boolean(params.inputValue);
  var label = checkboxContainer.querySelector('span');
  label.innerHTML = params.inputPlaceholder;
  return checkboxContainer;
};

renderInputType.textarea = function (textarea, params) {
  textarea.value = params.inputValue;
  setInputPlaceholder(textarea, params);

  if ('MutationObserver' in window) {
    // #1699
    var initialPopupWidth = parseInt(window.getComputedStyle(getPopup()).width);
    var popupPadding = parseInt(window.getComputedStyle(getPopup()).paddingLeft) + parseInt(window.getComputedStyle(getPopup()).paddingRight);

    var outputsize = function outputsize() {
      var contentWidth = textarea.offsetWidth + popupPadding;

      if (contentWidth > initialPopupWidth) {
        getPopup().style.width = contentWidth + 'px';
      } else {
        getPopup().style.width = null;
      }
    };

    new MutationObserver(outputsize).observe(textarea, {
      attributes: true,
      attributeFilter: ['style']
    });
  }

  return textarea;
};

var renderContent = function renderContent(instance, params) {
  var content = getContent().querySelector('#' + swalClasses.content); // Content as HTML

  if (params.html) {
    parseHtmlToContainer(params.html, content);
    show(content, 'block'); // Content as plain text
  } else if (params.text) {
    content.textContent = params.text;
    show(content, 'block'); // No content
  } else {
    hide(content);
  }

  renderInput(instance, params); // Custom class

  applyCustomClass(getContent(), params.customClass, 'content');
};

var renderFooter = function renderFooter(instance, params) {
  var footer = getFooter();
  toggle(footer, params.footer);

  if (params.footer) {
    parseHtmlToContainer(params.footer, footer);
  } // Custom class


  applyCustomClass(footer, params.customClass, 'footer');
};

var renderCloseButton = function renderCloseButton(instance, params) {
  var closeButton = getCloseButton();
  closeButton.innerHTML = params.closeButtonHtml; // Custom class

  applyCustomClass(closeButton, params.customClass, 'closeButton');
  toggle(closeButton, params.showCloseButton);
  closeButton.setAttribute('aria-label', params.closeButtonAriaLabel);
};

var renderIcon = function renderIcon(instance, params) {
  var innerParams = privateProps.innerParams.get(instance); // if the icon with the given type already rendered,
  // apply the custom class without re-rendering the icon

  if (innerParams && params.type === innerParams.type && getIcon()) {
    applyCustomClass(getIcon(), params.customClass, 'icon');
    return;
  }

  hideAllIcons();

  if (!params.type) {
    return;
  }

  adjustSuccessIconBackgoundColor();

  if (Object.keys(iconTypes).indexOf(params.type) !== -1) {
    var icon = elementBySelector(".".concat(swalClasses.icon, ".").concat(iconTypes[params.type]));
    show(icon); // Custom class

    applyCustomClass(icon, params.customClass, 'icon'); // Animate icon

    toggleClass(icon, "swal2-animate-".concat(params.type, "-icon"), params.animation);
  } else {
    error("Unknown type! Expected \"success\", \"error\", \"warning\", \"info\" or \"question\", got \"".concat(params.type, "\""));
  }
};

var hideAllIcons = function hideAllIcons() {
  var icons = getIcons();

  for (var i = 0; i < icons.length; i++) {
    hide(icons[i]);
  }
}; // Adjust success icon background color to match the popup background color


var adjustSuccessIconBackgoundColor = function adjustSuccessIconBackgoundColor() {
  var popup = getPopup();
  var popupBackgroundColor = window.getComputedStyle(popup).getPropertyValue('background-color');
  var successIconParts = popup.querySelectorAll('[class^=swal2-success-circular-line], .swal2-success-fix');

  for (var i = 0; i < successIconParts.length; i++) {
    successIconParts[i].style.backgroundColor = popupBackgroundColor;
  }
};

var renderImage = function renderImage(instance, params) {
  var image = getImage();

  if (!params.imageUrl) {
    return hide(image);
  }

  show(image); // Src, alt

  image.setAttribute('src', params.imageUrl);
  image.setAttribute('alt', params.imageAlt); // Width, height

  applyNumericalStyle(image, 'width', params.imageWidth);
  applyNumericalStyle(image, 'height', params.imageHeight); // Class

  image.className = swalClasses.image;
  applyCustomClass(image, params.customClass, 'image');

  if (params.imageClass) {
    addClass(image, params.imageClass);
  }
};

var createStepElement = function createStepElement(step) {
  var stepEl = document.createElement('li');
  addClass(stepEl, swalClasses['progress-step']);
  stepEl.innerHTML = step;
  return stepEl;
};

var createLineElement = function createLineElement(params) {
  var lineEl = document.createElement('li');
  addClass(lineEl, swalClasses['progress-step-line']);

  if (params.progressStepsDistance) {
    lineEl.style.width = params.progressStepsDistance;
  }

  return lineEl;
};

var renderProgressSteps = function renderProgressSteps(instance, params) {
  var progressStepsContainer = getProgressSteps();

  if (!params.progressSteps || params.progressSteps.length === 0) {
    return hide(progressStepsContainer);
  }

  show(progressStepsContainer);
  progressStepsContainer.innerHTML = '';
  var currentProgressStep = parseInt(params.currentProgressStep === null ? Swal.getQueueStep() : params.currentProgressStep);

  if (currentProgressStep >= params.progressSteps.length) {
    warn('Invalid currentProgressStep parameter, it should be less than progressSteps.length ' + '(currentProgressStep like JS arrays starts from 0)');
  }

  params.progressSteps.forEach(function (step, index) {
    var stepEl = createStepElement(step);
    progressStepsContainer.appendChild(stepEl);

    if (index === currentProgressStep) {
      addClass(stepEl, swalClasses['active-progress-step']);
    }

    if (index !== params.progressSteps.length - 1) {
      var lineEl = createLineElement(step);
      progressStepsContainer.appendChild(lineEl);
    }
  });
};

var renderTitle = function renderTitle(instance, params) {
  var title = getTitle();
  toggle(title, params.title || params.titleText);

  if (params.title) {
    parseHtmlToContainer(params.title, title);
  }

  if (params.titleText) {
    title.innerText = params.titleText;
  } // Custom class


  applyCustomClass(title, params.customClass, 'title');
};

var renderHeader = function renderHeader(instance, params) {
  var header = getHeader(); // Custom class

  applyCustomClass(header, params.customClass, 'header'); // Progress steps

  renderProgressSteps(instance, params); // Icon

  renderIcon(instance, params); // Image

  renderImage(instance, params); // Title

  renderTitle(instance, params); // Close button

  renderCloseButton(instance, params);
};

var renderPopup = function renderPopup(instance, params) {
  var popup = getPopup(); // Width

  applyNumericalStyle(popup, 'width', params.width); // Padding

  applyNumericalStyle(popup, 'padding', params.padding); // Background

  if (params.background) {
    popup.style.background = params.background;
  } // Default Class


  popup.className = swalClasses.popup;

  if (params.toast) {
    addClass([document.documentElement, document.body], swalClasses['toast-shown']);
    addClass(popup, swalClasses.toast);
  } else {
    addClass(popup, swalClasses.modal);
  } // Custom class


  applyCustomClass(popup, params.customClass, 'popup');

  if (typeof params.customClass === 'string') {
    addClass(popup, params.customClass);
  } // CSS animation


  toggleClass(popup, swalClasses.noanimation, !params.animation);
};

var render = function render(instance, params) {
  renderPopup(instance, params);
  renderContainer(instance, params);
  renderHeader(instance, params);
  renderContent(instance, params);
  renderActions(instance, params);
  renderFooter(instance, params);

  if (typeof params.onRender === 'function') {
    params.onRender(getPopup());
  }
};

/*
 * Global function to determine if SweetAlert2 popup is shown
 */

var isVisible$1 = function isVisible$$1() {
  return isVisible(getPopup());
};
/*
 * Global function to click 'Confirm' button
 */

var clickConfirm = function clickConfirm() {
  return getConfirmButton() && getConfirmButton().click();
};
/*
 * Global function to click 'Cancel' button
 */

var clickCancel = function clickCancel() {
  return getCancelButton() && getCancelButton().click();
};

function fire() {
  var Swal = this;

  for (var _len = arguments.length, args = new Array(_len), _key = 0; _key < _len; _key++) {
    args[_key] = arguments[_key];
  }

  return _construct(Swal, args);
}

/**
 * Returns an extended version of `Swal` containing `params` as defaults.
 * Useful for reusing Swal configuration.
 *
 * For example:
 *
 * Before:
 * const textPromptOptions = { input: 'text', showCancelButton: true }
 * const {value: firstName} = await Swal.fire({ ...textPromptOptions, title: 'What is your first name?' })
 * const {value: lastName} = await Swal.fire({ ...textPromptOptions, title: 'What is your last name?' })
 *
 * After:
 * const TextPrompt = Swal.mixin({ input: 'text', showCancelButton: true })
 * const {value: firstName} = await TextPrompt('What is your first name?')
 * const {value: lastName} = await TextPrompt('What is your last name?')
 *
 * @param mixinParams
 */
function mixin(mixinParams) {
  var MixinSwal =
  /*#__PURE__*/
  function (_this) {
    _inherits(MixinSwal, _this);

    function MixinSwal() {
      _classCallCheck(this, MixinSwal);

      return _possibleConstructorReturn(this, _getPrototypeOf(MixinSwal).apply(this, arguments));
    }

    _createClass(MixinSwal, [{
      key: "_main",
      value: function _main(params) {
        return _get(_getPrototypeOf(MixinSwal.prototype), "_main", this).call(this, _extends({}, mixinParams, params));
      }
    }]);

    return MixinSwal;
  }(this);

  return MixinSwal;
}

// private global state for the queue feature
var currentSteps = [];
/*
 * Global function for chaining sweetAlert popups
 */

var queue = function queue(steps) {
  var Swal = this;
  currentSteps = steps;

  var resetAndResolve = function resetAndResolve(resolve, value) {
    currentSteps = [];
    document.body.removeAttribute('data-swal2-queue-step');
    resolve(value);
  };

  var queueResult = [];
  return new Promise(function (resolve) {
    (function step(i, callback) {
      if (i < currentSteps.length) {
        document.body.setAttribute('data-swal2-queue-step', i);
        Swal.fire(currentSteps[i]).then(function (result) {
          if (typeof result.value !== 'undefined') {
            queueResult.push(result.value);
            step(i + 1, callback);
          } else {
            resetAndResolve(resolve, {
              dismiss: result.dismiss
            });
          }
        });
      } else {
        resetAndResolve(resolve, {
          value: queueResult
        });
      }
    })(0);
  });
};
/*
 * Global function for getting the index of current popup in queue
 */

var getQueueStep = function getQueueStep() {
  return document.body.getAttribute('data-swal2-queue-step');
};
/*
 * Global function for inserting a popup to the queue
 */

var insertQueueStep = function insertQueueStep(step, index) {
  if (index && index < currentSteps.length) {
    return currentSteps.splice(index, 0, step);
  }

  return currentSteps.push(step);
};
/*
 * Global function for deleting a popup from the queue
 */

var deleteQueueStep = function deleteQueueStep(index) {
  if (typeof currentSteps[index] !== 'undefined') {
    currentSteps.splice(index, 1);
  }
};

/**
 * Show spinner instead of Confirm button and disable Cancel button
 */

var showLoading = function showLoading() {
  var popup = getPopup();

  if (!popup) {
    Swal.fire('');
  }

  popup = getPopup();
  var actions = getActions();
  var confirmButton = getConfirmButton();
  var cancelButton = getCancelButton();
  show(actions);
  show(confirmButton);
  addClass([popup, actions], swalClasses.loading);
  confirmButton.disabled = true;
  cancelButton.disabled = true;
  popup.setAttribute('data-loading', true);
  popup.setAttribute('aria-busy', true);
  popup.focus();
};

var RESTORE_FOCUS_TIMEOUT = 100;

var globalState = {};
var focusPreviousActiveElement = function focusPreviousActiveElement() {
  if (globalState.previousActiveElement && globalState.previousActiveElement.focus) {
    globalState.previousActiveElement.focus();
    globalState.previousActiveElement = null;
  } else if (document.body) {
    document.body.focus();
  }
}; // Restore previous active (focused) element


var restoreActiveElement = function restoreActiveElement() {
  return new Promise(function (resolve) {
    var x = window.scrollX;
    var y = window.scrollY;
    globalState.restoreFocusTimeout = setTimeout(function () {
      focusPreviousActiveElement();
      resolve();
    }, RESTORE_FOCUS_TIMEOUT); // issues/900

    if (typeof x !== 'undefined' && typeof y !== 'undefined') {
      // IE doesn't have scrollX/scrollY support
      window.scrollTo(x, y);
    }
  });
};

/**
 * If `timer` parameter is set, returns number of milliseconds of timer remained.
 * Otherwise, returns undefined.
 */

var getTimerLeft = function getTimerLeft() {
  return globalState.timeout && globalState.timeout.getTimerLeft();
};
/**
 * Stop timer. Returns number of milliseconds of timer remained.
 * If `timer` parameter isn't set, returns undefined.
 */

var stopTimer = function stopTimer() {
  return globalState.timeout && globalState.timeout.stop();
};
/**
 * Resume timer. Returns number of milliseconds of timer remained.
 * If `timer` parameter isn't set, returns undefined.
 */

var resumeTimer = function resumeTimer() {
  return globalState.timeout && globalState.timeout.start();
};
/**
 * Resume timer. Returns number of milliseconds of timer remained.
 * If `timer` parameter isn't set, returns undefined.
 */

var toggleTimer = function toggleTimer() {
  var timer = globalState.timeout;
  return timer && (timer.running ? timer.stop() : timer.start());
};
/**
 * Increase timer. Returns number of milliseconds of an updated timer.
 * If `timer` parameter isn't set, returns undefined.
 */

var increaseTimer = function increaseTimer(n) {
  return globalState.timeout && globalState.timeout.increase(n);
};
/**
 * Check if timer is running. Returns true if timer is running
 * or false if timer is paused or stopped.
 * If `timer` parameter isn't set, returns undefined
 */

var isTimerRunning = function isTimerRunning() {
  return globalState.timeout && globalState.timeout.isRunning();
};

var defaultParams = {
  title: '',
  titleText: '',
  text: '',
  html: '',
  footer: '',
  type: null,
  toast: false,
  customClass: '',
  customContainerClass: '',
  target: 'body',
  backdrop: true,
  animation: true,
  heightAuto: true,
  allowOutsideClick: true,
  allowEscapeKey: true,
  allowEnterKey: true,
  stopKeydownPropagation: true,
  keydownListenerCapture: false,
  showConfirmButton: true,
  showCancelButton: false,
  preConfirm: null,
  confirmButtonText: 'OK',
  confirmButtonAriaLabel: '',
  confirmButtonColor: null,
  confirmButtonClass: '',
  cancelButtonText: 'Cancel',
  cancelButtonAriaLabel: '',
  cancelButtonColor: null,
  cancelButtonClass: '',
  buttonsStyling: true,
  reverseButtons: false,
  focusConfirm: true,
  focusCancel: false,
  showCloseButton: false,
  closeButtonHtml: '&times;',
  closeButtonAriaLabel: 'Close this dialog',
  showLoaderOnConfirm: false,
  imageUrl: null,
  imageWidth: null,
  imageHeight: null,
  imageAlt: '',
  imageClass: '',
  timer: null,
  width: null,
  padding: null,
  background: null,
  input: null,
  inputPlaceholder: '',
  inputValue: '',
  inputOptions: {},
  inputAutoTrim: true,
  inputClass: '',
  inputAttributes: {},
  inputValidator: null,
  validationMessage: null,
  grow: false,
  position: 'center',
  progressSteps: [],
  currentProgressStep: null,
  progressStepsDistance: null,
  onBeforeOpen: null,
  onOpen: null,
  onRender: null,
  onClose: null,
  onAfterClose: null,
  scrollbarPadding: true
};
var updatableParams = ['title', 'titleText', 'text', 'html', 'type', 'customClass', 'showConfirmButton', 'showCancelButton', 'confirmButtonText', 'confirmButtonAriaLabel', 'confirmButtonColor', 'confirmButtonClass', 'cancelButtonText', 'cancelButtonAriaLabel', 'cancelButtonColor', 'cancelButtonClass', 'buttonsStyling', 'reverseButtons', 'imageUrl', 'imageWidth', 'imageHeigth', 'imageAlt', 'imageClass', 'progressSteps', 'currentProgressStep'];
var deprecatedParams = {
  customContainerClass: 'customClass',
  confirmButtonClass: 'customClass',
  cancelButtonClass: 'customClass',
  imageClass: 'customClass',
  inputClass: 'customClass'
};
var toastIncompatibleParams = ['allowOutsideClick', 'allowEnterKey', 'backdrop', 'focusConfirm', 'focusCancel', 'heightAuto', 'keydownListenerCapture'];
/**
 * Is valid parameter
 * @param {String} paramName
 */

var isValidParameter = function isValidParameter(paramName) {
  return Object.prototype.hasOwnProperty.call(defaultParams, paramName);
};
/**
 * Is valid parameter for Swal.update() method
 * @param {String} paramName
 */

var isUpdatableParameter = function isUpdatableParameter(paramName) {
  return updatableParams.indexOf(paramName) !== -1;
};
/**
 * Is deprecated parameter
 * @param {String} paramName
 */

var isDeprecatedParameter = function isDeprecatedParameter(paramName) {
  return deprecatedParams[paramName];
};

var checkIfParamIsValid = function checkIfParamIsValid(param) {
  if (!isValidParameter(param)) {
    warn("Unknown parameter \"".concat(param, "\""));
  }
};

var checkIfToastParamIsValid = function checkIfToastParamIsValid(param) {
  if (toastIncompatibleParams.indexOf(param) !== -1) {
    warn("The parameter \"".concat(param, "\" is incompatible with toasts"));
  }
};

var checkIfParamIsDeprecated = function checkIfParamIsDeprecated(param) {
  if (isDeprecatedParameter(param)) {
    warnAboutDepreation(param, isDeprecatedParameter(param));
  }
};
/**
 * Show relevant warnings for given params
 *
 * @param params
 */


var showWarningsForParams = function showWarningsForParams(params) {
  for (var param in params) {
    checkIfParamIsValid(param);

    if (params.toast) {
      checkIfToastParamIsValid(param);
    }

    checkIfParamIsDeprecated();
  }
};



var staticMethods = Object.freeze({
	isValidParameter: isValidParameter,
	isUpdatableParameter: isUpdatableParameter,
	isDeprecatedParameter: isDeprecatedParameter,
	argsToParams: argsToParams,
	isVisible: isVisible$1,
	clickConfirm: clickConfirm,
	clickCancel: clickCancel,
	getContainer: getContainer,
	getPopup: getPopup,
	getTitle: getTitle,
	getContent: getContent,
	getImage: getImage,
	getIcon: getIcon,
	getIcons: getIcons,
	getCloseButton: getCloseButton,
	getActions: getActions,
	getConfirmButton: getConfirmButton,
	getCancelButton: getCancelButton,
	getHeader: getHeader,
	getFooter: getFooter,
	getFocusableElements: getFocusableElements,
	getValidationMessage: getValidationMessage,
	isLoading: isLoading,
	fire: fire,
	mixin: mixin,
	queue: queue,
	getQueueStep: getQueueStep,
	insertQueueStep: insertQueueStep,
	deleteQueueStep: deleteQueueStep,
	showLoading: showLoading,
	enableLoading: showLoading,
	getTimerLeft: getTimerLeft,
	stopTimer: stopTimer,
	resumeTimer: resumeTimer,
	toggleTimer: toggleTimer,
	increaseTimer: increaseTimer,
	isTimerRunning: isTimerRunning
});

/**
 * Enables buttons and hide loader.
 */

function hideLoading() {
  var innerParams = privateProps.innerParams.get(this);
  var domCache = privateProps.domCache.get(this);

  if (!innerParams.showConfirmButton) {
    hide(domCache.confirmButton);

    if (!innerParams.showCancelButton) {
      hide(domCache.actions);
    }
  }

  removeClass([domCache.popup, domCache.actions], swalClasses.loading);
  domCache.popup.removeAttribute('aria-busy');
  domCache.popup.removeAttribute('data-loading');
  domCache.confirmButton.disabled = false;
  domCache.cancelButton.disabled = false;
}

function getInput$1(instance) {
  var innerParams = privateProps.innerParams.get(instance || this);
  var domCache = privateProps.domCache.get(instance || this);

  if (!domCache) {
    return null;
  }

  return getInput(domCache.content, innerParams.input);
}

var fixScrollbar = function fixScrollbar() {
  // for queues, do not do this more than once
  if (states.previousBodyPadding !== null) {
    return;
  } // if the body has overflow


  if (document.body.scrollHeight > window.innerHeight) {
    // add padding so the content doesn't shift after removal of scrollbar
    states.previousBodyPadding = parseInt(window.getComputedStyle(document.body).getPropertyValue('padding-right'));
    document.body.style.paddingRight = states.previousBodyPadding + measureScrollbar() + 'px';
  }
};
var undoScrollbar = function undoScrollbar() {
  if (states.previousBodyPadding !== null) {
    document.body.style.paddingRight = states.previousBodyPadding + 'px';
    states.previousBodyPadding = null;
  }
};

/* istanbul ignore next */

var iOSfix = function iOSfix() {
  var iOS = /iPad|iPhone|iPod/.test(navigator.userAgent) && !window.MSStream || navigator.platform === 'MacIntel' && navigator.maxTouchPoints > 1;

  if (iOS && !hasClass(document.body, swalClasses.iosfix)) {
    var offset = document.body.scrollTop;
    document.body.style.top = offset * -1 + 'px';
    addClass(document.body, swalClasses.iosfix);
    lockBodyScroll();
  }
};

var lockBodyScroll = function lockBodyScroll() {
  // #1246
  var container = getContainer();
  var preventTouchMove;

  container.ontouchstart = function (e) {
    preventTouchMove = e.target === container || !isScrollable(container) && e.target.tagName !== 'INPUT' // #1603
    ;
  };

  container.ontouchmove = function (e) {
    if (preventTouchMove) {
      e.preventDefault();
      e.stopPropagation();
    }
  };
};
/* istanbul ignore next */


var undoIOSfix = function undoIOSfix() {
  if (hasClass(document.body, swalClasses.iosfix)) {
    var offset = parseInt(document.body.style.top, 10);
    removeClass(document.body, swalClasses.iosfix);
    document.body.style.top = '';
    document.body.scrollTop = offset * -1;
  }
};

var isIE11 = function isIE11() {
  return !!window.MSInputMethodContext && !!document.documentMode;
}; // Fix IE11 centering sweetalert2/issues/933

/* istanbul ignore next */


var fixVerticalPositionIE = function fixVerticalPositionIE() {
  var container = getContainer();
  var popup = getPopup();
  container.style.removeProperty('align-items');

  if (popup.offsetTop < 0) {
    container.style.alignItems = 'flex-start';
  }
};
/* istanbul ignore next */


var IEfix = function IEfix() {
  if (typeof window !== 'undefined' && isIE11()) {
    fixVerticalPositionIE();
    window.addEventListener('resize', fixVerticalPositionIE);
  }
};
/* istanbul ignore next */

var undoIEfix = function undoIEfix() {
  if (typeof window !== 'undefined' && isIE11()) {
    window.removeEventListener('resize', fixVerticalPositionIE);
  }
};

// Adding aria-hidden="true" to elements outside of the active modal dialog ensures that
// elements not within the active modal dialog will not be surfaced if a user opens a screen
// reader’s list of elements (headings, form controls, landmarks, etc.) in the document.

var setAriaHidden = function setAriaHidden() {
  var bodyChildren = toArray(document.body.children);
  bodyChildren.forEach(function (el) {
    if (el === getContainer() || contains(el, getContainer())) {
      return;
    }

    if (el.hasAttribute('aria-hidden')) {
      el.setAttribute('data-previous-aria-hidden', el.getAttribute('aria-hidden'));
    }

    el.setAttribute('aria-hidden', 'true');
  });
};
var unsetAriaHidden = function unsetAriaHidden() {
  var bodyChildren = toArray(document.body.children);
  bodyChildren.forEach(function (el) {
    if (el.hasAttribute('data-previous-aria-hidden')) {
      el.setAttribute('aria-hidden', el.getAttribute('data-previous-aria-hidden'));
      el.removeAttribute('data-previous-aria-hidden');
    } else {
      el.removeAttribute('aria-hidden');
    }
  });
};

/**
 * This module containts `WeakMap`s for each effectively-"private  property" that a `Swal` has.
 * For example, to set the private property "foo" of `this` to "bar", you can `privateProps.foo.set(this, 'bar')`
 * This is the approach that Babel will probably take to implement private methods/fields
 *   https://github.com/tc39/proposal-private-methods
 *   https://github.com/babel/babel/pull/7555
 * Once we have the changes from that PR in Babel, and our core class fits reasonable in *one module*
 *   then we can use that language feature.
 */
var privateMethods = {
  swalPromiseResolve: new WeakMap()
};

/*
 * Instance method to close sweetAlert
 */

function removePopupAndResetState(instance, container, isToast, onAfterClose) {
  if (isToast) {
    triggerOnAfterCloseAndDispose(instance, onAfterClose);
  } else {
    restoreActiveElement().then(function () {
      return triggerOnAfterCloseAndDispose(instance, onAfterClose);
    });
    globalState.keydownTarget.removeEventListener('keydown', globalState.keydownHandler, {
      capture: globalState.keydownListenerCapture
    });
    globalState.keydownHandlerAdded = false;
  }

  if (container.parentNode) {
    container.parentNode.removeChild(container);
  }

  if (isModal()) {
    undoScrollbar();
    undoIOSfix();
    undoIEfix();
    unsetAriaHidden();
  }

  removeBodyClasses();
}

function removeBodyClasses() {
  removeClass([document.documentElement, document.body], [swalClasses.shown, swalClasses['height-auto'], swalClasses['no-backdrop'], swalClasses['toast-shown'], swalClasses['toast-column']]);
}

function disposeSwal(instance) {
  // Unset this.params so GC will dispose it (#1569)
  delete instance.params; // Unset globalState props so GC will dispose globalState (#1569)

  delete globalState.keydownHandler;
  delete globalState.keydownTarget; // Unset WeakMaps so GC will be able to dispose them (#1569)

  unsetWeakMaps(privateProps);
  unsetWeakMaps(privateMethods);
}

function close(resolveValue) {
  var popup = getPopup();

  if (!popup || hasClass(popup, swalClasses.hide)) {
    return;
  }

  var innerParams = privateProps.innerParams.get(this);

  if (!innerParams) {
    return;
  }

  var swalPromiseResolve = privateMethods.swalPromiseResolve.get(this);
  removeClass(popup, swalClasses.show);
  addClass(popup, swalClasses.hide);
  handlePopupAnimation(this, popup, innerParams); // Resolve Swal promise

  swalPromiseResolve(resolveValue || {});
}

var handlePopupAnimation = function handlePopupAnimation(instance, popup, innerParams) {
  var container = getContainer(); // If animation is supported, animate

  var animationIsSupported = animationEndEvent && hasCssAnimation(popup);
  var onClose = innerParams.onClose,
      onAfterClose = innerParams.onAfterClose;

  if (onClose !== null && typeof onClose === 'function') {
    onClose(popup);
  }

  if (animationIsSupported) {
    animatePopup(instance, popup, container, onAfterClose);
  } else {
    // Otherwise, remove immediately
    removePopupAndResetState(instance, container, isToast(), onAfterClose);
  }
};

var animatePopup = function animatePopup(instance, popup, container, onAfterClose) {
  globalState.swalCloseEventFinishedCallback = removePopupAndResetState.bind(null, instance, container, isToast(), onAfterClose);
  popup.addEventListener(animationEndEvent, function (e) {
    if (e.target === popup) {
      globalState.swalCloseEventFinishedCallback();
      delete globalState.swalCloseEventFinishedCallback;
    }
  });
};

var unsetWeakMaps = function unsetWeakMaps(obj) {
  for (var i in obj) {
    obj[i] = new WeakMap();
  }
};

var triggerOnAfterCloseAndDispose = function triggerOnAfterCloseAndDispose(instance, onAfterClose) {
  setTimeout(function () {
    if (onAfterClose !== null && typeof onAfterClose === 'function') {
      onAfterClose();
    }

    if (!getPopup()) {
      disposeSwal(instance);
    }
  });
};

function setButtonsDisabled(instance, buttons, disabled) {
  var domCache = privateProps.domCache.get(instance);
  buttons.forEach(function (button) {
    domCache[button].disabled = disabled;
  });
}

function setInputDisabled(input, disabled) {
  if (!input) {
    return false;
  }

  if (input.type === 'radio') {
    var radiosContainer = input.parentNode.parentNode;
    var radios = radiosContainer.querySelectorAll('input');

    for (var i = 0; i < radios.length; i++) {
      radios[i].disabled = disabled;
    }
  } else {
    input.disabled = disabled;
  }
}

function enableButtons() {
  setButtonsDisabled(this, ['confirmButton', 'cancelButton'], false);
}
function disableButtons() {
  setButtonsDisabled(this, ['confirmButton', 'cancelButton'], true);
} // @deprecated

function enableConfirmButton() {
  warnAboutDepreation('Swal.enableConfirmButton()', "Swal.getConfirmButton().removeAttribute('disabled')");
  setButtonsDisabled(this, ['confirmButton'], false);
} // @deprecated

function disableConfirmButton() {
  warnAboutDepreation('Swal.disableConfirmButton()', "Swal.getConfirmButton().setAttribute('disabled', '')");
  setButtonsDisabled(this, ['confirmButton'], true);
}
function enableInput() {
  return setInputDisabled(this.getInput(), false);
}
function disableInput() {
  return setInputDisabled(this.getInput(), true);
}

function showValidationMessage(error) {
  var domCache = privateProps.domCache.get(this);
  domCache.validationMessage.innerHTML = error;
  var popupComputedStyle = window.getComputedStyle(domCache.popup);
  domCache.validationMessage.style.marginLeft = "-".concat(popupComputedStyle.getPropertyValue('padding-left'));
  domCache.validationMessage.style.marginRight = "-".concat(popupComputedStyle.getPropertyValue('padding-right'));
  show(domCache.validationMessage);
  var input = this.getInput();

  if (input) {
    input.setAttribute('aria-invalid', true);
    input.setAttribute('aria-describedBy', swalClasses['validation-message']);
    focusInput(input);
    addClass(input, swalClasses.inputerror);
  }
} // Hide block with validation message

function resetValidationMessage$1() {
  var domCache = privateProps.domCache.get(this);

  if (domCache.validationMessage) {
    hide(domCache.validationMessage);
  }

  var input = this.getInput();

  if (input) {
    input.removeAttribute('aria-invalid');
    input.removeAttribute('aria-describedBy');
    removeClass(input, swalClasses.inputerror);
  }
}

function getProgressSteps$1() {
  warnAboutDepreation('Swal.getProgressSteps()', "const swalInstance = Swal.fire({progressSteps: ['1', '2', '3']}); const progressSteps = swalInstance.params.progressSteps");
  var innerParams = privateProps.innerParams.get(this);
  return innerParams.progressSteps;
}
function setProgressSteps(progressSteps) {
  warnAboutDepreation('Swal.setProgressSteps()', 'Swal.update()');
  var innerParams = privateProps.innerParams.get(this);

  var updatedParams = _extends({}, innerParams, {
    progressSteps: progressSteps
  });

  renderProgressSteps(this, updatedParams);
  privateProps.innerParams.set(this, updatedParams);
}
function showProgressSteps() {
  var domCache = privateProps.domCache.get(this);
  show(domCache.progressSteps);
}
function hideProgressSteps() {
  var domCache = privateProps.domCache.get(this);
  hide(domCache.progressSteps);
}

var Timer =
/*#__PURE__*/
function () {
  function Timer(callback, delay) {
    _classCallCheck(this, Timer);

    this.callback = callback;
    this.remaining = delay;
    this.running = false;
    this.start();
  }

  _createClass(Timer, [{
    key: "start",
    value: function start() {
      if (!this.running) {
        this.running = true;
        this.started = new Date();
        this.id = setTimeout(this.callback, this.remaining);
      }

      return this.remaining;
    }
  }, {
    key: "stop",
    value: function stop() {
      if (this.running) {
        this.running = false;
        clearTimeout(this.id);
        this.remaining -= new Date() - this.started;
      }

      return this.remaining;
    }
  }, {
    key: "increase",
    value: function increase(n) {
      var running = this.running;

      if (running) {
        this.stop();
      }

      this.remaining += n;

      if (running) {
        this.start();
      }

      return this.remaining;
    }
  }, {
    key: "getTimerLeft",
    value: function getTimerLeft() {
      if (this.running) {
        this.stop();
        this.start();
      }

      return this.remaining;
    }
  }, {
    key: "isRunning",
    value: function isRunning() {
      return this.running;
    }
  }]);

  return Timer;
}();

var defaultInputValidators = {
  email: function email(string, validationMessage) {
    return /^[a-zA-Z0-9.+_-]+@[a-zA-Z0-9.-]+\.[a-zA-Z0-9-]{2,24}$/.test(string) ? Promise.resolve() : Promise.resolve(validationMessage || 'Invalid email address');
  },
  url: function url(string, validationMessage) {
    // taken from https://stackoverflow.com/a/3809435 with a small change from #1306
    return /^https?:\/\/(www\.)?[-a-zA-Z0-9@:%._+~#=]{2,256}\.[a-z]{2,63}\b([-a-zA-Z0-9@:%_+.~#?&/=]*)$/.test(string) ? Promise.resolve() : Promise.resolve(validationMessage || 'Invalid URL');
  }
};

function setDefaultInputValidators(params) {
  // Use default `inputValidator` for supported input types if not provided
  if (!params.inputValidator) {
    Object.keys(defaultInputValidators).forEach(function (key) {
      if (params.input === key) {
        params.inputValidator = defaultInputValidators[key];
      }
    });
  }
}

function validateCustomTargetElement(params) {
  // Determine if the custom target element is valid
  if (!params.target || typeof params.target === 'string' && !document.querySelector(params.target) || typeof params.target !== 'string' && !params.target.appendChild) {
    warn('Target parameter is not valid, defaulting to "body"');
    params.target = 'body';
  }
}
/**
 * Set type, text and actions on popup
 *
 * @param params
 * @returns {boolean}
 */


function setParameters(params) {
  setDefaultInputValidators(params); // showLoaderOnConfirm && preConfirm

  if (params.showLoaderOnConfirm && !params.preConfirm) {
    warn('showLoaderOnConfirm is set to true, but preConfirm is not defined.\n' + 'showLoaderOnConfirm should be used together with preConfirm, see usage example:\n' + 'https://sweetalert2.github.io/#ajax-request');
  } // params.animation will be actually used in renderPopup.js
  // but in case when params.animation is a function, we need to call that function
  // before popup (re)initialization, so it'll be possible to check Swal.isVisible()
  // inside the params.animation function


  params.animation = callIfFunction(params.animation);
  validateCustomTargetElement(params); // Replace newlines with <br> in title

  if (typeof params.title === 'string') {
    params.title = params.title.split('\n').join('<br />');
  }

  init(params);
}

function swalOpenAnimationFinished(popup, container) {
  popup.removeEventListener(animationEndEvent, swalOpenAnimationFinished);
  container.style.overflowY = 'auto';
}
/**
 * Open popup, add necessary classes and styles, fix scrollbar
 *
 * @param {Array} params
 */


var openPopup = function openPopup(params) {
  var container = getContainer();
  var popup = getPopup();

  if (typeof params.onBeforeOpen === 'function') {
    params.onBeforeOpen(popup);
  }

  addClasses(container, popup, params); // scrolling is 'hidden' until animation is done, after that 'auto'

  setScrollingVisibility(container, popup);

  if (isModal()) {
    fixScrollContainer(container, params.scrollbarPadding);
  }

  if (!isToast() && !globalState.previousActiveElement) {
    globalState.previousActiveElement = document.activeElement;
  }

  if (typeof params.onOpen === 'function') {
    setTimeout(function () {
      return params.onOpen(popup);
    });
  }
};

var setScrollingVisibility = function setScrollingVisibility(container, popup) {
  if (animationEndEvent && hasCssAnimation(popup)) {
    container.style.overflowY = 'hidden';
    popup.addEventListener(animationEndEvent, swalOpenAnimationFinished.bind(null, popup, container));
  } else {
    container.style.overflowY = 'auto';
  }
};

var fixScrollContainer = function fixScrollContainer(container, scrollbarPadding) {
  iOSfix();
  IEfix();
  setAriaHidden();

  if (scrollbarPadding) {
    fixScrollbar();
  } // sweetalert2/issues/1247


  setTimeout(function () {
    container.scrollTop = 0;
  });
};

var addClasses = function addClasses(container, popup, params) {
  if (params.animation) {
    addClass(popup, swalClasses.show);
  }

  show(popup);
  addClass([document.documentElement, document.body, container], swalClasses.shown);

  if (params.heightAuto && params.backdrop && !params.toast) {
    addClass([document.documentElement, document.body], swalClasses['height-auto']);
  }
};

var handleInputOptionsAndValue = function handleInputOptionsAndValue(instance, params) {
  if (params.input === 'select' || params.input === 'radio') {
    handleInputOptions(instance, params);
  } else if (['text', 'email', 'number', 'tel', 'textarea'].indexOf(params.input) !== -1 && isPromise(params.inputValue)) {
    handleInputValue(instance, params);
  }
};
var getInputValue = function getInputValue(instance, innerParams) {
  var input = instance.getInput();

  if (!input) {
    return null;
  }

  switch (innerParams.input) {
    case 'checkbox':
      return getCheckboxValue(input);

    case 'radio':
      return getRadioValue(input);

    case 'file':
      return getFileValue(input);

    default:
      return innerParams.inputAutoTrim ? input.value.trim() : input.value;
  }
};

var getCheckboxValue = function getCheckboxValue(input) {
  return input.checked ? 1 : 0;
};

var getRadioValue = function getRadioValue(input) {
  return input.checked ? input.value : null;
};

var getFileValue = function getFileValue(input) {
  return input.files.length ? input.getAttribute('multiple') !== null ? input.files : input.files[0] : null;
};

var handleInputOptions = function handleInputOptions(instance, params) {
  var content = getContent();

  var processInputOptions = function processInputOptions(inputOptions) {
    return populateInputOptions[params.input](content, formatInputOptions(inputOptions), params);
  };

  if (isPromise(params.inputOptions)) {
    showLoading();
    params.inputOptions.then(function (inputOptions) {
      instance.hideLoading();
      processInputOptions(inputOptions);
    });
  } else if (_typeof(params.inputOptions) === 'object') {
    processInputOptions(params.inputOptions);
  } else {
    error("Unexpected type of inputOptions! Expected object, Map or Promise, got ".concat(_typeof(params.inputOptions)));
  }
};

var handleInputValue = function handleInputValue(instance, params) {
  var input = instance.getInput();
  hide(input);
  params.inputValue.then(function (inputValue) {
    input.value = params.input === 'number' ? parseFloat(inputValue) || 0 : inputValue + '';
    show(input);
    input.focus();
    instance.hideLoading();
  })["catch"](function (err) {
    error('Error in inputValue promise: ' + err);
    input.value = '';
    show(input);
    input.focus();
    instance.hideLoading();
  });
};

var populateInputOptions = {
  select: function select(content, inputOptions, params) {
    var select = getChildByClass(content, swalClasses.select);
    inputOptions.forEach(function (inputOption) {
      var optionValue = inputOption[0];
      var optionLabel = inputOption[1];
      var option = document.createElement('option');
      option.value = optionValue;
      option.innerHTML = optionLabel;

      if (params.inputValue.toString() === optionValue.toString()) {
        option.selected = true;
      }

      select.appendChild(option);
    });
    select.focus();
  },
  radio: function radio(content, inputOptions, params) {
    var radio = getChildByClass(content, swalClasses.radio);
    inputOptions.forEach(function (inputOption) {
      var radioValue = inputOption[0];
      var radioLabel = inputOption[1];
      var radioInput = document.createElement('input');
      var radioLabelElement = document.createElement('label');
      radioInput.type = 'radio';
      radioInput.name = swalClasses.radio;
      radioInput.value = radioValue;

      if (params.inputValue.toString() === radioValue.toString()) {
        radioInput.checked = true;
      }

      var label = document.createElement('span');
      label.innerHTML = radioLabel;
      label.className = swalClasses.label;
      radioLabelElement.appendChild(radioInput);
      radioLabelElement.appendChild(label);
      radio.appendChild(radioLabelElement);
    });
    var radios = radio.querySelectorAll('input');

    if (radios.length) {
      radios[0].focus();
    }
  }
};
/**
 * Converts `inputOptions` into an array of `[value, label]`s
 * @param inputOptions
 */

var formatInputOptions = function formatInputOptions(inputOptions) {
  var result = [];

  if (typeof Map !== 'undefined' && inputOptions instanceof Map) {
    inputOptions.forEach(function (value, key) {
      result.push([key, value]);
    });
  } else {
    Object.keys(inputOptions).forEach(function (key) {
      result.push([key, inputOptions[key]]);
    });
  }

  return result;
};

var handleConfirmButtonClick = function handleConfirmButtonClick(instance, innerParams) {
  instance.disableButtons();

  if (innerParams.input) {
    handleConfirmWithInput(instance, innerParams);
  } else {
    confirm(instance, innerParams, true);
  }
};
var handleCancelButtonClick = function handleCancelButtonClick(instance, dismissWith) {
  instance.disableButtons();
  dismissWith(DismissReason.cancel);
};

var handleConfirmWithInput = function handleConfirmWithInput(instance, innerParams) {
  var inputValue = getInputValue(instance, innerParams);

  if (innerParams.inputValidator) {
    instance.disableInput();
    var validationPromise = Promise.resolve().then(function () {
      return innerParams.inputValidator(inputValue, innerParams.validationMessage);
    });
    validationPromise.then(function (validationMessage) {
      instance.enableButtons();
      instance.enableInput();

      if (validationMessage) {
        instance.showValidationMessage(validationMessage);
      } else {
        confirm(instance, innerParams, inputValue);
      }
    });
  } else if (!instance.getInput().checkValidity()) {
    instance.enableButtons();
    instance.showValidationMessage(innerParams.validationMessage);
  } else {
    confirm(instance, innerParams, inputValue);
  }
};

var succeedWith = function succeedWith(instance, value) {
  instance.closePopup({
    value: value
  });
};

var confirm = function confirm(instance, innerParams, value) {
  if (innerParams.showLoaderOnConfirm) {
    showLoading(); // TODO: make showLoading an *instance* method
  }

  if (innerParams.preConfirm) {
    instance.resetValidationMessage();
    var preConfirmPromise = Promise.resolve().then(function () {
      return innerParams.preConfirm(value, innerParams.validationMessage);
    });
    preConfirmPromise.then(function (preConfirmValue) {
      if (isVisible(getValidationMessage()) || preConfirmValue === false) {
        instance.hideLoading();
      } else {
        succeedWith(instance, typeof preConfirmValue === 'undefined' ? value : preConfirmValue);
      }
    });
  } else {
    succeedWith(instance, value);
  }
};

var addKeydownHandler = function addKeydownHandler(instance, globalState, innerParams, dismissWith) {
  if (globalState.keydownTarget && globalState.keydownHandlerAdded) {
    globalState.keydownTarget.removeEventListener('keydown', globalState.keydownHandler, {
      capture: globalState.keydownListenerCapture
    });
    globalState.keydownHandlerAdded = false;
  }

  if (!innerParams.toast) {
    globalState.keydownHandler = function (e) {
      return keydownHandler(instance, e, innerParams, dismissWith);
    };

    globalState.keydownTarget = innerParams.keydownListenerCapture ? window : getPopup();
    globalState.keydownListenerCapture = innerParams.keydownListenerCapture;
    globalState.keydownTarget.addEventListener('keydown', globalState.keydownHandler, {
      capture: globalState.keydownListenerCapture
    });
    globalState.keydownHandlerAdded = true;
  }
}; // Focus handling

var setFocus = function setFocus(innerParams, index, increment) {
  var focusableElements = getFocusableElements(); // search for visible elements and select the next possible match

  for (var i = 0; i < focusableElements.length; i++) {
    index = index + increment; // rollover to first item

    if (index === focusableElements.length) {
      index = 0; // go to last item
    } else if (index === -1) {
      index = focusableElements.length - 1;
    }

    return focusableElements[index].focus();
  } // no visible focusable elements, focus the popup


  getPopup().focus();
};
var arrowKeys = ['ArrowLeft', 'ArrowRight', 'ArrowUp', 'ArrowDown', 'Left', 'Right', 'Up', 'Down' // IE11
];
var escKeys = ['Escape', 'Esc' // IE11
];

var keydownHandler = function keydownHandler(instance, e, innerParams, dismissWith) {
  if (innerParams.stopKeydownPropagation) {
    e.stopPropagation();
  } // ENTER


  if (e.key === 'Enter') {
    handleEnter(instance, e, innerParams); // TAB
  } else if (e.key === 'Tab') {
    handleTab(e, innerParams); // ARROWS - switch focus between buttons
  } else if (arrowKeys.indexOf(e.key) !== -1) {
    handleArrows(); // ESC
  } else if (escKeys.indexOf(e.key) !== -1) {
    handleEsc(e, innerParams, dismissWith);
  }
};

var handleEnter = function handleEnter(instance, e, innerParams) {
  // #720 #721
  if (e.isComposing) {
    return;
  }

  if (e.target && instance.getInput() && e.target.outerHTML === instance.getInput().outerHTML) {
    if (['textarea', 'file'].indexOf(innerParams.input) !== -1) {
      return; // do not submit
    }

    clickConfirm();
    e.preventDefault();
  }
};

var handleTab = function handleTab(e, innerParams) {
  var targetElement = e.target;
  var focusableElements = getFocusableElements();
  var btnIndex = -1;

  for (var i = 0; i < focusableElements.length; i++) {
    if (targetElement === focusableElements[i]) {
      btnIndex = i;
      break;
    }
  }

  if (!e.shiftKey) {
    // Cycle to the next button
    setFocus(innerParams, btnIndex, 1);
  } else {
    // Cycle to the prev button
    setFocus(innerParams, btnIndex, -1);
  }

  e.stopPropagation();
  e.preventDefault();
};

var handleArrows = function handleArrows() {
  var confirmButton = getConfirmButton();
  var cancelButton = getCancelButton(); // focus Cancel button if Confirm button is currently focused

  if (document.activeElement === confirmButton && isVisible(cancelButton)) {
    cancelButton.focus(); // and vice versa
  } else if (document.activeElement === cancelButton && isVisible(confirmButton)) {
    confirmButton.focus();
  }
};

var handleEsc = function handleEsc(e, innerParams, dismissWith) {
  if (callIfFunction(innerParams.allowEscapeKey)) {
    e.preventDefault();
    dismissWith(DismissReason.esc);
  }
};

var handlePopupClick = function handlePopupClick(domCache, innerParams, dismissWith) {
  if (innerParams.toast) {
    handleToastClick(domCache, innerParams, dismissWith);
  } else {
    // Ignore click events that had mousedown on the popup but mouseup on the container
    // This can happen when the user drags a slider
    handleModalMousedown(domCache); // Ignore click events that had mousedown on the container but mouseup on the popup

    handleContainerMousedown(domCache);
    handleModalClick(domCache, innerParams, dismissWith);
  }
};

var handleToastClick = function handleToastClick(domCache, innerParams, dismissWith) {
  // Closing toast by internal click
  domCache.popup.onclick = function () {
    if (innerParams.showConfirmButton || innerParams.showCancelButton || innerParams.showCloseButton || innerParams.input) {
      return;
    }

    dismissWith(DismissReason.close);
  };
};

var ignoreOutsideClick = false;

var handleModalMousedown = function handleModalMousedown(domCache) {
  domCache.popup.onmousedown = function () {
    domCache.container.onmouseup = function (e) {
      domCache.container.onmouseup = undefined; // We only check if the mouseup target is the container because usually it doesn't
      // have any other direct children aside of the popup

      if (e.target === domCache.container) {
        ignoreOutsideClick = true;
      }
    };
  };
};

var handleContainerMousedown = function handleContainerMousedown(domCache) {
  domCache.container.onmousedown = function () {
    domCache.popup.onmouseup = function (e) {
      domCache.popup.onmouseup = undefined; // We also need to check if the mouseup target is a child of the popup

      if (e.target === domCache.popup || domCache.popup.contains(e.target)) {
        ignoreOutsideClick = true;
      }
    };
  };
};

var handleModalClick = function handleModalClick(domCache, innerParams, dismissWith) {
  domCache.container.onclick = function (e) {
    if (ignoreOutsideClick) {
      ignoreOutsideClick = false;
      return;
    }

    if (e.target === domCache.container && callIfFunction(innerParams.allowOutsideClick)) {
      dismissWith(DismissReason.backdrop);
    }
  };
};

function _main(userParams) {
  showWarningsForParams(userParams); // Check if there is another Swal closing

  if (getPopup() && globalState.swalCloseEventFinishedCallback) {
    globalState.swalCloseEventFinishedCallback();
    delete globalState.swalCloseEventFinishedCallback;
  } // Check if there is a swal disposal defer timer


  if (globalState.deferDisposalTimer) {
    clearTimeout(globalState.deferDisposalTimer);
    delete globalState.deferDisposalTimer;
  }

  var innerParams = _extends({}, defaultParams, userParams);

  setParameters(innerParams);
  Object.freeze(innerParams); // clear the previous timer

  if (globalState.timeout) {
    globalState.timeout.stop();
    delete globalState.timeout;
  } // clear the restore focus timeout


  clearTimeout(globalState.restoreFocusTimeout);
  var domCache = populateDomCache(this);
  render(this, innerParams);
  privateProps.innerParams.set(this, innerParams);
  return swalPromise(this, domCache, innerParams);
}

var swalPromise = function swalPromise(instance, domCache, innerParams) {
  return new Promise(function (resolve) {
    // functions to handle all closings/dismissals
    var dismissWith = function dismissWith(dismiss) {
      instance.closePopup({
        dismiss: dismiss
      });
    };

    privateMethods.swalPromiseResolve.set(instance, resolve);
    setupTimer(globalState, innerParams, dismissWith);

    domCache.confirmButton.onclick = function () {
      return handleConfirmButtonClick(instance, innerParams);
    };

    domCache.cancelButton.onclick = function () {
      return handleCancelButtonClick(instance, dismissWith);
    };

    domCache.closeButton.onclick = function () {
      return dismissWith(DismissReason.close);
    };

    handlePopupClick(domCache, innerParams, dismissWith);
    addKeydownHandler(instance, globalState, innerParams, dismissWith);

    if (innerParams.toast && (innerParams.input || innerParams.footer || innerParams.showCloseButton)) {
      addClass(document.body, swalClasses['toast-column']);
    } else {
      removeClass(document.body, swalClasses['toast-column']);
    }

    handleInputOptionsAndValue(instance, innerParams);
    openPopup(innerParams);
    initFocus(domCache, innerParams); // Scroll container to top on open (#1247)

    domCache.container.scrollTop = 0;
  });
};

var populateDomCache = function populateDomCache(instance) {
  var domCache = {
    popup: getPopup(),
    container: getContainer(),
    content: getContent(),
    actions: getActions(),
    confirmButton: getConfirmButton(),
    cancelButton: getCancelButton(),
    closeButton: getCloseButton(),
    validationMessage: getValidationMessage(),
    progressSteps: getProgressSteps()
  };
  privateProps.domCache.set(instance, domCache);
  return domCache;
};

var setupTimer = function setupTimer(globalState$$1, innerParams, dismissWith) {
  if (innerParams.timer) {
    globalState$$1.timeout = new Timer(function () {
      dismissWith('timer');
      delete globalState$$1.timeout;
    }, innerParams.timer);
  }
};

var initFocus = function initFocus(domCache, innerParams) {
  if (innerParams.toast) {
    return;
  }

  if (!callIfFunction(innerParams.allowEnterKey)) {
    return blurActiveElement();
  }

  if (innerParams.focusCancel && isVisible(domCache.cancelButton)) {
    return domCache.cancelButton.focus();
  }

  if (innerParams.focusConfirm && isVisible(domCache.confirmButton)) {
    return domCache.confirmButton.focus();
  }

  setFocus(innerParams, -1, 1);
};

var blurActiveElement = function blurActiveElement() {
  if (document.activeElement && typeof document.activeElement.blur === 'function') {
    document.activeElement.blur();
  }
};

/**
 * Updates popup parameters.
 */

function update(params) {
  var popup = getPopup();

  if (!popup || hasClass(popup, swalClasses.hide)) {
    return warn("You're trying to update the closed or closing popup, that won't work. Use the update() method in preConfirm parameter or show a new popup.");
  }

  var validUpdatableParams = {}; // assign valid params from `params` to `defaults`

  Object.keys(params).forEach(function (param) {
    if (Swal.isUpdatableParameter(param)) {
      validUpdatableParams[param] = params[param];
    } else {
      warn("Invalid parameter to update: \"".concat(param, "\". Updatable params are listed here: https://github.com/sweetalert2/sweetalert2/blob/master/src/utils/params.js"));
    }
  });
  var innerParams = privateProps.innerParams.get(this);

  var updatedParams = _extends({}, innerParams, validUpdatableParams);

  render(this, updatedParams);
  privateProps.innerParams.set(this, updatedParams);
  Object.defineProperties(this, {
    params: {
      value: _extends({}, this.params, params),
      writable: false,
      enumerable: true
    }
  });
}



var instanceMethods = Object.freeze({
	hideLoading: hideLoading,
	disableLoading: hideLoading,
	getInput: getInput$1,
	close: close,
	closePopup: close,
	closeModal: close,
	closeToast: close,
	enableButtons: enableButtons,
	disableButtons: disableButtons,
	enableConfirmButton: enableConfirmButton,
	disableConfirmButton: disableConfirmButton,
	enableInput: enableInput,
	disableInput: disableInput,
	showValidationMessage: showValidationMessage,
	resetValidationMessage: resetValidationMessage$1,
	getProgressSteps: getProgressSteps$1,
	setProgressSteps: setProgressSteps,
	showProgressSteps: showProgressSteps,
	hideProgressSteps: hideProgressSteps,
	_main: _main,
	update: update
});

var currentInstance; // SweetAlert constructor

function SweetAlert() {
  // Prevent run in Node env

  /* istanbul ignore if */
  if (typeof window === 'undefined') {
    return;
  } // Check for the existence of Promise

  /* istanbul ignore if */


  if (typeof Promise === 'undefined') {
    error('This package requires a Promise library, please include a shim to enable it in this browser (See: https://github.com/sweetalert2/sweetalert2/wiki/Migration-from-SweetAlert-to-SweetAlert2#1-ie-support)');
  }

  currentInstance = this;

  for (var _len = arguments.length, args = new Array(_len), _key = 0; _key < _len; _key++) {
    args[_key] = arguments[_key];
  }

  var outerParams = Object.freeze(this.constructor.argsToParams(args));
  Object.defineProperties(this, {
    params: {
      value: outerParams,
      writable: false,
      enumerable: true,
      configurable: true
    }
  });

  var promise = this._main(this.params);

  privateProps.promise.set(this, promise);
} // `catch` cannot be the name of a module export, so we define our thenable methods here instead


SweetAlert.prototype.then = function (onFulfilled) {
  var promise = privateProps.promise.get(this);
  return promise.then(onFulfilled);
};

SweetAlert.prototype["finally"] = function (onFinally) {
  var promise = privateProps.promise.get(this);
  return promise["finally"](onFinally);
}; // Assign instance methods from src/instanceMethods/*.js to prototype


_extends(SweetAlert.prototype, instanceMethods); // Assign static methods from src/staticMethods/*.js to constructor


_extends(SweetAlert, staticMethods); // Proxy to instance methods to constructor, for now, for backwards compatibility


Object.keys(instanceMethods).forEach(function (key) {
  SweetAlert[key] = function () {
    if (currentInstance) {
      var _currentInstance;

      return (_currentInstance = currentInstance)[key].apply(_currentInstance, arguments);
    }
  };
});
SweetAlert.DismissReason = DismissReason;
SweetAlert.version = '8.19.0';

var Swal = SweetAlert;
Swal["default"] = Swal;

return Swal;

})));
if (typeof this !== 'undefined' && this.Sweetalert2){  this.swal = this.sweetAlert = this.Swal = this.SweetAlert = this.Sweetalert2}

"undefined"!=typeof document&&function(e,t){var n=e.createElement("style");if(e.getElementsByTagName("head")[0].appendChild(n),n.styleSheet)n.styleSheet.disabled||(n.styleSheet.cssText=t);else try{n.innerHTML=t}catch(e){n.innerText=t}}(document,"@charset \"UTF-8\";.swal2-popup.swal2-toast{flex-direction:row;align-items:center;width:auto;padding:.625em;overflow-y:hidden;box-shadow:0 0 .625em #d9d9d9}.swal2-popup.swal2-toast .swal2-header{flex-direction:row}.swal2-popup.swal2-toast .swal2-title{flex-grow:1;justify-content:flex-start;margin:0 .6em;font-size:1em}.swal2-popup.swal2-toast .swal2-footer{margin:.5em 0 0;padding:.5em 0 0;font-size:.8em}.swal2-popup.swal2-toast .swal2-close{position:static;width:.8em;height:.8em;line-height:.8}.swal2-popup.swal2-toast .swal2-content{justify-content:flex-start;font-size:1em}.swal2-popup.swal2-toast .swal2-icon{width:2em;min-width:2em;height:2em;margin:0}.swal2-popup.swal2-toast .swal2-icon::before{display:flex;align-items:center;font-size:2em;font-weight:700}@media all and (-ms-high-contrast:none),(-ms-high-contrast:active){.swal2-popup.swal2-toast .swal2-icon::before{font-size:.25em}}.swal2-popup.swal2-toast .swal2-icon.swal2-success .swal2-success-ring{width:2em;height:2em}.swal2-popup.swal2-toast .swal2-icon.swal2-error [class^=swal2-x-mark-line]{top:.875em;width:1.375em}.swal2-popup.swal2-toast .swal2-icon.swal2-error [class^=swal2-x-mark-line][class$=left]{left:.3125em}.swal2-popup.swal2-toast .swal2-icon.swal2-error [class^=swal2-x-mark-line][class$=right]{right:.3125em}.swal2-popup.swal2-toast .swal2-actions{flex-basis:auto!important;width:auto;height:auto;margin:0 .3125em}.swal2-popup.swal2-toast .swal2-styled{margin:0 .3125em;padding:.3125em .625em;font-size:1em}.swal2-popup.swal2-toast .swal2-styled:focus{box-shadow:0 0 0 .0625em #fff,0 0 0 .125em rgba(50,100,150,.4)}.swal2-popup.swal2-toast .swal2-success{border-color:#a5dc86}.swal2-popup.swal2-toast .swal2-success [class^=swal2-success-circular-line]{position:absolute;width:1.6em;height:3em;transform:rotate(45deg);border-radius:50%}.swal2-popup.swal2-toast .swal2-success [class^=swal2-success-circular-line][class$=left]{top:-.8em;left:-.5em;transform:rotate(-45deg);transform-origin:2em 2em;border-radius:4em 0 0 4em}.swal2-popup.swal2-toast .swal2-success [class^=swal2-success-circular-line][class$=right]{top:-.25em;left:.9375em;transform-origin:0 1.5em;border-radius:0 4em 4em 0}.swal2-popup.swal2-toast .swal2-success .swal2-success-ring{width:2em;height:2em}.swal2-popup.swal2-toast .swal2-success .swal2-success-fix{top:0;left:.4375em;width:.4375em;height:2.6875em}.swal2-popup.swal2-toast .swal2-success [class^=swal2-success-line]{height:.3125em}.swal2-popup.swal2-toast .swal2-success [class^=swal2-success-line][class$=tip]{top:1.125em;left:.1875em;width:.75em}.swal2-popup.swal2-toast .swal2-success [class^=swal2-success-line][class$=long]{top:.9375em;right:.1875em;width:1.375em}.swal2-popup.swal2-toast.swal2-show{-webkit-animation:swal2-toast-show .5s;animation:swal2-toast-show .5s}.swal2-popup.swal2-toast.swal2-hide{-webkit-animation:swal2-toast-hide .1s forwards;animation:swal2-toast-hide .1s forwards}.swal2-popup.swal2-toast .swal2-animate-success-icon .swal2-success-line-tip{-webkit-animation:swal2-toast-animate-success-line-tip .75s;animation:swal2-toast-animate-success-line-tip .75s}.swal2-popup.swal2-toast .swal2-animate-success-icon .swal2-success-line-long{-webkit-animation:swal2-toast-animate-success-line-long .75s;animation:swal2-toast-animate-success-line-long .75s}.swal2-container{display:flex;position:fixed;z-index:1060;top:0;right:0;bottom:0;left:0;flex-direction:row;align-items:center;justify-content:center;padding:.625em;overflow-x:hidden;transition:background-color .1s;background-color:transparent;-webkit-overflow-scrolling:touch}.swal2-container.swal2-top{align-items:flex-start}.swal2-container.swal2-top-left,.swal2-container.swal2-top-start{align-items:flex-start;justify-content:flex-start}.swal2-container.swal2-top-end,.swal2-container.swal2-top-right{align-items:flex-start;justify-content:flex-end}.swal2-container.swal2-center{align-items:center}.swal2-container.swal2-center-left,.swal2-container.swal2-center-start{align-items:center;justify-content:flex-start}.swal2-container.swal2-center-end,.swal2-container.swal2-center-right{align-items:center;justify-content:flex-end}.swal2-container.swal2-bottom{align-items:flex-end}.swal2-container.swal2-bottom-left,.swal2-container.swal2-bottom-start{align-items:flex-end;justify-content:flex-start}.swal2-container.swal2-bottom-end,.swal2-container.swal2-bottom-right{align-items:flex-end;justify-content:flex-end}.swal2-container.swal2-bottom-end>:first-child,.swal2-container.swal2-bottom-left>:first-child,.swal2-container.swal2-bottom-right>:first-child,.swal2-container.swal2-bottom-start>:first-child,.swal2-container.swal2-bottom>:first-child{margin-top:auto}.swal2-container.swal2-grow-fullscreen>.swal2-modal{display:flex!important;flex:1;align-self:stretch;justify-content:center}.swal2-container.swal2-grow-row>.swal2-modal{display:flex!important;flex:1;align-content:center;justify-content:center}.swal2-container.swal2-grow-column{flex:1;flex-direction:column}.swal2-container.swal2-grow-column.swal2-bottom,.swal2-container.swal2-grow-column.swal2-center,.swal2-container.swal2-grow-column.swal2-top{align-items:center}.swal2-container.swal2-grow-column.swal2-bottom-left,.swal2-container.swal2-grow-column.swal2-bottom-start,.swal2-container.swal2-grow-column.swal2-center-left,.swal2-container.swal2-grow-column.swal2-center-start,.swal2-container.swal2-grow-column.swal2-top-left,.swal2-container.swal2-grow-column.swal2-top-start{align-items:flex-start}.swal2-container.swal2-grow-column.swal2-bottom-end,.swal2-container.swal2-grow-column.swal2-bottom-right,.swal2-container.swal2-grow-column.swal2-center-end,.swal2-container.swal2-grow-column.swal2-center-right,.swal2-container.swal2-grow-column.swal2-top-end,.swal2-container.swal2-grow-column.swal2-top-right{align-items:flex-end}.swal2-container.swal2-grow-column>.swal2-modal{display:flex!important;flex:1;align-content:center;justify-content:center}.swal2-container:not(.swal2-top):not(.swal2-top-start):not(.swal2-top-end):not(.swal2-top-left):not(.swal2-top-right):not(.swal2-center-start):not(.swal2-center-end):not(.swal2-center-left):not(.swal2-center-right):not(.swal2-bottom):not(.swal2-bottom-start):not(.swal2-bottom-end):not(.swal2-bottom-left):not(.swal2-bottom-right):not(.swal2-grow-fullscreen)>.swal2-modal{margin:auto}@media all and (-ms-high-contrast:none),(-ms-high-contrast:active){.swal2-container .swal2-modal{margin:0!important}}.swal2-container.swal2-shown{background-color:rgba(0,0,0,.4)}.swal2-popup{display:none;position:relative;box-sizing:border-box;flex-direction:column;justify-content:center;width:32em;max-width:100%;padding:1.25em;border:none;border-radius:.3125em;background:#fff;font-family:inherit;font-size:1rem}.swal2-popup:focus{outline:0}.swal2-popup.swal2-loading{overflow-y:hidden}.swal2-header{display:flex;flex-direction:column;align-items:center}.swal2-title{position:relative;max-width:100%;margin:0 0 .4em;padding:0;color:#595959;font-size:1.875em;font-weight:600;text-align:center;text-transform:none;word-wrap:break-word}.swal2-actions{display:flex;z-index:1;flex-wrap:wrap;align-items:center;justify-content:center;width:100%;margin:1.25em auto 0}.swal2-actions:not(.swal2-loading) .swal2-styled[disabled]{opacity:.4}.swal2-actions:not(.swal2-loading) .swal2-styled:hover{background-image:linear-gradient(rgba(0,0,0,.1),rgba(0,0,0,.1))}.swal2-actions:not(.swal2-loading) .swal2-styled:active{background-image:linear-gradient(rgba(0,0,0,.2),rgba(0,0,0,.2))}.swal2-actions.swal2-loading .swal2-styled.swal2-confirm{box-sizing:border-box;width:2.5em;height:2.5em;margin:.46875em;padding:0;-webkit-animation:swal2-rotate-loading 1.5s linear 0s infinite normal;animation:swal2-rotate-loading 1.5s linear 0s infinite normal;border:.25em solid transparent;border-radius:100%;border-color:transparent;background-color:transparent!important;color:transparent;cursor:default;-webkit-user-select:none;-moz-user-select:none;-ms-user-select:none;user-select:none}.swal2-actions.swal2-loading .swal2-styled.swal2-cancel{margin-right:30px;margin-left:30px}.swal2-actions.swal2-loading :not(.swal2-styled).swal2-confirm::after{content:\"\";display:inline-block;width:15px;height:15px;margin-left:5px;-webkit-animation:swal2-rotate-loading 1.5s linear 0s infinite normal;animation:swal2-rotate-loading 1.5s linear 0s infinite normal;border:3px solid #999;border-radius:50%;border-right-color:transparent;box-shadow:1px 1px 1px #fff}.swal2-styled{margin:.3125em;padding:.625em 2em;box-shadow:none;font-weight:500}.swal2-styled:not([disabled]){cursor:pointer}.swal2-styled.swal2-confirm{border:0;border-radius:.25em;background:initial;background-color:#3085d6;color:#fff;font-size:1.0625em}.swal2-styled.swal2-cancel{border:0;border-radius:.25em;background:initial;background-color:#aaa;color:#fff;font-size:1.0625em}.swal2-styled:focus{outline:0;box-shadow:0 0 0 2px #fff,0 0 0 4px rgba(50,100,150,.4)}.swal2-styled::-moz-focus-inner{border:0}.swal2-footer{justify-content:center;margin:1.25em 0 0;padding:1em 0 0;border-top:1px solid #eee;color:#545454;font-size:1em}.swal2-image{max-width:100%;margin:1.25em auto}.swal2-close{position:absolute;z-index:2;top:0;right:0;justify-content:center;width:1.2em;height:1.2em;padding:0;overflow:hidden;transition:color .1s ease-out;border:none;border-radius:0;outline:initial;background:0 0;color:#ccc;font-family:serif;font-size:2.5em;line-height:1.2;cursor:pointer}.swal2-close:hover{transform:none;background:0 0;color:#f27474}.swal2-content{z-index:1;justify-content:center;margin:0;padding:0;color:#545454;font-size:1.125em;font-weight:400;line-height:normal;text-align:center;word-wrap:break-word}.swal2-checkbox,.swal2-file,.swal2-input,.swal2-radio,.swal2-select,.swal2-textarea{margin:1em auto}.swal2-file,.swal2-input,.swal2-textarea{box-sizing:border-box;width:100%;transition:border-color .3s,box-shadow .3s;border:1px solid #d9d9d9;border-radius:.1875em;background:inherit;box-shadow:inset 0 1px 1px rgba(0,0,0,.06);color:inherit;font-size:1.125em}.swal2-file.swal2-inputerror,.swal2-input.swal2-inputerror,.swal2-textarea.swal2-inputerror{border-color:#f27474!important;box-shadow:0 0 2px #f27474!important}.swal2-file:focus,.swal2-input:focus,.swal2-textarea:focus{border:1px solid #b4dbed;outline:0;box-shadow:0 0 3px #c4e6f5}.swal2-file::-webkit-input-placeholder,.swal2-input::-webkit-input-placeholder,.swal2-textarea::-webkit-input-placeholder{color:#ccc}.swal2-file::-moz-placeholder,.swal2-input::-moz-placeholder,.swal2-textarea::-moz-placeholder{color:#ccc}.swal2-file:-ms-input-placeholder,.swal2-input:-ms-input-placeholder,.swal2-textarea:-ms-input-placeholder{color:#ccc}.swal2-file::-ms-input-placeholder,.swal2-input::-ms-input-placeholder,.swal2-textarea::-ms-input-placeholder{color:#ccc}.swal2-file::placeholder,.swal2-input::placeholder,.swal2-textarea::placeholder{color:#ccc}.swal2-range{margin:1em auto;background:inherit}.swal2-range input{width:80%}.swal2-range output{width:20%;color:inherit;font-weight:600;text-align:center}.swal2-range input,.swal2-range output{height:2.625em;padding:0;font-size:1.125em;line-height:2.625em}.swal2-input{height:2.625em;padding:0 .75em}.swal2-input[type=number]{max-width:10em}.swal2-file{background:inherit;font-size:1.125em}.swal2-textarea{height:6.75em;padding:.75em}.swal2-select{min-width:50%;max-width:100%;padding:.375em .625em;background:inherit;color:inherit;font-size:1.125em}.swal2-checkbox,.swal2-radio{align-items:center;justify-content:center;background:inherit;color:inherit}.swal2-checkbox label,.swal2-radio label{margin:0 .6em;font-size:1.125em}.swal2-checkbox input,.swal2-radio input{margin:0 .4em}.swal2-validation-message{display:none;align-items:center;justify-content:center;padding:.625em;overflow:hidden;background:#f0f0f0;color:#666;font-size:1em;font-weight:300}.swal2-validation-message::before{content:\"!\";display:inline-block;width:1.5em;min-width:1.5em;height:1.5em;margin:0 .625em;border-radius:50%;background-color:#f27474;color:#fff;font-weight:600;line-height:1.5em;text-align:center}.swal2-icon{position:relative;box-sizing:content-box;justify-content:center;width:5em;height:5em;margin:1.25em auto 1.875em;border:.25em solid transparent;border-radius:50%;font-family:inherit;line-height:5em;cursor:default;-webkit-user-select:none;-moz-user-select:none;-ms-user-select:none;user-select:none}.swal2-icon::before{display:flex;align-items:center;height:92%;font-size:3.75em}.swal2-icon.swal2-error{border-color:#f27474}.swal2-icon.swal2-error .swal2-x-mark{position:relative;flex-grow:1}.swal2-icon.swal2-error [class^=swal2-x-mark-line]{display:block;position:absolute;top:2.3125em;width:2.9375em;height:.3125em;border-radius:.125em;background-color:#f27474}.swal2-icon.swal2-error [class^=swal2-x-mark-line][class$=left]{left:1.0625em;transform:rotate(45deg)}.swal2-icon.swal2-error [class^=swal2-x-mark-line][class$=right]{right:1em;transform:rotate(-45deg)}.swal2-icon.swal2-warning{border-color:#facea8;color:#f8bb86}.swal2-icon.swal2-warning::before{content:\"!\"}.swal2-icon.swal2-info{border-color:#9de0f6;color:#3fc3ee}.swal2-icon.swal2-info::before{content:\"i\"}.swal2-icon.swal2-question{border-color:#c9dae1;color:#87adbd}.swal2-icon.swal2-question::before{content:\"?\"}.swal2-icon.swal2-question.swal2-arabic-question-mark::before{content:\"؟\"}.swal2-icon.swal2-success{border-color:#a5dc86}.swal2-icon.swal2-success [class^=swal2-success-circular-line]{position:absolute;width:3.75em;height:7.5em;transform:rotate(45deg);border-radius:50%}.swal2-icon.swal2-success [class^=swal2-success-circular-line][class$=left]{top:-.4375em;left:-2.0635em;transform:rotate(-45deg);transform-origin:3.75em 3.75em;border-radius:7.5em 0 0 7.5em}.swal2-icon.swal2-success [class^=swal2-success-circular-line][class$=right]{top:-.6875em;left:1.875em;transform:rotate(-45deg);transform-origin:0 3.75em;border-radius:0 7.5em 7.5em 0}.swal2-icon.swal2-success .swal2-success-ring{position:absolute;z-index:2;top:-.25em;left:-.25em;box-sizing:content-box;width:100%;height:100%;border:.25em solid rgba(165,220,134,.3);border-radius:50%}.swal2-icon.swal2-success .swal2-success-fix{position:absolute;z-index:1;top:.5em;left:1.625em;width:.4375em;height:5.625em;transform:rotate(-45deg)}.swal2-icon.swal2-success [class^=swal2-success-line]{display:block;position:absolute;z-index:2;height:.3125em;border-radius:.125em;background-color:#a5dc86}.swal2-icon.swal2-success [class^=swal2-success-line][class$=tip]{top:2.875em;left:.875em;width:1.5625em;transform:rotate(45deg)}.swal2-icon.swal2-success [class^=swal2-success-line][class$=long]{top:2.375em;right:.5em;width:2.9375em;transform:rotate(-45deg)}.swal2-progress-steps{align-items:center;margin:0 0 1.25em;padding:0;background:inherit;font-weight:600}.swal2-progress-steps li{display:inline-block;position:relative}.swal2-progress-steps .swal2-progress-step{z-index:20;width:2em;height:2em;border-radius:2em;background:#3085d6;color:#fff;line-height:2em;text-align:center}.swal2-progress-steps .swal2-progress-step.swal2-active-progress-step{background:#3085d6}.swal2-progress-steps .swal2-progress-step.swal2-active-progress-step~.swal2-progress-step{background:#add8e6;color:#fff}.swal2-progress-steps .swal2-progress-step.swal2-active-progress-step~.swal2-progress-step-line{background:#add8e6}.swal2-progress-steps .swal2-progress-step-line{z-index:10;width:2.5em;height:.4em;margin:0 -1px;background:#3085d6}[class^=swal2]{-webkit-tap-highlight-color:transparent}.swal2-show{-webkit-animation:swal2-show .3s;animation:swal2-show .3s}.swal2-show.swal2-noanimation{-webkit-animation:none;animation:none}.swal2-hide{-webkit-animation:swal2-hide .15s forwards;animation:swal2-hide .15s forwards}.swal2-hide.swal2-noanimation{-webkit-animation:none;animation:none}.swal2-rtl .swal2-close{right:auto;left:0}.swal2-animate-success-icon .swal2-success-line-tip{-webkit-animation:swal2-animate-success-line-tip .75s;animation:swal2-animate-success-line-tip .75s}.swal2-animate-success-icon .swal2-success-line-long{-webkit-animation:swal2-animate-success-line-long .75s;animation:swal2-animate-success-line-long .75s}.swal2-animate-success-icon .swal2-success-circular-line-right{-webkit-animation:swal2-rotate-success-circular-line 4.25s ease-in;animation:swal2-rotate-success-circular-line 4.25s ease-in}.swal2-animate-error-icon{-webkit-animation:swal2-animate-error-icon .5s;animation:swal2-animate-error-icon .5s}.swal2-animate-error-icon .swal2-x-mark{-webkit-animation:swal2-animate-error-x-mark .5s;animation:swal2-animate-error-x-mark .5s}@supports (-ms-accelerator:true){.swal2-range input{width:100%!important}.swal2-range output{display:none}}@media all and (-ms-high-contrast:none),(-ms-high-contrast:active){.swal2-range input{width:100%!important}.swal2-range output{display:none}}@-moz-document url-prefix(){.swal2-close:focus{outline:2px solid rgba(50,100,150,.4)}}@-webkit-keyframes swal2-toast-show{0%{transform:translateY(-.625em) rotateZ(2deg)}33%{transform:translateY(0) rotateZ(-2deg)}66%{transform:translateY(.3125em) rotateZ(2deg)}100%{transform:translateY(0) rotateZ(0)}}@keyframes swal2-toast-show{0%{transform:translateY(-.625em) rotateZ(2deg)}33%{transform:translateY(0) rotateZ(-2deg)}66%{transform:translateY(.3125em) rotateZ(2deg)}100%{transform:translateY(0) rotateZ(0)}}@-webkit-keyframes swal2-toast-hide{100%{transform:rotateZ(1deg);opacity:0}}@keyframes swal2-toast-hide{100%{transform:rotateZ(1deg);opacity:0}}@-webkit-keyframes swal2-toast-animate-success-line-tip{0%{top:.5625em;left:.0625em;width:0}54%{top:.125em;left:.125em;width:0}70%{top:.625em;left:-.25em;width:1.625em}84%{top:1.0625em;left:.75em;width:.5em}100%{top:1.125em;left:.1875em;width:.75em}}@keyframes swal2-toast-animate-success-line-tip{0%{top:.5625em;left:.0625em;width:0}54%{top:.125em;left:.125em;width:0}70%{top:.625em;left:-.25em;width:1.625em}84%{top:1.0625em;left:.75em;width:.5em}100%{top:1.125em;left:.1875em;width:.75em}}@-webkit-keyframes swal2-toast-animate-success-line-long{0%{top:1.625em;right:1.375em;width:0}65%{top:1.25em;right:.9375em;width:0}84%{top:.9375em;right:0;width:1.125em}100%{top:.9375em;right:.1875em;width:1.375em}}@keyframes swal2-toast-animate-success-line-long{0%{top:1.625em;right:1.375em;width:0}65%{top:1.25em;right:.9375em;width:0}84%{top:.9375em;right:0;width:1.125em}100%{top:.9375em;right:.1875em;width:1.375em}}@-webkit-keyframes swal2-show{0%{transform:scale(.7)}45%{transform:scale(1.05)}80%{transform:scale(.95)}100%{transform:scale(1)}}@keyframes swal2-show{0%{transform:scale(.7)}45%{transform:scale(1.05)}80%{transform:scale(.95)}100%{transform:scale(1)}}@-webkit-keyframes swal2-hide{0%{transform:scale(1);opacity:1}100%{transform:scale(.5);opacity:0}}@keyframes swal2-hide{0%{transform:scale(1);opacity:1}100%{transform:scale(.5);opacity:0}}@-webkit-keyframes swal2-animate-success-line-tip{0%{top:1.1875em;left:.0625em;width:0}54%{top:1.0625em;left:.125em;width:0}70%{top:2.1875em;left:-.375em;width:3.125em}84%{top:3em;left:1.3125em;width:1.0625em}100%{top:2.8125em;left:.875em;width:1.5625em}}@keyframes swal2-animate-success-line-tip{0%{top:1.1875em;left:.0625em;width:0}54%{top:1.0625em;left:.125em;width:0}70%{top:2.1875em;left:-.375em;width:3.125em}84%{top:3em;left:1.3125em;width:1.0625em}100%{top:2.8125em;left:.875em;width:1.5625em}}@-webkit-keyframes swal2-animate-success-line-long{0%{top:3.375em;right:2.875em;width:0}65%{top:3.375em;right:2.875em;width:0}84%{top:2.1875em;right:0;width:3.4375em}100%{top:2.375em;right:.5em;width:2.9375em}}@keyframes swal2-animate-success-line-long{0%{top:3.375em;right:2.875em;width:0}65%{top:3.375em;right:2.875em;width:0}84%{top:2.1875em;right:0;width:3.4375em}100%{top:2.375em;right:.5em;width:2.9375em}}@-webkit-keyframes swal2-rotate-success-circular-line{0%{transform:rotate(-45deg)}5%{transform:rotate(-45deg)}12%{transform:rotate(-405deg)}100%{transform:rotate(-405deg)}}@keyframes swal2-rotate-success-circular-line{0%{transform:rotate(-45deg)}5%{transform:rotate(-45deg)}12%{transform:rotate(-405deg)}100%{transform:rotate(-405deg)}}@-webkit-keyframes swal2-animate-error-x-mark{0%{margin-top:1.625em;transform:scale(.4);opacity:0}50%{margin-top:1.625em;transform:scale(.4);opacity:0}80%{margin-top:-.375em;transform:scale(1.15)}100%{margin-top:0;transform:scale(1);opacity:1}}@keyframes swal2-animate-error-x-mark{0%{margin-top:1.625em;transform:scale(.4);opacity:0}50%{margin-top:1.625em;transform:scale(.4);opacity:0}80%{margin-top:-.375em;transform:scale(1.15)}100%{margin-top:0;transform:scale(1);opacity:1}}@-webkit-keyframes swal2-animate-error-icon{0%{transform:rotateX(100deg);opacity:0}100%{transform:rotateX(0);opacity:1}}@keyframes swal2-animate-error-icon{0%{transform:rotateX(100deg);opacity:0}100%{transform:rotateX(0);opacity:1}}@-webkit-keyframes swal2-rotate-loading{0%{transform:rotate(0)}100%{transform:rotate(360deg)}}@keyframes swal2-rotate-loading{0%{transform:rotate(0)}100%{transform:rotate(360deg)}}body.swal2-shown:not(.swal2-no-backdrop):not(.swal2-toast-shown){overflow:hidden}body.swal2-height-auto{height:auto!important}body.swal2-no-backdrop .swal2-shown{top:auto;right:auto;bottom:auto;left:auto;max-width:calc(100% - .625em * 2);background-color:transparent}body.swal2-no-backdrop .swal2-shown>.swal2-modal{box-shadow:0 0 10px rgba(0,0,0,.4)}body.swal2-no-backdrop .swal2-shown.swal2-top{top:0;left:50%;transform:translateX(-50%)}body.swal2-no-backdrop .swal2-shown.swal2-top-left,body.swal2-no-backdrop .swal2-shown.swal2-top-start{top:0;left:0}body.swal2-no-backdrop .swal2-shown.swal2-top-end,body.swal2-no-backdrop .swal2-shown.swal2-top-right{top:0;right:0}body.swal2-no-backdrop .swal2-shown.swal2-center{top:50%;left:50%;transform:translate(-50%,-50%)}body.swal2-no-backdrop .swal2-shown.swal2-center-left,body.swal2-no-backdrop .swal2-shown.swal2-center-start{top:50%;left:0;transform:translateY(-50%)}body.swal2-no-backdrop .swal2-shown.swal2-center-end,body.swal2-no-backdrop .swal2-shown.swal2-center-right{top:50%;right:0;transform:translateY(-50%)}body.swal2-no-backdrop .swal2-shown.swal2-bottom{bottom:0;left:50%;transform:translateX(-50%)}body.swal2-no-backdrop .swal2-shown.swal2-bottom-left,body.swal2-no-backdrop .swal2-shown.swal2-bottom-start{bottom:0;left:0}body.swal2-no-backdrop .swal2-shown.swal2-bottom-end,body.swal2-no-backdrop .swal2-shown.swal2-bottom-right{right:0;bottom:0}@media print{body.swal2-shown:not(.swal2-no-backdrop):not(.swal2-toast-shown){overflow-y:scroll!important}body.swal2-shown:not(.swal2-no-backdrop):not(.swal2-toast-shown)>[aria-hidden=true]{display:none}body.swal2-shown:not(.swal2-no-backdrop):not(.swal2-toast-shown) .swal2-container{position:static!important}}body.swal2-toast-shown .swal2-container{background-color:transparent}body.swal2-toast-shown .swal2-container.swal2-shown{background-color:transparent}body.swal2-toast-shown .swal2-container.swal2-top{top:0;right:auto;bottom:auto;left:50%;transform:translateX(-50%)}body.swal2-toast-shown .swal2-container.swal2-top-end,body.swal2-toast-shown .swal2-container.swal2-top-right{top:0;right:0;bottom:auto;left:auto}body.swal2-toast-shown .swal2-container.swal2-top-left,body.swal2-toast-shown .swal2-container.swal2-top-start{top:0;right:auto;bottom:auto;left:0}body.swal2-toast-shown .swal2-container.swal2-center-left,body.swal2-toast-shown .swal2-container.swal2-center-start{top:50%;right:auto;bottom:auto;left:0;transform:translateY(-50%)}body.swal2-toast-shown .swal2-container.swal2-center{top:50%;right:auto;bottom:auto;left:50%;transform:translate(-50%,-50%)}body.swal2-toast-shown .swal2-container.swal2-center-end,body.swal2-toast-shown .swal2-container.swal2-center-right{top:50%;right:0;bottom:auto;left:auto;transform:translateY(-50%)}body.swal2-toast-shown .swal2-container.swal2-bottom-left,body.swal2-toast-shown .swal2-container.swal2-bottom-start{top:auto;right:auto;bottom:0;left:0}body.swal2-toast-shown .swal2-container.swal2-bottom{top:auto;right:auto;bottom:0;left:50%;transform:translateX(-50%)}body.swal2-toast-shown .swal2-container.swal2-bottom-end,body.swal2-toast-shown .swal2-container.swal2-bottom-right{top:auto;right:0;bottom:0;left:auto}body.swal2-toast-column .swal2-toast{flex-direction:column;align-items:stretch}body.swal2-toast-column .swal2-toast .swal2-actions{flex:1;align-self:stretch;height:2.2em;margin-top:.3125em}body.swal2-toast-column .swal2-toast .swal2-loading{justify-content:center}body.swal2-toast-column .swal2-toast .swal2-input{height:2em;margin:.3125em auto;font-size:1em}body.swal2-toast-column .swal2-toast .swal2-validation-message{font-size:1em}");

/***/ }),
/* 36 */
/***/ (function(module, __webpack_exports__, __webpack_require__) {

"use strict";
__webpack_require__.r(__webpack_exports__);
/* harmony import */ var _babel_runtime_helpers_toConsumableArray__WEBPACK_IMPORTED_MODULE_0__ = __webpack_require__(37);
/* harmony import */ var _babel_runtime_helpers_toConsumableArray__WEBPACK_IMPORTED_MODULE_0___default = /*#__PURE__*/__webpack_require__.n(_babel_runtime_helpers_toConsumableArray__WEBPACK_IMPORTED_MODULE_0__);
/* harmony import */ var _babel_runtime_helpers_defineProperty__WEBPACK_IMPORTED_MODULE_1__ = __webpack_require__(25);
/* harmony import */ var _babel_runtime_helpers_defineProperty__WEBPACK_IMPORTED_MODULE_1___default = /*#__PURE__*/__webpack_require__.n(_babel_runtime_helpers_defineProperty__WEBPACK_IMPORTED_MODULE_1__);
/* harmony import */ var _babel_runtime_helpers_classCallCheck__WEBPACK_IMPORTED_MODULE_2__ = __webpack_require__(1);
/* harmony import */ var _babel_runtime_helpers_classCallCheck__WEBPACK_IMPORTED_MODULE_2___default = /*#__PURE__*/__webpack_require__.n(_babel_runtime_helpers_classCallCheck__WEBPACK_IMPORTED_MODULE_2__);
/* harmony import */ var _babel_runtime_helpers_createClass__WEBPACK_IMPORTED_MODULE_3__ = __webpack_require__(2);
/* harmony import */ var _babel_runtime_helpers_createClass__WEBPACK_IMPORTED_MODULE_3___default = /*#__PURE__*/__webpack_require__.n(_babel_runtime_helpers_createClass__WEBPACK_IMPORTED_MODULE_3__);
/* harmony import */ var _babel_runtime_helpers_assertThisInitialized__WEBPACK_IMPORTED_MODULE_4__ = __webpack_require__(3);
/* harmony import */ var _babel_runtime_helpers_assertThisInitialized__WEBPACK_IMPORTED_MODULE_4___default = /*#__PURE__*/__webpack_require__.n(_babel_runtime_helpers_assertThisInitialized__WEBPACK_IMPORTED_MODULE_4__);
/* harmony import */ var _babel_runtime_helpers_inherits__WEBPACK_IMPORTED_MODULE_5__ = __webpack_require__(4);
/* harmony import */ var _babel_runtime_helpers_inherits__WEBPACK_IMPORTED_MODULE_5___default = /*#__PURE__*/__webpack_require__.n(_babel_runtime_helpers_inherits__WEBPACK_IMPORTED_MODULE_5__);
/* harmony import */ var _babel_runtime_helpers_possibleConstructorReturn__WEBPACK_IMPORTED_MODULE_6__ = __webpack_require__(6);
/* harmony import */ var _babel_runtime_helpers_possibleConstructorReturn__WEBPACK_IMPORTED_MODULE_6___default = /*#__PURE__*/__webpack_require__.n(_babel_runtime_helpers_possibleConstructorReturn__WEBPACK_IMPORTED_MODULE_6__);
/* harmony import */ var _babel_runtime_helpers_getPrototypeOf__WEBPACK_IMPORTED_MODULE_7__ = __webpack_require__(8);
/* harmony import */ var _babel_runtime_helpers_getPrototypeOf__WEBPACK_IMPORTED_MODULE_7___default = /*#__PURE__*/__webpack_require__.n(_babel_runtime_helpers_getPrototypeOf__WEBPACK_IMPORTED_MODULE_7__);
/* harmony import */ var _DirectEntryForm__WEBPACK_IMPORTED_MODULE_8__ = __webpack_require__(41);









function _createForOfIteratorHelper(o, allowArrayLike) { var it = typeof Symbol !== "undefined" && o[Symbol.iterator] || o["@@iterator"]; if (!it) { if (Array.isArray(o) || (it = _unsupportedIterableToArray(o)) || allowArrayLike && o && typeof o.length === "number") { if (it) o = it; var i = 0; var F = function F() {}; return { s: F, n: function n() { if (i >= o.length) return { done: true }; return { done: false, value: o[i++] }; }, e: function e(_e) { throw _e; }, f: F }; } throw new TypeError("Invalid attempt to iterate non-iterable instance.\nIn order to be iterable, non-array objects must have a [Symbol.iterator]() method."); } var normalCompletion = true, didErr = false, err; return { s: function s() { it = it.call(o); }, n: function n() { var step = it.next(); normalCompletion = step.done; return step; }, e: function e(_e2) { didErr = true; err = _e2; }, f: function f() { try { if (!normalCompletion && it["return"] != null) it["return"](); } finally { if (didErr) throw err; } } }; }

function _unsupportedIterableToArray(o, minLen) { if (!o) return; if (typeof o === "string") return _arrayLikeToArray(o, minLen); var n = Object.prototype.toString.call(o).slice(8, -1); if (n === "Object" && o.constructor) n = o.constructor.name; if (n === "Map" || n === "Set") return Array.from(o); if (n === "Arguments" || /^(?:Ui|I)nt(?:8|16|32)(?:Clamped)?Array$/.test(n)) return _arrayLikeToArray(o, minLen); }

function _arrayLikeToArray(arr, len) { if (len == null || len > arr.length) len = arr.length; for (var i = 0, arr2 = new Array(len); i < len; i++) { arr2[i] = arr[i]; } return arr2; }

function _createSuper(Derived) { var hasNativeReflectConstruct = _isNativeReflectConstruct(); return function _createSuperInternal() { var Super = _babel_runtime_helpers_getPrototypeOf__WEBPACK_IMPORTED_MODULE_7___default()(Derived), result; if (hasNativeReflectConstruct) { var NewTarget = _babel_runtime_helpers_getPrototypeOf__WEBPACK_IMPORTED_MODULE_7___default()(this).constructor; result = Reflect.construct(Super, arguments, NewTarget); } else { result = Super.apply(this, arguments); } return _babel_runtime_helpers_possibleConstructorReturn__WEBPACK_IMPORTED_MODULE_6___default()(this, result); }; }

function _isNativeReflectConstruct() { if (typeof Reflect === "undefined" || !Reflect.construct) return false; if (Reflect.construct.sham) return false; if (typeof Proxy === "function") return true; try { Boolean.prototype.valueOf.call(Reflect.construct(Boolean, [], function () {})); return true; } catch (e) { return false; } }

/**
 * This file contains React component for Direct Data Entry
 *
 * @author Jordan Stirling (StiringApps ltd.)
 * @version 0.0.1
 *
 */

/**
 * Panel component
 * Wraps children in a collapsible bootstrap panel
 */


var DirectEntry = /*#__PURE__*/function (_React$Component) {
  _babel_runtime_helpers_inherits__WEBPACK_IMPORTED_MODULE_5___default()(DirectEntry, _React$Component);

  var _super = _createSuper(DirectEntry);

  function DirectEntry(props) {
    var _this;

    _babel_runtime_helpers_classCallCheck__WEBPACK_IMPORTED_MODULE_2___default()(this, DirectEntry);

    _this = _super.call(this, props);
    var height = window.innerHeight / 3;
    var style = {
      'margin-top': height
    };
    var page = -1;
    var url = window.location;

    if (!window.location.origin) {
      url.origin = url.protocol + '//' + url.hostname + (url.port ? ':' + url.port : '');
    }

    _this.nextPage = _this.nextPage.bind(_babel_runtime_helpers_assertThisInitialized__WEBPACK_IMPORTED_MODULE_4___default()(_this));
    _this.prevPage = _this.prevPage.bind(_babel_runtime_helpers_assertThisInitialized__WEBPACK_IMPORTED_MODULE_4___default()(_this));
    _this.updateAnswer = _this.updateAnswer.bind(_babel_runtime_helpers_assertThisInitialized__WEBPACK_IMPORTED_MODULE_4___default()(_this));
    _this.setupPageValues = _this.setupPageValues.bind(_babel_runtime_helpers_assertThisInitialized__WEBPACK_IMPORTED_MODULE_4___default()(_this));
    _this.submit = _this.submit.bind(_babel_runtime_helpers_assertThisInitialized__WEBPACK_IMPORTED_MODULE_4___default()(_this));
    _this.state = {
      style: style,
      page: page,
      values: {},
      errors: {},
      InstrumentJSON: {},
      completionStats: {
        total: 0,
        completed: 0
      },
      api_url: "".concat(url.origin, "/bobdule/ajax/survey_api.php?key=").concat(props.commentID),
      submitState: 0 // 0 = not submitted, 1 = successfull submit, 2 = already submitted, 3 = error in form submit

    };
    return _this;
  }

  _babel_runtime_helpers_createClass__WEBPACK_IMPORTED_MODULE_3___default()(DirectEntry, [{
    key: "componentDidMount",
    value: function componentDidMount() {
      var _this2 = this;

      $.ajax({
        url: this.state.api_url,
        method: 'GET',
        dataType: 'json',
        success: function (data) {
          var InstrumentJSON = JSON.parse(data.InstrumentJSON);
          var Values = JSON.parse(data.Values);
          var page = -1;

          if (InstrumentJSON.Elements[0].Type === 'ElementGroup' && InstrumentJSON.Elements[0].GroupType === 'Page') {
            // The following Instrument has pages
            page = 0;
          }

          var total = 0;
          var completed = 0; // eslint-disable-next-line guard-for-in

          for (var key in Values) {
            if (Values[key] != null && Values[key] != '') {
              completed++;
            }

            total++;
          }

          this.setState({
            values: Values,
            InstrumentJSON: InstrumentJSON,
            page: page,
            completionStats: {
              total: total,
              completed: completed
            }
          }, this.setupPageValues.bind(this, page));
        }.bind(this)
      }).fail(function (responseData) {
        // TODO display error to user
        console.log(responseData.status);

        if (responseData.status == '403') {
          _this2.setState({
            submitState: 2
          });
        }
      });
    }
  }, {
    key: "setupPageValues",
    value: function setupPageValues(page) {
      if (page >= this.state.InstrumentJSON.Elements.length) {
        // on review page, dont need to set up page values
        return;
      }

      var pageElements = this.state.InstrumentJSON.Elements[page].Elements;
      var pageValues = {};

      for (var i = 0; i < pageElements.length; i++) {
        var name = this.getElementName(pageElements[i]);

        if (name instanceof Array) {
          for (var j = 0; j < name.length; j++) {
            if (name[j] in this.state.values) {
              pageValues[name[j]] = this.state.values[name[j]];
            }
          }
        } else if (name in this.state.values) {
          pageValues[name] = this.state.values[name];
        }
      }

      this.setState({
        pageValues: pageValues
      });
    }
  }, {
    key: "getElementName",
    value: function getElementName(element) {
      var name;

      if (element.Type === 'ElementGroup') {
        name = [];

        for (var i = 0; i < element.Elements.length; i++) {
          name.push(this.getElementName(element.Elements[i]));
        }
      } else {
        name = element.Name;
      }

      return name;
    }
  }, {
    key: "removeHeaderTags",
    value: function removeHeaderTags(str) {
      if (typeof str == 'string') {
        return str.replace(/<h.>/g, '').replace(/<\/h.>/g, '');
      } else {
        return '';
      }
    }
  }, {
    key: "nextPage",
    value: function nextPage() {
      var _this3 = this;

      var page = 0;
      var finalPage = false;

      if (this.state.page != 0) {
        page = this.state.InstrumentJSON.Elements[this.state.page].Subtest;
      }

      var data = {
        'data': this.state.pageValues,
        'page': page
      };
      var that = this;

      if (this.state.page === this.state.InstrumentJSON.Elements.length - 1) {
        data['FinalPage'] = true;
        finalPage = true;
      }

      $.ajax({
        url: this.state.api_url,
        data: JSON.stringify(data),
        type: 'PUT',
        contentType: 'application/json',
        success: function success(result) {
          var page = that.state.page + 1;
          var InstrumentJSON;
          var reviewPage;

          if (finalPage) {
            InstrumentJSON = that.state.InstrumentJSON;
            reviewPage = JSON.parse(result);
          } else {
            InstrumentJSON = JSON.parse(result);
          }

          if (reviewPage != undefined) {
            // eslint-disable-next-line new-cap
            var selects = DirectEntry.FindSelects(InstrumentJSON.Elements.map(function (i) {
              return i.Elements;
            }));

            var _iterator = _createForOfIteratorHelper(reviewPage.questions),
                _step;

            try {
              for (_iterator.s(); !(_step = _iterator.n()).done;) {
                var i = _step.value;
                var options = selects[i.SourceField];

                if (options != undefined) {
                  var value = options[i.response];

                  if (value != undefined) {
                    i.response = value;
                  }
                }

                i.question = _this3.removeHeaderTags(i.question);
              }
            } catch (err) {
              _iterator.e(err);
            } finally {
              _iterator.f();
            }
          }

          that.setState({
            page: page,
            errors: {},
            InstrumentJSON: InstrumentJSON,
            ReviewData: reviewPage
          });
          that.setupPageValues(page);
          window.scrollTo(0, 0);
        }
      }).fail(function (responseData) {
        if (responseData.status === 400) {
          var response = JSON.parse(responseData.responseText);

          _this3.setState({
            errors: response
          });

          swal({
            title: 'Error',
            text: 'Please resolve page errors before continuing'
          }, function (e) {
            $('html, body').animate({
              scrollTop: $($('.questionError')[0]).offset().top - 100
            }, 100);
          });
        }
      });
    }
  }, {
    key: "prevPage",
    value: function prevPage() {
      var page = this.state.page - 1;
      this.setState({
        page: page,
        errors: {}
      });
      this.setupPageValues(page);
      window.scrollTo(0, 0);
    }
  }, {
    key: "updateAnswer",
    value: function updateAnswer(fieldName, value) {
      var data = {};
      data[fieldName] = value;
      $.ajax({
        url: this.state.api_url,
        data: JSON.stringify(data),
        type: 'PATCH',
        contentType: 'application/json'
      });
      this.setState(function (state) {
        var values = state.values;
        var pageValues = state.pageValues;
        var stats = state.completionStats;

        if (values[fieldName] == null || values[fieldName] == '') {
          stats.completed = stats.completed + 1;
        } else if (value == null || value == '') {
          stats.completed = stats.completed - 1;
        }

        values[fieldName] = value;
        pageValues[fieldName] = value;
        return {
          values: values,
          pageValues: pageValues,
          completionStats: stats
        };
      });
    }
  }, {
    key: "submit",
    value: function submit() {
      var _this4 = this;

      var that = this;
      $.ajax({
        url: this.state.api_url,
        type: 'POST',
        contentType: 'application/json',
        success: function success(result) {
          that.props.close();
        }
      }).fail(function (responseData) {
        console.log('FAIL');
        console.log(responseData);

        _this4.setState({
          submitState: 3
        });
      });
    }
  }, {
    key: "render",
    value: function render() {
      if (this.state.submitState === 2) {
        // The form has already been submitted
        return /*#__PURE__*/React.createElement("div", null, "This form has already been completed");
      } else if (this.state.submitState === 1) {
        // The form has just been successfully submitted
        return /*#__PURE__*/React.createElement("div", null, /*#__PURE__*/React.createElement("h3", null, "Thank you for sharing your responses! You can close this page now. If you need to fill another questionnaire, you can click on the link to return to the 'Parent Portal' page (Please remember to refresh the page). You can also return to the 'Parent Portal' page later to complete the remaining questionnaires. Thank you so much!"));
      } else if (!this.state.InstrumentJSON.Elements) {
        // Since the Instrument data is set when the component is
        // mounted we want to display nothing until it has been set
        return /*#__PURE__*/React.createElement("div", null);
      }

      var DirectEntryFormElements;
      var buttons;

      if (this.state.page === this.state.InstrumentJSON.Elements.length) {
        DirectEntryFormElements = /*#__PURE__*/React.createElement(ReviewPage, {
          reviewData: this.state.ReviewData,
          submitState: this.state.submitState
        });
      } else if (this.state.page >= 0) {
        DirectEntryFormElements = /*#__PURE__*/React.createElement(_DirectEntryForm__WEBPACK_IMPORTED_MODULE_8__["default"], {
          elements: this.state.InstrumentJSON.Elements[this.state.page].Elements,
          values: this.state.values,
          updateAnswer: this.updateAnswer,
          errors: this.state.errors
        });
      } else {
        DirectEntryFormElements = /*#__PURE__*/React.createElement(_DirectEntryForm__WEBPACK_IMPORTED_MODULE_8__["default"], {
          elements: this.state.InstrumentJSON.Elements,
          values: this.state.values,
          updateAnswer: this.updateAnswer,
          errors: this.state.errors
        });
      }

      if (this.state.page === this.state.InstrumentJSON.Elements.length) {
        buttons = /*#__PURE__*/React.createElement("div", null, /*#__PURE__*/React.createElement("button", {
          type: "button",
          className: "btn btn-primary btn-lg",
          onClick: this.prevPage
        }, "Prev"), /*#__PURE__*/React.createElement("button", {
          type: "button",
          className: "btn btn-primary btn-lg",
          onClick: this.submit
        }, "Submit"));
      } else if (this.state.page === -1 || this.state.page === 0 && this.state.InstrumentJSON.Elements.length === 1) {
        buttons = /*#__PURE__*/React.createElement("button", {
          type: "button",
          className: "btn btn-primary btn-lg",
          onClick: this.nextPage
        }, "Done");
      } else if (this.state.page === 0) {
        buttons = /*#__PURE__*/React.createElement("button", {
          type: "button",
          className: "btn btn-primary btn-lg",
          onClick: this.nextPage
        }, "Next");
      } else if (this.state.page === this.state.InstrumentJSON.Elements.length - 1) {
        buttons = /*#__PURE__*/React.createElement("div", null, /*#__PURE__*/React.createElement("button", {
          type: "button",
          className: "btn btn-primary btn-lg",
          onClick: this.prevPage
        }, "Prev"), /*#__PURE__*/React.createElement("button", {
          type: "button",
          className: "btn btn-primary btn-lg",
          onClick: this.nextPage
        }, "Done"));
      } else {
        buttons = /*#__PURE__*/React.createElement("div", null, /*#__PURE__*/React.createElement("button", {
          type: "button",
          className: "btn btn-primary btn-lg",
          onClick: this.prevPage
        }, "Prev"), /*#__PURE__*/React.createElement("button", {
          type: "button",
          className: "btn btn-primary btn-lg",
          onClick: this.nextPage
        }, "Next"));
      }

      var style = {
        width: this.state.completionStats.completed / this.state.completionStats.total * 100 + '%'
      };
      return /*#__PURE__*/React.createElement("div", null, /*#__PURE__*/React.createElement("nav", {
        className: "navbar navbar-default navbar-fixed-top"
      }, /*#__PURE__*/React.createElement("span", _babel_runtime_helpers_defineProperty__WEBPACK_IMPORTED_MODULE_1___default()({
        className: "h1"
      }, "className", "navbar-brand"), "LORIS")), /*#__PURE__*/React.createElement("div", {
        id: "page",
        className: "container-fluid"
      }, DirectEntryFormElements, /*#__PURE__*/React.createElement("div", {
        className: "question-container col-xs-12 col-sm-10 col-sm-offset-1"
      }, buttons)), /*#__PURE__*/React.createElement("div", {
        className: "navbar navbar-default navbar-fixed-bottom"
      }, /*#__PURE__*/React.createElement("div", {
        className: "col-xs-5 footer-bar"
      }, this.state.completionStats.completed, " of ", this.state.completionStats.total, " Answered"), /*#__PURE__*/React.createElement("div", {
        className: "col-xs-4 footer-bar"
      }, /*#__PURE__*/React.createElement("div", {
        className: "progress"
      }, /*#__PURE__*/React.createElement("div", {
        className: "progress-bar-info progress-bar-striped",
        role: "progressbar",
        "aria-valuenow": "60",
        "aria-valuemin": "0",
        "aria-valuemax": "100",
        style: style
      }, "\xA0")))));
    }
  }], [{
    key: "FindSelects",
    value: function FindSelects(root) {
      var _ref;

      return (_ref = []).concat.apply(_ref, _babel_runtime_helpers_toConsumableArray__WEBPACK_IMPORTED_MODULE_0___default()(root)).filter(function (i) {
        return i.Type == 'select' || i.Type == 'ElementGroup';
      }).reduce(function (memo, i) {
        if (i.Type == 'select') {
          memo[i.Name] = i.Options.Values;
        } else {
          // eslint-disable-next-line new-cap
          Object.assign(memo, DirectEntry.FindSelects(i.Elements));
        }

        return memo;
      }, {});
    }
  }]);

  return DirectEntry;
}(React.Component);

var ReviewPage = /*#__PURE__*/function (_React$Component2) {
  _babel_runtime_helpers_inherits__WEBPACK_IMPORTED_MODULE_5___default()(ReviewPage, _React$Component2);

  var _super2 = _createSuper(ReviewPage);

  function ReviewPage(props) {
    _babel_runtime_helpers_classCallCheck__WEBPACK_IMPORTED_MODULE_2___default()(this, ReviewPage);

    return _super2.call(this, props);
  }

  _babel_runtime_helpers_createClass__WEBPACK_IMPORTED_MODULE_3___default()(ReviewPage, [{
    key: "render",
    value: function render() {
      var questions = this.props.reviewData.questions.map(function (element) {
        return /*#__PURE__*/React.createElement("tr", {
          className: "reviewPage",
          key: element.question
        }, /*#__PURE__*/React.createElement("td", null, /*#__PURE__*/React.createElement(Markdown, {
          content: element.question
        })), /*#__PURE__*/React.createElement("td", null, element.response));
      });
      var error;

      if (this.props.submitState === 3) {
        error = /*#__PURE__*/React.createElement("h5", {
          className: "has-error"
        }, "This form has an error, please fix errors before submitting");
      }

      return /*#__PURE__*/React.createElement("div", {
        className: "question-container col-xs-12 col-sm-10 col-sm-offset-1"
      }, /*#__PURE__*/React.createElement("h3", null, "Review Your Submission"), error, /*#__PURE__*/React.createElement("table", {
        className: "table table-striped table-bordered"
      }, /*#__PURE__*/React.createElement("tbody", null, questions)));
    }
  }]);

  return ReviewPage;
}(React.Component);

window.DirectEntry = DirectEntry;
/* harmony default export */ __webpack_exports__["default"] = (DirectEntry);

/***/ }),
/* 37 */
/***/ (function(module, exports, __webpack_require__) {

var arrayWithoutHoles = __webpack_require__(38);

var iterableToArray = __webpack_require__(39);

var unsupportedIterableToArray = __webpack_require__(14);

var nonIterableSpread = __webpack_require__(40);

function _toConsumableArray(arr) {
  return arrayWithoutHoles(arr) || iterableToArray(arr) || unsupportedIterableToArray(arr) || nonIterableSpread();
}

module.exports = _toConsumableArray;
module.exports["default"] = module.exports, module.exports.__esModule = true;

/***/ }),
/* 38 */
/***/ (function(module, exports, __webpack_require__) {

var arrayLikeToArray = __webpack_require__(15);

function _arrayWithoutHoles(arr) {
  if (Array.isArray(arr)) return arrayLikeToArray(arr);
}

module.exports = _arrayWithoutHoles;
module.exports["default"] = module.exports, module.exports.__esModule = true;

/***/ }),
/* 39 */
/***/ (function(module, exports) {

function _iterableToArray(iter) {
  if (typeof Symbol !== "undefined" && iter[Symbol.iterator] != null || iter["@@iterator"] != null) return Array.from(iter);
}

module.exports = _iterableToArray;
module.exports["default"] = module.exports, module.exports.__esModule = true;

/***/ }),
/* 40 */
/***/ (function(module, exports) {

function _nonIterableSpread() {
  throw new TypeError("Invalid attempt to spread non-iterable instance.\nIn order to be iterable, non-array objects must have a [Symbol.iterator]() method.");
}

module.exports = _nonIterableSpread;
module.exports["default"] = module.exports, module.exports.__esModule = true;

/***/ }),
/* 41 */
/***/ (function(module, __webpack_exports__, __webpack_require__) {

"use strict";
__webpack_require__.r(__webpack_exports__);
/* harmony import */ var _babel_runtime_helpers_assertThisInitialized__WEBPACK_IMPORTED_MODULE_0__ = __webpack_require__(3);
/* harmony import */ var _babel_runtime_helpers_assertThisInitialized__WEBPACK_IMPORTED_MODULE_0___default = /*#__PURE__*/__webpack_require__.n(_babel_runtime_helpers_assertThisInitialized__WEBPACK_IMPORTED_MODULE_0__);
/* harmony import */ var _babel_runtime_helpers_classCallCheck__WEBPACK_IMPORTED_MODULE_1__ = __webpack_require__(1);
/* harmony import */ var _babel_runtime_helpers_classCallCheck__WEBPACK_IMPORTED_MODULE_1___default = /*#__PURE__*/__webpack_require__.n(_babel_runtime_helpers_classCallCheck__WEBPACK_IMPORTED_MODULE_1__);
/* harmony import */ var _babel_runtime_helpers_createClass__WEBPACK_IMPORTED_MODULE_2__ = __webpack_require__(2);
/* harmony import */ var _babel_runtime_helpers_createClass__WEBPACK_IMPORTED_MODULE_2___default = /*#__PURE__*/__webpack_require__.n(_babel_runtime_helpers_createClass__WEBPACK_IMPORTED_MODULE_2__);
/* harmony import */ var _babel_runtime_helpers_inherits__WEBPACK_IMPORTED_MODULE_3__ = __webpack_require__(4);
/* harmony import */ var _babel_runtime_helpers_inherits__WEBPACK_IMPORTED_MODULE_3___default = /*#__PURE__*/__webpack_require__.n(_babel_runtime_helpers_inherits__WEBPACK_IMPORTED_MODULE_3__);
/* harmony import */ var _babel_runtime_helpers_possibleConstructorReturn__WEBPACK_IMPORTED_MODULE_4__ = __webpack_require__(6);
/* harmony import */ var _babel_runtime_helpers_possibleConstructorReturn__WEBPACK_IMPORTED_MODULE_4___default = /*#__PURE__*/__webpack_require__.n(_babel_runtime_helpers_possibleConstructorReturn__WEBPACK_IMPORTED_MODULE_4__);
/* harmony import */ var _babel_runtime_helpers_getPrototypeOf__WEBPACK_IMPORTED_MODULE_5__ = __webpack_require__(8);
/* harmony import */ var _babel_runtime_helpers_getPrototypeOf__WEBPACK_IMPORTED_MODULE_5___default = /*#__PURE__*/__webpack_require__.n(_babel_runtime_helpers_getPrototypeOf__WEBPACK_IMPORTED_MODULE_5__);
/* harmony import */ var _GroupElement_js__WEBPACK_IMPORTED_MODULE_6__ = __webpack_require__(42);
/* harmony import */ var _Markdown__WEBPACK_IMPORTED_MODULE_7__ = __webpack_require__(43);







function _createSuper(Derived) { var hasNativeReflectConstruct = _isNativeReflectConstruct(); return function _createSuperInternal() { var Super = _babel_runtime_helpers_getPrototypeOf__WEBPACK_IMPORTED_MODULE_5___default()(Derived), result; if (hasNativeReflectConstruct) { var NewTarget = _babel_runtime_helpers_getPrototypeOf__WEBPACK_IMPORTED_MODULE_5___default()(this).constructor; result = Reflect.construct(Super, arguments, NewTarget); } else { result = Super.apply(this, arguments); } return _babel_runtime_helpers_possibleConstructorReturn__WEBPACK_IMPORTED_MODULE_4___default()(this, result); }; }

function _isNativeReflectConstruct() { if (typeof Reflect === "undefined" || !Reflect.construct) return false; if (Reflect.construct.sham) return false; if (typeof Proxy === "function") return true; try { Boolean.prototype.valueOf.call(Reflect.construct(Boolean, [], function () {})); return true; } catch (e) { return false; } }

/**
 * This file contains React form components for Direct Data Entry
 *
 * @author Jordan Stirling (StiringApps ltd.)
 * @version 0.0.1
 *
 */


/**
 *     THIS ELEMENT IS FOR DEVELOPMENT PURPOSES ONLY
 */

var NotImplement = /*#__PURE__*/function (_React$Component) {
  _babel_runtime_helpers_inherits__WEBPACK_IMPORTED_MODULE_3___default()(NotImplement, _React$Component);

  var _super = _createSuper(NotImplement);

  function NotImplement(props) {
    _babel_runtime_helpers_classCallCheck__WEBPACK_IMPORTED_MODULE_1___default()(this, NotImplement);

    return _super.call(this, props);
  }

  _babel_runtime_helpers_createClass__WEBPACK_IMPORTED_MODULE_2___default()(NotImplement, [{
    key: "render",
    value: function render() {
      return /*#__PURE__*/React.createElement("div", null, this.props.element.Type, " is not yet implemented");
    }
  }]);

  return NotImplement;
}(React.Component);
/* eslint-disable */

/**
 *     THIS ELEMENT IS FOR DEVELOPMENT PURPOSES ONLY
 */


var NotSupported = /*#__PURE__*/function (_React$Component2) {
  _babel_runtime_helpers_inherits__WEBPACK_IMPORTED_MODULE_3___default()(NotSupported, _React$Component2);

  var _super2 = _createSuper(NotSupported);

  function NotSupported(props) {
    _babel_runtime_helpers_classCallCheck__WEBPACK_IMPORTED_MODULE_1___default()(this, NotSupported);

    return _super2.call(this, props);
  }

  _babel_runtime_helpers_createClass__WEBPACK_IMPORTED_MODULE_2___default()(NotSupported, [{
    key: "render",
    value: function render() {
      return /*#__PURE__*/React.createElement("div", null, this.props.element.Type, " is not supported by browser");
    }
  }]);

  return NotSupported;
}(React.Component);
/* eslint-enable */


var DirectEntryFormElement = /*#__PURE__*/function (_React$Component3) {
  _babel_runtime_helpers_inherits__WEBPACK_IMPORTED_MODULE_3___default()(DirectEntryFormElement, _React$Component3);

  var _super3 = _createSuper(DirectEntryFormElement);

  function DirectEntryFormElement(props) {
    _babel_runtime_helpers_classCallCheck__WEBPACK_IMPORTED_MODULE_1___default()(this, DirectEntryFormElement);

    return _super3.call(this, props);
  }

  _babel_runtime_helpers_createClass__WEBPACK_IMPORTED_MODULE_2___default()(DirectEntryFormElement, [{
    key: "render",
    value: function render() {
      var element;
      var errorMessage;
      var questionClass = 'question-container col-xs-12 col-sm-10 col-sm-offset-1';
      var group;

      switch (this.props.element.Type) {
        case 'select':
          element = /*#__PURE__*/React.createElement(SelectElement, {
            element: this.props.element,
            value: this.props.values[this.props.element.Name],
            updateAnswer: this.props.updateAnswer,
            error: this.props.errors[this.props.element.Name]
          });
          break;

        case 'text':
          element = /*#__PURE__*/React.createElement(TextElement, {
            element: this.props.element,
            value: this.props.values[this.props.element.Name],
            updateAnswer: this.props.updateAnswer,
            error: this.props.errors[this.props.element.Name]
          });
          break;

        case 'date':
          element = /*#__PURE__*/React.createElement(DateElement, {
            element: this.props.element,
            value: this.props.values[this.props.element.Name],
            updateAnswer: this.props.updateAnswer,
            error: this.props.errors[this.props.element.Name]
          });
          break;

        case 'label':
          element = /*#__PURE__*/React.createElement(LabelElement, {
            element: this.props.element
          });
          break;

        case 'header':
          element = /*#__PURE__*/React.createElement(HeaderElement, {
            element: this.props.element
          });
          break;

        case 'ElementGroup':
          group = 'true';
          element = /*#__PURE__*/React.createElement(_GroupElement_js__WEBPACK_IMPORTED_MODULE_6__["default"], {
            element: this.props.element,
            values: this.props.values,
            updateAnswer: this.props.updateAnswer,
            errors: this.props.errors
          });
          break;

        case 'advcheckbox':
          element = /*#__PURE__*/React.createElement(AdvcheckboxElement, {
            element: this.props.element,
            value: this.props.values[this.props.element.Name],
            updateAnswer: this.props.updateAnswer,
            error: this.props.errors[this.props.element.Name]
          });
          break;

        default:
          element = /*#__PURE__*/React.createElement(NotImplement, {
            element: this.props.element
          });
      }

      ;

      if (this.props.errors[this.props.element.Name]) {
        questionClass += ' questionError';
        errorMessage = /*#__PURE__*/React.createElement("h4", {
          className: "col-xs-12 has-error"
        }, "* ", this.props.errors[this.props.element.Name]);
      } // eslint-disable-next-line camelcase


      var element_name = this.props.element.Name;
      var str = element_name.toLowerCase();

      if (group == 'true' && str.includes('score')) {
        questionClass = 'hidden';
      }

      return /*#__PURE__*/React.createElement("div", {
        className: questionClass
      }, element, errorMessage);
    }
  }]);

  return DirectEntryFormElement;
}(React.Component);

var Page = /*#__PURE__*/function (_React$Component4) {
  _babel_runtime_helpers_inherits__WEBPACK_IMPORTED_MODULE_3___default()(Page, _React$Component4);

  var _super4 = _createSuper(Page);

  function Page(props) {
    _babel_runtime_helpers_classCallCheck__WEBPACK_IMPORTED_MODULE_1___default()(this, Page);

    return _super4.call(this, props);
  }

  _babel_runtime_helpers_createClass__WEBPACK_IMPORTED_MODULE_2___default()(Page, [{
    key: "render",
    value: function render() {
      var _this = this;

      var DirectEntryFormElements = this.props.elements.map(function (element) {
        return /*#__PURE__*/React.createElement(DirectEntryFormElement, {
          element: element,
          values: _this.props.values,
          updateAnswer: _this.props.updateAnswer,
          errors: _this.props.errors,
          key: element.Name
        });
      });
      return /*#__PURE__*/React.createElement("div", null, DirectEntryFormElements);
    }
  }]);

  return Page;
}(React.Component);

var SelectElement = /*#__PURE__*/function (_React$Component5) {
  _babel_runtime_helpers_inherits__WEBPACK_IMPORTED_MODULE_3___default()(SelectElement, _React$Component5);

  var _super5 = _createSuper(SelectElement);

  function SelectElement(props) {
    var _this2;

    _babel_runtime_helpers_classCallCheck__WEBPACK_IMPORTED_MODULE_1___default()(this, SelectElement);

    _this2 = _super5.call(this, props);
    _this2.state = {
      value: ''
    };
    return _this2;
  }

  _babel_runtime_helpers_createClass__WEBPACK_IMPORTED_MODULE_2___default()(SelectElement, [{
    key: "onSelect",
    value: function onSelect(value) {
      // this.setState({'value': value});
      if (this.props.value !== value) {
        this.props.updateAnswer(this.props.element.Name, value);
      } else {
        this.props.updateAnswer(this.props.element.Name, null);
      }
    }
  }, {
    key: "render",
    value: function render() {
      var options = [];
      var optionLabel;

      for (var key in this.props.element.Options.Values) {
        if (!Object.prototype.hasOwnProperty.call(this.props.element.Options.Values, key)) {
          continue;
        }

        var checked = /*#__PURE__*/React.createElement("div", {
          style: {
            height: '20px',
            width: '14px'
          }
        });

        if (key === '') {
          continue;
        } else if (key === this.props.value) {
          checked = /*#__PURE__*/React.createElement("i", {
            className: "glyphicon glyphicon-ok"
          });
        }

        optionLabel = String(this.props.element.Options.Values[key]);
        options.push( /*#__PURE__*/React.createElement("div", {
          className: "col-xs-12 col-sm-6 select-option",
          onClick: this.onSelect.bind(this, key),
          key: key
        }, /*#__PURE__*/React.createElement("div", {
          className: "selectBox"
        }, /*#__PURE__*/React.createElement("label", {
          className: "btn btn-default btn-circle"
        }, checked)), /*#__PURE__*/React.createElement("div", {
          className: "selectOption"
        }, /*#__PURE__*/React.createElement(_Markdown__WEBPACK_IMPORTED_MODULE_7__["default"], {
          content: optionLabel
        }))));
      }

      var element = /*#__PURE__*/React.createElement("div", {
        className: "row field_input",
        "data-toggle": "buttons"
      }, options);
      var classInfo = 'col-xs-12 field_question';

      if (this.props.error) {
        classInfo += ' has-error';
      }

      var description = '';

      if (!!this.props.element.Description) {
        description = /*#__PURE__*/React.createElement("h3", {
          className: classInfo
        }, /*#__PURE__*/React.createElement(_Markdown__WEBPACK_IMPORTED_MODULE_7__["default"], {
          content: this.props.element.Description
        }));
      }

      return /*#__PURE__*/React.createElement("div", null, description, element);
    }
  }]);

  return SelectElement;
}(React.Component);

var TextElement = /*#__PURE__*/function (_React$Component6) {
  _babel_runtime_helpers_inherits__WEBPACK_IMPORTED_MODULE_3___default()(TextElement, _React$Component6);

  var _super6 = _createSuper(TextElement);

  function TextElement(props) {
    var _this3;

    _babel_runtime_helpers_classCallCheck__WEBPACK_IMPORTED_MODULE_1___default()(this, TextElement);

    _this3 = _super6.call(this, props);
    _this3.updateText = _this3.updateText.bind(_babel_runtime_helpers_assertThisInitialized__WEBPACK_IMPORTED_MODULE_0___default()(_this3));
    return _this3;
  }

  _babel_runtime_helpers_createClass__WEBPACK_IMPORTED_MODULE_2___default()(TextElement, [{
    key: "updateText",
    value: function updateText(e) {
      this.props.updateAnswer(this.props.element.Name, e.target.value);
    }
  }, {
    key: "render",
    value: function render() {
      var type;
      var value = '';

      if (this.props.value) {
        value = this.props.value;
      }

      if (this.props.element.Options.Type === 'small') {
        type = /*#__PURE__*/React.createElement("input", {
          name: this.props.element.Name,
          type: "text",
          className: "form-control",
          onChange: this.updateText,
          value: value
        });
      } else {
        type = /*#__PURE__*/React.createElement("textarea", {
          name: this.props.element.Name,
          className: "form-control",
          onChange: this.updateText,
          value: value
        });
      }

      var classInfo = 'col-xs-12 col-sm-6 col-sm-offset-3 col-md-4 col-md-offset-4';
      var descClass = 'col-xs-12 field_question';

      if (this.props.error) {
        classInfo += ' has-error';
        descClass += ' has-error';
      }

      var description = '';

      if (!!this.props.element.Description) {
        description = /*#__PURE__*/React.createElement("h3", {
          className: descClass
        }, /*#__PURE__*/React.createElement(_Markdown__WEBPACK_IMPORTED_MODULE_7__["default"], {
          content: this.props.element.Description
        }));
      }

      return /*#__PURE__*/React.createElement("div", null, description, /*#__PURE__*/React.createElement("div", {
        className: classInfo
      }, type));
    }
  }]);

  return TextElement;
}(React.Component);

var DateElement = /*#__PURE__*/function (_React$Component7) {
  _babel_runtime_helpers_inherits__WEBPACK_IMPORTED_MODULE_3___default()(DateElement, _React$Component7);

  var _super7 = _createSuper(DateElement);

  function DateElement(props) {
    var _this4;

    _babel_runtime_helpers_classCallCheck__WEBPACK_IMPORTED_MODULE_1___default()(this, DateElement);

    _this4 = _super7.call(this, props);
    _this4.updateDate = _this4.updateDate.bind(_babel_runtime_helpers_assertThisInitialized__WEBPACK_IMPORTED_MODULE_0___default()(_this4));
    return _this4;
  }

  _babel_runtime_helpers_createClass__WEBPACK_IMPORTED_MODULE_2___default()(DateElement, [{
    key: "updateDate",
    value: function updateDate(e) {
      this.props.updateAnswer(this.props.element.Name, e.target.value);
    }
  }, {
    key: "componentDidMount",
    value: function componentDidMount() {
      var that = this;

      if (!checkInput(this.props.element.Type)) {
        $('#' + this.props.element.Name).datepicker({
          'dateFormat': 'yy-mm-dd',
          'minDate': this.props.element.Options.MinDate,
          'maxDate': this.props.element.Options.MaxDate,
          'changeMonth': true,
          'changeYear': true,
          'yearRange': '-100:+15'
        }).on('change', function (e) {
          that.updateDate(e);
        });
      }
    }
  }, {
    key: "render",
    value: function render() {
      // eslint-disable-next-line no-unused-vars
      var classInfo = 'col-xs-12 field_question';
      var value = '';

      if (this.props.value) {
        value = this.props.value;
      }

      var input = /*#__PURE__*/React.createElement("input", {
        name: this.props.element.Name,
        type: "date",
        className: "form-control",
        min: this.props.element.Options.MinDate,
        max: this.props.element.Options.MaxDate,
        onChange: this.updateDate,
        value: value
      });

      if (!checkInput(this.props.element.Type)) {
        input = /*#__PURE__*/React.createElement("input", {
          name: this.props.element.Name,
          type: "text",
          className: "form-control",
          value: this.props.value,
          id: this.props.element.Name
        });
      }

      if (this.props.error) {
        classInfo += ' has-error';
      }

      var description = '';

      if (!!this.props.element.Description) {
        description = /*#__PURE__*/React.createElement("h3", {
          className: "col-xs-12 field_question"
        }, /*#__PURE__*/React.createElement(_Markdown__WEBPACK_IMPORTED_MODULE_7__["default"], {
          content: this.props.element.Description
        }));
      }

      return /*#__PURE__*/React.createElement("div", null, description, /*#__PURE__*/React.createElement("div", {
        className: "col-xs-12 col-sm-6 col-sm-offset-3 col-md-4 col-md-offset-4"
      }, input));
    }
  }]);

  return DateElement;
}(React.Component);

var LabelElement = /*#__PURE__*/function (_React$Component8) {
  _babel_runtime_helpers_inherits__WEBPACK_IMPORTED_MODULE_3___default()(LabelElement, _React$Component8);

  var _super8 = _createSuper(LabelElement);

  function LabelElement(props) {
    _babel_runtime_helpers_classCallCheck__WEBPACK_IMPORTED_MODULE_1___default()(this, LabelElement);

    return _super8.call(this, props);
  }

  _babel_runtime_helpers_createClass__WEBPACK_IMPORTED_MODULE_2___default()(LabelElement, [{
    key: "render",
    value: function render() {
      var description = '';

      if (!!this.props.element.Description) {
        description = /*#__PURE__*/React.createElement("h3", {
          className: "col-xs-12 field_question"
        }, /*#__PURE__*/React.createElement(_Markdown__WEBPACK_IMPORTED_MODULE_7__["default"], {
          content: this.props.element.Description
        }));
      }

      return /*#__PURE__*/React.createElement("div", null, description);
    }
  }]);

  return LabelElement;
}(React.Component);

var HeaderElement = /*#__PURE__*/function (_React$Component9) {
  _babel_runtime_helpers_inherits__WEBPACK_IMPORTED_MODULE_3___default()(HeaderElement, _React$Component9);

  var _super9 = _createSuper(HeaderElement);

  function HeaderElement(props) {
    _babel_runtime_helpers_classCallCheck__WEBPACK_IMPORTED_MODULE_1___default()(this, HeaderElement);

    return _super9.call(this, props);
  }

  _babel_runtime_helpers_createClass__WEBPACK_IMPORTED_MODULE_2___default()(HeaderElement, [{
    key: "render",
    value: function render() {
      var element; // eslint-disable-next-line camelcase

      var score_header = this.props.element.Description;
      var str = score_header.toLowerCase();

      if (str.includes('score')) {
        element = /*#__PURE__*/React.createElement("h1", null);
      } else {
        element = /*#__PURE__*/React.createElement("h1", null, /*#__PURE__*/React.createElement(_Markdown__WEBPACK_IMPORTED_MODULE_7__["default"], {
          content: this.props.element.Description
        }));
      }

      return /*#__PURE__*/React.createElement("div", null, element);
    }
  }]);

  return HeaderElement;
}(React.Component);

var AdvcheckboxElement = /*#__PURE__*/function (_React$Component10) {
  _babel_runtime_helpers_inherits__WEBPACK_IMPORTED_MODULE_3___default()(AdvcheckboxElement, _React$Component10);

  var _super10 = _createSuper(AdvcheckboxElement);

  function AdvcheckboxElement(props) {
    var _this5;

    _babel_runtime_helpers_classCallCheck__WEBPACK_IMPORTED_MODULE_1___default()(this, AdvcheckboxElement);

    _this5 = _super10.call(this, props);
    _this5.state = {
      value: ''
    };
    return _this5;
  }

  _babel_runtime_helpers_createClass__WEBPACK_IMPORTED_MODULE_2___default()(AdvcheckboxElement, [{
    key: "onSelect",
    value: function onSelect(lNull, value) {
      if (this.props.value !== value) {
        this.props.updateAnswer(this.props.element.Name, value);
      } else {
        this.props.updateAnswer(this.props.element.Name, lNull);
      }
    }
  }, {
    key: "render",
    value: function render() {
      var checkbox = [];
      var value = this.props.value != null ? this.props.value : '';
      var checked = /*#__PURE__*/React.createElement("div", {
        style: {
          height: '20px',
          width: '14px'
        }
      });

      if (this.props.element.States.length == 2) {
        var lNull = this.props.element.States[0];
        var strValue = String(this.props.element.States[1]);

        if (strValue === value) {
          checked = /*#__PURE__*/React.createElement("i", {
            className: "glyphicon glyphicon-ok"
          });
        }

        var rightTxt = null;

        if (this.props.element.RightTxt !== '') {
          rightTxt = /*#__PURE__*/React.createElement("div", {
            className: "h3title rightTxt"
          }, /*#__PURE__*/React.createElement("span", null, this.props.element.RightTxt));
        }

        console.log('HELLO');
        checkbox = /*#__PURE__*/React.createElement("div", {
          className: "col-xs-9 col-sm-6 select-option",
          onClick: this.onSelect.bind(this, lNull, strValue)
        }, /*#__PURE__*/React.createElement("div", {
          className: "selectBox"
        }, /*#__PURE__*/React.createElement("label", {
          className: "btn btn-default btn-box"
        }, checked)), rightTxt);
      }

      var classInfo = 'col-xs-3 col-sm-6 h3title field_question';

      if (this.props.error) {
        classInfo += ' has-error';
      }

      var description = '';

      if (!!this.props.element.Description) {
        console.log('ABC');
        description = /*#__PURE__*/React.createElement("div", {
          className: classInfo
        }, /*#__PURE__*/React.createElement(_Markdown__WEBPACK_IMPORTED_MODULE_7__["default"], {
          content: this.props.element.Description
        }));
      }

      console.log('123');
      return /*#__PURE__*/React.createElement("div", {
        className: "row field_input",
        "data-toggle": "buttons"
      }, description, checkbox);
    }
  }]);

  return AdvcheckboxElement;
}(React.Component);

/* harmony default export */ __webpack_exports__["default"] = (Page);

/***/ }),
/* 42 */
/***/ (function(module, __webpack_exports__, __webpack_require__) {

"use strict";
__webpack_require__.r(__webpack_exports__);
/* harmony import */ var _babel_runtime_helpers_assertThisInitialized__WEBPACK_IMPORTED_MODULE_0__ = __webpack_require__(3);
/* harmony import */ var _babel_runtime_helpers_assertThisInitialized__WEBPACK_IMPORTED_MODULE_0___default = /*#__PURE__*/__webpack_require__.n(_babel_runtime_helpers_assertThisInitialized__WEBPACK_IMPORTED_MODULE_0__);
/* harmony import */ var _babel_runtime_helpers_classCallCheck__WEBPACK_IMPORTED_MODULE_1__ = __webpack_require__(1);
/* harmony import */ var _babel_runtime_helpers_classCallCheck__WEBPACK_IMPORTED_MODULE_1___default = /*#__PURE__*/__webpack_require__.n(_babel_runtime_helpers_classCallCheck__WEBPACK_IMPORTED_MODULE_1__);
/* harmony import */ var _babel_runtime_helpers_createClass__WEBPACK_IMPORTED_MODULE_2__ = __webpack_require__(2);
/* harmony import */ var _babel_runtime_helpers_createClass__WEBPACK_IMPORTED_MODULE_2___default = /*#__PURE__*/__webpack_require__.n(_babel_runtime_helpers_createClass__WEBPACK_IMPORTED_MODULE_2__);
/* harmony import */ var _babel_runtime_helpers_inherits__WEBPACK_IMPORTED_MODULE_3__ = __webpack_require__(4);
/* harmony import */ var _babel_runtime_helpers_inherits__WEBPACK_IMPORTED_MODULE_3___default = /*#__PURE__*/__webpack_require__.n(_babel_runtime_helpers_inherits__WEBPACK_IMPORTED_MODULE_3__);
/* harmony import */ var _babel_runtime_helpers_possibleConstructorReturn__WEBPACK_IMPORTED_MODULE_4__ = __webpack_require__(6);
/* harmony import */ var _babel_runtime_helpers_possibleConstructorReturn__WEBPACK_IMPORTED_MODULE_4___default = /*#__PURE__*/__webpack_require__.n(_babel_runtime_helpers_possibleConstructorReturn__WEBPACK_IMPORTED_MODULE_4__);
/* harmony import */ var _babel_runtime_helpers_getPrototypeOf__WEBPACK_IMPORTED_MODULE_5__ = __webpack_require__(8);
/* harmony import */ var _babel_runtime_helpers_getPrototypeOf__WEBPACK_IMPORTED_MODULE_5___default = /*#__PURE__*/__webpack_require__.n(_babel_runtime_helpers_getPrototypeOf__WEBPACK_IMPORTED_MODULE_5__);







function _createSuper(Derived) { var hasNativeReflectConstruct = _isNativeReflectConstruct(); return function _createSuperInternal() { var Super = _babel_runtime_helpers_getPrototypeOf__WEBPACK_IMPORTED_MODULE_5___default()(Derived), result; if (hasNativeReflectConstruct) { var NewTarget = _babel_runtime_helpers_getPrototypeOf__WEBPACK_IMPORTED_MODULE_5___default()(this).constructor; result = Reflect.construct(Super, arguments, NewTarget); } else { result = Super.apply(this, arguments); } return _babel_runtime_helpers_possibleConstructorReturn__WEBPACK_IMPORTED_MODULE_4___default()(this, result); }; }

function _isNativeReflectConstruct() { if (typeof Reflect === "undefined" || !Reflect.construct) return false; if (Reflect.construct.sham) return false; if (typeof Proxy === "function") return true; try { Boolean.prototype.valueOf.call(Reflect.construct(Boolean, [], function () {})); return true; } catch (e) { return false; } }

var GroupElement = /*#__PURE__*/function (_React$Component) {
  _babel_runtime_helpers_inherits__WEBPACK_IMPORTED_MODULE_3___default()(GroupElement, _React$Component);

  var _super = _createSuper(GroupElement);

  function GroupElement(props) {
    _babel_runtime_helpers_classCallCheck__WEBPACK_IMPORTED_MODULE_1___default()(this, GroupElement);

    return _super.call(this, props);
  }

  _babel_runtime_helpers_createClass__WEBPACK_IMPORTED_MODULE_2___default()(GroupElement, [{
    key: "render",
    value: function render() {
      var element;

      switch (this.props.element.GroupType) {
        case 'Element':
          element = /*#__PURE__*/React.createElement(ElementGroup, {
            element: this.props.element,
            values: this.props.values,
            updateAnswer: this.props.updateAnswer,
            errors: this.props.errors
          });
          break;
      }

      return /*#__PURE__*/React.createElement("div", null, element);
    }
  }]);

  return GroupElement;
}(React.Component);

var ElementGroup = /*#__PURE__*/function (_React$Component2) {
  _babel_runtime_helpers_inherits__WEBPACK_IMPORTED_MODULE_3___default()(ElementGroup, _React$Component2);

  var _super2 = _createSuper(ElementGroup);

  function ElementGroup(props) {
    _babel_runtime_helpers_classCallCheck__WEBPACK_IMPORTED_MODULE_1___default()(this, ElementGroup);

    return _super2.call(this, props);
  }

  _babel_runtime_helpers_createClass__WEBPACK_IMPORTED_MODULE_2___default()(ElementGroup, [{
    key: "render",
    value: function render() {
      var labelClass;
      var elementClass;
      var elements;
      var error;
      var errorMessage;

      switch (this.props.element.Elements.length) {
        case 1:
          labelClass = 'col-xs-12 col-sm-4 field_question';
          elementClass = 'col-xs-12 col-sm-8';
          break;

        case 2:
          labelClass = 'col-xs-12 col-sm-4 field_question';
          elementClass = 'col-xs-12 col-sm-4';
          break;

        case 3:
          labelClass = 'col-xs-12 col-sm-3 field_question';
          elementClass = 'col-xs-12 col-sm-3';
          break;

        case 4:
          labelClass = 'col-xs-12 col-sm-4 field_question';
          elementClass = 'col-xs-12 col-sm-2';
          break;

        case 5:
          labelClass = 'col-xs-12 col-sm-2 field_question';
          elementClass = 'col-xs-12 col-sm-2';
          break;

        case 6:
          labelClass = 'col-xs-12 col-sm-2 field_question';
          elementClass = 'col-xs-10 col-sm-custom';
          break;

        case 7:
          labelClass = 'col-xs-12 col-sm-2 field_question';
          elementClass = 'col-xs-10 col-sm-custom';
          break;

        case 8:
          labelClass = 'col-xs-12 col-sm-2 field_question';
          elementClass = 'col-xs-10 col-sm-custom';
          break;
      }

      if (this.props.errors[this.props.element.Name]) {
        error = true;
        labelClass += ' has-error';
      }

      elements = this.props.element.Elements.map(function (element) {
        if (!error && this.props.errors[element.Name]) {
          error = true;
          errorMessage = this.props.errors[element.Name];
        }

        return /*#__PURE__*/React.createElement(BaseElement, {
          element: element,
          classInfo: elementClass,
          value: this.props.values[element.Name],
          updateAnswer: this.props.updateAnswer,
          error: error,
          errorMessage: errorMessage,
          key: "".concat(element.Name, "_").concat(element.Description)
        });
      }.bind(this));
      var description = '';

      if (!!this.props.element.Description) {
        description = /*#__PURE__*/React.createElement("h3", {
          className: labelClass
        }, /*#__PURE__*/React.createElement(Markdown, {
          content: this.props.element.Description
        }));
      }

      return /*#__PURE__*/React.createElement("div", {
        className: "col-xs-12",
        style: {
          paddingTop: '10px'
        }
      }, description, elements);
    }
  }]);

  return ElementGroup;
}(React.Component);

var GroupDateElement = /*#__PURE__*/function (_React$Component3) {
  _babel_runtime_helpers_inherits__WEBPACK_IMPORTED_MODULE_3___default()(GroupDateElement, _React$Component3);

  var _super3 = _createSuper(GroupDateElement);

  function GroupDateElement(props) {
    var _this;

    _babel_runtime_helpers_classCallCheck__WEBPACK_IMPORTED_MODULE_1___default()(this, GroupDateElement);

    _this = _super3.call(this, props);
    _this.updateValue = _this.updateValue.bind(_babel_runtime_helpers_assertThisInitialized__WEBPACK_IMPORTED_MODULE_0___default()(_this));
    return _this;
  }

  _babel_runtime_helpers_createClass__WEBPACK_IMPORTED_MODULE_2___default()(GroupDateElement, [{
    key: "updateValue",
    value: function updateValue(e) {
      this.props.updateAnswer(this.props.element.Name, e.target.value);
    }
  }, {
    key: "componentDidMount",
    value: function componentDidMount() {
      var that = this;

      if (!checkInput(this.props.element.Type)) {
        $('#' + this.props.element.Name).datepicker({
          'dateFormat': 'yy-mm-dd',
          'minDate': this.props.element.Options.MinDate,
          'maxDate': this.props.element.Options.MaxDate,
          'changeMonth': true,
          'changeYear': true,
          'yearRange': '-100:+15'
        }).on('change', function (e) {
          that.updateValue(e);
        });
      }
    }
  }, {
    key: "render",
    value: function render() {
      var value = '';

      if (this.props.value) {
        value = this.props.value;
      }

      var input = /*#__PURE__*/React.createElement("input", {
        name: this.props.element.Name,
        type: "date",
        className: "form-control",
        min: this.props.element.Options.MinDate,
        max: this.props.element.Options.MaxDate,
        onChange: this.updateValue,
        value: value
      });

      if (!checkInput(this.props.element.Type)) {
        input = /*#__PURE__*/React.createElement("input", {
          name: this.props.element.Name,
          type: "text",
          className: "form-control",
          value: value,
          id: this.props.element.Name
        });
      }

      return /*#__PURE__*/React.createElement("div", null, input);
    }
  }]);

  return GroupDateElement;
}(React.Component);

var GroupTimeElement = /*#__PURE__*/function (_React$Component4) {
  _babel_runtime_helpers_inherits__WEBPACK_IMPORTED_MODULE_3___default()(GroupTimeElement, _React$Component4);

  var _super4 = _createSuper(GroupTimeElement);

  function GroupTimeElement(props) {
    var _this2;

    _babel_runtime_helpers_classCallCheck__WEBPACK_IMPORTED_MODULE_1___default()(this, GroupTimeElement);

    _this2 = _super4.call(this, props);

    if (!checkInput(_this2.props.element.Type)) {
      var hour = '';
      var min = '';

      if (_this2.props.value) {
        var val = _this2.props.value.split(':');

        hour = val[0];
        min = val[1];
      }

      _this2.state = {
        'hour': hour,
        'min': min
      };
    }

    _this2.updateValue = _this2.updateValue.bind(_babel_runtime_helpers_assertThisInitialized__WEBPACK_IMPORTED_MODULE_0___default()(_this2));
    return _this2;
  }

  _babel_runtime_helpers_createClass__WEBPACK_IMPORTED_MODULE_2___default()(GroupTimeElement, [{
    key: "updateValue",
    value: function updateValue(e) {
      if (checkInput(this.props.element.Type)) {
        var val = e.target.value != '' ? e.target.value : null;
        this.props.updateAnswer(this.props.element.Name, val);
      }
    }
  }, {
    key: "updateTime",
    value: function updateTime(unit, e) {
      var val;

      if (unit == 'hour') {
        if (e.target.value == '') {
          val = null;
        } else if (this.state.min != '') {
          val = e.target.value + ':' + this.state.min + ':00';
        }

        this.props.updateAnswer(this.props.element.Name, val);
        this.setState({
          'hour': e.target.value
        });
      } else if (unit == 'min') {
        if (e.target.value == '') {
          val = null;
        } else if (this.state.hour != '') {
          val = this.state.hour + ':' + e.target.value + ':00';
        }

        this.props.updateAnswer(this.props.element.Name, val);
        this.setState({
          'min': e.target.value
        });
      }
    }
  }, {
    key: "render",
    value: function render() {
      var input = /*#__PURE__*/React.createElement("input", {
        type: "time",
        name: this.props.element.Name,
        className: "form-control",
        onChange: this.updateValue,
        value: this.props.value
      });

      if (!checkInput(this.props.element.Type)) {
        var hourOptions = [];
        var minOptions = [];
        var val;
        var i;
        hourOptions.push( /*#__PURE__*/React.createElement("option", {
          value: ""
        }));
        minOptions.push( /*#__PURE__*/React.createElement("option", {
          value: ""
        }));

        for (i = 0; i < 24; i++) {
          if (i < 10) {
            val = '0' + i;
          } else {
            val = String(i);
          }

          hourOptions.push( /*#__PURE__*/React.createElement("option", {
            value: val
          }, val));
        }

        for (i = 0; i < 60; i++) {
          if (i < 10) {
            val = '0' + i;
          } else {
            val = String(i);
          }

          minOptions.push( /*#__PURE__*/React.createElement("option", {
            value: val
          }, val));
        }

        input = /*#__PURE__*/React.createElement("div", {
          className: "row"
        }, /*#__PURE__*/React.createElement("div", {
          className: "col-xs-4"
        }, /*#__PURE__*/React.createElement("select", {
          className: "form-control",
          onChange: this.updateTime.bind(this, 'hour'),
          value: this.state.hour
        }, hourOptions)), /*#__PURE__*/React.createElement("div", {
          className: "col-xs-4"
        }, /*#__PURE__*/React.createElement("select", {
          className: "form-control",
          onChange: this.updateTime.bind(this, 'min'),
          value: this.state.min
        }, minOptions)));
      }

      return /*#__PURE__*/React.createElement("div", null, input);
    }
  }]);

  return GroupTimeElement;
}(React.Component);

var BaseElement = /*#__PURE__*/function (_React$Component5) {
  _babel_runtime_helpers_inherits__WEBPACK_IMPORTED_MODULE_3___default()(BaseElement, _React$Component5);

  var _super5 = _createSuper(BaseElement);

  function BaseElement(props) {
    var _this3;

    _babel_runtime_helpers_classCallCheck__WEBPACK_IMPORTED_MODULE_1___default()(this, BaseElement);

    _this3 = _super5.call(this, props);
    _this3.updateValue = _this3.updateValue.bind(_babel_runtime_helpers_assertThisInitialized__WEBPACK_IMPORTED_MODULE_0___default()(_this3));
    return _this3;
  }

  _babel_runtime_helpers_createClass__WEBPACK_IMPORTED_MODULE_2___default()(BaseElement, [{
    key: "updateValue",
    value: function updateValue(e) {
      this.props.updateAnswer(this.props.element.Name, e.target.value);
    }
  }, {
    key: "onSelect",
    value: function onSelect(lNull, value) {
      if (this.props.value !== value) {
        this.props.updateAnswer(this.props.element.Name, value);
      } else {
        this.props.updateAnswer(this.props.element.Name, lNull);
      }
    }
  }, {
    key: "render",
    value: function render() {
      var element;
      var classInfo = this.props.classInfo; // let value;

      var errorMessage;

      if (this.props.error) {
        classInfo += ' has-error';
      }

      if (this.props.errorMessage) {
        classInfo += ' questionError';
        errorMessage = /*#__PURE__*/React.createElement("div", null, this.props.errorMessage);
      }

      var rightTxt = null;

      switch (this.props.element.Type) {
        case 'text':
          value = this.props.value != null ? this.props.value : '';

          if (this.props.element.Options.Type === 'small') {
            element = /*#__PURE__*/React.createElement("input", {
              type: "text",
              name: this.props.element.Name,
              className: "form-control",
              onChange: this.updateValue,
              value: value
            });
          } else {
            element = /*#__PURE__*/React.createElement("textarea", {
              name: this.props.element.Name,
              className: "form-control",
              onChange: this.updateValue,
              value: value
            });
          }

          break;

        case 'select':
          var options = [];
          value = this.props.value != null ? this.props.value : ''; // eslint-disable-next-line guard-for-in

          for (var key in this.props.element.Options.Values) {
            options.push( /*#__PURE__*/React.createElement("option", {
              value: key,
              key: key
            }, this.props.element.Options.Values[key]));
          }

          element = /*#__PURE__*/React.createElement("select", {
            className: "form-control",
            onChange: this.updateValue,
            value: value
          }, options);
          break;

        case 'advcheckbox':
          var value = this.props.value != null ? this.props.value : '';
          var checked = /*#__PURE__*/React.createElement("div", {
            style: {
              height: '20px',
              width: '14px'
            }
          });

          if (this.props.element.States.length == 2) {
            var lNull = this.props.element.States[0];
            var strValue = String(this.props.element.States[1]);

            if (strValue === value) {
              checked = /*#__PURE__*/React.createElement("i", {
                className: "glyphicon glyphicon-ok"
              });
            }

            if (this.props.element.RightTxt !== '') {
              rightTxt = /*#__PURE__*/React.createElement("div", {
                className: "h3title rightTxt"
              }, /*#__PURE__*/React.createElement("span", null, this.props.element.RightTxt));
            }

            element = /*#__PURE__*/React.createElement("div", {
              className: "selectBox",
              onClick: this.onSelect.bind(this, lNull, strValue)
            }, /*#__PURE__*/React.createElement("label", {
              className: "btn btn-default btn-box"
            }, checked));
          } else {
            element = null;
          }

          break;

        case 'label':
          var content = '';

          if (!!this.props.value) {
            content = this.props.value;
          } else if (!!this.props.element.Description) {
            content = this.props.element.Description;
          }

          element = /*#__PURE__*/React.createElement(Markdown, {
            content: content
          });
          break;

        case 'date':
          element = /*#__PURE__*/React.createElement(GroupDateElement, {
            element: this.props.element,
            value: this.props.value,
            updateAnswer: this.props.updateAnswer
          });
          break;

        case 'time':
          value = this.props.value != null ? this.props.value : '';
          element = /*#__PURE__*/React.createElement(GroupTimeElement, {
            element: this.props.element,
            value: this.props.value,
            updateAnswer: this.props.updateAnswer
          });
          break;

        default:
          element = /*#__PURE__*/React.createElement("div", null, this.props.element.Type, " is not yet implemented group");
      }

      return /*#__PURE__*/React.createElement("div", {
        className: classInfo
      }, element, rightTxt, errorMessage);
    }
  }]);

  return BaseElement;
}(React.Component);

/* harmony default export */ __webpack_exports__["default"] = (GroupElement);

/***/ }),
/* 43 */
/***/ (function(module, __webpack_exports__, __webpack_require__) {

"use strict";
__webpack_require__.r(__webpack_exports__);
/* harmony import */ var _babel_runtime_helpers_classCallCheck__WEBPACK_IMPORTED_MODULE_0__ = __webpack_require__(1);
/* harmony import */ var _babel_runtime_helpers_classCallCheck__WEBPACK_IMPORTED_MODULE_0___default = /*#__PURE__*/__webpack_require__.n(_babel_runtime_helpers_classCallCheck__WEBPACK_IMPORTED_MODULE_0__);
/* harmony import */ var _babel_runtime_helpers_createClass__WEBPACK_IMPORTED_MODULE_1__ = __webpack_require__(2);
/* harmony import */ var _babel_runtime_helpers_createClass__WEBPACK_IMPORTED_MODULE_1___default = /*#__PURE__*/__webpack_require__.n(_babel_runtime_helpers_createClass__WEBPACK_IMPORTED_MODULE_1__);
/* harmony import */ var _babel_runtime_helpers_inherits__WEBPACK_IMPORTED_MODULE_2__ = __webpack_require__(4);
/* harmony import */ var _babel_runtime_helpers_inherits__WEBPACK_IMPORTED_MODULE_2___default = /*#__PURE__*/__webpack_require__.n(_babel_runtime_helpers_inherits__WEBPACK_IMPORTED_MODULE_2__);
/* harmony import */ var _babel_runtime_helpers_possibleConstructorReturn__WEBPACK_IMPORTED_MODULE_3__ = __webpack_require__(6);
/* harmony import */ var _babel_runtime_helpers_possibleConstructorReturn__WEBPACK_IMPORTED_MODULE_3___default = /*#__PURE__*/__webpack_require__.n(_babel_runtime_helpers_possibleConstructorReturn__WEBPACK_IMPORTED_MODULE_3__);
/* harmony import */ var _babel_runtime_helpers_getPrototypeOf__WEBPACK_IMPORTED_MODULE_4__ = __webpack_require__(8);
/* harmony import */ var _babel_runtime_helpers_getPrototypeOf__WEBPACK_IMPORTED_MODULE_4___default = /*#__PURE__*/__webpack_require__.n(_babel_runtime_helpers_getPrototypeOf__WEBPACK_IMPORTED_MODULE_4__);
/* harmony import */ var react__WEBPACK_IMPORTED_MODULE_5__ = __webpack_require__(9);
/* harmony import */ var react__WEBPACK_IMPORTED_MODULE_5___default = /*#__PURE__*/__webpack_require__.n(react__WEBPACK_IMPORTED_MODULE_5__);
/* harmony import */ var prop_types__WEBPACK_IMPORTED_MODULE_6__ = __webpack_require__(17);
/* harmony import */ var prop_types__WEBPACK_IMPORTED_MODULE_6___default = /*#__PURE__*/__webpack_require__.n(prop_types__WEBPACK_IMPORTED_MODULE_6__);






function _createSuper(Derived) { var hasNativeReflectConstruct = _isNativeReflectConstruct(); return function _createSuperInternal() { var Super = _babel_runtime_helpers_getPrototypeOf__WEBPACK_IMPORTED_MODULE_4___default()(Derived), result; if (hasNativeReflectConstruct) { var NewTarget = _babel_runtime_helpers_getPrototypeOf__WEBPACK_IMPORTED_MODULE_4___default()(this).constructor; result = Reflect.construct(Super, arguments, NewTarget); } else { result = Super.apply(this, arguments); } return _babel_runtime_helpers_possibleConstructorReturn__WEBPACK_IMPORTED_MODULE_3___default()(this, result); }; }

function _isNativeReflectConstruct() { if (typeof Reflect === "undefined" || !Reflect.construct) return false; if (Reflect.construct.sham) return false; if (typeof Proxy === "function") return true; try { Boolean.prototype.valueOf.call(Reflect.construct(Boolean, [], function () {})); return true; } catch (e) { return false; } }

/* exported RMarkdown */

/**
 * This file contains a React component which renders markdown text into HTML.
 * by way of JSX.
 *
 * Only very basic markdown is supported. In particular:
 * 1. Paragraphs can be delineated with an empty line.
 * 2. **text** or __text__ will bold the text. *text* or _text_ will italicize it.
 * 3. Up to six header levels can be supported by starting a paragraph with (up to 6)
 *    # characters.
 * 4. Links can be added with [text](url)
 *
 * This should be enough to write help documents in Markdown, even without the
 * more complicated features that markdown should support.
 *
 * @author Dave MacFarlane
 * @version 0.0.1
 *
 */



var Markdown = /*#__PURE__*/function (_Component) {
  _babel_runtime_helpers_inherits__WEBPACK_IMPORTED_MODULE_2___default()(Markdown, _Component);

  var _super = _createSuper(Markdown);

  function Markdown() {
    _babel_runtime_helpers_classCallCheck__WEBPACK_IMPORTED_MODULE_0___default()(this, Markdown);

    return _super.apply(this, arguments);
  }

  _babel_runtime_helpers_createClass__WEBPACK_IMPORTED_MODULE_1___default()(Markdown, [{
    key: "htmlSpecialCharsDecode",
    value: function htmlSpecialCharsDecode(text) {
      return text.replace(/&amp;/g, '&').replace(/&quot;/g, '"');
    }
  }, {
    key: "render",
    value: function render() {
      // Fix stupid-style newlines to be just \n.
      var fixedNewLines = this.props.content.replace(/\r\n/g, '\n'); // Fix excaped html

      fixedNewLines = this.htmlSpecialCharsDecode(fixedNewLines); // 2 newlines in a row mean it's a paragraph breaker.

      var paragraphs = fixedNewLines.split('\n\n');
      var headersRe = /^(#+)\s+(.+)$/; // Do a non-greedy match on text surrounded by ** or __ separately,
      // because we need to be sure that the end tag is the same as the
      // start and want the callback to reference the same index

      var boldRe1 = /(\*\*)(.+?)(\*\*)/g;
      var boldRe2 = /(__)(.+?)(__)/g;

      function boldCallback(match, start, content, end, offset, val) {
        return '<b>' + content + '</b>';
      }

      var italRe1 = /(\*)(.+?)(\*)/g;
      var italRe2 = /(_)(.+?)(_)/g;

      function italCallback(match, start, content, end, offset, val) {
        return '<i>' + content + '</i>';
      }

      var linkRe = /\[(.+?)\]\((.+?)\)/g;

      function linkCallback(match, text, link, offset, val) {
        return '<a href="' + link + '">' + text + '</a>';
      } // This needs to be declared outside of the loop to keep eslint
      // happy. It's just the callback for the regex.


      var hlevel = 1;

      function headerCallback(match, headerLevel, headerContent, offset, val) {
        hlevel = headerLevel.length;
        return headerContent;
      }

      for (var i = 0; i < paragraphs.length; i++) {
        // For now, assume that there's an empty line between
        // any headers. It's not true of strict markdown, but
        // it's true enough to enforce for the help pages.
        // Technically, a header should also end at the newline,
        // not at the end of its paragraph too.
        if (paragraphs[i][0] === '#') {
          hlevel = 1;
          paragraphs[i] = paragraphs[i].replace(headersRe, headerCallback);

          switch (hlevel) {
            case 6:
              paragraphs[i] = /*#__PURE__*/react__WEBPACK_IMPORTED_MODULE_5___default.a.createElement("h6", {
                key: i + '_help_editor_h6'
              }, paragraphs[i]);
              break;

            case 5:
              paragraphs[i] = /*#__PURE__*/react__WEBPACK_IMPORTED_MODULE_5___default.a.createElement("h5", {
                key: i + '_help_editor_h5'
              }, paragraphs[i]);
              break;

            case 4:
              paragraphs[i] = /*#__PURE__*/react__WEBPACK_IMPORTED_MODULE_5___default.a.createElement("h4", {
                key: i + '_help_editor_h4'
              }, paragraphs[i]);
              break;

            case 3:
              paragraphs[i] = /*#__PURE__*/react__WEBPACK_IMPORTED_MODULE_5___default.a.createElement("h3", {
                key: i + '_help_editor_h3'
              }, paragraphs[i]);
              break;

            case 2:
              paragraphs[i] = /*#__PURE__*/react__WEBPACK_IMPORTED_MODULE_5___default.a.createElement("h2", {
                key: i + '_help_editor_h2'
              }, paragraphs[i]);
              break;

            case 1:
            default:
              paragraphs[i] = /*#__PURE__*/react__WEBPACK_IMPORTED_MODULE_5___default.a.createElement("h1", {
                key: i + '_help_editor_h1'
              }, paragraphs[i]);
          }
        } else {
          var paramd = paragraphs[i]; // Do bold before italics, because otherwise italics will catch
          // the inner * of the bold.

          paramd = paramd.replace(boldRe1, boldCallback);
          paramd = paramd.replace(boldRe2, boldCallback);
          paramd = paramd.replace(italRe1, italCallback);
          paramd = paramd.replace(italRe2, italCallback);
          paramd = paramd.replace(linkRe, linkCallback);
          paragraphs[i] = /*#__PURE__*/react__WEBPACK_IMPORTED_MODULE_5___default.a.createElement("p", {
            key: i + '_help_editor_p',
            dangerouslySetInnerHTML: {
              __html: paramd
            }
          });
        }
      }

      return /*#__PURE__*/react__WEBPACK_IMPORTED_MODULE_5___default.a.createElement("div", null, paragraphs);
    }
  }]);

  return Markdown;
}(react__WEBPACK_IMPORTED_MODULE_5__["Component"]);

Markdown.propTypes = {
  content: prop_types__WEBPACK_IMPORTED_MODULE_6___default.a.string.isRequired
};
var RMarkdown = /*#__PURE__*/react__WEBPACK_IMPORTED_MODULE_5___default.a.createFactory(Markdown);
window.Markdown = Markdown;
window.RMarkdown = RMarkdown;
/* harmony default export */ __webpack_exports__["default"] = (Markdown);

/***/ })
/******/ ]);
//# sourceMappingURL=bobdule.js.map