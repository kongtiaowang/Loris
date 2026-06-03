<?php
/**
 * Primary PHP class of the Data Release module
 *
 * PHP Version 7.1
 *
 * @category LORIS
 * @package  Main
 * @author   Jean-Michel Raoult <jean-michel.raoult.comtl@ssss.gouv.qc.ca>
 */

namespace LORIS\data_release;

use ConfigurationException;
use DatabaseException;
use Exception;
use LorisException;
use NDB_Factory;
use NDB_Menu;
use NDB_Menu_Filter;
use Smarty_NeuroDB;
use SmartyException;
use \Psr\Http\Message\ServerRequestInterface;
use \Psr\Http\Message\ResponseInterface;

/**
 *
 */
class Data_Release extends NDB_Menu_Filter
{
    // Singleton instance of the User class (User.class.inc)
    var $user;
    // Singleton instance of the Config class (NDB_Config.class.inc)
    var $config;
    // Singleton instance of the Database class (Database.class.inc)
    var $db;
    // Singleton instance of the Factory class (NDB_Factory.class.inc)
    var $factory;
    // Base URL for the module
    var $BaseURL;
    // Permission Level of user
    var $PermissionLevel;
    // Main table name
    var $mainTable = "data_release";
    // Table for data release documents
    var $documentsTable = "data_release_documents";
    // Table for data release documents/versions relationships
    var $versionsTable = "data_release_documents_versions_rel";
    // Table for document categories
    var $categoriesTable = "data_release_categories";
    // Table for links between documents and categories
    var $documentsCategoryTable = "data_release_categories_documents_rel";
    // Default upload location
    var $uploadLocation;

/**
     * Data_Release Module Constructor
     *
     * @param \LORIS\LorisInstance $lorisInstance The global LORIS instance container
     * @param \LORIS\data_release\Module $module The module context object
     * @param string $page The current page string identifier
     * @param string $identifier The unique element identifier
     * @param string $commentID The comment tracking identifier
     * @param string $formName The front-end form wrapper name
     */
    function __construct(
        $lorisInstance, 
        \LORIS\data_release\Module $module, 
        string $page, 
        string $identifier, 
        string $commentID, 
        string $formName
    ) {
        // Forward all arguments up to NDB_Menu / NDB_Menu_Filter in the exact order expected
        parent::__construct($lorisInstance, $module, $page, $identifier, $commentID, $formName);

        // Try/catch block to exit script if the required singletons are unavailable
        try {
            // Getting the factory singleton
            $this->factory = NDB_Factory::singleton();
            // Using the factory singleton, getting the other required singletons
            $this->user = $this->factory->user();
            $this->config = $this->factory->config();
            $this->db = $this->factory->database();
        } catch (Exception $e) {
            throw new \LorisException("Data Release Module: Generic exception while getting the required singletons", 500);
        }

        // Sets the AjaxModule variable to true
        $this->AjaxModule = true;

	// Getting settings from config
	//
	    $factory = \NDB_Factory::singleton();
            $DB      = $factory->database();
	    $this->BaseURL = $factory->settings()->getBaseURL();
	    $this->uploadLocation = "/data/DataReleaseDirectory";

        // Setting the permission level of the user
        // If the User has the edit permission or is superuser
        if ($this->hasPermission("Edit")) {
            $this->PermissionLevel = "Edit";
        // If the User only has the View permission
        } else {
            $this->PermissionLevel = "View";
	}
	     $this->PermissionLevel = "Edit";
    }
    /**
     * Returns a boolean if the user has access to the page.
     *
     * @return boolean
     */
    function _hasAccess(\User $user): bool
    {
	    return true;
        // Check whether the user has either the view or edit permissions
        //Note: implementing permission checking on multiple permissions should be done in the UserPermission Class
        return $this->hasPermissions(["View", "Edit"]);
    }

    /**
     *
     * Utility function which checks if the user has any of the permissions passed.
     *
     * @param array $permissions    Array of the sought permissions
     * @return bool
     */
    function hasPermissions(array $permissions): bool
    {
	    return true;
        // If the user has the superuser permission
        if( isset($this->user->getPermissions()["superuser"])
            && $this->user->getPermissions()["superuser"]){
            return true;
        }
        // For each permission being examined
        foreach($permissions as $permissionCode){
            // If the user has the permission
            if($this->hasPermission($permissionCode)){
                return true;
            }
        }
        return false;
    }

    /**
     *
     * Wrapper function testing for the presence of the viewing, editing and uploading permissions for
     * the data release module.
     *
     * @param string $code  Name of the role
     * @return bool     Presence of the permission
     */
    function hasPermission(string $code): bool
    {return true;
        // Code key to simplify naming scheme
        $permissionCodeKey = array(
            "View" => "data_release_view",
            "Edit" => "data_release_edit");
        // If the user has the superuser permission
        if(isset($this->user->getPermissions()["superuser"])
            && $this->user->getPermissions()["superuser"]){
            return true;
            // If the user has the permission and the permission is set to true
        }elseif (isset($this->user->getPermissions()[$permissionCodeKey[$code]])
            && $this->user->getPermissions()[$permissionCodeKey[$code]]){
            return true;
        }
        return false;
    }

    /**
     * Does the setup required for this page. By default, sets up elements
     * that are common to every type of page. May be overridden by a specific
     * page or specific page type.
     *
     * @return true
     */
    function setup(): bool
    {
        // Setup of the grandparent
        NDB_Menu::setup();
        // Defining the basic associative arrays from the DB
        $this::_setupVariables();
        // Applying parent default filter (trim) for compatibility
        parent::registerDefaultFilter();
        // Getting the user-specific data needed for display
        $this->_build();
        return true;
    }

