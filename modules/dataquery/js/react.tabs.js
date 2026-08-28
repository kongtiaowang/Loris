window["lorisjs"] = window["lorisjs"] || {}; window["lorisjs"]["dataquery"] = window["lorisjs"]["dataquery"] || {}; window["lorisjs"]["dataquery"]["react.tabs"] =
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
/******/ 	return __webpack_require__(__webpack_require__.s = 14);
/******/ })
/************************************************************************/
/******/ ([
/* 0 */,
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
var has = __webpack_require__(8);
var checkPropTypes = __webpack_require__(9);

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
/***/ (function(module, exports) {

module.exports = Function.call.bind(Object.prototype.hasOwnProperty);


/***/ }),
/* 9 */
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
  var has = __webpack_require__(8);

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
/* 10 */,
/* 11 */,
/* 12 */,
/* 13 */,
/* 14 */
/***/ (function(module, __webpack_exports__, __webpack_require__) {

"use strict";
__webpack_require__.r(__webpack_exports__);
/* harmony import */ var react__WEBPACK_IMPORTED_MODULE_0__ = __webpack_require__(1);
/* harmony import */ var react__WEBPACK_IMPORTED_MODULE_0___default = /*#__PURE__*/__webpack_require__.n(react__WEBPACK_IMPORTED_MODULE_0__);
/* harmony import */ var prop_types__WEBPACK_IMPORTED_MODULE_1__ = __webpack_require__(2);
/* harmony import */ var prop_types__WEBPACK_IMPORTED_MODULE_1___default = /*#__PURE__*/__webpack_require__.n(prop_types__WEBPACK_IMPORTED_MODULE_1__);
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
 *  The following file contains the components used for displaying the tab content
 *
 *  @author   Dave MacFarlane <david.macfarlane2@mcgill.ca>
 *  @author   Jordan Stirling <jstirling91@gmail.com>
 *  @license  http://www.gnu.org/licenses/gpl-3.0.txt GPLv3
 *  @link     https://github.com/mohadesz/Loris-Trunk
 */


/*
 *  The following componet is used to indicate to users that their data is currently
 *  loading
 */

var Loading = /*#__PURE__*/function (_Component) {
  _inherits(Loading, _Component);

  var _super = _createSuper(Loading);

  function Loading(props) {
    var _this;

    _classCallCheck(this, Loading);

    _this = _super.call(this, props);
    _this.state = {};
    return _this;
  }

  _createClass(Loading, [{
    key: "render",
    value: function render() {
      return /*#__PURE__*/react__WEBPACK_IMPORTED_MODULE_0___default.a.createElement("div", {
        className: "row"
      }, /*#__PURE__*/react__WEBPACK_IMPORTED_MODULE_0___default.a.createElement("h3", {
        className: "text-center loading-header"
      }, "We are currently working hard to load your data. Please be patient."), /*#__PURE__*/react__WEBPACK_IMPORTED_MODULE_0___default.a.createElement("div", {
        className: "spinner"
      }, /*#__PURE__*/react__WEBPACK_IMPORTED_MODULE_0___default.a.createElement("div", {
        className: "bounce1"
      }), /*#__PURE__*/react__WEBPACK_IMPORTED_MODULE_0___default.a.createElement("div", {
        className: "bounce2"
      }), /*#__PURE__*/react__WEBPACK_IMPORTED_MODULE_0___default.a.createElement("div", {
        className: "bounce3"
      })));
    }
  }]);

  return Loading;
}(react__WEBPACK_IMPORTED_MODULE_0__["Component"]);
/*
 *  The following component is the base component for displaying the tab's contnet
 */


var TabPane = /*#__PURE__*/function (_Component2) {
  _inherits(TabPane, _Component2);

  var _super2 = _createSuper(TabPane);

  function TabPane(props) {
    var _this2;

    _classCallCheck(this, TabPane);

    _this2 = _super2.call(this, props);
    _this2.state = {};
    return _this2;
  }

  _createClass(TabPane, [{
    key: "render",
    value: function render() {
      var classList = 'tab-pane';

      if (this.props.Active) {
        classList += ' active';
      }

      if (this.props.Loading) {
        return /*#__PURE__*/react__WEBPACK_IMPORTED_MODULE_0___default.a.createElement("div", {
          className: classList,
          id: this.props.TabId
        }, /*#__PURE__*/react__WEBPACK_IMPORTED_MODULE_0___default.a.createElement(Loading, null));
      }

      return /*#__PURE__*/react__WEBPACK_IMPORTED_MODULE_0___default.a.createElement("div", {
        key: this.props.TabId,
        className: classList,
        id: this.props.TabId
      }, /*#__PURE__*/react__WEBPACK_IMPORTED_MODULE_0___default.a.createElement("h1", null, this.props.Title), this.props.children);
    }
  }]);

  return TabPane;
}(react__WEBPACK_IMPORTED_MODULE_0__["Component"]);
/*
 *  The following component is used for displaying the info tab content
 */


var InfoTabPane = /*#__PURE__*/function (_Component3) {
  _inherits(InfoTabPane, _Component3);

  var _super3 = _createSuper(InfoTabPane);

  function InfoTabPane(props) {
    var _this3;

    _classCallCheck(this, InfoTabPane);

    _this3 = _super3.call(this, props);
    _this3.state = {};
    return _this3;
  }

  _createClass(InfoTabPane, [{
    key: "render",
    value: function render() {
      return /*#__PURE__*/react__WEBPACK_IMPORTED_MODULE_0___default.a.createElement(TabPane, {
        Title: "Welcome to the Data Query Tool",
        TabId: this.props.TabId,
        Active: this.props.Active,
        Loading: this.props.Loading
      }, /*#__PURE__*/react__WEBPACK_IMPORTED_MODULE_0___default.a.createElement("p", null, "Data was last updated on ", this.props.UpdatedTime, "."), /*#__PURE__*/react__WEBPACK_IMPORTED_MODULE_0___default.a.createElement("p", null, "Please define or use your query by using the following tabs."), /*#__PURE__*/react__WEBPACK_IMPORTED_MODULE_0___default.a.createElement("dl", null, /*#__PURE__*/react__WEBPACK_IMPORTED_MODULE_0___default.a.createElement("dt", null, "Define Fields"), /*#__PURE__*/react__WEBPACK_IMPORTED_MODULE_0___default.a.createElement("dd", null, "Define the fields to be added to your query here."), /*#__PURE__*/react__WEBPACK_IMPORTED_MODULE_0___default.a.createElement("dt", null, "Define Filters"), /*#__PURE__*/react__WEBPACK_IMPORTED_MODULE_0___default.a.createElement("dd", null, "Define the criteria to filter the data for your query here."), /*#__PURE__*/react__WEBPACK_IMPORTED_MODULE_0___default.a.createElement("dt", null, "View Data"), /*#__PURE__*/react__WEBPACK_IMPORTED_MODULE_0___default.a.createElement("dd", null, "See the results of your query."), /*#__PURE__*/react__WEBPACK_IMPORTED_MODULE_0___default.a.createElement("dt", null, "Statistical Analysis"), /*#__PURE__*/react__WEBPACK_IMPORTED_MODULE_0___default.a.createElement("dd", null, "Visualize or see basic statistical measures from your query here."), /*#__PURE__*/react__WEBPACK_IMPORTED_MODULE_0___default.a.createElement("dt", null, "Load Saved Query"), /*#__PURE__*/react__WEBPACK_IMPORTED_MODULE_0___default.a.createElement("dd", null, "Load a previously saved query (by name) by selecting from this menu."), /*#__PURE__*/react__WEBPACK_IMPORTED_MODULE_0___default.a.createElement("dt", null, "Manage Saved Queries"), /*#__PURE__*/react__WEBPACK_IMPORTED_MODULE_0___default.a.createElement("dd", null, "Either save your current query or see the criteria of previously saved quer ies here.")));
    }
  }]);

  return InfoTabPane;
}(react__WEBPACK_IMPORTED_MODULE_0__["Component"]);
/*
 *  The following component is used for displaying the field select tab content
 */


var FieldSelectTabPane = /*#__PURE__*/function (_Component4) {
  _inherits(FieldSelectTabPane, _Component4);

  var _super4 = _createSuper(FieldSelectTabPane);

  function FieldSelectTabPane(props) {
    var _this4;

    _classCallCheck(this, FieldSelectTabPane);

    _this4 = _super4.call(this, props);
    _this4.state = {};
    return _this4;
  }

  _createClass(FieldSelectTabPane, [{
    key: "render",
    value: function render() {
      return /*#__PURE__*/react__WEBPACK_IMPORTED_MODULE_0___default.a.createElement(TabPane, {
        TabId: this.props.TabId,
        Loading: this.props.Loading,
        Active: this.props.Active
      }, /*#__PURE__*/react__WEBPACK_IMPORTED_MODULE_0___default.a.createElement(FieldSelector, {
        title: "Fields",
        items: this.props.categories,
        onFieldChange: this.props.onFieldChange,
        selectedFields: this.props.selectedFields,
        Visits: this.props.Visits,
        fieldVisitSelect: this.props.fieldVisitSelect
      }));
    }
  }]);

  return FieldSelectTabPane;
}(react__WEBPACK_IMPORTED_MODULE_0__["Component"]);
/*
 *  The following component is used for displaying the filter builder tab content
 */


var FilterSelectTabPane = /*#__PURE__*/function (_Component5) {
  _inherits(FilterSelectTabPane, _Component5);

  var _super5 = _createSuper(FilterSelectTabPane);

  function FilterSelectTabPane(props) {
    var _this5;

    _classCallCheck(this, FilterSelectTabPane);

    _this5 = _super5.call(this, props);
    _this5.state = {};
    return _this5;
  }

  _createClass(FilterSelectTabPane, [{
    key: "render",
    value: function render() {
      return /*#__PURE__*/react__WEBPACK_IMPORTED_MODULE_0___default.a.createElement(TabPane, {
        TabId: this.props.TabId,
        Loading: this.props.Loading
      }, /*#__PURE__*/react__WEBPACK_IMPORTED_MODULE_0___default.a.createElement(FilterBuilder, {
        items: this.props.categories,
        updateFilter: this.props.updateFilter,
        filter: this.props.filter,
        Visits: this.props.Visits,
        Active: this.props.Active
      }));
    }
  }]);

  return FilterSelectTabPane;
}(react__WEBPACK_IMPORTED_MODULE_0__["Component"]);
/*
 *  The following component is used for displaying the view data tab content
 */


var ViewDataTabPane = /*#__PURE__*/function (_Component6) {
  _inherits(ViewDataTabPane, _Component6);

  var _super6 = _createSuper(ViewDataTabPane);

  function ViewDataTabPane(props) {
    var _this6;

    _classCallCheck(this, ViewDataTabPane);

    _this6 = _super6.call(this, props);
    _this6.state = {
      sessions: []
    };
    _this6.runQuery = _this6.runQuery.bind(_assertThisInitialized(_this6));
    _this6.changeDataDisplay = _this6.changeDataDisplay.bind(_assertThisInitialized(_this6));
    _this6.getOrCreateProgressElement = _this6.getOrCreateProgressElement.bind(_assertThisInitialized(_this6));
    _this6.getOrCreateDownloadLink = _this6.getOrCreateDownloadLink.bind(_assertThisInitialized(_this6));
    _this6.downloadData = _this6.downloadData.bind(_assertThisInitialized(_this6));
    return _this6;
  }

  _createClass(ViewDataTabPane, [{
    key: "runQuery",
    value: function runQuery() {
      this.props.runQuery(this.props.Fields, this.props.Sessions);
    }
  }, {
    key: "changeDataDisplay",
    value: function changeDataDisplay(displayID) {
      // Wrapper function to change the data display type
      this.props.changeDataDisplay(displayID);
    }
  }, {
    key: "getOrCreateProgressElement",
    value: function getOrCreateProgressElement(id) {
      // Helper function to display the progress of downloading the downloadable
      // fields into a ZIP folder
      var element = document.getElementById(id),
          progress;

      if (element) {
        return element;
      }

      progress = document.getElementById('progress');
      element = document.createElement('div');
      element.setAttribute('id', id);
      progress.appendChild(element);
      return element;
    }
  }, {
    key: "getOrCreateDownloadLink",
    value: function getOrCreateDownloadLink(fileName, type) {
      // Helper function to create and click a downloadable link to download the
      // downloadable fields into a ZIP folder
      var element = document.getElementById('DownloadLink' + fileName),
          parentEl,
          el2;

      if (element) {
        return element;
      }

      parentEl = document.getElementById('downloadlinksUL');
      element = document.createElement('a');
      element.download = fileName;
      element.type = type;
      element.textContent = 'Zip file: ' + fileName;
      element.setAttribute('id', 'DownloadLink' + fileName);
      el2 = document.createElement('li');
      el2.appendChild(element);
      parentEl.appendChild(el2);
      return element;
    }
  }, {
    key: "downloadData",
    value: function downloadData() {
      var _this7 = this;

      // Download the downloadable fields into a ZIP folder
      // Makes use of a web worker to format and download the data
      var zip = new JSZip(),
          i = 0,
          FileList = this.props.FileData,
          CompleteMask = new Array(FileList.length),
          saveworker,
          dataURLs = [],
          multiLinkHandler = function multiLinkHandler(buffer) {
        return function (ce) {
          var downloadLink = document.getElementById('DownloadLink'),
              dv = new DataView(buffer),
              blb;
          ce.preventDefault();
          blb = new Blob([dv], {
            type: 'application/zip'
          });
          downloadLink.href = window.URL.createObjectURL(blb);
          downloadLink.download = _this7.download;
          downloadLink.type = 'application/zip';
          downloadLink.click();
          window.URL.revokeObjectURL(downloadLink.href);
        };
      }; // Does this work if we hold a global reference instead of a closure
      // to the object URL?


      window.dataBlobs = [];

      if (FileList.length < 100 || confirm('You are trying to download more than 100 files. This may be slow or crash your web browser.\n\nYou may want to consider splitting your query into more, smaller queries by defining more restrictive filters.\n\nPress OK to continue with attempting to download current files or cancel to abort.')) {
        saveworker = new Worker(loris.BaseURL + '/dataquery/js/workers/savezip.js');
        saveworker.addEventListener('message', function (e) {
          var link, progress, FileName, NewFileName, downloadLinks, i;

          if (e.data.cmd === 'SaveFile') {
            progress = _this7.getOrCreateProgressElement('download_progress'); //progress.textContent = "Downloaded files";
            //hold a reference to the blob so that chrome doesn't release it. This shouldn't
            //be required.

            window.dataBlobs[e.data.FileNo - 1] = new Blob([e.data.buffer], {
              type: 'application/zip'
            });
            ;
            dataURLs[e.data.FileNo - 1] = window.URL.createObjectURL(window.dataBlobs[e.data.FileNo - 1]);
            link = _this7.getOrCreateDownloadLink(e.data.Filename, 'application/zip');
            link.href = dataURLs[e.data.FileNo - 1]; //link.onclick = multiLinkHandler(e.data.buffer);
            //link.href = "#";

            progress = _this7.getOrCreateProgressElement('zip_progress');
            progress.textContent = '';
          } else if (e.data.cmd === 'Progress') {
            progress = _this7.getOrCreateProgressElement('download_progress');
            progress.innerHTML = 'Downloading files: <progress value="' + e.data.Complete + '" max="' + e.data.Total + '">' + e.data.Complete + ' out of ' + e.data.Total + '</progress>';
          } else if (e.data.cmd === 'Finished') {
            if (dataURLs.length === 1) {
              $('#downloadlinksUL li a')[0].click();
            }

            if (dataURLs.length > 1) {
              progress = document.getElementById('downloadlinks');
              progress.style.display = 'initial';
              downloadLinks = $('#downloadlinksUL li a');

              for (i = 0; i < dataURLs.length; i += 1) {
                FileName = downloadLinks[i].id.slice('DownloadLinkFiles-'.length, -4);
                NewFileName = 'files-' + FileName + 'of' + e.data.NumFiles + '.zip';
                downloadLinks[i].download = NewFileName;
                downloadLinks[i].href = dataURLs[i];
                downloadLinks[i].textContent = 'Zip file: ' + NewFileName;
              }
            }

            progress = _this7.getOrCreateProgressElement('download_progress');
            progress.textContent = 'Finished generating zip files'; //this.terminate();
          } else if (e.data.cmd === 'CreatingZip') {
            progress = _this7.getOrCreateProgressElement('zip_progress');
            progress.textContent = 'Creating a zip file with current batch of downloaded files. Process may be slow before proceeding.';
          }
        });
        saveworker.postMessage({
          Files: FileList,
          BaseURL: loris.BaseURL
        });
      }
    }
  }, {
    key: "render",
    value: function render() {
      var downloadData;
      var buttons = /*#__PURE__*/react__WEBPACK_IMPORTED_MODULE_0___default.a.createElement("div", {
        className: "row"
      }, /*#__PURE__*/react__WEBPACK_IMPORTED_MODULE_0___default.a.createElement("div", {
        className: "commands col-xs-12 form-group"
      }, /*#__PURE__*/react__WEBPACK_IMPORTED_MODULE_0___default.a.createElement("button", {
        className: "btn btn-primary",
        onClick: this.runQuery
      }, "Run Query"), /*#__PURE__*/react__WEBPACK_IMPORTED_MODULE_0___default.a.createElement("button", {
        className: "btn btn-primary",
        onClick: this.downloadData
      }, "Download Data as ZIP")), /*#__PURE__*/react__WEBPACK_IMPORTED_MODULE_0___default.a.createElement("div", {
        id: "progress",
        className: "col-xs-12"
      }), /*#__PURE__*/react__WEBPACK_IMPORTED_MODULE_0___default.a.createElement("div", {
        id: "downloadlinks",
        className: "col-xs-12"
      }, /*#__PURE__*/react__WEBPACK_IMPORTED_MODULE_0___default.a.createElement("ul", {
        id: "downloadlinksUL"
      })));
      var criteria = [];

      for (var el in this.props.Criteria) {
        if (!this.props.Criteria.hasOwnProperty(el)) {
          continue;
        }

        var item = this.props.Criteria[el];

        if (item === undefined) {
          criteria.push( /*#__PURE__*/react__WEBPACK_IMPORTED_MODULE_0___default.a.createElement("div", {
            className: "alert alert-warning",
            role: "alert"
          }, el, " has been added as a filter but not had criteria defined."));
        } else {
          criteria.push( /*#__PURE__*/react__WEBPACK_IMPORTED_MODULE_0___default.a.createElement("div", {
            className: "row"
          }, /*#__PURE__*/react__WEBPACK_IMPORTED_MODULE_0___default.a.createElement("span", {
            className: "col-sm-3"
          }, el), /*#__PURE__*/react__WEBPACK_IMPORTED_MODULE_0___default.a.createElement("span", {
            className: "col-sm-3"
          }, item.operator), /*#__PURE__*/react__WEBPACK_IMPORTED_MODULE_0___default.a.createElement("span", {
            className: "col-sm-3"
          }, item.value)));
        }
      }

      return /*#__PURE__*/react__WEBPACK_IMPORTED_MODULE_0___default.a.createElement(TabPane, {
        TabId: this.props.TabId,
        Loading: this.props.Loading,
        Active: this.props.Active
      }, /*#__PURE__*/react__WEBPACK_IMPORTED_MODULE_0___default.a.createElement("h2", null, "Query Criteria"), criteria, buttons, /*#__PURE__*/react__WEBPACK_IMPORTED_MODULE_0___default.a.createElement("div", {
        className: "form-group form-horizontal row"
      }, /*#__PURE__*/react__WEBPACK_IMPORTED_MODULE_0___default.a.createElement("label", {
        htmlFor: "selected-input",
        className: "col-sm-1 control-label"
      }, "Data"), /*#__PURE__*/react__WEBPACK_IMPORTED_MODULE_0___default.a.createElement("div", {
        className: "col-sm-4"
      }, /*#__PURE__*/react__WEBPACK_IMPORTED_MODULE_0___default.a.createElement("div", {
        className: "btn-group"
      }, /*#__PURE__*/react__WEBPACK_IMPORTED_MODULE_0___default.a.createElement("button", {
        id: "selected-input",
        type: "button",
        className: "btn btn-default dropdown-toggle",
        "data-toggle": "dropdown"
      }, /*#__PURE__*/react__WEBPACK_IMPORTED_MODULE_0___default.a.createElement("span", {
        id: "search_concept"
      }, this.props.displayType), /*#__PURE__*/react__WEBPACK_IMPORTED_MODULE_0___default.a.createElement("span", {
        className: "caret"
      })), /*#__PURE__*/react__WEBPACK_IMPORTED_MODULE_0___default.a.createElement("ul", {
        className: "dropdown-menu",
        role: "menu"
      }, /*#__PURE__*/react__WEBPACK_IMPORTED_MODULE_0___default.a.createElement("li", {
        onClick: this.changeDataDisplay.bind(this, 0)
      }, /*#__PURE__*/react__WEBPACK_IMPORTED_MODULE_0___default.a.createElement("div", {
        className: "col-sm-12"
      }, /*#__PURE__*/react__WEBPACK_IMPORTED_MODULE_0___default.a.createElement("h5", {
        className: ""
      }, "Cross-sectional"))), /*#__PURE__*/react__WEBPACK_IMPORTED_MODULE_0___default.a.createElement("li", {
        onClick: this.changeDataDisplay.bind(this, 1)
      }, /*#__PURE__*/react__WEBPACK_IMPORTED_MODULE_0___default.a.createElement("div", {
        className: "col-sm-12"
      }, /*#__PURE__*/react__WEBPACK_IMPORTED_MODULE_0___default.a.createElement("h5", {
        className: ""
      }, "Longitudinal"))))))), /*#__PURE__*/react__WEBPACK_IMPORTED_MODULE_0___default.a.createElement(StaticDataTable, {
        Headers: this.props.RowHeaders,
        RowNumLabel: "Identifiers",
        Data: this.props.Data,
        RowNameMap: this.props.RowInfo
      }));
    }
  }]);

  return ViewDataTabPane;
}(react__WEBPACK_IMPORTED_MODULE_0__["Component"]);

ViewDataTabPane.propTypes = {
  runQuery: prop_types__WEBPACK_IMPORTED_MODULE_1___default.a.func.isRequired
};
/*
 *  The following component is used for displaying the scatterplot graph
 *  in the stats tab using flot. The following code is a modification of
 *  code used in the couchApp implementation of the DQT
 */

var ScatterplotGraph = /*#__PURE__*/function (_Component7) {
  _inherits(ScatterplotGraph, _Component7);

  var _super7 = _createSuper(ScatterplotGraph);

  function ScatterplotGraph(props) {
    var _this8;

    _classCallCheck(this, ScatterplotGraph);

    _this8 = _super7.call(this, props);
    _this8.state = {};
    _this8.lsFit = _this8.lsFit.bind(_assertThisInitialized(_this8));
    _this8.minmaxx = _this8.minmaxx.bind(_assertThisInitialized(_this8));
    _this8.updateScatterplot = _this8.updateScatterplot.bind(_assertThisInitialized(_this8));
    return _this8;
  }

  _createClass(ScatterplotGraph, [{
    key: "lsFit",
    value: function lsFit(data) {
      var i = 0,
          means = jStat(data).mean(),
          xmean = means[0],
          ymean = means[1],
          interim = 0,
          numerator = 0,
          denominator = 0,
          slope,
          xi,
          yi;

      for (i = 0; i < data.length; i += 1) {
        xi = data[i][0];
        yi = data[i][1];
        numerator += (xi - xmean) * (yi - ymean);
        denominator += (xi - xmean) * (xi - xmean);
      }

      slope = numerator / denominator;
      return [ymean - slope * xmean, slope];
    }
  }, {
    key: "minmaxx",
    value: function minmaxx(arr) {
      var i, min, max;

      for (i = 0; i < arr.length; i += 1) {
        if (arr[i][0] < min || min === undefined) {
          if (arr[i][0] !== undefined && arr[i][0] !== null) {
            min = arr[i][0];
          }
        }

        if (arr[i][0] > max || max === undefined) {
          if (arr[i][0] !== undefined && arr[i][0] !== null) {
            max = arr[i][0];
          }
        }
      }

      return [min, max];
    }
  }, {
    key: "updateScatterplot",
    value: function updateScatterplot() {
      var xaxis = document.getElementById('scatter-xaxis').value,
          yaxis = document.getElementById('scatter-yaxis').value,
          grouping = document.getElementById('scatter-group').value,
          data = this.props.Data,
          points = [],
          min,
          max,
          field1 = [],
          field2 = [],
          grouped_points = {},
          i = 0,
          group_label,
          minmax,
          LS,
          slope,
          start,
          plots = [],
          label,
          plotY = function plotY(x) {
        return [x, start + slope * x];
      },
          dataset;

      for (i = 0; i < data.length; i += 1) {
        points.push([data[i][xaxis], data[i][yaxis]]);
        field1.push(data[i][xaxis]);
        field2.push(data[i][yaxis]);

        if (grouping) {
          group_label = data[i][grouping];

          if (!(grouped_points[group_label] instanceof Array)) {
            grouped_points[group_label] = [];
          }

          grouped_points[group_label].push([data[i][xaxis], data[i][yaxis]]);
        }
      }

      if (grouping === 'ungrouped') {
        minmax = this.minmaxx(points);
        min = minmax[0];
        max = minmax[1];
        LS = this.lsFit(points);
        slope = LS[1];
        start = LS[0];
        $.plot('#scatterplotdiv', [{
          label: 'Data Points',
          data: points,
          points: {
            show: true
          }
        }, // Least Squares Fit
        {
          label: 'Least Squares Fit',
          data: jStat.seq(min, max, 3, plotY),
          lines: {
            show: true
          }
        }], {});
      } else {
        minmax = this.minmaxx(points);
        min = minmax[0];
        max = minmax[1];
        i = 0;

        for (dataset in grouped_points) {
          if (grouped_points.hasOwnProperty(dataset)) {
            label = document.getElementById("scatter-group").selectedOptions.item(0).textContent + " = " + dataset;
            plots.push({
              color: i,
              label: dataset,
              data: grouped_points[dataset],
              points: {
                show: true
              }
            });
            LS = this.lsFit(grouped_points[dataset]); //LS = lsFit(grouped_points[dataset].convertNumbers());

            slope = LS[1];
            start = LS[0];
            plots.push({
              color: i,
              // label: "LS Fit for " + dataset,
              data: jStat.seq(min, max, 3, plotY),
              lines: {
                show: true
              }
            });
            i += 1;
          }
        }

        $.plot('#scatterplotdiv', plots, {});
      }

      $('#correlationtbl tbody').children().remove();
      $('#correlationtbl tbody').append('<tr><td>' + jStat.covariance(field1, field2) + '</td><td>' + jStat.corrcoeff(field1, field2) + '</td></tr>');
    }
  }, {
    key: "render",
    value: function render() {
      var options = this.props.Fields.map(function (element, key) {
        console.log(element);
        return /*#__PURE__*/react__WEBPACK_IMPORTED_MODULE_0___default.a.createElement("option", {
          value: key
        }, element);
      }),
          scatterStyle = {
        width: '500px',
        height: '500px'
      };
      return /*#__PURE__*/react__WEBPACK_IMPORTED_MODULE_0___default.a.createElement("div", null, /*#__PURE__*/react__WEBPACK_IMPORTED_MODULE_0___default.a.createElement("h2", null, "Scatterplot"), /*#__PURE__*/react__WEBPACK_IMPORTED_MODULE_0___default.a.createElement("div", {
        className: "col-xs-4 col-md-3"
      }, "Column for X Axis"), /*#__PURE__*/react__WEBPACK_IMPORTED_MODULE_0___default.a.createElement("div", {
        className: "col-xs-8 col-md-3"
      }, /*#__PURE__*/react__WEBPACK_IMPORTED_MODULE_0___default.a.createElement("select", {
        id: "scatter-xaxis",
        onChange: this.updateScatterplot
      }, /*#__PURE__*/react__WEBPACK_IMPORTED_MODULE_0___default.a.createElement("option", null, "None"), options)), /*#__PURE__*/react__WEBPACK_IMPORTED_MODULE_0___default.a.createElement("div", {
        className: "col-xs-4 col-md-3"
      }, "Column for Y Axis"), /*#__PURE__*/react__WEBPACK_IMPORTED_MODULE_0___default.a.createElement("div", {
        className: "col-xs-8 col-md-3"
      }, /*#__PURE__*/react__WEBPACK_IMPORTED_MODULE_0___default.a.createElement("select", {
        id: "scatter-yaxis",
        onChange: this.updateScatterplot
      }, /*#__PURE__*/react__WEBPACK_IMPORTED_MODULE_0___default.a.createElement("option", null, "None"), options)), /*#__PURE__*/react__WEBPACK_IMPORTED_MODULE_0___default.a.createElement("div", {
        className: "col-xs-4 col-md-3"
      }, "Group by column"), /*#__PURE__*/react__WEBPACK_IMPORTED_MODULE_0___default.a.createElement("div", {
        className: "col-xs-8 col-md-3"
      }, /*#__PURE__*/react__WEBPACK_IMPORTED_MODULE_0___default.a.createElement("select", {
        id: "scatter-group",
        onChange: this.updateScatterplot
      }, /*#__PURE__*/react__WEBPACK_IMPORTED_MODULE_0___default.a.createElement("option", null, "None"), options)), /*#__PURE__*/react__WEBPACK_IMPORTED_MODULE_0___default.a.createElement("h3", null, "Scatterplot"), /*#__PURE__*/react__WEBPACK_IMPORTED_MODULE_0___default.a.createElement("div", {
        id: "scatterplotdiv",
        style: scatterStyle
      }), /*#__PURE__*/react__WEBPACK_IMPORTED_MODULE_0___default.a.createElement("h3", null, "Statistics"), /*#__PURE__*/react__WEBPACK_IMPORTED_MODULE_0___default.a.createElement("table", {
        id: "correlationtbl"
      }, /*#__PURE__*/react__WEBPACK_IMPORTED_MODULE_0___default.a.createElement("thead", null, /*#__PURE__*/react__WEBPACK_IMPORTED_MODULE_0___default.a.createElement("tr", null, /*#__PURE__*/react__WEBPACK_IMPORTED_MODULE_0___default.a.createElement("th", null, "Covariance"), /*#__PURE__*/react__WEBPACK_IMPORTED_MODULE_0___default.a.createElement("th", null, "Correlation Coefficient"))), /*#__PURE__*/react__WEBPACK_IMPORTED_MODULE_0___default.a.createElement("tbody", null)));
    }
  }]);

  return ScatterplotGraph;
}(react__WEBPACK_IMPORTED_MODULE_0__["Component"]);
/*
 *  The following component is used for displaying the stats tab content
 */


var StatsVisualizationTabPane = /*#__PURE__*/function (_Component8) {
  _inherits(StatsVisualizationTabPane, _Component8);

  var _super8 = _createSuper(StatsVisualizationTabPane);

  function StatsVisualizationTabPane(props) {
    var _this9;

    _classCallCheck(this, StatsVisualizationTabPane);

    _this9 = _super8.call(this, props);
    _this9.state = {
      displayed: false
    };
    return _this9;
  }

  _createClass(StatsVisualizationTabPane, [{
    key: "render",
    value: function render() {
      var content = /*#__PURE__*/react__WEBPACK_IMPORTED_MODULE_0___default.a.createElement("div", null, "Statistics not yet calculated."); // if(this.state.displayed === false) {
      //     var content = <div>Statistics not yet calculated.</div>;
      //     // return <TabPane content={content} TabId={this.props.TabId} />;
      // } else

      if (this.props.Data.length === 0) {
        var _content = /*#__PURE__*/react__WEBPACK_IMPORTED_MODULE_0___default.a.createElement("div", null, "Could not calculate stats, query not run"); // return <TabPane content={content} TabId={this.props.TabId} />;

      } else {
        var stats = jStat(this.props.Data),
            min = stats.min(),
            max = stats.max(),
            stddev = stats.stdev(),
            mean = stats.mean(),
            meandev = stats.meandev(),
            meansqerr = stats.meansqerr(),
            quartiles = stats.quartiles(),
            rows = [];

        for (var i = 0; i < this.props.Fields.length; i += 1) {
          rows.push( /*#__PURE__*/react__WEBPACK_IMPORTED_MODULE_0___default.a.createElement("tr", {
            key: 'fields_' + i
          }, /*#__PURE__*/react__WEBPACK_IMPORTED_MODULE_0___default.a.createElement("td", null, this.props.Fields[i]), /*#__PURE__*/react__WEBPACK_IMPORTED_MODULE_0___default.a.createElement("td", null, min && min[i] ? min[i].toString() : ''), /*#__PURE__*/react__WEBPACK_IMPORTED_MODULE_0___default.a.createElement("td", null, max && max[i] ? max[i].toString() : ''), /*#__PURE__*/react__WEBPACK_IMPORTED_MODULE_0___default.a.createElement("td", null, stddev && stddev[i] ? stddev[i].toString() : ''), /*#__PURE__*/react__WEBPACK_IMPORTED_MODULE_0___default.a.createElement("td", null, mean && mean[i] ? mean[i].toString() : ''), /*#__PURE__*/react__WEBPACK_IMPORTED_MODULE_0___default.a.createElement("td", null, meandev && meandev[i] ? meandev[i].toString() : ''), /*#__PURE__*/react__WEBPACK_IMPORTED_MODULE_0___default.a.createElement("td", null, meansqerr && meansqerr[i] ? meansqerr[i].toString() : ''), /*#__PURE__*/react__WEBPACK_IMPORTED_MODULE_0___default.a.createElement("td", null, quartiles && quartiles[i] && quartiles[i][0] ? quartiles[i][0].toString() : ''), /*#__PURE__*/react__WEBPACK_IMPORTED_MODULE_0___default.a.createElement("td", null, quartiles && quartiles[i] && quartiles[i][1] ? quartiles[i][1].toString() : ''), /*#__PURE__*/react__WEBPACK_IMPORTED_MODULE_0___default.a.createElement("td", null, quartiles && quartiles[i] && quartiles[i][2] ? quartiles[i][2].toString() : '')));
        }

        var statsTable = /*#__PURE__*/react__WEBPACK_IMPORTED_MODULE_0___default.a.createElement("table", {
          className: "table table-hover table-primary table-bordered colm-freeze"
        }, /*#__PURE__*/react__WEBPACK_IMPORTED_MODULE_0___default.a.createElement("thead", null, /*#__PURE__*/react__WEBPACK_IMPORTED_MODULE_0___default.a.createElement("tr", {
          className: "info"
        }, /*#__PURE__*/react__WEBPACK_IMPORTED_MODULE_0___default.a.createElement("th", null, "Measure"), /*#__PURE__*/react__WEBPACK_IMPORTED_MODULE_0___default.a.createElement("th", null, "Min"), /*#__PURE__*/react__WEBPACK_IMPORTED_MODULE_0___default.a.createElement("th", null, "Max"), /*#__PURE__*/react__WEBPACK_IMPORTED_MODULE_0___default.a.createElement("th", null, "Standard Deviation"), /*#__PURE__*/react__WEBPACK_IMPORTED_MODULE_0___default.a.createElement("th", null, "Mean"), /*#__PURE__*/react__WEBPACK_IMPORTED_MODULE_0___default.a.createElement("th", null, "Mean Deviation"), /*#__PURE__*/react__WEBPACK_IMPORTED_MODULE_0___default.a.createElement("th", null, "Mean Squared Error"), /*#__PURE__*/react__WEBPACK_IMPORTED_MODULE_0___default.a.createElement("th", null, "First Quartile"), /*#__PURE__*/react__WEBPACK_IMPORTED_MODULE_0___default.a.createElement("th", null, "Second Quartile"), /*#__PURE__*/react__WEBPACK_IMPORTED_MODULE_0___default.a.createElement("th", null, "Third Quartile"))), /*#__PURE__*/react__WEBPACK_IMPORTED_MODULE_0___default.a.createElement("tbody", null, rows));
        content = /*#__PURE__*/react__WEBPACK_IMPORTED_MODULE_0___default.a.createElement("div", null, /*#__PURE__*/react__WEBPACK_IMPORTED_MODULE_0___default.a.createElement("h2", null, "Basic Statistics"), statsTable, /*#__PURE__*/react__WEBPACK_IMPORTED_MODULE_0___default.a.createElement(ScatterplotGraph, {
          Fields: this.props.Fields,
          Data: this.props.Data
        }));
      }

      return /*#__PURE__*/react__WEBPACK_IMPORTED_MODULE_0___default.a.createElement(TabPane, {
        TabId: this.props.TabId,
        Loading: this.props.Loading,
        Active: this.props.Active
      }, content);
    }
  }]);

  return StatsVisualizationTabPane;
}(react__WEBPACK_IMPORTED_MODULE_0__["Component"]);

StatsVisualizationTabPane.propTypes = {
  Data: prop_types__WEBPACK_IMPORTED_MODULE_1___default.a.array
};
StatsVisualizationTabPane.defaultProps = {
  Data: []
};
/*
 *  The following component is used for displaying a popout dialog for saving the current
 *  query
 */

var SaveQueryDialog = /*#__PURE__*/function (_Component9) {
  _inherits(SaveQueryDialog, _Component9);

  var _super9 = _createSuper(SaveQueryDialog);

  function SaveQueryDialog(props) {
    var _this10;

    _classCallCheck(this, SaveQueryDialog);

    _this10 = _super9.call(this, props);
    _this10.state = {
      queryName: '',
      shared: false
    };
    _this10.editName = _this10.editName.bind(_assertThisInitialized(_this10));
    _this10.editPublic = _this10.editPublic.bind(_assertThisInitialized(_this10));
    _this10.onSaveClicked = _this10.onSaveClicked.bind(_assertThisInitialized(_this10));
    _this10.onDismissClicked = _this10.onDismissClicked.bind(_assertThisInitialized(_this10));
    return _this10;
  }

  _createClass(SaveQueryDialog, [{
    key: "editName",
    value: function editName(e) {
      this.setState({
        queryName: e.target.value
      });
    }
  }, {
    key: "editPublic",
    value: function editPublic(e) {
      this.setState({
        shared: e.target.checked
      });
    }
  }, {
    key: "onSaveClicked",
    value: function onSaveClicked() {
      // Should do validation before doing anything here.. ie query name is entered, doesn't already
      // exist, there are fields selected..
      if (this.props.onSaveClicked) {
        this.props.onSaveClicked(this.state.queryName, this.state.shared);
      }
    }
  }, {
    key: "onDismissClicked",
    value: function onDismissClicked() {
      if (this.props.onDismissClicked) {
        this.props.onDismissClicked();
      }
    }
  }, {
    key: "render",
    value: function render() {
      return /*#__PURE__*/react__WEBPACK_IMPORTED_MODULE_0___default.a.createElement("div", {
        className: "modal show"
      }, /*#__PURE__*/react__WEBPACK_IMPORTED_MODULE_0___default.a.createElement("div", {
        className: "modal-dialog"
      }, /*#__PURE__*/react__WEBPACK_IMPORTED_MODULE_0___default.a.createElement("div", {
        className: "modal-content"
      }, /*#__PURE__*/react__WEBPACK_IMPORTED_MODULE_0___default.a.createElement("div", {
        className: "modal-header"
      }, /*#__PURE__*/react__WEBPACK_IMPORTED_MODULE_0___default.a.createElement("button", {
        type: "button",
        className: "close",
        "aria-label": "Close",
        onClick: this.onDismissClicked
      }, /*#__PURE__*/react__WEBPACK_IMPORTED_MODULE_0___default.a.createElement("span", {
        "aria-hidden": "true"
      }, "\xD7")), /*#__PURE__*/react__WEBPACK_IMPORTED_MODULE_0___default.a.createElement("h4", {
        className: "modal-title",
        id: "myModalLabel"
      }, "Save Current Query")), /*#__PURE__*/react__WEBPACK_IMPORTED_MODULE_0___default.a.createElement("div", {
        className: "modal-body"
      }, /*#__PURE__*/react__WEBPACK_IMPORTED_MODULE_0___default.a.createElement("p", null, "Enter the name you would like to save your query under here:"), /*#__PURE__*/react__WEBPACK_IMPORTED_MODULE_0___default.a.createElement("div", {
        className: "input-group"
      }, "Query Name: ", /*#__PURE__*/react__WEBPACK_IMPORTED_MODULE_0___default.a.createElement("input", {
        type: "text",
        className: "form-control",
        placeholder: "My Query",
        value: this.state.queryName,
        onChange: this.editName
      })), /*#__PURE__*/react__WEBPACK_IMPORTED_MODULE_0___default.a.createElement("p", null, "Make query a publicly shared query? ", /*#__PURE__*/react__WEBPACK_IMPORTED_MODULE_0___default.a.createElement("input", {
        type: "checkbox",
        checked: this.state.shared ? 'checked' : '',
        onChange: this.editPublic,
        "aria-label": "Shared Query"
      }))), /*#__PURE__*/react__WEBPACK_IMPORTED_MODULE_0___default.a.createElement("div", {
        className: "modal-footer"
      }, /*#__PURE__*/react__WEBPACK_IMPORTED_MODULE_0___default.a.createElement("button", {
        type: "button",
        className: "btn btn-default",
        onClick: this.onDismissClicked
      }, "Close"), /*#__PURE__*/react__WEBPACK_IMPORTED_MODULE_0___default.a.createElement("button", {
        type: "button",
        className: "btn btn-primary",
        onClick: this.onSaveClicked
      }, "Save changes")))));
    }
  }]);

  return SaveQueryDialog;
}(react__WEBPACK_IMPORTED_MODULE_0__["Component"]);
/*
 *  The following component is used for displaying the filter of a individual query in a tree
 *  like structure
 */


var ManageSavedQueryFilter = /*#__PURE__*/function (_Component10) {
  _inherits(ManageSavedQueryFilter, _Component10);

  var _super10 = _createSuper(ManageSavedQueryFilter);

  function ManageSavedQueryFilter(props) {
    var _this11;

    _classCallCheck(this, ManageSavedQueryFilter);

    _this11 = _super10.call(this, props);
    _this11.state = {};
    return _this11;
  }

  _createClass(ManageSavedQueryFilter, [{
    key: "render",
    value: function render() {
      var filterItem,
          filter = this.props.filterItem;

      if (filter.activeOperator) {
        var logicOp = 'AND',
            children = filter.children.map(function (element, key) {
          return /*#__PURE__*/react__WEBPACK_IMPORTED_MODULE_0___default.a.createElement(ManageSavedQueryFilter, {
            filterItem: element
          });
        });

        if (filter.activeOperator === 1) {
          logicOp = 'OR';
        }

        return /*#__PURE__*/react__WEBPACK_IMPORTED_MODULE_0___default.a.createElement("li", null, /*#__PURE__*/react__WEBPACK_IMPORTED_MODULE_0___default.a.createElement("span", null, logicOp), /*#__PURE__*/react__WEBPACK_IMPORTED_MODULE_0___default.a.createElement("ul", {
          className: "savedQueryTree"
        }, children));
      } else {
        filter = this.props.filterItem;

        if (filter.instrument) {
          var operator;

          switch (filter.operator) {
            case 'equal':
              operator = '=';
              break;

            case 'notEqual':
              operator = '!=';
              break;

            case 'lessThanEqual':
              operator = '<=';
              break;

            case 'greaterThanEqual':
              operator = '>=';
              break;

            default:
              operator = filter.operator;
              break;
          }

          filterItem = /*#__PURE__*/react__WEBPACK_IMPORTED_MODULE_0___default.a.createElement("span", null, filter.instrument, ",", filter.field, " ", operator, " ", filter.value);
        } else {
          filterItem = /*#__PURE__*/react__WEBPACK_IMPORTED_MODULE_0___default.a.createElement("span", null, filter.Field, " ", filter.Operator, " ", filter.Value);
        }
      }

      return /*#__PURE__*/react__WEBPACK_IMPORTED_MODULE_0___default.a.createElement("li", null, filterItem);
    }
  }]);

  return ManageSavedQueryFilter;
}(react__WEBPACK_IMPORTED_MODULE_0__["Component"]);
/*
 *  The following component is used for displaying the individual saved queries in the
 *  manage saved queries tab
 */


var ManageSavedQueryRow = /*#__PURE__*/function (_Component11) {
  _inherits(ManageSavedQueryRow, _Component11);

  var _super11 = _createSuper(ManageSavedQueryRow);

  function ManageSavedQueryRow(props) {
    var _this12;

    _classCallCheck(this, ManageSavedQueryRow);

    _this12 = _super11.call(this, props);
    _this12.state = {};
    return _this12;
  }

  _createClass(ManageSavedQueryRow, [{
    key: "render",
    value: function render() {
      var fields = [];
      var filters;

      if (this.props.Query.Fields && Array.isArray(this.props.Query.Fields)) {
        for (var i = 0; i < this.props.Query.Fields.length; i += 1) {
          fields.push( /*#__PURE__*/react__WEBPACK_IMPORTED_MODULE_0___default.a.createElement("li", null, this.props.Query.Fields[i]));
        }
      } else if (this.props.Query.Fields) {
        for (var instrument in this.props.Query.Fields) {
          for (var field in this.props.Query.Fields[instrument]) {
            if (field === "allVisits") {
              continue;
            } else {
              fields.push( /*#__PURE__*/react__WEBPACK_IMPORTED_MODULE_0___default.a.createElement("li", null, instrument, ",", field));
            }
          }
        }
      }

      if (fields.length === 0) {
        fields.push( /*#__PURE__*/react__WEBPACK_IMPORTED_MODULE_0___default.a.createElement("li", null, "No fields defined"));
      }

      if (this.props.Query.Conditions) {
        var operator, filter;

        if (this.props.Query.Conditions.activeOperator) {
          if (this.props.Query.Conditions.children) {
            if (this.props.Query.Conditions.activeOperator === 0) {
              operator = /*#__PURE__*/react__WEBPACK_IMPORTED_MODULE_0___default.a.createElement("span", null, "AND");
            } else {
              operator = /*#__PURE__*/react__WEBPACK_IMPORTED_MODULE_0___default.a.createElement("span", null, "OR");
            }

            filter = this.props.Query.Conditions.children.map(function (element, key) {
              return /*#__PURE__*/react__WEBPACK_IMPORTED_MODULE_0___default.a.createElement(ManageSavedQueryFilter, {
                key: key,
                filterItem: element
              });
            });
          } else {
            operator = /*#__PURE__*/react__WEBPACK_IMPORTED_MODULE_0___default.a.createElement("span", null, "No filters defined");
          }
        } else {
          if (this.props.Query.Conditions.length === 0) {
            operator = /*#__PURE__*/react__WEBPACK_IMPORTED_MODULE_0___default.a.createElement("span", null, "No filters defined");
          } else {
            operator = /*#__PURE__*/react__WEBPACK_IMPORTED_MODULE_0___default.a.createElement("span", null, "AND");
            filter = this.props.Query.Conditions.map(function (element, key) {
              return /*#__PURE__*/react__WEBPACK_IMPORTED_MODULE_0___default.a.createElement(ManageSavedQueryFilter, {
                key: key,
                filterItem: element
              });
            });
          }
        }

        filters = /*#__PURE__*/react__WEBPACK_IMPORTED_MODULE_0___default.a.createElement("div", {
          className: "tree"
        }, /*#__PURE__*/react__WEBPACK_IMPORTED_MODULE_0___default.a.createElement("ul", {
          className: "firstUL savedQueryTree"
        }, /*#__PURE__*/react__WEBPACK_IMPORTED_MODULE_0___default.a.createElement("li", null, operator, /*#__PURE__*/react__WEBPACK_IMPORTED_MODULE_0___default.a.createElement("ul", {
          className: "savedQueryTree"
        }, filter))));
      }

      if (!filters) {
        filters = /*#__PURE__*/react__WEBPACK_IMPORTED_MODULE_0___default.a.createElement("strong", null, "No filters defined");
      }

      return /*#__PURE__*/react__WEBPACK_IMPORTED_MODULE_0___default.a.createElement("tr", null, /*#__PURE__*/react__WEBPACK_IMPORTED_MODULE_0___default.a.createElement("td", null, this.props.Name), /*#__PURE__*/react__WEBPACK_IMPORTED_MODULE_0___default.a.createElement("td", null, /*#__PURE__*/react__WEBPACK_IMPORTED_MODULE_0___default.a.createElement("ul", null, fields)), /*#__PURE__*/react__WEBPACK_IMPORTED_MODULE_0___default.a.createElement("td", null, filters));
    }
  }]);

  return ManageSavedQueryRow;
}(react__WEBPACK_IMPORTED_MODULE_0__["Component"]);

ManageSavedQueryRow.propTypes = {
  Name: prop_types__WEBPACK_IMPORTED_MODULE_1___default.a.string,
  Query: prop_types__WEBPACK_IMPORTED_MODULE_1___default.a.object
};
ManageSavedQueryRow.defaultProps = {
  Name: 'Unknown',
  Query: {
    Fields: []
  }
};
/*
 *  The following component is used for displaying the manage saved queries tab content
 */

var ManageSavedQueriesTabPane = /*#__PURE__*/function (_Component12) {
  _inherits(ManageSavedQueriesTabPane, _Component12);

  var _super12 = _createSuper(ManageSavedQueriesTabPane);

  function ManageSavedQueriesTabPane(props) {
    var _this13;

    _classCallCheck(this, ManageSavedQueriesTabPane);

    _this13 = _super12.call(this, props);
    _this13.state = {
      savePrompt: false,
      queriesLoaded: false,
      queries: {}
    };
    _this13.dismissDialog = _this13.dismissDialog.bind(_assertThisInitialized(_this13));
    _this13.saveQuery = _this13.saveQuery.bind(_assertThisInitialized(_this13));
    _this13.savedQuery = _this13.savedQuery.bind(_assertThisInitialized(_this13));
    return _this13;
  }

  _createClass(ManageSavedQueriesTabPane, [{
    key: "dismissDialog",
    value: function dismissDialog() {
      this.setState({
        savePrompt: false
      });
    }
  }, {
    key: "saveQuery",
    value: function saveQuery() {
      this.setState({
        savePrompt: true
      });
    }
  }, {
    key: "savedQuery",
    value: function savedQuery(name, shared) {
      if (this.props.onSaveQuery) {
        this.props.onSaveQuery(name, shared, 'false');
      }

      this.setState({
        savePrompt: false
      });
    }
  }, {
    key: "render",
    value: function render() {
      var queryRows = [];

      if (this.props.queriesLoaded) {
        for (var i = 0; i < this.props.userQueries.length; i += 1) {
          var query = this.props.queryDetails[this.props.userQueries[i]];
          var name = 'Unnamed Query: ' + this.props.userQueries[i];

          if (query.Meta.name) {
            name = query.Meta.name;
          }

          queryRows.push( /*#__PURE__*/react__WEBPACK_IMPORTED_MODULE_0___default.a.createElement(ManageSavedQueryRow, {
            Name: name,
            Query: query
          }));
        }
      } else {
        queryRows.push( /*#__PURE__*/react__WEBPACK_IMPORTED_MODULE_0___default.a.createElement("tr", {
          key: "loading"
        }, /*#__PURE__*/react__WEBPACK_IMPORTED_MODULE_0___default.a.createElement("td", {
          colSpan: "3"
        }, "Loading saved query details")));
      }

      var savePrompt = '';

      if (this.state.savePrompt) {
        savePrompt = /*#__PURE__*/react__WEBPACK_IMPORTED_MODULE_0___default.a.createElement(SaveQueryDialog, {
          onDismissClicked: this.dismissDialog,
          onSaveClicked: this.savedQuery
        });
      }

      var content = /*#__PURE__*/react__WEBPACK_IMPORTED_MODULE_0___default.a.createElement("div", null, /*#__PURE__*/react__WEBPACK_IMPORTED_MODULE_0___default.a.createElement("h2", null, "Your currently saved queries"), /*#__PURE__*/react__WEBPACK_IMPORTED_MODULE_0___default.a.createElement("button", {
        onClick: this.saveQuery
      }, "Save Current Query"), /*#__PURE__*/react__WEBPACK_IMPORTED_MODULE_0___default.a.createElement("table", {
        className: "table table-hover table-primary table-bordered colm-freeze"
      }, /*#__PURE__*/react__WEBPACK_IMPORTED_MODULE_0___default.a.createElement("thead", null, /*#__PURE__*/react__WEBPACK_IMPORTED_MODULE_0___default.a.createElement("tr", {
        key: "info",
        className: "info"
      }, /*#__PURE__*/react__WEBPACK_IMPORTED_MODULE_0___default.a.createElement("th", null, "Query Name"), /*#__PURE__*/react__WEBPACK_IMPORTED_MODULE_0___default.a.createElement("th", null, "Fields"), /*#__PURE__*/react__WEBPACK_IMPORTED_MODULE_0___default.a.createElement("th", null, "Filters"))), /*#__PURE__*/react__WEBPACK_IMPORTED_MODULE_0___default.a.createElement("tbody", null, queryRows)), savePrompt);
      return /*#__PURE__*/react__WEBPACK_IMPORTED_MODULE_0___default.a.createElement(TabPane, {
        TabId: this.props.TabId,
        Loading: this.props.Loading
      }, content);
    }
  }]);

  return ManageSavedQueriesTabPane;
}(react__WEBPACK_IMPORTED_MODULE_0__["Component"]);

ManageSavedQueriesTabPane.propTypes = {
  userQueries: prop_types__WEBPACK_IMPORTED_MODULE_1___default.a.array,
  globalQueries: prop_types__WEBPACK_IMPORTED_MODULE_1___default.a.array,
  queriesLoaded: prop_types__WEBPACK_IMPORTED_MODULE_1___default.a.bool,
  queryDetails: prop_types__WEBPACK_IMPORTED_MODULE_1___default.a.object
};
ManageSavedQueriesTabPane.defaultProps = {
  userQueries: [],
  globalQueries: [],
  queriesLoaded: false,
  queryDetails: {}
};
window.Loading = Loading;
window.TabPane = TabPane;
window.InfoTabPane = InfoTabPane;
window.FieldSelectTabPane = FieldSelectTabPane;
window.FilterSelectTabPane = FilterSelectTabPane;
window.ViewDataTabPane = ViewDataTabPane;
window.ScatterplotGraph = ScatterplotGraph;
window.StatsVisualizationTabPane = StatsVisualizationTabPane;
window.SaveQueryDialog = SaveQueryDialog;
window.ManageSavedQueryFilter = ManageSavedQueryFilter;
window.ManageSavedQueryRow = ManageSavedQueryRow;
window.ManageSavedQueriesTabPane = ManageSavedQueriesTabPane;
/* harmony default export */ __webpack_exports__["default"] = ({
  Loading: Loading,
  TabPane: TabPane,
  InfoTabPane: InfoTabPane,
  FieldSelectTabPane: FieldSelectTabPane,
  FilterSelectTabPane: FilterSelectTabPane,
  ViewDataTabPane: ViewDataTabPane,
  ScatterplotGraph: ScatterplotGraph,
  StatsVisualizationTabPane: StatsVisualizationTabPane,
  SaveQueryDialog: SaveQueryDialog,
  ManageSavedQueryFilter: ManageSavedQueryFilter,
  ManageSavedQueryRow: ManageSavedQueryRow,
  ManageSavedQueriesTabPane: ManageSavedQueriesTabPane
});

/***/ })
/******/ ]);
//# sourceMappingURL=react.tabs.js.map