<?php
/**
 * This file contains the NDB_BVL_Instrument_COVID_Child_Self_Report_survey class
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
 * Creates the form elements for the COVID_Child_Self_Report_survey instrument
 *
 * @category Instrument
 * @package  Neuropsych
 * @author   Suzanne Lee <suzannelee.mcin@gmail.com>
 * @license  http://www.gnu.org/licenses/gpl-3.0.txt GPLv3
 * @link     https://www.github.com/aces/IBIS/
 */
class NDB_BVL_Instrument_COVID_Child_Self_Report_survey extends NDB_BVL_Instrument
{
    use LegacyInstrumentTrait;
    use instrument_validator;

    var $ValidityRequired = false;

    const YES_NO_OPTIONS = array(
                            null    => "",
                            "1_yes" => "Yes",
                            "2_no"  => "No",
                           );

    /**
     * Sample SQL statement for test_names table and instrument subtests table
     *
     * INSERT INTO test_names (Test_name, Full_name, Sub_Group, isDirectEntry) VALUES ('COVID_Child_Self_Report_survey', "COVID - Child Self Report - Survey", 1, 1);
     * INSERT INTO instrument_subtests (Test_name, Subtest_name, Description, Order_number) VALUES ('COVID_Child_Self_Report_survey','COVID_Child_Self_Report_survey_page1', "Page 1", 1);
     * INSERT INTO instrument_subtests (Test_name, Subtest_name, Description, Order_number) VALUES ('COVID_Child_Self_Report_survey','COVID_Child_Self_Report_survey_page2', "Page 2", 2);
     * INSERT INTO instrument_subtests (Test_name, Subtest_name, Description, Order_number) VALUES ('COVID_Child_Self_Report_survey','COVID_Child_Self_Report_survey_page3', "Page 3", 3);
     * INSERT INTO instrument_subtests (Test_name, Subtest_name, Description, Order_number) VALUES ('COVID_Child_Self_Report_survey','COVID_Child_Self_Report_survey_page4', "Page 4", 4);
     * INSERT INTO instrument_subtests (Test_name, Subtest_name, Description, Order_number) VALUES ('COVID_Child_Self_Report_survey','COVID_Child_Self_Report_survey_page5', "Page 5", 5);
     * INSERT INTO instrument_subtests (Test_name, Subtest_name, Description, Order_number) VALUES ('COVID_Child_Self_Report_survey','COVID_Child_Self_Report_survey_page6', "Page 6", 6);
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
        $this->form     = new LorisForm('COVID_Child_Self_Report_survey_form');
        $this->page     = $page;            // page label (number or
        // string - used by
        // user-defined child classes)

        // set the object properties
        $this->testName = "COVID_Child_Self_Report_survey";           // test_names.Test_name
        $this->table    = 'COVID_Child_Self_Report_survey';           // name of database table corresponding to instrument
        // data keyed by commentID
        $this->commentID = $commentID;

        //The array of dates/timestamps to convert to database dates/timestamps
        //Any LorisForm date elements must be listed here
        $this->dateTimeFields = array(
                                 "Date_taken",
                                 "A_q3a_date_of_most_recent_test",
                                 "A_q3b_date_of_most_recent_negative_test",
                                 "A_q3c_date_of_most_recent_positive_test",
                                 "A_q4a_date_of_most_recent_test",
                                 "A_q4b_date_of_most_recent_negative_test",
                                 "A_q4c_date_of_most_recent_positive_test",
                                );

        //The array of selects with multiple answers allowed
        //Any LorisForm multiple selects must be listed here
        $this->selectMultipleElements = array();

        // required fields for data entry completion status
        $this->_requiredElements = array(
                                    "A_q1_healthcare_provider_told_have_or_most_likely_have_covid_19",
                                    "A_q5_has_anyone_else_living_in_your_home_had_covid_19",
                                    "B_q2_did_your_school_close_because_of_covid_19",
                                    "B_q4a_eating",
                                    "B_q7_indicate_covid_19_positive_or_negative_impact_on_your_life",
                                    "B_q9a_had_difficulty_sleeping",
                                   );

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
        if (preg_match("/COVID_Child_Self_Report_survey(_page[0-9]+)/", $this->page, $matches)) {
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
        $this->addHeader("COVID - Child Self Report - Survey");

        $this->form->addElement(
            'static',
            null,
            "<h3>Instructions:</h3><br>
            <i>This form has 2 sections:<br>
            <ul>
                <li>Section A: COVID-19 Infection</li>
                <li>Section B: Impacts of the COVID-19 Outbreak on You</li>
            </ul><br>
            These questions are about your experience with COVID-19, or the coronavirus. For each question, do the best you can to remember the details requested.</i>"
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
        $this->addHeader("COVID - Child Self Report - Survey");

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
                        "1_kept_overnight_in_hospital"                         => "I was kept overnight in a hospital because a healthcare provider thought I had COVID-19",
                        "2_saw_healthcare_provider_in_person"                  => "I saw a healthcare provider in person, such as in a clinic, doctor's office, urgent care, or Emergency Room (ER)/Emergency Department (ED)",
                        "3_spoke_to_healthcare_provider_by_phone_email_online" => "I spoke to a healthcare provider over the phone, by email, or online",
                        "4_self_isolated_or_quarantined_at_home"               => "I self-isolated or quarantined at home",
                        "5_none_of_the_above"                                  => "None of the above",
                       );

        $q2b_options = array(
                        "1_have_contact_with_someone_tested_positive" => "Have contact with someone who tested positive for COVID-19",
                        "2_have_contact_with_someone_who_likely_had"  => "Have contact with someone who likely had COVID-19 (e.g., was not tested but had symptoms; was told by a healthcare provider that he/she likely had it)",
                        "3_travel_to_different_state_or_country"      => "Travel to a different state or country (specify)",
                        "4_none_of_the_above"                         => "None of the above",
                       );

        $this->addSelect("A_q1_healthcare_provider_told_have_or_most_likely_have_covid_19", "1. Has a healthcare provider ever told you that you have, or likely have, COVID-19 (Coronavirus)?", self::YES_NO_OPTIONS);

        $this->form->addElement("static", null, "2. Which of the following symptoms have you had at any point in time since March 1, 2020? (<b><i>Mark all that apply</i></b>)");

        foreach ($q2_options as $key => $value) {
            $this->form->addElement("advcheckbox", "A_q2_" . $key, null, $value, null, array("no", "yes"));
            $this->XINRegisterRule(
                "A_q2_{$key}",
                array("A_q2_{$key}{@}=={@}NEVER_REQUIRED"),
                "Not required"
            );
        }

        $this->form->addElement("static", null, "2.a. Which of the following occurred as a result of your symptoms? (<b><i>Mark all that apply</i></b>)");

        foreach ($q2a_options as $key => $value) {
            $this->form->addElement("advcheckbox", "A_q2a_" . $key, null, $value, null, array("no", "yes"));
            $this->XINRegisterRule(
                "A_q2a_{$key}",
                array("A_q2a_{$key}{@}=={@}NEVER_REQUIRED"),
                "Not required"
            );
        }

        $this->form->addElement("static", null, "2.b. In the two weeks before you had symptoms, did you: (<b><i>Mark all that apply</i></b>)");

        foreach ($q2b_options as $key => $value) {
            $this->form->addElement("advcheckbox", "A_q2b_" . $key, null, $value, null, array("no", "yes"));
            $this->XINRegisterRule(
                "A_q2b_{$key}",
                array("A_q2b_{$key}{@}=={@}NEVER_REQUIRED"),
                "Not required"
            );
        }

        $this->form->addElement('text', 'A_q2b_3_travel_to_different_state_or_country_specify', "If you've travelled to a different state or country, specify:");

        $this->XINRegisterRule(
            "A_q2b_3_travel_to_different_state_or_country_specify",
            array("A_q2b_3_travel_to_different_state_or_country{@}=={@}yes"),
            'Required if travelled to a different state or country'
        );

        $this->form->addFormRule(array(&$this, 'validate_page1'));
    }

    /**
    * Generates the second page of the form.
    *
    * @return void
    */
    function _page2()
    {
        $this->addHeader("COVID - Child Self Report - Survey");

        $this->form->addElement(
            'static',
            null,
            "<h3><b>Section A. COVID-19 Infection (continued)</b></h3>"
        );

        $q3_options = array(
                       "1_no_never_tried_to_get_tested"                   => "No, I never tried to get tested",
                       "2_no_tried_to_get_tested_but_unable_to"           => "No, I tried to get tested but was not able to",
                       "3_yes_waiting_for_the_results"                    => "Yes, and I am waiting for the results",
                       "4_yes_test_showed_i_do_not_have_it_negative_test" => "Yes, and the test showed that I do not have it (\"negative\" test)",
                       "5_yes_test_showed_i_do_have_it_positive_test"     => "Yes, and the test showed that I do have it (\"positive\" test)",
                      );

        $q4_options = array(
                       "1_no_never_tried_to_get_tested"                    => "No, I never tried to get tested",
                       "2_no_tried_to_get_tested_but_unable_to"            => "No, I tried to get tested but was not able to",
                       "3_yes_waiting_for_the_results"                     => "Yes, and I am waiting for the results",
                       "4_yes_test_showed_i_did_not_have_it_negative_test" => "Yes, and the test showed that I did not have it (\"negative\" test)",
                       "5_yes_test_showed_i_did_have_it_positive_test"     => "Yes, and the test showed that I did have it (\"positive\" test)",
                      );

        $this->form->addElement("static", null, "3. Have you had the nose swab test for the virus that causes COVID-19? (<b><i>Mark all that apply</i></b>)");

        foreach ($q3_options as $key => $value) {
            $this->form->addElement("advcheckbox", "A_q3_" . $key, null, $value, null, array("no", "yes"));
            $this->XINRegisterRule(
                "A_q3_{$key}",
                array("A_q3_{$key}{@}=={@}NEVER_REQUIRED"),
                "Not required"
            );
        }

        $this->addBasicDate('A_q3a_date_of_most_recent_test', $this->indent . 'If you are waiting for the results --> 3.a. When was the date of your most recent test?', $this->dateOptions);

        $this->XINRegisterRule(
            "A_q3a_date_of_most_recent_test",
            array("A_q3_3_yes_waiting_for_the_results{@}=={@}yes"),
            'Required if waiting for results'
        );

        $this->addBasicDate('A_q3b_date_of_most_recent_negative_test', $this->indent . 'If you had the test and it showed you <u>do not</u> have it --> 3.b. When was the date of your most recent <b>negative</b> test?', $this->dateOptions);

        $this->XINRegisterRule(
            "A_q3b_date_of_most_recent_negative_test",
            array("A_q3_4_yes_test_showed_i_do_not_have_it_negative_test{@}=={@}yes"),
            'Required if test showed you <u>do not</u> have COVID_19'
        );

        $this->addBasicDate('A_q3c_date_of_most_recent_positive_test', $this->indent . 'If you had the test and it showed you <u>do</u> have it --> 3.c. When was the date of your most recent <b>positive</b> test?', $this->dateOptions);

        $this->XINRegisterRule(
            "A_q3c_date_of_most_recent_positive_test",
            array("A_q3_5_yes_test_showed_i_do_have_it_positive_test{@}=={@}yes"),
            'Required if test showed you <u>have</u> COVID_19'
        );

        $this->form->addElement("static", null, "4. Have you had a blood test to see whether you already had the COVID-19 virus (\"serology\")? (<b><i>Mark all that apply</i></b>)");

        foreach ($q4_options as $key => $value) {
            $this->form->addElement("advcheckbox", "A_q4_" . $key, null, $value, null, array("no", "yes"));
            $this->XINRegisterRule(
                "A_q4_{$key}",
                array("A_q4_{$key}{@}=={@}NEVER_REQUIRED"),
                "Not required"
            );
        }

        $this->addBasicDate('A_q4a_date_of_most_recent_test', $this->indent . 'If you are waiting for the results --> 4.a. When was the date of your most recent test?', $this->dateOptions);

        $this->XINRegisterRule(
            "A_q4a_date_of_most_recent_test",
            array("A_q4_3_yes_waiting_for_the_results{@}=={@}yes"),
            'Required if waiting for results'
        );

        $this->addBasicDate('A_q4b_date_of_most_recent_negative_test', $this->indent . 'If you had the test and it showed you <u>did not</u> have it --> 4.b. When was the date of your most recent <b>negative</b> test?', $this->dateOptions);

        $this->XINRegisterRule(
            "A_q4b_date_of_most_recent_negative_test",
            array("A_q4_4_yes_test_showed_i_did_not_have_it_negative_test{@}=={@}yes"),
            'Required if test showed you <u>did not</u> have COVID_19'
        );

        $this->addBasicDate('A_q4c_date_of_most_recent_positive_test', $this->indent . 'If you had the test and it showed you <u>did</u> have it --> 4.c. When was the date of your most recent <b>positive</b> test?', $this->dateOptions);

        $this->XINRegisterRule(
            "A_q4c_date_of_most_recent_positive_test",
            array("A_q4_5_yes_test_showed_i_did_have_it_positive_test{@}=={@}yes"),
            'Required if test showed you <u>had</u> COVID_19'
        );

        $this->addSelect("A_q5_has_anyone_else_living_in_your_home_had_covid_19", "5. Has anyone else living in your home had, or probably had, COVID-19?", self::YES_NO_OPTIONS);
    }

