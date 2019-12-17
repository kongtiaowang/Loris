<?php
/**
 * This file contains the NDB_Menu_Filter_media class
 *
 * PHP Version 5
 *
 * @category Module
 * @package  Quality Control
 * @author   Liza Levitis <llevitis.mcin@gmail.com>
 * @license  http://www.gnu.org/licenses/gpl-3.0.txt GPLv3
 * @link     https://www.github.com/aces/CCNA/
 */
namespace LORIS\quality_control;

/**
 * Main class for quality control module corresponding to /quality_control/ URL
 * Tools section of the LorisMenu.
 *
 * PHP Version 5
 *
 * @category Module
 * @package  Quality Control
 * @author   Liza Levitis  <llevitis.mcin@gmail.com>
 * @license  http://www.gnu.org/licenses/gpl-3.0.txt GPLv3
 * @link     https://www.github.com/aces/CCNA/
 */
class Quality_Control extends \NDB_Menu_Filter
{
    public $hasWritePermission = false;
    public $AjaxModule         = true;

    /**
     * Check user permissions
     *
     * @return bool
     * @throws ConfigurationException
     */
    function _hasAccess()
    {
        //create user object
        $user =& \User::singleton();
        return $user->hasPermission('data_team_helper');
    }

    /**
     * Checks configuration module to find which scans are relevant
     * to the given project
     *
     * @return array $scan_types of desired scan types.
     */
    function _getScanTypes()
    {
        $config = \NDB_Config::singleton();
        $db     = \Database::singleton();

        //-------------------------------------------//
        // Build associative array of all scan types //
        //-------------------------------------------//
        $all_scan_types_2d = $db->pselect(
            "SELECT ID, Scan_type FROM mri_scan_type mri",
            array()
        );
        foreach ($all_scan_types_2d as $row) {
            $all_scan_types[$row['ID']] = $row['Scan_type'];
        }

        //---------------------------------------------------------------//
        // Build array of the scan types that belong to any of the scan  //
        // type groups listed in $toTable_scan_type_groups               //
        //---------------------------------------------------------------//
        $toTable_scan_type_groups = $config->getSetting('tblScanTypeGroups');

        $query = sprintf(
            "
             SELECT DISTINCT ID, Scan_type
             FROM mri_scan_type mri
             JOIN mri_scan_type_groups_rel mstgr ON (mri.ID=mstgr.MriScanTypeID)
             JOIN mri_scan_type_groups mstg ON (mstgr.MriScanTypeGroupID=mstg.MriScanTypeGroupID)
             WHERE mstg.Name IN (%s)
            ",
            implode(",", array_fill(0, count($toTable_scan_type_groups), '?'))
        );
        $scan_types_in_all_groups_2d = $db->pselect($query, $toTable_scan_type_groups);
        foreach ($scan_types_in_all_groups_2d as $row) {
            $scan_types_in_all_groups[$row['ID']] = $row['Scan_type'];
        }

        // Get the intersection between all the scan types and those
        // that are desired to go into imaging browser table, based on
        // array values rather than keys (hence the array_flip), then flip
        // the resulting array back to revert it to a key/value (i.e.
        // acquisition protocol ID/scan type) combination.
        $scan_id_types =array_flip(
            array_intersect_key(
                array_flip($scan_types_in_all_groups),
                array_flip($all_scan_types)
            )
        );
        $scan_types    =[];

        foreach ($scan_id_types as $scan) {
            $scan_types[$scan] = $scan;
        }
        
        return $scan_types;
    }



