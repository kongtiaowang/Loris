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
	//var PureRenderMixin = require('react/addons').addons.PureRenderMixin;
	
	var PaginationLinks = React.createClass({
	    displayName: 'PaginationLinks',
	
	    mixins: [React.addons.PureRenderMixin],
	    propTypes: {
	        onChangePage: React.PropTypes.func
	    },
	    getDefaultProps: function getDefaultProps() {
	        return {
	            'RowsPerPage': 10,
	            'Active': 1
	        };
	    },
	    changePage: function changePage(i) {
	        var that = this;
	        return function (evt) {
	            // Don't jump to the top of the page
	            evt.preventDefault();
	
	            if (that.props.onChangePage) {
	                that.props.onChangePage(i);
	            }
	        };
	    },
	    render: function render() {
	        var rowsPerPage = this.props.RowsPerPage;
	        var pageLinks = [];
	        var classList;
	        var lastPage = Math.ceil(this.props.total / rowsPerPage);
	        var startPage = Math.max(1, this.props.Active - 3);
	        var lastShownPage = Math.min(this.props.Active + 3, lastPage);
	
	        if (this.props.total === 0) {
	            return React.createElement('div', null);
	        }
	
	        if (lastShownPage - startPage <= 7) {
	            lastShownPage = startPage + 6;
	            if (lastShownPage > lastPage) {
	                lastShownPage = lastPage;
	                startPage = lastPage - 6;
	            }
	        }
	
	        if (startPage > 1) {
	            pageLinks.push(React.createElement(
	                'li',
	                { onClick: this.changePage(1) },
	                React.createElement(
	                    'a',
	                    { href: '#' },
	                    '\xAB'
	                )
	            ));
	        }
	        for (var i = startPage; i <= lastShownPage; i += 1) {
	            classList = '';
	            if (this.props.Active == i) {
	                classList = "active";
	            }
	            pageLinks.push(React.createElement(
	                'li',
	                { onClick: this.changePage(i), className: classList },
	                React.createElement(
	                    'a',
	                    { href: '#' },
	                    i
	                )
	            ));
	        }
	        if (lastShownPage !== lastPage) {
	            pageLinks.push(React.createElement(
	                'li',
	                { onClick: this.changePage(lastPage) },
	                React.createElement(
	                    'a',
	                    { href: '#' },
	                    '\xBB'
	                )
	            ));
	        }
	        return React.createElement(
	            'ul',
	            { className: 'pagination' },
	            pageLinks
	        );
	    }
	});
	
	window.PaginationLinks = PaginationLinks;
	window.RPaginationLinks = React.createFactory(PaginationLinks);
	
	exports.default = PaginationLinks;

/***/ }
/******/ ]);
//# sourceMappingURL=react.paginator.js.map