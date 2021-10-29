window["lorisjs"] = window["lorisjs"] || {}; window["lorisjs"]["imaging_browser"] = window["lorisjs"]["imaging_browser"] || {}; window["lorisjs"]["imaging_browser"]["ImagePanel"] =
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
/* harmony import */ var react__WEBPACK_IMPORTED_MODULE_0__ = __webpack_require__(1);
/* harmony import */ var react__WEBPACK_IMPORTED_MODULE_0___default = /*#__PURE__*/__webpack_require__.n(react__WEBPACK_IMPORTED_MODULE_0__);
/* harmony import */ var prop_types__WEBPACK_IMPORTED_MODULE_1__ = __webpack_require__(2);
/* harmony import */ var prop_types__WEBPACK_IMPORTED_MODULE_1___default = /*#__PURE__*/__webpack_require__.n(prop_types__WEBPACK_IMPORTED_MODULE_1__);
function _typeof(obj) { "@babel/helpers - typeof"; if (typeof Symbol === "function" && typeof Symbol.iterator === "symbol") { _typeof = function _typeof(obj) { return typeof obj; }; } else { _typeof = function _typeof(obj) { return obj && typeof Symbol === "function" && obj.constructor === Symbol && obj !== Symbol.prototype ? "symbol" : typeof obj; }; } return _typeof(obj); }

function _classCallCheck(instance, Constructor) { if (!(instance instanceof Constructor)) { throw new TypeError("Cannot call a class as a function"); } }

function _defineProperties(target, props) { for (var i = 0; i < props.length; i++) { var descriptor = props[i]; descriptor.enumerable = descriptor.enumerable || false; descriptor.configurable = true; if ("value" in descriptor) descriptor.writable = true; Object.defineProperty(target, descriptor.key, descriptor); } }

function _createClass(Constructor, protoProps, staticProps) { if (protoProps) _defineProperties(Constructor.prototype, protoProps); if (staticProps) _defineProperties(Constructor, staticProps); return Constructor; }

function _inherits(subClass, superClass) { if (typeof superClass !== "function" && superClass !== null) { throw new TypeError("Super expression must either be null or a function"); } subClass.prototype = Object.create(superClass && superClass.prototype, { constructor: { value: subClass, writable: true, configurable: true } }); if (superClass) _setPrototypeOf(subClass, superClass); }

function _setPrototypeOf(o, p) { _setPrototypeOf = Object.setPrototypeOf || function _setPrototypeOf(o, p) { o.__proto__ = p; return o; }; return _setPrototypeOf(o, p); }

function _createSuper(Derived) { var hasNativeReflectConstruct = _isNativeReflectConstruct(); return function _createSuperInternal() { var Super = _getPrototypeOf(Derived), result; if (hasNativeReflectConstruct) { var NewTarget = _getPrototypeOf(this).constructor; result = Reflect.construct(Super, arguments, NewTarget); } else { result = Super.apply(this, arguments); } return _possibleConstructorReturn(this, result); }; }

function _possibleConstructorReturn(self, call) { if (call && (_typeof(call) === "object" || typeof call === "function")) { return call; } else if (call !== void 0) { throw new TypeError("Derived constructors may only return object or undefined"); } return _assertThisInitialized(self); }

function _assertThisInitialized(self) { if (self === void 0) { throw new ReferenceError("this hasn't been initialised - super() hasn't been called"); } return self; }

function _isNativeReflectConstruct() { if (typeof Reflect === "undefined" || !Reflect.construct) return false; if (Reflect.construct.sham) return false; if (typeof Proxy === "function") return true; try { Boolean.prototype.valueOf.call(Reflect.construct(Boolean, [], function () {})); return true; } catch (e) { return false; } }

function _getPrototypeOf(o) { _getPrototypeOf = Object.setPrototypeOf ? Object.getPrototypeOf : function _getPrototypeOf(o) { return o.__proto__ || Object.getPrototypeOf(o); }; return _getPrototypeOf(o); }

/* exported ImagePanelHeader, ImagePanelHeadersTable, ImageQCDropdown, ImageQCStatic,
 ImagePanelQCStatusSelector, ImagePanelQCSelectedSelector, ImagePanelQCCaveatSelector,
 ImagePanelQCSNRValue, ImagePanelQCPanel, DownloadButton, ImageQCCommentsButton.
 LongitudinalViewButton, ImageDownloadButtons, ImagePanelBody, RImagePanel
* */



var ImagePanelHeader = /*#__PURE__*/function (_Component) {
  _inherits(ImagePanelHeader, _Component);

  var _super = _createSuper(ImagePanelHeader);

  function ImagePanelHeader(props) {
    _classCallCheck(this, ImagePanelHeader);

    return _super.call(this, props);
  }

  _createClass(ImagePanelHeader, [{
    key: "componentDidMount",
    value: function componentDidMount() {
      $('.panel-title').tooltip();
    }
  }, {
    key: "render",
    value: function render() {
      var QCStatusLabel;

      if (this.props.QCStatus === 'Pass') {
        QCStatusLabel = /*#__PURE__*/react__WEBPACK_IMPORTED_MODULE_0___default.a.createElement("span", {
          className: "label label-success"
        }, this.props.QCStatus);
      } else if (this.props.QCStatus === 'Fail') {
        QCStatusLabel = /*#__PURE__*/react__WEBPACK_IMPORTED_MODULE_0___default.a.createElement("span", {
          className: "label label-danger"
        }, this.props.QCStatus);
      }

      var arrow;

      if (this.props.Expanded) {
        arrow = /*#__PURE__*/react__WEBPACK_IMPORTED_MODULE_0___default.a.createElement("span", {
          onClick: this.props.onToggleBody,
          className: "pull-right clickable glyphicon arrow glyphicon-chevron-up"
        });
      } else {
        arrow = /*#__PURE__*/react__WEBPACK_IMPORTED_MODULE_0___default.a.createElement("span", {
          onClick: this.props.onToggleBody,
          className: "pull-right clickable glyphicon arrow glyphicon-chevron-down"
        });
      }

      var headerButton = /*#__PURE__*/react__WEBPACK_IMPORTED_MODULE_0___default.a.createElement("div", {
        className: "pull-right"
      }, /*#__PURE__*/react__WEBPACK_IMPORTED_MODULE_0___default.a.createElement("div", {
        className: "btn-group views"
      }, /*#__PURE__*/react__WEBPACK_IMPORTED_MODULE_0___default.a.createElement("button", {
        type: "button",
        className: "btn btn-default btn-xs dropdown-toggle",
        onClick: this.props.onToggleHeaders,
        "aria-expanded": this.props.HeadersExpanded
      }, "Header Info"), /*#__PURE__*/react__WEBPACK_IMPORTED_MODULE_0___default.a.createElement("span", {
        className: "caret"
      }))); // IBIS SPECIFIC OVERRIDE CODE
      // OVERRIDE: add acquisition date to header.

      var acquiredOn = this.props.HeaderInfo.AcquisitionDate ? ' acquired on ' + this.props.HeaderInfo.AcquisitionDate : ' (acq. date unknown) ';
      var acquisitionDate = this.props.HeaderInfo.AcquisitionDate ? this.props.HeaderInfo.AcquisitionDate : '(acq. date unknown)';
      return /*#__PURE__*/react__WEBPACK_IMPORTED_MODULE_0___default.a.createElement("div", {
        className: "panel-heading clearfix"
      }, /*#__PURE__*/react__WEBPACK_IMPORTED_MODULE_0___default.a.createElement("input", {
        type: "checkbox",
        "data-file-id": this.props.FileID,
        className: "mripanel user-success"
      }), /*#__PURE__*/react__WEBPACK_IMPORTED_MODULE_0___default.a.createElement("h3", {
        className: "panel-title",
        "data-toggle": "tooltip",
        title: this.props.Filename + acquiredOn
      }, this.props.Filename, "\xA0\xA0\u2023\u2023\xA0\xA0", acquisitionDate, "\xA0"), QCStatusLabel, arrow, headerButton); // IBIS SPECIFIC OVERRIDE CODE ENDS HERE
    }
  }]);

  return ImagePanelHeader;
}(react__WEBPACK_IMPORTED_MODULE_0__["Component"]); // IBIS SPECIFIC OVERRIDE CODE
// OVERRIDE: add HeaderInfo prop.


