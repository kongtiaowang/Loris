window["lorisjs"] = window["lorisjs"] || {}; window["lorisjs"]["survey_module"] = window["lorisjs"]["survey_module"] || {}; window["lorisjs"]["survey_module"]["DirectEntry"] =
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
/* harmony import */ var _DirectEntryForm__WEBPACK_IMPORTED_MODULE_0__ = __webpack_require__(1);
function _typeof(obj) { "@babel/helpers - typeof"; if (typeof Symbol === "function" && typeof Symbol.iterator === "symbol") { _typeof = function _typeof(obj) { return typeof obj; }; } else { _typeof = function _typeof(obj) { return obj && typeof Symbol === "function" && obj.constructor === Symbol && obj !== Symbol.prototype ? "symbol" : typeof obj; }; } return _typeof(obj); }

function _toConsumableArray(arr) { return _arrayWithoutHoles(arr) || _iterableToArray(arr) || _unsupportedIterableToArray(arr) || _nonIterableSpread(); }

function _nonIterableSpread() { throw new TypeError("Invalid attempt to spread non-iterable instance.\nIn order to be iterable, non-array objects must have a [Symbol.iterator]() method."); }

function _iterableToArray(iter) { if (typeof Symbol !== "undefined" && iter[Symbol.iterator] != null || iter["@@iterator"] != null) return Array.from(iter); }

function _arrayWithoutHoles(arr) { if (Array.isArray(arr)) return _arrayLikeToArray(arr); }

function _defineProperty(obj, key, value) { if (key in obj) { Object.defineProperty(obj, key, { value: value, enumerable: true, configurable: true, writable: true }); } else { obj[key] = value; } return obj; }

function _createForOfIteratorHelper(o, allowArrayLike) { var it = typeof Symbol !== "undefined" && o[Symbol.iterator] || o["@@iterator"]; if (!it) { if (Array.isArray(o) || (it = _unsupportedIterableToArray(o)) || allowArrayLike && o && typeof o.length === "number") { if (it) o = it; var i = 0; var F = function F() {}; return { s: F, n: function n() { if (i >= o.length) return { done: true }; return { done: false, value: o[i++] }; }, e: function e(_e) { throw _e; }, f: F }; } throw new TypeError("Invalid attempt to iterate non-iterable instance.\nIn order to be iterable, non-array objects must have a [Symbol.iterator]() method."); } var normalCompletion = true, didErr = false, err; return { s: function s() { it = it.call(o); }, n: function n() { var step = it.next(); normalCompletion = step.done; return step; }, e: function e(_e2) { didErr = true; err = _e2; }, f: function f() { try { if (!normalCompletion && it["return"] != null) it["return"](); } finally { if (didErr) throw err; } } }; }

function _unsupportedIterableToArray(o, minLen) { if (!o) return; if (typeof o === "string") return _arrayLikeToArray(o, minLen); var n = Object.prototype.toString.call(o).slice(8, -1); if (n === "Object" && o.constructor) n = o.constructor.name; if (n === "Map" || n === "Set") return Array.from(o); if (n === "Arguments" || /^(?:Ui|I)nt(?:8|16|32)(?:Clamped)?Array$/.test(n)) return _arrayLikeToArray(o, minLen); }

