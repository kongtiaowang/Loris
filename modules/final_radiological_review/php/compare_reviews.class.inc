<?php
/**
 * Code for the form used to compare all the reviews done in the
 * final radiological review module.
 * See final_radiological_review for a description of how the module 
 * works.
 *
 * PHP Version 7
 *
 * @category Final_Radiological_Review
 * @package  Main
 * @author   Dave MacFarlane <driusan@bic.mni.mcgill.ca>
 * @license  Loris license
 * @link     https://www.github.com/aces/Loris-Trunk/
 */
 
namespace LORIS\final_radiological_review; 

require_once __DIR__ . "/final_radiological_review.class.inc";

/**
 * Generates the form to compare all the reviews (final, site and extra)
 * in the final_radiological_review module.
 *
 * @category Final_Radiological_Review
 * @package  Main
 * @author   Dave MacFarlane <driusan@bic.mni.mcgill.ca>
 * @license  Loris license
 * @link     https://www.github.com/aces/Loris-Trunk/
 */
class Compare_Reviews extends \NDB_Form
{
    /**
     * Table that the review is saved to
     */
    var $__table = 'final_radiological_review';

    /**
     * Determine whether the logged in user has permission
     * to view this page
     *
     * @return boolean page access
     */
    function _hasAccess(\User $user) : bool
    {
        return (
            $user->hasPermission('view_final_radiological_review') ||
            $user->hasPermission('edit_final_radiological_review')
        );
    }
    
    /**
     * Wrapper to get the user object and check the permission.
     * Used both in hasAccess and the setup when determining
     * if the user can view, or view and edit the page
     *
     * @param string $perm Name of the permission to check
     *
     * @return  boolean Whether the user has said permission
     * @private
     */
    function _hasPerm($perm)
    {
        $user =& \User::singleton();
        return $user->hasPermission($perm);
    }

    /**
     * Constructor which sets up this->tpl_data for the form
     *
     * @return void
     */
    function setup()// @codingStandardsIgnoreLine
    {
        $yes_no       = array(
                         ''    => '',
                         'yes' => 'Yes',
                         'no'  => 'No',
                        );
        $exclusionary = array(
                         ''                 => '',
                         'exclusionary'     => 'Exclusionary',
                         'non_exclusionary' => 'Non-Exclusionary',
                        );
        $results      = array(
                         ''         => '',
                         'normal'   => 'Normal',
                         'abnormal' => 'Abnormal',
                         'atypical' => 'Atypical',
                        );
        $abnormality  = array(
                         null => '',
                         '0'  => 'None',
                         '1'  => 'Minimal',
                         '2'  => 'Mild',
                         '3'  => 'Moderate',
                         '4'  => 'Marked',
                        );

        $DB =& \Database::singleton();
        $radiologists_q = $DB->pselect(
            "SELECT * FROM examiners WHERE radiologist=True",
            array()
        );

        $radiologists[''] = '';
        foreach ($radiologists_q as &$row) {
            $radiologists[$row['examinerID']] = $row['full_name'];
        }

        $this->addSelect(
            'Final_Examiner',
            'Radiologist/Reviewer:',
            $radiologists
        );
        $this->addScoreColumn('CandID', 'DCCID:', 'Unknown');
        $this->addScoreColumn('PSCID', 'PSCID:', 'Unknown');
        $this->addScoreColumn('SessionID', 'Session ID:', '');
        $this->addScoreColumn('CommentID', 'Comment ID:', '');
        $this->addScoreColumn('Visit_label', 'Visit Label:', '');

        $this->addScoreColumn('DICOM_Folder_Name', 'DICOM Folder:', 'Unknown');
        $this->addScoreColumn('DICOM_ID', 'DICOM ID:', 'Unknown');

        $this->addSelect('Review_Done', 'Review Done:', $yes_no);
        $this->addSelect(
            'Final_Review_Results',
            'Results of Radiology Review:',
            $results
        );
        $this->addSelect(
            'Final_Exclusionary',
            'Exclusionary Status:',
            $exclusionary
        );
        $this->addSelect('SAS', 'SAS Score:', $abnormality);
        $this->addSelect('PVS', 'PVS Score:', $abnormality);
        $this->addBasicTextArea(
            'Final_Incidental_Findings',
            'Description of Incidental Findings (Comments):'
        );
        $this->addSelect('Finalized', 'Is review finalized?', $yes_no);

        $this->addSelect(
            'Final_Examiner2',
            'Radiologist/Reviewer:',
            $radiologists
        );
        $this->addSelect('Review_Done2', 'Review Done:', $yes_no);
        $this->addSelect(
            'Final_Review_Results2',
            'Results of Radiology Review:',
            $results
        );
        $this->addSelect(
            'Final_Exclusionary2',
            'Exclusionary Status:',
            $exclusionary
        );
        $this->addSelect('SAS2', 'SAS Score:', $abnormality);
        $this->addSelect('PVS2', 'PVS Score:', $abnormality);
        $this->addBasicTextArea(
            'Final_Incidental_Findings2',
            'Description of Incidental Findings (Comments):'
        );
        // Original review, this might move
        $this->addScoreColumn(
            'Original_Scan_Done',
            'Original Scan Done:',
            'Unknown'
        );
        $this->addScoreColumn(
            'Original_Review_Results',
            'Original Results:',
            'Unknown'
        );
        $this->addScoreColumn(
            'Original_Exclusionary',
            'Original Exclusionary Results:',
            ''
        );
        $this->addScoreColumn(
            'Original_Incidental_Findings',
            'Original Incidental Findings:',
            ''
        );
        $this->addScoreColumn(
            'Original_Examiner',
            'Original Radiologist/Reviewer:',
            'Unknown'
        );

        $this->form->addElement('static', 'history', '', '');

        if ($this->_hasPerm('edit_final_radiological_review') == false) {
            $this->form->freeze();
        }

        //DEPRECATION MESSAGE FOR 18.0
        error_log(
            "The Final Radiological Review Module is deprecated and will be "
            . "removed in a future release (Loris 18.0). Please update your code "
            . "in accordance. If you are actively using this module, "
            . "it should be moved to the `project/modules` directory."
        );
    }

