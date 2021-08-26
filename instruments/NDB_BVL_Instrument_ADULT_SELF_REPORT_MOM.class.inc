<?php
/**
 * This file contains the NDB_BVL_Instrument_ADULT_SELF_REPORT
 * class
 *
 * PHP Version 5
 *
 * @category Instrument
 * @package  Neuropsych
 * @author   Leo Thomas <lthomas.mcin@gmail.com>
 * @license  http://www.gnu.org/licenses/gpl-3.0.txt GPLv3
 * @link     https://www.github.com/aces/
 */
/**
 * Creates the form elements for the ADULT_SELF_REPORT instrument (MOM)
 *
 * @category Instrument
 * @package  Neuropsych
 * @author   Leo Thomas <lthomas.mcin@gmail.com>
 * @license  http://www.gnu.org/licenses/gpl-3.0.txt GPLv_
 * @link     https://www.github.com/aces/
 */
class NDB_BVL_Instrument_ADULT_SELF_REPORT_MOM extends NDB_BVL_Instrument
{
    use LegacyInstrumentTrait;

    var $ValidityEnabled  = false;
    var $ValidityRequired = false;

    var $scoreLabels = array(
                        "i_friends_total_score",
                        "i_friends_t_score",
                        "ii_spouse_partner_total_score",
                        "ii_spouse_partner_t_score",
                        "iii_family_mean_score",
                        "iii_family_t_score",
                        "iv_job_total_score",
                        "iv_job_t_score",
                        "v_education_total_score",
                        "v_education_t_score",
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
        $this->formType = 'XIN';
        $this->form     = new LorisForm('ADULT_SELF_REPORT_MOM_form');
        $this->page     = $page;

        // set the object properties
        $this->testName = 'ADULT_SELF_REPORT_MOM'; // test_names.Test_name
        $this->table    = 'ADULT_SELF_REPORT_MOM'; // name of database
        // table corresponding to instrument
        $this->commentID = $commentID; // data keyed by commentID

        //The array of dates/timestamps to convert to database dates/timestamps
        //Any LorisForm date elements must be listed here
        $this->dateTimeFields = array("Date_taken");

        //The array of selects with multiple answers allowed
        //Any LorisForm multiple selects must be listed here
        $this->_selectMultipleElements = array();

        // required fields for data entry completion status
        $this->_requiredElements = array('CommentID');

        $config            = NDB_Config::singleton();
        $this->dateOptions = array(
                              'language'         => 'en',
                              'format'           => 'YMd',
                              'minYear'          => $config->getSetting('startYear'),
                              'maxYear'          => $config->getSetting('endYear'),
                              'addEmptyOption'   => true,
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
            "/ADULT_SELF_REPORT_MOM(_page[0-9]+)/",
            $this->page,
            $matches
        )
        ) {
            call_user_func(array($this, $matches[1]));
        } else {
            $this->_main();
        }

        $this->form->addFormRule(array(&$this, 'XINValidate'));
        $this->form->addFormRule(array(&$this, 'asrSpecialRules'));
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
        $this->addHeader("Adult Self Report Ages 18-59 aka Adult Self CBCL (MOM)");

        //survey instrument don't need this
        // $this->_addMetadataFields();
        $this->addBasicDate('Date_taken', 'Date of Administration', $this->dateOptions);

        $label = "Please click this bubble 'Yes' to confirm that you are the enrolled child’s biological mother, reporting on yourself.";

        $this->form->addElement(
            'select',
            'respondent',
            $label,
            array(
             null       => '',
	     'yes'      => 'Yes'
            )
        );

        $opts = array(
                 null     => "",
                 "female" => "Female",
                 "other"  => "Other",
                );
        $this->addSelect("user_gender", "Your sex: ", $opts);

        $this->addBasicText("user_age", "Your age:<br><h5><i>(Please enter a numeric value between 0-100 or if you really don't wish to answer; enter NA)</i></h5>");

        $this->addBasicText("user_ethnic_group", "Your ethnic group or race:<br><h5><i>(If you really don't wish to answer enter NA)</i></h5>");

        $this->addDateElement(
            "user_birthdate",
            "Your birthdate:",
            array(
             'language'         => 'en',
             'format'           => 'YMd',
             'minYear'          => date('Y')-120,
             'maxYear'          => date('Y'),
             'addEmptyOption'   => true,
             'emptyOptionValue' => null,
            )
        );

        $this->addLabel("Please fill out this form to reflect <i><b>your</b></i> views, even if other people might not agree. You need not spend a lot of time on any item. Feel free to print additional comments (optional). <b><i>Be sure to answer all items</i></b>");

        $this->addLabel("<b>YOUR USUAL TYPE OF WORK, even if not working now.</b> Please be specific -- for example, auto mechanic; high school teacher; homemaker; laborer; lathe operator; shoe salesman; army sergeant; student(indicate what you are studying & what degree you expect)");

        $this->addBasicText("user_work", "Your work:<br><h5><i>(If you don't wish to answer enter NA)</i></h5>");
        $this->addBasicText("spouse_work", "Spouse or partner's work:<br><h5><i>(If you don't wish to answer enter NA)</i></h5>");
        $this->XINRegisterRule(
            "spouse_work",
            array("spouse_work{@}=={@}NEVER_REQUIRED")
        );
        $opts = array(
                 null    => "",
                 "1"     => "1. No high school diploma and no GED",
                 "2"     => "2. General Equivalency Diploma (GED)",
                 "3"     => "3. High school graduate",
                 "4"     => "4. Some college but no college degree",
                 "5"     => "5. Associate's Degree",
                 "6"     => "6. Bachelor's or RN Degree",
                 "7"     => "7. Some graduate school but no graduate degree",
                 "8"     => "8. Master's Degree",
                 "9"     => "9. Doctoral or Law Degree",
                 "other" => "Other Education (specify)",
                );

        $this->addSelect("user_education", "<b>PLEASE SELECT YOUR HIGHEST EDUCATION</b>", $opts);

        $this->addBasicText("if_other_education", "$this->indent If other, please specify:<br><h5><i>$this->indent$this->indent(If you don't wish to answer enter NA)</i></h5>");

        $this->XINRegisterRule(
            "if_other_education",
            array("user_education{@}=={@}other"),
            "Required",
            "if_other_education"
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
                    "iii_family"                        => "III. Family",
                    "iv_job"                            => "IV. Job",
                    "v_education"                       => "V. Education",
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
    }

