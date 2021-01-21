<?php
/**
 * This file implements the add_survey page which is used by the Loris
 * survey module, for creating user account/keys that are tied to a
 * CommentID and only valid for one use.
 *
 * PHP Version 5
 *
 * @category Survey
 * @package  Loris
 * @author   Dave MacFarlane <driusan@bic.mni.mcgill.ca>
 * @license  http://www.gnu.org/licenses/gpl-3.0.txt GPLv3
 * @link     https://www.github.com/aces/Loris/
 */
namespace LORIS\survey_accounts;
/**
 * The form which creates the add_survey page for the
 * Loris survey module
 *
 * @category Survey
 * @package  Loris
 * @author   Dave MacFarlane <driusan@bic.mni.mcgill.ca>
 * @license  http://www.gnu.org/licenses/gpl-3.0.txt GPLv3
 * @link     https://www.github.com/aces/Loris/
 */

class AddSurvey extends \NDB_Form
{


    /**
     * Determine whether the logged in user has access to this page.
     * Tied to data_entry
     *
     * @return boolean true if user has access to this page
     */
    function _hasAccess(\User $user) : bool
    {

        return $user->hasPermission('user_accounts');
    }

    /**
     * Return default values for QuickForm elements on this page
     *
     * @return associative array of FieldName => Default Value mapping
     */
    function _getDefaults()
    {
        $defaults = array();
        return $defaults;
    }

    /**
     * Validate that user data entered on the add survey page was correct
     *
     * @param array $values Array of values submitted on the page
     *
     * @return array Empty if no error, associative array of element with
     *               error if there was a problem with data entered.
     */
    function _validateAddSurvey($values)
    {
        $db = \Database::singleton();

        $numCandidates = $db->pselectOne(
            "SELECT COUNT(*) FROM candidate 
            WHERE PSCID=:v_PSCID 
            AND CandID=:v_CandID AND Active='Y'",
            array(
             'v_PSCID'  => $values['PSCID'],
             'v_CandID' => $values['CandID'],
            )
        );
        $error         = "PSCID and DCC ID do not match "
                ."or candidate does not exist.";
        if ($numCandidates != 1) {
            return
              array('CandID' => $error);
        }

        $numSessions = $db->pselectOne(
            "SELECT COUNT(*) FROM session 
            WHERE CandID=:v_CandID 
            AND UPPER(Visit_label)=UPPER(:v_VL) 
            AND Active='Y'",
            array(
             'v_CandID' => $values['CandID'],
             'v_VL'     => $values['VL'],
            )
        );

        if ($numSessions != 1) {
            return array(
                    'VL' => "Visit ".
                            $values['VL'].
                            " does not exist for given candidate",
                   );
        }

        $instrument_list = $db->pselect(
            "SELECT f.Test_name FROM flag f
             JOIN session s on s.ID = f.SessionID
             WHERE s.CandID=:v_CandID  
             AND UPPER(s.Visit_label)=UPPER(:v_VL) 
             AND s.Active='Y' and f.CommentID not like '%DDE%'",
            array(
             'v_CandID' => $values['CandID'],
             'v_VL'     => $values['VL'],
            )
        );
        $existing_instr='';
        foreach ($instrument_list as $instrument) {
                if(in_array($instrument['Test_name'], $values['Test_name'])){
                    $existing_instr.=$instrument['Test_name'].'<br>';
            }
        }
        if($existing_instr!='') {
            return array(
                'Test_name' => "These instrument(s) already exist for visit ". $values['VL'] .":<br>". $existing_instr
            );
        }

        if (!empty($values['Email']) ) {
            if (!filter_var($values['Email'], FILTER_VALIDATE_EMAIL) ) {
                return array('Email' => 'The email address is not valid.');
            }
        }
        if (!empty($values['Email']) && !empty($values['Email2'])) {
            if ($values['Email'] != $values['Email2']) {
                return array('Email2' => 'The email addresses do not match.');
            }
        }

        if (!empty($values['Email']) && empty($values['Email2'])) {
            return array('Email2' => 'Please confirm the email address.');
        }
        if (empty($values['Email']) ) {
                return array('Email' => 'Email is required.');
        }
        if (empty($values['Test_name'])) {
            return array('Test_name' => 'Please choose an instrument.');
        }
        if (in_array('', $values['Test_name'])) {
            return array('Test_name' => 'Please unselect the blank option in the instrument list.');
        }
        if ($_REQUEST['fire_away'] !== 'Create survey') {
            if (!filter_var(
                $values['Email'],
                FILTER_VALIDATE_EMAIL
            )
            ) {
                return array('Email' => 'Email is not valid.');

            }
        }
        return array();

    }

