<?php
/**
 * Dashboard: displays recruitment and study progression charts,
 * user tasks and document repository notifications
 *
 * PHP Version 5
 *
 * @category Main
 * @package  Loris
 * @author   Tara Campbell <tara.campbell@mail.mcgill.ca>
 * @license  http://www.gnu.org/licenses/gpl-3.0.txt GPLv3
 * @link     https://www.github.com/aces/Loris
 */

/**
 * Dashboard: displays recruitment and study progression charts,
 * user tasks and document repository notifications
 *
 * @category Main
 * @package  Loris
 * @author   Tara Campbell <tara.campbell@mail.mcgill.ca>
 * @license  http://www.gnu.org/licenses/gpl-3.0.txt GPLv3
 * @link     https://www.github.com/aces/Loris
 */

class NDB_Form_Module_Distribution extends NDB_Form
{

    /**
     * Creates the template data for the dashboard
     *
     * @return void
     */
    function display()
    {
	return null;
    }
   /**
     * Construct the template variables for the training page.
     *
     * @return void
     */
    function module_distribution()
    {
    }
    /**
     * Include additional CSS files:
     *  1. dashboard.css
     *
     * @return array of css to be included
     */
    function getCSSDependencies()
    {
        $factory = NDB_Factory::singleton();
        $baseURL = $factory->settings()->getBaseURL();
        $deps    = parent::getCSSDependencies();
        return array_merge(
            $deps,
            [$baseURL . "/dashboard/css/dashboard.css"]
        );
    }

    /**
     * Add dependency on D3 and C3 javascript libraries
     * for the pretty dashboards in the chart
     *
     * @return array of javascript files to be included
     */
    function getJSDependencies()
    {
        $factory = NDB_Factory::singleton();
        $config  = $factory->config();

        $www     = $config->getSetting('www');
        $baseurl = $www['url'];

        $baseDeps = parent::getJSDependencies();

        return array_merge(
            $baseDeps,
            array(
             $baseurl . '/module_distribution/js/index.js',
            )
        );

    }
    /**
     * Check user permissions
     *
     * @return bool
     * @throws ConfigurationException
     */
    function _hasAccess()
    {
        //create user object
       // $user =& User::singleton();
        return true;
       // $user->hasPermission('media_write');
    }
}
?>
