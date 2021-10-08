<?php
/**
 *This file contains the NDB_BVL_Instrument_Teachers_Report_Form_6_To_18 class
 *
 * PHP Version 5
 *
 * @category Instrument
 * @package  Neuropsych
 * @author   Suzanne Lee <suzannelee.mcin@gmail.com>
 * @license  http://www.gnu.org/licenses/gpl-3.0.txt GPLv3
 * @link     https://www.github.com/aces/IBIS/
 */

/**
 * Creates the form elements for the NDB_BVL_Instrument_Teachers_Report_Form_6_To_18 instrument
 *
 * @category Instrument
 * @package  Neuropsych
 * @author   Suzanne Lee <suzannelee.mcin@gmail.com>
 * @license  http://www.gnu.org/licenses/gpl-3.0.txt GPLv3
 * @link     https://www.github.com/aces/IBIS/
 */
class NDB_BVL_Instrument_Teachers_Report_Form_6_To_18 extends NDB_BVL_Instrument
{
    use LegacyInstrumentTrait;

    use instrument_validator;
    var $ValidityRequired = false;
    var $scoreLabels = array('anxious_score',
        'anxious_T_score',
        'anxious_percentile',
        'depressed_score',
        'depressed_T_score',
        'depressed_percentile',
        'som_comp_score',
        'som_comp_T_score',
        'som_comp_percentile',
        'social_prob_score',
        'social_prob_T_score',
        'social_prob_percentile',
        'thought_prob_score',
        'thought_prob_T_score',
        'thought_prob_percentile',
        'rule_break_behav_score',
        'rule_break_behav_T_score',
        'rule_break_behav_percentile',
        'aggr_behav_score',
        'aggr_behav_T_score',
        'aggr_behav_percentile',
        'attention_prob_score',
        'attention_prob_T_score',
        'attention_prob_percentile',
        'internalizing_score',
        'internalizing_T_score',
        'internalizing_percentile',
        'externalizing_score',
        'externalizing_T_score',
        'externalizing_percentile',
        'total_problems_score',
        'total_problems_T_score',
        'total_problems_percentile',
        'depressive_prob_score',
        'depressive_prob_T_score',
        'depressive_prob_percentile',
        'anx_prob_score',
        'anx_prob_T_score',
        'anx_prob_percentile',
        'som_prob_score',
        'som_prob_T_score',
        'som_prob_percentile',
        'attention_hyper_prob_score',
        'attention_hyper_prob_T_score',
        'attention_hyper_prob_percentile',
        'oppo_def_prob_score',
        'oppo_def_prob_T_score',
        'oppo_def_prob_percentile',
        'conduct_prob_score',
        'conduct_prob_T_score',
        'conduct_prob_percentile',
        'sluggish_cogn_tempo_score',
        'sluggish_cogn_tempo_T_score',
        'sluggish_cogn_tempo_percentile',
        'obsessive_comp_prob_score',
        'obsessive_comp_prob_T_score',
        'obsessive_comp_prob_percentile',
        'stress_prob_score',
        'stress_prob_T_score',
        'stress_prob_percentile',
        'Inatt_score',
        'Inatt_T_score',
        'Inatt_percentile',
        'HyperImp_score',
        'HyperImp_T_score',
        'HyperImp_percentile',
    );



    /**
    * Sets up basic data, such as the HTML_Quickform object, and so on.
    *
    * @param string $commentID the CommentID identifying the data to load
    * @param string $page      if a multipage form, the page to show
    *
    * @return void
    * @access public
    */
    function setup(?string $commentID = NULL, ?string $page = NULL): void
    {
        $this->formType ="XIN";
        $this->form     = new LorisForm('test_form');
        $this->page     = $page;            // page label (number or
        // string - used by
        // user-defined child classes)

        // set the object properties
        $this->testName = "Teachers_Report_Form_6_To_18";           // test_names.Test_name
        $this->table    = 'Teachers_Report_Form_6_To_18';              // name of database table corresponding to instrument
        // data keyed by commentID
        $this->commentID = $commentID;

        //The array of dates/timestamps to convert to database dates/timestamps
        //Any HTML_Quickform date elements must be listed here
        $this->dateTimeFields =array("pupil_birthdate");

        //The array of selects with multiple answers allowed
        //Any HTML_Quickform multiple selects must be listed here
        $this->_selectMultipleElements = array();


        // setup the form
        $this->_setupForm();

    }

    //If the instrument is not paged, remove the switch from the _setupForm method and add all the form Elements in this function.