    /**
     *
     * Function which calls the necessary procedures to define the version and documents
     * array used subsequently.
     *
     * @return bool     success of the building of the arrays
     */
    function _setupVariables(): bool
    {
        // Set the categories assocs
        $this->_setCategoriesArrays();
        // Set the documents assocs
        $this->_setDocumentsArray();
        // Set the versions assocs
        $this->_setVersionsArray();
        // Set the permission level and base URL for the template
        $this->tpl_data["permissionLevel"] = $this->PermissionLevel;
        $this->tpl_data['baseURL'] = $this->BaseURL;
        return true;
    }
/**
     * Set up structural category array models for display.
     * Converts lazy-loaded Query streams into native PHP 8 arrays for extraction.
     */
    function _setCategoriesArrays()
    {
	    error_log("_setCategoriesArrays");
        // Get the categories from the DB, ordered by parents and display order
        // Note: the parents ordering is important for the simplified recursion 
        // used to layout the categories by level
        $availableCategoriesDB = iterator_to_array($this->db->pselect(
            "SELECT
                        DataReleaseCategoryID,
                        Name,
                        Parents,
                        DisplayOrder
                    FROM {$this->categoriesTable}
                    ORDER BY Parents, DisplayOrder",
            array()
        ));
         
        // Re-index a copy of the categories from the DB by the PK of the table safely using raw arrays
        $categoriesIndexByID = array_combine(
            array_column($availableCategoriesDB, "DataReleaseCategoryID"),
            array_values($availableCategoriesDB)
        );

        // Initialize the hierarchical document array
        $availableDocuments = array();

        // Loop execution contexts across parsed rows
        foreach ($availableCategoriesDB as $category) {
            if (empty($category['Parents'])) {
                // If it doesn't have a parent, it's a top level category
                $availableDocuments[$category['DataReleaseCategoryID']] = array(
                    "DataReleaseCategoryID" => $category['DataReleaseCategoryID'],
                    "Name" => $category['Name'],
                    "DisplayOrder" => $category['DisplayOrder'],
                    "Elements" => array(),
                    "SubCategories" => array()
                );
            } else {
                // Parse out the inheritance chain
                $levels = explode('/', trim($category['Parents'], '/'));

                if (isset($availableDocuments[$levels[0]])) {
                    // Get a pointer on the first parent
                    $pointer = &$availableDocuments[$levels[0]];
                    // Remove the first parent from the array
                    array_shift($levels);
                    // While the parent array is not empty
                    while (!empty($levels)) {
                        // If the pointer exists
                        if ($pointer) {
                            // Go to the subcategory of the next parent
                            $pointer = &$pointer['SubCategories'][$levels[0]];
                        }
                        // remove the next parent
                        array_shift($levels);
                    }
                    // If the final parent's pointer exists
                    if ($pointer) {
                        // Add the category as a subcategory of the final parent
                        $pointer['SubCategories'][$category['DataReleaseCategoryID']] = array(
                            "DataReleaseCategoryID" => $category['DataReleaseCategoryID'],
                            "Name" => $category['Name'],
                            "DisplayOrder" => $category['DisplayOrder'],
                            "Elements" => array(),
                            "SubCategories" => array()
                        );
                    }
                }
            }
        }

        // Add the calculated arrays to the template data
        $this->tpl_data["categoriesIndexedByID"] = $categoriesIndexByID;
        $this->tpl_data["availableDocuments"] = $availableDocuments;
    }

    /**
     *
     * Function which calculates the documents assoc.
     *
     * @return void
     */
    function _setDocumentsArray()
    {
        // Getting the documents from the DB with their associated
        // category information.
        $existingDocumentsDB = iterator_to_array($this->db->pselect(
            "SELECT
                        dr.DataReleaseDocumentID,
                        dr.DisplayName,
                        dr.displayLatest,
                        dr.Description,
                        drc.DataReleaseCategoryID,
                        drc.Parents
                    FROM {$this->documentsTable} dr
                    LEFT JOIN {$this->documentsCategoryTable} drcfr ON (dr.DataReleaseDocumentID = drcfr.DataReleaseDocumentID)
                    LEFT JOIN {$this->categoriesTable} drc ON (drc.DataReleaseCategoryID = drcfr.DataReleaseCategoryID)
                    ORDER BY dr.DisplayName",
            array()
        ));

        // Re-index the results based on the documentID
        $existingDocumentsDB = array_combine(
            array_column($existingDocumentsDB, "DataReleaseDocumentID"),
            array_values($existingDocumentsDB)
        );

        // Assign the assoc to the template data
        $this->tpl_data['existingDocuments'] = $existingDocumentsDB;
    }

    /**
     *
     * Function which calculates the versions assocs.
     *
     * @return void
     */
    function _setVersionsArray()
    {
        // Get the versions from the DB with their associated documentID
        $existingVersionsDB = iterator_to_array($this->db->pselect(
            "SELECT
	                    dr.DataReleaseID,
                        dr.DisplayName,
                        dr.FileName,
                        dr.Author,
                        dr.ReferencePaper,
                        dr.UploadDate,
                        dr.LastModification,
                        dr.Description,
                        drfir.DataReleaseDocumentID
                    FROM {$this->mainTable} dr
                    LEFT JOIN {$this->versionsTable} drfir ON (drfir.DataReleaseID = dr.DataReleaseID)",
            array()
        ));

        // Re-index results based on the version ID
        $existingVersionsDB = array_combine(
            array_column($existingVersionsDB, "DataReleaseID"),
            array_values($existingVersionsDB)
        );

        // Assign the assoc to the template data
        $this->tpl_data['existingVersions'] = $existingVersionsDB;
    }

    /**
     *
     * Function which modifies the versions and documents assocs to
     * include the needed entries extracted in the build phase.
     *
     * @return bool
     */
    function _build(): bool
    {
        // Get the versions from the DB and assign them to the existing documents assoc
        // as appropriate
        $this->_buildVersionsByDocumentArray();
        // Assign the existing documents to the available documents assoc
        $this->_buildAvailableDocumentsArray();

        return true;
    }

