<?php
/**
 * This file contains the NDB_BVL_Instrument_COVID_Parent_Report_survey
 * class
 *
 * PHP Version 7
 *
 * @category Instrument
 * @package  COVID_Parent_Report_survey
 * @author   Tanishq Bhatia <tanishq.bhatia@mcin.ca>
 * @license  http://www.gnu.org/licenses/gpl-3.0.txt GPLv3
 * @link     https://www.github.com/aces/loris/
 */

/**
 * Creates the form elements for the COVID - Parent Report - Survey
 *
 * @category Instrument
 * @package  COVID_Parent_Report_survey
 * @author   Tanishq Bhatia <tanishq.bhatia@mcin.ca>
 * @license  http://www.gnu.org/licenses/gpl-3.0.txt GPLv3
 * @link     https://www.github.com/aces/loris/
 */
class NDB_BVL_Instrument_COVID_Parent_Report_survey extends NDB_BVL_Instrument
{
    use LegacyInstrumentTrait;
    use instrument_validator;

    const YES_NO_OPTIONS = array(
                            null    => "",
                            "1_yes" => "Yes",
                            "2_no"  => "No",
                           );

    /**
     * Sample SQL statement for test_names table and instrument subtests table
     *
     * INSERT INTO test_names (Test_name, Full_name, Sub_Group, isDirectEntry) VALUES ('COVID_Parent_Report_survey', "COVID - Parent Report - Survey", 1, 1);
     * INSERT INTO instrument_subtests (Test_name, Subtest_name, Description, Order_number) VALUES ('COVID_Parent_Report_survey','COVID_Parent_Report_survey_page1', "Page 1", 1);
     * INSERT INTO instrument_subtests (Test_name, Subtest_name, Description, Order_number) VALUES ('COVID_Parent_Report_survey','COVID_Parent_Report_survey_page2', "Page 2", 2);
     * INSERT INTO instrument_subtests (Test_name, Subtest_name, Description, Order_number) VALUES ('COVID_Parent_Report_survey','COVID_Parent_Report_survey_page3', "Page 3", 3);
     * INSERT INTO instrument_subtests (Test_name, Subtest_name, Description, Order_number) VALUES ('COVID_Parent_Report_survey','COVID_Parent_Report_survey_page4', "Page 4", 4);
     */

    /**
     * Sets up basic data such as the HTML_Quickform object, database references
     *
     * @param string $commentID the CommentID identifying the data to load
     * @param string $page      if a multipage form, the page to show
     *
     * @return void
     * @access public
     */
    function setup(?string $commentID = NULL, ?string $page = NULL): void
    {
        $this->formType = "XIN";
        $this->form     = new LorisForm('COVID_Parent_Report_survey');
        $this->page     = $page;            // page label (number or
        // string - used by
        // user-defined child classes)

        // set the object properties
        // Corresponds to the Test_name column in test_names table
        $this->testName = "COVID_Parent_Report_survey";
        // name of database table corresponding to instrument
        $this->table = 'COVID_Parent_Report_survey';
        // data keyed by commentID
        $this->commentID = $commentID;

        //The array of dates/timestamps to convert to database dates/timestamps
        //Any HTML_Quickform date elements must be listed here
        $this->dateTimeFields = array("Date_taken");

        //The array of selects with multiple answers allowed
        //Any HTML_Quickform multiple selects must be listed here
        $this->selectMultipleElements = array();

        // required fields for data entry completion status
        $this->_requiredElements = array(
                                    "A_q1_healthcare_provider_told_has_or_most_likely_has_covid_19",
                                    "A_q6_is_child_older_than_12_months",
                                   );

        // setup the form
        $this->_setupForm();
    }