    /**
     * Page 1
     *
     * @return void
     */
    function _page1()
    {
        // Header
        $this->addHeader("Adult Self Report Ages 18-59 aka Adult Self CBCL (MOM)");

        $this->addLabel("<h1><b>I. FRIENDS </b></h1>");
        $opts = array(
                 null   => "",
                 "none" => "None",
                 "1"    => "1",
                 "2"    => "2 or 3",
                 "4"    => "4 or more",
                );

        $this->addSelect("1_A", "A. About how many close friends do you have? (Do not include family members)", $opts);

        $opts2 = array(
                  null   => "",
                  "less" => "Less than 1",
                  "1"    => "1 or 2",
                  "3"    => "3 or 4",
                  "more" => "5 or more",
                 );

        $this->addSelect("1_B", "B. About how many times a month do you have contact with any of your friends? (Include in-person contacts, phone, letters, e-mail.)", $opts2);

        $opts = array(
                 null      => "",
                 "not"     => "Not as well as I'd like",
                 "average" => "Average",
                 "above"   => "Above average",
                 "far"     => "Far above average",
                );

        $this->addSelect("1_C", "C. How well do you get along with your close friends?", $opts);

        $this->addSelect("1_D", "D. About how many times a month do any friends or family visit you?", $opts2);

        $this->addBasicTextArea("I_comments", "Additional comments (optional): ");
        $this->XINRegisterRule(
            "I_comments",
            array("I_comments{@}=={@}NEVER_REQUIRED")
        );

        $this->addLabel("<h1><b>II. SPOUSE OR PARTNER </b></h1>");

        $opts = array(
                 null                => "",
                 "never"             => "Never been married",
                 "married_separated" => "Married but separated from spouse",
                 "married_together"  => "Married, living with spouse",
                 "divorced"          => "Divorced",
                 "widowed"           => "Widowed",
                 "other"             => "Other",
                );

        $this->addSelect("marital_state", "What is your marital status?", $opts);
        $this->addBasicText("if_other_marital", "$this->indent If other -- please describe:<br><h5><i>$this->indent$this->indent(If you don't wish to answer enter NA)</i></h5>");

        $this->XINRegisterRule(
            "if_other_marital",
            array("marital_state{@}=={@}other"),
            "Required",
            "if_other_marital"
        );
        $opts = array(
                 null  => "",
                 "no"  => "<b>No -- please skip to page 2 </b>",
                 "yes" => "<b>Yes </b> -- Answer items A-H to describe your relationship
  <b><i>during the past 6 months </i><b>",
                );

        $this->addSelect(
            "live_with_spouse",
            "<b><i>At any time in the past 6 months,</i></b> did you live with your
spouse or with a partner? ",
            $opts
        );

        $opts = array(
                 null            => "",
                 "not_true"      => "Not True",
                 "somewhat_true" => "Somewhat or Sometimes true",
                 "very_true"     => "Very True or Often True",
                );

        $this->addSelect("spouse_A", "A. I get along well with my spouse or partner", $opts);
        $this->XINRegisterRule(
            "spouse_A",
            array("live_with_spouse{@}=={@}yes"),
            "Required"
        );

        $this->addSelect("spouse_B", "B. My spouse or partner and I have trouble sharing responsibilites", $opts);
        $this->XINRegisterRule(
            "spouse_B",
            array("live_with_spouse{@}=={@}yes"),
            "Required"
        );

        $this->addSelect("spouse_C", "C. I feel satisfied with my spouse or partner", $opts);
        $this->XINRegisterRule(
            "spouse_C",
            array("live_with_spouse{@}=={@}yes"),
            "Required"
        );

        $this->addSelect("spouse_D", "D. My spouse or partner and I enjoy similar activities", $opts);
        $this->XINRegisterRule(
            "spouse_D",
            array("live_with_spouse{@}=={@}yes"),
            "Required"
        );
        $this->addSelect(
            "spouse_E",
            "E. My spouse or partner and I <i>disagree</i> about living arrangements,
such as where we live",
            $opts
        );
        $this->XINRegisterRule(
            "spouse_E",
            array("live_with_spouse{@}=={@}yes"),
            "Required"
        );
        $this->addSelect("spouse_F", "F. I have trouble with my spouse or partner's family", $opts);
        $this->XINRegisterRule(
            "spouse_F",
            array("live_with_spouse{@}=={@}yes"),
            "Required"
        );
        $this->addSelect("spouse_G", "G. I like my spouse or partner's friends", $opts);
        $this->XINRegisterRule(
            "spouse_G",
            array("live_with_spouse{@}=={@}yes"),
            "Required"
        );
        $this->addSelect("spouse_H", "H. My spouse or partner's behavior annoys me", $opts);
        $this->XINRegisterRule(
            "spouse_H",
            array("live_with_spouse{@}=={@}yes"),
            "Required"
        );

        $this->addBasicTextArea("II_comments", "Additional Comments (optional): ");
        $this->XINRegisterRule(
            "II_comments",
            array("II_comments{@}=={@}NEVER_REQUIRED")
        );
    }