ImagePanelHeader.propTypes = {
  QCStatus: prop_types__WEBPACK_IMPORTED_MODULE_1___default.a.string,
  onToggleBody: prop_types__WEBPACK_IMPORTED_MODULE_1___default.a.string,
  onToggleHeaders: prop_types__WEBPACK_IMPORTED_MODULE_1___default.a.string,
  HeadersExpanded: prop_types__WEBPACK_IMPORTED_MODULE_1___default.a.string,
  FileID: prop_types__WEBPACK_IMPORTED_MODULE_1___default.a.string,
  HeaderInfo: prop_types__WEBPACK_IMPORTED_MODULE_1___default.a.object
}; // IBIS SPECIFIC OVERRIDE CODE ENDS HERE

var ImagePanelHeadersTable = /*#__PURE__*/function (_Component2) {
  _inherits(ImagePanelHeadersTable, _Component2);

  var _super2 = _createSuper(ImagePanelHeadersTable);

  function ImagePanelHeadersTable(props) {
    _classCallCheck(this, ImagePanelHeadersTable);

    return _super2.call(this, props);
  }

  _createClass(ImagePanelHeadersTable, [{
    key: "componentDidMount",
    value: function componentDidMount() {
      $(ReactDOM.findDOMNode(this)).DynamicTable();
    }
  }, {
    key: "componentWillUnmount",
    value: function componentWillUnmount() {
      // Remove wrapper nodes so React is able to remove component
      $(ReactDOM.findDOMNode(this)).DynamicTable({
        removeDynamicTable: true
      });
    }
  }, {
    key: "render",
    value: function render() {
      return /*#__PURE__*/react__WEBPACK_IMPORTED_MODULE_0___default.a.createElement("table", {
        className: "table table-hover table-bordered header-info col-xs-12 dynamictable"
      }, /*#__PURE__*/react__WEBPACK_IMPORTED_MODULE_0___default.a.createElement("tbody", null, /*#__PURE__*/react__WEBPACK_IMPORTED_MODULE_0___default.a.createElement("tr", null, /*#__PURE__*/react__WEBPACK_IMPORTED_MODULE_0___default.a.createElement("th", {
        className: "info col-xs-2"
      }, "Voxel Size"), /*#__PURE__*/react__WEBPACK_IMPORTED_MODULE_0___default.a.createElement("td", {
        className: "col-xs-6",
        colSpan: "3"
      }, this.props.HeaderInfo.XStep === '' ? ' ' : 'X: ' + this.props.HeaderInfo.XStep + ' mm ', this.props.HeaderInfo.YStep === '' ? ' ' : 'Y: ' + this.props.HeaderInfo.YStep + ' mm ', this.props.HeaderInfo.ZStep === '' ? ' ' : 'Z: ' + this.props.HeaderInfo.ZStep + ' mm '), /*#__PURE__*/react__WEBPACK_IMPORTED_MODULE_0___default.a.createElement("th", {
        className: "col-xs-2 info"
      }, "Output Type"), /*#__PURE__*/react__WEBPACK_IMPORTED_MODULE_0___default.a.createElement("td", {
        className: "col-xs-2"
      }, this.props.HeaderInfo.OutputType)), /*#__PURE__*/react__WEBPACK_IMPORTED_MODULE_0___default.a.createElement("tr", null, /*#__PURE__*/react__WEBPACK_IMPORTED_MODULE_0___default.a.createElement("th", {
        className: "col-xs-2 info"
      }, "Acquisition Date"), /*#__PURE__*/react__WEBPACK_IMPORTED_MODULE_0___default.a.createElement("td", {
        className: "col-xs-2"
      }, this.props.HeaderInfo.AcquisitionDate), /*#__PURE__*/react__WEBPACK_IMPORTED_MODULE_0___default.a.createElement("th", {
        className: "col-xs-2 info"
      }, "Space"), /*#__PURE__*/react__WEBPACK_IMPORTED_MODULE_0___default.a.createElement("td", {
        className: "col-xs-2"
      }, this.props.HeaderInfo.CoordinateSpace), /*#__PURE__*/react__WEBPACK_IMPORTED_MODULE_0___default.a.createElement("th", {
        className: "col-xs-2 info"
      }, "Inserted Date"), /*#__PURE__*/react__WEBPACK_IMPORTED_MODULE_0___default.a.createElement("td", {
        className: "col-xs-2"
      }, this.props.HeaderInfo.InsertedDate)), /*#__PURE__*/react__WEBPACK_IMPORTED_MODULE_0___default.a.createElement("tr", null, /*#__PURE__*/react__WEBPACK_IMPORTED_MODULE_0___default.a.createElement("th", {
        className: "col-xs-2 info"
      }, "Protocol"), /*#__PURE__*/react__WEBPACK_IMPORTED_MODULE_0___default.a.createElement("td", {
        className: "col-xs-2"
      }, this.props.HeaderInfo.AcquisitionProtocol), /*#__PURE__*/react__WEBPACK_IMPORTED_MODULE_0___default.a.createElement("th", {
        className: "col-xs-2 info"
      }, "Series Description"), /*#__PURE__*/react__WEBPACK_IMPORTED_MODULE_0___default.a.createElement("td", {
        className: "col-xs-2"
      }, this.props.HeaderInfo.SeriesDescription), /*#__PURE__*/react__WEBPACK_IMPORTED_MODULE_0___default.a.createElement("th", {
        className: "col-xs-2 info"
      }, "Series Number"), /*#__PURE__*/react__WEBPACK_IMPORTED_MODULE_0___default.a.createElement("td", {
        className: "col-xs-2"
      }, this.props.HeaderInfo.SeriesNumber)), /*#__PURE__*/react__WEBPACK_IMPORTED_MODULE_0___default.a.createElement("tr", null, /*#__PURE__*/react__WEBPACK_IMPORTED_MODULE_0___default.a.createElement("th", {
        className: "col-xs-2 info"
      }, "Echo Time"), /*#__PURE__*/react__WEBPACK_IMPORTED_MODULE_0___default.a.createElement("td", {
        className: "col-xs-2"
      }, this.props.HeaderInfo.EchoTime, " ms"), /*#__PURE__*/react__WEBPACK_IMPORTED_MODULE_0___default.a.createElement("th", {
        className: "col-xs-2 info"
      }, "Rep Time"), /*#__PURE__*/react__WEBPACK_IMPORTED_MODULE_0___default.a.createElement("td", {
        className: "col-xs-2"
      }, this.props.HeaderInfo.RepetitionTime, " ms"), /*#__PURE__*/react__WEBPACK_IMPORTED_MODULE_0___default.a.createElement("th", {
        className: "col-xs-2 info"
      }, "Slice Thick"), /*#__PURE__*/react__WEBPACK_IMPORTED_MODULE_0___default.a.createElement("td", {
        className: "col-xs-2"
      }, this.props.HeaderInfo.SliceThickness, " mm")), /*#__PURE__*/react__WEBPACK_IMPORTED_MODULE_0___default.a.createElement("tr", null, /*#__PURE__*/react__WEBPACK_IMPORTED_MODULE_0___default.a.createElement("th", {
        className: "col-xs-2 info"
      }, "Number of volumes"), /*#__PURE__*/react__WEBPACK_IMPORTED_MODULE_0___default.a.createElement("td", {
        className: "col-xs-2"
      }, this.props.HeaderInfo.NumVolumes, " volumes"), /*#__PURE__*/react__WEBPACK_IMPORTED_MODULE_0___default.a.createElement("th", {
        className: "col-xs-2 info"
      }, "Pipeline"), /*#__PURE__*/react__WEBPACK_IMPORTED_MODULE_0___default.a.createElement("td", {
        className: "col-xs-2"
      }, this.props.HeaderInfo.Pipeline), /*#__PURE__*/react__WEBPACK_IMPORTED_MODULE_0___default.a.createElement("th", {
        className: "col-xs-2 info"
      }, "Algorithm"), /*#__PURE__*/react__WEBPACK_IMPORTED_MODULE_0___default.a.createElement("td", {
        className: "col-xs-2"
      }, this.props.HeaderInfo.Algorithm)), /*#__PURE__*/react__WEBPACK_IMPORTED_MODULE_0___default.a.createElement("tr", null, /*#__PURE__*/react__WEBPACK_IMPORTED_MODULE_0___default.a.createElement("th", {
        className: "col-xs-2 info"
      }, "Number of rejected directions"), /*#__PURE__*/react__WEBPACK_IMPORTED_MODULE_0___default.a.createElement("td", {
        className: "col-xs-2"
      }, this.props.HeaderInfo.TotalRejected), /*#__PURE__*/react__WEBPACK_IMPORTED_MODULE_0___default.a.createElement("th", {
        className: "col-xs-2 info"
      }, "Number of Interlace correlations"), /*#__PURE__*/react__WEBPACK_IMPORTED_MODULE_0___default.a.createElement("td", {
        className: "col-xs-2"
      }, this.props.HeaderInfo.InterlaceRejected), /*#__PURE__*/react__WEBPACK_IMPORTED_MODULE_0___default.a.createElement("th", {
        className: "col-xs-2 info"
      }, "Number of Gradient-wise correlations"), /*#__PURE__*/react__WEBPACK_IMPORTED_MODULE_0___default.a.createElement("td", {
        className: "col-xs-2"
      }, this.props.HeaderInfo.IntergradientRejected)), /*#__PURE__*/react__WEBPACK_IMPORTED_MODULE_0___default.a.createElement("tr", null, /*#__PURE__*/react__WEBPACK_IMPORTED_MODULE_0___default.a.createElement("th", {
        className: "col-xs-2 info"
      }, "Number of Slicewise correlations"), /*#__PURE__*/react__WEBPACK_IMPORTED_MODULE_0___default.a.createElement("td", {
        className: "col-xs-2"
      }, this.props.HeaderInfo.SlicewiseRejected), /*#__PURE__*/react__WEBPACK_IMPORTED_MODULE_0___default.a.createElement("th", {
        className: "col-xs-2 info"
      }, "Series Instance UID"), /*#__PURE__*/react__WEBPACK_IMPORTED_MODULE_0___default.a.createElement("td", {
        className: "col-xs-2",
        colSpan: "2"
      }, this.props.HeaderInfo.SeriesUID), /*#__PURE__*/react__WEBPACK_IMPORTED_MODULE_0___default.a.createElement("td", {
        className: "col-xs-4",
        colSpan: "4"
      }, "\xA0"))));
    }
  }]);

  return ImagePanelHeadersTable;
}(react__WEBPACK_IMPORTED_MODULE_0__["Component"]);

