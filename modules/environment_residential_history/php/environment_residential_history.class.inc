<?php

/**
 * IBIS module.
 *
 * PHP Version 5
 *
 * @category   Module
 * @package    Main
 * @subpackage Environment Residential History
 * @author     Gregory Luneau <gregory.luneau@mcgill.ca>
 * @license    http://www.gnu.org/licenses/gpl-3.0.txt GPLv3
 * @link       https://www.github.com/aces/Loris-Trunk/
 */
namespace LORIS\environment_residential_history;

/**
 *
 * @category   Module
 * @package    Main
 * @subpackage Environment Residential History
 * @author     Gregory Luneau <gregory.luneau@mcgill.ca>
 * @license    http://www.gnu.org/licenses/gpl-3.0.txt GPLv3
 * @link       https://www.github.com/aces/Loris-Trunk/
 */
class environment_residential_history extends \NDB_Page
{
    // Container variable for smarty
    var $tpl_data;

    /**
     * Create a new Module instance
     */
    public function __construct()
    {
        $factory  = \NDB_Factory::singleton();
        $settings = $factory->settings();

        $this->tpl_data['baseurl'] = $settings->getBaseURL();
    }

    /**
     * Determine whether the user has permission to view this page
     *
     * @return bool whether the user has access
     */
    function _hasAccess()
    {
        return true;
    }

    /**
     * Overrides base getJSDependencies() to add support for dicom specific
     * React column formatters.
     *
     * @return an array of extra JS files that this page depends on
     */
    function getJSDependencies()
    {
        $factory = \NDB_Factory::singleton();
        $baseURL = $factory->settings()->getBaseURL();
        $deps    = parent::getJSDependencies();
        return array_merge(
            $deps,
            array(
               $baseURL . "/js/sjcl.js",
               $baseURL . "/environment_residential_history/js/air_pollution_decrypt.js",
               $baseURL . "/environment_residential_history/js/papaparse.min.js",
            )
        );
    }

    /**
     * Include additional CSS files:
     *
     * @return array of CSS to be inserted
     */
    function getCSSDependencies()
    {
        $factory = \NDB_Factory::singleton();
        $baseURL = $factory->settings()->getBaseURL();
        $deps    = parent::getCSSDependencies();
        return array_merge(
            $deps,
            array()
        );
    }
}
?>
