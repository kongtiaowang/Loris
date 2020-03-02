<?php
/**
 * This file contains a wrapper around imaging comments for a session or File.
 *
 * PHP Version 7
 *
 * @category Imaging
 * @package  Imaging
 * @author   Loris Team <loris.mni@bic.mni.mcgill.ca>
 * @license  http://www.gnu.org/licenses/gpl-3.0.txt GPLv3
 * @link     https://www.github.com/aces/Loris/
 */

class FeedbackMRI_IBIS
{
    /**
     * FileID from files table
     */
    var $fileID;

    /**
     * ID from session table
     */
    var $sessionID;

    /**
     * CommentType from feedback_mri_comment_types table (enum('visit','volume'))
     */
    var $objectType;

    private $DB;

    private $items = [
        'T1' => [
            't1' => ['l' => 'T1',
                't' => 'select',
                'o' => [
                    '' => '',
                    '1' => 'PASS',
                    '2' => 'FAIL',
                    '3' => 'QUESTIONABLE'
                ]
            ],
            't1_overall_motion_score' => ['l' => 'OVERALL MOTION SCORE',
                't' => 'select',
                'o' => [
                    '' => '',
                    '1' => '1 (PASS)',
                    '2' => '2 (PASS)',
                    '3' => '(3) QUESTIONABLE',
                    '4' => '(4) FAIL'
                ]
            ],
            't1_presence_absence_motion' => ['l' => 'PRESENCE OR ABSENCE OF MOTION',
                't' => 'select',
                'o' => [
                    '' => '', '1' => '1 (PROBLEM PRESENT)', '2' => '0 PROBLEM ABSENT'
                ]
            ],
            't1_eye_motion' => ['l' => 'EYE MOTION',
                't' => 'select',
                'o' => [
                    '' => '', '1' => '1 (PROBLEM PRESENT)', '2' => '0 PROBLEM ABSENT'
                ]
            ],
            't1_ringing' => ['l' => 'RINGING',
                't' => 'select',
                'o' => [
                    '' => '', '1' => '1 (PROBLEM PRESENT)', '2' => '0 PROBLEM ABSENT'
                ]
            ],
            't1_hemodynamic_artifact' => ['l' => 'HEMODYNAMIC ARTIFACT',
                't' => 'select',
                'o' => [
                    '' => '', '1' => '1 (PROBLEM PRESENT)', '2' => '0 PROBLEM ABSENT'
                ]
            ],
            't1_coverage_crop' => ['l' => 'COVERAGE/CROP',
                't' => 'select',
                'o' => [
                    '' => '', '1' => '1 (PROBLEM PRESENT)', '2' => '0 PROBLEM ABSENT'
                ]
            ],
            't1_comment' => ['l' => 'COMMENT', 't' => 'text']
        ],
        'T2' => [
            't2' => ['l' => 'T2',
                't' => 'select',
                'o' => [
                    '' => '',
                    '1' => 'PASS',
                    '2' => 'FAIL',
                    '3' => 'QUESTIONABLE'
                ]
            ],
            't2_overall_motion_score' => ['l' => 'OVERALL MOTION SCORE',
                't' => 'select',
                'o' => [
                    '' => '',
                    '1' => '1 (PASS)',
                    '2' => '2 (PASS)',
                    '3' => '(3) QUESTIONABLE',
                    '4' => '(4) FAIL'
                ]
            ],
            't2_presence_absence_motion' => ['l' => 'PRESENCE OR ABSENCE OF MOTION',
                't' => 'select',
                'o' => [
                    '' => '', '1' => '1 (PROBLEM PRESENT)', '2' => '0 PROBLEM ABSENT'
                ]
            ],
            't2_eye_motion' => ['l' => 'EYE MOTION',
                't' => 'select',
                'o' => [
                    '' => '', '1' => '1 (PROBLEM PRESENT)', '2' => '0 PROBLEM ABSENT'
                ]
            ],
            't2_ringing' => ['l' => 'RINGING',
                't' => 'select',
                'o' => [
                    '' => '', '1' => '1 (PROBLEM PRESENT)', '2' => '0 PROBLEM ABSENT'
                ]
            ],
            't2_hemodynamic_artifact' => ['l' => 'HEMODYNAMIC ARTIFACT',
                't' => 'select',
                'o' => [
                    '' => '', '1' => '1 (PROBLEM PRESENT)', '2' => '0 PROBLEM ABSENT'
                ]
            ],
            't2_coverage_crop' => ['l' => 'COVERAGE/CROP',
                't' => 'select',
                'o' => [
                    '' => '', '1' => '1 (PROBLEM PRESENT)', '2' => '0 PROBLEM ABSENT'
                ]
            ],
            't2_dark_cerebellar_tonsils' => ['l' => 'DARK CEREBELLAR TONSILS',
                't' => 'select',
                'o' => [
                    '' => '', '1' => '1 (PROBLEM PRESENT)', '2' => '0 PROBLEM ABSENT'
                ]
            ],
            't2_comment' => ['l' => 'COMMENT', 't' => 'text']
        ],
        'DWI' => [
            'dwi_qc' => ['l' => 'PRELIMINARY QC OF DWI',
                't' => 'select',
                'o' => [
                    '' => '', '1' => 'PRELIMINARY PASS', '2' => 'PRELIMINARY FAILURE', '3' => 'PRELIMINARY QUESTIONABLE'
                ]
            ],
            'dwi_exclusion_reason' => ['l' => 'PRELIMINARY DWI EXCLUSION REASON ',
                't' => 'select',
                'o' => [
                    '' => '', '1' => 'Motion', '2' => 'Coverage', '3' => 'Other'
                ]
            ],
            'dwi_comment' => ['l' => 'COMMENT', 't' => 'text']
        ]
    ];

