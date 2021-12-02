<?php
/**
 * Sub class for the bobdule corresponding to /bobdule/other_reviews
 * endpoint. This endpoint is used to get the visits site radiological review
 * as well as the previous visits final radiological review.
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

/**
 * Class Other_Reviews
 * @package LORIS\bobdule
 */
class Other_Reviews extends \NDB_Page
{
    public $skipTemplate  = true;

    function _hasAccess(\User $user): bool
    {
        return $user->hasAnyPermission(
            array(
                'edit_final_radiological_review',
                'view_final_radiological_review',
            )
        );
    }

    /**
     * This endpoint is to behave like an API endpoint and only return json values.
     *
     * @return string
     * @throws \ConfigurationException
     */
    function toJSON(): string
    {
        // create DB object
        $factory = \NDB_Factory::singleton();
        $DB      = $factory->database();
        $candID  = $_REQUEST['candID'];
        $visit   = $_REQUEST['visit'];

        $site = $DB->pselectRow("
            SELECT f.CommentID,
                s.ID
            FROM flag f
                JOIN session s ON (s.ID = f.sessionID)
            WHERE f.Test_name = 'Radiology_Review_VSA'
                AND f.CommentID NOT LIKE 'DDE_%'
                AND s.CandID = :candID
                AND s.Visit_label = :visit
        ", array(
            "candID" => $candID,
            "visit"  => $visit
        ));

        $previous = $DB->pselect("
            SELECT
                r.CommentID,
                s.Visit_label
            FROM final_radiological_review r
                JOIN flag f ON (f.CommentID = r.CommentID)
                JOIN session s ON (s.ID = f.sessionID)
            WHERE s.CandID = :candID
        ", array("candID" => $candID));

        $otherReviews = array(
            "site" => array(
                "commentID" => $site['CommentID'],
                "sessionID" => $site['ID']
            ),
            "previous" => array()
        );

        foreach ($previous as $visit) {
            $otherReviews["previous"][$visit['Visit_label']] = $visit['CommentID'];
        }

        return json_encode($otherReviews);
    }
}
