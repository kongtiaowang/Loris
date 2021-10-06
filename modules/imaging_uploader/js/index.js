window["lorisjs"] = window["lorisjs"] || {}; window["lorisjs"]["imaging_uploader"] = window["lorisjs"]["imaging_uploader"] || {}; window["lorisjs"]["imaging_uploader"]["index"] =
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
/* harmony import */ var _ImagingUploader__WEBPACK_IMPORTED_MODULE_0__ = __webpack_require__(1);
/* global ReactDOM */

/**
 * Render imaging_uploader on page load
 */

$(function () {
  var imagingUploader = React.createElement("div", {
    className: "page-imaging-uploader"
  }, React.createElement(_ImagingUploader__WEBPACK_IMPORTED_MODULE_0__["default"], {
    Module: "imaging_uploader",
    DataURL: loris.BaseURL + '/imaging_uploader/?format=json'
  }));
  ReactDOM.render(imagingUploader, document.getElementById('lorisworkspace'));
});

/***/ }),
/* 1 */
/***/ (function(module, __webpack_exports__, __webpack_require__) {

"use strict";
__webpack_require__.r(__webpack_exports__);
/* harmony import */ var react__WEBPACK_IMPORTED_MODULE_0__ = __webpack_require__(2);
/* harmony import */ var react__WEBPACK_IMPORTED_MODULE_0___default = /*#__PURE__*/__webpack_require__.n(react__WEBPACK_IMPORTED_MODULE_0__);
/* harmony import */ var prop_types__WEBPACK_IMPORTED_MODULE_1__ = __webpack_require__(3);
/* harmony import */ var prop_types__WEBPACK_IMPORTED_MODULE_1___default = /*#__PURE__*/__webpack_require__.n(prop_types__WEBPACK_IMPORTED_MODULE_1__);
/* harmony import */ var FilterForm__WEBPACK_IMPORTED_MODULE_2__ = __webpack_require__(10);
/* harmony import */ var Tabs__WEBPACK_IMPORTED_MODULE_3__ = __webpack_require__(12);
/* harmony import */ var Loader__WEBPACK_IMPORTED_MODULE_4__ = __webpack_require__(13);
/* harmony import */ var _LogPanel__WEBPACK_IMPORTED_MODULE_5__ = __webpack_require__(14);
/* harmony import */ var _UploadForm__WEBPACK_IMPORTED_MODULE_6__ = __webpack_require__(15);
function _typeof(obj) { if (typeof Symbol === "function" && typeof Symbol.iterator === "symbol") { _typeof = function _typeof(obj) { return typeof obj; }; } else { _typeof = function _typeof(obj) { return obj && typeof Symbol === "function" && obj.constructor === Symbol && obj !== Symbol.prototype ? "symbol" : typeof obj; }; } return _typeof(obj); }

function _classCallCheck(instance, Constructor) { if (!(instance instanceof Constructor)) { throw new TypeError("Cannot call a class as a function"); } }

function _defineProperties(target, props) { for (var i = 0; i < props.length; i++) { var descriptor = props[i]; descriptor.enumerable = descriptor.enumerable || false; descriptor.configurable = true; if ("value" in descriptor) descriptor.writable = true; Object.defineProperty(target, descriptor.key, descriptor); } }

function _createClass(Constructor, protoProps, staticProps) { if (protoProps) _defineProperties(Constructor.prototype, protoProps); if (staticProps) _defineProperties(Constructor, staticProps); return Constructor; }

function _possibleConstructorReturn(self, call) { if (call && (_typeof(call) === "object" || typeof call === "function")) { return call; } return _assertThisInitialized(self); }

function _getPrototypeOf(o) { _getPrototypeOf = Object.setPrototypeOf ? Object.getPrototypeOf : function _getPrototypeOf(o) { return o.__proto__ || Object.getPrototypeOf(o); }; return _getPrototypeOf(o); }

function _assertThisInitialized(self) { if (self === void 0) { throw new ReferenceError("this hasn't been initialised - super() hasn't been called"); } return self; }

function _inherits(subClass, superClass) { if (typeof superClass !== "function" && superClass !== null) { throw new TypeError("Super expression must either be null or a function"); } subClass.prototype = Object.create(superClass && superClass.prototype, { constructor: { value: subClass, writable: true, configurable: true } }); if (superClass) _setPrototypeOf(subClass, superClass); }

function _setPrototypeOf(o, p) { _setPrototypeOf = Object.setPrototypeOf || function _setPrototypeOf(o, p) { o.__proto__ = p; return o; }; return _setPrototypeOf(o, p); }









var ImagingUploader =
/*#__PURE__*/
function (_Component) {
  _inherits(ImagingUploader, _Component);

  function ImagingUploader(props) {
    var _this;

    _classCallCheck(this, ImagingUploader);

    _this = _possibleConstructorReturn(this, _getPrototypeOf(ImagingUploader).call(this, props));
    loris.hiddenHeaders = ['PatientName', 'SessionID'];
    _this.state = {
      isLoaded: false,
      filter: {}
    };
    /**
     * Set filter to the element's ref for filtering
     */

    _this.filter = null;

    _this.setFilterRef = function (element) {
      _this.filter = element;
    };
    /**
     * Bind component instance to custom methods
     */


    _this.fetchData = _this.fetchData.bind(_assertThisInitialized(_this));
    _this.updateFilter = _this.updateFilter.bind(_assertThisInitialized(_this));
    _this.resetFilters = _this.resetFilters.bind(_assertThisInitialized(_this));
    _this.formatColumn = _this.formatColumn.bind(_assertThisInitialized(_this));
    return _this;
  }

  _createClass(ImagingUploader, [{
    key: "componentDidMount",
    value: function componentDidMount() {
      this.fetchData();
    }
    /**
     * Retrive data from the provided URL and save it in state
     * Additionaly add hiddenHeaders to global loris vairable
     * for easy access by columnFormatter.
     */

  }, {
    key: "fetchData",
    value: function fetchData() {
      var _this2 = this;

      $.ajax(this.props.DataURL, {
        method: 'GET',
        dataType: 'json',
        success: function success(data) {
          _this2.setState({
            data: data,
            isLoaded: true
          });
        },
        error: function error(_error) {
          console.error(_error);
        }
      });
    }
    /**
     * Set this.state.filter to the input filter object
     *
     * @param {object} filter = the filter object
     */

  }, {
    key: "updateFilter",
    value: function updateFilter(filter) {
      this.setState({
        filter: filter
      });
    } // TODO: deprecate clearing filters via refs in future refactoring.

    /**
     * Reset the filter elements with textInput refs to empty values
     */

  }, {
    key: "resetFilters",
    value: function resetFilters() {
      this.filter.clearFilter();
    }
    /**
     * Modify behaviour of specified column cells in the Data Table component
     *
     * @param {string} column - column name
     * @param {string} cell - cell content
     * @param {array} rowData - array of cell contents for a specific row
     * @param {array} rowHeaders - array of table headers (column names)
     *
     * @return {*} a formatted table cell for a given column
     */

  }, {
    key: "formatColumn",
    value: function formatColumn(column, cell, rowData, rowHeaders) {
      // If a column if set as hidden, don't display it
      if (loris.hiddenHeaders.indexOf(column) > -1) {
        return null;
      } // Create the mapping between rowHeaders and rowData in a row object.


      var row = {};
      rowHeaders.forEach(function (header, index) {
        row[header] = rowData[index];
      }, this); // Default cell style

      var cellStyle = {
        whiteSpace: 'nowrap'
      };

      if (column === 'Progress') {
        if (cell === 'Failure') {
          cellStyle.color = '#fff';
          return react__WEBPACK_IMPORTED_MODULE_0___default.a.createElement("td", {
            className: "label-danger",
            style: cellStyle
          }, cell);
        }

        if (cell === 'In Progress...') {
          cellStyle.color = '#fff';
          return react__WEBPACK_IMPORTED_MODULE_0___default.a.createElement("td", {
            className: "label-warning",
            style: cellStyle
          }, cell);
        }

        if (cell === 'Success') {
          var created = row['Number Of MINC Created'];
          var inserted = row['Number Of MINC Inserted'];
          return react__WEBPACK_IMPORTED_MODULE_0___default.a.createElement("td", {
            style: cellStyle
          }, cell, " (", inserted, " out of ", created, ")");
        } // cell == 'Not started'


        return react__WEBPACK_IMPORTED_MODULE_0___default.a.createElement("td", {
          style: cellStyle
        }, cell);
      }

      if (column === 'Tarchive Info') {
        if (!cell || cell === '0') {
          return react__WEBPACK_IMPORTED_MODULE_0___default.a.createElement("td", null);
        }

        var url = loris.BaseURL + '/dicom_archive/viewDetails/?tarchiveID=' + cell;
        return react__WEBPACK_IMPORTED_MODULE_0___default.a.createElement("td", {
          style: cellStyle
        }, react__WEBPACK_IMPORTED_MODULE_0___default.a.createElement("a", {
          href: url
        }, "View details"));
      }

      if (column === 'Number Of MINC Inserted') {
        if (cell > 0) {
          var _url = loris.BaseURL + '/imaging_browser/viewSession/?sessionID=' + row.SessionID;

          return react__WEBPACK_IMPORTED_MODULE_0___default.a.createElement("td", {
            style: cellStyle
          }, react__WEBPACK_IMPORTED_MODULE_0___default.a.createElement("a", {
            href: _url
          }, cell));
        }
      }

      if (column === 'Number Of MINC Created') {
        var violatedScans;

        if (row['Number Of MINC Created'] - row['Number Of MINC Inserted'] > 0) {
          var numViolatedScans = row['Number Of MINC Created'] - row['Number Of MINC Inserted'];
          var patientName = row.PatientName;
          violatedScans = react__WEBPACK_IMPORTED_MODULE_0___default.a.createElement("a", {
            onClick: this.openViolatedScans.bind(null, patientName)
          }, "(", numViolatedScans, " violated scans)");
        }

        return react__WEBPACK_IMPORTED_MODULE_0___default.a.createElement("td", {
          style: cellStyle
        }, cell, "\xA0", violatedScans);
      }

      return react__WEBPACK_IMPORTED_MODULE_0___default.a.createElement("td", {
        style: cellStyle
      }, cell);
    }
    /**
     * Opens MRI Violations for when there are violated scans
     *
     * @param {string} patientName - Patient name of the form PSCID_DCCID_VisitLabel
     * @param {object} e - event info
     */

  }, {
    key: "openViolatedScans",
    value: function openViolatedScans(patientName, e) {
      loris.loadFilteredMenuClickHandler('mri_violations/', {
        PatientName: patientName
      })(e);
    }
  }, {
    key: "render",
    value: function render() {
      if (!this.state.isLoaded) {
        return react__WEBPACK_IMPORTED_MODULE_0___default.a.createElement(Loader__WEBPACK_IMPORTED_MODULE_4__["default"], null);
      }

      var tabList = [{
        id: 'browse',
        label: 'Browse'
      }, {
        id: 'upload',
        label: 'Upload'
      }];
      return react__WEBPACK_IMPORTED_MODULE_0___default.a.createElement(Tabs__WEBPACK_IMPORTED_MODULE_3__["Tabs"], {
        tabs: tabList,
        defaultTab: "browse",
        updateURL: true
      }, react__WEBPACK_IMPORTED_MODULE_0___default.a.createElement(Tabs__WEBPACK_IMPORTED_MODULE_3__["TabPane"], {
        TabId: tabList[0].id
      }, react__WEBPACK_IMPORTED_MODULE_0___default.a.createElement("div", {
        className: "row"
      }, react__WEBPACK_IMPORTED_MODULE_0___default.a.createElement("div", {
        className: "col-md-5"
      }, react__WEBPACK_IMPORTED_MODULE_0___default.a.createElement(FilterForm__WEBPACK_IMPORTED_MODULE_2__["default"], {
        Module: "imaging_uploader",
        name: "imaging_filter",
        id: "imaging_filter",
        ref: this.setFilterRef,
        onUpdate: this.updateFilter,
        filter: this.state.filter
      }, react__WEBPACK_IMPORTED_MODULE_0___default.a.createElement(TextboxElement, this.state.data.form.candID), react__WEBPACK_IMPORTED_MODULE_0___default.a.createElement(TextboxElement, this.state.data.form.pSCID), react__WEBPACK_IMPORTED_MODULE_0___default.a.createElement(SelectElement, this.state.data.form.visitLabel), react__WEBPACK_IMPORTED_MODULE_0___default.a.createElement(ButtonElement, {
        type: "reset",
        label: "Clear Filters",
        onUserInput: this.resetFilters
      }))), react__WEBPACK_IMPORTED_MODULE_0___default.a.createElement("div", {
        className: "col-md-7"
      }, react__WEBPACK_IMPORTED_MODULE_0___default.a.createElement(_LogPanel__WEBPACK_IMPORTED_MODULE_5__["default"], null))), react__WEBPACK_IMPORTED_MODULE_0___default.a.createElement("div", {
        id: "mri_upload_table"
      }, react__WEBPACK_IMPORTED_MODULE_0___default.a.createElement(StaticDataTable, {
        Data: this.state.data.Data,
        Headers: this.state.data.Headers,
        getFormattedCell: this.formatColumn,
        Filter: this.state.filter,
        hiddenHeaders: this.state.hiddenHeaders
      }))), react__WEBPACK_IMPORTED_MODULE_0___default.a.createElement(Tabs__WEBPACK_IMPORTED_MODULE_3__["TabPane"], {
        TabId: tabList[1].id
      }, react__WEBPACK_IMPORTED_MODULE_0___default.a.createElement(_UploadForm__WEBPACK_IMPORTED_MODULE_6__["default"], {
        form: this.state.data.form,
        mriList: this.state.data.mriList,
        maxUploadSize: this.state.data.maxUploadSize,
        imagingUploaderAutoLaunch: this.state.data.imagingUploaderAutoLaunch
      })));
    }
  }]);

  return ImagingUploader;
}(react__WEBPACK_IMPORTED_MODULE_0__["Component"]);

ImagingUploader.propTypes = {
  DataURL: prop_types__WEBPACK_IMPORTED_MODULE_1___default.a.string.isRequired
};
/* harmony default export */ __webpack_exports__["default"] = (ImagingUploader);

/***/ }),
/* 2 */
/***/ (function(module, exports) {

(function() { module.exports = window["React"]; }());

/***/ }),
/* 3 */
/***/ (function(module, exports, __webpack_require__) {

/**
 * Copyright (c) 2013-present, Facebook, Inc.
 *
 * This source code is licensed under the MIT license found in the
 * LICENSE file in the root directory of this source tree.
 */

if (true) {
  var ReactIs = __webpack_require__(4);

  // By explicitly using `prop-types` you are opting into new development behavior.
  // http://fb.me/prop-types-in-prod
  var throwOnDirectAccess = true;
  module.exports = __webpack_require__(6)(ReactIs.isElement, throwOnDirectAccess);
} else {}


/***/ }),
/* 4 */
/***/ (function(module, exports, __webpack_require__) {

"use strict";


if (false) {} else {
  module.exports = __webpack_require__(5);
}


/***/ }),
/* 5 */
/***/ (function(module, exports, __webpack_require__) {

"use strict";
/** @license React v16.9.0
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

Object.defineProperty(exports, '__esModule', { value: true });

// The Symbol used to tag the ReactElement-like types. If there is no native Symbol
// nor polyfill, then a plain number is used for performance.
var hasSymbol = typeof Symbol === 'function' && Symbol.for;

var REACT_ELEMENT_TYPE = hasSymbol ? Symbol.for('react.element') : 0xeac7;
var REACT_PORTAL_TYPE = hasSymbol ? Symbol.for('react.portal') : 0xeaca;
var REACT_FRAGMENT_TYPE = hasSymbol ? Symbol.for('react.fragment') : 0xeacb;
var REACT_STRICT_MODE_TYPE = hasSymbol ? Symbol.for('react.strict_mode') : 0xeacc;
var REACT_PROFILER_TYPE = hasSymbol ? Symbol.for('react.profiler') : 0xead2;
var REACT_PROVIDER_TYPE = hasSymbol ? Symbol.for('react.provider') : 0xeacd;
var REACT_CONTEXT_TYPE = hasSymbol ? Symbol.for('react.context') : 0xeace;
// TODO: We don't use AsyncMode or ConcurrentMode anymore. They were temporary
// (unstable) APIs that have been removed. Can we remove the symbols?
var REACT_ASYNC_MODE_TYPE = hasSymbol ? Symbol.for('react.async_mode') : 0xeacf;
var REACT_CONCURRENT_MODE_TYPE = hasSymbol ? Symbol.for('react.concurrent_mode') : 0xeacf;
var REACT_FORWARD_REF_TYPE = hasSymbol ? Symbol.for('react.forward_ref') : 0xead0;
var REACT_SUSPENSE_TYPE = hasSymbol ? Symbol.for('react.suspense') : 0xead1;
var REACT_SUSPENSE_LIST_TYPE = hasSymbol ? Symbol.for('react.suspense_list') : 0xead8;
var REACT_MEMO_TYPE = hasSymbol ? Symbol.for('react.memo') : 0xead3;
var REACT_LAZY_TYPE = hasSymbol ? Symbol.for('react.lazy') : 0xead4;
var REACT_FUNDAMENTAL_TYPE = hasSymbol ? Symbol.for('react.fundamental') : 0xead5;
var REACT_RESPONDER_TYPE = hasSymbol ? Symbol.for('react.responder') : 0xead6;

function isValidElementType(type) {
  return typeof type === 'string' || typeof type === 'function' ||
  // Note: its typeof might be other than 'symbol' or 'number' if it's a polyfill.
  type === REACT_FRAGMENT_TYPE || type === REACT_CONCURRENT_MODE_TYPE || type === REACT_PROFILER_TYPE || type === REACT_STRICT_MODE_TYPE || type === REACT_SUSPENSE_TYPE || type === REACT_SUSPENSE_LIST_TYPE || typeof type === 'object' && type !== null && (type.$$typeof === REACT_LAZY_TYPE || type.$$typeof === REACT_MEMO_TYPE || type.$$typeof === REACT_PROVIDER_TYPE || type.$$typeof === REACT_CONTEXT_TYPE || type.$$typeof === REACT_FORWARD_REF_TYPE || type.$$typeof === REACT_FUNDAMENTAL_TYPE || type.$$typeof === REACT_RESPONDER_TYPE);
}

/**
 * Forked from fbjs/warning:
 * https://github.com/facebook/fbjs/blob/e66ba20ad5be433eb54423f2b097d829324d9de6/packages/fbjs/src/__forks__/warning.js
 *
 * Only change is we use console.warn instead of console.error,
 * and do nothing when 'console' is not supported.
 * This really simplifies the code.
 * ---
 * Similar to invariant but only logs a warning if the condition is not met.
 * This can be used to log issues in development environments in critical
 * paths. Removing the logging code for production environments will keep the
 * same logic and follow the same code paths.
 */

var lowPriorityWarning = function () {};

{
  var printWarning = function (format) {
    for (var _len = arguments.length, args = Array(_len > 1 ? _len - 1 : 0), _key = 1; _key < _len; _key++) {
      args[_key - 1] = arguments[_key];
    }

    var argIndex = 0;
    var message = 'Warning: ' + format.replace(/%s/g, function () {
      return args[argIndex++];
    });
    if (typeof console !== 'undefined') {
      console.warn(message);
    }
    try {
      // --- Welcome to debugging React ---
      // This error was thrown as a convenience so that you can use this stack
      // to find the callsite that caused this warning to fire.
      throw new Error(message);
    } catch (x) {}
  };

  lowPriorityWarning = function (condition, format) {
    if (format === undefined) {
      throw new Error('`lowPriorityWarning(condition, format, ...args)` requires a warning ' + 'message argument');
    }
    if (!condition) {
      for (var _len2 = arguments.length, args = Array(_len2 > 2 ? _len2 - 2 : 0), _key2 = 2; _key2 < _len2; _key2++) {
        args[_key2 - 2] = arguments[_key2];
      }

      printWarning.apply(undefined, [format].concat(args));
    }
  };
}

var lowPriorityWarning$1 = lowPriorityWarning;

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
              case REACT_PROVIDER_TYPE:
                return $$typeofType;
              default:
                return $$typeof;
            }
        }
      case REACT_LAZY_TYPE:
      case REACT_MEMO_TYPE:
      case REACT_PORTAL_TYPE:
        return $$typeof;
    }
  }

  return undefined;
}