ImagePanelHeadersTable.propTypes = {
  HeaderInfo: prop_types__WEBPACK_IMPORTED_MODULE_1___default.a.object
};

var ImageQCDropdown = /*#__PURE__*/function (_Component3) {
  _inherits(ImageQCDropdown, _Component3);

  var _super3 = _createSuper(ImageQCDropdown);

  function ImageQCDropdown(props) {
    _classCallCheck(this, ImageQCDropdown);

    return _super3.call(this, props);
  }

  _createClass(ImageQCDropdown, [{
    key: "render",
    value: function render() {
      var label = /*#__PURE__*/react__WEBPACK_IMPORTED_MODULE_0___default.a.createElement("label", null, this.props.Label);

      if (this.props.url) {
        label = /*#__PURE__*/react__WEBPACK_IMPORTED_MODULE_0___default.a.createElement("label", null, /*#__PURE__*/react__WEBPACK_IMPORTED_MODULE_0___default.a.createElement("a", {
          href: this.props.url
        }, this.props.Label));
      }

      var dropdown;

      if (this.props.editable) {
        var options = [];

        for (var key in this.props.options) {
          if (this.props.options.hasOwnProperty(key)) {
            options.push( /*#__PURE__*/react__WEBPACK_IMPORTED_MODULE_0___default.a.createElement("option", {
              key: this.props.FormName + this.props.FileID + key,
              className: "form-control input-sm option",
              value: key
            }, this.props.options[key]));
          }
        }

        dropdown = /*#__PURE__*/react__WEBPACK_IMPORTED_MODULE_0___default.a.createElement("select", {
          name: this.props.FormName + '[' + this.props.FileID + ']',
          defaultValue: this.props.defaultValue,
          className: "form-control input-sm"
        }, options);
      } else {
        dropdown = /*#__PURE__*/react__WEBPACK_IMPORTED_MODULE_0___default.a.createElement("div", {
          className: "col-xs-12"
        }, this.props.defaultValue);
      }

      return /*#__PURE__*/react__WEBPACK_IMPORTED_MODULE_0___default.a.createElement("div", {
        className: "row"
      }, label, dropdown);
    }
  }]);

  return ImageQCDropdown;
}(react__WEBPACK_IMPORTED_MODULE_0__["Component"]);

