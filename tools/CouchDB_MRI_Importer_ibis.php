<?php
require_once __DIR__ . "/../../vendor/autoload.php";
require_once 'generic_includes.php';

/**
 * Wrapper around CouchDB MRI functions
 *
 *  @category CouchDB_Import_Script
 *  @package  Main
 *  @author   Dave MacFarlane <david.macfarlane2@mcgill.ca>
 *  @license  http://www.gnu.org/licenses/gpl-3.0.txt GPLv3
 *  @link     https://www.github.com/aces/Loris/
 */
class CouchDBMRIImporter
{
    var $SQLDB; // reference to the database handler, store here instead
    // of using Database::singleton in case it's a mock.
    var $CouchDB; // reference to the CouchDB database handler

    // this is just in an instance variable to make
    // the code a little more readable.
    private $Dictionary = array();
    var $feedback_Comments; //reference to list of MRI feedback types;
    var $feedback_PreDefinedComments; //reference to list of MRI feedback types;
    var $mri_header_fields;// reference to list of mri header fields
    /**
     * Constructor for CouchDBMRIImporter
     */
    function __construct()
    {
        $factory       = \NDB_Factory::singleton();
        $config        = \NDB_Config::singleton();
        $couchConfig   = $config->getSetting('CouchDB');
        $this->SQLDB   = $factory->Database();
        $this->CouchDB = $factory->couchDB(
            $couchConfig['dbName'],
            $couchConfig['hostname'],
            intval($couchConfig['port']),
            $couchConfig['admin'],
            $couchConfig['adminpass']
        );
    }

    /**
     * Runs the script
     *
     * @return void
     */
    function run()
    {
        $ScanTypes = $this->getScanTypes();
        $this->updateDataDict($ScanTypes);

        $CandidateData = $this->getCandidateData($ScanTypes);
        $this->updateCandidateDocs($CandidateData, $ScanTypes);
    }


    public function getDataDictionary($types)
    {
        $this->_buildDataDictionary($types);
        return $this->Dictionary;
    }

    /**
     * Add data dictionary for all selected types in DQT
     *
     * @param array $types The different selected types in the database
     *
     * @return void
     */
    function updateDataDict($types)
    {
        $this->CouchDB->replaceDoc(
            "DataDictionary:mri_data",
            array(
                'Meta'           => array('DataDict' => true),
                'DataDictionary' => array('mri_data' => $this->getDataDictionary($types))
            )
        );
    }