    /**
     *
     * Function which takes the versions associated with a document from the DB
     * and assigns them to the existing document array from the template data.
     *
     * @return void
     */
    function _buildVersionsByDocumentArray()
    {
        // Get the versions associated with each document from the DB
        $versionsAssociatedToDocumentsDB = $this->db->pselect(
            "SELECT
                        dr.DataReleaseID,
                        dr.DisplayName AS `VersionDisplayName`,
                        dr.FileName,
                        dr.Author,
                        dr.ReferencePaper,
                        dr.UploadDate,
                        dr.LastModification,
                        dr.Description AS `VersionDescription`,
                        drf.DataReleaseDocumentID,
                        drf.DisplayName AS `DocumentDisplayName`,
                        drf.Description AS `DocumentDescription`
                    FROM {$this->mainTable} dr
                    INNER JOIN {$this->versionsTable} drfir ON (dr.DataReleaseID = drfir.DataReleaseID)
                    INNER JOIN {$this->documentsTable} drf ON (drf.DataReleaseDocumentID = drfir.DataReleaseDocumentID)
                    ORDER BY UploadDate DESC",
            array()
        );

        // For each version
        foreach($versionsAssociatedToDocumentsDB as $version){
            // Add to the appropriate section of the existing document array
            $this->tpl_data['existingDocuments'][$version['DataReleaseDocumentID']]['Versions'][$version['DataReleaseID']] = array(
                "DataReleaseID" => $version['DataReleaseID'],
                "DisplayName" => $version['VersionDisplayName'],
                "FileName" => $version['FileName'],
                "Author" => $version['Author'],
                "ReferencePaper" => $version['ReferencePaper'],
                "UploadDate" => $version['UploadDate'],
                "Description" => $version['VersionDescription']
            );
        }
    }

    /**
     *
     * Function which takes the existing documents array and adds its elements
     * to the appropriate locations of the available document array.
     *
     * @return void
     */
    function _buildAvailableDocumentsArray()
    {
        // Filtering for documents without a category
        $existingDocuments = array_filter($this->tpl_data['existingDocuments'], function($v, $k){
                return $v['DataReleaseCategoryID'] !== null && isset($v['Versions']);
            }, ARRAY_FILTER_USE_BOTH);
        // For each existing document with a category
        foreach($existingDocuments as $documentID => $document){
            // If the parents are null
            if($document['Parents'] === null){
                // Add to the zero-level of the available document array
                $this->tpl_data['availableDocuments'][$document['DataReleaseCategoryID']]['Elements'][$documentID] = $document;
            // if the parents exists
            }else{
                // explode the parents to an array
                $levels = explode('/', $document['Parents']);
                // if the first parent is valid
                if(isset($this->tpl_data['availableDocuments'][$levels[0]])){
                    // Get a pointer to the first parent
                    $pointer = &$this->tpl_data['availableDocuments'][$levels[0]];
                    // remove from parent array
                    array_shift($levels);
                    // While the parent array is not empty
                    while(!empty($levels)){
                        // if the pointer is valid
                        if($pointer){
                            // get a pointer to the next parent
                            $pointer = &$pointer['SubCategories'][$levels[0]];
                        }
                        // remove the next parent from the array
                        array_shift($levels);
                    }
                    // if the final point is valid
                    if($pointer){
                        // add the document to the subcategory of the last parent
                        $pointer['SubCategories'][$document['DataReleaseCategoryID']]['Elements'][$documentID] = $document;
                    }
                }
            }
        }
    }

    /**
     *
     * Instantiate a Smarty object, load the module's template data and return the HTML
     * produced by parsing this data through the menu's default template.
     *
     * @return ?string  HTML string or false boolean value in case of exceptions or errors.
     */
    function display(): ?string
    {
        // Hook for the potential support for CSV instead of templated HTML
        if ($this->skipTemplate) {
            return "";
        }
        try{
            // Create a new instance of the modified Smarty class
            $smarty = new Smarty_NeuroDB($this->Module->getName());
            // Assign the tpl_data variable to the Smarty instance
            $smarty->assign($this->getTemplateData());
            // Return the HTML produced by the default template
            return $smarty->fetch("menu_$this->menu.tpl");
        } catch(SmartyException|Exception $e) {
            return false;
        }
    }

    /**
     * Add the JavaScript dependencies needed for the module
     *
     * @return array of JavaScript files to be included
     */
    function getJSDependencies(): array
    {
        // Get the base JS dependency from the parent
        $baseDeps = parent::getJSDependencies();
        // Select the additional dependencies depending on the permission level
        switch($this->PermissionLevel){
            case 'Edit':
                $baseDeps = array_merge(
                    $baseDeps,
                    array($this->BaseURL . "/" . $this->page . "/" . "js/data_release_edit.js"));
                break;
            default:
                $baseDeps = array_merge(
                    $baseDeps,
                    array($this->BaseURL . "/" . $this->page . "/" . "js/data_release_view.js"));
                break;
        }
        // Return the new dependencies
        return $baseDeps;
    }

    /**
     *
     * Add the CSS dependencies needed for the module
     *
     * @return array of CSS files to be included
     */
    function getCSSDependencies(): array
    {
        return array(
            $this->BaseURL . "/bootstrap/css/bootstrap.min.css",
            $this->BaseURL . "/bootstrap/css/custom-css.css",
            $this->BaseURL . "/js/jquery/datepicker/datepicker.css",
            $this->BaseURL . '/vendor/sweetalert/sweetalert.css',
            $this->BaseURL . "/data_release/css/data_release.css"
        );
    }