    /**
     * Overrides the base class getDefaults to get the needed
     * information from the final_radiological_review table for
     * smarty
     *
     * @throws \LorisException
     * @return array defaults for smarty to use
     */
    function _getDefaults()
    {
        if (isset($this->identifier)) {
            $DB =& \Database::singleton();
            // Get the basics for the final radiological review
            $final_review = $DB->pselectRow(
                "SELECT * FROM $this->__table WHERE CommentID=:CID",
                array('CID' => $this->identifier)
            );
            if (empty($final_review)) {
                $final_review = array(
                                 'CommentID'                  => '',
                                 'Review_Done'                => '',
                                 'Final_Review_Results'       => '',
                                 'Final_Exclusionary'         => '',
                                 'SAS'                        => '',
                                 'PVS'                        => '',
                                 'Final_Incidental_Findings'  => '',
                                 'Final_Examiner'             => '',
                                 'Final_Review_Results2'      => '',
                                 'Final_Examiner2'            => '',
                                 'Final_Exclusionary2'        => '',
                                 'Review_Done2'               => '',
                                 'SAS2'                       => '',
                                 'PVS2'                       => '',
                                 'Final_Incidental_Findings2' => '',
                                 'Finalized'                  => '',
                                );
            }

            if ($DB->tableExists('radiology_review') === false) {
                throw new \LorisException(
                    "Table 'radiology_review' does not exist."
                    . " Please have this instrument set up in order"
                    . " to use this module properly."
                );
            }

            $original_review = $DB->pselectRow(
                "SELECT r.Scan_done as Original_Scan_Done, 
                r.review_results as Original_Review_Results, 
                r.abnormal_atypical_exclusionary as Original_Exclusionary,
                r.Incidental_findings as Original_Incidental_Findings, 
                e.full_name as Original_Examiner, 
                c.PSCID as PSCID, 
                c.CandID as CandID, 
                s.Visit_Label as Visit_label, 
                GROUP_CONCAT(substring_index(t.sourcelocation, '/', -1))
                as DICOM_Folder_Name, 
                f.SessionID as SessionID, 
                f.CommentID as CommentID 
                FROM radiology_review r LEFT JOIN examiners e 
                on (e.ExaminerID=r.Examiner) 
                LEFT JOIN flag f ON (f.CommentID=r.CommentID) 
                LEFT JOIN session s ON (s.ID=f.SessionID) 
                LEFT JOIN candidate c ON (c.CandID=s.CandID) 
                LEFT JOIN tarchive t ON (upper(t.PatientName) 
                LIKE CONCAT(upper(c.PSCID), '_', upper(s.CandID), '_',
                upper(s.visit_label), '%')) 
                WHERE r.CommentID=:CID 
                GROUP by CandID, PSCID, Visit_label, SessionID, CommentID,
                r.Scan_done, r.review_results,
                r.abnormal_atypical_exclusionary, 
                r.Incidental_findings, e.full_name",
                array('CID' => $this->identifier)
            );
            if (empty($original_review)) {
                $original_review = array(
                                    'Original_Scan_Done'           => '',
                                    'Original_Review_Results'      => '',
                                    'Original_Exclusionary'        => '',
                                    'Original_Incidental_Findings' => '',
                                    'Original_Examiner'            => '',
                                   );
            }

            $history = $DB->pselect(
                'SELECT 
                    frrh.userID, 
                    frrh.changeDate, 
                    frrh.col, 
                    frrh.old, 
                    frrh.new, 
                    ex_old.full_name as old_examiner, 
                    ex_new.full_name as new_examiner
                 FROM final_radiological_review_history frrh
                 LEFT JOIN examiners ex_old 
                    ON(col="Final_Examiner" AND old=ex_old.examinerID)
                 LEFT JOIN examiners ex_new 
                    ON(col="Final_Examiner" AND new=ex_new.examinerID)
                WHERE CommentID= :primKey 
                ORDER BY changeDate DESC',
                array('primKey' => $this->identifier)
            );

            $history_display = '';
            foreach ($history as &$history_item) {
				# For the Final_Examiner column, display the full name instead of the
				# numerical ID
				$oldValue = $history_item['col'] == 'Final_Examiner' ?
				    $history_item['old_examiner'] : $history_item['old'];
				$newValue = $history_item['col'] == 'Final_Examiner' ?
				    $history_item['new_examiner'] : $history_item['new'];
				    
                $history_display .= '<tr><td>' .
                    $history_item['changeDate'] . '</td><td>' .
                    $history_item['userID'] . '</td><td>' .
                    $history_item['col'] . '</td><td>' .
                    \LORIS\final_radiological_review\Final_Radiological_Review::_makePretty($history_item['col'], $oldValue) .
                    '</td><td>' .
                    \LORIS\final_radiological_review\Final_Radiological_Review::_makePretty($history_item['col'], $newValue) .
                    '</td></tr>';
            }
            $defaults   = array_merge(
                $final_review,
                $original_review
            );
            $condition1 = $defaults['Final_Review_Results']
                              !=  $defaults['Final_Review_Results2'];
            $condition2 = $defaults['Final_Exclusionary']
                              != $defaults['Final_Exclusionary2'];
            $condition3 = $defaults['SAS'] != $defaults['SAS2'];

            $condition4 = $defaults['PVS'] != $defaults['PVS2'];
            if ($condition1 || $condition2 || $condition3 || $condition4) {
                $this->tpl_data['conflicts'][]
                    = "Conflict between final and extra review";
            }

            $condition1 = $defaults['Final_Review_Results']
                              != $defaults['Original_Review_Results'];
            $condition2 = $defaults['Original_Exclusionary']
                              != $defaults['Final_Exclusionary'];
            if ($condition1 || $condition2) {
                $this->tpl_data['conflicts'][]
                    = "Conflict between original and final review";
            }

            $this->tpl_data['history'] = $history_display;
            return $defaults;
        }
        return array();
    }