    /**
     * Builds the HTML_Quickform object into a paged form
     *
     * @return void
     * @access private
     */
    function _setupForm()
    {
        if (preg_match("/COVID_Parent_Report_survey(_page[0-9]+)/", $this->page, $matches)) {
            call_user_func(array($this, $matches[1]));
        } else {
            $this->_main();
        }
        // Defines the call back function for HTML Quickform to use in validation
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
        $this->addHeader("COVID - Parent Report - Survey");

        $this->form->addElement(
            'static',
            null,
            "<h3>Instructions:</h3>
            <br>
            This form has 2 sections:<br>
            <ul>
                <li>Section A: COVID-19 Infection</li>
                <li>Section B: Impacts of the COVID-19 Outbreak on the Child Enrolled</li>
            </ul><br>
            Please complete Sections A and B if the child is 12 months old or older.
            Please complete Section A only if the child is less than 12 months old.<br><br>
            These questions are about the child’s experience with COVID-19, or the coronavirus.
            For each question, do the best you can to remember the details requested."
        );

        $config =& NDB_Config::singleton();

        $dateOptions = array(
                        'language'         => 'en',
                        'format'           => 'YMd',
                        'minYear'          => $config->getSetting('startYear'),
                        'maxYear'          => $config->getSetting('endYear'),
                        'addEmptyOption'   => true,
                        'emptyOptionValue' => null,
                       );

        $this->addBasicDate('Date_taken', 'Date of Administration', $this->dateOptions);

        $this->form->addElement(
            'select',
            'respondent',
            'What is your relationship to the child',
            array(
             ''            => '',
             'mother'      => 'Mother',
             'father'      => 'Father',
             'step_mother' => 'Step Mother',
             'step_father' => 'Step Father',
             'other'       => 'Other',
            )
        );

        $this->form->addElement('text', 'respondent_specify', 'If other, specify:');

        $this->XINRegisterRule('respondent_specify', array('respondent{@}=={@}other'), 'Required if other');

        $this->form->addFormRule(array(&$this, 'validate_main_page'));
    }