    /**
     * An NDB_Page can act as both a middleware, or a handler, depending on the
     * context. When treated as a handler, an NDB_Page calls display() and
     * converts the output to a PSR7 stream.
     *
     * @param ServerRequestInterface $request The PSR15 Request being handled
     *
     * @return ResponseInterface The PSR15 response for the page.
     * @throws LorisException
     */
    public function handle(ServerRequestInterface $request) : ResponseInterface
    {
        // Get a copy of the POST parameters
        $POST = $request->getParsedBody();
        // Run the class setup
        $this->setup();
        // If the request is a POST and the user has sufficient permissions
        if(
            $request->getMethod() === 'POST' && $this->PermissionLevel === "Edit") {
            // If the value of the action parameter is not a character string
            if(!preg_match('/^[a-z]+$/i', $POST['action'])){
                return (new \LORIS\Router\NoopResponder(
                    new \LORIS\Http\Error(
                        $request,
                        500,
                        "Error Code 500:<br/>Data Release Module<br/>The {$POST['action']} POST action doesn't follow the expected format."
                    )
                ))->handle($request);
            }
            switch($POST['action']){
                case 'addCategory':
                    if($this::_validateAddCategory($POST)){
                        $this::addCategory($POST);
                    }
                    break;
                case 'editCategory':
                    if($this::_validateEditCategory($POST)){
                        $this::editCategory($POST);
                    }
                    break;
                case 'deleteCategory':
                    if($this::_validateDeleteCategory($POST['DataReleaseCategoryID'])){
                        $this::deleteCategory($POST['DataReleaseCategoryID']);
                    }
                    break;
                case 'addDocument':
                    if($this::_validateAddDocument($POST)){
                        $this::addDocument($POST);
                    }
                    break;
                case 'editDocument':
                    if($this::_validateEditDocument($POST)){
                        $this::editDocument($POST);
                    }
                    break;
                case 'deleteDocument':
                    if($this::_validateDeleteDocument($POST['DataReleaseDocumentID'])){
                        $this::deleteDocument($POST['DataReleaseDocumentID']);
                    }
                    break;
                case 'editVersion':
                    if($this::_validateEditVersion($POST)){
                        $this::editVersion($POST);
                    }
                    break;
                case 'deleteVersion':
                    if($this::_validateDeleteVersion($POST['DataReleaseID'])){
                        $this::deleteVersion($POST['DataReleaseID']);
                    }
                    break;
                default:
                    return (new \LORIS\Router\NoopResponder(
                        new \LORIS\Http\Error(
                            $request,
                            500,
                            "Error Code 500:<br/>Data Release Module<br/>The {$POST['action']} POST action is not implemented by the data release module"
                        )
                    ))->handle($request);
            }
            // Reload the variables and rebuild the arrays with the new data
            $this->_setupVariables();
            $this->_build();
            // If the request is a POST and the user has insufficient permissions
        }elseif ($request->getMethod() === 'POST' && $this->PermissionLevel !== "Edit"){
            return (new \LORIS\Router\NoopResponder(
                new \LORIS\Http\Error(
                    $request,
                    403,
                    "Error Code 403:<br/>Data Release Module<br/>You do not have the permissions for editing or uploading in the data release module."
                )
            ))->handle($request);
        }
        return (new \LORIS\Http\Response())
            ->withBody(new \LORIS\Http\StringStream($this->display()));
    }

    /**
     *
     * Validation function which validates the POST parameter of an Add category
     * request.
     *
     * @param array $parameters     POST array of the add category request
     * @return bool     validity of the parameters of the request
     */
    function _validateAddCategory(array $parameters): bool
    {
        return  $this::_validateString(
                    $parameters['CategoryNameTextInput'],
                    127,
                    "[^\w\s\d\.\-_~,;:\[\]\(\)'/]") &&
                !$this::_validateParameterExistence(
                    $this->categoriesTable,
                    "Name",
                    $parameters['CategoryNameTextInput']) &&
                $this::_validateCategoryParents($parameters['CategoryParentsTextInput']) &&
                $this::_validateIntegerID($parameters['CategoryDisplayOrderTextInput'], 255, 0);
    }

    /**
     *
     * Validation function for the parents parameter of a category
     * add or edit request.
     *
     * @param string $parents       String of the parents of the category
     * @return bool     validity of the parameter
     */
    function _validateCategoryParents(string $parents): bool
    {
        // If the string is larger than 50 or doesn't match either
        // a whitespace, a single digit or a sequence like 1/2/3
        if(!preg_match('/^(\s*|(\d+(\/\d+)*))$/', $parents) ||
            strlen($parents) > 50){
            return false;
        }
        // If the parents match either a blank space or a whitespace
        if($parents === " " | $parents === ""){
            return true;
        }
        // Explode the parents
        $levels = explode("/", $parents);
        // If the first parent matches a known category
        if(isset($this->tpl_data["availableDocuments"][$levels[0]])){
            // Get a pointer to the first parent
            $pointer = &$this->tpl_data["availableDocuments"][$levels[0]];
            // Remove the first parent
            array_shift($levels);
            // While the parent array is not empty
            while(!empty($levels)){
                // if the pointer is valid
                if($pointer){
                    // get a pointer to the next parent
                    $pointer = &$pointer['SubCategories'][$levels[0]];
                    // If the pointer is not valid
                }else{
                    return false;
                }
                // Remove the next parent
                array_shift($levels);
            }
            // If the first parent was unknown
        }else{
            return false;
        }
        return true;
    }

    /**
     *
     * Function which processes a validated addCategory request.
     *
     * @param array $parameters     Array of POST parameter for a addCategory request
     * @return bool     success of the addition of a category
     */
    function addCategory(array $parameters): bool
    {
        try{
            // Insert entry into DB
            $this->db->insert(
                $this->categoriesTable,
                array(
                    "Name" => $parameters['CategoryNameTextInput'],
                    "Parents" => (!isset($parameters['CategoryParentsTextInput']) || $parameters['CategoryParentsTextInput'] === ' ') ? null : $parameters['CategoryParentsTextInput'],
                    "DisplayOrder" => $parameters['CategoryDisplayOrderTextInput']
                )
            );
        }catch(\DatabaseException | \Exception $e){
            return false;
        }
        return true;
    }

