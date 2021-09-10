<?php
/**
 * The module used to display the IBIS automated statistics tab.
 *
 * PHP Version 7
 *
 * @category Loris
 * @package  Main
 * @author   Nicolas Brossard
 * @license  http://www.gnu.org/licenses/gpl-3.0.txt GPLv3
 * @link     https://github.com/aces/IBIS
 */

namespace LORIS\statistics_ibis;

/**
 * The module used to display the IBIS automated statistics tab.
 *
 * PHP Version 7
 *
 * @category Loris
 * @package  Main
 * @author   Nicolas Brossard
 * @license  http://www.gnu.org/licenses/gpl-3.0.txt GPLv3
 * @link     https://github.com/aces/IBIS
 */
class Stats_Automated extends \NDB_Form
{
    /**
     * Determine whether the user has access to the module or not.
     *
     * @return bool true if the user has access, false otherwise.
     */
    function _hasAccess(\User $user) : bool
    {
        return $user->hasPermission('data_entry');
    }

    /**
     * InCenter function.
     *
     * @param string $centerID the value of centreID.
     * @param string $Centres  the value of Centres.
     *
     * @return bool
     */
    function _inCenter($centerID, $Centres)
    {
        foreach ($Centres as $Centre) {
            if($Centre['NumericID'] == $centerID) {
                return true;
            }
        }
        return false;
    }

    /**
     * Sets up the module prior to displaying it.
     *
     * @return void.
     */
    function setup()
    {
        parent::setup();
    }

    /**
     * Adds additional Javascript utility classes for this module.
     *
     * @return array of javascript to be inserted
     */
    function getJSDependencies()
    {
        $factory = \NDB_Factory::singleton();
        $baseURL = $factory->settings()->getBaseURL();
        $deps    = parent::getJSDependencies();
        return array_merge(
            $deps,
            array(
             $baseURL . "/statistics_ibis/js/form_stats_automated.js",
            )
        );
    }

    /**
     * Include additional CSS files:
     *
     * @return array of javascript to be inserted
     */
    function getCSSDependencies()
    {
        $factory = \NDB_Factory::singleton();
        $baseURL = $factory->settings()->getBaseURL();
        $deps    = parent::getCSSDependencies();
        return array_merge(
            $deps,
            array($baseURL . "/statistics/css/statistics.css")
        );
    }

} // End class

