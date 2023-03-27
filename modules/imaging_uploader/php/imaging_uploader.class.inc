<?php
/**
 * Mri_upload class file
 *
 * PHP version 5
 *
 * @category Behavioural
 * @package  Main
 * @author   Zia Mohaddes  <zia.mohades@gmail.com>
 * @license  http://www.gnu.org/licenses/gpl-3.0.txt GPLv3
 * @link     https://github.com/mohadesz/Loris-Trunk
 */
namespace LORIS\imaging_uploader;
use LORIS\server_processes_manager as SP;
/**
 * This module allows a zipped/tgz/gz file to be uploaded into the incoming folder
 * after passing a series of validation.
 *
 * @category Behavioural
 * @package  Main
 * @author   Zia Mohaddes  <zia.mohades@gmail.com>
 * @license  http://www.gnu.org/licenses/gpl-3.0.txt GPLv3
 * @link     https://github.com/aces/Loris
 */
class Imaging_Uploader extends \DataFrameworkMenu
{
    var $show_queries    = true;
    var $temp_path       = null;
    var $AjaxModule      = true;
    public $skipTemplate = true;
    /**
     * ID of the uploaded file in mri_upload table (if upload successful).
     * If the file is a reupload of an existing file, then it will be set to
     * the ID of the original upload.
     */
    var $mri_upload_id;
    /**
     * Path to the uploaded file (value of SourceLocation in mri_upload table).
     */
    var $uploaded_file_path;
    /**
     * The hasAccess function ensures that the user has the imaging_uploader
     * permission.
     *
     * @param \User $user The user whose access is being checked
     *
     * @return bool
     */
    function _hasAccess(\User $user) : bool
    {
        return $user->hasPermission('imaging_uploader');
    }
    /**
     * Sets up the Filter Variables
     *
     * @return void
     */
    function getJSDependencies()
    {
        $factory = \NDB_Factory::singleton();
        $baseURL = $factory->settings()->getBaseURL();
        $deps    = parent::getJSDependencies();
        return array_merge(
            $deps,
            [
                $baseURL . "/imaging_uploader/js/index.js",
                $baseURL . "/imaging_uploader/js/imaging_uploader_helper.js",
            ]
        );
    }
    /**
     * Include additional CSS files:
     *  imaging_uploader.css
     *
     * @return array of css to be inserted
     */
    function getCSSDependencies()
    {
        $factory = \NDB_Factory::singleton();
        $baseURL = $factory->settings()->getBaseURL();
        $deps    = parent::getCSSDependencies();
        return array_merge(
            $deps,
            [$baseURL . "/imaging_uploader/css/imaging_uploader.css"]
        );
    }
    /**
     * {@inheritDoc}
     *
     * @return \Loris\Data\Provisioner
     */
    public function getBaseDataProvisioner(): \LORIS\Data\Provisioner
    {
        return new ImagingUploaderProvisioner();
    }    
    /**
     * Tells the base class that this page's provisioner can support the
     * HasAnyPermissionOrUserSiteMatch filter.
     *
     * @return ?array of site permissions or null
     */
    public function allSitePermissionNames() : ?array
    {
        return null;
    }

    /**
     * Tells the base class that this page's provisioner can support
     * the UserProjectMatch filter.
     *
     * @return bool false
     */
    public function useProjectFilter() : bool
    {
        return false;
    }
    /**
     * Tells the base class that this page's provisioner can support
     * the UserProjectMatch filter.
     *
     * @return bool false
     */
    public function useSiteFilter() : bool
    {
        return true;
    }
    public function getFieldOptions() : array
    {
	    return [
            'sites'            => \Utility::getSiteList(false),		    
            ];
    }    
}

