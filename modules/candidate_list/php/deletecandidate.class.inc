<?php
/**
 * This class handles a post request to delete a candidate
 * PHP Version 7
 *
 * @category Main
 * @package  candidate_list
 * @author   Shen Wang <wangshen.mcin@gmail.com>
 * @license  http://www.gnu.org/licenses/gpl-3.0.txt GPLv3
 * @link     https://www.github.com/aces/Loris/
 */
namespace LORIS\candidate_list;

use LORIS\StudyEntities\Candidate\CandID;
use \Psr\Http\Message\ResponseInterface;
use \Psr\Http\Message\ServerRequestInterface;

/**
 * This class handles a post request to upload a new category.
 * PHP Version 7
 *
 * @category Main
 * @package  candidate_list
 * @author   Shen Wang <wangshen.mcin@gmail.com>
 * @license  http://www.gnu.org/licenses/gpl-3.0.txt GPLv3
 * @link     https://www.github.com/aces/Loris/
 */
class DeleteCandidate extends \NDB_Page

{
    public $skipTemplate = true;

    /**
     * Same as the permissions for the main menu filter page.
     *
     * @param \User $user The user whose access is being checked
     *
     * @return bool true if the user has access to this page.
     */
    public function _hasAccess(\User $user): bool
    {
        return $user->hasPermission('user_accounts');
    }