ImageQCDropdown.propTypes = {
  Label: prop_types__WEBPACK_IMPORTED_MODULE_1___default.a.string,
  url: prop_types__WEBPACK_IMPORTED_MODULE_1___default.a.string,
  editable: prop_types__WEBPACK_IMPORTED_MODULE_1___default.a.string,
  options: prop_types__WEBPACK_IMPORTED_MODULE_1___default.a.object,
  FileID: prop_types__WEBPACK_IMPORTED_MODULE_1___default.a.string,
  FormName: prop_types__WEBPACK_IMPORTED_MODULE_1___default.a.string,
  defaultValue: prop_types__WEBPACK_IMPORTED_MODULE_1___default.a.string
};

var ImageQCStatic = /*#__PURE__*/function (_Component4) {
  _inherits(ImageQCStatic, _Component4);

  var _super4 = _createSuper(ImageQCStatic);

  function ImageQCStatic(props) {
    _classCallCheck(this, ImageQCStatic);

    return _super4.call(this, props);
  }

  _createClass(ImageQCStatic, [{
    key: "render",
    value: function render() {
      var staticInfo;
      staticInfo = /*#__PURE__*/react__WEBPACK_IMPORTED_MODULE_0___default.a.createElement("div", {
        className: "col-xs-12"
      }, this.props.defaultValue);
      return /*#__PURE__*/react__WEBPACK_IMPORTED_MODULE_0___default.a.createElement("div", {
        className: "row"
      }, /*#__PURE__*/react__WEBPACK_IMPORTED_MODULE_0___default.a.createElement("label", null, this.props.Label), staticInfo);
    }
  }]);

  return ImageQCStatic;
}(react__WEBPACK_IMPORTED_MODULE_0__["Component"]);

ImageQCStatic.propTypes = {
  defaultValue: prop_types__WEBPACK_IMPORTED_MODULE_1___default.a.string,
  Label: prop_types__WEBPACK_IMPORTED_MODULE_1___default.a.string
};

var ImagePanelQCStatusSelector = /*#__PURE__*/function (_Component5) {
  _inherits(ImagePanelQCStatusSelector, _Component5);

  var _super5 = _createSuper(ImagePanelQCStatusSelector);

  function ImagePanelQCStatusSelector(props) {
    _classCallCheck(this, ImagePanelQCStatusSelector);

    return _super5.call(this, props);
  }

  _createClass(ImagePanelQCStatusSelector, [{
    key: "render",
    value: function render() {
      var qcStatusLabel;

      if (this.props.HasQCPerm && this.props.FileNew) {
        qcStatusLabel = /*#__PURE__*/react__WEBPACK_IMPORTED_MODULE_0___default.a.createElement("span", null, "QC Status ", /*#__PURE__*/react__WEBPACK_IMPORTED_MODULE_0___default.a.createElement("span", {
          className: "text-info"
        }, "( ", /*#__PURE__*/react__WEBPACK_IMPORTED_MODULE_0___default.a.createElement("span", {
          className: "glyphicon glyphicon-star"
        }), " New )"));
      } else {
        qcStatusLabel = 'QC Status';
      }

      return /*#__PURE__*/react__WEBPACK_IMPORTED_MODULE_0___default.a.createElement(ImageQCDropdown, {
        Label: qcStatusLabel,
        FormName: "status",
        FileID: this.props.FileID,
        editable: this.props.HasQCPerm,
        defaultValue: this.props.QCStatus,
        options: {
          '': '',
          'Pass': 'Pass',
          'Fail': 'Fail'
        }
      });
    }
  }]);

  return ImagePanelQCStatusSelector;
}(react__WEBPACK_IMPORTED_MODULE_0__["Component"]);

ImagePanelQCStatusSelector.propTypes = {
  FileNew: prop_types__WEBPACK_IMPORTED_MODULE_1___default.a.string,
  HasQCPerm: prop_types__WEBPACK_IMPORTED_MODULE_1___default.a.string,
  QCStatus: prop_types__WEBPACK_IMPORTED_MODULE_1___default.a.string
};

var ImagePanelQCSelectedSelector = /*#__PURE__*/function (_Component6) {
  _inherits(ImagePanelQCSelectedSelector, _Component6);

  var _super6 = _createSuper(ImagePanelQCSelectedSelector);

  function ImagePanelQCSelectedSelector(props) {
    _classCallCheck(this, ImagePanelQCSelectedSelector);

    return _super6.call(this, props);
  }

  _createClass(ImagePanelQCSelectedSelector, [{
    key: "render",
    value: function render() {
      return /*#__PURE__*/react__WEBPACK_IMPORTED_MODULE_0___default.a.createElement(ImageQCDropdown, {
        Label: "Selected",
        FormName: "selectedvol",
        FileID: this.props.FileID,
        editable: this.props.HasQCPerm,
        options: {
          '': '',
          'true': 'True',
          'false': 'False'
        },
        defaultValue: this.props.Selected
      });
    }
  }]);

  return ImagePanelQCSelectedSelector;
}(react__WEBPACK_IMPORTED_MODULE_0__["Component"]);

ImagePanelQCSelectedSelector.propTypes = {
  FileID: prop_types__WEBPACK_IMPORTED_MODULE_1___default.a.string,
  HasQCPerm: prop_types__WEBPACK_IMPORTED_MODULE_1___default.a.string,
  Selected: prop_types__WEBPACK_IMPORTED_MODULE_1___default.a.string
};

var ImagePanelQCCaveatSelector = /*#__PURE__*/function (_Component7) {
  _inherits(ImagePanelQCCaveatSelector, _Component7);

  var _super7 = _createSuper(ImagePanelQCCaveatSelector);

  function ImagePanelQCCaveatSelector(props) {
    _classCallCheck(this, ImagePanelQCCaveatSelector);

    return _super7.call(this, props);
  }

  _createClass(ImagePanelQCCaveatSelector, [{
    key: "render",
    value: function render() {
      // Link caveat to MRI Violations if set true
      var mriViolationsLink = null;

      if (this.props.SeriesUID && this.props.Caveat === '1') {
        // If there is a manual caveat that was set, the link
        // will take you to it, even though there might also
        // be a caveat that was set by the MRI piepline (i.e
        // not manual). Note that manual caveat are always
        // resolved
        if (this.props.CaveatViolationsResolvedID) {
          mriViolationsLink = '/mri_violations/resolved_violations/?' + 'SeriesUID=' + this.props.SeriesUID + '&filter=true';
        }
      }

      return /*#__PURE__*/react__WEBPACK_IMPORTED_MODULE_0___default.a.createElement(ImageQCDropdown, {
        Label: "Caveat",
        FormName: "caveat",
        FileID: this.props.FileID,
        editable: this.props.HasQCPerm,
        options: {
          '': '',
          '1': 'True',
          '0': 'False'
        },
        defaultValue: this.props.Caveat,
        url: mriViolationsLink
      });
    }
  }]);

  return ImagePanelQCCaveatSelector;
}(react__WEBPACK_IMPORTED_MODULE_0__["Component"]);

ImagePanelQCCaveatSelector.propTypes = {
  FileID: prop_types__WEBPACK_IMPORTED_MODULE_1___default.a.string,
  HasQCPerm: prop_types__WEBPACK_IMPORTED_MODULE_1___default.a.string,
  SeriesUID: prop_types__WEBPACK_IMPORTED_MODULE_1___default.a.string,
  Caveat: prop_types__WEBPACK_IMPORTED_MODULE_1___default.a.string,
  CaveatViolationsResolvedID: prop_types__WEBPACK_IMPORTED_MODULE_1___default.a.string
};