    /**
    * Generates the third page of the form.
    *
    * @return void
    */
    function _page3()
    {
        $this->addHeader("COVID - Child Self Report - Survey");

        $this->form->addElement(
            'static',
            null,
            "<h3><b>Section B. Impacts of the COVID-19 Outbreak on You</b></h3>"
        );

        $q1_options = array(
                       "1_did_not_go_to_healthcare_appointments_concerned"           => "I did not go to healthcare appointments because I was concerned about entering my healthcare provider's office",
                       "2_healthcare_provider_canceled_appointments"                 => "My healthcare provider canceled appointments",
                       "3_healthcare_provider_changed_to_phone_or_online"            => "My healthcare provider changed to phone or online visits",
                       "4_healthcare_provider_told_me_to_self_isolate_or_quarantine" => "My healthcare provider told me to self-isolate or quarantine",
                       "5_none_of_these_apply"                                       => "None of these apply",
                      );

        $q2_options = array(
                       "1_yes"                             => "Yes",
                       "2_no"                              => "No",
                       "3_i_am_not_enrolled_in_any_school" => "I am not enrolled in any school",
                      );

        $this->form->addElement("static", null, "1. In what ways has the COVID-19 outbreak affected your overall healthcare? (<b><i>Mark all that apply</i></b>)");

        foreach ($q1_options as $key => $value) {
            $this->form->addElement("advcheckbox", "B_q1_" . $key, null, $value, null, array("no", "yes"));
            $this->XINRegisterRule(
                "B_q1_{$key}",
                array("B_q1_{$key}{@}=={@}NEVER_REQUIRED"),
                "Not required"
            );
        }

        $this->addSelect("B_q2_did_your_school_close_because_of_covid_19", "2. Did your school close because of the COVID-19 outbreak?", $q2_options);

        $this->addSelect("B_q2a_do_you_usually_receive_free_meals_at_school", $this->indent . "2.a. Do you usually receive free meals at school?", self::YES_NO_OPTIONS);

        $this->XINRegisterRule(
            "B_q2a_do_you_usually_receive_free_meals_at_school",
            array("B_q2_did_your_school_close_because_of_covid_19{@}!={@}3_i_am_not_enrolled_in_any_school"),
            'Required.'
        );

        $this->addSelect("B_q2a1_has_your_school_offered_meals_during_school_closure", $this->indent . $this->indent . "2.a.1. Has your school offered meals during the school closure from COVID-19?", self::YES_NO_OPTIONS);

        $this->XINRegisterRule(
            "B_q2a1_has_your_school_offered_meals_during_school_closure",
            array("B_q2a_do_you_usually_receive_free_meals_at_school{@}=={@}1_yes"),
            'Required.'
        );

        $this->addSelect("B_q2a1a_have_you_been_able_to_get_school_provided_meals", $this->indent . $this->indent . $this->indent . "2.a.1.a. Have you been able to get the school-provided meals during the COVID-19 associated closure?", self::YES_NO_OPTIONS);

        $this->XINRegisterRule(
            "B_q2a1a_have_you_been_able_to_get_school_provided_meals",
            array("B_q2a1_has_your_school_offered_meals_during_school_closure{@}=={@}1_yes"),
            'Required.'
        );

        $this->addSelect("B_q2b_has_your_school_offered_online_learning_while_closed", $this->indent . "2.b. Has your school offered online learning while closed?", self::YES_NO_OPTIONS);

        $this->XINRegisterRule(
            "B_q2b_has_your_school_offered_online_learning_while_closed",
            array("B_q2_did_your_school_close_because_of_covid_19{@}!={@}3_i_am_not_enrolled_in_any_school"),
            'Required.'
        );

        $this->form->addElement(
            'static',
            null,
            $this->indent . $this->indent . "2.b.1. Has your school provided either of the following to support online learning?"
        );

        $this->addSelect("B_q2b1a_has_your_school_provided_free_home_internet_access", $this->indent . $this->indent . $this->indent . "a. Free home internet access", self::YES_NO_OPTIONS);

        $this->XINRegisterRule(
            "B_q2b1a_has_your_school_provided_free_home_internet_access",
            array("B_q2b_has_your_school_offered_online_learning_while_closed{@}=={@}1_yes"),
            'Required.'
        );

        $this->addSelect("B_q2b1b_has_your_school_provided_free_computer_or_tablet", $this->indent . $this->indent . $this->indent . "b. Free computer or tablet", self::YES_NO_OPTIONS);

        $this->XINRegisterRule(
            "B_q2b1b_has_your_school_provided_free_computer_or_tablet",
            array("B_q2b_has_your_school_offered_online_learning_while_closed{@}=={@}1_yes"),
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
        $this->addHeader("COVID - Child Self Report - Survey");

        $this->form->addElement(
            'static',
            null,
            "<h3><b>Section B. Impacts of the COVID-19 Outbreak on You (continued)</b></h3>"
        );

        $q3_options = array(
                       "1_high_speed_broadband_internet"         => "High-speed broadband internet (\"WiFi\") (e.g., DSL, cable, fiberoptic)",
                       "2_dial_up_internet"                      => "Dial-up internet (not WiFi)",
                       "3_smartphone_not_connected_to_home_wifi" => "Smartphone not connected to WiFi network at home (e.g., use cellular, LTE, mobile hotspot, neighbor’s WiFi)",
                       "4_i_do_not_have_internet_access_at_home" => "I do not have internet access at home",
                      );

        $q4_subquestions = array(
                            "q4a_eating"                                             => "a. Eating",
                            "q4b_sleeping"                                           => "b. Sleeping",
                            "q4c_physical_activity"                                  => "c. Physical activity",
                            "q4d_spending_time_outside"                              => "d. Spending time outside",
                            "q4e_spending_time_with_friends_in_person"               => "e. Spending time with friends in-person",
                            "q4f_spending_time_with_friends_remotely"                => "f. Spending time with friends remotely (e.g., online, social media, texting)",
                            "q4g_spending_time_tv_games_social_media_educational"    => "g. Spending time watching TV, playing video/computer games, or using social media for <b><i><u>educational</u></i></b> purposes, including school work",
                            "q4h_spending_time_tv_games_social_media_noneducational" => "h. Spending time watching TV, playing video/computer games, or using social media for <b><i><u>non-educational</u></i></b> purposes",
                           );

        $q4_options = array(
                       "1_less"        => "Less",
                       "2_same_amount" => "Same amount",
                       "3_more"        => "More",
                      );

        $q5_options = array(
                       "1_much_less"     => "Much less socially connected",
                       "2_less"          => "Less socially connected",
                       "3_slightly_less" => "Slightly less socially connected",
                       "4_slightly_more" => "Slightly more socially connected",
                       "5_more"          => "More socially connected",
                       "6_much_more"     => "Much more socially connected",
                      );

        $this->form->addElement("static", null, "3. What type of internet access do you have at home? (<b><i>Mark all that apply</i></b>)");

        foreach ($q3_options as $key => $value) {
            $this->form->addElement("advcheckbox", "B_q3_" . $key, null, $value, null, array("no", "yes"));
            $this->XINRegisterRule(
                "B_q3_{$key}",
                array("B_q3_{$key}{@}=={@}NEVER_REQUIRED"),
                "Not required"
            );
        }

        $this->addSelect("B_q3b_did_you_have_high_speed_broadband_internet_march_1_2020", $this->indent . "3.b. Did you have high-speed broadband internet access at home prior to March 1, 2020?", self::YES_NO_OPTIONS);

        $this->XINRegisterRule(
            "B_q3b_did_you_have_high_speed_broadband_internet_march_1_2020",
            array("B_q3_1_high_speed_broadband_internet{@}=={@}yes"),
            'Required.'
        );

        $this->form->addElement(
            'static',
            null,
            "<i>For rows 4.a through 4.h below, please mark 'Less', 'Same amount', or 'More' for <u>how much</u> you are now engaged in the activity compared to before the COVID-19 outbreak.</i>"
        );

        $this->form->addElement(
            'static',
            null,
            "4. Compared to before the COVID-19 outbreak, how much are you now doing the following:"
        );

        foreach ($q4_subquestions as $key => $value) {
            $this->addSelect("B_" . $key, $value, $q4_options);
        }

        $this->addSelect("B_q5_compared_to_before_covid_do_you_feel", "5. Compared to before the COVID-19 outbreak, do you feel...", $q5_options);
    }

    /**
    * Generates the fifth page of the form.
    *
    * @return void
    */
    function _page5()
    {
        $this->addHeader("COVID - Child Self Report - Survey");

        $this->form->addElement(
            'static',
            null,
            "<h3><b>Section B. Impacts of the COVID-19 Outbreak on You (continued)</b></h3>"
        );

        $q6_options = array(
                       "1_meditation_mindfulness_practices"                 => "Meditation and/or mindfulness practices",
                       "2_engaging_in_more_family_activities"               => "Engaging in more family activities (e.g., games, sports)",
                       "3_eating_more_often_including_snacking"             => "Eating more often,including snacking",
                       "4_increasing_time_reading_or_activities"            => "Increasing time reading books, or doing activities like puzzles and crosswords",
                       "5_drinking_alcohol"                                 => "Drinking alcohol",
                       "6_using_tobacco"                                    => "Using tobacco (e.g., smoking; do not include vaping)",
                       "7_using_marijuana"                                  => "Using marijuana (e.g., smoking, edibles; do not include vaping) or cannabidiol (CBD)",
                       "8_vaping_marijuana"                                 => "Vaping marijuana",
                       "9_vaping_other_substances"                          => "Vaping other substances (e.g., using e-cigarettes, e-juice)",
                       "10_talking_to_healthcare_providers_more_frequently" => "Talking to my healthcare providers more frequently, including mental healthcare provider (e.g., therapist, psychologist, counselor)",
                       "11_volunteer_work"                                  => "Volunteer work",
                       "12_i_have_not_done_any_of_these_things_to_cope"     => "I have not done any of these things to cope with the COVID-19 outbreak",
                      );

        $q7_options = array(
                       "1_extremely_negative"  => "Extremely negative",
                       "2_moderately_negative" => "Moderately negative",
                       "3_somewhat_negative"   => "Somewhat negative",
                       "4_no_impact"           => "No impact",
                       "5_slightly_positive"   => "Slightly positive",
                       "6_moderately_positive" => "Moderately positive",
                       "7_extremely_positive"  => "Extremely positive",
                      );

        $q8_options = array(
                       "1_not_at_all" => "Not at all",
                       "2_rarely"     => "Rarely",
                       "3_sometimes"  => "Sometimes",
                       "4_often"      => "Often",
                       "5_very_often" => "Very often",
                      );

        $this->form->addElement("static", null, "6. What have you done to cope with your stress related to the COVID-19 outbreak? (<b><i>Mark all that apply</i></b>)");

        foreach ($q6_options as $key => $value) {
            $this->form->addElement("advcheckbox", "B_q6_" . $key, null, $value, null, array("no", "yes"));
            $this->XINRegisterRule(
                "B_q6_{$key}",
                array("B_q6_{$key}{@}=={@}NEVER_REQUIRED"),
                "Not required"
            );
        }

        $this->addSelect("B_q7_indicate_covid_19_positive_or_negative_impact_on_your_life", "7. Please indicate the extent to which you view the COVID-19 outbreak as having either a positive or negative impact on your life.", $q7_options);

        $this->addSelect("B_q8_since_covid_19_how_often_happy_satisfied_with_your_life", "8. Since becoming aware of the COVID-19 outbreak, how often have you felt happy and satisfied with your life?", $q8_options);

        $this->form->addFormRule(array(&$this, 'validate_page5'));
    }

    /**
    * Generates the sixth page of the form.
    *
    * @return void
    */
    function _page6()
    {
        $this->addHeader("COVID - Child Self Report - Survey");

        $this->form->addElement(
            'static',
            null,
            "<h3><b>Section B. Impacts of the COVID-19 Outbreak on You (continued)</b></h3>
            <i>Please mark 'Not at all', 'Rarely', 'Sometimes', 'Often', or 'Very often' for how often you have had the experience since becoming aware of the COVID-19 outbreak.</i>"
        );

        $q9_subquestions = array(
                            "q9a_had_difficulty_sleeping"                                => "a. Had difficulty sleeping",
                            "q9b_startled_easily"                                        => "b. Startled easily",
                            "q9c_had_angry_outbursts"                                    => "c. Had angry outbursts",
                            "q9d_felt_a_sense_of_time_slowing_down"                      => "d. Felt a sense of time slowing down",
                            "q9e_felt_in_a_daze"                                         => "e. Felt in a daze",
                            "q9f_tried_to_avoid_thoughts_and_feelings_about_covid_19"    => "f. Tried to avoid thoughts and feelings about COVID-19",
                            "q9g_tried_to_avoid_reading_or_watching_info_about_covid_19" => "g. Tried to avoid reading or watching information about COVID-19",
                            "q9h_had_distressing_dreams_about_covid_19"                  => "h. Had distressing dreams about COVID-19",
                            "q9i_been_distressed_when_something_reminds_me_of_covid_19"  => "i. Been distressed when I see something that reminds me of COVID-19",
                           );

        $q9_options = array(
                       "1_not_at_all" => "Not at all",
                       "2_rarely"     => "Rarely",
                       "3_sometimes"  => "Sometimes",
                       "4_often"      => "Often",
                       "5_very_often" => "Very often",
                      );

        $this->form->addElement(
            'static',
            null,
            "9. Since becoming aware of the COVID-19 outbreak, how often have you..."
        );

        foreach ($q9_subquestions as $key => $value) {
            $this->addSelect("B_" . $key, $value, $q9_options);
        }
    }

    function validate_main_page($values)
    {
         $errors = [];

        if ($values["respondent"] != "other") {
            $this->validate_empty_subquestions($values, ["respondent_specify"], $errors);
        }

         return $errors;
    }

    function validate_page1($values)
    {
        $errors = [];

        $q2_options = array(
                       "1_fever_or_chills",
                       "2_cough",
                       "3_shortness_of_breath",
                       "4_sore_throat",
                       "5_headache",
                       "6_muscle_or_body_aches",
                       "7_runny_nose",
                       "8_fatigue_or_excessive_sleepiness",
                       "9_diarrhea_nausea_or_vomiting",
                       "10_loss_of_sense_of_smell_or_taste",
                       "11_itchy_red_eyes",
                      );

        $q2a_options = array(
                        "1_kept_overnight_in_hospital",
                        "2_saw_healthcare_provider_in_person",
                        "3_spoke_to_healthcare_provider_by_phone_email_online",
                        "4_self_isolated_or_quarantined_at_home",
                       );

        $q2b_options = array(
                        "1_have_contact_with_someone_tested_positive",
                        "2_have_contact_with_someone_who_likely_had",
                        "3_travel_to_different_state_or_country",
                       );

        if ($values["A_q2_12_none_of_the_above"] != null && $values["A_q2_12_none_of_the_above"] != "no") {
            foreach ($q2_options as $q) {
                if ($values["A_q2_" . $q] != null && $values["A_q2_" . $q] != "no") {
                    $this->validate_empty_subquestions($values, ["A_q2_" . $q], $errors, "Cannot select other options when 'None of the Above' option has been selected.");
                }
            }
        }

        if ($values["A_q2a_5_none_of_the_above"] != null && $values["A_q2a_5_none_of_the_above"] != "no") {
            foreach ($q2a_options as $q) {
                if ($values["A_q2a_" . $q] != null && $values["A_q2a_" . $q] != "no") {
                    $this->validate_empty_subquestions($values, ["A_q2a_" . $q], $errors, "Cannot select other options when 'None of the Above' option has been selected.");
                }
            }
        }

        if ($values["A_q2b_4_none_of_the_above"] != null && $values["A_q2b_4_none_of_the_above"] != "no") {
            foreach ($q2b_options as $q) {
                if ($values["A_q2b_" . $q] != null && $values["A_q2b_" . $q] != "no") {
                    $this->validate_empty_subquestions($values, ["A_q2b_" . $q], $errors, "Cannot select other options when 'None of the Above' option has been selected.");
                }
            }
        }

        return $errors;
    }

    function validate_page3($values)
    {
        $errors = [];

        if ($values["B_q2_did_your_school_close_because_of_covid_19"] == "3_i_am_not_enrolled_in_any_school") {
            $this->validate_empty_subquestions($values, ["B_q2a_do_you_usually_receive_free_meals_at_school"], $errors);
            $this->validate_empty_subquestions($values, ["B_q2a1_has_your_school_offered_meals_during_school_closure"], $errors);
            $this->validate_empty_subquestions($values, ["B_q2a1a_have_you_been_able_to_get_school_provided_meals"], $errors);
            $this->validate_empty_subquestions($values, ["B_q2b_has_your_school_offered_online_learning_while_closed"], $errors);
            $this->validate_empty_subquestions($values, ["B_q2b1a_has_your_school_provided_free_home_internet_access"], $errors);
            $this->validate_empty_subquestions($values, ["B_q2b1b_has_your_school_provided_free_computer_or_tablet"], $errors);
        }

        if ($values["B_q2a_do_you_usually_receive_free_meals_at_school"] == "2_no") {
            $this->validate_empty_subquestions($values, ["B_q2a1_has_your_school_offered_meals_during_school_closure"], $errors);
            $this->validate_empty_subquestions($values, ["B_q2a1a_have_you_been_able_to_get_school_provided_meals"], $errors);
        }

        if ($values["B_q2a1_has_your_school_offered_meals_during_school_closure"] == "2_no") {
            $this->validate_empty_subquestions($values, ["B_q2a1a_have_you_been_able_to_get_school_provided_meals"], $errors);
        }

        return $errors;
    }

    function validate_page5($values)
    {
        $errors = [];

        $q6_options = array(
                       "1_meditation_mindfulness_practices",
                       "2_engaging_in_more_family_activities",
                       "3_eating_more_often_including_snacking",
                       "4_increasing_time_reading_or_activities",
                       "5_drinking_alcohol",
                       "6_using_tobacco",
                       "7_using_marijuana",
                       "8_vaping_marijuana",
                       "9_vaping_other_substances",
                       "10_talking_to_healthcare_providers_more_frequently",
                       "11_volunteer_work",
                      );

        if ($values["B_q6_12_i_have_not_done_any_of_these_things_to_cope"] != null && $values["B_q6_12_i_have_not_done_any_of_these_things_to_cope"] != "no") {
            foreach ($q6_options as $q) {
                if ($values["B_q6_" . $q] != null && $values["B_q6_" . $q] != "no") {
                    $this->validate_empty_subquestions($values, ["B_q6_" . $q], $errors, "Cannot select other options when 'I have not done any of these things to cope with the COVID-19 outbreak' option has been selected.");
                }
            }
        }

        return $errors;
    }
}
