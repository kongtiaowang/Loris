window["lorisjs"] = window["lorisjs"] || {}; window["lorisjs"]["candidate_parameters"] = window["lorisjs"]["candidate_parameters"] || {}; window["lorisjs"]["candidate_parameters"]["ConsentWidget"] =
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
/******/ 	return __webpack_require__(__webpack_require__.s = 18);
/******/ })
/************************************************************************/
/******/ ({

/***/ 18:
/***/ (function(module, __webpack_exports__, __webpack_require__) {

"use strict";
__webpack_require__.r(__webpack_exports__);
/**
 * A Widget to display consent information for a candidate in
 * LORIS
 *
 * @param {array} props - The React props
 *
 * @return {object} - The rendered widget
 */
function ConsentWidget(props) {
  if (props.Consents.length == 0) {
    return null;
  }

  var consents = props.Consents.map(consentTerm);
  return /*#__PURE__*/React.createElement("table", {
    className: "table",
    style: {
      width: '100%'
    }
  }, /*#__PURE__*/React.createElement("thead", null, /*#__PURE__*/React.createElement("tr", null, /*#__PURE__*/React.createElement("th", null, "Consent Type"), /*#__PURE__*/React.createElement("th", null, "Status"), /*#__PURE__*/React.createElement("th", null, "Date"))), /*#__PURE__*/React.createElement("tbody", null, consents));
}
/**
 * Returns a rendered JSX component for a single consent type
 *
 * @param {array} consent - The type of consent
 *
 * @return {object}
 */


function consentTerm(consent) {
  var value;
  var date;

  switch (consent.Status) {
    case 'yes':
      value = 'Yes';
      date = consent.DateGiven;
      break;

    case 'no':
      if (consent.DateWithdrawn) {
        value = 'Withdrawn';
        date = consent.DateWithdrawn;
      } else {
        value = 'No';
      }

      break;

    default:
      value = consent.Status;
      return /*#__PURE__*/React.createElement("tr", {
        key: consent.ConsentID
      }, /*#__PURE__*/React.createElement("th", null, consent.Label), /*#__PURE__*/React.createElement("td", {
        colSpan: "2",
        align: "center"
      }, "-"));
  }

  return /*#__PURE__*/React.createElement("tr", {
    key: consent.ConsentID
  }, /*#__PURE__*/React.createElement("th", null, consent.Label), /*#__PURE__*/React.createElement("td", null, value), /*#__PURE__*/React.createElement("td", null, date));
}

/* harmony default export */ __webpack_exports__["default"] = (ConsentWidget);

/***/ })

/******/ });
//# sourceMappingURL=ConsentWidget.js.map