var ImagePanelQCSNRValue = /*#__PURE__*/function (_Component8) {
  _inherits(ImagePanelQCSNRValue, _Component8);

  var _super8 = _createSuper(ImagePanelQCSNRValue);

  function ImagePanelQCSNRValue(props) {
    _classCallCheck(this, ImagePanelQCSNRValue);

    return _super8.call(this, props);
  }

  _createClass(ImagePanelQCSNRValue, [{
    key: "render",
    value: function render() {
      return /*#__PURE__*/react__WEBPACK_IMPORTED_MODULE_0___default.a.createElement(ImageQCStatic, {
        Label: "SNR",
        FormName: "snr",
        FileID: this.props.FileID,
        defaultValue: this.props.SNR
      });
    }
  }]);

  return ImagePanelQCSNRValue;
}(react__WEBPACK_IMPORTED_MODULE_0__["Component"]);

ImagePanelQCSNRValue.propTypes = {
  FileID: prop_types__WEBPACK_IMPORTED_MODULE_1___default.a.string,
  SNR: prop_types__WEBPACK_IMPORTED_MODULE_1___default.a.string
};

var ImagePanelQCPanel = /*#__PURE__*/function (_Component9) {
  _inherits(ImagePanelQCPanel, _Component9);

  var _super9 = _createSuper(ImagePanelQCPanel);

  function ImagePanelQCPanel(props) {
    _classCallCheck(this, ImagePanelQCPanel);

    return _super9.call(this, props);
  }

  _createClass(ImagePanelQCPanel, [{
    key: "render",
    value: function render() {
      return /*#__PURE__*/react__WEBPACK_IMPORTED_MODULE_0___default.a.createElement("div", {
        className: "form-group"
      }, /*#__PURE__*/react__WEBPACK_IMPORTED_MODULE_0___default.a.createElement(ImagePanelQCStatusSelector, {
        FileID: this.props.FileID,
        HasQCPerm: this.props.HasQCPerm,
        QCStatus: this.props.QCStatus,
        FileNew: this.props.FileNew
      }), /*#__PURE__*/react__WEBPACK_IMPORTED_MODULE_0___default.a.createElement(ImagePanelQCSelectedSelector, {
        FileID: this.props.FileID,
        HasQCPerm: this.props.HasQCPerm,
        Selected: this.props.Selected
      }), /*#__PURE__*/react__WEBPACK_IMPORTED_MODULE_0___default.a.createElement(ImagePanelQCCaveatSelector, {
        FileID: this.props.FileID,
        HasQCPerm: this.props.HasQCPerm,
        Caveat: this.props.Caveat,
        SeriesUID: this.props.SeriesUID,
        CaveatViolationsResolvedID: this.props.CaveatViolationsResolvedID
      }), /*#__PURE__*/react__WEBPACK_IMPORTED_MODULE_0___default.a.createElement(ImagePanelQCSNRValue, {
        FileID: this.props.FileID,
        SNR: this.props.SNR
      }));
    }
  }]);

  return ImagePanelQCPanel;
}(react__WEBPACK_IMPORTED_MODULE_0__["Component"]);

ImagePanelQCPanel.propTypes = {
  FileID: prop_types__WEBPACK_IMPORTED_MODULE_1___default.a.string,
  HasQCPerm: prop_types__WEBPACK_IMPORTED_MODULE_1___default.a.string,
  QCStatus: prop_types__WEBPACK_IMPORTED_MODULE_1___default.a.string,
  FileNew: prop_types__WEBPACK_IMPORTED_MODULE_1___default.a.string,
  Selected: prop_types__WEBPACK_IMPORTED_MODULE_1___default.a.string,
  Caveat: prop_types__WEBPACK_IMPORTED_MODULE_1___default.a.string,
  SeriesUID: prop_types__WEBPACK_IMPORTED_MODULE_1___default.a.string,
  SNR: prop_types__WEBPACK_IMPORTED_MODULE_1___default.a.string,
  CaveatViolationsResolvedID: prop_types__WEBPACK_IMPORTED_MODULE_1___default.a.string
};

var DownloadButton = /*#__PURE__*/function (_Component10) {
  _inherits(DownloadButton, _Component10);

  var _super10 = _createSuper(DownloadButton);

  function DownloadButton(props) {
    _classCallCheck(this, DownloadButton);

    return _super10.call(this, props);
  }

  _createClass(DownloadButton, [{
    key: "render",
    value: function render() {
      if (!this.props.FileName || this.props.FileName === '') {
        return /*#__PURE__*/react__WEBPACK_IMPORTED_MODULE_0___default.a.createElement("span", null);
      }

      var style = {
        margin: 6
      };
      return /*#__PURE__*/react__WEBPACK_IMPORTED_MODULE_0___default.a.createElement("a", {
        href: this.props.BaseURL + '/mri/jiv/get_file.php?file=' + this.props.FileName,
        className: "btn btn-default",
        style: style
      }, /*#__PURE__*/react__WEBPACK_IMPORTED_MODULE_0___default.a.createElement("span", {
        className: "glyphicon glyphicon-download-alt"
      }), /*#__PURE__*/react__WEBPACK_IMPORTED_MODULE_0___default.a.createElement("span", {
        className: "hidden-xs"
      }, this.props.Label));
    }
  }]);

  return DownloadButton;
}(react__WEBPACK_IMPORTED_MODULE_0__["Component"]);

DownloadButton.propTypes = {
  FileName: prop_types__WEBPACK_IMPORTED_MODULE_1___default.a.string,
  BaseURL: prop_types__WEBPACK_IMPORTED_MODULE_1___default.a.string,
  Label: prop_types__WEBPACK_IMPORTED_MODULE_1___default.a.string
};

var ImageQCCommentsButton = /*#__PURE__*/function (_Component11) {
  _inherits(ImageQCCommentsButton, _Component11);

  var _super11 = _createSuper(ImageQCCommentsButton);

  function ImageQCCommentsButton(props) {
    var _this;

    _classCallCheck(this, ImageQCCommentsButton);

    _this = _super11.call(this, props);
    _this.openWindowHandler = _this.openWindowHandler.bind(_assertThisInitialized(_this));
    return _this;
  } // IBIS SPECIFIC OVERRIDE CODE
  // OVERRIDE: modify url link.


  _createClass(ImageQCCommentsButton, [{
    key: "openWindowHandler",
    value: function openWindowHandler(e) {
      e.preventDefault();
      window.open(this.props.BaseURL + '/feedback_mri_popup_ibis.php?fileID=' + this.props.FileID + '&sessionID=' + this.props.SessionID, 'feedback_mri', 'width=500,height=800,toolbar=no,location=no,' + 'status=yes,scrollbars=yes,resizable=yes');
    } // IBIS SPECIFIC OVERRIDE CODE ENDS HERE

  }, {
    key: "render",
    value: function render() {
      if (!this.props.FileID || this.props.FileID === '') {
        return /*#__PURE__*/react__WEBPACK_IMPORTED_MODULE_0___default.a.createElement("span", null);
      }

      return /*#__PURE__*/react__WEBPACK_IMPORTED_MODULE_0___default.a.createElement("a", {
        className: "btn btn-default",
        href: "#noID",
        onClick: this.openWindowHandler
      }, /*#__PURE__*/react__WEBPACK_IMPORTED_MODULE_0___default.a.createElement("span", {
        className: "text-default"
      }, /*#__PURE__*/react__WEBPACK_IMPORTED_MODULE_0___default.a.createElement("span", {
        className: "glyphicon glyphicon-pencil"
      }), /*#__PURE__*/react__WEBPACK_IMPORTED_MODULE_0___default.a.createElement("span", {
        className: "hidden-xs"
      }, "QC Comments")));
    }
  }]);

  return ImageQCCommentsButton;
}(react__WEBPACK_IMPORTED_MODULE_0__["Component"]); // IBIS SPECIFIC OVERRIDE CODE
// OVERRIDE: add SessionID prop.


