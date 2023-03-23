/******/ (() => { // webpackBootstrap
/******/ 	var __webpack_modules__ = ({

/***/ "./jsx/Loader.js":
/*!***********************!*\
  !*** ./jsx/Loader.js ***!
  \***********************/
/***/ ((__unused_webpack_module, __webpack_exports__, __webpack_require__) => {

"use strict";
__webpack_require__.r(__webpack_exports__);
/* harmony export */ __webpack_require__.d(__webpack_exports__, {
/* harmony export */   "default": () => (__WEBPACK_DEFAULT_EXPORT__)
/* harmony export */ });
/* harmony import */ var prop_types__WEBPACK_IMPORTED_MODULE_0__ = __webpack_require__(/*! prop-types */ "./node_modules/prop-types/index.js");
/* harmony import */ var prop_types__WEBPACK_IMPORTED_MODULE_0___default = /*#__PURE__*/__webpack_require__.n(prop_types__WEBPACK_IMPORTED_MODULE_0__);
/**
 * This file contains the React component for Loader
 *
 * @author Henri Rabalais
 * @version 1.0.0
 */

/**
 * Loader is a React component which shows a spinner wheel while
 * something is loading.
 *
 * @param {array} props - The React props
 * @return {HTMLElement} - Loader React component
 */

function Loader(props) {
  return /*#__PURE__*/React.createElement("div", {
    className: "loader",
    style: {
      width: parseInt(props.size),
      height: parseInt(props.size)
    }
  });
}

Loader.propTypes = {
  size: (prop_types__WEBPACK_IMPORTED_MODULE_0___default().string)
};
Loader.defaultProps = {
  size: '120'
};
/* harmony default export */ const __WEBPACK_DEFAULT_EXPORT__ = (Loader);

/***/ }),

/***/ "./jsx/Tabs.js":
/*!*********************!*\
  !*** ./jsx/Tabs.js ***!
  \*********************/
/***/ ((__unused_webpack_module, __webpack_exports__, __webpack_require__) => {

"use strict";
__webpack_require__.r(__webpack_exports__);
/* harmony export */ __webpack_require__.d(__webpack_exports__, {
/* harmony export */   "TabPane": () => (/* binding */ TabPane),
/* harmony export */   "Tabs": () => (/* binding */ Tabs),
/* harmony export */   "VerticalTabs": () => (/* binding */ VerticalTabs)
/* harmony export */ });
/* harmony import */ var _babel_runtime_helpers_classCallCheck__WEBPACK_IMPORTED_MODULE_0__ = __webpack_require__(/*! @babel/runtime/helpers/classCallCheck */ "./node_modules/@babel/runtime/helpers/esm/classCallCheck.js");
/* harmony import */ var _babel_runtime_helpers_createClass__WEBPACK_IMPORTED_MODULE_1__ = __webpack_require__(/*! @babel/runtime/helpers/createClass */ "./node_modules/@babel/runtime/helpers/esm/createClass.js");
/* harmony import */ var _babel_runtime_helpers_assertThisInitialized__WEBPACK_IMPORTED_MODULE_2__ = __webpack_require__(/*! @babel/runtime/helpers/assertThisInitialized */ "./node_modules/@babel/runtime/helpers/esm/assertThisInitialized.js");
/* harmony import */ var _babel_runtime_helpers_inherits__WEBPACK_IMPORTED_MODULE_3__ = __webpack_require__(/*! @babel/runtime/helpers/inherits */ "./node_modules/@babel/runtime/helpers/esm/inherits.js");
/* harmony import */ var _babel_runtime_helpers_possibleConstructorReturn__WEBPACK_IMPORTED_MODULE_4__ = __webpack_require__(/*! @babel/runtime/helpers/possibleConstructorReturn */ "./node_modules/@babel/runtime/helpers/esm/possibleConstructorReturn.js");
/* harmony import */ var _babel_runtime_helpers_getPrototypeOf__WEBPACK_IMPORTED_MODULE_5__ = __webpack_require__(/*! @babel/runtime/helpers/getPrototypeOf */ "./node_modules/@babel/runtime/helpers/esm/getPrototypeOf.js");
/* harmony import */ var react__WEBPACK_IMPORTED_MODULE_6__ = __webpack_require__(/*! react */ "react");
/* harmony import */ var react__WEBPACK_IMPORTED_MODULE_6___default = /*#__PURE__*/__webpack_require__.n(react__WEBPACK_IMPORTED_MODULE_6__);
/* harmony import */ var prop_types__WEBPACK_IMPORTED_MODULE_7__ = __webpack_require__(/*! prop-types */ "./node_modules/prop-types/index.js");
/* harmony import */ var prop_types__WEBPACK_IMPORTED_MODULE_7___default = /*#__PURE__*/__webpack_require__.n(prop_types__WEBPACK_IMPORTED_MODULE_7__);







function _createSuper(Derived) { var hasNativeReflectConstruct = _isNativeReflectConstruct(); return function _createSuperInternal() { var Super = (0,_babel_runtime_helpers_getPrototypeOf__WEBPACK_IMPORTED_MODULE_5__["default"])(Derived), result; if (hasNativeReflectConstruct) { var NewTarget = (0,_babel_runtime_helpers_getPrototypeOf__WEBPACK_IMPORTED_MODULE_5__["default"])(this).constructor; result = Reflect.construct(Super, arguments, NewTarget); } else { result = Super.apply(this, arguments); } return (0,_babel_runtime_helpers_possibleConstructorReturn__WEBPACK_IMPORTED_MODULE_4__["default"])(this, result); }; }

function _isNativeReflectConstruct() { if (typeof Reflect === "undefined" || !Reflect.construct) return false; if (Reflect.construct.sham) return false; if (typeof Proxy === "function") return true; try { Boolean.prototype.valueOf.call(Reflect.construct(Boolean, [], function () {})); return true; } catch (e) { return false; } }

/**
 * This file contains React components for Tabs component.
 *
 * @author Loris Team
 * @version 1.1.0
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
  (0,_babel_runtime_helpers_inherits__WEBPACK_IMPORTED_MODULE_3__["default"])(Tabs, _Component);

  var _super = _createSuper(Tabs);

  /**
   * @constructor
   * @param {object} props - React Component properties
   */
  function Tabs(props) {
    var _this;

    (0,_babel_runtime_helpers_classCallCheck__WEBPACK_IMPORTED_MODULE_0__["default"])(this, Tabs);

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
    _this.handleClick = _this.handleClick.bind((0,_babel_runtime_helpers_assertThisInitialized__WEBPACK_IMPORTED_MODULE_2__["default"])(_this));
    _this.getTabs = _this.getTabs.bind((0,_babel_runtime_helpers_assertThisInitialized__WEBPACK_IMPORTED_MODULE_2__["default"])(_this));
    _this.getTabPanes = _this.getTabPanes.bind((0,_babel_runtime_helpers_assertThisInitialized__WEBPACK_IMPORTED_MODULE_2__["default"])(_this));
    return _this;
  }
  /**
   * Handle clicks on a tab header to change the active
   * tab. If this.props.updateURL is set, update the window
   * URL and scroll to the top of the page.
   *
   * @param {number} tabId -- The tab clicked on
   * @param {Event} e -- The click event
   */


  (0,_babel_runtime_helpers_createClass__WEBPACK_IMPORTED_MODULE_1__["default"])(Tabs, [{
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
        return /*#__PURE__*/react__WEBPACK_IMPORTED_MODULE_6___default().createElement("li", {
          role: "presentation",
          className: tabClass,
          key: tab.id
        }, /*#__PURE__*/react__WEBPACK_IMPORTED_MODULE_6___default().createElement("a", {
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
      var tabPanes = react__WEBPACK_IMPORTED_MODULE_6___default().Children.map(this.props.children, function (child, key) {
        if (child) {
          return /*#__PURE__*/react__WEBPACK_IMPORTED_MODULE_6___default().cloneElement(child, {
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
      return /*#__PURE__*/react__WEBPACK_IMPORTED_MODULE_6___default().createElement("div", null, /*#__PURE__*/react__WEBPACK_IMPORTED_MODULE_6___default().createElement("ul", {
        className: "nav nav-tabs",
        role: "tablist",
        style: tabStyle
      }, tabs), /*#__PURE__*/react__WEBPACK_IMPORTED_MODULE_6___default().createElement("div", {
        className: "tab-content"
      }, tabPanes));
    }
  }]);

  return Tabs;
}(react__WEBPACK_IMPORTED_MODULE_6__.Component);

Tabs.propTypes = {
  tabs: (prop_types__WEBPACK_IMPORTED_MODULE_7___default().array.isRequired),
  defaultTab: (prop_types__WEBPACK_IMPORTED_MODULE_7___default().string),
  updateURL: (prop_types__WEBPACK_IMPORTED_MODULE_7___default().bool),
  onTabChange: (prop_types__WEBPACK_IMPORTED_MODULE_7___default().func),
  children: (prop_types__WEBPACK_IMPORTED_MODULE_7___default().node)
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
  (0,_babel_runtime_helpers_inherits__WEBPACK_IMPORTED_MODULE_3__["default"])(VerticalTabs, _Component2);

  var _super2 = _createSuper(VerticalTabs);

  /**
   * Construct the Component
   *
   * @param {array} props - array of React props
   */
  function VerticalTabs(props) {
    var _this2;

    (0,_babel_runtime_helpers_classCallCheck__WEBPACK_IMPORTED_MODULE_0__["default"])(this, VerticalTabs);

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
    _this2.handleClick = _this2.handleClick.bind((0,_babel_runtime_helpers_assertThisInitialized__WEBPACK_IMPORTED_MODULE_2__["default"])(_this2));
    _this2.getTabs = _this2.getTabs.bind((0,_babel_runtime_helpers_assertThisInitialized__WEBPACK_IMPORTED_MODULE_2__["default"])(_this2));
    _this2.getTabPanes = _this2.getTabPanes.bind((0,_babel_runtime_helpers_assertThisInitialized__WEBPACK_IMPORTED_MODULE_2__["default"])(_this2));
    return _this2;
  }
  /**
   * Handle clicks on a tab header to change the active
   * tab. If this.props.updateURL is set, update the window
   * URL and scroll to the top of the page.
   *
   * @param {number} tabId -- The tab clicked on
   * @param {Event} e -- The click event
   */


  (0,_babel_runtime_helpers_createClass__WEBPACK_IMPORTED_MODULE_1__["default"])(VerticalTabs, [{
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
        return /*#__PURE__*/react__WEBPACK_IMPORTED_MODULE_6___default().createElement("li", {
          role: "presentation",
          className: tabClass,
          key: tab.id
        }, /*#__PURE__*/react__WEBPACK_IMPORTED_MODULE_6___default().createElement("a", {
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
      var tabPanes = react__WEBPACK_IMPORTED_MODULE_6___default().Children.map(this.props.children, function (child, key) {
        if (child) {
          return /*#__PURE__*/react__WEBPACK_IMPORTED_MODULE_6___default().cloneElement(child, {
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
      return /*#__PURE__*/react__WEBPACK_IMPORTED_MODULE_6___default().createElement("div", null, /*#__PURE__*/react__WEBPACK_IMPORTED_MODULE_6___default().createElement("div", {
        className: "tabbable col-md-3 col-sm-3"
      }, /*#__PURE__*/react__WEBPACK_IMPORTED_MODULE_6___default().createElement("ul", {
        className: "nav nav-pills nav-stacked",
        role: "tablist",
        style: tabStyle
      }, tabs)), /*#__PURE__*/react__WEBPACK_IMPORTED_MODULE_6___default().createElement("div", {
        className: "tab-content col-md-9 col-sm-9"
      }, tabPanes));
    }
  }]);

  return VerticalTabs;
}(react__WEBPACK_IMPORTED_MODULE_6__.Component);

VerticalTabs.propTypes = {
  tabs: (prop_types__WEBPACK_IMPORTED_MODULE_7___default().array.isRequired),
  defaultTab: (prop_types__WEBPACK_IMPORTED_MODULE_7___default().string),
  updateURL: (prop_types__WEBPACK_IMPORTED_MODULE_7___default().bool),
  onTabChange: (prop_types__WEBPACK_IMPORTED_MODULE_7___default().func),
  children: (prop_types__WEBPACK_IMPORTED_MODULE_7___default().node)
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
  (0,_babel_runtime_helpers_inherits__WEBPACK_IMPORTED_MODULE_3__["default"])(TabPane, _Component3);

  var _super3 = _createSuper(TabPane);

  function TabPane() {
    (0,_babel_runtime_helpers_classCallCheck__WEBPACK_IMPORTED_MODULE_0__["default"])(this, TabPane);

    return _super3.apply(this, arguments);
  }

  (0,_babel_runtime_helpers_createClass__WEBPACK_IMPORTED_MODULE_1__["default"])(TabPane, [{
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
        title = /*#__PURE__*/react__WEBPACK_IMPORTED_MODULE_6___default().createElement("h1", null, this.props.Title);
      }

      return /*#__PURE__*/react__WEBPACK_IMPORTED_MODULE_6___default().createElement("div", {
        role: "tabpanel",
        className: classList,
        id: this.props.TabId
      }, title, this.props.children);
    }
  }]);

  return TabPane;
}(react__WEBPACK_IMPORTED_MODULE_6__.Component);

TabPane.propTypes = {
  TabId: (prop_types__WEBPACK_IMPORTED_MODULE_7___default().string.isRequired),
  Title: (prop_types__WEBPACK_IMPORTED_MODULE_7___default().string),
  activeTab: (prop_types__WEBPACK_IMPORTED_MODULE_7___default().string),
  children: (prop_types__WEBPACK_IMPORTED_MODULE_7___default().node)
};


/***/ }),

/***/ "./modules/candidate_parameters/jsx/CandidateDOB.js":
/*!**********************************************************!*\
  !*** ./modules/candidate_parameters/jsx/CandidateDOB.js ***!
  \**********************************************************/
/***/ ((__unused_webpack_module, __webpack_exports__, __webpack_require__) => {

"use strict";
__webpack_require__.r(__webpack_exports__);
/* harmony export */ __webpack_require__.d(__webpack_exports__, {
/* harmony export */   "default": () => (__WEBPACK_DEFAULT_EXPORT__)
/* harmony export */ });
/* harmony import */ var _babel_runtime_helpers_classCallCheck__WEBPACK_IMPORTED_MODULE_0__ = __webpack_require__(/*! @babel/runtime/helpers/classCallCheck */ "./node_modules/@babel/runtime/helpers/esm/classCallCheck.js");
/* harmony import */ var _babel_runtime_helpers_createClass__WEBPACK_IMPORTED_MODULE_1__ = __webpack_require__(/*! @babel/runtime/helpers/createClass */ "./node_modules/@babel/runtime/helpers/esm/createClass.js");
/* harmony import */ var _babel_runtime_helpers_assertThisInitialized__WEBPACK_IMPORTED_MODULE_2__ = __webpack_require__(/*! @babel/runtime/helpers/assertThisInitialized */ "./node_modules/@babel/runtime/helpers/esm/assertThisInitialized.js");
/* harmony import */ var _babel_runtime_helpers_inherits__WEBPACK_IMPORTED_MODULE_3__ = __webpack_require__(/*! @babel/runtime/helpers/inherits */ "./node_modules/@babel/runtime/helpers/esm/inherits.js");
/* harmony import */ var _babel_runtime_helpers_possibleConstructorReturn__WEBPACK_IMPORTED_MODULE_4__ = __webpack_require__(/*! @babel/runtime/helpers/possibleConstructorReturn */ "./node_modules/@babel/runtime/helpers/esm/possibleConstructorReturn.js");
/* harmony import */ var _babel_runtime_helpers_getPrototypeOf__WEBPACK_IMPORTED_MODULE_5__ = __webpack_require__(/*! @babel/runtime/helpers/getPrototypeOf */ "./node_modules/@babel/runtime/helpers/esm/getPrototypeOf.js");
/* harmony import */ var react__WEBPACK_IMPORTED_MODULE_6__ = __webpack_require__(/*! react */ "react");
/* harmony import */ var react__WEBPACK_IMPORTED_MODULE_6___default = /*#__PURE__*/__webpack_require__.n(react__WEBPACK_IMPORTED_MODULE_6__);
/* harmony import */ var prop_types__WEBPACK_IMPORTED_MODULE_8__ = __webpack_require__(/*! prop-types */ "./node_modules/prop-types/index.js");
/* harmony import */ var prop_types__WEBPACK_IMPORTED_MODULE_8___default = /*#__PURE__*/__webpack_require__.n(prop_types__WEBPACK_IMPORTED_MODULE_8__);
/* harmony import */ var Loader__WEBPACK_IMPORTED_MODULE_7__ = __webpack_require__(/*! Loader */ "./jsx/Loader.js");







function _createSuper(Derived) { var hasNativeReflectConstruct = _isNativeReflectConstruct(); return function _createSuperInternal() { var Super = (0,_babel_runtime_helpers_getPrototypeOf__WEBPACK_IMPORTED_MODULE_5__["default"])(Derived), result; if (hasNativeReflectConstruct) { var NewTarget = (0,_babel_runtime_helpers_getPrototypeOf__WEBPACK_IMPORTED_MODULE_5__["default"])(this).constructor; result = Reflect.construct(Super, arguments, NewTarget); } else { result = Super.apply(this, arguments); } return (0,_babel_runtime_helpers_possibleConstructorReturn__WEBPACK_IMPORTED_MODULE_4__["default"])(this, result); }; }

function _isNativeReflectConstruct() { if (typeof Reflect === "undefined" || !Reflect.construct) return false; if (Reflect.construct.sham) return false; if (typeof Proxy === "function") return true; try { Boolean.prototype.valueOf.call(Reflect.construct(Boolean, [], function () {})); return true; } catch (e) { return false; } }





var CandidateDOB = /*#__PURE__*/function (_Component) {
  (0,_babel_runtime_helpers_inherits__WEBPACK_IMPORTED_MODULE_3__["default"])(CandidateDOB, _Component);

  var _super = _createSuper(CandidateDOB);

  function CandidateDOB(props) {
    var _this;

    (0,_babel_runtime_helpers_classCallCheck__WEBPACK_IMPORTED_MODULE_0__["default"])(this, CandidateDOB);

    _this = _super.call(this, props);
    _this.state = {
      data: {},
      formData: {
        dob: null
      },
      error: false,
      isLoaded: false
    };
    _this.fetchData = _this.fetchData.bind((0,_babel_runtime_helpers_assertThisInitialized__WEBPACK_IMPORTED_MODULE_2__["default"])(_this));
    _this.setFormData = _this.setFormData.bind((0,_babel_runtime_helpers_assertThisInitialized__WEBPACK_IMPORTED_MODULE_2__["default"])(_this));
    _this.handleSubmit = _this.handleSubmit.bind((0,_babel_runtime_helpers_assertThisInitialized__WEBPACK_IMPORTED_MODULE_2__["default"])(_this));
    return _this;
  }

  (0,_babel_runtime_helpers_createClass__WEBPACK_IMPORTED_MODULE_1__["default"])(CandidateDOB, [{
    key: "componentDidMount",
    value: function componentDidMount() {
      var _this2 = this;

      this.fetchData().then(function () {
        return _this2.setState({
          isLoaded: true
        });
      });
    }
  }, {
    key: "fetchData",
    value: function fetchData() {
      var _this3 = this;

      return fetch(this.props.dataURL, {
        credentials: 'same-origin'
      }).then(function (resp) {
        return resp.json();
      }).then(function (data) {
        return _this3.setState({
          data: data,
          formData: data
        });
      })["catch"](function (error) {
        _this3.setState({
          error: true
        });

        console.error(error);
      });
    }
  }, {
    key: "setFormData",
    value: function setFormData(formElement, value) {
      var formData = this.state.formData;
      formData[formElement] = value;
      this.setState({
        formData: formData
      });
    }
  }, {
    key: "render",
    value: function render() {
      if (this.state.error) {
        return /*#__PURE__*/react__WEBPACK_IMPORTED_MODULE_6___default().createElement("h3", null, "An error occured while loading the page.");
      }

      if (!this.state.isLoaded) {
        return /*#__PURE__*/react__WEBPACK_IMPORTED_MODULE_6___default().createElement(Loader__WEBPACK_IMPORTED_MODULE_7__["default"], null);
      }

      var disabled = true;
      var updateButton = null;

      if (loris.userHasPermission('candidate_dob_edit')) {
        disabled = false;
        updateButton = /*#__PURE__*/react__WEBPACK_IMPORTED_MODULE_6___default().createElement(ButtonElement, {
          label: "Update"
        });
      }

      return /*#__PURE__*/react__WEBPACK_IMPORTED_MODULE_6___default().createElement("div", {
        className: "row"
      }, /*#__PURE__*/react__WEBPACK_IMPORTED_MODULE_6___default().createElement(FormElement, {
        name: "candidateDOB",
        onSubmit: this.handleSubmit,
        ref: "form",
        "class": "col-md-6"
      }, /*#__PURE__*/react__WEBPACK_IMPORTED_MODULE_6___default().createElement(StaticElement, {
        label: "PSCID",
        text: this.state.data.pscid
      }), /*#__PURE__*/react__WEBPACK_IMPORTED_MODULE_6___default().createElement(StaticElement, {
        label: "DCCID",
        text: this.state.data.candID
      }), /*#__PURE__*/react__WEBPACK_IMPORTED_MODULE_6___default().createElement(StaticElement, {
        label: "Disclaimer:",
        text: "Any changes to the date of birth requires an administrator to run the fix_candidate_age script.",
        "class": "form-control-static text-danger bg-danger col-sm-10"
      }), /*#__PURE__*/react__WEBPACK_IMPORTED_MODULE_6___default().createElement(DateElement, {
        label: "Date Of Birth:",
        name: "dob",
        value: this.state.formData.dob,
        onUserInput: this.setFormData,
        disabled: disabled,
        required: true
      }), updateButton));
    }
    /**
     * Handles form submission
     *
     * @param {event} e - Form submission event
     */

  }, {
    key: "handleSubmit",
    value: function handleSubmit(e) {
      var _this4 = this;

      e.preventDefault();
      var today = new Date();
      var dd = String(today.getDate()).padStart(2, '0');
      var mm = String(today.getMonth() + 1).padStart(2, '0'); // January is 0!

      var yyyy = today.getFullYear();
      today = yyyy + '-' + mm + '-' + dd;
      var dob = this.state.formData.dob ? this.state.formData.dob : null;

      if (dob > today) {
        swal({
          title: 'Error!',
          text: 'Date of birth cannot be later than today!',
          type: 'error',
          confrimButtonText: 'OK'
        });
        return;
      } // Set form data and upload the media file


      var formData = this.state.formData;
      var formObject = new FormData();

      for (var key in formData) {
        if (formData.hasOwnProperty(key)) {
          if (formData[key] !== '') {
            formObject.append(key, formData[key]);
          }
        }
      }

      formObject.append('tab', this.props.tabName); // IBIS SPECIFIC OVERRIDE CODE
      // Add proper error handling to handle error when study consent = no

      fetch(this.props.action, {
        method: 'POST',
        cache: 'no-cache',
        credentials: 'same-origin',
        body: formObject
      }).then(function (response) {
        return new Promise(function (resolve) {
          return response.json().then(function (json) {
            return resolve({
              status: response.status,
              ok: response.ok,
              json: json
            });
          });
        });
      }).then(function (_ref) {
        var status = _ref.status,
            json = _ref.json,
            ok = _ref.ok;

        if (ok && status === 200) {
          swal({
            title: 'Success!',
            text: 'Date of birth updated!',
            type: 'success',
            confrimButtonText: 'OK'
          }, function (result) {
            if (result) {
              _this4.fetchData();
            }
          });
        } else {
          var error = json.error ? json.error : 'Something went wrong.';
          swal({
            title: 'Error!',
            text: error,
            type: 'error',
            confrimButtonText: 'OK'
          });
        }
      })["catch"](function (error) {
        console.error(error);
      }); // IBIS SPECIFIC OVERRIDE CODE ENDS HERE
    }
  }]);

  return CandidateDOB;
}(react__WEBPACK_IMPORTED_MODULE_6__.Component);

CandidateDOB.propTypes = {
  dataURL: (prop_types__WEBPACK_IMPORTED_MODULE_8___default().string),
  tabName: (prop_types__WEBPACK_IMPORTED_MODULE_8___default().string),
  action: (prop_types__WEBPACK_IMPORTED_MODULE_8___default().string)
};
/* harmony default export */ const __WEBPACK_DEFAULT_EXPORT__ = (CandidateDOB);

/***/ }),

/***/ "./modules/candidate_parameters/jsx/CandidateDOD.js":
/*!**********************************************************!*\
  !*** ./modules/candidate_parameters/jsx/CandidateDOD.js ***!
  \**********************************************************/
/***/ ((__unused_webpack_module, __webpack_exports__, __webpack_require__) => {

"use strict";
__webpack_require__.r(__webpack_exports__);
/* harmony export */ __webpack_require__.d(__webpack_exports__, {
/* harmony export */   "default": () => (__WEBPACK_DEFAULT_EXPORT__)
/* harmony export */ });
/* harmony import */ var _babel_runtime_helpers_classCallCheck__WEBPACK_IMPORTED_MODULE_0__ = __webpack_require__(/*! @babel/runtime/helpers/classCallCheck */ "./node_modules/@babel/runtime/helpers/esm/classCallCheck.js");
/* harmony import */ var _babel_runtime_helpers_createClass__WEBPACK_IMPORTED_MODULE_1__ = __webpack_require__(/*! @babel/runtime/helpers/createClass */ "./node_modules/@babel/runtime/helpers/esm/createClass.js");
/* harmony import */ var _babel_runtime_helpers_assertThisInitialized__WEBPACK_IMPORTED_MODULE_2__ = __webpack_require__(/*! @babel/runtime/helpers/assertThisInitialized */ "./node_modules/@babel/runtime/helpers/esm/assertThisInitialized.js");
/* harmony import */ var _babel_runtime_helpers_inherits__WEBPACK_IMPORTED_MODULE_3__ = __webpack_require__(/*! @babel/runtime/helpers/inherits */ "./node_modules/@babel/runtime/helpers/esm/inherits.js");
/* harmony import */ var _babel_runtime_helpers_possibleConstructorReturn__WEBPACK_IMPORTED_MODULE_4__ = __webpack_require__(/*! @babel/runtime/helpers/possibleConstructorReturn */ "./node_modules/@babel/runtime/helpers/esm/possibleConstructorReturn.js");
/* harmony import */ var _babel_runtime_helpers_getPrototypeOf__WEBPACK_IMPORTED_MODULE_5__ = __webpack_require__(/*! @babel/runtime/helpers/getPrototypeOf */ "./node_modules/@babel/runtime/helpers/esm/getPrototypeOf.js");
/* harmony import */ var react__WEBPACK_IMPORTED_MODULE_6__ = __webpack_require__(/*! react */ "react");
/* harmony import */ var react__WEBPACK_IMPORTED_MODULE_6___default = /*#__PURE__*/__webpack_require__.n(react__WEBPACK_IMPORTED_MODULE_6__);
/* harmony import */ var prop_types__WEBPACK_IMPORTED_MODULE_8__ = __webpack_require__(/*! prop-types */ "./node_modules/prop-types/index.js");
/* harmony import */ var prop_types__WEBPACK_IMPORTED_MODULE_8___default = /*#__PURE__*/__webpack_require__.n(prop_types__WEBPACK_IMPORTED_MODULE_8__);
/* harmony import */ var Loader__WEBPACK_IMPORTED_MODULE_7__ = __webpack_require__(/*! Loader */ "./jsx/Loader.js");







function _createSuper(Derived) { var hasNativeReflectConstruct = _isNativeReflectConstruct(); return function _createSuperInternal() { var Super = (0,_babel_runtime_helpers_getPrototypeOf__WEBPACK_IMPORTED_MODULE_5__["default"])(Derived), result; if (hasNativeReflectConstruct) { var NewTarget = (0,_babel_runtime_helpers_getPrototypeOf__WEBPACK_IMPORTED_MODULE_5__["default"])(this).constructor; result = Reflect.construct(Super, arguments, NewTarget); } else { result = Super.apply(this, arguments); } return (0,_babel_runtime_helpers_possibleConstructorReturn__WEBPACK_IMPORTED_MODULE_4__["default"])(this, result); }; }

function _isNativeReflectConstruct() { if (typeof Reflect === "undefined" || !Reflect.construct) return false; if (Reflect.construct.sham) return false; if (typeof Proxy === "function") return true; try { Boolean.prototype.valueOf.call(Reflect.construct(Boolean, [], function () {})); return true; } catch (e) { return false; } }





var CandidateDOD = /*#__PURE__*/function (_Component) {
  (0,_babel_runtime_helpers_inherits__WEBPACK_IMPORTED_MODULE_3__["default"])(CandidateDOD, _Component);

  var _super = _createSuper(CandidateDOD);

  function CandidateDOD(props) {
    var _this;

    (0,_babel_runtime_helpers_classCallCheck__WEBPACK_IMPORTED_MODULE_0__["default"])(this, CandidateDOD);

    _this = _super.call(this, props);
    _this.state = {
      data: [],
      formData: {},
      error: false,
      isLoaded: false
    };
    _this.fetchData = _this.fetchData.bind((0,_babel_runtime_helpers_assertThisInitialized__WEBPACK_IMPORTED_MODULE_2__["default"])(_this));
    _this.setFormData = _this.setFormData.bind((0,_babel_runtime_helpers_assertThisInitialized__WEBPACK_IMPORTED_MODULE_2__["default"])(_this));
    _this.handleSubmit = _this.handleSubmit.bind((0,_babel_runtime_helpers_assertThisInitialized__WEBPACK_IMPORTED_MODULE_2__["default"])(_this));
    return _this;
  }

  (0,_babel_runtime_helpers_createClass__WEBPACK_IMPORTED_MODULE_1__["default"])(CandidateDOD, [{
    key: "componentDidMount",
    value: function componentDidMount() {
      var _this2 = this;

      this.fetchData().then(function () {
        return _this2.setState({
          isLoaded: true
        });
      });
    }
  }, {
    key: "fetchData",
    value: function fetchData() {
      var _this3 = this;

      return fetch(this.props.dataURL, {
        credentials: 'same-origin'
      }).then(function (resp) {
        return resp.json();
      }).then(function (data) {
        return _this3.setState({
          data: data,
          formData: data
        });
      })["catch"](function (error) {
        _this3.setState({
          error: true
        });

        console.error(error);
      });
    }
  }, {
    key: "setFormData",
    value: function setFormData(formElement, value) {
      var formData = this.state.formData;
      formData[formElement] = value;
      this.setState({
        formData: formData
      });
    }
  }, {
    key: "render",
    value: function render() {
      if (this.state.error) {
        return /*#__PURE__*/react__WEBPACK_IMPORTED_MODULE_6___default().createElement("h3", null, "An error occured while loading the page.");
      }

      if (!this.state.isLoaded) {
        return /*#__PURE__*/react__WEBPACK_IMPORTED_MODULE_6___default().createElement(Loader__WEBPACK_IMPORTED_MODULE_7__["default"], null);
      }

      var disabled = true;
      var updateButton = null;

      if (loris.userHasPermission('candidate_dod_edit')) {
        disabled = false;
        updateButton = /*#__PURE__*/react__WEBPACK_IMPORTED_MODULE_6___default().createElement(ButtonElement, {
          label: "Update"
        });
      }

      return /*#__PURE__*/react__WEBPACK_IMPORTED_MODULE_6___default().createElement("div", {
        className: "row"
      }, /*#__PURE__*/react__WEBPACK_IMPORTED_MODULE_6___default().createElement(FormElement, {
        name: "candidateDOD",
        onSubmit: this.handleSubmit,
        ref: "form",
        "class": "col-md-6"
      }, /*#__PURE__*/react__WEBPACK_IMPORTED_MODULE_6___default().createElement(StaticElement, {
        label: "PSCID",
        text: this.state.data.pscid
      }), /*#__PURE__*/react__WEBPACK_IMPORTED_MODULE_6___default().createElement(StaticElement, {
        label: "DCCID",
        text: this.state.data.candID
      }), /*#__PURE__*/react__WEBPACK_IMPORTED_MODULE_6___default().createElement(StaticElement, {
        label: "Disclaimer:",
        text: "Any changes to the date of death requires an administrator to run the fix_candidate_age script.",
        "class": "form-control-static text-danger bg-danger col-sm-10"
      }), /*#__PURE__*/react__WEBPACK_IMPORTED_MODULE_6___default().createElement(DateElement, {
        label: "Date Of Death:",
        name: "dod",
        value: this.state.formData.dod,
        onUserInput: this.setFormData,
        disabled: disabled,
        required: true
      }), updateButton));
    }
    /**
     * Handles form submission
     *
     * @param {event} e - Form submission event
     */

  }, {
    key: "handleSubmit",
    value: function handleSubmit(e) {
      var _this4 = this;

      e.preventDefault();
      var today = new Date();
      var dd = String(today.getDate()).padStart(2, '0');
      var mm = String(today.getMonth() + 1).padStart(2, '0'); // January is 0!

      var yyyy = today.getFullYear();
      today = yyyy + '-' + mm + '-' + dd;
      var dod = this.state.formData.dod ? this.state.formData.dod : null;
      var dob = this.state.data.dob ? this.state.data.dob : null;

      if (dod > today) {
        swal({
          title: 'Invalid date',
          text: 'Date of death cannot be later than today!',
          type: 'error',
          confirmButtonText: 'OK'
        });
        return;
      }

      if (dob > dod) {
        swal({
          title: 'Invalid date',
          text: 'Date of death must be after date of birth!',
          type: 'error',
          confirmButtonText: 'OK'
        });
        return;
      } // Set form data and upload the media file


      var formData = this.state.formData;
      var formObject = new FormData();

      for (var key in formData) {
        if (formData.hasOwnProperty(key)) {
          if (formData[key] !== '') {
            formObject.append(key, formData[key]);
          }
        }
      }

      formObject.append('tab', this.props.tabName);
      fetch(this.props.action, {
        method: 'POST',
        cache: 'no-cache',
        credentials: 'same-origin',
        body: formObject
      }).then(function (resp) {
        return resp.text();
      }).then(function (result) {
        swal({
          title: 'Success!',
          text: 'Date of death updated!',
          type: 'success',
          confirmButtonText: 'OK'
        });

        if (result.value) {
          _this4.fetchData();
        }
      })["catch"](function (error) {
        console.error(error);
        swal({
          title: 'Error!',
          text: 'Something went wrong.',
          type: 'error',
          confirmButtonText: 'OK'
        });
      });
    }
  }]);

  return CandidateDOD;
}(react__WEBPACK_IMPORTED_MODULE_6__.Component);

CandidateDOD.propTypes = {
  dataURL: (prop_types__WEBPACK_IMPORTED_MODULE_8___default().string),
  tabName: (prop_types__WEBPACK_IMPORTED_MODULE_8___default().string),
  action: (prop_types__WEBPACK_IMPORTED_MODULE_8___default().string)
};
/* harmony default export */ const __WEBPACK_DEFAULT_EXPORT__ = (CandidateDOD);

/***/ }),

/***/ "./modules/candidate_parameters/jsx/CandidateInfo.js":
/*!***********************************************************!*\
  !*** ./modules/candidate_parameters/jsx/CandidateInfo.js ***!
  \***********************************************************/
/***/ ((__unused_webpack_module, __webpack_exports__, __webpack_require__) => {

"use strict";
__webpack_require__.r(__webpack_exports__);
/* harmony export */ __webpack_require__.d(__webpack_exports__, {
/* harmony export */   "default": () => (__WEBPACK_DEFAULT_EXPORT__)
/* harmony export */ });
/* harmony import */ var _babel_runtime_helpers_classCallCheck__WEBPACK_IMPORTED_MODULE_0__ = __webpack_require__(/*! @babel/runtime/helpers/classCallCheck */ "./node_modules/@babel/runtime/helpers/esm/classCallCheck.js");
/* harmony import */ var _babel_runtime_helpers_createClass__WEBPACK_IMPORTED_MODULE_1__ = __webpack_require__(/*! @babel/runtime/helpers/createClass */ "./node_modules/@babel/runtime/helpers/esm/createClass.js");
/* harmony import */ var _babel_runtime_helpers_assertThisInitialized__WEBPACK_IMPORTED_MODULE_2__ = __webpack_require__(/*! @babel/runtime/helpers/assertThisInitialized */ "./node_modules/@babel/runtime/helpers/esm/assertThisInitialized.js");
/* harmony import */ var _babel_runtime_helpers_inherits__WEBPACK_IMPORTED_MODULE_3__ = __webpack_require__(/*! @babel/runtime/helpers/inherits */ "./node_modules/@babel/runtime/helpers/esm/inherits.js");
/* harmony import */ var _babel_runtime_helpers_possibleConstructorReturn__WEBPACK_IMPORTED_MODULE_4__ = __webpack_require__(/*! @babel/runtime/helpers/possibleConstructorReturn */ "./node_modules/@babel/runtime/helpers/esm/possibleConstructorReturn.js");
/* harmony import */ var _babel_runtime_helpers_getPrototypeOf__WEBPACK_IMPORTED_MODULE_5__ = __webpack_require__(/*! @babel/runtime/helpers/getPrototypeOf */ "./node_modules/@babel/runtime/helpers/esm/getPrototypeOf.js");
/* harmony import */ var react__WEBPACK_IMPORTED_MODULE_6__ = __webpack_require__(/*! react */ "react");
/* harmony import */ var react__WEBPACK_IMPORTED_MODULE_6___default = /*#__PURE__*/__webpack_require__.n(react__WEBPACK_IMPORTED_MODULE_6__);
/* harmony import */ var prop_types__WEBPACK_IMPORTED_MODULE_7__ = __webpack_require__(/*! prop-types */ "./node_modules/prop-types/index.js");
/* harmony import */ var prop_types__WEBPACK_IMPORTED_MODULE_7___default = /*#__PURE__*/__webpack_require__.n(prop_types__WEBPACK_IMPORTED_MODULE_7__);







function _createSuper(Derived) { var hasNativeReflectConstruct = _isNativeReflectConstruct(); return function _createSuperInternal() { var Super = (0,_babel_runtime_helpers_getPrototypeOf__WEBPACK_IMPORTED_MODULE_5__["default"])(Derived), result; if (hasNativeReflectConstruct) { var NewTarget = (0,_babel_runtime_helpers_getPrototypeOf__WEBPACK_IMPORTED_MODULE_5__["default"])(this).constructor; result = Reflect.construct(Super, arguments, NewTarget); } else { result = Super.apply(this, arguments); } return (0,_babel_runtime_helpers_possibleConstructorReturn__WEBPACK_IMPORTED_MODULE_4__["default"])(this, result); }; }

function _isNativeReflectConstruct() { if (typeof Reflect === "undefined" || !Reflect.construct) return false; if (Reflect.construct.sham) return false; if (typeof Proxy === "function") return true; try { Boolean.prototype.valueOf.call(Reflect.construct(Boolean, [], function () {})); return true; } catch (e) { return false; } }




var CandidateInfo = /*#__PURE__*/function (_Component) {
  (0,_babel_runtime_helpers_inherits__WEBPACK_IMPORTED_MODULE_3__["default"])(CandidateInfo, _Component);

  var _super = _createSuper(CandidateInfo);

  function CandidateInfo(props) {
    var _this;

    (0,_babel_runtime_helpers_classCallCheck__WEBPACK_IMPORTED_MODULE_0__["default"])(this, CandidateInfo);

    _this = _super.call(this, props);
    _this.state = {
      caveatOptions: {
        "true": 'True',
        "false": 'False'
      },
      Data: [],
      formData: {},
      updateResult: null,
      errorMessage: null,
      isLoaded: false,
      loadedData: 0
    };
    _this.setFormData = _this.setFormData.bind((0,_babel_runtime_helpers_assertThisInitialized__WEBPACK_IMPORTED_MODULE_2__["default"])(_this));
    _this.onSubmit = _this.onSubmit.bind((0,_babel_runtime_helpers_assertThisInitialized__WEBPACK_IMPORTED_MODULE_2__["default"])(_this));
    _this.handleSubmit = _this.handleSubmit.bind((0,_babel_runtime_helpers_assertThisInitialized__WEBPACK_IMPORTED_MODULE_2__["default"])(_this));
    _this.showAlertMessage = _this.showAlertMessage.bind((0,_babel_runtime_helpers_assertThisInitialized__WEBPACK_IMPORTED_MODULE_2__["default"])(_this));
    return _this;
  }

  (0,_babel_runtime_helpers_createClass__WEBPACK_IMPORTED_MODULE_1__["default"])(CandidateInfo, [{
    key: "componentDidMount",
    value: function componentDidMount() {
      var that = this;
      $.ajax(this.props.dataURL, {
        dataType: 'json',
        success: function success(data) {
          var formData = {
            flaggedCaveatemptor: data.flagged_caveatemptor,
            flaggedOther: data.flagged_other,
            flaggedReason: data.flagged_reason
          }; // Add parameter values to formData

          Object.assign(formData, data.parameter_values);
          that.setState({
            Data: data,
            isLoaded: true,
            formData: formData
          });
        },
        error: function error(data, errorCode, errorMsg) {
          that.setState({
            error: 'An error occurred when loading the form!'
          });
        }
      });
    }
  }, {
    key: "setFormData",
    value: function setFormData(formElement, value) {
      var formData = JSON.parse(JSON.stringify(this.state.formData));
      formData[formElement] = value; // Reset 'reason' and 'other' fields

      if (formElement === 'flaggedCaveatemptor' && value === 'false') {
        formData.flaggedReason = '';
        formData.flaggedOther = '';
      } // Reset 'other' field


      if (formElement === 'flaggedReason' && this.state.Data.caveatReasonOptions[value] !== 'Other') {
        formData.flaggedOther = '';
      }

      this.setState({
        formData: formData
      });
    }
  }, {
    key: "onSubmit",
    value: function onSubmit(e) {
      e.preventDefault();
    } // IBIS SPECIFIC OVERRIDE CODE
    // IBIS doesn't use Caveat Emptor Flag for Candidate* and Reason for Caveat Emptor Flag.

  }, {
    key: "render",
    value: function render() {
      if (!this.state.isLoaded) {
        if (this.state.error !== undefined) {
          return /*#__PURE__*/react__WEBPACK_IMPORTED_MODULE_6___default().createElement("div", {
            className: "alert alert-danger text-center"
          }, /*#__PURE__*/react__WEBPACK_IMPORTED_MODULE_6___default().createElement("strong", null, this.state.error));
        }
      }

      ;
      var disabled = true;
      var updateButton = null;

      if (loris.userHasPermission('candidate_parameter_edit')) {
        disabled = false;
        updateButton = /*#__PURE__*/react__WEBPACK_IMPORTED_MODULE_6___default().createElement(ButtonElement, {
          label: "Update"
        });
      }

      var extraParameterFields = [];
      var extraParameters = this.state.Data.extra_parameters;

      for (var key2 in extraParameters) {
        if (extraParameters.hasOwnProperty(key2)) {
          var paramTypeID = extraParameters[key2].ParameterTypeID;
          var name = paramTypeID;
          var value = this.state.formData[paramTypeID];

          switch (extraParameters[key2].Type.substring(0, 3)) {
            case 'enu':
              var types = extraParameters[key2].Type.substring(5);
              types = types.slice(0, -1);
              types = types.replace(/'/g, '');
              types = types.split(',');
              var selectOptions = {};

              for (var key3 in types) {
                if (types.hasOwnProperty(key3)) {
                  selectOptions[types[key3]] = types[key3];
                }
              }

              extraParameterFields.push( /*#__PURE__*/react__WEBPACK_IMPORTED_MODULE_6___default().createElement(SelectElement, {
                label: extraParameters[key2].Description,
                name: name,
                options: selectOptions,
                value: value,
                onUserInput: this.setFormData,
                ref: name,
                disabled: disabled,
                key: key2
              }));
              break;

            case 'dat':
              extraParameterFields.push( /*#__PURE__*/react__WEBPACK_IMPORTED_MODULE_6___default().createElement(DateElement, {
                label: extraParameters[key2].Description,
                name: name,
                value: value,
                onUserInput: this.setFormData,
                ref: name,
                disabled: disabled,
                key: key2
              }));
              break;

            default:
              extraParameterFields.push( /*#__PURE__*/react__WEBPACK_IMPORTED_MODULE_6___default().createElement(TextareaElement, {
                label: extraParameters[key2].Description,
                name: name,
                value: value,
                onUserInput: this.setFormData,
                ref: name,
                disabled: disabled,
                key: key2
              }));
          }
        }
      }

      var alertMessage = '';
      var alertClass = 'alert text-center hide';

      if (this.state.updateResult) {
        if (this.state.updateResult === 'success') {
          alertClass = 'alert alert-success text-center';
          alertMessage = 'Update Successful!';
        } else if (this.state.updateResult === 'error') {
          var errorMessage = this.state.errorMessage;
          alertClass = 'alert alert-danger text-center';
          alertMessage = errorMessage ? errorMessage : 'Failed to update!';
        }
      }

      return /*#__PURE__*/react__WEBPACK_IMPORTED_MODULE_6___default().createElement("div", {
        className: "row"
      }, /*#__PURE__*/react__WEBPACK_IMPORTED_MODULE_6___default().createElement("div", {
        className: alertClass,
        role: "alert",
        ref: "alert-message"
      }, alertMessage), /*#__PURE__*/react__WEBPACK_IMPORTED_MODULE_6___default().createElement(FormElement, {
        name: "candidateInfo",
        onSubmit: this.handleSubmit,
        ref: "form",
        "class": "col-md-6"
      }, /*#__PURE__*/react__WEBPACK_IMPORTED_MODULE_6___default().createElement(StaticElement, {
        label: "PSCID",
        text: this.state.Data.pscid
      }), /*#__PURE__*/react__WEBPACK_IMPORTED_MODULE_6___default().createElement(StaticElement, {
        label: "DCCID",
        text: this.state.Data.candID
      }), extraParameterFields, updateButton));
    } // IBIS SPECIFIC OVERRIDE CODE ENDS HERE

    /**
     * Handles form submission
     *
     * @param {event} e - Form submission event
     */

  }, {
    key: "handleSubmit",
    value: function handleSubmit(e) {
      e.preventDefault();
      var myFormData = this.state.formData; // Set form data and upload the media file

      var self = this;
      var formData = new FormData();

      for (var key in myFormData) {
        if (myFormData.hasOwnProperty(key)) {
          if (myFormData[key] !== '') {
            formData.append(key, myFormData[key]);
          }
        }
      }

      formData.append('tab', this.props.tabName);
      formData.append('candID', this.state.Data.candID);
      $.ajax({
        type: 'POST',
        url: self.props.action,
        data: formData,
        cache: false,
        contentType: false,
        processData: false,
        success: function success(data) {
          self.setState({
            updateResult: 'success'
          });
          self.showAlertMessage();
        },
        error: function error(err) {
          if (err.responseText !== '') {
            var errorMessage = JSON.parse(err.responseText).message;
            self.setState({
              updateResult: 'error',
              errorMessage: errorMessage
            });
            self.showAlertMessage();
          }
        }
      });
    }
    /**
     * Display a success/error alert message after form submission
     */

  }, {
    key: "showAlertMessage",
    value: function showAlertMessage() {
      var self = this;

      if (this.refs['alert-message'] === null) {
        return;
      }

      var alertMsg = this.refs['alert-message'];
      $(alertMsg).fadeTo(2000, 500).delay(3000).slideUp(500, function () {
        self.setState({
          updateResult: null
        });
      });
    }
  }]);

  return CandidateInfo;
}(react__WEBPACK_IMPORTED_MODULE_6__.Component);

CandidateInfo.propTypes = {
  dataURL: (prop_types__WEBPACK_IMPORTED_MODULE_7___default().string),
  tabName: (prop_types__WEBPACK_IMPORTED_MODULE_7___default().string),
  action: (prop_types__WEBPACK_IMPORTED_MODULE_7___default().string)
};
/* harmony default export */ const __WEBPACK_DEFAULT_EXPORT__ = (CandidateInfo);

/***/ }),

/***/ "./modules/candidate_parameters/jsx/ConsentStatus.js":
/*!***********************************************************!*\
  !*** ./modules/candidate_parameters/jsx/ConsentStatus.js ***!
  \***********************************************************/
/***/ ((__unused_webpack_module, __webpack_exports__, __webpack_require__) => {

"use strict";
__webpack_require__.r(__webpack_exports__);
/* harmony export */ __webpack_require__.d(__webpack_exports__, {
/* harmony export */   "default": () => (__WEBPACK_DEFAULT_EXPORT__)
/* harmony export */ });
/* harmony import */ var _babel_runtime_helpers_classCallCheck__WEBPACK_IMPORTED_MODULE_0__ = __webpack_require__(/*! @babel/runtime/helpers/classCallCheck */ "./node_modules/@babel/runtime/helpers/esm/classCallCheck.js");
/* harmony import */ var _babel_runtime_helpers_createClass__WEBPACK_IMPORTED_MODULE_1__ = __webpack_require__(/*! @babel/runtime/helpers/createClass */ "./node_modules/@babel/runtime/helpers/esm/createClass.js");
/* harmony import */ var _babel_runtime_helpers_assertThisInitialized__WEBPACK_IMPORTED_MODULE_2__ = __webpack_require__(/*! @babel/runtime/helpers/assertThisInitialized */ "./node_modules/@babel/runtime/helpers/esm/assertThisInitialized.js");
/* harmony import */ var _babel_runtime_helpers_inherits__WEBPACK_IMPORTED_MODULE_3__ = __webpack_require__(/*! @babel/runtime/helpers/inherits */ "./node_modules/@babel/runtime/helpers/esm/inherits.js");
/* harmony import */ var _babel_runtime_helpers_possibleConstructorReturn__WEBPACK_IMPORTED_MODULE_4__ = __webpack_require__(/*! @babel/runtime/helpers/possibleConstructorReturn */ "./node_modules/@babel/runtime/helpers/esm/possibleConstructorReturn.js");
/* harmony import */ var _babel_runtime_helpers_getPrototypeOf__WEBPACK_IMPORTED_MODULE_5__ = __webpack_require__(/*! @babel/runtime/helpers/getPrototypeOf */ "./node_modules/@babel/runtime/helpers/esm/getPrototypeOf.js");
/* harmony import */ var react__WEBPACK_IMPORTED_MODULE_6__ = __webpack_require__(/*! react */ "react");
/* harmony import */ var react__WEBPACK_IMPORTED_MODULE_6___default = /*#__PURE__*/__webpack_require__.n(react__WEBPACK_IMPORTED_MODULE_6__);
/* harmony import */ var prop_types__WEBPACK_IMPORTED_MODULE_8__ = __webpack_require__(/*! prop-types */ "./node_modules/prop-types/index.js");
/* harmony import */ var prop_types__WEBPACK_IMPORTED_MODULE_8___default = /*#__PURE__*/__webpack_require__.n(prop_types__WEBPACK_IMPORTED_MODULE_8__);
/* harmony import */ var Loader__WEBPACK_IMPORTED_MODULE_7__ = __webpack_require__(/*! Loader */ "./jsx/Loader.js");







function _createSuper(Derived) { var hasNativeReflectConstruct = _isNativeReflectConstruct(); return function _createSuperInternal() { var Super = (0,_babel_runtime_helpers_getPrototypeOf__WEBPACK_IMPORTED_MODULE_5__["default"])(Derived), result; if (hasNativeReflectConstruct) { var NewTarget = (0,_babel_runtime_helpers_getPrototypeOf__WEBPACK_IMPORTED_MODULE_5__["default"])(this).constructor; result = Reflect.construct(Super, arguments, NewTarget); } else { result = Super.apply(this, arguments); } return (0,_babel_runtime_helpers_possibleConstructorReturn__WEBPACK_IMPORTED_MODULE_4__["default"])(this, result); }; }

function _isNativeReflectConstruct() { if (typeof Reflect === "undefined" || !Reflect.construct) return false; if (Reflect.construct.sham) return false; if (typeof Proxy === "function") return true; try { Boolean.prototype.valueOf.call(Reflect.construct(Boolean, [], function () {})); return true; } catch (e) { return false; } }




/**
 * Consent Status Component.
 *
 * Renders the contents of the Consent Status tab, consisting of the FormElement component
 */

var ConsentStatus = /*#__PURE__*/function (_Component) {
  (0,_babel_runtime_helpers_inherits__WEBPACK_IMPORTED_MODULE_3__["default"])(ConsentStatus, _Component);

  var _super = _createSuper(ConsentStatus);

  function ConsentStatus(props) {
    var _this;

    (0,_babel_runtime_helpers_classCallCheck__WEBPACK_IMPORTED_MODULE_0__["default"])(this, ConsentStatus);

    _this = _super.call(this, props);
    _this.state = {
      consentOptions: {
        yes: 'Yes',
        no: 'No'
      },
      Data: [],
      formData: {},
      error: false,
      isLoaded: false,
      loadedData: 0
    };
    /**
     * Bind component instance to custom methods
     */

    _this.fetchData = _this.fetchData.bind((0,_babel_runtime_helpers_assertThisInitialized__WEBPACK_IMPORTED_MODULE_2__["default"])(_this));
    _this.setFormData = _this.setFormData.bind((0,_babel_runtime_helpers_assertThisInitialized__WEBPACK_IMPORTED_MODULE_2__["default"])(_this));
    _this.handleSubmit = _this.handleSubmit.bind((0,_babel_runtime_helpers_assertThisInitialized__WEBPACK_IMPORTED_MODULE_2__["default"])(_this));
    return _this;
  }

  (0,_babel_runtime_helpers_createClass__WEBPACK_IMPORTED_MODULE_1__["default"])(ConsentStatus, [{
    key: "componentDidMount",
    value: function componentDidMount() {
      this.fetchData();
    }
    /**
     * Retrieve data from the provided URL and save it in state
     */

  }, {
    key: "fetchData",
    value: function fetchData() {
      var _this2 = this;

      $.ajax(this.props.dataURL, {
        method: 'GET',
        dataType: 'json',
        success: function success(data) {
          var formData = {};
          var consents = data.consents;

          for (var consentStatus in consents) {
            if (consents.hasOwnProperty(consentStatus)) {
              var consentDate = consentStatus + '_date';
              var consentDate2 = consentStatus + '_date2';
              var consentWithdrawal = consentStatus + '_withdrawal';
              var consentWithdrawal2 = consentStatus + '_withdrawal2';
              var consentT1 = consentStatus + '_t1';
              formData[consentStatus] = data.consentStatuses[consentStatus];
              formData[consentDate] = data.consentDates[consentStatus];
              formData[consentDate2] = data.consentDates[consentStatus];
              formData[consentWithdrawal] = data.withdrawals[consentStatus];
              formData[consentWithdrawal2] = data.withdrawals[consentStatus];
              formData[consentT1] = data.t1[consentStatus];
            }
          }

          _this2.setState({
            Data: data,
            formData: formData,
            isLoaded: true
          });
        },
        error: function error(_error) {
          console.error(_error);

          _this2.setState({
            error: true
          });
        }
      });
    }
    /**
     * Store the value of the element in this.state.formData
     *
     * @param {string} formElement - name of the form element
     * @param {string} value - value of the form element
     */

  }, {
    key: "setFormData",
    value: function setFormData(formElement, value) {
      var formData = this.state.formData;
      formData[formElement] = value;

      for (var consent in this.state.Data.consents) {
        if (this.state.Data.consents.hasOwnProperty(consent)) {
          var oldConsent = this.state.Data.consentStatuses[consent];
          var newConsent = this.state.formData[consent]; // Clear withdrawal date if consent status changes from no
          // (or empty if uncleaned data) to yes

          if (formElement === consent) {
            if (newConsent === 'yes' && oldConsent !== 'yes' || newConsent === 'no' && oldConsent === null) {
              formData[consent + '_withdrawal'] = '';
              formData[consent + '_withdrawal2'] = '';
            }
          }
        }
      }

      this.setState({
        formData: formData
      });
    }
    /**
     * Handles form submission
     *
     * @param {event} e - Form submission event
     */

  }, {
    key: "handleSubmit",
    value: function handleSubmit(e) {
      var _this3 = this;

      e.preventDefault();
      var myFormData = this.state.formData;
      var today = new Date();
      var dd = today.getDate();
      var mm = today.getMonth() + 1; // January is 0!

      var yyyy = today.getFullYear();

      if (dd < 10) {
        dd = '0' + dd;
      }

      if (mm < 10) {
        mm = '0' + mm;
      }

      today = yyyy + '-' + mm + '-' + dd;

      for (var consentStatus in this.state.Data.consents) {
        if (this.state.Data.consents.hasOwnProperty(consentStatus)) {
          var label = this.state.Data.consents[consentStatus];
          var consentDate = consentStatus + '_date';
          var consentDate2 = consentStatus + '_date2';
          var date1 = myFormData[consentDate] ? myFormData[consentDate] : null;
          var date2 = myFormData[consentDate2] ? myFormData[consentDate2] : null;

          if (date1 !== date2) {
            alert(label + ' dates do not match!');
            return;
          }

          if (date1 > today) {
            alert(label + ' date cannot be later than today!');
            return;
          }

          var consentWithdrawal = consentStatus + '_withdrawal';
          var consentWithdrawal2 = consentStatus + '_withdrawal2';
          date1 = myFormData[consentWithdrawal] ? myFormData[consentWithdrawal] : null;
          date2 = myFormData[consentWithdrawal2] ? myFormData[consentWithdrawal2] : null;

          if (date1 !== date2) {
            alert(label + ' withdrawal dates do not match!');
            return;
          }

          if (date1 > today) {
            alert(label + ' withdrawal date cannot be later than today!');
            return;
          }
        }
      } // Set form data


      var formData = new FormData();

      for (var key in myFormData) {
        // Does not submit data with empty string
        if (myFormData[key] !== '') {
          formData.append(key, myFormData[key]);
        }
      }

      formData.append('tab', this.props.tabName);
      formData.append('candID', this.state.Data.candID);
      $.ajax({
        type: 'POST',
        url: this.props.action,
        data: formData,
        cache: false,
        contentType: false,
        processData: false,
        success: function success(data) {
          swal('Success!', 'Update successful.', 'success');

          _this3.fetchData();
        },
        error: function error(_error2) {
          console.error(_error2);
          var errorMessage = _error2.responseText || 'Update failed.';
          swal('Error!', errorMessage, 'error');
        }
      });
    }
  }, {
    key: "render",
    value: function render() {
      // If error occurs, return a message.
      // XXX: Replace this with a UI component for 500 errors.
      if (this.state.error) {
        return /*#__PURE__*/react__WEBPACK_IMPORTED_MODULE_6___default().createElement("h3", null, "An error occured while loading the page.");
      }

      if (!this.state.isLoaded) {
        return /*#__PURE__*/react__WEBPACK_IMPORTED_MODULE_6___default().createElement(Loader__WEBPACK_IMPORTED_MODULE_7__["default"], null);
      }

      var disabled = true;
      var updateButton = null;

      if (loris.userHasPermission('candidate_parameter_edit')) {
        disabled = false;
        updateButton = /*#__PURE__*/react__WEBPACK_IMPORTED_MODULE_6___default().createElement(ButtonElement, {
          label: "Update"
        });
      }

      var emptyOption = [];
      var dateRequired = [];
      var withdrawalRequired = [];
      var withdrawalDisabled = [];
      var i = 0;

      for (var consent in this.state.Data.consents) {
        if (this.state.Data.consents.hasOwnProperty(consent)) {
          var oldConsent = this.state.Data.consentStatuses[consent];
          var newConsent = this.state.formData[consent];
          var withdrawalDate = this.state.Data.withdrawals[consent]; // Set defaults

          emptyOption[i] = true;
          dateRequired[i] = false;
          withdrawalRequired[i] = false; // Let date of withdrawal field be disabled until it is needed

          withdrawalDisabled[i] = true; // If answer to consent is 'yes', require date of consent

          if (newConsent === 'yes') {
            dateRequired[i] = true;
          } // If answer to consent is 'no', require date of consent


          if (newConsent === 'no') {
            dateRequired[i] = true; // If answer was previously 'yes' and consent is now being withdrawn, enable and require withdrawal date
            // If consent was previously withdrawn and stays withdrawn, enable and require withdrawal date

            if (oldConsent === 'yes' || oldConsent === 'no' && withdrawalDate) {
              withdrawalDisabled[i] = false;
              withdrawalRequired[i] = true;
            }
          } // Disallow clearing a valid consent status by removing empty option


          if (oldConsent === 'no' || oldConsent === 'yes') {
            emptyOption[i] = false;
          }

          i++;
        }
      } // IBIS SPECIFIC OVERRIDE CODE


      var consentsEcho = [];
      var consentsOnly = [];
      var consents = [];
      var consentsSpark = [];
      var sparkOption = {
        yes: 'Yes',
        no: 'No'
      };
      i = 0;

      for (var consentStatus in this.state.Data.consents) {
        if (this.state.Data.consents.hasOwnProperty(consentStatus)) {
          var consentLabel = this.state.Data.consents[consentStatus];
          var statusLabel = 'Response';
          var consentDate = consentStatus + '_date';
          var consentDate2 = consentStatus + '_date2';
          var consentDateLabel = 'Date of ' + statusLabel;
          var consentDateConfirmationLabel = 'Confirmation Date of ' + statusLabel;
          var consentWithdrawal = consentStatus + '_withdrawal';
          var consentWithdrawal2 = consentStatus + '_withdrawal2';
          var consentWithdrawalLabel = 'Date of Withdrawal of Consent';
          var consentWithdrawalConfirmationLabel = 'Confirmation Date of Withdrawal of Consent';

          if (consentStatus == 'spark_participation') {
            var spark = /*#__PURE__*/react__WEBPACK_IMPORTED_MODULE_6___default().createElement("div", {
              key: i
            }, /*#__PURE__*/react__WEBPACK_IMPORTED_MODULE_6___default().createElement(HeaderElement, {
              text: "Spark participation2222"
            }), /*#__PURE__*/react__WEBPACK_IMPORTED_MODULE_6___default().createElement(SelectElement, {
              label: statusLabel,
              name: "spark_participation",
              options: sparkOption,
              value: this.state.formData['spark_participation'],
              onUserInput: this.setFormData,
              ref: consentStatus,
              disabled: disabled,
              required: false,
              emptyOption: true
            }), /*#__PURE__*/react__WEBPACK_IMPORTED_MODULE_6___default().createElement("hr", null));
            consentsSpark.push(spark);
            i++;
            continue;
          }

          var echoOption1 = {
            yes: 'Yes',
            no: 'No'
          };
          var echoOption2 = {
            yes: 'Yes1',
            no: 'No2'
          };

          if (consentStatus == 'echo_participation') {
            var echo = /*#__PURE__*/react__WEBPACK_IMPORTED_MODULE_6___default().createElement("div", {
              key: i
            }, /*#__PURE__*/react__WEBPACK_IMPORTED_MODULE_6___default().createElement(HeaderElement, {
              text: "ECHO participation2222"
            }), /*#__PURE__*/react__WEBPACK_IMPORTED_MODULE_6___default().createElement(SelectElement, {
              label: statusLabel,
              name: "echo_participation",
              options: echoOption1,
              value: this.state.formData['echo_participation'],
              onUserInput: this.setFormData,
              ref: consentStatus,
              disabled: disabled,
              required: false,
              emptyOption: true
            }), /*#__PURE__*/react__WEBPACK_IMPORTED_MODULE_6___default().createElement(SelectElement, {
              label: statusLabel,
              name: "echo_participation_t1",
              options: echoOption2,
              value: this.state.formData['echo_participation_t1'],
              onUserInput: this.setFormData,
              ref: consentStatus,
              disabled: disabled,
              required: false,
              emptyOption: true
            }), /*#__PURE__*/react__WEBPACK_IMPORTED_MODULE_6___default().createElement("hr", null));
            consentsEcho.push(echo);
            i++;
            continue;
          }

          var _consent = /*#__PURE__*/react__WEBPACK_IMPORTED_MODULE_6___default().createElement("div", {
            key: i
          }, /*#__PURE__*/react__WEBPACK_IMPORTED_MODULE_6___default().createElement(HeaderElement, {
            text: consentLabel
          }), /*#__PURE__*/react__WEBPACK_IMPORTED_MODULE_6___default().createElement(SelectElement, {
            label: statusLabel,
            name: consentStatus,
            options: this.state.consentOptions,
            value: this.state.formData[consentStatus],
            onUserInput: this.setFormData,
            ref: consentStatus,
            disabled: disabled,
            required: false,
            emptyOption: emptyOption[i]
          }), /*#__PURE__*/react__WEBPACK_IMPORTED_MODULE_6___default().createElement(DateElement, {
            label: consentDateLabel,
            name: consentDate,
            value: this.state.formData[consentDate],
            onUserInput: this.setFormData,
            ref: consentDate,
            disabled: disabled,
            required: dateRequired[i]
          }), /*#__PURE__*/react__WEBPACK_IMPORTED_MODULE_6___default().createElement(DateElement, {
            label: consentDateConfirmationLabel,
            name: consentDate2,
            value: this.state.formData[consentDate2],
            onUserInput: this.setFormData,
            ref: consentDate2,
            disabled: disabled,
            required: dateRequired[i]
          }), /*#__PURE__*/react__WEBPACK_IMPORTED_MODULE_6___default().createElement(DateElement, {
            label: consentWithdrawalLabel,
            name: consentWithdrawal,
            value: this.state.formData[consentWithdrawal],
            onUserInput: this.setFormData,
            ref: consentWithdrawal,
            disabled: disabled || withdrawalDisabled[i],
            required: withdrawalRequired[i]
          }), /*#__PURE__*/react__WEBPACK_IMPORTED_MODULE_6___default().createElement(DateElement, {
            label: consentWithdrawalConfirmationLabel,
            name: consentWithdrawal2,
            value: this.state.formData[consentWithdrawal2],
            onUserInput: this.setFormData,
            ref: consentWithdrawal2,
            disabled: disabled || withdrawalDisabled[i],
            required: withdrawalRequired[i]
          }), /*#__PURE__*/react__WEBPACK_IMPORTED_MODULE_6___default().createElement("hr", null));

          consentsOnly.push(_consent);
          i++;
        }
      }

      consents.push(consentsSpark);
      consents.push(consentsEcho);
      consents.push(consentsOnly); // IBIS SPECIFIC OVERRIDE CODE END

      var formattedHistory = [];

      for (var consentKey in this.state.Data.history) {
        if (this.state.Data.history.hasOwnProperty(consentKey)) {
          var _consentLabel = this.state.Data.history[consentKey].label;
          var consentType = this.state.Data.history[consentKey].consentType;

          for (var field in this.state.Data.history[consentKey]) {
            if (this.state.Data.history[consentKey].hasOwnProperty(field)) {
              var line = '';
              var historyConsent = this.state.Data.history[consentKey][field];

              for (var field2 in historyConsent) {
                if (historyConsent.hasOwnProperty(field2)) {
                  var current = historyConsent[field2];

                  if (current !== null) {
                    switch (field2) {
                      case 'data_entry_date':
                        line += '[';
                        line += current;
                        line += '] ';
                        break;

                      case 'entry_staff':
                        line += current;
                        line += ' ';
                        break;

                      case consentType:
                        line += _consentLabel + ' Status: ';
                        line += current;
                        line += ' ';
                        break;

                      case consentType + '_date':
                        line += 'Date of Consent: ';
                        line += current;
                        line += ' ';
                        break;

                      case consentType + '_withdrawal':
                        line += 'Date of Consent Withdrawal: ';
                        line += current;
                        line += ' ';
                        break;

                      default:
                    }
                  }
                }
              }

              formattedHistory.push( /*#__PURE__*/react__WEBPACK_IMPORTED_MODULE_6___default().createElement("p", {
                key: field
              }, line));
            }
          }
        }
      }

      return /*#__PURE__*/react__WEBPACK_IMPORTED_MODULE_6___default().createElement("div", {
        className: "row"
      }, /*#__PURE__*/react__WEBPACK_IMPORTED_MODULE_6___default().createElement(FormElement, {
        name: "consentStatus",
        onSubmit: this.handleSubmit,
        ref: "form",
        "class": "col-md-6"
      }, /*#__PURE__*/react__WEBPACK_IMPORTED_MODULE_6___default().createElement(StaticElement, {
        label: "PSCID",
        text: this.state.Data.pscid
      }), /*#__PURE__*/react__WEBPACK_IMPORTED_MODULE_6___default().createElement(StaticElement, {
        label: "DCCID",
        text: this.state.Data.candID
      }), consents, updateButton, formattedHistory));
    }
  }]);

  return ConsentStatus;
}(react__WEBPACK_IMPORTED_MODULE_6__.Component);

ConsentStatus.propTypes = {
  dataURL: (prop_types__WEBPACK_IMPORTED_MODULE_8___default().string.isRequired),
  action: (prop_types__WEBPACK_IMPORTED_MODULE_8___default().string.isRequired),
  tabName: (prop_types__WEBPACK_IMPORTED_MODULE_8___default().string)
};
/* harmony default export */ const __WEBPACK_DEFAULT_EXPORT__ = (ConsentStatus);

/***/ }),

/***/ "./modules/candidate_parameters/jsx/FamilyInfo.js":
/*!********************************************************!*\
  !*** ./modules/candidate_parameters/jsx/FamilyInfo.js ***!
  \********************************************************/
/***/ ((__unused_webpack_module, __webpack_exports__, __webpack_require__) => {

"use strict";
__webpack_require__.r(__webpack_exports__);
/* harmony export */ __webpack_require__.d(__webpack_exports__, {
/* harmony export */   "default": () => (__WEBPACK_DEFAULT_EXPORT__)
/* harmony export */ });
/* harmony import */ var _babel_runtime_helpers_classCallCheck__WEBPACK_IMPORTED_MODULE_0__ = __webpack_require__(/*! @babel/runtime/helpers/classCallCheck */ "./node_modules/@babel/runtime/helpers/esm/classCallCheck.js");
/* harmony import */ var _babel_runtime_helpers_createClass__WEBPACK_IMPORTED_MODULE_1__ = __webpack_require__(/*! @babel/runtime/helpers/createClass */ "./node_modules/@babel/runtime/helpers/esm/createClass.js");
/* harmony import */ var _babel_runtime_helpers_assertThisInitialized__WEBPACK_IMPORTED_MODULE_2__ = __webpack_require__(/*! @babel/runtime/helpers/assertThisInitialized */ "./node_modules/@babel/runtime/helpers/esm/assertThisInitialized.js");
/* harmony import */ var _babel_runtime_helpers_inherits__WEBPACK_IMPORTED_MODULE_3__ = __webpack_require__(/*! @babel/runtime/helpers/inherits */ "./node_modules/@babel/runtime/helpers/esm/inherits.js");
/* harmony import */ var _babel_runtime_helpers_possibleConstructorReturn__WEBPACK_IMPORTED_MODULE_4__ = __webpack_require__(/*! @babel/runtime/helpers/possibleConstructorReturn */ "./node_modules/@babel/runtime/helpers/esm/possibleConstructorReturn.js");
/* harmony import */ var _babel_runtime_helpers_getPrototypeOf__WEBPACK_IMPORTED_MODULE_5__ = __webpack_require__(/*! @babel/runtime/helpers/getPrototypeOf */ "./node_modules/@babel/runtime/helpers/esm/getPrototypeOf.js");
/* harmony import */ var react__WEBPACK_IMPORTED_MODULE_6__ = __webpack_require__(/*! react */ "react");
/* harmony import */ var react__WEBPACK_IMPORTED_MODULE_6___default = /*#__PURE__*/__webpack_require__.n(react__WEBPACK_IMPORTED_MODULE_6__);
/* harmony import */ var prop_types__WEBPACK_IMPORTED_MODULE_7__ = __webpack_require__(/*! prop-types */ "./node_modules/prop-types/index.js");
/* harmony import */ var prop_types__WEBPACK_IMPORTED_MODULE_7___default = /*#__PURE__*/__webpack_require__.n(prop_types__WEBPACK_IMPORTED_MODULE_7__);







function _createSuper(Derived) { var hasNativeReflectConstruct = _isNativeReflectConstruct(); return function _createSuperInternal() { var Super = (0,_babel_runtime_helpers_getPrototypeOf__WEBPACK_IMPORTED_MODULE_5__["default"])(Derived), result; if (hasNativeReflectConstruct) { var NewTarget = (0,_babel_runtime_helpers_getPrototypeOf__WEBPACK_IMPORTED_MODULE_5__["default"])(this).constructor; result = Reflect.construct(Super, arguments, NewTarget); } else { result = Super.apply(this, arguments); } return (0,_babel_runtime_helpers_possibleConstructorReturn__WEBPACK_IMPORTED_MODULE_4__["default"])(this, result); }; }

function _isNativeReflectConstruct() { if (typeof Reflect === "undefined" || !Reflect.construct) return false; if (Reflect.construct.sham) return false; if (typeof Proxy === "function") return true; try { Boolean.prototype.valueOf.call(Reflect.construct(Boolean, [], function () {})); return true; } catch (e) { return false; } }




var FamilyInfo = /*#__PURE__*/function (_Component) {
  (0,_babel_runtime_helpers_inherits__WEBPACK_IMPORTED_MODULE_3__["default"])(FamilyInfo, _Component);

  var _super = _createSuper(FamilyInfo);

  function FamilyInfo(props) {
    var _this;

    (0,_babel_runtime_helpers_classCallCheck__WEBPACK_IMPORTED_MODULE_0__["default"])(this, FamilyInfo);

    _this = _super.call(this, props);
    _this.state = {
      Data: [],
      formData: {},
      familyMembers: [],
      updateResult: null,
      errorMessage: null,
      isLoaded: false,
      loadedData: 0
    };
    _this.setFormData = _this.setFormData.bind((0,_babel_runtime_helpers_assertThisInitialized__WEBPACK_IMPORTED_MODULE_2__["default"])(_this));
    _this.onSubmit = _this.onSubmit.bind((0,_babel_runtime_helpers_assertThisInitialized__WEBPACK_IMPORTED_MODULE_2__["default"])(_this));
    _this.handleSubmit = _this.handleSubmit.bind((0,_babel_runtime_helpers_assertThisInitialized__WEBPACK_IMPORTED_MODULE_2__["default"])(_this));
    _this.showAlertMessage = _this.showAlertMessage.bind((0,_babel_runtime_helpers_assertThisInitialized__WEBPACK_IMPORTED_MODULE_2__["default"])(_this));
    _this.deleteFamilyMember = _this.deleteFamilyMember.bind((0,_babel_runtime_helpers_assertThisInitialized__WEBPACK_IMPORTED_MODULE_2__["default"])(_this));
    _this.fetchData = _this.fetchData.bind((0,_babel_runtime_helpers_assertThisInitialized__WEBPACK_IMPORTED_MODULE_2__["default"])(_this));
    return _this;
  }

  (0,_babel_runtime_helpers_createClass__WEBPACK_IMPORTED_MODULE_1__["default"])(FamilyInfo, [{
    key: "fetchData",
    value: function fetchData() {
      $.ajax(this.props.dataURL, {
        dataType: 'json',
        xhr: function () {
          var xhr = new window.XMLHttpRequest();
          xhr.addEventListener('progress', function (evt) {
            this.setState({
              loadedData: evt.loaded
            });
          }.bind(this));
          return xhr;
        }.bind(this),
        success: function (data) {
          this.setState({
            Data: data,
            isLoaded: true,
            familyMembers: data.existingFamilyMembers
          });
        }.bind(this),
        error: function (data, errorCode, errorMsg) {
          this.setState({
            error: 'An error occurred when loading the form!'
          });
        }.bind(this)
      });
    }
  }, {
    key: "componentDidMount",
    value: function componentDidMount() {
      this.fetchData();
    }
  }, {
    key: "setFormData",
    value: function setFormData(formElement, value) {
      var formData = this.state.formData;
      formData[formElement] = value;
      this.setState({
        formData: formData
      });
    }
  }, {
    key: "onSubmit",
    value: function onSubmit(e) {
      e.preventDefault();
    }
  }, {
    key: "render",
    value: function render() {
      if (!this.state.isLoaded) {
        if (this.state.error !== undefined) {
          return /*#__PURE__*/react__WEBPACK_IMPORTED_MODULE_6___default().createElement("div", {
            className: "alert alert-danger text-center"
          }, /*#__PURE__*/react__WEBPACK_IMPORTED_MODULE_6___default().createElement("strong", null, this.state.error));
        }

        return /*#__PURE__*/react__WEBPACK_IMPORTED_MODULE_6___default().createElement("button", {
          className: "btn-info has-spinner"
        }, "Loading", /*#__PURE__*/react__WEBPACK_IMPORTED_MODULE_6___default().createElement("span", {
          className: "glyphicon glyphicon-refresh glyphicon-refresh-animate"
        }));
      }

      var relationshipOptions = {
        'full_sibling': 'Full Sibling',
        'half_sibling': 'Half Sibling',
        '1st_cousin': 'First Cousin'
      };
      var disabled = true;
      var addButton = null;

      if (loris.userHasPermission('candidate_parameter_edit')) {
        disabled = false;
        addButton = /*#__PURE__*/react__WEBPACK_IMPORTED_MODULE_6___default().createElement(ButtonElement, {
          label: "Add"
        });
      }

      var candidateList = this.state.Data.candidates;
      var familyMembers = this.state.familyMembers;
      var familyMembersHTML = [];

      for (var key in familyMembers) {
        if (familyMembers.hasOwnProperty(key)) {
          var candID = familyMembers[key].FamilyCandID;
          var relationship = familyMembers[key].Relationship_type;
          var link = '?candID=' + candID + '&identifier=' + candID;
          familyMembersHTML.push( /*#__PURE__*/react__WEBPACK_IMPORTED_MODULE_6___default().createElement("div", {
            key: key
          }, /*#__PURE__*/react__WEBPACK_IMPORTED_MODULE_6___default().createElement(StaticElement, {
            label: "Family Member DCCID",
            text: /*#__PURE__*/react__WEBPACK_IMPORTED_MODULE_6___default().createElement("a", {
              href: link
            }, candID)
          }), /*#__PURE__*/react__WEBPACK_IMPORTED_MODULE_6___default().createElement(StaticElement, {
            label: "Relation Type",
            text: relationshipOptions[relationship]
          }), /*#__PURE__*/react__WEBPACK_IMPORTED_MODULE_6___default().createElement(ButtonElement, {
            label: "Delete",
            type: "button",
            onUserInput: this.deleteFamilyMember.bind(null, candID, key, candidateList)
          }), /*#__PURE__*/react__WEBPACK_IMPORTED_MODULE_6___default().createElement("hr", null))); // remove from list of candidates because it can only be added once

          delete candidateList[candID];
        }
      }

      ;
      var alertMessage = '';
      var alertClass = 'alert text-center hide';

      if (this.state.updateResult) {
        if (this.state.updateResult === 'success') {
          alertClass = 'alert alert-success text-center';
          alertMessage = 'Update Successful!';
        } else if (this.state.updateResult === 'error') {
          var errorMessage = this.state.errorMessage;
          alertClass = 'alert alert-danger text-center';
          alertMessage = errorMessage ? errorMessage : 'Failed to update!';
        }
      }

      return /*#__PURE__*/react__WEBPACK_IMPORTED_MODULE_6___default().createElement("div", {
        className: "row"
      }, /*#__PURE__*/react__WEBPACK_IMPORTED_MODULE_6___default().createElement("div", {
        className: alertClass,
        role: "alert",
        ref: "alert-message"
      }, alertMessage), /*#__PURE__*/react__WEBPACK_IMPORTED_MODULE_6___default().createElement(FormElement, {
        name: "familyInfo",
        onSubmit: this.handleSubmit,
        ref: "form",
        "class": "col-md-6"
      }, /*#__PURE__*/react__WEBPACK_IMPORTED_MODULE_6___default().createElement(StaticElement, {
        label: "PSCID",
        text: this.state.Data.pscid
      }), /*#__PURE__*/react__WEBPACK_IMPORTED_MODULE_6___default().createElement(StaticElement, {
        label: "DCCID",
        text: this.state.Data.candID
      }), /*#__PURE__*/react__WEBPACK_IMPORTED_MODULE_6___default().createElement("hr", null), familyMembersHTML, /*#__PURE__*/react__WEBPACK_IMPORTED_MODULE_6___default().createElement(SelectElement, {
        label: "Family Member ID (DCCID)",
        name: "FamilyCandID",
        options: candidateList,
        onUserInput: this.setFormData,
        ref: "FamilyCandID",
        disabled: disabled,
        required: true,
        value: this.state.formData.FamilyCandID
      }), /*#__PURE__*/react__WEBPACK_IMPORTED_MODULE_6___default().createElement(SelectElement, {
        label: "Relation Type",
        name: "Relationship_type",
        options: relationshipOptions,
        onUserInput: this.setFormData,
        ref: "Relationship_type",
        disabled: disabled,
        required: true,
        value: this.state.formData.Relationship_type
      }), addButton));
    }
    /**
     * Handles form submission
     *
     * @param {event} e - Form submission event
     */

  }, {
    key: "handleSubmit",
    value: function handleSubmit(e) {
      e.preventDefault();
      var myFormData = this.state.formData;
      var self = this;
      var formData = new FormData();
      var formRefs = this.refs;
      var familyMembers = this.state.familyMembers;
      var familyMember = {};

      for (var key in myFormData) {
        if (myFormData.hasOwnProperty(key)) {
          if (myFormData[key] !== '') {
            familyMember[key] = myFormData[key];
            formData.append(key, myFormData[key]);
          }
        }
      }

      formData.append('tab', this.props.tabName);
      formData.append('candID', this.state.Data.candID);
      familyMembers.push(familyMember);
      this.setState({
        familyMembers: familyMembers
      });
      $.ajax({
        type: 'POST',
        url: this.props.action,
        data: formData,
        cache: false,
        contentType: false,
        processData: false,
        success: function success(data) {
          self.setState({
            updateResult: 'success',
            formData: {}
          });
          self.showAlertMessage(); // Iterates through child components and resets state
          // to initial state in order to clear the form

          Object.keys(formRefs).map(function (ref) {
            if (formRefs[ref].state && formRefs[ref].state.value) {
              formRefs[ref].state.value = '';
            }
          }); // rerender components

          self.forceUpdate();
        },
        error: function error(err) {
          var errorMessage = JSON.parse(err.responseText).message;
          self.setState({
            updateResult: 'error',
            errorMessage: errorMessage
          });
          self.showAlertMessage();
        }
      });
    }
    /**
     * Display a success/error alert message after form submission
     */

  }, {
    key: "showAlertMessage",
    value: function showAlertMessage() {
      var self = this;

      if (this.refs['alert-message'] === null) {
        return;
      }

      var alertMsg = this.refs['alert-message'];
      $(alertMsg).fadeTo(2000, 500).delay(3000).slideUp(500, function () {
        self.setState({
          updateResult: null
        });
      });
    }
  }, {
    key: "deleteFamilyMember",
    value: function deleteFamilyMember(candID, key, candidateList) {
      var familyMembers = this.state.familyMembers;
      delete familyMembers[key]; // readd to list of possible family members

      candidateList[candID] = candID;
      this.setState({
        familyMembers: familyMembers
      });
      var myFormData = this.state.formData;
      var self = this;
      var formData = new FormData();

      for (var _key in myFormData) {
        if (myFormData.hasOwnProperty(_key)) {
          if (myFormData[_key] !== '') {
            formData.append(_key, myFormData[_key]);
          }
        }
      }

      formData.append('tab', 'deleteFamilyMember');
      formData.append('candID', this.state.Data.candID);
      formData.append('familyDCCID', candID);
      $.ajax({
        type: 'POST',
        url: this.props.action,
        data: formData,
        cache: false,
        contentType: false,
        processData: false,
        success: function success(data) {
          self.setState({
            updateResult: 'success'
          });
          self.showAlertMessage();
        },
        error: function error(err) {
          if (err.responseText !== '') {
            var errorMessage = JSON.parse(err.responseText).message;
            self.setState({
              updateResult: 'error',
              errorMessage: errorMessage
            });
            self.showAlertMessage();
          }
        }
      });
    }
  }]);

  return FamilyInfo;
}(react__WEBPACK_IMPORTED_MODULE_6__.Component);

FamilyInfo.propTypes = {
  dataURL: (prop_types__WEBPACK_IMPORTED_MODULE_7___default().string),
  tabName: (prop_types__WEBPACK_IMPORTED_MODULE_7___default().string),
  candID: (prop_types__WEBPACK_IMPORTED_MODULE_7___default().string),
  action: (prop_types__WEBPACK_IMPORTED_MODULE_7___default().string)
};
/* harmony default export */ const __WEBPACK_DEFAULT_EXPORT__ = (FamilyInfo);

/***/ }),

/***/ "./modules/candidate_parameters/jsx/ParticipantStatus.js":
/*!***************************************************************!*\
  !*** ./modules/candidate_parameters/jsx/ParticipantStatus.js ***!
  \***************************************************************/
/***/ ((__unused_webpack_module, __webpack_exports__, __webpack_require__) => {

"use strict";
__webpack_require__.r(__webpack_exports__);
/* harmony export */ __webpack_require__.d(__webpack_exports__, {
/* harmony export */   "default": () => (__WEBPACK_DEFAULT_EXPORT__)
/* harmony export */ });
/* harmony import */ var _babel_runtime_helpers_classCallCheck__WEBPACK_IMPORTED_MODULE_0__ = __webpack_require__(/*! @babel/runtime/helpers/classCallCheck */ "./node_modules/@babel/runtime/helpers/esm/classCallCheck.js");
/* harmony import */ var _babel_runtime_helpers_createClass__WEBPACK_IMPORTED_MODULE_1__ = __webpack_require__(/*! @babel/runtime/helpers/createClass */ "./node_modules/@babel/runtime/helpers/esm/createClass.js");
/* harmony import */ var _babel_runtime_helpers_assertThisInitialized__WEBPACK_IMPORTED_MODULE_2__ = __webpack_require__(/*! @babel/runtime/helpers/assertThisInitialized */ "./node_modules/@babel/runtime/helpers/esm/assertThisInitialized.js");
/* harmony import */ var _babel_runtime_helpers_inherits__WEBPACK_IMPORTED_MODULE_3__ = __webpack_require__(/*! @babel/runtime/helpers/inherits */ "./node_modules/@babel/runtime/helpers/esm/inherits.js");
/* harmony import */ var _babel_runtime_helpers_possibleConstructorReturn__WEBPACK_IMPORTED_MODULE_4__ = __webpack_require__(/*! @babel/runtime/helpers/possibleConstructorReturn */ "./node_modules/@babel/runtime/helpers/esm/possibleConstructorReturn.js");
/* harmony import */ var _babel_runtime_helpers_getPrototypeOf__WEBPACK_IMPORTED_MODULE_5__ = __webpack_require__(/*! @babel/runtime/helpers/getPrototypeOf */ "./node_modules/@babel/runtime/helpers/esm/getPrototypeOf.js");
/* harmony import */ var react__WEBPACK_IMPORTED_MODULE_6__ = __webpack_require__(/*! react */ "react");
/* harmony import */ var react__WEBPACK_IMPORTED_MODULE_6___default = /*#__PURE__*/__webpack_require__.n(react__WEBPACK_IMPORTED_MODULE_6__);
/* harmony import */ var prop_types__WEBPACK_IMPORTED_MODULE_7__ = __webpack_require__(/*! prop-types */ "./node_modules/prop-types/index.js");
/* harmony import */ var prop_types__WEBPACK_IMPORTED_MODULE_7___default = /*#__PURE__*/__webpack_require__.n(prop_types__WEBPACK_IMPORTED_MODULE_7__);







function _createSuper(Derived) { var hasNativeReflectConstruct = _isNativeReflectConstruct(); return function _createSuperInternal() { var Super = (0,_babel_runtime_helpers_getPrototypeOf__WEBPACK_IMPORTED_MODULE_5__["default"])(Derived), result; if (hasNativeReflectConstruct) { var NewTarget = (0,_babel_runtime_helpers_getPrototypeOf__WEBPACK_IMPORTED_MODULE_5__["default"])(this).constructor; result = Reflect.construct(Super, arguments, NewTarget); } else { result = Super.apply(this, arguments); } return (0,_babel_runtime_helpers_possibleConstructorReturn__WEBPACK_IMPORTED_MODULE_4__["default"])(this, result); }; }

function _isNativeReflectConstruct() { if (typeof Reflect === "undefined" || !Reflect.construct) return false; if (Reflect.construct.sham) return false; if (typeof Proxy === "function") return true; try { Boolean.prototype.valueOf.call(Reflect.construct(Boolean, [], function () {})); return true; } catch (e) { return false; } }




var ParticipantStatus = /*#__PURE__*/function (_Component) {
  (0,_babel_runtime_helpers_inherits__WEBPACK_IMPORTED_MODULE_3__["default"])(ParticipantStatus, _Component);

  var _super = _createSuper(ParticipantStatus);

  function ParticipantStatus(props) {
    var _this;

    (0,_babel_runtime_helpers_classCallCheck__WEBPACK_IMPORTED_MODULE_0__["default"])(this, ParticipantStatus);

    _this = _super.call(this, props);
    _this.state = {
      Data: [],
      formData: {},
      updateResult: null,
      errorMessage: null,
      isLoaded: false,
      loadedData: 0
    };
    _this.fetchData = _this.fetchData.bind((0,_babel_runtime_helpers_assertThisInitialized__WEBPACK_IMPORTED_MODULE_2__["default"])(_this));
    _this.setFormData = _this.setFormData.bind((0,_babel_runtime_helpers_assertThisInitialized__WEBPACK_IMPORTED_MODULE_2__["default"])(_this));
    _this.onSubmit = _this.onSubmit.bind((0,_babel_runtime_helpers_assertThisInitialized__WEBPACK_IMPORTED_MODULE_2__["default"])(_this));
    _this.handleSubmit = _this.handleSubmit.bind((0,_babel_runtime_helpers_assertThisInitialized__WEBPACK_IMPORTED_MODULE_2__["default"])(_this));
    _this.showAlertMessage = _this.showAlertMessage.bind((0,_babel_runtime_helpers_assertThisInitialized__WEBPACK_IMPORTED_MODULE_2__["default"])(_this));
    return _this;
  }

  (0,_babel_runtime_helpers_createClass__WEBPACK_IMPORTED_MODULE_1__["default"])(ParticipantStatus, [{
    key: "componentDidMount",
    value: function componentDidMount() {
      this.fetchData();
    }
  }, {
    key: "fetchData",
    value: function fetchData() {
      var that = this;
      $.ajax(this.props.dataURL, {
        dataType: 'json',
        xhr: function xhr() {
          var xhr = new window.XMLHttpRequest();
          xhr.addEventListener('progress', function (evt) {
            that.setState({
              loadedData: evt.loaded
            });
          });
          return xhr;
        },
        success: function success(data) {
          var formData = {};
          formData.participantStatus = data.participantStatus;
          formData.participantSuboptions = data.participantSuboptions;
          formData.reasonSpecify = data.reasonSpecify;
          that.setState({
            Data: data,
            formData: formData,
            isLoaded: true
          });
        },
        error: function error(data, errorCode, errorMsg) {
          that.setState({
            error: 'An error occurred when loading the form!'
          });
        }
      });
    }
  }, {
    key: "setFormData",
    value: function setFormData(formElement, value) {
      var formData = this.state.formData;
      var required = this.state.Data.required;

      if (formElement === 'participantStatus' && required.indexOf(value) < 0) {
        formData.participantSuboptions = '';
      }

      formData[formElement] = value;
      this.setState({
        formData: formData
      });
    }
  }, {
    key: "onSubmit",
    value: function onSubmit(e) {
      e.preventDefault();
    }
  }, {
    key: "render",
    value: function render() {
      if (!this.state.isLoaded) {
        if (this.state.error !== undefined) {
          return /*#__PURE__*/react__WEBPACK_IMPORTED_MODULE_6___default().createElement("div", {
            className: "alert alert-danger text-center"
          }, /*#__PURE__*/react__WEBPACK_IMPORTED_MODULE_6___default().createElement("strong", null, this.state.error));
        }
      }

      ;
      var disabled = true;
      var updateButton = null;

      if (loris.userHasPermission('candidate_parameter_edit')) {
        disabled = false;
        updateButton = /*#__PURE__*/react__WEBPACK_IMPORTED_MODULE_6___default().createElement(ButtonElement, {
          label: "Update"
        });
      }

      var required = this.state.Data.required;
      var subOptions = {};
      var suboptionsRequired = false;
      var participantStatus = this.state.formData.participantStatus ? this.state.formData.participantStatus : this.state.Data.participantStatus;

      if (participantStatus && required.indexOf(participantStatus) > -1) {
        subOptions = this.state.Data.parentIDs[participantStatus];
        suboptionsRequired = true;
      }

      var formattedHistory = [];

      for (var statusKey in this.state.Data.history) {
        if (this.state.Data.history.hasOwnProperty(statusKey)) {
          var line = '';

          for (var field in this.state.Data.history[statusKey]) {
            if (this.state.Data.history[statusKey].hasOwnProperty(field)) {
              var current = this.state.Data.history[statusKey][field];

              if (current !== null) {
                switch (field) {
                  case 'data_entry_date':
                    line += '[';
                    line += current;
                    line += '] ';
                    break;

                  case 'entry_staff':
                    line += current;
                    line += ' ';
                    break;

                  case 'status':
                    line += ' Status: ';
                    line += current;
                    line += ' ';
                    break;

                  case 'suboption':
                    line += 'Details: ';
                    line += current;
                    line += ' ';
                    break;

                  case 'reason_specify':
                    line += 'Comments: ';
                    line += current;
                    line += ' ';
                    break;

                  default:
                }
              }
            }
          }

          formattedHistory.push( /*#__PURE__*/react__WEBPACK_IMPORTED_MODULE_6___default().createElement("p", {
            key: statusKey
          }, line));
        }
      }

      var alertMessage = '';
      var alertClass = 'alert text-center hide';

      if (this.state.updateResult) {
        if (this.state.updateResult === 'success') {
          alertClass = 'alert alert-success text-center';
          alertMessage = 'Update Successful!';
        } else if (this.state.updateResult === 'error') {
          var errorMessage = this.state.errorMessage;
          alertClass = 'alert alert-danger text-center';
          alertMessage = errorMessage ? errorMessage : 'Failed to update!';
        }
      }

      return /*#__PURE__*/react__WEBPACK_IMPORTED_MODULE_6___default().createElement("div", {
        className: "row"
      }, /*#__PURE__*/react__WEBPACK_IMPORTED_MODULE_6___default().createElement("div", {
        className: alertClass,
        role: "alert",
        ref: "alert-message"
      }, alertMessage), /*#__PURE__*/react__WEBPACK_IMPORTED_MODULE_6___default().createElement(FormElement, {
        name: "participantStatus",
        onSubmit: this.handleSubmit,
        ref: "form",
        "class": "col-md-6"
      }, /*#__PURE__*/react__WEBPACK_IMPORTED_MODULE_6___default().createElement(StaticElement, {
        label: "PSCID",
        text: this.state.Data.pscid
      }), /*#__PURE__*/react__WEBPACK_IMPORTED_MODULE_6___default().createElement(StaticElement, {
        label: "DCCID",
        text: this.state.Data.candID
      }), /*#__PURE__*/react__WEBPACK_IMPORTED_MODULE_6___default().createElement(SelectElement, {
        label: "Participant Status",
        name: "participantStatus",
        options: this.state.Data.statusOptions,
        value: this.state.formData.participantStatus,
        onUserInput: this.setFormData,
        ref: "participantStatus",
        disabled: disabled,
        required: true
      }), /*#__PURE__*/react__WEBPACK_IMPORTED_MODULE_6___default().createElement(SelectElement, {
        label: "Specify Reason",
        name: "participantSuboptions",
        options: subOptions,
        value: this.state.formData.participantSuboptions,
        onUserInput: this.setFormData,
        ref: "participantSuboptions",
        disabled: !suboptionsRequired,
        required: suboptionsRequired
      }), /*#__PURE__*/react__WEBPACK_IMPORTED_MODULE_6___default().createElement(TextareaElement, {
        label: "Comments",
        name: "reasonSpecify",
        value: this.state.formData.reasonSpecify,
        onUserInput: this.setFormData,
        ref: "reasonSpecify",
        disabled: disabled,
        required: false
      }), updateButton, formattedHistory));
    }
    /**
     * Handles form submission
     *
     * @param {event} e - Form submission event
     */

  }, {
    key: "handleSubmit",
    value: function handleSubmit(e) {
      e.preventDefault();
      var myFormData = this.state.formData;
      var self = this;
      var formData = new FormData();

      for (var key in myFormData) {
        if (myFormData.hasOwnProperty(key) && myFormData[key] !== '' && myFormData[key] !== null && myFormData[key] !== undefined) {
          formData.append(key, myFormData[key]);
        }
      }

      formData.append('tab', this.props.tabName);
      formData.append('candID', this.state.Data.candID);
      $.ajax({
        type: 'POST',
        url: self.props.action,
        data: formData,
        cache: false,
        contentType: false,
        processData: false,
        success: function success(data) {
          self.setState({
            updateResult: 'success'
          });
          self.showAlertMessage();
          self.fetchData();
        },
        error: function error(err) {
          if (err.responseText !== '') {
            var errorMessage = JSON.parse(err.responseText).message;
            self.setState({
              updateResult: 'error',
              errorMessage: errorMessage
            });
            self.showAlertMessage();
          }
        }
      });
    }
    /**
     * Display a success/error alert message after form submission
     */

  }, {
    key: "showAlertMessage",
    value: function showAlertMessage() {
      var self = this;

      if (this.refs['alert-message'] === null) {
        return;
      }

      var alertMsg = this.refs['alert-message'];
      $(alertMsg).fadeTo(2000, 500).delay(3000).slideUp(500, function () {
        self.setState({
          updateResult: null
        });
      });
    }
  }]);

  return ParticipantStatus;
}(react__WEBPACK_IMPORTED_MODULE_6__.Component);

ParticipantStatus.propTypes = {
  dataURL: (prop_types__WEBPACK_IMPORTED_MODULE_7___default().string),
  tabName: (prop_types__WEBPACK_IMPORTED_MODULE_7___default().string),
  action: (prop_types__WEBPACK_IMPORTED_MODULE_7___default().string)
};
/* harmony default export */ const __WEBPACK_DEFAULT_EXPORT__ = (ParticipantStatus);

/***/ }),

/***/ "./modules/candidate_parameters/jsx/ProbandInfo.js":
/*!*********************************************************!*\
  !*** ./modules/candidate_parameters/jsx/ProbandInfo.js ***!
  \*********************************************************/
/***/ ((__unused_webpack_module, __webpack_exports__, __webpack_require__) => {

"use strict";
__webpack_require__.r(__webpack_exports__);
/* harmony export */ __webpack_require__.d(__webpack_exports__, {
/* harmony export */   "default": () => (__WEBPACK_DEFAULT_EXPORT__)
/* harmony export */ });
/* harmony import */ var _babel_runtime_helpers_classCallCheck__WEBPACK_IMPORTED_MODULE_0__ = __webpack_require__(/*! @babel/runtime/helpers/classCallCheck */ "./node_modules/@babel/runtime/helpers/esm/classCallCheck.js");
/* harmony import */ var _babel_runtime_helpers_createClass__WEBPACK_IMPORTED_MODULE_1__ = __webpack_require__(/*! @babel/runtime/helpers/createClass */ "./node_modules/@babel/runtime/helpers/esm/createClass.js");
/* harmony import */ var _babel_runtime_helpers_assertThisInitialized__WEBPACK_IMPORTED_MODULE_2__ = __webpack_require__(/*! @babel/runtime/helpers/assertThisInitialized */ "./node_modules/@babel/runtime/helpers/esm/assertThisInitialized.js");
/* harmony import */ var _babel_runtime_helpers_inherits__WEBPACK_IMPORTED_MODULE_3__ = __webpack_require__(/*! @babel/runtime/helpers/inherits */ "./node_modules/@babel/runtime/helpers/esm/inherits.js");
/* harmony import */ var _babel_runtime_helpers_possibleConstructorReturn__WEBPACK_IMPORTED_MODULE_4__ = __webpack_require__(/*! @babel/runtime/helpers/possibleConstructorReturn */ "./node_modules/@babel/runtime/helpers/esm/possibleConstructorReturn.js");
/* harmony import */ var _babel_runtime_helpers_getPrototypeOf__WEBPACK_IMPORTED_MODULE_5__ = __webpack_require__(/*! @babel/runtime/helpers/getPrototypeOf */ "./node_modules/@babel/runtime/helpers/esm/getPrototypeOf.js");
/* harmony import */ var react__WEBPACK_IMPORTED_MODULE_6__ = __webpack_require__(/*! react */ "react");
/* harmony import */ var react__WEBPACK_IMPORTED_MODULE_6___default = /*#__PURE__*/__webpack_require__.n(react__WEBPACK_IMPORTED_MODULE_6__);
/* harmony import */ var prop_types__WEBPACK_IMPORTED_MODULE_8__ = __webpack_require__(/*! prop-types */ "./node_modules/prop-types/index.js");
/* harmony import */ var prop_types__WEBPACK_IMPORTED_MODULE_8___default = /*#__PURE__*/__webpack_require__.n(prop_types__WEBPACK_IMPORTED_MODULE_8__);
/* harmony import */ var Loader__WEBPACK_IMPORTED_MODULE_7__ = __webpack_require__(/*! Loader */ "./jsx/Loader.js");







function _createSuper(Derived) { var hasNativeReflectConstruct = _isNativeReflectConstruct(); return function _createSuperInternal() { var Super = (0,_babel_runtime_helpers_getPrototypeOf__WEBPACK_IMPORTED_MODULE_5__["default"])(Derived), result; if (hasNativeReflectConstruct) { var NewTarget = (0,_babel_runtime_helpers_getPrototypeOf__WEBPACK_IMPORTED_MODULE_5__["default"])(this).constructor; result = Reflect.construct(Super, arguments, NewTarget); } else { result = Super.apply(this, arguments); } return (0,_babel_runtime_helpers_possibleConstructorReturn__WEBPACK_IMPORTED_MODULE_4__["default"])(this, result); }; }

function _isNativeReflectConstruct() { if (typeof Reflect === "undefined" || !Reflect.construct) return false; if (Reflect.construct.sham) return false; if (typeof Proxy === "function") return true; try { Boolean.prototype.valueOf.call(Reflect.construct(Boolean, [], function () {})); return true; } catch (e) { return false; } }




/**
 * Proband Info Component.
 *
 * Renders the contents of the ProbandInfo tab, consisting of the FormElement component
 */

var ProbandInfo = /*#__PURE__*/function (_Component) {
  (0,_babel_runtime_helpers_inherits__WEBPACK_IMPORTED_MODULE_3__["default"])(ProbandInfo, _Component);

  var _super = _createSuper(ProbandInfo);

  function ProbandInfo(props) {
    var _this;

    (0,_babel_runtime_helpers_classCallCheck__WEBPACK_IMPORTED_MODULE_0__["default"])(this, ProbandInfo);

    _this = _super.call(this, props);
    _this.state = {
      sexOptions: {
        Male: 'Male',
        Female: 'Female',
        Other: 'Other'
      },
      Data: [],
      formData: {},
      updateResult: null,
      errorMessage: null,
      isLoaded: false,
      loadedData: 0
    };
    /**
     * Bind component instance to custom methods
     */

    _this.fetchData = _this.fetchData.bind((0,_babel_runtime_helpers_assertThisInitialized__WEBPACK_IMPORTED_MODULE_2__["default"])(_this));
    _this.setFormData = _this.setFormData.bind((0,_babel_runtime_helpers_assertThisInitialized__WEBPACK_IMPORTED_MODULE_2__["default"])(_this));
    _this.handleSubmit = _this.handleSubmit.bind((0,_babel_runtime_helpers_assertThisInitialized__WEBPACK_IMPORTED_MODULE_2__["default"])(_this));
    _this.showAlertMessage = _this.showAlertMessage.bind((0,_babel_runtime_helpers_assertThisInitialized__WEBPACK_IMPORTED_MODULE_2__["default"])(_this));
    return _this;
  }

  (0,_babel_runtime_helpers_createClass__WEBPACK_IMPORTED_MODULE_1__["default"])(ProbandInfo, [{
    key: "componentDidMount",
    value: function componentDidMount() {
      this.fetchData();
    }
    /**
     * Retrieve data from the provided URL and save it in state
     */

  }, {
    key: "fetchData",
    value: function fetchData() {
      var _this2 = this;

      $.ajax(this.props.dataURL, {
        method: 'GET',
        dataType: 'json',
        success: function success(data) {
          var formData = {
            ProbandSex: data.ProbandSex,
            ProbandDoB: data.ProbandDoB,
            ProbandDoB2: data.ProbandDoB
          }; // Add parameter values to formData

          Object.assign(formData, data.parameter_values);

          _this2.setState({
            formData: formData,
            Data: data,
            isLoaded: true
          });
        },
        error: function error(_error) {
          _this2.setState({
            error: 'An error occurred when loading the form!'
          });
        }
      });
    }
    /**
     * Store the value of the element in this.state.formData
     *
     * @param {string} formElement - name of the form element
     * @param {string} value - value of the form element
     */

  }, {
    key: "setFormData",
    value: function setFormData(formElement, value) {
      var formData = JSON.parse(JSON.stringify(this.state.formData));
      formData[formElement] = value;
      this.setState({
        formData: formData
      });
    }
    /**
     * Handles form submission
     *
     * @param {event} e - Form submission event
     */

  }, {
    key: "handleSubmit",
    value: function handleSubmit(e) {
      var _this3 = this;

      e.preventDefault();
      var myFormData = this.state.formData;
      var today = new Date();
      var dd = today.getDate();
      var mm = today.getMonth() + 1; // January is 0!

      var yyyy = today.getFullYear();

      if (dd < 10) {
        dd = '0' + dd;
      }

      if (mm < 10) {
        mm = '0' + mm;
      }

      today = yyyy + '-' + mm + '-' + dd;
      var dob1 = myFormData.ProbandDoB ? myFormData.ProbandDoB : null;
      var dob2 = myFormData.ProbandDoB2 ? myFormData.ProbandDoB2 : null;

      if (dob1 !== dob2) {
        alert('DOB do not match!');
        return;
      }

      if (dob1 > today) {
        alert('Proband date of birth cannot be later than today!');
        return;
      } // Set form data


      var formData = new FormData();

      for (var key in myFormData) {
        if (myFormData[key] !== '') {
          formData.append(key, myFormData[key]);
        }
      }

      formData.append('tab', this.props.tabName);
      formData.append('candID', this.state.Data.candID);
      $.ajax({
        type: 'POST',
        url: this.props.action,
        data: formData,
        cache: false,
        contentType: false,
        processData: false,
        success: function success(data) {
          _this3.setState({
            updateResult: 'success'
          });

          _this3.showAlertMessage();

          _this3.fetchData();
        },
        error: function error(_error2) {
          if (_error2.responseText !== '') {
            var errorMessage = JSON.parse(_error2.responseText).message;

            _this3.setState({
              updateResult: 'error',
              errorMessage: errorMessage
            });

            _this3.showAlertMessage();
          }
        }
      });
    }
    /**
     * Display a success/error alert message after form submission
     */

  }, {
    key: "showAlertMessage",
    value: function showAlertMessage() {
      var _this4 = this;

      if (this.refs['alert-message'] === null) {
        return;
      }

      var alertMsg = this.refs['alert-message'];
      $(alertMsg).fadeTo(2000, 500).delay(3000).slideUp(500, function () {
        _this4.setState({
          updateResult: null
        });
      });
    }
  }, {
    key: "render",
    value: function render() {
      if (!this.state.isLoaded) {
        return /*#__PURE__*/react__WEBPACK_IMPORTED_MODULE_6___default().createElement(Loader__WEBPACK_IMPORTED_MODULE_7__["default"], null);
      }

      var disabled = true;
      var updateButton = null;

      if (loris.userHasPermission('candidate_parameter_edit')) {
        disabled = false;
        updateButton = /*#__PURE__*/react__WEBPACK_IMPORTED_MODULE_6___default().createElement(ButtonElement, {
          label: "Update"
        });
      }

      var dobRequired = false;
      var dob2Required = false;

      if (this.state.formData.ProbandSex !== null) {
        dobRequired = true;
      }

      if (this.state.formData.ProbandDoB !== null) {
        dob2Required = true;
      }

      var extraParameterFields = [];
      var extraParameters = this.state.Data.extra_parameters;

      for (var key2 in extraParameters) {
        if (extraParameters.hasOwnProperty(key2)) {
          var paramTypeID = extraParameters[key2].ParameterTypeID;
          var name = paramTypeID;
          var value = this.state.formData[paramTypeID];

          switch (extraParameters[key2].Type.substring(0, 3)) {
            case 'enu':
              {
                var types = extraParameters[key2].Type.substring(5);
                types = types.slice(0, -1);
                types = types.replace(/'/g, '');
                types = types.split(',');
                var selectOptions = {};

                for (var key3 in types) {
                  if (types.hasOwnProperty(key3)) {
                    selectOptions[types[key3]] = types[key3];
                  }
                }

                extraParameterFields.push( /*#__PURE__*/react__WEBPACK_IMPORTED_MODULE_6___default().createElement(SelectElement, {
                  label: extraParameters[key2].Description,
                  name: name,
                  options: selectOptions,
                  value: value,
                  onUserInput: this.setFormData,
                  ref: name,
                  disabled: disabled,
                  key: key2
                }));
                break;
              }

            case 'dat':
              extraParameterFields.push( /*#__PURE__*/react__WEBPACK_IMPORTED_MODULE_6___default().createElement(DateElement, {
                label: extraParameters[key2].Description,
                name: name,
                value: value,
                onUserInput: this.setFormData,
                ref: name,
                disabled: disabled,
                key: key2
              }));
              break;

            default:
              extraParameterFields.push( /*#__PURE__*/react__WEBPACK_IMPORTED_MODULE_6___default().createElement(TextareaElement, {
                label: extraParameters[key2].Description,
                name: name,
                value: value,
                onUserInput: this.setFormData,
                ref: name,
                disabled: disabled,
                key: key2
              }));
          }
        }
      }

      var alertMessage = '';
      var alertClass = 'alert text-center hide';

      if (this.state.updateResult) {
        if (this.state.updateResult === 'success') {
          alertClass = 'alert alert-success text-center';
          alertMessage = 'Update Successful!';
        } else if (this.state.updateResult === 'error') {
          var errorMessage = this.state.errorMessage;
          alertClass = 'alert alert-danger text-center';
          alertMessage = errorMessage ? errorMessage : 'Failed to update!';
        }
      }

      return /*#__PURE__*/react__WEBPACK_IMPORTED_MODULE_6___default().createElement("div", {
        className: "row"
      }, /*#__PURE__*/react__WEBPACK_IMPORTED_MODULE_6___default().createElement("div", {
        className: alertClass,
        role: "alert",
        ref: "alert-message"
      }, alertMessage), /*#__PURE__*/react__WEBPACK_IMPORTED_MODULE_6___default().createElement(FormElement, {
        name: "probandInfo",
        onSubmit: this.handleSubmit,
        ref: "form",
        "class": "col-md-6"
      }, /*#__PURE__*/react__WEBPACK_IMPORTED_MODULE_6___default().createElement(StaticElement, {
        label: "PSCID",
        text: this.state.Data.pscid
      }), /*#__PURE__*/react__WEBPACK_IMPORTED_MODULE_6___default().createElement(StaticElement, {
        label: "DCCID",
        text: this.state.Data.candID
      }), /*#__PURE__*/react__WEBPACK_IMPORTED_MODULE_6___default().createElement(SelectElement, {
        label: "Proband Sex",
        name: "ProbandSex",
        options: this.state.sexOptions,
        value: this.state.formData.ProbandSex,
        onUserInput: this.setFormData,
        ref: "ProbandSex",
        disabled: disabled,
        required: true
      }), /*#__PURE__*/react__WEBPACK_IMPORTED_MODULE_6___default().createElement(DateElement, {
        label: "DoB Proband",
        name: "ProbandDoB",
        value: this.state.formData.ProbandDoB,
        onUserInput: this.setFormData,
        ref: "ProbandDoB",
        disabled: disabled,
        required: dobRequired
      }), /*#__PURE__*/react__WEBPACK_IMPORTED_MODULE_6___default().createElement(DateElement, {
        label: "Confirm DoB Proband",
        name: "ProbandDoB2",
        value: this.state.formData.ProbandDoB2,
        onUserInput: this.setFormData,
        ref: "ProbandDoB2",
        disabled: disabled,
        required: dob2Required
      }), /*#__PURE__*/react__WEBPACK_IMPORTED_MODULE_6___default().createElement(StaticElement, {
        label: "Age Difference (months)",
        text: this.state.Data.ageDifference.toString()
      }), extraParameterFields, updateButton));
    }
  }]);

  return ProbandInfo;
}(react__WEBPACK_IMPORTED_MODULE_6__.Component);

ProbandInfo.propTypes = {
  dataURL: (prop_types__WEBPACK_IMPORTED_MODULE_8___default().string.isRequired),
  action: (prop_types__WEBPACK_IMPORTED_MODULE_8___default().string.isRequired),
  tabName: (prop_types__WEBPACK_IMPORTED_MODULE_8___default().string)
};
/* harmony default export */ const __WEBPACK_DEFAULT_EXPORT__ = (ProbandInfo);

/***/ }),

/***/ "./node_modules/object-assign/index.js":
/*!*********************************************!*\
  !*** ./node_modules/object-assign/index.js ***!
  \*********************************************/
/***/ ((module) => {

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

/***/ "./node_modules/prop-types/checkPropTypes.js":
/*!***************************************************!*\
  !*** ./node_modules/prop-types/checkPropTypes.js ***!
  \***************************************************/
/***/ ((module, __unused_webpack_exports, __webpack_require__) => {

"use strict";
/**
 * Copyright (c) 2013-present, Facebook, Inc.
 *
 * This source code is licensed under the MIT license found in the
 * LICENSE file in the root directory of this source tree.
 */



var printWarning = function() {};

if (true) {
  var ReactPropTypesSecret = __webpack_require__(/*! ./lib/ReactPropTypesSecret */ "./node_modules/prop-types/lib/ReactPropTypesSecret.js");
  var loggedTypeFailures = {};
  var has = __webpack_require__(/*! ./lib/has */ "./node_modules/prop-types/lib/has.js");

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
    } catch (x) { /**/ }
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
              'it must be a function, usually from the `prop-types` package, but received `' + typeof typeSpecs[typeSpecName] + '`.' +
              'This often happens because of typos such as `PropTypes.function` instead of `PropTypes.func`.'
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

/***/ "./node_modules/prop-types/factoryWithTypeCheckers.js":
/*!************************************************************!*\
  !*** ./node_modules/prop-types/factoryWithTypeCheckers.js ***!
  \************************************************************/
/***/ ((module, __unused_webpack_exports, __webpack_require__) => {

"use strict";
/**
 * Copyright (c) 2013-present, Facebook, Inc.
 *
 * This source code is licensed under the MIT license found in the
 * LICENSE file in the root directory of this source tree.
 */



var ReactIs = __webpack_require__(/*! react-is */ "./node_modules/react-is/index.js");
var assign = __webpack_require__(/*! object-assign */ "./node_modules/object-assign/index.js");

var ReactPropTypesSecret = __webpack_require__(/*! ./lib/ReactPropTypesSecret */ "./node_modules/prop-types/lib/ReactPropTypesSecret.js");
var has = __webpack_require__(/*! ./lib/has */ "./node_modules/prop-types/lib/has.js");
var checkPropTypes = __webpack_require__(/*! ./checkPropTypes */ "./node_modules/prop-types/checkPropTypes.js");

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
    bigint: createPrimitiveTypeChecker('bigint'),
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
  function PropTypeError(message, data) {
    this.message = message;
    this.data = data && typeof data === 'object' ? data: {};
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
              'function for the `' + propFullName + '` prop on `' + componentName + '`. This is deprecated ' +
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

        return new PropTypeError(
          'Invalid ' + location + ' `' + propFullName + '` of type ' + ('`' + preciseType + '` supplied to `' + componentName + '`, expected ') + ('`' + expectedType + '`.'),
          {expectedType: expectedType}
        );
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
       true ? printWarning('Invalid argument supplied to oneOfType, expected an instance of array.') : 0;
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
      var expectedTypes = [];
      for (var i = 0; i < arrayOfTypeCheckers.length; i++) {
        var checker = arrayOfTypeCheckers[i];
        var checkerResult = checker(props, propName, componentName, location, propFullName, ReactPropTypesSecret);
        if (checkerResult == null) {
          return null;
        }
        if (checkerResult.data && has(checkerResult.data, 'expectedType')) {
          expectedTypes.push(checkerResult.data.expectedType);
        }
      }
      var expectedTypesMessage = (expectedTypes.length > 0) ? ', expected one of type [' + expectedTypes.join(', ') + ']': '';
      return new PropTypeError('Invalid ' + location + ' `' + propFullName + '` supplied to ' + ('`' + componentName + '`' + expectedTypesMessage + '.'));
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

  function invalidValidatorError(componentName, location, propFullName, key, type) {
    return new PropTypeError(
      (componentName || 'React class') + ': ' + location + ' type `' + propFullName + '.' + key + '` is invalid; ' +
      'it must be a function, usually from the `prop-types` package, but received `' + type + '`.'
    );
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
        if (typeof checker !== 'function') {
          return invalidValidatorError(componentName, location, propFullName, key, getPreciseType(checker));
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
      // We need to check all keys in case some are required but missing from props.
      var allKeys = assign({}, props[propName], shapeTypes);
      for (var key in allKeys) {
        var checker = shapeTypes[key];
        if (has(shapeTypes, key) && typeof checker !== 'function') {
          return invalidValidatorError(componentName, location, propFullName, key, getPreciseType(checker));
        }
        if (!checker) {
          return new PropTypeError(
            'Invalid ' + location + ' `' + propFullName + '` key `' + key + '` supplied to `' + componentName + '`.' +
            '\nBad object: ' + JSON.stringify(props[propName], null, '  ') +
            '\nValid keys: ' + JSON.stringify(Object.keys(shapeTypes), null, '  ')
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

/***/ "./node_modules/prop-types/index.js":
/*!******************************************!*\
  !*** ./node_modules/prop-types/index.js ***!
  \******************************************/
/***/ ((module, __unused_webpack_exports, __webpack_require__) => {

/**
 * Copyright (c) 2013-present, Facebook, Inc.
 *
 * This source code is licensed under the MIT license found in the
 * LICENSE file in the root directory of this source tree.
 */

if (true) {
  var ReactIs = __webpack_require__(/*! react-is */ "./node_modules/react-is/index.js");

  // By explicitly using `prop-types` you are opting into new development behavior.
  // http://fb.me/prop-types-in-prod
  var throwOnDirectAccess = true;
  module.exports = __webpack_require__(/*! ./factoryWithTypeCheckers */ "./node_modules/prop-types/factoryWithTypeCheckers.js")(ReactIs.isElement, throwOnDirectAccess);
} else {}


/***/ }),

/***/ "./node_modules/prop-types/lib/ReactPropTypesSecret.js":
/*!*************************************************************!*\
  !*** ./node_modules/prop-types/lib/ReactPropTypesSecret.js ***!
  \*************************************************************/
/***/ ((module) => {

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

/***/ "./node_modules/prop-types/lib/has.js":
/*!********************************************!*\
  !*** ./node_modules/prop-types/lib/has.js ***!
  \********************************************/
/***/ ((module) => {

module.exports = Function.call.bind(Object.prototype.hasOwnProperty);


/***/ }),

/***/ "./node_modules/react-is/cjs/react-is.development.js":
/*!***********************************************************!*\
  !*** ./node_modules/react-is/cjs/react-is.development.js ***!
  \***********************************************************/
/***/ ((__unused_webpack_module, exports) => {

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

/***/ "./node_modules/react-is/index.js":
/*!****************************************!*\
  !*** ./node_modules/react-is/index.js ***!
  \****************************************/
/***/ ((module, __unused_webpack_exports, __webpack_require__) => {

"use strict";


if (false) {} else {
  module.exports = __webpack_require__(/*! ./cjs/react-is.development.js */ "./node_modules/react-is/cjs/react-is.development.js");
}


/***/ }),

/***/ "react":
/*!************************!*\
  !*** external "React" ***!
  \************************/
/***/ ((module) => {

"use strict";
module.exports = window["React"];

/***/ }),

/***/ "./node_modules/@babel/runtime/helpers/esm/assertThisInitialized.js":
/*!**************************************************************************!*\
  !*** ./node_modules/@babel/runtime/helpers/esm/assertThisInitialized.js ***!
  \**************************************************************************/
/***/ ((__unused_webpack___webpack_module__, __webpack_exports__, __webpack_require__) => {

"use strict";
__webpack_require__.r(__webpack_exports__);
/* harmony export */ __webpack_require__.d(__webpack_exports__, {
/* harmony export */   "default": () => (/* binding */ _assertThisInitialized)
/* harmony export */ });
function _assertThisInitialized(self) {
  if (self === void 0) {
    throw new ReferenceError("this hasn't been initialised - super() hasn't been called");
  }

  return self;
}

/***/ }),

/***/ "./node_modules/@babel/runtime/helpers/esm/classCallCheck.js":
/*!*******************************************************************!*\
  !*** ./node_modules/@babel/runtime/helpers/esm/classCallCheck.js ***!
  \*******************************************************************/
/***/ ((__unused_webpack___webpack_module__, __webpack_exports__, __webpack_require__) => {

"use strict";
__webpack_require__.r(__webpack_exports__);
/* harmony export */ __webpack_require__.d(__webpack_exports__, {
/* harmony export */   "default": () => (/* binding */ _classCallCheck)
/* harmony export */ });
function _classCallCheck(instance, Constructor) {
  if (!(instance instanceof Constructor)) {
    throw new TypeError("Cannot call a class as a function");
  }
}

/***/ }),

/***/ "./node_modules/@babel/runtime/helpers/esm/createClass.js":
/*!****************************************************************!*\
  !*** ./node_modules/@babel/runtime/helpers/esm/createClass.js ***!
  \****************************************************************/
/***/ ((__unused_webpack___webpack_module__, __webpack_exports__, __webpack_require__) => {

"use strict";
__webpack_require__.r(__webpack_exports__);
/* harmony export */ __webpack_require__.d(__webpack_exports__, {
/* harmony export */   "default": () => (/* binding */ _createClass)
/* harmony export */ });
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
  Object.defineProperty(Constructor, "prototype", {
    writable: false
  });
  return Constructor;
}

/***/ }),

/***/ "./node_modules/@babel/runtime/helpers/esm/getPrototypeOf.js":
/*!*******************************************************************!*\
  !*** ./node_modules/@babel/runtime/helpers/esm/getPrototypeOf.js ***!
  \*******************************************************************/
/***/ ((__unused_webpack___webpack_module__, __webpack_exports__, __webpack_require__) => {

"use strict";
__webpack_require__.r(__webpack_exports__);
/* harmony export */ __webpack_require__.d(__webpack_exports__, {
/* harmony export */   "default": () => (/* binding */ _getPrototypeOf)
/* harmony export */ });
function _getPrototypeOf(o) {
  _getPrototypeOf = Object.setPrototypeOf ? Object.getPrototypeOf.bind() : function _getPrototypeOf(o) {
    return o.__proto__ || Object.getPrototypeOf(o);
  };
  return _getPrototypeOf(o);
}

/***/ }),

/***/ "./node_modules/@babel/runtime/helpers/esm/inherits.js":
/*!*************************************************************!*\
  !*** ./node_modules/@babel/runtime/helpers/esm/inherits.js ***!
  \*************************************************************/
/***/ ((__unused_webpack___webpack_module__, __webpack_exports__, __webpack_require__) => {

"use strict";
__webpack_require__.r(__webpack_exports__);
/* harmony export */ __webpack_require__.d(__webpack_exports__, {
/* harmony export */   "default": () => (/* binding */ _inherits)
/* harmony export */ });
/* harmony import */ var _setPrototypeOf_js__WEBPACK_IMPORTED_MODULE_0__ = __webpack_require__(/*! ./setPrototypeOf.js */ "./node_modules/@babel/runtime/helpers/esm/setPrototypeOf.js");

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
  Object.defineProperty(subClass, "prototype", {
    writable: false
  });
  if (superClass) (0,_setPrototypeOf_js__WEBPACK_IMPORTED_MODULE_0__["default"])(subClass, superClass);
}

/***/ }),

/***/ "./node_modules/@babel/runtime/helpers/esm/possibleConstructorReturn.js":
/*!******************************************************************************!*\
  !*** ./node_modules/@babel/runtime/helpers/esm/possibleConstructorReturn.js ***!
  \******************************************************************************/
/***/ ((__unused_webpack___webpack_module__, __webpack_exports__, __webpack_require__) => {

"use strict";
__webpack_require__.r(__webpack_exports__);
/* harmony export */ __webpack_require__.d(__webpack_exports__, {
/* harmony export */   "default": () => (/* binding */ _possibleConstructorReturn)
/* harmony export */ });
/* harmony import */ var _typeof_js__WEBPACK_IMPORTED_MODULE_0__ = __webpack_require__(/*! ./typeof.js */ "./node_modules/@babel/runtime/helpers/esm/typeof.js");
/* harmony import */ var _assertThisInitialized_js__WEBPACK_IMPORTED_MODULE_1__ = __webpack_require__(/*! ./assertThisInitialized.js */ "./node_modules/@babel/runtime/helpers/esm/assertThisInitialized.js");


function _possibleConstructorReturn(self, call) {
  if (call && ((0,_typeof_js__WEBPACK_IMPORTED_MODULE_0__["default"])(call) === "object" || typeof call === "function")) {
    return call;
  } else if (call !== void 0) {
    throw new TypeError("Derived constructors may only return object or undefined");
  }

  return (0,_assertThisInitialized_js__WEBPACK_IMPORTED_MODULE_1__["default"])(self);
}

/***/ }),

/***/ "./node_modules/@babel/runtime/helpers/esm/setPrototypeOf.js":
/*!*******************************************************************!*\
  !*** ./node_modules/@babel/runtime/helpers/esm/setPrototypeOf.js ***!
  \*******************************************************************/
/***/ ((__unused_webpack___webpack_module__, __webpack_exports__, __webpack_require__) => {

"use strict";
__webpack_require__.r(__webpack_exports__);
/* harmony export */ __webpack_require__.d(__webpack_exports__, {
/* harmony export */   "default": () => (/* binding */ _setPrototypeOf)
/* harmony export */ });
function _setPrototypeOf(o, p) {
  _setPrototypeOf = Object.setPrototypeOf ? Object.setPrototypeOf.bind() : function _setPrototypeOf(o, p) {
    o.__proto__ = p;
    return o;
  };
  return _setPrototypeOf(o, p);
}

/***/ }),

/***/ "./node_modules/@babel/runtime/helpers/esm/typeof.js":
/*!***********************************************************!*\
  !*** ./node_modules/@babel/runtime/helpers/esm/typeof.js ***!
  \***********************************************************/
/***/ ((__unused_webpack___webpack_module__, __webpack_exports__, __webpack_require__) => {

"use strict";
__webpack_require__.r(__webpack_exports__);
/* harmony export */ __webpack_require__.d(__webpack_exports__, {
/* harmony export */   "default": () => (/* binding */ _typeof)
/* harmony export */ });
function _typeof(obj) {
  "@babel/helpers - typeof";

  return _typeof = "function" == typeof Symbol && "symbol" == typeof Symbol.iterator ? function (obj) {
    return typeof obj;
  } : function (obj) {
    return obj && "function" == typeof Symbol && obj.constructor === Symbol && obj !== Symbol.prototype ? "symbol" : typeof obj;
  }, _typeof(obj);
}

/***/ })

/******/ 	});
/************************************************************************/
/******/ 	// The module cache
/******/ 	var __webpack_module_cache__ = {};
/******/ 	
/******/ 	// The require function
/******/ 	function __webpack_require__(moduleId) {
/******/ 		// Check if module is in cache
/******/ 		var cachedModule = __webpack_module_cache__[moduleId];
/******/ 		if (cachedModule !== undefined) {
/******/ 			return cachedModule.exports;
/******/ 		}
/******/ 		// Create a new module (and put it into the cache)
/******/ 		var module = __webpack_module_cache__[moduleId] = {
/******/ 			// no module.id needed
/******/ 			// no module.loaded needed
/******/ 			exports: {}
/******/ 		};
/******/ 	
/******/ 		// Execute the module function
/******/ 		__webpack_modules__[moduleId](module, module.exports, __webpack_require__);
/******/ 	
/******/ 		// Return the exports of the module
/******/ 		return module.exports;
/******/ 	}
/******/ 	
/************************************************************************/
/******/ 	/* webpack/runtime/compat get default export */
/******/ 	(() => {
/******/ 		// getDefaultExport function for compatibility with non-harmony modules
/******/ 		__webpack_require__.n = (module) => {
/******/ 			var getter = module && module.__esModule ?
/******/ 				() => (module['default']) :
/******/ 				() => (module);
/******/ 			__webpack_require__.d(getter, { a: getter });
/******/ 			return getter;
/******/ 		};
/******/ 	})();
/******/ 	
/******/ 	/* webpack/runtime/define property getters */
/******/ 	(() => {
/******/ 		// define getter functions for harmony exports
/******/ 		__webpack_require__.d = (exports, definition) => {
/******/ 			for(var key in definition) {
/******/ 				if(__webpack_require__.o(definition, key) && !__webpack_require__.o(exports, key)) {
/******/ 					Object.defineProperty(exports, key, { enumerable: true, get: definition[key] });
/******/ 				}
/******/ 			}
/******/ 		};
/******/ 	})();
/******/ 	
/******/ 	/* webpack/runtime/hasOwnProperty shorthand */
/******/ 	(() => {
/******/ 		__webpack_require__.o = (obj, prop) => (Object.prototype.hasOwnProperty.call(obj, prop))
/******/ 	})();
/******/ 	
/******/ 	/* webpack/runtime/make namespace object */
/******/ 	(() => {
/******/ 		// define __esModule on exports
/******/ 		__webpack_require__.r = (exports) => {
/******/ 			if(typeof Symbol !== 'undefined' && Symbol.toStringTag) {
/******/ 				Object.defineProperty(exports, Symbol.toStringTag, { value: 'Module' });
/******/ 			}
/******/ 			Object.defineProperty(exports, '__esModule', { value: true });
/******/ 		};
/******/ 	})();
/******/ 	
/************************************************************************/
var __webpack_exports__ = {};
// This entry need to be wrapped in an IIFE because it need to be in strict mode.
(() => {
"use strict";
/*!*****************************************************************!*\
  !*** ./modules/candidate_parameters/jsx/CandidateParameters.js ***!
  \*****************************************************************/
__webpack_require__.r(__webpack_exports__);
/* harmony import */ var _babel_runtime_helpers_classCallCheck__WEBPACK_IMPORTED_MODULE_0__ = __webpack_require__(/*! @babel/runtime/helpers/classCallCheck */ "./node_modules/@babel/runtime/helpers/esm/classCallCheck.js");
/* harmony import */ var _babel_runtime_helpers_createClass__WEBPACK_IMPORTED_MODULE_1__ = __webpack_require__(/*! @babel/runtime/helpers/createClass */ "./node_modules/@babel/runtime/helpers/esm/createClass.js");
/* harmony import */ var _babel_runtime_helpers_assertThisInitialized__WEBPACK_IMPORTED_MODULE_2__ = __webpack_require__(/*! @babel/runtime/helpers/assertThisInitialized */ "./node_modules/@babel/runtime/helpers/esm/assertThisInitialized.js");
/* harmony import */ var _babel_runtime_helpers_inherits__WEBPACK_IMPORTED_MODULE_3__ = __webpack_require__(/*! @babel/runtime/helpers/inherits */ "./node_modules/@babel/runtime/helpers/esm/inherits.js");
/* harmony import */ var _babel_runtime_helpers_possibleConstructorReturn__WEBPACK_IMPORTED_MODULE_4__ = __webpack_require__(/*! @babel/runtime/helpers/possibleConstructorReturn */ "./node_modules/@babel/runtime/helpers/esm/possibleConstructorReturn.js");
/* harmony import */ var _babel_runtime_helpers_getPrototypeOf__WEBPACK_IMPORTED_MODULE_5__ = __webpack_require__(/*! @babel/runtime/helpers/getPrototypeOf */ "./node_modules/@babel/runtime/helpers/esm/getPrototypeOf.js");
/* harmony import */ var react__WEBPACK_IMPORTED_MODULE_6__ = __webpack_require__(/*! react */ "react");
/* harmony import */ var react__WEBPACK_IMPORTED_MODULE_6___default = /*#__PURE__*/__webpack_require__.n(react__WEBPACK_IMPORTED_MODULE_6__);
/* harmony import */ var prop_types__WEBPACK_IMPORTED_MODULE_15__ = __webpack_require__(/*! prop-types */ "./node_modules/prop-types/index.js");
/* harmony import */ var prop_types__WEBPACK_IMPORTED_MODULE_15___default = /*#__PURE__*/__webpack_require__.n(prop_types__WEBPACK_IMPORTED_MODULE_15__);
/* harmony import */ var _CandidateInfo__WEBPACK_IMPORTED_MODULE_7__ = __webpack_require__(/*! ./CandidateInfo */ "./modules/candidate_parameters/jsx/CandidateInfo.js");
/* harmony import */ var _ProbandInfo__WEBPACK_IMPORTED_MODULE_8__ = __webpack_require__(/*! ./ProbandInfo */ "./modules/candidate_parameters/jsx/ProbandInfo.js");
/* harmony import */ var _FamilyInfo__WEBPACK_IMPORTED_MODULE_9__ = __webpack_require__(/*! ./FamilyInfo */ "./modules/candidate_parameters/jsx/FamilyInfo.js");
/* harmony import */ var _ParticipantStatus__WEBPACK_IMPORTED_MODULE_10__ = __webpack_require__(/*! ./ParticipantStatus */ "./modules/candidate_parameters/jsx/ParticipantStatus.js");
/* harmony import */ var _ConsentStatus__WEBPACK_IMPORTED_MODULE_11__ = __webpack_require__(/*! ./ConsentStatus */ "./modules/candidate_parameters/jsx/ConsentStatus.js");
/* harmony import */ var _CandidateDOB__WEBPACK_IMPORTED_MODULE_12__ = __webpack_require__(/*! ./CandidateDOB */ "./modules/candidate_parameters/jsx/CandidateDOB.js");
/* harmony import */ var _CandidateDOD__WEBPACK_IMPORTED_MODULE_13__ = __webpack_require__(/*! ./CandidateDOD */ "./modules/candidate_parameters/jsx/CandidateDOD.js");
/* harmony import */ var Tabs__WEBPACK_IMPORTED_MODULE_14__ = __webpack_require__(/*! Tabs */ "./jsx/Tabs.js");







function _createSuper(Derived) { var hasNativeReflectConstruct = _isNativeReflectConstruct(); return function _createSuperInternal() { var Super = (0,_babel_runtime_helpers_getPrototypeOf__WEBPACK_IMPORTED_MODULE_5__["default"])(Derived), result; if (hasNativeReflectConstruct) { var NewTarget = (0,_babel_runtime_helpers_getPrototypeOf__WEBPACK_IMPORTED_MODULE_5__["default"])(this).constructor; result = Reflect.construct(Super, arguments, NewTarget); } else { result = Super.apply(this, arguments); } return (0,_babel_runtime_helpers_possibleConstructorReturn__WEBPACK_IMPORTED_MODULE_4__["default"])(this, result); }; }

function _isNativeReflectConstruct() { if (typeof Reflect === "undefined" || !Reflect.construct) return false; if (Reflect.construct.sham) return false; if (typeof Proxy === "function") return true; try { Boolean.prototype.valueOf.call(Reflect.construct(Boolean, [], function () {})); return true; } catch (e) { return false; } }












var CandidateParameters = /*#__PURE__*/function (_Component) {
  (0,_babel_runtime_helpers_inherits__WEBPACK_IMPORTED_MODULE_3__["default"])(CandidateParameters, _Component);

  var _super = _createSuper(CandidateParameters);

  function CandidateParameters(props) {
    var _this;

    (0,_babel_runtime_helpers_classCallCheck__WEBPACK_IMPORTED_MODULE_0__["default"])(this, CandidateParameters);

    _this = _super.call(this, props);
    _this.getTabPanes = _this.getTabPanes.bind((0,_babel_runtime_helpers_assertThisInitialized__WEBPACK_IMPORTED_MODULE_2__["default"])(_this));
    return _this;
  }

  (0,_babel_runtime_helpers_createClass__WEBPACK_IMPORTED_MODULE_1__["default"])(CandidateParameters, [{
    key: "getTabPanes",
    value: function getTabPanes(tabList) {
      var actionURL = "".concat(loris.BaseURL, "/candidate_parameters/ajax/formHandler.php");
      var dataURL = "".concat(loris.BaseURL, "/candidate_parameters/ajax/getData.php?candID=").concat(this.props.candID);
      var tabPanes = Object.keys(tabList).map(function (key) {
        var TabContent = tabList[key].component;
        return /*#__PURE__*/react__WEBPACK_IMPORTED_MODULE_6___default().createElement(Tabs__WEBPACK_IMPORTED_MODULE_14__.TabPane, {
          TabId: tabList[key].id,
          key: key
        }, /*#__PURE__*/react__WEBPACK_IMPORTED_MODULE_6___default().createElement(TabContent, {
          action: actionURL,
          dataURL: "".concat(dataURL, "&data=").concat(tabList[key].id),
          tabName: tabList[key].id
        }));
      });
      return tabPanes;
    }
  }, {
    key: "render",
    value: function render() {
      var tabList = [{
        id: 'candidateInfo',
        label: 'Candidate Information',
        component: _CandidateInfo__WEBPACK_IMPORTED_MODULE_7__["default"]
      }, {
        id: 'participantStatus',
        label: 'Participant Status',
        component: _ParticipantStatus__WEBPACK_IMPORTED_MODULE_10__["default"]
      }, {
        id: 'candidateDOB',
        label: 'Date of Birth',
        component: _CandidateDOB__WEBPACK_IMPORTED_MODULE_12__["default"]
      }, {
        id: 'candidateDOD',
        label: 'Date of Death',
        component: _CandidateDOD__WEBPACK_IMPORTED_MODULE_13__["default"]
      }];

      if (loris.config('useProband') === 'true') {
        tabList.push({
          id: 'probandInfo',
          label: 'Proband Information',
          component: _ProbandInfo__WEBPACK_IMPORTED_MODULE_8__["default"]
        });
      }

      if (loris.config('useFamilyID') === 'true') {
        tabList.push({
          id: 'familyInfo',
          label: 'Family Information',
          component: _FamilyInfo__WEBPACK_IMPORTED_MODULE_9__["default"]
        });
      }

      if (loris.config('useConsent') === 'true') {
        tabList.push({
          id: 'consentStatus',
          label: 'Consent Status',
          component: _ConsentStatus__WEBPACK_IMPORTED_MODULE_11__["default"]
        });
      }

      return /*#__PURE__*/react__WEBPACK_IMPORTED_MODULE_6___default().createElement("div", null, /*#__PURE__*/react__WEBPACK_IMPORTED_MODULE_6___default().createElement("a", {
        className: "btn btn-sm btn-primary",
        href: loris.BaseURL + '/' + this.props.candID,
        style: {
          marginBottom: '20px'
        }
      }, "Return to timepoint list"), /*#__PURE__*/react__WEBPACK_IMPORTED_MODULE_6___default().createElement("br", null), /*#__PURE__*/react__WEBPACK_IMPORTED_MODULE_6___default().createElement(Tabs__WEBPACK_IMPORTED_MODULE_14__.Tabs, {
        tabs: tabList,
        defaultTab: "candidateInfo",
        updateURL: true
      }, this.getTabPanes(tabList)));
    }
  }]);

  return CandidateParameters;
}(react__WEBPACK_IMPORTED_MODULE_6__.Component);

CandidateParameters.propTypes = {
  candID: (prop_types__WEBPACK_IMPORTED_MODULE_15___default().string.isRequired)
};
/**
 * Render Candidate Parameters component on page load
 */

var args = QueryString.get(document.currentScript.src);
window.addEventListener('load', function () {
  var candidateParameters = /*#__PURE__*/react__WEBPACK_IMPORTED_MODULE_6___default().createElement("div", {
    className: "page-candidate-parameters"
  }, /*#__PURE__*/react__WEBPACK_IMPORTED_MODULE_6___default().createElement(CandidateParameters, {
    Module: "candidate_parameters",
    candID: args.candID
  }));
  ReactDOM.render(candidateParameters, document.getElementById('lorisworkspace'));
});
})();

((window.lorisjs = window.lorisjs || {}).candidate_parameters = window.lorisjs.candidate_parameters || {}).CandidateParameters = __webpack_exports__;
/******/ })()
;
//# sourceMappingURL=CandidateParameters.js.map