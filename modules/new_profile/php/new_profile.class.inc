<?php
declare(strict_types=1);
/**
 * New_profile
 *
 * PHP Version 5
 *
 * @category Main
 * @package  Loris
 * @author   Shen Wang <shen.wang2@mcgill.ca>
 *           Zaliqa Rosli <zaliqa.rosli@mcin.ca>
 * @license  http://www.gnu.org/licenses/gpl-3.0.txt GPLv3
 * @link     https://github.com/aces/Loris
 */
namespace LORIS\new_profile;


/**
 * New_profile
 *
 * PHP Version 7
 *
 * @category Main
 * @package  Loris
 * @author   Shen Wang <shen.wang2@mcgill.ca>
 *           Zaliqa Rosli <zaliqa.rosli@mcin.ca>
 * @license  http://www.gnu.org/licenses/gpl-3.0.txt GPLv3
 * @link     https://github.com/aces/Loris
 */
class New_Profile extends \NDB_Form
{
    /**
     * Tie the access to a data_entry permission
     *
     * @return bool true if they have access to this page
     */
    function _hasAccess(\User $user) : bool
    {
        // create user object
        $user =& \User::singleton();

        $site_arr = $user->getData('CenterIDs');
        foreach ($site_arr as $key=>$val) {
            $site[$key]        = & \Site::singleton($val);
            $isStudySite[$key] = $site[$key]->isStudySite();
            $isDCCSite[$key]   = $site[$key]->getCenterName();
        }
        $oneIsStudySite = in_array("1", $isStudySite);
        $oneIsDCCSite   = in_array("DCC", $isDCCSite);
        if ($oneIsStudySite or $oneIsDCCSite) {
            return $user->hasPermission('data_entry');
        }
        return false;
    }
    /**
     * Processes the values and saves to database
     *
     * @param array $values form values
     *
     * @return void
     */
    function _process($values)
    {
        // print_r($values);
        // set up the arguments to Candidate::createNew
        $user   =& \User::singleton();
        $config =& \NDB_Config::singleton();
        $dob    = empty($values['dob1']) ? null : $values['dob1'];

        $edc = null;
        if ($config->getSetting('useEDC') == "true") {
            $edc = empty($values['edc1']) ? null : $values['edc1'];
        }

        // create the candidate
        $DB        = \Database::singleton();
        $site_arr  = $user->getData('CenterIDs');
        $num_sites = count($site_arr);

        $startNum = 0;
        if($values['ProjectID'] == 2) {
            $startNum = 1000;
        } elseif ($values['ProjectID'] == 5) {
            $startNum = 2000;
        } elseif ($values['ProjectID'] == 6) {
            $startNum = 3000;
        }elseif ($values['ProjectID'] == 9) {
            $startNum = 4000;
        }elseif ($values['ProjectID'] == 10) {
            $startNum = 6000;
        } elseif ($values['ProjectID'] == 8) {
            $startNum = 7000;
        }

        if ($num_sites >1) {
            $candID = \Candidate::createNew(
                (int)$values['psc'],
                $dob,
                $edc,
                $values['sex'],
                $values['PSCID'] ?? null,
                isset($values['ProjectID']) ? intval($values['ProjectID']) : null,
                $startNum
            );
        } else {
            $centerIDs = $user->getData('CenterIDs');
            $centerID  = $centerIDs[0];
            $candID    = \Candidate::createNew(
                $centerID,
                $dob,
                $edc,
                $values['sex'],
                $values['PSCID'] ?? null,
                isset($values['ProjectID']) ? intval($values['ProjectID']) : null,
                $startNum
            );
        }

        // get the candidate
        $candidate =& \Candidate::singleton($candID);


        $db = \Database::singleton();
        if( $values['ProjectID'] == '2'){
            $PTID = $db->pselectOne("SELECT ParameterTypeID FROM parameter_type WHERE Name='candidate_plan'", array());
            if(!is_numeric($PTID)) {
                throw new LorisException("Missing ParameterTypeID for candidate_plan");
            }
            $db->insert("parameter_candidate", array('ParameterTypeID' => $PTID,
                'CandID' => $candID,
                'Value' => $values['candidate_plan']
            ));
        }

        //------------------------------------------------------------

        $this->tpl_data['success'] = true;
        $this->tpl_data['candID']  = $candID;
        $this->tpl_data['PSCID']   = $candidate->getPSCID();

        // freeze it, just in case
        $this->form->freeze();
    }