    /**
     * Generates the first page of the form.
     *
     * @return void
     */
    function _page1()
    {
        // display test name
        $this->addHeader("COVID - Parent Report - Survey");

        $this->form->addElement(
            'static',
            null,
            "<h3><b>Section A. COVID-19 Infection</b></h3>
            <i>For the following questions, healthcare provider means a doctor, nurse practitioner, physician assistant or anyone you go to for medical care.</i>"
        );

        $q2_options = array(
                       "1_fever_or_chills"                  => "Fever or chills",
                       "2_cough"                            => "Cough",
                       "3_shortness_of_breath"              => "Shortness of breath",
                       "4_sore_throat"                      => "Sore throat",
                       "5_headache"                         => "Headache",
                       "6_muscle_or_body_aches"             => "Muscle or body aches",
                       "7_runny_nose"                       => "Runny nose",
                       "8_fatigue_or_excessive_sleepiness"  => "Fatigue or excessive sleepiness",
                       "9_diarrhea_nausea_or_vomiting"      => "Diarrhea, nausea, or vomiting",
                       "10_loss_of_sense_of_smell_or_taste" => "Loss of sense of smell or taste",
                       "11_itchy_red_eyes"                  => "Itchy/red eyes",
                       "12_none_of_the_above"               => "None of the above -> skip to Section A, Question 3.",
                      );

        $q2a_options = array(
                        "1_kept_overnight_in_hospital"                         => "The child was kept overnight in a hospital because a healthcare provider thought he/she had COVID-19",
                        "2_saw_healthcare_provider_in_person"                  => "The child saw a healthcare provider in person, such as in a clinic, doctor’s office, urgent care, or Emergency Room (ER)/Emergency Department (ED)",
                        "3_spoke_to_healthcare_provider_by_phone_email_online" => "You/the child spoke to a healthcare provider over the phone, by email, or online",
                        "4_self_isolated_or_quarantined_at_home"               => "You/the child self-isolated or quarantined at home",
                        "5_none_of_the_above"                                  => "None of the above",
                       );

        $q2b_options = array(
                        "1_have_contact_with_someone_tested_positive" => "Have contact with someone who tested positive for COVID-19",
                        "2_have_contact_with_someone_who_likely_had"  => "Have contact with someone who likely had COVID-19 (e.g., was not tested but had symptoms; was told by a healthcare provider that he/she likely had it)",
                        "3_travel_to_different_state_or_country"      => "Travel to a different state or country (specify)",
                        "4_none_of_the_above"                         => "None of the above",
                       );

        $this->addSelect(
            "A_q1_healthcare_provider_told_has_or_most_likely_has_covid_19",
            "1. Has a healthcare provider ever told you that the child has, or likely has, COVID-19  (Coronavirus)?",
            self::YES_NO_OPTIONS
        );

        $this->form->addElement("static", null, "2. Which of the following symptoms has the child had at any point in time since March 1, 2020? (<b><i>Mark all that apply</i></b>)");

        foreach ($q2_options as $key => $value) {
            $this->form->addElement("advcheckbox", "A_q2_" . $key, null, $value, null, array("no", "yes"));
            $this->XINRegisterRule(
                "A_q2_{$key}",
                array("A_q2_{$key}{@}=={@}NEVER_REQUIRED"),
                "Not required"
            );
        }

        $this->form->addElement("static", null, "2.a. Which of the following occurred as a result of the child’s symptoms? (<b><i>Mark all that apply</i></b>)");

        foreach ($q2a_options as $key => $value) {
            $this->form->addElement("advcheckbox", "A_q2a_" . $key, null, $value, null, array("no", "yes"));
            $this->XINRegisterRule(
                "A_q2a_{$key}",
                array("A_q2a_{$key}{@}=={@}NEVER_REQUIRED"),
                "Not required"
            );
        }

        $this->form->addElement("static", null, "2.b. In the two weeks before the child had symptoms, did he/she: (<b><i>Mark all that apply</i></b>)");

        foreach ($q2b_options as $key => $value) {
            $this->form->addElement("advcheckbox", "A_q2b_" . $key, null, $value, null, array("no", "yes"));
            $this->XINRegisterRule(
                "A_q2b_{$key}",
                array("A_q2b_{$key}{@}=={@}NEVER_REQUIRED"),
                "Not required"
            );
        }

        $this->form->addElement('text', 'A_q2b_3_travel_to_different_state_or_country_specify', "If child travelled to a different state or country, specify:");

        $this->XINRegisterRule(
            "A_q2b_3_travel_to_different_state_or_country_specify",
            array("A_q2b_3_travel_to_different_state_or_country{@}=={@}yes"),
            'Required if child travelled to a different state or country'
        );
    }

