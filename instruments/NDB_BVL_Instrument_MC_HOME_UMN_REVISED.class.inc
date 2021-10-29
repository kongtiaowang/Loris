<?php
/**
 * This file contains the NDB_BVL_Instrument_MC_HOME_UMN_REVISED class
 *
 * PHP Version 7
 *
 * @category Instrument
 * @package  MC_HOME_UMN_REVISED
 * @author   Suzanne Lee <suzannelee.mcin@gmail.com>
 * @license  http://www.gnu.org/licenses/gpl-3.0.txt GPLv3
 * @link     https://www.github.com/aces/IBIS/
 */

/**
 * Creates the form elements for the MC_HOME_UMN_REVISED instrument
 *
 * @category Instrument
 * @package  MC_HOME_UMN_REVISED
 * @author   Suzanne Lee <suzannelee.mcin@gmail.com>
 * @license  http://www.gnu.org/licenses/gpl-3.0.txt GPLv3
 * @link     https://www.github.com/aces/IBIS/
 */
class NDB_BVL_Instrument_MC_HOME_UMN_REVISED extends NDB_BVL_Instrument
{
    use instrument_validator;

    use LegacyInstrumentTrait;

    var $ValidityEnabled  = false;
    var $ValidityRequired = false;

    var $scoreLabels = array(
	    "routine_and_responsibility"        =>  "ROUTINES AND RESPONSIBILITY",
	    "emotional_need"                    =>  "EMOTIONAL NEEDS",
	    "learning_behavior"                 =>  "LEARNING BEHAVIOR",
	    "recreational_activity"             =>  "RECREATIONAL ACTIVITIES",
	    "place_or_travel"                   =>  "PLACES/TRAVEL",
	    "family_friend"                     =>  "FAMILY AND FRIENDS",
	    "house"                             =>  "HOUSE",
	    "parent_child_interaction"          =>  "PARENT-CHILD INTERACTIONS",
	    "parent_visitor_interaction"        =>  "PARENT-VISITOR INTERACTIONS",
    			);

    CONST ROUTINES_AND_RESPONSIBILITY = ["q1_score","q11_score","q12_score","q13_score","q14_score","q15_score","q19_score"];

    CONST EMOTIONAL_NEEDS = ["q3_score","q20_score","q18_score","q21_score","q2_score"];

    CONST LEARNING_BEHAVIOR = ["q26_score","q4_score","q31_score","q27_score","q29_score","q30_score","q32_score"];

    CONST RECREATIONAL_ACTIVITIES = ["q34_score","q46_score","q35_score","q36_score","q37_score","q47_score"];

    CONST PLACES_TRAVEL = ["q39_score","q40_score","q44_score","q43_score","q41_score","q45_score"];

    CONST FAMILY_AND_FRIENDS = ["q48_score","q49_score","q50_score","q51_score","q42_score","q28_score"];

    CONST HOUSE = ["q22_score","q38_score","q33_score","q52_score","q53_score","q54_score","q55_score","q56_score","q57_score","q58_score","q59_score"];

    CONST PARENT_CHILD_INTERACTIONS = ["q5_score","q23_score","q7_score","q8_score","q6_score","q9_score","q24_score","q25_score","q16_score"];

    CONST PARENT_VISITOR_INTERACTIONS = ["q10_score","q17_score"];

