<?php
/**
 * This file contains the NDB_BVL_Instrument_TSI_FU_DS_Infant class
 *
 * PHP Version 7
 *
 * @category Instrument
 * @package  IBIS
 * @author   Tanishq Bhatia <tanishq.bhatia@mcin.ca>
 * @license  http://www.gnu.org/licenses/gpl-3.0.txt GPLv3
 * @link     https://www.github.com/aces/IBIS/
 */

/**
 * Creates the form elements for the TSI-FU DS-Infant - Telephone Screening Interview - Follow-Up - DS-Infant
 *
 * @category Instrument
 * @package  Neuropsych
 * @author   Tanishq Bhatia <tanishq.bhatia@mcin.ca>
 * @license  http://www.gnu.org/licenses/gpl-3.0.txt GPLv3
 * @link     https://www.github.com/aces/IBIS/
 */
class NDB_BVL_Instrument_TSI_FU_DS_Infant extends NDB_BVL_Instrument
{
    use LegacyInstrumentTrait;
    use instrument_validator;

    var $ValidityEnabled  = false;
    var $ValidityRequired = false;

    const YES_NO_NA_OPTIONS = array(
                               null           => "",
                               "yes"          => "Yes",
                               "no"           => "No",
                               "not_answered" => "Not Answered",
                              );

    const YES_NO_OPTIONS = array(
                            null  => "",
                            "yes" => "Yes",
                            "no"  => "No",
                           );

    const GENDER_OPTIONS = array(
                            null     => "",
                            "male"   => "Male",
                            "female" => "Female",
                           );

    const HOUSEHOLD_SES_OPTIONS = array(
                                   null            => '',
                                   'less_than_25K' => 'less than $24,999',
                                   '25K-35K'       => '$25,000 - 34,999',
                                   '35K-50K'       => '$35,000 - 49,999',
                                   '50K-75K'       => '$50,000 - 74,999',
                                   '75K-100K'      => '$75,000 - 99,999',
                                   '100K-150K'     => '$100,000 - 149,999',
                                   '150K-200K'     => '$150,000 - 199,999',
                                   'over_200K'     => 'over $200,000',
                                  );

