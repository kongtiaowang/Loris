<?php
/**
 * Creates the form elements for the ABCL instrument (Mom on Dad)
 *
 * PHP Version 7
 *
 * @category Instrument
 * @package  Main
 * @author   Sruthy Mathew <sruthy.mcin@gmail.com>
 * @license  http://www.gnu.org/licenses/gpl-3.0.txt GPLv3
 * @link     https://www.github.com/aces/IBIS/
 */

/**
 * Creates the form elements for the ABCL instrument (Mom on Dad)
 *
 * @category Instrument
 * @package  Main
 * @author   Sruthy Mathew <sruthy.mcin@gmail.com>
 * @license  http://www.gnu.org/licenses/gpl-3.0.txt GPLv3
 * @link     https://www.github.com/aces/IBIS/
 */
class NDB_BVL_Instrument_ABCL_MOM_ON_DAD extends NDB_BVL_Instrument
{
    use LegacyInstrumentTrait;

    var $scoreLabels = array(
                        "i_friends_total_score",
                        "i_friends_t_score",
                        "ii_spouse_partner_total_score",
                        "ii_spouse_partner_t_score",
                        //"iii_family_mean_score",
                        //"iii_family_t_score",
                        //"iv_job_total_score",
                        //"iv_job_t_score",
                        //"v_education_total_score",
                        //"v_education_t_score",
                        "mean_adaptive_score",
                        "mean_adaptive_t_score",
                        "tobacco_t_score",
                        "alcohol_t_score",
                        "drugs_t_score",
                        "mean_substance_use_score",
                        "mean_substance_use_t_score",
                        "critical_items_score",
                        "critical_items_t_score",
                        "i_anxious_depressed_score",
                        "i_anxious_depressed_t_score",
                        "ii_withdrawn_score",
                        "ii_withdrawn_t_score",
                        "iii_somatic_complaints_score",
                        "iii_somatic_complaints_t_score",
                        "iv_thought_problems_score",
                        "iv_thought_problems_t_score",
                        "v_attention_problems_score",
                        "v_attention_problems_t_score",
                        "vi_aggressive_behavior_score",
                        "vi_aggressive_behavior_t_score",
                        "vii_rule_breaking_behavior_score",
                        "vii_rule_breaking_behavior_t_score",
                        "viii_intrusive_score",
                        "viii_intrusive_t_score",
                        "other_problems_score",
                        "1_depressive_problems_score",
                        "1_depressive_problems_t_score",
                        "2_anxiety_problems_score",
                        "2_anxiety_problems_t_score",
                        "3_somatic_problems_score",
                        "3_somatic_problems_t_score",
                        "4_avoidant_personality_problems_score",
                        "4_avoidant_personality_problems_t_score",
                        "5_adh_problems_score",
                        "5_adh_problems_t_score",
                        "6_antisocial_personality_problems_score",
                        "6_antisocial_personality_problems_t_score",
                       );

    /**
     * Sample SQL statement for test_names table and instrument subtests table
     *
     * INSERT INTO test_names(Test_name, Full_name,Sub_group,isDirectEntry) VALUES ('<TEST_NAME>','<INSTRUMENT_TITLE>',1, false);
     * INSERT INTO instrument_subtests(Test_name, Subtest_name, Description, Order_number) VALUES('<TEST_NAME>', '<TEST_NAME>_page1', 'Page1', 1);
     */

