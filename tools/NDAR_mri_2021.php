<?php

/**
 * Prepares a specific MRI data set for submission to NDAR. Three types of
 * MRI data can be submitted: STRUCTURAL (T1s and T2s), DTI and FMRI (bold)
 * Only scans from candidates whose participant status is either 'Active',
 * 'Complete' or 'Active - Flagged' are considered. All submitted files are
 * fully anonymized (i.e all headers that contain either PII or dates are
 * scrambled.
 * The submitted data consists of:
 * 1. The Minc files associated to the program argument (for T1s and T2s, the defaced
 *    versions of the scans are used).
 * 2. All the files found in step 1 in NIFTI format, except when the program argument
 *    is dti. For DTI files, use program dwi_nifti_creation_for_IBIS_NDAR.pl on pinch to
 *    genrate the NIFTI, BVEC and BVAL files.
 *
 *
 * Usage: php NDAR_mri_2021.php structural | dti | fmri
 */

set_include_path(get_include_path().":../libraries:../../php/libraries:");

require_once __DIR__ . "/../../vendor/autoload.php";
require_once 'NDB_Factory.class.inc';

class NDAR_mri_2021 {
    // Submit onyl scans that belong to candidates from this project.
    const NDAR_PROJECT              = "IBIS2";
    // Submit only scans that are associated to these visits.
    const NDAR_VISIT_LABELS         = "V06,V12,V24";
    // To be submitted, a scan's selected flag value has to be equal to the value listed
    // below. The expected selected flag value is specific to each scan type and is null
    // if the selected flag can have any value.
    const NDAR_FILE_SELECTED        = [
        'structural' => "true",
        'dti'        => null,
        'fmri'       => null
    ];
    // To be submitted, a scan's QC status has to be equal to the value listed
    // below. The expected QC status value is specific to each scan type and is null
    // if the QC status can have any value.
    const NDAR_FILE_QC_STATUSES     = [
        'structural' => "pass",
        'dti'        => null,
        'fmri'       => null
    ];
    // Submit only the scans for candidates whose participant status is listed below.
    const NDAR_PARTICIPANT_STATUSES = "Active,Complete,Active - Flagged";
    // Whether NIFTI files should be generated for each Minc file that is to be submitted
    const NDAR_CREATE_NII = true;


    // Root dir for all defaced T1s and T2s are located.
    const DEFACED_T1_T2_ROOT_DIR = "/pinch-scratch/VLAD_DEFACED_DATA";
    // When anonymizing a DICOM header, it is replaced with this value.
    const TAG_USED_TO_ANONYMIZE  = "ibis";
    // All submitted files go there.
    const OUTPUT_ROOT_DIR        = "/data/not_backed_up/NDAR_2021";
    // Basename of the CSV file that lists all the submitted scans and derived data
    const CSV_FILE_BASENAME      = "NDARMRI.csv";

    // Value of column 'Scan_type' in table mri_scan_type for a T1
    const MRI_SCAN_TYPE_T1       = 't1w';
    // Value of column 'Scan_type' in table mri_scan_type for a T2
    const MRI_SCAN_TYPE_T2       = 't2w';
    // Value of column 'Scan_type' in table mri_scan_type for an fMRI scan
    const MRI_SCAN_TYPE_EP2D     = 'ep2d_bold';
    // Value of column 'Scan_type' in table mri_scan_type for a DTI scan
    const MRI_SCAN_TYPE_DTI      = 'dti';

    // Specific scan types from table mri_scan_type associated to all the possible
    // script arguments (i.e modalities to submit)
    const SCAN_TYPES = [
        'structural' => "t1w,t2w",
        'dti'        => "dti",
        'fmri'       => "ep2d_bold"
    ];

