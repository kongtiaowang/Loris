<?php
/**
 * This file contains the NDB_BVL_Instrument_Visit_Level_Information_DS_Infant class
 *
 * PHP Version 7
 *
 * @category Instrument
 * @package  IBIS
 * @author   Suzanne Lee <suzannelee.mcin@gmail.com>
 * @license  http://www.gnu.org/licenses/gpl-3.0.txt GPLv3
 * @link     https://www.github.com/aces/IBIS/
 */

 /**
 * Creates the form elements for the Visit Level Information - DS-Infant
 *
 * @category Instrument
 * @package  Neuropsych
 * @author   Suzanne Lee <suzannelee.mcin@gmail.com>
 * @license  http://www.gnu.org/licenses/gpl-3.0.txt GPLv3
 * @link     https://www.github.com/aces/IBIS/
 */
class NDB_BVL_Instrument_Visit_Level_Information_DS_Infant extends NDB_BVL_Instrument
{
    use LegacyInstrumentTrait;
    use instrument_validator;

    var $ValidityEnabled  = false;
    var $ValidityRequired = false;

    /**
     * Sample SQL statement for test_names table and instrument subtests table
     *
     * INSERT INTO test_names (Test_name, Full_name, Sub_Group, isDirectEntry) VALUES ('Visit_Level_Information_DS_Infant', "Visit Level Information - DS-Infant", 1, 0);
     * INSERT INTO instrument_subtests (Test_name, Subtest_name, Description, Order_number) VALUES ('Visit_Level_Information_DS_Infant','Visit_Level_Information_DS_Infant_page1', "Page 1", 1);
     */

    /**
     * Sets up basic data, such as the LorisForm object, and so on.
     *
     * @param string $commentID the CommentID identifying the data to load
     * @param string $page      if a multipage form, the page to show
     *
     * @return void
     * @access public
     */
    function setup(?string $commentID = null, ?string $page = null): void
    {
        $this->formType = "XIN";
        $this->form     = new LorisForm('Visit_Level_Information_DS_Infant_form');
        $this->page     = $page;            // page label (number or
        // string - used by
        // user-defined child classes)

        // set the object properties
        $this->testName = "Visit_Level_Information_DS_Infant"; // test_names.Test_name
        $this->table    = 'Visit_Level_Information_DS_Infant'; // name of database table corresponding to instrument
        // data keyed by commentID
        $this->commentID = $commentID;

        //The array of dates/timestamps to convert to database dates/timestamps
        //Any LorisForm date elements must be listed here
        $this->dateTimeFields =array("Date_taken");

        //The array of selects with multiple answers allowed
        //Any LorisForm multiple selects must be listed here
        $this->_selectMultipleElements = array(
                                          "q4_if_yes_when",

                                          "bayley_assessor_ppe",
                                          "ados_2_assessor_ppe",
                                          "aosi_assessor_ppe",
                                          "csbs_assessor_ppe",
                                          "escs_assessor_ppe",
                                          "vineland_3_assessor_ppe",
                                          "mri_scan_1_assessor_ppe",
                                          "mri_scan_2nd_attempt_assessor_ppe",

                                          "bayley_subject_ppe",
                                          "ados_2_subject_ppe",
                                          "aosi_subject_ppe",
                                          "csbs_subject_ppe",
                                          "escs_subject_ppe",
                                          "vineland_3_subject_ppe",
                                          "mri_scan_1_subject_ppe",
                                          "mri_scan_2nd_attempt_subject_ppe",

                                          "bayley_parent_ppe",
                                          "ados_2_parent_ppe",
                                          "aosi_parent_ppe",
                                          "csbs_parent_ppe",
                                          "escs_parent_ppe",
                                          "vineland_3_parent_ppe",
                                          "mri_scan_1_parent_ppe",
                                          "mri_scan_2nd_attempt_parent_ppe",
                                         );

        // required fields for data entry completion status
        $this->_requiredElements = array("q1_visit");

        // setup the form
        $this->_setupForm();
    }

    //If the instrument is not paged, remove the switch from the _setupForm method and add all the form Elements in this function.

    /**
    * Method to build the LorisForm object into a paged form
    *
    * @return void
    * @access private
    */
    function _setupForm()
    {
        if (preg_match("/Visit_Level_Information_DS_Infant(_page[0-9]+)/", $this->page, $matches)) {
            call_user_func(array($this, $matches[1]));
        } else {
            $this->_main();
        }

        //Defines the call back function for HTML Quickform to use when validating the form.
        $this->form->addFormRule(array(&$this, 'XINValidate'));
    }

    /**
    * Generates the main page of the form.
    *
    * @return void
    * @access private
    */
    function _main()
    {
        // display test name
        $this->addHeader("VISIT LEVEL CVD INFORMATION FORM: Infant (DS)");

        // automatically adds examiner & date of administration
        $this->_addMetadataFields();

        $config      =& NDB_Config::singleton();
        $dateOptions = array(
                        'language'         => 'en',
                        'format'           => 'YMd',
                        'minYear'          => $config->getSetting('startYear'),
                        'maxYear'          => $config->getSetting('endYear'),
                        'addEmptyOption'   => true,
                        'emptyOptionValue' => null,
                       );
    }