    /**
     * Sample SQL statement for test_names table and instrument subtests table
     *
     * INSERT INTO test_names (Test_name, Full_name, Sub_Group, isDirectEntry) VALUES ('MC_HOME_UMN_REVISED', "HOME-MC University of Minnesota Revised Version", 1, 0);
     *
     * INSERT INTO instrument_subtests (Test_name, Subtest_name, Description, Order_number) VALUES ('MC_HOME_UMN_REVISED','MC_HOME_UMN_REVISED_page1', "Page 1", 1);
     * INSERT INTO instrument_subtests (Test_name, Subtest_name, Description, Order_number) VALUES ('MC_HOME_UMN_REVISED','MC_HOME_UMN_REVISED_page2', "Page 2", 2);
     * INSERT INTO instrument_subtests (Test_name, Subtest_name, Description, Order_number) VALUES ('MC_HOME_UMN_REVISED','MC_HOME_UMN_REVISED_page3', "Page 3", 3);
     * INSERT INTO instrument_subtests (Test_name, Subtest_name, Description, Order_number) VALUES ('MC_HOME_UMN_REVISED','MC_HOME_UMN_REVISED_page4', "Page 4", 4);
     * INSERT INTO instrument_subtests (Test_name, Subtest_name, Description, Order_number) VALUES ('MC_HOME_UMN_REVISED','MC_HOME_UMN_REVISED_page5', "Page 5", 5);
     * INSERT INTO instrument_subtests (Test_name, Subtest_name, Description, Order_number) VALUES ('MC_HOME_UMN_REVISED','MC_HOME_UMN_REVISED_page6', "Page 6", 6);
     * INSERT INTO instrument_subtests (Test_name, Subtest_name, Description, Order_number) VALUES ('MC_HOME_UMN_REVISED','MC_HOME_UMN_REVISED_page7', "Page 7", 7);
     * INSERT INTO instrument_subtests (Test_name, Subtest_name, Description, Order_number) VALUES ('MC_HOME_UMN_REVISED','MC_HOME_UMN_REVISED_page8', "Page 8", 8);
     * INSERT INTO instrument_subtests (Test_name, Subtest_name, Description, Order_number) VALUES ('MC_HOME_UMN_REVISED','MC_HOME_UMN_REVISED_page9', "Page 9", 9);
     *
     * INSERT INTO test_battery (Test_name, AgeMinDays, AgeMaxDays, Active, Stage, SubprojectID, Visit_label, CenterID) VALUES ('MC_HOME_UMN_REVISED', '0', '0', 'Y', 'Visit', '9', 'VSA', NULL);
     * INSERT INTO test_battery (Test_name, AgeMinDays, AgeMaxDays, Active, Stage, SubprojectID, Visit_label, CenterID) VALUES ('MC_HOME_UMN_REVISED', '0', '0', 'Y', 'Visit', '10', 'VSA', NULL);
     * INSERT INTO test_battery (Test_name, AgeMinDays, AgeMaxDays, Active, Stage, SubprojectID, Visit_label, CenterID) VALUES ('MC_HOME_UMN_REVISED', '0', '0', 'Y', 'Visit', '1', 'VSA', NULL);
     * INSERT INTO test_battery (Test_name, AgeMinDays, AgeMaxDays, Active, Stage, SubprojectID, Visit_label, CenterID) VALUES ('MC_HOME_UMN_REVISED', '0', '0', 'Y', 'Visit', '2', 'VSA', NULL);
     * INSERT INTO test_battery (Test_name, AgeMinDays, AgeMaxDays, Active, Stage, SubprojectID, Visit_label, CenterID) VALUES ('MC_HOME_UMN_REVISED', '0', '0', 'Y', 'Visit', '3', 'VSA', NULL);
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
    function setup(?string $commentID = null, ?string $page = null): void
    {
        $this->formType = "XIN";
        $this->form     = new LorisForm('MC_HOME_UMN_REVISED_form');
        $this->page     = $page;            // page label (number or
        // string - used by
        // user-defined child classes)

        // set the object properties
        // Corresponds to the Test_name column in test_names table
        $this->testName = "MC_HOME_UMN_REVISED";
        // name of database table corresponding to instrument
        $this->table = 'MC_HOME_UMN_REVISED';
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
                                    "q1",
                                    "q3",
                                    "q26",
                                    "q34",
                                    "q39",
                                    "q48",
                                    "q22",
                                    "q5",
                                    "q10",
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
        if (preg_match("/MC_HOME_UMN_REVISED(_page[0-9]+)/", $this->page, $matches)) {
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
        $this->addHeader("HOME-MC University of Minnesota Revised Version");

        $config =& NDB_Config::singleton();

        $dateOptions = array(
                        'language'         => 'en',
                        'format'           => 'YMd',
                        'minYear'          => $config->getSetting('startYear'),
                        'maxYear'          => $config->getSetting('endYear'),
                        'addEmptyOption'   => true,
                        'emptyOptionValue' => null,
                       );

        $this->addBasicDate('Date_taken', 'Date Taken', $dateOptions);

        // automatically adds examiner & date of administration
<<<<<<< HEAD
        $this->_addMetadataFields();
=======
	$this->_addMetadataFields();

	$this->addSelect("ira_completed_for_this_visit","IRA completed for this visit", array(null => "", "yes" => "Yes", "no" => "No"));

	$this->form->addElement("text","ira_percentage","IRA (Percentage)");

	$this->form->addElement("header",null, "Score Summary");

        $group[] = $this->form->createElement('static',null, "Score", null);       
	$this->form->addGroup($group, "subscale_score_group", "Subscale", $this->_GUIDelimiter, false);
        unset($group);

	foreach($this->scoreLabels as $field => $label){
            
            $group[] = $this->form->createElement('static', $field, null, null);
            $this->form->addGroup($group, "{$field}_score_group", "$label:", $this->_GUIDelimiter, false);
            unset($group);
	}

	$this->form->addFormRule(array(&$this, 'validate_main_page'));
>>>>>>> 3df773dd9... add scoring, fix error
    }

    /**
     * Generates the first page of the form.
     *
     * @return void
     */
    function _page1()
    {
        // display test name
        $this->addHeader("HOME-MC University of Minnesota Revised Version");

        $this->form->addElement("static", null, "Please tell us about your family and who lives in your home (use the family’s response to this question to tailor how you ask questions related to family members).");

        $this->form->addElement("static", null, "Researchers will also note if responses include connection with other people over virtual means (vs. in-person).");

        $this->form->addElement(
            'static',
            'lorisSubHeader',
            '<h3>ROUTINES AND RESPONSIBILITY</h3>'
        );

        $this->form->addElement("static", null, "<i>We will start out by asking some questions about things that happen on a typical day for the family and tasks ____ does around the home. Note to staff: Questions are listed in the order that they were asked (numbers are not chronological). YES/NO indicate how the data are coded into LORIS (and are synonymous with plus (yes) and minus (no)).</i>");

        $this->form->addElement("static", null, "<br/>");

        $score_options = array(
                          null           => "",
                          "yes"          => "+ (YES)",
                          "no"           => "- (NO)",
                          "missing_data" => "Missing data - describe reason in text box",
                         );

        // Q1, 11-15, 19
        $page1_question_prompts = array(
                                   "q1"  => "1. Can you tell me what a typical day looks like for you? Do you have regular times for certain things like meals, homework, or bedtime?",
                                   "q11" => "11. Getting all the housework done can be quite a challenge with time stretched so thin. That sometimes means kids have to pitch in and help. Is _______ responsible for any selfcare tasks? Things like showering, getting dressed, or brushing hair?",
                                   "q12" => "12. Is _______ responsible for keeping living and play areas clean?",
                                   "q13" => "13. Is _______ responsible for putting clothing away?",
                                   "q14" => "14. Are there general household rules? (Bedtime? Homework time? Screen time?)",
                                   "q15" => "15. Thinking about the rules that we just talked about, how strict or lenient is your family about enforcing these rules? What happens if a rule is broken?",
                                   "q19" => "19. Some families use physical punishment. This can look very different from family to family. Did you ever have to use physical punishment with _____ within the past month? How many times would you say that happened last month?",
                                  );

        $page1_score_descriptions = array(
                                     "q1"  => "+ Any indication of a predictable schedule (YES)<br>- No indication of a predictable schedule (NO)",
                                     "q11" => "+ Parent encourages child to do at least 3 selfcare tasks routinely. (YES)<br>- Parent does NOT encourage child to do at least three selfcare tasks. (If child just does selfcare tasks on their own, this is still a minus.) (NO)",
                                     "q12" => "+ Parent encourages child to clean at least ONE living/play space routinely. (YES)<br>- Parent does NOT encourage child to clean at least ONE living/play space. (If child just cleans living/play space on their own, this is still a minus.) (NO)",
                                     "q13" => "+ Parent encourages child to pick up at least ONE type of clothing routinely. (YES)<br>- Parent does NOT encourage child to put clothing away. (If child just does this on their own, this is still a minus.) (NO)",
                                     "q14" => "+ Parents have at least ONE clear limit (YES)<br>- Parents do NOT have at least ONE clear limit (NO)",
                                     "q15" => "+ Parent has set consequences for rules that are broken OR parent says child has not broken any rules yet, but can still describe hypothetical response if they do. (YES)<br>- Parent does not have set consequences OR parents differ in the extent that they enforce rules OR there are NO rules. (NO)",
                                     "q19" => "+ 0 or 1 physical punishments minimal (YES)<br>- 2+  physical punishments (were physical punishments minimal) (NO)",
                                    );

        foreach ($page1_question_prompts as $q => $prompt) {
            $this->addSelect($q . "_score", $this->indent . "Score:<h6>" . $page1_score_descriptions[$q] . "<br>Missing data - describe reason in text box</h6>", $score_options);
	    $this->addTextAreaElement($q, $prompt);
	    $this->form->addElement("static", null, "<br/>");
        }
    }