    /**
     * Page 2
     *
     * @return void
     */
    function _page2()
    {
        $this->addLabel("<h1>III. Family</h1>");
        $this->addLabel("<h3>Compared to others, how well do you: </h3>");

        $opts = array(
                 null         => "",
                 "worse"      => "Worse than Average",
                 "variable"   => "Variable or Average",
                 "better"     => "Better than Average",
                 "no_contact" => "No contact",
                );

        $opts_temp = $opts;
        $opts_temp["no_brothers"] = " I have no brothers";

        $this->addSelect("family_A", "A. Get along with your brothers?", $opts_temp);

        $opts_temp = $opts;
        $opts_temp["no_sisters"] = " I have no sisters";

        $this->addSelect("family_B", "B. Get along with your sisters?", $opts_temp);

        $opts_temp = $opts;
        $opts_temp["mother_deceased"] = "Mother is deceased";

        $this->addSelect("family_C", "C. Get along with your mother?", $opts_temp);

        $opts_temp = $opts;
        $opts_temp["father_deceased"] = "Father is deceased";

        $this->addSelect("family_D", "D. Get along with your father?", $opts_temp);

        $opts_temp = array(
                      null          => "",
                      "no_children" => "I have no children",
                     );

        $this->addSelect("Family_E", "E. Get along with your biological <br> or adopted children? ", $opts_temp);

        $this->XINRegisterRule(
            "Family_E",
            array("Family_E{@}=={@}NEVER_REQUIRED")
        );

        $opts_temp = $opts;
        $opts_temp["not_applicable"] ="Not applicable";

        $this->addSelect("Family_E_1", "$this->indent 1. Oldest child", $opts_temp);
        $this->XINRegisterRule(
            "Family_E_1",
            array("Family_E{@}!={@}no_children"),
            'Required'
        );
        $this->addSelect("Family_E_2", "$this->indent 2. 2nd oldest child", $opts_temp);
        $this->XINRegisterRule(
            "Family_E_2",
            array("Family_E{@}!={@}no_children"),
            'Required'
        );
        $this->addSelect("Family_E_3", "$this->indent 3. 3rd oldest child", $opts_temp);
        $this->XINRegisterRule(
            "Family_E_3",
            array("Family_E{@}!={@}no_children"),
            'Required'
        );
        $this->addSelect("Family_E_4", "$this->indent 4. Other children", $opts_temp);
        $this->XINRegisterRule(
            "Family_E_4",
            array("Family_E{@}!={@}no_children"),
            'Required'
        );
        $opts_temp = $opts;
        $opts_temp["no_stepchildren"] = "I have no step children";

        $this->addSelect("Family_F", "F. Get along with your stepchildren", $opts_temp);
        $this->addBasicTextArea("III_comments", "Additional Comments (optional): ");
        $this->XINRegisterRule(
            "III_comments",
            array("III_comments{@}=={@}NEVER_REQUIRED")
        );

        $this->addLabel("<h1>IV. Job</h1>");
        $opts = array(
                 null  => "",
                 "no"  => "<b>No -- please skip to section V.</b>",
                 "yes" => "<b>Yes -- please describe your job(s)</b>",
                );
        $this->addSelect("jobs", "<b><i> At any time in the past 6 months,</i></b> did you have any paid jobs (including self-employment and military service)? ", $opts);
        $this->addBasicTextArea("job_desc", "Description of your job(s):<br><h5><i>(Required if you answered 'Yes' to the above. If you don't wish to answer enter NA)</i></h5>");
        $this->XINRegisterRule(
            "job_desc",
            array("jobs{@}=={@}yes"),
            "Required",
            "job_desc"
        );
        $opts = array(
                 null        => "",
                 "not_true"  => "Not True",
                 "sometimes" => "Somewhat or Sometimes True",
                 "very_true" => "Very True or Often True",
                );
        $this->addSelect("Job_A", "A. I work well with others", $opts);
        $this->XINRegisterRule(
            "Job_A",
            array("jobs{@}=={@}yes"),
            "Required"
        );
        $this->addSelect("Job_B", "B. I have trouble getting along with bosses", $opts);
        $this->XINRegisterRule(
            "Job_B",
            array("jobs{@}=={@}yes"),
            "Required"
        );
        $this->addSelect("Job_C", "C. I do my work well", $opts);
        $this->XINRegisterRule(
            "Job_C",
            array("jobs{@}=={@}yes"),
            "Required"
        );
        $this->addSelect("Job_D", "D. I have trouble finishing my work", $opts);
        $this->XINRegisterRule(
            "Job_D",
            array("jobs{@}=={@}yes"),
            "Required"
        );
        $this->addSelect("Job_E", "E. I am satisfied with my work situation", $opts);
        $this->XINRegisterRule(
            "Job_E",
            array("jobs{@}=={@}yes"),
            "Required"
        );
        $this->addSelect("Job_F", "F. I do things that may cause me to lose my job", $opts);
        $this->XINRegisterRule(
            "Job_F",
            array("jobs{@}=={@}yes"),
            "Required"
        );
        $this->addSelect("Job_G", "G. I stay away from my job even when I'm not sick or on vacation", $opts);
        $this->XINRegisterRule(
            "Job_G",
            array("jobs{@}=={@}yes"),
            "Required"
        );
        $this->addSelect("Job_H", "H. My job is too stressful for me", $opts);
        $this->XINRegisterRule(
            "Job_H",
            array("jobs{@}=={@}yes"),
            "Required"
        );
        $this->addSelect("Job_I", "I. I worry too much about work", $opts);
        $this->XINRegisterRule(
            "Job_I",
            array("jobs{@}=={@}yes"),
            "Required"
        );

        $this->addBasicTextArea("IV_comments", "Additional Comments (optional):");
        $this->XINRegisterRule(
            "IV_comments",
            array("IV_comments{@}=={@}NEVER_REQUIRED")
        );

        $this->addLabel("<h1>V. Education:</h1>");
        $opts = array(
                 null  => "",
                 "no"  => "<b>No -- please skip to Section VI</b>",
                 "yes" => "<b>Yes</b> -- Please answer the following items:",
                );

        $this->addSelect("education", "<b><i>At any time in the past 6 months,</i><b> did you attend school, college, or any other education or training program?", $opts);

        $this->addBasicText("kind_of_program", "What kind of school or program?<br><h5><i>(If you don't wish to answer enter NA)</i></h5>");
        $this->XINRegisterRule(
            "kind_of_program",
            array("education{@}=={@}yes"),
            "Required",
            "kind_of_program"
        );
        $this->addBasicText("degree_seeking", "What degree or diploma are you seeking?<br><h5><i>(if you don't wish to answer enter NA)</i></h5>");
        $this->XINRegisterRule(
            "degree_seeking",
            array("education{@}=={@}yes"),
            "Required",
            "degree_seeking"
        );
        $this->addBasicText("major", "Major?<br><h5><i>(If you don't wish to answer enter NA)</i></h5>");
        $this->XINRegisterRule(
            "major",
            array("education{@}=={@}yes"),
            "Required",
            "major"
        );
        $this->addBasicText("expected_grad", "When do you expect to receive your degree or diploma?<br><h5><i>(If you don't wish to answer enter NA)</i></h5>");
        $this->XINRegisterRule(
            "expected_grad",
            array("education{@}=={@}yes"),
            "Required",
            "expected_grad"
        );

        $opts = array(
                 null        => "",
                 "not_true"  => "Not True",
                 "sometime"  => "Somewhat or Sometimes True",
                 "very_true" => "Very True or Often True",
                );

        $this->addSelect("education_A", "A. I get along well with other students", $opts);
        $this->XINRegisterRule(
            "education_A",
            array("education{@}=={@}yes"),
            "Required"
        );
        $this->addSelect("education_B", "B. I achieve what I am capable of", $opts);
        $this->XINRegisterRule(
            "education_B",
            array("education{@}=={@}yes"),
            "Required"
        );
        $this->addSelect("education_C", "C. I have trouble finishing assignments", $opts);
        $this->XINRegisterRule(
            "education_C",
            array("education{@}=={@}yes"),
            "Required"
        );
        $this->addSelect("education_D", "D. I am satisfied with my educational situation", $opts);
        $this->XINRegisterRule(
            "education_D",
            array("education{@}=={@}yes"),
            "Required"
        );
        $this->addSelect("education_E", "E. I do things that may cause me to fail", $opts);
        $this->XINRegisterRule(
            "education_E",
            array("education{@}=={@}yes"),
            "Required"
        );
        $this->addBasicTextArea("V_comments", "Additional Comments (optional): ");
        $this->XINRegisterRule(
            "V_comments",
            array("V_comments{@}=={@}NEVER_REQUIRED")
        );
    }