    /**
     * Sample SQL statement for test_names table and instrument subtests table
     *
     * INSERT INTO test_names (Test_name, Full_name, Sub_Group, isDirectEntry) VALUES ('TSI_FU_DS_Infant', "Telephone Screening Interview - Follow-Up - DS-Infant", 9, 0);
     * INSERT INTO instrument_subtests (Test_name, Subtest_name, Description, Order_number) VALUES ('TSI_FU_DS_Infant','TSI_FU_DS_Infant_page1', "Page 1", 1);
     * INSERT INTO instrument_subtests (Test_name, Subtest_name, Description, Order_number) VALUES ('TSI_FU_DS_Infant','TSI_FU_DS_Infant_page2', "Page 2", 2);
     * INSERT INTO instrument_subtests (Test_name, Subtest_name, Description, Order_number) VALUES ('TSI_FU_DS_Infant','TSI_FU_DS_Infant_page3', "Page 3", 3);
     * INSERT INTO instrument_subtests (Test_name, Subtest_name, Description, Order_number) VALUES ('TSI_FU_DS_Infant','TSI_FU_DS_Infant_page4', "Page 4", 4);
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
    function setup(?string $commentID = NULL, ?string $page = NULL): void
    {
        $this->formType = "XIN";
        $this->form     = new LorisForm('TSI_FU_DS_Infant_form');
        $this->page     = $page;            // page label (number or
        // string - used by
        // user-defined child classes)

        // set the object properties
        $this->testName = "TSI_FU_DS_Infant";           // test_names.Test_name
        $this->table    = 'TSI_FU_DS_Infant';           // name of database table corresponding to instrument
        // data keyed by commentID
        $this->commentID = $commentID;

        //The array of dates/timestamps to convert to database dates/timestamps
        //Any LorisForm date elements must be listed here
        $this->dateTimeFields = array("Date_taken");

        //The array of selects with multiple answers allowed
        //Any LorisForm multiple selects must be listed here
        $this->_selectMultipleElements = array("inf_medhist_q6_metal_options");

        // required fields for data entry completion status
        $this->_requiredElements = array(
                                    "are_bio_parents_living_in_same_home",
                                    "inf_devfactors_q1_specific_neurological_problems",
                                    "inf_medhist_q1_had_serious_medical_or_surgical_problems",
                                    "likelihood_of_child_sleeping_through_a_scan_rating",
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
        if (preg_match("/TSI_FU_DS_Infant(_page[0-9]+)/", $this->page, $matches)) {
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
        $this->addHeader("Telephone Screening Interview - Follow-Up - DS-Infant");

        // automatically adds examiner & date of administration
        $this->_addMetadataFields();

        $config =& NDB_Config::singleton();
    }

    /**
     * Page 1
     *
     * @return void
     */
    function _page1()
    {
        $this->addHeader("Telephone Screening Interview - Follow-Up - DS-Infant");

        $page1_questions = array(
                            "are_bio_parents_living_in_same_home" => "Are biological parents living in the same home?",
                            "are_parents_divorced_or_separated"   => "Are parents divorced or separated?",
                           );

        $pii_address = array(
                        "Street Address",
                        "City",
                        "State",
                        "Zip Code",
                       );

        foreach ($page1_questions as $field => $label) {
            $this->addSelect($field, $label, self::YES_NO_OPTIONS);

            if ($field == "are_bio_parents_living_in_same_home") {
                $this->addSelect("if_not_in_same_home_childs_primary_address_with", $this->indent . "If biological parents not in the same home, child’s primary address is with", array(null => "", "mother" => "Mother", "father" => "Father"));
                $this->XINRegisterRule("if_not_in_same_home_childs_primary_address_with", array("are_bio_parents_living_in_same_home{@}=={@}no"), 'Required if no');
            }
        }

        $this->form->addElement('static', null, null);

        $this->form->addElement('static', null, "<h4>Has your address changed since your last visit? If yes, provide updated address and date effective.</h4>");

        // CHILD PRIMARY ADDRESS
        $this->form->addElement('static', null, "CHILD PRIMARY ADDRESS");

        foreach ($pii_address as $field) {
            $this->form->addElement('text', null, $this->indent . $field, ['disabled' => 'disabled']);
        }

        $this->form->addElement('text', 'when_did_you_move_primary', $this->indent . "When did you move?");
        $this->XINRegisterRule(
            "when_did_you_move_primary",
            array("when_did_you_move_primary{@}=={@}NEVER_REQUIRED"),
            "Not required"
        );

        $this->form->addElement('static', null, null);

        $this->form->addElement('static', null, "<h4>If applicable, did child’s secondary address change? If yes, provide updated address and date effective.</h4>");

        // SECONDARY ADDRESS
        $this->form->addElement('static', null, "SECONDARY ADDRESS<br>(if 2 households)");

        foreach ($pii_address as $field) {
            $this->form->addElement('text', null, $this->indent . $field, ['disabled' => 'disabled']);
        }

        $this->form->addElement('text', 'when_did_you_move_secondary', $this->indent . "When did you move?");
        $this->XINRegisterRule(
            "when_did_you_move_secondary",
            array("when_did_you_move_secondary{@}=={@}NEVER_REQUIRED"),
            "Not required"
        );

        $this->form->addElement('static', null, null);

        $this->form->addElement('static', null, "<h4>Household income change since last visit?</h4>");

        $this->addSelect("household_ses_mother_or_combined", "Household SES Mother or combined", self::HOUSEHOLD_SES_OPTIONS);
        $this->addSelect("household_ses_father_if_2_households", "Household SES Father if 2 households", self::HOUSEHOLD_SES_OPTIONS);

        $this->form->addElement('static', null, null);

        $this->form->addElement('static', null, "<h4>Any new siblings or changes in medical or psychiatric status of existing siblings?</h4>");

        $this->form->addElement('static', null, "<h4><b>New Siblings or sibling with change in status</b></h4>");

        $sibling_status = array(
                           null => '',
                           "ns" => "NS",
                           "nd" => "ND",
                          );

        $sibling_options = array(
                            null      => '',
                            "half"    => "Half",
                            "full"    => "Full",
                            "step"    => "Step",
                            "adopted" => "Adopted",
                           );

        // INFANT'S SIBLINGS
        $group[] =& $this->form->createElement(
            "static",
            null,
            null,
            "First Name"
        );
        $group[] =& $this->form->createElement(
            "static",
            null,
            null,
            "Last Name"
        );
        $group[] =& $this->form->createElement(
            "static",
            null,
            null,
            "DOB"
        );
        $group[] =& $this->form->createElement(
            "static",
            null,
            null,
            "M/F"
        );
        $group[] =& $this->form->createElement(
            "static",
            null,
            null,
            "Any developmental disabilities or chronic medical diagnoses?"
        );
        $group[] =& $this->form->createElement(
            "static",
            null,
            null,
            "New sibling (NS) or new diagnosis (ND)?"
        );
        $group[] =& $this->form->createElement(
            "static",
            null,
            null,
            "Half/full/step/adopted"
        );
        $group[] =& $this->form->createElement(
            "static",
            null,
            null,
            "Live in home?"
        );
        $this->addGroup(
            $group,
            "page1_sibling_headers",
            null,
            $this->_GUIDelimiter,
            false
        );
        unset($group);

        for ($i = 1; $i <= 3; $i++) {
            $group[] =& $this->createText(
                null,
                "",
                ['disabled' => 'disabled']
            );
            $group[] =& $this->createText(
                null,
                "",
                ['disabled' => 'disabled']
            );
            $group[] =& $this->createDate(
                "sibling_{$i}_dob",
                ""
            );
            $group[] =& $this->createSelect(
                "sibling_{$i}_gender",
                "M/F",
                self::GENDER_OPTIONS
            );
            $group[] =& $this->createText(
                "sibling_{$i}_diagnoses",
                null,
                ""
            );
            $group[] =& $this->createSelect(
                "sibling_{$i}_status",
                "NS/ND",
                $sibling_status
            );
            $group[] =& $this->createSelect(
                "sibling_{$i}_type",
                "Half/full/step/adopted",
                $sibling_options
            );
            $group[] =& $this->createSelect(
                "sibling_{$i}_live_in_home",
                "Live in home?",
                self::YES_NO_OPTIONS
            );

            $this->XINRegisterRule(
                "sibling_" . $i . "_dob",
                array("sibling_{$i}_dob{@}=={@}NEVER_REQUIRED"),
                "Never required.",
                "sibling_" . $i . "_group"
            );
            $this->XINRegisterRule(
                "sibling_" . $i . "_gender",
                array("sibling_{$i}_gender{@}=={@}NEVER_REQUIRED"),
                "Never required.",
                "sibling_" . $i . "_group"
            );
            $this->XINRegisterRule(
                "sibling_" . $i . "_diagnoses",
                array("sibling_{$i}_diagnoses{@}=={@}NEVER_REQUIRED"),
                "Never required.",
                "sibling_" . $i . "_group"
            );
            $this->XINRegisterRule(
                "sibling_" . $i . "_status",
                array("sibling_{$i}_status{@}=={@}NEVER_REQUIRED"),
                "Never required.",
                "sibling_" . $i . "_group"
            );
            $this->XINRegisterRule(
                "sibling_" . $i . "_type",
                array("sibling_{$i}_type{@}=={@}NEVER_REQUIRED"),
                "Never required.",
                "sibling_" . $i . "_group"
            );
            $this->XINRegisterRule(
                "sibling_" . $i . "_live_in_home",
                array("sibling_{$i}_live_in_home{@}=={@}NEVER_REQUIRED"),
                "Never required.",
                "sibling_" . $i . "_group"
            );

            $this->addGroup(
                $group,
                "sibling_" . $i . "_group",
                null,
                $this->_GUIDelimiter,
                false
            );
            unset($group);
        }

        $this->form->addFormRule(array(&$this, 'validate_page1'));
    }

