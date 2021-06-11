window["lorisjs"] = window["lorisjs"] || {}; window["lorisjs"]["reliability"] = window["lorisjs"]["reliability"] || {}; window["lorisjs"]["reliability"]["columnFormatter"] =
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
/* exported formatColumn */

/**
 * Modify behaviour of specified column cells in the Data Table component
 * @param {string} column - column name
 * @param {string} cell - cell content
 * @param {array} rowData - array of cell contents for a specific row
 * @param {array} rowHeaders - array of table headers (column names)
 * @return {*} a formated table cell for a given column
 */
function formatColumn(column, cell, rowData, rowHeaders) {
  // If a column if set as hidden, don't display it
  if (loris.hiddenHeaders !== undefined && loris.hiddenHeaders.indexOf(column) > -1) {
    return null;
  } // Create the mapping between rowHeaders and rowData in a row object.


  var row = {};
  rowHeaders.forEach(function (header, index) {
    row[header] = rowData[index];
  }, this);

  if (column === 'PSCID') {
    if (row['Current Stage'] === 'Recycling Bin') {
      return /*#__PURE__*/React.createElement("td", null, cell, /*#__PURE__*/React.createElement("span", {
        className: "text-danger"
      }, "(Recycling Bin)"));
    }

    if (row.Invalid === 'yes') {
      return /*#__PURE__*/React.createElement("td", null, cell, " ", /*#__PURE__*/React.createElement("span", {
        className: "text-danger"
      }, "(Invalid)"));
    }

    if (row['Manual Swap'] === 'yes') {
      return /*#__PURE__*/React.createElement("td", null, cell, " ", /*#__PURE__*/React.createElement("span", {
        className: "text-danger"
      }, "(Manual)"));
    }

    var testName = '/reliability/' + row.Instrument + '_reliability';
    var commentID = row.CommentID;
    var siteID = row.SiteID;
    var url = loris.BaseURL + testName + '?identifier=' + commentID + '&reliability_center_id=' + siteID;
    return /*#__PURE__*/React.createElement("td", null, /*#__PURE__*/React.createElement("a", {
      href: url
    }, cell));
  }

  if (column === 'Reliable') {
    var reliable = row.Reliable;

    if (reliable === 'Yes') {
      return /*#__PURE__*/React.createElement("td", {
        className: "bg-success"
      }, "Yes");
    } else if (reliable === 'No') {
      return /*#__PURE__*/React.createElement("td", {
        className: "bg-danger"
      }, "No");
    }
  }

  if (column === 'File In DB') {
    var fileInDB = row['File In DB'];

    if (fileInDB === 'No') {
      return /*#__PURE__*/React.createElement("td", {
        className: "bg-danger"
      }, "No");
    } else {
      var fileDetails = fileInDB.split(',');
      var restPath = '/temp_videos/ajax/GetFile.php?File=/videos/' + fileDetails[1] + '/' + fileDetails[2];
      var fileUrl = loris.BaseURL + restPath;
      return /*#__PURE__*/React.createElement("td", {
        className: "bg-success"
      }, /*#__PURE__*/React.createElement("a", {
        download: fileDetails[2],
        href: fileUrl
      }, fileDetails[0]));
    }
  }

  return /*#__PURE__*/React.createElement("td", null, cell);
}

window.formatColumn = formatColumn;
/* harmony default export */ __webpack_exports__["default"] = (formatColumn);

/***/ })
/******/ ]);
//# sourceMappingURL=columnFormatter.js.map