    /**
     * Builds query for given modality. Works with t1w, t2w, dti.
     *
     * @param string $scan_type One of 't1w', 't2w', 'dti'
     * @param string $scan_done Name of column to check in mri_parameter_form
     * @param string $acqID     Aquisition protocol ID for given modality
     *
     * @return string $query for the given modality
     */
    function _buildQuery($scan_type, $mriPfColumn, $mriPfTable, $acqID, $mriPfDoneValues)
    {
		$mriPfTableAlias ='';
		$noMriPf = 0;
		
		// Set the value of $mriPfTable to be the table alias used in 
		// the SQL statement below
		switch ($mriPfTable ) {
			case null: 
			    $noMriPf = 1;
			    break;
		    case 'mri_parameter_form_sa':
		        $mriPfTableAlias = 'm_sa';
		        break;
	        case 'mri_parameter_form': 
		        $mriPfTableAlias = 'm';
		        break;
		    default: throw new \InvalidArgumentException("Unsupported MRI parameter form table $mriPfTable");
		}
		
		$db =& \Database::singleton();
		$mriPfDoneValueSet = is_null($mriPfDoneValues)
		    ? ''
		    : $db->quote(implode(',', $mriPfDoneValues));
		
        $select =  " SELECT DISTINCT
           c.PSCID,
           s.ID as SessionID,
           s.CandID as cand_id,
           (SELECT name FROM psc WHERE CenterID=s.CenterID) as site,
           s.Visit_label as visit_label,
           '".$scan_type."' as scan_type,
           t.TarchiveID as tarchiveID,
           CASE
              WHEN EXISTS(
                  SELECT
                      *
                  FROM
                      tarchive_series ts
                  WHERE
                      ts.TarchiveID = t.TarchiveID
                      AND(
                          ts.EchoTime BETWEEN(
                              SELECT
                                  SUBSTRING_INDEX(mp.TE_range, '-', 1)
                              FROM
                                  mri_protocol mp
                              WHERE
                                  mp.Scan_type = ".$acqID." LIMIT 1
                          ) AND(
                              SELECT
                                  SUBSTRING_INDEX(mp.TE_range, '-', -1)
                              FROM
                                  mri_protocol mp
                              WHERE
                                   mp.Scan_type = ".$acqID." LIMIT 1
                           )
                      )
                      AND(
                          (ts.RepetitionTime = (
                              SELECT
                                  SUBSTRING_INDEX(mp.TR_range, ',', 1)
                              FROM
                                  mri_protocol mp
                              WHERE
                                  mp.Scan_type = ".$acqID." LIMIT 1
                          )) OR ( ts.RepetitionTime = (
                              SELECT
                                  SUBSTRING_INDEX(mp.TR_range, ',', -1)
                              FROM
                                  mri_protocol mp
                              WHERE
                                  mp.Scan_type = ".$acqID." LIMIT 1
                           ))
                      )
               ) THEN 'In DICOM'
              ELSE 'Missing'
           END as tarchive_loc,
           (SELECT Name FROM Project WHERE ProjectID=c.ProjectID) as project,".
            " (SELECT title FROM subproject WHERE SubprojectID=s.SubprojectID)
           as subproject,".
            " CASE
              WHEN m.Data_entry_completion_status='Incomplete' THEN 'Incomplete'
              ELSE 'Complete'
           END AS mri_parameter_form,
           CASE
              WHEN ($noMriPf OR {$mriPfTableAlias}.$mriPfColumn IS NULL) THEN ''
              WHEN FIND_IN_SET({$mriPfTableAlias}.$mriPfColumn, $mriPfDoneValueSet)>0 THEN 'Yes'
              ELSE 'No'
           END as scan_done,
           CASE
              WHEN (fi.fileID IS NULL AND mvl.PatientName IS NULL) THEN 'Missing'
              WHEN fi.fileID IS NOT NULL THEN 'In Imaging Browser'
              WHEN mvl.PatientName IS NOT NULL THEN 'In MRI Violated Scans'
           END as scan_location,
           CASE
              WHEN qc.Selected = '' THEN 'False'
              WHEN qc.Selected = 'true' THEN 'True'
           END as selected,
           qc.QCStatus as qc_status,
           mu.uploadedBy as uploaded_by,
           f.CommentID as CommentID ";

        //print_r($select);
        $joins = " FROM flag f
        LEFT JOIN session s ON (f.SessionID=s.ID)
        LEFT JOIN mri_parameter_form m ON (m.CommentID=f.CommentID)
        LEFT JOIN mri_parameter_form_sa m_sa ON (m_sa.CommentID=f.CommentID)
        LEFT JOIN tarchive t ON (t.SessionID=s.ID)".
            " LEFT JOIN files fi ON (fi.SessionID=s.ID AND
        fi.AcquisitionProtocolID=".$acqID.")".
            " LEFT JOIN mri_violations_log mvl ON".
            " (mvl.CandID = s.CandID AND mvl.Scan_type=".$acqID."".
            " AND mvl.PatientName LIKE CONCAT ('%', s.Visit_label,'%'))".
            " LEFT JOIN candidate c ON (s.CandID=c.CandID)
        LEFT JOIN files_qcstatus qc ON (qc.FileID = fi.FileID)
        LEFT JOIN mri_upload mu ON (mu.SessionID = f.SessionID) ";