    /**
     * Page 3
     *
     * @return void
     */
    function _page3()
    {
        $this->addSelect("illness", "<b>VI. Do you have any illness, disability or handicap? </b>", array(null => "", "no" => "No", "yes" => "Yes"));
        $this->addBasicTextArea("illness_description", "If yes, please describe:<br><h5><i>(If you don't wish to answer enter NA)</i></h5>");
        $this->XINRegisterRule(
            "illness_description",
            array("illness{@}=={@}yes"),
            "Required",
            "illness_description"
        );

        $this->addSelect("concerns", "<b>VII. Do you have concerns or worries about family, education, or other things?</b>", array(null => "", "no" => "No concerns", "yes" => "Yes -- Please describe"));

        $this->addBasicTextArea("concern_description", "If yes, please describe:<br><h5><i>(If you don't wish to answer enter NA)</i></h5>");

        $this->XINRegisterRule(
            "concern_description",
            array("concerns{@}=={@}yes"),
            "Required",
            "concern_description"
        );
        $this->addBasicTextArea("self_description", "<b>VII.Please describe the best things about yourself");
        $this->XINRegisterRule(
            "self_description",
            array("self_description{@}=={@}NEVER_REQUIRED")
        );
        $this->addBasicTextArea("VI_VIII_comments", "Additional Comments (optional): ");
        $this->XINRegisterRule(
            "VI_VIII_comments",
            array("VI_VIII_comments{@}=={@}NEVER_REQUIRED")
        );
    }

    /**
     * Page 4
     *
     * @return void
     */
    function _page4()
    {
        $this-> addLabel("<h2>IX. Below is a list of items that describe people. For each item please select \"Not True\", \"Somewhat or Sometimes True\", or \"Very True or Often True\" to describe yourself <i>over the past 6 months.</i> Please answer all items as well as you can, even if some do not seem to apply to you. </h2>");
        $questions = [
                      "I am too forgetful",
                      "I make good use of my opportunities",
                      "I argue a lot",
                      "I work up to my ability",
                      "I blame others for my problems",
                      "I use drugs (other than for alcohol and nicotine) for nonmedical purposes (describe)",
                      "I brag",
                      "I have trouble concentrating or paying attention for long",
                      "I can't get my mind off certain thoughts (describe)",
                      "I have trouble sitting still",
                      "I am too dependent on others",
                      "I feel lonely",
                      "I feel confused or in a fog",
                      "I cry a lot",
                      "I am pretty honest",
                      "I am mean to others",
                      "I daydream a lot",
                      "I deliberately try to hurt or kill myself",
                      "I try to get a lot of attention",
                      "I damage or destroy my things",
                      "I damage or destroy things belonging to others",
                      "I worry about my future",
                      "I break rules at work or elsewhere",
                      "I don't eat as well as I should",
                      "I don't get along with other people",
                      "I don't feel guilty after doing something I shouldn't",
                      "I am jealous of others",
                     ];

        $opts = array(
                 null        => "",
                 "not_true"  => "Not True",
                 "sometimes" => "Somewhat or Sometimes True",
                 "very_true" => "Very True or Often True",
                );

        for ($i = 0; $i<count($questions); $i++) {
                //$this->addLabel("{$questions[$i]}");
                $n = $i +1;
                $this->addSelect("question_{$n}", "{$n}. {$questions[$i]}", $opts);

            if (strpos($questions[$i], "(describe)") !== false) {
                //print_r("found it!");
                //die();
                $this->addBasicText("q_{$n}_description", "$this->indent Description:<br><h5><i>$this->indent$this->indent (Required if you answered true above. If you do not wish to answer enter NA)</i></h5>");
                $this->XINRegisterRule(
                    "q_{$n}_description",
                    array("question_{$n}{@}=={@}sometimes|very_true"),
                    "Required",
                    "q_{$n}_description"
                );
            }
        }
    }

    /**
     * Page 5
     *
     * @return void
     */
    function _page5()
    {
        $this->addLabel("<h2>IX. Below is a list of items that describe people. For each item please select \"Not True\", \"Somewhat or Sometimes True\", or \"Very True or Often True\" to describe yourself <i>over the past 6 months.</i> Please answer all items as well as you can, even if some do not seem to apply to you. </h2>");
        $questions = [
                      "I get along badly with my family",
                      "I am afraid of certain animals, situations, or places (describe)",
                      "My relations with the opposite sex are poor",
                      "I am afraid I might think or do something bad",
                      "I feel that I have to be perfect",
                      "I feel that no one loves me",
                      "I feel that others are out to get me",
                      "I feel worthless or inferior",
                      "I accidentally get hurt a lot, accident-prone",
                      "I get in many fights",
                      "My relations with neighbors are poor",
                      "I hang around peoeple who get in trouble",
                      "I hear sounds or voices that other people think aren't there (describe)",
                      "I am impulsive or act without thinking",
                      "I would rather be alone than with others",
                      "I lie or cheat",
                      "I feel overwhelmed by my responsibilities",
                      "I am nervous or tense",
                      "Parts of my body twitch or make nervous movements (describe)",
                      "I lack self-confidence",
                      "I am not liked by others",
                      "I can do certain things better than other people",
                      "I am too fearful or anxious",
                      "I feel dizzy or lightheaded",
                      "I feel too guilty",
                      "I have trouble planning for the future",
                      "I feel tired without good reason",
                      "My mood swings between elation and depression",
                     ];

        $opts = array(
                 null        => "",
                 "not_true"  => "Not True",
                 "sometimes" => "Somewhat or Sometimes True",
                 "very_true" => "Very True or Often True",
                );

        for ($i = 0; $i<count($questions); $i++) {
                //$this->addLabel("{$questions[$i]}");
                $n = $i +28;
                $this->addSelect("question_{$n}", "{$n}. {$questions[$i]}", $opts);

            if (strpos($questions[$i], "(describe)") !== false) {
                //print_r("found it!");
                //die();
                $this->addBasicText("q_{$n}_description", "$this->indent Description:<br><h5><i>$this->indent$this->indent (Required if you answered true above. If you do not wish to answer enter NA)</i></h5>");
                $this->XINRegisterRule(
                    "q_{$n}_description",
                    array("question_{$n}{@}=={@}sometimes|very_true"),
                    "Required",
                    "q_{$n}_description"
                );
            }
        }
    }

