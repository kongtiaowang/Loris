(function(modules){var installedModules={};function __webpack_require__(moduleId){if(installedModules[moduleId]){return installedModules[moduleId].exports}var module=installedModules[moduleId]={i:moduleId,l:false,exports:{}};modules[moduleId].call(module.exports,module,module.exports,__webpack_require__);module.l=true;return module.exports}__webpack_require__.m=modules;__webpack_require__.c=installedModules;__webpack_require__.d=function(exports,name,getter){if(!__webpack_require__.o(exports,name)){Object.defineProperty(exports,name,{enumerable:true,get:getter})}};__webpack_require__.r=function(exports){if(typeof Symbol!=="undefined"&&Symbol.toStringTag){Object.defineProperty(exports,Symbol.toStringTag,{value:"Module"})}Object.defineProperty(exports,"__esModule",{value:true})};__webpack_require__.t=function(value,mode){if(mode&1)value=__webpack_require__(value);if(mode&8)return value;if(mode&4&&typeof value==="object"&&value&&value.__esModule)return value;var ns=Object.create(null);__webpack_require__.r(ns);Object.defineProperty(ns,"default",{enumerable:true,value});if(mode&2&&typeof value!="string")for(var key in value)__webpack_require__.d(ns,key,function(key){return value[key]}.bind(null,key));return ns};__webpack_require__.n=function(module){var getter=module&&module.__esModule?function getDefault(){return module["default"]}:function getModuleExports(){return module};__webpack_require__.d(getter,"a",getter);return getter};__webpack_require__.o=function(object,property){return Object.prototype.hasOwnProperty.call(object,property)};__webpack_require__.p="";return __webpack_require__(__webpack_require__.s=132)})({0:function(module,exports){module.exports=React},1:function(module,exports,__webpack_require__){if(false){var throwOnDirectAccess,isValidElement,REACT_ELEMENT_TYPE}else{module.exports=__webpack_require__(2)()}},132:function(module,exports,__webpack_require__){"use strict";var _typeof=typeof Symbol==="function"&&typeof Symbol.iterator==="symbol"?function(obj){return typeof obj}:function(obj){return obj&&typeof Symbol==="function"&&obj.constructor===Symbol&&obj!==Symbol.prototype?"symbol":typeof obj};Object.defineProperty(exports,"__esModule",{value:true});var _createClass=function(){function defineProperties(target,props){for(var i=0;i<props.length;i++){var descriptor=props[i];descriptor.enumerable=descriptor.enumerable||false;descriptor.configurable=true;if("value"in descriptor)descriptor.writable=true;Object.defineProperty(target,descriptor.key,descriptor)}}return function(Constructor,protoProps,staticProps){if(protoProps)defineProperties(Constructor.prototype,protoProps);if(staticProps)defineProperties(Constructor,staticProps);return Constructor}}();var _react=__webpack_require__(0);var _react2=_interopRequireDefault(_react);var _propTypes=__webpack_require__(1);var _propTypes2=_interopRequireDefault(_propTypes);function _interopRequireDefault(obj){return obj&&obj.__esModule?obj:{default:obj}}function _classCallCheck(instance,Constructor){if(!(instance instanceof Constructor)){throw new TypeError("Cannot call a class as a function")}}function _possibleConstructorReturn(self,call){if(!self){throw new ReferenceError("this hasn't been initialised - super() hasn't been called")}return call&&((typeof call==="undefined"?"undefined":_typeof(call))==="object"||typeof call==="function")?call:self}function _inherits(subClass,superClass){if(typeof superClass!=="function"&&superClass!==null){throw new TypeError("Super expression must either be null or a function, not "+(typeof superClass==="undefined"?"undefined":_typeof(superClass)))}subClass.prototype=Object.create(superClass&&superClass.prototype,{constructor:{value:subClass,enumerable:false,writable:true,configurable:true}});if(superClass)Object.setPrototypeOf?Object.setPrototypeOf(subClass,superClass):subClass.__proto__=superClass}
/**
   *  The following file contains the base component for the data query react app.
   *  It also contains the component for the saved queries dropdown.
   *
   *  @author   Jordan Stirling <jstirling91@gmail.com>
   *  @author   Dave MacFarlane <david.macfarlane2@mcgill.ca>
   *  @license  http://www.gnu.org/licenses/gpl-3.0.txt GPLv3
   *  @link     https://github.com/mohadesz/Loris-Trunk
   */var SavedQueriesList=function(_Component){_inherits(SavedQueriesList,_Component);function SavedQueriesList(props){_classCallCheck(this,SavedQueriesList);var _this=_possibleConstructorReturn(this,(SavedQueriesList.__proto__||Object.getPrototypeOf(SavedQueriesList)).call(this,props));_this.state={};_this.loadQuery=_this.loadQuery.bind(_this);return _this}_createClass(SavedQueriesList,[{key:"componentDidMount",value:function componentDidMount(){}},{key:"loadQuery",value:function loadQuery(queryName){this.props.onSelectQuery(this.props.queryDetails[queryName].Fields,this.props.queryDetails[queryName].Conditions)}},{key:"render",value:function render(){var userSaved=[];var globalSaved=[];var queryName=void 0,curQuery=void 0;if(this.props.queriesLoaded===false){return _react2.default.createElement("div",null)}for(var i=0;i<this.props.userQueries.length;i+=1){curQuery=this.props.queryDetails[this.props.userQueries[i]];if(curQuery.Meta&&curQuery.Meta.name){queryName=curQuery.Meta.name}else{queryName=this.props.userQueries[i]}userSaved.push(_react2.default.createElement("li",{key:this.props.userQueries[i]},_react2.default.createElement("a",{href:"#",onClick:this.loadQuery.bind(this,this.props.userQueries[i])},queryName)))}for(var _i=0;_i<this.props.globalQueries.length;_i+=1){curQuery=this.props.queryDetails[this.props.globalQueries[_i]];if(curQuery.Meta&&curQuery.Meta.name){queryName=curQuery.Meta.name}else{queryName=this.props.globalQueries[_i]}globalSaved.push(_react2.default.createElement("li",{key:this.props.globalQueries[_i]},_react2.default.createElement("a",{href:"#",onClick:this.loadQuery.bind(this,this.props.globalQueries[_i])},queryName)))}return _react2.default.createElement("ul",{className:"nav nav-tabs navbar-right"},_react2.default.createElement("li",{className:"dropdown"},_react2.default.createElement("a",{href:"#",className:"dropdown-toggle","data-toggle":"dropdown",role:"button","aria-expanded":"false"},"Load Saved Query ",_react2.default.createElement("span",{className:"caret"})),_react2.default.createElement("ul",{className:"dropdown-menu",role:"menu"},_react2.default.createElement("li",{role:"presentation",className:"dropdown-header"},"User Saved Queries"),userSaved,_react2.default.createElement("li",{role:"presentation",className:"dropdown-header"},"Shared Saved Queries"),globalSaved)),_react2.default.createElement("li",{role:"presentation",id:"presentationMSQ"},_react2.default.createElement("a",{href:"#SavedQueriesTab","data-toggle":"tab"},"Manage Saved Queries")))}}]);return SavedQueriesList}(_react.Component);SavedQueriesList.propTypes={queryDetails:_propTypes2.default.array,queriesLoaded:_propTypes2.default.bool};SavedQueriesList.defaultProps={queryDetails:[],queriesLoaded:false};var DataQueryApp=function(_Component2){_inherits(DataQueryApp,_Component2);function DataQueryApp(props){_classCallCheck(this,DataQueryApp);var _this2=_possibleConstructorReturn(this,(DataQueryApp.__proto__||Object.getPrototypeOf(DataQueryApp)).call(this,props));_this2.state={displayType:"Cross-sectional",fields:[],criteria:{},sessiondata:{},grouplevel:0,queryIDs:_this2.props.SavedQueries,savedQueries:{},queriesLoaded:false,alertLoaded:false,alertSaved:false,alertConflict:{show:false},ActiveTab:"Info",rowData:{},filter:{type:"group",activeOperator:0,children:[{type:"rule"}],session:_this2.props.AllSessions},selectedFields:{},downloadableFields:{},loading:false};_this2.saveFilterRule=_this2.saveFilterRule.bind(_this2);_this2.saveFilterGroup=_this2.saveFilterGroup.bind(_this2);_this2.saveCurrentQuery=_this2.saveCurrentQuery.bind(_this2);_this2.overrideQuery=_this2.overrideQuery.bind(_this2);_this2.loadFilterRule=_this2.loadFilterRule.bind(_this2);_this2.loadFilterGroup=_this2.loadFilterGroup.bind(_this2);_this2.loadSavedQuery=_this2.loadSavedQuery.bind(_this2);_this2.fieldVisitSelect=_this2.fieldVisitSelect.bind(_this2);_this2.fieldChange=_this2.fieldChange.bind(_this2);_this2.getSessions=_this2.getSessions.bind(_this2);_this2.runQuery=_this2.runQuery.bind(_this2);_this2.getRowData=_this2.getRowData.bind(_this2);_this2.dismissAlert=_this2.dismissAlert.bind(_this2);_this2.resetQuery=_this2.resetQuery.bind(_this2);_this2.changeDataDisplay=_this2.changeDataDisplay.bind(_this2);_this2.updateFilter=_this2.updateFilter.bind(_this2);return _this2}_createClass(DataQueryApp,[{key:"onTabChangeHandler",value:function onTabChangeHandler(e){if(e.target.innerHTML!=="Manage Saved Queries"){document.getElementById("presentationMSQ").classList.remove("active")}}},{key:"componentDidMount",value:function componentDidMount(){var _this3=this;var domNode=this;$(domNode).find('a[data-toggle="tab"]').on("shown.bs.tab",function(e){$(domNode).find("li").removeClass("active");if(e.target){e.target.classList.add("active");if(e.target.parentNode){e.target.parentNode.classList.add("active")}}});var promises=[];for(var key in this.state.queryIDs){for(var i=0;i<this.state.queryIDs[key].length;i+=1){var curRequest=void 0;curRequest=Promise.resolve($.ajax(loris.BaseURL+"/AjaxHelper.php?Module=dataquery&script=GetDoc.php&DocID="+encodeURIComponent(this.state.queryIDs[key][i])),{data:{DocID:this.state.queryIDs[key][i]},dataType:"json"}).then(function(value){var queries=_this3.state.savedQueries;queries[value._id]=value;_this3.setState({savedQueries:queries})});promises.push(curRequest)}}var allDone=Promise.all(promises).then(function(value){_this3.setState({queriesLoaded:true})});$('a[data-toggle="tab"]').on("shown.bs.tab",function(e){_this3.setState({ActiveTab:e.target.getAttribute("href").substr(1)})})}},{key:"saveFilterRule",value:function saveFilterRule(rule){var savedRule={field:rule.field,operator:rule.operator,value:rule.value,instrument:rule.instrument,visit:rule.visit};return savedRule}},{key:"saveFilterGroup",value:function saveFilterGroup(group){var savedFilter={activeOperator:group.activeOperator,children:[]};for(var i=0;i<group.children.length;i++){if(group.children[i].type==="rule"){savedFilter.children.push(this.saveFilterRule(group.children[i]))}else if(group.children[i].type==="group"){savedFilter.children.push(this.saveFilterGroup(group.children[i]))}}return savedFilter}},{key:"saveCurrentQuery",value:function saveCurrentQuery(name,shared,override){var _this4=this;var filter=this.saveFilterGroup(this.state.filter);var fields=JSON.stringify(this.state.selectedFields);$.post(loris.BaseURL+"/AjaxHelper.php?Module=dataquery&script=saveQuery.php",{Fields:fields,Filters:filter,QueryName:name,SharedQuery:shared,OverwriteQuery:override},function(data){var id=JSON.parse(data).id,queryIDs=_this4.state.queryIDs;if(!override){if(shared===true){queryIDs.Shared.push(id)}else{queryIDs.User.push(id)}}$.get(loris.BaseURL+"/AjaxHelper.php?Module=dataquery&script=GetDoc.php&DocID="+id,function(value){var queries=_this4.state.savedQueries;queries[value._id]=value;_this4.setState({savedQueries:queries,queryIDs,alertLoaded:false,alertSaved:true,alertConflict:{show:false}})})}).fail(function(data){if(data.status===409){_this4.setState({alertConflict:{show:true,QueryName:name,SharedQuery:shared}})}})}},{key:"overrideQuery",value:function overrideQuery(){this.saveCurrentQuery(this.state.alertConflict.QueryName,this.state.alertConflict.SharedQuery,true)}},{key:"loadFilterRule",value:function loadFilterRule(rule){var script=void 0;if(!rule.type){rule.type="rule"}$.ajax({url:loris.BaseURL+"/AjaxHelper.php?Module=dataquery&script=datadictionary.php",success:function success(data){rule.fields=data},async:false,data:{category:rule.instrument},dataType:"json"});for(var i=0;i<rule.fields.length;i++){if(rule.fields[i].key[1]===rule.field){rule.fieldType=rule.fields[i].value.Type;break}}switch(rule.operator){case"equal":case"isNull":script="queryEqual.php";break;case"notEqual":case"isNotNull":script="queryNotEqual.php";break;case"lessThanEqual":script="queryLessThanEqual.php";break;case"greaterThanEqual":script="queryGreaterThanEqual.php";break;case"startsWith":script="queryStartsWith.php";break;case"contains":script="queryContains.php";break;default:break}$.ajax({url:loris.BaseURL+"/AjaxHelper.php?Module=dataquery&script="+script,success:function success(data){var i=void 0,allSessions={},allCandiates={};for(i=0;i<data.length;i++){if(!allSessions[data[i][1]]){allSessions[data[i][1]]=[]}allSessions[data[i][1]].push(data[i][0]);if(!allCandiates[data[i][0]]){allCandiates[data[i][0]]=[]}allCandiates[data[i][0]].push(data[i][1])}rule.candidates={allCandiates,allSessions};if(rule.visit==="All"){rule.session=Object.keys(allCandiates)}else{if(allSessions[rule.visit]){rule.session=allSessions[rule.visit]}else{rule.session=[]}}},async:false,data:{category:rule.instrument,field:rule.field,value:rule.value},dataType:"json"});return rule}},{key:"loadFilterGroup",value:function loadFilterGroup(group){for(var i=0;i<group.children.length;i++){if(group.children[i].activeOperator){if(!group.children[i].type){group.children[i].type="group"}group.children[i]=this.loadFilterGroup(group.children[i])}else{group.children[i]=this.loadFilterRule(group.children[i])}}group.session=getSessions(group);return group}},{key:"loadSavedQuery",value:function loadSavedQuery(fields,criteria){var _this5=this;var filterState={},selectedFields={},fieldsList=[];this.setState({loading:true});if(Array.isArray(criteria)){filterState={type:"group",activeOperator:0,children:[]};filterState.children=criteria.map(function(item){var fieldInfo=item.Field.split(",");var rule={instrument:fieldInfo[0],field:fieldInfo[1],value:item.Value,type:"rule",visit:"All"};switch(item.Operator){case"=":rule.operator="equal";break;case"!=":rule.operator="notEqual";break;case"<=":rule.operator="lessThanEqual";break;case">=":rule.operator="greaterThanEqual";break;default:rule.operator=item.Operator;break}return rule});var fieldSplit=void 0;fieldsList=fields;for(var i=0;i<fields.length;i++){fieldSplit=fields[i].split(",");if(!selectedFields[fieldSplit[0]]){selectedFields[fieldSplit[0]]={};selectedFields[fieldSplit[0]][fieldSplit[1]]={};selectedFields[fieldSplit[0]].allVisits={};for(var key in this.props.Visits){selectedFields[fieldSplit[0]].allVisits[key]=1;selectedFields[fieldSplit[0]][fieldSplit[1]][key]=[key]}}else{selectedFields[fieldSplit[0]][fieldSplit[1]]={};for(var _key in this.props.Visits){selectedFields[fieldSplit[0]].allVisits[_key]++;selectedFields[fieldSplit[0]][fieldSplit[1]][_key]=[_key]}}}}else{filterState=criteria;selectedFields=fields?fields:{};for(var instrument in fields){for(var field in fields[instrument]){if(field!=="allVisits"){fieldsList.push(instrument+","+field)}}}}if(filterState.children&&filterState.children.length>0){filterState=this.loadFilterGroup(filterState)}else{filterState.children=[{type:"rule"}];filterState.session=this.props.AllSessions}this.setState({fields:fieldsList,selectedFields,filter:filterState,alertLoaded:true,alertSaved:false,loading:false});$.ajax({url:loris.BaseURL+"/dqt/ajax/datadictionary.php",success:function success(data){for(var _i2=0;_i2<fieldsList.length;_i2++){if(data[_i2].value.IsFile){var _key2=data[_i2].key[0]+","+data[_i2].key[1];var downloadable=_this5.state.downloadableFields;downloadable[_key2]=true;_this5.setState({downloadableFields:downloadable})}}},data:{keys:JSON.stringify(fieldsList)},dataType:"json"})}},{key:"fieldVisitSelect",value:function fieldVisitSelect(action,visit,field){this.setState(function(state){var temp=state.selectedFields[field.instrument];if(action==="check"){temp[field.field][visit]=visit;if(temp.allVisits[visit]){temp.allVisits[visit]++}else{temp.allVisits[visit]=1}}else{delete temp[field.field][visit];if(temp.allVisits[visit]===1){delete temp.allVisits[visit]}else{temp.allVisits[visit]--}}return temp})}},{key:"fieldChange",value:function fieldChange(fieldName,category,downloadable){var _this6=this;this.setState(function(state){var selectedFields=state.selectedFields,fields=state.fields.slice(0);if(!selectedFields[category]){selectedFields[category]={};selectedFields[category][fieldName]=JSON.parse(JSON.stringify(_this6.props.Visits));selectedFields[category].allVisits={};for(var key in _this6.props.Visits){selectedFields[category].allVisits[key]=1}fields.push(category+","+fieldName);if(downloadable){state.downloadableFields[category+","+fieldName]=true}}else if(selectedFields[category][fieldName]){for(var _key3 in selectedFields[category][fieldName]){if(selectedFields[category].allVisits[_key3]===1){delete selectedFields[category].allVisits[_key3]}else{selectedFields[category].allVisits[_key3]--}}delete selectedFields[category][fieldName];var idx=fields.indexOf(category+","+fieldName);fields.splice(idx,1);if(Object.keys(selectedFields[category]).length===1){delete selectedFields[category]}if(downloadable){delete state.downloadableFields[category+","+fieldName]}}else{if(!selectedFields[category][fieldName]){selectedFields[category][fieldName]={}}for(var _key4 in selectedFields[category].allVisits){if(_key4==="allVisits"){continue}selectedFields[category].allVisits[_key4]++;selectedFields[category][fieldName][_key4]=_key4}fields.push(category+","+fieldName);if(downloadable){state.downloadableFields[category+","+fieldName]=true}}return{selectedFields,fields}})}},{key:"getSessions",value:function getSessions(){if(this.state.filter.children.length>0){return this.state.filter.session}else{return this.props.AllSessions}}},{key:"runQuery",value:function runQuery(fields,sessions){var _this7=this;var DocTypes=[],semaphore=0,sectionedSessions=void 0,ajaxComplete=function ajaxComplete(){if(semaphore==0){var rowdata=_this7.getRowData(_this7.state.grouplevel);_this7.setState({rowData:rowdata,loading:false})}};this.setState({rowData:{},sessiondata:{},loading:true});for(var i=0;i<fields.length;i+=1){var field_split=fields[i].split(",");var category=field_split[0];if(DocTypes.indexOf(category)===-1){var sessionInfo=[];for(var j=0;j<this.state.filter.session.length;j++){if(Array.isArray(this.state.filter.session[j])){if(this.state.selectedFields[category].allVisits[this.state.filter.session[j][1]]){sessionInfo.push(this.state.filter.session[j])}}else{for(var key in this.state.selectedFields[category].allVisits){var temp=[];temp.push(this.state.filter.session[j]);temp.push(key);sessionInfo.push(temp)}}}DocTypes.push(category);semaphore++;sectionedSessions=JSON.stringify(sessionInfo);$.ajax({type:"POST",url:loris.BaseURL+"/AjaxHelper.php?Module=dataquery&script=retrieveCategoryDocs.php",data:{DocType:category,Sessions:sectionedSessions},dataType:"text",success:function success(data){if(data){var _i3=void 0,row=void 0,rows=void 0,identifier=void 0,sessiondata=_this7.state.sessiondata;data=JSON.parse(data);rows=data.rows;for(_i3=0;_i3<rows.length;_i3+=1){row=rows[_i3];identifier=row.value;if(!sessiondata.hasOwnProperty(identifier)){sessiondata[identifier]={}}sessiondata[identifier][row.key[0]]=row.doc}_this7.setState({sessiondata})}semaphore--;ajaxComplete()}})}}}},{key:"getRowData",value:function getRowData(displayID){var sessiondata=this.state.sessiondata;var sessions=this.getSessions();var fields=this.state.fields.sort();var downloadableFields=this.state.downloadableFields;var i=void 0,j=void 0;var rowdata=[];var currow=[];var Identifiers=[];var RowHeaders=[];var fileData=[];var href=void 0;if(displayID===0){for(i=0;fields&&i<fields.length;i+=1){RowHeaders.push(fields[i])}for(var session in sessiondata){currow=[];for(i=0;fields&&i<fields.length;i+=1){var fieldSplit=fields[i].split(",");currow[i]=".";var sd=sessiondata[session];if(sd[fieldSplit[0]]&&sd[fieldSplit[0]].data[fieldSplit[1]]&&downloadableFields[fields[i]]){href=loris.BaseURL+"/mri/jiv/get_file.php?file="+sd[fieldSplit[0]].data[fieldSplit[1]];currow[i]=_react2.default.createElement("a",{href},sd[fieldSplit[0]].data[fieldSplit[1]]);fileData.push("file/"+sd[fieldSplit[0]]._id+"/"+encodeURIComponent(sd[fieldSplit[0]].data[fieldSplit[1]]))}else if(sd[fieldSplit[0]]){currow[i]=sd[fieldSplit[0]].data[fieldSplit[1]]}}rowdata.push(currow);Identifiers.push(session)}}else{var Visits={},visit=void 0,identifier=void 0,temp=void 0,colHeader=void 0,index=void 0,instrument=void 0,_fieldSplit=void 0;for(var _session in sessiondata){temp=_session.split(",");visit=temp[1];if(!Visits[visit]){Visits[visit]=true}identifier=temp[0];if(Identifiers.indexOf(identifier)===-1){Identifiers.push(identifier)}}for(i=0;fields&&i<fields.length;i+=1){for(visit in Visits){temp=fields[i].split(",");instrument=this.state.selectedFields[temp[0]];if(instrument&&instrument[temp[1]]&&instrument[temp[1]][visit]){RowHeaders.push(visit+" "+fields[i])}}}for(identifier in Identifiers){currow=[];for(colHeader in RowHeaders){temp=Identifiers[identifier]+","+RowHeaders[colHeader].split(" ")[0];index=sessiondata[temp];if(!index){currow.push(".")}else{temp=index[RowHeaders[colHeader].split(",")[0].split(" ")[1]];_fieldSplit=RowHeaders[colHeader].split(" ")[1].split(",");if(temp){if(temp.data[RowHeaders[colHeader].split(",")[1]]&&downloadableFields[_fieldSplit[0]+","+_fieldSplit[1]]){href=loris.BaseURL+"/mri/jiv/get_file.php?file="+temp.data[RowHeaders[colHeader].split(",")[1]];temp=_react2.default.createElement("a",{href},temp.data[RowHeaders[colHeader].split(",")[1]])}else{temp=temp.data[RowHeaders[colHeader].split(",")[1]]}}else{temp="."}currow.push(temp)}}rowdata.push(currow)}}return{rowdata,Identifiers,RowHeaders,fileData}}},{key:"dismissAlert",value:function dismissAlert(){this.setState({alertLoaded:false,alertSaved:false,alertConflict:{show:false}})}},{key:"resetQuery",value:function resetQuery(){this.setState({fields:[],criteria:{},selectedFields:{}})}},{key:"changeDataDisplay",value:function changeDataDisplay(displayID){var rowdata=this.getRowData(displayID);this.setState({grouplevel:displayID,rowData:rowdata})}},{key:"updateFilter",value:function updateFilter(filter){if(filter.children.length===0){filter.session=this.props.AllSessions}this.setState({filter})}},{key:"render",value:function render(){var tabs=[];var tabsNav=[];var alert=_react2.default.createElement("div",null);tabs.push(_react2.default.createElement(InfoTabPane,{key:"Info",TabId:"Info",UpdatedTime:this.props.UpdatedTime,Loading:this.state.loading,Active:this.state.ActiveTab=="Info"}));tabs.push(_react2.default.createElement(FieldSelectTabPane,{key:"DefineFields",TabId:"DefineFields",categories:this.props.categories,onFieldChange:this.fieldChange,selectedFields:this.state.selectedFields,Visits:this.props.Visits,fieldVisitSelect:this.fieldVisitSelect,Loading:this.state.loading,Active:this.state.ActiveTab=="DefineFields"}));tabs.push(_react2.default.createElement(FilterSelectTabPane,{key:"DefineFilters",TabId:"DefineFilters",categories:this.props.categories,filter:this.state.filter,updateFilter:this.updateFilter,Visits:this.props.Visits,Loading:this.state.loading,Active:this.state.ActiveTab=="DefineFilters"}));var displayType=this.state.grouplevel===0?"Cross-sectional":"Longitudinal";tabs.push(_react2.default.createElement(ViewDataTabPane,{key:"ViewData",TabId:"ViewData",Active:this.state.ActiveTab=="ViewData",Fields:this.state.fields,Criteria:this.state.criteria,Sessions:this.getSessions(),Data:this.state.rowData.rowdata,RowInfo:this.state.rowData.Identifiers,RowHeaders:this.state.rowData.RowHeaders,FileData:this.state.rowData.fileData,onRunQueryClicked:this.runQuery,displayType,changeDataDisplay:this.changeDataDisplay,Loading:this.state.loading,runQuery:this.runQuery}));tabs.push(_react2.default.createElement(StatsVisualizationTabPane,{key:"Statistics",TabId:"Statistics",Active:this.state.ActiveTab=="Statistics",Fields:this.state.rowData.RowHeaders,Data:this.state.rowData.rowdata,Loading:this.state.loading}));tabs.push(_react2.default.createElement(ManageSavedQueriesTabPane,{key:"SavedQueriesTab",TabId:"SavedQueriesTab",userQueries:this.state.queryIDs.User,globalQueries:this.state.queryIDs.Shared,onSaveQuery:this.saveCurrentQuery,queryDetails:this.state.savedQueries,queriesLoaded:this.state.queriesLoaded,Loading:this.state.loading}));if(this.state.alertLoaded){alert=_react2.default.createElement("div",{className:"alert alert-success",role:"alert"},_react2.default.createElement("button",{type:"button",className:"close","aria-label":"Close",onClick:this.dismissAlert},_react2.default.createElement("span",{"aria-hidden":"true"},"×")),_react2.default.createElement("strong",null,"Success")," Query Loaded.")}if(this.state.alertSaved){alert=_react2.default.createElement("div",{className:"alert alert-success",role:"alert"},_react2.default.createElement("button",{type:"button",className:"close","aria-label":"Close",onClick:this.dismissAlert},_react2.default.createElement("span",{"aria-hidden":"true"},"×")),_react2.default.createElement("strong",null,"Success")," Query Saved.")}if(this.state.alertConflict.show){alert=_react2.default.createElement("div",{className:"alert alert-warning",role:"alert"},_react2.default.createElement("button",{type:"button",className:"close","aria-label":"Close",onClick:this.dismissAlert},_react2.default.createElement("span",{"aria-hidden":"true"},"×")),_react2.default.createElement("button",{type:"button",className:"close","aria-label":"Close",onClick:this.dismissAlert},_react2.default.createElement("span",{"aria-hidden":"true"},"Override")),_react2.default.createElement("strong",null,"Error")," Query with the same name already exists.",_react2.default.createElement("a",{href:"#",class:"alert-link",onClick:this.overrideQuery},"Click here to override"))}var widthClass="col-md-12";var sideBar=_react2.default.createElement("div",null);if(this.state.fields.length>0&&this.state.ActiveTab!=="ViewData"&&this.state.ActiveTab!=="Statistics"&&this.state.ActiveTab!=="Info"){widthClass="col-md-10";sideBar=_react2.default.createElement("div",{className:"col-md-2"},_react2.default.createElement(FieldsSidebar,{Fields:this.state.fields,Criteria:this.state.criteria,resetQuery:this.resetQuery}))}return _react2.default.createElement("div",null,alert,_react2.default.createElement("div",{className:widthClass},_react2.default.createElement("nav",{className:"nav nav-tabs"},_react2.default.createElement("ul",{className:"nav nav-tabs navbar-left","data-tabs":"tabs"},_react2.default.createElement("li",{role:"presentation",onClick:this.onTabChangeHandler,className:"active"},_react2.default.createElement("a",{href:"#Info","data-toggle":"tab"},"Info")),_react2.default.createElement("li",{role:"presentation",onClick:this.onTabChangeHandler},_react2.default.createElement("a",{href:"#DefineFields","data-toggle":"tab"},"Define Fields")),_react2.default.createElement("li",{role:"presentation",onClick:this.onTabChangeHandler},_react2.default.createElement("a",{href:"#DefineFilters","data-toggle":"tab"},"Define Filters")),_react2.default.createElement("li",{role:"presentation",onClick:this.onTabChangeHandler},_react2.default.createElement("a",{href:"#ViewData","data-toggle":"tab"},"View Data")),_react2.default.createElement("li",{role:"presentation",onClick:this.onTabChangeHandler},_react2.default.createElement("a",{href:"#Statistics","data-toggle":"tab"},"Statistical Analysis"))),_react2.default.createElement(SavedQueriesList,{userQueries:this.state.queryIDs.User,globalQueries:this.state.queryIDs.Shared,queryDetails:this.state.savedQueries,queriesLoaded:this.state.queriesLoaded,onSelectQuery:this.loadSavedQuery,loadedQuery:this.state.loadedQuery})),_react2.default.createElement("div",{className:"tab-content"},tabs)),sideBar)}}]);return DataQueryApp}(_react.Component);DataQueryApp.propTypes={SavedQueries:_propTypes2.default.array,AllSessions:_propTypes2.default.array};DataQueryApp.defaultProps={SavedQueries:[],AllSessions:[]};window.SavedQueriesList=SavedQueriesList;window.DataQueryApp=DataQueryApp;window.RDataQueryApp=_react2.default.createFactory(DataQueryApp);exports.default=DataQueryApp},2:function(module,exports,__webpack_require__){"use strict";var ReactPropTypesSecret=__webpack_require__(3);function emptyFunction(){}module.exports=function(){function shim(props,propName,componentName,location,propFullName,secret){if(secret===ReactPropTypesSecret){return}var err=new Error("Calling PropTypes validators directly is not supported by the `prop-types` package. "+"Use PropTypes.checkPropTypes() to call them. "+"Read more at http://fb.me/use-check-prop-types");err.name="Invariant Violation";throw err}shim.isRequired=shim;function getShim(){return shim}var ReactPropTypes={array:shim,bool:shim,func:shim,number:shim,object:shim,string:shim,symbol:shim,any:shim,arrayOf:getShim,element:shim,instanceOf:getShim,node:shim,objectOf:getShim,oneOf:getShim,oneOfType:getShim,shape:getShim,exact:getShim};ReactPropTypes.checkPropTypes=emptyFunction;ReactPropTypes.PropTypes=ReactPropTypes;return ReactPropTypes}},3:function(module,exports,__webpack_require__){"use strict";var ReactPropTypesSecret="SECRET_DO_NOT_PASS_THIS_OR_YOU_WILL_BE_FIRED";module.exports=ReactPropTypesSecret}});
//# sourceMappingURL=react.app.js.map