    private const Default_Options = array(
                                     null => '',
                                     '2'  => '2-Very True or Often True',
                                     '1'  => '1-Somewhat or Sometimes True',
                                     '0'  => '0-Not True (as far as you know)',
                                     'nk' => 'Prefer not to answer',
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
    function setup(?string $commentID = null, ?string $page = null): void
    {
        $this->formType = "XIN";
        $this->form     = new LorisForm('test_form');
        $this->page     = $page;            // page label (number or
        // string - used by
        // user-defined child classes)
        // set the object properties
        $this->testName = "ABCL_MOM_ON_DAD";           // test_names.Test_name
        $this->table    = 'ABCL_MOM_ON_DAD';              // name of database table corresponding to instrument
        // data keyed by commentID
        $this->commentID = $commentID;
        //The array of dates/timestamps to convert to database dates/timestamps
        //Any HTML_Quickform date elements must be listed here
        $this->dateTimeFields = array(
                                 "Date_taken",
                                 "adult_birthdate",
                                );

        //The array of selects with multiple answers allowed
        //Any HTML_Quickform multiple selects must be listed here
        $this->_selectMultipleElements = array();

        // required fields for data entry completion status
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
        if (preg_match("/ABCL_MOM_ON_DAD(_page[0-9]+)/", $this->page, $matches)) {
            call_user_func(array($this, $matches[1]));
        } else {
            $this->_main();
        }
        //Defines the call back function for HTML Quickform to use when validating the form.
        // Validations are now blocking data entry as we have currently
        //no 'not answered' option . So quick solution from Leigh is to remove all the validations and will re implement once we add not_answered option to all instruments.
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
        $this->addHeader("ABCL Informant (Adult Informant Behavior Checklist) Ages 18-59 - Mom on Dad");

        $config =& NDB_Config::singleton();

        $dateOptions = array(
                        'language'         => 'en',
                        'format'           => 'YMd',
                        'minYear'          => $config->getSetting('startYear'),
                        'maxYear'          => $config->getSetting('endYear'),
                        'addEmptyOption'   => true,
                        'emptyOptionValue' => null,
                       );

        $this->addBasicDate('Date_taken', 'Date of Administration', $dateOptions);
        $opts = array(
                 null          => "",
                 "mother"      => "Mother",
                 "father"      => "Father",
                 "step_mother" => "Step Mother",
                 "step_father" => "Step Father",
                 "other"       => "Other",
                );
        $this->addSelect("relationship_to_child", "What is YOUR relationship to the child?", $opts);
        $this->addBasicText("other_relationship_to_child", $this->indent."If Other, please describe:");
        $this->XINRegisterRule(
            "other_relationship_to_child",
            array("relationship_to_child{@}=={@}other"),
            "Required",
            "other_relationship_to_child"
        );


        // SCORE TABLE
        $this->form->addElement('header', 'score', "Score Summary<h4><i>(Calculated on Completing Next Page)</i></h4>");

        // score column headers
        $group[] = $this->form->createElement('static', "category", null, null);
        $group[] = $this->form->createElement('static', "score", null, null);
        $group[] = $this->form->createElement('static', "t_score", null, null);
        $this->form->addGroup($group, 'score_header_group', "<strong>Scale</strong>", $this->_GUIDelimiter, false);
        unset($group);

        $domains = array(
                    "i_friends"                         => "I. Friends",
                    "ii_spouse_partner"                 => "II. Spouse/Partner",
                    //"iii_family"                        => "III. Family",
                    //"iv_job"                            => "IV. Job",
                    //"v_education"                       => "V. Education",
                    "mean_adaptive"                     => "Mean Adaptive",
                    "tobacco"                           => "Tobacco",
                    "alcohol"                           => "Alcohol",
                    "drugs"                             => "Drugs",
                    "mean_substance_use"                => "Mean Substance Use",
                    "critical_items"                    => "Critical Items",
                    "i_anxious_depressed"               => "I. Anxious/Depressed",
                    "ii_withdrawn"                      => "II. Withdrawn",
                    "iii_somatic_complaints"            => "III. Somatic Complaints",
                    "iv_thought_problems"               => "IV. Thought Problems",
                    "v_attention_problems"              => "V. Attention Problems",
                    "vi_aggressive_behavior"            => "VI. Aggressive Behavior",
                    "vii_rule_breaking_behavior"        => "VII. Rule Breaking Behavior",
                    "viii_intrusive"                    => "VIII. Intrusive",
                    "other_problems"                    => "Other Problems",
                    "1_depressive_problems"             => "1. Depressive Problems",
                    "2_anxiety_problems"                => "2. Anxiety Problems",
                    "3_somatic_problems"                => "3. Somatic Problems",
                    "4_avoidant_personality_problems"   => "4. Avoidant Personality Problems",
                    "5_adh_problems"                    => "5. AD-H Problems",
                    "6_antisocial_personality_problems" => "6. Antisocial Personality Problems",

                   );

        $columnHeaders = array(
                          "category" => "Category",
                          "score"    => "Score",
                          "t_score"  => "T-Score",
                         );

        foreach ($columnHeaders as $field => $label) {
            $columnHeaders[$field] .= "   ";
        }
        $this->localDefaults = array_merge($this->localDefaults, $columnHeaders);

        $category = "Adaptive Functioning";

        foreach ($domains as $field => $label) {
            foreach ($columnHeaders as $scoreField => $scoreLabel) {
                if ($scoreField == "category") {
                    if ($field == "tobacco") {
                        $category = "Substance Use";
                    }
                    if ($field == "i_anxious_depressed") {
                        $category = "Syndrome";
                    }
                    if ($field == "1_depressive_problems") {
                        $category = "DSM Oriented";
                    }
                    $group[] = $this->form->createElement('static', null, null, $category);
                }
                if ($scoreField == "score") {
                    if ($field == "i_friends" || $field == "ii_spouse_partner" || $field == "iv_job" || $field == "v_education") {
                        $group[] = $this->form->createElement('static', "{$field}_total_score", null, null);
                    } elseif ($field == "iii_family") {
                        $group[] = $this->form->createElement('static', "{$field}_mean_score", null, null);
                    } elseif ($field == "tobacco" || $field == "alcohol" || $field == "drugs") {
                        $group[] = $this->form->createElement('static', null, null, null);
                    } else {
                        $group[] = $this->form->createElement('static', "{$field}_{$scoreField}", null, null);
                    }
                }
                if ($scoreField == "t_score") {
                    if ($field != "other_problems") {
                        $group[] = $this->form->createElement('static', "{$field}_{$scoreField}", null, null);
                    }
                }
            }
            $this->form->addGroup($group, "{$label}_score_group", $label, $this->_GUIDelimiter, false);
            unset($group);
	}
	$this->form->addFormRule(array(&$this, 'validate_main_page'));
    }

    /**
    * Generates the first page of the form.
    *
    * @return void
    */
    function _page1()
    {
        $this->addHeader("ABCL Informant (Adult Informant Behavior Checklist) Ages 18-59 - Mom on Dad");

        //Child's Biological Father's Gender
        $gender_options = array(
                           null     => "",
                           "male"   => "Male",
                           "female" => "Female",
                           "other"  => "Other",
                          );

        $this->addSelect("adults_gender", "Child's Biological Father's Sex", $gender_options);

        //Child's Biological Father's Age
        $this->addBasicText("adult_age", "Child's Biological Father's Age <br><h5><i>(Please enter a numeric value between 0-100 or if you really don't wish to answer; enter NA)</i></h5>");
        //Ethnic Group or Race
        $this->addBasicText("ethnic_group_or_race", "Ethnic Group or Race");

        //Child's Biological Father's Birthdate (month, date, year)
        $this->addBasicDate('adult_birthdate', 'Child\'s Biological Father\'s Birthdate');

        //Highest Education
        $opts = array(
                 null    => "",
                 "1"     => "1. No high school diploma and no GED",
                 "2"     => "2. General Equivalency Diploma (GED)",
                 "3"     => "3. High school graduate",
                 "4"     => "4. Some college but no college degree",
                 "5"     => "5. Associate’s Degree",
                 "6"     => "6. Bachelor’s or RN Degree",
                 "7"     => "7. Some graduate school but no graduate degree",
                 "8"     => "8. Master’s Degree",
                 "9"     => "9. Doctoral or Law degree",
                 "other" => "Other education (specify)",
                 'nk'    => 'Prefer not to answer',
                );

        $this->addSelect("user_education", "Please Check Child's Biological Father's HIGHEST EDUCATION", $opts);

        $this->addBasicText("if_other_education", "$this->indent If other, please specify:");

        $this->XINRegisterRule(
            "if_other_education",
            array("user_education{@}=={@}other"),
            "Required."
        );

        $this->addLabel("Child's Biological Father's Usual Type of Work, even if not working now. Please be specific - for example, auto mechanic; high school teacher; homemaker; laborer; lathe operator; shoe salesman; army sergeant; student (indicate what he is studying & what degree is expected).");

        $this->addBasicText("work_adult", "Child's Biological Father's work");

        $this->addBasicText("work_spouse", "YOUR work");

        //Your relationship to Child's Biological Father
        $relationship_options = array(
                                 null      => "",
                                 "spouse"  => "Spouse",
                                 "partner" => "Partner",
                                 "other"   => "Other (specify)",
                                );

        $this->addSelect("relationship_to_adult", "Your relationship to Child's Biological Father:", $relationship_options);

        $this->addBasicText("if_other_relationship", "$this->indent If other, please specify:");

        $this->XINRegisterRule(
            "if_other_relationship",
            array("relationship_to_adult{@}=={@}other"),
            "Required."
        );

        $this->form->addElement("static", null, "<br/>");

        $this->addLabel("Please fill out this form to reflect <i>your</i> views, even if other people might not agree. You need not spend a lot of time on any item. Feel free to give additional comments (optional). <i>Be sure to answer all items</i>");

        //I. FRIENDS
        $this->addHeader("I. FRIENDS");

        $friends_options_1 = array(
                              null   => "",
                              "none" => "None",
                              "1"    => "1",
                              "2"    => "2 or 3",
                              "3"    => "4 or more",
                              'nk'   => 'Prefer not to answer',
                             );

        $friends_options_2 = array(
                              null => "",
                              "0"  => "Less than 1",
                              "1"  => "1 or 2",
                              "2"  => "3 or 4",
                              "3"  => "5 or more",
                              'nk' => 'Prefer not to answer',
                             );

        $friends_options_3 = array(
                              null            => "",
                              "not_well"      => "Not well",
                              "average"       => "Average",
                              "above_average" => "Above average",
                              "far_above"     => "Far above average",
                              'nk'            => 'Prefer not to answer',
                             );

        $this->addSelect("a_how_many_close_friends", "A. About how many close friends does he have? (Do not include family members.)", $friends_options_1);

        $this->addSelect("b_contact_with_close_friends", "B. About how many times a month does he have contact with any close friends? (Include in-person contacts, phone, letters, e-mail.)", $friends_options_2);

        $this->addSelect("c_how_well_do_they_get_along_with_friends", "C. How well does he get along with close friends?", $friends_options_3);

        $this->addSelect("d_how_many_times_do_family_or_friends_visit", "D. About how many times a month do any friends or family visit him?", $friends_options_2);

        $this->addBasicText("I_friends_comments", "Additional Comments (optional):");

        $this->XINRegisterRule(
            "I_friends_comments",
            array("I_friends_comments{@}=={@}NEVER_REQUIRED"),
            "Never required."
        );

        //II. SPOUSE OR PARTNER
        $this->addHeader("II. SPOUSE OR PARTNER");

        //marital status
        $marital_status_opts = array(
                                null        => "",
                                "never"     => "Never been married",
                                "living"    => "Married, living with spouse",
                                "widowed"   => "Widowed",
                                "separated" => "Married but separated from spouse",
                                "divorced"  => "Divorced",
                                "other"     => "Other- please describe",
                                'nk'        => 'Prefer not to answer',
                               );

        $this->addSelect("marital_status_user", "What is his marital status?", $marital_status_opts);

        $this->addBasicText("if_other_marital", "$this->indent If other, please describe: ");

        $this->XINRegisterRule(
            "if_other_marital",
            array("marital_status_user{@}=={@}other"),
            "Required."
        );

        //Did they live with partner?
        $yes_no_opts = array(
                        null  => "",
                        "no"  => "No",
                        "yes" => "Yes",
                        'nk'  => 'Prefer not to answer',
                       );

        //if yes, answer following questions
        //if no, skip following questions
        $this->addSelect(
            "live_with_partner",
            "At any time in the past 6 months, did he live with a spouse or partner?
        <br><h4><i>*(If 'No' selected, then subset of questions below (A-H) should be left blank OR if 'Yes', choose options beside items A-H)</i></h4>",
            $yes_no_opts
        );

        $this->addSelect("a_gets_along_well_with_partner", "A. Gets along well with spouse or partner", self::Default_Options);

        $this->XINRegisterRule(
            "a_gets_along_well_with_partner",
            array("live_with_partner{@}=={@}yes"),
            "Required."
        );

        $this->addSelect("b_trouble_sharing_responsibilities", "B. Has trouble sharing responsibilities with spouse or partner", self::Default_Options);

        $this->XINRegisterRule(
            "b_trouble_sharing_responsibilities",
            array("live_with_partner{@}=={@}yes"),
            "Required."
        );

        $this->addSelect("c_seems_satisfied_with_spouse_or_partner", "C. Seems satisfied with spouse or partner", self::Default_Options);

        $this->XINRegisterRule(
            "c_seems_satisfied_with_spouse_or_partner",
            array("live_with_partner{@}=={@}yes"),
            "Required."
        );

        $this->addSelect("d_enjoys_similar_activities_as_partner", "D. Enjoys similar activities as spouse or partner", self::Default_Options);

        $this->XINRegisterRule(
            "d_enjoys_similar_activities_as_partner",
            array("live_with_partner{@}=={@}yes"),
            "Required."
        );

        $this->addSelect("e_disagrees_with_partner_about_living_arrangements", "E. Disagrees with spouse or partner about living arrangements, such as where to live", self::Default_Options);

        $this->XINRegisterRule(
            "e_disagrees_with_partner_about_living_arrangements",
            array("live_with_partner{@}=={@}yes"),
            "Required."
        );

        $this->addSelect("f_has_trouble_with_family_of_partner", "F. Has trouble with spouse or partner's family", self::Default_Options);

        $this->XINRegisterRule(
            "f_has_trouble_with_family_of_partner",
            array("live_with_partner{@}=={@}yes"),
            "Required."
        );

        $this->addSelect("g_likes_friends_of_partner", "G. Likes spouse or partner's friends", self::Default_Options);

        $this->XINRegisterRule(
            "g_likes_friends_of_partner",
            array("live_with_partner{@}=={@}yes"),
            "Required."
        );

        $this->addSelect("h_annoyed_by_behavior_of_spouse", "H. Is annoyed by spouse or partner's behavior", self::Default_Options);

        $this->XINRegisterRule(
            "h_annoyed_by_behavior_of_spouse",
            array("live_with_partner{@}=={@}yes"),
            "Required."
        );

        $this->addBasicTextArea("II_spouse_partner_comments", "Additional Comments (optional):");

        $this->XINRegisterRule(
            "II_spouse_partner_comments",
            array("II_spouse_partner_comments{@}=={@}NEVER_REQUIRED")
        );

        $this->form->addFormRule(array(&$this, 'abcl_special_rules'));
    }

    /**
    * Generates the second page of the form.
    *
    * @return void
    */
    function _page2()
    {

        $this->addHeader("ABCL Informant (Adult Informant Behavior Checklist) Ages 18-59 - Mom on Dad");

        //III. Does he have any illness, disability, or handicap?
        $opts = array(
                 null  => "",
                 "no"  => "No",
                 "yes" => "Yes-please describe",
                 'nk'  => 'Prefer not to answer',
                );

        $this->addSelect("user_handicap", "<h4>III. Does he have any illness, disability, or handicap?</h4>", $opts);

        $this->addBasicText("user_handicap_yes", "$this->indent If yes, please describe:");

        $this->XINRegisterRule(
            "user_handicap_yes",
            array("user_handicap{@}=={@}yes"),
            "Required."
        );

        //IV. Please describe any concerns you have about him:
        $concerns_options = array(
                             null  => "",
                             "no"  => "No concerns",
                             "yes" => "Yes-please describe",
                             'nk'  => 'Prefer not to answer',
                            );

        $this->addSelect("user_concerns", "<h4>IV. Please describe any concerns you have about him:</h4>", $concerns_options);

        $this->addBasicText("user_concerns_yes", "$this->indent If yes, please describe:");

        $this->XINRegisterRule(
            "user_concerns_yes",
            array("user_concerns{@}=={@}yes"),
            "Required."
        );

        //V. Please describe the best things about him:
        $this->addBasicText("describe_best_things_about_them", "<h4>V. Please describe the best things about him:</h4>");

        $this->addBasicText("III_IV_V_comments", "Additional Comments (optional):");

        $this->XINRegisterRule(
            "III_IV_V_comments",
            array("III_IV_V_comments{@}=={@}NEVER_REQUIRED")
        );
        $this->form->addFormRule(array(&$this, 'abcl_special_rules'));
    }

    /**
    * Generates the third page of the form.
    *
    * @return void
    */
    function _page3()
    {
        $this->addHeader("ABCL Informant (Adult Informant Behavior Checklist) Ages 18-59 - Mom on Dad");

        $this->addLabel("<h3>VI. Below is a list of items that describe people. As you read each item, please decide whether it has been true of the child's biological father <i>over the past 6 months</i>. Then choose <i>0, 1,</i> or <i>2</i> to describe the child's biological father. Please answer all items as well as you can, even if some do not seem to apply to the child's biological father.</h3>");

        $this->addSelect("1_is_too_forgetful", "1. Is too forgetful", self::Default_Options);

        $this->addSelect("2_makes_good_use_of_opportunities", "2. Makes good use of his opportunities", self::Default_Options);

        $this->addSelect("3_argues_a_lot", "3. Argues a lot", self::Default_Options);

        $this->addSelect("4_works_up_to_ability", "4. Works up to ability", self::Default_Options);

        $this->addSelect("5_blames_others_for_own_problems", "5. Blames others for own problems", self::Default_Options);

        $this->addSelect("6_uses_drugs_for_nonmedical_purposes", "6.(i) Uses drugs (other than alcohol or nicotine) for nonmedical purposes", self::Default_Options);

        $this->addBasicText("6_continued", "6.(ii) Description: <h5><i>(Required if selected 'True' for the above)</i></h5>");

        $this->XINRegisterRule(
            "6_continued",
            array("6_uses_drugs_for_nonmedical_purposes{@}=={@}1|2"),
            "Required if selected True for the above"
        );

        $this->addSelect("7_bragging_boasting", "7. Bragging, boasting", self::Default_Options);

        $this->addSelect("8_cant_concentrate_or_pay_attention", "8. Can't concentrate, can't pay attention for long", self::Default_Options);

        $this->addSelect("9_cant_get_mind_off_certain_thoughts", "9.(i) Can't get mind off certain thoughts; obsessions", self::Default_Options);

        $this->addBasicText("9_continued", "9.(ii) Description: <h5><i>(Required if selected 'True' for the above)</i></h5>");

        $this->XINRegisterRule(
            "9_continued",
            array("9_cant_get_mind_off_certain_thoughts{@}=={@}1|2"),
            "Required if selected True for the above"
        );

        $this->addSelect("10_cant_sit_still", "10. Can't sit still, restless, or hyperactive", self::Default_Options);

        $this->addSelect("11_too_dependent_on_others", "11. Too dependent on others", self::Default_Options);

        $this->addSelect("12_complains_of_loneliness", "12. Complains of loneliness", self::Default_Options);

        $this->addSelect("13_confused_or_in_a_fog", "13. Confused or seems to be in a fog", self::Default_Options);

        $this->addSelect("14_cries_a_lot", "14. Cries a lot", self::Default_Options);

        $this->addSelect("15_pretty_honest", "15. Is pretty honest", self::Default_Options);

        $this->addSelect("16_cruelty_bullying_meanness", "16. Cruelty, bullying, or meanness to others", self::Default_Options);

        $this->addSelect("17_daydreams_or_gets_lost_in_thoughts", "17. Daydreams or gets lost in his thoughts", self::Default_Options);

        $this->addSelect("18_deliberately_harms_self", "18. Deliberately harms self or attempts suicide", self::Default_Options);

        $this->addSelect("19_demands_attention", "19. Demands a lot of attention", self::Default_Options);

        $this->addSelect("20_damages_own_things", "20. Damages or destroys his own things", self::Default_Options);

        $this->addSelect("21_damages_things_belonging_to_others", "21. Damages or destroys things belonging to others", self::Default_Options);

        $this->addSelect("22_worries_about_their_future", "22. Worries about his future", self::Default_Options);

        $this->addSelect("23_breaks_rules", "23. Breaks rules at work or elsewhere", self::Default_Options);

        $this->addSelect("24_does_not_eat_well", "24. Doesn't eat well", self::Default_Options);

        $this->addSelect("25_does_not_get_along_with_others", "25. Doesn't get along with other people", self::Default_Options);

        $this->addSelect("26_does_not_feel_guilty_after_misbehaving", "26. Doesn't seem to feel guilty after misbehaving", self::Default_Options);

        $this->addSelect("27_easily_jealous", "27. Easily jealous", self::Default_Options);

        $this->addSelect("28_gets_along_badly_with_family", "28. Gets along badly with family", self::Default_Options);

        $this->addSelect("29_fears_certain_animals_situations_places", "29.(i) Fears certain animals, situations, or places", self::Default_Options);

        $this->addBasicText("29_continued", "29.(ii) Description: <h5><i>(Required if selected 'True' for the above)</i></h5>");

        $this->XINRegisterRule(
            "29_continued",
            array("29_fears_certain_animals_situations_places{@}=={@}1|2"),
            "Required if selected True for the above"
        );

        $this->addSelect("30_poor_relations_with_opposite_sex", "30. Poor relations with opposite sex", self::Default_Options);

        $this->addSelect("31_fears_they_might_think_or_do_something_bad", "31. Fears he might think or do something bad", self::Default_Options);

        $this->addSelect("32_feels_they_have_to_be_perfect", "32. Feels he has to be perfect", self::Default_Options);

        $this->addSelect("33_feels_or_complains_that_no_one_loves_them", "33. Feels or complains that no one loves him", self::Default_Options);

        $this->addSelect("34_feels_others_are_out_to_get_them", "34. Feels others are out to get him", self::Default_Options);

        $this->addSelect("35_feels_worthless_or_inferior", "35. Feels worthless or inferior", self::Default_Options);

        $this->addSelect("36_gets_hurt_a_lot", "36. Gets hurt a lot, accident-prone", self::Default_Options);

        $this->form->addFormRule(array(&$this, 'abcl_special_rules'));
    }


    /**
    * Generates the fourth page of the form.
    *
    * @return void
    */
    function _page4()
    {
        $this->addHeader("ABCL Informant (Adult Informant Behavior Checklist) Ages 18-59 - Mom on Dad");

        $this->addSelect("37_gets_in_many_fights", "37. Gets in many fights", self::Default_Options);

        $this->addSelect("38_poor_relations_with_neighbors", "38. His relations with neighbors are poor", self::Default_Options);

        $this->addSelect("39_hangs_around_people_who_get_in_trouble", "39. Hangs around people who get in trouble", self::Default_Options);

        $this->addSelect("40_hears_sounds_or_voices", "40.(i) Hears sounds or voices that aren't there", self::Default_Options);

        $this->addBasicText("40_continued", "40.(ii) Description: <h5><i>(Required if selected 'True' for the above)</i></h5>");

        $this->XINRegisterRule(
            "40_continued",
            array("40_hears_sounds_or_voices{@}=={@}1|2"),
            "Required if selected True for the above"
        );

        $this->addSelect("41_acts_without_thinking", "41. Impulsive or acts without thinking", self::Default_Options);

        $this->addSelect("42_would_rather_be_alone", "42. Would rather be alone than with others", self::Default_Options);

        $this->addSelect("43_lying_or_cheating", "43. Lying or cheating", self::Default_Options);

        $this->addSelect("44_feels_overwhelmed_by_responsibilities", "44. Feels overwhelmed by responsibilities", self::Default_Options);

        $this->addSelect("45_nervous_highstrung_tense", "45. Nervous, highstrung, or tense", self::Default_Options);

        $this->addSelect("46_nervous_movements", "46.(i) Nervous movements or twitching", self::Default_Options);

        $this->addBasicText("46_continued", "46.(ii) Description: <h5><i>(Required if selected 'True' for the above)</i></h5>");

        $this->XINRegisterRule(
            "46_continued",
            array("46_nervous_movements{@}=={@}1|2"),
            "Required if selected True for the above"
        );

        $this->addSelect("47_lacks_self_confidence", "47. Lacks self-confidence", self::Default_Options);

        $this->addSelect("48_not_liked_by_others", "48. Not liked by others", self::Default_Options);

        $this->addSelect("49_can_do_certain_things_better_than_others", "49. Can do certain things better than other people", self::Default_Options);

        $this->addSelect("50_too_fearful_or_anxious", "50. Too fearful or anxious", self::Default_Options);

        $this->addSelect("51_feels_dizzy_or_lightheaded", "51. Feels dizzy or lightheaded", self::Default_Options);

        $this->addSelect("52_feels_too_guilty", "52. Feels too guilty", self::Default_Options);

        $this->addSelect("53_trouble_planning_for_future", "53. Has trouble planning for the future", self::Default_Options);

        $this->addSelect("54_trouble_planning_for_future", "54. Feels tired without good reasons", self::Default_Options);

        $this->addSelect("55_moods_swing_between_elation_and_depression", "55. Moods swing between elation and depression", self::Default_Options);

        $this->addLabel("56.Physical problems <i>without known medical cause:</i>");

        $this->addSelect("a_aches_or_pains", "a. Aches or pains (<i>not</i> stomach or headaches)", self::Default_Options);

        $this->addSelect("b_headaches", "b. Headaches", self::Default_Options);

        $this->addSelect("c_nausea", "c. Nausea, feels sick", self::Default_Options);

        $this->addSelect("d_problems_witih_eyes", "d.(i) Problems with eyes (<i>not</i> if corrected by glasses)", self::Default_Options);

        $this->addBasicText("d_continued", "d.(ii) Description: <h5><i>(Required if selected 'True' for Problems with eyes)</i></h5>");

        $this->XINRegisterRule(
            "d_continued",
            array("d_problems_witih_eyes{@}=={@}1|2"),
            "Required if selected True for the above"
        );

        $this->addSelect("e_skin_problems", "e. Rashes or other skin problems", self::Default_Options);

        $this->addSelect("f_stomachaches", "f. Stomachaches", self::Default_Options);

        $this->addSelect("g_vomiting", "g. Vomiting, throwing up", self::Default_Options);

        $this->addSelect("57_physically_attacks_people", "57. Physically attacks people", self::Default_Options);

        $this->addSelect("58_picks_skin_or_other_parts_of_body", "58.(i) Picks skin or other parts of his body", self::Default_Options);

        $this->addBasicText("58_continued", "58.(ii) Description: <h5><i>(Required if selected 'True' for the above)</i></h5>");

        $this->XINRegisterRule(
            "58_continued",
            array("58_picks_skin_or_other_parts_of_body{@}=={@}1|2"),
            "Required if selected True for the above"
        );

        $this->addSelect("59_fails_to_finish_things_they_should_do", "59. Fails to finish things he should do", self::Default_Options);

        $this->addSelect("60_enjoys_very_little", "60. There is very little that he enjoys", self::Default_Options);

        $this->addSelect("61_poor_work_performance", "61. Poor work performance", self::Default_Options);

        $this->addSelect("62_poorly_coordinated", "62. Poorly coordinated or clumsy", self::Default_Options);

        $this->form->addFormRule(array(&$this, 'abcl_special_rules'));
    }

    /**
    * Generates the fifth page of the form.
    *
    * @return void
    */
    function _page5()
    {
        $this->addHeader("ABCL Informant (Adult Informant Behavior Checklist) Ages 18-59 - Mom on Dad");

        $this->addSelect("63_would_rather_be_with_older_people", "63. Would rather be with older people than with people of own age", self::Default_Options);

        $this->addSelect("64_has_trouble_setting_priorities", "64. Has trouble setting priorities", self::Default_Options);

        $this->addSelect("65_refuses_to_talk", "65. Refuses to talk", self::Default_Options);

        $this->addSelect("66_repeats_certain_acts", "66.(i) Repeats certain acts over and over; compulsions", self::Default_Options);

        $this->addBasicText("66_continued", "66.(ii) Description: <h5><i>(Required if selected 'True' for the above)</i></h5>");

        $this->XINRegisterRule(
            "66_continued",
            array("66_repeats_certain_acts{@}=={@}1|2"),
            "Required if selected True for the above"
        );

        $this->addSelect("67_has_trouble_making_or_keeping_friends", "67. Has trouble making or keeping friends", self::Default_Options);

        $this->addSelect("68_screams_or_yells_a_lot", "68. Screams or yells a lot", self::Default_Options);

        $this->addSelect("69_keeps_things_to_self", "69. Secretive, keeps things to self", self::Default_Options);

        $this->addSelect("70_sees_things_that_are_not_there", "70.(i) Sees things that aren't there (describe)", self::Default_Options);

        $this->addBasicText("70_continued", "70.(ii) Description: <h5><i>(Required if selected 'True' for the above)</i></h5>");

        $this->XINRegisterRule(
            "70_continued",
            array("70_sees_things_that_are_not_there{@}=={@}1|2"),
            "Required if selected True for the above"
        );

        $this->addSelect("71_self_conscious_or_easily_embarrassed", "71. Self-conscious or easily embarrassed", self::Default_Options);

        $this->addSelect("72_worries_about_their_family", "72. Worries about his family", self::Default_Options);

        $this->addSelect("73_meets_responsibilities_to_their_family", "73. Meets responsibilities to his family", self::Default_Options);

        $this->addSelect("74_showing_off", "74. Showing off or clowning", self::Default_Options);

        $this->addSelect("75_too_shy_or_timid", "75. Too shy or timid", self::Default_Options);

        $this->addSelect("76_irresponsible_behavior", "76. Irresponsible behavior", self::Default_Options);

        $this->addSelect("77_sleeps_more_than_most_others", "77.(i) Sleeps more than most other people during day and/or night (describe)", self::Default_Options);

        $this->addBasicText("77_continued", "77.(ii) Description: <h5><i>(Required if selected 'True' for the above)</i></h5>");

        $this->XINRegisterRule(
            "77_continued",
            array("77_sleeps_more_than_most_others{@}=={@}1|2"),
            "Required if selected True for the above"
        );

        $this->addSelect("78_has_trouble_making_decisions", "78. Has trouble making decisions", self::Default_Options);

        $this->addSelect("79_speech_problem", "79.(i) Speech problem (describe)", self::Default_Options);

        $this->addBasicText("79_continued", "79.(ii) Description: <h5><i>(Required if selected 'True' for the above)</i></h5>");

        $this->XINRegisterRule(
            "79_continued",
            array("79_speech_problem{@}=={@}1|2"),
            "Required if selected True for the above"
        );

        $this->addSelect("80_stares_blankly", "80. Stares blankly", self::Default_Options);

        $this->addSelect("81_very_changeable_behaavior", "81. Very changeable behavior", self::Default_Options);

        $this->addSelect("82_steals", "82. Steals", self::Default_Options);

        $this->addSelect("83_easily_bored", "83. Is easily bored", self::Default_Options);

        $this->addSelect("84_strange_behavior", "84.(i) Strange behavior (describe)", self::Default_Options);

        $this->addBasicText("84_continued", "84.(ii) Description: <h5><i>(Required if selected 'True' for the above)</i></h5>");

        $this->XINRegisterRule(
            "84_continued",
            array("84_strange_behavior{@}=={@}1|2"),
            "Required if selected True for the above"
        );

        $this->addSelect("85_strange_ideas", "85.(i) Strange ideas (describe)", self::Default_Options);

        $this->addBasicText("85_continued", "85.(ii) Description: <h5><i>(Required if selected 'True' for the above)</i></h5>");

        $this->XINRegisterRule(
            "85_continued",
            array("85_strange_ideas{@}=={@}1|2"),
            "Required if selected True for the above"
        );

        $this->addSelect("86_stubborn_sullen_irritable", "86. Stubborn, sullen, or irritable", self::Default_Options);

        $this->addSelect("87_sudden_changes_in_mood_or_feelings", "87. Sudden changes in mood or feelings", self::Default_Options);

        $this->addSelect("88_enjoys_being_with_people", "88. Enjoys being with people", self::Default_Options);

        $this->addSelect("89_rushes_into_things_without_considering_risks", "89. Rushes into things without considering the risks", self::Default_Options);

        $this->addSelect("90_drinks_too_much_alcohol", "90. Drinks too much alcohol or gets drunk", self::Default_Options);

        $this->addSelect("91_talks_about_killing_self", "91. Talks about killing self", self::Default_Options);

        $this->addSelect("92_does_things_that_may_cause_trouble_with_law", "92(i). Does things that may cause trouble with the law (describe)", self::Default_Options);

        $this->addBasicText("92_continued", "92.(ii)Description: <h5><i>(Required if selected 'True' for the above)</i></h5>");

        $this->XINRegisterRule(
            "92_continued",
            array("92_does_things_that_may_cause_trouble_with_law{@}=={@}1|2"),
            "Required if selected True for the above"
        );

        $this->form->addFormRule(array(&$this, 'abcl_special_rules'));
    }

    /**
    * Generates the sixth page of the form.
    *
    * @return void
    */
    function _page6()
    {
        $this->addHeader("ABCL Informant (Adult Informant Behavior Checklist) Ages 18-59 - Mom on Dad");

        $this->addSelect("93_walks_too_much", "93. Talks too much", self::Default_Options);

        $this->addSelect("94_teases_a_lot", "94. Teases a lot", self::Default_Options);

        $this->addSelect("95_temper_tantrums", "95. Temper tantrums or hot temper", self::Default_Options);

        $this->addSelect("96_passive_or_lacks_initiative", "96. Passive or lacks initiative", self::Default_Options);

        $this->addSelect("97_threatens_to_hurt_people", "97. Threatens to hurt people", self::Default_Options);

        $this->addSelect("98_likes_to_help_others", "98. Likes to help others", self::Default_Options);

        $this->addSelect("99_dislikes_staying_in_one_place_for_long", "99. Dislikes staying in one place for very long", self::Default_Options);

        $this->addSelect("100_trouble_sleeping", "100. Has trouble sleeping", self::Default_Options);

        $this->addSelect("101_stays_away_from_job_even_when_not_sick_or_on_vacation", "101. Stays away from job even when not sick and not on vacation", self::Default_Options);

        $this->addSelect("102_underactive_slow_moving_lacks_energy", "102. Underactive, slow moving, or lacks energy", self::Default_Options);

        $this->addSelect("103_unhappy_sad_depressed", "103. Unhappy, sad, or depressed", self::Default_Options);

        $this->addSelect("104_unusually_loud", "104. Is unusually loud", self::Default_Options);

        $this->addSelect("105_disorganized", "105. Is disorganized", self::Default_Options);

        $this->addSelect("106_tries_to_be_fair", "106. Tries to be fair to others", self::Default_Options);

        $this->addSelect("107_feels_they_cant_succeed", "107. Feels he can't succeed", self::Default_Options);

        $this->addSelect("108_tends_to_lose_things", "108. Tends to lose things", self::Default_Options);

        $this->addSelect("109_likes_to_try_new_things", "109. Likes to try new things", self::Default_Options);

        $this->addSelect("110_makes_good_decisions", "110. Makes good decisions", self::Default_Options);

        $this->addSelect("111_withdrawn_not_involved_with_others", "111. Withdrawn, doesn't get involved with others", self::Default_Options);

        $this->addSelect("112_worries", "112. Worries", self::Default_Options);

        $this->addSelect("113_sulks_a_lot", "113. Sulks a lot", self::Default_Options);

        $this->addSelect("114_fails_to_pay_debts_or_meet_financial_responsibilities", "114. Fails to pay his debts or meet other financial responsibilities", self::Default_Options);

        $this->addSelect("115_restless_or_fidgety", "115. Is restless or fidgety", self::Default_Options);

        $this->addSelect("116_gets_upset_too_easily", "116. Gets upset too easily", self::Default_Options);

        $this->addSelect("117_trouble_managing_money_or_credit_cards", "117. Has trouble managing money or credit cards", self::Default_Options);

        $this->addSelect("118_too_impatient", "118. Is too impatient", self::Default_Options);

        $this->addSelect("119_not_good_at_details", "119. he is not good at details", self::Default_Options);

        $this->addSelect("120_drives_too_fast", "120. Drives too fast", self::Default_Options);

        $this->addSelect("121_tends_to_be_late_for_appointments", "121. Tends to be late for appointments", self::Default_Options);

        $this->addSelect("122_trouble_keeping_job", "122. Has trouble keeping a job", self::Default_Options);

        $this->addSelect("123_is_happy_person", "123. He is a happy person", self::Default_Options);

        $this->addBasicText("124_how_many_times_per_day_did_they_use_tobacco", "124. <i>In the past 6 months,</i> about how many times per day did he use tobacco (including smokeless tobacco)?");

        $this->addBasicText("125_how_many_days_were_they_drunk", "125. <i>In the past 6 months,</i> on how many days was he drunk?");

        $this->addBasicText("126_how_many_days_use_drugs_for_nonmedical_purposes", "126. <i>In the past 6 months,</i> on how many days did he use drugs for nonmedical purposes (including marijuana, cocaine, and other drugs, except alcohol and nicotine)?");

        $this->addBasicText("VI_comments", "Additional Comments (optional):");

        $this->XINRegisterRule(
            "VI_comments",
            array("VI_comments{@}=={@}NEVER_REQUIRED"),
            "Not required."
        );
    }

    function abcl_special_rules($values)
    {
        $errors = array();
        //any page1 value is set
        if (isset($values['adult_age'])) {
            if (is_numeric($values['adult_age'])) {
                if (intval($values['adult_age']) > 100 || intval($values['adult_age']) < 0) {

                    $errors['adult_age'] = "Specify age between 0 and 100 or NA";
                }
            } else {
                if ($values['adult_age'] != 'NA') {
                    $errors['adult_age'] = "Specify age between 0 and 100 or NA";
                }
            }

            $blank_restricted_spouse_array = array(
                                              'a_gets_along_well_with_partner',
                                              'b_trouble_sharing_responsibilities',
                                              'c_seems_satisfied_with_spouse_or_partner',
                                              'd_enjoys_similar_activities_as_partner',
                                              'e_disagrees_with_partner_about_living_arrangements',
                                              'g_likes_friends_of_partner',
                                              'f_has_trouble_with_family_of_partner',
                                              'h_annoyed_by_behavior_of_spouse',
                                             );

            foreach ($blank_restricted_spouse_array as $value) {
                if (in_array($values['live_with_partner'], ['no', 'nk']) && $values[$value] != "") {
                    $errors[$value] = "This field should be left blank OR change the response in the above question of the applicable subset.";
                }
            }

            if ($values['marital_status_user'] != 'other' && $values['if_other_marital'] != "") {
                $errors['if_other_marital'] = "This field should be left blank OR change the response in the above question.";
            }

            if ($values['user_education'] != 'other' && $values['if_other_education'] != "") {
                $errors['if_other_education'] = "This field should be left blank OR change the response in the above question.";
            }

            if ($values['relationship_to_adult'] != 'other' && $values['if_other_relationship'] != "") {
                $errors['if_other_relationship'] = "This field should be left blank OR change the response in the above question.";
            }
        }

        //any page2 value is set
        if (isset($values['user_concerns'])) {
            $yes_restricted_array = array(
                                     'user_concerns',
                                     'user_handicap',
                                    );
            foreach ($yes_restricted_array as $val) {
                if ($values[$val] == 'no' && $values[$val . '_yes'] != "") {
                    $errors[$val . '_yes'] = "This field should be left blank OR change the response in the above question.";
                }
            }
        }

        //any page3 val is set
        if (isset($values['6_uses_drugs_for_nonmedical_purposes'])) {
            $blank_restricted_array_page3 = array(
                                             '6_uses_drugs_for_nonmedical_purposes',
                                             'user_handicap',
                                             '9_cant_get_mind_off_certain_thoughts',
                                             '29_fears_certain_animals_situations_places',
                                            );
            foreach ($blank_restricted_array_page3 as $val) {
                $question_description_split = explode("_", $val);
                $question_number            =$question_description_split[0];
                if ($values[$val] == '0' && $values[$question_number . '_continued'] != "") {
                    $errors[$question_number . '_continued'] = "This field should be left blank OR change the response in the above question.";
                }
            }
        }

        //any page4 val is set
        if (isset($values['40_hears_sounds_or_voices'])) {
            $blank_restricted_array_page4 = array(
                                             '40_hears_sounds_or_voices',
                                             '46_nervous_movements',
                                             'd_problems_witih_eyes',
                                             '58_picks_skin_or_other_parts_of_body',
                                            );
            foreach ($blank_restricted_array_page4 as $val) {
                $question_description_split = explode("_", $val);
                $question_number            =$question_description_split[0];
                if ($values[$val] == '0' && $values[$question_number . '_continued'] != "") {
                    $errors[$question_number . '_continued'] = "This field should be left blank OR change the response in the above question.";
                }
            }
        }

        //any page5 val is set
        if (isset($values['66_repeats_certain_acts'])) {
            $blank_restricted_array_page5 = array(
                                             '66_repeats_certain_acts',
                                             '70_sees_things_that_are_not_there',
                                             '77_sleeps_more_than_most_others',
                                             '79_speech_problem',
                                             '84_strange_behavior',
                                             '85_strange_ideas',
                                             '92_does_things_that_may_cause_trouble_with_law',
                                            );

            foreach ($blank_restricted_array_page5 as $val) {
                $question_description_split = explode("_", $val);
                $question_number            =$question_description_split[0];

                if ($values[$val] == '0' && $values[$question_number . '_continued'] != "") {
                    $errors[$question_number . '_continued'] = "This field should be left blank OR change the response in the above question.";
                }
            }
        }

        return $errors;
    }

    function sum012Responses($array, $record)
    {
        $sum = 0;

        foreach ($array as $a) {
            if ($record[$a] == "2") {
                $sum += 2;
            } elseif ($record[$a] == "1") {
                $sum += 1;
            } else {
                $sum += 0;
            }
        }

        return $sum;
    }

    function getAdaptiveTScore(string $age_range, string $scale, $score, $db)
    {
        $sex     = "male";
        $t_score = null;

        if ($age_range != "18-35" && $age_range != "36-59" && $age_range != "18-29") {
            return "Invalid Age Range";
        }

        $query = "SELECT
                      t_score
                  FROM
                      ASR_Adaptive_Functioning_Scales_lookup
                  WHERE
                      age_range = :age_range AND
                      sex = :sex AND
                      scale = :scale AND
                      score_min <= :score AND
                      score_max >= :score";

        $record = $db->pselectOne(
            $query,
            array(
             "age_range" => $age_range,
             "sex"       => $sex,
             "scale"     => $scale,
             "score"     => $score,
            )
        );

        if (is_null($record)) {
            return "No Record Found";
        }

        return $record;
    }

    function getSubstanceTScore(string $age_range, string $substance, $score, $db)
    {
        $sex     = "male";
        $t_score = null;

        $query = "SELECT
                      t_score
                  FROM
                      ASR_Substance_Use_Scales_lookup
                  WHERE
                      age_range = :age_range AND
                      sex = :sex AND
                      substance = :substance AND
                      score_min <= :score AND
                      score_max >= :score";

        $record = $db->pselectOne(
            $query,
            array(
             "age_range" => $age_range,
             "sex"       => $sex,
             "substance" => $substance,
             "score"     => $score,
            )
        );

        if (is_null($record)) {
            return "No Record Found";
        }

        return $record;
    }

    function getSyndromeTScore(string $age_range, string $scale, $score, $db)
    {
        $sex     = "male";
        $t_score = null;

        if ($age_range != "18-35" && $age_range != "36-59") {
            return "Invalid Age Range";
        }

        $query = "SELECT
                      t_score
                  FROM
                      ASR_Syndrome_Scales_lookup
                  WHERE
                      age_range = :age_range AND
                      sex = :sex AND
                      scale = :scale AND
                      score_min <= :score AND
                      score_max >= :score";

        $record = $db->pselectOne(
            $query,
            array(
             "age_range" => $age_range,
             "sex"       => $sex,
             "scale"     => $scale,
             "score"     => $score,
            )
        );

        if (is_null($record)) {
            return "No Record Found";
        }

        return $record;
    }

    function getOrientedTScore(string $age_range, string $scale, $score, $db)
    {
        $sex     = "male";
        $t_score = null;

        if ($age_range != "18-35" && $age_range != "36-59") {
            return "Invalid Age Range";
        }

        $query = "SELECT
                      t_score
                  FROM
                      ASR_DSM5_Oriented_Scales_lookup
                  WHERE
                      age_range = :age_range AND
                      sex = :sex AND
                      scale = :scale AND
                      score_min <= :score AND
                      score_max >= :score";

        $record = $db->pselectOne(
            $query,
            array(
             "age_range" => $age_range,
             "sex"       => $sex,
             "scale"     => $scale,
             "score"     => $score,
            )
        );

        if (is_null($record)) {
            return "No Record Found";
        }

        return $record;
    }

    function roundToNearestPoint5($num)
    {
        return round($num*2)/2;
    }

    function score(): void
    {
        if ($this->_determineDataEntryCompletionStatus() == "Incomplete") {
            return;
        }

        $this->_nullScores($this->scoreLabels);

        $db     = Database::singleton();
        $record = $db->pselectRow("SELECT * FROM $this->table WHERE CommentID=:cid", array("cid" => $this->getCommentID()));

        $age       = $record["adult_age"];
        $age_range = "";

        if (!is_null($age) || $age != "NA") {
            if ($age >= 18 && $age <= 35) {
                $age_range = "18-35";
            } elseif ($age >= 36 && $age <= 59) {
                $age_range = "36-59";
            } else {
                $age_range = "Out of range";
            }
        }

        $scores = array();

        /***** ASR AND ABCL ADAPTIVE FUNCTIONING SCALES *****/

        /********************
         * I. FRIENDS SCALE *
         ********************/

        $I_A = 0;
        $I_B = 0;
        $I_C = 0;
        $I_D = 0;

        if ($record["a_how_many_close_friends"] == "none" || $record["a_how_many_close_friends"] == "nk") {
            $I_A = 0;
        } elseif ($record["a_how_many_close_friends"] == "1") {
            $I_A = 1;
        } elseif ($record["a_how_many_close_friends"] == "2") {
            $I_A = 2;
        } elseif ($record["a_how_many_close_friends"] == "3") {
            $I_A = 3;
        }

        if ($record["b_contact_with_close_friends"] == "none" || $record["b_contact_with_close_friends"] == "nk") {
            $I_B = 0;
        } elseif ($record["b_contact_with_close_friends"] == "1") {
            $I_B = 1;
        } elseif ($record["b_contact_with_close_friends"] == "2") {
            $I_B = 2;
        } elseif ($record["b_contact_with_close_friends"] == "3") {
            $I_B = 3;
        }

        if ($record["c_how_well_do_they_get_along_with_friends"] == "not_well" || $record["c_how_well_do_they_get_along_with_friends"] == "nk") {
            $I_C = 0;
        } elseif ($record["c_how_well_do_they_get_along_with_friends"] == "average") {
            $I_C = 1;
        } elseif ($record["c_how_well_do_they_get_along_with_friends"] == "above_average") {
            $I_C = 2;
        } elseif ($record["c_how_well_do_they_get_along_with_friends"] == "far_above") {
            $I_C = 3;
        }

        if ($record["d_how_many_times_do_family_or_friends_visit"] == "0" || $record["d_how_many_times_do_family_or_friends_visit"] == "nk") {
            $I_D = 0;
        } elseif ($record["d_how_many_times_do_family_or_friends_visit"] == "1") {
            $I_D = 1;
        } elseif ($record["d_how_many_times_do_family_or_friends_visit"] == "2") {
            $I_D = 2;
        } elseif ($record["d_how_many_times_do_family_or_friends_visit"] == "3") {
            $I_D = 3;
        }

        $scores["i_friends_total_score"] = $I_A + $I_B + $I_C + $I_D;

        $scores["i_friends_t_score"] = $this->getAdaptiveTScore($age_range, "friends", $scores["i_friends_total_score"], $db);

        /****************************
         * II. SPOUSE/PARTNER SCALE *
         ****************************/

         // Do not score this scale unless the person being assessed lived
         // with spouse or partner in the last 6 months
         // and circled scores for each item II-A through II-H

         // II - A, C, D, G: Enter the 0, 1, 2 scores circled by the respondent
         // in the columns of spaces under the + (plus) heading for these items
         // II - B, E, F, H: Enter the 0, 1, 2 scores circled by the respondent
         // in the columns of spaces under the - (minus) heading for these items

         // Total score for Spouse/Partner scale:
         // 1. Sum the scores in the + (plus) column
         // 2. Sum the scores in the - (minus) column
         // 3. Subtract the sum of the - (minus) column from the sum of the + (plus)
         // column to obtain the total scale score
         // 4. Enter this total scale score in the box labeled Total
         // 5. Circle the corresponding number in the age-specific column above

        if ($record["live_with_partner"] == "yes") {
            $plus  = 0;
            $minus = 0;

            $plus_fields = array(
                            "a_gets_along_well_with_partner",
                            "c_seems_satisfied_with_spouse_or_partner",
                            "d_enjoys_similar_activities_as_partner",
                            "g_likes_friends_of_partner",
                           );

            $minus_fields = array(
                             "b_trouble_sharing_responsibilities",
                             "e_disagrees_with_partner_about_living_arrangements",
                             "f_has_trouble_with_family_of_partner",
                             "h_annoyed_by_behavior_of_spouse",
                            );

            $plus  = $this->sum012Responses($plus_fields, $record);
            $minus = $this->sum012Responses($minus_fields, $record);

            $scores["ii_spouse_partner_total_score"] = $plus - $minus;
            $scores["ii_spouse_partner_t_score"]     = $this->getAdaptiveTScore($age_range, "spouse_partner", $scores["ii_spouse_partner_total_score"], $db);
        } else {
            $scores["ii_spouse_partner_total_score"] = "Not Scored";
            $scores["ii_spouse_partner_t_score"]     = "N/A";
        }

        /*****************************
         * MEAN ADAPTIVE FUNCTIONING *
         *****************************/

        // Mean of the adaptive functioning scales:
        // - Friends
        // - Spouse/Partner (Can be not scored)
        // - Family [MISSING]
        // - Job [MISSING]
        // - Education [MISSING]

        // Only compute mean of all all adaptive functioning scales
        // if each scale was scored

        if (is_numeric($scores["i_friends_total_score"])
            && is_numeric($scores["ii_spouse_partner_total_score"])
        ) {
            $mean = 0;

            $adaptive_functioning_sum =
            $scores["i_friends_total_score"] +
            $scores["ii_spouse_partner_total_score"];

            $mean = $adaptive_functioning_sum / 2;
            $mean = round($mean, 1);

            $scores["mean_adaptive_score"]   = $mean;
            $scores["mean_adaptive_t_score"] = $this->getAdaptiveTScore($age_range, "mean_adaptive", $scores["mean_adaptive_score"], $db);
        } else {
            $scores["mean_adaptive_score"]   = "Not Scored";
            $scores["mean_adaptive_t_score"] = "N/A";
        }

        /***** SUBSTANCE USE SCALES *****/

        $substances = array(
                       "tobacco" => $record["124_how_many_times_per_day_did_they_use_tobacco"],
                       "alcohol" => $record["125_how_many_days_were_they_drunk"],
                       "drugs"   => $record["126_how_many_days_use_drugs_for_nonmedical_purposes"],
                      );

        $can_compute_mean_substance_use = true;

        foreach ($substances as $name => $response) {
            if (is_null($response)) {
                $scores[$name . "_t_score"]     = "Missing field";
                $can_compute_mean_substance_use = false;
            }
            if (ctype_digit($response)) {
                if ($age_range == "18-35" || $age_range == "36-59") {
                    $t_score = $this->getSubstanceTScore($age_range, $name, intval($response), $db);
                    $scores[$name . "_t_score"] = $t_score;
                } else {
                    $scores[$name . "_t_score"] = "Age out of bounds";
                }
            } else {
                $scores[$name . "_t_score"]     = "Invalid Input";
                $can_compute_mean_substance_use = false;
            }
        }

        if ($can_compute_mean_substance_use) {
            $sum  = $scores["tobacco_t_score"] + $scores["alcohol_t_score"] + $scores["drugs_t_score"];
            $mean = $this->roundToNearestPoint5($sum/3);
            $scores["mean_substance_use_score"] = $mean;

            $t_score = $this->getSubstanceTScore($age_range, "mean_substance_use", $mean, $db);
            $scores["mean_substance_use_t_score"] = $t_score;
        } else {
            $scores["mean_substance_use_t_score"] = "Missing field(s)";
        }

        /***** CRITICAL ITEMS *****/

        $scores["critical_items_score"]   = $this->sum012Responses(self::CRITICAL_ITEMS, $record);
        $scores["critical_items_t_score"] = $this->getSubstanceTScore($age_range, "critical_items", $scores["critical_items_score"], $db);;

        /***** SYNDROME SCALE *****/

        $syndrome_scales = array(
                            "i_anxious_depressed"        => self::I_ANXIOUS_DEPRESSED,
                            "ii_withdrawn"               => self::II_WITHDRAWN,
                            "iii_somatic_complaints"     => self::III_SOMATIC_COMPLAINTS,
                            "iv_thought_problems"        => self::IV_THOUGHT_PROBLEMS,
                            "v_attention_problems"       => self::V_ATTENTION_PROBLEMS,
                            "vi_aggressive_behavior"     => self::VI_AGGRESSIVE_BEHAVIOR,
                            "vii_rule_breaking_behavior" => self::VII_RULE_BREAKING_BEHAVIOR,
                            "viii_intrusive"             => self::VIII_INTRUSIVE,
                           );

        foreach ($syndrome_scales as $scale => $array) {
            $scores[$scale . "_score"]   = $this->sum012Responses($array, $record);
            $scores[$scale . "_t_score"] = $this->getSyndromeTScore($age_range, $scale, $scores[$scale . "_score"], $db);
        }

        $scores["other_problems_score"] = $this->sum012Responses(self::OTHER_PROBLEMS, $record);

        /***** DSM-ORIENTED SCALE *****/

         $oriented_scales = array(
                             "1_depressive_problems"             => self::_1_DEPRESSIVE_PROBLEMS,
                             "2_anxiety_problems"                => self::_2_ANXIETY_PROBLEMS,
                             "3_somatic_problems"                => self::_3_SOMATIC_PROBLEMS,
                             "4_avoidant_personality_problems"   => self::_4_AVOIDANT_PERSONALITY_PROBLEMS,
                             "5_adh_problems"                    => self::_5_ADH_PROBLEMS,
                             "6_antisocial_personality_problems" => self::_6_ANTISOCIAL_PERSONALITY_PROBLEMS,
                            );

        foreach ($oriented_scales as $scale => $array) {
            $scores[$scale . "_score"]   = $this->sum012Responses($array, $record);
            $scores[$scale . "_t_score"] = $this->getOrientedTScore($age_range, $scale, $scores[$scale . "_score"], $db);
        }

        $db->update($this->table, $scores, array("CommentID" => $this->getCommentID()));
    }

    CONST CRITICAL_ITEMS = [
                            "14_cries_a_lot",
                            "91_talks_about_killing_self",
                            "103_unhappy_sad_depressed",
                            "9_cant_get_mind_off_certain_thoughts",
                            "18_deliberately_harms_self",
                            "40_hears_sounds_or_voices",
                            "66_repeats_certain_acts",
                            "70_sees_things_that_are_not_there",
                            "84_strange_behavior",
                            "8_cant_concentrate_or_pay_attention",
                            "16_cruelty_bullying_meanness",
                            "55_moods_swing_between_elation_and_depression",
                            "57_physically_attacks_people",
                            "97_threatens_to_hurt_people",
                            "6_uses_drugs_for_nonmedical_purposes",
                            "90_drinks_too_much_alcohol",
                            "92_does_things_that_may_cause_trouble_with_law",
                            "10_cant_sit_still",
                            "21_damages_things_belonging_to_others",
                           ];

    CONST I_ANXIOUS_DEPRESSED = [
                                 "12_complains_of_loneliness",
                                 "13_confused_or_in_a_fog",
                                 "14_cries_a_lot",
                                 "22_worries_about_their_future",
                                 "31_fears_they_might_think_or_do_something_bad",
                                 "33_feels_or_complains_that_no_one_loves_them",
                                 "34_feels_others_are_out_to_get_them",
                                 "35_feels_worthless_or_inferior",
                                 "45_nervous_highstrung_tense",
                                 "47_lacks_self_confidence",
                                 "50_too_fearful_or_anxious",
                                 "52_feels_too_guilty",
                                 "71_self_conscious_or_easily_embarrassed",
                                 "91_talks_about_killing_self",
                                 "103_unhappy_sad_depressed",
                                 "107_feels_they_cant_succeed",
                                 "112_worries",
                                 "113_sulks_a_lot",
                                ];

    CONST II_WITHDRAWN = [
                          "25_does_not_get_along_with_others",
                          "30_poor_relations_with_opposite_sex",
                          "42_would_rather_be_alone",
                          "48_not_liked_by_others",
                          "60_enjoys_very_little",
                          "65_refuses_to_talk",
                          "67_has_trouble_making_or_keeping_friends",
                          "69_keeps_things_to_self",
                          "111_withdrawn_not_involved_with_others",
                         ];

    CONST III_SOMATIC_COMPLAINTS = [
                                    "51_feels_dizzy_or_lightheaded",
                                    "54_trouble_planning_for_future",
                                    "a_aches_or_pains",
                                    "b_headaches",
                                    "c_nausea",
                                    "d_problems_witih_eyes",
                                    "e_skin_problems",
                                    "f_stomachaches",
                                    "g_vomiting",
                                    "100_trouble_sleeping",
                                   ];

    CONST IV_THOUGHT_PROBLEMS = [
                                 "9_cant_get_mind_off_certain_thoughts",
                                 "18_deliberately_harms_self",
                                 "36_gets_hurt_a_lot",
                                 "40_hears_sounds_or_voices",
                                 "46_nervous_movements",
                                 "63_would_rather_be_with_older_people",
                                 "66_repeats_certain_acts",
                                 "70_sees_things_that_are_not_there",
                                 "84_strange_behavior",
                                 "85_strange_ideas",
                                ];

    CONST V_ATTENTION_PROBLEMS = [
                                  "1_is_too_forgetful",
                                  "8_cant_concentrate_or_pay_attention",
                                  "11_too_dependent_on_others",
                                  "17_daydreams_or_gets_lost_in_thoughts",
                                  "53_trouble_planning_for_future",
                                  "59_fails_to_finish_things_they_should_do",
                                  "61_poor_work_performance",
                                  "64_has_trouble_setting_priorities",
                                  "78_has_trouble_making_decisions",
                                  "101_stays_away_from_job_even_when_not_sick_or_on_vacation",
                                  "102_underactive_slow_moving_lacks_energy",
                                  "105_disorganized",
                                  "108_tends_to_lose_things",
                                  "119_not_good_at_details",
                                  "121_tends_to_be_late_for_appointments",
                                 ];

    CONST VI_AGGRESSIVE_BEHAVIOR = [
                                    "3_argues_a_lot",
                                    "5_blames_others_for_own_problems",
                                    "16_cruelty_bullying_meanness",
                                    "28_gets_along_badly_with_family",
                                    "37_gets_in_many_fights",
                                    "55_moods_swing_between_elation_and_depression",
                                    "57_physically_attacks_people",
                                    "68_screams_or_yells_a_lot",
                                    "81_very_changeable_behaavior",
                                    "86_stubborn_sullen_irritable",
                                    "87_sudden_changes_in_mood_or_feelings",
                                    "95_temper_tantrums",
                                    "97_threatens_to_hurt_people",
                                    "116_gets_upset_too_easily",
                                    "118_too_impatient",
                                   ];

    CONST VII_RULE_BREAKING_BEHAVIOR = [
                                        "6_uses_drugs_for_nonmedical_purposes",
                                        "20_damages_own_things",
                                        "23_breaks_rules",
                                        "26_does_not_feel_guilty_after_misbehaving",
                                        "39_hangs_around_people_who_get_in_trouble",
                                        "41_acts_without_thinking",
                                        "43_lying_or_cheating",
                                        "76_irresponsible_behavior",
                                        "82_steals",
                                        "90_drinks_too_much_alcohol",
                                        "92_does_things_that_may_cause_trouble_with_law",
                                        "114_fails_to_pay_debts_or_meet_financial_responsibilities",
                                        "117_trouble_managing_money_or_credit_cards",
                                        "122_trouble_keeping_job",
                                       ];

    CONST VIII_INTRUSIVE = [
                            "7_bragging_boasting",
                            "19_demands_attention",
                            "74_showing_off",
                            "93_walks_too_much",
                            "94_teases_a_lot",
                            "104_unusually_loud",
                           ];

    CONST OTHER_PROBLEMS = [
                            "10_cant_sit_still",
                            "21_damages_things_belonging_to_others",
                            "24_does_not_eat_well",
                            "27_easily_jealous",
                            "29_fears_certain_animals_situations_places",
                            "32_feels_they_have_to_be_perfect",
                            "38_poor_relations_with_neighbors",
                            "44_feels_overwhelmed_by_responsibilities",
                            "58_picks_skin_or_other_parts_of_body",
                            "62_poorly_coordinated",
                            "72_worries_about_their_family",
                            "75_too_shy_or_timid",
                            "77_sleeps_more_than_most_others",
                            "79_speech_problem",
                            "83_easily_bored",
                            "89_rushes_into_things_without_considering_risks",
                            "96_passive_or_lacks_initiative",
                            "99_dislikes_staying_in_one_place_for_long",
                            "110_makes_good_decisions",
                            "115_restless_or_fidgety",
                            "120_drives_too_fast",
                           ];

    CONST _1_DEPRESSIVE_PROBLEMS = [
                                    "14_cries_a_lot",
                                    "18_deliberately_harms_self",
                                    "24_does_not_eat_well",
                                    "35_feels_worthless_or_inferior",
                                    "52_feels_too_guilty",
                                    "54_trouble_planning_for_future",
                                    "60_enjoys_very_little",
                                    "77_sleeps_more_than_most_others",
                                    "78_has_trouble_making_decisions",
                                    "91_talks_about_killing_self",
                                    "100_trouble_sleeping",
                                    "102_underactive_slow_moving_lacks_energy",
                                    "103_unhappy_sad_depressed",
                                    "107_feels_they_cant_succeed",
                                   ];

    CONST _2_ANXIETY_PROBLEMS = [
                                 "22_worries_about_their_future",
                                 "29_fears_certain_animals_situations_places",
                                 "45_nervous_highstrung_tense",
                                 "50_too_fearful_or_anxious",
                                 "72_worries_about_their_family",
                                 "112_worries",
                                ];

    CONST _3_SOMATIC_PROBLEMS = [
                                 "a_aches_or_pains",
                                 "b_headaches",
                                 "c_nausea",
                                 "d_problems_witih_eyes",
                                 "e_skin_problems",
                                 "f_stomachaches",
                                 "g_vomiting",
                                ];

    CONST _4_AVOIDANT_PERSONALITY_PROBLEMS = [
                                              "25_does_not_get_along_with_others",
                                              "42_would_rather_be_alone",
                                              "47_lacks_self_confidence",
                                              "67_has_trouble_making_or_keeping_friends",
                                              "71_self_conscious_or_easily_embarrassed",
                                              "75_too_shy_or_timid",
                                              "111_withdrawn_not_involved_with_others",
                                             ];

    CONST _5_ADH_PROBLEMS = [
                             "1_is_too_forgetful",
                             "8_cant_concentrate_or_pay_attention",
                             "10_cant_sit_still",
                             "36_gets_hurt_a_lot",
                             "41_acts_without_thinking",
                             "59_fails_to_finish_things_they_should_do",
                             "61_poor_work_performance",
                             "89_rushes_into_things_without_considering_risks",
                             "105_disorganized",
                             "108_tends_to_lose_things",
                             "115_restless_or_fidgety",
                             "118_too_impatient",
                             "119_not_good_at_details",
                            ];

    CONST _6_ANTISOCIAL_PERSONALITY_PROBLEMS = [
                                                "3_argues_a_lot",
                                                "5_blames_others_for_own_problems",
                                                "16_cruelty_bullying_meanness",
                                                "21_damages_things_belonging_to_others",
                                                "23_breaks_rules",
                                                "26_does_not_feel_guilty_after_misbehaving",
                                                "28_gets_along_badly_with_family",
                                                "37_gets_in_many_fights",
                                                "39_hangs_around_people_who_get_in_trouble",
                                                "43_lying_or_cheating",
                                                "57_physically_attacks_people",
                                                "76_irresponsible_behavior",
                                                "82_steals",
                                                "92_does_things_that_may_cause_trouble_with_law",
                                                "95_temper_tantrums",
                                                "97_threatens_to_hurt_people",
                                                "101_stays_away_from_job_even_when_not_sick_or_on_vacation",
                                                "114_fails_to_pay_debts_or_meet_financial_responsibilities",
                                                "120_drives_too_fast",
                                                "122_trouble_keeping_job",
					];

  function validate_main_page($values)
  {
              $errors = [];

   if ($values["relationship_to_child"] == "father") {
   $errors["relationship_to_child"] = "This survey should be filled out ABOUT the child’s biological father by someone else. If you are the child’s biological father, please do not fill out this survey.";
   }

  return $errors;
}
}
