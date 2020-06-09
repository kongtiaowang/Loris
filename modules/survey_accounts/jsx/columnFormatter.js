/* exported formatColumn */

/**
 * Modify behaviour of specified column cells in the Data Table component
 * @param {string} column - column name
 * @param {string} cell - cell content
 * @param {arrray} rowData - array of cell contents for a specific row
 * @param {arrray} rowHeaders - array of table headers (column names)
 * @return {*} a formated table cell for a given column
 */
loris.hiddenHeaders = ['Email'];
function formatColumn(column, cell, rowData, rowHeaders) {
    // If a column if set as hidden, don't display it
    if (loris.hiddenHeaders.indexOf(column) > -1) {
        return null;
    }
  // Create the mapping between rowHeaders and rowData in a row object.
  var row = {};
  rowHeaders.forEach(function(header, index) {
    row[header] = rowData[index];
  }, this);
  if (column === 'URL') {
      if (row.SurveyName === 'AP (Air Pollution) - Survey') {
          var url = loris.BaseURL + "/survey.php?key=" + row.URL;
          return (<td><a href={url}>{cell}</a></td>);
      }
      else{
          var url = loris.BaseURL + "/survey_module/?key=" + row.URL;
          return (<td><a href={url}>{cell}</a></td>);
      }
  }
    if (column === 'Parent Portal') {
        var parentid = row['Parent Portal'];
        if (parentid !="NA") {
            var url = loris.BaseURL + "/parent_portal/?id=" + parentid;
            return (<td><a href={url} target="_blank">Go To Parent Portal</a></td>);
        }
        else{
            return <td>NA</td>;
        }
    }
  return <td>{cell}</td>;
}

window.formatColumn = formatColumn;

export default formatColumn;
