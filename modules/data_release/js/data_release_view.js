/**
 * Script for the Data release module with edit permissions
 *
 * @author Jean-Michel Raoult <jean-michel.raoult.comtl@ssss.gouv.qc.ca>
 */

'use strict';

// When the document is ready
$(document).ready(function() {
  // If the URL includes hashes, adjust scroll height
  adjustScrollForTargetedLinks();
  // Add Tooltips
  addTooltips();
});

/**
 * Convenience function which detects the presence of hashes in the
 * URL and scrolls to the proper height. Useful because of the header
 * used in the layout.
 */
function adjustScrollForTargetedLinks() {
  // If the address has a hash
  if (window.location.hash !== '') {
    // Adjust scroll height to the element specified
    $(window.location.hash).get(0).scrollIntoView();
  }
}

/**
 * Function which uses the data field defined in each file download link
 * to generate a custom HTML bootstrap tooltip and clears the fields afterwards.
 */
function addTooltips() {
  // For each file download link
  $('a.latest-links, a.historical-links').each(function() {
    // Set the tooltip to HTML and place it to the right
    $(this).tooltip({
      html: true,
      placement: 'right',
      container: 'body'
    });
    // Start building the HTML tooltip with the date
    let htmlTip = '<span class="bold">Upload Date: </span> ' +
      '<span class="tooltip-document-data">' + $(this).attr('latest-uploadDate') +
      '</span><br/>';
    // Add the filename to the HTML tooltip
    htmlTip += '<span class="bold">Filename: </span> ' +
      '<span class="tooltip-document-data">' + $(this).attr('latest-filename') +
      '</span><br/>';
    // If the file description is defined, add it to the tooltip
    if ($(this).attr('latest-description') !== undefined) {
      htmlTip += '<span class="bold">Description: </span> ' +
        '<span class="tooltip-document-data">' + $(this).attr('latest-description') +
        '</span><br/>';
    }
    // If the file author is defined, add it to the tooltip
    if ($(this).attr('latest-author') !== undefined) {
      htmlTip += '<span class="bold">Author: </span> ' +
        '<span class="tooltip-document-data">' + $(this).attr('latest-author') +
        '</span><br/>';
    }
    // If the reference paper is defined, add it to the tooltip
    if ($(this).attr('latest-reference') !== undefined) {
      htmlTip += '<span class="bold">Reference Paper: </span> ' +
        '<span class="tooltip-document-data">' +
        $(this).attr('latest-reference') +
        '</span><br/>';
    }
    // Clear the data field from the link element
    $(this).removeAttr(
      'latest-uploadDate latest-filename latest-description latest-author ' +
      'latest-reference');
    // Set a listener on the tooltip for the show event
    $(this).on('show.bs.tooltip', function(e) {
      // Set the text to the defined tooltip text
      $(e.target).attr('data-original-title', htmlTip);
    });
  });
}