    /**
     * Page 2
     *
     * @return void
     */
    function _page2()
    {
        $this->addHeader("Telephone Screening Interview - Follow-Up - DS-Infant");

        $this->form->addElement('static', null, "<h4><b>Any changes in developmental factors in infant</b></h4>");

        $this->form->addElement('static', null, null);

        // Q1
        $this->addSelect("inf_devfactors_q1_specific_neurological_problems", "1. Any new specific neurological problems diagnosed in infant?", self::YES_NO_OPTIONS);
        $this->form->addElement('text', "inf_devfactors_q1_list", $this->indent . 'If yes, list:');
        $this->XINRegisterRule("inf_devfactors_q1_list", array("inf_devfactors_q1_specific_neurological_problems{@}=={@}yes"), 'Required if yes');

        // Q2
        $this->addSelect("inf_devfactors_q2_diagnosed_suspected_genetic_conditions", "2. Any new diagnosed/suspected genetic conditions other than DS?", self::YES_NO_OPTIONS);
        $this->form->addElement('text', "inf_devfactors_q2_list", $this->indent . 'If yes, list:');
        $this->XINRegisterRule("inf_devfactors_q2_list", array("inf_devfactors_q2_diagnosed_suspected_genetic_conditions{@}=={@}yes"), 'Required if yes');

        // Q3
        $this->addSelect("inf_devfactors_q3_genetic_testing_completed", "3. Any new genetic testing completed?", self::YES_NO_OPTIONS);

        // Q4
        $this->addSelect("inf_devfactors_q4_had_seizures", "4. Has infant had any seizures since your last visit?", self::YES_NO_OPTIONS);

        // Q5
        $this->addSelect("inf_devfactors_q5_central_nervous_system_problems", "5. Any new central nervous system problems?", self::YES_NO_OPTIONS);
        $this->form->addElement('text', "inf_devfactors_q5_list", $this->indent . 'If yes, list:');
        $this->XINRegisterRule("inf_devfactors_q5_list", array("inf_devfactors_q5_central_nervous_system_problems{@}=={@}yes"), 'Required if yes');

        // Q5A
        $this->addSelect("inf_devfactors_q5a_history_of_head_injury", "5a. Has infant had a head injury since last visit?", self::YES_NO_OPTIONS);
        $this->form->addElement('text', "inf_devfactors_q5a_details", $this->indent . 'If yes, specify details:');
        $this->XINRegisterRule("inf_devfactors_q5a_details", array("inf_devfactors_q5a_history_of_head_injury{@}=={@}yes"), 'Required if yes');

        // Q7
        $this->addSelect("inf_devfactors_q7_significant_hearing_vision_problems", "7. Any changes in hearing or vision since last visit?", self::YES_NO_OPTIONS);

        // Q9
        $this->addSelect("inf_devfactors_q9_problems_with_sleep_apnea_or_breathing", "9. Any new problems with sleep apnea or breathing during sleep?", self::YES_NO_OPTIONS);

        // Q10
        $this->addSelect("inf_devfactors_q10_gastrointestinal_condition", "10. Any newly diagnosed gastrointestinal conditions?", self::YES_NO_OPTIONS);

        $q11_weaned_options = array(
            null           => "",
            "weaned"       => "Weaned",
            "not_weaned"   => "Not Weaned",
            "not_answered" => "Not Answered",
           );

        // Q11
        $this->addSelect("inf_devfactors_q11_breastfeeding", "11. Have you ever or are you breastfeeding your infant?", self::YES_NO_OPTIONS);

        $this->addSelect("inf_devfactors_q11b_if_weaned_how_long_breastfeed", "11b. If weaned, how long did you breastfeed?", $q11_weaned_options);

        $this->form->addElement('text', "inf_devfactors_q11b_how_long_breastfeed_weeks", $this->indent . 'Weeks');
        $this->form->addElement('text', "inf_devfactors_q11b_how_long_breastfeed_months", $this->indent . 'Months');

        $this->XINRegisterRule("inf_devfactors_q11b_how_long_breastfeed_weeks", array('inf_devfactors_q11b_if_weaned_how_long_breastfeed{@}=={@}weaned'), 'Required if weaned');
        $this->XINRegisterRule("inf_devfactors_q11b_how_long_breastfeed_months", array('inf_devfactors_q11b_if_weaned_how_long_breastfeed{@}=={@}weaned'), 'Required if weaned');

        // Q15
        $q15_subquestions = array(
                             "intellectual_disability" => "Intellectual Disability",
                             "schizophrenia"           => "Schizophrenia",
                             "bipolar_disorder"        => "Bipolar Disorder",
                             "psychosis"               => "Psychosis",
                             "ocd"                     => "Obsessive Compulsive Disorder (OCD)",
                             "tourettes_disorder"      => "Tourettes Disorder",
                            );

        $this->addSelect("inf_devfactors_q15_first_degree_relative", "15. Any first degree relative (mom, dad, or full siblings) recently diagnosed with:", self::YES_NO_OPTIONS);

        $group[] =& $this->form->createElement(
            "static",
            null,
            null,
            ""
        );
        $group[] =& $this->form->createElement(
            "static",
            null,
            null,
            "Mother"
        );
        $group[] =& $this->form->createElement(
            "static",
            null,
            null,
            "Father"
        );
        $group[] =& $this->form->createElement(
            "static",
            null,
            null,
            "Full sibling"
        );
        $this->addGroup(
            $group,
            "page2_headers",
            null,
            $this->_GUIDelimiter,
            false
        );
        unset($group);

        foreach ($q15_subquestions as $key => $value) {
            $group[] = $this->createLabel($value);

            $group[] =& $this->createSelect(
                "inf_devfactors_q15_{$key}_mother",
                "Mother",
                self::YES_NO_OPTIONS
            );
            $group[] =& $this->createSelect(
                "inf_devfactors_q15_{$key}_father",
                "Father",
                self::YES_NO_OPTIONS
            );
            $group[] =& $this->createSelect(
                "inf_devfactors_q15_{$key}_full_sibling",
                "Full Sibling",
                self::YES_NO_OPTIONS
            );

            $this->XINRegisterRule(
                "inf_devfactors_q15_{$key}_mother",
                array("inf_devfactors_q15_first_degree_relative{@}=={@}yes"),
                $this->indent . "Required if yes.",
                "page2_" . $key . "_group"
            );
            $this->XINRegisterRule(
                "inf_devfactors_q15_{$key}_father",
                array("inf_devfactors_q15_first_degree_relative{@}=={@}yes"),
                $this->indent . "Required if yes.",
                "page2_" . $key . "_group"
            );
            $this->XINRegisterRule(
                "inf_devfactors_q15_{$key}_full_sibling",
                array("inf_devfactors_q15_first_degree_relative{@}=={@}yes"),
                $this->indent . "Required if yes.",
                "page2_" . $key . "_group"
            );

            $this->addGroup(
                $group,
                "page2_" . $key . "_group",
                null,
                $this->_GUIDelimiter,
                false
            );
            unset($group);
        }

        $this->addSelect("inf_devfactors_q15_second_degree_relatives_with_any", $this->indent . "2 or more second degree relatives with any of the above?", self::YES_NO_OPTIONS);

        $this->XINRegisterRule("inf_devfactors_q15_second_degree_relatives_with_any", array("inf_devfactors_q15_first_degree_relative{@}=={@}yes"), 'Required if yes');

        $this->form->addElement(
            'static',
            null,
            "<h6><i>If diagnosed with one of these after inclusion into the study, DO NOT exclude, BUT PLEASE FLAG THIS IN THE DATABASE FOR ANALYSIS</i></h6>"
        );

        $this->form->addFormRule(array(&$this, 'validate_page2'));
    }

