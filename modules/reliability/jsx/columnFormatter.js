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
  if (loris.hiddenHeaders !== undefined &&
    loris.hiddenHeaders.indexOf(column) > -1) {
    return null;
  }

  // Create the mapping between rowHeaders and rowData in a row object.
  const row = {};
  rowHeaders.forEach(function(header, index) {
    row[header] = rowData[index];
  }, this);

  if (column === 'PSCID') {
    if (row['Current Stage'] === 'Recycling Bin') {
      return (
        <td>{cell}
          <span className='text-danger'>(Recycling Bin)</span>
        </td>
      );
    }

    if (row.Invalid === 'yes') {
      return (<td>{cell} <span className='text-danger'>(Invalid)</span></td>);
    }

    if (row['Manual Swap'] === 'yes') {
      return (<td>{cell} <span className='text-danger'>(Manual)</span></td>);
    }

    const testName = '/reliability/' + row.Instrument + '_reliability';
    const commentID = row.CommentID;
    const siteID = row.SiteID;
    const url = loris.BaseURL + testName +
      '?identifier=' + commentID + '&reliability_center_id=' + siteID;

    return (
      <td>
        <a href={url}>{cell}</a>
      </td>
    );
  }

  if (column === 'Reliable') {
    const reliable = row.Reliable;

    if (reliable === 'Yes') {
      return <td className='bg-success'>Yes</td>;
    } else if (reliable === 'No') {
      return <td className='bg-danger'>No</td>;
    }
  }
    if (column === 'File In DB') {
        const fileInDB = row['File In DB'];

        if (fileInDB === 'No') {
            return <td className='bg-danger'>No</td>;
        } else {
            const fileDetails = fileInDB.split(',');
            const restPath ='/temp_videos/ajax/GetFile.php?File=/videos/'+fileDetails[1]+'/'+fileDetails[2];
            const fileUrl = loris.BaseURL +restPath;
            return <td className='bg-success'><a download ={fileDetails[2]} href={fileUrl}>{fileDetails[0]}</a></td>;
        }
    }


  return <td>{cell}</td>;
}

window.formatColumn = formatColumn;

export default formatColumn;