    /**
     * Constructor sets object parameters
     *
     * @param int $fileID    The fileID that this feedback is for
     * @param int $sessionID The SessionID that this feedback is for
     */
    function __construct($fileID='', $sessionID='')
    {
        // set object properties
        $this->fileID    = $fileID;
        $this->sessionID = $sessionID;

        // determine object type (visit or volume)
        if (!empty($fileID)) {
            $this->objectType = 'volume';
        } else {
            $this->objectType = 'visit';
        }

        // create DB object
        $this->DB =& Database::singleton();
    }

    /**
     * Clears all comments from the object
     *
     * @return void
     * @access public
     */
    function clearComment()
    {
        $this->DB->delete('feedback_mri_comments_ibis', $this->_buildWhereAssoc());
        return true;
    }


    /**
     * Gets the comments stored for the object
     *
     * @return array tree: $cA[$typeID]['predefined'] is an array with integer
     *               keys (PredefinedCommentID) and boolean values (true) and
     *               $cA[$typeID]['text'] is an array of strings (free-form
     *               comments) where $typeID is always the CommentTypeID from
     *               feedback_mri_comment_types table
     */
    function getComment()
    {
        // start building the query
        $query = "SELECT * FROM feedback_mri_comments_ibis WHERE ".
            $this->_buildWhere();

        $result = $this->DB->pselectRow($query, array());
        return $result;
    }

    function save($values) {
        // determine whether to insert or update
        $query = "SELECT count(CommentID) AS UpdateNeeded FROM
                  feedback_mri_comments_ibis
                  WHERE SessionID=:SID AND FileID=:FID";

        $updateNeeded = $this->DB->pselectOne(
            $query,
            array(
                'SID' => $this->sessionID,
                'FID'  => $this->fileID,
            )
        );

        // build the query
        if ($updateNeeded) {
            $this->DB->update(
                'feedback_mri_comments_ibis',
                $values,
                array(
                    'SessionID' => $this->sessionID,
                    'FileID'    => $this->fileID,
                )
            );
        } else {
            $this->DB->insert(
                'feedback_mri_comments_ibis',
                array_merge($values,
                    [
                        'SessionID' => $this->sessionID,
                        'FileID'    => $this->fileID
                    ])
            );
        }
    }

    /**
     * Gets the list of all comment types
     *
     * @return array A two-dimensional array of ints (CommentTypeID) and
     *               three-element arrays ('name'=>string CommentName,
     *               'field'=>string name of column in mri table for status,
     *               'values'=>array of possible enum values for field)
     */
    function getCommentItems()
    {
        return $this->items;
    }

    /**
     * Constructs an appropriate where expression to limit selects to the
     * current object
     *
     * @return string where string to limit selects to current object
     * @access private
     */
    function _buildWhere()
    {
        // build the where depending on object and subject type
        if ($this->objectType == 'volume') {
            // per-volume
            return "FileID='$this->fileID'";
        } else {
            // per-visit
            return "SessionID='$this->sessionID'";
        }
    }
}