    // Various NDAR-specific properties for each scan type.
    const NDAR_SCAN_PROPERTIES   = [
        self::MRI_SCAN_TYPE_EP2D => [
            'DESCRIPTION'          => 'fMRI',
            'SCAN_TYPE'            => 'single-shell DTI',
            'ORIENTATION'          => 'axial',
            'ACQUISITION_MATRIX'   => '256',
            'PHOTOMETER'           => 'monochrome2',
            'IMAGE_NUM_DIMENSIONS' => 4
        ],
        self::MRI_SCAN_TYPE_DTI => [
            'DESCRIPTION'          => 'DTI',
            'SCAN_TYPE'            => 'single-shell DTI',
            'ORIENTATION'          => 'Sagittal',
            'ACQUISITION_MATRIX'   => '256',
            'PHOTOMETER'           => 'monochrome2',
            'IMAGE_NUM_DIMENSIONS' => 4
        ],
        self::MRI_SCAN_TYPE_T1 => [
            'DESCRIPTION'          => 'MR structural (T1)',
            'SCAN_TYPE'            => 'MR structural (MPRAGE)',
            'ORIENTATION'          => 'Sagittal',
            'ACQUISITION_MATRIX'   => '256',
            'PHOTOMETER'           => 'monochrome2',
            'IMAGE_NUM_DIMENSIONS' => 3
        ],
        self::MRI_SCAN_TYPE_T2 => [
            'DESCRIPTION'          => 'MR structural (T2)',
            'SCAN_TYPE'            => 'MR structural (T2)',
            'ORIENTATION'          => 'Sagittal',
            'ACQUISITION_MATRIX'   => '256',
            'PHOTOMETER'           => 'monochrome2',
            'IMAGE_NUM_DIMENSIONS' => 3
        ]
    ];

    // All the known DICOM headers containing PII
    const PII_HEADERS = [
        'dicom_0x0018:el_0x1000',
        'dicom_0x0008:el_0x0080',
        'dicom_0x0008:el_0x0081',
        'dicom_0x0008:el_0x1010',
        'dicom_0x0008:el_0x1030',
        'dicom_0x0008:el_0x1070',
        'dicom_0x0018:el_0x1000',
        'dicom_0x0010:el_0x0010',
        'dicom_0x0010:el_0x0020',
        'dicom_0x0010:el_0x0030',
        'dicom_0x0010:el_0x0040',
        'dicom_0x0010:el_0x1001',
        'dicom_0x0010:el_0x2154',
        'dicom_0x0008:el_0x0090',
        'dicom_0x0008:el_0x1048',
        'dicom_0x0010:el_0x1010',
        'dicom_0x0010:el_0x1030',
        'dicom_0x0020:el_0x000d',
        'dicom_0x0032:el_0x1032',
        'dicom_0x0032:el_0x1060',
        'dicom_0x0040:el_0x0254',
        'dicom_0x0040:el_0x0253',
        'dicom_0x0023:el_0x0006',
        'dicom_0x0010:el_0x1040',
        'patient:birthdate',
        'patient:sex',
        'patient:full_name',
        'patient:weight',
        'patient:age',
        'study:operator',
        'study:institution',
        'study:referring_physician',
        'study:serial_no',
        'study:station_id',
        'study:procedure'
    ];

    // All known DICOM headers that contain sensitive dates (ie. DoB, etc...)
    const DATE_HEADERS = [
        'acquisition:start_time',
        'dicom_0x0008:el_0x0012',
        'dicom_0x0008:el_0x0018',
        'dicom_0x0008:el_0x0020',
        'dicom_0x0008:el_0x0021',
        'dicom_0x0008:el_0x0022',
        'dicom_0x0008:el_0x0023',
        'dicom_0x0020:el_0x000e',
        'dicom_0x0020:el_0x0052',
        'dicom_0x0029:el_0x1009',
        'dicom_0x0029:el_0x1019',
        'dicom_0x0040:el_0x0244',
        'study:start_date',
        'study:study_id'
    ];

    // Will contain the file meta data of the scan files and their associated derived data (if any).
    var $CSVData = array();

    // Will contain the ID of the modalities to submit (script argument passed on the command line)
    // Can be one of : structural.
    var $modalitiesToSubmit;

    //======================================================================================================//
    //                                                                                                      //
    //                                               FUNCTIONS                                              //
    //                                                                                                      //
    //======================================================================================================//

    /**
     * Copies one file in a given directory, creating the directory if it does not
     * already exist.
     *
     * @param $fileFullPath   string File's full path.
     * @param $destinationDir string Absolute path of the directory in which the file should be copied.
     *
     * @return void
     *
     */
    function copyFile($fileFullPath, $destinationDir) {
        if(!is_dir(dirname($destinationDir))) {
            mkdir(dirname($destinationDir), 0777, true);
        }
        copy($fileFullPath, $destinationDir);
    }