    /**
     * Generates the second page of the form.
     *
     * @return void
     */
    function _page2()
    {
        // display test name
        $this->addHeader("HOME-MC University of Minnesota Revised Version");

        $this->form->addElement(
            'static',
            'lorisSubHeader',
            '<h3>EMOTIONAL NEEDS</h3>'
        );

        $this->form->addElement("static", null, "<i>These next questions ask about feelings. Note to staff: Questions are listed in the order that they were asked (numbers are not chronological). YES/NO indicate how the data are coded into LORIS (and are synonymous with plus (yes) and minus (no)).</i>");

        $this->form->addElement("static", null, "<br/>");

        $score_options = array(
                          null           => "",
                          "yes"          => "+ (YES)",
                          "no"           => "- (NO)",
                          "missing_data" => "Missing data - describe reason in text box",
                         );

        // Q3, 20, 18, 21, 2
        $page2_question_prompts = array(
                                   "q3"  => "3. Tell me a couple of things ____ has done in the past week that pleased you (i.e., a week from day of interview)? What did you do when ____ did that?",
                                   "q20" => "20. Sometimes kids get upset or have opinions that differ from their parents. Maybe they call you a name or get sassy. If ______ does this to you, how would you handle it? If parent says child would never do that, ask: How would you handle it if ______ did?",
                                   "q18" => "18. Sometimes, children do things that annoy or frustrate us. In the past week (i.e., a week from day of interview), have you ever lost your temper with _______ and let it show? How often would you say that happened in the last week? What did you do when you lost your temper?",
                                   "q21" => "21. Sometimes life gets emotional, and we cry. Has that happened to you within the past week (i.e., a week from day of interview)? Did _____ see you when this happened?",
                                   "q2"  => "2. Most children ____’s age have things they are afraid of such as the dark, being left alone, or big dogs. Have you ever had to help____ work through something that is scary for him/her?
            What did you do to help ___ work through that? If parent insists the child has none, ask: What would you do if ____ was afraid of something?",
                                  );

        $page2_score_descriptions = array(
                                     "q3"  => "+ Parent HAS praised child at least 2x in past week (YES)<br>-Parent has NOT praised child at least 2x (NO)",
                                     "q20" => "+ Parent responds appropriately (YES)<br>-Parent responds with harsh comment or harsh punishment (NO)",
                                     "q18" => "+ 0 – 1 minimal expressions of anger TO child in past week (YES)<br>- 2+ expressions of anger TO child in past week (NO)",
                                     "q21" => "+ 0-1 cried last week in front of child (YES)<br>- 2+ cries last week in front of child (NO)",
                                     "q2"  => "+ Tolerance (helps child work through it or allows something like a night light) (YES)<br>- Intolerance (says the child is just being silly, does not offer help to child or says they do not believe in coddling that way) (NO)",
                                    );

        foreach ($page2_question_prompts as $q => $prompt) {
            $this->addSelect($q . "_score", $this->indent . "Score:<h6>" . $page2_score_descriptions[$q] . "<br>Missing data - describe reason in text box</h6>", $score_options);
	    $this->addTextAreaElement($q, $prompt);
	    $this->form->addElement("static", null, "<br/>");
        }
    }

