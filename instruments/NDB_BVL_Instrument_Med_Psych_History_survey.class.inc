<?php
/**
 * This file contains the NDB_BVL_Instrument_Med_Psych_History_survey class
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
 * Creates the form elements for the Med_Psych_History_survey instrument
 *
 * @category Instrument
 * @package  Neuropsych
 * @author   Suzanne Lee <suzannelee.mcin@gmail.com>
 * @license  http://www.gnu.org/licenses/gpl-3.0.txt GPLv3
 * @link     https://www.github.com/aces/IBIS/
 */
class NDB_BVL_Instrument_Med_Psych_History_survey extends NDB_BVL_Instrument
{
    use LegacyInstrumentTrait;
    use instrument_validator;
    var $ValidityRequired = false;
    /**
     * Sample SQL statement for test_names table and instrument subtests table
     *
     * INSERT INTO test_names (Test_name, Full_name, Sub_Group, isDirectEntry) VALUES ('Med_Psych_History_survey', "Medical and Psychiatric History - Survey", 1, 1);
     * INSERT INTO instrument_subtests (Test_name, Subtest_name, Description, Order_number) VALUES ('Med_Psych_History_survey','Med_Psych_History_survey_page1', "Page 1", 1);
     * INSERT INTO instrument_subtests (Test_name, Subtest_name, Description, Order_number) VALUES ('Med_Psych_History_survey','Med_Psych_History_survey_page2', "Page 2", 2);
     * INSERT INTO instrument_subtests (Test_name, Subtest_name, Description, Order_number) VALUES ('Med_Psych_History_survey','Med_Psych_History_survey_page3', "Page 3", 3);
     * INSERT INTO instrument_subtests (Test_name, Subtest_name, Description, Order_number) VALUES ('Med_Psych_History_survey','Med_Psych_History_survey_page4', "Page 4", 4);
     * INSERT INTO instrument_subtests (Test_name, Subtest_name, Description, Order_number) VALUES ('Med_Psych_History_survey','Med_Psych_History_survey_page5', "Page 5", 5);
     * INSERT INTO instrument_subtests (Test_name, Subtest_name, Description, Order_number) VALUES ('Med_Psych_History_survey','Med_Psych_History_survey_page6', "Page 6", 6);
     * INSERT INTO instrument_subtests (Test_name, Subtest_name, Description, Order_number) VALUES ('Med_Psych_History_survey','Med_Psych_History_survey_page7', "Page 7", 7);
     * INSERT INTO instrument_subtests (Test_name, Subtest_name, Description, Order_number) VALUES ('Med_Psych_History_survey','Med_Psych_History_survey_page8', "Page 8", 8);
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
        $this->form     = new LorisForm('Med_Psych_History_survey_form');
        $this->page     = $page;            // page label (number or
        // string - used by
        // user-defined child classes)

        // set the object properties
        $this->testName = "Med_Psych_History_survey";           // test_names.Test_name
        $this->table    = 'Med_Psych_History_survey';           // name of database table corresponding to instrument
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
        if (preg_match("/Med_Psych_History_survey(_page[0-9]+)/", $this->page, $matches)) {
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
        $this->addHeader("Medical and Psychiatric History - Survey");

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
        $this->addHeader("Medical and Psychiatric History - Survey");

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
        $this->addHeader("Medical and Psychiatric History - Survey");

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
                $this->form->addElement('text', "q3_disorder_i_specify", $this->indent . "<h4>Please specify: </h4><h5><i>i. Other chromosomal abnormality, disorder or syndrome</i></h5>");

                $this->XINRegisterRule(
                    "q3_disorder_i_specify",
                    array("q3_disorder_i_presence{@}=={@}yes"),
                    "Required if yes."
                );
            }
            if ($key == "q3_x_cancer") {
                $this->form->addElement('text', "q3_disorder_x_specify", $this->indent . "<h4>Please specify: </h4><h5><i>x. Cancer</i></h5>");

                $this->XINRegisterRule(
                    "q3_disorder_x_specify",
                    array("q3_disorder_x_presence{@}=={@}yes"),
                    "Required if yes."
                );
            }

            $i++;
        }

        $this->form->addFormRule(array(&$this, 'validate_page2'));
    }

    /**
    * Generates the third page of the form.
    *
    * @return void
    */
    function _page3()
    {
        $this->addHeader("Medical and Psychiatric History - Survey");

        $this->form->addElement(
            'static',
            null,
            "<h3>Instructions:</h3>
            Please answer the following items for the child being evaluated for this study."
        );

        $options = array(
                    null           => '',
                    '0_no'         => "No",
                    '1_yes'        => "Yes",
                    'not_answered' => "Not Answered",
                   );

        $this->addSelect("q4_was_this_pregnancy_result_of_ART", "4. Was this pregnancy the result of Assisted Reproductive Technology (ART)?", $options);

        $this->form->addElement(
            'static',
            null,
            "IF YES
            <br><br>
            Type of ART/ovulation induction technique:
            "
        );

        $q4_subquestions = array(
                            "q4_a_ovulation_induction"              => "a. Ovulation induction (e.g., took Clomid or Pergonal)",
                            "q4_b_in_vitro_fertilization"           => "b. In Vitro Fertilization (IVF)",
                            "q4_c_gift_or_zift"                     => "c. GIFT or ZIFT",
                            "q4_d_intracytoplasmic_sperm_injection" => "d. Intracytoplasmic sperm injection (ICSI)",
                            "q4_e_sperm_donor"                      => "e. Sperm donor",
                            "q4_f_egg_donor"                        => "f. Egg donor",
                            "q4_g_eggs_or_embryos_frozen"           => "g. Eggs or embryos frozen",
                            "q4_h_other"                            => "h. Other <h4><i>(Please specify)</i></h4>",
                           );

        foreach ($q4_subquestions as $key => $question) {
            $this->addSelect($key, $question, $options);

            $this->XINRegisterRule(
                $key,
                array("q4_was_this_pregnancy_result_of_ART{@}=={@}1_yes"),
                "Required."
            );

            if ($key == "q4_h_other") {
                $this->form->addElement('text', $key . "_specify", $this->indent . "Please specify:");

                $this->XINRegisterRule(
                    $key . "_specify",
                    array("{$key}{@}=={@}1_yes"),
                    "Required."
                );
            }
        }

        $this->form->addElement('static', null, null);

        $this->form->addElement(
            'static',
            null,
            "5. At <u>any</u> time in this pregnancy, did <u>you</u> have any of the following health problems?"
        );

        $q5_subquestions = array(
                            "q5_a_fever_over_101"                    => "a. Fever over 101οF or infection (e.g., Strep Throat or Urinary Tract) requiring antibiotics",
                            "q5_b_seizures"                          => "b. Seizures",
                            "q5_c_viral_illness_with_rash"           => "c. Viral illness (e.g., flu or cold) with a rash",
                            "q5_d_diabetes"                          => "d. Diabetes (including gestational diabetes)",
                            "q5_e_preterm_labor_requiring_treatment" => "e. Preterm labor requiring treatment such as bed rest or medication",
                            "q5_f_other_major_illness_injury"        => "f. Other major illness or injury <h4><i>(Please specify)</i></h4>",
                            "q5_g_vaginal_bleeding"                  => "g. Vaginal Bleeding",
                            "q5_h_generalized_edema"                 => "h. Generalized edema",
                            "q5_i_proteinuria"                       => "i. Proteinuria (>.3 g/L/24 hours)",
                            "q5_j_high_blood_pressure"               => "j. High blood pressure (>140/90)",
                           );

        foreach ($q5_subquestions as $key => $question) {
            $this->addSelect($key, $question, $options);

            if ($key == "q5_f_other_major_illness_injury") {
                $this->form->addElement('text', $key . "_specify", $this->indent . "Please specify:");

                $this->XINRegisterRule(
                    $key . "_specify",
                    array("{$key}{@}=={@}1_yes"),
                    "Required."
                );
            }
        }

        $this->form->addFormRule(array(&$this, 'validate_page3'));
    }