    /**
     * Page 3
     *
     * @return void
     */
    function _page3()
    {
        $this->addHeader("Telephone Screening Interview - Follow-Up - DS-Infant");

        $this->form->addElement('static', null, "<h4><b>Updated Medical History</b></h4>");

        $this->form->addElement('static', null, null);

        $q6_options = array(
                       null                             => '',
                       "metallic_ear_tubes"             => "Metallic Ear Tubes",
                       "pacemaker"                      => "Pacemaker",
                       "vascular_stints"                => "Vascular Stints",
                       "other_metal_implants_or_braces" => "Other metal implants or braces",
                       "sternal_wires"                  => "Sternal wires (allowed for MRI is 6 weeks post-surgery)",
                       "pacer_wires"                    => "Pacer wires (exclusionary)",
                      );

        // Q1
        $this->addSelect("inf_medhist_q1_had_serious_medical_or_surgical_problems", "1. Has infant had any serious medical or surgical problems since last visit?", self::YES_NO_OPTIONS);

        $this->form->addElement('text', "inf_medhist_q1_list", $this->indent . 'If yes, list:');
        $this->XINRegisterRule("inf_medhist_q1_list", array("inf_medhist_q1_had_serious_medical_or_surgical_problems{@}=={@}yes"), 'Required if yes');

        // Q2
        $this->addSelect("inf_medhist_q2_been_hospitalized", "2. Has infant been hospitalized since last visit?", self::YES_NO_OPTIONS);
        $this->form->addElement('text', "inf_medhist_q2_list", $this->indent . 'If yes, list:');
        $this->XINRegisterRule("inf_medhist_q2_list", array("inf_medhist_q2_been_hospitalized{@}=={@}yes"), 'Required if yes');

        // Q5
        $this->addSelect("inf_medhist_q5_had_surgery", "5. Has infant had any surgery since last visit?", self::YES_NO_OPTIONS);
        $this->form->addElement('text', "inf_medhist_q5_list_with_dates", $this->indent . 'If yes, list with dates:');
        $this->XINRegisterRule("inf_medhist_q5_list_with_dates", array("inf_medhist_q5_had_surgery{@}=={@}yes"), 'Required if yes');

        // Q6
        $this->addSelect("inf_medhist_q6_have_metal_plates_clips_etc_from_surgery", "6. Does X have any metal plates, clips, etc. from surgery?", self::YES_NO_OPTIONS);
        $this->addSelect("inf_medhist_q6_metal_options", $this->indent . "", $q6_options, array("multiple"));
        $this->XINRegisterRule("inf_medhist_q6_metal_options", array("inf_medhist_q6_have_metal_plates_clips_etc_from_surgery{@}=={@}yes"), 'Required if yes');

        // Q7
        $this->addSelect("inf_medhist_q7_taken_medications_since_birth", "7. Has X taken medications since last visit?", self::YES_NO_OPTIONS);
        $this->form->addElement('text', "inf_medhist_q7_list", $this->indent . 'If yes, list:');
        $this->XINRegisterRule("inf_medhist_q7_list", array("inf_medhist_q7_taken_medications_since_birth{@}=={@}yes"), 'Required if yes');

        // Q8
        $this->addSelect("inf_medhist_q8_seen_doctor_for_more_than_well_baby_visit", "8. Since last visit, has infant seen doctor for more than a well-baby visit?", self::YES_NO_OPTIONS);
        $this->form->addElement('text', "inf_medhist_q8_list", $this->indent . 'If yes, list:');
        $this->XINRegisterRule("inf_medhist_q8_list", array("inf_medhist_q8_seen_doctor_for_more_than_well_baby_visit{@}=={@}yes"), 'Required if yes');

        // Q10
        $this->addSelect("inf_medhist_q10_had_anesthesia_or_other_sedation", "10. Has X had anesthesia or other forms of sedation since last visit?", self::YES_NO_OPTIONS);

        // Q11
        $this->addSelect("inf_medhist_q11_nap_during_the_day", "11. Does infant nap during the day?", self::YES_NO_OPTIONS);
        $this->form->addElement('text', "inf_medhist_q11_when", $this->indent . 'If yes, when?');
        $this->form->addElement('text', "inf_medhist_q11_how_long", $this->indent . 'If yes, how long:');
        $this->XINRegisterRule("inf_medhist_q11_when", array("inf_medhist_q11_nap_during_the_day{@}=={@}yes"), 'Required if yes');
        $this->XINRegisterRule("inf_medhist_q11_how_long", array("inf_medhist_q11_nap_during_the_day{@}=={@}yes"), 'Required if yes');

        $this->addBasicText("inf_medhist_q12_what_time_does_X_go_to_sleep_at_night", "12. What time does X go to sleep at night?");

        $scale_of_1_to_10 = array(
                             null                  => "",
                             "0_not_at_all_likely" => "0 - Not at all likely",
                             "1"                   => "1",
                             "2"                   => "2",
                             "3"                   => "3",
                             "4"                   => "4",
                             "5"                   => "5",
                             "6"                   => "6",
                             "7"                   => "7",
                             "8"                   => "8",
                             "9"                   => "9",
                             "10_very_likely"      => "10 - Very likely",
                            );

        $this->addSelect("likelihood_of_child_sleeping_through_a_scan_rating", "On a scale of 1 – 10, please rate the likelihood of your child sleeping through a scan.", $scale_of_1_to_10);

        $this->form->addElement('static', null, "<b>***Must fill out this table to document infant is eligible to continue in study.</b>");

        $this->form->addElement(
            'static',
            null,
            "<b>***Unless contraindication for MRI or something comes up that has a significant impact on brain development,
            very little will exclude families after they have been seen for their first visit.
            However, anything that would have originally excluded them should be flagged in the DCC database for analysis.
            This step must be completed.</b>"
        );

        $this->form->addFormRule(array(&$this, 'validate_page3'));
    }