    /**
     * Generates the third page of the form.
     *
     * @return void
     */
    function _page3()
    {
        // display test name
        $this->addHeader("HOME-MC University of Minnesota Revised Version");

        $this->form->addElement(
            'static',
            'lorisSubHeader',
            '<h3>LEARNING BEHAVIOR</h3>'
        );

        $this->form->addElement("static", null, "<i>These next questions ask about things in the house that ____ has access to. Note to staff: Questions are listed in the order that they were asked (numbers are not chronological). YES/NO indicate how the data are coded into LORIS (and are synonymous with plus (yes) and minus (no)).</i>");

        $this->form->addElement("static", null, "<br/>");

        $score_options = array(
                          null           => "",
                          "yes"          => "+ (YES)",
                          "no"           => "- (NO)",
                          "missing_data" => "Missing data - describe reason in text box",
                         );

        // Q26, 4, 31, 27, 29, 30, 32
        $page3_question_prompts = array(
                                   "q26" => "26. Do you find time to read things like the newspaper, magazines, books, or online news on a daily basis? Does _____ see you when you read these? If parent says they read on their phone but aren’t sure if child knows, then ask child \"Do you see ___ reading news?\"",
                                   "q4"  => "4. Does ___ like to read? Do you like for ____ to read at home, or do you think ____ reads enough at school? Does ____ do this on their own, or do you try to encourage it?",
                                   "q31" => "31. Does ____ have access to at least ten books in the home that match his/her reading level?",
                                   "q27" => "27. Kids are often asking their parents what a word means. Does _______ have access to a dictionary or some other tool (like Siri or Google) for learning a word at home? Do you ever ask or encourage ____ to look up words him/herself using one of those tools?",
                                   "q29" => "29. Does _____ have access to some kind of music device like a tape recorder, CD, radio, iPod, iPad, MP3, or music streaming? Can _______ use it by him/herself?",
                                   "q30" => "30. Does____ have access to any musical instruments?",
                                   "q32" => "32. Observation or Does ____ have a desk or other place of their own, appropriate for doing homework?",
                                  );

        $page3_score_descriptions = array(
                                     "q26" => "+ 1+ learning material read daily by at least one parent AND child can see this behavior (YES)<br>- No reading material OR child does not see (NO)",
                                     "q4"  => "+ Parent encourages child to read (YES)<br>- Parent does not encourage (NO)",
                                     "q31" => "+ At least 10 appropriate books present in the home (YES)<br>- Less than 10 appropriate books (NO)",
                                     "q27" => "+ Child has access to a dictionary or a different tool (Siri, Alexa, Google) AND parent encourages child to use them (YES)<br>- Not available OR child is not encouraged (e.g., “we have a dictionary but I usually just tell them the word”) (NO)",
                                     "q29" => "+ Child has access at least ONE device AND child can use independently (YES)<br>- No device OR child cannot use independently (NO)",
                                     "q30" => "+ Child has access to a real instrument in the home (YES)<br>- No instrument OR instrument is NOT real OR instrument is NOT in the house (recorder does NOT count) (NO)",
                                     "q32" => "+ Child has a specific and appropriate space (YES)<br>- No designated appropriate space (NO)",
                                    );

        foreach ($page3_question_prompts as $q => $prompt) {
            $this->addSelect($q . "_score", $this->indent . "Score:<h6>" . $page3_score_descriptions[$q] . "<br>Missing data - describe reason in text box</h6>", $score_options);
	    $this->addTextAreaElement($q, $prompt);
	    $this->form->addElement("static", null, "<br/>");
        }
    }