    /**
     * Converts empty string to null, because Smarty converts null
     * to empty, and we don't want to screw up the table
     *
     * @param array  $arr   A reference to the array being cleaned
     * @param string $field The field being cleaned
     *
     * @return array $arr Modified so that empty strings are instead
     *                    null
     */
    function stripEmpty(&$arr, $field)
    {
        if ($arr[$field] === '') {
            $arr[$field] = null;
        }
        return $arr;
    }

    /**
     * Process the submitted data and save if valid
     *
     * @param array $values The data submitted on the form
     *
     * @return boolean Always true?
     */
    function _process($values)
    {
        if (!is_array($values)
            || count($values) == 0
            || $this->_hasPerm('edit_final_radiological_review') == false
        ) {
            return true;
        }

        $this->stripEmpty($values, 'Review_Done');
        $this->stripEmpty($values, 'SAS');
        $this->stripEmpty($values, 'PVS');
        $this->stripEmpty($values, 'Final_Examiner');
        $this->stripEmpty($values, 'SAS2');
        $this->stripEmpty($values, 'PVS2');
        $this->stripEmpty($values, 'Final_Examiner2');
        $this->stripEmpty($values, 'Review_Done2');
        $this->stripEmpty($values, 'Finalized');

        if (!(is_null($_SESSION['State']))) {
            $currentUser = \User::singleton($_SESSION['State']->getUsername());
            $userID      = $currentUser->getData("UserID");
        }

        $DB =& \Database::singleton();
        if (isset($this->identifier)) {
            $exists = $DB->pselectRow(
                "SELECT * FROM " . $this->__table . " WHERE CommentID=:CID",
                array('CID' => $this->identifier)
            );

            if ($exists == array()) {
                $insert_values = array_merge(
                    array('CommentID' => $this->identifier),
                    $values
                );
                $DB->insert($this->__table, $insert_values);
            } else {
                /* update the final radiological review history table
                 * if any field was updated */
                foreach ($values as $key=>$val) {
                    if ($exists[$key] != $val) {
                        $update_vals = array(
                                        'col'       => $key,
                                        'new'       => $val,
                                        'old'       => $exists[$key],
                                        'CommentID' => $this->identifier,
                                        'userID'    => $userID,
                                       );

                        $DB->insert(
                            "final_radiological_review_history",
                            $update_vals
                        );
                    }
                }
                $DB->update(
                    $this->__table,
                    $values,
                    array('CommentID' => $this->identifier)
                );
            }

        }
        return true;
    }
}
?>