    /**
     * Generates the second page of the form.
     *
     * @return void
     */
    function _page2()
    {
        // display test name
        $this->addHeader("COVID - Parent Report - Survey");

        $this->form->addElement(
            'static',
            null,
            "<h3><b>Section A. COVID-19 Infection (continued)</b></h3>"
        );

        $q3_options = array(
                       "1_no_never_tried_to_get_tested"                         => "No, I never tried to get the child tested",
                       "2_no_tried_to_get_tested_but_unable_to"                 => "No, I tried to get the child tested but was not able to",
                       "3_yes_waiting_for_the_results"                          => "Yes, and the child is waiting for the results",
                       "4_yes_test_showed_child_does_not_have_it_negative_test" => "Yes, and the test showed that the child does not not have it (\"negative\" test)",
                       "5_yes_test_showed_child_does_have_it_positive_test"     => "Yes, and the test showed that the child does have it (\"positive\" test)",
                      );

        $q4_options = array(
                       "1_no_never_tried_to_get_tested"                         => "No, I never tried to get the child tested",
                       "2_no_tried_to_get_tested_but_unable_to"                 => "No, I tried to get the child tested but was not able to",
                       "3_yes_waiting_for_the_results"                          => "Yes, and the child is waiting for the results",
                       "4_yes_test_showed_child_does_not_have_it_negative_test" => "Yes, and the test showed that the child did not have it (\"negative\" test)",
                       "5_yes_test_showed_child_does_have_it_positive_test"     => "Yes, and the test showed that the child did have it (\"positive\" test)",
                      );

        $q5_options = array(
                       "1_did_not_go_to_healthcare_appointments_concerned"         => "The child did not go to healthcare appointments because I was concerned about the child entering the healthcare provider's office",
                       "2_healthcare_provider_canceled_appointments"               => "The child's healthcare provider canceled appointments",
                       "3_healthcare_provider_changed_to_phone_or_online"          => "The child's healthcare provider changed to phone or online visits",
                       "4_healthcare_provider_told_child_to_isolate_or_quarantine" => "The child's healthcare provider told him/her to self-isolate or quarantine",
                       "5_none_of_these_apply"                                     => "None of these apply",
                      );

        $this->form->addElement("static", null, "3. Has the child had the nose swab test for the virus that causes COVID-19? (<b><i>Mark all that apply</i></b>)");

        foreach ($q3_options as $key => $value) {
            $this->form->addElement("advcheckbox", "A_q3_" . $key, null, $value, null, array("no", "yes"));
            $this->XINRegisterRule(
                "A_q3_{$key}",
                array("A_q3_{$key}{@}=={@}NEVER_REQUIRED"),
                "Not required"
            );
        }

        $this->addBasicDate('A_q3a_date_of_most_recent_test', $this->indent . 'If child had the test and is waiting for the results --> 3.a. When was the date of the child’s most recent test?', $this->dateOptions);

        $this->XINRegisterRule(
            "A_q3a_date_of_most_recent_test",
            array("A_q3_3_yes_waiting_for_the_results{@}=={@}yes"),
            'Required if waiting for results'
        );

        $this->addBasicDate('A_q3b_date_of_most_recent_negative_test', $this->indent . 'If child had the test and it showed they <u>do not</u> have it --> 3.b. When was the date of the child’s most recent <b>negative</b> test?', $this->dateOptions);

        $this->XINRegisterRule(
            "A_q3b_date_of_most_recent_negative_test",
            array("A_q3_4_yes_test_showed_child_does_not_have_it_negative_test{@}=={@}yes"),
            'Required if test showed child does not have COVID-19'
        );

        $this->addBasicDate('A_q3c_date_of_most_recent_positive_test', $this->indent . 'If child had the test and it showed they <u>do</u> have it --> 3.c. When was the date of the child’s most recent <b>positive</b> test?', $this->dateOptions);

        $this->XINRegisterRule(
            "A_q3c_date_of_most_recent_positive_test",
            array("A_q3_5_yes_test_showed_child_does_have_it_positive_test{@}=={@}yes"),
            'Required if test showed child does have COVID-19'
        );

        $this->form->addElement("static", null, "4. Has the child had a blood test to see whether he/she already had the COVID-19 virus (\"serology\")? (<b><i>Mark all that apply</i></b>)");

        foreach ($q4_options as $key => $value) {
            $this->form->addElement("advcheckbox", "A_q4_" . $key, null, $value, null, array("no", "yes"));
            $this->XINRegisterRule(
                "A_q4_{$key}",
                array("A_q4_{$key}{@}=={@}NEVER_REQUIRED"),
                "Not required"
            );
        }

        $this->addBasicDate('A_q4a_date_of_most_recent_test', $this->indent . 'If child had the test and is waiting for the results --> 4.a. When was the date of the child\'s most recent test?', $this->dateOptions);

        $this->XINRegisterRule(
            "A_q4a_date_of_most_recent_test",
            array("A_q4_3_yes_waiting_for_the_results{@}=={@}yes"),
            'Required if waiting for results'
        );

        $this->addBasicDate('A_q4b_date_of_most_recent_negative_test', $this->indent . 'If child had the test and it showed they <u>did not</u> have it --> 4.b. When was the date of the child\'s most recent <b>negative</b> test?', $this->dateOptions);

        $this->XINRegisterRule(
            "A_q4b_date_of_most_recent_negative_test",
            array("A_q4_4_yes_test_showed_child_does_not_have_it_negative_test{@}=={@}yes"),
            'Required if test showed child did not have COVID-19'
        );

        $this->addBasicDate('A_q4c_date_of_most_recent_positive_test', $this->indent . 'If child had the test and it showed they <u>did</u> have it --> 4.c. When was the date of the child\'s most recent <b>positive</b> test?', $this->dateOptions);

        $this->XINRegisterRule(
            "A_q4c_date_of_most_recent_positive_test",
            array("A_q4_5_yes_test_showed_child_does_have_it_positive_test{@}=={@}yes"),
            'Required if test showed child did have COVID-19'
        );

        $this->form->addElement("static", null, "5. In what ways has the COVID-19 outbreak affected the child's overall healthcare? (<b><i>Mark all that apply</i></b>)");

        foreach ($q5_options as $key => $value) {
            $this->form->addElement("advcheckbox", "A_q5_" . $key, null, $value, null, array("no", "yes"));
            $this->XINRegisterRule(
                "A_q5_{$key}",
                array("A_q5_{$key}{@}=={@}NEVER_REQUIRED"),
                "Not required"
            );
        }

        $this->addSelect(
            "A_q6_is_child_older_than_12_months",
            "To route you through the remaining questions, is the child 12 months or older?<h4><i>If yes, continue to Section B; if no, skip to END of survey</i></h4>",
            self::YES_NO_OPTIONS
        );
    }