    /**
     * Process the form submission. Data has already been validated
     * when this is called, so we only need to handle insertion into
     * the database
     *
     * @param array $values The values submitted on the page
     *
     * @return none, but as a side-effect inserts into database
     */
    function _process($values)
    {
        $db        = \Database::singleton();
        $SessionID = $db->pselectOne(
            "SELECT ID FROM session".
            " WHERE CandID=:v_CandID AND Visit_label=:v_VL",
            array(
                'v_CandID' => $values['CandID'],
                'v_VL'     => $values['VL'],
            )
        );

        $timepoint =& \TimePoint::singleton($SessionID);
        $selected_instruments=$values['Test_name'];
        $url='';
        foreach ($selected_instruments as $instrument) {
            $db = \Database::singleton();
            $InstrumentExists = $db->pselectOne(
                "SELECT 'x' FROM participant_accounts
            WHERE Test_name=:TN AND SessionID=:SID",
                array(
                    'TN' => $instrument,
                    'SID' => $SessionID,
                )
            );
            if ($InstrumentExists == 'x') {
                return;
            }
            $battery = new \NDB_BVL_Battery();
            $battery->selectBattery($SessionID);

            $commentID = $battery->addInstrument($instrument);

            $key = $this->_generateSurveyKey();

            $email = false;
            if (isset($_REQUEST['send_email'])) {
                $email = true;
            }
            if ($email) {
                $status = 'Sent';
            } else {
                $status = 'Created';
            }

            try{
                $db->insert(
                    "participant_accounts",
                    array(
                        'SessionID' => $SessionID,
                        'Test_name' => $instrument,
                        'Email' => $values['Email'],
                        'Status' => $status,
                        'OneTimePassword' => $key,
                        'CommentID' => $commentID,
                    )
                );

            } catch(\DatabaseException $e) {
                error_log($e->getMessage());
                $this->tpl_data['success'] = false;
            }
            $this->tpl_data['success'] = true;



            $config = \NDB_Config::singleton();
            $www = $config->getSetting("www");

            if ($instrument == 'air_pollution' || $instrument == 'SA_Consent_Form' ||
                $instrument == 'NDAR_Consent_SA_Form' || $instrument == 'IBIS_SA_SLEEP_Consent_Form') {
                $url.= $www['url'] . '/survey.php?key=' .
                    urlencode($key) . "<\n>";
            } else {
                $url.= $www['url'] . '/survey_module/?key=' .
                    urlencode($key) . "\n";
            }
        }
        if ($values['Email'] != '') {
            $parentid = $this->getParentID($values['CandID']);
            $parent_portal_note = "\nYou can access all of your surveys on our Parent Portal.\nPlease note that to log into your Parent Portal, you will be asked for the Parent ID and Email, listed below. 
\n" . $www['url'] . "/parent_portal/
                ParentID:  $parentid
                Email: " . $values['Email'] . "\n\n You can also click the link below to access the survey(s) individually.\n";
            $urls= $parent_portal_note . $url;
        }
        else{
            $urls=$url;
        }

                $msg_data = array(
                    'study' => $config->getSetting("title"),
                    'url' => $urls,
                    'EmailForm' => $values['email_dialog'],
                );
            if ($email) {
                \Email::send($values['Email'], 'new_survey.tpl', $msg_data, "", "IBIS Team <noreply@ibis.loris.ca>");
            }

    }

    function getParentID($cnid)
    {
        $db        = \Database::singleton();
        $parentid = $db->pselectRow(
            "SELECT ParentID FROM candidate
            WHERE CandID=:cid",
            array(
                'cid'  => $cnid
            )
        );
        return $parentid['ParentID'];
    }

    /**
     * Generates a URL safe key
     *
     * @return string
     */
    function _generateSurveyKey()
    {
        $bytes = openssl_random_pseudo_bytes(8);
        return bin2hex($bytes);
    }

    /**
     * Does the setup required for this page. By default, sets up elements
     * that are common to every type of page. May be overridden by a specific
     * page or specific page type.
     *
     * @return none
     */
    function setup()
    {
        parent::setup();
        $this->_selectMultipleElements = array('Test_name');

        $this->redirect = "test_name=$this->name";
        $this->addBasicText("CandID", "DCCID");
        $this->addBasicText("PSCID", "PSCID");
        $this->addSelect("VL", "Visit Label", \Utility::getVisitList());
        $this->addSelect(
            "Test_name",
            "Instrument<BR><h5><i>(Cmd+Click or Ctrl+Click to select multiple options)</i></h5>",
            array_merge(
                array('' => ''),
                $this->getOrderedDirectInstruments()
            ),
            array("multiple")
        );
        $this->addBasicText("Email", "Email address");
        $this->addBasicText("Email2", "Confirm Email address");

        $this->form->addFormRule(array(&$this, '_validateAddSurvey'));
    }

    function getOrderedDirectInstruments()
    {
        $DB            =& \Database::singleton();
        $instruments   = array();
        $instruments_q = $DB->pselect(
            "SELECT Test_name,Full_name FROM test_names WHERE IsDirectEntry=true ORDER BY Full_name",
            array()
        );
        foreach ($instruments_q as $key) {
            $instruments[$key['Test_name']] =$key['Full_name'];
        }
        return $instruments;
    }

    /**
     * Gathers JS dependecies and merge them with the parent
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
             $baseURL . "/survey_accounts/js/survey_accounts_helper.js",
             $baseURL . "/survey_accounts/js/columnFormatter.js",
            )
        );
    }
}
?>
