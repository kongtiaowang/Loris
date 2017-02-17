<?php
/**
 * OVERWRITTEN SO ADD IBIS2 PLAN SUPPORT AND CHANGE PSCID
 * START NUMBER FOR IBIS2
 */
require_once "NDB_Form.class.inc";

/**
 * The forms for the new profile menu
 * @package main
 */
class NDB_Form_new_profile extends NDB_Form
{
    function _hasAccess()
    {
        // create user object
        $user =& User::singleton();

        $site =& Site::singleton($user->getData('CenterID'));

        if ($site->isStudySite() or ($site->getCenterName() == "DCC")) {
            return $user->hasPermission('data_entry');
        }

        return false;
    }

    function _process($values)
    {
        // set up the arguments to Candidate::createNew
        $user =& User::singleton();
        $config =& NDB_Config::singleton();
        $dob = empty($values['dob1']) ? null : $values['dob1'];

        if($config->getSetting('useEDC') == "true"){
            $edc = empty($values['edc1']) ? null : $values['edc1'];
        }

        // create the candidate
        $startNum = 0;
        if($values['ProjectID'] == 2) {
            $startNum = 1000;
        } elseif ($values['ProjectID'] == 5) {
            $startNum = 2000;
        }

        $candID = Candidate::createNew($user->getData('CenterID'), $dob, $edc, $values['gender'], $values['PSCID']);

        // get the candidate
        $candidate =& Candidate::singleton($candID);

        if($config->getSetting('useProjects') == "true") {
            $candidate->setData('ProjectID', $values['ProjectID']);

        }

        $db = Database::singleton();
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
        $this->tpl_data['candID'] = $candID;
        $this->tpl_data['PSCID'] = $candidate->getPSCID();

        // freeze it, just in case
        $this->form->freeze();
    }

    function new_profile()
    {
        $config =& NDB_Config::singleton();
        $study = $config->getSetting('study');

        $dateOptions = array(
            'language'        => 'en',
            'format'          => 'YMd',
            'addEmptyOption'  => true,
            'minYear'         => $study['startYear'] - $study['ageMax'],
            'maxYear'         => $study['endYear'] - $study['ageMin']
        );

        $dateAttributes = ['class' => 'form-control input-sm input-date'];

        // add date of birth
        $this->addBasicDate('dob1', 'Date of Birth', $dateOptions, $dateAttributes);
        $this->addBasicDate('dob2', 'Confirm Date of Birth', $dateOptions, $dateAttributes);
        $this->addRule(array('dob1', 'dob2'), 'Date of birth fields must match', 'compare');


        // date of birth rules
        $this->addRule('dob1', 'Date of Birth is required', 'required');
        $this->addRule('dob2', 'Date of Birth confirmation is required', 'required');

        if($config->getSetting('useEDC') == "true"){
            // add expected date of confinement
            $this->addBasicDate('edc1', 'Expected Date of Confinement', $dateOptions, $dateAttributes);
            $this->addBasicDate('edc2', 'Confirm EDC', $dateOptions, $dateAttributes);

            // expected date of confinement rules
            $this->addRule(array('edc1', 'edc2'), 'EDC fields must match', 'compare');
        }

        if($config->getSetting("useProjects") == "true") {
            $projects = Utility::getProjectList();
            $projList = array('' => '');
            foreach($projects as $projectID => $projectName) {
                $projList[$projectID] = $projectName;
            }
            $this->addSelect('ProjectID', 'Project', $projList);
        }

        // add gender
        $genderOptions = array('' => '', 'Male' => 'Male', 'Female' => 'Female');
        $this->addSelect('gender', 'Gender', $genderOptions);

        // gender rules
        $this->addRule('gender', 'Gender is required', 'required');
        $this->addSelect("candidate_plan", 'Candidate Plan',
            array(
                ''         => '',
                '3m_plan1' => '3m_plan1',
                '3m_plan2' => '3m_plan2',
                '3m_plan3' => '3m_plan3',
                '3m_plan4' => '3m_plan4',
                '6m_plan1' => '6m_plan1',
                '6m_plan2' => '6m_plan2',
                '6m_plan3' => '6m_plan3'
            )
        );
        $PSCIDsettings = $config->getSetting('PSCID');
        if($PSCIDsettings['generation'] == 'user') {
            $this->addBasicText('PSCID', 'PSCID');
        }

        $this->form->addFormRule(array(&$this, '_validate'));
    }

    function _validate($values)
    {
        $errors = array();

        $config =& NDB_Config::singleton();

        if($values['dob1'] != $values['dob2'])
        {
            $errors['dob1'] = 'Date of Birth fields must match.';
        }
        if($config->getSetting('useEDC') == "true") {
            if (strlen(implode($values['edc1'])) > 2 && !Utility::_checkDate($values['edc1'])) {
                $errors['edc1'] = 'EDC is not a valid date';
            }
            if($values['edc1'] != $values['edc2'])
            {
                $errors['edc1'] = 'Estimated Due date fields must match.';
            }
        }

        if (empty($values['gender'])) {
            $errors['gender'] = 'Gender is required.';
        }

        $PSCIDsettings = $config->getSetting('PSCID');
        if($PSCIDsettings['generation'] == 'user') {
            $db =& Database::singleton();
            $user =& User::singleton();
            $centerID = $user->getData('CenterID');
            $site =& Site::singleton($centerID);

            if(empty($values['PSCID'])) {
                $errors['PSCID'] = 'PSCID must be specified';
            } elseif(!Candidate::validatePSCID($values['PSCID'], $site->getSiteAlias())) {
                $errors['PSCID'] = 'PSCID does not match the required structure';
            } elseif($db->pselectOne("SELECT count(PSCID) FROM candidate WHERE PSCID=:V_PSCID",
                array('V_PSCID' => $values[PSCID])) > 0
            ) {
                    $errors['PSCID'] = 'PSCID has already been registered';
            }
        }
        $useProjects = $config->getSetting('useProjects');
        if($useProjects === "true" && empty($values['ProjectID'])) {
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