    /**
     * Page 6
     *
     * @return void
     */
    function _page6()
    {
        $this-> addLabel("<h2>IX. Below is a list of items that describe people. For each item please select \"Not True\", \"Somewhat or Sometimes True\", or \"Very True or Often True\" to describe yourself <i>over the past 6 months.</i> Please answer all items as well as you can, even if some do not seem to apply to you. </h2>");
        $this-> addLabel("<h3>56. Physical problems <i><b>without known medical cause:</b></i></h3>");
        $questions =[
                     "a. Aches or pains (<i><b>not</b></i> stomach or headaches)",
                     "b. Headaches",
                     "c. Nausea, feel sick",
                     "d. Problems with eyes (<i><b>not</b></i> if corrected by glasses) (describe)",
                     "e. Rashes or other skin problems",
                     "f. Stomachaches",
                     "g. Vomiting, throwing up",
                     "h. Heart pounding or racing",
                     "i. Numbness or tingling in body parts",
                    ];
        $opts      = array(
                      null        => "",
                      "not_true"  => "Not True",
                      "sometimes" => "Somewhat or Sometimes True",
                      "very_true" => "Very True or Often True",
                     );
        for ($i = 0; $i<count($questions); $i++) {
                //$this->addLabel("{$questions[$i]}");
                $n    = 56;
                $q_id = "{$n}_" . chr(ord('a')+$i);
                $this->addSelect("question_{$q_id}", "{$questions[$i]}", $opts);

            if (strpos($questions[$i], "(describe)") !== false) {
                //print_r("found it!");
                //die();
                $this->addBasicText("q_{$q_id}_description", "$this->indent Description:<br><h5><i>$this->indent$this->indent (Required if you answered true above. If you do not wish to answer enter NA)</i></h5> ");
                $this->XINRegisterRule(
                    "q_{$q_id}_description",
                    array("question_{$q_id}{@}=={@}sometimes|very_true"),
                    "Required",
                    "q_{$q_id}_description"
                );
            }
        }
        $questions =[
                     "I physically attack people",
                     "I pick my skin or other parts of my body (describe)",
                     "I fail to finish the things I should do",
                     "There is very little I enjoy",
                     "My work performance is poor",
                     "I am poorly coordinated or clumsy",
                     "I would rather be with older people than with people of my own age",
                     "I have trouble setting priorities",
                     "I refuse to talk",
                     "I repeat certain acts over and over (describe)",
                     "I have trouble making or keeping friends",
                     "I scream or yell a lot",
                     "I am secretive or keep things to myself",
                     "I see things that other people think aren't there (describe)",
                     "I am self-conscious or easily embarrassed",
                     "I worry about my family",
                     "I meet my responsibilities to my family",
                     "I show off or clown",
                    ];
        for ($i = 0; $i<count($questions); $i++) {
            //$this->addLabel("{$questions[$i]}");
            $n = $i+57;
            $this->addSelect("question_{$n}", "{$n}.  {$questions[$i]}", $opts);

            if (strpos($questions[$i], "(describe)") !== false) {
                //print_r("found it!");
                //die();
                $this->addBasicText("q_{$n}_description", "$this->indent Description:<br><h5><i>$this->indent$this->indent (Required if you answered true above. If you do not wish to answer enter NA)</i></h5>");
                $this->XINRegisterRule(
                    "q_{$n}_description",
                    array("question_{$n}{@}=={@}sometimes|very_true"),
                    "Required",
                    "q_{$n}_description"
                );
            }
        }
    }

    /**
     * Page 7
     *
     * @return void
     */
    function _page7()
    {
        $this-> addLabel("<h2>IX. Below is a list of items that describe people. For each item please select \"Not True\", \"Somewhat or Sometimes True\", or \"Very True or Often True\" to describe yourself <i>over the past 6 months.</i> Please answer all items as well as you can, even if some do not seem to apply to you. </h2>");
        $questions =[
                     "I am too shy or timid",
                     "My behavior is irresponsible",
                     "I sleep more than most other people during day and/or night (describe)",
                     "I have trouble making decisions",
                     "I have a speech problem (describe)",
                     "I stand up for my rights",
                     "My behavior is very changeable",
                     "I steal",
                     "I am easily bored",
                     "I do things that other people think are strange (describe)",
                     "I have thoughts that other people would think are strange (describe)",
                     "I am stubborn, sullen, or irritable",
                     "My moods or feelings change suddenly",
                     "I enjoy being with people",
                     "I rush into things without considering the risks",
                     "I drink too much alcohol or get drunk",
                     "I think about killing myself",
                     "I do things that may cause me trouble with the law (describe)",
                     "I talk too much",
                     "I tease others a lot",
                     "I have a hot temper",

                    ];

        $opts = array(
                 null        => "",
                 "not_true"  => "Not True",
                 "sometimes" => "Somewhat or Sometimes True",
                 "very_true" => "Very True or Often True",
                );

        for ($i = 0; $i<count($questions); $i++) {
                //$this->addLabel("{$questions[$i]}");
                $n = 75 + $i;
                $this->addSelect("question_{$n}", "{$n}.  {$questions[$i]}", $opts);

            if (strpos($questions[$i], "(describe)") !== false) {
                //print_r("found it!");
                //die();
                $this->addBasicText("q_{$n}_description", "$this->indent Description:<br><h5><i>$this->indent$this->indent (Required if you answered true above. If you do not wish to answer enter NA)</i></h5>");
                $this->XINRegisterRule(
                    "q_{$n}_description",
                    array("question_{$n}{@}=={@}sometimes|very_true"),
                    "Required",
                    "q_{$n}_description"
                );
            }
        }
    }