    /**
    * Generates the fourth page of the form.
    *
    * @return void
    */
    function _page4()
    {
        $this->addHeader("Medical and Psychiatric History - Survey");

        $this->form->addElement(
            'static',
            null,
            "<h3>
            6. Please answer the following items for the child being evaluated for this study.
            In this pregnancy, did you take any the following prescription medications?
            If so, did you take the medications before or after you knew your were pregnant or both
            (i.e., before and after you knew you were pregnant)?
            <br><br>
            <i>
            $this->indent Before = Medications taken <b>before</b> knowledge of pregnancy.<br>
            $this->indent After  = Medications taken <b>after</b> knowledge of pregnancy.<br>
            $this->indent Both   = Medications taken <b>before and after</b> knowledge of pregnancy.
            </i>
            </h3>"
        );

        $options = array(
                    null           => '',
                    '0_no'         => "No",
                    '1_yes'        => "Yes",
                    'not_answered' => "Not Answered",
                   );

        $when = array(
                 null              => '',
                 '0_before'        => "Before",
                 '1_after'         => "After",
                 '2_both'          => "Both (Before and After)",
                 '3_breastfeeding' => "Breastfeeding",
                 'not_answered'    => "Not Answered",
                );

        $q6_subquestions = array(
                            "q6_a_antibiotics_for_infections"                        => "a. Antibiotics for infections <h4><i>(e.g., Amoxicillin, Augmentin, Cephalosporins, Clindamycin, Erythromycin, Flagyl, Nystatin, Penicillin, Septra/Bactrim, Zithromax)</i></h4>",
                            "q6_b_medications_for_acne"                              => "b. Medications for acne <h4><i>(e.g., Accutane)</i></h4>",
                            "q6_c_medications_for_birth_control"                     => "c. Medications for birth control <h4><i>(e.g., Pills, Depo-Provera)</i></h4>",
                            "q6_d_antihypertensives_high_blood_pressure"             => "d. Antihypertensives for high blood pressure <h4><i>(e.g., Catapres (clonidine), Hydrochlorothiazide, Inderal (propranolol), Tenex (guanfacine))</i></h4>",
                            "q6_e_medications_for_heart"                             => "e. Medications for heart or cardiac problems",
                            "q6_f_medications_for_attention_deficit_disorder"        => "f. Medications for Attention Deficit Disorder <h4><i>(e.g., Adderall, Concerta (Methylphenidate), Dexedrine, Metadate, Ritalin)</i></h4>",
                            "q6_g_antiepileptics"                                    => "g. Antiepileptics or anti-seizure medications <h4><i>(e.g., Depakene/Depakote, Dilantin, Keppra, Lamictal, Neurontin, phenobarbital, Tegretol, Carbatrol (Carbamazepine), Trileptal, Topamax)</i></h4>",
                            "q6_h_medications_control_diabetes"                      => "h. Medications to control diabetes <h4><i>(e.g., Insulin)</i></h4>",
                            "q6_i_medications_regulate_thyroid"                      => "i. Medications to regulate thyroid <h4><i>(e.g., Synthroid, Thyroxin)</i></h4>",
                            "q6_j_antidepressants"                                   => "j. Antidepressants <h4><i>(e.g., Celexa, Effexor, Elavil (amitriptyline), Lexapro, Luvox, Paxil, Prozac (fluoxetine), Tofranil (imipramine), Wellbutrin (bupropion), Zoloft (sertraline))</i></h4>",
                            "q6_k_mood_stabilizers"                                  => "k. Mood stabilizers or anti-psychotics <h4><i>(e.g., Carbatrol (carbamazepine), Depakote, Haldol, Lamictal, Lithium, Mellaril, Neurontin, Olanzapine, Risperdal, Seroquel, Tegretol, Thorazine, Trileptal, Topamax)</i></h4>",
                            "q6_l_tranquilizers"                                     => "l. Tranquilizers or nerve pills <h4><i>(e.g., Ativan, BuSpar, Klonopin, Valium, Xanax)</i></h4>",
                            "q6_m_pain_killers_migraine_medications_muscle_relaxers" => "m. Pain killers <h4 style=\"display: inline;\"><i>(e.g., Darvon, Demerol, Dilaudid, Morphine, Percocet, Percodan, Tylenol with codeine, Codeine preparations)</i></h4> or Migraine medications <h4 style=\"display: inline;\"><i>(e.g., Amerge, Axert, Cafergot, Fiorinal, Imitrex, Maxalt, Midrin, Zomig)</i></h4> or Muscle relaxers <h4 style=\"display: inline;\"><i>(e.g., Baclofen, Flexeril, Zanaflex)</i></h4>",
                            "q6_n_sedatives_sleeping_pills"                          => "n. Sedatives or sleeping pills <h4><i>(e.g., Halcion, Methaqualone, Phenobarbital, Seconal)</i></h4>",
                            "q6_o_anti_inflammatory_immune"                          => "o. Anti-inflammatory or anti-immune drugs <h4><i>(e.g., Cytoxan, Imuran, Prednisone, Steroids)</i></h4>",
                            "q6_p_treatment_for_hiv"                                 => "p. Treatment for HIV",
                            "q6_q_thalidomide"                                       => "q. Thalidomide <h4><i>(Please specify medication and why it was prescribed)</i></h4>",
                            "q6_r_misoprostol"                                       => "r. Misoprostol <h4><i>(Please specify medication and why it was prescribed)</i></h4>",
                            "q6_s_other"                                             => "s. Other <h4><i>(Please specify medication and why it was prescribed)</i></h4>",
                           );

        foreach ($q6_subquestions as $key => $question) {
            $this->addSelect($key, $question, $options);
            $this->addSelect($key . "_when", $this->indent . "If yes, when was medication taken?", $when);

            $this->XINRegisterRule(
                $key . "_when",
                array("{$key}{@}=={@}1_yes"),
                "Required."
            );

            if ($key == "q6_q_thalidomide" || $key == "q6_r_misoprostol" || $key == "q6_s_other") {
                $this->form->addElement('text', $key . "_specify", $this->indent . "Please specify medication and why it was prescribed:");

                $this->XINRegisterRule(
                    $key . "_specify",
                    array("{$key}{@}=={@}1_yes"),
                    "Required."
                );
            }
        }

        $this->form->addFormRule(array(&$this, 'validate_page4'));
    }

