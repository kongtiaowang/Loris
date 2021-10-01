<?php
/**
 * This class features the code for the menu portion of the final radiological
 * review. The Final Radiological Review module is used for the head radiologist
 * of a study to do an radiological review on each subject in a study, in addition
 * to the on-site review that was done by the each site's (likely more junior)
 * radiologist.
 *
 * For sites where the head radiologist is also the site radiologist, a second,
 * trusted radiologist does the second review. Conflicts between any of the radiology
 * reviews are flagged for the radiologists to consult over before finalizing.
 *
 * PHP Version 7
 *
 *  @category Loris
 *  @package  Document_Repository
 *  @author   Dave MacFarlane <driusan@bic.mni.mcgill.ca>
 *  @license  Loris license
 *  @link     https://www.github.com/aces/Loris-Trunk/
 */

namespace LORIS\final_radiological_review;


/**
 * Provides the PHP code for the menu filter for the final radiological review.
 *
 *  @category Loris
 *  @package  Document_Repository
 *  @author   Dave MacFarlane <driusan@bic.mni.mcgill.ca>
 *  @license  Loris license
 *  @link     https://www.github.com/aces/Loris-Trunk/
 */
class Final_Radiological_Review extends \NDB_Menu_Filter
{
	/**
     * Utility function to make things more human readable.
     *
     * This is used both below and in the history on the NDB_Form.
     *
     * This maybe should be moved into the base class so that other menus that need
     * to customize the display of how data is shown can do so in a consistent manner
     *
     * @param string  $key The key that's being prettified
     * @param unknown $val The raw value for the key
     *
     * @return string Human readable version of raw data
     */
    public static function _makePretty($key, $val)
    {
        if ($key=='Conflict' || $key=="Conflict2" || $key=="Conflict") {
            // The table was created with a boolean, which mysql turns into a tinyint.
            // Print 'Yes' or 'No' instead of 1 or 0.
            if ($val == 1 || $val === '1' || $val === 'true') {
                return 'Yes';
			}

			/* PHP turns the tinyint back into a string ....*/
            return ($val === "0" || $val === "false") ? 'No' : '';
        }
        if ($key == "Finalized" || $key =="Review_Done") {
            if ($val == "yes") {
                return 'Yes';
            }

            return $val == "no" ? 'No' : '';
        }

        if ($key == 'Final_Review_Results'
            || $key == 'Exclusionary_Status'
            || $key=="Final_Exclusionary"
            || $key == "Results"
        ) {
            // Make the enum columns prettier by changing _ into
            // a space and capitalizing
            return ucwords(str_replace('_', ' ', $val));
        } elseif ($key == 'SAS' or $key == 'PVS') {
            switch($val) {
            case '0':
                return 'None';
            case '1':
                return 'Minimal';
            case '2':
                return 'Mild';
            case '3':
                return 'Moderate';
            case '4':
                return 'Marked';
            default:
                return '';
            }
        } elseif ($key == 'Project') {
            $projectlist = \Utility::getProjectList();
            return $projectlist[$val];
        } else {
            return $val;
        }
    }

    /**
     * Determine whether the user has permission to view this page
     *
     * @return bool whether the user hass access
     */
    function _hasAccess(\User $user) : bool
    {
        return (
            $user->hasPermission('view_final_radiological_review') ||
            $user->hasPermission('edit_final_radiological_review')
        );
    }

