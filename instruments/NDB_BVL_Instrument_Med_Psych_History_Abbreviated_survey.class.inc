<?php
/**
 * This file contains the NDB_BVL_Instrument_Med_Psych_History_Abbreviated_survey class
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
 * Creates the form elements for the Med_Psych_History_Abbreviated_survey instrument
 *
 * @category Instrument
 * @package  Neuropsych
 * @author   Suzanne Lee <suzannelee.mcin@gmail.com>
 * @license  http://www.gnu.org/licenses/gpl-3.0.txt GPLv3
 * @link     https://www.github.com/aces/IBIS/
 */
class NDB_BVL_Instrument_Med_Psych_History_Abbreviated_survey extends NDB_BVL_Instrument
{
    use LegacyInstrumentTrait;
    use instrument_validator;

    var $ValidityEnabled   = true;
    var $ValidityRequired  = false;

    /**
     * Sample SQL statement for test_names table and instrument subtests table
     *
     * INSERT INTO test_names (Test_name, Full_name, Sub_Group, isDirectEntry) VALUES ('Med_Psych_History_Abbreviated_survey', "Medical and Psychiatry Form - Abbreviated - Survey", 1, 1);
     * INSERT INTO instrument_subtests (Test_name, Subtest_name, Description, Order_number) VALUES ('Med_Psych_History_Abbreviated_survey','Med_Psych_History_Abbreviated_survey_page1', "Page 1", 1);
     * INSERT INTO instrument_subtests (Test_name, Subtest_name, Description, Order_number) VALUES ('Med_Psych_History_Abbreviated_survey','Med_Psych_History_Abbreviated_survey_page2', "Page 2", 2);
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
        $this->form     = new LorisForm('Med_Psych_History_Abbreviated_survey_form');
        $this->page     = $page;            // page label (number or
        // string - used by
        // user-defined child classes)

        // set the object properties
        $this->testName = "Med_Psych_History_Abbreviated_survey";           // test_names.Test_name
        $this->table    = 'Med_Psych_History_Abbreviated_survey';           // name of database table corresponding to instrument
        // data keyed by commentID
        $this->commentID = $commentID;

        //The array of dates/timestamps to convert to database dates/timestamps
        //Any LorisForm date elements must be listed here
        $this->dateTimeFields = array(
                                 "Date_taken",
                                 "q1_b_date_of_birth_pregnancy_1",
                                 "q1_b_date_of_birth_pregnancy_2",
                                 "q1_b_date_of_birth_pregnancy_3",
                                 "q1_b_date_of_birth_pregnancy_4",
                                 "q1_b_date_of_birth_pregnancy_5",
                                 "q1_b_date_of_birth_pregnancy_6",
                                 "q1_b_date_of_birth_pregnancy_7",
                                 "q1_b_date_of_birth_pregnancy_8",
                                 "q1_b_date_of_birth_pregnancy_9",
                                 "q1_b_date_of_birth_pregnancy_10",
                                );

        //The array of selects with multiple answers allowed
        //Any LorisForm multiple selects must be listed here
        $this->_selectMultipleElements = array();

        // required fields for data entry completion status
        $this->_requiredElements = array(
                                    "q1_a_what_was_the_outcome_of_pregnancy_1",
                                    "q3_disorder_a_presence",
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
        if (preg_match("/Med_Psych_History_Abbreviated_survey(_page[0-9]+)/", $this->page, $matches)) {
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
        $this->addHeader("Medical and Psychiatry Form - Abbreviated - Survey");

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
        $this->addHeader("Medical and Psychiatry Form - Abbreviated - Survey");

        $this->form->addElement(
            'static',
            null,
            "<h3>Instructions:</h3>
            Please provide details for each of your previous pregnancies in the table below. Enter information in the order of your
            pregnancies (i.e., from the first time you were pregnant until the last time you were pregnant).
            Date of birth and fetus age at delivery are only required if the baby was either a live birth or stillbirth."
        );

        $this->form->addElement(
            'static',
            null,
            "<h3>1. Pregnancy history:</h3>
            <h4><i>Note: If one pregnancy resulted in multiples (e.g., twins), please list them separately,
            by order of pregnancy outcome (e.g., list earliest first).
            For example, if twins, one miscarried and one live birth,
            the miscarried one would be listed first.
            <br><br>
            *Typically, full term pregnancy is 40 weeks or 10 months and preterm pregnancy is less than 37 weeks or 9 months.
            <br><br>
            Nothing needs be filled out after 'No more pregnancies' is indicated.
            </i></h4>"
        );

        $number_of_pregnancies = array(
                                  "1"  => "First",
                                  "2"  => "Second",
                                  "3"  => "Third",
                                  "4"  => "Fourth",
                                  "5"  => "Fifth",
                                  "6"  => "Sixth",
                                  "7"  => "Seventh",
                                  "8"  => "Eighth",
                                  "9"  => "Ninth",
                                  "10" => "Tenth",
                                 );

        $q1a_options = array(
                        null                   => "",
                        "live_birth"           => "Live birth",
                        "stillbirth"           => "Stillbirth",
                        "elective_termination" => "Elective Termination (including ectopic or tubal pregnancies)",
                        "miscarriage"          => "Miscarriage",
                       );

        $q1c_options = array(
                        null                                => "",
                        "greater_than_37_completed_weeks"   => "Greater than 37 completed weeks",
                        "less_than_28_completed_weeks"      => "Less than 28 completed weeks",
                        "between_28_and_32_completed_weeks" => "Between 28 and 32 completed weeks",
                        "between_32_and_37_completed_weeks" => "Between 32 and 37 completed weeks",
                        "fetus_age_at_delivery_unknown"     => "Fetus age at delivery unknown",
                        "not_answered"                      => "Not Answered",
                       );

        $options = array(
                    null           => '',
                    '0_no'         => "No",
                    '1_yes'        => "Yes",
                    'not_answered' => "Not Answered",
                   );

        $tmp = "1";

        foreach ($number_of_pregnancies as $key => $label) {
            $this->form->addElement(
                'static',
                null,
                "<b><i><u>" .  $label . " Pregnancy</u></i></b>"
            );

            // After first pregnancy, add "No more pregnancies" option to q1a
            if ($key == "2") {
                $q1a_options["no_more_pregnancies"] = "No more pregnancies";
            }

            $this->addSelect("q1_a_what_was_the_outcome_of_pregnancy_" . $key, "a. What was the outcome of the " . strtolower($label) . " pregnancy?", $q1a_options);

            // After the first pregnancy
            if ($key != "1") {
                $this->XINRegisterRule(
                    "q1_a_what_was_the_outcome_of_pregnancy_" . $key,
                    array("q1_a_what_was_the_outcome_of_pregnancy_{$tmp}{@}!={@}no_more_pregnancies"),
                    "Required. If the previous pregnancy was the last, select 'No more pregnancies'."
                );

                $this->XINRegisterRule(
                    "q1_a_what_was_the_outcome_of_pregnancy_" . $key,
                    array("q1_a_what_was_the_outcome_of_pregnancy_{$tmp}{@}!={@}"),
                    "Required. If the previous pregnancy was the last, select 'No more pregnancies'."
                );

                $tmp = $key;
            }

            $this->addSelect("q1_a1_if_live_birth_child_still_living_pregnancy_" . $key, $this->indent . "1. If live birth, child still living (" . strtolower($label) . " pregnancy)", $options);

            $this->XINRegisterRule(
                "q1_a1_if_live_birth_child_still_living_pregnancy_" . $key,
                array("q1_a_what_was_the_outcome_of_pregnancy_{$key}{@}=={@}live_birth"),
                "Required."
            );

            $this->addBasicDate("q1_b_date_of_birth_pregnancy_" . $key, "b. Date of birth (" . strtolower($label) . " pregnancy) <h4><i>(if stillbirth or live birth only)</i></h4>", $this->dateOptions);

            $this->XINRegisterRule(
                "q1_b_date_of_birth_pregnancy_" . $key,
                array("q1_a_what_was_the_outcome_of_pregnancy_{$key}{@}=={@}stillbirth|live_birth"),
                "Required."
            );

            $this->addSelect("q1_c_what_week_did_you_deliver_pregnancy_" . $key, "c. At what week did you deliver in the " . strtolower($label) . " pregnancy? <h4><i>(if stillbirth or live birth only)</i></h4>", $q1c_options);

            $this->XINRegisterRule(
                "q1_c_what_week_did_you_deliver_pregnancy_" . $key,
                array("q1_a_what_was_the_outcome_of_pregnancy_{$key}{@}=={@}stillbirth|live_birth"),
                "Required."
            );
        }

        $this->form->addElement('static', null, null);

        $this->addSelect("q2_pregnancy_number_of_child_being_evaluated", "2. What pregnancy number corresponds to the child being evaluated for this study?", $number_of_pregnancies);

        $this->form->addFormRule(array(&$this, 'validate_page1'));
    }

    /**
    * Generates the second page of the form.
    *
    * @return void
    */
    function _page2()
    {
        $this->addHeader("Medical and Psychiatry Form - Abbreviated - Survey");

        $this->form->addElement(
            'static',
            null,
            "3. The items below ask about the medical history of the child (and that of the child’s blood relatives)
            being evaluated for this study. Please indicate if either the child or a blood relative has the given
            disorder or problem listed. If so, provide details regarding who has the disorder or problem by selecting the appropriate person.
            <h4><i>
            <br>
            Definitions:
            <br><br>
            Child = Child being evaluated in this study;<br>
            Parents of Child (Mom) = Mother of child being evaluated;<br>
            Parents of Child (Dad)= Father of child being evaluated;<br>
            Siblings = Brothers or sisters of child being evaluated;<br>
            1⁄2 Siblings = Half brothers or sisters of child;<br>
            First Cousins = First cousins of child being evaluated;<br>
            Aunts and Uncles = Aunts and uncles of child being evaluated;<br>
            Grandparents = Grandparents of child being evaluated;<br>
            Other = Other blood relatives of child being evaluated.<br>
            <br>
            For the relative options 1⁄2 Siblings, First Cousins, Aunts and Uncles and Grandparents, Maternal and Paternal are defined as follows:<br>
            Maternal = Mother’s (of child being evaluated) side of the family,<br>
            Paternal = Father’s (of child being evaluated) side of the family.
            </i></h4>"
        );

        $q3_subquestions = array(
                            "q3_a_autism_spectrum_disorder"                          => "a. Autism Spectrum Disorder",
                            "q3_b_fragile_x"                                         => "b. Fragile X",
                            "q3_c_tuberous_sclerosis"                                => "c. Tuberous Sclerosis",
                            "q3_d_neurofibromatosis"                                 => "d. Neurofibromatosis",
                            "q3_e_rett_syndrome"                                     => "e. Rett Syndrome",
                            "q3_f_childhood_disintegration_disorder"                 => "f. Childhood Disintegration Disorder",
                            "q3_g_prader_willi_syndrome"                             => "g. Prader Willi Syndrome",
                            "q3_h_angelman_syndrome"                                 => "h. Angelman Syndrome",
                            "q3_i_other_chromosomal"                                 => "i. Other chromosomal abnormality, disorder or syndrome (please specify)", // please specify
                            "q3_j_congenital_rubella"                                => "j. Congenital rubella",
                            "q3_k_pku"                                               => "k. PKU",
                            "q3_l_hydrocephalus"                                     => "l. Hydrocephalus (water on the brain)",
                            "q3_m_cerebral_palsy"                                    => "m. Cerebral Palsy",
                            "q3_n_mental_retardation"                                => "n. Mental retardation",
                            "q3_o_seizures"                                          => "o. Seizures",
                            "q3_p_speech_delay_requiring_therapy"                    => "p. Speech delay requiring therapy",
                            "q3_q_attention_deficit_disorder"                        => "q. Attention Deficit Disorder (ADD)",
                            "q3_r_panic_or_anxiety_disorder"                         => "r. Panic or anxiety disorder",
                            "q3_s_depression"                                        => "s. Depression",
                            "q3_t_manic_depression_bipolar"                          => "t. Manic depression/Bipolar",
                            "q3_u_schizophrenia"                                     => "u. Schizophrenia",
                            "q3_v_been_admitted_to_hospital_for_psychiatric_illness" => "v. Been admitted to a hospital for psychiatric illness",
                            "q3_w_birth_defects"                                     => "w. Birth defects (e.g., cleft lip or palate, open spine)",
                            "q3_x_cancer"                                            => "x. Cancer (please specify type)", // // please specify
                            "q3_y_norrie_syndrome"                                   => "y. Norrie Syndrome",
                           );

        $q3_presence_options = array(
                                null           => '',
                                'no'           => "No",
                                'yes'          => "Yes",
                                'not_sure'     => "Not Sure",
                                'not_answered' => "Not Answered",
                               );

        $q3_relative_options = array(
                                null                   => '',
                                'child'                => "Child",
                                "parents_of_child_mom" => "Parents of Child (Mom)",
                                "parents_of_child_dad" => "Parents of Child (Dad)",
                                "siblings"             => "Siblings",
                                "half_siblings_mat"    => "Half Siblings (Maternal)",
                                "half_siblings_pat"    => "Half Siblings (Paternal)",
                                "first_cousins_mat"    => "First Cousins (Maternal)",
                                "first_cousins_pat"    => "First Cousins (Paternal)",
                                "aunts_uncles_mat"     => "Aunts & Uncles (Maternal)",
                                "aunts_uncles_pat"     => "Aunts & Uncles (Paternal)",
                                "grandparents_mat"     => "Grandparents (Maternal)",
                                "grandparents_pat"     => "Grandparents (Paternal)",
                                "multiple"             => "Multiple Relatives (specify relationships)",
                                "other"                => "Other (specify relationship)",
                                "not_answered"         => "Not Answered",
                               );

        $group[] =& $this->form->createElement(
            "static",
            null,
            null,
            "<h4><b><i>Disorder or Problem</i></b></h4>"
        );
        $group[] =& $this->form->createElement(
            "static",
            null,
            null,
            "<h4><b><i>Child/blood relative has disorder</i></b></h4>"
        );
        $group[] =& $this->form->createElement(
            "static",
            null,
            null,
            "<h4><b><i>Relative</i></b></h4>"
        );
        $group[] =& $this->form->createElement(
            "static",
            null,
            null,
            "<h4><b><i>If Other, specify relationship</i></b></h4>"
        );
        $group[] =& $this->form->createElement(
            "static",
            null,
            null,
            "<h4><b><i>If Multiple Relatives, specify relationships</i></b></h4>"
        );
        $this->addGroup(
            $group,
            "page2_headers",
            "",
            $this->_GUIDelimiter,
            false
        );
        unset($group);

        $i = "a";

        foreach ($q3_subquestions as $key => $question) {
            $group[] = $this->form->createElement('static', null, null, $question);

            $group[] =& $this->createSelect(
                "q3_disorder_" . $i . "_presence",
                "3. " . substr($question, 0, 2) . " Child/blood relative has: " . substr($question, 2),
                $q3_presence_options
            );

            $group[] =& $this->createSelect(
                "q3_disorder_" . $i . "_relative",
                $this->indent . "Relative with " . substr($question, 2),
                $q3_relative_options
            );

            $group[] =& $this->createText(
                "q3_disorder_" . $i . "_relative_other",
                $this->indent . "If other relative, specify:"
            );

            $group[] =& $this->createText(
                "q3_disorder_" . $i . "_relative_multiple",
                $this->indent . "If multiple relatives, specify:"
            );

            $this->XINRegisterRule(
                "q3_disorder_{$i}_presence",
                array("q3_disorder_{$i}_presence{@}=={@}"),
                "You must indicate whether the child/blood relative has the disorder or not",
                "q3_disorder_{$i}_group"
            );

            $this->XINRegisterRule(
                "q3_disorder_" . $i . "_relative",
                array("q3_disorder_{$i}_presence{@}=={@}yes"),
                "Required if yes.",
                "q3_disorder_" . $i . "_group"
            );

            $this->XINRegisterRule(
                "q3_disorder_" . $i . "_relative_other",
                array("q3_disorder_{$i}_relative{@}=={@}other"),
                "Required if other.",
                "q3_disorder_" . $i . "_group"
            );

            $this->XINRegisterRule(
                "q3_disorder_" . $i . "_relative_multiple",
                array("q3_disorder_{$i}_relative{@}=={@}multiple"),
                "Required if multiple.",
                "q3_disorder_" . $i . "_group"
            );

            $this->addGroup(
                $group,
                "q3_disorder_" . $i . "_group",
                null,
                $this->_GUIDelimiter,
                false
            );
            unset($group);

            if ($key == "q3_i_other_chromosomal") {
                $group[] = $this->form->createElement('static', null, null, "&emsp;&rarr;&emsp;If 'Yes', specify:");
                $group[] = $this->form->createElement('text', "q3_disorder_i_specify", "");
                $group[] = $this->form->createElement('static', null, null, "");
                $group[] = $this->form->createElement('static', null, null, "");
                $group[] = $this->form->createElement('static', null, null, "");

                $this->addGroup(
                    $group,
                    "q3_disorder_i_specify_group",
                    "",
                    $this->_GUIDelimiter,
                    false
                );
                unset($group);

                $this->XINRegisterRule(
                    "q3_disorder_i_specify",
                    array("q3_disorder_i_presence{@}=={@}yes"),
                    "Required if yes.",
                    "q3_disorder_i_specify_group"
                ); 
            }
            if ($key == "q3_x_cancer") {
                $group[] = $this->form->createElement('static', null, null, "&emsp;&rarr;&emsp;If 'Yes', please specify:");
                $group[] = $this->form->createElement('text', "q3_disorder_x_specify", "");
                $group[] = $this->form->createElement('static', null, null, "");
                $group[] = $this->form->createElement('static', null, null, "");
                $group[] = $this->form->createElement('static', null, null, "");

                $this->addGroup(
                    $group,
                    "q3_disorder_x_specify_group",
                    "",
                    $this->_GUIDelimiter,
                    false
                );
                unset($group);

                $this->XINRegisterRule(
                    "q3_disorder_x_specify",
                    array("q3_disorder_x_presence{@}=={@}yes"),
                    "Required if yes.",
                    "q3_disorder_x_specify_group"
                );
            }

            $i++;
        }

        $this->form->addFormRule(array(&$this, 'validate_page2'));
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

        for ($i = 1; $i <= 10; $i++) {
            if ($values["q1_a_what_was_the_outcome_of_pregnancy_" . $i] != "live_birth") {
                $this->validate_empty_subquestions($values, ["q1_a1_if_live_birth_child_still_living_pregnancy_" . $i], $errors);
            }

            if ($values["q1_a_what_was_the_outcome_of_pregnancy_" . $i] != "live_birth" && $values["q1_a_what_was_the_outcome_of_pregnancy_" . $i] != "stillbirth") {
                $this->validate_empty_subquestions($values, ["q1_b_date_of_birth_pregnancy_" . $i], $errors);
            }

            if ($values["q1_a_what_was_the_outcome_of_pregnancy_" . $i] != "live_birth" && $values["q1_a_what_was_the_outcome_of_pregnancy_" . $i] != "stillbirth") {
                $this->validate_empty_subquestions($values, ["q1_c_what_week_did_you_deliver_pregnancy_" . $i], $errors);
            }

            if ($values["q1_a_what_was_the_outcome_of_pregnancy_" . $i] == "no_more_pregnancies") {
                $no_more_pregnancies_index = $i;
            }

            if (isset($no_more_pregnancies_index)) {
                if ($i > $no_more_pregnancies_index) {
                    $this->validate_empty_subquestions($values, ["q1_a_what_was_the_outcome_of_pregnancy_" . $i], $errors);
                    $this->validate_empty_subquestions($values, ["q1_a1_if_live_birth_child_still_living_pregnancy_" . $i], $errors);
                    $this->validate_empty_subquestions($values, ["q1_b_date_of_birth_pregnancy_" . $i], $errors);
                    $this->validate_empty_subquestions($values, ["q1_c_what_week_did_you_deliver_pregnancy_" . $i], $errors);
                }
            }
        }

        return $errors;
    }

    function validate_page2($values)
    {
        $errors = [];

        for ($i = "a"; $i <= "y"; $i++) {
            if ($values["q3_disorder_" . $i . "_presence"] != "yes") {
                $this->validate_empty_subquestions($values, ["q3_disorder_" . $i . "_relative"], $errors);
            }

            if ($values["q3_disorder_" . $i . "_relative"] != "other") {
                $this->validate_empty_subquestions($values, ["q3_disorder_" . $i . "_relative_other"], $errors);
            }

            if ($values["q3_disorder_" . $i . "_relative"] != "multiple") {
                $this->validate_empty_subquestions($values, ["q3_disorder_" . $i . "_relative_multiple"], $errors);
            }
        }

        if ($values["q3_disorder_i_presence"] != "yes") {
            $this->validate_empty_subquestions($values, ["q3_disorder_i_specify"], $errors);
        }

        if ($values["q3_disorder_x_presence"] != "yes") {
            $this->validate_empty_subquestions($values, ["q3_disorder_x_specify"], $errors);
        }

        return $errors;
    }
}