    /**
     * Generates the fourth page of the form.
     *
     * @return void
     */
    function _page4()
    {
        // display test name
        $this->addHeader("HOME-MC University of Minnesota Revised Version");

        $this->form->addElement(
            'static',
            'lorisSubHeader',
            '<h3>RECREATIONAL ACTIVITIES</h3>'
        );

        $this->form->addElement("static", null, "<i>These next questions ask about activities you do as a family. Note to staff: Questions are listed in the order that they were asked (numbers are not chronological). YES/NO indicate how the data are coded into LORIS (and are synonymous with plus (yes) and minus (no)).</i>");

        $this->form->addElement("static", null, "<br/>");

        $score_options = array(
                          null           => "",
                          "yes"          => "+ (YES)",
                          "no"           => "- (NO)",
                          "missing_data" => "Missing data - describe reason in text box",
                         );

        // Q34, 46, 35, 36, 37, 47
        $page4_question_prompts = array(
                                   "q34" => "34. Let’s start by talking about TV/screen-time. Is there a TV or screens in the house? Can you tell me about TV or screen-time usage in your family? If parent response does not tell amount of time tv is left on, ask: Are there specific times that the TV is turned on, or does the TV typically run in the background?",
                                   "q46" => "46. We just asked about TV in the previous question. Do you ever sit and watch with ________? Do you ever have conversations with ____ about things you watch together on TV?",
                                   "q35" => "35. Does _______ have any hobbies? Does ______ ask you for help or support for his/her hobbies (like maybe for money to buy things for a train collection)? What do you do when _______ asks?",
                                   "q36" => "36. Now, how about hobbies for the whole family... Do you have any family hobbies like camping, fishing, bowling, or gardening? Does ________ participate in these family hobbies?",
                                   "q37" => "37. Does ____take lessons of any sort in an activity s/he likes? Like karate, dance, music, or gymnastics? Does _______ have a membership at a community center or program like the YMCA or the Boys and Girls club?",
                                   "q47" => "47. Does ____ like to (ride a bike, skate, play ball)? If the answer is in the affirmative, ask: Did you teach or help ___ learn to do those activities?",
                                  );

        $page4_score_descriptions = array(
                                     "q34" => "+ Any scheduling limits to TV or screen-time (YES)<br>- No TV or screen-time or the TV or screens is left on for long periods of time (NO)",
                                     "q46" => "+ Parent discusses TV programs by engaging in back and forth conversation with child (YES)<br>- No indication of back and forth conversation (NO)",
                                     "q35" => "+ Parents encourages or sustains child’s hobbies (does not include sports) (YES)<br>- Family does not encourage or sustain child’s hobbies (NO)",
                                     "q36" => "+ Family has hobbies AND child and at least one parent are included (YES)<br>- No hobbies OR no parent is included OR child is not included; picnics do NOT count (NO)",
                                     "q37" => "+ Child has membership or lessons (YES)<br>- None (NO)",
                                     "q47" => "+ Parent teaches child advanced motor skills or provides lessons/means for child to learn (YES)<br>- No (NO)",
                                    );

        foreach ($page4_question_prompts as $q => $prompt) {
            $this->addSelect($q . "_score", $this->indent . "Score:<h6>" . $page4_score_descriptions[$q] . "<br>Missing data - describe reason in text box</h6>", $score_options);
	    $this->addTextAreaElement($q, $prompt);
	    $this->form->addElement("static", null, "<br/>");
        }
    }

    /**
     * Generates the fifth page of the form.
     *
     * @return void
     */
    function _page5()
    {
        // display test name
        $this->addHeader("HOME-MC University of Minnesota Revised Version");

        $this->form->addElement(
            'static',
            'lorisSubHeader',
            '<h3>PLACES/TRAVEL</h3>'
        );

        $this->form->addElement("static", null, "<i>These next questions ask about places ____ regularly goes to or has been. Note to staff: Questions are listed in the order that they were asked (numbers are not chronological). YES/NO indicate how the data are coded into LORIS (and are synonymous with plus (yes) and minus (no)).</i>");

        $this->form->addElement("static", null, "<br/>");

        $score_options = array(
                          null           => "",
                          "yes"          => "+ (YES)",
                          "no"           => "- (NO)",
                          "missing_data" => "Missing data - describe reason in text box",
                         );

        // Q39, 40, 44, 43, 41, 45
        $page5_question_prompts = array(
                                   "q39" => "39. Does the family have a public library card? Do you ever take ___ to the public library? How often do you take ______ to a public library?",
                                   "q40" => "40. How about a museum. Has a family member taken _____ to a museum within the past year? If parent were not the ones who took child, ask how they were involved with next question: Did you help arrange this trip for _______?",
                                   "q44" => "44. Has a family member ever taken ____ to a concert or play? If parent were not the ones who took child, ask how they were involved with next question: Did you help arrange this trip for _______?",
                                   "q43" => "43. Do you or the other parent take ________ with you when running errands like paying bills, repairing a car, getting dry cleaning? How often would you say this happens with ___?",
                                   "q41" => "41. Does your family do much traveling? When was the last time your family traveled? How did you get there? About how far was that?",
                                   "q45" => "45. Prompt from #41 should get at this",
                                  );

        $page5_score_descriptions = array(
                                     "q39" => "+ Family has a card AND takes child to the library once per month (YES)<br>- Family has NO card OR takes child to library less than once per month (NO)",
                                     "q40" => "+ Child has been taken  at least once in past year arranged by parent (not a school trip) (YES)<br>- No visit to museum in last year OR not arranged by parent (NO)",
                                     "q44" => "+ Child has been to a musical/theater performance in lifetime arranged by parent (YES)<br>- No OR not arranged by parent (NO)",
                                     "q43" => "+ Child accompanies parent on a business venture that is located in the community at least THREE times within past year (YES)<br>- Less than 3 times (NO)",
                                     "q41" => "+ Family member has taken child on a plane, car, train, or bus trip arranged by parent at least ONCE within past year (Not a school trip) (YES)<br>- No trip in last year (NO)",
                                     "q45" => "+ Family member has taken child on 50+ mile trip (any transportation, but not arranged by school) (YES)<br>- No (NO)",
                                    );

        foreach ($page5_question_prompts as $q => $prompt) {
            $this->addSelect($q . "_score", $this->indent . "Score:<h6>" . $page5_score_descriptions[$q] . "<br>Missing data - describe reason in text box</h6>", $score_options);
	    $this->addTextAreaElement($q, $prompt);
	    $this->form->addElement("static", null, "<br/>");
        }
    }