    /**
     * Page 4
     *
     * @return void
     */
    function _page4()
    {
        $this->addHeader("Telephone Screening Interview - Follow-Up - DS-Infant");

        $this->form->addElement('static', null, "<h4><b>For Research Staff to Complete</b></h4>");

        $this->form->addElement('static', null, null);

        $research_staff_questions = array(
                                     "q1_infant_meets_any_medical_neurological_exclusion_criteria" => "1. This infant meets any of the medical or neurological exclusion criteria for this study.",
                                     "q2_subject_has_evidence_for_contraindication_to_MRI"         => "2. This subject has evidence for contraindication to MRI.",
                                     "q3_additional_documentation_required_to_MRI"                 => "3. Additional documentation required to approve MRI safety. Medical records sent for review.",
                                     "q4_additional_documentation_completed"                       => "4. Additional documentation completed and submitted to MRI tech.",
                                     "q5_proceed_to_next_level_beyond_screening"                   => "5. Proceed to next level beyond screening.",
                                    );

        foreach ($research_staff_questions as $key => $question) {
            $this->addSelect($key, $question, self::YES_NO_OPTIONS);
        }

        $this->addTextAreaElement("if_reviewed_decision", "If reviewed, what was reviewed and what decision was made?");

        $this->addBasicDate('date_received_exclusion_review_decision', "Date received exclusion review decision:");

        $this->XINRegisterRule(
            "date_received_exclusion_review_decision",
            array("if_reviewed_decision{@}!={@}"),
            'Required.'
        );
    }

