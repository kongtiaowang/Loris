<?php

/**
 * IBIS module.
 *
 * PHP Version 5
 *
 * @category   Module
 * @package    Main
 * @subpackage Parent Portal - View Surveys
 * @author     Sruthy Mathew <sruthy.mathew@mcgill.ca>
 * @license    http://www.gnu.org/licenses/gpl-3.0.txt GPLv3
 * @link       https://www.github.com/aces/Loris-Trunk/
 */
namespace LORIS\parent_portal;

/**
 *
 * @category   Module
 * @package    Main
 * @subpackage Parent Portal - View Surveys
 * @author     Sruthy Mathew <sruthy.mathew@mcgill.ca>
 * @license    http://www.gnu.org/licenses/gpl-3.0.txt GPLv3
 * @link       https://www.github.com/aces/Loris-Trunk/
 */
class view_surveys extends \NDB_Form
{


    function _hasAccess()
    {
        return true;
    }


    function setup()
    {
        $this->tpl_data['page_title'] = 'Welcome To Parent Portal! (ID:'.base64_decode($this->identifier).')';
        $factory = \NDB_Factory::singleton();
        $baseURL = $factory->settings()->getBaseURL();
        $url= $baseURL. "/survey_module/?key=";
        $this->tpl_data['url']=$url;
        $DB =& \Database::singleton();
        $query=$DB->pselect("select tn.Full_name,s.Visit_label, p.Status,p.OneTimePassword
            FROM participant_accounts p 
            JOIN session s ON (p.SessionID=s.ID)
            JOIN candidate c ON (c.CandID=s.CandID)
            JOIN flag f ON (f.CommentID =p.CommentID)
            JOIN test_names tn ON (tn.Test_name=f.Test_name)
            WHERE s.Visit_label='VSA' and c.PSCID=:pid
            ORDER BY p.Status",
                array('pid' => base64_decode($this->identifier))
            );
        $this->tpl_data['survey_data'] = $query;

    }


}

?>