    /**
     * Generates the third page of the form.
     *
     * @return void
     */
    function _page3()
    {
        // display test name
        $this->addHeader("COVID - Parent Report - Survey");

        $this->form->addElement(
            'static',
            null,
            "<h3><b>Section B. Impacts of the COVID-19 Outbreak on the Child Enrolled in IBIS</b></h3>
            <i>Section B needs to be completed if the child is 12 months or older. If child is less than 12 months, skip to end of survey.</i>"
        );

        $q1_options = array(
                       "1_yes"                              => "Yes",
                       "2_no"                               => "No",
                       "3_child_not_enrolled_in_any_school" => "The child is not enrolled in any school/preschool/daycare",
                      );

        $q2_options = array(
                       "1_high_speed_broadband_internet"               => "High-speed broadband internet (\"WiFi\") (e.g., DSL, cable, fiberoptic)",
                       "2_dial_up_internet"                            => "Dial-up internet (not WiFi)",
                       "3_smartphone_not_connected_to_home_wifi"       => "Smartphone not connected to WiFi network at home (e.g., use cellular, LTE, mobile hotspot, neighbor’s WiFi)",
                       "4_child_does_not_have_internet_access_at_home" => "The child does not have internet access at home",
                      );

        $this->addSelect("B_q1_did_childs_school_close_because_of_covid_19", "1. Did the child’s school/preschool/daycare close because of the COVID-19 outbreak?", $q1_options);

        // if child is older than 12 months, section B is required
        $this->XINRegisterRule(
            "B_q1_did_childs_school_close_because_of_covid_19",
            array("A_q6_is_child_older_than_12_months{@}=={@}1_yes"),
            'Required.'
        );

        $this->addSelect("B_q1a_does_child_usually_receive_free_meals_at_school", $this->indent . "1.a. Does the child usually receive free meals at school/preschool/daycare?", self::YES_NO_OPTIONS);

        $this->XINRegisterRule(
            "B_q1a_does_child_usually_receive_free_meals_at_school",
            array("B_q1_did_childs_school_close_because_of_covid_19{@}!={@}3_child_not_enrolled_in_any_school"),
            'Required.'
        );

        $this->addSelect("B_q1a1_has_childs_school_offered_meals_during_school_closure", $this->indent . $this->indent . "1.a.1. Has the child’s school/preschool/daycare offered meals during the closure from COVID-19?", self::YES_NO_OPTIONS);

        $this->XINRegisterRule(
            "B_q1a1_has_childs_school_offered_meals_during_school_closure",
            array("B_q1a_does_child_usually_receive_free_meals_at_school{@}=={@}1_yes"),
            'Required.'
        );

        $this->addSelect("B_q1a1a_has_child_been_able_to_get_school_provided_meals", $this->indent . $this->indent . $this->indent . "1.a.1.a. Has the child been able to get the school-provided meals during the COVID-19 associated closure?", self::YES_NO_OPTIONS);

        $this->XINRegisterRule(
            "B_q1a1a_has_child_been_able_to_get_school_provided_meals",
            array("B_q1a1_has_childs_school_offered_meals_during_school_closure{@}=={@}1_yes"),
            'Required.'
        );

        $this->addSelect("B_q1b_has_childs_school_offered_online_learning_while_closed", $this->indent . "1.b. Has the child’s school/preschool/daycare offered online learning while closed?", self::YES_NO_OPTIONS);

        $this->XINRegisterRule(
            "B_q1b_has_childs_school_offered_online_learning_while_closed",
            array("B_q1_did_childs_school_close_because_of_covid_19{@}!={@}3_child_not_enrolled_in_any_school"),
            'Required.'
        );

        $this->form->addElement(
            'static',
            null,
            $this->indent . $this->indent . "1.b.1. Has the child's school/preschool/daycare provided either of the following to support online learning?"
        );

        $this->addSelect("B_q1b1a_has_childs_school_provided_free_home_internet_access", $this->indent . $this->indent . $this->indent . "a. Free home internet access", self::YES_NO_OPTIONS);

        $this->XINRegisterRule(
            "B_q1b1a_has_childs_school_provided_free_home_internet_access",
            array("B_q1b_has_childs_school_offered_online_learning_while_closed{@}=={@}1_yes"),
            'Required.'
        );

        $this->addSelect("B_q1b1b_has_childs_school_provided_free_computer_or_tablet", $this->indent . $this->indent . $this->indent . "b. Free computer or tablet", self::YES_NO_OPTIONS);

        $this->XINRegisterRule(
            "B_q1b1b_has_childs_school_provided_free_computer_or_tablet",
            array("B_q1b_has_childs_school_offered_online_learning_while_closed{@}=={@}1_yes"),
            'Required.'
        );

        $this->form->addElement("static", null, "2. What type of internet access does the child have at home? (<b><i>Mark all that apply</i></b>)");

        foreach ($q2_options as $key => $value) {
            $this->form->addElement("advcheckbox", "B_q2_" . $key, null, $value, null, array("no", "yes"));
            $this->XINRegisterRule(
                "B_q2_{$key}",
                array("B_q2_{$key}{@}=={@}NEVER_REQUIRED"),
                "Not required"
            );
        }

        $this->addSelect("B_q2b_did_child_have_high_speed_broadband_internet_march_1_2020", $this->indent . "2.b. Did the child have high-speed broadband internet access at home prior to March 1, 2020?", self::YES_NO_OPTIONS);

        $this->XINRegisterRule(
            "B_q2b_did_child_have_high_speed_broadband_internet_march_1_2020",
            array("B_q2_1_high_speed_broadband_internet{@}=={@}yes"),
            'Required.'
        );

        $this->form->addFormRule(array(&$this, 'validate_page3'));
    }