    /**
     * Does the setup required for this page. By default, sets up elements
     * that are common to every type of page. May be overridden by a specific
     * page or specific page type.
     *
     * @return void
     */
    function setup()
    {
        parent::setup();

        $config    =& \NDB_Config::singleton();
        $startYear = $config->getSetting('startYear');
        $endYear   = $config->getSetting('endYear');
        $ageMax    = $config->getSetting('ageMax');
        $ageMin    = $config->getSetting('ageMin');
        $dobFormat = $config->getSetting('dobFormat');

        $dateOptions = array(
                        'language'       => 'en',
                        'format'         => $dobFormat,
                        'addEmptyOption' => true,
                        'minYear'        => $startYear - $ageMax,
                        'maxYear'        => $endYear - $ageMin,
                       );

        $dateAttributes = ['class' => 'form-control input-sm input-date'];

        // add date of birth
        $this->addBasicDate(
            'dob1',
            'Date of Birth',
            $dateOptions,
            $dateAttributes
        );
        $this->addBasicDate(
            'dob2',
            'Confirm Date of Birth',
            $dateOptions,
            $dateAttributes
        );
        $this->addRule(
            array(
             'dob1',
             'dob2',
            ),
            'Date of birth fields must match',
            'compare'
        );

        // date of birth rules
        $this->addRule('dob1', 'Date of Birth is required', 'required');
        $this->addRule(
            'dob2',
            'Date of Birth confirmation is required',
            'required'
        );

        if ($config->getSetting('useEDC') == "true") {
            // add expected date of confinement
            $this->addBasicDate(
                'edc1',
                'Expected Date of Confinement',
                $dateOptions,
                $dateAttributes
            );
            $this->addBasicDate(
                'edc2',
                'Confirm EDC',
                $dateOptions,
                $dateAttributes
            );

            // expected date of confinement rules
            $this->addRule(
                array(
                 'edc1',
                 'edc2',
                ),
                'EDC fields must match',
                'compare'
            );
        }


            $projects = \Utility::getProjectList();
            $projList = array('' => '');
            foreach ($projects as $projectID => $projectName) {
                $projList[$projectID] = $projectName;
            }
            $this->addSelect('ProjectID', 'Project', $projList);


        // add gender
        $sexOptions = array(
                          ''       => '',
                          'Male'   => 'Male',
                          'Female' => 'Female',
                         );
        $this->addSelect('sex', 'Sex', $sexOptions);

        // Sex rules
        $this->addRule('sex', 'Sex is required', 'required');
        $this->addSelect("candidate_plan", 'Candidate Plan',
            array(
                ''         => '',
                '3m_plan1' => '3m_plan1',
                '3m_plan2' => '3m_plan2',
                '3m_plan3' => '3m_plan3',
                '3m_plan4' => '3m_plan4',
                '6m_plan1' => '6m_plan1',
                '6m_plan2' => '6m_plan2',
                '6m_plan3' => '6m_plan3',
            )
        );

        // add sites for users with more than one site affiliation
        $user =& \User::singleton();
        $DB   = \Database::singleton();
        $user_list_of_sites = $user->getData('CenterIDs');
        $num_sites          = count($user_list_of_sites);

        if ($num_sites >1) {
            $psc_labelOptions = array(null => '');
            foreach ($user_list_of_sites as $key => $siteID) {
                $center = $DB->pselectRow(
                    "SELECT CenterID as ID, Name FROM psc WHERE CenterID =:cid",
                    array('cid' => $siteID)
                );
                $psc_labelOptions[$siteID] = $center['Name'];
            }
            $this->addSelect('psc', 'Site', $psc_labelOptions);

            // site rules
            $this->addRule('psc', 'Site is required', 'required');
        }

        $PSCIDsettings = $config->getSetting('PSCID');
        if ($PSCIDsettings['generation'] == 'user') {
            $this->addBasicText('PSCID', 'PSCID');
        }

        $this->form->addFormRule(array(&$this, '_validate'));
    }
    /**
     * Validate function
     *
     * @param array $values the value
     *
     * @return string
     */
    function _validate($values)
    {
        $errors = array();
        $config =& \NDB_Config::singleton();

        if ($values['dob1'] != $values['dob2']) {
            $errors['dob1'] = 'Date of Birth fields must match.';
        }

        if ($config->getSetting('useEDC') == "true") {
            if (empty($values['edc1'])) {
                $errors['edc1'] = 'Expected Date of Confinement field is required';
            }

            if (empty($values['edc2'])) {
                $errors['edc2'] = 'Confirm EDC field is required';
            }

            if ($values['edc1'] != $values['edc2']) {
                $errors['edc1'] = 'Estimated Due date fields must match.';
            }
        }
        // Validate date format
        $dobFormat = $config->getSetting('dobFormat');
        if (strtolower($dobFormat) == 'ym' || strtolower($dobFormat) == 'my') {
            // Dates still need to be submitted into the database in format
            // YYYY-DD-MM. This is a last check before _process is called.
            if ($config->getSetting('useEDC') == "true"
                && strlen($values['edcDate']) < 10
            ) {
                $errors['edcFormat'] = 'EDC is not in valid date format.';
            }
            if (strlen($values['dobDate']) < 10) {
                $errors['dobFormat'] = 'DOB is not in valid date format.';
            }
        }

        if (empty($values['sex'])) {
            $errors['sex'] = 'Gender is required.';
        }

        $PSCIDsettings = $config->getSetting('PSCID');
        if ($PSCIDsettings['generation'] == 'user') {
            $db =& \Database::singleton();
            if (empty($values['psc'])) { // user is in only one site
                $user      =& \User::singleton();
                $centerIDs = $user->getData('CenterIDs');
                $centerID  = $centerIDs[0];
                $site      =& \Site::singleton($centerID);
            } else {
                // user has multiple sites,
                // so validate PSCID against the Site selected
                $site =& \Site::singleton($values['psc']);
            }

            if (empty($values['PSCID'])) {
                $errors['PSCID'] = 'PSCID must be specified';
            } elseif (!\Candidate::validatePSCID(
                $values['PSCID'],
                $site->getSiteAlias()
            )
            ) {
                $errors['PSCID'] = 'PSCID does not match the required structure';
            } elseif ($db->pselectOne(
                "SELECT count(PSCID) FROM candidate WHERE PSCID=:V_PSCID",
                array('V_PSCID' => $values['PSCID'])
            ) > 0
            ) {
                    $errors['PSCID'] = 'PSCID has already been registered';
            }
        }

        if (empty($values['ProjectID'])) {
            $errors['ProjectID'] = "Project is required";
        }

        if(empty($values['candidate_plan']) && $values['ProjectID'] == '2') {
            $errors['candidate_plan'] = 'Plan is required for IBIS2';
        }
        elseif(!empty($values['candidate_plan']) && $values['ProjectID'] != '2') {
            $errors['candidate_plan'] = 'Candidate Plan is not required for non-IBIS2 candidates';
        }

        return $errors;
    }
}
?>
