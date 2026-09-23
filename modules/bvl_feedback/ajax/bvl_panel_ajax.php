<?php
/**
 * File to be included in AJAX scripts for the bvl_feedback panel.
 * These files should initialize a user, a candidate and a feedback object.
 *
 * These files are intended to be used at the timepoint list,
 * instrument list and on individual instruments.
 *
 * PHP version 7
 *
 * @category Behavioural
 * @package  Main
 * @author   Evan McIlroy <evanmcilroy@gmail.com>
 * @license  GPLv3 <http://www.gnu.org/licenses/gpl-3.0.en.html>
 * @link     https://www.github.com/aces/Loris-Trunk/
 */

namespace LORIS\bvl_feedback;
use \LORIS\StudyEntities\Candidate\CandID;

//----------------------------------------//
// Ensure user is allowed to issue any of //
// the bvl_feedback AJAX calls            //
//----------------------------------------//
$user = \User::singleton();
if (!$user->hasPermission('bvl_feedback')) {
    header("HTTP/1.1 403 Forbidden");
    header("Content-Type: text/plain");
    exit(
        "You do not have valid permissions for this
         operation."
    );
}
$username = $user->getUsername();
if (isset($_POST['candID']) && (empty($_POST['sessionID']))) {
    $candID         = new CandID($_POST['candID']);
    $feedbackThread = \NDB_BVL_Feedback::Singleton($username, $candID);
} elseif (isset($_POST['candID']) && isset($_POST['sessionID'])
    && (empty($_POST['commentID']))
) {
    $candID         = new CandID($_POST['candID']);
    $feedbackThread =& \NDB_BVL_Feedback::Singleton(
        $username,
        $candID,
        $_POST['sessionID']
    );
} elseif (isset($_POST['candID']) && isset($_POST['sessionID'])
    && isset($_POST['commentID'])
) {
    $candID         = new CandID($_POST['candID']);
    $feedbackThread =& \NDB_BVL_Feedback::Singleton(
        $username,
        $candID,
        $_POST['sessionID'],
        $_POST['commentID']
    );
}