// AsyncMode is deprecated along with isAsyncMode
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

var hasWarnedAboutDeprecatedIsAsyncMode = false;

// AsyncMode should be deprecated
function isAsyncMode(object) {
  {
    if (!hasWarnedAboutDeprecatedIsAsyncMode) {
      hasWarnedAboutDeprecatedIsAsyncMode = true;
      lowPriorityWarning$1(false, 'The ReactIs.isAsyncMode() alias has been deprecated, ' + 'and will be removed in React 17+. Update your code to use ' + 'ReactIs.isConcurrentMode() instead. It has the exact same API.');
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

exports.typeOf = typeOf;
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
exports.isValidElementType = isValidElementType;
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
  })();
}


/***/ }),
/* 6 */
/***/ (function(module, exports, __webpack_require__) {

"use strict";
/**
 * Copyright (c) 2013-present, Facebook, Inc.
 *
 * This source code is licensed under the MIT license found in the
 * LICENSE file in the root directory of this source tree.
 */



var ReactIs = __webpack_require__(4);
var assign = __webpack_require__(7);

var ReactPropTypesSecret = __webpack_require__(8);
var checkPropTypes = __webpack_require__(9);

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
/* 7 */
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
/* 8 */
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
/* 9 */
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
  var ReactPropTypesSecret = __webpack_require__(8);
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
/* 10 */
/***/ (function(module, __webpack_exports__, __webpack_require__) {

"use strict";
__webpack_require__.r(__webpack_exports__);
/* harmony import */ var react__WEBPACK_IMPORTED_MODULE_0__ = __webpack_require__(2);
/* harmony import */ var react__WEBPACK_IMPORTED_MODULE_0___default = /*#__PURE__*/__webpack_require__.n(react__WEBPACK_IMPORTED_MODULE_0__);
/* harmony import */ var prop_types__WEBPACK_IMPORTED_MODULE_1__ = __webpack_require__(3);
/* harmony import */ var prop_types__WEBPACK_IMPORTED_MODULE_1___default = /*#__PURE__*/__webpack_require__.n(prop_types__WEBPACK_IMPORTED_MODULE_1__);
/* harmony import */ var Panel__WEBPACK_IMPORTED_MODULE_2__ = __webpack_require__(11);
function _typeof(obj) { if (typeof Symbol === "function" && typeof Symbol.iterator === "symbol") { _typeof = function _typeof(obj) { return typeof obj; }; } else { _typeof = function _typeof(obj) { return obj && typeof Symbol === "function" && obj.constructor === Symbol && obj !== Symbol.prototype ? "symbol" : typeof obj; }; } return _typeof(obj); }

function _classCallCheck(instance, Constructor) { if (!(instance instanceof Constructor)) { throw new TypeError("Cannot call a class as a function"); } }

function _defineProperties(target, props) { for (var i = 0; i < props.length; i++) { var descriptor = props[i]; descriptor.enumerable = descriptor.enumerable || false; descriptor.configurable = true; if ("value" in descriptor) descriptor.writable = true; Object.defineProperty(target, descriptor.key, descriptor); } }

function _createClass(Constructor, protoProps, staticProps) { if (protoProps) _defineProperties(Constructor.prototype, protoProps); if (staticProps) _defineProperties(Constructor, staticProps); return Constructor; }

function _possibleConstructorReturn(self, call) { if (call && (_typeof(call) === "object" || typeof call === "function")) { return call; } return _assertThisInitialized(self); }

function _getPrototypeOf(o) { _getPrototypeOf = Object.setPrototypeOf ? Object.getPrototypeOf : function _getPrototypeOf(o) { return o.__proto__ || Object.getPrototypeOf(o); }; return _getPrototypeOf(o); }

function _assertThisInitialized(self) { if (self === void 0) { throw new ReferenceError("this hasn't been initialised - super() hasn't been called"); } return self; }

function _inherits(subClass, superClass) { if (typeof superClass !== "function" && superClass !== null) { throw new TypeError("Super expression must either be null or a function"); } subClass.prototype = Object.create(superClass && superClass.prototype, { constructor: { value: subClass, writable: true, configurable: true } }); if (superClass) _setPrototypeOf(subClass, superClass); }

function _setPrototypeOf(o, p) { _setPrototypeOf = Object.setPrototypeOf || function _setPrototypeOf(o, p) { o.__proto__ = p; return o; }; return _setPrototypeOf(o, p); }

/**
 * This file contains React component for FilterForm
 *
 * @author Loris Team
 * @version 1.1.0
 *
 */



/**
 * FilterForm component.
 * A wrapper for form elements inside a selection filter.
 *
 * Adds necessary filter callbacks to all children and passes them to FormElement
 * for proper rendering.
 *
 * Keeps track of filter object and sends it to parent on every update.
 *
 * //HACK/NOTE: Loris has special behaviour for `candID` attribute in the query string,
 * making it impossible to use it for selection filters. This components renames
 * all `candID` fields to `candidateID` automatically before appending them to URL.
 *
 */

var FilterForm =
/*#__PURE__*/
function (_Component) {
  _inherits(FilterForm, _Component);

  function FilterForm(props) {
    var _this;

    _classCallCheck(this, FilterForm);

    _this = _possibleConstructorReturn(this, _getPrototypeOf(FilterForm).call(this, props)); // Bind component instance to custom methods

    _this.clearFilter = _this.clearFilter.bind(_assertThisInitialized(_this));
    _this.getFormChildren = _this.getFormChildren.bind(_assertThisInitialized(_this));
    _this.setFilter = _this.setFilter.bind(_assertThisInitialized(_this));
    _this.onElementUpdate = _this.onElementUpdate.bind(_assertThisInitialized(_this)); // Keeps track of querystring values
    // Saved as class variable instead of keeping in state

    _this.queryString = QueryString.get();
    return _this;
  }

  _createClass(FilterForm, [{
    key: "componentDidMount",
    value: function componentDidMount() {
      var filter = {};
      var queryString = this.queryString; // Initiaze filter using querystring value

      Object.keys(queryString).forEach(function (key) {
        var filterKey = key === 'candidateID' ? 'candID' : key;
        filter[filterKey] = {
          value: queryString[key],
          exactMatch: false
        };
      }); // Update parent component

      this.props.onUpdate(filter);
    }
    /**
     * Clear the filter object, querystring and input fields
     */

  }, {
    key: "clearFilter",
    value: function clearFilter() {
      this.queryString = QueryString.clear(this.props.Module);
      this.props.onUpdate({});
    }
    /**
     * Iterates through FilterForm children, sets necessary callback functions
     * and initializes filterTable
     *
     * @return {Array} formChildren - array of children with necessary props
     */

  }, {
    key: "getFormChildren",
    value: function getFormChildren() {
      var formChildren = [];
      react__WEBPACK_IMPORTED_MODULE_0___default.a.Children.forEach(this.props.children, function (child, key) {
        // If child is a React component (i.e not a simple DOM element)
        if (react__WEBPACK_IMPORTED_MODULE_0___default.a.isValidElement(child) && typeof child.type === 'function' && child.props.onUserInput) {
          var callbackFunc = child.props.onUserInput;
          var callbackName = callbackFunc.name;
          var elementName = child.type.displayName;
          var queryFieldName = child.props.name === 'candID' ? 'candidateID' : child.props.name;
          var filterValue = this.queryString[queryFieldName]; // If callback function was not set, set it to onElementUpdate() for form
          // elements and to clearFilter() for <ButtonElement type='reset'/>.

          if (callbackName === 'onUserInput') {
            if (elementName === 'ButtonElement' && child.props.type === 'reset') {
              callbackFunc = this.clearFilter;
            } else {
              callbackFunc = this.onElementUpdate.bind(null, elementName);
            }
          } // Pass onUserInput and value props to all children


          formChildren.push(react__WEBPACK_IMPORTED_MODULE_0___default.a.cloneElement(child, {
            onUserInput: callbackFunc,
            value: filterValue ? filterValue : '',
            key: key
          })); // Initialize filter for StaticDataTable

          this.setFilter(elementName, child.props.name, filterValue);
        } else {
          formChildren.push(react__WEBPACK_IMPORTED_MODULE_0___default.a.cloneElement(child, {
            key: key
          }));
        }
      }.bind(this));
      return formChildren;
    }
    /**
     * Appends entry to filter object or deletes it if value is
     * empty.
     *
     * Sets exactMatch to true for all SelectElements (i.e dropdowns)
     * in order to force StaticDataTable to do exact comparaison
     *
     * @param {string} type - form element type (i.e component name)
     * @param {string} key - the name of the form element
     * @param {string} value - the value of the form element
     *
     * @return {{}} filter - filterData
     */

  }, {
    key: "setFilter",
    value: function setFilter(type, key, value) {
      var filter = {};

      if (this.props.filter) {
        filter = JSON.parse(JSON.stringify(this.props.filter));
      }

      if (key) {
        filter[key] = {};

        if (value) {
          // all defined/non-null values must have some length, else empty string
          filter[key].value = Object.keys(value).length > 0 ? value : '';
        } else {
          // null and undefined handled here
          filter[key].value = '';
        }

        filter[key].exactMatch = type === 'SelectElement' || type === 'select';
      }

      if (filter && key && value === '') {
        delete filter[key];
      }

      return filter;
    }
    /**
     * Sets filter object and querystring to reflect values of input fields
     *
     * @param {string} type - form element type (i.e component name)
     * @param {string} fieldName - the name of the form element
     * @param {string} fieldValue - the value of the form element
     */

  }, {
    key: "onElementUpdate",
    value: function onElementUpdate(type, fieldName, fieldValue) {
      // Make sure key is of string type and value is of string or object type
      // before sending them to querystring
      if (typeof fieldName !== 'string' || typeof fieldValue !== 'string' && _typeof(fieldValue) !== 'object') {
        return;
      } // Update query string


      var queryFieldName = fieldName === 'candID' ? 'candidateID' : fieldName;
      this.queryString = QueryString.set(this.queryString, queryFieldName, fieldValue); // Update filter and get new filter object

      var filter = this.setFilter(type, fieldName, fieldValue);
      this.props.onUpdate(filter);
    }
  }, {
    key: "render",
    value: function render() {
      // Get formatted children
      var formChildren = this.getFormChildren();
      var formElements = this.props.formElements;

      if (formElements) {
        Object.keys(formElements).forEach(function (fieldName) {
          var queryFieldName = fieldName === 'candID' ? 'candidateID' : fieldName;
          formElements[fieldName].onUserInput = this.onElementUpdate.bind(null, formElements[fieldName].type);
          formElements[fieldName].value = this.queryString[queryFieldName];
        }.bind(this));
      }

      return react__WEBPACK_IMPORTED_MODULE_0___default.a.createElement(Panel__WEBPACK_IMPORTED_MODULE_2__["default"], {
        id: this.props.id,
        height: this.props.height,
        title: this.props.title
      }, react__WEBPACK_IMPORTED_MODULE_0___default.a.createElement(FormElement, this.props, formChildren));
    }
  }]);

  return FilterForm;
}(react__WEBPACK_IMPORTED_MODULE_0__["Component"]);

FilterForm.defaultProps = {
  id: 'selection-filter',
  height: '100%',
  title: 'Selection Filter',
  onUpdate: function onUpdate() {
    console.warn('onUpdate() callback is not set!');
  }
};
FilterForm.propTypes = {
  Module: prop_types__WEBPACK_IMPORTED_MODULE_1___default.a.string.isRequired,
  filter: prop_types__WEBPACK_IMPORTED_MODULE_1___default.a.object.isRequired,
  id: prop_types__WEBPACK_IMPORTED_MODULE_1___default.a.string,
  height: prop_types__WEBPACK_IMPORTED_MODULE_1___default.a.string,
  title: prop_types__WEBPACK_IMPORTED_MODULE_1___default.a.string,
  onUpdate: prop_types__WEBPACK_IMPORTED_MODULE_1___default.a.func
};
/* harmony default export */ __webpack_exports__["default"] = (FilterForm);

/***/ }),
/* 11 */
/***/ (function(module, __webpack_exports__, __webpack_require__) {

"use strict";
__webpack_require__.r(__webpack_exports__);
/* harmony import */ var react__WEBPACK_IMPORTED_MODULE_0__ = __webpack_require__(2);
/* harmony import */ var react__WEBPACK_IMPORTED_MODULE_0___default = /*#__PURE__*/__webpack_require__.n(react__WEBPACK_IMPORTED_MODULE_0__);
/* harmony import */ var prop_types__WEBPACK_IMPORTED_MODULE_1__ = __webpack_require__(3);
/* harmony import */ var prop_types__WEBPACK_IMPORTED_MODULE_1___default = /*#__PURE__*/__webpack_require__.n(prop_types__WEBPACK_IMPORTED_MODULE_1__);
function _typeof(obj) { if (typeof Symbol === "function" && typeof Symbol.iterator === "symbol") { _typeof = function _typeof(obj) { return typeof obj; }; } else { _typeof = function _typeof(obj) { return obj && typeof Symbol === "function" && obj.constructor === Symbol && obj !== Symbol.prototype ? "symbol" : typeof obj; }; } return _typeof(obj); }

function ownKeys(object, enumerableOnly) { var keys = Object.keys(object); if (Object.getOwnPropertySymbols) { var symbols = Object.getOwnPropertySymbols(object); if (enumerableOnly) symbols = symbols.filter(function (sym) { return Object.getOwnPropertyDescriptor(object, sym).enumerable; }); keys.push.apply(keys, symbols); } return keys; }

function _objectSpread(target) { for (var i = 1; i < arguments.length; i++) { var source = arguments[i] != null ? arguments[i] : {}; if (i % 2) { ownKeys(source, true).forEach(function (key) { _defineProperty(target, key, source[key]); }); } else if (Object.getOwnPropertyDescriptors) { Object.defineProperties(target, Object.getOwnPropertyDescriptors(source)); } else { ownKeys(source).forEach(function (key) { Object.defineProperty(target, key, Object.getOwnPropertyDescriptor(source, key)); }); } } return target; }

function _defineProperty(obj, key, value) { if (key in obj) { Object.defineProperty(obj, key, { value: value, enumerable: true, configurable: true, writable: true }); } else { obj[key] = value; } return obj; }

function _classCallCheck(instance, Constructor) { if (!(instance instanceof Constructor)) { throw new TypeError("Cannot call a class as a function"); } }

function _defineProperties(target, props) { for (var i = 0; i < props.length; i++) { var descriptor = props[i]; descriptor.enumerable = descriptor.enumerable || false; descriptor.configurable = true; if ("value" in descriptor) descriptor.writable = true; Object.defineProperty(target, descriptor.key, descriptor); } }

function _createClass(Constructor, protoProps, staticProps) { if (protoProps) _defineProperties(Constructor.prototype, protoProps); if (staticProps) _defineProperties(Constructor, staticProps); return Constructor; }

function _possibleConstructorReturn(self, call) { if (call && (_typeof(call) === "object" || typeof call === "function")) { return call; } return _assertThisInitialized(self); }

function _getPrototypeOf(o) { _getPrototypeOf = Object.setPrototypeOf ? Object.getPrototypeOf : function _getPrototypeOf(o) { return o.__proto__ || Object.getPrototypeOf(o); }; return _getPrototypeOf(o); }

function _assertThisInitialized(self) { if (self === void 0) { throw new ReferenceError("this hasn't been initialised - super() hasn't been called"); } return self; }

function _inherits(subClass, superClass) { if (typeof superClass !== "function" && superClass !== null) { throw new TypeError("Super expression must either be null or a function"); } subClass.prototype = Object.create(superClass && superClass.prototype, { constructor: { value: subClass, writable: true, configurable: true } }); if (superClass) _setPrototypeOf(subClass, superClass); }

function _setPrototypeOf(o, p) { _setPrototypeOf = Object.setPrototypeOf || function _setPrototypeOf(o, p) { o.__proto__ = p; return o; }; return _setPrototypeOf(o, p); }

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

var Panel =
/*#__PURE__*/
function (_Component) {
  _inherits(Panel, _Component);

  /**
   * Construct the React component
   *
   * @param {array} props - The React props
   */
  function Panel(props) {
    var _this;

    _classCallCheck(this, Panel);

    _this = _possibleConstructorReturn(this, _getPrototypeOf(Panel).call(this, props));
    _this.state = {
      collapsed: _this.props.initCollapsed
    }; // Initialize panel class based on collapsed status

    _this.panelClass = _this.props.initCollapsed ? 'panel-collapse collapse' : 'panel-collapse collapse in';
    _this.toggleCollapsed = _this.toggleCollapsed.bind(_assertThisInitialized(_this));
    return _this;
  }
  /**
   * Toggle whether this Panel is displayed as collapsed
   */


  _createClass(Panel, [{
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

      var panelHeading = this.props.title ? react__WEBPACK_IMPORTED_MODULE_0___default.a.createElement("div", {
        className: "panel-heading",
        onClick: this.toggleCollapsed,
        "data-toggle": "collapse",
        "data-target": '#' + this.props.id,
        style: {
          cursor: 'pointer',
          height: '3em'
        }
      }, this.props.title, react__WEBPACK_IMPORTED_MODULE_0___default.a.createElement("span", {
        className: glyphClass
      })) : '';
      return react__WEBPACK_IMPORTED_MODULE_0___default.a.createElement("div", {
        className: "panel panel-primary",
        style: {
          height: this.props.panelSize
        }
      }, panelHeading, react__WEBPACK_IMPORTED_MODULE_0___default.a.createElement("div", {
        id: this.props.id,
        className: this.panelClass,
        role: "tabpanel",
        style: {
          height: 'calc(100% - 3em)'
        }
      }, react__WEBPACK_IMPORTED_MODULE_0___default.a.createElement("div", {
        className: "panel-body",
        style: _objectSpread({}, this.props.style, {
          height: this.props.height
        })
      }, this.props.children)));
    }
  }]);

  return Panel;
}(react__WEBPACK_IMPORTED_MODULE_0__["Component"]);

Panel.propTypes = {
  id: prop_types__WEBPACK_IMPORTED_MODULE_1___default.a.string,
  height: prop_types__WEBPACK_IMPORTED_MODULE_1___default.a.string,
  title: prop_types__WEBPACK_IMPORTED_MODULE_1___default.a.string
};
Panel.defaultProps = {
  initCollapsed: false,
  id: 'default-panel',
  height: '100%'
};
/* harmony default export */ __webpack_exports__["default"] = (Panel);

/***/ }),
/* 12 */
/***/ (function(module, __webpack_exports__, __webpack_require__) {

"use strict";
__webpack_require__.r(__webpack_exports__);
/* harmony export (binding) */ __webpack_require__.d(__webpack_exports__, "Tabs", function() { return Tabs; });
/* harmony export (binding) */ __webpack_require__.d(__webpack_exports__, "VerticalTabs", function() { return VerticalTabs; });
/* harmony export (binding) */ __webpack_require__.d(__webpack_exports__, "TabPane", function() { return TabPane; });
/* harmony import */ var react__WEBPACK_IMPORTED_MODULE_0__ = __webpack_require__(2);
/* harmony import */ var react__WEBPACK_IMPORTED_MODULE_0___default = /*#__PURE__*/__webpack_require__.n(react__WEBPACK_IMPORTED_MODULE_0__);
/* harmony import */ var prop_types__WEBPACK_IMPORTED_MODULE_1__ = __webpack_require__(3);
/* harmony import */ var prop_types__WEBPACK_IMPORTED_MODULE_1___default = /*#__PURE__*/__webpack_require__.n(prop_types__WEBPACK_IMPORTED_MODULE_1__);
function _typeof(obj) { if (typeof Symbol === "function" && typeof Symbol.iterator === "symbol") { _typeof = function _typeof(obj) { return typeof obj; }; } else { _typeof = function _typeof(obj) { return obj && typeof Symbol === "function" && obj.constructor === Symbol && obj !== Symbol.prototype ? "symbol" : typeof obj; }; } return _typeof(obj); }

function _classCallCheck(instance, Constructor) { if (!(instance instanceof Constructor)) { throw new TypeError("Cannot call a class as a function"); } }

function _defineProperties(target, props) { for (var i = 0; i < props.length; i++) { var descriptor = props[i]; descriptor.enumerable = descriptor.enumerable || false; descriptor.configurable = true; if ("value" in descriptor) descriptor.writable = true; Object.defineProperty(target, descriptor.key, descriptor); } }

function _createClass(Constructor, protoProps, staticProps) { if (protoProps) _defineProperties(Constructor.prototype, protoProps); if (staticProps) _defineProperties(Constructor, staticProps); return Constructor; }

function _possibleConstructorReturn(self, call) { if (call && (_typeof(call) === "object" || typeof call === "function")) { return call; } return _assertThisInitialized(self); }

function _getPrototypeOf(o) { _getPrototypeOf = Object.setPrototypeOf ? Object.getPrototypeOf : function _getPrototypeOf(o) { return o.__proto__ || Object.getPrototypeOf(o); }; return _getPrototypeOf(o); }

function _assertThisInitialized(self) { if (self === void 0) { throw new ReferenceError("this hasn't been initialised - super() hasn't been called"); } return self; }

function _inherits(subClass, superClass) { if (typeof superClass !== "function" && superClass !== null) { throw new TypeError("Super expression must either be null or a function"); } subClass.prototype = Object.create(superClass && superClass.prototype, { constructor: { value: subClass, writable: true, configurable: true } }); if (superClass) _setPrototypeOf(subClass, superClass); }

function _setPrototypeOf(o, p) { _setPrototypeOf = Object.setPrototypeOf || function _setPrototypeOf(o, p) { o.__proto__ = p; return o; }; return _setPrototypeOf(o, p); }

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

var Tabs =
/*#__PURE__*/
function (_Component) {
  _inherits(Tabs, _Component);

  /**
   * Construct a Tabs react component
   *
   * @param {array} props - The React props
   */
  function Tabs(props) {
    var _this;

    _classCallCheck(this, Tabs);

    _this = _possibleConstructorReturn(this, _getPrototypeOf(Tabs).call(this, props));
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
    _this.handleClick = _this.handleClick.bind(_assertThisInitialized(_this));
    _this.getTabs = _this.getTabs.bind(_assertThisInitialized(_this));
    _this.getTabPanes = _this.getTabPanes.bind(_assertThisInitialized(_this));
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


  _createClass(Tabs, [{
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
        return react__WEBPACK_IMPORTED_MODULE_0___default.a.createElement("li", {
          role: "presentation",
          className: tabClass,
          key: tab.id
        }, react__WEBPACK_IMPORTED_MODULE_0___default.a.createElement("a", {
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
      var tabPanes = react__WEBPACK_IMPORTED_MODULE_0___default.a.Children.map(this.props.children, function (child, key) {
        if (child) {
          return react__WEBPACK_IMPORTED_MODULE_0___default.a.cloneElement(child, {
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
      return react__WEBPACK_IMPORTED_MODULE_0___default.a.createElement("div", null, react__WEBPACK_IMPORTED_MODULE_0___default.a.createElement("ul", {
        className: "nav nav-tabs",
        role: "tablist",
        style: tabStyle
      }, tabs), react__WEBPACK_IMPORTED_MODULE_0___default.a.createElement("div", {
        className: "tab-content"
      }, tabPanes));
    }
  }]);

  return Tabs;
}(react__WEBPACK_IMPORTED_MODULE_0__["Component"]);

Tabs.propTypes = {
  tabs: prop_types__WEBPACK_IMPORTED_MODULE_1___default.a.array.isRequired,
  defaultTab: prop_types__WEBPACK_IMPORTED_MODULE_1___default.a.string,
  updateURL: prop_types__WEBPACK_IMPORTED_MODULE_1___default.a.bool
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

var VerticalTabs =
/*#__PURE__*/
function (_Component2) {
  _inherits(VerticalTabs, _Component2);

  /**
   * Construct the Component
   *
   * @param {array} props - array of React props
   */
  function VerticalTabs(props) {
    var _this2;

    _classCallCheck(this, VerticalTabs);

    _this2 = _possibleConstructorReturn(this, _getPrototypeOf(VerticalTabs).call(this, props));
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
    _this2.handleClick = _this2.handleClick.bind(_assertThisInitialized(_this2));
    _this2.getTabs = _this2.getTabs.bind(_assertThisInitialized(_this2));
    _this2.getTabPanes = _this2.getTabPanes.bind(_assertThisInitialized(_this2));
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


  _createClass(VerticalTabs, [{
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
        return react__WEBPACK_IMPORTED_MODULE_0___default.a.createElement("li", {
          role: "presentation",
          className: tabClass,
          key: tab.id
        }, react__WEBPACK_IMPORTED_MODULE_0___default.a.createElement("a", {
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
      var tabPanes = react__WEBPACK_IMPORTED_MODULE_0___default.a.Children.map(this.props.children, function (child, key) {
        if (child) {
          return react__WEBPACK_IMPORTED_MODULE_0___default.a.cloneElement(child, {
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
      return react__WEBPACK_IMPORTED_MODULE_0___default.a.createElement("div", null, react__WEBPACK_IMPORTED_MODULE_0___default.a.createElement("div", {
        className: "tabbable col-md-3 col-sm-3"
      }, react__WEBPACK_IMPORTED_MODULE_0___default.a.createElement("ul", {
        className: "nav nav-pills nav-stacked",
        role: "tablist",
        style: tabStyle
      }, tabs)), react__WEBPACK_IMPORTED_MODULE_0___default.a.createElement("div", {
        className: "tab-content col-md-9 col-sm-9"
      }, tabPanes));
    }
  }]);

  return VerticalTabs;
}(react__WEBPACK_IMPORTED_MODULE_0__["Component"]);

VerticalTabs.propTypes = {
  tabs: prop_types__WEBPACK_IMPORTED_MODULE_1___default.a.array.isRequired,
  defaultTab: prop_types__WEBPACK_IMPORTED_MODULE_1___default.a.string,
  updateURL: prop_types__WEBPACK_IMPORTED_MODULE_1___default.a.bool
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

var TabPane =
/*#__PURE__*/
function (_Component3) {
  _inherits(TabPane, _Component3);

  function TabPane() {
    _classCallCheck(this, TabPane);

    return _possibleConstructorReturn(this, _getPrototypeOf(TabPane).apply(this, arguments));
  }

  _createClass(TabPane, [{
    key: "render",

    /**
     * React lifecycle method
     *
     * @return {object}
     */
    value: function render() {
      var classList = 'tab-pane';
      var title;

      if (this.props.TabId === this.props.activeTab) {
        classList += ' active';
      }

      if (this.props.Title) {
        title = react__WEBPACK_IMPORTED_MODULE_0___default.a.createElement("h1", null, this.props.Title);
      }

      return react__WEBPACK_IMPORTED_MODULE_0___default.a.createElement("div", {
        role: "tabpanel",
        className: classList,
        id: this.props.TabId
      }, title, this.props.children);
    }
  }]);

  return TabPane;
}(react__WEBPACK_IMPORTED_MODULE_0__["Component"]);

TabPane.propTypes = {
  TabId: prop_types__WEBPACK_IMPORTED_MODULE_1___default.a.string.isRequired,
  Title: prop_types__WEBPACK_IMPORTED_MODULE_1___default.a.string,
  activeTab: prop_types__WEBPACK_IMPORTED_MODULE_1___default.a.string
};


/***/ }),
/* 13 */
/***/ (function(module, __webpack_exports__, __webpack_require__) {

"use strict";
__webpack_require__.r(__webpack_exports__);
/* harmony import */ var prop_types__WEBPACK_IMPORTED_MODULE_0__ = __webpack_require__(3);
/* harmony import */ var prop_types__WEBPACK_IMPORTED_MODULE_0___default = /*#__PURE__*/__webpack_require__.n(prop_types__WEBPACK_IMPORTED_MODULE_0__);
/**
 * This file contains the React component for Loader
 *
 * @author Henri Rabalais
 * @version 1.0.0
 *
 */

/**
 * Loader is a React component which shows a spinner wheel while
 * something is loading.
 *
 * @param {array} props - The React props
 *
 * @return {DOMObject} - Loader React component
 */

function Loader(props) {
  return React.createElement("div", {
    className: "loader",
    style: {
      width: parseInt(props.size),
      height: parseInt(props.size)
    }
  });
}

Loader.propTypes = {
  size: prop_types__WEBPACK_IMPORTED_MODULE_0___default.a.string
};
Loader.defaultProps = {
  size: '120'
};
/* harmony default export */ __webpack_exports__["default"] = (Loader);

/***/ }),
/* 14 */
/***/ (function(module, __webpack_exports__, __webpack_require__) {

"use strict";
__webpack_require__.r(__webpack_exports__);
/* harmony import */ var react__WEBPACK_IMPORTED_MODULE_0__ = __webpack_require__(2);
/* harmony import */ var react__WEBPACK_IMPORTED_MODULE_0___default = /*#__PURE__*/__webpack_require__.n(react__WEBPACK_IMPORTED_MODULE_0__);
/* harmony import */ var Panel__WEBPACK_IMPORTED_MODULE_1__ = __webpack_require__(11);
function _typeof(obj) { if (typeof Symbol === "function" && typeof Symbol.iterator === "symbol") { _typeof = function _typeof(obj) { return typeof obj; }; } else { _typeof = function _typeof(obj) { return obj && typeof Symbol === "function" && obj.constructor === Symbol && obj !== Symbol.prototype ? "symbol" : typeof obj; }; } return _typeof(obj); }

function _classCallCheck(instance, Constructor) { if (!(instance instanceof Constructor)) { throw new TypeError("Cannot call a class as a function"); } }

function _defineProperties(target, props) { for (var i = 0; i < props.length; i++) { var descriptor = props[i]; descriptor.enumerable = descriptor.enumerable || false; descriptor.configurable = true; if ("value" in descriptor) descriptor.writable = true; Object.defineProperty(target, descriptor.key, descriptor); } }

function _createClass(Constructor, protoProps, staticProps) { if (protoProps) _defineProperties(Constructor.prototype, protoProps); if (staticProps) _defineProperties(Constructor, staticProps); return Constructor; }

function _possibleConstructorReturn(self, call) { if (call && (_typeof(call) === "object" || typeof call === "function")) { return call; } return _assertThisInitialized(self); }

function _getPrototypeOf(o) { _getPrototypeOf = Object.setPrototypeOf ? Object.getPrototypeOf : function _getPrototypeOf(o) { return o.__proto__ || Object.getPrototypeOf(o); }; return _getPrototypeOf(o); }

function _assertThisInitialized(self) { if (self === void 0) { throw new ReferenceError("this hasn't been initialised - super() hasn't been called"); } return self; }

function _inherits(subClass, superClass) { if (typeof superClass !== "function" && superClass !== null) { throw new TypeError("Super expression must either be null or a function"); } subClass.prototype = Object.create(superClass && superClass.prototype, { constructor: { value: subClass, writable: true, configurable: true } }); if (superClass) _setPrototypeOf(subClass, superClass); }

function _setPrototypeOf(o, p) { _setPrototypeOf = Object.setPrototypeOf || function _setPrototypeOf(o, p) { o.__proto__ = p; return o; }; return _setPrototypeOf(o, p); }

/* global UploadProgress */


/**
 * Log Panel Component
 *
 * Panel component that displays logs for a selected MRI upload whether it is
 * in progress or already completed or failed.
 *
 * @author Alex Ilea
 * @version 1.0.0
 * @since 2017/04/01
 *
 */

var LogPanel =
/*#__PURE__*/
function (_Component) {
  _inherits(LogPanel, _Component);

  function LogPanel(props) {
    var _this;

    _classCallCheck(this, LogPanel);

    _this = _possibleConstructorReturn(this, _getPrototypeOf(LogPanel).call(this, props));
    _this.state = {
      logText: '<select a row in the table below to view the upload logs>',
      logType: 'summary'
    };
    _this.initHelper = _this.initHelper.bind(_assertThisInitialized(_this));
    _this.onLogTypeChange = _this.onLogTypeChange.bind(_assertThisInitialized(_this));
    _this.setServerPolling = _this.setServerPolling.bind(_assertThisInitialized(_this));
    _this.monitorProgress = _this.monitorProgress.bind(_assertThisInitialized(_this));
    return _this;
  }

  _createClass(LogPanel, [{
    key: "componentDidMount",
    value: function componentDidMount() {
      this.initHelper();
    }
  }, {
    key: "initHelper",
    value: function initHelper() {
      var uploadProgress = new UploadProgress();
      this.uploadProgress = uploadProgress;
      $('#mri_upload_table').on('click', 'tbody tr', function (event) {
        // Stop server polling if any was taking place
        if (uploadProgress.getUploadRow() !== null) {
          $(uploadProgress.getUploadRow()).css('background-color', 'white');
          this.setServerPolling(false);
        } // If user clicked on the same row, it is interpreted as a de-selection:
        // deselect row and set log text to 'nothing selected'


        if (event.currentTarget === uploadProgress.getUploadRow()) {
          uploadProgress.setUploadRow(null);
          uploadProgress.setProgressFromServer(null);
          this.setState({
            logText: '<select a row in the table below to view the upload logs>'
          });
          return;
        }

        uploadProgress.setUploadRow(event.currentTarget);
        $(event.currentTarget).css('background-color', '#EFEFFB');
        this.monitorProgress(this.state.logType);
      }.bind(this));
    }
    /**
     * Monitors the progress of an MRI pipeline run on the server by repeatedly
     * issuing POST requests for this information at regular intervals.
     * As soon as the server indicates that the pipeline has finished running, polling
     * will end.
     *
     * @param {string} logType - summary or details
     */

  }, {
    key: "monitorProgress",
    value: function monitorProgress(logType) {
      var summary = logType === 'summary';
      var uploadProgress = this.uploadProgress;
      var uploadId = uploadProgress.getUploadId(); // If no row was selected

      if (!uploadId) {
        return;
      }

      $.post(loris.BaseURL + '/imaging_uploader/ajax/getUploadSummary.php', {
        uploadId: uploadId,
        summary: summary
      }, function (data) {
        uploadProgress.setProgressFromServer(data);
        this.setState({
          logText: uploadProgress.getProgressText()
        }); // If the pipeline is still running, start polling
        // If the pipeline is not running, end the polling (if any was started)

        this.setServerPolling(uploadProgress.getPipelineStatus() === UploadProgress.PIPELINE_STATUS_RUNNING);
      }.bind(this)); // post call
    }
    /**
     * Starts/stops polling on the server.
     * @param {bool} poll - pool boolean
     */

  }, {
    key: "setServerPolling",
    value: function setServerPolling(poll) {
      var _this2 = this;

      var uploadProgress = this.uploadProgress;

      if (poll) {
        // START POLLING
        // If there were no POST requests being issued, start issuing some.
        if (!this.setServerPolling.getSummaryInterval) {
          this.setServerPolling.getSummaryInterval = setInterval(this.monitorProgress, 5000);
        } // If there were no updates to the string of dots, start updating


        if (!this.setServerPolling.dotUpdateInterval) {
          this.setServerPolling.dotUpdateInterval = setInterval(function () {
            uploadProgress.updateDots();

            _this2.setState({
              logText: uploadProgress.getProgressText()
            });
          }, 3000);
        } // If there were no updates to the animated chars, start updating


        if (!this.setServerPolling.animatedCharInterval) {
          this.setServerPolling.animatedCharInterval = setInterval(function () {
            uploadProgress.updateAnimatedCharIndex();

            _this2.setState({
              logText: uploadProgress.getProgressText()
            });
          }, 250);
        }
      } else {
        // STOP POLLING
        // Stop issuing POST requests (if any polling was taking place)
        if (this.setServerPolling.getSummaryInterval) {
          clearInterval(this.setServerPolling.getSummaryInterval);
          this.setServerPolling.getSummaryInterval = null;
        } // Stop updating the series of dots string (if such an update was going on)


        if (this.setServerPolling.dotUpdateInterval) {
          clearInterval(this.setServerPolling.dotUpdateInterval);
          this.setServerPolling.dotUpdateInterval = null;
        } // Stop updating the animated char (if such an update was going on)


        if (this.setServerPolling.animatedCharInterval) {
          clearInterval(this.setServerPolling.animatedCharInterval);
          this.setServerPolling.animatedCharInterval = null;
        }
      }
    }
  }, {
    key: "onLogTypeChange",
    value: function onLogTypeChange(name, value) {
      // Update log box
      this.monitorProgress(value);
      this.setState({
        logType: value
      });
    }
  }, {
    key: "render",
    value: function render() {
      var logTypes = {
        summary: 'Summary',
        detailed: 'Detailed'
      };
      return react__WEBPACK_IMPORTED_MODULE_0___default.a.createElement(Panel__WEBPACK_IMPORTED_MODULE_1__["default"], {
        id: "log_panel",
        title: "Log Viewer"
      }, react__WEBPACK_IMPORTED_MODULE_0___default.a.createElement(FormElement, {
        name: "log_form"
      }, react__WEBPACK_IMPORTED_MODULE_0___default.a.createElement(SelectElement, {
        name: "LogType",
        label: "Logs to display",
        options: logTypes,
        onUserInput: this.onLogTypeChange,
        value: this.state.logType,
        emptyOption: false
      }), react__WEBPACK_IMPORTED_MODULE_0___default.a.createElement(TextareaElement, {
        name: "UploadLogs",
        disabled: true,
        id: "mri_upload_logs",
        value: this.state.logText,
        rows: 6
      })));
    }
  }]);

  return LogPanel;
}(react__WEBPACK_IMPORTED_MODULE_0__["Component"]);

LogPanel.propTypes = {};
LogPanel.defaultProps = {};
/* harmony default export */ __webpack_exports__["default"] = (LogPanel);

/***/ }),
/* 15 */
/***/ (function(module, __webpack_exports__, __webpack_require__) {

"use strict";
__webpack_require__.r(__webpack_exports__);
/* harmony import */ var ProgressBar__WEBPACK_IMPORTED_MODULE_0__ = __webpack_require__(16);
/* harmony import */ var react__WEBPACK_IMPORTED_MODULE_1__ = __webpack_require__(2);
/* harmony import */ var react__WEBPACK_IMPORTED_MODULE_1___default = /*#__PURE__*/__webpack_require__.n(react__WEBPACK_IMPORTED_MODULE_1__);
function _typeof(obj) { if (typeof Symbol === "function" && typeof Symbol.iterator === "symbol") { _typeof = function _typeof(obj) { return typeof obj; }; } else { _typeof = function _typeof(obj) { return obj && typeof Symbol === "function" && obj.constructor === Symbol && obj !== Symbol.prototype ? "symbol" : typeof obj; }; } return _typeof(obj); }

function _classCallCheck(instance, Constructor) { if (!(instance instanceof Constructor)) { throw new TypeError("Cannot call a class as a function"); } }

function _defineProperties(target, props) { for (var i = 0; i < props.length; i++) { var descriptor = props[i]; descriptor.enumerable = descriptor.enumerable || false; descriptor.configurable = true; if ("value" in descriptor) descriptor.writable = true; Object.defineProperty(target, descriptor.key, descriptor); } }

function _createClass(Constructor, protoProps, staticProps) { if (protoProps) _defineProperties(Constructor.prototype, protoProps); if (staticProps) _defineProperties(Constructor, staticProps); return Constructor; }

function _possibleConstructorReturn(self, call) { if (call && (_typeof(call) === "object" || typeof call === "function")) { return call; } return _assertThisInitialized(self); }

function _getPrototypeOf(o) { _getPrototypeOf = Object.setPrototypeOf ? Object.getPrototypeOf : function _getPrototypeOf(o) { return o.__proto__ || Object.getPrototypeOf(o); }; return _getPrototypeOf(o); }

function _assertThisInitialized(self) { if (self === void 0) { throw new ReferenceError("this hasn't been initialised - super() hasn't been called"); } return self; }

function _inherits(subClass, superClass) { if (typeof superClass !== "function" && superClass !== null) { throw new TypeError("Super expression must either be null or a function"); } subClass.prototype = Object.create(superClass && superClass.prototype, { constructor: { value: subClass, writable: true, configurable: true } }); if (superClass) _setPrototypeOf(subClass, superClass); }

function _setPrototypeOf(o, p) { _setPrototypeOf = Object.setPrototypeOf || function _setPrototypeOf(o, p) { o.__proto__ = p; return o; }; return _setPrototypeOf(o, p); }



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

var UploadForm =
/*#__PURE__*/
function (_Component) {
  _inherits(UploadForm, _Component);

  function UploadForm(props) {
    var _this;

    _classCallCheck(this, UploadForm);

    _this = _possibleConstructorReturn(this, _getPrototypeOf(UploadForm).call(this, props));
    var form = JSON.parse(JSON.stringify(_this.props.form));
    _this.state = {
      formData: {},
      form: form,
      hasError: {},
      errorMessage: {},
      uploadProgress: -1
    };
    _this.onFormChange = _this.onFormChange.bind(_assertThisInitialized(_this));
    _this.submitForm = _this.submitForm.bind(_assertThisInitialized(_this));
    _this.uploadFile = _this.uploadFile.bind(_assertThisInitialized(_this));
    return _this;
  } // IBIS SPECIFIC OVERRIDE CODE
  // IBIS adds more options for imaging types.


  _createClass(UploadForm, [{
    key: "componentDidMount",
    value: function componentDidMount() {
      // Disable fields on initial load
      this.onFormChange(this.state.form.imagingUploadType.name, null);
    } // IBIS SPECIFIC OVERRIDE CODE ENDS HERE

    /*
     Updates values in formData
     Deletes CandID, PSCID, and VisitLabel values if Phantom Scans is set to No
     */
    // IBIS SPECIFIC OVERRIDE CODE
    // IBIS adds more options for imaging types.

  }, {
    key: "onFormChange",
    value: function onFormChange(field, value) {
      if (!field) return;
      var form = JSON.parse(JSON.stringify(this.state.form));
      var formData = Object.assign({}, this.state.formData);

      if (field === 'imagingUploadType') {
        if (value !== 'Subject') {
          delete formData.candID;
          delete formData.pSCID;
          delete formData.visitLabel;
        } else if (typeof formData.mriFile !== 'undefined') {
          var patientName = formData.mriFile.name.replace(/\.[a-z]+\.?[a-z]+?$/i, '');
          var ids = patientName.split('_');
          formData.candID = ids[1];
          formData.pSCID = ids[0]; // Note that the vlabel can be followed by an optional "_whatever"
          // which we have to ignore

          formData.visitLabel = ids[2];
        }
      }

      formData[field] = value;

      if (field === 'mriFile') {
        if (value.name && formData.imagingUploadType === 'Subject') {
          var _patientName = value.name.replace(/\.[a-z]+\.?[a-z]+?$/i, '');

          var _ids = _patientName.split('_');

          formData.candID = _ids[1];
          formData.pSCID = _ids[0]; // Note that the vlabel can be followed by an optional "_whatever"
          // which we have to ignore

          formData.visitLabel = _ids[2];
        }
      }

      this.setState({
        form: form,
        formData: formData,
        hasError: {},
        errorMessage: {},
        uploadProgress: -1
      });
    } // IBIS SPECIFIC OVERRIDE CODE ENDS HERE

  }, {
    key: "submitForm",
    value: function submitForm() {
      // Validate required fields
      var data = this.state.formData; // IBIS SPECIFIC OVERRIDE CODE
      // IBIS adds more options for imaging types.

      if (!data.mriFile || !data.imagingUploadType) {
        return;
      } // IBIS SPECIFIC OVERRIDE CODE ENDS HERE


      var fileName = data.mriFile.name; // Make sure file is of type .zip|.tgz|.tar.gz format

      var properExt = new RegExp('\.(zip|tgz|tar\.gz)$');

      if (!fileName.match(properExt)) {
        swal({
          title: 'Invalid extension for the uploaded file!',
          text: 'Filename extension does not match .zip, .tgz or .tar.gz ',
          type: 'error',
          confirmButtonText: 'OK'
        });
        var errorMessage = {
          mriFile: 'The file ' + fileName + ' must be of type .tgz, .tar.gz or .zip.',
          candID: undefined,
          pSCID: undefined,
          visitLabel: undefined
        };
        var hasError = {
          mriFile: true,
          candID: false,
          pSCID: false,
          visitLabel: false
        };
        this.setState({
          errorMessage: errorMessage,
          hasError: hasError
        });
        return;
      } // IBIS SPECIFIC OVERRIDE CODE
      // IBIS adds more options for imaging types.


      if (data.imagingUploadType === 'Subject') {
        // IBIS SPECIFIC OVERRIDE CODE ENDS HERE
        if (!data.candID || !data.pSCID || !data.visitLabel) {
          swal({
            title: 'Incorrect file name!',
            text: 'Could not determine PSCID, CandID and Visit Label based on the filename!\n',
            type: 'error',
            confirmButtonText: 'OK'
          });
          return;
        }
      } // Checks if a file with a given fileName has already been uploaded


      var mriFile = this.props.mriList.find(function (mriFile) {
        return mriFile.fileName.indexOf(fileName) > -1;
      }); // New File

      if (!mriFile) {
        this.uploadFile();
        return;
      } // File uploaded and completed mri pipeline


      if (mriFile.status === 'Success') {
        swal({
          title: 'File already exists!',
          text: 'A file with this name has already successfully passed the MRI pipeline!\n',
          type: 'error',
          confirmButtonText: 'OK'
        });
        return;
      } // File in the middle of insertion pipeline


      if (mriFile.status === 'In Progress...') {
        swal({
          title: 'File is currently processing!',
          text: 'A file with this name is currently going through the MRI pipeline!\n',
          type: 'error',
          confirmButtonText: 'OK'
        });
        return;
      } // File uploaded but failed during mri pipeline


      if (mriFile.status === 'Failure') {
        swal({
          title: 'Are you sure?',
          text: 'A file with this name already exists!\n Would you like to overwrite the existing file?',
          type: 'warning',
          showCancelButton: true,
          confirmButtonText: 'Yes, I am sure!',
          cancelButtonText: 'No, cancel it!'
        }, function (isConfirm) {
          if (isConfirm) {
            this.uploadFile(true);
          } else {
            swal('Cancelled', 'Your upload has been cancelled.', 'error');
          }
        }.bind(this));
      } // Pipeline has not been triggered yet


      if (mriFile.status === 'Not Started') {
        swal({
          title: 'Are you sure?',
          text: 'A file with this name has been uploaded but has not yet been processed by the MRI pipeline.' + '\n Would you like to overwrite the existing file?',
          type: 'warning',
          showCancelButton: true,
          confirmButtonText: 'Yes, I am sure!',
          cancelButtonText: 'No, cancel it!'
        }, function (isConfirm) {
          if (isConfirm) {
            this.uploadFile(true);
          } else {
            swal('Cancelled', 'Your upload has been cancelled.', 'error');
          }
        }.bind(this));
      }

      return;
    }
    /*
     Uploads file to the server, listening to the progress
     in order to get the percentage uploaded as value for the progress bar
     */

  }, {
    key: "uploadFile",
    value: function uploadFile(overwriteFile) {
      var _this2 = this;

      var formData = this.state.formData;
      var formObj = new FormData();

      for (var key in formData) {
        if (formData[key] !== '') {
          formObj.append(key, formData[key]);
        }
      }

      formObj.append('fire_away', 'Upload');

      if (overwriteFile) {
        formObj.append('overwrite', true);
      }

      $.ajax({
        type: 'POST',
        url: loris.BaseURL + '/imaging_uploader/',
        data: formObj,
        cache: false,
        contentType: false,
        processData: false,
        xhr: function () {
          var xhr = new window.XMLHttpRequest();
          xhr.upload.addEventListener('progress', function (evt) {
            if (evt.lengthComputable) {
              var percentage = Math.round(evt.loaded / evt.total * 100);
              this.setState({
                uploadProgress: percentage
              });
            }
          }.bind(this), false);
          return xhr;
        }.bind(this),
        // Upon successful upload:
        // - Resets errorMessage and hasError so no errors are displayed on form
        // - Displays pop up window with success message
        // - Returns to Browse tab
        success: function success(data) {
          var errorMessage = _this2.state.errorMessage;
          var hasError = _this2.state.hasError;

          for (var i in errorMessage) {
            if (errorMessage.hasOwnProperty(i)) {
              errorMessage[i] = '';
              hasError[i] = false;
            }
          }

          _this2.setState({
            errorMessage: errorMessage,
            hasError: hasError
          });

          var text = '';

          if (_this2.props.imagingUploaderAutoLaunch === 'true' || _this2.props.imagingUploaderAutoLaunch === '1') {
            text = 'Processing of this file by the MRI pipeline has started\n' + 'Select this upload in the result table to view the processing progress';
          }

          swal({
            title: 'Upload Successful!',
            text: text,
            type: 'success'
          }, function () {
            window.location.assign(loris.BaseURL + '/imaging_uploader/');
          });
        },
        // Upon errors in upload:
        // - Displays pop up window with submission error message
        // - Updates errorMessage and hasError so relevant errors are displayed on form
        // - Returns to Upload tab
        error: function error(_error, textStatus, errorThrown) {
          var errorMessage = Object.assign({}, _this2.state.errorMessage);
          var hasError = Object.assign({}, _this2.state.hasError);
          var messageToPrint = '';

          if (_error.responseJSON && _error.responseJSON.errors) {
            errorMessage = _error.responseJSON.errors;
          } else if (_error.status == 0) {
            errorMessage = {
              'mriFile': ['Upload failed: a network error occured']
            };
          } else if (_error.status == 413) {
            errorMessage = {
              'mriFile': ['Please make sure files are not larger than ' + _this2.props.maxUploadSize]
            };
          } else {
            errorMessage = {
              'mriFile': ['Upload failed: received HTTP response code ' + _error.status]
            };
          }

          for (var i in errorMessage) {
            if (errorMessage.hasOwnProperty(i)) {
              errorMessage[i] = errorMessage[i].toString();

              if (errorMessage[i].length) {
                hasError[i] = true;
                messageToPrint += errorMessage[i] + '\n';
              } else {
                hasError[i] = false;
              }
            }
          }

          swal({
            title: 'Submission error!',
            text: messageToPrint,
            type: 'error'
          });

          _this2.setState({
            uploadProgress: -1,
            errorMessage: errorMessage,
            hasError: hasError
          });
        }
      });
    } // IBIS SPECIFIC OVERRIDE CODE
    // IBIS adds more options for imaging types.

  }, {
    key: "render",
    value: function render() {
      // Bind form elements to formData
      var form = this.state.form;
      form.imagingUploadType.value = this.state.formData.imagingUploadType;
      form.candID.value = this.state.formData.candID;
      form.pSCID.value = this.state.formData.pSCID;
      form.visitLabel.value = this.state.formData.visitLabel;
      form.mriFile.value = this.state.formData.mriFile; // Hide button when progress bar is shown

      var btnClass = this.state.uploadProgress > -1 ? 'btn btn-primary hide' : undefined;
      var notes = react__WEBPACK_IMPORTED_MODULE_1___default.a.createElement("span", null, "File cannot exceed ", this.props.maxUploadSize, react__WEBPACK_IMPORTED_MODULE_1___default.a.createElement("br", null), "File must be of type .tgz or tar.gz or .zip", react__WEBPACK_IMPORTED_MODULE_1___default.a.createElement("br", null), react__WEBPACK_IMPORTED_MODULE_1___default.a.createElement("br", null), "For files that are ", react__WEBPACK_IMPORTED_MODULE_1___default.a.createElement("u", null, "Subject Scans"), ", file name must begin with", react__WEBPACK_IMPORTED_MODULE_1___default.a.createElement("b", null, " [PSCID]_[CandID]_[Visit Label]"), react__WEBPACK_IMPORTED_MODULE_1___default.a.createElement("br", null), "For example, for CandID ", react__WEBPACK_IMPORTED_MODULE_1___default.a.createElement("i", null, "100000"), ", PSCID ", react__WEBPACK_IMPORTED_MODULE_1___default.a.createElement("i", null, "ABC123"), ", and Visit Label ", react__WEBPACK_IMPORTED_MODULE_1___default.a.createElement("i", null, "V1"), " the file name should be prefixed by:", react__WEBPACK_IMPORTED_MODULE_1___default.a.createElement("b", null, " ABC123_100000_V1"), react__WEBPACK_IMPORTED_MODULE_1___default.a.createElement("br", null), react__WEBPACK_IMPORTED_MODULE_1___default.a.createElement("br", null), "For ", react__WEBPACK_IMPORTED_MODULE_1___default.a.createElement("u", null, "inter-scanner reliability scans"), ", the file name (without extension) must be of the form:", react__WEBPACK_IMPORTED_MODULE_1___default.a.createElement("br", null), react__WEBPACK_IMPORTED_MODULE_1___default.a.createElement("b", null, " [site]_interscan_[subject initials]_[scanner name]_[scanner_location]_[date][scan number] "), react__WEBPACK_IMPORTED_MODULE_1___default.a.createElement("br", null), "where", react__WEBPACK_IMPORTED_MODULE_1___default.a.createElement("br", null), react__WEBPACK_IMPORTED_MODULE_1___default.a.createElement("ul", null, react__WEBPACK_IMPORTED_MODULE_1___default.a.createElement("li", null, "[site] is the three-letter site abbreviation"), react__WEBPACK_IMPORTED_MODULE_1___default.a.createElement("li", null, "[subject initials] are the subject\u2019s initials (three letters)"), react__WEBPACK_IMPORTED_MODULE_1___default.a.createElement("li", null, "[scanner name] is the name of the scanner"), react__WEBPACK_IMPORTED_MODULE_1___default.a.createElement("li", null, "[scanner location] three-letter scanner location"), react__WEBPACK_IMPORTED_MODULE_1___default.a.createElement("li", null, "[date] is the scan acquisition date in format YYYYMMDD"), react__WEBPACK_IMPORTED_MODULE_1___default.a.createElement("li", null, "[scan number] is an optional string of the form \u2019_scan1\u2019 for multi-part scans")), "All the file name parts are case-insensitive. Example of a valid file name:", react__WEBPACK_IMPORTED_MODULE_1___default.a.createElement("br", null), "UNC_interscan_BEA_trio_HOS_20190324_scan2.tar.gz"); // Returns individual form elements
      // For CandID, PSCID, and Visit Label, disabled and required
      // are updated depending on imagingUploadType value
      // For all elements, hasError and errorMessage
      // are updated depending on what values are submitted

      return react__WEBPACK_IMPORTED_MODULE_1___default.a.createElement("div", {
        className: "row"
      }, react__WEBPACK_IMPORTED_MODULE_1___default.a.createElement("div", {
        className: "col-md-7"
      }, react__WEBPACK_IMPORTED_MODULE_1___default.a.createElement("h3", null, "Upload an imaging scan"), react__WEBPACK_IMPORTED_MODULE_1___default.a.createElement("br", null), react__WEBPACK_IMPORTED_MODULE_1___default.a.createElement(FormElement, {
        name: "upload_form",
        fileUpload: true
      }, react__WEBPACK_IMPORTED_MODULE_1___default.a.createElement(SelectElement, {
        name: "imagingUploadType",
        label: "Imaging Upload Type",
        options: this.props.form.imagingUploadType.options,
        onUserInput: this.onFormChange,
        required: true,
        hasError: this.state.hasError.imagingUploadType,
        errorMessage: this.state.errorMessage.imagingUploadType,
        value: this.state.formData.imagingUploadType
      }), react__WEBPACK_IMPORTED_MODULE_1___default.a.createElement(TextboxElement, {
        name: "candID",
        label: "CandID",
        disabled: true,
        required: false,
        hasError: this.state.hasError.candID,
        errorMessage: this.state.errorMessage.candID,
        value: this.state.formData.candID
      }), react__WEBPACK_IMPORTED_MODULE_1___default.a.createElement(TextboxElement, {
        name: "pSCID",
        label: "PSCID",
        disabled: true,
        required: false,
        hasError: this.state.hasError.pSCID,
        errorMessage: this.state.errorMessage.pSCID,
        value: this.state.formData.pSCID
      }), react__WEBPACK_IMPORTED_MODULE_1___default.a.createElement(TextboxElement, {
        name: "visitLabel",
        label: "Visit Label",
        disabled: true,
        required: false,
        hasError: this.state.hasError.visitLabel,
        errorMessage: this.state.errorMessage.visitLabel,
        value: this.state.formData.visitLabel
      }), react__WEBPACK_IMPORTED_MODULE_1___default.a.createElement(FileElement, {
        name: "mriFile",
        label: "File to Upload",
        onUserInput: this.onFormChange,
        required: true,
        hasError: this.state.hasError.mriFile,
        errorMessage: this.state.errorMessage.mriFile,
        value: this.state.formData.mriFile
      }), react__WEBPACK_IMPORTED_MODULE_1___default.a.createElement(StaticElement, {
        label: "Notes",
        text: notes
      }), react__WEBPACK_IMPORTED_MODULE_1___default.a.createElement("div", {
        className: "row"
      }, react__WEBPACK_IMPORTED_MODULE_1___default.a.createElement("div", {
        className: "col-sm-9 col-sm-offset-3"
      }, react__WEBPACK_IMPORTED_MODULE_1___default.a.createElement(ProgressBar__WEBPACK_IMPORTED_MODULE_0__["default"], {
        value: this.state.uploadProgress
      }))), react__WEBPACK_IMPORTED_MODULE_1___default.a.createElement(ButtonElement, {
        onUserInput: this.submitForm,
        buttonClass: btnClass
      }))));
    } // IBIS SPECIFIC OVERRIDE CODE ENDS HERE

  }]);

  return UploadForm;
}(react__WEBPACK_IMPORTED_MODULE_1__["Component"]);

UploadForm.propTypes = {};
UploadForm.defaultProps = {};
/* harmony default export */ __webpack_exports__["default"] = (UploadForm);

/***/ }),
/* 16 */
/***/ (function(module, __webpack_exports__, __webpack_require__) {

"use strict";
__webpack_require__.r(__webpack_exports__);
/* harmony import */ var react__WEBPACK_IMPORTED_MODULE_0__ = __webpack_require__(2);
/* harmony import */ var react__WEBPACK_IMPORTED_MODULE_0___default = /*#__PURE__*/__webpack_require__.n(react__WEBPACK_IMPORTED_MODULE_0__);
/* harmony import */ var prop_types__WEBPACK_IMPORTED_MODULE_1__ = __webpack_require__(3);
/* harmony import */ var prop_types__WEBPACK_IMPORTED_MODULE_1___default = /*#__PURE__*/__webpack_require__.n(prop_types__WEBPACK_IMPORTED_MODULE_1__);
function _typeof(obj) { if (typeof Symbol === "function" && typeof Symbol.iterator === "symbol") { _typeof = function _typeof(obj) { return typeof obj; }; } else { _typeof = function _typeof(obj) { return obj && typeof Symbol === "function" && obj.constructor === Symbol && obj !== Symbol.prototype ? "symbol" : typeof obj; }; } return _typeof(obj); }

function _classCallCheck(instance, Constructor) { if (!(instance instanceof Constructor)) { throw new TypeError("Cannot call a class as a function"); } }

function _defineProperties(target, props) { for (var i = 0; i < props.length; i++) { var descriptor = props[i]; descriptor.enumerable = descriptor.enumerable || false; descriptor.configurable = true; if ("value" in descriptor) descriptor.writable = true; Object.defineProperty(target, descriptor.key, descriptor); } }

function _createClass(Constructor, protoProps, staticProps) { if (protoProps) _defineProperties(Constructor.prototype, protoProps); if (staticProps) _defineProperties(Constructor, staticProps); return Constructor; }

function _possibleConstructorReturn(self, call) { if (call && (_typeof(call) === "object" || typeof call === "function")) { return call; } return _assertThisInitialized(self); }

function _assertThisInitialized(self) { if (self === void 0) { throw new ReferenceError("this hasn't been initialised - super() hasn't been called"); } return self; }

function _getPrototypeOf(o) { _getPrototypeOf = Object.setPrototypeOf ? Object.getPrototypeOf : function _getPrototypeOf(o) { return o.__proto__ || Object.getPrototypeOf(o); }; return _getPrototypeOf(o); }

function _inherits(subClass, superClass) { if (typeof superClass !== "function" && superClass !== null) { throw new TypeError("Super expression must either be null or a function"); } subClass.prototype = Object.create(superClass && superClass.prototype, { constructor: { value: subClass, writable: true, configurable: true } }); if (superClass) _setPrototypeOf(subClass, superClass); }

function _setPrototypeOf(o, p) { _setPrototypeOf = Object.setPrototypeOf || function _setPrototypeOf(o, p) { o.__proto__ = p; return o; }; return _setPrototypeOf(o, p); }

/**
 * React ProgressBar.
 *
 * Updates UI automatically when passed a progress value between 0 and 100.
 * To hide progress bar before/after upload, set value to -1.
 *
 * Note: This component relies on Bootstrap 3 progress-bar classes
 * (http://getbootstrap.com/components/#progress)
 */



var ProgressBar =
/*#__PURE__*/
function (_Component) {
  _inherits(ProgressBar, _Component);

  function ProgressBar() {
    _classCallCheck(this, ProgressBar);

    return _possibleConstructorReturn(this, _getPrototypeOf(ProgressBar).apply(this, arguments));
  }

  _createClass(ProgressBar, [{
    key: "render",
    value: function render() {
      var progressStyle = {
        display: this.props.value < 0 ? 'none' : 'block',
        backgroundColor: '#d3d3d3',
        height: '30px',
        position: 'relative'
      };
      var labelStyle = {
        position: 'absolute',
        top: 0,
        left: 0,
        zIndex: 1000,
        width: '100%',
        color: '#fff',
        textAlign: 'center',
        lineHeight: '30px',
        fontWeight: '600'
      };
      return react__WEBPACK_IMPORTED_MODULE_0___default.a.createElement("div", {
        className: "progress",
        style: progressStyle
      }, react__WEBPACK_IMPORTED_MODULE_0___default.a.createElement("div", {
        className: "progress-bar progress-bar-striped active",
        role: "progressbar",
        "aria-valuemin": "0",
        "aria-valuemax": "100",
        "aria-valuenow": this.props.value,
        style: {
          width: this.props.value + '%'
        }
      }), react__WEBPACK_IMPORTED_MODULE_0___default.a.createElement("span", {
        style: labelStyle
      }, this.props.value, "%"));
    }
  }]);

  return ProgressBar;
}(react__WEBPACK_IMPORTED_MODULE_0__["Component"]);

ProgressBar.propTypes = {
  value: prop_types__WEBPACK_IMPORTED_MODULE_1___default.a.number
};
ProgressBar.defaultProps = {
  value: 0
};
/* harmony default export */ __webpack_exports__["default"] = (ProgressBar);

/***/ })
/******/ ]);
//# sourceMappingURL=index.js.map