    /**
     * Replaces a candidate's ID with its IBIS ID in a string.
     *
     * @param $string string a string.
     * @param $CandID string the candidate ID.
     * @param $IBISID string the candidate's IBIS ID.
     *
     * @return the modified string.
     */
    function replaceID($string, $CandID, $IBISID) {
        return preg_replace("/$CandID/", $IBISID, $string);
    }

    /**
     * Takes a non-anonymized file, copies it to the output directory and
     * anonymizes it.
     *
     * @param $fileFullPath           string absolute path of the file to move and anonymize.
     * @param $anonymizedFileFullPath string absolute path that the file should have once it
     *                                       has been moved and anonymized.
     * @return void
     */
    function anonymizeFile($fileFullPath, $anonymizedFileFullPath) {
        // Copy file to output dir
        $this->copyFile($fileFullPath, $anonymizedFileFullPath);
        print "Copied $fileFullPath to $anonymizedFileFullPath\n";
        print "Anonymizing $anonymizedFileFullPath:\n";

        // Anonymize all PII headers
        foreach (self::PII_HEADERS as $header) {
            $headerValue = $this->getHeader($anonymizedFileFullPath, $header);
            if ($headerValue != '' && $headerValue != 'ibis') {
                print "\tReplacing value of $header: was '$headerValue' is now 'ibis'\n";
                $this->anonymizeHeader($anonymizedFileFullPath, $header, 'ibis');
            }
        }

        // Anonymize all date headers
        foreach (self::DATE_HEADERS as $header) {
            $date = $this->getHeader($anonymizedFileFullPath, $header);
            if($date != array()) {
                $anon_date = substr($date, 0, 6);
                if ($date != $anon_date) {
                    print "\tReplacing value of $header: was '$date' is now '$anon_date'\n";
                    $this->anonymizeHeader($anonymizedFileFullPath, $header, $anon_date);
                }
            }
        }
        print "Finished anonymizing $anonymizedFileFullPath\n";
    }

    /**
     * Gets a specific Minc header in a file using program mincheader.
     *
     * @param $fileFullPath string absolute path of the file to get the header from.
     * @param $header       string header to get.
     *
     * @return string the header value.
     */
    function getHeader($fileFullPath, $header) {
        // Run mincheader on the file and get the line with the header information
        // Do not use mincinfo as it's not reliable
        $line = `mincheader $fileFullPath | grep $header`;

        // If the header is not in the file
        if (strpos($line, "=") === false) {
            return '';
        }

        $headerValueTokens = explode("=", $line);

        $headerValue = $headerValueTokens[1];
        $headerValue = str_replace(";" , "", $headerValue);
        $headerValue = str_replace("\"", "", $headerValue);

        return trim($headerValue);
    }

    /**
     * Changes the value of a Minc header in a file to a specific (anonymized) value.
     *
     * @param $fileFullPath string absolute path of the file.
     * @param $header       string header for which the value should be changed.
     * @param $value        string new header value.
     *
     * @return void
     */
    function anonymizeHeader($fileFullPath, $header, $value=self::TAG_USED_TO_ANONYMIZE) {
        system("minc_modify_header -sinsert " . escapeshellarg($header . "=" . $value) . " \\$fileFullPath" . " 2>&1");
    }

    /**
     * Converts a string to a float number with 6 decimal digits.
     *
     * @param $s string number string.
     *
     * @return string formatted float number.
     */
    function stringToFloat($s) {
        return floatval(sprintf("%.6f", $s));
    }

