<?php
set_include_path(get_include_path().":../libraries:../../php/libraries:");
require_once __DIR__ . "/../../vendor/autoload.php";
require_once 'NDB_Factory.class.inc';


class NDAR_Release_MRI {
    var $ReplaceHeaders = array(
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
    );

    var $DateHeaders = array(
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
    );

    var $CSVData = array();
    function copyFile($origin, $dest) {
        if(!is_dir(dirname($dest))) {
            mkdir(dirname($dest), 0777, true);
        }
        return copy($origin, $dest);
    }

    function replaceID($string, $CandID, $IBISID) {
        return preg_replace("/$CandID/", $IBISID, $string);
    }

    function anonFile($original, $output) {
        print "Copying $original\n";
        $this->copyFile($original, $output);
        print "Copied to $output\n";
        foreach ($this->ReplaceHeaders as $header) {
            $this->anonHeader($output, $header, 'ibis');
        }
        print "Anonymized replacement headers\n";
        foreach ($this->DateHeaders as $header) {
            $date = $this->getHeader($output, $header);
            if($date != array()) {
                $anon_date = substr($date, 0, 6);
                $this->anonHeader($output, $header, $anon_date);
            }
        }
        print "Done anonymizing all $output\n\n";
    }

    function getHeader_old($file, $header) {
        $factory = NDB_Factory::singleton();
        $db = $factory->Database();
        return trim(
            $db->pselectOne("SELECT parameter_file.Value FROM files JOIN parameter_file USING (FileID) JOIN parameter_type USING (ParameterTypeID) WHERE parameter_type.Name=:header AND files.file=:filename",
            array(
                'header' => $header,
                'filename' => $file
            ))
        );
    }

    function getHeader($file, $header) {
        $line = system("mincheader \\$file | grep $header");
        $output_array = explode("=", $line);

        if (is_array($output_array)) {
            $value = trim(str_replace("\"", "", $output_array[1]));
        }

        return $value;
    }

    function anonHeader($file, $header, $value='ibis') {
        system("minc_modify_header -sinsert " . escapeshellarg($header . "=" . $value) . " \\$file" . " 2>&1");
    }

    function addToCSV($file, $info) {
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

        if ($StudyDate == "") {
            $intervage = "N/A";
        } else {
            $StudyYear = substr($StudyDate, 0, 4);
            $StudyMo   = substr($StudyDate, 4, 2);
            $StudyDay  = substr($StudyDate, 6, 2);
            if (!ctype_digit($StudyDay)) {
              $StudyDay = "01";
            }
            $intervage = round(date_diff(new DateTime("$StudyYear-$StudyMo-$StudyDay"), new DateTime($info['DoB']))->format('%a') / (365/12));
        }

        $desc = '';
        $orient = '';
        if(strpos($file, "ep2d") !== FALSE) {
            $desc = 'fMRI';
            $orient = 'axial';
        } elseif(strpos($file, "dti") !== FALSE) {
            $desc = 'DTI';
            $orient = 'sagittal';
        }

        print "$StudyYear $StudyMo $StudyDay\n";
        $this->CSVData[] = array(
            'image_file' => $file,
            /* 'ProbandGUID' => $info['ProbandGUID'], */
            'subjectkey' => $info['CandidateGUID'],
            'src_subject_ID' => $info['IBISID'],
            'gender'     => $info['Gender'],
            'Site'       => $info['CenterID'],
            'ScannerID' => md5($ScannerID),
            'interview_date'   => "$StudyMo/01/$StudyYear",
            'interview_age' => $intervage,
            'image_description' => $desc,
            'image_num_dimensions' => 4,
            'image_extent1' => $XSpace,
            'image_extent2' => $YSpace,
            'image_extent3' => $ZSpace,
            'image_extent4' => $TimeLength,
            'image_thumbnail_file' => '',
            'image_file_format' => 'MINC',
            'image_modality'   => 'MRI',
            'scanner_manufacturer_pd'=> 'Siemens',
            'transformation_performed'=> 'Yes',
            'transformation_type' => 'DICOM to MINC',
            'image_unit1' => 'millimeters',
            'image_unit2' => 'millimeters',
            'image_unit3' => 'millimeters',
            'image_unit4' => 'seconds',
            'extent4_type' => 'time',
            'image_resolution1' => abs($XStep),
            'image_resolution2' => abs($YStep),
            'image_resolution3' => abs($ZStep),
            'image_resolution4' => abs($TimeStep),
            'image_orientation' => $orient,
            'image_slice_thickness'=> abs($ZStep)
        );
    }

