<?php
/**
 * Main class for bobdule corresponding to /bobdule/
 * endpoint.
 *
 * PHP Version 7
 *
 * @category Module
 * @package  Bobdule
 * @author   Jordan Stirling <jordan.stirling@mcgill.ca>
 * @license  http://www.gnu.org/licenses/gpl-3.0.txt GPLv3
 * @link     https://www.github.com/aces/Loris
*/
namespace LORIS\bobdule;

class Bobdule extends \NDB_Menu_Filter_Form
{
    public $skipTemplate  = true;

    function _hasAccess(\User $user): bool
    {
        return $user->hasPermission('data_team_helper');
    }

    function _setupVariables()
    {
        $this->query = "
            FROM session s
                JOIN flag ON (s.ID=flag.SessionID AND flag.Test_name='final_radiological_review_VSA' AND (flag.Data_entry='In Progress' OR flag.Data_entry IS NULL))
                JOIN final_radiological_review_VSA t ON (t.CommentID=flag.CommentID)
            WHERE EXISTS (
                SELECT * FROM files f
                    JOIN mri_scan_type m ON (f.AcquisitionProtocolID=m.ID)
                WHERE f.SessionID=s.ID AND (m.scan_type like '%t1w%' or m.scan_type like '%t2w%')
            ) AND flag.CommentID NOT LIKE 'DDE_%'";
        $this->columns = array(
                            'flag.CommentID',
                            's.ID',
                            't.Date_taken',
                            's.CandID',
                            's.Visit_label',
                            't.clinical_mri',
                            't.clinical_follow',
                            't.subtest_1_1_check',
                            't.subtest_1_2_check',
                            't.subtest_1_3_check'
                         );
    }

    function getJSDependencies()
    {
        $factory = \NDB_Factory::singleton();
        $baseURL = $factory->settings()->getBaseURL();
        $deps    = parent::getJSDependencies();
        return array_merge(
            $deps,
            array(
                $baseURL . "/bobdule/js/bobdule.js",
            )
        );
    }
}
