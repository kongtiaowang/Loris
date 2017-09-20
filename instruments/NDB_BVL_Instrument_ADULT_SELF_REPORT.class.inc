<?php
/**
 * This file contains the NDB_BVL_Instrument_TADULT_SELF_REPORT
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
    function setup($commentID, $page)
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
        $this->_selectMultipleElements = array();

        // required fields for data entry completion status
        $this->_requiredElements = array(
                                    'Examiner',
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
        )) {
            call_user_func(array($this, $matches[1]));
        } else {
            $this->_main();
        }

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
        $this->addHeader("Adult Self-Report For Ages 18-59");

        $this->_addMetadataFields();
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

        $this->addLabel("<h3>Your full name:</h3>");
        $this->addTextElement("user_first_name", "$this->indent First: ");
        $this->addTextElement("user_last_name", "$this->indent Last: ");

        $opts = array(
                 null   => "",
                 "male"   => "Male",
                 "female" => "Female",
                );
        $this->addSelect("user_gender", "Your gender: ", $opts);

        $this->addNumericElement("user_age", "Your age: ");

        $this->addTextElement("user_ethnic_group", "Your ethnic group or race: ");

        $this->addDateElement("date", "Today's Date: ");

        $this->addDateElement("user_birthdate", "Your birthdate:");

        $this->addLabel("Please fill out this form to reflect <i><b>your</b></i> views, even if other people might not agree. You need not spend a lot of time on any item. Feel free to print additional comments (optional). <b><i>Be sure to answer all items</i></b>");

        $this->addLabel("<b>YOUR USUAL TYPE OF WORK, even if not working now.</b> Please be specific -- for example, auto mechanic; high school teacher; homemaker; laborer; lathe operator; shoe salesman; army sergeant; student(indicate what you are studying & what degree you expect)");

        $this->addTextElement("user_work", "Your work: ");
        $this->addTextElement("spouse_work", "Spouse or partner's work: ");
        $this->XINRegisterRule("spouse_work",
          array("spouse_work{@}=={@}NEVER_REQUIRED")
          );
        $opts = array(
                 null  => "",
                 "1"     => "1. No high school diploma and no GED",
                 "2"     => "2. General Equivalency Diploma (GED)",
                 "3"     => "3. High school graduate",
                 "4"     => "4. Some college but no college degree",
                 "5"     => "5. Associate's Degree",
                 "6"     => "6. Bachelor's or RN Degree",
                 "7"     => "7. Some graduate school but no graudate degree",
                 "8"     => "8. Master's Degree",
                 "9"     => "9. Doctoral or Law Degree",
                 "other" => "Other Education (specify)",
                );

        $this->addSelect("user_education", "<b>PLEASE SELECT YOUR HIGHEST EDUCATION</b>", $opts);

        $this->addTextElement("if_other_education", "$this->indent If other, please specify: ");

        $this->XINRegisterRule(
            "if_other_education",
            array("user_education{@}=={@}other"),
            "Required",
            "if_other_group"
        );

        $this->addLabel("<h1><b>I. FRIENDS </b></h1>");
        $opts = array(
                 null => "",
                 "none" => "None",
                 "1"    => "1",
                 "2"    => "2 or 3",
                 "4"    => "4 or more",
                );

        $this->addSelect("1_A", "A. About how many close friends do you have? (Do not include family members)", $opts);

          $opts2 = array(
                    null => "",
                    "less" => "Less than 1",
                    "1"    => "1 or 2",
                    "3"    => "3 or 4",
                    "more" => "5 or more",
                   );

          $this->addSelect("1_B", "B. About how many times a month do you have contact with any of your friends? (Include in-person contacts, phone, letters, e-mail.)", $opts2);

          $opts = array(
                   null    => "",
                   "not"     => "Not as well as I'd like",
                   "average" => "Average",
                   "above"   => "Above average",
                   "far"     => "Far above average",
                  );

          $this->addSelect("1_C", "C. How well do you get along with your close friends?", $opts);

          $this->addSelect("1_D", "D. About how many times a month do any friends or family visit you?", $opts2);

          $this->addTextAreaElement("I_comments", "Additional comments (optional): ");
          $this->XINRegisterRule(
              "I_comments",
              array("I_comments{@}=={@}NEVER_REQUIRED")
          );

          $this->addLabel("<h1><b>II. SPOUSE OR PARTNER </b></h1>");

          $opts = array(
                   null              => "",
                   "never"             => "Never been married",
                   "married_separated" => "Married but separated from spouse",
                   "married_together"  => "Married, living with spouse",
                   "divorced"          => "Divorced",
                   "widowed"           => "Widowed",
                   "other"             => "Other",
                  );

          $this->addSelect("marital_state", "What is your marital status?", $opts);
          $this->addTextElement("if_other_marital", "$this->indent If other -- please describe: ");

          $this->XINRegisterRule(
              "if_other_marital",
              array("marital_status{@}=={@}other"),
              "Required",
              "if_other_group"
          );
          $opts= array(
                    null => "",
                    "no" => "<b>No -- please skip to page 2 </b>",
                    "yes" => "<b>Yes </b> -- Answer items A-H to describe your relationship 
                      <b><i>during the past 6 months </i><b>");

          $this->addSelect("live_with_spouse", "<b><i>At any time in the past 6 months,</i></b> did you live with your 
            spouse or with a partner? ", $opts);

          $opts= array(
                  null => "",
                  "not_true" => "Not True",
                  "somewhat_true" => "Somewhat or Sometimes true",
                  "very_true" => "Very True or Often True");

          $this->addSelect("spouse_A", "A. I get along well with my spouse or partner", $opts);
          $this->XINRegisterRule(
              "spouse_A",
              array("live_with_spouse{@}=={@}not_true"),
              "Please skip to page 2 if you've answered \"No\" above",
              "answer_not_allowed_group"
          );

          $this->addSelect("spouse_B", "B. My spouse or partner and I have trouble sharing responsibilites", $opts);
          $this->XINRegisterRule(
              "spouse_B",
              array("live_with_spouse{@}=={@}not_true"),
              "Please skip to page 2 if you've answered \"No\" above",
              "answer_not_allowed_group"
          );

          $this->addSelect("spouse_C", "C. I feel satisfied with my spouse or partner", $opts);
          $this->XINRegisterRule(
              "spouse_C",
              array("live_with_spouse{@}=={@}not_true"),
              "Please skip to page 2 if you've answered \"No\" above",
              "answer_not_allowed_group"
          );

          $this->addSelect("spouse_D", "D. My spouse or partner and I enjoy similar activities", $opts);
          $this->XINRegisterRule(
              "spouse_D",
              array("live_with_spouse{@}=={@}not_true"),
              "Please skip to page 2 if you've answered \"No\" above",
              "answer_not_allowed_group"
          );
          $this->addSelect("spouse_E", "E. my spouse or partner and I <i>disagree</i> about living arrangements, 
            such as where we live", $opts);
          $this->XINRegisterRule(
              "spouse_E",
              array("live_with_spouse{@}=={@}not_true"),
              "Please skip to page 2 if you've answered \"No\" above",
              "answer_not_allowed_group"
          );
          $this->addSelect("spouse_F", "F. I have trouble with my spouse or partner's family", $opts);
          $this->XINRegisterRule(
              "spouse_F",
              array("live_with_spouse{@}=={@}not_true"),
              "Please skip to page 2 if you've answered \"No\" above",
              "answer_not_allowed_group"
          );
          $this->addSelect("spouse_G", "G. I like my spouse or partner's friends", $opts);
          $this->XINRegisterRule(
              "spouse_G",
              array("live_with_spouse{@}=={@}not_true"),
              "Please skip to page 2 if you've answered \"No\" above",
              "answer_not_allowed_group"
          );
          $this->addSelect("spouse_H", "H. My spouse or partner's behavior annoys me", $opts);
          $this->XINRegisterRule(
              "spouse_H",
              array("live_with_spouse{@}=={@}not_true"),
              "Please skip to page 2 if you've answered \"No\" above",
              "answer_not_allowed_group"
          );

          $this->addTextAreaElement("II_comments", "Additional Comments (optional): ");
          $this->XINRegisterRule(
              "II_comments",
              array("II_comments{@}=={@}NEVER_REQUIRED")
          );
      }
      function _page2(){
        
        $this->addLabel("<h1>III. Family</h1>");
        $this->addLabel("<h3>Compared to others, how well do you: </h3>");

        $opts = array(
                  null => "",
                  "worse" => "Worse than Average",
                  "variable" => "Variable or Average",
                  "better" => "Better than Average",
                  "no_contact" => "No contact");
        
        $opts_temp = $opts;
        $opts_temp["no_brothers"] = " I have no brothers";
        
        $this->addSelect("family_A", "A. Get along with your brothers?",$opts_temp );
        
        $opts_temp = $opts;
        $opts_temp["no_sisters"] = " I have no sisters";

        $this->addSelect("family_B", "B. Get along with your sisters?",$opts_temp );
      
        $opts_temp = $opts;
        $opts_temp["mother_deceased"] = "Mother is deceased";
        
        $this->addSelect("family_C", "C. Get along with your mother?",$opts_temp );
        
        $opts_temp = $opts;
        $opts_temp["father_deceased"] = "Father is deceased";
        
        $this->addSelect("family_D", "D. Get along with your father?",$opts_temp );
      
        $opts_temp = array(
                      null=> "", 
                      "no_children" => "I have no children"
                      );
        
        $this->addSelect("Family_E", "E. Get along with your biological <br> or adpoted children? ", $opts_temp);

        $this->XINRegisterRule(
              "Family_E",
              array("no_children{@}=={@}NEVER_REQUIRED")
          );

        $opts_temp = $opts;
        $opts_temp["not_applicable"] ="Not applicable";

        $this->addSelect("Family_E_1","$this->indent 1. Oldest child", $opts_temp);
        $this->XINRegisterRule(
              "Family_E_1",
              array("Family_E{@}=={@}no_children"),
              "Please unselect \"I have no children \" above to answer this question",
              "answer_not_allowed_group"
          );
        $this->addSelect("Family_E_2","$this->indent 2. 2nd oldest child", $opts_temp);
        $this->XINRegisterRule(
              "Family_E_2",
              array("Family_E{@}=={@}no_children"),
              "Please unselect \"I have no children \" above to answer this question",
              "answer_not_allowed_group"
          );
        $this->addSelect("Family_E_3","$this->indent 3. 3rd oldest child", $opts_temp);
        $this->XINRegisterRule(
              "Family_E_3",
              array("Family_E{@}=={@}no_children"),
              "Please unselect \"I have no children \" above to answer this question",
              "answer_not_allowed_group"
          );
        $this->addSelect("Family_E_4","$this->indent 4. Other children", $opts_temp);
        $this->XINRegisterRule(
              "Family_E_4",
              array("Family_E{@}=={@}no_children"),
              "Please unselect \"I have no children \" above to answer this question",
              "answer_not_allowed_group"
          );
        $opts_temp = $opts;
        $opts_temp["no_stepchildren"] = "I have no step children";

        $this->addSelect("Family_F", "F. Get along with your stepchildren", $opts_temp);
        $this->addTextAreaElement("III_comments", "Additional Comments (optional): ");
        $this->XINRegisterRule(
              "III_comments",
              array("III_comments{@}=={@}NEVER_REQUIRED")
          );
      
        $this->addLabel("<h1>IV. Job</h1>");
        $opts = array(
                    null => "",
                    "no" => "<b>No -- please skip to section V.</b>",
                    "yes" => "<b>Yes -- please describe your job(s)</b>");
        $this->addSelect("jobs", "<b><i> At any time in the past 6 months,</i></b> did you have any paid jobs (including self-eployment and military service)? ", $opts);
        $this->addTextAreaElement("job_desc","Description of your job(s)");
        $this->XINRegisterRule(
              "jobs_desc", 
              array("jobs{@}=={@}yes"),
              "Required",
              "if_other_group");
        $opts = array(
                  null => "",
                  "not_true" => "Not True",
                  "sometimes" => "Somewhat or Sometimes True",
                  "very_true" => "Very True or Often True"
                  );
        $this->addSelect("Job_A", "A. I work well with others", $opts);
        $this->XINRegisterRule(
              "Job_A",
              array("jobs{@}=={@}no"),
              "Please skip to section V, if you've answered \"No\" above",
              "answer_not_allowed_group"
          );
        $this->addSelect("Job_B", "B. I have trouble getting along with bosses", $opts);
        $this->XINRegisterRule(
              "Job_B",
              array("jobs{@}=={@}no"),
              "Please skip to section V, if you've answered \"No\" above",
              "answer_not_allowed_group"
          );
        $this->addSelect("Job_C", "C. I do my work well", $opts);
        $this->XINRegisterRule(
              "Job_C",
              array("jobs{@}=={@}no"),
              "Please skip to section V, if you've answered \"No\" above",
              "answer_not_allowed_group"
          );
        $this->addSelect("Job_D", "D. I have trouble finishing my work", $opts);
        $this->XINRegisterRule(
              "Job_D",
              array("jobs{@}=={@}no"),
              "Please skip to section V, if you've answered \"No\" above",
              "answer_not_allowed_group"
          );
        $this->addSelect("Job_E", "E. I am satisfied with my work situation", $opts);
        $this->XINRegisterRule(
              "Job_E",
              array("jobs{@}=={@}no"),
              "Please skip to section V, if you've answered \"No\" above",
              "answer_not_allowed_group"
          );
        $this->addSelect("Job_F", "F. I do things that may cause me to lose my job", $opts);
        $this->addSelect("Job_G", "G. I stay away from my job even when I'm not sick or on vacation", $opts);
        $this->addSelect("Job_H", "H. My job is too stressful for me", $opts);
        $this->addSelect("Job_I", "I. I worry too much about work", $opts);

        $this->addTextAreaElement("IV_comments", "Additional Comments (optional): ");
        $this->XINRegisterRule(
              "IV_comments",
              array("IV_comments{@}=={@}NEVER_REQUIRED")
          );

        $this->addLabel("<h1>V. Education:</h1>");
        $opts = array(null=>"",
          "no" => "<b>No -- please skip to Section VI</b>",
          "yes"=> "<b>Yes</b> -- PLease answer the following items:");

        $this->addSelect("education", "<b><i>At any time in the past 6 months,</i><b> did you attend school, college, or any other education or training program?", $opts);
        
        $this->addTextElement("kind_of_program","What kind of school or program?");
        $this->addTextElement("degree_seeking", "What degree or diploma are you seeking?");
        $this->addTextElement("major", "Major?");
        $this->addTextElement("expected_grad", "When do you expect to receive your degree or diploma?");

        $this->XINRegisterRule(
              "kind_of_program",
              array("education{@}=={@}yes"),
              "Required",
              "if_other_group"
          );
        $this->XINRegisterRule(
              "degree_seeking",
              array("education{@}=={@}yes"),
              "Required",
              "if_other_group"
          );
        $this->XINRegisterRule(
              "major",
              array("education{@}=={@}yes"),
              "Required",
              "if_other_group"
          );
        $this->XINRegisterRule(
              "expected_grad",
              array("education{@}=={@}yes"),
              "Required",
              "if_other_group"
          );

        $opts = array(null=> "",
          "not_true" => "Not True",
          "sometime" => "Somewhat or Sometimes True",
          "very_true" => "Very True or Often True");
        
        $this->addSelect("education_A","A. I get along well with other students", $opts);
        $this->XINRegisterRule(
              "education_A",
              array("education{@}=={@}no"),
              "Please skip to section VI, if you've answered \"No\" above",
              "answer_not_allowed_group"
          );
        $this->addSelect("education_B", "B. I achieve what I am capable of", $opts);
        $this->XINRegisterRule(
              "education_B",
              array("education{@}=={@}no"),
              "Please skip to section VI, if you've answered \"No\" above",
              "answer_not_allowed_group"
          );
        $this->addSelect("education_C", "C. I have trouble finishing assignments", $opts);
        $this->XINRegisterRule(
              "education_C",
              array("education{@}=={@}no"),
              "Please skip to section VI, if you've answered \"No\" above",
              "answer_not_allowed_group"
          );
        $this->addSelect("education_D", "D. I am satisfied with my educaitonal situation", $opts);
        $this->XINRegisterRule(
              "education_D",
              array("education{@}=={@}no"),
              "Please skip to section VI, if you've answered \"No\" above",
              "answer_not_allowed_group"
          );
        $this->addSelect("education_E", "E. I do things that may cause me to fail", $opts);
        $this->XINRegisterRule(
              "education_E",
              array("education{@}=={@}no"),
              "Please skip to section VI, if you've answered \"No\" above",
              "answer_not_allowed_group"
          );
        $this->addTextAreaElement("V_comments", "Additional Comments (optional): ");
        $this->XINRegisterRule(
              "V_comments",
              array("V_comments{@}=={@}NEVER_REQUIRED")
          );
  }
function _page3(){

        $this->addSelect("illness", "<b>VI. Do you have any illness, disability or handicap? </b>", array(null=> "", "no" => "No", "yes"=> "Yes"));
        $this->addTextAreaElement("illness_description","If yes, please describe");
        $this->XINRegisterRule(
              "illness_description",
              array("illness{@}=={@}yes"),
              "Required",
              "if_other_group"
        );
         
        
        $this->addSelect("concerns", "<b>VII. Do you have concerns or worries about family, education, or other things?</b>", array(null=> "", "no" => "No concerns", "yes"=> "Yes -- Please describe"));

        $this->addTextAreaElement("concern_description","If yes, please describe");
        
        $this->XINRegisterRule(
              "concern_description",
              array("concerns{@}=={@}yes"),
              "Required",
              "if_other_group"
        );
        $this->addTextAreaElement("self_description", "<b>VII.Please describe the best things about yourself");
        $this->XINRegisterRule("self_description",
            array("self_description{@}==NEVER_REQUIRED"));
        $this->addTextAreaElement("VI_VIII_comments", "Additional Comments (optional): ");
        $this->XINRegisterRule(
              "VI_VIII_comments",
              array("VI_VIII_comments{@}=={@}NEVER_REQUIRED")
          );

      }
      function _page4(){
        $this-> addLabel("<h2>IX. Below is a list of items that describe people. For each item please select \"Not True\", \"Somewhat or Sometimes True\", or \"Very True or Often True\" to describe yourself <i>over the past 6 months.</i> Plase answer all items as well as you can, even if some do not seem to apply to you. </h2>");
        $questions= [
        "I am too forgetful",
        "I make good user of my opportunities",
        "I argue a lot",
        "I work up to my ability",
        "I balme others for my problems",
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
        "I don't gell guilty after doing sometthing I shouldn't",
        "I am jealous of others"
        ];

         $opts = array(null=> "", 
          "not_true" => "Not True",
          "sometimes" => "Somewhat or Sometimes True",
          "very_true" => "Very True or Often True");


        for ($i = 0; $i<count($questions); $i++){
          //$this->addLabel("{$questions[$i]}");
          $n = $i +1;
          $this->addSelect("question_{$n}", "{$n}. {$questions[$i]}", $opts);
          
          if ( strpos($questions[$i], "(describe)") !== false){
            //print_r("found it!");
            //die();
            $this->addTextElement("q_{$n}_description", "$this->indent Description: ");
            $this->XINRegisterRule("
              q_{$n}_description", 
              array("question_{$i}{@}=={@}sometimes", "question_{$i}{@}=={@}very_true"),
              "Required",
              "describe_group"
              );
          }
        }
      }
function _page5(){
    $this->addLabel("<h2>IX. Below is a list of items that describe people. For each item please select \"Not True\", \"Somewhat or Sometimes True\", or \"Very True or Often True\" to describe yourself <i>over the past 6 months.</i> Plase answer all items as well as you can, even if some do not seem to apply to you. </h2>");
        $questions= [
        "I get along badly with my family",
        "I am afraid of certain animals, situations, or places (describe)",
        "My relations with the opposite sex are poor",
        "I am afraid I might think or do somthing bad",
        "I feel that I have to be perfect",
        "I feel that no one loves me",
        "I feel that others are out to get me",
        "I feel worthless or inferior",
        "I accidentally get hurt a lot, accident-prone",
        "I get in many fights",
        "My relations with neighbors are poor",
        "I hang around peoeple who get in trouble",
        "I hear sounds or voices that other people think aren't there (describ)",
        "I am impulsive or act without thinking",
        "I would rather be alone than with others",
        "I lie or cheat",
        "I feel everwhelmed by my responsibilites",
        "I am nervous or tense",
        "Parts of my body twitch or make nervous movemenets (describe)",
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
          "not_true" => "Not True",
          "sometimes" => "Somewhat or Sometimes True",
          "very_true" => "Very True or Often True");


        for ($i = 0; $i<count($questions); $i++){
          //$this->addLabel("{$questions[$i]}");
          $n = $i +28;
          $this->addSelect("question_{$n}", "{$n}. {$questions[$i]}", $opts);
          
          if ( strpos($questions[$i], "(describe)") !== false){
            //print_r("found it!");
            //die();
            $this->addTextElement("q_{$n}_description", "$this->indent Description: ");
            $this->XINRegisterRule(
              "q_{$n}_description", 
              array("question_{$i}{@}=={@}sometimes", "question_{$i}{@}=={@}very_true"),
              "Required",
              "describe_group"
              );
          }
        }
      }

    function _page6(){
              $this-> addLabel("<h2>IX. Below is a list of items that describe people. For each item please select \"Not True\", \"Somewhat or Sometimes True\", or \"Very True or Often True\" to describe yourself <i>over the past 6 months.</i> Plase answer all items as well as you can, even if some do not seem to apply to you. </h2>");

              $this-> addLabel("56.Physical problems <i><b>without know medical cause:</b></i>");
              $questions=[
                "a. Aches or pains (<i><b>not</b></i> stomach or headaches)",
                "b. Headaches",
                "c. Nausea, feel sick",
                "d. Problems with eyes (<i><b>not</b></i> if corrected by glasses (describe))",
                "e. Rashes or other skin problems",
                "f. Stomachaches",
                "g. Vomiting, throwing up",
                "h. Heart pounding or racing",
                "i Numbmess or tingling in body parts"
              ];

               $opts = array(null=> "", 
          "not_true" => "Not True",
          "sometimes" => "Somewhat or Sometimes True",
          "very_true" => "Very True or Often True");

                    for ($i = 0; $i<count($questions); $i++){
          //$this->addLabel("{$questions[$i]}");
          $n = $i+1;
          $this->addSelect("question_{$n}", "{$questions[$i]}", $opts);
          
          if ( strpos($questions[$i], "(describe)") !== false){
            //print_r("found it!");
            //die();
            $this->addTextElement("q_{$n}_description", "$this->indent Description: ");
            $this->XINRegisterRule("
              q_{$n}_description", 
              array("question_{$i}{@}=={@}sometimes", "question_{$i}{@}=={@}very_true"),
              "Required",
              "describe_group"
              );
          }
        }
         $questions=[
                "I physically attack people",
                "I pick my skin or other parts of my body (describe)",
                "I fail to finish the things I should do",
                "There is very little I enjoy",
                "My work performance is poor",
                "I am poorly coordinated or clumsy",
                "I would rather be with older poeple than with people my own age",
                "I have trouble setting priorities",
                "I refuse to talk",
                "I repeat certain acts over and over (describe)",
                "I have trouble making or keeping friends",
                "I scream or yell a lot",
                "I am secretitve or keep things to myself",
                "I see things that other people think aren't there (describe)",
                "I am self-conscious or easily embarrassed",
                "I worry about my family",
                "I meet my responsibilites to my family",
                "I show off or clown"
              ];
                    for ($i = 0; $i<count($questions); $i++){
          //$this->addLabel("{$questions[$i]}");
          $n = $i+57;
          $this->addSelect("question_{$n}", "{$n}.  {$questions[$i]}", $opts);
          
          if ( strpos($questions[$i], "(describe)") !== false){
            //print_r("found it!");
            //die();
            $this->addTextElement("q_{$n}_description", "$this->indent Description: ");
            $this->XINRegisterRule("
              q_{$n}_description", 
              array("question_{$i}{@}=={@}sometimes", "question_{$i}{@}=={@}very_true"),
              "Required",
              "describe_group"
              );
          }
        }

    }
    function _page7(){
      $this-> addLabel("<h2>IX. Below is a list of items that describe people. For each item please select \"Not True\", \"Somewhat or Sometimes True\", or \"Very True or Often True\" to describe yourself <i>over the past 6 months.</i> Plase answer all items as well as you can, even if some do not seem to apply to you. </h2>");
      $questions=[
                "I am too shy or timid",
                "My behavior is irresponsible",
                "I sleep more than most other people during day and/or night (describe)",
                "I have trouble making decisions",
                "I have speeck problem (describe)",
                "I stand up for my rights",
                "My behavior is very changeable",
                "I steal",
                "I am easily bored",
                "I do things that other people think are strange (describe)",
                "I have thoughts that other people would think are strange (describe)",
                "I am stubborn, sullen, or irritable",
                "My moods or feelins change suddenly",
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
          "not_true" => "Not True",
          "sometimes" => "Somewhat or Sometimes True",
          "very_true" => "Very True or Often True");

                    for ($i = 0; $i<count($questions); $i++){
          //$this->addLabel("{$questions[$i]}");
          $n = 75 + $i;
          $this->addSelect("question_{$n}", "{$n}.  {$questions[$i]}", $opts);
          
          if ( strpos($questions[$i], "(describe)") !== false){
            //print_r("found it!");
            //die();
            $this->addTextElement("q_{$n}_description", "$this->indent Description: ");
            $this->XINRegisterRule("
              q_{$n}_description", 
              array("question_{$i}{@}=={@}sometimes", "question_{$i}{@}=={@}very_true"),
              "Required",
              "describe_group"
              );
          }
        }

    }

function _page8(){
  $this-> addLabel("<h2>IX. Below is a list of items that describe people. For each item please select \"Not True\", \"Somewhat or Sometimes True\", or \"Very True or Often True\" to describe yourself <i>over the past 6 months.</i> Plase answer all items as well as you can, even if some do not seem to apply to you. </h2>");
      $questions=[
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
                "I  keep from getting involved with others",
                "I worry alot",
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

               $opts = array(null=> "", 
          "not_true" => "Not True",
          "sometimes" => "Somewhat or Sometimes True",
          "very_true" => "Very True or Often True");

                    for ($i = 0; $i<count($questions); $i++){
          //$this->addLabel("{$questions[$i]}");
          $n = 96 + $i;
          $this->addSelect("question_{$n}", "{$n}.  {$questions[$i]}", $opts);
          
          if ( strpos($questions[$i], "(describe)") !== false){
            //print_r("found it!");
            //die();
            $this->addTextElement("q_{$n}_description", "$this->indent Description: ");
            $this->XINRegisterRule("
              q_{$n}_description", 
              array("question_{$i}{@}=={@}sometimes", "question_{$i}{@}=={@}very_true"),
              "Required",
              "describe_group"
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
}