    /**
     * Generates the fourth page of the form.
     *
     * @return void
     */
    function _page4()
    {
        // display test name
        $this->addHeader("COVID - Parent Report - Survey");

        $this->form->addElement(
            'static',
            null,
            "<h3><b>Section B. Impacts of the COVID-19 Outbreak on the Child Enrolled in IBIS (continued)</b></h3>
            <i>Section B needs to be completed if the child is 12 months or older. If child is less than 12 months, skip to end of survey.</i>"
        );

        $q3_subquestions = array(
                            "q3a_eating"                                             => "a. Eating",
                            "q3b_sleeping"                                           => "b. Sleeping",
                            "q3c_physical_activity"                                  => "c. Physical activity",
                            "q3d_spending_time_outside"                              => "d. Spending time outside",
                            "q3e_spending_time_with_friends_in_person"               => "e. Spending time with friends in-person",
                            "q3f_spending_time_with_friends_remotely"                => "f. Spending time with friends remotely (e.g., online, social media, texting)",
                            "q3g_spending_time_tv_games_social_media_educational"    => "g. Spending time watching TV, playing video/computer games, or using social media for <b><i><u>educational</u></i></b> purposes, including school work",
                            "q3h_spending_time_tv_games_social_media_noneducational" => "h. Spending time watching TV, playing video/computer games, or using social media for <b><i><u>non-educational</u></i></b> purposes",
                           );

        $q3_options = array(
                       "1_less"        => "Less",
                       "2_same_amount" => "Same amount",
                       "3_more"        => "More",
                      );

        $q4_options = array(
                       "1_much_less"     => "Much less socially connected",
                       "2_less"          => "Less socially connected",
                       "3_slightly_less" => "Slightly less socially connected",
                       "4_slightly_more" => "Slightly more socially connected",
                       "5_more"          => "More socially connected",
                       "6_much_more"     => "Much more socially connected",
                      );

        $this->form->addElement(
            'static',
            null,
            "<i>For rows 3.a through 3.h below, please mark 'Less', 'Same amount', or 'More' for <u>how much</u> the child is now engaged in the activity compared to before the COVID-19 outbreak.</i>"
        );

        $this->form->addElement(
            'static',
            null,
            "3. Compared to before the COVID-19 outbreak, <u>how much</u> is the child now doing the following:"
        );

        foreach ($q3_subquestions as $key => $value) {
            $this->addSelect("B_" . $key, $value, $q3_options);

            // if child is older than 12 months, section B is required
            $this->XINRegisterRule(
                "B_" . $key,
                array("A_q6_is_child_older_than_12_months{@}=={@}1_yes"),
                'Required.'
            );
        }

        $this->addSelect("B_q4_compared_to_before_covid_does_the_child_seem", "4. Compared to before the COVID-19 outbreak, does the child seem...", $q4_options);

        // if child is older than 12 months, section B is required
        $this->XINRegisterRule(
            "B_q4_compared_to_before_covid_does_the_child_seem",
            array("A_q6_is_child_older_than_12_months{@}=={@}1_yes"),
            'Required.'
        );
    }