    /**
     * Add an anoymized (and possibly defaced) scan to the CSV file (the table of contents file).
     *
     * @param $file     string absolute path of the anonymized (and possibly defaced) scan.
     * @param $fileInfo array  file properties fetched from the DB.
     *
     * @return void
     */
    function addToCsvFile($file, $fileInfo) {
        $StudyDate = $this->getHeader($file, 'study:start_date');
        $ScannerID = $this->getHeader($file, 'study:serial_no');

        $XSpace     = $this->getHeader($file, 'xspace:length');
        $YSpace     = $this->getHeader($file, 'yspace:length');
        $ZSpace     = $this->getHeader($file, 'zspace:length');
        $TimeLength = $this->getHeader($file, 'time:length');

        $XStep     = $this->getHeader($file, 'xspace:step');
        $YStep     = $this->getHeader($file, 'yspace:step');
        $ZStep     = $this->getHeader($file, 'zspace:step');
        $TimeStep  = $this->getHeader($file, 'time:step');

        $sliceThickness         = $this->getHeader($file, 'acquisition:slice_thickness');
        $scannerSoftwareVersion = $this->getHeader($file, 'study:software_version');
        $patientPosition        = $this->getHeader($file, 'patient:position');
        $echoTime               = floatval($this->getHeader($file, 'acquisition:echo_time'));
        $flipAngle              = $this->getHeader($file, 'acquisition:flip_angle');
        $repetitionTime         = $this->getHeader($file, 'dicom_0x0018:el_0x0080');
        $magneticFieldStrength  = $this->getHeader($file, 'dicom_0x0018:el_0x0087');

        if ($StudyDate == "") {
            $ageAtInterview = "N/A";
        } else {
            $StudyYear = substr($StudyDate, 0, 4);
            $StudyMo   = substr($StudyDate, 4, 2);
            $StudyDay  = substr($StudyDate, 6, 2);
            if (!ctype_digit($StudyDay)) {
              $StudyDay = "01";
            }
            $ageAtInterview = round(
                date_diff(
                    new DateTime("$StudyYear-$StudyMo-$StudyDay"),
                    new DateTime($fileInfo['DoB']))->format('%a') / (365/12)
            );
        }

        if (!isset(self::NDAR_SCAN_PROPERTIES[ $fileInfo['Scan_type'] ])) {
            fwrite(STDERR, "Unknow scan type {$fileInfo['Scan_type']} for file $file. Cannot add to CSV file.\n");
            exit(1);
        }
        $ndarScanProperties = self::NDAR_SCAN_PROPERTIES[ $fileInfo['Scan_type'] ];

        // The file properties to write to the CSV file, in the order in which they will be written
        $csvdata = array(
            'image_file'                   => $file,
            'subjectkey'                   => $fileInfo['CandidateGUID'],
            'src_subject_ID'               => $fileInfo['IBISID'],
            'gender'                       => strlen($fileInfo['Sex']) == 0 ? '' : substr(ucfirst($fileInfo['Sex']), 0, 1),
            'Site'                         => $fileInfo['CenterID'],
            'ScannerID'                    => md5($ScannerID),
            'interview_date'               => "$StudyMo/01/$StudyYear",
            'interview_age'                => $ageAtInterview,
            'image_description'            => $ndarScanProperties['DESCRIPTION'],
            'scan_type'                    => $ndarScanProperties['SCAN_TYPE'],
            'scan_object'                  => 'Live',
            'image_num_dimensions'         => $ndarScanProperties['IMAGE_NUM_DIMENSIONS'],
            'image_extent1'                => $this->stringToFloat($XSpace),
            'image_extent2'                => $this->stringToFloat($YSpace),
            'image_extent3'                => $this->stringToFloat($ZSpace),
            'image_extent4'                => $TimeLength,
            'image_thumbnail_file'         => '',
            'image_file_format'            => 'MINC',
            'image_modality'               => 'MRI',
            'scanner_manufacturer_pd'      => 'Siemens',
            'transformation_performed'     => 'Yes',
            'transformation_type'          => 'DICOM to MINC',
            'image_unit1'                  => 'Millimeters',
            'image_unit2'                  => 'Millimeters',
            'image_unit3'                  => 'Millimeters',
            'image_unit4'                  => 'Seconds',
            'extent4_type'                 => 'time',
            'image_resolution1'            => $this->stringToFloat(abs($XStep)),
            'image_resolution2'            => $this->stringToFloat(abs($YStep)),
            'image_resolution3'            => $this->stringToFloat(abs($ZStep)),
            'image_resolution4'            => $this->stringToFloat(abs($TimeStep)),
            'image_orientation'            => $ndarScanProperties['ORIENTATION'],
            'image_slice_thickness'        => $this->stringToFloat($sliceThickness),
            'scanner_software_versions_pd' => $scannerSoftwareVersion,
            'magnetic_field_strength'      => $this->stringToFloat($magneticFieldStrength) . "T",
            'mri_repetition_time_pd'       => $repetitionTime,
            'mri_echo_time_pd'             => 1000*$echoTime,
            'flip_angle'                   => $this->stringToFloat($flipAngle),
            'acquisition_matrix'           => $ndarScanProperties['ACQUISITION_MATRIX'],
            'mri_field_of_view_pd'         => "$ZSpace$YSpace$XSpace",
            'patient_position'             => $patientPosition,
            'photomet_interpret'           => $ndarScanProperties['PHOTOMETER']
        );

        // For DTI scans, write the path of the BVEC and BVAL files
        if($fileInfo['Scan_type'] == "dti") {
            $csvdata['bvek_bval_files'] = 'Yes';
            $csvdata['bvecfile']        = basename($file, '.mnc') . '.bvec';
            $csvdata['bvalfile']        = basename($file, '.mnc') . '.bval';
        }

        // For fMRI scans, write the experiment ID (scan index)
        if($fileInfo['Scan_type'] == "ep2d_bold") {
            preg_match('/(\d+).mnc/', $file, $matches);
            $fileIndex = $matches[1];
            $csvdata['experiment_id'] = $fileIndex;
        }

        $this->CSVData[] = $csvdata;
        print "Added $file to the set of files to submit.\n";

        $niiFile               = preg_replace("/\.mnc$/", ".nii", $file);
        $csvdata['image_file'] = $niiFile;
        $this->CSVData[]       = $csvdata;
        print "Added $niiFile to the set of files to submit.\n";
    }