        $where = " WHERE 1=1
          AND NOT f.CommentID LIKE 'DDE%'
          AND f.Test_name=" . (is_null($mriPfTable) ? "''" : "'$mriPfTable'") .
        " AND s.Active='Y'
          AND s.CenterID <> '1' ";

        $query = $select.$joins.$where;

        return $query;
    }
    /**
     * Create a form to filter behavioral QC by various criteria
     *
     * @return bool
     * @throws ConfigurationException
     * @throws DatabaseException
     * @throws Exception
     */
    function _setFilterForm()
    {
        $user      =& \User::singleton();
        $db        =& \Database::singleton();
        $siteList  = array();
        $visitList = \Utility::getVisitList();
        // allow to view all sites data through filter
        if ($user->hasPermission('imaging_browser_qc')) {
            $siteList = \Utility::getSiteList();
            // Index sites using their names (used to filter react tables)
            foreach ($siteList as $key => $site) {
                unset($siteList[$key]);
                $siteList[$site] = $site;
            }
        } else {
            // allow only to view own site data
            $siteIDs = $user->getData('CenterIDs');
            foreach ($siteIDs as $val) {
                $site = &Site::singleton($val);
                if ($site->isStudySite()) {
                    $siteList[$site->getCenterName()] = $site->getCenterName();
                }
            }
        }

        $scan_types = $this->_getScanTypes();

        $projectList     = \Utility::getProjectList();
        foreach ($projectList as $key => $value) {
            $projectList2[$value] = $value;
        }
        $subprojectList  = \Utility::getSubprojectList();
        $subprojectList2 = array();
        foreach ($subprojectList as $key => $value) {
            $subprojectList2[$value] = $value;
        }
        //print_r($subprojectList2);
        $uploaderList =[];
        $uploaders    = $db -> pselect(
            "SELECT UploadedBy FROM mri_upload GROUP BY UploadedBy",
            array()
        );
        foreach ($uploaders as $up) {
            $uploaderList[$up['UploadedBy']] = $up['UploadedBy'];
        }

        $scan_location = array(
            "In Imaging Browser"    => "Found in Imaging Browser",
            "In MRI Violated Scans" => "Found in MRI Violated Scans",
            "Missing"               => "Missing",
        );
        // Form Elements
        $this->addSelect('site', 'Site', $siteList);
        $this->addBasicText('candId', 'DCCID', ["size" => 9, "maxlength" => 7]);
        $this->addBasicText('pSCID', 'PSCID', ["size" => 9, "maxlength" => 7]);
        $this->addSelect('project', 'Project', $projectList2);
        $this->addSelect('subproject', 'Subproject', $subprojectList2);
        $this->addSelect('scanType', 'Scan Type', $scan_types);
        $this->addSelect(
            'mRIParameterForm',
            "MRI Parameter Form",
            array(
                "Incomplete" => "Incomplete",
                "Complete"   => "Complete",
            )
        );
        $this->addSelect(
            'scanDoneInMRIPF',
            'Scan Done in MRI PF',
            array(
                "Yes" => "Yes",
                "No"  => "No",
            )
        );
        $this->addSelect(
            'tarchive',
            'Tarchive Status',
            array(
                "In DICOM" => "In DICOM Archives",
                "Missing"  => "Missing",
            )
        );
        $this->addSelect(
            'scanLocation',
            'Scan Location',
            $scan_location
        );
        $this->addSelect(
            'qCStatus',
            'QC Status',
            array(
                "Pass" => "Pass",
                "Fail" => "Fail",
            )
        );
        $this->addSelect(
            'uploadedBy',
            'Uploaded By',
            $uploaderList
        );
        $this->addSelect(
            'selected',
            'Selected',
            array(
                "True"  => "True",
                "False" => "False",
            )
        );
        return true;
    }
    
    /**
     * Gets the name of the table where the MRI parameter form info is stored
     * for the given scan type.
     * 
     * @param $scanType a scan type from table mri_scan_types.
     * 
     * @return string the table name.
     */
    function _getMriPfTableName(string $scanType) : string
    {
		if (preg_match('/SA$/', $scanType)) {
			return 'mri_parameter_form_sa';
		} elseif (preg_match('/EP$/', $scanType)) {
			return null;
		} 

        return 'mri_parameter_form';
	}
	
	/**
	 * Gets the name of the column in the table returned by _getMriPfTableName
	 * that tells whether the given scan type was acquired or not.
	 * 
	 * @param string $scanType a scan type from table mri_scan_types.
	 * 
	 * @return string the column name.
	 */
	function _getMriPfColumnName(string $scanType) : string
    {
        switch ($scanType) {
			case 't1w':
			case 't1relx':      return 'T1_Scan_done';
			case 't2w':         return 'T2_Scan_done';
			case 'dti':         return 'DTI_Scan_done';
			case 'DTI65':  
			case 'DTI65_B1000': return 'DTI65_Scan_done';
			case 'fMRI':        return 'BOLD_Scan_done';
			case 'T1wNormSA':
			case 'T1wRawSA':    return 't1w_acquired';
			case 'T2wNormSA':
			case 'T2wRawSA':    return 't2w_acquired';
		}
		
        return 'mri_parameter_form';
	}

    /**
     * Gets the set of values in the column whose name is returned by
     * _getMriPfColumnName indicating the a partial or complete (including multiple)
     * scan of the given type was acquired.
     * 
     * @param string $scanType a scan type from table mri_scan_types.
     * 
     * @return array the set of values as an array of strings.
     */
	function _getMriPfDoneValues(string $scanType) : array
    {
		if (preg_match('/EP$/', $scanType)) {
			return null;
		}
		
        switch ($scanType) {
			case 'T1wRawSA':
			case 'T1wNormSA':
			case 'T2RawSA':
			case 'T2NormSA': return array('Yes_2', 'Yes_1');
		}
		
		return array('Complete', 'Partial');
	}
	
    /**
     * Build a list of imaging QC to display in Data Table
     *
     * @return bool
     * @throws DatabaseException
     */
    function _setupVariables()
    {

        $db =& \Database::singleton();
        $this->skipTemplate = true;

        $scan_types = $this->_getScanTypes();
        foreach ($scan_types as $scan_type) {
            $query_params        = array('scan_type' => $scan_type);
            $acq_IDs[$scan_type] = $db->pselectOne(
                "SELECT ID FROM mri_scan_type WHERE Scan_type=:scan_type",
                $query_params
            );
        }

        foreach ($scan_types as $scan_type) {
			$mriPfDoneValues = $this->_getMriPfDoneValues($scan_type);
            $scan_types[$scan_type] = $this->_buildQuery(
                $scan_type,
                $this->_getMriPfColumnName($scan_type),
                $this->_getMriPfTableName($scan_type),
                $acq_IDs[$scan_type],
                $mriPfDoneValues
            );
        }

        $query = implode(
            "
          UNION ALL
          ",
            $scan_types
        );

        $this->query = " FROM ( " . $query . " ) as tmp";

        $this->columns = [
            'PSCID',
            'SessionID',
            'cand_id',
            'site',
            'project',
            'subproject',
            'visit_label',
            'scan_type',
            'mri_parameter_form',
            'scan_done',
            'tarchive_loc',
            'scan_location',
            'qc_status',
            'uploaded_by',
            'selected',
            'CommentID',
            'TarchiveID',
        ];

        $this->group_by = 'PSCID,
            SessionID,
            cand_id,
            site,
            project,
            subproject,
            visit_label,
            scan_type,
            mri_parameter_form,
            scan_done,
            tarchive_loc,
            scan_location,
            qc_status,
            selected,
            uploaded_by,
            CommentID,
            TarchiveID ';

        $this->order_by = 'PSCID';

        $this->headers = [
            'PSCID',
            'Session ID',
            'DCCID',
            'Site',
            'Project',
            'Subproject',
            'Visit Label',
            'Scan Type',
            'MRI Parameter Form',
            'Scan Done in MRI PF',
            'Tarchive',
            'Scan Location',
            'QC Status',
            'Uploaded By',
            'Selected',
            'CommentID',
            'TarchiveID',
        ];

        return true;
    }
    /**
     * Converts the results of this menu filter to a JSON format to be retrieved
     * with ?format=json
     *
     * @return a json encoded string of the headers and data from this table
     */
    function toJSON()
    {
        $result         = $this->toArray();
        $result['form'] = $this->form->form;
        return json_encode($result);
    }
    /**
     * Include additional JS files
     *
     * @return array of javascript to be inserted
     */
    function getJSDependencies()
    {
        $factory = \NDB_Factory::singleton();
        $baseURL = $factory->settings()->getBaseURL();
        $deps    = parent::getJSDependencies();
        return array_merge(
            $deps,
            array(
                $baseURL . "/quality_control/js/qualityControlIndex.js",
            )
        );
    }
}