    function run() {
        $factory = NDB_Factory::singleton();
        $db = $factory->Database();
        // IBIS1 subproject IDs: 1, 2, 3
        // IBIS2 subproject IDs: 9, 10
        
        /* NDAR DEFACED T1 & T2's */
        $ibis     = 2;
        $t1t2     = true;
        $dti      = false;
        $location = "prod";  // prod or defaced
        $v[$ibis] = "'V24'"; // "'V06', 'V12'";
        $anonFilePath = "/data/ibis/data/assembly/";  // Non defaced
        // $anonFilePath = "/data/not_backed_up/";     // Defaced
        // $anonFilePath = "/home/lorisadmin/";  // Devv Box
        $outputDir = "/data/not_backed_up/ibis_anon_". $ibis ."_". date("Ymd") ."/";
        // $outputDir = "/data/not_backed_up/ibis_anon_jrichards/";

        /* DTI25 Prod location */
        // $ibis = 2;
        // $dti  = false;
        // $t1t2 = true;
        // $location = "prod";
        // $v[$ibis] = "'V24'";
        // $anonFilePath = "/data/ibis/data/assembly/";
        // $outputDir = "/data/not_backed_up/v24lr/";
        // $outputDir = "/data/not_backed_up/ibis_dti_" . $ibis . "_20170611/";


        /*
        // IBIS1 - v06 - 25 direction DTIs
        $files = $db->pselect("SELECT c.CandID, c.PSCID, c.IBISID, pcc.Value, c.ProbandGUID, c.DoB, s.CenterID, s.Visit_label, s.Current_stage, f.File, fqc.QCStatus, c.Sex
        from files f left join files_qcstatus fqc USING (FileID) LEFT JOIN session s ON (s.ID=f.SessionID)
        LEFT JOIN candidate c on (c.CandID=s.CandID) LEFT JOIN parameter_file AS pf ON (f.FileID=pf.FileID)
        LEFT JOIN parameter_type AS pt ON (pt.ParameterTypeID=pf.ParameterTypeID) LEFT JOIN participant_status ps ON (c.CandID=ps.CandID)
        WHERE pt.Name='time' AND pf.Value=26 AND lower(s.Visit_label)='v06' AND s.Active='Y' AND c.Active='Y'
        AND File like '%dti%' AND COALESCE(pcc.Value, '') <> '' AND s.Current_stage <> 'Recycling Bin' AND s.SubprojectID IN (1, 2, 3)
        AND ( (ps.study_consent = 'yes' OR ps.study_consent IS NULL) AND (COALESCE(ps.study_consent_withdrawal,'0000-00-00') = '0000-00-00' )) AND ((ps.ndar_consent = 'yes' OR ps.ndar_consent IS NULL) AND (COALESCE(ps.ndar_consent_withdrawal,'0000-00-00') = '0000-00-00')) ORDER BY PSCID", array());

        // IBIS2 - v03 - 25 direction DTI, 65 direction, and fMRI
        $files = $db->pselect("select c.CandID, c.PSCID, c.IBISID, pcc.Value, c.ProbandGUID, c.DoB, s.CenterID, s.Visit_label, s.Current_stage, f.File, fqc.QCStatus, c.Sex FROM files f left join files_qcstatus fqc USING (FileID) LEFT JOIN session s ON (s.ID=f.SessionID) LEFT JOIN candidate c on (c.CandID=s.CandID) LEFT JOIN parameter_file AS pf ON (f.FileID=pf.FileID) LEFT JOIN parameter_type AS pt ON (pt.ParameterTypeID=pf.ParameterTypeID) LEFT JOIN participant_status ps ON (c.CandID=ps.CandID) WHERE pt.Name='time' AND LOWER(s.Visit_label)='v03' AND s.Active='Y' AND c.Active='Y' AND
            (
                (lower(File) like '%dti%' AND pf.Value IN (26, 66)) OR
                (lower(File) LIKE '%ep2d%')
            )
            AND COALESCE(pcc.Value, '') <> '' AND s.Current_stage <> 'Recycling Bin' AND s.SubprojectID IN (9, 10)
            AND ( (ps.study_consent = 'yes' OR ps.study_consent IS NULL) AND (COALESCE(ps.study_consent_withdrawal,'0000-00-00') = '0000-00-00' )) AND ((ps.ndar_consent = 'yes' OR ps.ndar_consent IS NULL) AND (COALESCE(ps.ndar_consent_withdrawal,'0000-00-00') = '0000-00-00'))
            ORDER BY PSCID", array());

        // IBIS2 - v03 - 25 direction DTI, 65 direction 2016
        $files = $db->pselect("select c.CandID, c.PSCID, c.IBISID, pcc.Value, c.ProbandGUID, c.DoB, s.CenterID, s.Visit_label, s.Current_stage, f.File, fqc.QCStatus, c.Sex FROM files f left join files_qcstatus fqc USING (FileID) LEFT JOIN session s ON (s.ID=f.SessionID) LEFT JOIN candidate c on (c.CandID=s.CandID) LEFT JOIN parameter_file AS pf ON (f.FileID=pf.FileID) LEFT JOIN parameter_type AS pt ON (pt.ParameterTypeID=pf.ParameterTypeID) LEFT JOIN participant_status ps ON (c.CandID=ps.CandID) WHERE pt.Name='time' AND LOWER(s.Visit_label)='v03' AND s.Active='Y' AND c.Active='Y' AND
            (
                (lower(File) like '%dti%' AND pf.Value IN (26, 66))
            )
            AND COALESCE(pcc.Value, '') <> '' AND s.Current_stage <> 'Recycling Bin' AND s.SubprojectID IN (9, 10)
            AND ( (ps.study_consent = 'yes' OR ps.study_consent IS NULL) AND (COALESCE(ps.study_consent_withdrawal,'0000-00-00') = '0000-00-00' )) AND ((ps.ndar_consent = 'yes' OR ps.ndar_consent IS NULL) AND (COALESCE(ps.ndar_consent_withdrawal,'0000-00-00') = '0000-00-00'))
            ORDER BY PSCID", array());


        // IBIS1 - v06 - T1 & T2's
        $files = $db->pselect("SELECT c.CandID, c.PSCID, c.IBISID, pcc.Value, c.ProbandGUID, c.DoB, s.CenterID, s.Visit_label, s.Current_stage, f.File, fqc.QCStatus, c.Sex from files f left join files_qcstatus fqc USING (FileID) LEFT JOIN session s ON (s.ID=f.SessionID) LEFT JOIN candidate c on (c.CandID=s.CandID) LEFT JOIN parameter_file AS pf ON (f.FileID=pf.FileID) LEFT JOIN parameter_type AS pt ON (pt.ParameterTypeID=pf.ParameterTypeID) LEFT JOIN participant_status ps ON (c.CandID=ps.CandID) WHERE pt.Name='patient_id' AND lower(s.Visit_label)='v06' AND s.Active='Y' AND c.Active='Y' AND
            (
                f.AcquisitionProtocolID='44' OR f.AcquisitionProtocolID='45'
            )
            AND COALESCE(pcc.Value, '') <> '' AND s.Current_stage <> 'Recycling Bin' AND s.SubprojectID IN (1, 2, 3)
            AND ( (ps.study_consent = 'yes' OR ps.study_consent IS NULL) AND (COALESCE(ps.study_consent_withdrawal,'0000-00-00') = '0000-00-00' )) AND ((ps.ndar_consent = 'yes' OR ps.ndar_consent IS NULL) AND (COALESCE(ps.ndar_consent_withdrawal,'0000-00-00') = '0000-00-00')) 
            ORDER BY PSCID", array());

        */
        // IBIS1 - 'V06', 'V12', 'V24' - T1 & T2's
        if ($t1t2) {
          if ($ibis == 1) {
            $files = $db->pselect("select c.CandID, c.PSCID, c.IBISID, pcc.Value AS CandidateGUID, pcp.Value AS ProbandGUID, c.DoB, s.CenterID, s.Visit_label, s.Current_stage, f.File, fqc.QCStatus, c.Sex
            FROM files f 
            LEFT JOIN files_qcstatus fqc USING (FileID) 
            LEFT JOIN session s ON (s.ID=f.SessionID) 
            LEFT JOIN candidate c ON (c.CandID=s.CandID)
            LEFT JOIN parameter_file AS pf ON (f.FileID=pf.FileID) 
            LEFT JOIN parameter_type AS pt ON (pt.ParameterTypeID=pf.ParameterTypeID) 
            LEFT JOIN participant_status ps ON (c.CandID=ps.CandID)
            LEFT JOIN parameter_candidate AS pcc ON (pcc.ParameterTypeID=(SELECT ParameterTypeID FROM parameter_type WHERE name='CandidateGUID') AND pcc.CandID=c.CandID)
            LEFT JOIN parameter_candidate AS pcp ON (pcp.ParameterTypeID=(SELECT ParameterTypeID FROM parameter_type WHERE name='ProbandGUID') AND pcp.CandID=c.CandID)
            WHERE pt.Name='patient_id' AND UPPER(s.Visit_label) IN ({$v[$ibis]}) AND s.Active='Y' AND c.Active='Y' AND (ps.participant_status=1 OR ps.participant_status=7) AND
            (
                f.AcquisitionProtocolID='44' OR f.AcquisitionProtocolID='45'
            )
            AND COALESCE(pcc.Value, '') <> '' AND s.Current_stage <> 'Recycling Bin' AND s.SubprojectID IN (1, 2, 3)
            AND ((ps.study_consent = 'yes' OR ps.study_consent IS NULL) AND (COALESCE(ps.study_consent_withdrawal,'0000-00-00') = '0000-00-00' ))
            AND ((ps.ndar_consent  = 'yes' OR ps.ndar_consent  IS NULL) AND (COALESCE(ps.ndar_consent_withdrawal, '0000-00-00') = '0000-00-00'))
            ORDER BY PSCID", array());
          } else if ($ibis == 2) {
            $files = $db->pselect("select c.CandID, c.PSCID, c.IBISID, pcc.Value AS CandidateGUID, pcp.Value AS ProbandGUID, c.DoB, s.CenterID, s.Visit_label, s.Current_stage, f.File, fqc.QCStatus, c.Sex
            FROM files f 
            LEFT JOIN files_qcstatus fqc USING (FileID) 
            LEFT JOIN session s ON (s.ID=f.SessionID) 
            LEFT JOIN candidate c ON (c.CandID=s.CandID)
            LEFT JOIN parameter_file AS pf ON (f.FileID=pf.FileID) 
            LEFT JOIN parameter_type AS pt ON (pt.ParameterTypeID=pf.ParameterTypeID) 
            LEFT JOIN participant_status ps ON (c.CandID=ps.CandID)
            LEFT JOIN parameter_candidate AS pcc ON (pcc.ParameterTypeID=(SELECT ParameterTypeID FROM parameter_type WHERE name='CandidateGUID') AND pcc.CandID=c.CandID)
            LEFT JOIN parameter_candidate AS pcp ON (pcp.ParameterTypeID=(SELECT ParameterTypeID FROM parameter_type WHERE name='ProbandGUID') AND pcp.CandID=c.CandID)
            WHERE pt.Name='patient_id' AND UPPER(s.Visit_label) IN ({$v[$ibis]}) AND s.Active='Y' AND c.Active='Y' AND (ps.participant_status=1 OR ps.participant_status=7) AND
            (
                f.AcquisitionProtocolID='44' OR f.AcquisitionProtocolID='45'
            )
            AND COALESCE(pcc.Value, '') <> '' AND s.Current_stage <> 'Recycling Bin' AND s.SubprojectID IN (9, 10)
            AND ((ps.study_consent = 'yes' OR ps.study_consent IS NULL) AND (COALESCE(ps.study_consent_withdrawal,'0000-00-00') = '0000-00-00' ))
            AND ((ps.ndar_consent  = 'yes' OR ps.ndar_consent  IS NULL) AND (COALESCE(ps.ndar_consent_withdrawal, '0000-00-00') = '0000-00-00'))
            ORDER BY PSCID", array());
          }
        }

        // IBIS1 - 'V06', 'V12', 'V24' - DTI25
        if ($dti) {
          if ($ibis == 1) {
            $files = $db->pselect("select c.CandID, c.PSCID, c.IBISID, pcc.Value AS CandidateGUID, pcp.Value AS ProbandGUID, c.DoB, s.CenterID, s.Visit_label, s.Current_stage, f.File, fqc.QCStatus, c.Sex
            FROM files f 
            left join files_qcstatus fqc USING (FileID) 
            LEFT JOIN session s ON (s.ID=f.SessionID) 
            LEFT JOIN candidate c on (c.CandID=s.CandID)
            LEFT JOIN parameter_file AS pf ON (f.FileID=pf.FileID) 
            LEFT JOIN parameter_type AS pt ON (pt.ParameterTypeID=pf.ParameterTypeID) 
            LEFT JOIN participant_status ps ON (c.CandID=ps.CandID)
            LEFT JOIN parameter_candidate AS pcc ON (pcc.ParameterTypeID=(SELECT ParameterTypeID FROM parameter_type WHERE name='CandidateGUID') AND pcc.CandID=c.CandID)
            LEFT JOIN parameter_candidate AS pcp ON (pcp.ParameterTypeID=(SELECT ParameterTypeID FROM parameter_type WHERE name='ProbandGUID') AND pcp.CandID=c.CandID)
            WHERE UPPER(s.Visit_label) IN ({$v[$ibis]}) AND s.Active='Y' AND c.Active='Y' AND (ps.participant_status=1 OR ps.participant_status=7) AND
            pt.Name='time' AND pf.Value=26 AND f.AcquisitionProtocolID='48' AND f.File like '%dti%'
            AND COALESCE(pcc.Value, '') <> '' AND s.Current_stage <> 'Recycling Bin' AND s.SubprojectID IN (1, 2, 3)
            AND ((ps.study_consent = 'yes' OR ps.study_consent IS NULL) AND (COALESCE(ps.study_consent_withdrawal,'0000-00-00') = '0000-00-00' ))
            AND ((ps.ndar_consent  = 'yes' OR ps.ndar_consent  IS NULL) AND (COALESCE(ps.ndar_consent_withdrawal, '0000-00-00') = '0000-00-00'))
            ORDER BY PSCID", array());
          } else if ($ibis == 2) {
            $files = $db->pselect("select c.CandID, c.PSCID, c.IBISID, pcc.Value AS CandidateGUID, pcp.Value AS ProbandGUID, c.DoB, s.CenterID, s.Visit_label, s.Current_stage, f.File, fqc.QCStatus, c.Sex
            FROM files f 
            left join files_qcstatus fqc USING (FileID) 
            LEFT JOIN session s ON (s.ID=f.SessionID) 
            LEFT JOIN candidate c on (c.CandID=s.CandID)
            LEFT JOIN parameter_file AS pf ON (f.FileID=pf.FileID) 
            LEFT JOIN parameter_type AS pt ON (pt.ParameterTypeID=pf.ParameterTypeID) 
            LEFT JOIN participant_status ps ON (c.CandID=ps.CandID)
            LEFT JOIN parameter_candidate AS pcc ON (pcc.ParameterTypeID=(SELECT ParameterTypeID FROM parameter_type WHERE name='CandidateGUID') AND pcc.CandID=c.CandID)
            LEFT JOIN parameter_candidate AS pcp ON (pcp.ParameterTypeID=(SELECT ParameterTypeID FROM parameter_type WHERE name='ProbandGUID') AND pcp.CandID=c.CandID)
            WHERE UPPER(s.Visit_label) IN ({$v[$ibis]}) AND s.Active='Y' AND c.Active='Y' AND (ps.participant_status=1 OR ps.participant_status=7) AND
            pt.Name='time' AND pf.Value=26 AND f.AcquisitionProtocolID='48' AND f.File like '%dti%'
            AND COALESCE(pcc.Value, '') <> '' AND s.Current_stage <> 'Recycling Bin' AND s.SubprojectID IN (9, 10)
            AND ((ps.study_consent = 'yes' OR ps.study_consent IS NULL) AND (COALESCE(ps.study_consent_withdrawal,'0000-00-00') = '0000-00-00' ))
            AND ((ps.ndar_consent  = 'yes' OR ps.ndar_consent  IS NULL) AND (COALESCE(ps.ndar_consent_withdrawal, '0000-00-00') = '0000-00-00'))
            ORDER BY PSCID", array());
          }
        }


        // $files = array_merge($filesq1, $filesq2, $filesq3);

        /*
        // Casey's request
        $files = $db->pselect("select pt.Name, c.CandID, c.PSCID, c.IBISID, pcc.Value, c.ProbandGUID, c.DoB, s.CenterID, s.Visit_label, s.Current_stage, f.File, fqc.QCStatus, c.Sex
            FROM files f
            LEFT JOIN files_qcstatus fqc USING (FileID)
            LEFT JOIN session s ON (s.ID=f.SessionID)
            LEFT JOIN candidate c on (c.CandID=s.CandID)
            LEFT JOIN parameter_file AS pf ON (f.FileID=pf.FileID)
            LEFT JOIN parameter_type AS pt ON (pt.ParameterTypeID=pf.ParameterTypeID)
            LEFT JOIN participant_status ps ON (c.CandID=ps.CandID)
            WHERE pf.ParameterTypeID='1'
            AND ((f.acquisitionprotocolid = 44 and pf.value = 't1w') or (f.acquisitionprotocolid = 45 and pf.value = 't2w'))
            AND s.SubprojectID IN (1, 2, 3, 9, 10)
            AND ((ps.study_consent = 'yes' OR ps.study_consent IS NULL) AND (COALESCE(ps.study_consent_withdrawal,'0000-00-00') = '0000-00-00' ))
            AND c.candID in (216477, 274101, 755073, 842426, 924951)
            ORDER BY PSCID", array());
        */

        // NDAR
        //$anonFilePath = "/data/ibis/data/";

        // Casey´s
        // $anonFilePath = "/data/not_backed_up/";


        foreach($files as $row) {
            print "Replacing file: ". $row['File'] ."\n";
            $file_anonymized = $this->replaceID($row['File'], $row['CandID'], $row['IBISID']);
            $split_file = explode("/", $file_anonymized);
            $only_anon_file = $split_file[count($split_file)-1];print $row['File']."\n";

            if ($location == "prod") {
              $row['File'] = str_replace("assembly/","", $row["File"]);
            }

            if ($location == "defaced") {
                // login is the folder which contain defaced images; for eg:data/not_backed_up/login
              $row['File'] = str_replace("assembly", "login", $row['File']);
              $row['File'] = str_replace("mri/native/ibis", "deface/deface", $row['File']);
              $row['File'] = preg_replace("/_00\d/", "$1", $row['File']);
              $row['File'] = str_replace("v03", "V03", $row['File']);
              $row['File'] = str_replace("v06", "V06", $row['File']);
              $row['File'] = str_replace("v12", "V12", $row['File']);
              $row['File'] = str_replace("v24", "V24", $row['File']);
            }

            if (!file_exists($outputDir . $only_anon_file)) {
              if (file_exists($anonFilePath . $row['File'])) {
                $this->anonFile($anonFilePath . $row['File'], $outputDir . $only_anon_file);
                $this->addToCSV($outputDir . $only_anon_file, $row);
              } else {
                print "Original not found: ". $anonFilePath . $row['File'] . "\n";
              }
            } else {
              print "File was already done: " . $outputDir . $only_anon_file . "\n";
              $this->addToCSV($outputDir . $only_anon_file, $row);
            }
        }

        $fp = fopen($outputDir . "NDARMRI.csv", 'w');
        fputcsv($fp, array('image03'));
        fputcsv($fp, array_keys($this->CSVData[0]));
        foreach ($this->CSVData as $row) {
            fputcsv($fp, $row);
        }
        fclose($fp);
        print_r($this->CSVData);
    }
}
// Don't run if we're doing the unit tests, the unit test will call run..
if(!class_exists('UnitTestCase')) {
    require_once "NDB_Client.class.inc";
    $factory = NDB_Factory::singleton();
    // Initialize so that the factory looks in the right place.
    $throwaway = $factory->config('../config.xml');

    $client = new NDB_Client();
    $client->makeCommandLine();
    $client->initialize('../config.xml');
    $Runner = new NDAR_Release_MRI();
    $Runner->run();
}
?>