    /**
     * Generates the sixth page of the form.
     *
     * @return void
     */
    function _page6()
    {
        // display test name
        $this->addHeader("HOME-MC University of Minnesota Revised Version");

        $this->form->addElement(
            'static',
            'lorisSubHeader',
            '<h3>FAMILY AND FRIENDS</h3>'
        );

        $this->form->addElement("static", null, "<i>These next questions ask about time spent with friends and family members. Note to staff: Questions are listed in the order that they were asked (numbers are not chronological). YES/NO indicate how the data are coded into LORIS (and are synonymous with plus (yes) and minus (no)).</i>");

        $this->form->addElement("static", null, "<br/>");

        $score_options = array(
                          null           => "",
                          "yes"          => "+ (YES)",
                          "no"           => "- (NO)",
                          "missing_data" => "Missing data - describe reason in text box",
                         );

        // Q48, 49, 50, 51, 42, 28
        $page6_question_prompts = array(
                                   "q48" => "48. Does ______ spend time with a father figure/other parent? Do they do any activities together? How often do they do activities together?",
                                   "q49" => "49. How many days of the week does ______ see and spend time his/her dad (or other parent)?",
                                   "q50" => "50. Does ____ eat with you and the other parent at least once a day? About how many dinners?",
                                   "q51" => "51. Does your family today consist of the same people who have been there throughout ____'s life? Or in other words, has ____ ever lost anyone close to him/her? Has _____ ever lived with anyone else or been in foster care for a time?",
                                   "q42" => "42. Does your family have any relatives or friends nearby? How often do you see them?",
                                   "q28" => "28. Does _____ have any friends that they have seen in the past week?",
                                  );

        $page6_score_descriptions = array(
                                     "q48" => "+ A father figure/other parent regularly engages in at least ONE activity a week with child (YES)<br>- A father figure/other parent does not engage with child (NO)",
                                     "q49" => "+ Father/other parent spends time with child at least FOUR days a week (YES)<br>- Father/other parent does NOT spend time with child at least four days a week OR there is NO father figure/second parent in child’s life. (NO)",
                                     "q50" => "+ Child generally eats at least ONE meal/day with the parent(s) in their household AND dinner absence of parent(s) is not more than once (2 or more days = minus) (YES)<br>- Child generally does NOT eat one meal/day together with the parent(s) in their household OR dinner absence of either parent(s) is more than 2 days (NO)",
                                     "q51" => "+ No changes in mother, father, grandparents, or other caregiver since birth (YES)<br>- Child has been in foster care, has been sent away to a special school, parents have divorced, parent or grandparent has died, or parent has had a prolonged absence due to job (one month or more). (NO)",
                                     "q42" => "+ Family visits OR receives visits from relatives/friends at least TWICE a month, generally (YES)<br>- No visits or not at least twice per month (NO)",
                                     "q28" => "+ Yes, in the past week (YES)<br>- No, or not in past week (NO)",
                                    );

        foreach ($page6_question_prompts as $q => $prompt) {
            $this->addSelect($q . "_score", $this->indent . "Score:<h6>" . $page6_score_descriptions[$q] . "<br>Missing data - describe reason in text box</h6>", $score_options);
	    $this->addTextAreaElement($q, $prompt);
	    $this->form->addElement("static", null, "<br/>");
        }
    }

