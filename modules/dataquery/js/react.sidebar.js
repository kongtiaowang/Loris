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
/***/ function(module, exports) {

	'use strict';
	
	Object.defineProperty(exports, "__esModule", {
	    value: true
	});
	var Sidebar = React.createClass({
	    displayName: 'Sidebar',
	
	    getInitialState: function getInitialState() {
	        return {
	            'hidden': false
	        };
	    },
	    toggleHidden: function toggleHidden() {
	        this.setState({ 'hidden': !this.state.hidden });
	    },
	    hide: function hide() {
	        this.setState({ 'hidden': true });
	    },
	    show: function show() {
	        this.setState({ 'hidden': false });
	    },
	    render: function render() {
	        if (this.state.hidden) {
	            return React.createElement('div', null);
	        }
	        return React.createElement(
	            'div',
	            null,
	            React.createElement(
	                'h2',
	                null,
	                this.props.Name
	            ),
	            this.props.children
	        );
	    }
	});
	var FieldsSidebar = React.createClass({
	    displayName: 'FieldsSidebar',
	
	    getDefaultProps: function getDefaultProps() {
	        return {
	            Fields: [],
	            Criteria: {}
	        };
	    },
	    render: function render() {
	        if ((!this.props.Fields || this.props.Fields.length === 0) && (!this.props.Criteria || Object.keys(this.props.Criteria).length === 0)) {
	            return React.createElement('div', null);
	        }
	
	        var fieldDiv = '';
	        var fieldList = [];
	        if (this.props.Fields) {
	            for (var i = this.props.Fields.length - 1; i >= 0; i--) {
	                var fieldInfo = this.props.Fields[i].split(",");
	                fieldList.push(React.createElement(
	                    'div',
	                    { className: 'list-group-item row', key: this.props.Fields[i] },
	                    React.createElement(
	                        'h4',
	                        { className: 'list-group-item-heading col-xs-12' },
	                        fieldInfo[0]
	                    ),
	                    React.createElement(
	                        'span',
	                        { className: 'col-xs-12' },
	                        fieldInfo[1]
	                    )
	                ));
	            }
	        }
	        return React.createElement(
	            Sidebar,
	            { Name: 'Fields' },
	            React.createElement(
	                'div',
	                { className: 'form-group' },
	                React.createElement(
	                    'button',
	                    { className: 'btn btn-primary', onClick: this.props.resetQuery },
	                    'Clear Query'
	                )
	            ),
	            fieldList
	        );
	    }
	});
	
	window.Sidebar = Sidebar;
	window.FieldsSidebar = FieldsSidebar;
	
	exports.default = {
	    Sidebar: Sidebar,
	    FieldsSidebar: FieldsSidebar
	};

/***/ }
/******/ ]);
//# sourceMappingURL=react.sidebar.js.map