    /**
     *
     * Function which validates an edit category request.
     *
     * @param array $parameters     Array of the POST parameters of an editCategory request
     * @return bool
     */
    function _validateEditCategory(array $parameters): bool
    {
        return  $this::_validateIntegerID($parameters['DataReleaseCategoryID']) &&
                $this::_validateParameterExistence(
                    $this->categoriesTable,
                    "DataReleaseCategoryID",
                    $parameters['DataReleaseCategoryID']) &&
                $this::_validateString(
                    $parameters['CategoryNameTextInput'],
                    127,
                    "[^\w\s\d\.\-_~,;:\[\]\(\)'/]") &&
                $this::_validateCategoryParents($parameters['CategoryParentsTextInput']) &&
                $this::_validateIntegerID($parameters['CategoryDisplayOrderTextInput'], 255, 0);
    }

    /**
     *
     * Processing function of an edit category request.
     *
     * @param array $parameters     Array of the POST parameters of an edit category request
     * @return bool     success of the edit category request
     */
    function editCategory(array $parameters): bool
    {
        try{
            // Update the record in the DB
            $this->db->update(
                $this->categoriesTable,
                array(
                    "Name" => $parameters['CategoryNameTextInput'],
                    "Parents" => (!isset($parameters['CategoryParentsTextInput']) || $parameters['CategoryParentsTextInput'] === ' ') ? null : $parameters['CategoryParentsTextInput'],
                    "DisplayOrder" => $parameters['CategoryDisplayOrderTextInput']
                ),
                array(
                    "DataReleaseCategoryID" => $parameters['DataReleaseCategoryID']
                )
            );
        }catch(\DatabaseException|\Exception $e){
            return false;
        }
        return true;
    }

    /**
     *
     * Function which validates a delete category request.
     *
     * @param string $CategoryID        Unsigned MySQL smallint of the PK of the table
     * @return bool
     */
    function _validateDeleteCategory(string $CategoryID): bool
    {
        // If the ID provided doesn't match the format expected or doesn't exist in the DB
        if( !$this::_validateIntegerID($CategoryID) ||
            !$this::_validateParameterExistence(
            $this->categoriesTable,
            "DataReleaseCategoryID",
            $CategoryID)){
            return false;
        }
        // If the category exists as a parent for another category
        foreach($this->tpl_data['categoriesIndexedByID'] as $category){
            if($category['Parents'] !== null && preg_match("/$CategoryID/", $category['Parents'])){
                return false;
            }
        }
        return true;
    }

    /**
     *
     * Processing function for deleting a category
     *
     * @param string $CategoryID        Unsigned MySQL smallint of the PK
     * @return bool     success of the deletion of the category
     */
    function deleteCategory(string $CategoryID): bool
    {
        try{
            // Delete the record from the table
            // Note: the cascade of the FK constraints will remove
            // the entries from the rel tables
            $this->db->delete(
                $this->categoriesTable,
                array(
                    "DataReleaseCategoryID" => $CategoryID
                )
            );
        }catch(\DatabaseException| \Exception $e){
            return false;
        }
        return true;
    }

    /**
     *
     * Validation function for an add document request.
     *
     * @param array $parameters     Array of the POST parameters of an add document request
     * @return bool     validity of the parameters provided
     */
    function _validateAddDocument(array $parameters): bool
    {
        return  $this::_validateString(
                    $parameters['DocumentDisplayNameTextInput'],
                    127,
                    "[^\w\s\d\.\-_~,;:\[\]\(\)'/]") &&
                !$this::_validateParameterExistence(
                    $this->documentsTable,
                    "DisplayName",
                    $parameters['DocumentDisplayNameTextInput']) &&
                $this::_validateDescription($parameters['DocumentDescriptionTextareaInput']) &&
                $this::_validateIntegerID($parameters['category']) &&
                $this::_validateParameterExistence(
                    $this->categoriesTable,
                    "DataReleaseCategoryID",
                    $parameters['category']);
    }

    /**
     *
     * Processing function for a validated addDocument request
     *
     * @param array $parameters     Array of the POST parameter of a addDocument request
     * @return bool     success of the operation
     */
    function addDocument(array $parameters): bool
    {
        try{
            // Given the impact on multiple tables and the
            // use of a get last id function, a transaction
            // is recommended to maintain atomicity
            $this->db->beginTransaction();
            // Insert entry into document table
            $this->db->insert(
                $this->documentsTable,
                array(
                    "DisplayName" => $parameters['DocumentDisplayNameTextInput'],
                    "displayLatest" => isset($parameters['DocumentDisplayLatestCheckboxInput']) ? 1 : 0,
                    "Description" => $parameters['DocumentDescriptionTextareaInput']
                )
            );
            // Insert entry into the category/document rel table
            $this->db->insert(
                $this->documentsCategoryTable,
                array(
                    "DataReleaseDocumentID" => $this->db->getLastInsertId(),
                    "DataReleaseCategoryID" => $parameters['category']
                )
            );
            // Commit the transaction
            $this->db->commit();
        }catch(\DatabaseException | \Exception $e){
            return false;
        }
        return true;
    }

    /**
     *
     * Validation function for an editDocument request
     *
     * @param array $parameters     Array of the POST parameters of an editDocument request
     * @return bool     validity of the parameters provided
     */
    function _validateEditDocument(array $parameters): bool
    {
        return  $this::_validateString(
                    $parameters['DocumentDisplayNameTextInput'],
                    127,
                    "[^\w\s\d\.\-_~,;:\[\]\(\)'/]") &&
                $this::_validateDescription($parameters['DocumentDescriptionTextareaInput']) &&
                $this::_validateIntegerID($parameters['category']) &&
                $this::_validateParameterExistence(
                    $this->categoriesTable,
                    "DataReleaseCategoryID",
                    $parameters['category']) &&
                $this::_validateIntegerID($parameters['DataReleaseDocumentID']) &&
                $this::_validateParameterExistence(
                    $this->documentsTable,
                    "DataReleaseDocumentID",
                    $parameters['DataReleaseDocumentID']);
    }