    function validate_page1($values)
    {
        $errors = [];

        if ($values["are_bio_parents_living_in_same_home"] != "no") {
            $this->validate_empty_subquestions($values, ["if_not_in_same_home_childs_primary_address_with"], $errors);
        }

        return $errors;
    }

    function validate_page2($values)
    {
        $errors = [];

        if ($values["inf_devfactors_q2_diagnosed_suspected_genetic_conditions"] != "yes") {
            $this->validate_empty_subquestions($values, ["inf_devfactors_q2_list"], $errors);
        }

        if ($values["inf_devfactors_q3_genetic_testing_completed"] != "yes") {
            $this->validate_empty_subquestions($values, ["inf_devfactors_q3_when_and_where"], $errors);
        }

        if ($values["inf_devfactors_q4_had_seizures"] != "yes") {
            $this->validate_empty_subquestions($values, ["inf_devfactors_q4_list"], $errors);
        }

        if ($values["inf_devfactors_q7_significant_hearing_vision_problems"] != "yes") {
            $this->validate_empty_subquestions($values, ["inf_devfactors_q7_list"], $errors);
        }

        if ($values["inf_devfactors_q9_problems_with_sleep_apnea_or_breathing"] != "yes") {
            $this->validate_empty_subquestions($values, ["inf_devfactors_q9_list"], $errors);
        }

        if ($values["inf_devfactors_q10_gastrointestinal_condition"] != "yes") {
            $this->validate_empty_subquestions($values, ["inf_devfactors_q10_list"], $errors);
        }

        if ($values["inf_devfactors_q11b_if_weaned_how_long_breastfeed"] != "weaned") {
            $this->validate_empty_subquestions($values, ["inf_devfactors_q11b_how_long_breastfeed_weeks"], $errors);
            $this->validate_empty_subquestions($values, ["inf_devfactors_q11b_how_long_breastfeed_months"], $errors);
        }

        $this->validate_positive_numeric($values, "inf_devfactors_q11b_how_long_breastfeed_weeks", $errors);
        $this->validate_positive_numeric($values, "inf_devfactors_q11b_how_long_breastfeed_months", $errors);

        $q15_subquestions = array(
                             "intellectual_disability",
                             "schizophrenia",
                             "bipolar_disorder",
                             "psychosis",
                             "ocd",
                             "tourettes_disorder",
                            );

        foreach ($q15_subquestions as $key) {
            if ($values["inf_devfactors_q15_first_degree_relative"] != "yes" && ($values["inf_devfactors_q15_" . $key . "_mother"] != "" || $values["inf_devfactors_q15_" . $key . "_father"] != "" || $values["inf_devfactors_q15_" . $key . "_full_sibling"] != "")) {
                $errors["page3_" . $key . "_group"] = $this->indent . "This field should be left blank OR response in the related question should be changed.";
            }
        }

        if ($values["inf_devfactors_q15_first_degree_relative"] != "yes") {
            $this->validate_empty_subquestions($values, ["inf_devfactors_q15_second_degree_relatives_with_any"], $errors);
        }

        return $errors;
    }

