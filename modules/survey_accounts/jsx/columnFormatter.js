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
  let row = {};
  rowHeaders.forEach(function(header, index) {
    row[header] = rowData[index];
  }, this);
  if (column === 'URL') {
      if (row.SurveyName === 'AP (Air Pollution) - Survey') {
          let url = loris.BaseURL + '/survey.php?key=' + row.URL;
          return (<td><a href={url}>{cell}</a></td>);
      } else {
          let url = loris.BaseURL + '/survey_module/?key=' + row.URL;
          return (<td><a href={url}>{cell}</a></td>);
      }
  }
    if (column === 'Parent Portal') {
        let parentid = row['Parent Portal'];
        if (parentid !='NA') {
          let url = loris.BaseURL + '/parent_portal/?id=' + parentid;
          let text='Go To Parent Portal';
          return (<td><a href={url} target='_blank'>{text}</a></td>);
        } else {
            return <td>NA</td>;
        }
    }
  return <td>{cell}</td>;
}

window.formatColumn = formatColumn;

export default formatColumn;