    /**
     * Generates query for each of Scan types
     *
     * @param array $ScanTypes all selected scan types in the database
     *
     * @return string $Query
     */
    function _generateCandidatesQuery($ScanTypes)
    {

       $s = $ScanTypes;
        $Query = "SELECT c.PSCID, s.Visit_label, s.ID as SessionID, fmric.Comment as QCComment";

        foreach($s as $scan){
            $scantype=$scan['ScanType'];

            //-------------------------------------------------------------------------//
            // Add to the query a subselect that will compute the number of selected   //
            // files (0,1,...) for the given session/modality                          //
            //-------------------------------------------------------------------------//
            $Query .= ', ('
                   .  $this->_getQueryForSelectedFiles('count(*)', $scantype)
                   . ") AS NbSelected_$scantype";

            //-------------------------------------------------------------------------//
            // Add to the query a subselect that will compute the selected file        //
            // for the given session/modality. If more than one selected file exists,  //
            // the subquery will return 'Multiple Selected files'. If no selected file //
            // exists, the subselect will return 'No selected file'. Otherwise the     //
            // file path of the selected file is returned by the subselect             //
            //-------------------------------------------------------------------------//
            $Query .= ', '
                    . '('
                    . ' CASE ('. $this->_getQueryForSelectedFiles('count(*)', $scantype) . ') '
                    . '  WHEN 1 '
                    . '    THEN (' . $this->_getQueryForSelectedFiles('f.File', $scantype) . ') '
                    . '  WHEN 0 '
                    . '    THEN "No selected file" '
                    . '  ELSE "Multiple Selected files"'
                    . ' END'
                    . ") as Selected_$scantype";

            //---------------------------------------------------------------------------//
            // Add to the query a subselect that will compute the Qc status of the       //
            // selected file for the given session/modality. If more than one selected   //
            // file exists, the subquery will return 'Unknown: multiple Selected files'. //
            // If no selected file exists, the subselect will return 'No selected file'. //
            // Otherwise the subselect will return the Qc status of the selected file (or//
            // 'No Qc on selected file' if the file has not been Qced)                   //
            //---------------------------------------------------------------------------//
            $Query  .= ', '
                    . '('
                    . ' CASE (' . $this->_getQueryForSelectedFiles('count(*)', $scantype) . ') '
                    . '  WHEN 1 '
                    . '    THEN ('
                    .        $this->_getQueryForSelectedFiles(
                                 'COALESCE(fqs.QCStatus, "No Qc on selected file")',
                                 $scantype,
                                 's.ID'
                             )
                    .     ') '
                    . '  WHEN 0 '
                    . '    THEN "No selected file" '
                    . '  ELSE "Unknown: multiple Selected files"'
                    . ' END'
                    . ") as {$scantype}_QCStatus";
        }

        $Query .= " FROM session s"
                . " JOIN candidate c USING (CandID)"
                . " LEFT JOIN feedback_mri_comments fmric"
                . " ON (fmric.CommentTypeID=7 AND fmric.SessionID=s.ID)"
                . " LEFT JOIN participant_status ps ON ( ps.Candid = c.Candid )"
                . " WHERE c.Entity_type != 'Scanner' AND c.PSCID NOT LIKE '%9999'"
                . " AND c.Active='Y' AND s.Active='Y'"
                . " AND c.RegistrationCenterID NOT IN (1,8,9,10)"
                . " AND (ps.participant_status NOT IN (2,3,4) OR ps.participant_status IS NULL)"
                . " AND c.RegistrationProjectID NOT IN (5,6)";

        return $Query;
    }

    /**
     * Build a query to find specific information on the MRI files that were selected
     * for a given session/scan type.
     *
     * @param string $whatToSelect the comma separated list of fields to select.
     * @param string $scantype     name of the scan type.
     *
     * @return string built query.
     */
    function _getQueryForSelectedFiles($whatToSelect, $scanType)
    {
        return "SELECT $whatToSelect "
             . 'FROM files f '
             . 'LEFT JOIN mri_scan_type msc ON (f.AcquisitionProtocolID=msc.ID) '
             . 'LEFT JOIN files_qcstatus fqs USING (fileid) '
             . 'WHERE f.SessionID=s.ID '
             . "AND msc.Scan_type='$scanType' "
             . 'AND fqs.selected=\'true\'';
    }


    /**
     * Add mri header information  to each selected scan
     *
     * @param file object $FileObj   File object
     * @param string      $scan_type Scan type of the selected file
     *
     * @return array      $header    Array of mri header info for the given
     *                                     file
     */
    function _addMRIHeaderInfo($FileObj, $scan_type)
    {
        $header    = array();
        $type      = $scan_type;
        $coord     = 'CoordinateSpace';
        $ser_desc  = 'series_description';
        $ser_num   = 'series_number';
        $tot_rej   = 'processing:total_rejected';
        $inter_rej = 'IntergradientRejected_'.$type;
        $pipeline  = 'processing:pipeline';

        $header['ScannerID_'.$type]           = $this->_getScannerID((int)$FileObj->getParameter('FileID'));
        $header['Pipeline_'.$type]            = $FileObj->getParameter('Pipeline');
        $header['OutputType_'.$type]          = $FileObj->getParameter('OutputType');
        $header['AcquisitionProtocol_'.$type] = $FileObj->getAcquisitionProtocol();
        $header['CoordinateSpace_'.$type]     = $FileObj->getParameter($coord);
        $header['Algorithm_'.$type]           = $FileObj->getParameter('Algorithm');
        $header['AcquisitionDate_'.$type]     = $this->_getDate(
            $FileObj,
            'acquisition_date'
        );
        $header['FileInsertDate_'.$type]      = $FileObj->getParameter('InsertTime');
        $header['SeriesDescription_'.$type]   = $FileObj->getParameter($ser_desc);
        $header['SeriesNumber_'.$type]        = $FileObj->getParameter($ser_num);
        $header['EchoTime_'.$type]            = number_format(
            $FileObj->getParameter('echo_time')*1000,
            2
        );
        $header['RepetitionTime_'.$type]      = number_format(
            $FileObj->getParameter('repetition_time')*1000,
            2
        );
        $header['SliceThickness_'.$type]      = number_format(
            $FileObj->getParameter('slice_thickness'),
            2
        );
        $header['Time_'.$type]          = number_format(
            $FileObj->getParameter('time'),
            2
        );
        $header['Comment_'.$type]       = $FileObj->getParameter('Comment');
        $header['TotalRejected_'.$type] = $FileObj->getParameter($tot_rej);
        $header['SlicewiseRejected_'.$type] = $this->_getRejected(
            $FileObj,
            'slicewise'
        );
        $header['InterlaceRejected_'.$type] = $this->_getRejected(
            $FileObj,
            'interlace'
        );
        $header[$inter_rej]      = $this->_getRejected(
            $FileObj,
            'intergradient'
        );
        $header['Caveat_'.$type] = $FileObj->getParameter('Caveat');
        $header['ProcessingPipeline_'.$type] = $FileObj->getParameter($pipeline);
        return $header;
    }