    /**
     * Page 8
     *
     * @return void
     */
    function _page8()
    {
        $this-> addLabel("<h2>IX. Below is a list of items that describe people. For each item please select \"Not True\", \"Somewhat or Sometimes True\", or \"Very True or Often True\" to describe yourself <i>over the past 6 months.</i> Please answer all items as well as you can, even if some do not seem to apply to you. </h2>");
        $questions =[
                     "I think about sex too much",
                     "I threaten to hurt people",
                     "I like to help others",
                     "I dislike staying in one place for very long",
                     "I have trouble sleeping (describe)",
                     "I stay away from my job even when I'm not sick or not on vacation",
                     "I don't have much energy",
                     "I am unhappy, sad or depressed",
                     "I am louder than others",
                     "People think I am disorganized",
                     "I try to be fair to others",
                     "I feel that I can't succeed",
                     "I tend to lose things",
                     "I like to try new things",
                     "I wish I were of the opposite sex",
                     "I keep from getting involved with others",
                     "I worry a lot",
                     "I worry about my relations with the opposite sex",
                     "I fail to pay my debts or meet other financial responsibilities",
                     "I feel restless or fidgety",
                     "I get upset too easily",
                     "I have trouble managing money or credit cards",
                     "I am too impatient",
                     "I am not good at details",
                     "I drive too fast",
                     "I tend to be late for appointments",
                     "I have trouble keeping a job",
                     "I am a happy person",
                    ];
        $opts      = array(
                      null        => "",
                      "not_true"  => "Not True",
                      "sometimes" => "Somewhat or Sometimes True",
                      "very_true" => "Very True or Often True",
                     );
        for ($i = 0; $i<count($questions); $i++) {
                //$this->addLabel("{$questions[$i]}");
                $n = 96 + $i;
                $this->addSelect("question_{$n}", "{$n}.  {$questions[$i]}", $opts);

            if (strpos($questions[$i], "(describe)") !== false) {
                //print_r("found it!");
                //die();
                $this->addTextElement("q_{$n}_description", "$this->indent Description: ");
                $this->XINRegisterRule(
                    "q_{$n}_description",
                    array("question_{$n}{@}=={@}sometimes|very_true"),
                    "Required",
                    "q_{$n}_description_group"
                );
            }
        }
        $this->addNumericElement("tobacco_per_day", "<b>124. <i>In the past 6 months,</i></b> how many times per day did you use tobacco (including smokeless tobacco)? ");
        $this->addNumericElement("days_drunk", "<b>125.<i> In the past 6 months,</i></b> on how many days were you drunk?");
        $this->addNumericElement("days_drugs", "<b>126. <i> In the past 6 months,</i></b> on how many days did you use drugs for nonmedical purposes (including marijuana, cocaine, and other drugs, except alcohol and nicotine)?");

        $this->addTextAreaElement("IX_comments", "Additional Comments (optional): ");
        $this->XINRegisterRule(
            "IX_comments",
            array("IX_comments{@}=={@}NEVER_REQUIRED")
        );
    }

    /**
    * Special validation rules for the ASR form.
    *
    * @return none.
    */
    function asrSpecialRules($values)
    {
        $errors = array();

        //------ Make sure user_age is a number in [1,100] or NA
        if (isset($values['user_age']) && !$this->_isIntOrNa($values, 'user_age', 1, 100)) {
            $errors['user_age'] = "Specify age between 1 and 100 or NA";
        }

        //------ Make sure tobacco_per_day is a number in [0,100] or NA
        if (isset($values['tobacco_per_day'])&& !$this->_isIntOrNa($values, 'tobacco_per_day', 0, 100)) {
            $errors['tobacco_per_day'] = "Specify a number of times between 0 and 100 or NA";
        }

        //------ Make sure days_drunk is a number in [0,200] or NA
        if (isset($values['days_drunk']) && !$this->_isIntOrNa($values, 'days_drunk', 0, 200)) {
            $errors['days_drunk'] = "Specify a number of days between 0 and 200 or NA";
        }

        //------ Make sure days_drugs is a number in [0,200] or NA
        if (isset($values['days_drugs'])&& !$this->_isIntOrNa($values, 'days_drugs', 0, 200)) {
            $errors['days_drugs'] = "Specify a number of days between 0 and 200 or NA";
        }

        return $errors;
    }

    /**
    * Checks that $values[$key] is set and is either the string 'NA'
    * or an integer between $min and $max.
    *
    * @param array  $values array of form values.
    * @param string $key    key for which the value should be checked.
    * @param int    $min    minimum valid value.
    * @param int    $max    maximum valid value.
    *
    * @return boolean true if $value[$key] is valid, false otherwise.
    */
    function _isIntOrNa($values, $key, $min, $max)
    {
        if (isset($values[$key])) {
            $val = $values[$key];
            if (preg_match('/\s*NA\s*$/', $val)) {
                return true;
            }

            if (preg_match('/\s*\d+\s*$/', $val)) {
                return $val >= $min && $val <= $max;
            }

            return false;
        }

        return false;
    }