    /**
     * Generates the seventh page of the form.
     *
     * @return void
     */
    function _page7()
    {
        // display test name
        $this->addHeader("HOME-MC University of Minnesota Revised Version");

        $this->form->addElement(
            'static',
            'lorisSubHeader',
            '<h3>HOUSE</h3>'
        );

        $this->form->addElement("static", null, "These next questions ask about the house. Note to staff: Questions are listed in the order that they were asked (numbers are not chronological). YES/NO indicate how the data are coded into LORIS (and are synonymous with plus (yes) and minus (no)).");

        $this->form->addElement("static", null, "<br/>");

        $score_options = array(
                          null           => "",
                          "yes"          => "+ (YES)",
                          "no"           => "- (NO)",
                          "missing_data" => "Missing data - describe reason in text box",
                         );

         // Q22, 38, 33, 52, 53, 54, 55, 56, 57, 58, 59
        $page7_question_prompts = array(
                                   "q22" => "22. Does ______ have a special place to keep these things that are special to him/her like treasures, souvenirs, or toys?",
                                   "q38" => "38. What about outdoor play in your neighborhood. Is there a playground nearby where ______ can play on swings, climb bars, or throw a ball?",
                                   "q33" => "33. Observation - If not observed during session, ask: Do you guys have any art work around the house?",
                                   "q52" => "52. Observation - If not observed during session, ask: Tell me about _____'s room. Is it decorated in any special way? Are there pictures or wall decorations? Does ____ like his/her room?",
                                   "q53" => "53. Observation <i>(This should be observable on the interview where ever it is taking place)</i>",
                                   "q54" => "54. Observation – if not observed during session, ask: Do you feel like your house has enough space for everyone?",
                                   "q55" => "55. Observation Base this off of what is in view during the observation (even if you cannot observe the entire house)",
                                   "q56" => "56. Observation – if not observed during session, ask: Tell me a little bit about your home, how big is it? How many people live there?",
                                   "q57" => "57. Observation Base this off of what you can hear during the observation (even if you cannot observe the entire house)",
                                   "q58" => "58. Observation Base this off of what is in view during the observation (even if you cannot observe the entire house)",
                                   "q59" => "59. Does ___ have an outside play area? What is that like? Would you say it is safe for him/her?",
                                  );

        $page7_score_descriptions = array(
                                     "q22" => "+ Child has a special place (YES)<br>- Child does not have a special place (NO)",
                                     "q38" => "+ Yes, nearby that child can regularly go to (at least 2 playground equipment) (YES)<br>- No (NO)",
                                     "q33" => "+ 2+ pictures, posters, or wall hanging (not family photos) (YES)<br>- Less than 2 (NO)",
                                     "q52" => "+ Child’s room has a picture or wall decoration that the child likes (YES)<br>- No pictures or decoration the child likes (NO)",
                                     "q53" => "+ Appropriate light, decor, and effort to dress up home (YES)<br>- Lack of light, pictures, effort (NO)",
                                     "q54" => "+ Rooms allow area for movement and play and exits entrances are accessible (YES)<br>- Overcrowded, cluttered, lack of ability to move around. (NO)",
                                     "q55" => "+ Free of trash, clutter and visible dirt on walls or other areas (YES)<br>- Very dirty, abundance of cobwebs, clutter and trash (NO)",
                                     "q56" => "+ 100 square ft per person (YES)<br>- Less than 100sq ft per person (NO)",
                                     "q57" => "+ No more than general background noise (YES)<br>- Loud noise, trains, highways, subways (NO)",
                                     "q58" => "+ The living space appears safe (YES)<br>- A Major safety hazard. Open gas fires in a small home, and the presence of bleach, cleaning fluids, and other poisons within easy reach of a small child, and blocked exists (NO)",
                                     "q59" => "+ Safe play area (YES)<br>- No play area or the area has hazardous broken glass laying around, junk cars abandoned in the yard or along the side of the street, open ditches of a house so close to a street that a child could not safely play in the yard, and boards with nails sticking out of them. (NO)",
                                    );

        foreach ($page7_question_prompts as $q => $prompt) {
            $this->addSelect($q . "_score", $this->indent . "Score:<h6>" . $page7_score_descriptions[$q] . "<br>Missing data - describe reason in text box</h6>", $score_options);
	    $this->addTextAreaElement($q, $prompt);
	    $this->form->addElement("static", null, "<br/>");
        }
    }

    /**
     * Generates the eighth page of the form.
     *
     * @return void
     */
    function _page8()
    {
        // display test name
        $this->addHeader("HOME-MC University of Minnesota Revised Version");

        $this->form->addElement(
            'static',
            'lorisSubHeader',
            '<h3>PARENT-CHILD INTERACTIONS</h3>'
        );

        $this->form->addElement("static", null, "Note to staff: Questions are listed in the order that they were asked (numbers are not chronological). YES/NO indicate how the data are coded into LORIS (and are synonymous with plus (yes) and minus (no)).");

        $this->form->addElement("static", null, "<br/>");

        $score_options = array(
                          null           => "",
                          "yes"          => "+ (YES)",
                          "no"           => "- (NO)",
                          "missing_data" => "Missing data - describe reason in text box",
                         );

        // Q5, 23, 7, 8, 6, 9, 24, 25, 16
        $page8_question_prompts = array(
                                   "q5"  => "5. Observation",
                                   "q23" => "23. Observation",
                                   "q7"  => "7. Observation",
                                   "q8"  => "8. Observation",
                                   "q6"  => "6. Observation<br><i>Interviewer offers praise about the child to the parent</i>",
                                   "q9"  => "9. Observation",
                                   "q24" => "24. Observation",
                                   "q25" => "25. Observation",
                                   "q16" => "16. Observation",
                                  );

        $page8_score_descriptions = array(
                                     "q5"  => "+ Parent urges/asks child to say something at least ONE time (YES)<br>- Parent provides NO opportunities for child to contribute to the interview (NO)",
                                     "q23" => "+ At least 1 back and forth conversation (YES)<br>- No conversation (NO)",
                                     "q7"  => "+ Parent answers at least 1 child question or 5 instances of encouraging the child to participate in conversations (YES)<br>- Parent does not answer or brushes the child off (NO)",
                                     "q8"  => "+ Parent uses full sentences and some 2 syllable words (YES)<br>- No instances of rich language (NO)",
                                     "q6"  => "+ Parent responds positively (e.g., smiles, beams, hugs to child) or elaborates on praise (YES)<br>- Parent says no more than “thank you” without positive nonverbal responses, parent is embarrassed, parent is unsure/hesitant about the praise, parent ignores praise (NO)",
                                     "q9"  => "+ Overall parent conveys positivity towards the child (YES)<br>- Parent displays an overall lack of positivity (no smiling, or laughing towards the child, flat tone) (NO)",
                                     "q24" => "+ Demonstrates term of endearment at least 2 times (YES)<br>- Less than 2 terms of endearment (NO)",
                                     "q25" => "+ No annoyance or hostility towards the child (YES)<br>- Hostility or annoyance shown (NO)",
                                     "q16" => "+ Parent introduces child to us and introduces us to child (YES)<br>- Parent does not do an introduction (NO)",
                                    );

        foreach ($page8_question_prompts as $q => $prompt) {
            $this->addSelect($q . "_score", $this->indent . "Score:<h6>" . $page8_score_descriptions[$q] . "<br>Missing data - describe reason in text box</h6>", $score_options);
	    $this->addTextAreaElement($q, $prompt);
	    $this->form->addElement("static", null, "<br/>");
        }
    }