    /**
    * Generates the fifth page of the form.
    *
    * @return void
    */
    function _page5()
    {
        $this->addHeader("Medical and Psychiatric History - Survey");

        $this->form->addElement(
            'static',
            null,
            "<h3>Instructions:</h3>
            Please answer the following items for the child being evaluated for this study."
        );

        $options = array(
                    null           => '',
                    '0_no'         => "No",
                    '1_yes'        => "Yes",
                    'not_answered' => "Not Answered",
                   );

        $this->form->addElement(
            'static',
            null,
            "<h3>
            7. In this pregnancy, did your <u>doctor</u> tell you that the <u>baby</u> had any of the following health problems?
            </h3>"
        );

        $q7_subquestions = array(
                            "q7_a_screen_positive_on_blood_test"          => "a. Screen positive on a blood test <h4><i>(e.g., AFP test, triple screen)</i></h4>",
                            "q7_b_abnormal_ultrasound_or_sonogram"        => "b. Abnormal ultrasound or sonogram <h4><i>(Please specify)</i></h4>",
                            "q7_c_abnormality_based_on_amniocentesis_cvs" => "c. Abnormality based on results from an amniocentesis or Chorionic Villus Sampling (CVS) <h4><i>(Please specify)</i></h4>",
                            "q7_d_other"                                  => "d. Other <h4><i>(Please specify)</i></h4>",
                           );

        foreach ($q7_subquestions as $key => $question) {
            $this->addSelect($key, $question, $options);

            if ($key == "q7_b_abnormal_ultrasound_or_sonogram" || $key == "q7_c_abnormality_based_on_amniocentesis_cvs" || $key == "q7_d_other") {
                $this->form->addElement('text', $key . "_specify", $this->indent . "Please specify:");

                $this->XINRegisterRule(
                    $key . "_specify",
                    array("{$key}{@}=={@}1_yes"),
                    "Required."
                );
            }
        }

        $this->form->addElement('static', null, null);

        $when = array(
                 null              => '',
                 '0_before'        => "Before",
                 '1_after'         => "After",
                 '2_both'          => "Both (Before and After)",
                 '3_breastfeeding' => "Breastfeeding",
                 'not_answered'    => "Not Answered",
                );

        $this->form->addElement(
            'static',
            null,
            "<h3>
            8. In this pregnancy, did you do any of the following activities?
            If so, did you take it before or after you knew your were pregnant or both
            (i.e., before and after you knew you were pregnant)?
            <br><br>
            <i>
            $this->indent Before = Medications taken <b>before</b> knowledge of pregnancy.<br>
            $this->indent After  = Medications taken <b>after</b> knowledge of pregnancy.<br>
            $this->indent Both   = Medications taken <b>before and after</b> knowledge of pregnancy.
            </i>
            </h3>"
        );

        $q8_subquestions = array(
                            "q8_a_drink_alcohol"                  => "a. Drink alcohol",
                            "q8_b_smoke_cigarettes_other_tobacco" => "b. Smoke cigarettes or other tobacco products",
                           );

        foreach ($q8_subquestions as $key => $question) {
            $this->addSelect($key, $question, $options);
            $this->addSelect($key . "_when", $this->indent . "If yes, when was this taken?", $when);

            $this->XINRegisterRule(
                $key . "_when",
                array("{$key}{@}=={@}1_yes"),
                "Required."
            );
        }

        $this->form->addElement('static', null, null);

        $this->form->addElement(
            'static',
            null,
            "<h3>
            9. In this pregnancy, did you do any of the following activities? If so, did you take it before or
            after you knew your were pregnant or both (i.e., before and after you knew you were pregnant)?
            <br><br>
            <i>
            $this->indent Before = Medications taken <b>before</b> knowledge of pregnancy.<br>
            $this->indent After  = Medications taken <b>after</b> knowledge of pregnancy.<br>
            $this->indent Both   = Medications taken <b>before and after</b> knowledge of pregnancy.
            </i>
            </h3>"
        );

        $q9_subquestions = array(
                            "q9_a_smoke_marijuana_or_hashish"  => "a. Smoke marijuana or hashish <h4><i>(THC)</i></h4>",
                            "q9_b_use_cocaine_crack_free_base" => "b. Use Cocaine, Crack or Free base",
                            "q9_c_use_heroin"                  => "c. Use Heroin <h4><i>(includes speed balling (heroin and cocaine injected together))</i></h4>",
                            "q9_d_take_methadone"              => "d. Take Methadone",
                            "q9_e_take_amphetamines"           => "e. Take Amphetamines or other stimulants <h4><i>(speed, crank, uppers, Ice, methamphetamine)</i></h4>",
                            "q9_f_take_ecstasy"                => "f. Take Ecstasy <h4><i>(ADAM, XTC)</i></h4>",
                            "q9_g_take_hallucinogens"          => "g. Take Hallucinogens <h4><i>(LSD, PCP, Angel Dust, Peyote, Mescaline, Mushrooms, Green)</i></h4>",
                            "q9_h_take_inhalants"              => "h. Take inhalants that you sniff or breathe <h4><i>(Amyl Nitrate, Freon, Nitrous Oxide (“Whippets”), Gasoline, Spray Paint, “Poppers”, Glue or Solvents)</i></h4>",
                            "q9_i_other"                       => "i. Other <h4><i>(Please specify)</i></h4>",
                           );

        foreach ($q9_subquestions as $key => $question) {
            $this->addSelect($key, $question, $options);
            $this->addSelect($key . "_when", $this->indent . "If yes, when was this taken?", $when);

            $this->XINRegisterRule(
                $key . "_when",
                array("{$key}{@}=={@}1_yes"),
                "Required."
            );

            if ($key == "q9_i_other") {
                $this->form->addElement('text', $key . "_specify", $this->indent . "Please specify:");

                $this->XINRegisterRule(
                    $key . "_specify",
                    array("{$key}{@}=={@}1_yes"),
                    "Required."
                );
            }
        }
        $this->form->addFormRule(array(&$this, 'validate_page5'));
    }