    /**
     * Gets the date according to the type
     *
     * @param MRIFile $file  file object
     * @param string  $type  type of the date
     *
     * @return date if exists, if not an empty string
     */
    function _getDate($file, $type)
    {
        if (preg_match(
            "/(\d{4})-?(\d{2})-?(\d{2})/",
            $file->getParameter($type),
            $array
        )) {
            return (mktime(12, 0, 0, $array[2], $array[3], $array[1]));
        } else {
            return "";
        }
    }

    /**
     * Gets the scannerID
     *
     * @param MRIFile $file  file object
     *
     * @return scannerID
     */
     function _getScannerID($FileID){

         $scannerID = $this->SQLDB->pselectOne("SELECT ScannerID FROM files ".
             "WHERE FileID =:FileID",
             array(
                 'FileID' => $FileID
             )
         );
         return $scannerID;
     }

    /**
     * Gets a rejected parameter according to its type
     *
     * @param MRIFile $file  file object
     * @param string  $type  type of the rejected
     *
     * @return parameter of the rejected
     */
    function _getRejected($file, $type)
    {
        $parameter = 'processing:' . $type . '_rejected';
        if (preg_match(
            "/(Directions)([^\(]+)(\(\d+\))/",
            $file->getParameter($parameter),
            $array
        )) {
            $dirList = preg_split('/\,/', $array[2]);
            if (count($dirList) > 1) {
                sort($dirList);
            }
            return "Directions " . join(", ", $dirList) . " " . $array[3];
        } else {
            return $file->getParameter($parameter);
        }
    }

    /**
     * Add saved mri feedback to each of the selected scan
     *
     * @param array       $current_feedback Saved feedback for a particular
     *                                      scan
     * @param array       $scan_type        All selected scan types in the
     *                                      database
     * @param FeedbackMRI $mri_feedback     feedback object
     *
     * @return array $CandidateData Array of feedback and value for a particular
     *                              scan
     */
    function _addMRIFeedback($current_feedback, $scan_type, $mri_feedback)
    {
        $CandidateData = array();
        //setting default values for mri feedback
        foreach ($this->feedback_Comments as $CommentTypeID=>$field) {
            $CandidateData[$field."_".$scan_type]
                = $mri_feedback->getMRIValue($field);
            // overall comment field for each CommentTypeID
            $CandidateData["Comment_".$field."_".$scan_type] = '';
            // set deafault for all the predefined comments as well
            $predefn = $this->feedback_PreDefinedComments[$CommentTypeID];
            foreach ($predefn as $id=>$key) {
                $CandidateData[$key."_".$scan_type] = 'No'; //no is default
            }
        }
        foreach ($current_feedback as $CommentTypeID=>$comment) {
            if (array_key_exists("predefined", $comment)) {
                $predefined = $comment['predefined'];
                foreach ($predefined as $key=>$val) {
                    $field_set
                        = $this->feedback_PreDefinedComments[$CommentTypeID][$key];

                    $CandidateData[$field_set."_".$scan_type] = 'Yes';
                }
            }
            if (array_key_exists("text", $comment)) {
                $field_set = "Comment_".$this->feedback_Comments[$CommentTypeID];
                $CandidateData[$field_set."_".$scan_type] = $comment['text'];
            }
        }
        return $CandidateData;
    }

