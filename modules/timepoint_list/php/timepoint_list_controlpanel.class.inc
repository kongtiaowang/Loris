<?php declare(strict_types=1);

/**
 * Time Point List control panel class
 *
 * PHP version 5
 *
 * @category Main
 * @package  Timepoint_List
 * @author   zijdenbos <username@example.com>
 * @license  http://www.gnu.org/licenses/gpl-3.0.txt GPLv3
 * @link     https://www.github.com/aces/Loris-Trunk/
 * @access   public
 */

namespace LORIS\timepoint_list;
use \Loris\StudyEntities\Candidate\CandID;
/**
 * This class provides the management GUI for the status flags
 *
 * @category Main
 * @package  Timepoint_List
 * @author   zijdenbos <username@example.com>
 * @license  http://www.gnu.org/licenses/gpl-3.0.txt GPLv3
 * @link     https://www.github.com/aces/Loris-Trunk/
 * @access   public
 */

Class TimePoint_List_ControlPanel extends \Candidate
{
    /**
     * The template data for Smarty
     *
     * @var    array
     * @access private
     */
    var $tpl_data;

    /**
     * Fill the candidateInfo and listOfTimePoints variables using the
     * select function provide by the Candidate class.
     *
     * @param CandID $candID A 6-10 digit identifier that matches
     *                       a candidate in the candidate table
     *
     * @return void
     */
    function __construct($candID)
    {
        $this->select($candID);
    }

    /**
     * Generates the HTML to display the set of buttons for the status flags
     *
     * @return string
     * @access public
     */
    function display()
    {
        $user =& \User::singleton();

        $cand_CenterID = $this->getCenterID();

        $this->tpl_data['candID'] = $this->getCandID();

        $this->tpl_data['isDataEntryPerson']
            = $user->hasCenterPermission("data_entry", $cand_CenterID);

        $this->tpl_data['isImagingPerson'] = $user->hasAnyPermission(
            [
                'imaging_browser_view_site',
                'imaging_browser_view_allsites',
                'imaging_browser_phantom_allsites',
                'imaging_browser_phantom_ownsite'
            ]
        );

        //set the baseurl of the tpl_data
        $factory  = \NDB_Factory::singleton();
        $settings = $factory->settings();
        $this->tpl_data['baseurl'] = $settings->getBaseURL();

        $smarty = new \Smarty_NeuroDB('timepoint_list');
        $smarty->assign($this->tpl_data);
        $html = $smarty->fetch("timepoint_list_controlpanel.tpl");
        return $html;
    }

}