    /**
    * Generates the sixth page of the form.
    *
    * @return void
    */
    function _page6()
    {
        $this->addHeader("Medical and Psychiatric History - Survey");

        $this->form->addElement(
            'static',
            null,
            "<h3>Instructions:</h3>
            Please answer the items below regarding, labor, delivery and newborn information for the child being evaluated for this study."
        );

        $options = array(
                    null           => '',
                    '0_no'         => "No",
                    '1_yes'        => "Yes",
                    'not_answered' => "Not Answered",
                   );

        $this->addSelect("q10_a_given_special_medications_to_induce_labor", "10. Were you given any medications (e.g., Pitocin) to induce or start labor?", $options);

        $this->addSelect("q10_b_have_spinal_or_general_anesthesia_for_birth", "10. b. Did you have a spinal or general anesthesia for the birth", $options);

        $this->form->addElement('static', null, null);

        $this->form->addElement('text', "q11_how_much_did_child_weigh_at_birth_pounds", "11. How much did this <u>child</u> weigh at birth? <u>(Pounds)</u>");
        $this->form->addElement('text', "q11_how_much_did_child_weigh_at_birth_ounces", "11. How much did this <u>child</u> weigh at birth? <u>(Ounces)</u>");

        $this->form->addElement('static', null, null);

        $this->form->addElement('text', "q11_b_child_apgar_score_1_minute", "11. b. What were this <u>child’s</u> APGAR scores at: <u>1 minute</u>");
        $this->form->addElement('text', "q11_b_child_apgar_score_5_minutes", "11. b. What were this <u>child’s</u> APGAR scores at: <u>5-minutes</u>");

        $this->form->addElement('static', null, null);

        $this->form->addElement(
            'static',
            null,
            "12. Did this child need any of the following during/after labor and delivery:"
        );

        $q12_subquestions = array(
                             "q12_a_resuscitation"                       => "a. Resuscitation such as having the nurses and doctors help him/her breathe or get his/her heart started",
                             "q12_b_forceps_vacuum_extraction"           => "b. Forceps/vacuum extraction",
                             "q12_c_meconium_stain"                      => "c. Meconium stain in the amniotic fluid",
                             "q12_d_cord_prolapse"                       => "d. Cord prolapse/around neck/knot",
                             "q12_e_nonvertex_presentation"              => "e. Nonvertex presentation (i.e., breech)",
                             "q12_f_trauma_on_delivery"                  => "f. Trauma on delivery",
                             "q12_g_respiratory_distress_syndrome"       => "g. Respiratory distress syndrome",
                             "q12_h_septicemia_meningitis"               => "h. Septicemia/meningitis",
                             "q12_i_hyperbilirubinemia"                  => "i. Hyperbilirubinemia",
                             "q12_j_anemia_requiring_transfusion"        => "j. Anemia requiring transfusion",
                             "q12_k_irritable_floppy_infant_convulsions" => "k. Irritable/floppy infant/convulsions",
                             "q12_l_clinical_dysmaturity"                => "l. Clinical dysmaturity",
                             "q12_m_difficulty_regulating_temperature"   => "m. Difficulty regulating temperature",
                             "q12_n_oxygen_treatment"                    => "n. Oxygen treatment (>30%)",
                            );

        foreach ($q12_subquestions as $key => $question) {
            $this->addSelect($key, $question, $options);
        }

        $this->form->addElement('static', null, null);

        $this->addSelect("q13_did_child_stay_in_neonatal_intensive_care_unit", "13. Did this child stay in the neonatal intensive care unit?", $options);

        $this->form->addElement(
            'static',
            null,
            "IF YES"
        );

        $this->form->addElement('text', "q13_a_number_of_days", $this->indent . "a. Number of days");

        $this->form->addElement(
            'static',
            null,
            $this->indent . "<b><i><u>OR</i></i></b>"
        );

        $this->form->addElement('text', "q13_a_number_of_hours", $this->indent . "a. Number of hours");

        $this->XINRegisterRule(
            "q13_a_number_of_days",
            array("q13_did_child_stay_in_neonatal_intensive_care_unit{@}=={@}1_yes"),
            "Required if yes."
        );

        $this->XINRegisterRule(
            "q13_a_number_of_hours",
            array("q13_did_child_stay_in_neonatal_intensive_care_unit{@}=={@}1_yes"),
            "Required if yes."
        );

        $this->XINRegisterRule(
            "q13_a_number_of_days",
            array("q13_a_number_of_hours{@}=={@}"),
            "Number of hours OR days Required."
        );

        $this->XINRegisterRule(
            "q13_a_number_of_hours",
            array("q13_a_number_of_days{@}=={@}"),
            "Number of hours OR days Required."
        );

        $this->form->addElement('static', null, null);

        $this->form->addElement(
            'static',
            null,
            "14. How many days or hours <u>total</u> did this <u>child</u> stay in the hospital (after delivery up to discharge, including the neonatal ICU)?"
        );

        $this->form->addElement('text', "q14_a_number_of_days", $this->indent . "a. Number of days");

        $this->form->addElement(
            'static',
            null,
            $this->indent . "<b><i><u>OR</i></i></b>"
        );

        $this->form->addElement('text', "q14_a_number_of_hours", $this->indent . "a. Number of hours");

        $this->XINRegisterRule(
            "q14_a_number_of_days",
            array("q14_a_number_of_hours{@}=={@}"),
            "Number of hours OR days Required."
        );

        $this->XINRegisterRule(
            "q14_a_number_of_hours",
            array("q14_a_number_of_days{@}=={@}"),
            "Number of hours OR days Required."
        );

        $this->form->addFormRule(array(&$this, 'validate_page6'));
    }