    /**
     *
     * Processing function for an editDocument request
     *
     * @param array $parameters     Array of the POST parameter of an editDocument request
     * @return bool     success of the request
     */
    function editDocument(array $parameters): bool
    {
        try{
            // Given the multiple tables, a transaction
            // insures atomicity
            $this->db->beginTransaction();
            // Update the document's table
            $this->db->update(
                $this->documentsTable,
                array(
                    "DisplayName" => $parameters['DocumentDisplayNameTextInput'],
                    "displayLatest" => isset($parameters['DocumentDisplayLatestCheckboxInput']) ? 1 : 0,
                    "Description" => $parameters['DocumentDescriptionTextareaInput']
                ),
                array(
                    "DataReleaseDocumentID" => $parameters['DataReleaseDocumentID']
                )
            );
            // Remove the category
            $this->db->delete(
                $this->documentsCategoryTable,
                array(
                    "DataReleaseDocumentID" => $parameters['DataReleaseDocumentID']
                )
            );
            // Add a new one
            $this->db->insert(
                $this->documentsCategoryTable,
                array(
                    "DataReleaseDocumentID" => $parameters['DataReleaseDocumentID'],
                    "DataReleaseCategoryID" => $parameters['category']
                )
            );
            // Process the request
            $this->db->commit();
        }catch(\DatabaseException | \Exception $e){
            return false;
        }
        return true;
    }

    /**
     *
     * Validation function for a deleteDocument request
     *
     * @param string $DataReleaseDocumentID     Unsigned MySQL smallint of the PK
     * @return bool     validity of the parameters provided
     */
    function _validateDeleteDocument(string $DataReleaseDocumentID): bool
    {
        return  $this::_validateIntegerID($DataReleaseDocumentID) &&
                $this::_validateParameterExistence(
                    $this->documentsTable,
                    "DataReleaseDocumentID",
                    $DataReleaseDocumentID);
    }

    /**
     *
     * Processing function for a deleteDocument request.
     *
     * @param string $DataReleaseDocumentID     Unsigned MySQL smallint of the PK
     * @return bool     success of the operation
     */
    function deleteDocument(string $DataReleaseDocumentID): bool
    {
        try{
            // Delete the document from the table
            // Note: cascade of FK in the DB will take care of the entries
            // in rel tables
            $this->db->delete(
                $this->documentsTable,
                array(
                    "DataReleaseDocumentID" => $DataReleaseDocumentID
                )
            );
        }catch(\DatabaseException | \Exception $e){
            return false;
        }
        return true;
    }

    /**
     *
     * Validation function for an editVersion request.
     *
     * @param array $parameters     Array of the POST parameter provided for the request
     * @return bool     validity of the parameters provided
     */
    function _validateEditVersion(array $parameters):bool
    {
        return  $this::_validateIntegerID($parameters['DataReleaseID']) &&
                $this::_validateParameterExistence(
                    $this->mainTable,
                    "DataReleaseID",
                    $parameters['DataReleaseID']) &&
                $this::_validateString(
                    $parameters['VersionDisplayNameTextInput'],
                    127,
                    "[^\w\s\d\.\-_~,;:\[\]\(\)'/]") &&
                $this::_validateFileNameFormat($parameters['VersionFileNameTextInput']) &&
                $this::_validateString(
                    $parameters['VersionAuthorTextInput'],
                    127,
                    "[^A-Za-z0-9 \(\)\-\.'&ÀàÂâÄäÇçÉéÈèÊêÌìÏïÔôÖöÒòÙùÛûÜü]") &&
            $this::_validateString(
                $parameters['VersionReferencePaperTextInput'],
                255,
                "[^A-Za-z0-9 \(\)\-\.:,'&ÀàÂâÄäÇçÉéÈèÊêÌìÏïÔôÖöÒòÙùÛûÜü]") &&
            $this::_validateDate($parameters['VersionUploadDateTextInput']) &&
            $this::_validateDescription($parameters['VersionDescriptionTextareaInput']) &&
            (empty($parameter['VersionsDocumentSelectInput']) ||
                (
                    $this::_validateIntegerID($parameters['VersionsDocumentSelectInput']) &&
                    $this::_validateParameterExistence(
                        $this->documentsTable,
                        "DataReleaseDocumentID",
                        $parameters['VersionsDocumentSelectInput'])
                )
            );
    }

    /**
     *
     * Processing function for an editVersion request.
     *
     * @param array $parameters         Array of POST parameters for an editVersion request
     * @return bool     success of the request
     */
    function editVersion(array $parameters): bool
    {
        try{
            // Get the version data from the DB
            $fileInDB = $this->db->pselectRow(
                "SELECT
                        *
                    FROM $this->mainTable
                    WHERE DataReleaseID = :DataReleaseID",
                array("DataReleaseID" => $parameters['DataReleaseID'])
            );
            // If the filename hasn't changed
            if($fileInDB['FileName'] === $parameters['VersionFileNameTextInput']){
                // Simply edit the main table
                $this::_editVersionDBEntry($parameters);
                // If the filename has changed
            }else{
                // If the file exists and is writable
                if($this::_validateWritableFileExists($parameters['DataReleaseID'])){
                    // If the file can be renamed to the filename specified
                    if(rename($this->uploadLocation . $fileInDB['FileName'], $this->uploadLocation . $parameters['VersionFileNameTextInput'])){
                        // edit the main table
                        $this::_editVersionDBEntry($parameters);
                        // If the file couldn't be renamed
                    }else{
                        // Log the error
                        error_log("Data Release Module: error while renaming file {$fileInDB['FileName']} to {$parameters['VersionFileNameTextInput']}");
                        return false;
                    }
                    // If the file was not found or was not writable
                }else{
                    // Log the error
                    error_log("Data Release Module: {$parameters['DataReleaseID']} not found or not writable during version edit");
                    return false;
                }
            }
            // Catch the exceptions during the table editing or the file renaming
        }catch(\DatabaseException | \Exception $e){
            error_log("{$e->getCode()}: {$e->getMessage()}");
            return false;
        }
        return true;
    }