ImageQCCommentsButton.propTypes = {
  FileID: prop_types__WEBPACK_IMPORTED_MODULE_1___default.a.string,
  BaseURL: prop_types__WEBPACK_IMPORTED_MODULE_1___default.a.string,
  SessionID: prop_types__WEBPACK_IMPORTED_MODULE_1___default.a.string
}; // IBIS SPECIFIC OVERRIDE CODE ENDS HERE

var LongitudinalViewButton = /*#__PURE__*/function (_Component12) {
  _inherits(LongitudinalViewButton, _Component12);

  var _super12 = _createSuper(LongitudinalViewButton);

  function LongitudinalViewButton(props) {
    var _this2;

    _classCallCheck(this, LongitudinalViewButton);

    _this2 = _super12.call(this, props);
    _this2.openWindowHandler = _this2.openWindowHandler.bind(_assertThisInitialized(_this2));
    return _this2;
  }

  _createClass(LongitudinalViewButton, [{
    key: "openWindowHandler",
    value: function openWindowHandler(e) {
      e.preventDefault();
      window.open(this.props.BaseURL + '/brainbrowser/?minc_id=[' + this.props.OtherTimepoints + ']', 'BrainBrowser Volume Viewer', 'location = 0,width = auto, height = auto, scrollbars=yes');
    }
  }, {
    key: "render",
    value: function render() {
      if (!this.props.FileID || this.props.FileID === '') {
        return /*#__PURE__*/react__WEBPACK_IMPORTED_MODULE_0___default.a.createElement("span", null);
      }

      return /*#__PURE__*/react__WEBPACK_IMPORTED_MODULE_0___default.a.createElement("a", {
        className: "btn btn-default",
        href: "#noID",
        onClick: this.openWindowHandler
      }, /*#__PURE__*/react__WEBPACK_IMPORTED_MODULE_0___default.a.createElement("span", {
        className: "text-default"
      }, /*#__PURE__*/react__WEBPACK_IMPORTED_MODULE_0___default.a.createElement("span", {
        className: "glyphicon glyphicon-eye-open"
      }), /*#__PURE__*/react__WEBPACK_IMPORTED_MODULE_0___default.a.createElement("span", {
        className: "hidden-xs"
      }, "Longitudinal View")));
    }
  }]);

  return LongitudinalViewButton;
}(react__WEBPACK_IMPORTED_MODULE_0__["Component"]);

LongitudinalViewButton.propTypes = {
  FileID: prop_types__WEBPACK_IMPORTED_MODULE_1___default.a.string,
  BaseURL: prop_types__WEBPACK_IMPORTED_MODULE_1___default.a.string,
  OtherTimepoints: prop_types__WEBPACK_IMPORTED_MODULE_1___default.a.string
};

var ImageDownloadButtons = /*#__PURE__*/function (_Component13) {
  _inherits(ImageDownloadButtons, _Component13);

  var _super13 = _createSuper(ImageDownloadButtons);

  function ImageDownloadButtons(props) {
    _classCallCheck(this, ImageDownloadButtons);

    return _super13.call(this, props);
  }

  _createClass(ImageDownloadButtons, [{
    key: "render",
    value: function render() {
      return /*#__PURE__*/react__WEBPACK_IMPORTED_MODULE_0___default.a.createElement("div", {
        className: "row mri-second-row-panel col-xs-12"
      }, /*#__PURE__*/react__WEBPACK_IMPORTED_MODULE_0___default.a.createElement(ImageQCCommentsButton, {
        FileID: this.props.FileID,
        BaseURL: this.props.BaseURL,
        SessionID: this.props.SessionID
      }), /*#__PURE__*/react__WEBPACK_IMPORTED_MODULE_0___default.a.createElement(DownloadButton, {
        FileName: this.props.Fullname,
        Label: "Download Minc",
        BaseURL: this.props.BaseURL
      }), /*#__PURE__*/react__WEBPACK_IMPORTED_MODULE_0___default.a.createElement(DownloadButton, {
        FileName: this.props.XMLProtocol,
        BaseURL: this.props.BaseURL,
        Label: "Download XML Protocol"
      }), /*#__PURE__*/react__WEBPACK_IMPORTED_MODULE_0___default.a.createElement(DownloadButton, {
        FileName: this.props.XMLReport,
        BaseURL: this.props.BaseURL,
        Label: "Download XML Report"
      }), /*#__PURE__*/react__WEBPACK_IMPORTED_MODULE_0___default.a.createElement(DownloadButton, {
        FileName: this.props.NrrdFile,
        BaseURL: this.props.BaseURL,
        Label: "Download NRRD"
      }), /*#__PURE__*/react__WEBPACK_IMPORTED_MODULE_0___default.a.createElement(LongitudinalViewButton, {
        FileID: this.props.FileID,
        BaseURL: this.props.BaseURL,
        OtherTimepoints: this.props.OtherTimepoints
      }));
    }
  }]);

  return ImageDownloadButtons;
}(react__WEBPACK_IMPORTED_MODULE_0__["Component"]); // IBIS SPECIFIC OVERRIDE CODE
// OVERRIDE: add SessionID prop.


ImageDownloadButtons.propTypes = {
  FileID: prop_types__WEBPACK_IMPORTED_MODULE_1___default.a.string,
  BaseURL: prop_types__WEBPACK_IMPORTED_MODULE_1___default.a.string,
  Fullname: prop_types__WEBPACK_IMPORTED_MODULE_1___default.a.string,
  XMLProtocol: prop_types__WEBPACK_IMPORTED_MODULE_1___default.a.string,
  XMLReport: prop_types__WEBPACK_IMPORTED_MODULE_1___default.a.string,
  NrrdFile: prop_types__WEBPACK_IMPORTED_MODULE_1___default.a.string,
  OtherTimepoints: prop_types__WEBPACK_IMPORTED_MODULE_1___default.a.string,
  SessionID: prop_types__WEBPACK_IMPORTED_MODULE_1___default.a.string
}; // IBIS SPECIFIC OVERRIDE CODE ENDS HERE