    function validate_main_page($values)
    {
        $errors = [];

        if ($values["respondent"] != "other") {
            $this->validate_empty_subquestions($values, ["respondent_specify"], $errors);
        }

        return $errors;
    }

    function validate_page3($values)
    {
        $errors = [];

        if ($values["B_q1_did_childs_school_close_because_of_covid_19"] == "3_child_not_enrolled_in_any_school") {
            $this->validate_empty_subquestions($values, ["B_q1a_does_child_usually_receive_free_meals_at_school"], $errors);
            $this->validate_empty_subquestions($values, ["B_q1a1_has_childs_school_offered_meals_during_school_closure"], $errors);
            $this->validate_empty_subquestions($values, ["B_q1a1a_has_child_been_able_to_get_school_provided_meals"], $errors);
            $this->validate_empty_subquestions($values, ["B_q1b_has_childs_school_offered_online_learning_while_closed"], $errors);
            $this->validate_empty_subquestions($values, ["B_q1b1a_has_childs_school_provided_free_home_internet_access"], $errors);
            $this->validate_empty_subquestions($values, ["B_q1b1b_has_childs_school_provided_free_computer_or_tablet"], $errors);
        }

        if ($values["B_q1a_does_child_usually_receive_free_meals_at_school"] == "2_no") {
            $this->validate_empty_subquestions($values, ["B_q1a1_has_childs_school_offered_meals_during_school_closure"], $errors);
            $this->validate_empty_subquestions($values, ["B_q1a1a_has_child_been_able_to_get_school_provided_meals"], $errors);
        }

        if ($values["B_q1a1_has_childs_school_offered_meals_during_school_closure"] == "2_no") {
            $this->validate_empty_subquestions($values, ["B_q1a1a_has_child_been_able_to_get_school_provided_meals"], $errors);
        }

        return $errors;
    }
}
?>