    function validate_page3($values)
    {
        $errors = [];

        if ($values["inf_medhist_q1_had_serious_medical_or_surgical_problems"] != "yes") {
            $this->validate_empty_subquestions($values, ["inf_medhist_q1_list"], $errors);
        }

        if ($values["inf_medhist_q2_been_hospitalized"] != "yes") {
            $this->validate_empty_subquestions($values, ["inf_medhist_q2_list"], $errors);
        }

        if ($values["inf_medhist_q5_had_surgery"] != "yes") {
            $this->validate_empty_subquestions($values, ["inf_medhist_q5_list_with_dates"], $errors);
        }

        if ($values["inf_medhist_q7_taken_medications_since_birth"] != "yes") {
            $this->validate_empty_subquestions($values, ["inf_medhist_q7_list"], $errors);
        }

        if ($values["inf_medhist_q8_seen_doctor_for_more_than_well_baby_visit"] != "yes") {
            $this->validate_empty_subquestions($values, ["inf_medhist_q8_list"], $errors);
        }

        if ($values["inf_medhist_q11_nap_during_the_day"] != "yes") {
            $this->validate_empty_subquestions($values, ["inf_medhist_q11_when"], $errors);
            $this->validate_empty_subquestions($values, ["inf_medhist_q11_how_long"], $errors);
        }

        return $errors;
    }

    function validate_positive_numeric($values, $question, &$errors)
    {
        if (isset($values[$question])) {
            $user_input = $values[$question];
            if ((!is_numeric($user_input) || (is_numeric($user_input) && $user_input < 0)) && $user_input != "") {
                $errors[$question] = "Specify a positive number";
            }
        }
    }
}
?>