    /**
     * Updates DQT with the new data
     *
     * @param array $data      Candidate data to be updated
     * @param array $ScanTypes All selected scan types in the database
     *
     * @return void
     */
    function updateCandidateDocs($data, $ScanTypes)
    {
        foreach ($data as $row) {
            $doc        = $row;
            $identifier = array(
                $row['PSCID'],
                $row['Visit_label'],
            );
            $docid      = 'MRI_Files:' . join($identifier, '_');
            unset($doc['PSCID']);
            unset($doc['Visit_label']);
            unset($doc['SessionID']);

            $success = $this->CouchDB->replaceDoc(
                $docid,
                array(
                    'Meta' => array(
                        'DocType'    => 'mri_data',
                        'identifier' => $identifier,
                    ),
                    'data' => $doc,
                )
            );
            print $docid . ": " . $success . "\n";

        }
        return;
    }

    /**
     * Get Scan types
     *
     * @return array
     */
    public function getScanTypes()
    {

        $ScanTypes = $this->SQLDB->pselect(
            "SELECT DISTINCT msc.Scan_type as ScanType, f.AcquisitionProtocolID from mri_scan_type msc
            JOIN files f ON msc.ID= f.AcquisitionProtocolID
            JOIN files_qcstatus fqc ON f.FileID=fqc.FileID
            ORDER BY f.AcquisitionProtocolID",
            array()
        );

        return $ScanTypes;
    }

    /**
     * Get Candidate Data
     *
     * @param array $ScanTypes list of scan types
     *
     * @return array
     */
    public function getCandidateData($ScanTypes)
    {
        $query = $this->_generateCandidatesQuery($ScanTypes);

        $CandidateData = $this->SQLDB->pselect($query, array());
        foreach ($CandidateData as &$row) {
            foreach ($ScanTypes as $scanType) {
                $scan_type = $scanType['ScanType'];
                if ($row["NbSelected_$scan_type"] == 1) {
                    $fileID             = $this->SQLDB->pselectOne(
                        "SELECT FileID FROM files WHERE BINARY File=:fname",
                        array('fname' => $row['Selected_' . $scan_type])
                    );
                    $FileObj            = new MRIFile($fileID);
                    $mri_header_results = $this->_addMRIHeaderInfo(
                        $FileObj,
                        $scan_type
                    );
                    $row = array_merge(
                        $row, $mri_header_results
                    );
                    // instantiate feedback mri object
                    $mri_feedback     = new FeedbackMRI(
                        $fileID, $row['SessionID']
                    );
                    $current_feedback = $mri_feedback->getComments();
                    $mri_qc_results   = $this->_addMRIFeedback(
                        $current_feedback,
                        $scan_type,
                        $mri_feedback
                    );

                    $row = array_merge($row, $mri_qc_results);
                }
            }
        }
        return $CandidateData;
    }