    /**
     * Set up the variables required by NDB_Menu_Filter class for constructing
     * a query
     *
     * @return void
     */
    function _setupVariables()
    {
        $config      = \NDB_Config::singleton();

        $conflict_condition1 = "(CASE
            WHEN r.CommentID IS NULL THEN 'NA'
            WHEN orig.review_results <> r.final_review_results THEN 'true'
            WHEN orig.abnormal_atypical_exclusionary <> r.final_exclusionary
               THEN 'true'
            WHEN r.Final_Review_Results <> r.Final_Review_Results2 THEN 'true'
            WHEN r.Final_Exclusionary <> r.Final_Exclusionary2 THEN 'true'
            WHEN r.SAS <> r.SAS2 THEN 'true'
            WHEN r.PVS <> r.PVS2 THEN 'true'
            ELSE 'false' END)";
        $conflict_condition2 = "(CASE
            WHEN r.CommentID IS NULL THEN 'NA'
            WHEN r.Final_Review_Results <> r.Final_Review_Results2 THEN 'prim_second'
            WHEN r.Final_Exclusionary <> r.Final_Exclusionary2 THEN 'prim_second'
            WHEN r.SAS <> r.SAS2 THEN 'prim_second'
            WHEN r.PVS <> r.PVS2 THEN 'prim_second'
            ELSE 'false' END)";

        $DB = \Database::singleton();

        if ($DB->tableExists('mri_parameter_form') === false) {
            throw new \LorisException(
                "Table 'mri_parameter_form' does not exist."
                . " Please have this instrument set up in"
                . " order to use this module properly."
            );
        }

        if ($DB->tableExists('radiology_review') === false) {
            throw new \LorisException(
                "Table 'radiology_review' does not exist."
                . " Please have this instrument set up in"
                . " order to use this module properly."
            );
        }

        # This fetches the commentID (if any) of the radiology review done at the
        # same visit at which the MRI parameter form with commentID orig.commentID
        # was done (see $query below)
        $radiologyReviewSubquery=
            "SELECT rr2.commentid
             FROM radiology_review rr2
             JOIN flag f2 USING(CommentID)
             JOIN session s2 ON(f2.sessionID=s2.ID)
             WHERE s2.candid=c.candid
             AND s2.ID=s.ID
             AND rr2.commentid NOT LIKE 'DDE_%'";

        # This fetches the commentID (if any) of the final radiological review done
        # at the same visit at which the radiology review found above was done.
        $frrSubquery=
            "SELECT frr2.commentid
             FROM final_radiological_review frr2
             JOIN flag f3 USING(CommentID)
             JOIN session s3 ON(f3.sessionID=s3.ID)
             WHERE s3.candid=c.candid
             AND s3.ID=s.ID
             AND frr2.commentid NOT LIKE 'DDE_%'";

        $this->query = " FROM mri_parameter_form mpf
            JOIN flag f ON (f.CommentID=mpf.CommentID)
            JOIN session s ON (s.ID=f.SessionID)
            JOIN candidate c ON (c.CandID=s.CandID)
            LEFT JOIN Project pjct ON (pjct.ProjectID=c.RegistrationProjectID)
            LEFT JOIN psc ON (c.RegistrationCenterID=psc.CenterID)
            LEFT JOIN radiology_review orig ON (orig.CommentID=($radiologyReviewSubquery))
            LEFT JOIN final_radiological_review r ON (r.CommentID=($frrSubquery))
            WHERE mpf.commentid NOT LIKE 'DDE_%' AND mpf.commentid IS NOT NULL
            AND s.active='Y'
            AND mpf.T1_Scan_Done IN ('Complete', 'Partial')";

        $isT1Acq = "CASE
           COALESCE((
                SELECT fi.FileID
                FROM files fi
                WHERE fi.SessionID=s.ID AND fi.AcquisitionProtocolID=44
                GROUP BY fi.SessionID, fi.FileID LIMIT 1),'')
            WHEN '' THEN 'No'
            ELSE 'Yes'
            END
            ";


        //mullen custom query count to set yes to the candidate across all other visits if V24 mullen admin is found yes for that candidate.
        $mullen_custom_query_count="(
                                     SELECT COUNT(*) from session
                                     JOIN flag ON(session.ID=flag.SessionID)
                                     WHERE session.CandID=s.CandID and flag.Test_name='mullen'
                                     AND flag.Administration!='None' and session.Visit_label='V24'
                                    )";

        //mullen administration code incorporation
        $mullen_query = "CASE
              COALESCE((
              SELECT fg.CommentID
              FROM flag fg
              WHERE fg.SessionID=s.ID AND fg.Test_name='mullen' AND fg.Administration!='None'
              GROUP BY fg.SessionID,fg.CommentID  LIMIT 1),'')
         WHEN  '' THEN   IF(s.Visit_label!='V24', 'NA', 'No')
         ELSE IF($mullen_custom_query_count>0, 'Yes', 'NA')
         END
         ";

        $this->columns = array(
                          'c.PSCID as PSCID',
                          'c.CandID as DCCID',
                          's.visit_label as Visit_Label',
                         );

            $this->columns[] = 'pjct.Name as Project';


        $this->columns = array_merge(
            $this->columns,
            array(
             'psc.Name as Site',
             'c.DOB as Birth_Date',
             'r.Review_Done as Review_Done',
             "$isT1Acq as T1_Inserted",
             'r.Final_Review_Results as Results',
             'r.Final_Exclusionary as Exclusionary_Status',
             'r.sas as SAS',
             'r.pvs as PVS',
             'orig.CommentID as CommentID',
             "$conflict_condition1 as Conflict",
             "$conflict_condition2 as Conflict2",
             'r.Finalized as Finalized',
             'r.Final_Incidental_Findings as Comments',
             's.ID as SessionID',
             's.CandID as CandID',
             "$mullen_query as V24_Mullen_Admin",
            )
        );

        $this->order_by = 'PSCID';
        $this->headers  = array(
                           'PSCID',
                           'DCCID',
                           'Visit_Label',
                          );

            $this->headers[] = 'Project';

        $this->headers = array_merge(
            $this->headers,
            array(
             'Site',
             'Birth_Date',
             'Review_Done',
             'T1_Inserted',
             'Results',
             'Exclusionary_Status',
             'SAS',
             'PVS',
             'CommentID',
             'Conflict',
             'Conflict2',
             'Finalized',
             'Comments',
             'SessionID',
             'CandID',
             'V24_Mullen_Admin'
            )
        );
        $this->tpl_data['hiddenHeaders']
            = json_encode(['CommentID', 'Conflict2', 'SessionID', 'CandID']);
        $this->validFilters = array(
                               'c.CandID',
                               'r.DICOM_ID',
                               's.visit_label',
                               'c.PSCID',
                               'r.Final_Review_Results',
                               "COALESCE(r.Review_Done, 'no')",
                               'r.sas',
                               'r.pvs',
                               'r.Final_Exclusionary',
                               $conflict_condition1,
                               $conflict_condition2,
                               "COALESCE(r.Finalized, 'no')",
                               'c.CenterID',
                               'c.RegistrationProjectID',
                               'keyword',
                               $mullen_query
                              );

        $this->EqualityFilters = array('r.Final_Exclusionary');
        $Review_Done           = "COALESCE(r.Review_Done, 'no')";
        $Finalized          = "COALESCE(r.Finalized, 'no')";
        $keyword            = 'r.Final_Incidental_Findings';
        $this->formToFilter = array(
                               'dccid'                => 'c.CandID',
                               'site'                 => 'c.CenterID',
                               'Visit_label'          => 's.visit_label',
                               'Project'              => 'c.RegistrationProjectID',
                               'pscid'                => 'c.PSCID',
                               'Review_Done'          => $Review_Done,
                               'Results'              => 'r.Final_Review_Results',
                               'Final_Review_Results' => 'r.Final_Review_Results',
                               'Exclusionary_Status'  => 'r.Final_Exclusionary',
                               'PVS'                  => 'r.pvs',
                               'SAS'                  => 'r.sas',
                               'Conflict'             => $conflict_condition1,
                               'Conflict2'            => $conflict_condition2,
                               'Finalized'            => $Finalized,
                               'keyword'              => $keyword,
                               'V24_Mullen_Admin'  => $mullen_query
                              );
        $this->searchKeyword = array('r.Final_Incidental_Findings');

        //DEPRECATION MESSAGE FOR 18.0
        error_log(
            "The Final Radiological Review Module is deprecated and will be "
            . "removed in a future release (Loris 18.0). Please update your code "
            . "in accordance. If you are actively using this module, "
            . "it should be moved to the `project/modules` directory."
        );
    }

    /**
     * Setup $this->tpl_data for use by Smarty
     *
     * @return void
     */
    function _setFilterForm()
    {
        $config      = \NDB_Config::singleton();


        $list_of_visit_labels = array(null => 'All' );
        $visitList            = \Utility::getVisitList();
        foreach ($visitList as $key=>$value) {
            $list_of_visit_labels[$key] = $value;
        }
        $list_of_sites = array(null => 'All');
        $sitesList     = \Utility::getSiteList(false);
        foreach ($sitesList as $key=>$value) {
            $list_of_sites[$key] = $value;
        }
        ksort($list_of_sites);
            $list_of_projects = array(null => 'All');
            $projectList      = \Utility::getProjectList();
            foreach ($projectList as $key => $value) {
                $list_of_projects[$key] =$value;
            }

        $options_boolean           = array(
                                      null  => 'All',
                                      'yes' => 'Yes',
                                      'no'  => 'No',
                                     );
        $options_boolean_finalized = array(
                                      null  => 'All',
                                      'yes' => 'Yes',
                                      'no'  => 'No',
                                     );
        $conflict_options1         = array(
                                      null    => 'All',
                                      'NA'    => 'NA',
                                      'true'  => 'Yes',
                                      'false' => 'No',
                                     );
        $conflict_options2         = array(
                                      null          => 'All',
                                      'NA'          => 'NA',
                                      'prim_second' => 'Yes',
                                      'false'       => 'No',
                                     );
        $comment_options           = array(
                                      null    => 'All',
                                      'True'  => 'Yes',
                                      'False' => 'No',
                                     );
        $bob_score         = array(
                              null => 'All',
                              '0'  => 'None',
                              '1'  => 'Minimal',
                              '2'  => 'Mild',
                              '3'  => 'Moderate',
                              '4'  => 'Marked',
                             );
        $abnormal_atypical = array(
                              null       => 'All',
                              'abnormal' => 'Abnormal',
                              'atypical' => 'Atypical',
                              'normal'   => 'Normal',
                             );
        $exclude           = array(
                              null               => 'All',
                              'exclusionary'     => 'Exclusionary',
                              'non_exclusionary' => 'Non Exclusionary',
                             );

        $this->addBasicText(
            'dicomid', 'DICOM ID:', array("size"=>9, "maxlength"=>20)
        );
        $this->addBasicText(
            'pscid',
            'PSCID:',
            array(
             "size"      => 9,
             "maxlength" => 11,
            )
        );
        $this->addBasicText(
            'dccid',
            'DCCID:',
            array(
             "size"      => 9,
             "maxlength" => 6,
            )
        );
        $this->addSelect('Visit_label', 'Visit Label:', $list_of_visit_labels);
        $this->addSelect('site', 'Site', $list_of_sites);
        $this->addSelect('Review_Done', 'Review Done:', $options_boolean);
        $this->addSelect(
            'Conflict',
            'Conflict between any reviews:',
            $conflict_options1
        );
        $this->addSelect(
            'Conflict2',
            'Conflict between final and extra reviews:',
            $conflict_options2
        );

        $this->addSelect('SAS', 'SAS (Subarachnoid Spaces):', $bob_score);
        $this->addSelect('PVS', 'PVS (Perivascular Spaces):', $bob_score);

        $this->addSelect('Final_Review_Results', 'Results', $abnormal_atypical);
        $this->addSelect('Exclusionary_Status', 'Exclusionary Status', $exclude);

        $this->addSelect('Finalized', 'Finalized', $options_boolean_finalized);

            $this->addSelect('Project', 'Project', $list_of_projects);

        $this->addBasicText(
            'keyword',
            'Search keyword in Comments',
            array(
             "size"      => 10,
             "maxlength" => 25,
            )
        );
        $mullen_options=array(null => 'All', 'Yes' => 'Yes', 'No' => 'No');
        $this->addSelect('V24_Mullen_Admin', 'V24 Mullen Admin:', $mullen_options);
    }

    /**
     * Include the column formatter required to display the feedback link colours
     * in the candidate_list menu
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
             $baseURL . "/final_radiological_review/js/columnFormatter.js",
            )
        );
    }
}