    /**
     * Page 1
     *
     * @return void
     */
    function _page1()
    {
        $this->addHeader("VISIT LEVEL CVD INFORMATION FORM: Infant (DS)");

        $q1_options = array(
                       null                             => "",
                       "a_in_person_not_during_COVID"   => "a) An in person visit that did not occur during COVID",
                       "b_in_person_during_COVID"       => "b) An in person visit that occurred during COVID",
                       "c_remote_during_COVID"          => "c) A remote visit that occurred during COVID",
                       "d_remote_outside_COVID"         => "d) A remote visit that happened outside of COVID",
                       "e_combination_remote_in_person" => "e) Combination of both remote and in person",
                      );

        $q2_options = array(
                       null  => "",
                       "yes" => "Yes",
                       "no"  => "No",
                      );
        /*
        $q3_options = array(
                       null                             => "",
                       "a_successful_scan_done_already" => "a) Have a successful scan done already",
                       "b_attempt_at_scan_unsuccessful" => "b) Have an attempt at a scan that was unsuccessful",
                       "c_scan_scheduled_not_done_yet"  => "c) A scan is scheduled but not yet done (on the day of the bx visit)",
                       "d_will_likely_not_get_scanned"  => "d) The subject will likely not get scanned",
                      );*/

        $q4_options = array(
                       null  => "",
                       "yes" => "Yes",
                       "no"  => "No",
                      );

        $q4_if_yes_options = array(
                              "i_1_week_before_visit"    => "i) 1 week before the visit",
                              "ii_24_hours_before_visit" => "ii) 24 hours before the visit",
                              "iii_day_of_visit"         => "iii) Day of visit",
                             );

        $q5_options = array(
                       null          => "",
                       "yes"         => "Yes",
                       "no"          => "No",
                       "i_dont_know" => "I don't know",
                      );

        $q6_options = array(
                       null     => "",
                       "yes"    => "Yes",
                       "no"     => "No",
                       "unsure" => "Unsure",
                      );

        $q8_options = array(
                       null  => "",
                       "yes" => "Yes",
                       "no"  => "No",
                      );

        $this->addSelect("q1_visit", "1. Was this: ", $q1_options);

        $this->addSelect("q2_ppe_used", "2. Was PPE Used at any time during the assessment?", $q2_options);

        // Question 3 omitted

        $this->addSelect("q4_family_asked_questionnaire", "4. Was family asked the COVID screening questions?", $q4_options);

        $this->addSelect(
            "q4_if_yes_when",
            $this->indent . "If yes, when (check all that apply):",
            $q4_if_yes_options,
            array("multiple")
        );
        $this->XINRegisterRule(
            "q4_if_yes_when",
            array("q4_if_yes_when{@}=={@}NEVER_REQUIRED"),
            "Never required."
        );

        $this->addSelect("q5_had_covid", "5. To your knowledge has anyone in the family or the subject ever had COVID?", $q5_options);

        $this->form->addElement('text', "q5_i_if_yes_who", $this->indent . "i) If yes, who (indicate subject or relation to subject)");
        $this->XINRegisterRule("q5_i_if_yes_who", array("q5_had_covid{@}=={@}yes"), 'Required if yes');

        $this->form->addElement('text', "q5_ii_if_yes_when", $this->indent . "ii) If yes, when");
        $this->XINRegisterRule("q5_ii_if_yes_when", array("q5_had_covid{@}=={@}yes"), 'Required if yes');

        $this->addSelect("q6_tolerate_mask_well", "6. If the subject wore a mask, did they tolerate it well?", $q6_options);

        $this->addTextAreaElement("q7_additional_notes_about_visit", "7. Additional notes about this visit:");

        $this->addSelect("q8_ppe_used", "8. Was PPE used?<h6><i>If yes fill out the questions below</i></h6>", $q8_options);

        $this->form->addElement('static', null, null);

        $this->form->addElement('static', null, '<h3><b>PPE Tracking</b></h3>');

        $interviews_direct_assessments = array(
                                          "bayley"               => "Bayley (3 or 4)",
                                          "ados_2"               => "ADOS-2",
                                          "aosi"                 => "AOSI",
                                          "csbs"                 => "CSBS",
                                          "escs"                 => "ESCS",
                                          "vineland_3"           => "Vineland 3",
                                          "mri_scan_1"           => "MRI Scan 1",
                                          "mri_scan_2nd_attempt" => "MRI Scan 2nd Attempt",
                                         );

        $yes_no_options = array(
                           null  => "",
                           "yes" => "Yes",
                           "no"  => "No",
                          );

        $autofill = array("in_person" => "In person");

        $method_of_collection_options = array(
                                         null        => "",
                                         "phone"     => "Phone",
                                         "in_person" => "In person",
                                         "email"     => "Email",
                                        );

        $assessor_ppe = array(
                         null          => "",
                         "no_ppe"      => "No PPE",
                         "capr"        => "CAPR",
                         "opaque_mask" => "Opaque mask",
                         "clear_mask"  => "Clear mask",
                         "face_shield" => "Face shield",
                         "goggles"     => "Goggles",
                         "gloves"      => "Gloves",
                         "scrubs"      => "Scrubs",
                         "other"       => "Other",
                        );

        $subject_ppe = array(
                        null          => "",
                        "no_ppe"      => "No PPE",
                        "opaque_mask" => "Opaque mask",
                        "clear_mask"  => "Clear mask",
                        "face_shield" => "Face shield",
                        "goggles"     => "Goggles",
                        "gloves"      => "Gloves",
                       );

        $parent_ppe = array(
                       null                 => "",
                       "parent_not_in_room" => "Parent not in room",
                       "no_ppe"             => "No PPE",
                       "opaque_mask"        => "Opaque mask",
                       "clear_mask"         => "Clear mask",
                       "face_shield"        => "Face shield",
                       "goggles"            => "Goggles",
                       "gloves"             => "Gloves",
                      );

        foreach ($interviews_direct_assessments as $key => $value) {
            $this->form->addElement('static', null, "<h4><u>" . $value . "</u></h4>");
            $this->addSelect($key . "_was_collected", $this->indent . "Was this instrument collected", $yes_no_options);
            $this->XINRegisterRule($key . "_was_collected", array("q8_ppe_used{@}=={@}yes"), 'Required if Question 8 is answered yes');

            if ($key == "vineland_3") {
                $this->addSelect($key . "_method_of_collection", $this->indent . "Method of Collection", $method_of_collection_options);
                $this->XINRegisterRule($key . "_method_of_collection", array("{$key}_was_collected{@}=={@}yes"), 'Required if yes');
            } else {
                $this->addSelect($key . "_method_of_collection", $this->indent . "Method of Collection", $autofill);
            }

            $this->addSelect($key . "_assessor_ppe", $this->indent . "Assessor PPE", $assessor_ppe, array("multiple"));
            $this->XINRegisterRule($key . "_assessor_ppe", array("{$key}_was_collected{@}=={@}yes", "{$key}_method_of_collection{@}=={@}in_person"), 'Required if instrument was collected in person');

            $this->form->addElement('text', $key . "_assessor_ppe_if_other", $this->indent . $this->indent . "If Other:");
            $this->XINRegisterRule($key . "_assessor_ppe_if_other", array("{$key}_assessor_ppe{@}=={@}other"), 'Required if other');

            $this->addSelect($key . "_subject_ppe", $this->indent . "Subject PPE", $subject_ppe, array("multiple"));
            $this->XINRegisterRule($key . "_subject_ppe", array("{$key}_was_collected{@}=={@}yes", "{$key}_method_of_collection{@}=={@}in_person"), 'Required if instrument was collected in person');

            $this->addTextAreaElement($key . "_room_modifications", $this->indent . "List any room modifications (such as a Plexiglass shield, dirty bin, open window, etc.)");

                $this->XINRegisterRule(
                    $key . "_room_modifications",
                    array("{$key}_room_modifications{@}=={@}NEVER_REQUIRED"),
                    "Never required."
                );

            $this->addSelect($key . "_parent_ppe", $this->indent . "Parent PPE", $parent_ppe, array("multiple"));

            $this->XINRegisterRule(
                $key . "_parent_ppe",
                array("{$key}_parent_ppe{@}=={@}NEVER_REQUIRED"),
                "Never required."
            );

            $this->addTextAreaElement($key . "_notes", $this->indent . "Notes on this instrument:");

            $this->XINRegisterRule(
                $key . "_notes",
                array("{$key}_notes{@}=={@}NEVER_REQUIRED"),
                "Never required."
            );

            $this->form->addElement('static', null, null);
        }

        $this->form->addFormRule(array(&$this, 'validate_page1'));
    }

    function validate_page1($values)
    {
        $errors = [];

        if ($values["q5_had_covid"] == "no") {
            $this->validate_empty_subquestions($values, ["q5_i_if_yes_who"], $errors);
            $this->validate_empty_subquestions($values, ["q5_ii_if_yes_when"], $errors);
        }
        $err_msg = "Not required if instrument was not collected in person.";
        if ($values['vineland_3_method_of_collection'] != "in_person" && 
            $values['vineland_3_was_collected'] == 'yes'
            ){
            if ($values['vineland_3_assessor_ppe'][0] != null) {
             $errors['vineland_3_assessor_ppe'] = $err_msg;
            }
            if ($values['vineland_3_subject_ppe'][0] != null) {
             $errors['vineland_3_subject_ppe'] = $err_msg;
            }
            if ($values['vineland_3_parent_ppe'][0] != null) {
             $errors['vineland_3_parent_ppe'] = $err_msg;
            }
        }

        return $errors;
    }
}