function _arrayLikeToArray(arr, len) { if (len == null || len > arr.length) len = arr.length; for (var i = 0, arr2 = new Array(len); i < len; i++) { arr2[i] = arr[i]; } return arr2; }

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
  _inherits(DirectEntry, _React$Component);

  var _super = _createSuper(DirectEntry);

  function DirectEntry(props) {
    var _this;

    _classCallCheck(this, DirectEntry);

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

    _this.nextPage = _this.nextPage.bind(_assertThisInitialized(_this));
    _this.prevPage = _this.prevPage.bind(_assertThisInitialized(_this));
    _this.updateAnswer = _this.updateAnswer.bind(_assertThisInitialized(_this));
    _this.setupPageValues = _this.setupPageValues.bind(_assertThisInitialized(_this));
    _this.submit = _this.submit.bind(_assertThisInitialized(_this));
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
      api_url: url.origin + '/survey_module/ajax/survey_api.php' + url.search,
      submitState: 0 // 0 = not submitted, 1 = successfull submit, 2 = already submitted, 3 = error in form submit

    };
    return _this;
  }

  _createClass(DirectEntry, [{
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
          that.setState({
            submitState: 1
          });
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
        DirectEntryFormElements = /*#__PURE__*/React.createElement(_DirectEntryForm__WEBPACK_IMPORTED_MODULE_0__["default"], {
          elements: this.state.InstrumentJSON.Elements[this.state.page].Elements,
          values: this.state.values,
          updateAnswer: this.updateAnswer,
          errors: this.state.errors
        });
      } else {
        DirectEntryFormElements = /*#__PURE__*/React.createElement(_DirectEntryForm__WEBPACK_IMPORTED_MODULE_0__["default"], {
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
      }, /*#__PURE__*/React.createElement("span", _defineProperty({
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

      return (_ref = []).concat.apply(_ref, _toConsumableArray(root)).filter(function (i) {
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
  _inherits(ReviewPage, _React$Component2);

  var _super2 = _createSuper(ReviewPage);

  function ReviewPage(props) {
    _classCallCheck(this, ReviewPage);

    return _super2.call(this, props);
  }

  _createClass(ReviewPage, [{
    key: "render",
    value: function render() {
      var questions = this.props.reviewData.questions.map(function (element) {
        return /*#__PURE__*/React.createElement("tr", {
          className: "reviewPage"
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
/* 1 */
/***/ (function(module, __webpack_exports__, __webpack_require__) {

"use strict";
__webpack_require__.r(__webpack_exports__);
/* harmony import */ var _GroupElement_js__WEBPACK_IMPORTED_MODULE_0__ = __webpack_require__(2);
/* harmony import */ var _Markdown__WEBPACK_IMPORTED_MODULE_1__ = __webpack_require__(3);
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
  _inherits(NotImplement, _React$Component);

  var _super = _createSuper(NotImplement);

  function NotImplement(props) {
    _classCallCheck(this, NotImplement);

    return _super.call(this, props);
  }

  _createClass(NotImplement, [{
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
  _inherits(NotSupported, _React$Component2);

  var _super2 = _createSuper(NotSupported);

  function NotSupported(props) {
    _classCallCheck(this, NotSupported);

    return _super2.call(this, props);
  }

  _createClass(NotSupported, [{
    key: "render",
    value: function render() {
      return /*#__PURE__*/React.createElement("div", null, this.props.element.Type, " is not supported by browser");
    }
  }]);

  return NotSupported;
}(React.Component);
/* eslint-enable */


var DirectEntryFormElement = /*#__PURE__*/function (_React$Component3) {
  _inherits(DirectEntryFormElement, _React$Component3);

  var _super3 = _createSuper(DirectEntryFormElement);

  function DirectEntryFormElement(props) {
    _classCallCheck(this, DirectEntryFormElement);

    return _super3.call(this, props);
  }

  _createClass(DirectEntryFormElement, [{
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
          element = /*#__PURE__*/React.createElement(_GroupElement_js__WEBPACK_IMPORTED_MODULE_0__["default"], {
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
  _inherits(Page, _React$Component4);

  var _super4 = _createSuper(Page);

  function Page(props) {
    _classCallCheck(this, Page);

    return _super4.call(this, props);
  }

  _createClass(Page, [{
    key: "render",
    value: function render() {
      var _this = this;

      var DirectEntryFormElements = this.props.elements.map(function (element) {
        return /*#__PURE__*/React.createElement(DirectEntryFormElement, {
          element: element,
          values: _this.props.values,
          updateAnswer: _this.props.updateAnswer,
          errors: _this.props.errors
        });
      });
      return /*#__PURE__*/React.createElement("div", null, DirectEntryFormElements);
    }
  }]);

  return Page;
}(React.Component);

var SelectElement = /*#__PURE__*/function (_React$Component5) {
  _inherits(SelectElement, _React$Component5);

  var _super5 = _createSuper(SelectElement);

  function SelectElement(props) {
    var _this2;

    _classCallCheck(this, SelectElement);

    _this2 = _super5.call(this, props);
    _this2.state = {
      value: ''
    };
    return _this2;
  }

  _createClass(SelectElement, [{
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

        var checked = void 0;

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
          onClick: this.onSelect.bind(this, key)
        }, /*#__PURE__*/React.createElement("div", {
          className: "selectBox"
        }, /*#__PURE__*/React.createElement("label", {
          className: "btn btn-default btn-circle"
        }, checked)), /*#__PURE__*/React.createElement("div", {
          className: "selectOption"
        }, /*#__PURE__*/React.createElement(_Markdown__WEBPACK_IMPORTED_MODULE_1__["default"], {
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
        }, /*#__PURE__*/React.createElement(_Markdown__WEBPACK_IMPORTED_MODULE_1__["default"], {
          content: this.props.element.Description
        }));
      }

      return /*#__PURE__*/React.createElement("div", null, description, element);
    }
  }]);

  return SelectElement;
}(React.Component);

var TextElement = /*#__PURE__*/function (_React$Component6) {
  _inherits(TextElement, _React$Component6);

  var _super6 = _createSuper(TextElement);

  function TextElement(props) {
    var _this3;

    _classCallCheck(this, TextElement);

    _this3 = _super6.call(this, props);
    _this3.updateText = _this3.updateText.bind(_assertThisInitialized(_this3));
    return _this3;
  }

  _createClass(TextElement, [{
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
        }, /*#__PURE__*/React.createElement(_Markdown__WEBPACK_IMPORTED_MODULE_1__["default"], {
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
  _inherits(DateElement, _React$Component7);

  var _super7 = _createSuper(DateElement);

  function DateElement(props) {
    var _this4;

    _classCallCheck(this, DateElement);

    _this4 = _super7.call(this, props);
    _this4.updateDate = _this4.updateDate.bind(_assertThisInitialized(_this4));
    return _this4;
  }

  _createClass(DateElement, [{
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
        }, /*#__PURE__*/React.createElement(_Markdown__WEBPACK_IMPORTED_MODULE_1__["default"], {
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
  _inherits(LabelElement, _React$Component8);

  var _super8 = _createSuper(LabelElement);

  function LabelElement(props) {
    _classCallCheck(this, LabelElement);

    return _super8.call(this, props);
  }

  _createClass(LabelElement, [{
    key: "render",
    value: function render() {
      var description = '';

      if (!!this.props.element.Description) {
        description = /*#__PURE__*/React.createElement("h3", {
          className: "col-xs-12 field_question"
        }, /*#__PURE__*/React.createElement(_Markdown__WEBPACK_IMPORTED_MODULE_1__["default"], {
          content: this.props.element.Description
        }));
      }

      return /*#__PURE__*/React.createElement("div", null, description);
    }
  }]);

  return LabelElement;
}(React.Component);

var HeaderElement = /*#__PURE__*/function (_React$Component9) {
  _inherits(HeaderElement, _React$Component9);

  var _super9 = _createSuper(HeaderElement);

  function HeaderElement(props) {
    _classCallCheck(this, HeaderElement);

    return _super9.call(this, props);
  }

  _createClass(HeaderElement, [{
    key: "render",
    value: function render() {
      var element; // eslint-disable-next-line camelcase

      var score_header = this.props.element.Description;
      var str = score_header.toLowerCase();

      if (str.includes('score')) {
        element = /*#__PURE__*/React.createElement("h1", null);
      } else {
        element = /*#__PURE__*/React.createElement("h1", null, /*#__PURE__*/React.createElement(_Markdown__WEBPACK_IMPORTED_MODULE_1__["default"], {
          content: this.props.element.Description
        }));
      }

      return /*#__PURE__*/React.createElement("div", null, element);
    }
  }]);

  return HeaderElement;
}(React.Component);

var AdvcheckboxElement = /*#__PURE__*/function (_React$Component10) {
  _inherits(AdvcheckboxElement, _React$Component10);

  var _super10 = _createSuper(AdvcheckboxElement);

  function AdvcheckboxElement(props) {
    var _this5;

    _classCallCheck(this, AdvcheckboxElement);

    _this5 = _super10.call(this, props);
    _this5.state = {
      value: ''
    };
    return _this5;
  }

  _createClass(AdvcheckboxElement, [{
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
      var checked = null;

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
        description = /*#__PURE__*/React.createElement("div", {
          className: classInfo
        }, /*#__PURE__*/React.createElement(_Markdown__WEBPACK_IMPORTED_MODULE_1__["default"], {
          content: this.props.element.Description
        }));
      }

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
/* 2 */
/***/ (function(module, __webpack_exports__, __webpack_require__) {

"use strict";
__webpack_require__.r(__webpack_exports__);
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

var GroupElement = /*#__PURE__*/function (_React$Component) {
  _inherits(GroupElement, _React$Component);

  var _super = _createSuper(GroupElement);

  function GroupElement(props) {
    _classCallCheck(this, GroupElement);

    return _super.call(this, props);
  }

  _createClass(GroupElement, [{
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
  _inherits(ElementGroup, _React$Component2);

  var _super2 = _createSuper(ElementGroup);

  function ElementGroup(props) {
    _classCallCheck(this, ElementGroup);

    return _super2.call(this, props);
  }

  _createClass(ElementGroup, [{
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
          errorMessage: errorMessage
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
        className: "col-xs-12"
      }, description, elements);
    }
  }]);

  return ElementGroup;
}(React.Component);

var GroupDateElement = /*#__PURE__*/function (_React$Component3) {
  _inherits(GroupDateElement, _React$Component3);

  var _super3 = _createSuper(GroupDateElement);

  function GroupDateElement(props) {
    var _this;

    _classCallCheck(this, GroupDateElement);

    _this = _super3.call(this, props);
    _this.updateValue = _this.updateValue.bind(_assertThisInitialized(_this));
    return _this;
  }

  _createClass(GroupDateElement, [{
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
  _inherits(GroupTimeElement, _React$Component4);

  var _super4 = _createSuper(GroupTimeElement);

  function GroupTimeElement(props) {
    var _this2;

    _classCallCheck(this, GroupTimeElement);

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

    _this2.updateValue = _this2.updateValue.bind(_assertThisInitialized(_this2));
    return _this2;
  }

  _createClass(GroupTimeElement, [{
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
  _inherits(BaseElement, _React$Component5);

  var _super5 = _createSuper(BaseElement);

  function BaseElement(props) {
    var _this3;

    _classCallCheck(this, BaseElement);

    _this3 = _super5.call(this, props);
    _this3.updateValue = _this3.updateValue.bind(_assertThisInitialized(_this3));
    return _this3;
  }

  _createClass(BaseElement, [{
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
              value: key
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
          var checked = null;

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
/* 3 */
/***/ (function(module, __webpack_exports__, __webpack_require__) {

"use strict";
__webpack_require__.r(__webpack_exports__);
/* harmony import */ var react__WEBPACK_IMPORTED_MODULE_0__ = __webpack_require__(4);
/* harmony import */ var react__WEBPACK_IMPORTED_MODULE_0___default = /*#__PURE__*/__webpack_require__.n(react__WEBPACK_IMPORTED_MODULE_0__);
/* harmony import */ var prop_types__WEBPACK_IMPORTED_MODULE_1__ = __webpack_require__(5);
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
  _inherits(Markdown, _Component);

  var _super = _createSuper(Markdown);

  function Markdown() {
    _classCallCheck(this, Markdown);

    return _super.apply(this, arguments);
  }

  _createClass(Markdown, [{
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
              paragraphs[i] = /*#__PURE__*/react__WEBPACK_IMPORTED_MODULE_0___default.a.createElement("h6", {
                key: i + '_help_editor_h6'
              }, paragraphs[i]);
              break;

            case 5:
              paragraphs[i] = /*#__PURE__*/react__WEBPACK_IMPORTED_MODULE_0___default.a.createElement("h5", {
                key: i + '_help_editor_h5'
              }, paragraphs[i]);
              break;

            case 4:
              paragraphs[i] = /*#__PURE__*/react__WEBPACK_IMPORTED_MODULE_0___default.a.createElement("h4", {
                key: i + '_help_editor_h4'
              }, paragraphs[i]);
              break;

            case 3:
              paragraphs[i] = /*#__PURE__*/react__WEBPACK_IMPORTED_MODULE_0___default.a.createElement("h3", {
                key: i + '_help_editor_h3'
              }, paragraphs[i]);
              break;

            case 2:
              paragraphs[i] = /*#__PURE__*/react__WEBPACK_IMPORTED_MODULE_0___default.a.createElement("h2", {
                key: i + '_help_editor_h2'
              }, paragraphs[i]);
              break;

            case 1:
            default:
              paragraphs[i] = /*#__PURE__*/react__WEBPACK_IMPORTED_MODULE_0___default.a.createElement("h1", {
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
          paragraphs[i] = /*#__PURE__*/react__WEBPACK_IMPORTED_MODULE_0___default.a.createElement("p", {
            key: i + '_help_editor_p',
            dangerouslySetInnerHTML: {
              __html: paramd
            }
          });
        }
      }

      return /*#__PURE__*/react__WEBPACK_IMPORTED_MODULE_0___default.a.createElement("div", null, paragraphs);
    }
  }]);

  return Markdown;
}(react__WEBPACK_IMPORTED_MODULE_0__["Component"]);

Markdown.propTypes = {
  content: prop_types__WEBPACK_IMPORTED_MODULE_1___default.a.string.isRequired
};
var RMarkdown = /*#__PURE__*/react__WEBPACK_IMPORTED_MODULE_0___default.a.createFactory(Markdown);
window.Markdown = Markdown;
window.RMarkdown = RMarkdown;
/* harmony default export */ __webpack_exports__["default"] = (Markdown);

/***/ }),
/* 4 */
/***/ (function(module, exports) {

(function() { module.exports = window["React"]; }());

/***/ }),
/* 5 */
/***/ (function(module, exports, __webpack_require__) {

/**
 * Copyright (c) 2013-present, Facebook, Inc.
 *
 * This source code is licensed under the MIT license found in the
 * LICENSE file in the root directory of this source tree.
 */

if (true) {
  var ReactIs = __webpack_require__(6);

  // By explicitly using `prop-types` you are opting into new development behavior.
  // http://fb.me/prop-types-in-prod
  var throwOnDirectAccess = true;
  module.exports = __webpack_require__(8)(ReactIs.isElement, throwOnDirectAccess);
} else {}


/***/ }),
/* 6 */
/***/ (function(module, exports, __webpack_require__) {

"use strict";


if (false) {} else {
  module.exports = __webpack_require__(7);
}


/***/ }),
/* 7 */
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
/* 8 */
/***/ (function(module, exports, __webpack_require__) {

"use strict";
/**
 * Copyright (c) 2013-present, Facebook, Inc.
 *
 * This source code is licensed under the MIT license found in the
 * LICENSE file in the root directory of this source tree.
 */



var ReactIs = __webpack_require__(6);
var assign = __webpack_require__(9);

var ReactPropTypesSecret = __webpack_require__(10);
var checkPropTypes = __webpack_require__(11);

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
/* 9 */
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
/* 10 */
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
/* 11 */
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
  var ReactPropTypesSecret = __webpack_require__(10);
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
//# sourceMappingURL=DirectEntry.js.map