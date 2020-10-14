<?php
/*
 * This file contains the NDB_BVL_Instrument_mock_scanner_training_form
 * class
 *
 * PHP Version 7
 *
 * @category Instrument
 * @package  Neuropsych
 * @author   Sruthy Mathew <sruthy.mathew@mcgill.ca>
 * @license  http://www.gnu.org/licenses/gpl-3.0.txt GPLv3
 * @link     https://www.github.com/aces/IBIS/
 */

/**
 * Creates the form elements for the IPSC_tracking_form instrument
 *
 * @category Instrument
 * @package  Neuropsych
 * @author   Sruthy Mathew <sruthy.mathew@mcgill.ca>
 * @license  http://www.gnu.org/licenses/gpl-3.0.txt GPLv3
 * @link     https://www.github.com/aces/IBIS/
 */


class NDB_BVL_Instrument_IPSC_tracking_form extends NDB_BVL_Instrument
{
    use LegacyInstrumentTrait;

    var $ValidityEnabled = false;
    var $ValidityRequired = false;

    /**
     * sets up basic data, such as the LorisForm object, and so on.
     *
     * @param string $commentID the CommentID identifying the data to load
     * @param string $page if a multipage form, the page to show
     * @return void
     * @access public
     */
    function setup(?string $commentID = NULL, ?string $page = NULL): void
    {
        $this->formType = "XIN";
        $this->form = new LorisForm('test_form');
        $this->page = $page;

        // set the object properties
        $this->testName = "IPSC_tracking_form";           // test_names.Test_name
        $this->table = 'IPSC_tracking_form';             // name of table containing

        // data keyed by commentID
        $this->commentID = $commentID;

        $config = NDB_Config::singleton();
        $this->dateOptions = array(
            'language' => 'en',
            'format' => 'YMd',
            'minYear' => $config->getSetting('startYear'),
            'maxYear' => $config->getSetting('endYear'),
            'addEmptyOption' => true,
            'emptyOptionValue' => null,
        );

        // setup the form
        $this->_setupForm();
    }

    /**
     * Method to build the LorisForm object into a paged form
     *
     * @return void
     * @access private
     */
    function _setupForm()
    {
        //determine page to display
        if (preg_match(
            "/IPSC_tracking_form(_page[0-9]+)/",
            $this->page,
            $matches
        )) {
            call_user_func(array($this, $matches[1]));
        } else {
            $this->_main();
        }
    }

    function _main()
    {
        // automatically adds examiner & date of administration
        $this->_addMetadataFields();
        $this->addSelect(
            "recruiter_asked_blood_draw",
            '1. Did the recruiter ask about blood draw?',
            array('yes' => 'Yes', 'not_yet_asked' => 'Not yet asked')
        );

        $this->addSelect(
            "did_family_agree_to_project",
            '2. Did family agree to the project?',
            array('yes' => 'Yes', 'no' => 'No')
        );

        $this->addBasicDate('IPSC_consent_date', '3. Consent date', $this->dateOptions);

        $this->addSelect(
            "blood_draw_location",
            '4. Blood draw location',
            array(NULL => '', 'site' => 'SITE', 'take_home_kit_sent' => 'TAKE HOME KIT SENT ')
        );

        $this->addBasicTextArea("fedex_tracking_number", "5. Fedex tracking number of the return label");

        $this->addSelect(
            "was_the_blood_draw_successful",
            '6. Was the blood draw successful?',
            array('yes' => 'Yes', 'no' => 'No')
        );

        $this->addBasicDate('blood_draw_date', '7. Blood draw date', $this->dateOptions);

        $this->addBasicTextArea("ipsc_notes", "Notes:");

        $this->form->addFormRule(array(&$this, 'IPSC_Rules'));
    }

    function IPSC_Rules($values)
    {
        $errors = array();

        if ($values['blood_draw_location'] != NULL && $values['blood_draw_date'] == NULL) {
            $errors['blood_draw_date'] = "Please enter the Blood Draw Date as you have entered the Blood Draw Location";
        }

        if ($values['blood_draw_location'] == NULL && $values['blood_draw_date'] != NULL) {
            $errors['blood_draw_location'] = "Please enter the Blood Draw Location as you have entered the Blood Draw Date";
        }

        return $errors;
    }

    // This function is overridden here to send the email notifications if blood draw date is set.
    function _save(array $values): void
    {
        // clear any fields starting with __
        foreach (array_keys($values) AS $key) {
            if (strpos($key, '__') === 0) {
                unset($values[$key]);
            }
            $values = Utility::nullifyEmpty($values, $key);
        }

        $db =& Database::singleton();
        $candidate = Candidate::singleton($this->commentID);
        $PSCID = $candidate-> getPSCID();
        $centerID = $candidate->getData('RegistrationCenterID');

        if ($values['blood_draw_date'] != NULL && $values['blood_draw_date'] != '') {
            $blood_draw_date=date_create($values['blood_draw_date']);

            if($centerID==1)
            {
                $notification_reciever_email='sruthy.mcin@gmail.com,sruthymathew369@gmail.com';
            } else {
                $notification_reciever_email='roseg@email.unc.edu,jason_stein@med.unc.edu,abeltran@email.unc.edu';
            }

            $msg_data['PSCID'] = $PSCID;
            $msg_data['blood_draw_date'] = date_format($blood_draw_date,"F d, Y");
            $old_blood_draw_date = $db->pselectOne(
                "SELECT blood_draw_date FROM IPSC_tracking_form WHERE CommentID=:cid",
                array('cid' => $this->getCommentID())
            );

            if($values['blood_draw_date']!=$old_blood_draw_date) {
                Email::send($notification_reciever_email, 'IPSC_tracking_blood_draw_notification.tpl', $msg_data, "", "IBIS Team <noreply@ibis.loris.ca>");
            }
        }

        $result = $db->update(
            $this->table,
            $values,
            array('CommentID' => $this->getCommentID())
        );

        // Extract the old data and merge it with what was submitted so that we
        // don't overwrite data from other pages.
        $oldData = $db->pselectOne(
            "SELECT Data FROM flag WHERE CommentID=:cid",
            array('cid' => $this->getCommentID())
        );

        // (The PDO driver seems to return null as "null" for JSON column types)
        if (!empty($oldData) && $oldData !== "null") {
            $oldData = json_decode($oldData, true);
        } else {
            $oldData = array();
        }
        $newData = array_merge($oldData, $values);

        // Save the JSON to the flag.Data column.
        //
        // json_encode ensures that this is safe. If we use the safe wrapper,
        // HTML encoding the quotation marks will make it invalid JSON.
        $result = $db->unsafeUpdate(
            "flag",
            array("Data" => json_encode($newData)),
            array('CommentID' => $this->getCommentID())
        );
    }
}
?>