    /**
     * Looks into the directory where all defaced scans are stored and attempts to find
     * a defaced scan matching the non-defaced scan passed as argument. Matching is done
     * based on the series UID. This is only done for T1s and T2s.
     *
     * @param $candID     string ID of the candidate the scan belongs to.
     * @param $visitLabel string label of the visit at which the scan was done.
     * @param $seriesUID  string series UID of the non-defaced scan
     * @param $scanType   string type (i.e 't1w', 'ep2d_bold', etc..) of the non-defaced scan.
     *
     * @return string absolute path of the matching defaced file.
     */
    function getDefacedFile($candID, $visitLabel, $seriesUID, $scanType) {
        if ($scanType != self::MRI_SCAN_TYPE_T1 && $scanType != self:: MRI_SCAN_TYPE_T2) {
            return null;
        }

        $candidateDefacedFilesDir
            = self::DEFACED_T1_T2_ROOT_DIR . "/$candID/$visitLabel/deface";

        // If no defaced scans exist for that candidate/visit, return null
        if (!file_exists($candidateDefacedFilesDir)) {
            return null;
        }

        // Look in $candidateDefacedFilesDir to see if there's a Minc file with a series UID
        // matching the series UID passed as argument
        foreach (scandir($candidateDefacedFilesDir) as $defacedFileRelativePath) {
            // Only consider defaced files of the correct scan type
            if (preg_match("/$scanType\\.mnc$/", $defacedFileRelativePath)) {
                $defacedFileFullPath = "$candidateDefacedFilesDir/$defacedFileRelativePath";
                print "Getting seriuesUID of $defacedFileFullPath\n";
                $cmd = "mincheader $defacedFileFullPath"
                     . " | fgrep dicom_0x0020:el_0x000e"
                     . " | cut -d= -f2"
                     . " | cut -d\\\" -f2";
                $currentSeriesUID = trim(system($cmd));

                // If the series UID matches
                if ($currentSeriesUID == $seriesUID) {
                    return $defacedFileFullPath;
                }
            }
        }

        // If we end up here, no match was found
        return null;
    }