    /**
     * Builds data dictionary for given scan types
     *
     * @param array $types list of scan types
     *
     * @return void
     */
    private function _buildDataDictionary($types)
    {

        $this->Dictionary = array(
            'QCComment' => array(
                'Type'        => 'varchar(255)',
                'Description' => 'QC Comment for Session',
            )
        );
        /* creating dummy mri feedback object so all the mri feedback
                *  types can be added to the dictionary */
        $mri_feedback = new FeedbackMRI(1, "");

        foreach ($types as $type) {
            $ScanType = $type['ScanType'];

            $SelectedArray = array(
                'Type'        => 'varchar(255)',
                'Description' => "Selected $ScanType file for session",
                'IsFile'      => true,
            );
            $QCStatusArray = array(
                'Type'        => "enum('Pass', 'Fail')",
                'Description' => "QC Status for $ScanType file",
            );

            $this->Dictionary["Selected_$ScanType"]    = $SelectedArray;
            $this->Dictionary[$ScanType . "_QCStatus"] = $QCStatusArray;

            $feedback_types
                                                       = $mri_feedback->getAllCommentTypes(
            );
            foreach ($feedback_types as $CommentTypeID => $comments) {
                if (isset($comments['field']) && !empty($comments['field'])) {
                    $fieldName = $comments['field'];
                    $commentsValues = !is_array($comments['values'])
                        ? [$comments['values']] : $comments['values'];
                    $type      =
                        "enum ('" . implode("','", $commentsValues) . "')";
                    $cmt_field = "Comment_" . $fieldName . "_$ScanType";
                    $scanfield = "$fieldName $ScanType";
                    $cmt_Array = array(
                        'Type'        => 'varchar(255)',
                        'Description' => "Overall Comment for $scanfield",
                    );

                    $this->Dictionary[$cmt_field] = $cmt_Array;
                } else {
                    $fieldName = $comments['name'];
                    $type      = 'varchar(255)';
                }
                $this->feedback_Comments[$CommentTypeID] = $fieldName;

                $cmt_scanArray = array(
                    'Type'        => $type,
                    'Description' => $comments['name'] . " $ScanType",
                );

                $this->Dictionary[$fieldName . "_$ScanType"] = $cmt_scanArray;
                $preDefinedComments
                                                                   = $mri_feedback->getAllPredefinedComments(
                    $CommentTypeID
                );

                $this->feedback_PreDefinedComments[$CommentTypeID] = array();

                $pre                                               = array();
                foreach (
                    $preDefinedComments as
                    $preDefinedCommentTypeID => $preDefinedComment
                ) {
                    $preDefinedCommentField          = $preDefinedComment['field'] ?? '';
                    $preDef_field                    =
                        $preDefinedCommentField . "_$ScanType";
                    $preDef_cmt                      = $preDefinedComment['Comment'];
                    $preDef_Array                    = array(
                        'Type'        => "enum('Yes', 'No')",
                        'Description' => "$preDef_cmt $ScanType",
                    );
                    $this->Dictionary[$preDef_field] = $preDef_Array;
                    $pre[$preDefinedCommentTypeID]   = $preDefinedCommentField;
                }
                $this->feedback_PreDefinedComments[$CommentTypeID] = $pre;

            }
            $mri_array               = array(
                'ScannerID'           => 'Scanner ID',
                'Pipeline'            => 'Pipeline',
                'OutputType'          => 'Output Type',
                'AcquisitionProtocol' => 'Protocol',
                'CoordinateSpace'     => 'Space',
                'Algorithm'           => 'Algorithm',
                'AcquisitionDate'     => 'Acquisition Date',
                'FileInsertDate'      => 'Insert date',
                'SeriesDescription'   => 'Series Description',
                'SeriesNumber'        => 'Series Number',
                'EchoTime'            => 'Echo Time',
                'RepetitionTime'      => 'Repetition Time',
                'SliceThickness'      => 'Slice Thickness',
                'Time'                => 'No of volumes',
                'Comment'             => 'Comment',
                'SlicewiseRejected'   => 'Slicewise correlations (Nb)',
                'InterlaceRejected'   => 'Interlace correlations (Nb)',
                'IntergradientReject' => 'Gradient-wise correlations (Nb)',
                'TotalRejected'       => 'No. of rejected directions',
                'Caveat'              => 'Caveat',
                'ProcessingPipeline'  => 'Processing Pipleline',
            );
            $this->mri_header_fields = $mri_array;
            foreach ($this->mri_header_fields as $field => $desc) {
                $mri_field                    = $field . "_$ScanType";
                $this->Dictionary[$mri_field] = array(
                    'Type'        => "varchar(255)",
                    'Description' => $desc . " $ScanType",
                );
            }
        }
    }
}

// Don't run if we're doing the unit tests; the unit test will call run.
if(!class_exists('UnitTestCase')) {
    $Runner = new CouchDBMRIImporter();
    $Runner->run();
}