    /**
    * Method to build the HTML_Quickform object into a paged form
    *
    * @return void
    * @access private
    */
    function _setupForm()
    {
        if (preg_match("/Teachers_Report_Form_6_To_18(_page[0-9]+)/", $this->page, $matches)) {
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
        $this->addHeader("Teacher's Report Form (TRF) for Ages 6-18");

        $this->addBasicDate('Date_taken', 'Date of Administration', $this->dateOptions);

        for($i=1;$i<=5;$i++)
        {
            if($i==1) {
                $this->form->addElement('header', null, "Syndrome Scales (Scores)  ");
                $domains=array("anxious" => "Anxious/Depressed","depressed" => "Withdrawn/Depressed","som_comp" => "Somatic Complaints",
                    "social_prob" => "Social Problems", "thought_prob" => "Thought Problems", "attention_prob" => "Attention Problems",
                    "rule_break_behav" => "Rule Breaking Behaviour",
                    "aggr_behav" => "Aggressive Behaviour",
                );
            }
            if($i==2) {
                $this->form->addElement('header', null, "Internalizing, Externalizing, Total Problems, Other Problems (Scores) ");
                $domains=array("internalizing" => "Internalizing","externalizing" => "Externalizing","total_problems" => "Total Problems",
                );
            }
            if($i==3) {
                $this->form->addElement('header', null, "Attention Problems Subscales (Scores) ");
                $domains=array("Inatt" => "Inattention (I)","HyperImp" => "Hyperactivity-Impulsivity (H-I)",
                );
            }
            if($i==4)
            {
                $this->form->addElement('header', null, "DSM-5-Oriented Scales (Scores) ");
                $domains = array("depressive_prob" => "Depressive Problems","anx_prob" => "Anxiety Problems","som_prob" => "Somatic Problems",
                    "attention_hyper_prob" => "Attention Deficit/ Hyperactivity Problems", "oppo_def_prob" => "Oppositional Defiant Problems",
                    "conduct_prob" => "Conduct Problem"
                );
            }
            if($i==5)
            {
                $this->form->addElement('header', null, "2007 Scales (Scores)");
                $domains = array("sluggish_cogn_tempo" => "Sluggish Cognitive Tempo","obsessive_comp_prob" => " Obsessive-Compulsive Problems",
                    "stress_prob" => " Stress Problems",

                );
            }
            //scoring column headers
            $group[] = $this->form->createElement('static', "score", null, null);
            $group[] = $this->form->createElement('static', "T_score", null, null);
            $group[] = $this->form->createElement('static', "percentile", null, null);
            $this->form->addGroup($group, 'score_header_group_'.$i, "<strong>Domain</strong>", $this->_GUIDelimiter, FALSE);
            unset($group);


            //score fields

            $columnHeaders = array("score" => "Score", "T_score" => "T Score","percentile" =>"Percentile");

            foreach ($columnHeaders as $field => $label) {
                $columnHeaders[$field] .= "     ";
            }
            $this->localDefaults = array_merge($this->localDefaults, $columnHeaders);

            foreach ($domains as $field => $label) {
                foreach ($columnHeaders as $scoreField => $scoreLabel) {

                    $group[] = $this->form->createElement('static', "{$field}_{$scoreField}", null, null);
                }
                $this->form->addGroup($group, "{$label}_score_group_{$i}", $label, $this->_GUIDelimiter, FALSE);
                unset($group);


            }


            //scoring column headers
            $group[] = $this->form->createElement('static', "score", null, null);
            $group[] = $this->form->createElement('static', "T_score", null, null);
            $group[] = $this->form->createElement('static', "percentile", null, null);
            $this->form->addGroup($group, 'score_header_group_'.$i, "<strong>Domain</strong>", $this->_GUIDelimiter, FALSE);
            unset($group);
        }
    }

    /**
    * Generates the first page of the form.
    *
    *@return void
    */
    function _page1()
    {
        $this->addHeader("Teacher's Report Form (TRF) for Ages 6-18");

        $pupil_gender_options = array(
                                 null   => "",
                                 "boy"  => "Boy",
                                 "girl" => "Girl",
                                );

        $this->addSelect("pupil_gender", "PUPIL'S SEX", $pupil_gender_options);

        $this->addBasicText("pupil_age", "PUPIL'S AGE <br><h5><i>(Please enter a numeric value between 0-100. If you don't wish to answer, enter NA)</i></h5>");

        $this->addBasicText("pupil_ethnic_group_race", "PUPIL'S ETHNIC GROUP OR RACE");

        $this->addBasicDate('pupil_birthdate', "Pupil's Birthdate (if known)");

        $this->XINRegisterRule(
            "pupil_birthdate",
            array("pupil_birthdate{@}=={@}NEVER_REQUIRED"),
            "Never required."
        );

        $this->addBasicText("grade_in_school", "GRADE IN SCHOOL <br><h5><i>(Please enter a numeric value between 1-12 or K.)</i></h5>");

        $this->addLabel("<h3>PARENTS' USUAL TYPE OF WORK, even if not working now <i>(Please be specific -- for example, auto mechanic, high school teacher, homemaker, laborer, lathe operator, shoe salesman, army sergeant.)</i></h3>");

        $this->addBasicText("parent1_type_of_work", "PARENT 1 (or FATHER) TYPE OF WORK");

        $this->XINRegisterRule(
            "parent1_type_of_work",
            array("parent2_type_of_work{@}=={@}"),
            "Required."
        );

        $this->addBasicText("parent2_type_of_work", "PARENT 2 (or MOTHER) TYPE OF WORK");

        $this->XINRegisterRule(
            "parent2_type_of_work",
            array("parent1_type_of_work{@}=={@}"),
            "Required."
        );

        $role_options = array(
                         null                => "",
                         "classroom_teacher" => "Classroom Teacher",
                         "special_educator"  => "Special Educator",
                         "teachers_aide"     => "Teacher's Aide",
                         "counselor"         => "Counselor",
                         "administrator"     => "Administrator",
                         "other"             => "Other (specify):",
                        );

        $this->addSelect("role_at_school", "Your role at school:", $role_options);

        $this->addBasicText("if_other_role", "$this->indent If other, please specify:");

        $this->XINRegisterRule(
            "if_other_role",
            array("role_at_school{@}=={@}other"),
            "Required."
        );

        $this->addBasicText("I_months_known_pupil", "<h3>I. For how many months have you known this pupil?</h3><h5><i>(Please enter a numeric value between 0-120. If you don't wish to answer, enter NA.)</i></h5>");

        $II_options = array(
                       null         => "",
                       "not_well"   => "1. Not Well",
                       "moderately" => "2. Moderately Well",
                       "very_well"  => "3. Very Well",
                      );

        $this->addSelect("II_how_well_do_you_know_pupil", "<h3>II. How well do you know him/her?</h3>", $II_options);

        $this->addBasicText("III_time_per_week", "<h3>III. How much time does he/she spend in your class or service per week?</h3>");

        $this->addBasicText("IV_kind_of_class_or_service", "<h3>IV. What kind of class or service is it? (Please be specific, e.g., regular 5th grade, 7th grade math, learning disability, counseling, etc.)</h3>");

        $V_VI_options = array(
                         null        => "",
                         "dont_know" => "Don't Know",
                         "no"        => "0. No",
                         "yes"       => "1. Yes",
                        );

        $this->addSelect("V_been_referred_for_special", "<h3>V. Has he/she ever been referred for special class placement, services, or tutoring?</h3>", $V_VI_options);

        $this->addBasicText("V_is_yes", "$this->indent If Yes -- what kind and when?");

        $this->XINRegisterRule(
            "V_is_yes",
            array("V_been_referred_for_special{@}=={@}yes"),
            "Required."
        );

        $this->addSelect("VI_repeated_any_grades", "<h3>VI. Has he/she repeated any grades?</h3>", $V_VI_options);

        $this->addBasicText("VI_is_yes", "$this->indent Yes -- grades and reasons:");

        $this->XINRegisterRule(
            "VI_is_yes",
            array("VI_repeated_any_grades{@}=={@}yes"),
            "Required."
        );

        $this->addLabel("<h3>VII. Current academic performance -- list academic subjects and check box that indicates pupil's performance for each subject:</h3>");

        $VII_academic_performance_options = array(
                                             null                   => "",
                                             "far_below_grade"      => "1. Far below grade",
                                             "somewhat_below_grade" => "2. Somewhat below grade",
                                             "at_grade_level"       => "3. At grade level",
                                             "somewhat_above_grade" => "4. Somewhat above grade",
                                             "far_above_grade"      => "5. Far above grade",
                                            );

        $group[] =& $this->form->createElement(
            "static",
            null,
            null,
            "<h4>Academic Subject</h4>"
        );
        $group[] =& $this->form->createElement(
            "static",
            null,
            null,
            "<h4>Current performance</h4>"
        );
        $this->addGroup(
            $group,
            "page1_headers",
            null,
            $this->_GUIDelimiter,
            false
        );
        unset($group);

        for ($i=1; $i <= 6; $i++) {

            $this->addLabel($i . ".");

            $group[] =& $this->createText(
                "academic_subject_{$i}",
                ""
            );
            $group[] =& $this->createSelect(
                "academic_subject_" . $i . "_current_performance",
                "Current academic performance",
                $VII_academic_performance_options
            );

            // Not all 6 subjects are required
            $this->XINRegisterRule(
                "academic_subject_{$i}",
                array("academic_subject_{$i}_current_performance{@}!={@}"),
                "Required.",
                "academic_subject_" . $i . "_group"
            );
            $this->XINRegisterRule(
                "academic_subject_" . $i . "_current_performance",
                array("academic_subject_{$i}{@}!={@}"),
                "Required.",
                "academic_subject_" . $i . "_group"
            );

            $this->addGroup(
                $group,
                "academic_subject_" . $i . "_group",
                null,
                $this->_GUIDelimiter,
                false
            );
            unset($group);
        }

        $this->form->addFormRule(array(&$this, 'validate_page1'));
    }

    /**
    * Generates the second page of the form.
    *
    *@return void
    */
    function _page2()
    {
        $this->addHeader("Teacher's Report Form (TRF) for Ages 6-18");

        $VIII_options = array(
                         null            => "",
                         "much_less"     => "1. Much less",
                         "somewhat_less" => "2. Somewhat less",
                         "slightly_less" => "3. Slightly less",
                         "average"       => "4. About average",
                         "slightly_more" => "5. Slightly more",
                         "somewhat_more" => "6. Somewhat more",
                         "much_more"     => "7. Much more",
                        );

        $this->addLabel("<h3>VIII. Compared to typical pupils of the same age:</h3>");

        $questions = array(
                      "q1_how_hard_working"           => "1. How hard is he/she working?",
                      "q2_how_appropriately_behaving" => "2. How appropriately is he/she behaving?",
                      "q3_how_much_learning"          => "3. How much is he/she learning?",
                      "q4_how_happy"                  => "4. How happy is he/she?",
                     );

        foreach ($questions as $key => $question) {
            $this->addSelect($key, $question, $VIII_options);
        }

        $this->addLabel("<h3>IX. Most recent achievement test scores (optional):</h3>");

        $group[] =& $this->form->createElement(
            "static",
            null,
            null,
            "<h4>Name of test</h4>"
        );
        $group[] =& $this->form->createElement(
            "static",
            null,
            null,
            "<h4>Subject</h4>"
        );
        $group[] =& $this->form->createElement(
            "static",
            null,
            null,
            "<h4>Date</h4>"
        );
        $group[] =& $this->form->createElement(
            "static",
            null,
            null,
            "<h4>Percentile or grade level obtained</h4>"
        );
        $this->addGroup(
            $group,
            "page2_IX_headers",
            null,
            $this->_GUIDelimiter,
            false
        );
        unset($group);

        for ($i=1; $i <= 5; $i++) {

            $group[] =& $this->createText(
                "recent_test_{$i}",
                ""
            );
            $group[] =& $this->createText(
                "recent_test_{$i}_subject",
                ""
            );
            $group[] =& $this->createDate(
                "recent_test_{$i}_date",
                ""
            );
            $group[] =& $this->createText(
                "recent_test_{$i}_grade_level",
                ""
            );

            $this->XINRegisterRule(
                "recent_test_{$i}",
                array("recent_test_{$i}_{@}=={@}NEVER_REQUIRED"),
                "Not Required",
                "recent_test_" . $i . "_group"
            );
            $this->XINRegisterRule(
                "recent_test_{$i}_subject",
                array("test_{$i}_subject{@}=={@}NEVER_REQUIRED"),
                "Not Required",
                "recent_test_" . $i . "_group"
            );
            $this->XINRegisterRule(
                "recent_test_{$i}_date",
                array("test_{$i}_date{@}=={@}NEVER_REQUIRED"),
                "Not Required",
                "recent_test_" . $i . "_group"
            );
            $this->XINRegisterRule(
                "recent_test_{$i}_grade_level",
                array("test_{$i}_grade_level{@}=={@}NEVER_REQUIRED"),
                "Not Required",
                "recent_test_" . $i . "_group"
            );
            $this->addGroup(
                $group,
                "test_" . $i . "_group",
                null,
                $this->_GUIDelimiter,
                false
            );
            unset($group);
        }

        $this->addLabel("<h3>X. IQ, readiness, or aptitude tests (optional):</h3>");

        $group1[] =& $this->form->createElement(
            "static",
            null,
            null,
            "<h4>Name of test</h4>"
        );
        $group1[] =& $this->form->createElement(
            "static",
            null,
            null,
            "<h4>Date</h4>"
        );
        $group1[] =& $this->form->createElement(
            "static",
            null,
            null,
            "<h4>IQ or equivalent scores</h4>"
        );
        $this->addGroup(
            $group1,
            "page2_X_headers",
            null,
            $this->_GUIDelimiter,
            false
        );
        unset($group1);

        for ($i=1; $i <= 3; $i++) {

            $group1[] =& $this->createText(
                "test_{$i}",
                ""
            );
            $group1[] =& $this->createDate(
                "test_{$i}_date",
                ""
            );
            $group1[] =& $this->createText(
                "test_{$i}_iq_or_equiv",
                ""
            );

            $this->XINRegisterRule(
                "test_{$i}",
                array("test_{$i}_{@}=={@}NEVER_REQUIRED"),
                "Not Required",
                "test_" . $i . "_group1"
            );
            $this->XINRegisterRule(
                "test_{$i}_date",
                array("test_{$i}_date{@}=={@}NEVER_REQUIRED"),
                "Not Required",
                "test_" . $i . "_group1"
            );
            $this->XINRegisterRule(
                "test_{$i}_iq_or_equiv",
                array("test_{$i}_iq_or_equiv{@}=={@}NEVER_REQUIRED"),
                "Not Required",
                "test_" . $i . "_group1"
            );
            $this->addGroup(
                $group1,
                "test_" . $i . "_group1",
                null,
                $this->_GUIDelimiter,
                false
            );
            unset($group1);
        }

        $yes_no_options = array(
                           null  => "",
                           "no"  => "No",
                           "yes" => "Yes",
                          );

        $this->addSelect("pupil_illness_disability", "Does this pupil have any illness or disability (either physical or mental)?", $yes_no_options);

        $this->addBasicText("pupil_illness_yes", "$this->indent If Yes - please describe:");

        $this->XINRegisterRule(
            "pupil_illness_yes",
            array("pupil_illness_disability{@}=={@}yes"),
            "Required."
        );

        $this->addBasicText("concerns_about_pupil", "What concerns you most about this pupil?");

        $this->addBasicText("best_things_about_pupil", "Please describe the best things about this pupil:");

        $this->addBasicText("comments_on_work_behavior_potential", "Please feel free to write any comments about this pupil's work, behavior, or potential.");

        $this->XINRegisterRule(
            "comments_on_work_behavior_potential",
            array("comments_on_work_behavior_potential{@}=={@}NEVER_REQUIRED"),
            "Never required."
        );

        $this->form->addFormRule(array(&$this, 'validate_page2'));
    }
    /**
    * Generates the third page of the form.
    *
    *@return void
    */
    function _page3()
    {
        $this->addHeader("Teacher's Report Form (TRF) for Ages 6-18");

        $this->addLabel("<h3>Below is a list of items that describe pupils <b><i>now or within the past 2 months</i></b>. Please answer all items as well as you can, even if some do not seem to apply to this pupil.</h3>");

        $options = array(
                    null => "",
                    "0"  => "0 - Not True (as far as you know)",
                    "1"  => "1 - Somewhat or Sometimes True",
                    "2"  => "2 - Very True or Often True",
                   );

        $questions = array(
                      "q1_acts_too_young"                          => "1. Acts too young for his/her age",
                      "q2_hums_makes_noises_in_class"              => "2. Hums or makes other odd noises in class",
                      "q3_argues_a_lot"                            => "3. Argues a lot",
                      "q4_fails_to_finish_things_starts"           => "4. Fails to finish things he/she starts",
                      "q5_very_little_they_enjoy"                  => "5. There is very little that he/she enjoys",
                      "q6_defiant_talks_back"                      => "6. Defiant, talks back to stuff",
                      "q7_bragging_boasting"                       => "7. Bragging, boasting",
                      "q8_cant_concentrate_for_long"               => "8. Can't concentrate, can't pay attention for long",
                      "q9_cant_get_mind_off_certain_thoughts"      => "9. Can't get his/her mind off certain thoughts; obsessions (describe):",
                      "q10_cant_sit_still_restless"                => "10. Can't sit still, restless, or hyperactive",
                      "q11_clings_to_adults_dependent"             => "11. Clings to adults or too dependent",
                      "q12_complains_of_loneliness"                => "12. Complains of loneliness",
                      "q13_confused_in_a_fog"                      => "13. Confused or seems to be in a fog",
                      "q14_cries_a_lot"                            => "14. Cries a lot",
                      "q15_fidgets"                                => "15. Fidgets",
                      "q16_cruelty_bullying_meanness"              => "16. Cruelty, bullying, or meanness to others",
                      "q17_daydreams_gets_lost_in_thoughts"        => "17. Daydreams or gets lost in his/her thoughts",
                      "q18_harms_self_attempts_suicide"            => "18. Deliberately harms self or attempts suicide",
                      "q19_demands_a_lot_of_attention"             => "19. Demands a lot of attention",
                      "q20_destroys_own_things"                    => "20. Destroys his/her own things",
                      "q21_destroys_others_property"               => "21. Destroys property belonging to others",
                      "q22_difficulty_following_directions"        => "22. Difficulty following directions",
                      "q23_disobedient_at_school"                  => "23. Disobedient at school",
                      "q24_disturbs_other_pupils"                  => "24. Disturbs other pupils",
                      "q25_doesnt_get_along_with_other_pupils"     => "25. Doesn't get along with other pupils",
                      "q26_doesnt_feel_guilty_misbehaving"         => "26. Doesn't seem to feel guilty after misbehaving",
                      "q27_easily_jealous"                         => "27. Easily jealous",
                      "q28_breaks_school_rules"                    => "28. Breaks school rules",
                      "q29_fears_animals_situations_places"        => "29. Fears certain animals, situations, or places, other than school (describe):",
                      "q30_fears_going_to_school"                  => "30. Fears going to school",
                      "q31_fears_might_think_do_something_bad"     => "31. Fears he/she might think or do something bad",
                      "q32_feels_has_to_be_perfect"                => "32. Feels he/she has to be perfect",
                      "q33_feels_complains_no_one_loves_them"      => "33. Feels or complains that no one loves him/her",
                      "q34_feels_others_out_to_get_them"           => "34. Feels others are out to get him/her",
                      "q35_feels_worthless_inferior"               => "35. Feels worthless or inferior",
                      "q36_gets_hurt_a_lot_accident_prone"         => "36. Gets hurt a lot, accident-prone",
                      "q37_gets_in_many_fights"                    => "37. Gets in many fights",
                      "q38_gets_teased_a_lot"                      => "38. Gets teased a lot",
                      "q39_hangs_around_others_who_get_in_trouble" => "39. Hangs around with others who get in trouble",
                      "q40_hears_sounds_voices_arent_there"        => "40. Hears sounds or voices that aren't there (describe):",
                      "q41_impulsive_acts_without_thinking"        => "41. Impulsive or acts without thinking",
                      "q42_would_rather_be_alone"                  => "42. Would rather be alone than with others",
                      "q43_lying_or_cheating"                      => "43. Lying or cheating",
                      "q44_bites_fingernails"                      => "44. Bites fingernails",
                      "q45_nervous_high_strung_tense"              => "45. Nervous, high-strung, or tense",
                      "q46_nervous_movements_twitching"            => "46. Nervous movements or twitching (describe):",
                      "q47_overconforms_to_rules"                  => "47. Overconforms to rules",
                      "q48_not_liked_by_other_pupils"              => "48. Not liked by other pupils",
                      "q49_has_difficulty_learning"                => "49. Has difficulty learning",
                      "q50_too_fearful_or_anxious"                 => "50. Too fearful or anxious",
                      "q51_feels_dizzy_lightheaded"                => "51. Feels dizzy or lightheaded",
                      "q52_feels_too_guilty"                       => "52. Feels too guilty",
                      "q53_talks_out_of_turn"                      => "53. Talks out of turn",
                      "q54_overtired_without_good_reason"          => "54. Overtired without good reason",
                      "q55_overweight"                             => "55. Overweight",
                      "q56a_aches_or_pains"                        => "a. Aches or pains (<i>not</i> stomach or headaches)",
                      "q56b_headaches"                             => "b. Headaches",
                      "q56c_nausea_feels_sick"                     => "c. Nausea, feels sick",
                      "q56d_eye_problems"                          => "d. Eye problems (<i>not</i> if corrected by glasses)(describe):",
                      "q56e_rashes_or_skin_problems"               => "e. Rashes or other skin problems",
                      "q56f_stomachaches"                          => "f. Stomachaches",
                      "q56g_vomiting_throwing_up"                  => "g. Vomiting, throwing up",
                      "q56h_other"                                 => "h. Other (describe):",
                     );

        foreach ($questions as $key => $question) {
            // add label for q56
            if ($key == "q56a_aches_or_pains") {
                $this->addLabel("56. Physical problems <b><i>without known medical cause:</i></b>");
            }

            $this->addSelect($key, $question, $options);

            // if the question contains (describe), include text element
            if (strpos($question, "(describe)") !== false) {

                $str = substr($key, 0, strpos($key, "_")+1)."describe";

                $this->addBasicText($str, "$this->indent Describe: <br><h5><i>$this->indent$this->indent(Required if selected \"Somewhat or Sometimes True\" or \"Very True or Often True\".)</i></h5>");

                $this->XINRegisterRule(
                    $str,
                    array("{$key}{@}=={@}1|2"),
                    "Required."
                );
            }
        }

        $this->form->addFormRule(array(&$this, 'validate_page3'));
    }
    /**
    * Generates the fourth page of the form.
    *
    *@return void
    */
    function _page4()
    {
        $this->addHeader("Teacher's Report Form (TRF) for Ages 6-18");

        $this->addLabel("<h3>Below is a list of items that describe pupils <b><i>now or within the past 2 months</i></b>. Please answer all items as well as you can, even if some do not seem to apply to this pupil.</h3>");

        $options = array(
                    null => "",
                    "0"  => "0 - Not True (as far as you know)",
                    "1"  => "1 - Somewhat or Sometimes True",
                    "2"  => "2 - Very True or Often True",
                   );

        $questions = array(
                      "q57_physically_attacks_people"                  => "57. Physically attacks people",
                      "q58_picks_nose_skin_other_parts_of_body"        => "58. Picks nose, skin, or other parts of body (describe):",
                      "q59_sleeps_in_class"                            => "59. Sleeps in class",
                      "q60_apathetic_unmotivated"                      => "60. Apathetic or unmotivated",
                      "q61_poor_school_work"                           => "61. Poor school work",
                      "q62_poorly_coordinated_clumsy"                  => "62. Poorly coordinated or clumsy",
                      "q63_prefers_older_children_youths"              => "63. Prefers being with older children or youths",
                      "q64_prefers_younger_children"                   => "64. Prefers being with younger children",
                      "q65_refuses_to_talk"                            => "65. Refuses to talk",
                      "q66_repeats_certain_acts_compulsions"           => "66. Repeats certain acts over and over; compulsions (describe):",
                      "q67_disrupts_class_discipline"                  => "67. Disrupts class discipline",
                      "q68_screams_a_lot"                              => "68. Screams a lot",
                      "q69_secretive"                                  => "69. Secretive, keeps things to self",
                      "q70_sees_things_that_arent_there"               => "70. Sees things that aren't there (describe):",
                      "q71_self_conscious_easily_embarrassed"          => "71. Self-conscious or easily embarrassed",
                      "q72_messy_work"                                 => "72. Messy work",
                      "q73_behaves_irresponsibly"                      => "73. Behaves irresponsibly (describe):",
                      "q74_showing_off_clowning"                       => "74. Showing off or clowning",
                      "q75_too_shy_or_timid"                           => "75. Too shy or timid",
                      "q76_explosive_unpredictable_behavior"           => "76. Explosive and unpredictable behavior",
                      "q77_demands_must_be_met_immediately"            => "77. Demands must be met immediately, easily frustrated",
                      "q78_inattentive_easily_distracted"              => "78. Inattentive or easily distracted",
                      "q79_speech_problem"                             => "79. Speech problem (describe):",
                      "q80_stares_blankly"                             => "80. Stares blankly",
                      "q81_feels_hurt_when_criticized"                 => "81. Feels hurt when criticized",
                      "q82_steals"                                     => "82. Steals",
                      "q83_stores_up_many_things_doesnt_need"          => "83. Stores up too many things he/she doesn't need (describe)",
                      "q84_strange_behaviour"                          => "84. Strange behaviour (describe):",
                      "q85_strange_ideas"                              => "85. Strange ideas (describe):",
                      "q86_stubborn_sullen_irritable"                  => "86. Stubborn, sullen, or irritable",
                      "q87_sudden_changes_in_mood_feelings"            => "87. Sudden changes in mood or feelings",
                      "q88_sulks_a_lot"                                => "88. Sulks a lot",
                      "q89_suspicious"                                 => "89. Suspicious",
                      "q90_swearing_or_obscene_language"               => "90. Swearing or obscene language",
                      "q91_talks_about_killing_self"                   => "91. Talks about killing self",
                      "q92_underachieving_not_working_to_potential"    => "92. Underachieving, not working up to potential",
                      "q93_talks_too_much"                             => "93. Talks too much",
                      "q94_teases_a_lot"                               => "94. Teases a lot",
                      "q95_temper_tantrums_hot_temper"                 => "95. Temper tantrums or hot temper",
                      "q96_seems_preoccupied_with_sex"                 => "96. Seems preoccupied with sex",
                      "q97_threatens_people"                           => "97. Threatens people",
                      "q98_tardy_to_school_class"                      => "98. Tardy to school or class",
                      "q99_smokes_chews_sniffs_tobacco"                => "99. Smokes, chews, or sniffs tobacco",
                      "q100_fails_to_carry_out_tasks"                  => "100. Fails to carry out assigned tasks",
                      "q101_truancy_unexplained_absence"               => "101. Truancy or unexplained absence",
                      "q102_underactive_slow_moving_lacks_energy"      => "102. Underactive, slow moving, or lacks energy",
                      "q103_unhappy_sad_depressed"                     => "103. Unhappy, sad, or depressed",
                      "q104_unusually_loud"                            => "104. Unusually loud",
                      "q105_uses_alcohol_drugs_nonmedical"             => "105. Uses alcohol or drugs for nonmedical purposes (<i>don't</i> include tobacco)(describe):",
                      "q106_overly_anxious_to_please"                  => "106. Overly anxious to please",
                      "q107_dislikes_school"                           => "107. Dislikes school",
                      "q108_is_afraid_making_mistakes"                 => "108. Is afraid of making mistakes",
                      "q109_whining"                                   => "109. Whining",
                      "q110_unclean_personal_appearance"               => "110. Unclean personal appearance",
                      "q111_withdrawn_doesnt_get_involved_with_others" => "111. Withdrawn, doesn't get involved with others",
                      "q112_worries"                                   => "112. Worries",
                     );

        foreach ($questions as $key => $question) {

            $this->addSelect($key, $question, $options);

            // if the question contains (describe), include text element
            if (strpos($question, "(describe)") !== false) {

                $str = substr($key, 0, strpos($key, "_")+1)."describe";

                $this->addBasicText($str, "$this->indent Describe: <br><h5><i>$this->indent$this->indent(Required if selected \"Somewhat or Sometimes True\" or \"Very True or Often True\".)</i></h5>");

                $this->XINRegisterRule(
                    $str,
                    array("{$key}{@}=={@}1|2"),
                    "Required."
                );
            }
        }

        $this->addLabel("113. Please write any problems the pupil has that were not listed above.");

        $group[] =& $this->form->createElement(
            "static",
            null,
            null,
            "<h4>Problem</h4>"
        );
        $group[] =& $this->form->createElement(
            "static",
            null,
            null,
            "<h4>Problem rating</h4>"
        );
        $this->addGroup(
            $group,
            "page4_headers",
            null,
            $this->_GUIDelimiter,
            false
        );
        unset($group);

        for ($i=1; $i <= 3; $i++) {
            $this->addLabel($i . ".");

            $group[] =& $this->createText(
                "additional_problem_{$i}",
                ""
            );
            $group[] =& $this->createSelect(
                "additional_problem_" . $i . "_rating",
                "Additional Problems",
                $options
            );

            $this->XINRegisterRule(
                "additional_problem_" . $i . "_rating",
                array("additional_problem_{$i}{@}!={@}"),
                "Required",
                "additional_problem_" . $i . "_group"
            );
            // if someone adds score, the problem must be inputted
            $this->XINRegisterRule(
                "additional_problem_{$i}",
                array("additional_problem_{$i}_rating{@}=={@}0|1|2"),
                "Required.",
                "additional_problem_" . $i . "_group"
            );
            $this->addGroup(
                $group,
                "additional_problem_" . $i . "_group",
                null,
                $this->_GUIDelimiter,
                false
            );
            unset($group);
        }

        $this->form->addFormRule(array(&$this, 'validate_page4'));
    }

    function validate_page1($values)
    {
        $errors = [];

        // NA option because this is a Teacher form
        $this->validate_age($values, "pupil_age", $errors);

        $this->validate_grade($values, "grade_in_school", $errors);

        if ($values["role_at_school"] != "other") {
            $this->validate_empty_subquestions($values, ["if_other_role"], $errors);
        }

        $this->validate_numeric($values, "I_months_known_pupil", $errors, 0, 120);

        if ($values["V_been_referred_for_special"] != "yes") {
            $this->validate_empty_subquestions($values, ["V_is_yes"], $errors);
        }

        if ($values["VI_repeated_any_grades"] != "yes") {
            $this->validate_empty_subquestions($values, ["VI_is_yes"], $errors);
        }

        return $errors;
    }

    function validate_page2($values)
    {
        $errors = [];

        if ($values["pupil_illness_disability"] != "yes") {
            $this->validate_empty_subquestions($values, ["pupil_illness_yes"], $errors);
        }

        return $errors;
    }

    function validate_page3($values)
    {
        $errors = [];

        $questions = array(
                      "q9_cant_get_mind_off_certain_thoughts" => "q9_describe",
                      "q29_fears_animals_situations_places"   => "q29_describe",
                      "q40_hears_sounds_voices_arent_there"   => "q40_describe",
                      "q46_nervous_movements_twitching"       => "q46_describe",
                      "q56d_eye_problems"                     => "q56d_describe",
                      "q56h_other"                            => "q56h_describe",
                     );

        foreach ($questions as $key => $describe) {
            if ($values[$key] == "0") {
                $this->validate_empty_subquestions($values, [$describe], $errors);
            }
        }

        return $errors;
    }

    function validate_page4($values)
    {
        $errors = [];

        $questions = array(
                      "q58_picks_nose_skin_other_parts_of_body" => "q58_describe",
                      "q66_repeats_certain_acts_compulsions"    => "q66_describe",
                      "q70_sees_things_that_arent_there"        => "q70_describe",
                      "q73_behaves_irresponsibly"               => "q73_describe",
                      "q79_speech_problem"                      => "q79_describe",
                      "q83_stores_up_many_things_doesnt_need"   => "q83_describe",
                      "q84_strange_behaviour"                   => "q84_describe",
                      "q85_strange_ideas"                       => "q85_describe",
                      "q105_uses_alcohol_drugs_nonmedical"      => "q105_describe",
                     );

        foreach ($questions as $key => $describe) {
            if ($values[$key] == "0") {
                $this->validate_empty_subquestions($values, [$describe], $errors);
            }
        }

        return $errors;
    }
    function score(): void
    {


        if($this->_determineDataEntryCompletionStatus() == "Incomplete") {
            return;
        }
        $scores['score_validity'] =NULL;

        //null scores
        $this->_nullScores($this->scoreLabels);

        //get the saved scores
        $db =& Database::singleton();
        $query = "SELECT * FROM $this->table WHERE CommentID = '$this->commentID'";
        $record = $db->pselectRow($query, array());


        // Syndrome Raw Score calculation Start
        $anxious_array = array(
            $record['q14_cries_a_lot'],
            $record['q29_fears_animals_situations_places'],
            $record['q30_fears_going_to_school'],
            $record['q31_fears_might_think_do_something_bad'],
            $record['q32_feels_has_to_be_perfect'],
            $record['q33_feels_complains_no_one_loves_them'],
            $record['q35_feels_worthless_inferior'],
            $record['q45_nervous_high_strung_tense'],
            $record['q50_too_fearful_or_anxious'],
            $record['q52_feels_too_guilty'],
            $record['q71_self_conscious_easily_embarrassed'],
            $record['q81_feels_hurt_when_criticized'],
            $record['q91_talks_about_killing_self'],
            $record['q106_overly_anxious_to_please'],
            $record['q108_is_afraid_making_mistakes'],
            $record['q112_worries'],
        );

        $depressed_array = array(
            $record['q5_very_little_they_enjoy'],
            $record['q42_would_rather_be_alone'],
            $record['q65_refuses_to_talk'],
            $record['q69_secretive'],
            $record['q75_too_shy_or_timid'],
            $record['q102_underactive_slow_moving_lacks_energy'],
            $record['q103_unhappy_sad_depressed'],
            $record['q111_withdrawn_doesnt_get_involved_with_others'],

        );
        $som_comp_array = array(
            $record['q51_feels_dizzy_lightheaded'],
            $record['q54_overtired_without_good_reason'],
            $record['q56a_aches_or_pains'],
            $record['q56b_headaches'],
            $record['q56c_nausea_feels_sick'],
            $record['q56d_eye_problems'],
            $record['q56e_rashes_or_skin_problems'],
            $record['q56f_stomachaches'],
            $record['q56g_vomiting_throwing_up'],

        );
        $social_prob_array = array(
            $record['q11_clings_to_adults_dependent'],
            $record['q12_complains_of_loneliness'],
            $record['q25_doesnt_get_along_with_other_pupils'],
            $record['q27_easily_jealous'],
            $record['q34_feels_others_out_to_get_them'],
            $record['q36_gets_hurt_a_lot_accident_prone'],
            $record['q38_gets_teased_a_lot'],
            $record['q48_not_liked_by_other_pupils'],
            $record['q62_poorly_coordinated_clumsy'],
            $record['q64_prefers_younger_children'],
            $record['q79_speech_problem'],


        );
        $thought_prob_array = array(
            $record['q9_cant_get_mind_off_certain_thoughts'],
            $record['q18_harms_self_attempts_suicide'],
            $record['q40_hears_sounds_voices_arent_there'],
            $record['q46_nervous_movements_twitching'],
            $record['q58_picks_nose_skin_other_parts_of_body'],
            $record['q66_repeats_certain_acts_compulsions'],
            $record['q70_sees_things_that_arent_there'],
            $record['q83_stores_up_many_things_doesnt_need'],
            $record['q84_strange_behaviour'],
            $record['q85_strange_ideas'],
        );
        $attention_prob_array = array(

            $record['q1_acts_too_young'],
            $record['q2_hums_makes_noises_in_class'],
            $record['q4_fails_to_finish_things_starts'],
            $record['q7_bragging_boasting'],
            $record['q8_cant_concentrate_for_long'],
            $record['q10_cant_sit_still_restless'],
            $record['q13_confused_in_a_fog'],
            $record['q15_fidgets'],
            $record['q17_daydreams_gets_lost_in_thoughts'],
            $record['q22_difficulty_following_directions'],
            $record['q24_disturbs_other_pupils'],
            $record['q41_impulsive_acts_without_thinking'],
            $record['q49_has_difficulty_learning'],
            $record['q53_talks_out_of_turn'],
            $record['q60_apathetic_unmotivated'],
            $record['q61_poor_school_work'],
            $record['q67_disrupts_class_discipline'],
            $record['q72_messy_work'],
            $record['q73_behaves_irresponsibly'],
            $record['q74_showing_off_clowning'],
            $record['q78_inattentive_easily_distracted'],
            $record['q80_stares_blankly'],
            $record['q92_underachieving_not_working_to_potential'],
            $record['q93_talks_too_much'],
            $record['q100_fails_to_carry_out_tasks'],
            $record['q109_whining'],

        );

        $rule_break_behav_array = array(
            $record['q26_doesnt_feel_guilty_misbehaving'],
            $record['q28_breaks_school_rules'],
            $record['q39_hangs_around_others_who_get_in_trouble'],
            $record['q43_lying_or_cheating'],
            $record['q63_prefers_older_children_youths'],
            $record['q82_steals'],
            $record['q90_swearing_or_obscene_language'],
            $record['q96_seems_preoccupied_with_sex'],
            $record['q98_tardy_to_school_class'],
            $record['q99_smokes_chews_sniffs_tobacco'],
            $record['q101_truancy_unexplained_absence'],
            $record['q105_uses_alcohol_drugs_nonmedical'],

        );
        $aggr_behav_array = array(
            $record['q3_argues_a_lot'],
            $record['q6_defiant_talks_back'],
            $record['q16_cruelty_bullying_meanness'],
            $record['q19_demands_a_lot_of_attention'],
            $record['q20_destroys_own_things'],
            $record['q21_destroys_others_property'],
            $record['q23_disobedient_at_school'],
            $record['q37_gets_in_many_fights'],
            $record['q57_physically_attacks_people'],
            $record['q68_screams_a_lot'],
            $record['q76_explosive_unpredictable_behavior'],
            $record['q77_demands_must_be_met_immediately'],
            $record['q86_stubborn_sullen_irritable'],
            $record['q87_sudden_changes_in_mood_feelings'],
            $record['q88_sulks_a_lot'],
            $record['q89_suspicious'],
            $record['q94_teases_a_lot'],
            $record['q95_temper_tantrums_hot_temper'],
            $record['q97_threatens_people'],
            $record['q104_unusually_loud'],
        );

        $other_prob_array= array(
            $record['q44_bites_fingernails'],
            $record['q47_overconforms_to_rules'],
            $record['q55_overweight'],
            $record['q56h_other'],
            $record['q59_sleeps_in_class'],
            $record['q107_dislikes_school'],
            $record['q110_unclean_personal_appearance'],
            $record['additional_problem_1'],
            $record['additional_problem_2'],
            $record['additional_problem_3'],
        );

        $scores['anxious_score'] = $this->findRawScore($anxious_array);
        $scores['depressed_score'] = $this->findRawScore($depressed_array);
        $scores['som_comp_score'] = $this->findRawScore($som_comp_array);
        $scores['social_prob_score'] = $this->findRawScore($social_prob_array);
        $scores['thought_prob_score'] = $this->findRawScore($thought_prob_array);
        $scores['attention_prob_score'] = $this->findRawScore($attention_prob_array);
        $scores['rule_break_behav_score'] = $this->findRawScore($rule_break_behav_array);
        $scores['aggr_behav_score'] =  $this->findRawScore($aggr_behav_array);
        $scores['other_prob_score'] =  $this->findRawScore($other_prob_array);
        // Syndrome Raw Score calculation Finished
        //Internalization
        $scores['internalizing_score'] = $this->findRawScore($anxious_array) +  $this->findRawScore($depressed_array) + $this->findRawScore($som_comp_array);
        $scores['externalizing_score'] = $this->findRawScore($rule_break_behav_array)  +  $this->findRawScore($aggr_behav_array);
        // Sum of ext +int +other_prob +social + thought + attention
        $scores['total_problems_score'] =$this->findRawScore($social_prob_array) + $this->findRawScore($thought_prob_array) +  $this->findRawScore($attention_prob_array) + $this->findRawScore($other_prob_array) + $scores['internalizing_score'] + $scores['externalizing_score'];
        //Internalization, Ext, to scoring finish
        //DSM oriented scoring start
        $depressive_prob_array=array(
            $record['q5_very_little_they_enjoy'],
            $record['q14_cries_a_lot'],
            $record['q18_harms_self_attempts_suicide'],
            $record['q35_feels_worthless_inferior'],
            $record['q52_feels_too_guilty'],
            $record['q54_overtired_without_good_reason'],
            $record['q60_apathetic_unmotivated'],
            $record['q91_talks_about_killing_self'],
            $record['q102_underactive_slow_moving_lacks_energy'],
            $record['q103_unhappy_sad_depressed'],
        );
        $scores['depressive_prob_score'] = $this->findRawScore($depressive_prob_array);

        $anx_prob_array=array(
            $record['q11_clings_to_adults_dependent'],
            $record['q29_fears_animals_situations_places'],
            $record['q30_fears_going_to_school'],
            $record['q31_fears_might_think_do_something_bad'],
            $record['q45_nervous_high_strung_tense'],
            $record['q47_nightmares'],
            $record['q50_too_fearful_or_anxious'],
            $record['q71_self_conscious_easily_embarrassed'],
            $record['q112_worries'],

        );
        $scores['anx_prob_score'] = $this->findRawScore($anx_prob_array);

        $som_prob_array=array(
            $record['q56a_aches_or_pains'],
            $record['q56b_headaches'],
            $record['q56c_nausea_feels_sick'],
            $record['q56d_eye_problems'],
            $record['q56e_rashes_or_skin_problems'],
            $record['q56f_stomachaches'],
            $record['q56g_vomiting_throwing_up'],

        );
        $scores['som_prob_score'] = $this->findRawScore($som_prob_array);

        $attention_hyper_prob_array=array(
            $record['q4_fails_to_finish_things_starts'],
            $record['q8_cant_concentrate_for_long'],
            $record['q10_cant_sit_still_restless'],
            $record['q15_fidgets'],
            $record['q22_difficulty_following_directions'],
            $record['q24_disturbs_other_pupils'],
            $record['q41_impulsive_acts_without_thinking'],
            $record['q53_talks_out_of_turn'],
            $record['q67_disrupts_class_discipline'],
            $record['q78_inattentive_easily_distracted'],
            $record['q93_talks_too_much'],
            $record['q100_fails_to_carry_out_tasks'],
            $record['q104_unusually_loud'],

        );

        $scores['attention_hyper_prob_score']=$this->findRawScore($attention_hyper_prob_array);

        $oppo_def_prob_array=array(
            $record['q3_argues_a_lot'],
            $record['q6_defiant_talks_back'],
            $record['q23_disobedient_at_school'],
            $record['q86_stubborn_sullen_irritable'],
            $record['q95_temper_tantrums_hot_temper'],
        );
        $scores['oppo_def_prob_score']=$this->findRawScore($oppo_def_prob_array);

        $conduct_prob_array=array(
            $record['q16_cruelty_bullying_meanness'],
            $record['q21_destroys_others_property'],
            $record['q26_doesnt_feel_guilty_misbehaving'],
            $record['q28_breaks_school_rules'],
            $record['q37_gets_in_many_fights'],
            $record['q39_hangs_around_others_who_get_in_trouble'],
            $record['q43_lying_or_cheating'],
            $record['q57_physically_attacks_people'],
            $record['q73_behaves_irresponsibly'],
            $record['q82_steals'],
            $record['q90_swearing_or_obscene_language'],
            $record['q97_threatens_people'],
            $record['q101_truancy_unexplained_absence'],

        );
        $scores['conduct_prob_score']=$this->findRawScore($conduct_prob_array);
        // DSM oriented scoring finish

        //2007 scales scoring start

        $sluggish_cogn_tempo_array=array(
            $record['q13_confused_in_a_fog'],
            $record['q17_daydreams_gets_lost_in_thoughts'],
            $record['q60_apathetic_unmotivated'],
            $record['q80_stares_blankly'],
            $record['q102_underactive_slow_moving_lacks_energy'],

        );
        $scores['sluggish_cogn_tempo_score'] =$this->findRawScore($sluggish_cogn_tempo_array);

        $obsessive_comp_prob_array=array(
            $record['q9_cant_get_mind_off_certain_thoughts'],
            $record['q31_fears_might_think_do_something_bad'],
            $record['q32_feels_has_to_be_perfect'],
            $record['q52_feels_too_guilty'],
            $record['q66_repeats_certain_acts_compulsions'],
            $record['q84_strange_behaviour'],
            $record['q85_strange_ideas'],
            $record['q112_worries'],

        );
        $scores['obsessive_comp_prob_score'] =$this->findRawScore($obsessive_comp_prob_array);

        $stress_prob_array=array(
            $record['q3_argues_a_lot'],
            $record['q8_cant_concentrate_for_long'],
            $record['q9_cant_get_mind_off_certain_thoughts'],
            $record['q11_clings_to_adults_dependent'],
            $record['q31_fears_might_think_do_something_bad'],
            $record['q34_feels_others_out_to_get_them'],
            $record['q45_nervous_high_strung_tense'],
            $record['q50_too_fearful_or_anxious'],
            $record['q52_feels_too_guilty'],
            $record['q69_secretive'],
            $record['q87_sudden_changes_in_mood_feelings'],
            $record['q103_unhappy_sad_depressed'],
            $record['q111_withdrawn_doesnt_get_involved_with_others'],


        );
        $scores['stress_prob_score'] =$this->findRawScore($stress_prob_array);
        // 2007 scoring finish

        $Inatt_array= array($record['q1_acts_too_young'],
            $record['q4_fails_to_finish_things_starts'],
            $record['q8_cant_concentrate_for_long'],
            $record['q13_confused_in_a_fog'],
            $record['q17_daydreams_gets_lost_in_thoughts'],
            $record['q22_difficulty_following_directions'],
            $record['q49_has_difficulty_learning'],
            $record['q60_apathetic_unmotivated'],
            $record['q61_poor_school_work'],
            $record['q72_messy_work'],
            $record['q78_inattentive_easily_distracted'],
            $record['q80_stares_blankly'],
            $record['q92_underachieving_not_working_to_potential'],
            $record['q100_fails_to_carry_out_tasks'],
        );

        $scores['Inatt_score'] =$this->findRawScore($Inatt_array);

        $HyperImp_array= array(
            $record['q2_hums_makes_noises_in_class'],
            $record['q7_bragging_boasting'],
            $record['q10_cant_sit_still_restless'],
            $record['q15_fidgets'],
            $record['q24_disturbs_other_pupils'],
            $record['q41_impulsive_acts_without_thinking'],
            $record['q53_talks_out_of_turn'],
            $record['q67_disrupts_class_discipline'],
            $record['q73_behaves_irresponsibly'],
            $record['q74_showing_off_clowning'],
            $record['q93_talks_too_much'],
            $record['q109_whining'],
            );

        $scores['HyperImp_score'] = $this->findRawScore($HyperImp_array);

        $timepoint =& TimePoint::singleton($this->getSessionID());
        $dob = $timepoint->getEffectiveDateOfBirth();

        $age = Utility::calculateAge($dob, $record["Date_taken"]);

        $age_months = $age['year'] * 12 + $age['mon'] + ($age['day'] / 30);
        $age_years = $age_months / 12;
        $age_years = floor($age_years);
        if (in_array($age_years, range(6, 11))) {
            $age_range = "6 to 11";
        } else if (in_array($age_years, range(12, 18))) {
            $age_range = "12 to 18";
        } else if ($age_years < 6 && $age_years >18) {
            $scores['score_validity'] = "Age not valid for scoring";
        }

        if ($scores['score_validity'] != NULL) {
            echo "T score and classification are applicable only for ages  6 to 18 years";
            echo "\n";
        }


        $query_gender = "SELECT Sex FROM candidate as c, session as s, flag as f, $this->table as t WHERE t.CommentID = '$this->commentID'
AND f.CommentID=t.CommentID AND s.ID=f.SessionID AND s.CandID=c.CandID";
        $record_gender = $db->pselectRow($query_gender, array());
        if ($record_gender['Sex'] == 'Male') {
            $gender = 'M';
        }
        if ($record_gender['Sex'] == 'Female') {
            $gender = 'F';
        }
        $scales=array(
            'anxious',
            'depressed',
            'som_comp',
            'social_prob',
            'thought_prob',
            'rule_break_behav',
            'aggr_behav',
            'attention_prob',
            'internalizing',
            'externalizing',
            'total_problems',
            'depressive_prob',
            'anx_prob',
            'som_prob',
            'attention_hyper_prob',
            'oppo_def_prob',
            'conduct_prob',
            'sluggish_cogn_tempo',
            'obsessive_comp_prob',
            'stress_prob',
            'Inatt',
            'HyperImp'
        );


        foreach ($scales as $field) {
            $fied_raw_score=$scores[$field.'_score'];

            $query_scores1 = "SELECT * FROM Teachers_Report_Form_6_To_18_lookup WHERE
                age_years='$age_range' AND sex='$gender'  AND scale_raw_score= '$fied_raw_score' AND scale='$field'";
            $record_1 = $db->pselectRow($query_scores1, array());
            if (array_key_exists('scale_T_score', $record_1)) {
                if ($record_1['scale_T_score'] == "" || ($record_1['scale_T_score'] == NULL)) {
                    $scores[$field . '_T_score'] = "NA";
                } else {
                    $scores[$field . '_T_score'] = ($record_1['scale_T_score']);
                }
            } else {
                $scores[$field . '_T_score'] = "NA";
            }

            if (array_key_exists('scale_percentile', $record_1)) {
                if ($record_1['scale_percentile'] == "" || ($record_1['scale_percentile'] == NULL)) {
                    $scores[$field . '_percentile'] = "NA";
                } else {
                    $scores[$field . '_percentile'] = ($record_1['scale_percentile']);
                }
            } else {
                $scores[$field . '_percentile'] = "NA";
            }


        }

        $result = $db->update($this->table, $scores, array('CommentID'=>$this->getCommentID()));


    }
    function findRawScore($scale_array)
    {
        $raw_score=0;
        foreach ($scale_array as $val)
        {
            if($val=='0')
            {
                $raw_score=$raw_score+0;
            }
            if($val=='1')
            {
                $raw_score=$raw_score+1;
            }
            if($val=='2')
            {
                $raw_score=$raw_score+2;
            }
            if($val=='3')
            {
                $raw_score=$raw_score+3;
            }
        }
        return $raw_score;
    }
}
?>