    /**
    * Generates the seventh page of the form.
    *
    * @return void
    */
    function _page7()
    {
        $this->addHeader("Medical and Psychiatric History - Survey");

        $this->form->addElement(
            'static',
            null,
            "<h3>Instructions:</h3>
            Please answer the items below regarding neurological function for the child being evaluated for this study."
        );

        $options = array(
                    null           => '',
                    '0_no'         => "No",
                    '1_yes'        => "Yes",
                    'not_answered' => "Not Answered",
                   );

        $this->addSelect("q15_has_child_ever_had_seizures", "15. Has this child ever had seizures or convulsions?", $options);

        $this->form->addElement(
            'static',
            null,
            "IF YES"
        );

        $q15_a_options = array(
                          null                     => "",
                          "0_first_month"          => "First month of life",
                          "1_1_to_12_months"       => "1-12 months (before 1st birthday)",
                          "2_12_to_24_months"      => "12-24 months (before 2nd birthday)",
                          "3_2_to_5_years"         => "2-5 years (before 5th birthday)",
                          "4_greater_than_5_years" => ">5 years",
                         );

        $this->addSelect("q15_a_when_was_first_seizure", "a. When was the first seizure?", $q15_a_options);

        $this->XINRegisterRule(
            "q15_a_when_was_first_seizure",
            array("q15_has_child_ever_had_seizures{@}=={@}1_yes"),
            "Required."
        );

        $q15_subquestions = array(
                             "q15_b_does_child_have_seizures_now"                        => "b. Does this child have seizures or convulsions now?",
                             "q15_c_did_seizures_only_occur_when_fever"                  => "c. Did the seizures <i><u>only</u></i> occur when this child had a <u>fever</u>?",
                             "q15_d_does_child_now_take_medications_to_control_seizures" => "d. Does this child <u>now</u> take medications to help control seizures?",
                            );

        foreach ($q15_subquestions as $key => $question) {
            $this->addSelect($key, $question, $options);

            $this->XINRegisterRule(
                $key,
                array("q15_has_child_ever_had_seizures{@}=={@}1_yes"),
                "Required."
            );
        }

        $this->form->addElement('static', null, null);

        $this->form->addElement(
            'static',
            null,
            "16. Has this child ever..."
        );

        $q16_subquestions = array(
                             "16_a_had_abnormal_picture_of_brain"                    => "a. Had an abnormal picture of the brain (e.g., MRI or CT scan)",
                             "16_b_been_hospitalized_for_meningitis_or_encephalitis" => "b. Been hospitalized for meningitis or encephalitis (infection or inflammation of the brain)",
                             "16_c_lost_consciousness_due_to_head_injury"            => "c. Lost consciousness due to a head injury",
                            );

        foreach ($q16_subquestions as $key => $question) {
            $this->addSelect($key, $question, $options);
        }

        $this->form->addElement(
            'static',
            null,
            "IF YES
            <br><br>
            At what age(s) did this child lose consciousness"
        );

        $group[] =& $this->form->createElement(
            "static",
            null,
            null,
            "<h4><b><i>Years</i></b></h4>"
        );
        $group[] =& $this->form->createElement(
            "static",
            null,
            null,
            "<h4><b><i><u>OR</u> Months</i></b></h4>"
        );
        $this->addGroup(
            $group,
            "page7_headers",
            "",
            $this->_GUIDelimiter,
            false
        );
        unset($group);

        for ($i = 1; $i <= 3; $i++) {
            $this->addLabel("<h4>" . $i . ".</h4>");

            $group[] =& $this->createText(
                "q16_c_if_yes_years_" . $i,
                $this->indent . "At what age(s) did this child lose consciousness? <u>(Years)</u>"
            );

            $group[] =& $this->createText(
                "q16_c_if_yes_months_" . $i,
                $this->indent . "or <u>(Months)</u>"
            );

            $this->XINRegisterRule(
                "q16_c_if_yes_years_" . $i,
                array("16_c_lost_consciousness_due_to_head_injury{@}=={@}1_yes"),
                "Required if yes.",
                "q16_c_" . $i . "_group"
            );

            $this->XINRegisterRule(
                "q16_c_if_yes_months_" . $i,
                array("16_c_lost_consciousness_due_to_head_injury{@}=={@}1_yes"),
                "Required if yes.",
                "q16_c_" . $i . "_group"
            );

            if ($i != 1) {
                $this->XINRegisterRule(
                    "q16_c_if_yes_years_" . $i,
                    array("q16_c_if_yes_years_{$i}{@}=={@}NEVER_REQUIRED"),
                    "Never required.",
                    "q16_c_" . $i . "_group"
                );

                $this->XINRegisterRule(
                    "q16_c_if_yes_months_" . $i,
                    array("q16_c_if_yes_months_{$i}{@}=={@}NEVER_REQUIRED"),
                    "Never required.",
                    "q16_c_" . $i . "_group"
                );
            }

            $this->XINRegisterRule(
                "q16_c_if_yes_years_" . $i,
                array("q16_c_if_yes_months_{$i}{@}=={@}"),
                "Years OR Months Required.",
                "q16_c_" . $i . "_group"
            );

            $this->XINRegisterRule(
                "q16_c_if_yes_months_" . $i,
                array("q16_c_if_yes_years_{$i}{@}=={@}"),
                "Years OR Months Required.",
                "q16_c_" . $i . "_group"
            );

            $this->addGroup(
                $group,
                "q16_c_" . $i . "_group",
                null,
                $this->_GUIDelimiter,
                false
            );
            unset($group);
        }

        $this->form->addFormRule(array(&$this, 'validate_page7'));
    }

