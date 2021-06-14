<?php
declare(strict_types=1);
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
namespace LORIS\new_profile;

use \Psr\Http\Message\ServerRequestInterface;
use \Psr\Http\Message\ResponseInterface;

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
    public  $skipTemplate = true;
    private $_candID;
    private $_pscid;
    private $_error;

    /**
     * Tie the access to a data_entry permission
     *
     * @param \User $user The user whose access is being checked
     *
     * @return bool true if they have access to this page
     */
    // IBIS SPECIFIC OVERRIDE CODE
    // Not quite sure the reason behind this override.
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
    // IBIS SPECIFIC OVERRIDE CODE ENDS HERE

    /**
     * Processes the values and saves to database
     *
     * @param array $values form values
     *
     * @return void
     */
    // IBIS SPECIFIC OVERRIDE CODE
    // IBIS has a specific way of assigning candidate ids, overriding to
    // introduce that logic on creating a new candidate.
    function _process($values)
    {
        // print_r($values);
        // set up the arguments to Candidate::createNew
        $user   =& \User::singleton();
        $config =& \NDB_Config::singleton();
        $dob    = empty($values['dobDate']) ? null : $values['dobDate'];

        $edc = null;
        if ($config->getSetting('useEDC') == "true") {
            $edc = empty($values['edcDate']) ? null : $values['edcDate'];
        }

        // create the candidate
        $DB        = \Database::singleton();
        $site_arr  = $user->getData('CenterIDs');
        $num_sites = count($site_arr);

        $startNum = 0;
        if($values['project'] == 2) {
            $startNum = 1000;
        } elseif ($values['project'] == 5) {
            $startNum = 2000;
        } elseif ($values['project'] == 6) {
            $startNum = 3000;
        }elseif ($values['project'] == 9) {
            $startNum = 4000;
        }elseif ($values['project'] == 10) {
            $startNum = 6000;
        } elseif ($values['project'] == 8) {
            $startNum = 7000;
        }

        if ($num_sites >1) {
            $candID = \Candidate::createNew(
                (int)$values['site'],
                $dob,
                $edc,
                $values['sex'],
                $values['pscid'] ?? null,
                isset($values['project']) ? intval($values['project']) : null,
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
                $values['pscid'] ?? null,
                isset($values['project']) ? intval($values['project']) : null,
                $startNum
            );
        }

        // get the candidate
        $candidate =& \Candidate::singleton($candID);


        $db = \Database::singleton();
        if( $values['project'] == '2'){
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

        /**
         * Update front-end data. Use passed PSCID when present, otherwise
         * retrieve it from the newly-created candidate.
         */
        $this->_candID = (string) $candID;
        $this->_pscid  = $candidate->getPSCID();

        // freeze it, just in case
        $this->form->freeze();
    }
    // IBIS SPECIFIC OVERRIDE CODE ENDS HERE

    /**
     * This function will return a json file with DCCID and PSCID
     *
     * @param ServerRequestInterface $request The incoming PSR7 request
     *
     * @return ResponseInterface The outgoing PSR7 response
     */
    public function handle(ServerRequestInterface $request) : ResponseInterface
    {
        $this->setup();
        if ($request->getMethod() === "POST") {
            $this->save();
            if (!empty($this->_error)) {
                return new \LORIS\Http\Response\JSON\BadRequest($this->_error);
            }
            $result = array(
                'candID' => $this->_candID,
                'pscid'  => $this->_pscid,
            );
            return (new \LORIS\Http\Response\JSON\Created($result))
                ->withHeader("Allow", "POST");
        }

        return (new \LORIS\Http\Response())
            ->withBody(new \LORIS\Http\StringStream($this->display() ?? ""));
    }

    /**
     * Does the setup required for this page. By default, sets up elements
     * that are common to every type of page. May be overridden by a specific
     * page or specific page type.
     *
     * @return void
     */
    function setup(): void
    {
        $DB        = \Database::singleton();
        $config    = \NDB_Config::singleton();
        $user      = \User::singleton();
        $startYear = $config->getSetting('startYear');
        $endYear   = $config->getSetting('endYear');
        $ageMax    = $config->getSetting('ageMax');
        $ageMin    = $config->getSetting('ageMin');
        $dobFormat = $config->getSetting('dobFormat');
        $edc       = $config->getSetting('useEDC');
        $sex       = array(
            'male'   => 'Male',
            'female' => 'Female',
            'other'  => 'Other',
        );
        $pscidSet  = "false";
        $minYear   = (isset($startYear, $ageMax)) ? $startYear - $ageMax : null;
        $maxYear   = (isset($endYear, $ageMin)) ? $endYear - $ageMin : null;

        // Get sites for the select dropdown
        $user_list_of_sites = $user->getData('CenterIDs');
        $num_sites          = count($user_list_of_sites);
        $psc_labelOptions   = array();
        if ($num_sites > 1) {
            foreach ($user_list_of_sites as $siteID) {
                $center = $DB->pselectRow(
                    "SELECT CenterID as ID, Name FROM psc WHERE CenterID =:cid",
                    array('cid' => $siteID)
                );
                if (!is_null($center)) {
                    $psc_labelOptions[$siteID] = $center['Name'];
                }
            }
        }
        $site = $psc_labelOptions;

        // Get projects for the select dropdown
        $projList = array();
        $projects = \Utility::getProjectList();
        foreach ($projects as $projectID => $projectName) {
            $projList[$projectID] = $projectName;
        }
        $project = $projList ?? null;

        // Get setting through pscid
        $PSCIDsettings = $config->getSetting('PSCID');
        if ($PSCIDsettings['generation'] == 'user') {
            $pscidSet = "true";
        }

        $this->fieldOptions = array(
            'minYear'   => $minYear,
            'maxYear'   => $maxYear,
            'dobFormat' => $dobFormat,
            'edc'       => $edc,
            'sex'       => $sex,
            'pscidSet'  => $pscidSet,
            'site'      => $site,
            'project'   => $project,
            // IBIS SPECIFIC OVERRIDE CODE
            // Adding candidate plan options for IBIS2 project.
            'candidate_plan' => array(
                '3m_plan1' => '3m_plan1',
                '3m_plan2' => '3m_plan2',
                '3m_plan3' => '3m_plan3',
                '3m_plan4' => '3m_plan4',
                '6m_plan1' => '6m_plan1',
                '6m_plan2' => '6m_plan2',
                '6m_plan3' => '6m_plan3',
            ),
            // IBIS SPECIFIC OVERRIDE CODE ENDS HERE
        );

        $this->form->addFormRule(array(&$this, '_validateNewCandidate'));
    }

    /**
     * Validate function
     *
     * @param array $values the value
     *
     * @return array $errors
     */
    function _validateNewCandidate($values): array
    {
        $this->_error = null;
        $errors       = array();
        $config       = \NDB_Config::singleton();
        $user         = \User::singleton();
        $db           = \Database::singleton();

        // Validate DOB fields
        if (empty($values['dobDate'])) {
            $errors['dobDate'] = 'Date of Birth field is required.';
        }
        if (empty($values['dobDateConfirm'])) {
            $errors['dobDateConfirm'] = 'Confirm Date of Birth field is required.';
        }
        if ($values['dobDate'] != $values['dobDateConfirm']) {
            $errors['dobDate'] = 'Date of Birth fields must match.';
        }

        // Validate EDC fields
        if ($config->getSetting('useEDC') == "true") {
            if (empty($values['edcDate'])) {
                $errors['edcDate'] = 'Expected Date of Confinement field is
                                      required.';
            }

            if (empty($values['edcDateConfirm'])) {
                $errors['edcDateConfirm'] = 'Confirm EDC field is required.';
            }

            if ($values['edcDate'] != $values['edcDateConfirm']) {
                $errors['edDate'] = 'Expected Date of Confinement fields must
                                     match.';
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
            if (strlen($values['dobDate'] ?? '') < 10) {
                $errors['dobFormat'] = 'DOB is not in valid date format.';
            }
        }

        // Validate sex fields
        if (empty($values['sex'])) {
            $errors['sex'] = 'Sex is required.';
        }

        // Validate pscid
        $PSCIDsettings = $config->getSetting('PSCID');
        if ($PSCIDsettings['generation'] == 'user') {
            if (empty($values['site'])) { // user is in only one site
                $centerIDs = $user->getData('CenterIDs');
                $centerID  = $centerIDs[0];
                $site      =& \Site::singleton($centerID);
            } else {
                // user has multiple sites,
                // so validate PSCID against the Site selected
                $site =& \Site::singleton((int) $values['site']);
            }

            $project = \Project::getProjectFromID(intval($values['project']));

            if (empty($values['pscid'])) {
                $errors['pscid'] = 'PSCID must be specified';
            } elseif (!\Candidate::validatePSCID(
                $values['pscid'],
                $site->getSiteAlias(),
                $project->getAlias()
            )
            ) {
                $errors['pscid'] = 'PSCID does not match the required structure';
            } elseif ($db->pselectOne(
                "SELECT count(PSCID) FROM candidate WHERE PSCID=:V_PSCID",
                array('V_PSCID' => $values['pscid'])
            ) > 0
            ) {
                $errors['pscid'] = 'PSCID has already been registered';
            }
        }

        // Validate site entered
        $psc = isset($values['site']) ? (int)$values['site'] : '';
        $user_list_of_sites = $user->getData('CenterIDs');
        $num_sites          = count($user_list_of_sites);
        if ($num_sites > 1 && (empty($psc) || !$user->hasCenter($psc))) {
            $errors['site'] = "Site must be selected from the available dropdown.";
        }

        // Validate project
        if (empty($values['project'])) {
            $errors['project'] = "Project is required";
        }

        // IBIS SPECIFIC OVERRIDE CODE
        // Validate candidate plan property.
        if(empty($values['candidate_plan']) && $values['project'] == '2') {
            $errors['candidate_plan'] = 'Plan is required for IBIS2';
        }
        elseif(!empty($values['candidate_plan']) && $values['project'] != '2') {
            $errors['candidate_plan'] = 'Candidate Plan is not required for non-IBIS2 candidates';
        }
        // IBIS SPECIFIC OVERRIDE CODE ENDS HERE

        if (!empty($errors)) {
            $this->_error = reset($errors);
        }

        return $errors;
    }

    /**
     * Include additional JS files
     *
     * @return array of javascript to be inserted
     */
    function getJSDependencies(): array
    {
        $factory = \NDB_Factory::singleton();
        $baseURL = $factory->settings()->getBaseURL();
        $deps    = parent::getJSDependencies();
        return array_merge(
            $deps,
            [$baseURL . '/new_profile/js/NewProfileIndex.js']
        );
    }
}