    /**
     * Generates the ninth page of the form.
     *
     * @return void
     */
    function _page9()
    {
        // display test name
        $this->addHeader("HOME-MC University of Minnesota Revised Version");

        $this->form->addElement(
            'static',
            'lorisSubHeader',
            '<h3>PARENT-VISITOR INTERACTIONS</h3>'
        );

        $this->form->addElement("static", null, "Note to staff: Questions are listed in the order that they were asked (numbers are not chronological). YES/NO indicate how the data are coded into LORIS (and are synonymous with plus (yes) and minus (no)).");

        $this->form->addElement("static", null, "<br/>");

        $score_options = array(
                          null           => "",
                          "yes"          => "+ (YES)",
                          "no"           => "- (NO)",
                          "missing_data" => "Missing data - describe reason in text box",
                         );

        // Q10, 17
        $page9_question_prompts = array(
                                   "q10" => "10. Observation",
                                   "q17" => "17. Observation",
                                  );

        $page9_score_descriptions = array(
                                     "q10" => "+ Parent asks a question or makes a comment without any prompting from visitor (YES)<br>- Parent does not ask any questions or make any comments (i.e., parent only talks when visitor asks parent interview questions) (NO)",
                                     "q17" => "+ Courteous (YES)<br>- Rude or uninviting in any way (NO)",
                                    );

        foreach ($page9_question_prompts as $q => $prompt) {
            $this->addSelect($q . "_score", $this->indent . "Score:<h6>" . $page9_score_descriptions[$q] . "<br>Missing data - describe reason in text box</h6>", $score_options);
	   $this->addTextAreaElement($q, $prompt);
	    $this->form->addElement("static", null, "<br/>");
        }
    }
<<<<<<< HEAD
}
=======

    //sum response 

    function sumScaleScores($question_array, $record)
    {
        $sum = 0;

        foreach ($question_array as $q) {
            if ($record[$q] == "yes") {
                $sum += 1;
            }
        }

        return $sum;
    }

    function score(): void
    {
        if ($this->_determineDataEntryCompletionStatus() == "Incomplete") {
            return;
        }
        //null scores
        //$this->_nullScores($this->scoreLabels);

        //get the saved scores
        $db     = Database::singleton();
        $query  = "SELECT * FROM $this->table WHERE CommentID =:cid";
        $record = $db->pselectRow($query, array('cid' => $this->commentID));
	$scores  = array(
	        "routine_and_responsibility"        =>  0,
                "emotional_need"                    =>  0,
                "learning_behavior"                 =>  0,
                "recreational_activity"             =>  0,
                "place_or_travel"                   =>  0,
                "family_friend"                     =>  0,
                "house"                             =>  0,
                "parent_child_interaction"          =>  0,
                "parent_visitor_interaction"        =>  0,
	
	);
      
	$scores["routine_and_responsibility"] = $this->sumScaleScores(self::ROUTINES_AND_RESPONSIBILITY, $record);
	$scores["emotional_need"] = $this->sumScaleScores(self::EMOTIONAL_NEEDS, $record);
	$scores["learning_behavior"] = $this->sumScaleScores(self::LEARNING_BEHAVIOR, $record);
	$scores["recreational_activity"] = $this->sumScaleScores(self::RECREATIONAL_ACTIVITIES, $record);
	$scores["place_or_travel"] = $this->sumScaleScores(self::PLACES_TRAVEL, $record);
	$scores["family_friend"] = $this->sumScaleScores(self::FAMILY_AND_FRIENDS, $record);
	$scores["house"] = $this->sumScaleScores(self::HOUSE, $record);
	$scores["parent_child_interaction"] = $this->sumScaleScores(self::PARENT_CHILD_INTERACTIONS, $record);
	$scores["parent_visitor_interaction"] = $this->sumScaleScores(self::PARENT_VISITOR_INTERACTIONS, $record);

	$result = $db->update($this->table, $scores, array("CommentID" => $this->getCommentID()));
    }

    function validate_main_page($values)
    {
         $errors = [];
       if(!is_numeric($values["ira_percentage"])){

	       $errors["ira_percentage"] = "Please enter numeric value";
       }

	 return $errors;
    }

}
>>>>>>> 3df773dd9... add scoring, fix error
