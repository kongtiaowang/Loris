!function(modules){function __webpack_require__(moduleId){if(installedModules[moduleId])return installedModules[moduleId].exports;var module=installedModules[moduleId]={exports:{},id:moduleId,loaded:!1};return modules[moduleId].call(module.exports,module,module.exports,__webpack_require__),module.loaded=!0,module.exports}var installedModules={};return __webpack_require__.m=modules,__webpack_require__.c=installedModules,__webpack_require__.p="",__webpack_require__(0)}([function(module,exports){"use strict";function formatColumn(column,cell,rowData,rowHeaders){if(void 0!==loris.hiddenHeaders&&loris.hiddenHeaders.indexOf(column)>-1)return null;var row={};if(rowHeaders.forEach(function(header,index){row[header]=rowData[index]},this),"PSCID"===column){if("Recycling Bin"===row["Current Stage"])return React.createElement("td",null,cell,React.createElement("span",{className:"text-danger"},"(Recycling Bin)"));if("yes"===row.Invalid)return React.createElement("td",null,cell," ",React.createElement("span",{className:"text-danger"},"(Invalid)"));if("yes"===row["Manual Swap"])return React.createElement("td",null,cell," ",React.createElement("span",{className:"text-danger"},"(Manual)"));var testName="/"+row.Instrument+"_reliability",commentID=row.CommentID,siteID=row.SiteID,url=loris.BaseURL+testName+"?identifier="+commentID+"&reliability_center_id="+siteID;return React.createElement("td",null,React.createElement("a",{href:url},cell))}if("Reliable"===column){var reliable=row.Reliable;if("Yes"===reliable)return React.createElement("td",{className:"bg-success"},"Yes");if("No"===reliable)return React.createElement("td",{className:"bg-danger"},"No")}if("File In DB"===column){var file_in_DB=row["File In DB"];if("No"===file_in_DB)return React.createElement("td",{className:"bg-danger"},"No");var file_details=file_in_DB.split(","),rest_path="/temp_videos/ajax/GetFile.php?File=/videos/"+file_details[1]+"/"+file_details[2],file_url=loris.BaseURL+rest_path;return React.createElement("td",{className:"bg-success"},React.createElement("a",{download:file_details[2],href:file_url},file_details[0]))}return React.createElement("td",null,cell)}Object.defineProperty(exports,"__esModule",{value:!0}),window.formatColumn=formatColumn,exports.default=formatColumn}]);
//# sourceMappingURL=columnFormatter.js.map