var ImagePanelBody = /*#__PURE__*/function (_Component14) {
  _inherits(ImagePanelBody, _Component14);

  var _super14 = _createSuper(ImagePanelBody);

  function ImagePanelBody(props) {
    var _this3;

    _classCallCheck(this, ImagePanelBody);

    _this3 = _super14.call(this, props);
    _this3.openWindowHandler = _this3.openWindowHandler.bind(_assertThisInitialized(_this3));
    return _this3;
  }

  _createClass(ImagePanelBody, [{
    key: "openWindowHandler",
    value: function openWindowHandler(e) {
      e.preventDefault();
      window.open(this.props.BaseURL + '/brainbrowser/?minc_id=[' + this.props.FileID + ']', 'BrainBrowser Volume Viewer', 'location = 0,width = auto, height = auto, scrollbars=yes');
    }
  }, {
    key: "render",
    value: function render() {
      return /*#__PURE__*/react__WEBPACK_IMPORTED_MODULE_0___default.a.createElement("div", {
        className: "panel-body"
      }, /*#__PURE__*/react__WEBPACK_IMPORTED_MODULE_0___default.a.createElement("div", {
        className: "row"
      }, /*#__PURE__*/react__WEBPACK_IMPORTED_MODULE_0___default.a.createElement("div", {
        className: "col-xs-9 imaging_browser_pic"
      }, /*#__PURE__*/react__WEBPACK_IMPORTED_MODULE_0___default.a.createElement("a", {
        href: "#noID",
        onClick: this.openWindowHandler
      }, /*#__PURE__*/react__WEBPACK_IMPORTED_MODULE_0___default.a.createElement("img", {
        className: "img-checkpic img-responsive",
        src: this.props.Checkpic
      }))), /*#__PURE__*/react__WEBPACK_IMPORTED_MODULE_0___default.a.createElement("div", {
        className: "col-xs-3 mri-right-panel"
      }, /*#__PURE__*/react__WEBPACK_IMPORTED_MODULE_0___default.a.createElement(ImagePanelQCPanel, {
        FileID: this.props.FileID,
        FileNew: this.props.FileNew,
        HasQCPerm: this.props.HasQCPerm,
        QCStatus: this.props.QCStatus,
        Caveat: this.props.Caveat,
        CaveatViolationsResolvedID: this.props.CaveatViolationsResolvedID,
        Selected: this.props.Selected,
        SNR: this.props.SNR,
        SeriesUID: this.props.SeriesUID
      }))), /*#__PURE__*/react__WEBPACK_IMPORTED_MODULE_0___default.a.createElement(ImageDownloadButtons, {
        BaseURL: this.props.BaseURL,
        FileID: this.props.FileID,
        Fullname: this.props.Fullname,
        XMLProtocol: this.props.XMLProtocol,
        XMLReport: this.props.XMLReport,
        NrrdFile: this.props.NrrdFile,
        OtherTimepoints: this.props.OtherTimepoints,
        SessionID: this.props.SessionID
      }), this.props.HeadersExpanded ? /*#__PURE__*/react__WEBPACK_IMPORTED_MODULE_0___default.a.createElement(ImagePanelHeadersTable, {
        HeaderInfo: this.props.HeaderInfo
      }) : '');
    }
  }]);

  return ImagePanelBody;
}(react__WEBPACK_IMPORTED_MODULE_0__["Component"]); // IBIS SPECIFIC OVERRIDE CODE
// OVERRIDE: add SessionID prop.


ImagePanelBody.propTypes = {
  FileID: prop_types__WEBPACK_IMPORTED_MODULE_1___default.a.string,
  FileNew: prop_types__WEBPACK_IMPORTED_MODULE_1___default.a.string,
  HasQCPerm: prop_types__WEBPACK_IMPORTED_MODULE_1___default.a.string,
  QCStatus: prop_types__WEBPACK_IMPORTED_MODULE_1___default.a.string,
  Caveat: prop_types__WEBPACK_IMPORTED_MODULE_1___default.a.string,
  Selected: prop_types__WEBPACK_IMPORTED_MODULE_1___default.a.string,
  SNR: prop_types__WEBPACK_IMPORTED_MODULE_1___default.a.string,
  SeriesUID: prop_types__WEBPACK_IMPORTED_MODULE_1___default.a.string,
  BaseURL: prop_types__WEBPACK_IMPORTED_MODULE_1___default.a.string,
  Fullname: prop_types__WEBPACK_IMPORTED_MODULE_1___default.a.string,
  XMLProtocol: prop_types__WEBPACK_IMPORTED_MODULE_1___default.a.string,
  XMLReport: prop_types__WEBPACK_IMPORTED_MODULE_1___default.a.string,
  NrrdFile: prop_types__WEBPACK_IMPORTED_MODULE_1___default.a.string,
  OtherTimepoints: prop_types__WEBPACK_IMPORTED_MODULE_1___default.a.string,
  HeadersExpanded: prop_types__WEBPACK_IMPORTED_MODULE_1___default.a.string,
  Checkpic: prop_types__WEBPACK_IMPORTED_MODULE_1___default.a.string,
  CaveatViolationsResolvedID: prop_types__WEBPACK_IMPORTED_MODULE_1___default.a.string,
  SessionID: prop_types__WEBPACK_IMPORTED_MODULE_1___default.a.string
}; // IBIS SPECIFIC OVERRIDE CODE ENDS HERE

var ImagePanel = /*#__PURE__*/function (_Component15) {
  _inherits(ImagePanel, _Component15);

  var _super15 = _createSuper(ImagePanel);

  function ImagePanel(props) {
    var _this4;

    _classCallCheck(this, ImagePanel);

    _this4 = _super15.call(this, props);
    _this4.state = {
      BodyCollapsed: false,
      HeadersCollapsed: true
    };
    _this4.toggleBody = _this4.toggleBody.bind(_assertThisInitialized(_this4));
    _this4.toggleHeaders = _this4.toggleHeaders.bind(_assertThisInitialized(_this4));
    return _this4;
  }

  _createClass(ImagePanel, [{
    key: "toggleBody",
    value: function toggleBody(e) {
      this.setState({
        BodyCollapsed: !this.state.BodyCollapsed
      });
    }
  }, {
    key: "toggleHeaders",
    value: function toggleHeaders(e) {
      this.setState({
        HeadersCollapsed: !this.state.HeadersCollapsed
      });
    }
  }, {
    key: "render",
    value: function render() {
      return /*#__PURE__*/react__WEBPACK_IMPORTED_MODULE_0___default.a.createElement("div", {
        className: "col-xs-12 col-md-6"
      }, /*#__PURE__*/react__WEBPACK_IMPORTED_MODULE_0___default.a.createElement("div", {
        className: "panel panel-default"
      }, /*#__PURE__*/react__WEBPACK_IMPORTED_MODULE_0___default.a.createElement(ImagePanelHeader, {
        FileID: this.props.FileID,
        Filename: this.props.Filename,
        HeaderInfo: this.props.HeaderInfo,
        QCStatus: this.props.QCStatus,
        onToggleBody: this.toggleBody,
        onToggleHeaders: this.toggleHeaders,
        Expanded: !this.state.BodyCollapsed,
        HeadersExpanded: !this.state.HeadersCollapsed
      }), this.state.BodyCollapsed ? '' : /*#__PURE__*/react__WEBPACK_IMPORTED_MODULE_0___default.a.createElement(ImagePanelBody, {
        BaseURL: this.props.BaseURL,
        FileID: this.props.FileID,
        Filename: this.props.Filename,
        Checkpic: this.props.Checkpic,
        HeadersExpanded: !this.state.HeadersCollapsed,
        HeaderInfo: this.props.HeaderInfo,
        FileNew: this.props.FileNew,
        HasQCPerm: this.props.HasQCPerm,
        QCStatus: this.props.QCStatus,
        Caveat: this.props.Caveat,
        CaveatViolationsResolvedID: this.props.CaveatViolationsResolvedID,
        Selected: this.props.Selected,
        SNR: this.props.SNR,
        Fullname: this.props.Fullname,
        XMLProtocol: this.props.XMLProtocol,
        XMLReport: this.props.XMLReport,
        NrrdFile: this.props.NrrdFile,
        OtherTimepoints: this.props.OtherTimepoints,
        SeriesUID: this.props.SeriesUID,
        SessionID: this.props.SessionID
      })));
    }
  }]);

  return ImagePanel;
}(react__WEBPACK_IMPORTED_MODULE_0__["Component"]); // IBIS SPECIFIC OVERRIDE CODE
// OVERRIDE: add SessionID, Filename, HeaderInfo props.