    /**
     *
     * Function which takes an array of POST parameters and edits a version's
     * DB record
     *
     * @param array $parameters     Array of POST parameters for an editVersion request
     * @return void
     * @throws DatabaseException
     */
    function _editVersionDBEntry(array $parameters): void
    {
        // Given the multiple table, to maintain atomicity,
        // using a transaction is best
        $this->db->beginTransaction();
        // Update the main table
        $this->db->update(
            $this->mainTable,
            array(
                "DisplayName" => $parameters['VersionDisplayNameTextInput'],
                "FileName" => $parameters['VersionFileNameTextInput'],
                "Author" => $parameters['VersionAuthorTextInput'],
                "ReferencePaper" => $parameters['VersionReferencePaperTextInput'] ?? null,
                "UploadDate" => $parameters['VersionUploadDateTextInput'],
                "Description" => $parameters['VersionDescriptionTextareaInput'] ?? null
            ),
            array(
                "DataReleaseID" => $parameters['DataReleaseID']
            )
        );
        // Delete from the documents rel table
        $this->db->delete(
            $this->versionsTable,
            array(
                "DataReleaseID" => $parameters['DataReleaseID']
            )
        );
        // If a document was specified
        if(!empty($parameters['VersionsDocumentSelectInput'])){
            // insert into the documents rel table
            $this->db->insert(
                $this->versionsTable,
                array(
                    "DataReleaseID" => $parameters['DataReleaseID'],
                    "DataReleaseDocumentID" => $parameters['VersionsDocumentSelectInput']
                )
            );
        }
        $this->db->commit();
    }

    /**
     *
     * Validation function for a deleteVersion request.
     *
     * @param string $DataReleaseID     Unsigned MySQL smallint of the PK
     * @return bool     validity of the parameters provided
     */
    function _validateDeleteVersion(string $DataReleaseID): bool
    {
        return  $this::_validateIntegerID($DataReleaseID) &&
                $this::_validateParameterExistence(
                    $this->mainTable,
                    "DataReleaseID",
                    $DataReleaseID) &&
                $this::_validateWritableFileExists($DataReleaseID);
    }

    /**
     *
     * Processing function for a delete version request.
     *
     * @param string $DataReleaseID     Unsigned MySQL smallint of the PK
     * @return bool     success of the operation
     */
    function deleteVersion(string $DataReleaseID):bool
    {
        try{
            // Get the filename associated with the ID from the DB
            $fileRecordFromDB = $this->db->pselectRow(
                "SELECT
                            FileName
                        FROM $this->mainTable
                        WHERE DataReleaseID = :DataReleaseID",
                array("DataReleaseID" => $DataReleaseID)
            );
        }catch(Exception $e){
            error_log("{$e->getCode()}: {$e->getMessage()}");
            return false;
        }
        // If the filename is empty
        if(empty($fileRecordFromDB)){
            // Return an error
            return false;
        }
        // Path of the file with a regex in case of invalid value in the DB
        $AbsolutePath = $this->uploadLocation . preg_replace("[^\w\s\d\.\-_~,;:\[\]\(\)]", '',$fileRecordFromDB["FileName"]);
        // Given the unlinking time for very large files
        set_time_limit(0);
        // If the file was successfully deleted from the DB, delete from directory
        if(unlink($AbsolutePath)){
            // Delete file from DB
            try {
                $this->db->delete($this->mainTable, array("DataReleaseID" => $DataReleaseID));
                // In case of exception, stop there and don't delete from directory
            } catch (\DatabaseException | \Exception $e) {
                error_log("Data Release Module: error while deleting the $DataReleaseID entry in the {$this->mainTable} table.");
                return false;
            }
            return true;
            // If the file couldn't be erased
        }else{
            error_log("Data Release Module: error while erasing the {$fileRecordFromDB["FileName"]} file.");
            return false;
        }
    }

    /**
     *
     * General utility function to check the existence of a record with the specified
     * value for the specified column of a specified table.
     *
     * @param string $table     Name of the DB table
     * @param string $name      Name of the column to check
     * @param string $value     Value the column must take
     * @return bool     existence of the value in the column of the table specified
     */
    function _validateParameterExistence(string $table, string $name, string $value): bool
    {
        try{
            $valueInDB = $this->db->pselectOne(
                "SELECT
                        $name
                    FROM $table
                    WHERE $name = :value",
                array(
                    "value" => $value
                )
            );
        }catch(\DatabaseException | \Exception $e){
            return false;
        }
        if(empty($valueInDB)){
            return false;
        }else{
            return true;
        }
    }

    /**
     *
     * Utility function to check the int value of a string given some contraints.
     *
     * @param string $value     String value to be evaluated
     * @param int $max          Max value the integer can take
     * @param int $min          Min value the integer can take
     * @param bool $isSigned    Is the integer signed?
     * @return bool     validity of the integer provided
     */
    function _validateIntegerID(string $value, int $max = 65535, int $min = 0, bool $isSigned = false): bool
    {
        if( !ctype_digit($isSigned ? substr($value, 1) : $value) ||
            intval($value) > $max ||
            intval($value) <= $min){
            return false;
        }
        return true;
    }