    /**
     * Handle a post form
     *
     * @param ServerRequestInterface $request The incoming PSR7 request
     *
     * @return ResponseInterface The outgoing PSR7 response
     */
    public function handle(ServerRequestInterface $request): ResponseInterface
    {

        if ($request->getMethod() == "DELETE") {
            $id = basename($request->getUri()->getPath());
            $route = explode('/', $request->getUri()->getPath());
            if ($this->dodeleteCandidate($id)) {
                return (new \LORIS\Http\Response())
                    ->withStatus(200)
                    ->withHeader("Content-Type", "text/plain")
                    ->withBody(
                        new \LORIS\Http\StringStream(
                            json_encode("delete successfully")
                        )
                    );
            }
            return (new \LORIS\Http\Response())
                ->withStatus(403)
                ->withHeader("Content-Type", "text/plain")
                ->withHeader("Allow", "can't delete");

        } else {
            return (new \LORIS\Http\Response())
                ->withStatus(405)
                ->withHeader("Content-Type", "text/plain")
                ->withHeader("Allow", "DELETE");
        }
    }
    /**
     * Handles the upload category process
     *
     * @param ServerRequestInterface $request The incoming PSR7 request
     *
     * @return bool
     */
    public function dodeleteCandidate($CandID): bool
    {
        $DB = \NDB_Factory::singleton()->database();
        //check duplicate name category
        try {
// delete from db
// find sessionIDs

            $candidate = \Candidate::singleton(new CandID($CandID));
            // find the candidate with the given CandID
            $candidate->select(new CandID($CandID));
            $psc = $candidate->getCenterID();
            //
            $sessions = $candidate->getListOfTimePoints();
            foreach ($sessions as $sid) {


    // Check for existence of imaging data
    $filesExist = $DB->pselectOne(
        "SELECT COUNT(*) FROM files WHERE SessionID=:sid",
        ['sid' => $sessionID]
    );
    $numFiles   = (int)$filesExist;
    if ($numFiles > 0) {
        echo <<<MSG
Session ID $sessionID for candidate $CandID has imaging data and files
in the database, and should not be deleted. Look at `files` and `tarchive`
tables before deleting timepoint.
MSG;
        die();
    }



                $feedbackIDs = $DB->pselect(
                    'SELECT FeedbackID from feedback_bvl_thread WHERE SessionID =:sid',
                    ['sid' => $sid]
                );

                foreach ($feedbackIDs as $id) {
                    $DB->delete('feedback_bvl_entry',
                        ['FeedbackID' => $id['FeedbackID']]
                    );
                }
                // todo get fid
                $fIDs = $DB->pselect(
                    'SELECT FileID from files WHERE SessionID =:sid',
                    ['sid' => $sid]
                );
                //
                foreach ($fIDs as $fID) {

                    if ($DB->tableExists('files_qcstatus')) {
                        $DB->delete('files_qcstatus',
                            ['FileID' => $fID['FileID']]
                        );

                        $DB->delete('parameter_file',
                            ['FileID' => $fID['FileID']]
                        );
                        if ($DB->tableExists('feedback_mri_comments')) {
                            $DB->delete('feedback_mri_comments',
                                ['FileID' => $fID['FileID']]
                            );
                        }
                    }
                }

                if ($DB->tableExists('appointment')) {
                    $DB->delete('appointment',
                        ['SessionID' => $sid]
                    );
                }
                /////////////////////////////////////////
                $instruments = $DB->pselect(
                    'SELECT Test_name, CommentID FROM flag WHERE SessionID=:sid',
                    ['sid' => $sid]
                );
                foreach ($instruments as $instrument) {
                    try {

                        if ($DB->tableExists($instrument['Test_name'])) {
                            $DB->delete(
                                $instrument['Test_name'],
                                ['CommentID' => $instrument['CommentID']]
                            );
                        }
                        // Delete from conflicts
                        $DB->delete(
                            'conflicts_unresolved',
                            ['CommentId1' => $instrument['CommentID']]
                        );
                        $DB->delete(
                            'conflicts_unresolved',
                            ['CommentId2' => $instrument['CommentID']]
                        );
                        $DB->delete(
                            'conflicts_resolved',
                            ['CommentId1' => $instrument['CommentID']]
                        );
                        $DB->delete(
                            'conflicts_resolved',
                            ['CommentId2' => $instrument['CommentID']]
                        );
                    } catch (DatabaseException $e) {

                        echo "\nERROR:\n";
                        echo $e->getMessage();
                    }
                }
                ////. physiological_file get PhysiologicalFileID from physiological_file where SessionID = sid
                $pfileIDs = $DB->pselect(
                    'SELECT PhysiologicalFileID FROM physiological_file WHERE SessionID=:sid',
                    ['sid' => $sid]
                );

                try {
                    foreach ($pfileIDs as $pfileID) {
                        error_log(print_r($pfileID, true));
                        $p = $pfileID['PhysiologicalFileID'];

                        $DB->delete('physiological_task_event', ['PhysiologicalFileID' => $p]);

                        $DB->delete('physiological_event_file', ['PhysiologicalFileID' => $p]);

                        $DB->delete('physiological_archive', ['PhysiologicalFileID' => $p]);
                        $DB->delete('physiological_annotation_file', ['PhysiologicalFileID' => $p]);
                        $DB->delete('physiological_channel', ['PhysiologicalFileID' => $p]);
                        $DB->delete('physiological_coord_system_electrode_rel', ['PhysiologicalFileID' => $p]);
                        $DB->delete('physiological_parameter_file', ['PhysiologicalFileID' => $p]);

                        $DB->delete('physiological_file', ['PhysiologicalFileID' => $p]);
                    }

                    $DB->delete('flag', ['SessionID' => $sid]);
                    $DB->delete('media', ['session_id' => $sid]);
                    $DB->delete('issues', ['sessionID' => $sid]);
                    $DB->delete('mri_upload', ['SessionID' => $sid]);
                    $DB->delete('feedback_bvl_thread', ['SessionID' => $sid]);
                    $DB->delete('session', ['ID' => $sid]);
                } catch (DatabaseException $e) {
                    error_log("8errror8");
                    echo "\nERROR:\n";
                    echo $e->getMessage();
                }
            }

// Delete from other tables
            $tablesToDeleteFrom = [
                "participant_status",
                "participant_status_history",
                "candidate_consent_rel",
                "parameter_candidate",
                "SNP_candidate_rel",
                "CNV",
                "genomic_candidate_files_rel",
                "genomic_sample_candidate_rel",
                "issues",
                "candidate",
            ];
            if (isset($CandID) && !empty($CandID)) {
                foreach ($tablesToDeleteFrom as $table) {
                    if ($table !== "candidate_consent_rel") {
                        $DB->delete($table, ["CandID" => $CandID]);} else {
                        $DB->delete($table, ["CandidateID" => $CandID]);}
                }
            }

// add into issue tracker
            if ($CandID !== null && $CandID !== '') {
                $DB->insert("issues", ['title' => 'Candidate ' . $CandID . ' is archived',
                    'status' => 'closed',
                    'centerID' => $psc,
                    'reporter' => \User::singleton()->getUsername(),
                    'lastUpdatedBy' => \User::singleton()->getUsername(),
                ]);
            }
            return true;
        } catch (Exception $e) {
            return false;}
    }
}

