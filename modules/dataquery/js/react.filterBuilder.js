window["lorisjs"] = window["lorisjs"] || {}; window["lorisjs"]["dataquery"] = window["lorisjs"]["dataquery"] || {}; window["lorisjs"]["dataquery"]["react.filterBuilder"] =
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
/******/ 	return __webpack_require__(__webpack_require__.s = 11);
/******/ })
/************************************************************************/
/******/ ({

/***/ 1:
/***/ (function(module, exports) {

(function() { module.exports = window["React"]; }());

/***/ }),

/***/ 11:
/***/ (function(module, __webpack_exports__, __webpack_require__) {

"use strict";
__webpack_require__.r(__webpack_exports__);
/* harmony import */ var react__WEBPACK_IMPORTED_MODULE_0__ = __webpack_require__(1);
/* harmony import */ var react__WEBPACK_IMPORTED_MODULE_0___default = /*#__PURE__*/__webpack_require__.n(react__WEBPACK_IMPORTED_MODULE_0__);
function _typeof(obj) { "@babel/helpers - typeof"; return _typeof = "function" == typeof Symbol && "symbol" == typeof Symbol.iterator ? function (obj) { return typeof obj; } : function (obj) { return obj && "function" == typeof Symbol && obj.constructor === Symbol && obj !== Symbol.prototype ? "symbol" : typeof obj; }, _typeof(obj); }

function _classCallCheck(instance, Constructor) { if (!(instance instanceof Constructor)) { throw new TypeError("Cannot call a class as a function"); } }

function _defineProperties(target, props) { for (var i = 0; i < props.length; i++) { var descriptor = props[i]; descriptor.enumerable = descriptor.enumerable || false; descriptor.configurable = true; if ("value" in descriptor) descriptor.writable = true; Object.defineProperty(target, descriptor.key, descriptor); } }

function _createClass(Constructor, protoProps, staticProps) { if (protoProps) _defineProperties(Constructor.prototype, protoProps); if (staticProps) _defineProperties(Constructor, staticProps); Object.defineProperty(Constructor, "prototype", { writable: false }); return Constructor; }

function _inherits(subClass, superClass) { if (typeof superClass !== "function" && superClass !== null) { throw new TypeError("Super expression must either be null or a function"); } subClass.prototype = Object.create(superClass && superClass.prototype, { constructor: { value: subClass, writable: true, configurable: true } }); Object.defineProperty(subClass, "prototype", { writable: false }); if (superClass) _setPrototypeOf(subClass, superClass); }

function _setPrototypeOf(o, p) { _setPrototypeOf = Object.setPrototypeOf ? Object.setPrototypeOf.bind() : function _setPrototypeOf(o, p) { o.__proto__ = p; return o; }; return _setPrototypeOf(o, p); }

function _createSuper(Derived) { var hasNativeReflectConstruct = _isNativeReflectConstruct(); return function _createSuperInternal() { var Super = _getPrototypeOf(Derived), result; if (hasNativeReflectConstruct) { var NewTarget = _getPrototypeOf(this).constructor; result = Reflect.construct(Super, arguments, NewTarget); } else { result = Super.apply(this, arguments); } return _possibleConstructorReturn(this, result); }; }

function _possibleConstructorReturn(self, call) { if (call && (_typeof(call) === "object" || typeof call === "function")) { return call; } else if (call !== void 0) { throw new TypeError("Derived constructors may only return object or undefined"); } return _assertThisInitialized(self); }

function _assertThisInitialized(self) { if (self === void 0) { throw new ReferenceError("this hasn't been initialised - super() hasn't been called"); } return self; }

function _isNativeReflectConstruct() { if (typeof Reflect === "undefined" || !Reflect.construct) return false; if (Reflect.construct.sham) return false; if (typeof Proxy === "function") return true; try { Boolean.prototype.valueOf.call(Reflect.construct(Boolean, [], function () {})); return true; } catch (e) { return false; } }

function _getPrototypeOf(o) { _getPrototypeOf = Object.setPrototypeOf ? Object.getPrototypeOf.bind() : function _getPrototypeOf(o) { return o.__proto__ || Object.getPrototypeOf(o); }; return _getPrototypeOf(o); }

/**
 *  The following file contains the components used for the filter builder tab
 *
 *  @author   Jordan Stirling <jstirling91@gmail.com>
 *  @license  http://www.gnu.org/licenses/gpl-3.0.txt GPLv3
 *  @link     https://github.com/mohadesz/Loris-Trunk
 */

/*
 *  The following component is used for displaying operator for the group component
 */

var LogicOperator = /*#__PURE__*/function (_Component) {
  _inherits(LogicOperator, _Component);

  var _super = _createSuper(LogicOperator);

  function LogicOperator(props) {
    var _this;

    _classCallCheck(this, LogicOperator);

    _this = _super.call(this, props);
    _this.changeOperator = _this.changeOperator.bind(_assertThisInitialized(_this));
    return _this;
  }

  _createClass(LogicOperator, [{
    key: "changeOperator",
    value: function changeOperator(op) {
      // Wrapper function updating operator
      this.props.updateGroupOperator(op);
    }
  }, {
    key: "render",
    value: function render() {
      // Renders the html for the component
      var andClass = 'btn',
          orClass = 'btn'; // Set operator to OR if logicOperator is 1, AND otherwise

      if (this.props.logicOperator === 1) {
        orClass += ' btn-primary';
        andClass += ' switch';
      } else {
        andClass += ' btn-primary';
        orClass += ' switch';
      }

      return /*#__PURE__*/react__WEBPACK_IMPORTED_MODULE_0___default.a.createElement("div", {
        className: "btn-group",
        role: "group"
      }, /*#__PURE__*/react__WEBPACK_IMPORTED_MODULE_0___default.a.createElement("button", {
        type: "button",
        className: andClass,
        onClick: this.changeOperator.bind(this, 0)
      }, "And"), /*#__PURE__*/react__WEBPACK_IMPORTED_MODULE_0___default.a.createElement("button", {
        type: "button",
        className: orClass,
        onClick: this.changeOperator.bind(this, 1)
      }, "Or"));
    }
  }]);

  return LogicOperator;
}(react__WEBPACK_IMPORTED_MODULE_0__["Component"]);
/*
 *  The following component is used for displaying a filter rule
 */


var FilterRule = /*#__PURE__*/function (_Component2) {
  _inherits(FilterRule, _Component2);

  var _super2 = _createSuper(FilterRule);

  function FilterRule(props) {
    var _this2;

    _classCallCheck(this, FilterRule);

    _this2 = _super2.call(this, props);
    _this2.state = {
      operators: {
        equal: '=',
        notEqual: '!=',
        lessThanEqual: '<=',
        greaterThanEqual: '>=',
        startsWith: 'startsWith',
        contains: 'contains',
        isNull: 'isNull',
        isNotNull: 'isNotNull'
      },
      value: ''
    };
    _this2.selectInstrument = _this2.selectInstrument.bind(_assertThisInitialized(_this2));
    _this2.fieldSelect = _this2.fieldSelect.bind(_assertThisInitialized(_this2));
    _this2.operatorSelect = _this2.operatorSelect.bind(_assertThisInitialized(_this2));
    _this2.valueChange = _this2.valueChange.bind(_assertThisInitialized(_this2));
    _this2.valueSet = _this2.valueSet.bind(_assertThisInitialized(_this2));
    _this2.updateVisit = _this2.updateVisit.bind(_assertThisInitialized(_this2));
    return _this2;
  }

  _createClass(FilterRule, [{
    key: "componentWillMount",
    value: function componentWillMount() {
      this.valueSet = loris.debounce(this.valueSet, 1000);
    }
  }, {
    key: "selectInstrument",
    value: function selectInstrument(event) {
      var _this3 = this;

      // Update the rules instrument, getting the instruments avalible fields
      var rule = this.props.rule;

      if (event.target.value) {
        rule.instrument = event.target.value;
        $.get(loris.BaseURL + '/dataquery/ajax/datadictionary.php', {
          category: rule.instrument
        }, function (data) {
          rule.fields = data;

          _this3.props.updateRule(_this3.props.index, rule);
        }, 'json');
      }
    }
  }, {
    key: "fieldSelect",
    value: function fieldSelect(event) {
      // Update the rules desired field, setting the rules field and field type
      var rule = JSON.parse(JSON.stringify(this.props.rule));
      delete rule.field;
      delete rule.fieldType;
      delete rule.operator;
      delete rule.value;
      delete rule.visit;
      delete rule.candidates;

      if (event.target.value) {
        rule.field = rule.fields[event.target.value].key[1];
        rule.fieldType = rule.fields[event.target.value].value.Type;
      }

      this.props.updateRule(this.props.index, rule);
    }
  }, {
    key: "operatorSelect",
    value: function operatorSelect(event) {
      // Update the desired rule operation for the selected field
      var rule = JSON.parse(JSON.stringify(this.props.rule));
      delete rule.operator;
      delete rule.value;
      delete rule.visit;
      delete rule.candidates;

      if (event.target.value) {
        rule.operator = event.target.value;
      }

      this.props.updateRule(this.props.index, rule);

      if (rule.operator === 'isNull' || rule.operator === 'isNotNull') {
        this.setState({
          value: 'null'
        });
        this.valueSet();
      }
    }
  }, {
    key: "valueChange",
    value: function valueChange(event) {
      var rule = JSON.parse(JSON.stringify(this.props.rule));
      delete rule.visit;
      delete rule.candidates;
      rule.value = event.target.value;
      this.setState({
        value: event.target.value
      });
      this.valueSet();
      this.props.updateRule(this.props.index, rule);
    }
  }, {
    key: "valueSet",
    value: function valueSet() {
      var _this4 = this;

      // Update the value to filter for, and runs the query for the rules parameters
      var rule = JSON.parse(JSON.stringify(this.props.rule));

      if (this.state.value) {
        var responseHandler = function responseHandler(data) {
          var i;
          var allSessions = {};
          var allCandiates = {}; // Loop through data and divide into individual visits with unique PSCIDs
          // storing a master list of unique PSCIDs

          for (i = 0; i < data.length; i++) {
            if (!allSessions[data[i][1]]) {
              allSessions[data[i][1]] = [];
            }

            allSessions[data[i][1]].push(data[i][0]);

            if (!allCandiates[data[i][0]]) {
              allCandiates[data[i][0]] = [];
            }

            allCandiates[data[i][0]].push(data[i][1]);
          }

          rule.candidates = {
            allCandiates: allCandiates,
            allSessions: allSessions
          };
          rule.session = Object.keys(allCandiates);
          rule.visit = 'All';

          _this4.props.updateSessions(_this4.props.index, rule);
        };

        var ajaxRetrieve = function ajaxRetrieve(script) {
          $.get(loris.BaseURL + '/dataquery/ajax/' + script, {
            category: rule.instrument,
            field: rule.field,
            value: _this4.state.value
          }, responseHandler, 'json');
        };

        switch (rule.operator) {
          case 'equal':
          case 'isNull':
            ajaxRetrieve('queryEqual.php');
            break;

          case 'notEqual':
          case 'isNotNull':
            ajaxRetrieve('queryNotEqual.php');
            break;

          case 'lessThanEqual':
            ajaxRetrieve('queryLessThanEqual.php');
            break;

          case 'greaterThanEqual':
            ajaxRetrieve('queryGreaterThanEqual.php');
            break;

          case 'startsWith':
            ajaxRetrieve('queryStartsWith.php');
            break;

          case 'contains':
            ajaxRetrieve('queryContains.php');
            break;

          default:
            break;
        }
      }
    }
  }, {
    key: "updateVisit",
    value: function updateVisit(event) {
      // Update rule to filter for specified visit
      var rule = JSON.parse(JSON.stringify(this.props.rule));
      rule.visit = event.target.value;

      if (event.target.value === 'all') {
        // If all visits, use keys of master list
        rule.session = Object.keys(rule.candidates.allCandiates);
      } else {
        // Else use list of PSCIDs for given vist
        rule.session = rule.candidates.allSessions[event.target.value];
      }

      this.props.updateSessions(this.props.index, rule);
    }
  }, {
    key: "render",
    value: function render() {
      var _this5 = this;

      // Renders the html for the component
      var rule;
      var fieldIndex;
      var forVisits;
      var visits;

      if (this.props.rule.instrument) {
        // Only display field select and etc. if instrument is selected
        var fields = this.props.rule.fields.map(function (field, index) {
          if (_this5.props.rule.field && field.key[1] === _this5.props.rule.field) {
            fieldIndex = index;
          }

          return /*#__PURE__*/react__WEBPACK_IMPORTED_MODULE_0___default.a.createElement("option", {
            key: index,
            value: index
          }, field.key[1]);
        });
        var operators = [];
        var inputOptions = [];
        var input = [];
        var operatorKey = '';
        var operatorSelect = [];
        var options = [];
        var value = '';
        var inputType = [];

        if (this.props.rule.fieldType) {
          // Only display operators if field is selected
          inputType = this.props.rule.fieldType.split("(");
          operatorKey = inputType[0];

          for (var key in this.state.operators) {
            operators.push( /*#__PURE__*/react__WEBPACK_IMPORTED_MODULE_0___default.a.createElement("option", {
              value: key,
              onChange: this.operatorSelect
            }, this.state.operators[key]));
          }

          value = this.props.rule.operator ? this.props.rule.operator : "";
          operatorSelect = /*#__PURE__*/react__WEBPACK_IMPORTED_MODULE_0___default.a.createElement("select", {
            className: "input-sm col-xs-3 ",
            onChange: this.operatorSelect,
            value: value
          }, /*#__PURE__*/react__WEBPACK_IMPORTED_MODULE_0___default.a.createElement("option", {
            value: ""
          }), operators);

          if (this.props.rule.operator && this.props.rule.operator !== 'isNull' && this.props.rule.operator !== 'isNotNull') {
            // Only display value input if operator is selected, displaying specific
            // input type field data type
            switch (operatorKey) {
              case 'enum':
                inputOptions = enumToArray(this.props.rule.fieldType);
                options = inputOptions.map(function (option, index) {
                  return /*#__PURE__*/react__WEBPACK_IMPORTED_MODULE_0___default.a.createElement("option", {
                    key: index,
                    value: option
                  }, option);
                });
                value = this.props.rule.value ? this.props.rule.value : '';
                input = /*#__PURE__*/react__WEBPACK_IMPORTED_MODULE_0___default.a.createElement("select", {
                  className: "input-sm col-xs-3",
                  onChange: this.valueChange,
                  value: value
                }, /*#__PURE__*/react__WEBPACK_IMPORTED_MODULE_0___default.a.createElement("option", {
                  value: ""
                }), options);
                break;

              default:
                input = /*#__PURE__*/react__WEBPACK_IMPORTED_MODULE_0___default.a.createElement("input", {
                  type: "text",
                  className: "input-sm col-xs-3",
                  onChange: this.valueChange,
                  value: this.props.rule.value
                });
                break;
            }
          }

          if (this.props.rule.visit) {
            // Display dropdown for visit select. This only displays after a value
            // has been inputed
            visits = Object.keys(this.props.Visits).map(function (visit, index) {
              return /*#__PURE__*/react__WEBPACK_IMPORTED_MODULE_0___default.a.createElement("option", {
                key: index,
                value: visit
              }, visit);
            });
            forVisits = /*#__PURE__*/react__WEBPACK_IMPORTED_MODULE_0___default.a.createElement("select", {
              className: "input-sm col-xs-3",
              onChange: this.updateVisit,
              value: this.props.rule.visit
            }, /*#__PURE__*/react__WEBPACK_IMPORTED_MODULE_0___default.a.createElement("option", {
              value: "all"
            }, "All Visits"), visits);
          }
        }

        rule = /*#__PURE__*/react__WEBPACK_IMPORTED_MODULE_0___default.a.createElement("div", null, /*#__PURE__*/react__WEBPACK_IMPORTED_MODULE_0___default.a.createElement("div", {
          className: "col-xs-12"
        }, /*#__PURE__*/react__WEBPACK_IMPORTED_MODULE_0___default.a.createElement("label", {
          className: "instrumentLabel"
        }, this.props.rule.instrument)), /*#__PURE__*/react__WEBPACK_IMPORTED_MODULE_0___default.a.createElement("div", {
          className: "col-xs-10"
        }, /*#__PURE__*/react__WEBPACK_IMPORTED_MODULE_0___default.a.createElement("select", {
          className: "input-sm col-xs-3",
          onChange: this.fieldSelect,
          value: fieldIndex
        }, /*#__PURE__*/react__WEBPACK_IMPORTED_MODULE_0___default.a.createElement("option", {
          value: ""
        }), fields), operatorSelect, input, forVisits));
      } else {
        // Else display dropdown for instrument select
        var _options = this.props.items.map(function (item, index) {
          return /*#__PURE__*/react__WEBPACK_IMPORTED_MODULE_0___default.a.createElement("option", {
            key: index,
            value: item.category
          }, item.category);
        });

        rule = /*#__PURE__*/react__WEBPACK_IMPORTED_MODULE_0___default.a.createElement("select", {
          onChange: this.selectInstrument,
          className: "input-sm col-xs-10"
        }, /*#__PURE__*/react__WEBPACK_IMPORTED_MODULE_0___default.a.createElement("option", {
          value: ""
        }), _options);
      }

      return /*#__PURE__*/react__WEBPACK_IMPORTED_MODULE_0___default.a.createElement("div", {
        className: "panel panel-default"
      }, /*#__PURE__*/react__WEBPACK_IMPORTED_MODULE_0___default.a.createElement("div", {
        className: "panel-body"
      }, rule, /*#__PURE__*/react__WEBPACK_IMPORTED_MODULE_0___default.a.createElement("div", {
        className: "col-xs-2"
      }, /*#__PURE__*/react__WEBPACK_IMPORTED_MODULE_0___default.a.createElement("button", {
        className: "btn btn-danger btn-sm pull-right",
        onClick: this.props.deleteRule.bind(this, this.props.index)
      }, /*#__PURE__*/react__WEBPACK_IMPORTED_MODULE_0___default.a.createElement("span", {
        className: "glyphicon glyphicon-remove"
      }), " Delete"))));
    }
  }]);

  return FilterRule;
}(react__WEBPACK_IMPORTED_MODULE_0__["Component"]);
/*
 *  The following component is used for displaying a filter group
 */


var FilterGroup = /*#__PURE__*/function (_Component3) {
  _inherits(FilterGroup, _Component3);

  var _super3 = _createSuper(FilterGroup);

  function FilterGroup(props) {
    var _this6;

    _classCallCheck(this, FilterGroup);

    _this6 = _super3.call(this, props);
    _this6.state = {};
    _this6.updateChild = _this6.updateChild.bind(_assertThisInitialized(_this6));
    _this6.updateGroupOperator = _this6.updateGroupOperator.bind(_assertThisInitialized(_this6));
    _this6.updateSessions = _this6.updateSessions.bind(_assertThisInitialized(_this6));
    _this6.addChild = _this6.addChild.bind(_assertThisInitialized(_this6));
    _this6.deleteChild = _this6.deleteChild.bind(_assertThisInitialized(_this6));
    return _this6;
  }

  _createClass(FilterGroup, [{
    key: "updateChild",
    value: function updateChild(index, child) {
      // Update a specified child in the groups children
      var group = this.props.group;
      group.children[index] = child;

      if (this.props.index) {
        // If not base filter group, recursively call update child
        this.props.updateGroup(this.props.index, group);
      } else {
        // Else base filter group, update the filter in the data query component
        this.props.updateFilter(group);
      }
    }
  }, {
    key: "updateGroupOperator",
    value: function updateGroupOperator(operator) {
      // Update the group's operator
      var group = this.props.group;
      group.activeOperator = operator; // Update the groups sessions by calling the arrayintersect.js functions

      group.session = getSessions(group);

      if (this.props.index) {
        // If not base filter group, recursively call update child
        this.props.updateGroup(this.props.index, group);
      } else {
        // Else base filter group, update the filter in the data query component
        this.props.updateFilter(group);
      }
    }
  }, {
    key: "updateSessions",
    value: function updateSessions(index, child) {
      // Computes the desired sessions of the current group
      var group = this.props.group,
          sessions = [],
          session = [];
      group.children[index] = child; // Update the groups sessions by calling the arrayintersect.js functions

      group.session = getSessions(group);

      if (this.props.index) {
        // If not base filter group, recursively call update parents session
        this.props.updateSessions(this.props.index, group);
      } else {
        // Else base filter group, update the filter in the data query component
        this.props.updateFilter(group);
      }
    }
  }, {
    key: "addChild",
    value: function addChild(type) {
      // Add a child to the group
      var child,
          group = this.props.group; // Define the child's base data structure depending on specifed type

      if (type === 'rule') {
        child = {
          type: 'rule'
        };
      } else {
        child = {
          type: 'group',
          activeOperator: 0,
          children: [{
            type: 'rule'
          }]
        };
      }

      group.children.push(child);

      if (this.props.index) {
        // If not base filter group, recursively call update child
        this.props.updateGroup(this.props.index, group);
      } else {
        // Else base filter group, update the filter in the data query component
        this.props.updateFilter(group);
      }
    }
  }, {
    key: "deleteChild",
    value: function deleteChild(index) {
      // Delete a child
      var group = this.props.group;
      group.children.splice(index, 1); // Update the groups sessions by calling the arrayintersect.js functions

      group.session = getSessions(group);

      if (this.props.index) {
        // If not base filter group, recursively call update child
        this.props.updateGroup(this.props.index, group);
      } else {
        // Else base filter group, update the filter in the data query component
        this.props.updateFilter(group);
      }
    }
  }, {
    key: "render",
    value: function render() {
      var _this7 = this;

      // Renders the html for the component
      var logicOperator = /*#__PURE__*/react__WEBPACK_IMPORTED_MODULE_0___default.a.createElement(LogicOperator, {
        logicOperator: this.props.group.activeOperator,
        updateGroupOperator: this.updateGroupOperator
      }); // Render the children based on their type

      var children = this.props.group.children.map(function (child, index) {
        if (child.type === 'rule') {
          return /*#__PURE__*/react__WEBPACK_IMPORTED_MODULE_0___default.a.createElement("li", {
            key: index
          }, /*#__PURE__*/react__WEBPACK_IMPORTED_MODULE_0___default.a.createElement(FilterRule, {
            rule: child,
            items: _this7.props.items,
            index: index,
            updateRule: _this7.updateChild,
            updateSessions: _this7.updateSessions,
            deleteRule: _this7.deleteChild,
            Visits: _this7.props.Visits
          }));
        } else if (child.type === 'group') {
          return /*#__PURE__*/react__WEBPACK_IMPORTED_MODULE_0___default.a.createElement("li", {
            key: index
          }, /*#__PURE__*/react__WEBPACK_IMPORTED_MODULE_0___default.a.createElement(FilterGroup, {
            group: child,
            items: _this7.props.items,
            index: index,
            updateGroup: _this7.updateChild,
            updateSessions: _this7.updateSessions,
            deleteGroup: _this7.deleteChild,
            Visits: _this7.props.Visits
          }));
        }
      });
      var deleteButton;

      if (this.props.deleteGroup) {
        // Can only delete a group that isn't the base group
        deleteButton = /*#__PURE__*/react__WEBPACK_IMPORTED_MODULE_0___default.a.createElement("button", {
          className: "btn btn-danger btn-sm pull-right",
          onClick: this.props.deleteGroup.bind(this, this.props.index)
        }, /*#__PURE__*/react__WEBPACK_IMPORTED_MODULE_0___default.a.createElement("span", {
          className: "glyphicon glyphicon-remove"
        }), " Delete Group");
      }

      return /*#__PURE__*/react__WEBPACK_IMPORTED_MODULE_0___default.a.createElement("div", {
        className: "tree"
      }, /*#__PURE__*/react__WEBPACK_IMPORTED_MODULE_0___default.a.createElement("ul", {
        className: "firstUL"
      }, /*#__PURE__*/react__WEBPACK_IMPORTED_MODULE_0___default.a.createElement("li", null, /*#__PURE__*/react__WEBPACK_IMPORTED_MODULE_0___default.a.createElement("div", {
        className: "row"
      }, /*#__PURE__*/react__WEBPACK_IMPORTED_MODULE_0___default.a.createElement("div", {
        className: "col-xs-2"
      }, logicOperator), /*#__PURE__*/react__WEBPACK_IMPORTED_MODULE_0___default.a.createElement("div", {
        className: "col-xs-10"
      }, deleteButton, /*#__PURE__*/react__WEBPACK_IMPORTED_MODULE_0___default.a.createElement("button", {
        className: "btn btn-primary btn-sm pull-right",
        onClick: this.addChild.bind(this, 'group')
      }, /*#__PURE__*/react__WEBPACK_IMPORTED_MODULE_0___default.a.createElement("span", {
        className: "glyphicon glyphicon-add"
      }), " Add Group"), /*#__PURE__*/react__WEBPACK_IMPORTED_MODULE_0___default.a.createElement("button", {
        className: "btn btn-primary btn-sm pull-right",
        onClick: this.addChild.bind(this, 'rule')
      }, /*#__PURE__*/react__WEBPACK_IMPORTED_MODULE_0___default.a.createElement("span", {
        className: "glyphicon glyphicon-add"
      }), " Add Rule"))), /*#__PURE__*/react__WEBPACK_IMPORTED_MODULE_0___default.a.createElement("ul", null, children))));
    }
  }]);

  return FilterGroup;
}(react__WEBPACK_IMPORTED_MODULE_0__["Component"]);
/*
 *  The following component is the base componenet for the filter builder
 */


var FilterBuilder = /*#__PURE__*/function (_Component4) {
  _inherits(FilterBuilder, _Component4);

  var _super4 = _createSuper(FilterBuilder);

  function FilterBuilder(props) {
    var _this8;

    _classCallCheck(this, FilterBuilder);

    _this8 = _super4.call(this, props);
    _this8.state = {};
    return _this8;
  }

  _createClass(FilterBuilder, [{
    key: "render",
    value: function render() {
      return /*#__PURE__*/react__WEBPACK_IMPORTED_MODULE_0___default.a.createElement("div", null, /*#__PURE__*/react__WEBPACK_IMPORTED_MODULE_0___default.a.createElement("h1", {
        className: "col-xs-12"
      }, "Filter"), /*#__PURE__*/react__WEBPACK_IMPORTED_MODULE_0___default.a.createElement("div", {
        className: "col-xs-12"
      }, /*#__PURE__*/react__WEBPACK_IMPORTED_MODULE_0___default.a.createElement("div", {
        className: "well well-primary"
      }, /*#__PURE__*/react__WEBPACK_IMPORTED_MODULE_0___default.a.createElement(FilterGroup, {
        group: this.props.filter,
        items: this.props.items,
        updateFilter: this.props.updateFilter,
        Visits: this.props.Visits
      }))));
    }
  }]);

  return FilterBuilder;
}(react__WEBPACK_IMPORTED_MODULE_0__["Component"]);

window.LogicOperator = LogicOperator;
window.FilterRule = FilterRule;
window.FilterGroup = FilterGroup;
window.FilterBuilder = FilterBuilder;
/* harmony default export */ __webpack_exports__["default"] = ({
  LogicOperator: LogicOperator,
  FilterRule: FilterRule,
  FilterGroup: FilterGroup,
  FilterBuilder: FilterBuilder
});

/***/ })

/******/ });
//# sourceMappingURL=react.filterBuilder.js.map