ImagePanel.propTypes = {
  FileID: prop_types__WEBPACK_IMPORTED_MODULE_1___default.a.string,
  FileNew: prop_types__WEBPACK_IMPORTED_MODULE_1___default.a.string,
  HasQCPerm: prop_types__WEBPACK_IMPORTED_MODULE_1___default.a.string,
  QCStatus: prop_types__WEBPACK_IMPORTED_MODULE_1___default.a.string,
  Caveat: prop_types__WEBPACK_IMPORTED_MODULE_1___default.a.string,
  Selected: prop_types__WEBPACK_IMPORTED_MODULE_1___default.a.string,
  SNR: prop_types__WEBPACK_IMPORTED_MODULE_1___default.a.string,
  SeriesUID: prop_types__WEBPACK_IMPORTED_MODULE_1___default.a.string,
  BaseURL: prop_types__WEBPACK_IMPORTED_MODULE_1___default.a.string,
  Fullname: prop_types__WEBPACK_IMPORTED_MODULE_1___default.a.string,
  XMLProtocol: prop_types__WEBPACK_IMPORTED_MODULE_1___default.a.string,
  XMLReport: prop_types__WEBPACK_IMPORTED_MODULE_1___default.a.string,
  NrrdFile: prop_types__WEBPACK_IMPORTED_MODULE_1___default.a.string,
  OtherTimepoints: prop_types__WEBPACK_IMPORTED_MODULE_1___default.a.string,
  HeadersExpanded: prop_types__WEBPACK_IMPORTED_MODULE_1___default.a.string,
  Checkpic: prop_types__WEBPACK_IMPORTED_MODULE_1___default.a.string,
  CaveatViolationsResolvedID: prop_types__WEBPACK_IMPORTED_MODULE_1___default.a.string,
  SessionID: prop_types__WEBPACK_IMPORTED_MODULE_1___default.a.string,
  Filename: prop_types__WEBPACK_IMPORTED_MODULE_1___default.a.string,
  HeaderInfo: prop_types__WEBPACK_IMPORTED_MODULE_1___default.a.object
}; // IBIS SPECIFIC OVERRIDE CODE ENDS HERE

var RImagePanel = /*#__PURE__*/react__WEBPACK_IMPORTED_MODULE_0___default.a.createFactory(ImagePanel);
window.ImagePanelHeader = ImagePanelHeader;
window.ImagePanelHeadersTable = ImagePanelHeadersTable;
window.ImageQCDropdown = ImageQCDropdown;
window.ImageQCStatic = ImageQCStatic;
window.ImagePanelQCStatusSelector = ImagePanelQCStatusSelector;
window.ImagePanelQCSelectedSelector = ImagePanelQCSelectedSelector;
window.ImagePanelQCCaveatSelector = ImagePanelQCCaveatSelector;
window.ImagePanelQCSNRValue = ImagePanelQCSNRValue;
window.ImagePanelQCPanel = ImagePanelQCPanel;
window.DownloadButton = DownloadButton;
window.ImageQCCommentsButton = ImageQCCommentsButton;
window.LongitudinalViewButton = LongitudinalViewButton;
window.ImageDownloadButtons = ImageDownloadButtons;
window.ImagePanelBody = ImagePanelBody;
window.RImagePanel = RImagePanel;
/* harmony default export */ __webpack_exports__["default"] = ({
  ImagePanelHeader: ImagePanelHeader,
  ImagePanelHeadersTable: ImagePanelHeadersTable,
  ImageQCDropdown: ImageQCDropdown,
  ImageQCStatic: ImageQCStatic,
  ImagePanelQCStatusSelector: ImagePanelQCStatusSelector,
  ImagePanelQCSelectedSelector: ImagePanelQCSelectedSelector,
  ImagePanelQCCaveatSelector: ImagePanelQCCaveatSelector,
  ImagePanelQCSNRValue: ImagePanelQCSNRValue,
  ImagePanelQCPanel: ImagePanelQCPanel,
  DownloadButton: DownloadButton,
  ImageQCCommentsButton: ImageQCCommentsButton,
  LongitudinalViewButton: LongitudinalViewButton,
  ImageDownloadButtons: ImageDownloadButtons,
  ImagePanelBody: ImagePanelBody,
  RImagePanel: RImagePanel
});

/***/ }),
/* 1 */
/***/ (function(module, exports) {

(function() { module.exports = window["React"]; }());

/***/ }),
/* 2 */
/***/ (function(module, exports, __webpack_require__) {

/**
 * Copyright (c) 2013-present, Facebook, Inc.
 *
 * This source code is licensed under the MIT license found in the
 * LICENSE file in the root directory of this source tree.
 */

if (true) {
  var ReactIs = __webpack_require__(3);

  // By explicitly using `prop-types` you are opting into new development behavior.
  // http://fb.me/prop-types-in-prod
  var throwOnDirectAccess = true;
  module.exports = __webpack_require__(5)(ReactIs.isElement, throwOnDirectAccess);
} else {}


/***/ }),
/* 3 */
/***/ (function(module, exports, __webpack_require__) {

"use strict";


if (false) {} else {
  module.exports = __webpack_require__(4);
}


/***/ }),
/* 4 */
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
/* 5 */
/***/ (function(module, exports, __webpack_require__) {

"use strict";
/**
 * Copyright (c) 2013-present, Facebook, Inc.
 *
 * This source code is licensed under the MIT license found in the
 * LICENSE file in the root directory of this source tree.
 */



var ReactIs = __webpack_require__(3);
var assign = __webpack_require__(6);

var ReactPropTypesSecret = __webpack_require__(7);
var checkPropTypes = __webpack_require__(8);

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
/* 6 */
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
/* 7 */
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
/* 8 */
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
  var ReactPropTypesSecret = __webpack_require__(7);
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


/***/ })
/******/ ]);
//# sourceMappingURL=ImagePanel.js.map