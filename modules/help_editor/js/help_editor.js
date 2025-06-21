/******/ (() => { // webpackBootstrap
/******/ 	var __webpack_modules__ = ({

/***/ "./jsx/DataTable.js":
/*!**************************!*\
  !*** ./jsx/DataTable.js ***!
  \**************************/
/***/ ((__unused_webpack_module, exports, __webpack_require__) => {

"use strict";


var _interopRequireDefault = __webpack_require__(/*! @babel/runtime/helpers/interopRequireDefault */ "./node_modules/@babel/runtime/helpers/interopRequireDefault.js");
var _typeof3 = __webpack_require__(/*! @babel/runtime/helpers/typeof */ "./node_modules/@babel/runtime/helpers/typeof.js");
Object.defineProperty(exports, "__esModule", ({
  value: true
}));
exports["default"] = void 0;
var _typeof2 = _interopRequireDefault(__webpack_require__(/*! @babel/runtime/helpers/typeof */ "./node_modules/@babel/runtime/helpers/typeof.js"));
var _classCallCheck2 = _interopRequireDefault(__webpack_require__(/*! @babel/runtime/helpers/classCallCheck */ "./node_modules/@babel/runtime/helpers/classCallCheck.js"));
var _createClass2 = _interopRequireDefault(__webpack_require__(/*! @babel/runtime/helpers/createClass */ "./node_modules/@babel/runtime/helpers/createClass.js"));
var _assertThisInitialized2 = _interopRequireDefault(__webpack_require__(/*! @babel/runtime/helpers/assertThisInitialized */ "./node_modules/@babel/runtime/helpers/assertThisInitialized.js"));
var _inherits2 = _interopRequireDefault(__webpack_require__(/*! @babel/runtime/helpers/inherits */ "./node_modules/@babel/runtime/helpers/inherits.js"));
var _possibleConstructorReturn2 = _interopRequireDefault(__webpack_require__(/*! @babel/runtime/helpers/possibleConstructorReturn */ "./node_modules/@babel/runtime/helpers/possibleConstructorReturn.js"));
var _getPrototypeOf2 = _interopRequireDefault(__webpack_require__(/*! @babel/runtime/helpers/getPrototypeOf */ "./node_modules/@babel/runtime/helpers/getPrototypeOf.js"));
var _react = _interopRequireWildcard(__webpack_require__(/*! react */ "react"));
var _propTypes = _interopRequireDefault(__webpack_require__(/*! prop-types */ "./node_modules/prop-types/index.js"));
var _PaginationLinks = _interopRequireDefault(__webpack_require__(/*! jsx/PaginationLinks */ "./jsx/PaginationLinks.js"));
var _reactAddonsCreateFragment = _interopRequireDefault(__webpack_require__(/*! react-addons-create-fragment */ "./node_modules/react-addons-create-fragment/index.js"));
var _Form = __webpack_require__(/*! jsx/Form */ "./jsx/Form.js");
function _getRequireWildcardCache(e) { if ("function" != typeof WeakMap) return null; var r = new WeakMap(), t = new WeakMap(); return (_getRequireWildcardCache = function _getRequireWildcardCache(e) { return e ? t : r; })(e); }
function _interopRequireWildcard(e, r) { if (!r && e && e.__esModule) return e; if (null === e || "object" != _typeof3(e) && "function" != typeof e) return { "default": e }; var t = _getRequireWildcardCache(r); if (t && t.has(e)) return t.get(e); var n = { __proto__: null }, a = Object.defineProperty && Object.getOwnPropertyDescriptor; for (var u in e) { if ("default" !== u && {}.hasOwnProperty.call(e, u)) { var i = a ? Object.getOwnPropertyDescriptor(e, u) : null; i && (i.get || i.set) ? Object.defineProperty(n, u, i) : n[u] = e[u]; } } return n["default"] = e, t && t.set(e, n), n; }
function _createSuper(t) { var r = _isNativeReflectConstruct(); return function () { var e, o = (0, _getPrototypeOf2["default"])(t); if (r) { var s = (0, _getPrototypeOf2["default"])(this).constructor; e = Reflect.construct(o, arguments, s); } else e = o.apply(this, arguments); return (0, _possibleConstructorReturn2["default"])(this, e); }; }
function _isNativeReflectConstruct() { try { var t = !Boolean.prototype.valueOf.call(Reflect.construct(Boolean, [], function () {})); } catch (t) {} return (_isNativeReflectConstruct = function _isNativeReflectConstruct() { return !!t; })(); }
/**
 * Data Table component
 * Displays a set of data that is receives via props.
 */
var DataTable = /*#__PURE__*/function (_Component) {
  (0, _inherits2["default"])(DataTable, _Component);
  var _super = _createSuper(DataTable);
  /**
   * @constructor
   * @param {object} props - React Component properties
   */
  function DataTable(props) {
    var _this;
    (0, _classCallCheck2["default"])(this, DataTable);
    _this = _super.call(this, props);
    _this.state = {
      page: {
        number: 1,
        rows: 20
      },
      sort: {
        column: -1,
        ascending: true
      }
    };
    _this.changePage = _this.changePage.bind((0, _assertThisInitialized2["default"])(_this));
    _this.setSortColumn = _this.setSortColumn.bind((0, _assertThisInitialized2["default"])(_this));
    _this.updateSortColumn = _this.updateSortColumn.bind((0, _assertThisInitialized2["default"])(_this));
    _this.toggleSortOrder = _this.toggleSortOrder.bind((0, _assertThisInitialized2["default"])(_this));
    _this.updatePageNumber = _this.updatePageNumber.bind((0, _assertThisInitialized2["default"])(_this));
    _this.updatePageRows = _this.updatePageRows.bind((0, _assertThisInitialized2["default"])(_this));
    _this.downloadCSV = _this.downloadCSV.bind((0, _assertThisInitialized2["default"])(_this));
    _this.getFilteredRowIndexes = _this.getFilteredRowIndexes.bind((0, _assertThisInitialized2["default"])(_this));
    _this.sortRows = _this.sortRows.bind((0, _assertThisInitialized2["default"])(_this));
    _this.hasFilterKeyword = _this.hasFilterKeyword.bind((0, _assertThisInitialized2["default"])(_this));
    _this.renderActions = _this.renderActions.bind((0, _assertThisInitialized2["default"])(_this));
    return _this;
  }

  /**
   * Set the component page variable
   * to a new value
   * @param {number} i - Page index
   */
  (0, _createClass2["default"])(DataTable, [{
    key: "changePage",
    value: function changePage(i) {
      var page = this.state.page;
      page.number = i;
      this.setState({
        page: page
      });
    }

    /**
     * Update the sort column
     * If component sort.column is already set to column
     * Toggle sort.ascending
     * @param {number} column - The column index
     */
  }, {
    key: "setSortColumn",
    value: function setSortColumn(column) {
      if (this.state.sort.column === column) {
        this.toggleSortOrder();
      } else {
        this.updateSortColumn(column);
      }
    }

    /**
     * Update the sort column
     * @param {number} column - The column index
     */
  }, {
    key: "updateSortColumn",
    value: function updateSortColumn(column) {
      var sort = this.state.sort;
      sort.column = column;
      this.setState({
        sort: sort
      });
    }

    /**
     * Toggle sort.ascending
     */
  }, {
    key: "toggleSortOrder",
    value: function toggleSortOrder() {
      var sort = this.state.sort;
      sort.ascending = !sort.ascending;
      this.setState({
        sort: sort
      });
    }

    /**
     * Updates page state
     * @param {number} number - Number of page
     */
  }, {
    key: "updatePageNumber",
    value: function updatePageNumber(number) {
      var page = this.state.page;
      page.number = number;
      this.setState({
        page: page
      });
    }

    /**
     * Update number of rows per page
     * @param {object} e - Event from which to abstract value
     */
  }, {
    key: "updatePageRows",
    value: function updatePageRows(e) {
      var page = Object.assign({}, this.state.page);
      page.rows = e.target.value;
      page.number = 1;
      this.setState({
        page: page
      });
    }

    /**
     * Export the filtered rows and columns into a csv
     * @param {number[]} filteredRowIndexes - The filtered Row Indexes
     */
  }, {
    key: "downloadCSV",
    value: function downloadCSV(filteredRowIndexes) {
      var _this2 = this;
      var csvData = filteredRowIndexes.map(function (id) {
        return _this2.props.data[id];
      });
      // Map cell data to proper values if applicable.
      if (this.props.getMappedCell) {
        csvData = csvData.map(function (row, i) {
          return _this2.props.fields.flatMap(function (field, j) {
            return _this2.props.getMappedCell(field.label, row[j], row, _this2.props.fields.map(function (val) {
              return val.label;
            }), j);
          });
        });
      }
      var csvworker = new Worker(loris.BaseURL + '/js/workers/savecsv.js');
      csvworker.addEventListener('message', function (e) {
        var dataURL;
        var dataDate;
        var link;
        if (e.data.cmd === 'SaveCSV') {
          dataDate = new Date().toISOString();
          dataURL = window.URL.createObjectURL(e.data.message);
          link = document.createElement('a');
          link.download = 'data-' + dataDate + '.csv';
          link.type = 'text/csv';
          link.href = dataURL;
          document.body.appendChild(link);
          $(link)[0].click();
          document.body.removeChild(link);
        }
      });
      var headerList = this.props.fields.map(function (field) {
        return field.label;
      });
      csvworker.postMessage({
        cmd: 'SaveFile',
        data: csvData,
        headers: headerList,
        identifiers: this.props.RowNameMap
      });
    }

    /**
     * Get the Filtered Row Indexes
     */
  }, {
    key: "getFilteredRowIndexes",
    value: function getFilteredRowIndexes() {
      var useKeyword = false;
      var filterValuesCount = Object.keys(this.props.filters).length;
      var tableData = this.props.data;
      var fieldData = this.props.fields;
      var filteredIndexes = [];

      // If there are no filters set, use all the data.
      var hasFilters = filterValuesCount !== 0;
      if (hasFilters === false) {
        for (var i = 0; i < tableData.length; i++) {
          filteredIndexes.push(i);
        }
        return filteredIndexes;
      }
      if (this.props.filters.keyword) {
        useKeyword = true;
      }
      if (useKeyword) {
        filterValuesCount -= 1;
      }
      for (var _i = 0; _i < tableData.length; _i++) {
        var headerCount = 0;
        var keywordMatch = 0;
        for (var j = 0; j < fieldData.length; j++) {
          var data = tableData[_i] ? tableData[_i][j] : null;
          if (this.hasFilterKeyword((fieldData[j].filter || {}).name, data)) {
            headerCount++;
          }
          if (useKeyword) {
            if (this.hasFilterKeyword('keyword', data)) {
              keywordMatch++;
            }
          }
        }
        if (headerCount === filterValuesCount && (useKeyword === true && keywordMatch > 0 || useKeyword === false && keywordMatch === 0)) {
          filteredIndexes.push(_i);
        }
      }
      return filteredIndexes;
    }

    /**
     * Sort the given rows according to the sort configuration
     * @param {number[]} rowIndexes - The row indexes
     * @return {object[]}
     */
  }, {
    key: "sortRows",
    value: function sortRows(rowIndexes) {
      var _this3 = this;
      var index = [];
      for (var i = 0; i < rowIndexes.length; i++) {
        var idx = rowIndexes[i];
        var val = this.props.data[idx][this.state.sort.column] || undefined;

        // If sortColumn is equal to default No. column, set value to be
        // index + 1
        if (this.state.sort.column === -1) {
          val = idx + 1;
        }
        var isString = typeof val === 'string' || val instanceof String;
        var isNumber = !isNaN(val) && (0, _typeof2["default"])(val) !== 'object';
        if (val === '.') {
          // hack to handle non-existent items in DQT
          val = null;
        } else if (isNumber) {
          // perform type conversion (from string to int/float)
          val = Number(val);
        } else if (isString) {
          // if string with text convert to lowercase
          val = val.toLowerCase();
        } else if (Array.isArray(val)) {
          val = val.join(', ');
        } else {
          val = undefined;
        }
        if (this.props.RowNameMap) {
          index.push({
            RowIdx: idx,
            Value: val,
            Content: this.props.RowNameMap[idx]
          });
        } else {
          index.push({
            RowIdx: idx,
            Value: val,
            Content: idx + 1
          });
        }
      }
      index.sort(function (a, b) {
        if (_this3.state.sort.ascending) {
          if (a.Value === b.Value) {
            // If all values are equal, sort by rownum
            if (a.RowIdx < b.RowIdx) return -1;
            if (a.RowIdx > b.RowIdx) return 1;
          }
          // Check if null values
          if (a.Value === null || typeof a.Value === 'undefined') return -1;
          if (b.Value === null || typeof b.Value === 'undefined') return 1;

          // Sort by value
          if (a.Value < b.Value) return -1;
          if (a.Value > b.Value) return 1;
        } else {
          if (a.Value === b.Value) {
            // If all values are equal, sort by rownum
            if (a.RowIdx < b.RowIdx) return 1;
            if (a.RowIdx > b.RowIdx) return -1;
          }
          // Check if null values
          if (a.Value === null || typeof a.Value === 'undefined') return 1;
          if (b.Value === null || typeof b.Value === 'undefined') return -1;

          // Sort by value
          if (a.Value < b.Value) return 1;
          if (a.Value > b.Value) return -1;
        }
        // They're equal..
        return 0;
      });
      return index;
    }

    /**
     * Searches for the filter keyword in the column cell
     *
     * Note: Search is case-insensitive.
     * @param {string} name field name
     * @param {string} data search string
     * @return {boolean} true, if filter value is found to be a substring
     * of one of the column values, false otherwise.
     */
  }, {
    key: "hasFilterKeyword",
    value: function hasFilterKeyword(name, data) {
      var filterData = null;
      var exactMatch = false;
      var opposite = false;
      var result = false;
      var searchKey = null;
      var searchString = null;
      if (this.props.filters[name]) {
        filterData = this.props.filters[name].value;
        exactMatch = this.props.filters[name].exactMatch;
        opposite = this.props.filters[name].opposite;
      }

      // Handle null inputs
      if (filterData === null || data === null) {
        return false;
      }

      // Handle numeric inputs
      if (typeof filterData === 'number') {
        var intData = Number.parseInt(data, 10);
        result = filterData === intData;
      }

      // Handle string inputs
      if (typeof filterData === 'string') {
        searchKey = filterData.toLowerCase();
        switch ((0, _typeof2["default"])(data)) {
          case 'object':
            // Handles the case where the data is an array (typeof 'object')
            // and you want to search through it for
            // the string you are filtering by
            var searchArray = data.map(function (e) {
              return e.toLowerCase();
            });
            if (exactMatch) {
              result = searchArray.includes(searchKey);
            } else {
              result = searchArray.find(function (e) {
                return e.indexOf(searchKey) > -1;
              }) !== undefined;
            }
            break;
          default:
            searchString = data ? data.toString().toLowerCase() : '';
            if (exactMatch) {
              result = searchString === searchKey;
            } else if (opposite) {
              result = searchString !== searchKey;
            } else {
              result = searchString.indexOf(searchKey) > -1;
            }
            break;
        }
      }

      // Handle boolean inputs
      if (typeof filterData === 'boolean') {
        result = filterData === data;
      }

      // Handle array inputs for multiselects
      if ((0, _typeof2["default"])(filterData) === 'object') {
        var match = false;
        for (var i = 0; i < filterData.length; i += 1) {
          searchKey = filterData[i].toLowerCase();
          searchString = data ? data.toString().toLowerCase() : '';
          var _searchArray = searchString.split(',');
          match = _searchArray.includes(searchKey);
          if (match) {
            result = true;
          }
        }
      }
      return result;
    }

    /**
     * Called by React when the component has been rendered on the page.
     */
  }, {
    key: "componentDidMount",
    value: function componentDidMount() {
      if (!this.props.noDynamicTable) {
        $('.dynamictable').DynamicTable();
      }
    }

    /**
     * Renders the Actions buttons.
     * @return {string[]|void} - Array of React Elements
     */
  }, {
    key: "renderActions",
    value: function renderActions() {
      if (this.props.actions) {
        return this.props.actions.map(function (action, key) {
          if (action.show !== false) {
            return /*#__PURE__*/_react["default"].createElement(_Form.CTA, {
              key: key,
              label: action.label,
              onUserInput: action.action
            });
          }
        });
      }
    }

    /**
     * Renders the React component.
     * @return {JSX} - React markup for the component
     */
  }, {
    key: "render",
    value: function render() {
      var _this4 = this;
      if ((this.props.data === null || this.props.data.length === 0) && !this.props.nullTableShow) {
        return /*#__PURE__*/_react["default"].createElement("div", null, /*#__PURE__*/_react["default"].createElement("div", {
          className: "row"
        }, /*#__PURE__*/_react["default"].createElement("div", {
          className: "col-xs-12"
        }, /*#__PURE__*/_react["default"].createElement("div", {
          className: "pull-right",
          style: {
            marginRight: '10px'
          }
        }, this.renderActions()))), /*#__PURE__*/_react["default"].createElement("div", {
          className: "alert alert-info no-result-found-panel"
        }, /*#__PURE__*/_react["default"].createElement("strong", null, "No result found.")));
      }
      var rowsPerPage = this.state.page.rows;
      var headers = this.props.hide.defaultColumn === true ? [] : [/*#__PURE__*/_react["default"].createElement("th", {
        key: "th_col_0",
        onClick: function onClick() {
          _this4.setSortColumn(-1);
        }
      }, this.props.rowNumLabel)];
      var _loop = function _loop(i) {
        if (_this4.props.fields[i].show === true) {
          var colIndex = i + 1;
          if (_this4.props.fields[i].freezeColumn === true) {
            headers.push( /*#__PURE__*/_react["default"].createElement("th", {
              key: 'th_col_' + colIndex,
              id: _this4.props.freezeColumn,
              onClick: function onClick() {
                _this4.setSortColumn(i);
              }
            }, _this4.props.fields[i].label));
          } else {
            headers.push( /*#__PURE__*/_react["default"].createElement("th", {
              key: 'th_col_' + colIndex,
              onClick: function onClick() {
                _this4.setSortColumn(i);
              }
            }, _this4.props.fields[i].label));
          }
        }
      };
      for (var i = 0; i < this.props.fields.length; i += 1) {
        _loop(i);
      }
      var rows = [];
      var filteredRowIndexes = this.getFilteredRowIndexes();
      var filteredCount = filteredRowIndexes.length;
      var index = this.sortRows(filteredRowIndexes);
      var currentPageRow = rowsPerPage * (this.state.page.number - 1);

      // Format each cell for the data table.
      var _loop2 = function _loop2(_i2) {
        var rowIndex = index[_i2].RowIdx;
        var rowData = _this4.props.data[rowIndex];
        var curRow = [];

        // Iterates through headers to populate row columns
        // with corresponding data
        var _loop3 = function _loop3(j) {
          if (_this4.props.fields[j].show === false) {
            return "continue";
          }
          var celldata = rowData[j];
          var cell = null;
          var row = {};
          _this4.props.fields.forEach(function (field, k) {
            return row[field.label] = rowData[k];
          });
          var headers = _this4.props.fields.map(function (val) {
            return val.label;
          });

          // Get custom cell formatting if available
          if (_this4.props.getFormattedCell) {
            cell = _this4.props.getFormattedCell(_this4.props.fields[j].label, celldata, row, headers, j);
          } else {
            cell = /*#__PURE__*/_react["default"].createElement("td", null, celldata);
          }
          if (cell !== null) {
            curRow.push( /*#__PURE__*/_react["default"].cloneElement(cell, {
              key: 'td_col_' + j
            }));
          } else {
            curRow.push((0, _reactAddonsCreateFragment["default"])({
              celldata: celldata
            }));
          }
        };
        for (var j = 0; j < _this4.props.fields.length; j += 1) {
          var _ret = _loop3(j);
          if (_ret === "continue") continue;
        }
        var rowIndexDisplay = index[_i2].Content;
        rows.push( /*#__PURE__*/_react["default"].createElement("tr", {
          key: 'tr_' + rowIndex,
          colSpan: headers.length
        }, _this4.props.hide.defaultColumn === true ? null : /*#__PURE__*/_react["default"].createElement("td", {
          key: 'td_' + rowIndex
        }, rowIndexDisplay), curRow));
      };
      for (var _i2 = currentPageRow; _i2 < filteredCount && rows.length < rowsPerPage; _i2++) {
        _loop2(_i2);
      }
      var rowsPerPageDropdown = /*#__PURE__*/_react["default"].createElement("select", {
        className: "input-sm perPage",
        onChange: this.updatePageRows,
        value: this.state.page.rows
      }, /*#__PURE__*/_react["default"].createElement("option", null, "20"), /*#__PURE__*/_react["default"].createElement("option", null, "50"), /*#__PURE__*/_react["default"].createElement("option", null, "100"), /*#__PURE__*/_react["default"].createElement("option", null, "1000"), /*#__PURE__*/_react["default"].createElement("option", null, "5000"), /*#__PURE__*/_react["default"].createElement("option", null, "10000"));
      var loading = this.props.loading ? 'Loading...' : '';
      var header = this.props.hide.rowsPerPage === true ? '' : /*#__PURE__*/_react["default"].createElement("div", {
        className: "table-header"
      }, /*#__PURE__*/_react["default"].createElement("div", {
        className: "row"
      }, /*#__PURE__*/_react["default"].createElement("div", {
        style: {
          display: 'flex',
          justifyContent: 'space-between',
          alignItems: 'center',
          flexWrap: 'wrap',
          padding: '5px 15px'
        }
      }, /*#__PURE__*/_react["default"].createElement("div", {
        style: {
          order: '1',
          padding: '5px 0'
        }
      }, rows.length, " rows displayed of ", filteredCount, ". (Maximum rows per page: ", rowsPerPageDropdown, ")", loading), /*#__PURE__*/_react["default"].createElement("div", {
        style: {
          order: '2',
          display: 'flex',
          justifyContent: 'flex-end',
          alignItems: 'center',
          flexWrap: 'wrap',
          padding: '5px 0',
          marginLeft: 'auto'
        }
      }, this.renderActions(), this.props.hide.downloadCSV === true ? '' : /*#__PURE__*/_react["default"].createElement("button", {
        className: "btn btn-primary",
        onClick: this.downloadCSV.bind(null, filteredRowIndexes)
      }, "Download Table as CSV"), /*#__PURE__*/_react["default"].createElement(_PaginationLinks["default"], {
        Total: filteredCount,
        onChangePage: this.changePage,
        RowsPerPage: rowsPerPage,
        Active: this.state.page.number
      })))));
      var footer = /*#__PURE__*/_react["default"].createElement("div", null, /*#__PURE__*/_react["default"].createElement("div", {
        className: "row"
      }, /*#__PURE__*/_react["default"].createElement("div", {
        style: {
          display: 'flex',
          justifyContent: 'space-between',
          alignItems: 'center',
          flexWrap: 'wrap',
          padding: '5px 15px'
        }
      }, /*#__PURE__*/_react["default"].createElement("div", {
        style: {
          order: '1',
          padding: '5px 0'
        }
      }, rows.length, " rows displayed of ", filteredCount, ". (Maximum rows per page: ", rowsPerPageDropdown, ")"), /*#__PURE__*/_react["default"].createElement("div", {
        style: {
          order: '2',
          padding: '5px 0',
          marginLeft: 'auto'
        }
      }, /*#__PURE__*/_react["default"].createElement(_PaginationLinks["default"], {
        Total: filteredCount,
        onChangePage: this.changePage,
        RowsPerPage: rowsPerPage,
        Active: this.state.page.number
      })))));
      return /*#__PURE__*/_react["default"].createElement("div", {
        style: {
          margin: '14px'
        }
      }, header, /*#__PURE__*/_react["default"].createElement("table", {
        className: "table table-hover table-primary table-bordered dynamictable",
        id: "dynamictable"
      }, /*#__PURE__*/_react["default"].createElement("thead", null, /*#__PURE__*/_react["default"].createElement("tr", {
        className: "info"
      }, headers)), this.props.folder, /*#__PURE__*/_react["default"].createElement("tbody", null, rows)), footer);
    }
  }]);
  return DataTable;
}(_react.Component);
DataTable.propTypes = {
  data: _propTypes["default"].array.isRequired,
  rowNumLabel: _propTypes["default"].string,
  // Function of which returns a JSX element for a table cell, takes
  // parameters of the form: func(ColumnName, CellData, EntireRowData)
  getFormattedCell: _propTypes["default"].func,
  onSort: _propTypes["default"].func,
  actions: _propTypes["default"].array,
  hide: _propTypes["default"].object,
  nullTableShow: _propTypes["default"].bool,
  noDynamicTable: _propTypes["default"].bool,
  getMappedCell: _propTypes["default"].func,
  fields: _propTypes["default"].array,
  RowNameMap: _propTypes["default"].array,
  filters: _propTypes["default"].object,
  freezeColumn: _propTypes["default"].string,
  loading: _propTypes["default"].element,
  folder: _propTypes["default"].element
};
DataTable.defaultProps = {
  headers: [],
  data: {},
  rowNumLabel: 'No.',
  filters: {},
  hide: {
    rowsPerPage: false,
    downloadCSV: false,
    defaultColumn: false
  },
  nullTableShow: false,
  noDynamicTable: false
};
var _default = exports["default"] = DataTable;

/***/ }),

/***/ "./jsx/Filter.js":
/*!***********************!*\
  !*** ./jsx/Filter.js ***!
  \***********************/
/***/ ((__unused_webpack_module, exports, __webpack_require__) => {

"use strict";


var _interopRequireDefault = __webpack_require__(/*! @babel/runtime/helpers/interopRequireDefault */ "./node_modules/@babel/runtime/helpers/interopRequireDefault.js");
var _typeof = __webpack_require__(/*! @babel/runtime/helpers/typeof */ "./node_modules/@babel/runtime/helpers/typeof.js");
Object.defineProperty(exports, "__esModule", ({
  value: true
}));
exports["default"] = void 0;
var _react = _interopRequireWildcard(__webpack_require__(/*! react */ "react"));
var _propTypes = _interopRequireDefault(__webpack_require__(/*! prop-types */ "./node_modules/prop-types/index.js"));
var _Form = __webpack_require__(/*! jsx/Form */ "./jsx/Form.js");
var _DateTimePartialElement = _interopRequireDefault(__webpack_require__(/*! jsx/form/DateTimePartialElement */ "./jsx/form/DateTimePartialElement.tsx"));
function _getRequireWildcardCache(e) { if ("function" != typeof WeakMap) return null; var r = new WeakMap(), t = new WeakMap(); return (_getRequireWildcardCache = function _getRequireWildcardCache(e) { return e ? t : r; })(e); }
function _interopRequireWildcard(e, r) { if (!r && e && e.__esModule) return e; if (null === e || "object" != _typeof(e) && "function" != typeof e) return { "default": e }; var t = _getRequireWildcardCache(r); if (t && t.has(e)) return t.get(e); var n = { __proto__: null }, a = Object.defineProperty && Object.getOwnPropertyDescriptor; for (var u in e) { if ("default" !== u && {}.hasOwnProperty.call(e, u)) { var i = a ? Object.getOwnPropertyDescriptor(e, u) : null; i && (i.get || i.set) ? Object.defineProperty(n, u, i) : n[u] = e[u]; } } return n["default"] = e, t && t.set(e, n), n; }
/**
 * Filter component
 * A wrapper for form elements inside a selection filter.
 *
 * Constructs filter fields based on this.props.fields configuration object
 *
 * Alters the filter object and sends it to parent on every update.
 * @param {props} props
 * @return {JSX}
 */
function Filter(props) {
  /**
   * Takes query params from url and triggers an update of the fields that are
   * associated with those params, if they exist.
   */
  (0, _react.useEffect)(function () {
    var searchParams = new URLSearchParams(location.search);
    searchParams.forEach(function (value, name) {
      // This checks to make sure the filter actually exists
      if (props.fields.find(function (field) {
        return (field.filter || {}).name == name;
      })) {
        onFieldUpdate(name, searchParams.getAll(name));
      }
    });
  }, []);

  /**
   * Sets filter object to reflect values of input fields.
   * @param {string} name - form element type (i.e component name)
   * @param {string} value - the name of the form element
   */
  var onFieldUpdate = function onFieldUpdate(name, value) {
    var _JSON$parse = JSON.parse(JSON.stringify(props)),
      fields = _JSON$parse.fields;
    var type = fields.find(function (field) {
      return (field.filter || {}).name == name;
    }).filter.type;
    var exactMatch = !(type === 'text' || type === 'date' || type === 'datetime' || type === 'multiselect');
    if (value === null || value === '' || value.constructor === Array && value.length === 0 || type === 'checkbox' && value === false) {
      props.removeFilter(name);
    } else {
      props.addFilter(name, value, exactMatch);
    }
  };

  /**
   * Renders the filters based on the defined fields.
   * @return {array}
   */
  var renderFilterFields = function renderFilterFields() {
    return props.fields.reduce(function (result, field) {
      var filter = field.filter;
      if (filter && filter.hide !== true) {
        var element;
        switch (filter.type) {
          case 'text':
            element = /*#__PURE__*/_react["default"].createElement(_Form.TextboxElement, null);
            break;
          case 'select':
            element = /*#__PURE__*/_react["default"].createElement(_Form.SelectElement, {
              options: filter.options,
              sortByValue: filter.sortByValue,
              autoSelect: false
            });
            break;
          case 'multiselect':
            element = /*#__PURE__*/_react["default"].createElement(_Form.SelectElement, {
              options: filter.options,
              sortByValue: filter.sortByValue,
              multiple: true,
              emptyOption: false
            });
            break;
          case 'numeric':
            element = /*#__PURE__*/_react["default"].createElement(_Form.NumericElement, {
              options: filter.options
            });
            break;
          case 'date':
            element = /*#__PURE__*/_react["default"].createElement(_Form.DateElement, null);
            break;
          case 'datetime':
            element = /*#__PURE__*/_react["default"].createElement(_DateTimePartialElement["default"], null);
            break;
          case 'checkbox':
            element = /*#__PURE__*/_react["default"].createElement(_Form.CheckboxElement, null);
            break;
          case 'time':
            element = /*#__PURE__*/_react["default"].createElement(_Form.TimeElement, null);
            break;
          default:
            element = /*#__PURE__*/_react["default"].createElement(_Form.TextboxElement, null);
        }

        // The value prop has to default to false if the first two options
        // are undefined so that the checkbox component is a controlled input
        // element with a starting default value
        result.push( /*#__PURE__*/_react["default"].cloneElement(element, {
          key: filter.name,
          name: filter.name,
          label: field.label,
          value: (props.filters[filter.name] || {}).value || null,
          onUserInput: onFieldUpdate
        }));
      }
      return result;
    }, []);
  };
  var filterPresets = function filterPresets() {
    if (props.filterPresets) {
      var presets = props.filterPresets.map(function (preset) {
        var handleClick = function handleClick() {
          return props.updateFilters(preset.filter);
        };
        return /*#__PURE__*/_react["default"].createElement("li", null, /*#__PURE__*/_react["default"].createElement("a", {
          onClick: handleClick
        }, preset.label));
      });
      return /*#__PURE__*/_react["default"].createElement("li", {
        className: "dropdown"
      }, /*#__PURE__*/_react["default"].createElement("a", {
        className: "dropdown-toggle",
        "data-toggle": "dropdown",
        role: "button"
      }, "Load Filter Preset ", /*#__PURE__*/_react["default"].createElement("span", {
        className: "caret"
      })), /*#__PURE__*/_react["default"].createElement("ul", {
        className: "dropdown-menu",
        role: "menu"
      }, presets));
    }
  };
  var filterActions = /*#__PURE__*/_react["default"].createElement("ul", {
    className: "nav nav-tabs navbar-right",
    style: {
      borderBottom: 'none'
    }
  }, filterPresets(), /*#__PURE__*/_react["default"].createElement("li", null, /*#__PURE__*/_react["default"].createElement("a", {
    role: "button",
    name: "reset",
    onClick: props.clearFilters
  }, "Clear Filter")));
  return /*#__PURE__*/_react["default"].createElement(_Form.FormElement, {
    id: props.id,
    name: props.name
  }, /*#__PURE__*/_react["default"].createElement(_Form.FieldsetElement, {
    columns: props.columns,
    legend: props.title
  }, filterActions, renderFilterFields()));
}
Filter.defaultProps = {
  id: null,
  clearFilter: function clearFilter() {
    console.warn('onUpdate() callback is not set!');
  },
  columns: 1
};
Filter.propTypes = {
  filters: _propTypes["default"].object.isRequired,
  clearFilter: _propTypes["default"].func.isRequired,
  id: _propTypes["default"].string,
  name: _propTypes["default"].string,
  columns: _propTypes["default"].number,
  title: _propTypes["default"].string,
  fields: _propTypes["default"].array.isRequired,
  removeFilter: _propTypes["default"].func,
  addFilter: _propTypes["default"].func,
  filterPresets: _propTypes["default"].array,
  updateFilters: _propTypes["default"].func,
  clearFilters: _propTypes["default"].func
};
var _default = exports["default"] = Filter;

/***/ }),

/***/ "./jsx/FilterableDataTable.js":
/*!************************************!*\
  !*** ./jsx/FilterableDataTable.js ***!
  \************************************/
/***/ ((__unused_webpack_module, exports, __webpack_require__) => {

"use strict";


var _interopRequireDefault = __webpack_require__(/*! @babel/runtime/helpers/interopRequireDefault */ "./node_modules/@babel/runtime/helpers/interopRequireDefault.js");
var _typeof = __webpack_require__(/*! @babel/runtime/helpers/typeof */ "./node_modules/@babel/runtime/helpers/typeof.js");
Object.defineProperty(exports, "__esModule", ({
  value: true
}));
exports["default"] = void 0;
var _slicedToArray2 = _interopRequireDefault(__webpack_require__(/*! @babel/runtime/helpers/slicedToArray */ "./node_modules/@babel/runtime/helpers/slicedToArray.js"));
var _classCallCheck2 = _interopRequireDefault(__webpack_require__(/*! @babel/runtime/helpers/classCallCheck */ "./node_modules/@babel/runtime/helpers/classCallCheck.js"));
var _createClass2 = _interopRequireDefault(__webpack_require__(/*! @babel/runtime/helpers/createClass */ "./node_modules/@babel/runtime/helpers/createClass.js"));
var _assertThisInitialized2 = _interopRequireDefault(__webpack_require__(/*! @babel/runtime/helpers/assertThisInitialized */ "./node_modules/@babel/runtime/helpers/assertThisInitialized.js"));
var _inherits2 = _interopRequireDefault(__webpack_require__(/*! @babel/runtime/helpers/inherits */ "./node_modules/@babel/runtime/helpers/inherits.js"));
var _possibleConstructorReturn2 = _interopRequireDefault(__webpack_require__(/*! @babel/runtime/helpers/possibleConstructorReturn */ "./node_modules/@babel/runtime/helpers/possibleConstructorReturn.js"));
var _getPrototypeOf2 = _interopRequireDefault(__webpack_require__(/*! @babel/runtime/helpers/getPrototypeOf */ "./node_modules/@babel/runtime/helpers/getPrototypeOf.js"));
var _react = _interopRequireWildcard(__webpack_require__(/*! react */ "react"));
var _propTypes = _interopRequireDefault(__webpack_require__(/*! prop-types */ "./node_modules/prop-types/index.js"));
var _Panel = _interopRequireDefault(__webpack_require__(/*! jsx/Panel */ "./jsx/Panel.js"));
var _DataTable = _interopRequireDefault(__webpack_require__(/*! jsx/DataTable */ "./jsx/DataTable.js"));
var _Filter = _interopRequireDefault(__webpack_require__(/*! jsx/Filter */ "./jsx/Filter.js"));
var _ProgressBar = _interopRequireDefault(__webpack_require__(/*! jsx/ProgressBar */ "./jsx/ProgressBar.js"));
function _getRequireWildcardCache(e) { if ("function" != typeof WeakMap) return null; var r = new WeakMap(), t = new WeakMap(); return (_getRequireWildcardCache = function _getRequireWildcardCache(e) { return e ? t : r; })(e); }
function _interopRequireWildcard(e, r) { if (!r && e && e.__esModule) return e; if (null === e || "object" != _typeof(e) && "function" != typeof e) return { "default": e }; var t = _getRequireWildcardCache(r); if (t && t.has(e)) return t.get(e); var n = { __proto__: null }, a = Object.defineProperty && Object.getOwnPropertyDescriptor; for (var u in e) { if ("default" !== u && {}.hasOwnProperty.call(e, u)) { var i = a ? Object.getOwnPropertyDescriptor(e, u) : null; i && (i.get || i.set) ? Object.defineProperty(n, u, i) : n[u] = e[u]; } } return n["default"] = e, t && t.set(e, n), n; }
function _createSuper(t) { var r = _isNativeReflectConstruct(); return function () { var e, o = (0, _getPrototypeOf2["default"])(t); if (r) { var s = (0, _getPrototypeOf2["default"])(this).constructor; e = Reflect.construct(o, arguments, s); } else e = o.apply(this, arguments); return (0, _possibleConstructorReturn2["default"])(this, e); }; }
function _isNativeReflectConstruct() { try { var t = !Boolean.prototype.valueOf.call(Reflect.construct(Boolean, [], function () {})); } catch (t) {} return (_isNativeReflectConstruct = function _isNativeReflectConstruct() { return !!t; })(); }
/**
 * FilterableDataTable component.
 * A wrapper for all datatables that handles filtering.
 *
 * Handles the updating and clearing of the filter state based on changes sent
 * from the FitlerForm.
 *
 * Passes the Filter to the Datatable.
 *
 * Deprecates Filter Form.
 */
var FilterableDataTable = /*#__PURE__*/function (_Component) {
  (0, _inherits2["default"])(FilterableDataTable, _Component);
  var _super = _createSuper(FilterableDataTable);
  /**
   * @constructor
   * @param {object} props - React Component properties
   */
  function FilterableDataTable(props) {
    var _this;
    (0, _classCallCheck2["default"])(this, FilterableDataTable);
    _this = _super.call(this, props);
    _this.state = {
      filters: {}
    };
    _this.updateFilters = _this.updateFilters.bind((0, _assertThisInitialized2["default"])(_this));
    _this.clearFilters = _this.clearFilters.bind((0, _assertThisInitialized2["default"])(_this));
    _this.validFilters = _this.validFilters.bind((0, _assertThisInitialized2["default"])(_this));
    _this.addFilter = _this.addFilter.bind((0, _assertThisInitialized2["default"])(_this));
    _this.removeFilter = _this.removeFilter.bind((0, _assertThisInitialized2["default"])(_this));
    return _this;
  }

  /**
   * Updates filter state
   * @param {object} filters
   */
  (0, _createClass2["default"])(FilterableDataTable, [{
    key: "updateFilters",
    value: function updateFilters(filters) {
      this.updateQueryParams(filters);
      this.setState({
        filters: filters
      });
      if (this.props.updateFilterCallback) {
        this.props.updateFilterCallback(filters);
      }
    }

    /**
     * Updates URL Query Params
     * @param {object} filters
     */
  }, {
    key: "updateQueryParams",
    value: function updateQueryParams(filters) {
      var searchParams = new URLSearchParams();
      Object.entries(filters).forEach(function (_ref) {
        var _ref2 = (0, _slicedToArray2["default"])(_ref, 2),
          name = _ref2[0],
          filter = _ref2[1];
        if (filter.value.constructor === Array) {
          filter.value.forEach(function (v) {
            return searchParams.append(name, v);
          });
        } else {
          searchParams.set(name, filter.value);
        }
      });
      history.replaceState({}, '', "?".concat(searchParams.toString()));
    }

    /**
     * Add new filter to the filter object
     * @param {string} name
     * @param {*}      value
     * @param {boolean}   exactMatch
     */
  }, {
    key: "addFilter",
    value: function addFilter(name, value, exactMatch) {
      var filters = this.state.filters;
      filters[name] = {
        value: value,
        exactMatch: exactMatch
      };
      this.updateFilters(filters);
    }

    /**
     * Remove filter from the filter object
     * @param {string} name
     */
  }, {
    key: "removeFilter",
    value: function removeFilter(name) {
      var filters = this.state.filters;
      delete filters[name];
      this.updateFilters(filters);
    }

    /**
     * Sets Filter to empty object
     */
  }, {
    key: "clearFilters",
    value: function clearFilters() {
      this.updateFilters({});
    }

    /**
     * Returns the filter state, with filters that are
     * set to an invalid option removed from the returned
     * filters
     * @return {object}
     */
  }, {
    key: "validFilters",
    value: function validFilters() {
      var _this2 = this;
      var filters = {};
      this.props.fields.forEach(function (field) {
        if (!field.filter) {
          return;
        }
        var filtername = field.filter.name;
        var filterval = _this2.state.filters[filtername];
        if (!filterval) {
          return;
        }
        if (field.filter.type !== 'select') {
          filters[filtername] = filterval;
          return;
        }
        if (!(filterval.value in field.filter.options)) {
          return;
        }
        filters[filtername] = filterval;
      });
      return filters;
    }

    /**
     * Renders the React component.
     * @return {JSX} - React markup for the component
     */
  }, {
    key: "render",
    value: function render() {
      var filters = this.validFilters();
      var filter = /*#__PURE__*/_react["default"].createElement(_Filter["default"], {
        name: this.props.name + '_filter',
        id: this.props.name + '_filter',
        columns: this.props.columns,
        filters: filters,
        filterPresets: this.props.filterPresets,
        fields: this.props.fields,
        addFilter: this.addFilter,
        updateFilters: this.updateFilters,
        removeFilter: this.removeFilter,
        clearFilters: this.clearFilters
      });
      var progress = this.props.progress;
      var dataTable = !isNaN(progress) && progress < 100 ? /*#__PURE__*/_react["default"].createElement(_ProgressBar["default"], {
        value: progress
      }) : /*#__PURE__*/_react["default"].createElement(_DataTable["default"], {
        data: this.props.data,
        fields: this.props.fields,
        filters: filters,
        actions: this.props.actions,
        loading: this.props.loading,
        getFormattedCell: this.props.getFormattedCell,
        getMappedCell: this.props.getMappedCell,
        folder: this.props.folder,
        nullTableShow: this.props.nullTableShow,
        noDynamicTable: this.props.noDynamicTable
      });
      return /*#__PURE__*/_react["default"].createElement(_Panel["default"], {
        title: this.props.title
      }, filter, this.props.children, dataTable);
    }
  }]);
  return FilterableDataTable;
}(_react.Component);
FilterableDataTable.defaultProps = {
  columns: 3,
  noDynamicTable: false
};
FilterableDataTable.propTypes = {
  name: _propTypes["default"].string.isRequired,
  title: _propTypes["default"].string,
  data: _propTypes["default"].array.isRequired,
  filterPresets: _propTypes["default"].object,
  fields: _propTypes["default"].array.isRequired,
  columns: _propTypes["default"].number,
  getFormattedCell: _propTypes["default"].func,
  actions: _propTypes["default"].array,
  updateFilterCallback: _propTypes["default"].func,
  noDynamicTable: _propTypes["default"].bool,
  loading: _propTypes["default"].element,
  progress: _propTypes["default"].number,
  getMappedCell: _propTypes["default"].func,
  folder: _propTypes["default"].element,
  nullTableShow: _propTypes["default"].element,
  children: _propTypes["default"].node
};
var _default = exports["default"] = FilterableDataTable;

/***/ }),

/***/ "./jsx/Form.js":
/*!*********************!*\
  !*** ./jsx/Form.js ***!
  \*********************/
/***/ ((__unused_webpack_module, exports, __webpack_require__) => {

"use strict";


var _interopRequireDefault = __webpack_require__(/*! @babel/runtime/helpers/interopRequireDefault */ "./node_modules/@babel/runtime/helpers/interopRequireDefault.js");
var _typeof3 = __webpack_require__(/*! @babel/runtime/helpers/typeof */ "./node_modules/@babel/runtime/helpers/typeof.js");
Object.defineProperty(exports, "__esModule", ({
  value: true
}));
exports["default"] = exports.TimeElement = exports.TextboxElement = exports.TextareaElement = exports.TagsElement = exports.StaticElement = exports.SliderElement = exports.SelectElement = exports.SearchableDropdown = exports.RadioElement = exports.PasswordElement = exports.NumericElement = exports.LorisElement = exports.LinkElement = exports.HeaderElement = exports.FormElement = exports.FileElement = exports.FieldsetElement = exports.EmailElement = exports.DateTimeElement = exports.DateElement = exports.CheckboxElement = exports.CTA = exports.ButtonElement = void 0;
var _defineProperty2 = _interopRequireDefault(__webpack_require__(/*! @babel/runtime/helpers/defineProperty */ "./node_modules/@babel/runtime/helpers/defineProperty.js"));
var _typeof2 = _interopRequireDefault(__webpack_require__(/*! @babel/runtime/helpers/typeof */ "./node_modules/@babel/runtime/helpers/typeof.js"));
var _classCallCheck2 = _interopRequireDefault(__webpack_require__(/*! @babel/runtime/helpers/classCallCheck */ "./node_modules/@babel/runtime/helpers/classCallCheck.js"));
var _createClass2 = _interopRequireDefault(__webpack_require__(/*! @babel/runtime/helpers/createClass */ "./node_modules/@babel/runtime/helpers/createClass.js"));
var _assertThisInitialized2 = _interopRequireDefault(__webpack_require__(/*! @babel/runtime/helpers/assertThisInitialized */ "./node_modules/@babel/runtime/helpers/assertThisInitialized.js"));
var _inherits2 = _interopRequireDefault(__webpack_require__(/*! @babel/runtime/helpers/inherits */ "./node_modules/@babel/runtime/helpers/inherits.js"));
var _possibleConstructorReturn2 = _interopRequireDefault(__webpack_require__(/*! @babel/runtime/helpers/possibleConstructorReturn */ "./node_modules/@babel/runtime/helpers/possibleConstructorReturn.js"));
var _getPrototypeOf2 = _interopRequireDefault(__webpack_require__(/*! @babel/runtime/helpers/getPrototypeOf */ "./node_modules/@babel/runtime/helpers/getPrototypeOf.js"));
var _react = _interopRequireWildcard(__webpack_require__(/*! react */ "react"));
var _propTypes = _interopRequireDefault(__webpack_require__(/*! prop-types */ "./node_modules/prop-types/index.js"));
var _InputLabel = _interopRequireDefault(__webpack_require__(/*! jsx/form/InputLabel */ "./jsx/form/InputLabel.tsx"));
function _getRequireWildcardCache(e) { if ("function" != typeof WeakMap) return null; var r = new WeakMap(), t = new WeakMap(); return (_getRequireWildcardCache = function _getRequireWildcardCache(e) { return e ? t : r; })(e); }
function _interopRequireWildcard(e, r) { if (!r && e && e.__esModule) return e; if (null === e || "object" != _typeof3(e) && "function" != typeof e) return { "default": e }; var t = _getRequireWildcardCache(r); if (t && t.has(e)) return t.get(e); var n = { __proto__: null }, a = Object.defineProperty && Object.getOwnPropertyDescriptor; for (var u in e) { if ("default" !== u && {}.hasOwnProperty.call(e, u)) { var i = a ? Object.getOwnPropertyDescriptor(e, u) : null; i && (i.get || i.set) ? Object.defineProperty(n, u, i) : n[u] = e[u]; } } return n["default"] = e, t && t.set(e, n), n; }
function _createSuper(t) { var r = _isNativeReflectConstruct(); return function () { var e, o = (0, _getPrototypeOf2["default"])(t); if (r) { var s = (0, _getPrototypeOf2["default"])(this).constructor; e = Reflect.construct(o, arguments, s); } else e = o.apply(this, arguments); return (0, _possibleConstructorReturn2["default"])(this, e); }; }
function _isNativeReflectConstruct() { try { var t = !Boolean.prototype.valueOf.call(Reflect.construct(Boolean, [], function () {})); } catch (t) {} return (_isNativeReflectConstruct = function _isNativeReflectConstruct() { return !!t; })(); } /**
                                                                                                                                                                                                                                                     * This file contains React components for Loris form elements.
                                                                                                                                                                                                                                                     * @author Loris Team
                                                                                                                                                                                                                                                     * @version 1.0.0
                                                                                                                                                                                                                                                     */
/**
 * Form Component.
 * React wrapper for <form> element that accepts children react components
 *
 * The form elements can be passed in two ways:
 * 1. A `this.props.formElements` JSON object
 * 2. Form components nested directly inside <FormElement></FormElement>
 *
 * Note that if both are passed `this.props.formElements` is displayed first.
 *
 */
var FormElement = exports.FormElement = /*#__PURE__*/function (_Component) {
  (0, _inherits2["default"])(FormElement, _Component);
  var _super = _createSuper(FormElement);
  /**
   * @constructor
   * @param {object} props - React Component properties
   */
  function FormElement(props) {
    var _this;
    (0, _classCallCheck2["default"])(this, FormElement);
    _this = _super.call(this, props);
    _this.getFormElements = _this.getFormElements.bind((0, _assertThisInitialized2["default"])(_this));
    _this.handleSubmit = _this.handleSubmit.bind((0, _assertThisInitialized2["default"])(_this));
    return _this;
  }

  /**
   * Get form elements
   * @return {JSX[]} - An array of element React markup
   */
  (0, _createClass2["default"])(FormElement, [{
    key: "getFormElements",
    value: function getFormElements() {
      var formElementsHTML = [];
      var columns = this.props.columns;
      var maxColumnSize = 12;
      var colSize = Math.floor(maxColumnSize / columns);
      var colClass = 'col-xs-12 col-sm-' + colSize + ' col-md-' + colSize;

      // Render elements from JSON
      var filter = this.props.formElements;
      Object.keys(filter).forEach(function (objKey, index) {
        var userInput = this.props.onUserInput ? this.props.onUserInput : filter[objKey].onUserInput;
        var value = filter[objKey].value ? filter[objKey].value : '';
        formElementsHTML.push( /*#__PURE__*/_react["default"].createElement("div", {
          key: 'el_' + index,
          className: colClass
        }, /*#__PURE__*/_react["default"].createElement(LorisElement, {
          element: filter[objKey],
          onUserInput: userInput,
          value: value
        })));
      }.bind(this));

      // Render elements from React
      _react["default"].Children.forEach(this.props.children, function (child, key) {
        // If child is plain HTML, insert it as full size.
        // Useful for inserting <hr> to split form sections
        var elementClass = 'col-xs-12 col-sm-12 col-md-12';

        // If child is form element use appropriate size
        if ( /*#__PURE__*/_react["default"].isValidElement(child) && typeof child.type === 'function') {
          elementClass = colClass;
        }
        formElementsHTML.push( /*#__PURE__*/_react["default"].createElement("div", {
          key: 'el_child_' + key,
          className: elementClass
        }, child));
      });
      return formElementsHTML;
    }

    /**
     * Execute onSubmit
     * @param {object} e - Event
     */
  }, {
    key: "handleSubmit",
    value: function handleSubmit(e) {
      // Override default submit if property is set
      if (this.props.onSubmit) {
        e.preventDefault();
        this.props.onSubmit(e);
      }
    }

    /**
     * Renders the React component.
     * @return {JSX} - React markup for the component
     */
  }, {
    key: "render",
    value: function render() {
      var encType = this.props.fileUpload ? 'multipart/form-data' : null;

      // Generate form elements
      var formElements = this.getFormElements();

      // Flexbox is set to ensure that columns of different heights
      // are displayed proportionally on the screen
      var rowStyles = {
        display: 'flex',
        flexWrap: 'wrap'
      };
      return /*#__PURE__*/_react["default"].createElement("form", {
        name: this.props.name,
        id: this.props.id,
        className: this.props["class"],
        method: this.props.method,
        action: this.props.action,
        encType: encType,
        onSubmit: this.handleSubmit
      }, /*#__PURE__*/_react["default"].createElement("div", {
        className: "row",
        style: rowStyles
      }, formElements));
    }
  }]);
  return FormElement;
}(_react.Component);
FormElement.propTypes = {
  name: _propTypes["default"].string.isRequired,
  id: _propTypes["default"].string,
  method: _propTypes["default"].oneOf(['POST', 'GET']),
  action: _propTypes["default"].string,
  "class": _propTypes["default"].string,
  columns: _propTypes["default"].number,
  formElements: _propTypes["default"].shape({
    elementName: _propTypes["default"].shape({
      name: _propTypes["default"].string,
      type: _propTypes["default"].string
    })
  }),
  onSubmit: _propTypes["default"].func,
  onUserInput: _propTypes["default"].func,
  children: _propTypes["default"].node,
  fileUpload: _propTypes["default"].bool
};
FormElement.defaultProps = {
  name: null,
  id: null,
  method: 'POST',
  action: undefined,
  "class": 'form-horizontal',
  columns: 1,
  fileUpload: false,
  formElements: {},
  onSubmit: function onSubmit() {
    console.warn('onSubmit() callback is not set!');
  }
};

/**
 * FieldsetElement Component.
 * React wrapper for <fieldset> element that is nested inside <FormElement></FormElement>,
 * and accepts child react components. A fieldset groups related elements in a form.
 *
 * The form elements can be passed by nesting Form components directly inside <FieldsetElement></FieldsetElement>.
 *
 */
var FieldsetElement = exports.FieldsetElement = /*#__PURE__*/function (_Component2) {
  (0, _inherits2["default"])(FieldsetElement, _Component2);
  var _super2 = _createSuper(FieldsetElement);
  /**
   * @constructor
   * @param {object} props - React Component properties
   */
  function FieldsetElement(props) {
    var _this2;
    (0, _classCallCheck2["default"])(this, FieldsetElement);
    _this2 = _super2.call(this, props);
    _this2.getFormElements = _this2.getFormElements.bind((0, _assertThisInitialized2["default"])(_this2));
    return _this2;
  }

  /**
   * Get form elements
   * @return {JSX[]} - An array of element React markup
   */
  (0, _createClass2["default"])(FieldsetElement, [{
    key: "getFormElements",
    value: function getFormElements() {
      var formElementsHTML = [];
      var columns = this.props.columns;
      var maxColumnSize = 12;
      var colSize = Math.floor(maxColumnSize / columns);
      var colClass = 'col-xs-12 col-sm-' + colSize + ' col-md-' + colSize;

      // Render elements from React
      _react["default"].Children.forEach(this.props.children, function (child, key) {
        // If child is plain HTML, insert it as full size.
        // Useful for inserting <hr> to split form sections
        var elementClass = 'col-xs-12 col-sm-12 col-md-12';

        // If child is form element use appropriate size
        if ( /*#__PURE__*/_react["default"].isValidElement(child) && typeof child.type === 'function') {
          elementClass = colClass;
        }
        formElementsHTML.push( /*#__PURE__*/_react["default"].createElement("div", {
          key: 'el_child_' + key,
          className: elementClass
        }, child));
      });
      return formElementsHTML;
    }

    /**
     * Renders the React component.
     * @return {JSX} - React markup for the component
     */
  }, {
    key: "render",
    value: function render() {
      // Generate form elements
      var formElements = this.getFormElements();
      return /*#__PURE__*/_react["default"].createElement("fieldset", {
        name: this.props.name
      }, /*#__PURE__*/_react["default"].createElement("legend", null, this.props.legend), formElements);
    }
  }]);
  return FieldsetElement;
}(_react.Component);
FieldsetElement.propTypes = {
  columns: _propTypes["default"].number,
  name: _propTypes["default"].string,
  legend: _propTypes["default"].oneOfType([_propTypes["default"].string, _propTypes["default"].node]),
  children: _propTypes["default"].node
};
FieldsetElement.defaultProps = {
  columns: 1,
  legend: 'Selection Filter'
};

/**
 * Search Component
 * React wrapper for a searchable dropdown
 */
var SearchableDropdown = exports.SearchableDropdown = /*#__PURE__*/function (_Component3) {
  (0, _inherits2["default"])(SearchableDropdown, _Component3);
  var _super3 = _createSuper(SearchableDropdown);
  /**
   * @constructor
   * @param {object} props - React Component properties
   */
  function SearchableDropdown(props) {
    var _this3;
    (0, _classCallCheck2["default"])(this, SearchableDropdown);
    _this3 = _super3.call(this, props);
    _this3.state = {
      currentInput: ''
    };
    _this3.getKeyFromValue = _this3.getKeyFromValue.bind((0, _assertThisInitialized2["default"])(_this3));
    _this3.handleChange = _this3.handleChange.bind((0, _assertThisInitialized2["default"])(_this3));
    _this3.handleBlur = _this3.handleBlur.bind((0, _assertThisInitialized2["default"])(_this3));
    return _this3;
  }

  /**
   * Get key from value
   * @param {string} value
   * @return {string}
   */
  (0, _createClass2["default"])(SearchableDropdown, [{
    key: "getKeyFromValue",
    value: function getKeyFromValue(value) {
      var options = this.props.options;
      return Object.keys(options).find(function (o) {
        return options[o] === value;
      });
    }

    /**
     * Handle change
     * @param {object} e - Event
     */
  }, {
    key: "handleChange",
    value: function handleChange(e) {
      var value = this.getKeyFromValue(e.target.value);
      // if not in strict mode and key value is undefined (i.e., not in options prop)
      // set value equal to e.target.value
      if (!this.props.strictSearch && value === undefined) {
        value = e.target.value;
      }
      this.setState({
        currentInput: e.target.value
      });
      this.props.onUserInput(this.props.name, value);
    }

    /**
     * Handle blur
     * @param {object} e - Event
     */
  }, {
    key: "handleBlur",
    value: function handleBlur(e) {
      // null out entry if not present in options in strict mode
      if (this.props.strictSearch) {
        var value = e.target.value;
        var options = this.props.options;
        if (Object.values(options).indexOf(value) === -1) {
          // empty string out both the hidden value as well as the input text
          this.setState({
            currentInput: ''
          });
          this.props.onUserInput(this.props.name, '');
        }
      }
    }

    /**
     * Called by React when the component is updated.
     * @param {object} prevProps - Previous React Component properties
     */
  }, {
    key: "componentDidUpdate",
    value: function componentDidUpdate(prevProps) {
      // need to clear out currentInput for when props.value gets wiped
      // if the previous value prop contained data and the current one doesn't
      // clear currentInput
      if (prevProps.value && !this.props.value) {
        this.setState({
          currentInput: ''
        });
      }
    }

    /**
     * Renders the React component.
     * @return {JSX} - React markup for the component
     */
  }, {
    key: "render",
    value: function render() {
      var sortByValue = this.props.sortByValue;
      var options = this.props.options;
      var strictMessage = 'Entry must be included in provided list of options.';
      var errorMessage = null;
      var elementClass = 'row form-group';

      // Add error message
      if (this.props.errorMessage) {
        errorMessage = /*#__PURE__*/_react["default"].createElement("span", null, this.props.errorMessage);
        elementClass = 'row form-group has-error';
      } else if (this.props.required && this.props.value === '') {
        var msg = 'This field is required!';
        msg += this.props.strictSearch ? ' ' + strictMessage : '';
        errorMessage = /*#__PURE__*/_react["default"].createElement("span", null, msg);
        elementClass = 'row form-group has-error';
      } else if (this.props.strictSearch && this.props.value === '') {
        errorMessage = /*#__PURE__*/_react["default"].createElement("span", null, strictMessage);
        elementClass = 'row form-group has-error';
      }

      // determine value to place into text input
      var value = '';
      // use value in options if valid
      if (this.props.value !== undefined && Object.keys(options).indexOf(this.props.value) > -1) {
        value = options[this.props.value];
        // else, use input text value
      } else if (this.state.currentInput) {
        value = this.state.currentInput;
      }
      var newOptions = {};
      var optionList = [];
      if (sortByValue) {
        for (var key in options) {
          if (options.hasOwnProperty(key)) {
            newOptions[options[key]] = key;
          }
        }
        optionList = Object.keys(newOptions).sort().map(function (option) {
          return /*#__PURE__*/_react["default"].createElement("option", {
            value: option,
            key: newOptions[option]
          });
        });
      } else {
        optionList = Object.keys(options).map(function (option) {
          return /*#__PURE__*/_react["default"].createElement("option", {
            value: options[option],
            key: option
          });
        });
      }
      return /*#__PURE__*/_react["default"].createElement("div", {
        className: elementClass
      }, /*#__PURE__*/_react["default"].createElement(_InputLabel["default"], {
        label: this.props.label,
        required: this.props.required
      }), /*#__PURE__*/_react["default"].createElement("div", {
        className: "col-sm-9"
      }, /*#__PURE__*/_react["default"].createElement("input", {
        type: "text",
        name: this.props.name + '_input',
        value: value,
        id: this.props.id,
        list: this.props.name + '_list',
        className: "form-control",
        placeholder: this.props.placeHolder,
        onChange: this.handleChange,
        onBlur: this.handleBlur,
        disabled: this.props.disabled,
        required: this.props.required
      }), /*#__PURE__*/_react["default"].createElement("datalist", {
        id: this.props.name + '_list'
      }, optionList), errorMessage));
    }
  }]);
  return SearchableDropdown;
}(_react.Component);
SearchableDropdown.propTypes = {
  name: _propTypes["default"].string.isRequired,
  options: _propTypes["default"].object.isRequired,
  id: _propTypes["default"].string,
  // strictSearch, if set to true, will require that only options
  // provided in the options prop can be submitted
  strictSearch: _propTypes["default"].bool,
  label: _propTypes["default"].string,
  value: _propTypes["default"].oneOfType([_propTypes["default"].string, _propTypes["default"].array]),
  "class": _propTypes["default"].string,
  disabled: _propTypes["default"].bool,
  required: _propTypes["default"].bool,
  errorMessage: _propTypes["default"].string,
  placeHolder: _propTypes["default"].string,
  onUserInput: _propTypes["default"].func,
  sortByValue: _propTypes["default"].bool
};
SearchableDropdown.defaultProps = {
  name: '',
  options: {},
  strictSearch: true,
  label: '',
  value: undefined,
  id: null,
  "class": '',
  disabled: false,
  required: false,
  sortByValue: true,
  errorMessage: null,
  placeHolder: '',
  onUserInput: function onUserInput() {
    console.warn('onUserInput() callback is not set');
  }
};

/**
 * Select Component
 * React wrapper for a simple or 'multiple' <select> element.
 */
var SelectElement = exports.SelectElement = /*#__PURE__*/function (_Component4) {
  (0, _inherits2["default"])(SelectElement, _Component4);
  var _super4 = _createSuper(SelectElement);
  /**
   * @constructor
   * @param {object} props - React Component properties
   */
  function SelectElement(props) {
    var _this4;
    (0, _classCallCheck2["default"])(this, SelectElement);
    _this4 = _super4.call(this, props);
    _this4.handleChange = _this4.handleChange.bind((0, _assertThisInitialized2["default"])(_this4));
    return _this4;
  }

  /**
   * Call onUserInput on component rendered to select only option
   * if autoSelect prop is set to true
   */
  (0, _createClass2["default"])(SelectElement, [{
    key: "componentDidMount",
    value: function componentDidMount() {
      var optionsArray = Object.keys(this.props.options);
      if (this.props.autoSelect && optionsArray.length === 1) {
        this.props.onUserInput(this.props.name, optionsArray[0]);
      }
    }

    /**
     * On component update, if number of options dynamically
     * changes to 1, call onUserInput to select only option
     * if autoSelect prop is set to true
     * @param {object} prevProps - component props before component update
     */
  }, {
    key: "componentDidUpdate",
    value: function componentDidUpdate(prevProps) {
      var options = Object.keys(this.props.options);
      var prevOptions = Object.keys(prevProps.options);
      if (options.length !== prevOptions.length || !options.every(function (v, i) {
        return v === prevOptions[i];
      })) {
        if (this.props.autoSelect && options.length === 1) {
          this.props.onUserInput(this.props.name, options[0]);
        }
      }
    }

    /**
     * Handle change
     * @param {object} e - Event
     */
  }, {
    key: "handleChange",
    value: function handleChange(e) {
      var value = null;
      var options = e.target.options;
      var numOfOptions = options.length;

      // Multiple values
      if (this.props.multiple) {
        value = [];
        for (var i = 0, l = numOfOptions; i < l; i++) {
          if (options[i].selected) {
            value.push(options[i].value);
          }
        }
      } else {
        value = e.target.value;
      }
      this.props.onUserInput(this.props.name, value);
    }

    /**
     * Renders the React component.
     * @return {JSX} - React markup for the component
     */
  }, {
    key: "render",
    value: function render() {
      var sortByValue = this.props.sortByValue;
      var options = this.props.options;
      var disabledOptions = this.props.disabledOptions;
      var errorMessage = null;
      var emptyOptionHTML = null;
      var elementClass = this.props.noMargins ? '' : 'row form-group';

      // Add empty option
      if (this.props.emptyOption) {
        emptyOptionHTML = /*#__PURE__*/_react["default"].createElement("option", null);
      }

      // Add error message
      if (this.props.errorMessage || this.props.required && this.props.value === '') {
        errorMessage = /*#__PURE__*/_react["default"].createElement("span", null, this.props.errorMessage);
        elementClass = elementClass + ' has-error';
      }
      var newOptions = {};
      var optionList = [];
      if (sortByValue) {
        for (var key in options) {
          if (options.hasOwnProperty(key)) {
            newOptions[options[key]] = key;
          }
        }
        optionList = Object.keys(newOptions).sort().map(function (option) {
          var isDisabled = (newOptions[option] in disabledOptions);
          return /*#__PURE__*/_react["default"].createElement("option", {
            value: newOptions[option],
            key: newOptions[option],
            disabled: isDisabled
          }, option);
        });
      } else {
        optionList = Object.keys(options).map(function (option) {
          var isDisabled = (option in disabledOptions);
          return /*#__PURE__*/_react["default"].createElement("option", {
            value: option,
            key: option,
            disabled: isDisabled
          }, options[option]);
        });
      }
      if (this.props.placeholder !== '') {
        optionList.unshift( /*#__PURE__*/_react["default"].createElement("option", {
          value: ''
        }, this.props.placeholder));
      }

      // Default to empty string for regular select and to empty array for 'multiple' select
      var value = this.props.value || (this.props.multiple ? [] : '');

      // Label prop needs to be provided to render label
      // (including empty label i.e. <SelectElement label='' />)
      // and retain formatting. If label prop is not provided at all, the input
      // element will take up the whole row.
      var inputClass = this.props.noMargins ? '' : 'col-sm-12';
      if (this.props.label) {
        inputClass = 'col-sm-9';
      }
      return /*#__PURE__*/_react["default"].createElement("div", {
        className: elementClass
      }, this.props.label && /*#__PURE__*/_react["default"].createElement(_InputLabel["default"], {
        label: this.props.label,
        required: this.props.required
      }), /*#__PURE__*/_react["default"].createElement("div", {
        className: inputClass
      }, /*#__PURE__*/_react["default"].createElement("select", {
        name: this.props.name,
        multiple: this.props.multiple,
        className: "form-control",
        id: this.props.id,
        value: value,
        onChange: this.handleChange,
        required: this.props.required,
        disabled: this.props.disabled
      }, emptyOptionHTML, optionList), errorMessage));
    }
  }]);
  return SelectElement;
}(_react.Component);
SelectElement.propTypes = {
  name: _propTypes["default"].string.isRequired,
  options: _propTypes["default"].object.isRequired,
  disabledOptions: _propTypes["default"].object,
  label: _propTypes["default"].string,
  value: _propTypes["default"].oneOfType([_propTypes["default"].string, _propTypes["default"].array]),
  id: _propTypes["default"].string,
  multiple: _propTypes["default"].bool,
  disabled: _propTypes["default"].bool,
  required: _propTypes["default"].bool,
  emptyOption: _propTypes["default"].bool,
  autoSelect: _propTypes["default"].bool,
  errorMessage: _propTypes["default"].string,
  onUserInput: _propTypes["default"].func,
  noMargins: _propTypes["default"].bool,
  placeholder: _propTypes["default"].string,
  sortByValue: _propTypes["default"].bool
};
SelectElement.defaultProps = {
  name: '',
  options: {},
  disabledOptions: {},
  value: undefined,
  id: null,
  multiple: false,
  disabled: false,
  required: false,
  sortByValue: true,
  emptyOption: true,
  autoSelect: true,
  errorMessage: null,
  onUserInput: function onUserInput() {
    console.warn('onUserInput() callback is not set');
  },
  noMargins: false,
  placeholder: ''
};

/**
 * Tags Component
 * Allows for multiple values to be entered for a single field
 *
 * Comes in 3 flavors:
 * 1: If options are passed and useSearch = true
 *    input field is rendered as a searchable dropdown
 * 2: If only options are passed, input is rendered as
 *    a normal dropdown select
 * 3: Without options, input is a normal, free text input
 */
var TagsElement = exports.TagsElement = /*#__PURE__*/function (_Component5) {
  (0, _inherits2["default"])(TagsElement, _Component5);
  var _super5 = _createSuper(TagsElement);
  /**
   * @constructor
   * @param {object} props - React Component properties
   */
  function TagsElement(props) {
    var _this5;
    (0, _classCallCheck2["default"])(this, TagsElement);
    _this5 = _super5.call(this, props);
    _this5.handleChange = _this5.handleChange.bind((0, _assertThisInitialized2["default"])(_this5));
    _this5.handleKeyPress = _this5.handleKeyPress.bind((0, _assertThisInitialized2["default"])(_this5));
    _this5.handleAdd = _this5.handleAdd.bind((0, _assertThisInitialized2["default"])(_this5));
    _this5.handleRemove = _this5.handleRemove.bind((0, _assertThisInitialized2["default"])(_this5));
    _this5.getKeyFromValue = _this5.getKeyFromValue.bind((0, _assertThisInitialized2["default"])(_this5));
    _this5.canAddItem = _this5.canAddItem.bind((0, _assertThisInitialized2["default"])(_this5));
    return _this5;
  }

  /**
   * Handle change
   * @param {object} e - Event
   */
  (0, _createClass2["default"])(TagsElement, [{
    key: "handleChange",
    value: function handleChange(e) {
      // pendingValKey is the placeholder variable for temporarily storing
      // typed or selected items before adding them to the Tags
      this.props.onUserInput(this.props.pendingValKey, e.target.value);
    }

    /**
     * Handle key press
     * @param {object} e - Event
     */
  }, {
    key: "handleKeyPress",
    value: function handleKeyPress(e) {
      // also add tags if enter key is hit within input field
      if (e.keyCode === 13 || e.which === 13) {
        e.preventDefault();
        this.handleAdd();
      }
    }

    /**
     * Handle add
     */
  }, {
    key: "handleAdd",
    value: function handleAdd() {
      var options = this.props.options;
      var value = this.props.value;
      // if using a datalist (search), set value to be the key in options
      if (this.props.useSearch && Object.values(options).indexOf(value) > -1) {
        value = this.getKeyFromValue(value);
      }
      if (this.canAddItem(value)) {
        // send pendingValKey as an argument in order to null out entered item
        this.props.onUserAdd(this.props.name, value, this.props.pendingValKey);
      }
    }

    /**
     * Handle remove
     * @param {object} e -  Event
     */
  }, {
    key: "handleRemove",
    value: function handleRemove(e) {
      var value = e.target.getAttribute('data-item');
      this.props.onUserRemove(this.props.name, value);
    }

    /**
     * Get key from value
     * @param {string} value
     * @return {string}
     */
  }, {
    key: "getKeyFromValue",
    value: function getKeyFromValue(value) {
      var options = this.props.options;
      return Object.keys(options).find(function (o) {
        return options[o] === value;
      });
    }

    /**
     * Helper function to detect
     * if item should be added to Tags
     * @param {string} value
     * @return {boolean}
     */
  }, {
    key: "canAddItem",
    value: function canAddItem(value) {
      var result = true;
      // reject empty values
      if (!value) {
        result = false;
        // reject if allowDupl is false and item is already in array
      } else if (!this.props.allowDupl && this.props.items.indexOf(value) > -1) {
        result = false;
        // reject if using a strict datalist and value is not in options
      } else if (this.props.useSearch && this.props.strictSearch && Object.keys(this.props.options).indexOf(value) === -1) {
        result = false;
      }
      return result;
    }

    /**
     * Renders the React component.
     * @return {JSX} - React markup for the component
     */
  }, {
    key: "render",
    value: function render() {
      var _this6 = this;
      var emptyOptionHTML = null;
      var errorMessage = null;
      var elementClass = 'row form-group';

      // Add empty option
      if (this.props.emptyOption) {
        emptyOptionHTML = /*#__PURE__*/_react["default"].createElement("option", null);
      }
      if (this.props.errorMessage) {
        errorMessage = /*#__PURE__*/_react["default"].createElement("span", null, this.props.errorMessage);
        elementClass = 'row form-group has-error';
      }
      var input;
      var options = this.props.options;
      // if options are given and useSearch is specified
      if (Object.keys(options).length > 0 && this.props.useSearch) {
        input = /*#__PURE__*/_react["default"].createElement("div", null, /*#__PURE__*/_react["default"].createElement("input", {
          type: "text",
          name: this.props.name,
          id: this.props.id,
          list: this.props.id + '_list',
          className: "form-control",
          value: this.props.value || '',
          disabled: this.props.disabled,
          onChange: this.handleChange,
          onKeyPress: this.handleKeyPress
        }), /*#__PURE__*/_react["default"].createElement("datalist", {
          id: this.props.id + '_list'
        }, Object.keys(options).map(function (option) {
          return /*#__PURE__*/_react["default"].createElement("option", {
            value: options[option],
            key: option
          }, options[option]);
        })));
        // if options are present but useSearch is false, use normal dropdown
      } else if (Object.keys(options).length > 0) {
        input = /*#__PURE__*/_react["default"].createElement("select", {
          name: this.props.name,
          className: "form-control",
          id: this.props.id,
          value: this.props.value,
          disabled: this.props.disabled,
          onChange: this.handleChange,
          onKeyPress: this.handleKeyPress
        }, emptyOptionHTML, Object.keys(options).map(function (option) {
          return /*#__PURE__*/_react["default"].createElement("option", {
            value: option,
            key: option
          }, options[option]);
        }));
        // else, use a text input by default
      } else {
        input = /*#__PURE__*/_react["default"].createElement("input", {
          type: "text",
          name: this.props.name,
          id: this.props.id,
          className: "form-control",
          value: this.props.value || '',
          disabled: this.props.disabled,
          onChange: this.handleChange,
          onKeyPress: this.handleKeyPress
        });
      }

      // iterate through added Tags items and render them
      // with deletion button
      var items = this.props.items.map(function (item) {
        var itmTxt;
        // in event that the passed item is a key of options,
        // render option value
        if (Object.keys(options).length > 0 && options[item] !== undefined) {
          itmTxt = options[item];
          // otherwise just render item as is
        } else {
          itmTxt = item;
        }
        return /*#__PURE__*/_react["default"].createElement("button", {
          className: "btn btn-info btn-inline",
          type: "button",
          onClick: _this6.handleRemove,
          "data-item": item,
          key: item
        }, itmTxt, "\xA0", /*#__PURE__*/_react["default"].createElement("span", {
          className: "glyphicon glyphicon-remove",
          "data-item": item
        }));
      });
      return /*#__PURE__*/_react["default"].createElement("div", {
        className: elementClass
      }, /*#__PURE__*/_react["default"].createElement(_InputLabel["default"], {
        label: this.props.label,
        required: this.props.required
      }), /*#__PURE__*/_react["default"].createElement("div", {
        className: "col-sm-9"
      }, items, input, errorMessage, /*#__PURE__*/_react["default"].createElement("button", {
        className: "btn btn-success btn-add-tag",
        id: this.props.id + 'Add',
        type: "button",
        onClick: this.handleAdd
      }, /*#__PURE__*/_react["default"].createElement("span", {
        className: "glyphicon glyphicon-plus"
      }), this.props.btnLabel)));
    }
  }]);
  return TagsElement;
}(_react.Component);
TagsElement.propTypes = {
  name: _propTypes["default"].string.isRequired,
  id: _propTypes["default"].string.isRequired,
  pendingValKey: _propTypes["default"].string.isRequired,
  options: _propTypes["default"].object,
  items: _propTypes["default"].array,
  label: _propTypes["default"].string,
  value: _propTypes["default"].string,
  "class": _propTypes["default"].string,
  multiple: _propTypes["default"].bool,
  required: _propTypes["default"].bool,
  disabled: _propTypes["default"].bool,
  emptyOption: _propTypes["default"].bool,
  errorMessage: _propTypes["default"].string,
  btnLabel: _propTypes["default"].string,
  allowDupl: _propTypes["default"].bool,
  useSearch: _propTypes["default"].bool,
  strictSearch: _propTypes["default"].bool,
  onUserInput: _propTypes["default"].func,
  onUserAdd: _propTypes["default"].func,
  onUserRemove: _propTypes["default"].func
};
TagsElement.defaultProps = {
  name: '',
  options: {},
  items: [],
  label: '',
  value: undefined,
  id: null,
  "class": '',
  required: false,
  disabled: false,
  emptyOption: true,
  allowDupl: false,
  useSearch: false,
  strictSearch: false,
  // only accept items specified in options
  errorMessage: null,
  pendingValKey: '',
  btnLabel: 'Add Tag',
  onUserInput: function onUserInput() {
    console.warn('onUserInput() callback is not set');
  },
  onUserAdd: function onUserAdd() {
    console.warn('onUserAdd() callback is not set');
  },
  onUserRemove: function onUserRemove() {
    console.warn('onUserRemove() callback is not set');
  }
};

/**
 * Textarea Component
 * React wrapper for a <textarea> element.
 */
var TextareaElement = exports.TextareaElement = /*#__PURE__*/function (_Component6) {
  (0, _inherits2["default"])(TextareaElement, _Component6);
  var _super6 = _createSuper(TextareaElement);
  /**
   * @constructor
   * @param {object} props - React Component properties
   */
  function TextareaElement(props) {
    var _this7;
    (0, _classCallCheck2["default"])(this, TextareaElement);
    _this7 = _super6.call(this, props);
    _this7.handleChange = _this7.handleChange.bind((0, _assertThisInitialized2["default"])(_this7));
    return _this7;
  }

  /**
   * Handle change
   * @param {object} e - Event
   */
  (0, _createClass2["default"])(TextareaElement, [{
    key: "handleChange",
    value: function handleChange(e) {
      this.props.onUserInput(this.props.name, e.target.value);
    }

    /**
     * Renders the React component.
     * @return {JSX} - React markup for the component
     */
  }, {
    key: "render",
    value: function render() {
      return /*#__PURE__*/_react["default"].createElement("div", {
        className: "row form-group"
      }, /*#__PURE__*/_react["default"].createElement(_InputLabel["default"], {
        label: this.props.label,
        required: this.props.required
      }), /*#__PURE__*/_react["default"].createElement("div", {
        className: "col-sm-9"
      }, /*#__PURE__*/_react["default"].createElement("textarea", {
        cols: this.props.cols,
        rows: this.props.rows,
        className: "form-control",
        name: this.props.name,
        id: this.props.id,
        value: this.props.value || '',
        placeholder: this.props.placeholder,
        required: this.props.required,
        disabled: this.props.disabled,
        onChange: this.handleChange
      })));
    }
  }]);
  return TextareaElement;
}(_react.Component);
TextareaElement.propTypes = {
  name: _propTypes["default"].string.isRequired,
  label: _propTypes["default"].string,
  value: _propTypes["default"].string,
  placeholder: _propTypes["default"].string,
  id: _propTypes["default"].string,
  disabled: _propTypes["default"].bool,
  required: _propTypes["default"].bool,
  rows: _propTypes["default"].number,
  cols: _propTypes["default"].number,
  onUserInput: _propTypes["default"].func
};
TextareaElement.defaultProps = {
  name: '',
  label: '',
  value: '',
  placeholder: '',
  id: null,
  disabled: false,
  required: false,
  rows: 4,
  cols: 25,
  onUserInput: function onUserInput() {
    console.warn('onUserInput() callback is not set');
  }
};

/**
 * Textbox Component
 * React wrapper for a <input type="text"> element.
 */
var TextboxElement = exports.TextboxElement = /*#__PURE__*/function (_Component7) {
  (0, _inherits2["default"])(TextboxElement, _Component7);
  var _super7 = _createSuper(TextboxElement);
  /**
   * @constructor
   * @param {object} props - React Component properties
   */
  function TextboxElement(props) {
    var _this8;
    (0, _classCallCheck2["default"])(this, TextboxElement);
    _this8 = _super7.call(this, props);
    _this8.handleChange = _this8.handleChange.bind((0, _assertThisInitialized2["default"])(_this8));
    _this8.handleBlur = _this8.handleBlur.bind((0, _assertThisInitialized2["default"])(_this8));
    return _this8;
  }

  /**
   * Handle change
   * @param {object} e - Event
   */
  (0, _createClass2["default"])(TextboxElement, [{
    key: "handleChange",
    value: function handleChange(e) {
      this.props.onUserInput(this.props.name, e.target.value, e.target.id, 'textbox');
    }

    /**
     * Handle blur
     * @param {object} e - Event
     */
  }, {
    key: "handleBlur",
    value: function handleBlur(e) {
      this.props.onUserBlur(this.props.name, e.target.value);
    }

    /**
     * Renders the React component.
     * @return {JSX} - React markup for the component
     */
  }, {
    key: "render",
    value: function render() {
      var errorMessage = null;
      var elementClass = 'row form-group';

      // Add error message
      if (this.props.errorMessage) {
        errorMessage = /*#__PURE__*/_react["default"].createElement("span", null, this.props.errorMessage);
        elementClass = 'row form-group has-error';
      }

      // Label prop needs to be provided to render label
      // (including empty label i.e. <TextboxElement label='' />)
      // and retain formatting. If label prop is not provided at all, the input
      // element will take up the whole row.
      var inputClass = this.props["class"];
      if (this.props.label || this.props.label == '') {
        inputClass = 'col-sm-9';
      }
      return /*#__PURE__*/_react["default"].createElement("div", {
        className: elementClass
      }, (this.props.label || this.props.label == '') && /*#__PURE__*/_react["default"].createElement(_InputLabel["default"], {
        label: this.props.label,
        required: this.props.required
      }), /*#__PURE__*/_react["default"].createElement("div", {
        className: inputClass
      }, /*#__PURE__*/_react["default"].createElement("input", {
        type: "text",
        className: "form-control",
        name: this.props.name,
        id: this.props.id,
        value: this.props.value || '',
        required: this.props.required,
        disabled: this.props.disabled,
        onChange: this.handleChange,
        onBlur: this.handleBlur,
        autoComplete: this.props.autoComplete,
        placeholder: this.props.placeholder
      }), errorMessage));
    }
  }]);
  return TextboxElement;
}(_react.Component);
TextboxElement.propTypes = {
  name: _propTypes["default"].string.isRequired,
  label: _propTypes["default"].string,
  value: _propTypes["default"].string,
  id: _propTypes["default"].string,
  "class": _propTypes["default"].string,
  placeholder: _propTypes["default"].string,
  autoComplete: _propTypes["default"].string,
  disabled: _propTypes["default"].bool,
  required: _propTypes["default"].bool,
  errorMessage: _propTypes["default"].string,
  onUserInput: _propTypes["default"].func,
  onUserBlur: _propTypes["default"].func
};
TextboxElement.defaultProps = {
  name: '',
  value: '',
  id: null,
  "class": 'col-sm-12',
  placeholder: '',
  autoComplete: null,
  disabled: false,
  required: false,
  errorMessage: null,
  onUserInput: function onUserInput() {
    console.warn('onUserInput() callback is not set');
  },
  onUserBlur: function onUserBlur() {}
};

/**
 * EmailElement Component
 * React wrapper for a <input type="email"> element.
 */
var EmailElement = exports.EmailElement = /*#__PURE__*/function (_Component8) {
  (0, _inherits2["default"])(EmailElement, _Component8);
  var _super8 = _createSuper(EmailElement);
  /**
   * @constructor
   * @param {object} props - React Component properties
   */
  function EmailElement(props) {
    var _this9;
    (0, _classCallCheck2["default"])(this, EmailElement);
    _this9 = _super8.call(this, props);
    _this9.handleChange = _this9.handleChange.bind((0, _assertThisInitialized2["default"])(_this9));
    _this9.handleBlur = _this9.handleBlur.bind((0, _assertThisInitialized2["default"])(_this9));
    return _this9;
  }

  /**
   * Handle change
   * @param {object} e - Event
   */
  (0, _createClass2["default"])(EmailElement, [{
    key: "handleChange",
    value: function handleChange(e) {
      this.props.onUserInput(this.props.name, e.target.value, e.target.id, 'textbox');
    }

    /**
     * Handle blur
     * @param {object} e - Event
     */
  }, {
    key: "handleBlur",
    value: function handleBlur(e) {
      this.props.onUserBlur(this.props.name, e.target.value);
    }

    /**
     * Renders the React component.
     * @return {JSX} - React markup for the component
     */
  }, {
    key: "render",
    value: function render() {
      var errorMessage = null;
      var elementClass = 'row form-group';

      // Add error message
      if (this.props.errorMessage) {
        errorMessage = /*#__PURE__*/_react["default"].createElement("span", null, this.props.errorMessage);
        elementClass = 'row form-group has-error';
      }

      // Label prop needs to be provided to render label
      // (including empty label i.e. <TextboxElement label='' />)
      // and retain formatting. If label prop is not provided at all, the input
      // element will take up the whole row.
      var inputClass = this.props["class"];
      if (this.props.label || this.props.label == '') {
        inputClass = 'col-sm-9';
      }
      return /*#__PURE__*/_react["default"].createElement("div", {
        className: elementClass
      }, (this.props.label || this.props.label == '') && /*#__PURE__*/_react["default"].createElement(_InputLabel["default"], {
        label: this.props.label,
        required: this.props.required
      }), /*#__PURE__*/_react["default"].createElement("div", {
        className: inputClass
      }, /*#__PURE__*/_react["default"].createElement("input", {
        type: "email",
        title: "Please provide a valid email address!",
        className: "form-control",
        name: this.props.name,
        id: this.props.id,
        value: this.props.value || '',
        required: this.props.required,
        disabled: this.props.disabled,
        onChange: this.handleChange,
        onBlur: this.handleBlur,
        autoComplete: this.props.autoComplete,
        placeholder: this.props.placeholder
      }), errorMessage));
    }
  }]);
  return EmailElement;
}(_react.Component);
EmailElement.propTypes = {
  name: _propTypes["default"].string.isRequired,
  label: _propTypes["default"].string,
  value: _propTypes["default"].string,
  id: _propTypes["default"].string,
  "class": _propTypes["default"].string,
  placeholder: _propTypes["default"].string,
  autoComplete: _propTypes["default"].string,
  disabled: _propTypes["default"].bool,
  required: _propTypes["default"].bool,
  errorMessage: _propTypes["default"].string,
  onUserInput: _propTypes["default"].func,
  onUserBlur: _propTypes["default"].func
};
EmailElement.defaultProps = {
  name: '',
  value: '',
  id: null,
  "class": 'col-sm-12',
  placeholder: '',
  autoComplete: null,
  disabled: false,
  required: false,
  errorMessage: null,
  onUserInput: function onUserInput() {
    console.warn('onUserInput() callback is not set');
  },
  onUserBlur: function onUserBlur() {}
};

/**
 * Password Component
 * React wrapper for a <input type="password"> element.
 */
var PasswordElement = exports.PasswordElement = /*#__PURE__*/function (_Component9) {
  (0, _inherits2["default"])(PasswordElement, _Component9);
  var _super9 = _createSuper(PasswordElement);
  /**
   * @constructor
   * @param {object} props - React Component properties
   */
  function PasswordElement(props) {
    var _this10;
    (0, _classCallCheck2["default"])(this, PasswordElement);
    _this10 = _super9.call(this, props);
    _this10.state = {
      on: {
        // password is visible.
        icon: 'close',
        type: 'text'
      },
      off: {
        // password hidden.
        icon: 'open',
        type: 'password'
      },
      active: false // is password visible.
    };

    _this10.handleChange = _this10.handleChange.bind((0, _assertThisInitialized2["default"])(_this10));
    _this10.handleBlur = _this10.handleBlur.bind((0, _assertThisInitialized2["default"])(_this10));
    // callback called to toogle the visibility
    _this10.toggleVisibility = _this10.toggleVisibility.bind((0, _assertThisInitialized2["default"])(_this10));
    return _this10;
  }

  /**
   * Handle change
   * @param {object} e - Event
   */
  (0, _createClass2["default"])(PasswordElement, [{
    key: "handleChange",
    value: function handleChange(e) {
      this.props.onUserInput(this.props.name, e.target.value, e.target.id, this.state.active ? this.state.on.type : this.state.off.type);
    }

    /**
     * Handle blur
     * @param {object} e - Event
     */
  }, {
    key: "handleBlur",
    value: function handleBlur(e) {
      this.props.onUserBlur(this.props.name, e.target.value);
    }

    /**
     * Toggle visibility
     *
     */
  }, {
    key: "toggleVisibility",
    value: function toggleVisibility() {
      this.setState({
        active: !this.state.active
      });
    }

    /**
     * Renders the React component.
     * @return {JSX} - React markup for the component
     */
  }, {
    key: "render",
    value: function render() {
      var errorMessage = null;
      var elementClass = 'row form-group';

      // Add error message
      if (this.props.errorMessage) {
        errorMessage = /*#__PURE__*/_react["default"].createElement("span", null, this.props.errorMessage);
        elementClass = 'row form-group has-error';
      }
      var passwordDisplayType = this.state.active ? this.state.on.type : this.state.off.type;
      var passwordDisplayIcon = this.state.active ? this.state.on.icon : this.state.off.icon;
      return /*#__PURE__*/_react["default"].createElement("div", {
        className: elementClass
      }, this.props.label && /*#__PURE__*/_react["default"].createElement(_InputLabel["default"], {
        label: this.props.label,
        required: this.props.required
      }), /*#__PURE__*/_react["default"].createElement("div", {
        className: this.props["class"]
      }, /*#__PURE__*/_react["default"].createElement("input", {
        type: passwordDisplayType,
        className: "form-control",
        name: this.props.name,
        id: this.props.id,
        value: this.props.value || '',
        required: this.props.required,
        disabled: this.props.disabled,
        onChange: this.handleChange,
        onBlur: this.handleBlur,
        autoComplete: this.props.autoComplete,
        placeholder: this.props.placeholder
      }), /*#__PURE__*/_react["default"].createElement("span", {
        className: 'form-control-feedback glyphicon glyphicon-eye-' + passwordDisplayIcon,
        style: {
          marginRight: '15px'
        },
        onClick: this.toggleVisibility
      }), errorMessage));
    }
  }]);
  return PasswordElement;
}(_react.Component);
PasswordElement.propTypes = {
  name: _propTypes["default"].string.isRequired,
  label: _propTypes["default"].string,
  value: _propTypes["default"].string,
  "class": _propTypes["default"].string,
  type: _propTypes["default"].string,
  placeholder: _propTypes["default"].string,
  id: _propTypes["default"].string,
  disabled: _propTypes["default"].bool,
  required: _propTypes["default"].bool,
  autoComplete: _propTypes["default"].string,
  errorMessage: _propTypes["default"].string,
  onUserInput: _propTypes["default"].func,
  onUserBlur: _propTypes["default"].func
};
PasswordElement.defaultProps = {
  id: null,
  label: '',
  value: '',
  type: 'text',
  "class": 'col-sm-9',
  placeholder: '',
  disabled: false,
  required: false,
  autoComplete: null,
  errorMessage: null,
  onUserInput: function onUserInput() {
    console.warn('onUserInput() callback is not set');
  },
  onUserBlur: function onUserBlur() {}
};

/**
 * Date Component
 * React wrapper for a <input type="date"> element.
 */
var DateElement = exports.DateElement = /*#__PURE__*/function (_Component10) {
  (0, _inherits2["default"])(DateElement, _Component10);
  var _super10 = _createSuper(DateElement);
  /**
   * @constructor
   * @param {object} props - React Component properties
   */
  function DateElement(props) {
    var _this11;
    (0, _classCallCheck2["default"])(this, DateElement);
    _this11 = _super10.call(this, props);
    _this11.handleChange = _this11.handleChange.bind((0, _assertThisInitialized2["default"])(_this11));
    return _this11;
  }

  /**
   * Handle change
   * @param {object} e - Event
   */
  (0, _createClass2["default"])(DateElement, [{
    key: "handleChange",
    value: function handleChange(e) {
      this.props.onUserInput(this.props.name, e.target.value, e.target.id, 'date');
    }

    /**
     * Renders the React component.
     * @return {JSX} - React markup for the component
     */
  }, {
    key: "render",
    value: function render() {
      var errorMessage = null;
      var elementClass = 'row form-group';

      // Add error message
      if (this.props.errorMessage || this.props.required && this.props.value === '') {
        errorMessage = /*#__PURE__*/_react["default"].createElement("span", null, this.props.errorMessage);
        elementClass = elementClass + ' has-error';
      }

      // Check if props minYear and maxYear are valid values if supplied
      var minYear = this.props.minYear;
      var maxYear = this.props.maxYear;
      if (this.props.minYear === '' || this.props.minYear === null) {
        minYear = '1000';
      }
      if (this.props.maxYear === '' || this.props.maxYear === null) {
        maxYear = '9999';
      }
      var currentDate = new Date();
      // The added '0' is needed because getmonth and getdate return
      // values needed to be padded before saving.
      // padStart adds as many possible zeros while keeping the string
      // at a length of 2 for the following code.
      var currentDay = "".concat(currentDate.getDate()).padStart(2, '0');
      var currentMonth = "".concat(currentDate.getMonth() + 1).padStart(2, '0');

      // Handle date format
      var format = this.props.dateFormat;
      var inputType = 'date';
      var minFullDate = minYear + '-01-01';
      var maxFullDate = maxYear + '-' + currentMonth + '-' + currentDay;
      if (!format.match(/d/i)) {
        inputType = 'month';
        minFullDate = minYear + '-01';
        maxFullDate = maxYear + '-' + currentMonth;
      }
      var wrapperClass = this.props.label ? 'col-sm-9' : 'col-sm-12';
      return /*#__PURE__*/_react["default"].createElement("div", {
        className: elementClass
      }, this.props.label && /*#__PURE__*/_react["default"].createElement(_InputLabel["default"], {
        label: this.props.label,
        required: this.props.required
      }), /*#__PURE__*/_react["default"].createElement("div", {
        className: wrapperClass
      }, /*#__PURE__*/_react["default"].createElement("input", {
        type: inputType,
        className: "form-control",
        name: this.props.name,
        id: this.props.id,
        min: minFullDate,
        max: maxFullDate,
        onChange: this.handleChange,
        value: this.props.value || '',
        required: this.props.required,
        disabled: this.props.disabled
      }), errorMessage));
    }
  }]);
  return DateElement;
}(_react.Component);
DateElement.propTypes = {
  name: _propTypes["default"].string.isRequired,
  label: _propTypes["default"].string,
  value: _propTypes["default"].string,
  id: _propTypes["default"].string,
  maxYear: _propTypes["default"].oneOfType([_propTypes["default"].string, _propTypes["default"].number]),
  minYear: _propTypes["default"].oneOfType([_propTypes["default"].string, _propTypes["default"].number]),
  dateFormat: _propTypes["default"].string,
  disabled: _propTypes["default"].bool,
  required: _propTypes["default"].bool,
  errorMessage: _propTypes["default"].string,
  onUserInput: _propTypes["default"].func
};
DateElement.defaultProps = {
  name: '',
  label: '',
  value: undefined,
  id: null,
  maxYear: '9999',
  minYear: '1000',
  dateFormat: 'YMd',
  disabled: false,
  required: false,
  errorMessage: null,
  onUserInput: function onUserInput() {
    console.warn('onUserInput() callback is not set');
  }
};

/**
 * Time Component
 * React wrapper for a <input type="time"> element.
 */
var TimeElement = exports.TimeElement = /*#__PURE__*/function (_Component11) {
  (0, _inherits2["default"])(TimeElement, _Component11);
  var _super11 = _createSuper(TimeElement);
  /**
   * @constructor
   * @param {object} props - React Component properties
   */
  function TimeElement(props) {
    var _this12;
    (0, _classCallCheck2["default"])(this, TimeElement);
    _this12 = _super11.call(this, props);
    _this12.handleChange = _this12.handleChange.bind((0, _assertThisInitialized2["default"])(_this12));
    return _this12;
  }

  /**
   * Handle change
   * @param {object} e - Event
   */
  (0, _createClass2["default"])(TimeElement, [{
    key: "handleChange",
    value: function handleChange(e) {
      this.props.onUserInput(this.props.name, e.target.value);
    }

    /**
     * Renders the React component.
     * @return {JSX} - React markup for the component
     */
  }, {
    key: "render",
    value: function render() {
      var wrapperClass = this.props.label ? 'col-sm-9' : 'col-sm-12';
      return /*#__PURE__*/_react["default"].createElement("div", {
        className: "row form-group"
      }, this.props.label && /*#__PURE__*/_react["default"].createElement(_InputLabel["default"], {
        label: this.props.label,
        required: this.props.required
      }), /*#__PURE__*/_react["default"].createElement("div", {
        className: wrapperClass
      }, /*#__PURE__*/_react["default"].createElement("input", {
        type: "time",
        className: "form-control",
        name: this.props.name,
        id: this.props.id,
        onChange: this.handleChange,
        value: this.props.value || '',
        required: this.props.required,
        disabled: this.props.disabled,
        pattern: "([0-1][0-9]|2[0-4]|[1-9]):([0-5][0-9])(:([0-5][0-9]))?",
        title: 'Input must be in one of the following formats: ' + 'HH:MM or HH:MM:SS'
      })));
    }
  }]);
  return TimeElement;
}(_react.Component);
TimeElement.propTypes = {
  name: _propTypes["default"].string.isRequired,
  label: _propTypes["default"].string,
  value: _propTypes["default"].string,
  id: _propTypes["default"].string,
  disabled: _propTypes["default"].bool,
  required: _propTypes["default"].bool,
  onUserInput: _propTypes["default"].func
};
TimeElement.defaultProps = {
  name: '',
  label: '',
  value: '',
  id: '',
  disabled: false,
  required: false,
  onUserInput: function onUserInput() {
    console.warn('onUserInput() callback is not set');
  }
};

/**
 * DateTime Component
 * React wrapper for a <input type="datetime-local"> element.
 */
var DateTimeElement = exports.DateTimeElement = /*#__PURE__*/function (_Component12) {
  (0, _inherits2["default"])(DateTimeElement, _Component12);
  var _super12 = _createSuper(DateTimeElement);
  /**
   * @constructor
   * @param {object} props - React Component properties
   */
  function DateTimeElement(props) {
    var _this13;
    (0, _classCallCheck2["default"])(this, DateTimeElement);
    _this13 = _super12.call(this, props);
    _this13.handleChange = _this13.handleChange.bind((0, _assertThisInitialized2["default"])(_this13));
    return _this13;
  }

  /**
   * Handle change
   * @param {object} e - Event
   */
  (0, _createClass2["default"])(DateTimeElement, [{
    key: "handleChange",
    value: function handleChange(e) {
      this.props.onUserInput(this.props.name, e.target.value);
    }

    /**
     * Renders the React component.
     * @return {JSX} - React markup for the component
     */
  }, {
    key: "render",
    value: function render() {
      var wrapperClass = this.props.label ? 'col-sm-9' : 'col-sm-12';
      return /*#__PURE__*/_react["default"].createElement("div", {
        className: "row form-group"
      }, this.props.label && /*#__PURE__*/_react["default"].createElement(_InputLabel["default"], {
        label: this.props.label,
        required: this.props.required
      }), /*#__PURE__*/_react["default"].createElement("div", {
        className: wrapperClass
      }, /*#__PURE__*/_react["default"].createElement("input", {
        type: "datetime-local",
        className: "form-control",
        name: this.props.name,
        id: this.props.id,
        onChange: this.handleChange,
        value: this.props.value || '',
        required: this.props.required,
        disabled: this.props.disabled,
        pattern: "[0-9]{4}-[0-9]{2}-[0-9]{2}T[0-9]{2}:[0-9]{2}(:[0-5][0-9])?",
        title: 'Input must be in one of the following formats: ' + 'YYYY-MM-DDTHH:MM or YYYY-MM-DDTHH:MM:SS'
      })));
    }
  }]);
  return DateTimeElement;
}(_react.Component);
DateTimeElement.propTypes = {
  name: _propTypes["default"].string.isRequired,
  label: _propTypes["default"].string,
  value: _propTypes["default"].string,
  id: _propTypes["default"].string,
  disabled: _propTypes["default"].bool,
  required: _propTypes["default"].bool,
  onUserInput: _propTypes["default"].func
};
DateTimeElement.defaultProps = {
  name: '',
  label: '',
  value: '',
  id: '',
  disabled: false,
  required: false,
  onUserInput: function onUserInput() {
    console.warn('onUserInput() callback is not set');
  }
};

/**
 * Numeric Component
 * React wrapper for a <input type="number"> element.
 */
var NumericElement = exports.NumericElement = /*#__PURE__*/function (_Component13) {
  (0, _inherits2["default"])(NumericElement, _Component13);
  var _super13 = _createSuper(NumericElement);
  /**
   * @constructor
   * @param {object} props - React Component properties
   */
  function NumericElement(props) {
    var _this14;
    (0, _classCallCheck2["default"])(this, NumericElement);
    _this14 = _super13.call(this, props);
    _this14.handleChange = _this14.handleChange.bind((0, _assertThisInitialized2["default"])(_this14));
    return _this14;
  }

  /**
   * Handle change
   * @param {object} e - Event
   */
  (0, _createClass2["default"])(NumericElement, [{
    key: "handleChange",
    value: function handleChange(e) {
      this.props.onUserInput(this.props.name, e.target.value);
    }

    /**
     * Renders the React component.
     * @return {JSX} - React markup for the component
     */
  }, {
    key: "render",
    value: function render() {
      var errorMessage = null;
      var elementClass = 'row form-group';
      var wrapperClass = this.props.label ? 'col-sm-9' : 'col-sm-12';

      // Add error message
      if (this.props.errorMessage) {
        errorMessage = /*#__PURE__*/_react["default"].createElement("span", null, this.props.errorMessage);
        elementClass = 'row form-group has-error';
      }
      return /*#__PURE__*/_react["default"].createElement("div", {
        className: elementClass
      }, this.props.label && /*#__PURE__*/_react["default"].createElement(_InputLabel["default"], {
        label: this.props.label,
        required: this.props.required
      }), /*#__PURE__*/_react["default"].createElement("div", {
        className: wrapperClass
      }, /*#__PURE__*/_react["default"].createElement("input", {
        type: "number",
        className: "form-control",
        name: this.props.name,
        id: this.props.id,
        min: this.props.min,
        max: this.props.max,
        step: this.props.step,
        value: this.props.value || '',
        disabled: this.props.disabled,
        required: this.props.required,
        onChange: this.handleChange
      }), errorMessage));
    }
  }]);
  return NumericElement;
}(_react.Component);
NumericElement.propTypes = {
  name: _propTypes["default"].string.isRequired,
  min: _propTypes["default"].number,
  max: _propTypes["default"].number,
  step: _propTypes["default"].string,
  label: _propTypes["default"].string,
  value: _propTypes["default"].string,
  id: _propTypes["default"].string,
  disabled: _propTypes["default"].bool,
  required: _propTypes["default"].bool,
  onUserInput: _propTypes["default"].func,
  errorMessage: _propTypes["default"].string
};
NumericElement.defaultProps = {
  name: '',
  min: null,
  max: null,
  step: '1',
  label: '',
  value: '',
  id: null,
  required: false,
  disabled: false,
  onUserInput: function onUserInput() {
    console.warn('onUserInput() callback is not set');
  }
};

/**
 * File Component
 * React wrapper for a simple or 'multiple' <input type="file"> element.
 */
var FileElement = exports.FileElement = /*#__PURE__*/function (_Component14) {
  (0, _inherits2["default"])(FileElement, _Component14);
  var _super14 = _createSuper(FileElement);
  /**
   * @constructor
   * @param {object} props - React Component properties
   */
  function FileElement(props) {
    var _this15;
    (0, _classCallCheck2["default"])(this, FileElement);
    _this15 = _super14.call(this, props);
    _this15.handleChange = _this15.handleChange.bind((0, _assertThisInitialized2["default"])(_this15));
    return _this15;
  }

  /**
   * Handle change
   * @param {object} e - Event
   */
  (0, _createClass2["default"])(FileElement, [{
    key: "handleChange",
    value: function handleChange(e) {
      // Send current file to parent component
      var files = e.target.files ? this.props.allowMultiple ? e.target.files : e.target.files[0] : '';
      this.props.onUserInput(this.props.name, files);
    }

    /**
     * Renders the React component.
     * @return {JSX} - React markup for the component
     */
  }, {
    key: "render",
    value: function render() {
      var fileName = undefined;
      if (this.props.value) {
        switch ((0, _typeof2["default"])(this.props.value)) {
          case 'string':
            fileName = this.props.value;
            break;
          case 'object':
            if (this.props.value instanceof FileList) {
              var files = this.props.value;
              fileName = Array.from(files).map(function (file) {
                return file.name;
              }).join(', ');
            } else {
              fileName = this.props.value.name;
            }
            break;
          default:
            break;
        }
      }
      var errorMessage = '';
      var elementClass = 'row form-group';
      var truncateEllipsis = {
        display: 'table',
        tableLayout: 'fixed',
        width: '100%',
        whiteSpace: 'nowrap'
      };
      var truncateEllipsisChild = {
        display: 'table-cell',
        overflow: 'hidden',
        textOverflow: 'ellipsis'
      };

      // Add error message
      if (this.props.errorMessage) {
        errorMessage = this.props.errorMessage;
        elementClass = 'row form-group has-error';
      }

      // Need to manually reset file value, because HTML API
      // does not allow setting value to anything than empty string.
      // Hence can't use value attribute in the input element.
      var fileHTML = document.querySelector('.fileUpload');
      if (fileHTML && !fileName) {
        fileHTML.value = '';
      }
      if (this.props.disabled) {
        // add padding to align video title on disabled field
        truncateEllipsis.paddingTop = '7px';
        return /*#__PURE__*/_react["default"].createElement("div", {
          className: elementClass
        }, /*#__PURE__*/_react["default"].createElement(_InputLabel["default"], {
          label: this.props.label
        }), /*#__PURE__*/_react["default"].createElement("div", {
          className: "col-sm-9"
        }, /*#__PURE__*/_react["default"].createElement("div", {
          style: truncateEllipsis
        }, /*#__PURE__*/_react["default"].createElement("span", {
          style: truncateEllipsisChild
        }, fileName))));
      }
      var wrapperClass = this.props.label ? 'col-sm-9' : 'col-sm-12';
      return /*#__PURE__*/_react["default"].createElement("div", {
        className: elementClass
      }, this.props.label && /*#__PURE__*/_react["default"].createElement(_InputLabel["default"], {
        label: this.props.label,
        required: this.props.required
      }), /*#__PURE__*/_react["default"].createElement("div", {
        className: wrapperClass
      }, /*#__PURE__*/_react["default"].createElement("div", {
        className: "input-group"
      }, /*#__PURE__*/_react["default"].createElement("div", {
        tabIndex: "-1",
        className: "form-control file-caption kv-fileinput-caption"
      }, /*#__PURE__*/_react["default"].createElement("div", {
        style: truncateEllipsis
      }, /*#__PURE__*/_react["default"].createElement("span", {
        style: truncateEllipsisChild
      }, fileName)), /*#__PURE__*/_react["default"].createElement("div", {
        className: "file-caption-name",
        id: "video_file"
      })), /*#__PURE__*/_react["default"].createElement("div", {
        className: "input-group-btn"
      }, /*#__PURE__*/_react["default"].createElement("div", {
        className: "btn btn-primary btn-file"
      }, /*#__PURE__*/_react["default"].createElement("i", {
        className: "glyphicon glyphicon-folder-open"
      }), " Browse", /*#__PURE__*/_react["default"].createElement("input", {
        type: "file",
        className: "fileUpload",
        name: this.props.name,
        onChange: this.handleChange,
        required: this.props.required,
        multiple: this.props.allowMultiple
      })))), /*#__PURE__*/_react["default"].createElement("span", null, errorMessage)));
    }
  }]);
  return FileElement;
}(_react.Component);
FileElement.propTypes = {
  name: _propTypes["default"].string.isRequired,
  label: _propTypes["default"].string,
  value: _propTypes["default"].oneOfType([_propTypes["default"].string, _propTypes["default"].object]),
  id: _propTypes["default"].string,
  disabled: _propTypes["default"].bool,
  required: _propTypes["default"].bool,
  allowMultiple: _propTypes["default"].bool,
  errorMessage: _propTypes["default"].string,
  onUserInput: _propTypes["default"].func
};
FileElement.defaultProps = {
  name: '',
  label: 'File to Upload',
  value: '',
  id: null,
  disabled: false,
  required: false,
  allowMultiple: false,
  errorMessage: null,
  onUserInput: function onUserInput() {
    console.warn('onUserInput() callback is not set');
  }
};

/**
 * Static element component.
 * Used to displays plain/formatted text as part of a form
 *
 * To pass a formatted text, you need to wrap it in a single parent element.
 * Example usage:
 *
 * ```
 * let myText = (<span>This is my <b>text</b></span>);
 * <StaticElement
 *    text={myText}
 *    label={note}
 * />
 * ```
 */
var StaticElement = exports.StaticElement = /*#__PURE__*/function (_Component15) {
  (0, _inherits2["default"])(StaticElement, _Component15);
  var _super15 = _createSuper(StaticElement);
  /**
   * @constructor
   * @param {object} props - React Component properties
   */
  function StaticElement(props) {
    (0, _classCallCheck2["default"])(this, StaticElement);
    return _super15.call(this, props);
  }

  /**
   * Renders the React component.
   * @return {JSX} - React markup for the component
   */
  (0, _createClass2["default"])(StaticElement, [{
    key: "render",
    value: function render() {
      return /*#__PURE__*/_react["default"].createElement("div", {
        className: "row form-group"
      }, this.props.label && /*#__PURE__*/_react["default"].createElement(_InputLabel["default"], {
        label: this.props.label
      }), /*#__PURE__*/_react["default"].createElement("div", {
        className: this.props["class"]
      }, /*#__PURE__*/_react["default"].createElement("div", {
        className: this.props.textClass
      }, this.props.text)));
    }
  }]);
  return StaticElement;
}(_react.Component);
StaticElement.propTypes = (0, _defineProperty2["default"])({
  label: _propTypes["default"].string,
  "class": _propTypes["default"].string,
  textClass: _propTypes["default"].string,
  text: _propTypes["default"].oneOfType([_propTypes["default"].string, _propTypes["default"].element])
}, "class", _propTypes["default"].string);
StaticElement.defaultProps = {
  label: '',
  text: null,
  "class": 'col-sm-9',
  textClass: 'form-control-static'
};

/**
 * Header element component.
 * Used to display a header element with specific level (1-6) as part of a form
 *
 */
var HeaderElement = exports.HeaderElement = /*#__PURE__*/function (_Component16) {
  (0, _inherits2["default"])(HeaderElement, _Component16);
  var _super16 = _createSuper(HeaderElement);
  /**
   * @constructor
   * @param {object} props - React Component properties
   */
  function HeaderElement(props) {
    (0, _classCallCheck2["default"])(this, HeaderElement);
    return _super16.call(this, props);
  }

  /**
   * Renders the React component.
   * @return {JSX} - React markup for the component
   */
  (0, _createClass2["default"])(HeaderElement, [{
    key: "render",
    value: function render() {
      var Tag = 'h' + this.props.headerLevel;
      return /*#__PURE__*/_react["default"].createElement("div", {
        className: "row form-group"
      }, /*#__PURE__*/_react["default"].createElement(Tag, {
        className: "col-xs-12"
      }, this.props.text));
    }
  }]);
  return HeaderElement;
}(_react.Component);
HeaderElement.propTypes = {
  text: _propTypes["default"].string.isRequired,
  headerLevel: _propTypes["default"].oneOf([1, 2, 3, 4, 5, 6])
};
HeaderElement.defaultProps = {
  headerLevel: 3
};

/**
 * Link element component.
 * Used to link plain/formated text to an href destination as part of a form
 */
var LinkElement = exports.LinkElement = /*#__PURE__*/function (_Component17) {
  (0, _inherits2["default"])(LinkElement, _Component17);
  var _super17 = _createSuper(LinkElement);
  /**
   * @constructor
   * @param {object} props - React Component properties
   */
  function LinkElement(props) {
    (0, _classCallCheck2["default"])(this, LinkElement);
    return _super17.call(this, props);
  }

  /**
   * Renders the React component.
   * @return {JSX} - React markup for the component
   */
  (0, _createClass2["default"])(LinkElement, [{
    key: "render",
    value: function render() {
      return /*#__PURE__*/_react["default"].createElement("div", {
        className: "row form-group"
      }, /*#__PURE__*/_react["default"].createElement(_InputLabel["default"], {
        label: this.props.label
      }), /*#__PURE__*/_react["default"].createElement("div", {
        className: "col-sm-9"
      }, /*#__PURE__*/_react["default"].createElement("p", {
        className: "form-control-static"
      }, /*#__PURE__*/_react["default"].createElement("a", {
        href: this.props.href
      }, this.props.text))));
    }
  }]);
  return LinkElement;
}(_react.Component);
LinkElement.propTypes = {
  label: _propTypes["default"].string,
  text: _propTypes["default"].oneOfType([_propTypes["default"].string, _propTypes["default"].element]),
  href: _propTypes["default"].string
};
LinkElement.defaultProps = {
  label: '',
  text: null,
  href: null
};

/**
 * Checkbox Component
 * React wrapper for a <input type="checkbox"> element.
 */
var CheckboxElement = exports.CheckboxElement = /*#__PURE__*/function (_React$Component) {
  (0, _inherits2["default"])(CheckboxElement, _React$Component);
  var _super18 = _createSuper(CheckboxElement);
  /**
   * @constructor
   */
  function CheckboxElement() {
    var _this16;
    (0, _classCallCheck2["default"])(this, CheckboxElement);
    _this16 = _super18.call(this);
    _this16.handleChange = _this16.handleChange.bind((0, _assertThisInitialized2["default"])(_this16));
    return _this16;
  }

  /**
   * Handle change
   * @param {object} e - Event
   */
  (0, _createClass2["default"])(CheckboxElement, [{
    key: "handleChange",
    value: function handleChange(e) {
      this.props.onUserInput(this.props.name, e.target.checked);
    }

    /**
     * Renders the React component.
     * @return {JSX} - React markup for the component
     */
  }, {
    key: "render",
    value: function render() {
      var errorMessage = null;
      var requiredHTML = null;
      var elementClass = this.props["class"] + ' ' + this.props.offset;
      var divStyle = this.props["class"] === 'checkbox-inline' ? {
        paddingRight: '5px'
      } : {
        paddingRight: '5px',
        display: 'inline-block'
      };

      // Add required asterix
      if (this.props.required) {
        requiredHTML = /*#__PURE__*/_react["default"].createElement("span", {
          className: "text-danger"
        }, "*");
      }

      // Add error message
      if (this.props.errorMessage) {
        errorMessage = /*#__PURE__*/_react["default"].createElement("span", null, this.props.errorMessage);
        elementClass = elementClass + ' has-error';
      }
      return /*#__PURE__*/_react["default"].createElement("div", {
        className: elementClass
      }, /*#__PURE__*/_react["default"].createElement("div", {
        className: "col-sm-12"
      }, /*#__PURE__*/_react["default"].createElement("label", {
        htmlFor: this.props.id
      }, /*#__PURE__*/_react["default"].createElement("div", {
        style: divStyle
      }, /*#__PURE__*/_react["default"].createElement("input", {
        type: "checkbox",
        name: this.props.name,
        id: this.props.id,
        checked: this.props.value,
        required: this.props.required,
        disabled: this.props.disabled,
        onChange: this.handleChange
      })), errorMessage, this.props.label, requiredHTML)));
    }
  }]);
  return CheckboxElement;
}(_react["default"].Component);
CheckboxElement.propTypes = {
  name: _propTypes["default"].string.isRequired,
  label: _propTypes["default"].string.isRequired,
  value: _propTypes["default"].bool.isRequired,
  id: _propTypes["default"].string,
  "class": _propTypes["default"].string,
  offset: _propTypes["default"].string,
  disabled: _propTypes["default"].bool,
  required: _propTypes["default"].bool,
  errorMessage: _propTypes["default"].string,
  elementClass: _propTypes["default"].string,
  onUserInput: _propTypes["default"].func
};
CheckboxElement.defaultProps = {
  id: null,
  disabled: false,
  required: false,
  errorMessage: null,
  offset: 'col-sm-offset-3',
  "class": 'checkbox-inline',
  elementClass: 'checkbox-inline col-sm-offset-3',
  onUserInput: function onUserInput() {
    console.warn('onUserInput() callback is not set');
  }
};

/**
 * Button component
 * React wrapper for <button> element, typically used to submit forms
 */
var ButtonElement = exports.ButtonElement = /*#__PURE__*/function (_Component18) {
  (0, _inherits2["default"])(ButtonElement, _Component18);
  var _super19 = _createSuper(ButtonElement);
  /**
   * @constructor
   * @param {object} props - React Component properties
   */
  function ButtonElement(props) {
    var _this17;
    (0, _classCallCheck2["default"])(this, ButtonElement);
    _this17 = _super19.call(this, props);
    _this17.handleClick = _this17.handleClick.bind((0, _assertThisInitialized2["default"])(_this17));
    return _this17;
  }

  /**
   * Handle click
   * @param {object} e - Event
   */
  (0, _createClass2["default"])(ButtonElement, [{
    key: "handleClick",
    value: function handleClick(e) {
      this.props.onUserInput(e);
    }

    /**
     * Renders the React component.
     * @return {JSX} - React markup for the component
     */
  }, {
    key: "render",
    value: function render() {
      return /*#__PURE__*/_react["default"].createElement("div", {
        className: "row form-group"
      }, /*#__PURE__*/_react["default"].createElement("div", {
        className: this.props.columnSize
      }, /*#__PURE__*/_react["default"].createElement("button", {
        id: this.props.id,
        name: this.props.name,
        type: this.props.type,
        className: this.props.buttonClass,
        style: this.props.style,
        onClick: this.handleClick,
        disabled: this.props.disabled
      }, this.props.disabled ? 'Uploading...' : this.props.label)));
    }
  }]);
  return ButtonElement;
}(_react.Component);
ButtonElement.propTypes = {
  id: _propTypes["default"].string,
  name: _propTypes["default"].string,
  label: _propTypes["default"].string,
  type: _propTypes["default"].string,
  disabled: _propTypes["default"].bool,
  style: _propTypes["default"].object,
  onUserInput: _propTypes["default"].func,
  columnSize: _propTypes["default"].string,
  buttonClass: _propTypes["default"].string
};
ButtonElement.defaultProps = {
  label: 'Submit',
  type: 'submit',
  disabled: null,
  buttonClass: 'btn btn-primary',
  columnSize: 'col-sm-9 col-sm-offset-3',
  onUserInput: function onUserInput() {
    console.warn('onUserInput() callback is not set');
  }
};

/**
 * Call To Action (CTA) component
 * React wrapper for <button> element that is used for Call to Actions, usually
 * outside the context of forms.
 */
var CTA = exports.CTA = /*#__PURE__*/function (_Component19) {
  (0, _inherits2["default"])(CTA, _Component19);
  var _super20 = _createSuper(CTA);
  function CTA() {
    (0, _classCallCheck2["default"])(this, CTA);
    return _super20.apply(this, arguments);
  }
  (0, _createClass2["default"])(CTA, [{
    key: "render",
    value:
    /**
     * Renders the React component.
     * @return {JSX} - React markup for the component
     */
    function render() {
      return /*#__PURE__*/_react["default"].createElement("button", {
        className: this.props.buttonClass,
        onClick: this.props.onUserInput
      }, this.props.label);
    }
  }]);
  return CTA;
}(_react.Component);
CTA.propTypes = {
  label: _propTypes["default"].string,
  buttonClass: _propTypes["default"].string,
  onUserInput: _propTypes["default"].func
};
CTA.defaultProps = {
  buttonClass: 'btn btn-primary',
  onUserInput: function onUserInput() {
    console.warn('onUserInput() callback is not set');
  }
};

/**
 * Generic form element.
 */
var LorisElement = exports.LorisElement = /*#__PURE__*/function (_Component20) {
  (0, _inherits2["default"])(LorisElement, _Component20);
  var _super21 = _createSuper(LorisElement);
  /**
   * @constructor
   * @param {object} props - React Component properties
   */
  function LorisElement(props) {
    (0, _classCallCheck2["default"])(this, LorisElement);
    return _super21.call(this, props);
  }

  /**
   * Renders the React component.
   * @return {JSX} - React markup for the component
   */
  (0, _createClass2["default"])(LorisElement, [{
    key: "render",
    value: function render() {
      var elementProps = this.props.element;
      elementProps.ref = elementProps.name;
      elementProps.onUserInput = this.props.onUserInput;
      var elementHtml = /*#__PURE__*/_react["default"].createElement("div", null);
      switch (elementProps.type) {
        case 'text':
          elementHtml = /*#__PURE__*/_react["default"].createElement(TextboxElement, elementProps);
          break;
        case 'email':
          elementHtml = /*#__PURE__*/_react["default"].createElement(EmailElement, elementProps);
          break;
        case 'password':
          elementHtml = /*#__PURE__*/_react["default"].createElement(PasswordElement, elementProps);
          break;
        case 'tags':
          elementHtml = /*#__PURE__*/_react["default"].createElement(TagsElement, elementProps);
          break;
        case 'select':
          elementHtml = /*#__PURE__*/_react["default"].createElement(SelectElement, elementProps);
          break;
        case 'search':
          elementHtml = /*#__PURE__*/_react["default"].createElement(SearchableDropdown, elementProps);
          break;
        case 'date':
          elementHtml = /*#__PURE__*/_react["default"].createElement(DateElement, elementProps);
          break;
        case 'time':
          elementHtml = /*#__PURE__*/_react["default"].createElement(TimeElement, elementProps);
          break;
        case 'numeric':
          elementHtml = /*#__PURE__*/_react["default"].createElement(NumericElement, elementProps);
          break;
        case 'textarea':
          elementHtml = /*#__PURE__*/_react["default"].createElement(TextareaElement, elementProps);
          break;
        case 'file':
          elementHtml = /*#__PURE__*/_react["default"].createElement(FileElement, elementProps);
          break;
        case 'static':
          elementHtml = /*#__PURE__*/_react["default"].createElement(StaticElement, elementProps);
          break;
        case 'header':
          elementHtml = /*#__PURE__*/_react["default"].createElement(HeaderElement, elementProps);
          break;
        case 'link':
          elementHtml = /*#__PURE__*/_react["default"].createElement(LinkElement, elementProps);
          break;
        case 'advcheckbox':
          elementHtml = /*#__PURE__*/_react["default"].createElement(CheckboxElement, elementProps);
          break;
        default:
          console.warn('Element of type ' + elementProps.type + ' is not currently implemented!');
          break;
      }
      return elementHtml;
    }
  }]);
  return LorisElement;
}(_react.Component);
LorisElement.propTypes = {
  element: _propTypes["default"].object,
  onUserInput: _propTypes["default"].string
};

/**
 * Radio Component
 * React wrapper for a <input type='radio'> element.
 *
 * Example `options` prop:
 *   {
 *     female: 'Female',
 *     male: 'Male',
 *   }
 */
var RadioElement = exports.RadioElement = /*#__PURE__*/function (_React$Component2) {
  (0, _inherits2["default"])(RadioElement, _React$Component2);
  var _super22 = _createSuper(RadioElement);
  /**
   * @constructor
   * @param {object} props - React Component properties
   */
  function RadioElement(props) {
    var _this18;
    (0, _classCallCheck2["default"])(this, RadioElement);
    _this18 = _super22.call(this, props);
    _this18.handleChange = _this18.handleChange.bind((0, _assertThisInitialized2["default"])(_this18));
    _this18.generateLayout = _this18.generateLayout.bind((0, _assertThisInitialized2["default"])(_this18));
    return _this18;
  }

  /**
   * Handle change
   * @param {object} e - Event
   */
  (0, _createClass2["default"])(RadioElement, [{
    key: "handleChange",
    value: function handleChange(e) {
      this.props.onUserInput(this.props.name, e.target.value);
    }

    /**
     * Generate layout
     * @return {JSX[]} - An array of element React markup
     */
  }, {
    key: "generateLayout",
    value: function generateLayout() {
      var layout = [];
      var styleRow = {
        display: 'flex',
        flexDirection: this.props.vertical ? 'column' : 'row',
        flexWrap: 'wrap',
        width: '100%'
      };
      var styleColumn = {
        display: 'flex',
        flexDirection: 'column',
        alignSelf: 'flex-start',
        marginRight: '10px'
      };
      var styleContainer = {
        paddingTop: '7px',
        cursor: 'pointer'
      };
      var styleLabel = {
        margin: 0,
        color: '#064785',
        cursor: 'pointer'
      };
      var styleInput = {
        display: 'inline-block',
        margin: '0 5px 0 5px',
        cursor: 'pointer'
      };
      var content = [];
      for (var key in this.props.options) {
        if (this.props.options.hasOwnProperty(key)) {
          var checked = this.props.checked === key;
          content.push( /*#__PURE__*/_react["default"].createElement("div", {
            key: key,
            style: styleColumn
          }, /*#__PURE__*/_react["default"].createElement("div", {
            style: styleContainer
          }, /*#__PURE__*/_react["default"].createElement("input", {
            type: "radio",
            name: this.props.name,
            value: key,
            id: key,
            checked: checked,
            required: this.props.required,
            disabled: this.props.disabled,
            onChange: this.handleChange,
            style: styleInput
          }), /*#__PURE__*/_react["default"].createElement("label", {
            htmlFor: key,
            style: styleLabel
          }, this.props.options[key]))));
        }
      }
      layout.push( /*#__PURE__*/_react["default"].createElement("div", {
        key: this.props.name + '_key',
        style: styleRow
      }, content));
      return layout;
    }

    /**
     * Renders the React component.
     * @return {JSX} - React markup for the component
     */
  }, {
    key: "render",
    value: function render() {
      var errorMessage = null;
      var requiredHTML = null;
      var elementClass = this.props.elementClass;
      var required = this.props.required ? 'required' : null;

      // Add required asterix
      if (required) {
        requiredHTML = /*#__PURE__*/_react["default"].createElement("span", {
          className: "text-danger"
        }, "*");
      }
      // Add error message
      if (this.props.errorMessage) {
        errorMessage = /*#__PURE__*/_react["default"].createElement("span", null, this.props.errorMessage);
        elementClass = this.props.elementClass + ' has-error';
      }
      // Generate layout
      var layout = this.generateLayout();
      return /*#__PURE__*/_react["default"].createElement("div", {
        className: elementClass
      }, /*#__PURE__*/_react["default"].createElement("label", {
        className: 'col-sm-3 control-label'
      }, this.props.label, errorMessage, requiredHTML), /*#__PURE__*/_react["default"].createElement("div", {
        className: 'col-sm-9'
      }, layout));
    }
  }]);
  return RadioElement;
}(_react["default"].Component);
RadioElement.propTypes = {
  name: _propTypes["default"].string.isRequired,
  label: _propTypes["default"].string,
  options: _propTypes["default"].object.isRequired,
  disabled: _propTypes["default"].bool,
  required: _propTypes["default"].bool,
  vertical: _propTypes["default"].bool,
  checked: _propTypes["default"].string.isRequired,
  errorMessage: _propTypes["default"].string,
  elementClass: _propTypes["default"].string,
  onUserInput: _propTypes["default"].func
};
RadioElement.defaultProps = {
  disabled: false,
  required: false,
  vertical: false,
  errorMessage: null,
  elementClass: 'row form-group',
  onUserInput: function onUserInput() {
    console.warn('onUserInput() callback is not set');
  }
};

/**
 * Slider Component
 * React wrapper for a <input type='range'> element.
 */
var SliderElement = exports.SliderElement = /*#__PURE__*/function (_React$Component3) {
  (0, _inherits2["default"])(SliderElement, _React$Component3);
  var _super23 = _createSuper(SliderElement);
  /**
   * @constructor
   * @param {object} props - React Component properties
   */
  function SliderElement(props) {
    var _this19;
    (0, _classCallCheck2["default"])(this, SliderElement);
    _this19 = _super23.call(this, props);
    _this19.handleChange = _this19.handleChange.bind((0, _assertThisInitialized2["default"])(_this19));
    return _this19;
  }

  /**
   * Handle change
   * @param {object} e - Event
   */
  (0, _createClass2["default"])(SliderElement, [{
    key: "handleChange",
    value: function handleChange(e) {
      // Handles empty, min & max cases.
      var inputValue = e.target.value ? parseFloat(e.target.value) : this.props.minValue;
      var value = inputValue > this.props.maxValue ? this.props.maxValue : inputValue;
      value = value < this.props.minValue ? this.props.minValue : value;
      this.props.onUserInput(this.props.name, value);
    }

    /**
     * Renders the React component.
     * @return {JSX} - React markup for the component
     */
  }, {
    key: "render",
    value: function render() {
      var errorMessage = null;
      var requiredHTML = null;
      var elementClass = this.props.elementClass;
      // Add required asterix
      if (this.props.required) {
        requiredHTML = /*#__PURE__*/_react["default"].createElement("span", {
          className: "text-danger"
        }, "*");
      }
      // Add error message
      if (this.props.errorMessage) {
        errorMessage = /*#__PURE__*/_react["default"].createElement("span", null, this.props.errorMessage);
        elementClass = this.props.elementClass + ' has-error';
      }
      return /*#__PURE__*/_react["default"].createElement("div", {
        className: elementClass
      }, /*#__PURE__*/_react["default"].createElement("label", {
        className: 'col-sm-3 control-label',
        htmlFor: this.props.id
      }, this.props.label, errorMessage, requiredHTML), /*#__PURE__*/_react["default"].createElement("div", {
        className: 'col-sm-9'
      }, /*#__PURE__*/_react["default"].createElement("div", {
        style: {
          display: 'flex',
          flexDirection: 'row',
          flexWrap: 'wrap',
          width: '100%'
        }
      }, /*#__PURE__*/_react["default"].createElement("div", {
        style: {
          flexGrow: 1000,
          display: 'flex',
          flexDirection: 'column',
          flexBasis: '100%',
          maxWidth: this.props.maxWidth,
          marginRight: '5px',
          flex: 2
        }
      }, /*#__PURE__*/_react["default"].createElement("input", {
        type: "range",
        name: this.props.name,
        id: this.props.id,
        value: this.props.value,
        min: this.props.minValue,
        max: this.props.maxValue,
        required: this.props.required,
        disabled: this.props.disabled,
        onChange: this.handleChange,
        style: {
          width: '100%'
        }
      })), /*#__PURE__*/_react["default"].createElement("div", {
        style: {
          display: 'flex',
          flexDirection: 'column',
          flexBasis: '100%',
          maxWidth: '50px',
          flex: 1
        }
      }, /*#__PURE__*/_react["default"].createElement("input", {
        type: "number",
        name: 'input_' + this.props.name,
        value: this.props.value,
        min: this.props.minValue,
        max: this.props.maxValue,
        required: this.props.required,
        disabled: this.props.disabled,
        onChange: this.handleChange,
        style: {
          width: '50px',
          textAlign: 'center'
        }
      })))));
    }
  }]);
  return SliderElement;
}(_react["default"].Component);
SliderElement.propTypes = {
  id: _propTypes["default"].string,
  name: _propTypes["default"].string.isRequired,
  label: _propTypes["default"].string.isRequired,
  value: _propTypes["default"].number.isRequired,
  minValue: _propTypes["default"].number.isRequired,
  maxValue: _propTypes["default"].number.isRequired,
  maxWidth: _propTypes["default"].string,
  disabled: _propTypes["default"].bool,
  required: _propTypes["default"].bool,
  errorMessage: _propTypes["default"].string,
  elementClass: _propTypes["default"].string,
  onUserInput: _propTypes["default"].func
};
SliderElement.defaultProps = {
  id: null,
  maxWidth: 'auto',
  disabled: false,
  required: false,
  errorMessage: null,
  elementClass: 'row form-group',
  onUserInput: function onUserInput() {
    console.warn('onUserInput() callback is not set');
  }
};
var _default = exports["default"] = {
  FormElement: FormElement,
  FieldsetElement: FieldsetElement,
  SelectElement: SelectElement,
  TagsElement: TagsElement,
  SearchableDropdown: SearchableDropdown,
  TextareaElement: TextareaElement,
  TextboxElement: TextboxElement,
  PasswordElement: PasswordElement,
  DateElement: DateElement,
  TimeElement: TimeElement,
  DateTimeElement: DateTimeElement,
  NumericElement: NumericElement,
  FileElement: FileElement,
  StaticElement: StaticElement,
  HeaderElement: HeaderElement,
  LinkElement: LinkElement,
  CheckboxElement: CheckboxElement,
  RadioElement: RadioElement,
  SliderElement: SliderElement,
  ButtonElement: ButtonElement,
  CTA: CTA,
  LorisElement: LorisElement
};

/***/ }),

/***/ "./jsx/PaginationLinks.js":
/*!********************************!*\
  !*** ./jsx/PaginationLinks.js ***!
  \********************************/
/***/ ((__unused_webpack_module, exports, __webpack_require__) => {

"use strict";


var _interopRequireDefault = __webpack_require__(/*! @babel/runtime/helpers/interopRequireDefault */ "./node_modules/@babel/runtime/helpers/interopRequireDefault.js");
var _typeof = __webpack_require__(/*! @babel/runtime/helpers/typeof */ "./node_modules/@babel/runtime/helpers/typeof.js");
Object.defineProperty(exports, "__esModule", ({
  value: true
}));
exports["default"] = void 0;
var _classCallCheck2 = _interopRequireDefault(__webpack_require__(/*! @babel/runtime/helpers/classCallCheck */ "./node_modules/@babel/runtime/helpers/classCallCheck.js"));
var _createClass2 = _interopRequireDefault(__webpack_require__(/*! @babel/runtime/helpers/createClass */ "./node_modules/@babel/runtime/helpers/createClass.js"));
var _assertThisInitialized2 = _interopRequireDefault(__webpack_require__(/*! @babel/runtime/helpers/assertThisInitialized */ "./node_modules/@babel/runtime/helpers/assertThisInitialized.js"));
var _inherits2 = _interopRequireDefault(__webpack_require__(/*! @babel/runtime/helpers/inherits */ "./node_modules/@babel/runtime/helpers/inherits.js"));
var _possibleConstructorReturn2 = _interopRequireDefault(__webpack_require__(/*! @babel/runtime/helpers/possibleConstructorReturn */ "./node_modules/@babel/runtime/helpers/possibleConstructorReturn.js"));
var _getPrototypeOf2 = _interopRequireDefault(__webpack_require__(/*! @babel/runtime/helpers/getPrototypeOf */ "./node_modules/@babel/runtime/helpers/getPrototypeOf.js"));
var _react = _interopRequireWildcard(__webpack_require__(/*! react */ "react"));
var _propTypes = _interopRequireDefault(__webpack_require__(/*! prop-types */ "./node_modules/prop-types/index.js"));
function _getRequireWildcardCache(e) { if ("function" != typeof WeakMap) return null; var r = new WeakMap(), t = new WeakMap(); return (_getRequireWildcardCache = function _getRequireWildcardCache(e) { return e ? t : r; })(e); }
function _interopRequireWildcard(e, r) { if (!r && e && e.__esModule) return e; if (null === e || "object" != _typeof(e) && "function" != typeof e) return { "default": e }; var t = _getRequireWildcardCache(r); if (t && t.has(e)) return t.get(e); var n = { __proto__: null }, a = Object.defineProperty && Object.getOwnPropertyDescriptor; for (var u in e) { if ("default" !== u && {}.hasOwnProperty.call(e, u)) { var i = a ? Object.getOwnPropertyDescriptor(e, u) : null; i && (i.get || i.set) ? Object.defineProperty(n, u, i) : n[u] = e[u]; } } return n["default"] = e, t && t.set(e, n), n; }
function _createSuper(t) { var r = _isNativeReflectConstruct(); return function () { var e, o = (0, _getPrototypeOf2["default"])(t); if (r) { var s = (0, _getPrototypeOf2["default"])(this).constructor; e = Reflect.construct(o, arguments, s); } else e = o.apply(this, arguments); return (0, _possibleConstructorReturn2["default"])(this, e); }; }
function _isNativeReflectConstruct() { try { var t = !Boolean.prototype.valueOf.call(Reflect.construct(Boolean, [], function () {})); } catch (t) {} return (_isNativeReflectConstruct = function _isNativeReflectConstruct() { return !!t; })(); }
/**
 * Pagination component
 */
var PaginationLinks = /*#__PURE__*/function (_Component) {
  (0, _inherits2["default"])(PaginationLinks, _Component);
  var _super = _createSuper(PaginationLinks);
  /**
   * @constructor
   * @param {object} props - React Component properties
   */
  function PaginationLinks(props) {
    var _this;
    (0, _classCallCheck2["default"])(this, PaginationLinks);
    _this = _super.call(this, props);
    _this.state = {};
    _this.changePage = _this.changePage.bind((0, _assertThisInitialized2["default"])(_this));
    return _this;
  }

  /**
   * Called by React when the component is updated.
   * @param {object} prevProps - Previous React Component properties
   */
  (0, _createClass2["default"])(PaginationLinks, [{
    key: "componentDidUpdate",
    value: function componentDidUpdate(prevProps) {
      if (this.props.Total < prevProps.Total) {
        this.props.onChangePage(1);
      }
    }

    /**
     * Creates an onClick Event Handler
     * execyting this.props.onChangePage(i)
     * @param {number} i - Page index
     * @return {function(Event): void} - onClick Event Handler
     */
  }, {
    key: "changePage",
    value: function changePage(i) {
      return function (evt) {
        // Don't jump to the top of the page
        evt.preventDefault();
        if (this.props.onChangePage) {
          this.props.onChangePage(i);
        }
      }.bind(this);
    }

    /**
     * Renders the React component.
     * @return {JSX} - React markup for the component
     */
  }, {
    key: "render",
    value: function render() {
      var rowsPerPage = this.props.RowsPerPage;
      var pageLinks = [];
      var classList;
      var lastPage = Math.ceil(this.props.Total / rowsPerPage);
      var startPage = Math.max(1, this.props.Active - 3);
      var lastShownPage = Math.min(this.props.Active + 3, lastPage);
      if (this.props.Total === 0) {
        return /*#__PURE__*/_react["default"].createElement("div", null);
      }
      if (this.props.Total < this.props.RowsPerPage) {
        return /*#__PURE__*/_react["default"].createElement("div", null);
      }
      if (lastShownPage - startPage <= 7) {
        lastShownPage = startPage + 6;
        if (lastShownPage > lastPage) {
          lastShownPage = lastPage;
          startPage = lastPage - 6;
        }
      }
      if (startPage > 1) {
        pageLinks.push( /*#__PURE__*/_react["default"].createElement("li", {
          key: 'table_page_beginning_' + startPage.toString(),
          onClick: this.changePage(1)
        }, /*#__PURE__*/_react["default"].createElement("a", {
          href: "#"
        }, "\xAB")));
      }
      if (startPage < 1) {
        startPage = 1;
      }
      if (lastShownPage < 1) {
        lastShownPage = 1;
      }

      // If there is only 1 page, don't display pagination links
      if (startPage === lastShownPage) {
        return /*#__PURE__*/_react["default"].createElement("div", null);
      }
      for (var i = startPage; i <= lastShownPage; i += 1) {
        classList = '';
        if (this.props.Active === i) {
          classList = 'active';
        }
        pageLinks.push( /*#__PURE__*/_react["default"].createElement("li", {
          key: 'table_page_' + i.toString(),
          onClick: this.changePage(i),
          className: classList
        }, /*#__PURE__*/_react["default"].createElement("a", {
          href: "#"
        }, i)));
      }
      if (lastShownPage !== lastPage) {
        pageLinks.push( /*#__PURE__*/_react["default"].createElement("li", {
          key: 'table_page_more_' + lastShownPage.toString(),
          onClick: this.changePage(lastPage)
        }, /*#__PURE__*/_react["default"].createElement("a", {
          href: "#"
        }, "\xBB")));
      }
      return /*#__PURE__*/_react["default"].createElement("ul", {
        className: "pagination pagination-table"
      }, pageLinks);
    }
  }]);
  return PaginationLinks;
}(_react.Component);
PaginationLinks.propTypes = {
  onChangePage: _propTypes["default"].func,
  Total: _propTypes["default"].number.isRequired,
  RowsPerPage: _propTypes["default"].number,
  Active: _propTypes["default"].number
};
PaginationLinks.defaultProps = {
  RowsPerPage: 10,
  Active: 1
};
window.PaginationLinks = PaginationLinks;
var _default = exports["default"] = PaginationLinks;

/***/ }),

/***/ "./jsx/Panel.js":
/*!**********************!*\
  !*** ./jsx/Panel.js ***!
  \**********************/
/***/ ((__unused_webpack_module, exports, __webpack_require__) => {

"use strict";


var _interopRequireDefault = __webpack_require__(/*! @babel/runtime/helpers/interopRequireDefault */ "./node_modules/@babel/runtime/helpers/interopRequireDefault.js");
var _typeof = __webpack_require__(/*! @babel/runtime/helpers/typeof */ "./node_modules/@babel/runtime/helpers/typeof.js");
Object.defineProperty(exports, "__esModule", ({
  value: true
}));
exports["default"] = void 0;
var _defineProperty2 = _interopRequireDefault(__webpack_require__(/*! @babel/runtime/helpers/defineProperty */ "./node_modules/@babel/runtime/helpers/defineProperty.js"));
var _slicedToArray2 = _interopRequireDefault(__webpack_require__(/*! @babel/runtime/helpers/slicedToArray */ "./node_modules/@babel/runtime/helpers/slicedToArray.js"));
var _react = _interopRequireWildcard(__webpack_require__(/*! react */ "react"));
var _propTypes = _interopRequireDefault(__webpack_require__(/*! prop-types */ "./node_modules/prop-types/index.js"));
function _getRequireWildcardCache(e) { if ("function" != typeof WeakMap) return null; var r = new WeakMap(), t = new WeakMap(); return (_getRequireWildcardCache = function _getRequireWildcardCache(e) { return e ? t : r; })(e); }
function _interopRequireWildcard(e, r) { if (!r && e && e.__esModule) return e; if (null === e || "object" != _typeof(e) && "function" != typeof e) return { "default": e }; var t = _getRequireWildcardCache(r); if (t && t.has(e)) return t.get(e); var n = { __proto__: null }, a = Object.defineProperty && Object.getOwnPropertyDescriptor; for (var u in e) { if ("default" !== u && {}.hasOwnProperty.call(e, u)) { var i = a ? Object.getOwnPropertyDescriptor(e, u) : null; i && (i.get || i.set) ? Object.defineProperty(n, u, i) : n[u] = e[u]; } } return n["default"] = e, t && t.set(e, n), n; }
function ownKeys(e, r) { var t = Object.keys(e); if (Object.getOwnPropertySymbols) { var o = Object.getOwnPropertySymbols(e); r && (o = o.filter(function (r) { return Object.getOwnPropertyDescriptor(e, r).enumerable; })), t.push.apply(t, o); } return t; }
function _objectSpread(e) { for (var r = 1; r < arguments.length; r++) { var t = null != arguments[r] ? arguments[r] : {}; r % 2 ? ownKeys(Object(t), !0).forEach(function (r) { (0, _defineProperty2["default"])(e, r, t[r]); }) : Object.getOwnPropertyDescriptors ? Object.defineProperties(e, Object.getOwnPropertyDescriptors(t)) : ownKeys(Object(t)).forEach(function (r) { Object.defineProperty(e, r, Object.getOwnPropertyDescriptor(t, r)); }); } return e; }
function _createForOfIteratorHelper(r, e) { var t = "undefined" != typeof Symbol && r[Symbol.iterator] || r["@@iterator"]; if (!t) { if (Array.isArray(r) || (t = _unsupportedIterableToArray(r)) || e && r && "number" == typeof r.length) { t && (r = t); var _n = 0, F = function F() {}; return { s: F, n: function n() { return _n >= r.length ? { done: !0 } : { done: !1, value: r[_n++] }; }, e: function e(r) { throw r; }, f: F }; } throw new TypeError("Invalid attempt to iterate non-iterable instance.\nIn order to be iterable, non-array objects must have a [Symbol.iterator]() method."); } var o, a = !0, u = !1; return { s: function s() { t = t.call(r); }, n: function n() { var r = t.next(); return a = r.done, r; }, e: function e(r) { u = !0, o = r; }, f: function f() { try { a || null == t["return"] || t["return"](); } finally { if (u) throw o; } } }; }
function _unsupportedIterableToArray(r, a) { if (r) { if ("string" == typeof r) return _arrayLikeToArray(r, a); var t = {}.toString.call(r).slice(8, -1); return "Object" === t && r.constructor && (t = r.constructor.name), "Map" === t || "Set" === t ? Array.from(r) : "Arguments" === t || /^(?:Ui|I)nt(?:8|16|32)(?:Clamped)?Array$/.test(t) ? _arrayLikeToArray(r, a) : void 0; } }
function _arrayLikeToArray(r, a) { (null == a || a > r.length) && (a = r.length); for (var e = 0, n = Array(a); e < a; e++) { n[e] = r[e]; } return n; }
/**
 * Panel - a collapsible panel component with optional multiple views.
 * @author Alex I.
 * @version 2.0.0
 * @param {object} props
 * @return {JSX.Element}
 */
var Panel = function Panel(props) {
  var _useState = (0, _react.useState)(false),
    _useState2 = (0, _slicedToArray2["default"])(_useState, 2),
    collapsed = _useState2[0],
    setCollapsed = _useState2[1];
  var _useState3 = (0, _react.useState)(0),
    _useState4 = (0, _slicedToArray2["default"])(_useState3, 2),
    activeView = _useState4[0],
    setActiveView = _useState4[1];

  /**
   * Similar to componentDidMount and componentDidUpdate.
   */
  (0, _react.useEffect)(function () {
    setCollapsed(props.initCollapsed);
  }, []);

  /**
   * Toggle whether panel is displayed as collapsed
   */
  var toggleCollapsed = function toggleCollapsed() {
    if (props.collapsing) {
      setCollapsed(!collapsed);
    }
  };

  /**
   * User clicked a view to display.
   * @param {number} index
   */
  var viewClicked = function viewClicked(index) {
    setActiveView(index);
    if (props.onChangeView) {
      props.onChangeView(index);
    }
  };

  // Panel Views (START)
  var views = [];
  var content = [];
  var panelViews;
  if (props.views) {
    var _iterator = _createForOfIteratorHelper(props.views.entries()),
      _step;
    try {
      var _loop = function _loop() {
        var _step$value = (0, _slicedToArray2["default"])(_step.value, 2),
          index = _step$value[0],
          view = _step$value[1];
        views.push( /*#__PURE__*/_react["default"].createElement("li", {
          key: index,
          onClick: function onClick() {
            return viewClicked(index);
          },
          className: index === activeView ? 'active' : null
        }, /*#__PURE__*/_react["default"].createElement("a", {
          "data-target": "".concat(index, "_panel_content")
        }, view['title'])));
        content.push( /*#__PURE__*/_react["default"].createElement("div", {
          key: index,
          id: "".concat(index, "_panel_content_").concat(props.id),
          className: index === activeView ? "".concat(index, "_panel_content") : "".concat(index, "_panel_content hidden")
        }, view['content']));
      };
      for (_iterator.s(); !(_step = _iterator.n()).done;) {
        _loop();
      }
    } catch (err) {
      _iterator.e(err);
    } finally {
      _iterator.f();
    }
    panelViews = /*#__PURE__*/_react["default"].createElement("div", {
      className: "btn-group views"
    }, /*#__PURE__*/_react["default"].createElement("button", {
      type: "button",
      className: "btn btn-default btn-xs dropdown-toggle",
      "data-toggle": "dropdown"
    }, "Views", /*#__PURE__*/_react["default"].createElement("span", {
      className: "caret"
    })), /*#__PURE__*/_react["default"].createElement("ul", {
      className: "dropdown-menu pull-right",
      role: "menu"
    }, views));
  }
  // Panel Views (END)

  // Add panel header, if title is set
  var panelHeading = props.title || props.views ? /*#__PURE__*/_react["default"].createElement("div", {
    className: "panel-heading",
    "data-parent": props.parentId ? "#".concat(props.parentId) : null
  }, /*#__PURE__*/_react["default"].createElement("h3", {
    className: "panel-title"
  }, props.views && props.views[activeView]['title'] ? props.views[activeView]['title'] : props.title), panelViews, props.collapsing ? /*#__PURE__*/_react["default"].createElement("span", {
    className: collapsed ? 'glyphicon glyphicon-chevron-down' : 'glyphicon glyphicon-chevron-up',
    onClick: toggleCollapsed,
    "data-toggle": "collapse",
    "data-target": "#".concat(props.id),
    style: {
      cursor: 'pointer'
    }
  }) : null) : '';

  /**
   * Renders the React component.
   * @return {JSX.Element} - React markup for component.
   */
  return /*#__PURE__*/_react["default"].createElement("div", {
    className: "panel ".concat(props["class"]),
    style: {
      height: props.panelSize
    }
  }, panelHeading, /*#__PURE__*/_react["default"].createElement("div", {
    id: props.id,
    className: props.collapsed ? 'panel-collapse collapse' : 'panel-collapse collapse in',
    role: "tabpanel",
    style: {
      height: 'calc(100% - 3em)'
    }
  }, /*#__PURE__*/_react["default"].createElement("div", {
    className: "panel-body",
    style: _objectSpread(_objectSpread({}, props.style), {}, {
      height: props.height
    })
  }, content.length > 0 ? content : props.children)));
};
Panel.propTypes = (0, _defineProperty2["default"])({
  initCollapsed: _propTypes["default"].bool,
  collapsed: _propTypes["default"].bool,
  parentId: _propTypes["default"].string,
  id: _propTypes["default"].string,
  height: _propTypes["default"].string,
  title: _propTypes["default"].string,
  "class": _propTypes["default"].string,
  children: _propTypes["default"].node,
  views: _propTypes["default"].array,
  onChangeView: _propTypes["default"].func,
  collapsing: _propTypes["default"].bool,
  bold: _propTypes["default"].bool,
  panelSize: _propTypes["default"].string,
  style: _propTypes["default"].object
}, "children", _propTypes["default"].node);
Panel.defaultProps = {
  initCollapsed: false,
  parentId: null,
  id: 'default-panel',
  height: '100%',
  "class": 'panel-primary',
  collapsing: true
};
var _default = exports["default"] = Panel;

/***/ }),

/***/ "./jsx/ProgressBar.js":
/*!****************************!*\
  !*** ./jsx/ProgressBar.js ***!
  \****************************/
/***/ ((__unused_webpack_module, exports, __webpack_require__) => {

"use strict";


var _interopRequireDefault = __webpack_require__(/*! @babel/runtime/helpers/interopRequireDefault */ "./node_modules/@babel/runtime/helpers/interopRequireDefault.js");
var _typeof = __webpack_require__(/*! @babel/runtime/helpers/typeof */ "./node_modules/@babel/runtime/helpers/typeof.js");
Object.defineProperty(exports, "__esModule", ({
  value: true
}));
exports["default"] = void 0;
var _classCallCheck2 = _interopRequireDefault(__webpack_require__(/*! @babel/runtime/helpers/classCallCheck */ "./node_modules/@babel/runtime/helpers/classCallCheck.js"));
var _createClass2 = _interopRequireDefault(__webpack_require__(/*! @babel/runtime/helpers/createClass */ "./node_modules/@babel/runtime/helpers/createClass.js"));
var _inherits2 = _interopRequireDefault(__webpack_require__(/*! @babel/runtime/helpers/inherits */ "./node_modules/@babel/runtime/helpers/inherits.js"));
var _possibleConstructorReturn2 = _interopRequireDefault(__webpack_require__(/*! @babel/runtime/helpers/possibleConstructorReturn */ "./node_modules/@babel/runtime/helpers/possibleConstructorReturn.js"));
var _getPrototypeOf2 = _interopRequireDefault(__webpack_require__(/*! @babel/runtime/helpers/getPrototypeOf */ "./node_modules/@babel/runtime/helpers/getPrototypeOf.js"));
var _react = _interopRequireWildcard(__webpack_require__(/*! react */ "react"));
var _propTypes = _interopRequireDefault(__webpack_require__(/*! prop-types */ "./node_modules/prop-types/index.js"));
function _getRequireWildcardCache(e) { if ("function" != typeof WeakMap) return null; var r = new WeakMap(), t = new WeakMap(); return (_getRequireWildcardCache = function _getRequireWildcardCache(e) { return e ? t : r; })(e); }
function _interopRequireWildcard(e, r) { if (!r && e && e.__esModule) return e; if (null === e || "object" != _typeof(e) && "function" != typeof e) return { "default": e }; var t = _getRequireWildcardCache(r); if (t && t.has(e)) return t.get(e); var n = { __proto__: null }, a = Object.defineProperty && Object.getOwnPropertyDescriptor; for (var u in e) { if ("default" !== u && {}.hasOwnProperty.call(e, u)) { var i = a ? Object.getOwnPropertyDescriptor(e, u) : null; i && (i.get || i.set) ? Object.defineProperty(n, u, i) : n[u] = e[u]; } } return n["default"] = e, t && t.set(e, n), n; }
function _createSuper(t) { var r = _isNativeReflectConstruct(); return function () { var e, o = (0, _getPrototypeOf2["default"])(t); if (r) { var s = (0, _getPrototypeOf2["default"])(this).constructor; e = Reflect.construct(o, arguments, s); } else e = o.apply(this, arguments); return (0, _possibleConstructorReturn2["default"])(this, e); }; }
function _isNativeReflectConstruct() { try { var t = !Boolean.prototype.valueOf.call(Reflect.construct(Boolean, [], function () {})); } catch (t) {} return (_isNativeReflectConstruct = function _isNativeReflectConstruct() { return !!t; })(); }
/**
 * React ProgressBar.
 *
 * Updates UI automatically when passed a progress value between 0 and 100.
 * To hide progress bar before/after upload, set value to -1.
 *
 * Note: This component relies on Bootstrap 3 progress-bar classes
 * (http://getbootstrap.com/components/#progress)
 */
var ProgressBar = /*#__PURE__*/function (_Component) {
  (0, _inherits2["default"])(ProgressBar, _Component);
  var _super = _createSuper(ProgressBar);
  function ProgressBar() {
    (0, _classCallCheck2["default"])(this, ProgressBar);
    return _super.apply(this, arguments);
  }
  (0, _createClass2["default"])(ProgressBar, [{
    key: "render",
    value:
    /**
     * Renders the React component.
     * @return {JSX} - React markup for the component
     */
    function render() {
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
      return /*#__PURE__*/_react["default"].createElement("div", {
        className: "progress",
        style: progressStyle
      }, /*#__PURE__*/_react["default"].createElement("div", {
        className: "progress-bar progress-bar-striped active",
        role: "progressbar",
        "aria-valuemin": "0",
        "aria-valuemax": "100",
        "aria-valuenow": this.props.value,
        style: {
          width: this.props.value + '%'
        }
      }), /*#__PURE__*/_react["default"].createElement("span", {
        style: labelStyle
      }, this.props.value, "%"));
    }
  }]);
  return ProgressBar;
}(_react.Component);
ProgressBar.propTypes = {
  value: _propTypes["default"].number
};
ProgressBar.defaultProps = {
  value: 0
};
var _default = exports["default"] = ProgressBar;

/***/ }),

/***/ "./jsx/Loader.tsx":
/*!************************!*\
  !*** ./jsx/Loader.tsx ***!
  \************************/
/***/ ((__unused_webpack_module, exports) => {

"use strict";


Object.defineProperty(exports, "__esModule", ({
  value: true
}));
/**
 * Loader component renders a spinner wheel of a specified size.
 * @param {LoaderProps} props - The properties for the Loader component
 * @returns {JSX.Element} A div representing the loading spinner
 */
var Loader = function Loader(_a) {
  var _b = _a.size,
    size = _b === void 0 ? 120 : _b;
  var loaderStyle = {
    width: size,
    height: size,
    borderWidth: size / 15
  };
  return /*#__PURE__*/React.createElement("div", {
    className: "loader",
    style: loaderStyle
  });
};
exports["default"] = Loader;

/***/ }),

/***/ "./jsx/form/DateTimePartialElement.tsx":
/*!*********************************************!*\
  !*** ./jsx/form/DateTimePartialElement.tsx ***!
  \*********************************************/
/***/ ((__unused_webpack_module, exports, __webpack_require__) => {

"use strict";


var __read = void 0 && (void 0).__read || function (o, n) {
  var m = typeof Symbol === "function" && o[Symbol.iterator];
  if (!m) return o;
  var i = m.call(o),
    r,
    ar = [],
    e;
  try {
    while ((n === void 0 || n-- > 0) && !(r = i.next()).done) {
      ar.push(r.value);
    }
  } catch (error) {
    e = {
      error: error
    };
  } finally {
    try {
      if (r && !r.done && (m = i["return"])) m.call(i);
    } finally {
      if (e) throw e.error;
    }
  }
  return ar;
};
var __importDefault = void 0 && (void 0).__importDefault || function (mod) {
  return mod && mod.__esModule ? mod : {
    "default": mod
  };
};
Object.defineProperty(exports, "__esModule", ({
  value: true
}));
var react_1 = __webpack_require__(/*! react */ "react");
var InputLabel_1 = __importDefault(__webpack_require__(/*! jsx/form/InputLabel */ "./jsx/form/InputLabel.tsx"));
var format = 'YYYY-MM-DD hh:mm:ss';
/**
 * Check if a character is a digit.
 * @param character The character to check
 * @returns The result of the check
 */
function isDigit(character) {
  return character >= '0' && character <= '9';
}
/**
 * Check if a character is a letter.
 * @param character A character to check
 * @returns The result of the check
 */
function isLetter(character) {
  return character >= 'A' && character <= 'Z' || character >= 'a' && character <= 'z';
}
/**
 * Insert a string inside another string at a given index.
 * @param string The string in which the substring is to be inserted
 * @param index The index at which to insert the substring
 * @param other The substring to insert
 * @returns The new string
 */
function stringInsert(string, index, other) {
  return string.slice(0, index) + other + string.slice(index);
}
/**
 * Checks if a value matches the datetime format, formatting it if necessary.
 * @param oldDateTime The old value of the input (which is valid)
 * @param newDateTime The new value of the input (which may be invalid)
 * @returns The formatted new value, or `null` if the new value is invalid
 */
function formatDatetime(oldDateTime, newDateTime) {
  for (var i = 0; i < newDateTime.length; i++) {
    // Check that the new value is no longer than the format.
    // This check is done inside the loop because the value might grow during
    // formatting.
    if (i >= format.length) {
      return null;
    }
    // Check that each new value character matches that expected from the
    // format.
    var valueChar = newDateTime[i];
    var formatChar = format[i];
    if (isLetter(formatChar)) {
      if (!isDigit(valueChar)) {
        return null;
      }
    } else {
      if (isDigit(valueChar)) {
        newDateTime = stringInsert(newDateTime, i, formatChar);
      } else if (valueChar !== formatChar) {
        return null;
      }
    }
  }
  // If a character was added, add a special character if it is expected from
  // the format.
  if (newDateTime.length > oldDateTime.length && newDateTime.length < format.length) {
    var nextChar = format[newDateTime.length];
    if (!isLetter(nextChar)) {
      newDateTime += nextChar;
    }
  }
  // If a character was removed, remove a special character if it is expected
  // from the format.
  if (newDateTime.length < oldDateTime.length && newDateTime.length > 0) {
    var prevChar = format[newDateTime.length - 1];
    if (!isLetter(prevChar)) {
      newDateTime = newDateTime.slice(0, -1);
    }
  }
  return newDateTime;
}
/**
 * React component for an input datetime mask.
 * @param props The props of the component
 * @param props.value
 * @param props.children
 * @returns The corresponding React element
 */
var Mask = function Mask(_a) {
  var value = _a.value,
    children = _a.children;
  return /*#__PURE__*/React.createElement("div", {
    style: {
      position: 'relative'
    }
  }, children, /*#__PURE__*/React.createElement("div", {
    className: "form-control",
    style: {
      position: 'absolute',
      top: 0,
      left: 0,
      backgroundColor: 'transparent',
      borderColor: 'transparent',
      boxShadow: 'none',
      pointerEvents: 'none'
    }
  }, /*#__PURE__*/React.createElement("div", {
    style: {
      fontFamily: 'monospace',
      color: '#777777',
      overflow: 'hidden',
      whiteSpace: 'nowrap'
    }
  }, "\xA0".repeat(value.length), format.slice(value.length))));
};
/**
 * Datetime input (down to the second) React component
 * Compared to the standard HTML input, this input accepts incomplete datetimes
 * (useful for filtering).
 * @param props The props of the component
 * @returns The corresponding React element
 */
var DateTimePartialElement = function DateTimePartialElement(props) {
  var _a;
  var onUserInput = props.onUserInput !== undefined ? props.onUserInput : function () {
    return console.warn('onUserInput() callback is not set');
  };
  var _b = __read((0, react_1.useState)((_a = props.value) !== null && _a !== void 0 ? _a : ''), 2),
    value = _b[0],
    setValue = _b[1];
  /**
   * Handle a change in the input.
   * @param e The React event.
   */
  function handleChange(e) {
    var rawValue = e.target.value.replace(/[- :]/g, '');
    var newValue = formatDatetime(value, rawValue);
    if (newValue === null) {
      return;
    }
    setValue(newValue);
    onUserInput(props.name, newValue);
  }
  var errorMessage = null;
  var elementClass = 'row form-group';
  if (props.required && value == '') {
    errorMessage = /*#__PURE__*/React.createElement("span", null, "This field is required");
    elementClass += ' has-error';
  } else if (props.errorMessage) {
    errorMessage = /*#__PURE__*/React.createElement("span", null, props.errorMessage);
    elementClass += ' has-error';
  }
  var wrapperClass = props.label ? 'col-sm-9' : 'col-sm-12';
  return /*#__PURE__*/React.createElement("div", {
    className: elementClass
  }, props.label && /*#__PURE__*/React.createElement(InputLabel_1["default"], {
    label: props.label,
    required: props.required
  }), /*#__PURE__*/React.createElement("div", {
    className: wrapperClass
  }, /*#__PURE__*/React.createElement(Mask, {
    value: value
  }, /*#__PURE__*/React.createElement("input", {
    className: "form-control",
    name: props.name,
    id: props.id,
    onChange: handleChange,
    value: value,
    required: props.required,
    disabled: props.disabled,
    style: {
      fontFamily: 'monospace'
    }
  })), errorMessage));
};
exports["default"] = DateTimePartialElement;

/***/ }),

/***/ "./jsx/form/InputLabel.tsx":
/*!*********************************!*\
  !*** ./jsx/form/InputLabel.tsx ***!
  \*********************************/
/***/ ((__unused_webpack_module, exports) => {

"use strict";


Object.defineProperty(exports, "__esModule", ({
  value: true
}));
/**
 * Input label React component
 * @param props The props of the component
 * @param props.label
 * @param props.required
 * @returns The corresponding React element
 */
var InputLabel = function InputLabel(_a) {
  var label = _a.label,
    required = _a.required;
  return /*#__PURE__*/React.createElement("label", {
    className: "col-sm-3 control-label",
    htmlFor: label
  }, label, required && /*#__PURE__*/React.createElement("span", {
    className: "text-danger"
  }, "*"));
};
exports["default"] = InputLabel;

/***/ }),

/***/ "./node_modules/fbjs/lib/emptyFunction.js":
/*!************************************************!*\
  !*** ./node_modules/fbjs/lib/emptyFunction.js ***!
  \************************************************/
/***/ ((module) => {

"use strict";


/**
 * Copyright (c) 2013-present, Facebook, Inc.
 *
 * This source code is licensed under the MIT license found in the
 * LICENSE file in the root directory of this source tree.
 *
 * 
 */

function makeEmptyFunction(arg) {
  return function () {
    return arg;
  };
}

/**
 * This function accepts and discards inputs; it has no side effects. This is
 * primarily useful idiomatically for overridable function endpoints which
 * always need to be callable, since JS lacks a null-call idiom ala Cocoa.
 */
var emptyFunction = function emptyFunction() {};

emptyFunction.thatReturns = makeEmptyFunction;
emptyFunction.thatReturnsFalse = makeEmptyFunction(false);
emptyFunction.thatReturnsTrue = makeEmptyFunction(true);
emptyFunction.thatReturnsNull = makeEmptyFunction(null);
emptyFunction.thatReturnsThis = function () {
  return this;
};
emptyFunction.thatReturnsArgument = function (arg) {
  return arg;
};

module.exports = emptyFunction;

/***/ }),

/***/ "./node_modules/fbjs/lib/invariant.js":
/*!********************************************!*\
  !*** ./node_modules/fbjs/lib/invariant.js ***!
  \********************************************/
/***/ ((module) => {

"use strict";
/**
 * Copyright (c) 2013-present, Facebook, Inc.
 *
 * This source code is licensed under the MIT license found in the
 * LICENSE file in the root directory of this source tree.
 *
 */



/**
 * Use invariant() to assert state which your program assumes to be true.
 *
 * Provide sprintf-style format (only %s is supported) and arguments
 * to provide information about what broke and what you were
 * expecting.
 *
 * The invariant message will be stripped in production, but the invariant
 * will remain to ensure logic does not differ in production.
 */

var validateFormat = function validateFormat(format) {};

if (true) {
  validateFormat = function validateFormat(format) {
    if (format === undefined) {
      throw new Error('invariant requires an error message argument');
    }
  };
}

function invariant(condition, format, a, b, c, d, e, f) {
  validateFormat(format);

  if (!condition) {
    var error;
    if (format === undefined) {
      error = new Error('Minified exception occurred; use the non-minified dev environment ' + 'for the full error message and additional helpful warnings.');
    } else {
      var args = [a, b, c, d, e, f];
      var argIndex = 0;
      error = new Error(format.replace(/%s/g, function () {
        return args[argIndex++];
      }));
      error.name = 'Invariant Violation';
    }

    error.framesToPop = 1; // we don't care about invariant's own frame
    throw error;
  }
}

module.exports = invariant;

/***/ }),

/***/ "./node_modules/fbjs/lib/warning.js":
/*!******************************************!*\
  !*** ./node_modules/fbjs/lib/warning.js ***!
  \******************************************/
/***/ ((module, __unused_webpack_exports, __webpack_require__) => {

"use strict";
/**
 * Copyright (c) 2014-present, Facebook, Inc.
 *
 * This source code is licensed under the MIT license found in the
 * LICENSE file in the root directory of this source tree.
 *
 */



var emptyFunction = __webpack_require__(/*! ./emptyFunction */ "./node_modules/fbjs/lib/emptyFunction.js");

/**
 * Similar to invariant but only logs a warning if the condition is not met.
 * This can be used to log issues in development environments in critical
 * paths. Removing the logging code for production environments will keep the
 * same logic and follow the same code paths.
 */

var warning = emptyFunction;

if (true) {
  var printWarning = function printWarning(format) {
    for (var _len = arguments.length, args = Array(_len > 1 ? _len - 1 : 0), _key = 1; _key < _len; _key++) {
      args[_key - 1] = arguments[_key];
    }

    var argIndex = 0;
    var message = 'Warning: ' + format.replace(/%s/g, function () {
      return args[argIndex++];
    });
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

  warning = function warning(condition, format) {
    if (format === undefined) {
      throw new Error('`warning(condition, format, ...args)` requires a warning ' + 'message argument');
    }

    if (format.indexOf('Failed Composite propType: ') === 0) {
      return; // Ignore CompositeComponent proptype check.
    }

    if (!condition) {
      for (var _len2 = arguments.length, args = Array(_len2 > 2 ? _len2 - 2 : 0), _key2 = 2; _key2 < _len2; _key2++) {
        args[_key2 - 2] = arguments[_key2];
      }

      printWarning.apply(undefined, [format].concat(args));
    }
  };
}

module.exports = warning;

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

/***/ "./node_modules/react-addons-create-fragment/index.js":
/*!************************************************************!*\
  !*** ./node_modules/react-addons-create-fragment/index.js ***!
  \************************************************************/
/***/ ((module, __unused_webpack_exports, __webpack_require__) => {

"use strict";
/**
 * Copyright (c) 2015-present, Facebook, Inc.
 *
 * This source code is licensed under the MIT license found in the
 * LICENSE file in the root directory of this source tree.
 */



var React = __webpack_require__(/*! react */ "react");

var REACT_ELEMENT_TYPE =
  (typeof Symbol === 'function' && Symbol.for && Symbol.for('react.element')) ||
  0xeac7;

var emptyFunction = __webpack_require__(/*! fbjs/lib/emptyFunction */ "./node_modules/fbjs/lib/emptyFunction.js");
var invariant = __webpack_require__(/*! fbjs/lib/invariant */ "./node_modules/fbjs/lib/invariant.js");
var warning = __webpack_require__(/*! fbjs/lib/warning */ "./node_modules/fbjs/lib/warning.js");

var SEPARATOR = '.';
var SUBSEPARATOR = ':';

var didWarnAboutMaps = false;

var ITERATOR_SYMBOL = typeof Symbol === 'function' && Symbol.iterator;
var FAUX_ITERATOR_SYMBOL = '@@iterator'; // Before Symbol spec.

function getIteratorFn(maybeIterable) {
  var iteratorFn =
    maybeIterable &&
    ((ITERATOR_SYMBOL && maybeIterable[ITERATOR_SYMBOL]) ||
      maybeIterable[FAUX_ITERATOR_SYMBOL]);
  if (typeof iteratorFn === 'function') {
    return iteratorFn;
  }
}

function escape(key) {
  var escapeRegex = /[=:]/g;
  var escaperLookup = {
    '=': '=0',
    ':': '=2'
  };
  var escapedString = ('' + key).replace(escapeRegex, function(match) {
    return escaperLookup[match];
  });

  return '$' + escapedString;
}

function getComponentKey(component, index) {
  // Do some typechecking here since we call this blindly. We want to ensure
  // that we don't block potential future ES APIs.
  if (component && typeof component === 'object' && component.key != null) {
    // Explicit key
    return escape(component.key);
  }
  // Implicit key determined by the index in the set
  return index.toString(36);
}

function traverseAllChildrenImpl(
  children,
  nameSoFar,
  callback,
  traverseContext
) {
  var type = typeof children;

  if (type === 'undefined' || type === 'boolean') {
    // All of the above are perceived as null.
    children = null;
  }

  if (
    children === null ||
    type === 'string' ||
    type === 'number' ||
    // The following is inlined from ReactElement. This means we can optimize
    // some checks. React Fiber also inlines this logic for similar purposes.
    (type === 'object' && children.$$typeof === REACT_ELEMENT_TYPE)
  ) {
    callback(
      traverseContext,
      children,
      // If it's the only child, treat the name as if it was wrapped in an array
      // so that it's consistent if the number of children grows.
      nameSoFar === '' ? SEPARATOR + getComponentKey(children, 0) : nameSoFar
    );
    return 1;
  }

  var child;
  var nextName;
  var subtreeCount = 0; // Count of children found in the current subtree.
  var nextNamePrefix = nameSoFar === '' ? SEPARATOR : nameSoFar + SUBSEPARATOR;

  if (Array.isArray(children)) {
    for (var i = 0; i < children.length; i++) {
      child = children[i];
      nextName = nextNamePrefix + getComponentKey(child, i);
      subtreeCount += traverseAllChildrenImpl(
        child,
        nextName,
        callback,
        traverseContext
      );
    }
  } else {
    var iteratorFn = getIteratorFn(children);
    if (iteratorFn) {
      if (true) {
        // Warn about using Maps as children
        if (iteratorFn === children.entries) {
          warning(
            didWarnAboutMaps,
            'Using Maps as children is unsupported and will likely yield ' +
              'unexpected results. Convert it to a sequence/iterable of keyed ' +
              'ReactElements instead.'
          );
          didWarnAboutMaps = true;
        }
      }

      var iterator = iteratorFn.call(children);
      var step;
      var ii = 0;
      while (!(step = iterator.next()).done) {
        child = step.value;
        nextName = nextNamePrefix + getComponentKey(child, ii++);
        subtreeCount += traverseAllChildrenImpl(
          child,
          nextName,
          callback,
          traverseContext
        );
      }
    } else if (type === 'object') {
      var addendum = '';
      if (true) {
        addendum =
          ' If you meant to render a collection of children, use an array ' +
          'instead or wrap the object using createFragment(object) from the ' +
          'React add-ons.';
      }
      var childrenString = '' + children;
      invariant(
        false,
        'Objects are not valid as a React child (found: %s).%s',
        childrenString === '[object Object]'
          ? 'object with keys {' + Object.keys(children).join(', ') + '}'
          : childrenString,
        addendum
      );
    }
  }

  return subtreeCount;
}

function traverseAllChildren(children, callback, traverseContext) {
  if (children == null) {
    return 0;
  }

  return traverseAllChildrenImpl(children, '', callback, traverseContext);
}

var userProvidedKeyEscapeRegex = /\/+/g;
function escapeUserProvidedKey(text) {
  return ('' + text).replace(userProvidedKeyEscapeRegex, '$&/');
}

function cloneAndReplaceKey(oldElement, newKey) {
  return React.cloneElement(
    oldElement,
    {key: newKey},
    oldElement.props !== undefined ? oldElement.props.children : undefined
  );
}

var DEFAULT_POOL_SIZE = 10;
var DEFAULT_POOLER = oneArgumentPooler;

var oneArgumentPooler = function(copyFieldsFrom) {
  var Klass = this;
  if (Klass.instancePool.length) {
    var instance = Klass.instancePool.pop();
    Klass.call(instance, copyFieldsFrom);
    return instance;
  } else {
    return new Klass(copyFieldsFrom);
  }
};

var addPoolingTo = function addPoolingTo(CopyConstructor, pooler) {
  // Casting as any so that flow ignores the actual implementation and trusts
  // it to match the type we declared
  var NewKlass = CopyConstructor;
  NewKlass.instancePool = [];
  NewKlass.getPooled = pooler || DEFAULT_POOLER;
  if (!NewKlass.poolSize) {
    NewKlass.poolSize = DEFAULT_POOL_SIZE;
  }
  NewKlass.release = standardReleaser;
  return NewKlass;
};

var standardReleaser = function standardReleaser(instance) {
  var Klass = this;
  invariant(
    instance instanceof Klass,
    'Trying to release an instance into a pool of a different type.'
  );
  instance.destructor();
  if (Klass.instancePool.length < Klass.poolSize) {
    Klass.instancePool.push(instance);
  }
};

var fourArgumentPooler = function fourArgumentPooler(a1, a2, a3, a4) {
  var Klass = this;
  if (Klass.instancePool.length) {
    var instance = Klass.instancePool.pop();
    Klass.call(instance, a1, a2, a3, a4);
    return instance;
  } else {
    return new Klass(a1, a2, a3, a4);
  }
};

function MapBookKeeping(mapResult, keyPrefix, mapFunction, mapContext) {
  this.result = mapResult;
  this.keyPrefix = keyPrefix;
  this.func = mapFunction;
  this.context = mapContext;
  this.count = 0;
}
MapBookKeeping.prototype.destructor = function() {
  this.result = null;
  this.keyPrefix = null;
  this.func = null;
  this.context = null;
  this.count = 0;
};
addPoolingTo(MapBookKeeping, fourArgumentPooler);

function mapSingleChildIntoContext(bookKeeping, child, childKey) {
  var result = bookKeeping.result;
  var keyPrefix = bookKeeping.keyPrefix;
  var func = bookKeeping.func;
  var context = bookKeeping.context;

  var mappedChild = func.call(context, child, bookKeeping.count++);
  if (Array.isArray(mappedChild)) {
    mapIntoWithKeyPrefixInternal(
      mappedChild,
      result,
      childKey,
      emptyFunction.thatReturnsArgument
    );
  } else if (mappedChild != null) {
    if (React.isValidElement(mappedChild)) {
      mappedChild = cloneAndReplaceKey(
        mappedChild,
        // Keep both the (mapped) and old keys if they differ, just as
        // traverseAllChildren used to do for objects as children
        keyPrefix +
          (mappedChild.key && (!child || child.key !== mappedChild.key)
            ? escapeUserProvidedKey(mappedChild.key) + '/'
            : '') +
          childKey
      );
    }
    result.push(mappedChild);
  }
}

function mapIntoWithKeyPrefixInternal(children, array, prefix, func, context) {
  var escapedPrefix = '';
  if (prefix != null) {
    escapedPrefix = escapeUserProvidedKey(prefix) + '/';
  }
  var traverseContext = MapBookKeeping.getPooled(
    array,
    escapedPrefix,
    func,
    context
  );
  traverseAllChildren(children, mapSingleChildIntoContext, traverseContext);
  MapBookKeeping.release(traverseContext);
}

var numericPropertyRegex = /^\d+$/;

var warnedAboutNumeric = false;

function createReactFragment(object) {
  if (typeof object !== 'object' || !object || Array.isArray(object)) {
    warning(
      false,
      'React.addons.createFragment only accepts a single object. Got: %s',
      object
    );
    return object;
  }
  if (React.isValidElement(object)) {
    warning(
      false,
      'React.addons.createFragment does not accept a ReactElement ' +
        'without a wrapper object.'
    );
    return object;
  }

  invariant(
    object.nodeType !== 1,
    'React.addons.createFragment(...): Encountered an invalid child; DOM ' +
      'elements are not valid children of React components.'
  );

  var result = [];

  for (var key in object) {
    if (true) {
      if (!warnedAboutNumeric && numericPropertyRegex.test(key)) {
        warning(
          false,
          'React.addons.createFragment(...): Child objects should have ' +
            'non-numeric keys so ordering is preserved.'
        );
        warnedAboutNumeric = true;
      }
    }
    mapIntoWithKeyPrefixInternal(
      object[key],
      result,
      key,
      emptyFunction.thatReturnsArgument
    );
  }

  return result;
}

module.exports = createReactFragment;


/***/ }),

/***/ "./node_modules/react-dom/client.js":
/*!******************************************!*\
  !*** ./node_modules/react-dom/client.js ***!
  \******************************************/
/***/ ((__unused_webpack_module, exports, __webpack_require__) => {

"use strict";


var m = __webpack_require__(/*! react-dom */ "react-dom");
if (false) {} else {
  var i = m.__SECRET_INTERNALS_DO_NOT_USE_OR_YOU_WILL_BE_FIRED;
  exports.createRoot = function(c, o) {
    i.usingClientEntryPoint = true;
    try {
      return m.createRoot(c, o);
    } finally {
      i.usingClientEntryPoint = false;
    }
  };
  exports.hydrateRoot = function(c, h, o) {
    i.usingClientEntryPoint = true;
    try {
      return m.hydrateRoot(c, h, o);
    } finally {
      i.usingClientEntryPoint = false;
    }
  };
}


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

/***/ "react-dom":
/*!***************************!*\
  !*** external "ReactDOM" ***!
  \***************************/
/***/ ((module) => {

"use strict";
module.exports = window["ReactDOM"];

/***/ }),

/***/ "./node_modules/@babel/runtime/helpers/arrayLikeToArray.js":
/*!*****************************************************************!*\
  !*** ./node_modules/@babel/runtime/helpers/arrayLikeToArray.js ***!
  \*****************************************************************/
/***/ ((module) => {

function _arrayLikeToArray(arr, len) {
  if (len == null || len > arr.length) len = arr.length;

  for (var i = 0, arr2 = new Array(len); i < len; i++) {
    arr2[i] = arr[i];
  }

  return arr2;
}

module.exports = _arrayLikeToArray, module.exports.__esModule = true, module.exports["default"] = module.exports;

/***/ }),

/***/ "./node_modules/@babel/runtime/helpers/arrayWithHoles.js":
/*!***************************************************************!*\
  !*** ./node_modules/@babel/runtime/helpers/arrayWithHoles.js ***!
  \***************************************************************/
/***/ ((module) => {

function _arrayWithHoles(arr) {
  if (Array.isArray(arr)) return arr;
}

module.exports = _arrayWithHoles, module.exports.__esModule = true, module.exports["default"] = module.exports;

/***/ }),

/***/ "./node_modules/@babel/runtime/helpers/assertThisInitialized.js":
/*!**********************************************************************!*\
  !*** ./node_modules/@babel/runtime/helpers/assertThisInitialized.js ***!
  \**********************************************************************/
/***/ ((module) => {

function _assertThisInitialized(self) {
  if (self === void 0) {
    throw new ReferenceError("this hasn't been initialised - super() hasn't been called");
  }

  return self;
}

module.exports = _assertThisInitialized, module.exports.__esModule = true, module.exports["default"] = module.exports;

/***/ }),

/***/ "./node_modules/@babel/runtime/helpers/classCallCheck.js":
/*!***************************************************************!*\
  !*** ./node_modules/@babel/runtime/helpers/classCallCheck.js ***!
  \***************************************************************/
/***/ ((module) => {

function _classCallCheck(instance, Constructor) {
  if (!(instance instanceof Constructor)) {
    throw new TypeError("Cannot call a class as a function");
  }
}

module.exports = _classCallCheck, module.exports.__esModule = true, module.exports["default"] = module.exports;

/***/ }),

/***/ "./node_modules/@babel/runtime/helpers/createClass.js":
/*!************************************************************!*\
  !*** ./node_modules/@babel/runtime/helpers/createClass.js ***!
  \************************************************************/
/***/ ((module) => {

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

module.exports = _createClass, module.exports.__esModule = true, module.exports["default"] = module.exports;

/***/ }),

/***/ "./node_modules/@babel/runtime/helpers/defineProperty.js":
/*!***************************************************************!*\
  !*** ./node_modules/@babel/runtime/helpers/defineProperty.js ***!
  \***************************************************************/
/***/ ((module) => {

function _defineProperty(obj, key, value) {
  if (key in obj) {
    Object.defineProperty(obj, key, {
      value: value,
      enumerable: true,
      configurable: true,
      writable: true
    });
  } else {
    obj[key] = value;
  }

  return obj;
}

module.exports = _defineProperty, module.exports.__esModule = true, module.exports["default"] = module.exports;

/***/ }),

/***/ "./node_modules/@babel/runtime/helpers/getPrototypeOf.js":
/*!***************************************************************!*\
  !*** ./node_modules/@babel/runtime/helpers/getPrototypeOf.js ***!
  \***************************************************************/
/***/ ((module) => {

function _getPrototypeOf(o) {
  module.exports = _getPrototypeOf = Object.setPrototypeOf ? Object.getPrototypeOf.bind() : function _getPrototypeOf(o) {
    return o.__proto__ || Object.getPrototypeOf(o);
  }, module.exports.__esModule = true, module.exports["default"] = module.exports;
  return _getPrototypeOf(o);
}

module.exports = _getPrototypeOf, module.exports.__esModule = true, module.exports["default"] = module.exports;

/***/ }),

/***/ "./node_modules/@babel/runtime/helpers/inherits.js":
/*!*********************************************************!*\
  !*** ./node_modules/@babel/runtime/helpers/inherits.js ***!
  \*********************************************************/
/***/ ((module, __unused_webpack_exports, __webpack_require__) => {

var setPrototypeOf = __webpack_require__(/*! ./setPrototypeOf.js */ "./node_modules/@babel/runtime/helpers/setPrototypeOf.js");

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
  if (superClass) setPrototypeOf(subClass, superClass);
}

module.exports = _inherits, module.exports.__esModule = true, module.exports["default"] = module.exports;

/***/ }),

/***/ "./node_modules/@babel/runtime/helpers/interopRequireDefault.js":
/*!**********************************************************************!*\
  !*** ./node_modules/@babel/runtime/helpers/interopRequireDefault.js ***!
  \**********************************************************************/
/***/ ((module) => {

function _interopRequireDefault(obj) {
  return obj && obj.__esModule ? obj : {
    "default": obj
  };
}

module.exports = _interopRequireDefault, module.exports.__esModule = true, module.exports["default"] = module.exports;

/***/ }),

/***/ "./node_modules/@babel/runtime/helpers/iterableToArrayLimit.js":
/*!*********************************************************************!*\
  !*** ./node_modules/@babel/runtime/helpers/iterableToArrayLimit.js ***!
  \*********************************************************************/
/***/ ((module) => {

function _iterableToArrayLimit(arr, i) {
  var _i = arr == null ? null : typeof Symbol !== "undefined" && arr[Symbol.iterator] || arr["@@iterator"];

  if (_i == null) return;
  var _arr = [];
  var _n = true;
  var _d = false;

  var _s, _e;

  try {
    for (_i = _i.call(arr); !(_n = (_s = _i.next()).done); _n = true) {
      _arr.push(_s.value);

      if (i && _arr.length === i) break;
    }
  } catch (err) {
    _d = true;
    _e = err;
  } finally {
    try {
      if (!_n && _i["return"] != null) _i["return"]();
    } finally {
      if (_d) throw _e;
    }
  }

  return _arr;
}

module.exports = _iterableToArrayLimit, module.exports.__esModule = true, module.exports["default"] = module.exports;

/***/ }),

/***/ "./node_modules/@babel/runtime/helpers/nonIterableRest.js":
/*!****************************************************************!*\
  !*** ./node_modules/@babel/runtime/helpers/nonIterableRest.js ***!
  \****************************************************************/
/***/ ((module) => {

function _nonIterableRest() {
  throw new TypeError("Invalid attempt to destructure non-iterable instance.\nIn order to be iterable, non-array objects must have a [Symbol.iterator]() method.");
}

module.exports = _nonIterableRest, module.exports.__esModule = true, module.exports["default"] = module.exports;

/***/ }),

/***/ "./node_modules/@babel/runtime/helpers/possibleConstructorReturn.js":
/*!**************************************************************************!*\
  !*** ./node_modules/@babel/runtime/helpers/possibleConstructorReturn.js ***!
  \**************************************************************************/
/***/ ((module, __unused_webpack_exports, __webpack_require__) => {

var _typeof = (__webpack_require__(/*! ./typeof.js */ "./node_modules/@babel/runtime/helpers/typeof.js")["default"]);

var assertThisInitialized = __webpack_require__(/*! ./assertThisInitialized.js */ "./node_modules/@babel/runtime/helpers/assertThisInitialized.js");

function _possibleConstructorReturn(self, call) {
  if (call && (_typeof(call) === "object" || typeof call === "function")) {
    return call;
  } else if (call !== void 0) {
    throw new TypeError("Derived constructors may only return object or undefined");
  }

  return assertThisInitialized(self);
}

module.exports = _possibleConstructorReturn, module.exports.__esModule = true, module.exports["default"] = module.exports;

/***/ }),

/***/ "./node_modules/@babel/runtime/helpers/setPrototypeOf.js":
/*!***************************************************************!*\
  !*** ./node_modules/@babel/runtime/helpers/setPrototypeOf.js ***!
  \***************************************************************/
/***/ ((module) => {

function _setPrototypeOf(o, p) {
  module.exports = _setPrototypeOf = Object.setPrototypeOf ? Object.setPrototypeOf.bind() : function _setPrototypeOf(o, p) {
    o.__proto__ = p;
    return o;
  }, module.exports.__esModule = true, module.exports["default"] = module.exports;
  return _setPrototypeOf(o, p);
}

module.exports = _setPrototypeOf, module.exports.__esModule = true, module.exports["default"] = module.exports;

/***/ }),

/***/ "./node_modules/@babel/runtime/helpers/slicedToArray.js":
/*!**************************************************************!*\
  !*** ./node_modules/@babel/runtime/helpers/slicedToArray.js ***!
  \**************************************************************/
/***/ ((module, __unused_webpack_exports, __webpack_require__) => {

var arrayWithHoles = __webpack_require__(/*! ./arrayWithHoles.js */ "./node_modules/@babel/runtime/helpers/arrayWithHoles.js");

var iterableToArrayLimit = __webpack_require__(/*! ./iterableToArrayLimit.js */ "./node_modules/@babel/runtime/helpers/iterableToArrayLimit.js");

var unsupportedIterableToArray = __webpack_require__(/*! ./unsupportedIterableToArray.js */ "./node_modules/@babel/runtime/helpers/unsupportedIterableToArray.js");

var nonIterableRest = __webpack_require__(/*! ./nonIterableRest.js */ "./node_modules/@babel/runtime/helpers/nonIterableRest.js");

function _slicedToArray(arr, i) {
  return arrayWithHoles(arr) || iterableToArrayLimit(arr, i) || unsupportedIterableToArray(arr, i) || nonIterableRest();
}

module.exports = _slicedToArray, module.exports.__esModule = true, module.exports["default"] = module.exports;

/***/ }),

/***/ "./node_modules/@babel/runtime/helpers/typeof.js":
/*!*******************************************************!*\
  !*** ./node_modules/@babel/runtime/helpers/typeof.js ***!
  \*******************************************************/
/***/ ((module) => {

function _typeof(obj) {
  "@babel/helpers - typeof";

  return (module.exports = _typeof = "function" == typeof Symbol && "symbol" == typeof Symbol.iterator ? function (obj) {
    return typeof obj;
  } : function (obj) {
    return obj && "function" == typeof Symbol && obj.constructor === Symbol && obj !== Symbol.prototype ? "symbol" : typeof obj;
  }, module.exports.__esModule = true, module.exports["default"] = module.exports), _typeof(obj);
}

module.exports = _typeof, module.exports.__esModule = true, module.exports["default"] = module.exports;

/***/ }),

/***/ "./node_modules/@babel/runtime/helpers/unsupportedIterableToArray.js":
/*!***************************************************************************!*\
  !*** ./node_modules/@babel/runtime/helpers/unsupportedIterableToArray.js ***!
  \***************************************************************************/
/***/ ((module, __unused_webpack_exports, __webpack_require__) => {

var arrayLikeToArray = __webpack_require__(/*! ./arrayLikeToArray.js */ "./node_modules/@babel/runtime/helpers/arrayLikeToArray.js");

function _unsupportedIterableToArray(o, minLen) {
  if (!o) return;
  if (typeof o === "string") return arrayLikeToArray(o, minLen);
  var n = Object.prototype.toString.call(o).slice(8, -1);
  if (n === "Object" && o.constructor) n = o.constructor.name;
  if (n === "Map" || n === "Set") return Array.from(o);
  if (n === "Arguments" || /^(?:Ui|I)nt(?:8|16|32)(?:Clamped)?Array$/.test(n)) return arrayLikeToArray(o, minLen);
}

module.exports = _unsupportedIterableToArray, module.exports.__esModule = true, module.exports["default"] = module.exports;

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
var __webpack_exports__ = {};
// This entry need to be wrapped in an IIFE because it need to be in strict mode.
(() => {
"use strict";
/*!************************************************!*\
  !*** ./modules/help_editor/jsx/help_editor.js ***!
  \************************************************/


var _interopRequireDefault = __webpack_require__(/*! @babel/runtime/helpers/interopRequireDefault */ "./node_modules/@babel/runtime/helpers/interopRequireDefault.js");
var _classCallCheck2 = _interopRequireDefault(__webpack_require__(/*! @babel/runtime/helpers/classCallCheck */ "./node_modules/@babel/runtime/helpers/classCallCheck.js"));
var _createClass2 = _interopRequireDefault(__webpack_require__(/*! @babel/runtime/helpers/createClass */ "./node_modules/@babel/runtime/helpers/createClass.js"));
var _assertThisInitialized2 = _interopRequireDefault(__webpack_require__(/*! @babel/runtime/helpers/assertThisInitialized */ "./node_modules/@babel/runtime/helpers/assertThisInitialized.js"));
var _inherits2 = _interopRequireDefault(__webpack_require__(/*! @babel/runtime/helpers/inherits */ "./node_modules/@babel/runtime/helpers/inherits.js"));
var _possibleConstructorReturn2 = _interopRequireDefault(__webpack_require__(/*! @babel/runtime/helpers/possibleConstructorReturn */ "./node_modules/@babel/runtime/helpers/possibleConstructorReturn.js"));
var _getPrototypeOf2 = _interopRequireDefault(__webpack_require__(/*! @babel/runtime/helpers/getPrototypeOf */ "./node_modules/@babel/runtime/helpers/getPrototypeOf.js"));
var _FilterableDataTable = _interopRequireDefault(__webpack_require__(/*! FilterableDataTable */ "./jsx/FilterableDataTable.js"));
var _Loader = _interopRequireDefault(__webpack_require__(/*! Loader */ "./jsx/Loader.tsx"));
var _propTypes = _interopRequireDefault(__webpack_require__(/*! prop-types */ "./node_modules/prop-types/index.js"));
var _client = __webpack_require__(/*! react-dom/client */ "./node_modules/react-dom/client.js");
var _react = _interopRequireDefault(__webpack_require__(/*! react */ "react"));
function _createSuper(t) { var r = _isNativeReflectConstruct(); return function () { var e, o = (0, _getPrototypeOf2["default"])(t); if (r) { var s = (0, _getPrototypeOf2["default"])(this).constructor; e = Reflect.construct(o, arguments, s); } else e = o.apply(this, arguments); return (0, _possibleConstructorReturn2["default"])(this, e); }; }
function _isNativeReflectConstruct() { try { var t = !Boolean.prototype.valueOf.call(Reflect.construct(Boolean, [], function () {})); } catch (t) {} return (_isNativeReflectConstruct = function _isNativeReflectConstruct() { return !!t; })(); }
/**
 * Help Editor Archive Page.
 *
 * Serves as an entry-point to the module, rendering the whole react
 * component page on load.
 *
 * Renders Help Editor main page consisting of FilterForm and
 * StaticDataTable components.
 * @author LORIS Team
 * @version 1.0.0
 */
var HelpEditor = /*#__PURE__*/function (_React$Component) {
  (0, _inherits2["default"])(HelpEditor, _React$Component);
  var _super = _createSuper(HelpEditor);
  /**
   * @constructor
   * @param {object} props - React Component properties
   */
  function HelpEditor(props) {
    var _this;
    (0, _classCallCheck2["default"])(this, HelpEditor);
    _this = _super.call(this, props);
    _this.state = {
      data: {},
      fieldOptions: {},
      error: false,
      isLoaded: false
    };
    _this.fetchData = _this.fetchData.bind((0, _assertThisInitialized2["default"])(_this));
    _this.formatColumn = _this.formatColumn.bind((0, _assertThisInitialized2["default"])(_this));
    return _this;
  }

  /**
   * Called by React when the component has been rendered on the page.
   */
  (0, _createClass2["default"])(HelpEditor, [{
    key: "componentDidMount",
    value: function componentDidMount() {
      var _this2 = this;
      this.fetchData().then(function () {
        return _this2.setState({
          isLoaded: true
        });
      });
    }

    /**
     * Retrieve data from the provided URL and save it in state.
     * @return {object}
     */
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
          data: data
        });
      })["catch"](function (error) {
        _this3.setState({
          error: true
        });
        console.error(error);
      });
    }

    /**
     * Modify behaviour of specified column cells in the Data Table component
     * @param {string} column - column name
     * @param {string} cell - cell content
     * @param {object} row - row content indexed by column
     * @return {*} a formatted table cell for a given column
     */
  }, {
    key: "formatColumn",
    value: function formatColumn(column, cell, row) {
      var url;
      var result = /*#__PURE__*/_react["default"].createElement("td", null, cell);
      switch (column) {
        case 'Topic':
          url = loris.BaseURL + '/help_editor/edit_help_content/?helpID=' + row['Help ID'];
          result = /*#__PURE__*/_react["default"].createElement("td", null, /*#__PURE__*/_react["default"].createElement("a", {
            href: url
          }, cell));
          break;
      }
      return result;
    }

    /**
     * Renders the React component.
     * @return {JSX} - React markup for the component
     */
  }, {
    key: "render",
    value: function render() {
      // If error occurs, return a message.
      // XXX: Replace this with a UI component for 500 errors.
      if (this.state.error) {
        return /*#__PURE__*/_react["default"].createElement("h3", null, "An error occured while loading the page.");
      }

      // Waiting for async data to load
      if (!this.state.isLoaded) {
        return /*#__PURE__*/_react["default"].createElement(_Loader["default"], null);
      }
      var data = this.state.data;
      var addHelp = function addHelp() {
        window.location.replace(loris.BaseURL + '/help_editor/edit_help_content?helpID=null');
      };
      var actions = [{
        label: 'Adding help content for a specific instrument',
        action: addHelp
      }];
      /**
       * XXX: Currently, the order of these fields MUST match the order of the
       * queried columns in _setupVariables() in media.class.inc
       */
      var fields = [{
        label: 'Help ID',
        show: false
      }, {
        label: 'Topic',
        show: true,
        filter: {
          name: 'topic',
          type: 'text'
        }
      }, {
        label: 'Content',
        show: true,
        filter: {
          name: 'content',
          type: 'text'
        }
      }, {
        label: 'Instrument',
        show: true
      }];
      return /*#__PURE__*/_react["default"].createElement(_FilterableDataTable["default"], {
        name: "help_filter",
        data: data,
        fields: fields,
        actions: actions,
        getFormattedCell: this.formatColumn
      });
    }
  }]);
  return HelpEditor;
}(_react["default"].Component);
HelpEditor.propTypes = {
  dataURL: _propTypes["default"].string.isRequired
};
window.addEventListener('load', function () {
  (0, _client.createRoot)(document.getElementById('lorisworkspace')).render( /*#__PURE__*/_react["default"].createElement(HelpEditor, {
    Module: "help_editor",
    dataURL: loris.BaseURL + '/help_editor/?format=json'
  }));
});
})();

((window.lorisjs = window.lorisjs || {}).help_editor = window.lorisjs.help_editor || {}).help_editor = __webpack_exports__;
/******/ })()
;
//# sourceMappingURL=help_editor.js.map