    /**
     * Method executed when this class is run.
     *
     * @return void.
     */
    function run() {
        global $argc, $argv;

        if ($argc != 2
            || (strtolower($argv[1]) != 'structural' && strtolower($argv[1]) != 'fmri' && strtolower($argv[1]) != 'dti')
        ) {
            fwrite(STDERR, "Usage: php NDAR_mri_2021.php structural | dti | fmri.\n");
            exit(1);
        }
        $this->modalitiesToSubmit = strtolower($argv[1]);

        $factory = NDB_Factory::singleton();
        $outputDir = sprintf("%s/ibis_anon_%s_%s_%s", self::OUTPUT_ROOT_DIR, self::NDAR_PROJECT, date("Ymd"), $this->modalitiesToSubmit);

        // Query used to fetch all files in the DB that will go into the NDAR submission
        $query  = "SELECT c.CandID, c.PSCID, c.IBISID, pcc.Value AS CandidateGUID, pcp.Value AS ProbandGUID, c.DoB, s.CenterID, s.Visit_label, s.Current_stage, f.File, f.SeriesUID, fqc.QCStatus, c.Sex, mst.Scan_type "
                . "FROM files f "
                . "JOIN mri_scan_type mst ON (f.AcquisitionProtocolID=mst.ID) "
                . "LEFT JOIN files_qcstatus fqc USING (FileID) "
                . "LEFT JOIN session s ON (s.ID=f.SessionID) "
                . "LEFT JOIN project_rel pr ON (pr.SubprojectID=s.SubprojectID) "
                . "LEFT JOIN Project p ON (p.ProjectID=pr.ProjectID) "
                . "LEFT JOIN candidate c ON (c.CandID=s.CandID) "
                . "LEFT JOIN parameter_file AS pf ON (f.FileID=pf.FileID) "
                . "LEFT JOIN parameter_type AS pt ON (pt.ParameterTypeID=pf.ParameterTypeID) "
                . "LEFT JOIN participant_status ps ON (c.CandID=ps.CandID) "
                . "LEFT JOIN participant_status_options pso ON (pso.ID = ps.participant_status) "
                . "LEFT JOIN parameter_candidate AS pcc ON (pcc.ParameterTypeID=(SELECT ParameterTypeID FROM parameter_type WHERE name='CandidateGUID') AND pcc.CandID=c.CandID) "
                . "LEFT JOIN parameter_candidate AS pcp ON (pcp.ParameterTypeID=(SELECT ParameterTypeID FROM parameter_type WHERE name='ProbandGUID') AND pcp.CandID=c.CandID) "
                . "WHERE pt.Name='" . ($this->modalitiesToSubmit == 'dti' ? 'time' : 'patient_id') . "' "
                . ($this->modalitiesToSubmit == 'dti' ? " AND pf.Value IN (26,65) " : "")
                . "AND FIND_IN_SET(UPPER(s.Visit_label), :vlabels) "
                . "AND s.Active='Y' "
                . "AND c.Active='Y' "
                . "AND FIND_IN_SET(pso.Description, :participantStatuses) "
                . "AND FIND_IN_SET(mst.Scan_type, :acquisitionProtocols) "
                . "AND COALESCE(pcc.Value, '') <> '' "
                . "AND s.Current_stage <> 'Recycling Bin' "
                . "AND p.Name = :projectName "
                . "AND (ps.study_consent = 'yes' OR ps.study_consent IS NULL) "
                . "AND COALESCE(ps.study_consent_withdrawal,'0000-00-00') = '0000-00-00' "
                . "AND (ps.ndar_consent  = 'yes' OR ps.ndar_consent IS NULL) "
                . "AND COALESCE(ps.ndar_consent_withdrawal, '0000-00-00') = '0000-00-00' "
                . (!is_null(self::NDAR_FILE_SELECTED[$this->modalitiesToSubmit]) ? "AND FIND_IN_SET(fqc.Selected, :fileSelected) " : "")
                . (!is_null(self::NDAR_FILE_QC_STATUSES[$this->modalitiesToSubmit]) ? "AND FIND_IN_SET(fqc.QCStatus, :fileQcStatuses) " : "")
                . "ORDER BY PSCID";

        // Fill the array of query parameters
        $queryParams = [
            'vlabels'              => self::NDAR_VISIT_LABELS,
            'participantStatuses'  => self::NDAR_PARTICIPANT_STATUSES,
            'acquisitionProtocols' => self::SCAN_TYPES[$this->modalitiesToSubmit],
            'projectName'          => self::NDAR_PROJECT,
        ];

        // Add the parameter for the selected constraint (if any)
        if (!is_null(self::NDAR_FILE_SELECTED[$this->modalitiesToSubmit])) {
            $queryParams['fileSelected'] = self::NDAR_FILE_SELECTED[$this->modalitiesToSubmit];
        }
        // Add the parameter for the QC status constraint (if any)
        if (!is_null(self::NDAR_FILE_QC_STATUSES[$this->modalitiesToSubmit])) {
            $queryParams['fileQcStatuses'] = self::NDAR_FILE_QC_STATUSES[$this->modalitiesToSubmit];
        }

        // Run the query
        $db = $factory->Database();
        $files = $db->pselect($query, $queryParams);
        print "Found " . count($files) . " elligible files in the database.\n";

        // Process each file returned by the query
        $config = \NDB_Config::singleton();
        foreach($files as $file) {
            print "Processing file: ". $file['File'] ."\n";
            $anonymizedFilePath = $this->replaceID($file['File'], $file['CandID'], $file['IBISID']);
            $anonymizedFileBasename = basename($anonymizedFilePath);

            $fileToAnonymize = null;
            $anonymizedFile  = null;

            // Check the output directory to see if the output file already exists
            if (!file_exists("$outputDir/$anonymizedFileBasename")) {
                // If the file is a T1 or a T2, we need to find its defaced version first
                if ($file['Scan_type'] == "t1w" || $file['Scan_type'] == "t2w") {
                    $fileToAnonymize = $this->getDefacedFile($file['CandID'], $file['Visit_label'], $file['SeriesUID'], $file['Scan_type']);
                    if (!$fileToAnonymize) {
                        print "No defaced file found for {$file['File']}: skipping\n";
                    }
                // Scan is not a T1 and not a T2: find its absolute path
                } else {
                    $mriDataDirRoot = $config->getSetting('dataDirBasepath');

                    // There can be a mismatch in the casing of the visit label
                    // between the path of the file in the database (visit label always
                    // in uppercase) and the actual path of the file on the file system
                    // (upper or lower case visit label). This covers both cases.
                    if (file_exists("$mriDataDirRoot/{$file['File']}")) {
                        $fileToAnonymize = "$mriDataDirRoot/{$file['File']}";
                    } else {
                        $rowFile = preg_replace("/_V([0-9][0-9]?)_/", '_v$1_', $file['File']);
                        if (file_exists("$mriDataRootDir/$rowFile")) {
                            $fileToAnonymize = "$mriDataDirRoot/$rowFile";
                        } else {
                            print "File {$file['File']} was not found under $mriDataDirRoot: skipping.\n";
                        }
                    }
               }
            } else {
                print "Anonymized file $outputDir/$anonymizedFileBasename already exists.\n";
                $anonymizedFile = "$outputDir/$anonymizedFileBasename";
            }

            // If there is a file to anonymize, anonymize it
            if ($fileToAnonymize) {
                $this->anonymizeFile($fileToAnonymize, "$outputDir/$anonymizedFileBasename");
                $anonymizedFile = "$outputDir/$anonymizedFileBasename";
            }

            // If the file was successfully anonymized, add its properties to the CSV file
            if ($anonymizedFile) {
                // It is assumed that the NIFTI files associated to the Minc files of DTI scans
                // will be generated on pinch afterwards so we add entries for them in the
                // CSV file
                if (self::NDAR_CREATE_NII && $this->modalitiesToSubmit != 'dti') {
                    print "Generating NII file for $anonymizedFile...";
                    // NII file will be written in the same directory as $anonymizedFile
                    system("mnc2nii -nii $anonymizedFile");
                    print "done.\n";
                }
                $this->addToCsvFile($anonymizedFile, $file);
            }
            print "--------------------------------\n";
        }

        // Write the CSV file to disk
        $outputFile = "$outputDir/" . self::CSV_FILE_BASENAME;
        $fp = fopen($outputFile, 'w');
        fwrite($fp, implode(",", array('image03')) . "\n");
        fwrite($fp, implode(",", array_keys($this->CSVData[0])) . "\n");
        foreach ($this->CSVData as $row) {
            fwrite($fp, implode(",", $row) . "\n");
        }
        fclose($fp);

        print "Wrote $outputFile.\n";
    }
}

//=========================================================================================//
//                                                                                         //
//                                     MAIN PROGRAM                                        //
//                                                                                         //
//=========================================================================================//


// Don't run if we're doing the unit tests, the unit test will call run..
if(!class_exists('UnitTestCase')) {
    require_once "NDB_Client.class.inc";
    $factory = NDB_Factory::singleton();
    // Initialize so that the factory looks in the right place.
    $throwaway = $factory->config('../config.xml');

    $client = new NDB_Client();
    $client->makeCommandLine();
    $client->initialize('../config.xml');

    $Runner = new NDAR_mri_2021();
    $Runner->run();
}
?>