    function getAdaptiveTScore(string $age_range, string $scale, $score, $db)
    {
        $sex     = "female";
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
        $sex     = "female";
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
        $sex     = "female";
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
        $sex     = "female";
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

    function sum012Responses($array, $record)
    {
        $sum = 0;

        foreach ($array as $a) {
            if ($record["question_" . $a] == "not_true") {
                $sum += 0;
            } elseif ($record["question_" . $a] == "sometimes") {
                $sum += 1;
            } elseif ($record["question_" . $a] == "very_true") {
                $sum += 2;
            }
        }

        return $sum;
    }

    function roundToNearestPoint2($num)
    {
        return round($num*5)/5;
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

        $age       = $record["user_age"];
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

        $education_age_range = "";

        if ($age_range == "18-35") {
            if ($age >= 18 && $age <= 29) {
                $education_age_range = "18-29";
            }
        }

        $scores = array();

        /***** ASR AND ABCL ADAPTIVE FUNCTIONING SCALES *****/

        /********************
         * I. FRIENDS SCALE *
         ********************/

        if ($record["1_A"] == "none") {
            $I_A = 0;
        } elseif ($record["1_A"] == "1") {
            $I_A = 1;
        } elseif ($record["1_A"] == "2") {
            $I_A = 2;
        } elseif ($record["1_A"] == "4") {
            $I_A = 3;
        }

        if ($record["1_B"] == "less") {
            $I_B = 0;
        } elseif ($record["1_B"] == "1") {
            $I_B = 1;
        } elseif ($record["1_B"] == "3") {
            $I_B = 2;
        } elseif ($record["1_B"] == "more") {
            $I_B = 3;
        }

        if ($record["1_C"] == "not") {
            $I_C = 0;
        } elseif ($record["1_C"] == "average") {
            $I_C = 1;
        } elseif ($record["1_C"] == "above") {
            $I_C = 2;
        } elseif ($record["1_C"] == "far") {
            $I_C = 3;
        }

        if ($record["1_D"] == "less") {
            $I_D = 0;
        } elseif ($record["1_D"] == "1") {
            $I_D = 1;
        } elseif ($record["1_D"] == "3") {
            $I_D = 2;
        } elseif ($record["1_D"] == "more") {
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

        if ($record["live_with_spouse"] == "yes") {
            $plus  = 0;
            $minus = 0;

            $plus_fields = array(
                            "A",
                            "C",
                            "D",
                            "G",
                           );

            $minus_fields = array(
                             "B",
                             "E",
                             "F",
                             "H",
                            );

            foreach ($plus_fields as $field) {
                if ($record["spouse_" . $field] == "not_true") {
                    $plus += 0;
                } elseif ($record["spouse_" . $field] == "somewhat_true") {
                    $plus += 1;
                } elseif ($record["spouse_" . $field] == "very_true") {
                    $plus += 2;
                }
            }

            foreach ($minus_fields as $field) {
                if ($record["spouse_" . $field] == "not_true") {
                    $minus += 0;
                } elseif ($record["spouse_" . $field] == "somewhat_true") {
                    $minus += 1;
                } elseif ($record["spouse_" . $field] == "very_true") {
                    $minus += 2;
                }
            }

            $scores["ii_spouse_partner_total_score"] = $plus - $minus;
            $scores["ii_spouse_partner_t_score"]     = $this->getAdaptiveTScore($age_range, "spouse_partner", $scores["ii_spouse_partner_total_score"], $db);
        }

        if ($record["live_with_spouse"] == "no") {
            $scores["ii_spouse_partner_total_score"] = "Not Scored";
            $scores["ii_spouse_partner_t_score"]     = "N/A";
        }

        /****************************
         * III. ASR FAMILY SCALE *
         ****************************/

        // Score only the items for which Worse, Average, or Better are checked

        $ignore_count = 0;
        $sum          = 0;

        $family_questions = array(
                             "family_A",
                             "family_B",
                             "family_C",
                             "family_D",
                             "Family_E_1",
                             "Family_E_2",
                             "Family_E_3",
                             "Family_E_4",
                             "Family_F",
                            );

        foreach ($family_questions as $q) {
            if ($record[$q] == "worse") {
                $sum += 0;
            } elseif ($record[$q] == "variable") {
                $sum += 1;
            } elseif ($record[$q] == "better") {
                $sum += 2;
            } else {
                $ignore_count++;
            }
        }

        if ($ignore_count == 9) {
             $scores["iii_family_mean_score"] = null;
             $scores["iii_family_t_score"]    = "N/A";
        } else {
            $mean = $sum / (9 - $ignore_count);
            $mean = $this->roundToNearestPoint2($mean);
            $scores["iii_family_mean_score"] = $mean;
            $scores["iii_family_t_score"]    = $this->getAdaptiveTScore($age_range, "family", $scores["iii_family_mean_score"], $db);
        }

        /*********************
         * IV. ASR JOB SCALE *
         *********************/

        // Do not score this scale unless the respondent reported
        // being in paid jobs or the military in the past 6 months
        // and circled scores for each item IV-A through IV-I, except
        // item IV-E, which is not counted in the scale score

        // Items IV-A and C: Enter the 0,1,2 scores circled
        // by the respondent in the column of spaces
        // under the + (plus) heading for these items

        // Items IV-B, D, F, G, H, I: Enter the 0,1,2, scores circled
        // by the respondent in the column of spaces
        // under the - (minus) heading beside these items
        // Follow the procedure described for the Spouse/Partner scale
        // to obtain the total scale score

        $plus  = 0;
        $minus = 0;

        $plus_fields = array(
                        "A",
                        "C",
                       );

        $minus_fields = array(
                         "B",
                         "D",
                         "F",
                         "G",
                         "H",
                         "I",
                        );

        if ($record["jobs"] == "yes") {
            foreach ($plus_fields as $field) {
                if ($record["Job_" . $field] == "not_true") {
                    $plus += 0;
                } elseif ($record["Job_" . $field] == "sometimes") {
                    $plus += 1;
                } elseif ($record["Job_" . $field] == "very_true") {
                    $plus += 2;
                }
            }

            foreach ($minus_fields as $field) {
                if ($record["Job_" . $field] == "not_true") {
                    $minus += 0;
                } elseif ($record["Job_" . $field] == "sometimes") {
                    $minus += 1;
                } elseif ($record["Job_" . $field] == "very_true") {
                    $minus += 2;
                }
            }

            $scores["iv_job_total_score"] = $plus - $minus;
            $scores["iv_job_t_score"]     = $this->getAdaptiveTScore($age_range, "job", $scores["iv_job_total_score"], $db);
        }

        if ($record["jobs"] == "no") {
            $scores["iv_job_total_score"] = "Not Scored";
            $scores["iv_job_t_score"]     = "N/A";
        }

        /**************************
         * V. ASR EDUCATION SCALE *
         **************************/

        // Do not score this scale unless respondent reported being in an
        // educational or training program in the past 6 months and circled scores
        // for each item V-A through V-E

        // Items V-A, B, D: Enter the 0,1,2, scores circled
        // by the respondent in the column of spaces
        // UNDER THE + (plus) heading for these items

        // Items V-C, E: Enter the 0,1,2, scores circled
        // by the respondent in the column of spaces
        // UNDER THE - (minus) heading for these items

        $plus  = 0;
        $minus = 0;

        $plus_fields = array(
                        "A",
                        "B",
                        "D",
                       );

        $minus_fields = array(
                         "C",
                         "E",
                        );

        if ($record["education"] == "yes") {
            foreach ($plus_fields as $field) {
                if ($record["education_" . $field] == "not_true") {
                    $plus += 0;
                } elseif ($record["education_" . $field] == "somewhat_true") {
                    $plus += 1;
                } elseif ($record["education_" . $field] == "very_true") {
                    $plus += 2;
                }
            }

            foreach ($minus_fields as $field) {
                if ($record["education_" . $field] == "not_true") {
                    $minus += 0;
                } elseif ($record["education_" . $field] == "somewhat_true") {
                    $minus += 1;
                } elseif ($record["education_" . $field] == "very_true") {
                    $minus += 2;
                }
            }

            $scores["v_education_total_score"] = $plus - $minus;
            $scores["v_education_t_score"]     = $this->getAdaptiveTScore($education_age_range, "education", $scores["v_education_total_score"], $db);
        }

        if ($record["education"] == "no") {
            $scores["v_education_total_score"] = "Not Scored";
            $scores["v_education_t_score"]     = "N/A";
        }

        /*****************************
         * MEAN ADAPTIVE FUNCTIONING *
         *****************************/

        // Mean of the adaptive functioning scales:
        // - Friends
        // - Spouse/Partner (Can be not scored)
        // - Family
        // - Job (Can be not scored)
        // - Education (Can be not scored)

        // Only compute mean of all all adaptive functioning scales
        // if each scale was scored

        if (is_numeric($scores["i_friends_total_score"])
            && is_numeric($scores["ii_spouse_partner_total_score"])
            && is_numeric($scores["iii_family_mean_score"])
            && is_numeric($scores["iv_job_total_score"])
            && is_numeric($scores["v_education_total_score"])
        ) {
            $mean = 0;

            $adaptive_functioning_sum =
            $scores["i_friends_total_score"] +
            $scores["ii_spouse_partner_total_score"] +
            $scores["iii_family_mean_score"] +
            $scores["iv_job_total_score"] +
            $scores["v_education_total_score"];

            $mean = $adaptive_functioning_sum / 5;
            $mean = round($mean, 1);

            $scores["mean_adaptive_score"]   = $mean;
            $scores["mean_adaptive_t_score"] = $this->getAdaptiveTScore($age_range, "mean_adaptive", $scores["mean_adaptive_score"], $db);
        } else {
            $scores["mean_adaptive_score"]   = "Not Scored";
            $scores["mean_adaptive_t_score"] = "N/A";
        }

        /***** SUBSTANCE USE SCALES *****/

        $substances = array(
                       "tobacco" => $record["tobacco_per_day"],
                       "alcohol" => $record["days_drunk"],
                       "drugs"   => $record["days_drugs"],
                      );

        $missing_substance_field        = false;
        $can_compute_mean_substance_use = true;

        foreach ($substances as $name => $response) {
            if (is_null($response)) {
                $missing_substance_field        = true;
                $scores[$name . "_t_score"]     = "Missing field";
                $can_compute_mean_substance_use = false;
            } else {
                if ($age_range == "18-35" || $age_range == "36-59") {
                    $t_score = $this->getSubstanceTScore($age_range, $name, intval($response), $db);
                    $scores[$name . "_t_score"] = $t_score;
                } else {
                    $scores[$name . "_t_score"] = "Age out of bounds";
                }
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

        $sum = 0;

        foreach (self::CRITICAL_ITEMS as $c_item) {
            if ($record["question_" . $c_item] == "not_true") {
                $sum += 0;
            } elseif ($record["question_" . $c_item] == "sometimes") {
                $sum += 1;
            } elseif ($record["question_" . $c_item] == "very_true") {
                $sum += 2;
            }
        }

        $scores["critical_items_score"]   = $sum;
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
                            "14",
                            "91",
                            "103",
                            "9",
                            "18",
                            "40",
                            "66",
                            "70",
                            "84",
                            "8",
                            "16",
                            "55",
                            "57",
                            "97",
                            "6",
                            "90",
                            "92",
                            "10",
                            "21",
                           ];

    CONST I_ANXIOUS_DEPRESSED = [
                                 "12",
                                 "13",
                                 "14",
                                 "22",
                                 "31",
                                 "33",
                                 "34",
                                 "35",
                                 "45",
                                 "47",
                                 "50",
                                 "52",
                                 "71",
                                 "91",
                                 "103",
                                 "107",
                                 "112",
                                 "113",
                                ];

    CONST II_WITHDRAWN = [
                          "25",
                          "30",
                          "42",
                          "48",
                          "60",
                          "65",
                          "67",
                          "69",
                          "111",
                         ];

    CONST III_SOMATIC_COMPLAINTS = [
                                    "51",
                                    "54",
                                    "56_a",
                                    "56_b",
                                    "56_c",
                                    "56_d",
                                    "56_e",
                                    "56_f",
                                    "56_g",
                                    "56_h",
                                    "56_i",
                                    "100",
                                   ];

    CONST IV_THOUGHT_PROBLEMS = [
                                 "9",
                                 "18",
                                 "36",
                                 "40",
                                 "46",
                                 "63",
                                 "66",
                                 "70",
                                 "84",
                                 "85",
                                ];

    CONST V_ATTENTION_PROBLEMS = [
                                  "1",
                                  "8",
                                  "11",
                                  "17",
                                  "53",
                                  "59",
                                  "61",
                                  "64",
                                  "78",
                                  "101",
                                  "102",
                                  "105",
                                  "108",
                                  "119",
                                  "121",
                                 ];

    CONST VI_AGGRESSIVE_BEHAVIOR = [
                                    "3",
                                    "5",
                                    "16",
                                    "28",
                                    "37",
                                    "55",
                                    "57",
                                    "68",
                                    "81",
                                    "86",
                                    "87",
                                    "95",
                                    "97",
                                    "116",
                                    "118",
                                   ];

    CONST VII_RULE_BREAKING_BEHAVIOR = [
                                        "6",
                                        "20",
                                        "23",
                                        "26",
                                        "39",
                                        "41",
                                        "43",
                                        "76",
                                        "82",
                                        "90",
                                        "92",
                                        "114",
                                        "117",
                                        "122",
                                       ];

    CONST VIII_INTRUSIVE = [
                            "7",
                            "19",
                            "74",
                            "93",
                            "94",
                            "104",
                           ];

    CONST OTHER_PROBLEMS = [
                            "10",
                            "21",
                            "24",
                            "27",
                            "29",
                            "32",
                            "38",
                            "44",
                            "58",
                            "62",
                            "72",
                            "75",
                            "77",
                            "79",
                            "83",
                            "89",
                            "96",
                            "99",
                            "110",
                            "115",
                            "120",
                           ];

    CONST _1_DEPRESSIVE_PROBLEMS = [
                                    "14",
                                    "18",
                                    "24",
                                    "35",
                                    "52",
                                    "54",
                                    "60",
                                    "77",
                                    "78",
                                    "91",
                                    "100",
                                    "102",
                                    "103",
                                    "107",
                                   ];

    CONST _2_ANXIETY_PROBLEMS = [
                                 "22",
                                 "29",
                                 "45",
                                 "50",
                                 "72",
                                 "112",
                                ];

    CONST _3_SOMATIC_PROBLEMS = [
                                 "56_a",
                                 "56_b",
                                 "56_c",
                                 "56_d",
                                 "56_e",
                                 "56_f",
                                 "56_g",
                                 "56_h",
                                 "56_i",
                                ];

    CONST _4_AVOIDANT_PERSONALITY_PROBLEMS = [
                                              "25",
                                              "42",
                                              "47",
                                              "67",
                                              "71",
                                              "75",
                                              "111",
                                             ];

    CONST _5_ADH_PROBLEMS = [
                             "1",
                             "8",
                             "10",
                             "36",
                             "41",
                             "59",
                             "61",
                             "89",
                             "105",
                             "108",
                             "115",
                             "118",
                             "119",
                            ];

    CONST _6_ANTISOCIAL_PERSONALITY_PROBLEMS = [
                                                "3",
                                                "5",
                                                "16",
                                                "21",
                                                "23",
                                                "26",
                                                "28",
                                                "37",
                                                "39",
                                                "43",
                                                "57",
                                                "76",
                                                "82",
                                                "92",
                                                "95",
                                                "97",
                                                "101",
                                                "114",
                                                "120",
                                                "122",
                                               ];
}
