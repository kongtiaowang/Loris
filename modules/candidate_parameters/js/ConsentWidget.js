/******/ (() => { // webpackBootstrap
/******/ 	"use strict";
/******/ 	// The require scope
/******/ 	var __webpack_require__ = {};
/******/ 	
/************************************************************************/
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
/*!***********************************************************!*\
  !*** ./modules/candidate_parameters/jsx/ConsentWidget.js ***!
  \***********************************************************/
__webpack_require__.r(__webpack_exports__);
/* harmony export */ __webpack_require__.d(__webpack_exports__, {
/* harmony export */   "default": () => (__WEBPACK_DEFAULT_EXPORT__)
/* harmony export */ });
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

/* harmony default export */ const __WEBPACK_DEFAULT_EXPORT__ = (ConsentWidget);
((window.lorisjs = window.lorisjs || {}).candidate_parameters = window.lorisjs.candidate_parameters || {}).ConsentWidget = __webpack_exports__;
/******/ })()
;
//# sourceMappingURL=ConsentWidget.js.map