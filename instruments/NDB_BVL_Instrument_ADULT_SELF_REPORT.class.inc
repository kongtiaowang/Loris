<?php
/*
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
 * Creates the form elements for the ADULT_SELF_REPORT instrument
 *
 * @category Instrument
 * @package  Neuropsych
 * @author   Leo Thomas <lthomas.mcin@gmail.com>
 * @license  http://www.gnu.org/licenses/gpl-3.0.txt GPLv_
 * @link     https://www.github.com/aces/
 */
class NDB_BVL_Instrument_ADULT_SELF_REPORT extends NDB_BVL_Instrument
{
    use LegacyInstrumentTrait;

    var $ValidityEnabled  = false;
    var $ValidityRequired = false;

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
        $this->form     = new LorisForm('ADULT_SELF_REPORT_form');
        $this->page     = $page;

        // set the object properties
        $this->testName = 'ADULT_SELF_REPORT'; // test_names.Test_name
        $this->table    = 'ADULT_SELF_REPORT'; // name of database
        // table corresponding to instrument
        $this->commentID = $commentID; // data keyed by commentID

        //The array of dates/timestamps to convert to database dates/timestamps
        //Any LorisForm date elements must be listed here
        $this->dateTimeFields = array("Date_taken");

        //The array of selects with multiple answers allowed
        //Any LorisForm multiple selects must be listed here
        $this->selectMultipleElements = array();

        // required fields for data entry completion status
        $this->_requiredElements = array(
            'CommentID',
        );

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
            "/ADULT_SELF_REPORT(_page[0-9]+)/",
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
        $this->addHeader("Adult Self-Report For Ages 18-59");

        //survey instrument don't need this
        // $this->_addMetadataFields();
        $this->addBasicDate('Date_taken', 'Date of Administration', $this->dateOptions);

        $opts = array(
            null     => "",
            "male"   => "Male",
            "female" => "Female",
            "other"  => "Other"
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
    }

    /**
     * Page 1
     *
     * @return void
     */
    function _page1()
    {
        // Header
        $this->addHeader("Adult Self-Report For Ages 18-59");

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
                      <b><i>during the past 6 months </i><b>"
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
              "very_true"     => "Very True or Often True"
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
    function _page2()
    {

        $this->addLabel("<h1>III. Family</h1>");
        $this->addLabel("<h3>Compared to others, how well do you: </h3>");

        $opts = array(
            null         => "",
            "worse"      => "Worse than Average",
            "variable"   => "Variable or Average",
            "better"     => "Better than Average",
            "no_contact" => "No contact"
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
            "no_children" => "I have no children"
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
            "yes" => "<b>Yes -- please describe your job(s)</b>"
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
            "very_true" => "Very True or Often True"
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
        $opts = array(null=>"",
            "no"  => "<b>No -- please skip to Section VI</b>",
            "yes" => "<b>Yes</b> -- Please answer the following items:"
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

        $opts = array(null=> "",
            "not_true"  => "Not True",
            "sometime"  => "Somewhat or Sometimes True",
            "very_true" => "Very True or Often True"
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
    function _page3()
    {

        $this->addSelect("illness", "<b>VI. Do you have any illness, disability or handicap? </b>", array(null=> "", "no" => "No", "yes"=> "Yes"));
        $this->addBasicTextArea("illness_description", "If yes, please describe:<br><h5><i>(If you don't wish to answer enter NA)</i></h5>");
        $this->XINRegisterRule(
            "illness_description",
            array("illness{@}=={@}yes"),
            "Required",
            "illness_description"
        );

        $this->addSelect("concerns", "<b>VII. Do you have concerns or worries about family, education, or other things?</b>", array(null=> "", "no" => "No concerns", "yes"=> "Yes -- Please describe"));

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
            "I am jealous of others"
        ];

        $opts = array(null=> "",
            "not_true"  => "Not True",
            "sometimes" => "Somewhat or Sometimes True",
            "very_true" => "Very True or Often True"
        );

        for ($i = 0; $i<count($questions); $i++){
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

         $opts = array(null=> "",
             "not_true"  => "Not True",
             "sometimes" => "Somewhat or Sometimes True",
             "very_true" => "Very True or Often True"
         );

         for ($i = 0; $i<count($questions); $i++){
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
                  "i. Numbness or tingling in body parts"
              ];
               $opts     = array(null=> "",
                   "not_true"  => "Not True",
                   "sometimes" => "Somewhat or Sometimes True",
                   "very_true" => "Very True or Often True"
               );
               for ($i = 0; $i<count($questions); $i++){
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
                   "I show off or clown"
               ];
               for ($i = 0; $i<count($questions); $i++){
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
            "I have a hot temper"

        ];

               $opts = array(null=> "",
                   "not_true"  => "Not True",
                   "sometimes" => "Somewhat or Sometimes True",
                   "very_true" => "Very True or Often True"
               );

               for ($i = 0; $i<count($questions); $i++){
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
            "I am a happy person"
        ];
        $opts      = array(null=> "",
            "not_true"  => "Not True",
            "sometimes" => "Somewhat or Sometimes True",
            "very_true" => "Very True or Often True"
        );
        for ($i = 0; $i<count($questions); $i++){
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
        if(isset($values[$key])) {
            $val = $values[$key];
            if(preg_match('/\s*NA\s*$/', $val)) {
                return true;
            }

            if(preg_match('/\s*\d+\s*$/', $val)) {
                return $val >= $min && $val <= $max;
            }

            return false;
        }

        return false;
    }

}