    /**
    * Generates the eighth page of the form.
    *
    * @return void
    */
    function _page8()
    {
        $this->addHeader("Medical and Psychiatric History - Survey");

        $this->form->addElement(
            'static',
            null,
            "<h3>Instructions:</h3>
            Please answer the items below regarding the child being evaluated for this study."
        );

        $options = array(
                    null           => '',
                    '0_no'         => "No",
                    '1_yes'        => "Yes",
                    'not_answered' => "Not Answered",
                   );

        $this->form->addElement(
            'static',
            null,
            "17. Did this child have any of the following birth defects?"
        );

        $q17_subquestions = array(
                             "q17_a_cleft_lip_or_palate" => "a. Cleft lip or palate",
                             "q17_b_abnormal_shape"      => "b. Abnormal shape of hands, feet, arms or legs including Polydactyly (extra fingers (digits) or toes)",
                             "q17_c_open_spine"          => "c. Open spine (Spina bifida or other neural tube defect)",
                             "q17_d_heart_defect"        => "d. Heart defect <h4><i>(Please specify)</i></h4>",
                             "q17_e_kidney_defect"       => "e. Kidney defect <h4><i>(Please specify)</i></h4>",
                             "q17_f_other_defect"        => "f. Other defect <h4><i>(Please specify)</i></h4>",
                            );

        foreach ($q17_subquestions as $key => $question) {
            $this->addSelect($key, $question, $options);

            if ($key == "q17_d_heart_defect" || $key == "q17_e_kidney_defect" || $key == "q17_f_other_defect") {
                $this->form->addElement('text', $key . "_specify", $this->indent . "Please specify:");

                $this->XINRegisterRule(
                    $key . "_specify",
                    array("{$key}{@}=={@}1_yes"),
                    "Required."
                );
            }
        }

        $this->form->addElement('static', null, null);

        $this->addSelect("q18_other_chronic_medical_problems", "18. Does the child being evaluated today have any other chronic medical problems other than those listed above?", $options);

        $this->form->addElement(
            'static',
            null,
            "IF YES"
        );

        $q18_subquestions = array(
                             "q18_a_medical_problem_1" => "a. Medical Problem #1 <h4><i>(please specify)</i></h4>",
                             "q18_b_medical_problem_2" => "b. Medical Problem #2 <h4><i>(please specify)</i></h4>",
                             "q18_c_medical_problem_3" => "c. Medical Problem #3 <h4><i>(please specify)</i></h4>",
                            );

        $i = 0;

        foreach ($q18_subquestions as $key => $question) {
            $this->form->addElement('text', $key, $question);
            $i++;

            if ($i == 1) {
                $this->XINRegisterRule(
                    $key,
                    array("q18_other_chronic_medical_problems{@}=={@}1_yes"),
                    "Required."
                );
            } else {
                $this->XINRegisterRule(
                    $key,
                    array("{$key}{@}=={@}NEVER_REQUIRED"),
                    "Never required."
                );
            }

            $this->addSelect($key . "_was_child_hospitalized", $this->indent . "Was the child hospitalized for medical problem #" . $i, $options);

            $this->XINRegisterRule(
                $key . "_was_child_hospitalized",
                array("{$key}{@}!={@}"),
                "Required."
            );
        }

        $this->form->addFormRule(array(&$this, 'validate_page8'));
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

    function validate_page3($values)
    {
        $errors = [];

        if ($values["q4_h_other"] != "1_yes") {
            $this->validate_empty_subquestions($values, ["q4_h_other_specify"], $errors);
        }

        if ($values["q5_f_other_major_illness_injury"] != "1_yes") {
            $this->validate_empty_subquestions($values, ["q5_f_other_major_illness_injury_specify"], $errors);
        }

        return $errors;
    }

    function validate_page4($values)
    {
        $errors = [];

        $q6_subquestions = array(
                            "q6_a_antibiotics_for_infections",
                            "q6_b_medications_for_acne",
                            "q6_c_medications_for_birth_control",
                            "q6_d_antihypertensives_high_blood_pressure",
                            "q6_e_medications_for_heart",
                            "q6_f_medications_for_attention_deficit_disorder",
                            "q6_g_antiepileptics",
                            "q6_h_medications_control_diabetes",
                            "q6_i_medications_regulate_thyroid",
                            "q6_j_antidepressants",
                            "q6_k_mood_stabilizers",
                            "q6_l_tranquilizers",
                            "q6_m_pain_killers_migraine_medications_muscle_relaxers",
                            "q6_n_sedatives_sleeping_pills",
                            "q6_o_anti_inflammatory_immune",
                            "q6_p_treatment_for_hiv",
                            "q6_q_thalidomide",
                            "q6_r_misoprostol",
                            "q6_s_other",
                           );

        foreach ($q6_subquestions as $q) {
            if ($values[$q] != "1_yes") {
                $this->validate_empty_subquestions($values, [$q . "_when"], $errors);
            }

            if ($q == "q6_q_thalidomide" || $q == "q6_r_misoprostol" || $q == "q6_s_other") {
                if ($values[$q] != "1_yes") {
                    $this->validate_empty_subquestions($values, [$q . "_specify"], $errors);
                }
            }
        }

        return $errors;
    }

    function validate_page5($values)
    {
        $errors = [];

        $q7_subquestions = array(
                            "q7_b_abnormal_ultrasound_or_sonogram",
                            "q7_c_abnormality_based_on_amniocentesis_cvs",
                            "q7_d_other",
                           );

        foreach ($q7_subquestions as $q) {
            if ($values[$q] != "1_yes") {
                $this->validate_empty_subquestions($values, [$q . "_specify"], $errors);
            }
        }

        $q8_subquestions = array(
                            "q8_a_drink_alcohol",
                            "q8_b_smoke_cigarettes_other_tobacco",
                           );

        foreach ($q8_subquestions as $q) {
            if ($values[$q] != "1_yes") {
                $this->validate_empty_subquestions($values, [$q . "_when"], $errors);
            }
        }

        $q9_subquestions = array(
                            "q9_a_smoke_marijuana_or_hashish",
                            "q9_b_use_cocaine_crack_free_base",
                            "q9_c_use_heroin",
                            "q9_d_take_methadone",
                            "q9_e_take_amphetamines",
                            "q9_f_take_ecstasy",
                            "q9_g_take_hallucinogens",
                            "q9_h_take_inhalants",
                            "q9_i_other",
                           );

        foreach ($q9_subquestions as $q) {
            if ($values[$q] != "1_yes") {
                $this->validate_empty_subquestions($values, [$q . "_when"], $errors);
            }

            if ($q == "q9_i_other") {
                if ($values[$q] != "1_yes") {
                    $this->validate_empty_subquestions($values, [$q . "_specify"], $errors);
                }
            }
        }

        return $errors;
    }

    function validate_page6($values)
    {
        $errors = [];

        $page6_questions = array(
                            "q11_how_much_did_child_weigh_at_birth_pounds",
                            "q11_how_much_did_child_weigh_at_birth_ounces",
                            "q13_a_number_of_days",
                            "q13_a_number_of_hours",
                            "q14_a_number_of_days",
                            "q14_a_number_of_hours",
                           );

        foreach ($page6_questions as $q) {
            if (isset($values[$q])) {
                $user_input = $values[$q];
                if ((!is_numeric($user_input) || (is_numeric($user_input) && $user_input < 0)) && $user_input != "") {
                    $errors[$q] = "Specify a positive number";
                }
            }
        }

        if ($values["q13_did_child_stay_in_neonatal_intensive_care_unit"] != "1_yes") {
            $this->validate_empty_subquestions($values, ["q13_a_number_of_days"], $errors);
            $this->validate_empty_subquestions($values, ["q13_a_number_of_hours"], $errors);
        }

        return $errors;
    }

    function validate_page7($values)
    {
        $errors = [];

        $q15_subquestions = array(
                             "q15_a_when_was_first_seizure",
                             "q15_b_does_child_have_seizures_now",
                             "q15_c_did_seizures_only_occur_when_fever",
                             "q15_d_does_child_now_take_medications_to_control_seizures",
                            );

        foreach ($q15_subquestions as $q) {
            if ($values["q15_has_child_ever_had_seizures"] != "1_yes") {
                $this->validate_empty_subquestions($values, [$q], $errors);
            }
        }

        for ($i = 1; $i <= 3; $i++) {
            if ($values["16_c_lost_consciousness_due_to_head_injury"] != "1_yes") {
                $this->validate_empty_subquestions($values, ["q16_c_if_yes_years_" . $i], $errors);
                $this->validate_empty_subquestions($values, ["q16_c_if_yes_months_" . $i], $errors);
            }

            if (isset($values["q16_c_if_yes_years_" . $i])) {
                $user_input = $values["q16_c_if_yes_years_" . $i];
                if ((!is_numeric($user_input) || (is_numeric($user_input) && $user_input < 0)) && $user_input != "") {
                    $errors["q16_c_if_yes_years_" . $i] = "Specify a positive number";
                }
            }

            if (isset($values["q16_c_if_yes_months_" . $i])) {
                $user_input = $values["q16_c_if_yes_months_" . $i];
                if ((!is_numeric($user_input) || (is_numeric($user_input) && $user_input < 0)) && $user_input != "") {
                    $errors["q16_c_if_yes_months_" . $i] = "Specify a positive number";
                }
            }
        }

        return $errors;
    }

    function validate_page8($values)
    {
        $errors = [];

        $q17_subquestions = array(
                             "q17_d_heart_defect",
                             "q17_e_kidney_defect",
                             "q17_f_other_defect",
                            );

        foreach ($q17_subquestions as $q) {
            if ($values[$q] != "1_yes") {
                $this->validate_empty_subquestions($values, [$q . "_specify"], $errors);
            }
        }

        $q18_subquestions = array(
                             "q18_a_medical_problem_1",
                             "q18_b_medical_problem_2",
                             "q18_c_medical_problem_3",
                            );

        foreach ($q18_subquestions as $q) {
            if ($values[$q] == "") {
                $this->validate_empty_subquestions($values, [$q . "_was_child_hospitalized"], $errors);
            }
        }

        return $errors;
    }
}
?>
