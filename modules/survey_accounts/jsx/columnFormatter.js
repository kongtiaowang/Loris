/* exported formatColumn */

/**
 * Modify behaviour of specified column cells in the Data Table component
 * @param {string} column - column name
 * @param {string} cell - cell content
 * @param {arrray} rowData - array of cell contents for a specific row
 * @param {arrray} rowHeaders - array of table headers (column names)
 * @return {*} a formated table cell for a given column
 */
function formatColumn(column, cell, rowData, rowHeaders) {
  // Create the mapping between rowHeaders and rowData in a row object.
  var row = {};
  rowHeaders.forEach(function(header, index) {
    row[header] = rowData[index];
  }, this);
  if (column === 'URL') {
      if (row.SurveyName === 'air_pollution') {
          var url = loris.BaseURL + "/survey.php?key=" + row.URL;
          return (<td><a href={url}>{cell}</a></td>);
      }
      else{
          var url = loris.BaseURL + "/survey_module/?key=" + row.URL;
          return (<td><a href={url}>{cell}</a></td>);
      }
  }
    if (column === 'ParentID') {
        if (row.Visit === 'VSA') {
            var url = loris.BaseURL + "/parent_portal/?id=" + row.ParentID;
            return (<td><a href={url}>{cell}</a></td>);
        }
        else{
            return <td>{cell}</td>;
        }
    }
  return <td>{cell}</td>;
}

window.formatColumn = formatColumn;

export default formatColumn;
