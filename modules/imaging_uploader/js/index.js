/******/ (function(modules) { // webpackBootstrap
/******/ 	// The module cache
/******/ 	var installedModules = {};
/******/
/******/ 	// The require function
/******/ 	function __webpack_require__(moduleId) {
/******/
/******/ 		// Check if module is in cache
/******/ 		if(installedModules[moduleId])
/******/ 			return installedModules[moduleId].exports;
/******/
/******/ 		// Create a new module (and put it into the cache)
/******/ 		var module = installedModules[moduleId] = {
/******/ 			exports: {},
/******/ 			id: moduleId,
/******/ 			loaded: false
/******/ 		};
/******/
/******/ 		// Execute the module function
/******/ 		modules[moduleId].call(module.exports, module, module.exports, __webpack_require__);
/******/
/******/ 		// Flag the module as loaded
/******/ 		module.loaded = true;
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
/******/ 	// __webpack_public_path__
/******/ 	__webpack_require__.p = "";
/******/
/******/ 	// Load entry module and return exports
/******/ 	return __webpack_require__(0);
/******/ })
/************************************************************************/
/******/ ([
/* 0 */
/***/ function(module, exports, __webpack_require__) {

	"use strict";
	
	var _ImagingUploader = __webpack_require__(1);
	
	var _ImagingUploader2 = _interopRequireDefault(_ImagingUploader);
	
	function _interopRequireDefault(obj) { return obj && obj.__esModule ? obj : { default: obj }; }
	
	/**
	 * Render imaging_uploader on page load
	 */
	$(function () {
	  var imagingUploader = React.createElement(
	    "div",
	    { className: "page-imaging-uploader" },
	    React.createElement(_ImagingUploader2.default, {
	      Module: "imaging_uploader",
	      DataURL: loris.BaseURL + "/imaging_uploader/?format=json"
	    })
	  );
	
	  ReactDOM.render(imagingUploader, document.getElementById("lorisworkspace"));
	}); /* global ReactDOM */

/***/ },
/* 1 */
/***/ function(module, exports, __webpack_require__) {

	'use strict';
	
	Object.defineProperty(exports, "__esModule", {
	  value: true
	});
	
	var _createClass = function () { function defineProperties(target, props) { for (var i = 0; i < props.length; i++) { var descriptor = props[i]; descriptor.enumerable = descriptor.enumerable || false; descriptor.configurable = true; if ("value" in descriptor) descriptor.writable = true; Object.defineProperty(target, descriptor.key, descriptor); } } return function (Constructor, protoProps, staticProps) { if (protoProps) defineProperties(Constructor.prototype, protoProps); if (staticProps) defineProperties(Constructor, staticProps); return Constructor; }; }();
	
	var _FilterForm = __webpack_require__(2);
	
	var _FilterForm2 = _interopRequireDefault(_FilterForm);
	
	var _Tabs = __webpack_require__(4);
	
	var _LogPanel = __webpack_require__(5);
	
	var _LogPanel2 = _interopRequireDefault(_LogPanel);
	
	var _UploadForm = __webpack_require__(6);
	
	var _UploadForm2 = _interopRequireDefault(_UploadForm);
	
	var _columnFormatter = __webpack_require__(8);
	
	var _columnFormatter2 = _interopRequireDefault(_columnFormatter);
	
	function _interopRequireDefault(obj) { return obj && obj.__esModule ? obj : { default: obj }; }
	
	function _classCallCheck(instance, Constructor) { if (!(instance instanceof Constructor)) { throw new TypeError("Cannot call a class as a function"); } }
	
	function _possibleConstructorReturn(self, call) { if (!self) { throw new ReferenceError("this hasn't been initialised - super() hasn't been called"); } return call && (typeof call === "object" || typeof call === "function") ? call : self; }
	
	function _inherits(subClass, superClass) { if (typeof superClass !== "function" && superClass !== null) { throw new TypeError("Super expression must either be null or a function, not " + typeof superClass); } subClass.prototype = Object.create(superClass && superClass.prototype, { constructor: { value: subClass, enumerable: false, writable: true, configurable: true } }); if (superClass) Object.setPrototypeOf ? Object.setPrototypeOf(subClass, superClass) : subClass.__proto__ = superClass; }
	
	var ImagingUploader = function (_React$Component) {
	  _inherits(ImagingUploader, _React$Component);
	
	  function ImagingUploader(props) {
	    _classCallCheck(this, ImagingUploader);
	
	    var _this = _possibleConstructorReturn(this, (ImagingUploader.__proto__ || Object.getPrototypeOf(ImagingUploader)).call(this, props));
	
	    _this.state = {
	      isLoaded: false,
	      filter: {}
	    };
	
	    // Bind component instance to custom methods
	    _this.fetchData = _this.fetchData.bind(_this);
	    _this.updateFilter = _this.updateFilter.bind(_this);
	    _this.resetFilters = _this.resetFilters.bind(_this);
	    return _this;
	  }
	
	  _createClass(ImagingUploader, [{
	    key: 'componentDidMount',
	    value: function componentDidMount() {
	      this.fetchData();
	    }
	
	    /**
	     * Retrive data from the provided URL and save it in state
	     * Additionaly add hiddenHeaders to global loris vairable
	     * for easy access by columnFormatter.
	     */
	
	  }, {
	    key: 'fetchData',
	    value: function fetchData() {
	      $.ajax(this.props.DataURL, {
	        method: "GET",
	        dataType: 'json',
	        success: function (data) {
	          this.setState({
	            Data: data,
	            isLoaded: true
	          });
	        }.bind(this),
	        error: function error(_error) {
	          console.error(_error);
	        }
	      });
	    }
	  }, {
	    key: 'updateFilter',
	    value: function updateFilter(filter) {
	      this.setState({ filter: filter });
	    }
	  }, {
	    key: 'resetFilters',
	    value: function resetFilters() {
	      this.imagingUploaderFilter.clearFilter();
	    }
	  }, {
	    key: 'render',
	    value: function render() {
	      if (!this.state.isLoaded) {
	        return React.createElement(
	          'button',
	          { className: 'btn-info has-spinner' },
	          'Loading',
	          React.createElement('span', {
	            className: 'glyphicon glyphicon-refresh glyphicon-refresh-animate' })
	        );
	      }
	
	      var tabList = [{ id: "browse", label: "Browse" }, { id: "upload", label: "Upload" }];
	
	      var filterRef = function (f) {
	        this.imagingUploaderFilter = f;
	      }.bind(this);
	
	      return React.createElement(
	        _Tabs.Tabs,
	        { tabs: tabList, defaultTab: 'browse', updateURL: true },
	        React.createElement(
	          _Tabs.TabPane,
	          { TabId: tabList[0].id },
	          React.createElement(
	            'div',
	            { className: 'row' },
	            React.createElement(
	              'div',
	              { className: 'col-md-5' },
	              React.createElement(
	                _FilterForm2.default,
	                {
	                  Module: 'imaging_uploader',
	                  name: 'imaging_filter',
	                  id: 'imaging_filter',
	                  ref: filterRef,
	                  onUpdate: this.updateFilter,
	                  filter: this.state.filter
	                },
	                React.createElement(TextboxElement, this.state.Data.form.candID),
	                React.createElement(TextboxElement, this.state.Data.form.pSCID),
	                React.createElement(SelectElement, this.state.Data.form.visitLabel),
	                React.createElement(SelectElement, this.state.Data.form.imagingUploadType),
	                React.createElement(ButtonElement, { type: 'reset', label: 'Clear Filters', onUserInput: this.resetFilters })
	              )
	            ),
	            React.createElement(
	              'div',
	              { className: 'col-md-7' },
	              React.createElement(_LogPanel2.default, null)
	            )
	          ),
	          React.createElement(
	            'div',
	            { id: 'mri_upload_table' },
	            React.createElement(StaticDataTable, {
	              Data: this.state.Data.Data,
	              Headers: this.state.Data.Headers,
	              getFormattedCell: _columnFormatter2.default,
	              Filter: this.state.filter
	            })
	          )
	        ),
	        React.createElement(
	          _Tabs.TabPane,
	          { TabId: tabList[1].id },
	          React.createElement(_UploadForm2.default, {
	            form: this.state.Data.form,
	            mriList: this.state.Data.mriList,
	            maxUploadSize: this.state.Data.maxUploadSize
	          })
	        )
	      );
	    }
	  }]);
	
	  return ImagingUploader;
	}(React.Component);
	
	ImagingUploader.propTypes = {};
	ImagingUploader.defaultProps = {};
	
	exports.default = ImagingUploader;

/***/ },
/* 2 */
/***/ function(module, exports, __webpack_require__) {

	'use strict';
	
	Object.defineProperty(exports, "__esModule", {
	  value: true
	});
	
	var _typeof = typeof Symbol === "function" && typeof Symbol.iterator === "symbol" ? function (obj) { return typeof obj; } : function (obj) { return obj && typeof Symbol === "function" && obj.constructor === Symbol && obj !== Symbol.prototype ? "symbol" : typeof obj; };
	
	var _createClass = function () { function defineProperties(target, props) { for (var i = 0; i < props.length; i++) { var descriptor = props[i]; descriptor.enumerable = descriptor.enumerable || false; descriptor.configurable = true; if ("value" in descriptor) descriptor.writable = true; Object.defineProperty(target, descriptor.key, descriptor); } } return function (Constructor, protoProps, staticProps) { if (protoProps) defineProperties(Constructor.prototype, protoProps); if (staticProps) defineProperties(Constructor, staticProps); return Constructor; }; }();
	
	var _Panel = __webpack_require__(3);
	
	var _Panel2 = _interopRequireDefault(_Panel);
	
	function _interopRequireDefault(obj) { return obj && obj.__esModule ? obj : { default: obj }; }
	
	function _classCallCheck(instance, Constructor) { if (!(instance instanceof Constructor)) { throw new TypeError("Cannot call a class as a function"); } }
	
	function _possibleConstructorReturn(self, call) { if (!self) { throw new ReferenceError("this hasn't been initialised - super() hasn't been called"); } return call && (typeof call === "object" || typeof call === "function") ? call : self; }
	
	function _inherits(subClass, superClass) { if (typeof superClass !== "function" && superClass !== null) { throw new TypeError("Super expression must either be null or a function, not " + typeof superClass); } subClass.prototype = Object.create(superClass && superClass.prototype, { constructor: { value: subClass, enumerable: false, writable: true, configurable: true } }); if (superClass) Object.setPrototypeOf ? Object.setPrototypeOf(subClass, superClass) : subClass.__proto__ = superClass; } /**
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
	var FilterForm = function (_React$Component) {
	  _inherits(FilterForm, _React$Component);
	
	  function FilterForm(props) {
	    _classCallCheck(this, FilterForm);
	
	    // Bind component instance to custom methods
	    var _this = _possibleConstructorReturn(this, (FilterForm.__proto__ || Object.getPrototypeOf(FilterForm)).call(this, props));
	
	    _this.clearFilter = _this.clearFilter.bind(_this);
	    _this.getFormChildren = _this.getFormChildren.bind(_this);
	    _this.setFilter = _this.setFilter.bind(_this);
	    _this.onElementUpdate = _this.onElementUpdate.bind(_this);
	
	    // Keeps track of querystring values
	    // Saved as class variable instead of keeping in state
	    _this.queryString = QueryString.get();
	    return _this;
	  }
	
	  _createClass(FilterForm, [{
	    key: 'componentDidMount',
	    value: function componentDidMount() {
	      var filter = {};
	      var queryString = this.queryString;
	
	      // Initiaze filter using querystring value
	      Object.keys(queryString).forEach(function (key) {
	        var filterKey = key === 'candidateID' ? 'candID' : key;
	        filter[filterKey] = {
	          value: queryString[key],
	          exactMatch: false
	        };
	      });
	
	      // Update parent component
	      this.props.onUpdate(filter);
	    }
	
	    /**
	     * Clear the filter object, querystring and input fields
	     */
	
	  }, {
	    key: 'clearFilter',
	    value: function clearFilter() {
	      this.queryString = QueryString.clear(this.props.Module);
	      this.props.onUpdate({});
	    }
	
	    /**
	     * Itterates through FilterForm children, sets necessary callback functions
	     * and initializes filterTable
	     *
	     * @return {Array} formChildren - array of children with necessary props
	     */
	
	  }, {
	    key: 'getFormChildren',
	    value: function getFormChildren() {
	      var formChildren = [];
	      React.Children.forEach(this.props.children, function (child, key) {
	        // If child is a React component (i.e not a simple DOM element)
	        if (React.isValidElement(child) && typeof child.type === "function" && child.props.onUserInput) {
	          var callbackFunc = child.props.onUserInput;
	          var callbackName = callbackFunc.name;
	          var elementName = child.type.displayName;
	          var queryFieldName = child.props.name === 'candID' ? 'candidateID' : child.props.name;
	          var filterValue = this.queryString[queryFieldName];
	          // If callback function was not set, set it to onElementUpdate() for form
	          // elements and to clearFilter() for <ButtonElement type='reset'/>.
	          if (callbackName === "onUserInput") {
	            if (elementName === "ButtonElement" && child.props.type === "reset") {
	              callbackFunc = this.clearFilter;
	            } else {
	              callbackFunc = this.onElementUpdate.bind(null, elementName);
	            }
	          }
	          // Pass onUserInput and value props to all children
	          formChildren.push(React.cloneElement(child, {
	            onUserInput: callbackFunc,
	            value: filterValue ? filterValue : '',
	            key: key
	          }));
	          // Initialize filter for StaticDataTable
	          this.setFilter(elementName, child.props.name, filterValue);
	        } else {
	          formChildren.push(React.cloneElement(child, { key: key }));
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
	    key: 'setFilter',
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
	        filter[key].exactMatch = type === "SelectElement" || type === "select";
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
	    key: 'onElementUpdate',
	    value: function onElementUpdate(type, fieldName, fieldValue) {
	      // Make sure key is of string type and value is of string or object type
	      // before sending them to querystring
	      if (typeof fieldName !== 'string' || typeof fieldValue !== 'string' && (typeof fieldValue === 'undefined' ? 'undefined' : _typeof(fieldValue)) !== 'object') {
	        return;
	      }
	
	      // Update query string
	      var queryFieldName = fieldName === 'candID' ? 'candidateID' : fieldName;
	      this.queryString = QueryString.set(this.queryString, queryFieldName, fieldValue);
	
	      // Update filter and get new filter object
	      var filter = this.setFilter(type, fieldName, fieldValue);
	      this.props.onUpdate(filter);
	    }
	  }, {
	    key: 'render',
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
	
	      return React.createElement(
	        _Panel2.default,
	        {
	          id: this.props.id,
	          height: this.props.height,
	          title: this.props.title
	        },
	        React.createElement(
	          FormElement,
	          this.props,
	          formChildren
	        )
	      );
	    }
	  }]);
	
	  return FilterForm;
	}(React.Component);
	
	FilterForm.defaultProps = {
	  id: 'selection-filter',
	  height: '100%',
	  title: 'Selection Filter',
	  onUpdate: function onUpdate() {
	    console.warn('onUpdate() callback is not set!');
	  }
	};
	FilterForm.propTypes = {
	  Module: React.PropTypes.string.isRequired,
	  filter: React.PropTypes.object.isRequired,
	  id: React.PropTypes.string,
	  height: React.PropTypes.string,
	  title: React.PropTypes.string,
	  onUpdate: React.PropTypes.func
	};
	
	exports.default = FilterForm;

/***/ },
/* 3 */
/***/ function(module, exports) {

	"use strict";
	
	Object.defineProperty(exports, "__esModule", {
	  value: true
	});
	
	var _createClass = function () { function defineProperties(target, props) { for (var i = 0; i < props.length; i++) { var descriptor = props[i]; descriptor.enumerable = descriptor.enumerable || false; descriptor.configurable = true; if ("value" in descriptor) descriptor.writable = true; Object.defineProperty(target, descriptor.key, descriptor); } } return function (Constructor, protoProps, staticProps) { if (protoProps) defineProperties(Constructor.prototype, protoProps); if (staticProps) defineProperties(Constructor, staticProps); return Constructor; }; }();
	
	function _classCallCheck(instance, Constructor) { if (!(instance instanceof Constructor)) { throw new TypeError("Cannot call a class as a function"); } }
	
	function _possibleConstructorReturn(self, call) { if (!self) { throw new ReferenceError("this hasn't been initialised - super() hasn't been called"); } return call && (typeof call === "object" || typeof call === "function") ? call : self; }
	
	function _inherits(subClass, superClass) { if (typeof superClass !== "function" && superClass !== null) { throw new TypeError("Super expression must either be null or a function, not " + typeof superClass); } subClass.prototype = Object.create(superClass && superClass.prototype, { constructor: { value: subClass, enumerable: false, writable: true, configurable: true } }); if (superClass) Object.setPrototypeOf ? Object.setPrototypeOf(subClass, superClass) : subClass.__proto__ = superClass; }
	
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
	var Panel = function (_React$Component) {
	  _inherits(Panel, _React$Component);
	
	  function Panel(props) {
	    _classCallCheck(this, Panel);
	
	    var _this = _possibleConstructorReturn(this, (Panel.__proto__ || Object.getPrototypeOf(Panel)).call(this, props));
	
	    _this.state = {
	      collapsed: _this.props.initCollapsed
	    };
	
	    // Initialize panel class based on collapsed status
	    _this.panelClass = _this.props.initCollapsed ? "panel-collapse collapse" : "panel-collapse collapse in";
	
	    _this.toggleCollapsed = _this.toggleCollapsed.bind(_this);
	    return _this;
	  }
	
	  _createClass(Panel, [{
	    key: "toggleCollapsed",
	    value: function toggleCollapsed() {
	      this.setState({ collapsed: !this.state.collapsed });
	    }
	  }, {
	    key: "render",
	    value: function render() {
	      // Change arrow direction based on collapse status
	      var glyphClass = this.state.collapsed ? "glyphicon pull-right glyphicon-chevron-down" : "glyphicon pull-right glyphicon-chevron-up";
	
	      // Add panel header, if title is set
	      var panelHeading = this.props.title ? React.createElement(
	        "div",
	        {
	          className: "panel-heading",
	          onClick: this.toggleCollapsed,
	          "data-toggle": "collapse",
	          "data-target": '#' + this.props.id,
	          style: { cursor: 'pointer' }
	        },
	        this.props.title,
	        React.createElement("span", { className: glyphClass })
	      ) : '';
	
	      return React.createElement(
	        "div",
	        { className: "panel panel-primary" },
	        panelHeading,
	        React.createElement(
	          "div",
	          { id: this.props.id, className: this.panelClass, role: "tabpanel" },
	          React.createElement(
	            "div",
	            { className: "panel-body", style: { height: this.props.height } },
	            this.props.children
	          )
	        )
	      );
	    }
	  }]);
	
	  return Panel;
	}(React.Component);
	
	Panel.propTypes = {
	  id: React.PropTypes.string,
	  height: React.PropTypes.string,
	  title: React.PropTypes.string
	};
	Panel.defaultProps = {
	  initCollapsed: false,
	  id: 'default-panel',
	  height: '100%'
	};
	
	exports.default = Panel;

/***/ },
/* 4 */
/***/ function(module, exports) {

	'use strict';
	
	Object.defineProperty(exports, "__esModule", {
	  value: true
	});
	
	var _createClass = function () { function defineProperties(target, props) { for (var i = 0; i < props.length; i++) { var descriptor = props[i]; descriptor.enumerable = descriptor.enumerable || false; descriptor.configurable = true; if ("value" in descriptor) descriptor.writable = true; Object.defineProperty(target, descriptor.key, descriptor); } } return function (Constructor, protoProps, staticProps) { if (protoProps) defineProperties(Constructor.prototype, protoProps); if (staticProps) defineProperties(Constructor, staticProps); return Constructor; }; }();
	
	function _classCallCheck(instance, Constructor) { if (!(instance instanceof Constructor)) { throw new TypeError("Cannot call a class as a function"); } }
	
	function _possibleConstructorReturn(self, call) { if (!self) { throw new ReferenceError("this hasn't been initialised - super() hasn't been called"); } return call && (typeof call === "object" || typeof call === "function") ? call : self; }
	
	function _inherits(subClass, superClass) { if (typeof superClass !== "function" && superClass !== null) { throw new TypeError("Super expression must either be null or a function, not " + typeof superClass); } subClass.prototype = Object.create(superClass && superClass.prototype, { constructor: { value: subClass, enumerable: false, writable: true, configurable: true } }); if (superClass) Object.setPrototypeOf ? Object.setPrototypeOf(subClass, superClass) : subClass.__proto__ = superClass; }
	
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
	var Tabs = function (_React$Component) {
	  _inherits(Tabs, _React$Component);
	
	  function Tabs(props) {
	    _classCallCheck(this, Tabs);
	
	    var _this = _possibleConstructorReturn(this, (Tabs.__proto__ || Object.getPrototypeOf(Tabs)).call(this, props));
	
	    var hash = window.location.hash;
	    var activeTab = "";
	
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
	
	    _this.handleClick = _this.handleClick.bind(_this);
	    _this.getTabs = _this.getTabs.bind(_this);
	    _this.getTabPanes = _this.getTabPanes.bind(_this);
	    return _this;
	  }
	
	  _createClass(Tabs, [{
	    key: 'handleClick',
	    value: function handleClick(tabId, e) {
	      this.setState({ activeTab: tabId });
	      this.props.onTabChange(tabId);
	
	      // Add tab href to URL querystring and scroll the page to top
	      if (this.props.updateURL) {
	        var scrollDistance = $('body').scrollTop() || $('html').scrollTop();
	        window.location.hash = e.target.hash;
	        $('html,body').scrollTop(scrollDistance);
	      }
	    }
	  }, {
	    key: 'getTabs',
	    value: function getTabs() {
	      var tabs = this.props.tabs.map(function (tab) {
	        var tabClass = this.state.activeTab === tab.id ? 'active' : null;
	        var href = "#" + tab.id;
	        var tabID = "tab-" + tab.id;
	        return React.createElement(
	          'li',
	          {
	            role: 'presentation',
	            className: tabClass,
	            key: tab.id
	          },
	          React.createElement(
	            'a',
	            { id: tabID,
	              href: href,
	              role: 'tab',
	              'data-toggle': 'tab',
	              onClick: this.handleClick.bind(null, tab.id)
	            },
	            tab.label
	          )
	        );
	      }.bind(this));
	
	      return tabs;
	    }
	  }, {
	    key: 'getTabPanes',
	    value: function getTabPanes() {
	      var tabPanes = React.Children.map(this.props.children, function (child, key) {
	        if (child) {
	          return React.cloneElement(child, {
	            activeTab: this.state.activeTab,
	            key: key
	          });
	        }
	      }.bind(this));
	
	      return tabPanes;
	    }
	  }, {
	    key: 'render',
	    value: function render() {
	      var tabs = this.getTabs();
	      var tabPanes = this.getTabPanes();
	      var tabStyle = {
	        marginLeft: 0,
	        marginBottom: '5px'
	      };
	
	      return React.createElement(
	        'div',
	        null,
	        React.createElement(
	          'ul',
	          { className: 'nav nav-tabs', role: 'tablist', style: tabStyle },
	          tabs
	        ),
	        React.createElement(
	          'div',
	          { className: 'tab-content' },
	          tabPanes
	        )
	      );
	    }
	  }]);
	
	  return Tabs;
	}(React.Component);
	
	Tabs.propTypes = {
	  tabs: React.PropTypes.array.isRequired,
	  defaultTab: React.PropTypes.string,
	  updateURL: React.PropTypes.bool
	};
	Tabs.defaultProps = {
	  onTabChange: function onTabChange() {},
	  // Set updateURL to default to true but allow for change
	  // Nested tabs should set this variable to false
	  updateURL: true
	};
	
	/**
	 * Allows to dynamically render vertical tabs corresponding to tab panes.
	 */
	
	var VerticalTabs = function (_React$Component2) {
	  _inherits(VerticalTabs, _React$Component2);
	
	  function VerticalTabs(props) {
	    _classCallCheck(this, VerticalTabs);
	
	    var _this2 = _possibleConstructorReturn(this, (VerticalTabs.__proto__ || Object.getPrototypeOf(VerticalTabs)).call(this, props));
	
	    var hash = window.location.hash;
	    var activeTab = "";
	
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
	
	    _this2.handleClick = _this2.handleClick.bind(_this2);
	    _this2.getTabs = _this2.getTabs.bind(_this2);
	    _this2.getTabPanes = _this2.getTabPanes.bind(_this2);
	    return _this2;
	  }
	
	  _createClass(VerticalTabs, [{
	    key: 'handleClick',
	    value: function handleClick(tabId, e) {
	      this.setState({ activeTab: tabId });
	      this.props.onTabChange(tabId);
	
	      // Add tab href to URL querystring and scroll the page to top
	      if (this.props.updateURL) {
	        var scrollDistance = $('body').scrollTop() || $('html').scrollTop();
	        window.location.hash = e.target.hash;
	        $('html,body').scrollTop(scrollDistance);
	      }
	    }
	  }, {
	    key: 'getTabs',
	    value: function getTabs() {
	      var tabs = this.props.tabs.map(function (tab) {
	        var tabClass = this.state.activeTab === tab.id ? 'active' : null;
	        var href = "#" + tab.id;
	        var tabID = "tab-" + tab.id;
	        return React.createElement(
	          'li',
	          {
	            role: 'presentation',
	            className: tabClass,
	            key: tab.id
	          },
	          React.createElement(
	            'a',
	            { id: tabID,
	              href: href,
	              role: 'tab',
	              'data-toggle': 'tab',
	              onClick: this.handleClick.bind(null, tab.id)
	            },
	            tab.label
	          )
	        );
	      }.bind(this));
	
	      return tabs;
	    }
	  }, {
	    key: 'getTabPanes',
	    value: function getTabPanes() {
	      var tabPanes = React.Children.map(this.props.children, function (child, key) {
	        if (child) {
	          return React.cloneElement(child, {
	            activeTab: this.state.activeTab,
	            key: key
	          });
	        }
	      }.bind(this));
	
	      return tabPanes;
	    }
	  }, {
	    key: 'render',
	    value: function render() {
	      var tabs = this.getTabs();
	      var tabPanes = this.getTabPanes();
	      var tabStyle = {
	        marginLeft: 0,
	        marginBottom: '5px'
	      };
	
	      return React.createElement(
	        'div',
	        null,
	        React.createElement(
	          'div',
	          { className: 'tabbable col-md-3 col-sm-3' },
	          React.createElement(
	            'ul',
	            { className: 'nav nav-pills nav-stacked', role: 'tablist', style: tabStyle },
	            tabs
	          )
	        ),
	        React.createElement(
	          'div',
	          { className: 'tab-content col-md-9 col-sm-9' },
	          tabPanes
	        )
	      );
	    }
	  }]);
	
	  return VerticalTabs;
	}(React.Component);
	
	VerticalTabs.propTypes = {
	  tabs: React.PropTypes.array.isRequired,
	  defaultTab: React.PropTypes.string,
	  updateURL: React.PropTypes.bool
	};
	VerticalTabs.defaultProps = {
	  onTabChange: function onTabChange() {},
	  // Set updateURL to default to true but allow for change
	  // Nested tabs should set this variable to false
	  updateURL: true
	};
	
	/*
	 * TabPane component.
	 * Used to wrap content for every tab.
	 */
	
	var TabPane = function (_React$Component3) {
	  _inherits(TabPane, _React$Component3);
	
	  function TabPane() {
	    _classCallCheck(this, TabPane);
	
	    return _possibleConstructorReturn(this, (TabPane.__proto__ || Object.getPrototypeOf(TabPane)).apply(this, arguments));
	  }
	
	  _createClass(TabPane, [{
	    key: 'render',
	    value: function render() {
	      var classList = "tab-pane";
	      var title = void 0;
	
	      if (this.props.TabId === this.props.activeTab) {
	        classList += " active";
	      }
	      if (this.props.Title) {
	        title = React.createElement(
	          'h1',
	          null,
	          this.props.Title
	        );
	      }
	
	      return React.createElement(
	        'div',
	        { role: 'tabpanel', className: classList, id: this.props.TabId },
	        title,
	        this.props.children
	      );
	    }
	  }]);
	
	  return TabPane;
	}(React.Component);
	
	TabPane.propTypes = {
	  TabId: React.PropTypes.string.isRequired,
	  Title: React.PropTypes.string,
	  activeTab: React.PropTypes.string
	};
	
	exports.Tabs = Tabs;
	exports.VerticalTabs = VerticalTabs;
	exports.TabPane = TabPane;

/***/ },
/* 5 */
/***/ function(module, exports, __webpack_require__) {

	"use strict";
	
	Object.defineProperty(exports, "__esModule", {
	  value: true
	});
	
	var _createClass = function () { function defineProperties(target, props) { for (var i = 0; i < props.length; i++) { var descriptor = props[i]; descriptor.enumerable = descriptor.enumerable || false; descriptor.configurable = true; if ("value" in descriptor) descriptor.writable = true; Object.defineProperty(target, descriptor.key, descriptor); } } return function (Constructor, protoProps, staticProps) { if (protoProps) defineProperties(Constructor.prototype, protoProps); if (staticProps) defineProperties(Constructor, staticProps); return Constructor; }; }();
	
	var _Panel = __webpack_require__(3);
	
	var _Panel2 = _interopRequireDefault(_Panel);
	
	function _interopRequireDefault(obj) { return obj && obj.__esModule ? obj : { default: obj }; }
	
	function _classCallCheck(instance, Constructor) { if (!(instance instanceof Constructor)) { throw new TypeError("Cannot call a class as a function"); } }
	
	function _possibleConstructorReturn(self, call) { if (!self) { throw new ReferenceError("this hasn't been initialised - super() hasn't been called"); } return call && (typeof call === "object" || typeof call === "function") ? call : self; }
	
	function _inherits(subClass, superClass) { if (typeof superClass !== "function" && superClass !== null) { throw new TypeError("Super expression must either be null or a function, not " + typeof superClass); } subClass.prototype = Object.create(superClass && superClass.prototype, { constructor: { value: subClass, enumerable: false, writable: true, configurable: true } }); if (superClass) Object.setPrototypeOf ? Object.setPrototypeOf(subClass, superClass) : subClass.__proto__ = superClass; } /* global UploadProgress */
	
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
	var LogPanel = function (_React$Component) {
	  _inherits(LogPanel, _React$Component);
	
	  function LogPanel(props) {
	    _classCallCheck(this, LogPanel);
	
	    var _this = _possibleConstructorReturn(this, (LogPanel.__proto__ || Object.getPrototypeOf(LogPanel)).call(this, props));
	
	    _this.state = {
	      logText: "<select a row in the table below to view the upload logs>",
	      logType: "summary"
	    };
	
	    _this.initHelper = _this.initHelper.bind(_this);
	    _this.onLogTypeChange = _this.onLogTypeChange.bind(_this);
	    _this.setServerPolling = _this.setServerPolling.bind(_this);
	    _this.monitorProgress = _this.monitorProgress.bind(_this);
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
	        }
	
	        // If user clicked on the same row, it is interpreted as a de-selection:
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
	      var summary = logType === "summary";
	      var uploadProgress = this.uploadProgress;
	      var uploadId = uploadProgress.getUploadId();
	
	      // If no row was selected
	      if (!uploadId) {
	        return;
	      }
	
	      $.post(loris.BaseURL + "/imaging_uploader/ajax/getUploadSummary.php", {
	        uploadId: uploadId,
	        summary: summary
	      }, function (data) {
	        uploadProgress.setProgressFromServer(data);
	        this.setState({ logText: uploadProgress.getProgressText() });
	        // If the pipeline is still running, start polling
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
	      var uploadProgress = this.uploadProgress;
	
	      if (poll) {
	        // START POLLING
	        // If there were no POST requests being issued, start issuing some.
	        if (!this.setServerPolling.getSummaryInterval) {
	          this.setServerPolling.getSummaryInterval = setInterval(this.monitorProgress, 5000);
	        }
	        // If there were no updates to the string of dots, start updating
	        if (!this.setServerPolling.dotUpdateInterval) {
	          this.setServerPolling.dotUpdateInterval = setInterval(function () {
	            uploadProgress.updateDots();
	            this.setState({
	              logText: uploadProgress.getProgressText()
	            });
	          }, 3000);
	        }
	        // If there were no updates to the animated chars, start updating
	        if (!this.setServerPolling.animatedCharInterval) {
	          this.setServerPolling.animatedCharInterval = setInterval(function () {
	            uploadProgress.updateAnimatedCharIndex();
	            this.setState({
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
	        }
	        // Stop updating the series of dots string (if such an update was going on)
	        if (this.setServerPolling.dotUpdateInterval) {
	          clearInterval(this.setServerPolling.dotUpdateInterval);
	          this.setServerPolling.dotUpdateInterval = null;
	        }
	        // Stop updating the animated char (if such an update was going on)
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
	      this.setState({ logType: value });
	    }
	  }, {
	    key: "render",
	    value: function render() {
	      var logTypes = {
	        summary: 'Summary',
	        detailed: 'Detailed'
	      };
	
	      return React.createElement(
	        _Panel2.default,
	        { id: "log_panel", title: "Log Viewer" },
	        React.createElement(
	          FormElement,
	          { name: "log_form" },
	          React.createElement(SelectElement, {
	            name: "LogType",
	            label: "Logs to display",
	            options: logTypes,
	            onUserInput: this.onLogTypeChange,
	            value: this.state.logType,
	            emptyOption: false
	          }),
	          React.createElement(TextareaElement, {
	            name: "UploadLogs",
	            disabled: true,
	            id: "mri_upload_logs",
	            value: this.state.logText,
	            rows: 6
	          })
	        )
	      );
	    }
	  }]);
	
	  return LogPanel;
	}(React.Component);
	
	LogPanel.propTypes = {};
	LogPanel.defaultProps = {};
	
	exports.default = LogPanel;

/***/ },
/* 6 */
/***/ function(module, exports, __webpack_require__) {

	'use strict';
	
	Object.defineProperty(exports, "__esModule", {
	  value: true
	});
	
	var _createClass = function () { function defineProperties(target, props) { for (var i = 0; i < props.length; i++) { var descriptor = props[i]; descriptor.enumerable = descriptor.enumerable || false; descriptor.configurable = true; if ("value" in descriptor) descriptor.writable = true; Object.defineProperty(target, descriptor.key, descriptor); } } return function (Constructor, protoProps, staticProps) { if (protoProps) defineProperties(Constructor.prototype, protoProps); if (staticProps) defineProperties(Constructor, staticProps); return Constructor; }; }();
	
	var _ProgressBar = __webpack_require__(7);
	
	var _ProgressBar2 = _interopRequireDefault(_ProgressBar);
	
	function _interopRequireDefault(obj) { return obj && obj.__esModule ? obj : { default: obj }; }
	
	function _classCallCheck(instance, Constructor) { if (!(instance instanceof Constructor)) { throw new TypeError("Cannot call a class as a function"); } }
	
	function _possibleConstructorReturn(self, call) { if (!self) { throw new ReferenceError("this hasn't been initialised - super() hasn't been called"); } return call && (typeof call === "object" || typeof call === "function") ? call : self; }
	
	function _inherits(subClass, superClass) { if (typeof superClass !== "function" && superClass !== null) { throw new TypeError("Super expression must either be null or a function, not " + typeof superClass); } subClass.prototype = Object.create(superClass && superClass.prototype, { constructor: { value: subClass, enumerable: false, writable: true, configurable: true } }); if (superClass) Object.setPrototypeOf ? Object.setPrototypeOf(subClass, superClass) : subClass.__proto__ = superClass; }
	
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
	var UploadForm = function (_React$Component) {
	  _inherits(UploadForm, _React$Component);
	
	  function UploadForm(props) {
	    _classCallCheck(this, UploadForm);
	
	    var _this = _possibleConstructorReturn(this, (UploadForm.__proto__ || Object.getPrototypeOf(UploadForm)).call(this, props));
	
	    var form = JSON.parse(JSON.stringify(_this.props.form));
	
	    _this.state = {
	      formData: {},
	      form: form,
	      hasError: {},
	      errorMessage: {},
	      uploadProgress: -1
	    };
	
	    _this.onFormChange = _this.onFormChange.bind(_this);
	    _this.getDisabledStatus = _this.getDisabledStatus.bind(_this);
	    _this.submitForm = _this.submitForm.bind(_this);
	    _this.uploadFile = _this.uploadFile.bind(_this);
	    return _this;
	  }
	
	  _createClass(UploadForm, [{
	    key: 'componentDidMount',
	    value: function componentDidMount() {
	      // Disable fields on initial load
	      this.onFormChange(this.state.form.imagingUploadType.name, null);
	    }
	
	    /*
	     Updates values in formData
	     Deletes CandID, PSCID, and VisitLabel values if imagingUploadType is not set to 'Subject'
	     */
	
	  }, {
	    key: 'onFormChange',
	    value: function onFormChange(field, value) {
	      if (!field) return;
	
	      var form = JSON.parse(JSON.stringify(this.state.form));
	      var formData = Object.assign({}, this.state.formData);
	
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
	
	  }, {
	    key: 'getDisabledStatus',
	    value: function getDisabledStatus(imagingUploadType) {
	      if (imagingUploadType === 'Subject') {
	        return false;
	      }
	      return true;
	    }
	  }, {
	    key: 'submitForm',
	    value: function submitForm() {
	      // Validate required fields
	      var data = this.state.formData;
	      if (!data.mri_file || !data.imagingUploadType) {
	        return;
	      }
	
	      if (data.imagingUploadType === 'Subject' && (!data.candID || !data.pSCID || !data.visitLabel)) {
	        return;
	      }
	
	      // Checks if a file with a given fileName has already been uploaded
	      var fileName = data.mri_file.name;
	      var mriFile = this.props.mriList.find(function (mriFile) {
	        return mriFile.fileName.indexOf(fileName) > -1;
	      });
	
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
	        }, function (isConfirm) {
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
	          text: "A file with this name has been uploaded but has not yet started the MRI pipeline." + "\n Would you like to override the existing file?",
	          type: "warning",
	          showCancelButton: true,
	          confirmButtonText: 'Yes, I am sure!',
	          cancelButtonText: 'No, cancel it!'
	        }, function (isConfirm) {
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
	
	  }, {
	    key: 'uploadFile',
	    value: function uploadFile(overwriteFile) {
	      var _this2 = this;
	
	      var formData = this.state.formData;
	      var formObj = new FormData();
	      for (var key in formData) {
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
	        xhr: function () {
	          var xhr = new window.XMLHttpRequest();
	          xhr.upload.addEventListener("progress", function (evt) {
	            if (evt.lengthComputable) {
	              var percentage = Math.round(evt.loaded / evt.total * 100);
	              this.setState({ uploadProgress: percentage });
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
	              errorMessage[i] = "";
	              hasError[i] = false;
	            }
	          }
	          _this2.setState({ errorMessage: errorMessage, hasError: hasError });
	          swal({
	            title: "Upload Successful!",
	            type: "success"
	          }, function () {
	            window.location.assign(loris.BaseURL + "/imaging_uploader/");
	          });
	        },
	        // Upon errors in upload:
	        // - Displays pop up window with submission error message
	        // - Updates errorMessage and hasError so relevant errors are displayed on form
	        // - Returns to Upload tab
	        error: function error(_error, textStatus, errorThrown) {
	          swal({
	            title: "Submission error!",
	            type: "error"
	          });
	          var errorMessage = _this2.state.errorMessage;
	          var hasError = _this2.state.hasError;
	          errorMessage = (_error.responseJSON || {}).errors || 'Submission error!';
	          for (var i in errorMessage) {
	            if (errorMessage.hasOwnProperty(i)) {
	              errorMessage[i] = errorMessage[i].toString();
	              if (errorMessage[i].length) {
	                hasError[i] = true;
	              } else {
	                hasError[i] = false;
	              }
	            }
	          }
	          _this2.setState({ uploadProgress: -1, errorMessage: errorMessage, hasError: hasError });
	        }
	      });
	    }
	  }, {
	    key: 'render',
	    value: function render() {
	      // Bind form elements to formData
	      var form = this.state.form;
	      form.imagingUploadType.value = this.state.formData.imagingUploadType;
	      form.candID.value = this.state.formData.candID;
	      form.pSCID.value = this.state.formData.pSCID;
	      form.visitLabel.value = this.state.formData.visitLabel;
	      form.mri_file.value = this.state.formData.mri_file;
	
	      // Hide button when progress bar is shown
	      var btnClass = this.state.uploadProgress > -1 ? "btn btn-primary hide" : undefined;
	
	      var notes = React.createElement(
	        'span',
	        null,
	        'File cannot exceed ',
	        this.props.maxUploadSize,
	        React.createElement('br', null),
	        'File must be of type .tgz or tar.gz or .zip',
	        React.createElement('br', null),
	        React.createElement('br', null),
	        'For files that are ',
	        React.createElement(
	          'u',
	          null,
	          'Subject Scans'
	        ),
	        ', file name must begin with',
	        React.createElement(
	          'b',
	          null,
	          ' [PSCID]_[CandID]_[Visit Label]'
	        ),
	        React.createElement('br', null),
	        'For example, for CandID ',
	        React.createElement(
	          'i',
	          null,
	          '100000'
	        ),
	        ', PSCID ',
	        React.createElement(
	          'i',
	          null,
	          'ABC123'
	        ),
	        ', and Visit Label ',
	        React.createElement(
	          'i',
	          null,
	          'V1'
	        ),
	        ' the file name should be prefixed by:',
	        React.createElement(
	          'b',
	          null,
	          ' ABC123_100000_V1'
	        ),
	        React.createElement('br', null),
	        React.createElement('br', null),
	        'For ',
	        React.createElement(
	          'u',
	          null,
	          'inter-scanner reliability scans'
	        ),
	        ', the file name (without extension) must be of the form:',
	        React.createElement('br', null),
	        React.createElement(
	          'b',
	          null,
	          ' [site]_interscan_[subject initials]_[scanner name]_[scanner_location]_[date][scan number] '
	        ),
	        React.createElement('br', null),
	        'where',
	        React.createElement('br', null),
	        React.createElement(
	          'ul',
	          null,
	          React.createElement(
	            'li',
	            null,
	            '[site] is the three-letter site abbreviation'
	          ),
	          React.createElement(
	            'li',
	            null,
	            '[subject initials] are the subject\u2019s initials (three letters)'
	          ),
	          React.createElement(
	            'li',
	            null,
	            '[scanner name] is the name of the scanner'
	          ),
	          React.createElement(
	            'li',
	            null,
	            '[scanner location] three-letter scanner location'
	          ),
	          React.createElement(
	            'li',
	            null,
	            '[date] is the scan acquisition date in format YYYYMMDD'
	          ),
	          React.createElement(
	            'li',
	            null,
	            '[scan number] is an optional string of the form \u2019_scan1\u2019 for multi-part scans'
	          )
	        ),
	        'All the file name parts are case-insensitive. Example of a valid file name:',
	        React.createElement('br', null),
	        'UNC_interscan_BEA_trio_HOS_20190324_scan2.tar.gz'
	      );
	
	      // Returns individual form elements
	      // For CandID, PSCID, and Visit Label, disabled and required
	      // are updated depending on imagingUploadType value
	      // For all elements, hasError and errorMessage
	      // are updated depending on what values are submitted
	      return React.createElement(
	        'div',
	        { className: 'row' },
	        React.createElement(
	          'div',
	          { className: 'col-md-7' },
	          React.createElement(
	            'h3',
	            null,
	            'Upload an imaging scan'
	          ),
	          React.createElement('br', null),
	          React.createElement(
	            FormElement,
	            {
	              name: 'upload_form',
	              fileUpload: true
	            },
	            React.createElement(SelectElement, {
	              name: 'imagingUploadType',
	              label: 'Imaging Upload Type',
	              options: this.props.form.imagingUploadType.options,
	              onUserInput: this.onFormChange,
	              required: true,
	              hasError: this.state.hasError.imagingUploadType,
	              errorMessage: this.state.errorMessage.imagingUploadType,
	              value: this.state.formData.imagingUploadType
	            }),
	            React.createElement(TextboxElement, {
	              name: 'candID',
	              label: 'CandID',
	              onUserInput: this.onFormChange,
	              disabled: this.getDisabledStatus(this.state.formData.imagingUploadType),
	              required: !this.getDisabledStatus(this.state.formData.imagingUploadType),
	              hasError: this.state.hasError.candID,
	              errorMessage: this.state.errorMessage.candID,
	              value: this.state.formData.candID
	            }),
	            React.createElement(TextboxElement, {
	              name: 'pSCID',
	              label: 'PSCID',
	              onUserInput: this.onFormChange,
	              disabled: this.getDisabledStatus(this.state.formData.imagingUploadType),
	              required: !this.getDisabledStatus(this.state.formData.imagingUploadType),
	              hasError: this.state.hasError.pSCID,
	              errorMessage: this.state.errorMessage.pSCID,
	              value: this.state.formData.pSCID
	            }),
	            React.createElement(SelectElement, {
	              name: 'visitLabel',
	              label: 'Visit Label',
	              options: this.props.form.visitLabel.options,
	              onUserInput: this.onFormChange,
	              disabled: this.getDisabledStatus(this.state.formData.imagingUploadType),
	              required: !this.getDisabledStatus(this.state.formData.imagingUploadType),
	              hasError: this.state.hasError.visitLabel,
	              errorMessage: this.state.errorMessage.visitLabel,
	              value: this.state.formData.visitLabel
	            }),
	            React.createElement(FileElement, {
	              name: 'mri_file',
	              label: 'File to Upload',
	              onUserInput: this.onFormChange,
	              required: true,
	              hasError: this.state.hasError.mri_file,
	              errorMessage: this.state.errorMessage.mri_file,
	              value: this.state.formData.mri_file
	            }),
	            React.createElement(StaticElement, {
	              label: 'Notes',
	              text: notes
	            }),
	            React.createElement(
	              'div',
	              { className: 'row' },
	              React.createElement(
	                'div',
	                { className: 'col-sm-9 col-sm-offset-3' },
	                React.createElement(_ProgressBar2.default, { value: this.state.uploadProgress })
	              )
	            ),
	            React.createElement(ButtonElement, {
	              onUserInput: this.submitForm,
	              buttonClass: btnClass
	            })
	          )
	        )
	      );
	    }
	  }]);
	
	  return UploadForm;
	}(React.Component);
	
	UploadForm.propTypes = {};
	UploadForm.defaultProps = {};
	
	exports.default = UploadForm;

/***/ },
/* 7 */
/***/ function(module, exports) {

	'use strict';
	
	Object.defineProperty(exports, "__esModule", {
	  value: true
	});
	
	var _createClass = function () { function defineProperties(target, props) { for (var i = 0; i < props.length; i++) { var descriptor = props[i]; descriptor.enumerable = descriptor.enumerable || false; descriptor.configurable = true; if ("value" in descriptor) descriptor.writable = true; Object.defineProperty(target, descriptor.key, descriptor); } } return function (Constructor, protoProps, staticProps) { if (protoProps) defineProperties(Constructor.prototype, protoProps); if (staticProps) defineProperties(Constructor, staticProps); return Constructor; }; }();
	
	function _classCallCheck(instance, Constructor) { if (!(instance instanceof Constructor)) { throw new TypeError("Cannot call a class as a function"); } }
	
	function _possibleConstructorReturn(self, call) { if (!self) { throw new ReferenceError("this hasn't been initialised - super() hasn't been called"); } return call && (typeof call === "object" || typeof call === "function") ? call : self; }
	
	function _inherits(subClass, superClass) { if (typeof superClass !== "function" && superClass !== null) { throw new TypeError("Super expression must either be null or a function, not " + typeof superClass); } subClass.prototype = Object.create(superClass && superClass.prototype, { constructor: { value: subClass, enumerable: false, writable: true, configurable: true } }); if (superClass) Object.setPrototypeOf ? Object.setPrototypeOf(subClass, superClass) : subClass.__proto__ = superClass; }
	
	/**
	 * React ProgressBar.
	 *
	 * Updates UI automatically when passed a progress value between 0 and 100.
	 * To hide progress bar before/after upload, set value to -1.
	 *
	 * Note: This component relies on Bootstrap 3 progress-bar classes
	 * (http://getbootstrap.com/components/#progress)
	 */
	var ProgressBar = function (_React$Component) {
	  _inherits(ProgressBar, _React$Component);
	
	  function ProgressBar() {
	    _classCallCheck(this, ProgressBar);
	
	    return _possibleConstructorReturn(this, (ProgressBar.__proto__ || Object.getPrototypeOf(ProgressBar)).apply(this, arguments));
	  }
	
	  _createClass(ProgressBar, [{
	    key: 'render',
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
	
	      return React.createElement(
	        'div',
	        { className: 'progress', style: progressStyle },
	        React.createElement('div', {
	          className: 'progress-bar progress-bar-striped active',
	          role: 'progressbar',
	          'aria-valuemin': '0',
	          'aria-valuemax': '100',
	          'aria-valuenow': this.props.value,
	          style: { width: this.props.value + '%' }
	        }),
	        React.createElement(
	          'span',
	          { style: labelStyle },
	          this.props.value,
	          '%'
	        )
	      );
	    }
	  }]);
	
	  return ProgressBar;
	}(React.Component);
	
	ProgressBar.propTypes = {
	  value: React.PropTypes.number
	};
	ProgressBar.defaultProps = {
	  value: 0
	};
	
	exports.default = ProgressBar;

/***/ },
/* 8 */
/***/ function(module, exports) {

	'use strict';
	
	Object.defineProperty(exports, "__esModule", {
	  value: true
	});
	/* exported formatColumn */
	
	loris.hiddenHeaders = ['PatientName', 'ImagingUploadType'];
	
	/**
	 * Modify behaviour of specified column cells in the Data Table component
	 * @param {string} column - column name
	 * @param {string} cell - cell content
	 * @param {arrray} rowData - array of cell contents for a specific row
	 * @param {arrray} rowHeaders - array of table headers (column names)
	 * @return {*} a formated table cell for a given column
	 */
	function formatColumn(column, cell, rowData, rowHeaders) {
	  // If a column if set as hidden, don't display it
	  if (loris.hiddenHeaders.indexOf(column) > -1) {
	    return null;
	  }
	
	  // Create the mapping between rowHeaders and rowData in a row object.
	  var row = {};
	  rowHeaders.forEach(function (header, index) {
	    row[header] = rowData[index];
	  }, this);
	
	  // Default cell style
	  var cellStyle = {
	    whiteSpace: 'nowrap'
	  };
	
	  if (column === 'Progress') {
	    if (cell === 'Failure') {
	      cellStyle.color = '#fff';
	      return React.createElement(
	        'td',
	        { className: 'label-danger', style: cellStyle },
	        cell
	      );
	    }
	
	    if (cell === 'In Progress...') {
	      cellStyle.color = '#fff';
	      return React.createElement(
	        'td',
	        { className: 'label-warning', style: cellStyle },
	        cell
	      );
	    }
	
	    if (cell === 'Not Started') {
	      return React.createElement(
	        'td',
	        { style: cellStyle },
	        cell
	      );
	    } else {
	      var created = row['Number Of MincCreated'];
	      var inserted = row['Number Of MincInserted'];
	      return React.createElement(
	        'td',
	        { style: cellStyle },
	        cell,
	        ' (',
	        inserted,
	        ' out of ',
	        created,
	        ')'
	      );
	    }
	  }
	
	  if (column === 'Tarchive Info') {
	    if (!cell || cell === "0") {
	      return React.createElement('td', null);
	    }
	
	    var url = loris.BaseURL + '/dicom_archive/viewDetails/?tarchiveID=' + cell;
	    return React.createElement(
	      'td',
	      { style: cellStyle },
	      React.createElement(
	        'a',
	        { href: url },
	        'View Details'
	      )
	    );
	  }
	
	  if (column === 'Number Of MincInserted') {
	    if (cell > 0) {
	      return React.createElement(
	        'td',
	        { style: cellStyle },
	        React.createElement(
	          'a',
	          { onClick: handleClick.bind(null, row.CandID) },
	          cell
	        )
	      );
	    }
	  }
	
	  if (column === 'Number Of MincCreated') {
	    var violatedScans = void 0;
	    if (row['Number Of MincCreated'] - row['Number Of MincInserted'] > 0) {
	      var numViolatedScans = row['Number Of MincCreated'] - row['Number Of MincInserted'];
	
	      var patientName = row.PatientName;
	      violatedScans = React.createElement(
	        'a',
	        { onClick: openViolatedScans.bind(null, patientName) },
	        '(',
	        numViolatedScans,
	        ' violated scans)'
	      );
	    }
	
	    return React.createElement(
	      'td',
	      { style: cellStyle },
	      cell,
	      '\xA0',
	      violatedScans
	    );
	  }
	
	  /**
	   * Handles clicks on 'Number Of MincInserted' cells
	   *
	   * @param {string} dccid - dccid
	   * @param {object} e - event info
	   */
	  function handleClick(dccid, e) {
	    loris.loadFilteredMenuClickHandler('imaging_browser/', {
	      DCCID: dccid
	    })(e);
	  }
	
	  /**
	   * Opens MRI Violations for when there are violated scans
	   *
	   * @param {string} patientName - Patient name of the form PSCID_DCCID_VisitLabel
	   * @param {object} e - event info
	   */
	  function openViolatedScans(patientName, e) {
	    loris.loadFilteredMenuClickHandler('mri_violations/', {
	      PatientName: patientName
	    })(e);
	  }
	
	  return React.createElement(
	    'td',
	    { style: cellStyle },
	    cell
	  );
	}
	
	exports.default = formatColumn;

/***/ }
/******/ ]);
//# sourceMappingURL=index.js.map