    /**
     *
     * Utility function to validate the value given for a description.
     *
     * @param string $description           String of the description
     * @param int $length                   Maximum length of the description
     * @param string $blacklistPattern      Regex for detecting blacklisted characters
     * @return bool     validity of the description
     */
    function _validateDescription(string $description, int $length = 255, string $blacklistPattern = "[^\w\s\d\.\-_~,;:\[\]\(\)']"): bool
    {return true;
        if( preg_match($blacklistPattern, $description) ||
            strlen($description) > $length){
            return false;
        }
        return true;
    }

    /**
     *
     * Utility function to validate the value given for a string value.
     *
     * @param string $value                 String of the value
     * @param int $length                   Maximum length of the description
     * @param string $blacklistPattern      Regex for detecting blacklisted characters
     * @return bool     validity of the description
     */
    function _validateString(string $value, int $length, string $blacklistPattern):bool
    {
        if( preg_match($blacklistPattern, $value) ||
            strlen($value) > $length){
            return false;
        }
        return true;
    }

    /**
     *
     * Utility function to check whether a file exists and is writable
     *
     * @param string $DataReleaseID     Unsigned MySQL smallint of PK
     * @return bool
     */
    function _validateWritableFileExists(string $DataReleaseID):bool
    {
        try{
            // Get the filename associated with the ID from the DB
            $fileRecordFromDB = $this->db->pselectOne(
                "SELECT
                        FileName
                    FROM $this->mainTable
                    WHERE DataReleaseID = :DataReleaseID",
                array("DataReleaseID" => $DataReleaseID)
            );
        }catch(Exception $e){
            return false;
        }
        // If the filename is empty
        if(empty($fileRecordFromDB)){
            // Return an error
            return false;
        }
        // Note: The regex is to remove anything other than authorized characters from the filename,
        // in case the value in the DB contained such
        $AbsolutePath = $this->uploadLocation . preg_replace("[^\w\s\d\.\-_~,;:\[\]\(\)]", '',$fileRecordFromDB);
        // Check if the file exists
        if(!file_exists($AbsolutePath)){
            return false;
        }
        // Check if the folder is writable, thus allowing for deletion
        if(is_writable(dirname($AbsolutePath))){
            return true;
        }else{
            return false;
        }
    }

    /**
     *
     * Validation function to check for a filename validity
     *
     * @param string $FileName      Filename
     * @return bool
     */
    function _validateFileNameFormat(string $FileName):bool
    {
        // Note that the whitelisted characters don't include slashes, quotes
        // or repeating periods
        if( preg_match("/\.{2,}/", $FileName) ||
            preg_match("/[^\w\s\d\.\-_~,;:\[\]\(\)]/", $FileName) ||
            strlen($FileName) > 255){
            return false;
        }
        return true;
    }

    /**
     *
     * Utility function to check for a date's validity.
     *
     * @param string $Date      Date given to respect the YYYY-MM-DD format
     * @return bool
     */
    function _validateDate(string $Date): bool
    {
        // If the date string doesn't have the required number of character
        if( strlen($Date) != 10
            // if the date string cannot be converted to a timestamp
            || !(bool)strtotime($Date)
            // if the formatted timestamp doesn't match the date
            || date("Y-m-d", strtotime($Date)) != $Date){
            return false;
        }
        return true;
    }

    /**
     *
     * Public function for adding a version to the DB.
     *
     * @param string $DisplayName       Display name of the version
     * @param string $FileName          Filename of the version
     * @param string $Author            Author of the version
     * @param string $ReferencePaper    Reference paper of the version
     * @param string $DateUploaded      Date uploaded of the version
     * @param string $Description       Description of the version
     * @param string $DocumentID        DocumentID associated with the version
     * @return bool     success of the operation
     */
    function addDataReleaseFile(
        string $DisplayName,
        string $FileName,
        string $Author,
        string $ReferencePaper,
        string $DateUploaded,
        string $Description,
        string $DocumentID
    ):bool
    {
        try{
            //Verify if the file exists
            $fileInDB = $this->db->pselectRow(
                "SELECT
                            *
                        FROM $this->mainTable
                        WHERE FileName = :FileName",
                array("FileName" => $FileName)
            );
        }catch(Exception $e){
            return false;
        }
        // If the file already exists
        if(!empty($fileInDB)){
            return false;
        }
        // Try to insert the entry
        try{
            // To maintain atomicity given the multiple tables
            $this->db->beginTransaction();
            // Insert data into the main table
            $this->db->insert(
                $this->mainTable,
                array(
                    "DisplayName" => $DisplayName,
                    "FileName" => $FileName,
                    "Author" => $Author,
                    "ReferencePaper" => $ReferencePaper,
                    "UploadDate" => $DateUploaded,
                    "Description" => $Description
                )
            );
            // If a document was specified
            if(!empty($DocumentID)){
                // Insert into the versions/document rel table
                // based on the last id created
                $this->db->insert(
                    $this->versionsTable,
                    array(
                        "DataReleaseID" => $this->db->getLastInsertId(),
                        "DataReleaseDocumentID" => $DocumentID
                    )
                );
            }
            $this->db->commit();
            // Catch the exception thrown by the realinsert function
        }catch(Exception $e){
            // return an error
            return false;
        }
        // return success
        return true;
    }

    /**
     *
     * Public function for removing a version from the DB.
     *
     * @param string $FileName      Filename of the version to be removed
     * @return bool     success of the operation
     */
    function deleteDataReleaseFile(string $FileName) :bool
    {
        try{
            // Delete the entry that matches the filename provided
            // from the DB
            // Note: cascades of FKs take care of the rel tables for
            // the entry deleted
            $this->db->delete($this->mainTable, array("FileName" => $FileName));
        }catch(DatabaseException | Exception $e){
            return false;
        }
        return true;
    }
}

