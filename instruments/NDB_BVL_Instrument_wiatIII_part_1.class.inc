<?php
/**
 * This file contains the NDB_BVL_Instrument_wiatIII
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
 * Creates the form elements for the wiatIII instrument
 *
 * @category Instrument
 * @package  Neuropsych
 * @author   Leo Thomas <lthomas.mcin@gmail.com>
 * @license  http://www.gnu.org/licenses/gpl-3.0.txt GPLv_
 * @link     https://www.github.com/aces/
 */
require_once('NDB_BVL_Instrument_wiatIII.class.inc');
class NDB_BVL_Instrument_wiatIII_part_1 extends NDB_BVL_Instrument_wiatIII
{

    var $scoreLabels = array(
        "receptive_vocabulary_raw_score",
        "oral_discourse_comprehension_raw_score",
        "early_reading_skills_total_raw_score",
        "grade_1_item_set_total_raw_score",
        "grade_2_item_set_total_raw_score",
        "grade_3_item_set_total_raw_score",
        "grade_4_item_set_total_raw_score",
        "grade_5_item_set_total_raw_score",
        "grade_6_item_set_total_raw_score",
        "grade_7_item_set_total_raw_score",
        "grade_8_item_set_total_raw_score",
        "grade_9_12_item_set_total_raw_score",
        "math_problem_solving_total_raw_score",
        "alphabet_writing_fluency_raw_score",
        "sentence_combining_raw_score",
        "sentence_building_raw_score",
        "word_reading_total_raw_score",
        "word_reading_speed_total_raw_score",
        "word_reading_total_3",
        "word_reading_total_SC",

    );
    //abstract function setup($commentID, $page);
    /**
     * sets up basic data, such as the LorisForm object, and so on.
     *
     * @param string $commentID  the CommentID identifying the data to load
     * @param string $page       if a multipage form, the page to show
     * @return void
     * @access public
     */
    function setup($commentID, $page){
        $this->formType="XIN";
        $this->form = new LorisForm('test_form');
        $this->page = $page;            // page label (number or

        // set the object properties
        $this->testName = "wiatIII_part_1";           // test_names.Test_name
        $this->table = 'wiatIII_part_1';


        // data keyed by commentID
        $this->commentID = $commentID;
        $config =& NDB_Config::singleton();
        $this->dateOptions = array(
            'language' => 'en',
            'format'   => 'YMd',
            'minYear'  => $config->getSetting('startYear'),
            'maxYear'  => $config->getSetting('endYear'),
            'addEmptyOption' => true,
            'emptyOptionValue' => null
        );

        // setup the form
        $this->_setupForm();

    }
    /**
     * method to build the LorisForm object into a paged form
     *
     * @return void
     * @access private
     */
    function _setupForm(){

        if(preg_match("/wiatIII_part_1(_page[0-9]+)/",$this->page,$matches)){
            call_user_func(array($this, $matches[1]));
        } else {
            $this->_main();
        }

        //Defines the call back function for HTML Quickform to use when validating the form.
        $this->form->addFormRule(array(&$this,'XINValidate'));
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
        $this->addHeader("WIAT-III- PART 1");
        $this->_addMetadataFields();
        $this->addBasicDate('Date_taken', 'Date of Administration', $this->dateOptions);
        $grades=array(null=> " ",
            "PK" => "PK",
            "K" => "K",
            "1" => "1",
            "2" => "2",
            "3" => "3",
            "4" => "4",
            "5" => "5",
            "6" => "6",
            "7" => "7",
            "8" => "2",
            "9" => "9",
            "10" => "10",
            "11" => "11",
            "12" => "12"
        );
        $this->addTextElement("student_name", "Student Name: ");
        $this->addTextElement("school", "School: ");
        $this->addTextElement("examiner_name", "Examiner: ");
        $this->addTextElement("sex", "Sex: ");
        $this->addSelect('grade', 'Grade', $grades);
        $this->addDateElement("test_date", "Test Date: ");
        $this->addDateElement("birth_date", "Birth Date: ");
        $this->addDateElement("test_age", "Test Age: ");
        $this->addLabel("*Reminder: do not round up to next month or year");

    }
    function score() {
        if($this->_determineDataEntryCompletionStatus() == "Incomplete") {
            return;
        }
        //null scores
        $this->_nullScores($this->scoreLabels);
        $db =& Database::singleton();
        // Get the item scores
        $record= $db->pselectRow("SELECT * FROM $this->table WHERE CommentID=:cid", array('cid'=>$this->getCommentID()));
        $score = array();
        $scores["receptive_vocabulary_raw_score"]=$this->_rawScoreCalculatorRule(1,19,4, "LC_score");
        $scores["oral_discourse_comprehension_raw_score"]=$this->_rawScoreCalculatorRule(1,27,4, "oral_discourse");
        $scores["early_reading_skills_total_raw_score"]=$this->_rawScoreCalculator(1,34, "early_reading_");
        $scores["grade_1_item_set_total_raw_score"]=$this->_rawScoreCalculator(1,18, "reading_comprehension_");
        $scores["grade_2_item_set_total_raw_score"]=$this->_rawScoreCalculator(5,24, "reading_comprehension_");
        $scores["grade_3_item_set_total_raw_score"]=$this->_rawScoreCalculator(11,31, "reading_comprehension_");
        $scores["grade_4_item_set_total_raw_score"]=$this->_rawScoreCalculator(25,45, "reading_comprehension_");
        $scores["grade_5_item_set_total_raw_score"]=$this->_rawScoreCalculator(32,53, "reading_comprehension_");
        $scores["grade_6_item_set_total_raw_score"]=$this->_rawScoreCalculator(38,59, "reading_comprehension_");
        $scores["grade_7_item_set_total_raw_score"]=$this->_rawScoreCalculator(46,67, "reading_comprehension_");
        $scores["grade_8_item_set_total_raw_score"]=$this->_rawScoreCalculator(54,75, "reading_comprehension_");
        $scores["grade_9_12_item_set_total_raw_score"]=$this->_rawScoreCalculator(60,84, "reading_comprehension_");
        $scores["math_problem_solving_total_raw_score"]=$this->_rawScoreCalculatorRule(1,72,4, "math_problem");
        $scores["alphabet_writing_fluency_raw_score"]=$this->_rawScoreCalculator(1,25, "wf_");
        $scores["semantics_grammar_raw_score1"]=$this->_rawScoreCalculatorRule(1,5,2, "SC_semantics_grammar");
        $scores["mechanics_score1"]=$this->_rawScoreCalculatorRule(1,5,2, "SC_mechanics_score");
        $scores["extra_credits_raw_score1"]=$this->_rawScoreCalculatorRule(1,5,2, "SC_extra_credit");
        $scores["sentence_combining_raw_score"]=$scores["semantics_grammar_raw_score1"]+ $scores["mechanics_score1"]+$scores["extra_credits_raw_score1"];
        $scores["semantics_grammar_raw_score2"]=$this->_rawScoreCalculatorRule(1,7,2, "SB_semantics_grammar");
        $scores["mechanics_score2"]=$this->_rawScoreCalculatorRule(1,7,2, "SB_mechanics_score");
        $scores["sentence_building_raw_score"]=$scores["semantics_grammar_raw_score2"]+ $scores["mechanics_score2"];
        $scores["word_reading_total_raw_score"]=$this->_rawScoreCalculatorRule(1,75,4, "WR_score_");
        $scores["word_reading_total_3"]=$this->_rawScoreCalculator(1,75, "WR_3_");
        $scores["word_reading_total_SC"]=$this->_rawScoreCalculator(1,75,"WR_SC_");
        $result = $db->update($this->table, $scores, array('CommentID'=>$this->getCommentID()));
    }
    /**
     * Page 1
     *
     * @return void
     */
    // page1 => Listening Comprehension
    function _page1()
    {
        $this->addHeader("WIAT-III- PART1");
        $this->addLabel("<h1>Listening Comprehension</h1>");
        $this->addLabel("<h2>1. Receptive Vocabulary (Grades PK-12+)</h2>");
        $this->addLabel("Discontinue Rule: Discontinue after 4 consecutive scores of 0.");
        $this->addLabel("Note: Start points and rules are considered for scoring.");
        $group[] =& $this->form->createElement("static", null, null, "Item");
        $group[] =& $this->form->createElement("static", null, null, "Response");
        $group[] =& $this->form->createElement("static", null, null, "Score");
        $opts = array(null=> " ",
            "a" => "A",
            "b" => "B",
            "c" => "C",
            "d" => "D");
        $score = array(null => "",
            "dk"=>"DK",
            "1" => "1",
            "0" => "0");
        $this->form->addGroup(
            $group,
            "listening_table{0}",
            null,
            $this->_GUIDelimiter,
            false
        );
        unset($group);
        $q1 = "1. Say, Empty. Point to the picture that says shows empty";
        $group[] =& $this->form->createElement("static", null, null, $q1);
        $group[] =& $this->form->createElement("select", "LC_response1", null, $opts);
        $group[] =& $this->form->createElement("select", "LC_score1", null, $score);
        $this->form->addGroup(
            $group,
            "listening_table{1}",
            null,
            $this->_GUIDelimiter,
            false
        );
        unset($group);
        $this->XINRegisterRule(
            "LC_response1",
            array("LC_response1{@}=={@}NEVER_REQUIRED"), // rule
            "Required.", // message
            "listening_table{1}" // group [if field is a part of a group]
        );
        $this->XINRegisterRule(
            "LC_score1",
            array("LC_score1{@}=={@}NEVER_REQUIRED"), // rule
            "Required.", // message
            "listening_table{1}" // group [if field is a part of a group]
        );

        $questions=[
            "jar",
            "pair",
            "doze",
            "pen",
            "festive",
            "exhausted",
            "identical",
            "canine",
            "astounded",
            "currency",
            "descending",
            "ravine",
            "tethered",
            "pinnacle",
            "opaque",
            "solitary",
            "bucolic",
            "ponderous"
        ];
        for ($i = 0; $i<count($questions); $i++){
            $n = 2 + $i;
            $group[] =& $this->form->createElement("static", null, null, "{$n}. Say, (Point to) '{$questions[$i]}'.");
            $group[] =& $this->form->createElement("select", "LC_response{$n}", null, $opts);
            $group[] =& $this->form->createElement("select", "LC_score{$n}", null, $score);
            $this->form->addGroup(
                $group,
                "listening_table{$n}",
                null,
                $this->_GUIDelimiter,
                false
            );
            unset($group);
            $this->XINRegisterRule(
                "LC_response{$n}",
                array("LC_response{$n}{@}=={@}NEVER_REQUIRED"), // rule
                "Required.", // message
                "listening_table{$n}" // group [if field is a part of a group]
            );
            $this->XINRegisterRule(
                "LC_score{$n}",
                array("LC_score{$n}{@}=={@}NEVER_REQUIRED"), // rule
                "Required.", // message
                "listening_table{$n}" // group [if field is a part of a group]
            );

        }
        $this->addLabel("<h2>2. Oral Discourse Comprehension</h2>");
        $this->addLabel("Reverse Rule: If score of 0 on first three item given, administer preceding items in reverse order until 3 consecutive score of 1. ");
        $this->addLabel("Discontinue Rule: Discontinue after 4 consecutive scores of 0.");
        $this->addLabel("Note: Start points and rules are considered for scoring.");
        $opts = array(null => "",
            "dk" => "DK",
            "1" => "1",
            "0" => "0");
        $group[]=& $this->form->createElement("static", null, null, "Question");
        $group[]=& $this->form->createElement("static", null, null, "Correct Answer");
        $group[]=& $this->form->createElement("static", null, null, "Score");
        $this->form->addGroup(
            $group,
            "discourse_table{0}",
            null,
            $this->_GUIDelimiter,
            false
        );
        unset($group);
        $questions = [
            ["Grades PK-3<br>T2 - 1: Where does the bird sing?","In the tree"],
            ["T3 - 2: Who is running?","The boy"],
            ["T4 - 3: When was it raining","This morning"],
            ["T5 - 4: What do the people want to plant?","A tree"],
            ["T6 - 5: what did Lee see first?","A duck. (If the student says, \"Water\" Q: Tell me more )"],
            ["Grades 4-12+<br>T7 - 6: What day is Sally visiting Grandma?","Sunday/Tomorrow"],
            ["T8 - 7: What does Jackie have to do before she goes to the animal shelter?","Get her parents' permissions; Ask her parents"],
            ["T9 - 8: Why did Amy want to climb the tree?","To get her kitten; To save the kitten; To rbing down her cat; Her kitten is in the tree; Other similar response"],
            ["T9 - 9: What reason did Amy's grandfather giver her for not climbing the tree?","(He said) her kitten will come down when she's ready"],
            ["T10 - 10: What do you get free?","Mug(s)/ Cups(s)"],
            ["T11 - 11: Name two of the animal shown on the mugs.","Names at least two of the following: Gorilla, Kangaroo, Giraffe, Lion. (If only one correct animal is named: Q: Tell me another animal shown on the mugs.)"],
            ["T12 - 12: Which animal did Richard see last?","Horse(s)"],
            ["T13 - 13: Which sport does Julie most like to watch on television?","Soccer"],
            ["T14 - 14: How many cutouts do you need to send in to get a free pass?","Three"],
            ["T15 - 15: After you send in the cutout, what is the longest time you will have to wait for the free pass?","Four weeks"],
            ["T16 - 16: What is the first even Troy's family goes to on the Fourth of July?","Parade"],
            ["T17 - 17: Name two advantages given for the proposed building.","Names at least two of the following, using the comparative terms listed: Closer to a major highway; More efficient heating and cooling; Better insulated; Better parking.","(If comparative terms are not used (e.g. the student says, \"Good parking\"), Q: Name two advantages that make the proposed building better than the current one.)"],
            ["T18 - 18: What office if Gerald running for?","(Class) vice-president"],
            ["T19 - 19: To Gerald, what is the most important reason for running for office?","Experience (for the future)","(If the student says, \"he want to be in politics (in the future)\", Q: Tell me more)"],
            ["T20 - 20: What advantage does walking have over running?","No stress on the (the walker's) joints"],
            ["T21 - 21: Besides health, what is one reason given in support of walking?","Requires no expensive equipment / clothing; Can be done at any time of day; Can be done in almost any place.","(If the student says, \"(Walking) is good exercise\" Q: Name one reason why)","(If the student gives a health-related reason, repeat the question, emphasizing \"Besides...\")"],
            ["T22 - 22: What is the first book in the series about?","Runners/ Running"],
            ["T23 - 23: How much do you have to spend before you get the free item?","Seven ninety-five / Seven dollars and ninety-five cents"],
            ["T24 - 24: In what direction would Ms. Franklin be traveling for most of the train trip she wants to win?","East / Towards Toronto"],
            ["T25 - 25: By how much did unemployment change in one month, and in what direction?","Decreased by three-quarters of one percent","(If the student only says, \"(It) decreased\" Q: And by how much did unemployment change in one month?)","(If the student only says, \"By three-quarters of one percents,\" Q: And in what direction did unemployment change in one month?)"],
            ["T26 - 26: What effect did students ahve on unemployment in one month?","Their return to school created job opportunities / made more jobs available"],
            ["T27 - 27: In 1984, how many robots were produced in the United States?","More than five thousand."]
        ];
        for ($i = 0; $i<count($questions); $i++){
            $n = 1 + $i;
            $group[] =& $this->form->createElement("static", null, null, "{$questions[$i][0]}");
            $group[] =& $this->form->createElement("static", null, null, "{$questions[$i][1]}");
            $group[] =& $this->form->createElement("select", "oral_discourse{$n}", null, $opts);
            $this->form->addGroup(
                $group,
                "discourse_table{$n}",
                null,
                $this->_GUIDelimiter,
                false
            );
            unset($group);
            $this->XINRegisterRule(
                "oral_discourse{$n}",
                array("oral_discourse{$n}{@}=={@}NEVER_REQUIRED"), // rule
                "Required.", // message
                "discourse_table{$n}" // group [if field is a part of a group]
            );
        }
        $this->addLabel("<h2>Raw Scores:</h2>");
        $this->addScoreColumn("receptive_vocabulary_raw_score", "Receptive Vocabulary Raw Score");
        $this->addScoreColumn("oral_discourse_comprehension_raw_score", "Oral Discourse Comprehension Raw Score");
    }
    // page2 => Early Reading Skills
    function _page2(){
        $grade=$this->_getGradeCandidate();
        $include_grades_array= array("PK","K",1,2,3);
        if (!in_array($grade, $include_grades_array)) {
            $this->form->addElement("static", null, '<font color="Red">This test is not applicable for Grade '.$grade.' Candidate. Please skip this test.</font>');
        }
        $this->addHeader("Early Reading Skills");
        $this->addLabel("<h3>(Grades PK-3)</h3>");
        $this->addLabel("Note: Start points and rules are considered for scoring.");
        $opts = array(null => "",
            "dk" => "DK",
            "1" => "1",
            "0" =>"0");
        $group[] =& $this->form->createElement("static", null, "item", "Item");
        $group[] =& $this->form->createElement("static", null, "correct_answer", "Correct Answer");
        $group[] =& $this->form->createElement("static", null, "score", "Score") ;

        $this->form->addGroup(
            $group,
            "early_reading_table{0}",
            null,
            $this->_GUIDelimiter,
            false
        );
        unset($group);
        $group[] =& $this->form-> createElement("static", null, null, "To administer items 1-6, say \"Tell me the names of these letters.\" Point to each letter, in order, as the student reads. If the student provides the correct letter sound, rather than the letter name, say, \"Yes, but what is the name of this letter?\"");
        $this->form->addGroup(
            $group,
            "early_reading_table{0}",
            null,
            $this->_GUIDelimiter,
            false
        );
        unset($group);
        $questions= [
            ["Grades PK-3<br>1. (O) o"],
            ["2. (O) s"],
            ["3. (O) z"],
            ["4. (O) e"],
            ["5. (O) w"],
            ["6. (O) m"],
            ["7. (O) a"],
            ["8. (O) u"],
            ["9. (O) d"],
            ["10. (O) g"],
            ["11. (O) b"]
        ];
        for ( $i=0; $i<count($questions); $i++){
            $n = $i +1;
            $group[] =& $this->form->createElement("static", null, null,"{$questions[$i][0]}");
            $group[] =& $this->form->createElement("select", "early_reading_{$n}", "", $opts);
            $this->form->addGroup(
                $group,
                "early_reading_table{$n}",
                null,
                $this->_GUIDelimiter,
                false
            );
            unset($group);
            $this->XINRegisterRule(
                "early_reading_{$n}",
                array("early_reading_{$n}{@}=={@}"), // rule
                "Required.", // message
                "early_reading_table{$n}" // group [if field is a part of a group]
            );
        }

        $questions = [
            ["12. Say, \"Here are some letters. Which letter makes the \a\ sound like in apple?\" Ecourange the student to point", "(P) a"],
            ["13. Say, \"Which letter makes the \g\ sound like in gate?\" Encourage the student to point", "(P) g"],
            ["14. Say, \"Listen to these three different words. Two of them rhyme. Which one does not rhyme with the others?\". Point to the corresponding picture as you say each word: \"Hat, mat, sun\". You may repeat the three words at the students request", "(P or O) Sun"],
            ["15. Say, \"This time there are no pictures. Just listen. Fish, duck, dish. Which one does not rhyme with the others?\"", "(O) Duck"],
            ["16. Say, \"Now, tell me a word that rhymes with fly\"", "(O) Any rhyming word/nonword (e.g., sky, kie"],
            ["17. Say, \"Tell me a word that rhymes with star\"", "(0) Any rhyming word/nonword (e.g., far, lar)"],
            ["18. Say, \"Let's think about the beginning sounds now\". Point to the corresponding picture as you say each word. \"Here are a bat, bike, and truck. Which two words begin with the same sound?\"", "(P or O, any order) Bat, Bike"],
            ["19. Say, \"Lets try another one. Listen.\" Point to the corresponding on picture as you say each word \"Man, van, mud. Which two words beging with the same sound?\"", "(P or O, any order) Man, Mud"],
            ["20. Say, \"Listen.\" Point to the corresponding picture as you say each word: \"Flag, frog, freeze. Which two words begin with the same two sounds?\"", "(P or O, any order) Frog, Freeze"],
            ["21. Say, \"Listen.\" Point to the corresponding picture as you say each world: \"Clock, cat, clip. Which two words begin with the same two sounds?\"", "(P or O, any order) Clock, Clip"],
            ["22. Say, \"This time listen for ending sounds that are alike.\" Point to the corresponding picture as you say each word: \"Clip, plum, drip. Which two words end with the same sounds?\"", "(P or O, any order) Clip, Drip"],
            ["23. Say, \"Again, listen for ending sounds that are alike.\" Point to the corresponding picture as you say each word: \"Fish, clock, duck. Which two words end with the same sound?\"", "(P or O, any order) Clock, Duck"],
            ["24. Say, \"This time there are no pictures. I am going to say a word in two parts. Listen carefully to the parts, then put them together to make a word\" (Pause for 1 second between the two word parts). \"Listen: \p\ \an\. What is the word?\"", "(O) Pan"],
            ["25. Say, \"Put these parts together to make a word.\" (Pause for 1 second between the two word parts).\"Listen: \m\ \op\. What is the wor?d\"", "(O) Mop"],
            ["26. Say, \"Put these parts together to make a word.\" (Pause for 1 second between the two word parts).\"Listen: \sh\ \ell\. What is the wor?d\" ", "(O) Shell"],
            ["27. Say, \"Here are some letter groups. Which letter group makest he \sh\ sound like in ship?\" Encourage the student to point. ", "(O) sh"],
            ["28. Say, \"Which letter group makes the \st\ sounds like in stop?\"", "(O) st"],
            ["29. Say, \"Which letter group makes the \dr\ sounds like in drop? \"", "(O) dr"],
            ["30. Say, \"Point to the picture that matches this word.\" Point to the word green, but do not read it aloud.", "(P) Green crayon"],
            ["31. Say, \"Point to the picture that matches this word.\" Point to the word on, but do not read it aloud.", "(P) Ball on top of box"],
            ["32. Say, \"Point to the picture that matches these words.\" Point to the words red box, but do not read it aloud.", "(P) Red box"],
            ["33. Say, \"Point to the picture that matches this word.\" Point to the word ball, but do not read it aloud.", "(P) Ball"],
            ["34. Say, \"Point to the picture that matches these words.\" Point to the words two fish, but do not read it aloud.", "(P) Fish bowl with two fish"]
        ];
        for ( $i=0; $i<count($questions);$i++){
            $n = $i +12;
            $group[] =& $this->form->createElement("static", null,null,"{$questions[$i][0]}");
            $group[] =& $this->form->createElement("static", null, null, "{$questions[$i][1]}");
            $group[] =& $this->form->createElement("select","early_reading_{$n}", "", $opts);
            $this->form->addGroup(
                $group,
                "early_reading_table{$n}",
                null,
                $this->_GUIDelimiter,
                false
            );
            unset($group);
            $this->XINRegisterRule(
                "early_reading_{$n}",
                array("early_reading_{$n}{@}=={@}"), // rule
                "Required.", // message
                "early_reading_table{$n}" // group [if field is a part of a group]
            );
        }
        $this->addLabel("<h2>Raw Score:</h2>");
        $this->addScoreColumn("early_reading_skills_total_raw_score", "Early Reading Skills Total Raw Score");

    }
    // page3 => reading comprehension
    function _page3(){
        $grade=$this->_getGradeCandidate();
        $exclude_grades_array= array("PK","K");
        if (in_array($grade, $exclude_grades_array)) {
            $this->form->addElement("static", null, '<font color="Red">This test is not applicable for Grade '.$grade.' Candidate. Please skip this test.</font>');

        }
        $this->addHeader("Reading Comprehension");
        $this->addLabel("Item Set Reverse Rule.");
        $this->addLabel("Note: Start points and rules are considered for scoring.");
        $this->addLabel("<h2>The frog</h2> (grade 1)");
        $opts3 = array(null => "",
            "dk" => "DK",
            "2"=> "2",
            "1"=> "1",
            "0"=>"0"
        );
        $opts2 = array(null => "",
            "dk" => "DK",
            "2"=> "2",
            "0"=>"0"
        );
        $questions = [
            ["1. What color was the frog?", "Red with black (spots); Red and black", "Red"],
            ["2. What scared the frog?", "(It saw) someone / me / the boy / the girl", "" ],
            ["3. Where did the frog hide?", "Under / Next to / By a tree", ""],
            ["4. What time of day is it in the story?", "Sunset; Sundown; End of day; Late in the day", "Daytime 0; Afternoon 0; Evening 0; Late 0"]
        ];
        $group[] =& $this->form->createElement("static", null, null, "Item");
        $group[] =& $this->form->createElement("static", null, null, "2-Point Responses");
        $group[] =& $this->form->createElement("static", null, null, "1-Point Responses");
        $group[] =& $this->form->createElement("static", null, null, "Score");

        $this->form->addGroup(
            $group,
            "RC1_table{0}",
            null,
            $this->_GUIDelimiter,
            false
        );
        unset($group);
        for ( $i=0; $i<count($questions);$i++){
            $n = $i +1;
            $k = $i +1;
            $group[] =& $this->form->createElement("static",null,null,"{$questions[$i][0]}");
            $group[] =& $this->form->createElement("static",null,null,"{$questions[$i][1]}");
            $group[] =& $this->form->createElement("static",null,null,"{$questions[$i][2]}");
            if ("{$questions[$i][2]}" == ""){
                $opts = $opts2;
            }else{
                $opts = $opts3;
            }
            $group[] =& $this->form->createElement("select","reading_comprehension_{$k}", "", $opts);
            $this->XINRegisterRule("reading_comprehension_{$k}",
                array("reading_comprehension_{$k}{@}=={@}NEVER_REQUIRED"));

            $this->form->addGroup(
                $group,
                "RC1_table{$n}",
                null,
                $this->_GUIDelimiter,
                false
            );
            unset($group);
        }
        $this->addLabel("<h2>Pet Day</h2> (grade 2)");
        $questions = [
            ["5. which animals can students bring to school on Pet Day?", "Name ALL of the followign: Dogs, Cats, Birds", "Names TWO of the following: Dogs, Cats, Birds"],
            ["6. Amy brought her bird to school on Pet Day. She walked into the classroom with the bird on her finger. Which rule did Amy not follow?", "(Pets/ The bird) must be in a cage", "She can't have the bird on her finger 0"],
            ["7. Richard wants to win the prize on Pet Day. What must happen for Richard to win?", "His pet must be (voted) the best;  They must like his pet", "He must bring a pet 0; He must follow the rules (e.g., bring one pet; use a leash)0"],
            ["8. On Pet Day, Joe brought his three cats to school in a cage. Which rule did Joe not follow?", "Only one pet / cat is allowed; Three pets / cats are not allowed", ""],
            ["9. Martin brought his cat in a cage. Jeff caried his cat in his arms. Which person did not follow the ruls?", "Jeff; The one who carried the cat / pet", ""],
            ["10. Lauren has a rabbit, a puppy, and a goldfish. Which pet is she allowed to bring on Pet Day?", "The puppy / dog"],
        ];
        $group[] =& $this->form->createElement("static", null, null, "Item");
        $group[] =& $this->form->createElement("static", null, null, "2-Point Responses");
        $group[] =& $this->form->createElement("static", null, null, "1-Point Responses");
        $group[] =& $this->form->createElement("static", null, null, "Score");
        $this->form->addGroup(
            $group,
            "RC2_table{0}",
            null,
            $this->_GUIDelimiter,
            false
        );
        unset($group);
        for ( $i=0; $i<count($questions);$i++){
            $n = $i +1;
            $k = $i +5;
            $group[] =& $this->form->createElement("static",null,null,"{$questions[$i][0]}");
            $group[] =& $this->form->createElement("static",null,null,"{$questions[$i][1]}");
            $group[] =& $this->form->createElement("static",null,null,"{$questions[$i][2]}");

            if ("{$questions[$i][2]}" == ""){
                $opts = $opts2;
            }else{
                $opts = $opts3;
            }
            $group[] =& $this->form->createElement("select","reading_comprehension_{$k}", "", $opts);
            $this->XINRegisterRule("reading_comprehension_{$k}",
                array("reading_comprehension_{$k}{@}=={@}NEVER_REQUIRED"));
            $this->form->addGroup(
                $group,
                "RC2_table{$n}",
                null,
                $this->_GUIDelimiter,
                false
            );
            unset($group);
        }
        $this->addLabel("<h2>Baobab Tree</h2> (grade 3)");
        $questions = [
            ["11. I what type of land does the Baobab tree grow?", "Dry, African land", "Desert/ Dry lands; Where elephants live; Africa"],
            ["12. What does the story say makes the Baobad tree a funny - or unusual-looking tree?", "Looks like its growing upside down; The branches look like roots", "Thin branches; Lots of branches"],
            ["13. What are the two ways that people use the Baobab tree?", "Refers to BOTH of the following: Storage, Shelter", "Refers to ONE of the following: Storage; Shelter"],
            ["14. When does the tree get leaves?", "When it rains", "Two times a year"],
            ["15. What causes the Baobab tree to become hollow on the inside?", "The wood inside rots away; Elephants dig holes in the tree / chew the wood", ""],
            ["16. How long can the Baobab tree live?", " More than 1,000 years", "1,000 years"],
            ["17. Why do elephants dig holes in the tree?", "To chew the wood", "They're hungry; To get food / water"],
            ["18. Which part of the Baobad tree does the story say people use?", "The trunk / stem; The inside", ""],
        ];
        $group[] =& $this->form->createElement("static", null, null, "Item");
        $group[] =& $this->form->createElement("static", null, null, "2-Point Responses");
        $group[] =& $this->form->createElement("static", null, null, "1-Point Responses");
        $group[] =& $this->form->createElement("static", null, null, "Score");


        $this->form->addGroup(
            $group,
            "RC3_table{0}",
            null,
            $this->_GUIDelimiter,
            false
        );
        unset($group);
        for ( $i=0; $i<count($questions);$i++){
            $n = $i + 1;
            $k = $i + 11;
            $group[] =& $this->form->createElement("static",null,null,"{$questions[$i][0]}");
            $group[] =& $this->form->createElement("static",null,null,"{$questions[$i][1]}");
            $group[] =& $this->form->createElement("static",null,null,"{$questions[$i][2]}");
            if ("{$questions[$i][2]}" == ""){
                $opts = $opts2;
            }else{
                $opts = $opts3;
            }
            $group[] =& $this->form->createElement("select","reading_comprehension_{$k}", "", $opts);
            $this->XINRegisterRule("reading_comprehension_{$k}",
                array("reading_comprehension_{$k}{@}=={@}NEVER_REQUIRED"));
            $this->form->addGroup(
                $group,
                "RC3_table{$n}",
                null,
                $this->_GUIDelimiter,
                false
            );
            unset($group);
        }
        $this->addLabel("<h2>Tidy Tamiko</h2>");
        $questions=[
            ["19. What does the story say Tamiko liked to do?", "Wash; Clean; Shine", ""],
            ["20. What was the last thing Tamiko did before she went to Toko Town?", " Cleaned the house; Made the house spotless", "Washed the dog"],
            ["21. How did Tamiko get to the stars", "A gust / The wind (carried her)", ""],
            ["22. Why are the stars brighter now than ever before?", "Tamiko cleaned / polished the stars / them", "Tamiko is there"],
            ["23. Which part of the story could not have happened in real life?", "Polishing the stars; The moon had a familiar smile; Cleaning the tow; Getting carried into the sky by wind; Washing the dog until its bald"],
            ["24. Why do people say the moon's smile is familiar?", "Tamiko is up there / in the sky/ on the moon; It reminds people of Tamiko; It looks like Tamiko / Tamiko's smile"] ,
        ];
        $group[] =& $this->form->createElement("static", null, null, "Item");
        $group[] =& $this->form->createElement("static", null, null, "2-Point Responses");
        $group[] =& $this->form->createElement("static", null, null, "1-Point Responses");
        $group[] =& $this->form->createElement("static", null, null, "Score");
        $this->form->addGroup(
            $group,
            "RC4_table{0}",
            null,
            $this->_GUIDelimiter,
            false
        );
        unset($group);
        for ( $i=0; $i<count($questions);$i++){
            $n = $i +1;
            $k = $i + 19;
            $group[] =& $this->form->createElement("static",null,null,"{$questions[$i][0]}");
            $group[] =& $this->form->createElement("static",null,null,"{$questions[$i][1]}");
            $group[] =& $this->form->createElement("static",null,null,"{$questions[$i][2]}");
            if ("{$questions[$i][2]}" == ""){
                $opts = $opts2;
            }else{
                $opts = $opts3;
            }
            $group[] =& $this->form->createElement("select","reading_comprehension_{$k}", "", $opts);
            $this->XINRegisterRule("reading_comprehension_{$k}",
                array("reading_comprehension_{$k}{@}=={@}NEVER_REQUIRED"));
            $this->form->addGroup(
                $group,
                "RC4_table{$n}",
                null,
                $this->_GUIDelimiter,
                false
            );
            unset($group);
        }

        $this->addLabel("<h2>Good Neighbors</h2> (Grade 4)");
        $questions=[
            ["25. In what country does the story take place?", "(Old) Korea", ""],
            ["26. What did the man want?", "To live by a large mountain; To make the mountain bigger", "The dragon's help; To move rocks / mud"],
            ["27. What made the dragon's lake larger?", "Carrying away mud / rocks (from the lake)", "Putting mud / rocks on the mountain; Carrying mud / rocks up the hill / mountain"],
            ["28. How did the dragon and the man help each other?", "Refers to BOTH of the following: The dragon helped the man make a larger mountain, The man helped the dragon make a larger lake", "Refers to ONE of the following: The dragon helped the man make a larger mountain; The man helped the dragon make a larger lake"],
            ["29. Which part of the story shows that the dragon and the man worked hard to finish the job quickly?", "They often worked in the rain; Soon the mountain was large", "They went up and down the mountain"],
            ["30. Why did the dragon thank the man?", "For helping him create a larger lake", "The dragon got a bigger lake"],
            ["31. What important lesson could be learned from this story?", "Refers to the rewards / mutual benefits of cooperation (e.g., If you help someone, you will get something too", "Refers to friendship or helping (e.g., You should help people / be friendly)"],
        ];
        $group[] =& $this->form->createElement("static", null, null, "Item");
        $group[] =& $this->form->createElement("static", null, null, "2-Point Responses");
        $group[] =& $this->form->createElement("static", null, null, "1-Point Responses");
        $group[] =& $this->form->createElement("static", null, null, "Score");
        $this->form->addGroup(
            $group,
            "RC5_table{0}",
            null,
            $this->_GUIDelimiter,
            false
        );
        unset($group);
        for ( $i=0; $i<count($questions);$i++){
            $n = $i +1;
            $k = $i + 25;
            $group[] =& $this->form->createElement("static",null,null,"{$questions[$i][0]}");
            $group[] =& $this->form->createElement("static",null,null,"{$questions[$i][1]}");
            $group[] =& $this->form->createElement("static",null,null,"{$questions[$i][2]}");
            if ("{$questions[$i][2]}" == ""){
                $opts = $opts2;
            }else{
                $opts = $opts3;
            }
            $group[] =& $this->form->createElement("select","reading_comprehension_{$k}", "", $opts);
            $this->XINRegisterRule("reading_comprehension_{$k}",
                array("reading_comprehension_{$k}{@}=={@}NEVER_REQUIRED"));
            $this->form->addGroup(
                $group,
                "RC5_table{$n}",
                null,
                $this->_GUIDelimiter,
                false
            );
            unset($group);
        }
        $this->addLabel("<h2>Toontime Trees</h2> (Grade 5)");
        $questions=[
            ["32. What word does the advertisement use to describe the cartoon characters?","Athletic; Famous",""],
            ["33. What type of 100% cotton is used to make these shirts?","Refers to BOTH of the following: Preshrunk, Premium-weight","Refers to ONE of the following: Preshrunk, Premium-weight"],
            ["34. What information is given in the advertisement about cleaning shirts?","Machine washable",""],
            ["35. What are the shirt sizes that can be ordered","Names ALL of the following: Extra-small, Small, Medium, Large",""],
            ["36. Why does the Ollie Owl shirt cost more than the other two shirts?","It's long sleeved",""],
            ["37. What other information would someone need to know in order to purchase one of these shirts" ,"Refers to any relevant purchasing information (e.g., Where to buy; How to order; Contact information)",""],
        ];
        $group[] =& $this->form->createElement("static", null, null, "Item");
        $group[] =& $this->form->createElement("static", null, null, "2-Point Responses");
        $group[] =& $this->form->createElement("static", null, null, "1-Point Responses");
        $group[] =& $this->form->createElement("static", null, null, "Score");

        $this->form->addGroup(
            $group,
            "RC6_table{0}",
            null,
            $this->_GUIDelimiter,
            false
        );
        unset($group);
        for ( $i=0; $i<count($questions);$i++){
            $n = $i +1;
            $k = $i + 32;
            $group[] =& $this->form->createElement("static",null,null,"{$questions[$i][0]}");
            $group[] =& $this->form->createElement("static",null,null,"{$questions[$i][1]}");
            $group[] =& $this->form->createElement("static",null,null,"{$questions[$i][2]}");
            if ("{$questions[$i][2]}" == ""){
                $opts = $opts2;
            }else{
                $opts = $opts3;
            }
            $group[] =& $this->form->createElement("select","reading_comprehension_{$k}", "", $opts);
            $this->XINRegisterRule("reading_comprehension_{$k}",
                array("reading_comprehension_{$k}{@}=={@}NEVER_REQUIRED"));
            $this->form->addGroup(
                $group,
                "RC6_table{$n}",
                null,
                $this->_GUIDelimiter,
                false
            );
            unset($group);
        }
        $this->addLabel("<h2>Science Fun</h2> (Grade 6)");
        $questions=[
            ["38. Besides colorful, which word best describes Gobbledeeglue?", "Refers to any of the following (or similar) words: Bouncy; Stretchy; Gooey; Rubbery", ""],
            ["39. What three ingredients must you have to make Goddledeeglue?", "Names ALL of the following: Borax, Glue, Water", "Names TWO of the following: Borax, Glue, Water"],
            ["40. Why must you do steps 1 and 2 before step 3?", "The glue and borax must dissolve (before step 3); The glue and borax must each be mixed with water (before step 3)", "It won't combine right"],
            ["41. How does step 4 change Gobbledeeglue?", "Adds color", ""],
            ["42. What is the next step after stirring in the food colouring?", "Refers to BOTH of the following: Put Gobbledeeglue on plastic, Leave it alone / Wait (for three minutes)", "Refers to ONE of the following: Put Gobbledeeglue on plastic; Leave it alone / Wait"],
            ["43. How long do you have to mix the borax and water with the glue and water?", "Three minutes", ""],
            ["44. What do you predict would happen if you skipped step 5?", "It would be liquid / watery; It would not stick together; It would not roll / bounce; You could not pick it up", ""],
            ["45. Which words in the passage say it is okay to touch Gobbledeeglue with your bare hands.", "Refers to any of the following directions: Pick it up; Set it down; Roll it.", ""],
        ];
        $group[] =& $this->form->createElement("static", null, null, "Item");
        $group[] =& $this->form->createElement("static", null, null, "2-Point Responses");
        $group[] =& $this->form->createElement("static", null, null, "1-Point Responses");
        $group[] =& $this->form->createElement("static", null, null, "Score");

        $this->form->addGroup(
            $group,
            "RC7_table{0}",
            null,
            $this->_GUIDelimiter,
            false
        );
        unset($group);
        for ( $i=0; $i<count($questions);$i++){
            $n = $i +1;
            $k = $i + 38;
            $group[] =& $this->form->createElement("static",null,null,"{$questions[$i][0]}");
            $group[] =& $this->form->createElement("static",null,null,"{$questions[$i][1]}");
            $group[] =& $this->form->createElement("static",null,null,"{$questions[$i][2]}");
            if ("{$questions[$i][2]}" == ""){
                $opts = $opts2;
            }else{
                $opts = $opts3;
            }
            $group[] =& $this->form->createElement("select","reading_comprehension_{$k}", "", $opts);
            $this->XINRegisterRule("reading_comprehension_{$k}",
                array("reading_comprehension_{$k}{@}=={@}NEVER_REQUIRED"));
            $this->form->addGroup(
                $group,
                "RC7_table{$n}",
                null,
                $this->_GUIDelimiter,
                false
            );
            unset($group);
        }
        $this->addLabel("<h2>How California Came to Be</h2> (Grade 7)");
        $questions=[
            ["46. According to the passage who is Kwawar?", "Great Spirit", "A god"],
            ["47. After Kwawar decided to create land what gave him the idea to use turtles?", "He saw a huge turtle swim by", ""],
            ["48. Name two things metioned in teh passage taht were there before Kwawar created land", "Names at least TWO of the following: Water, Eath, Bulrushes, Turtles, Kwawar", "Names ONE of the following: Water, Earth, Bulrushes, Turtles, Kwawar"],
            ["49. What did Kwawar do to grow trees?", "Put his fingers in the soil", ""],
            ["50. Why did the turtles try to move away from each other?", "The became restless; They were tired of staying in the same place", "They disagreed"],
            ["51. Why couldn't the Turtle Brothers move away from each other?", "The weight of the land (one their backs); The earth was too heavy", ""],
            ["52. What type fo natural disaster occurs when the Turtle Brothers disagree", "Earthquake(s), Land quake(s)", "The ground quivers/trembles"],
            ["53. According to the passage, what group of people probably began telling this story?", "Native Americans in California; Gabrielino people of California", "Native Americans, Indians"]
        ];
        $group[] =& $this->form->createElement("static", null, null, "Item");
        $group[] =& $this->form->createElement("static", null, null, "2-Point Responses");
        $group[] =& $this->form->createElement("static", null, null, "1-Point Responses");
        $group[] =& $this->form->createElement("static", null, null, "Score");

        $this->form->addGroup(
            $group,
            "RC8_table{0}",
            null,
            $this->_GUIDelimiter,
            false
        );
        unset($group);
        for ( $i=0; $i<count($questions);$i++){
            $n = $i +1;
            $k = $i + 46;
            $group[] =& $this->form->createElement("static",null,null,"{$questions[$i][0]}");
            $group[] =& $this->form->createElement("static",null,null,"{$questions[$i][1]}");
            $group[] =& $this->form->createElement("static",null,null,"{$questions[$i][2]}");

            if ("{$questions[$i][2]}" == ""){
                $opts = $opts2;
            }else{
                $opts = $opts3;
            }
            $group[] =& $this->form->createElement("select","reading_comprehension_{$k}", "", $opts);
            $this->XINRegisterRule("reading_comprehension_{$k}",
                array("reading_comprehension_{$k}{@}=={@}NEVER_REQUIRED"));
            $this->form->addGroup(
                $group,
                "RC8_table{$n}",
                null,
                $this->_GUIDelimiter,
                false
            );
            unset($group);
        }
        $this->addLabel("<h2>Yukon Gold</h2> (Grade 8)");
        $questions=[
            ["54. Name three dangers encountered by the family on their journey", "Refers to at least THREE of the followingL Outlaws, Robberty, Chilkoot Pass, Cold/Harsh wilderness, Grizzly (bear)", "Refers to TWO of the following: Outlaws, Robbery, Chilkoot Pass, Cold/Harsh wilderness, Grizzly (bear)"],
            ["55. According to Gary's review (point to the first review), what are the two main themes or ideas in Yukon Gold", "Refers to BOTH of the following: Wilderness adventure, Family Conflict", "Refers to ONE of the following: Wilderness adventure, Family Conflict"],
            ["56. According to Dianan's review (point to the second review), why doesn't Charlie want to go to Yukon", "He deesn't want to chase his father's dream; His goals/desires differ from his father's", "It wasn't his idea/goal/dream"],
            ["57. What did Gary (point to the first review) dislike about the movie","The story is hackneyed/ predictable; The ending is predictable/hold not surprises", "The ending"],
            ["58. Which part of Diana's review (point to the second review) says that the teenagers' fight for independence is not the main plot of the movie?", "Refers to 'buried within this exciting adventure tale' ", ""],
            ["59. How did the Jasso family travel to Yukon?","Refers to BOTH of the following: By boat/ship, On foot/hiking", "Refers to ONE of the following: By boat/ship, On foot/hiking"],

        ];
        $group[] =& $this->form->createElement("static", null, null, "Item");
        $group[] =& $this->form->createElement("static", null, null, "2-Point Responses");
        $group[] =& $this->form->createElement("static", null, null, "1-Point Responses");
        $group[] =& $this->form->createElement("static", null, null, "Score");

        $this->form->addGroup(
            $group,
            "RC9_table{0}",
            null,
            $this->_GUIDelimiter,
            false
        );
        unset($group);
        for ( $i=0; $i<count($questions);$i++){
            $n = $i +1;
            $k = $i + 54;
            $group[] =& $this->form->createElement("static",null,null,"{$questions[$i][0]}");
            $group[] =& $this->form->createElement("static",null,null,"{$questions[$i][1]}");
            $group[] =& $this->form->createElement("static",null,null,"{$questions[$i][2]}");

            if ("{$questions[$i][2]}" == ""){
                $opts = $opts2;
            }else{
                $opts = $opts3;
            }
            $group[] =& $this->form->createElement("select","reading_comprehension_{$k}", "", $opts);
            $this->XINRegisterRule("reading_comprehension_{$k}",
                array("reading_comprehension_{$k}{@}=={@}NEVER_REQUIRED"));
            $this->form->addGroup(
                $group,
                "RC9_table{$n}",
                null,
                $this->_GUIDelimiter,
                false
            );
            unset($group);
        }
        $this->addLabel("<h2>Word of Wisdom</h2> (Grade 9-12+)");
        $questions=[
            ["60. According to the passage, why do most people like proverbs?","Referes to ALL of the following: (They are) short, Easy to remember, (Accepted as) true","Referes to ONE of the following: (They are) short, Easy to remember, (Accepted as) true"],
            ["61. What were the oldest known proverbs written on?","Clay Tablets","Clay; Tablets"],
            ["62. Why did the author mentiona Benjamin Franklin in this passage?","He popularized many proverbs; He worte a book containing many proverbs","The wrote Poor Richard's Almanack"],
            ["63. Where do you think Ben Franklin found the proverbs he included in the Poor Richard's Alamanac","Refers to at least TWO of the following: Old records/ Books, (Older) People, Life Experiences/Traveling","Refers to at least ONE of the following: Old records/ Books, (Older) People, Life Experiences/Traveling"],
            ["64. Which part of the passage tells you that not all proverbs are very old?","'Not all proverbs are so old'; 'Old or new...', (Some proverbs) were created in the 1920s, 1950s, and/or in the computer age ","'A picture is worth a thousand words', 'Different strokes for different folks', 'Garbage in, garbage out'"],
            ["65. Why of the proverbs mentioned in the passage is a comment on computer technology?","'Garbage in, garbage out'",""],
            ["66. Which part of the passage tells you that proverbs are common in many different parts of the world?","'Human beings almost everywhere in the world have thought up and repeated proverbs'","Proverbs were found in Sumer"],
            ["67. What is the author's main message in the last paragraph (point to the last paragraph)?","The popularity of provers; Why people like proverbs",""]

        ];
        $group[] =& $this->form->createElement("static", null, null, "Item");
        $group[] =& $this->form->createElement("static", null, null, "2-Point Responses");
        $group[] =& $this->form->createElement("static", null, null, "1-Point Responses");
        $group[] =& $this->form->createElement("static", null, null, "Score");

        $this->form->addGroup(
            $group,
            "RC10_table{0}",
            null,
            $this->_GUIDelimiter,
            false
        );
        unset($group);
        for ( $i=0; $i<count($questions);$i++){
            $n = $i +1;
            $k = $i + 60;
            $group[] =& $this->form->createElement("static",null,null,"{$questions[$i][0]}");
            $group[] =& $this->form->createElement("static",null,null,"{$questions[$i][1]}");
            $group[] =& $this->form->createElement("static",null,null,"{$questions[$i][2]}");

            if ("{$questions[$i][2]}" == ""){
                $opts = $opts2;
            }else{
                $opts = $opts3;
            }
            $group[] =& $this->form->createElement("select","reading_comprehension_{$k}", "", $opts);
            $this->XINRegisterRule("reading_comprehension_{$k}",
                array("reading_comprehension_{$k}{@}=={@}NEVER_REQUIRED"));
            $this->form->addGroup(
                $group,
                "RC10_table{$n}",
                null,
                $this->_GUIDelimiter,
                false
            );
            unset($group);
        }
        $this->addLabel("<h2>Humpback Whales</h2>");
        $questions=[
            ["68. What is the author's main message in this passage?","Help save humpback whales; Raise awareness about the decline / endangerment/ near extinction of humpback whales",""],
            ["69. In what two ways have people been the primary reason for the decline in humpback whales?","Refers to BOTH of the following: Hunting/Whales hunted, Whales caught in fishing nets drown/starve","Refers to ONE of the following: Hunting/Whales hunted, Whales caught in fishing nets drown/starve"],
            ["70. How do large humpback whales cause fishing nets to be lost or destroyed","Whales pull the fishing nets off the boat","Whales pull the fishing nets off the boat"],
            ["71. Which parts of the whales are sold to make products that people use?","Refers to BOTH of the following: Bones, Fat","Refers to ONE of the following: Bones, Fat"],
            ["72. According to the passage, what two things might happen to a what caught in a fishing net?","Refers to BOTH of the following: Drown, Starve","Refers to ONE of the following: Drown, Starve"],
            ["73. What caused the humpback whales to begin making a recovery?","Refers to BOTH of the following: People became aware of the situation, People were more active in their recovery. ","Refers to ONE of the following: People became aware of the situation, People were more active in their recovery, Placed on the endangered species list"],
            ["74. Approximately when were there over 100,000 humpback whales in the world?", "Before 1960; Any date before 1960 (e.g.,1920, the 1900s", ""],
            ["75.  What does the passage suggest is likely to happen to the humpback whale in the future?", "Their numbers will grow; They will recover", "They will be better protected; People will see their importance"]
        ];
        $group[] =& $this->form->createElement("static", null, null, "Item");
        $group[] =& $this->form->createElement("static", null, null, "2-Point Responses");
        $group[] =& $this->form->createElement("static", null, null, "1-Point Responses");
        $group[] =& $this->form->createElement("static", null, null, "Score");

        $this->form->addGroup(
            $group,
            "RC11_table{0}",
            null,
            $this->_GUIDelimiter,
            false
        );
        unset($group);
        for ( $i=0; $i<count($questions);$i++){
            $n = $i +1;
            $k = $i + 68;
            $group[] =& $this->form->createElement("static",null,null,"{$questions[$i][0]}");
            $group[] =& $this->form->createElement("static",null,null,"{$questions[$i][1]}");
            $group[] =& $this->form->createElement("static",null,null,"{$questions[$i][2]}");

            if ("{$questions[$i][2]}" == ""){
                $opts = $opts2;
            }else{
                $opts = $opts3;
            }
            $group[] =& $this->form->createElement("select","reading_comprehension_{$k}", "", $opts);
            $this->XINRegisterRule("reading_comprehension_{$k}",
                array("reading_comprehension_{$k}{@}=={@}NEVER_REQUIRED"));
            $this->form->addGroup(
                $group,
                "RC11_table{$n}",
                null,
                $this->_GUIDelimiter,
                false
            );
            unset($group);
        }
        $this->addLabel("<h2>City Zoo</h2>");
        $questions=[
            ["76. According to Tanisha, what three things might happen if zoo prices are not raised?","Refers to at least THREE of the following: Zoo closes, Animals sold off, Children lose learning experiences, Families lose entertainment","Refers to at TWO of the following: Zoo closes, Animals sold off, Children lose learning experiences, Families lose entertainment"],
            ["77. Why does Tanisha believe that increasing the cost of snacks and souvenirs is an unrealistic solution?","Refers to BOTH of the following: Only 25% of zoo revenue comes from such sales, Zoo patrons may start bringing their own snacks/ Reduced concession sales","Refers to ONE of the following: Only 25% of zoo revenue comes from such sales, Zoo patrons may start bringing their own snacks/ Reduced concession sales"],
            ["78. What is the main reason that Tom is against raising zoo prices?","Raising ticket prices leads to a drop in attendance; The last ticket increase led to a drop in attendance","Zoo attendance has dropped"],
            ["79. According to Tom, how should the zoo boost its income?","Refers to BOTH of the following: Concession sales, Souvenir sales","Refers to ONE of the following: Concession sales, Souvenir sales"],
            ["80. What important information is missing from Tom's letter to prove that zoon attendance dropped because of the price increase?","Attendance data prior to 1992; Data to support causality, Personal testimonies, An evaluation of other (3rd) variable affecting zoo attendance",""]
        ];
        $group[] =& $this->form->createElement("static", null, null, "Item");
        $group[] =& $this->form->createElement("static", null, null, "2-Point Responses");
        $group[] =& $this->form->createElement("static", null, null, "1-Point Responses");
        $group[] =& $this->form->createElement("static", null, null, "Score");

        $this->form->addGroup(
            $group,
            "RC12_table{0}",
            null,
            $this->_GUIDelimiter,
            false
        );
        unset($group);
        for ( $i=0; $i<count($questions);$i++){
            $n = $i +1;
            $k = $i + 76;
            $group[] =& $this->form->createElement("static",null,null,"{$questions[$i][0]}");
            $group[] =& $this->form->createElement("static",null,null,"{$questions[$i][1]}");
            $group[] =& $this->form->createElement("static",null,null,"{$questions[$i][2]}");

            if ("{$questions[$i][2]}" == ""){
                $opts = $opts2;
            }else{
                $opts = $opts3;
            }
            $group[] =& $this->form->createElement("select","reading_comprehension_{$k}", "", $opts);
            $this->XINRegisterRule("reading_comprehension_{$k}",
                array("reading_comprehension_{$k}{@}=={@}NEVER_REQUIRED"));
            $this->form->addGroup(
                $group,
                "RC12_table{$n}",
                null,
                $this->_GUIDelimiter,
                false
            );
            unset($group);
        }
        $this->addLabel("<h2>The Rock</h2>");
        $questions=[
            ["81. What suddenly made this hike so difficult?", "A 20-foot escarpment/cliff; A clump of rocks", "It became very steep; The trail ended; Switchbacks; The cold/wind"],
            ["82. What was the most important thing the women had to overcome in order to scale the rock", "Fatigue; Their mental defeat", "The last cliff; The 20-foot escarpment/cliff"],
            ["83. What kept the women from turning back when they saw the 20-foot cliff above them?", "They were determined to keep going/refused to surrender", "They had already come so far; They had already hiked 5 miles/6,000 feet"],
            ["84. Near the end of the climb, why did Angela refuse to check on Sherry's progress", "Angela needed to stay focused (on herself); Angela needed to get herself to the top", "She didn't want to look down/faill; She was afraid; she realized there was only 5 feet to go; She didn't wany to get discouraged"]

        ];
        $group[] =& $this->form->createElement("static", null, null, "Item");
        $group[] =& $this->form->createElement("static", null, null, "2-Point Responses");
        $group[] =& $this->form->createElement("static", null, null, "1-Point Responses");
        $group[] =& $this->form->createElement("static", null, null, "Score");

        $this->form->addGroup(
            $group,
            "RC13_table{0}",
            null,
            $this->_GUIDelimiter,
            false
        );
        unset($group);
        for ( $i=0; $i<count($questions);$i++){
            $n = $i +1;
            $k = $i + 81;
            $group[] =& $this->form->createElement("static",null,null,"{$questions[$i][0]}");
            $group[] =& $this->form->createElement("static",null,null,"{$questions[$i][1]}");
            $group[] =& $this->form->createElement("static",null,null,"{$questions[$i][2]}");

            if ("{$questions[$i][2]}" == ""){
                $opts = $opts2;
            }else{
                $opts = $opts3;
            }
            $group[] =& $this->form->createElement("select","reading_comprehension_{$k}", "", $opts);
            $this->XINRegisterRule("reading_comprehension_{$k}",
                array("reading_comprehension_{$k}{@}=={@}NEVER_REQUIRED"));
            $this->form->addGroup(
                $group,
                "RC13_table{$n}",
                null,
                $this->_GUIDelimiter,
                false
            );
            unset($group);
        }
        $this->addLabel("<h2>Raw Scores:</h2>");
        $this->addScoreColumn("grade_1_item_set_total_raw_score", "Grade 1 Item Set Total Raw Score");
        $this->addScoreColumn("grade_2_item_set_total_raw_score", "Grade 2 Item Set Total Raw Score");
        $this->addScoreColumn("grade_3_item_set_total_raw_score", "Grade 3 Item Set Total Raw Score");
        $this->addScoreColumn("grade_4_item_set_total_raw_score", "Grade 4 Item Set Total Raw Score");
        $this->addScoreColumn("grade_5_item_set_total_raw_score", "Grade 5 Item Set Total Raw Score");
        $this->addScoreColumn("grade_6_item_set_total_raw_score", "Grade 6 Item Set Total Raw Score");
        $this->addScoreColumn("grade_7_item_set_total_raw_score", "Grade 7 Item Set Total Raw Score");
        $this->addScoreColumn("grade_8_item_set_total_raw_score", "Grade 8 Item Set Total Raw Score");
        $this->addScoreColumn("grade_9_12_item_set_total_raw_score", "Grade 9-12 Item Set Total Raw Score");
    }
    // page4 => Math Problem Solving
    function _page4(){
        $this->addHeader("Math Problem Solving");
        $this->addLabel("<h3>Grades PK-12+</h3>");
        $this->addLabel("Discontinue Rule: Discontinue after 4 consecutive scores of 0.");
        $this->addLabel("Reverse Rule: If score of 0 on first three item given, administer preceding items in reverse order until 3 consecutive score of 1.");
        $this->addLabel("Note: Start points and rules are considered for scoring");
        $group[] =& $this->form->createElement("static", null, null, "Item");
        $group[] =& $this->form->createElement("static", null, null, "Correct Answer");
        $group[] =& $this->form->createElement("static", null, null, "Score");
        $group[] =& $this->form->createElement("static", null, null, "Paper/Pencil Used?");
        $this->form->addGroup(
            $group,
            "math_problem_table{0}",
            null,
            $this->_GUIDelimiter,
            false
        );
        unset($group);
        $opts = array(null => "",
            "dk" => "DK",
            "1" => "1",
            "0" => "0");
        $paperUsed = array(null=>"", "Y"=> "Yes");
        $questions = [
            ["Grade PK<br>1. Trial 1 / Trial2", "(O) 2",],
            ["2. Say 'Point to the circle'","(P) Circle"],
            ["3. Say 'Point to the empty glass'","(P) Empty glass"],
            ["4. Say 'This time there are no pictures. Just watch me' Raise three fingers, <br>one at a time, without counting them, and say 'How many fingers am I holding up?'","(O) 3"],
            ["5. Say 'Point to the number 9'","(P) 9"],
            ["6. Say 'Point to the number 5'","(P) 5"],
            ["7. Say, 'This time there are no pictures. Let's count to six. <br>I'll start and then you go one. Remember, count to six. Ready? <br>One, two, three... what comes after three?' Do not penalize for counting beyond six","(O, All three in order) 4-5-6"],
            ["Grade K<br>8. Say 'Point to the hand holding the most balloons'","(P) Hand with three balloons"],
            ["9. Say 'How many wagons are there?'","(O) 4"],
            ["10. Say 'Point to the longest line'","(P) Longest line"],
            ["11. Point to the number 2 and say 'What is this number?'","(O) 2"],
            ["12. Say 'Point to the triangle'","(P) Triangle"],
            ["13. Say 'Count aloud all the chips and tell me how many there are'","(O) 9"],
            ["14. Say 'Which number is less?' Encourage the student to point","(P) 3"],
            ["15. Say 'Which two hands have the same number of balloons?'","(P) Both hands with one balloon"],
            ["Grades 1-2<br>16. Point to the number 7 and say 'What is this number?'","(O) 7"],
            ["17. Point to the number 10 and say 'What is this number?'","(O) 10"],
            ["18. Say 'A group of students were asked which toys they liked best.<br>This graph shows the choices of the students'. Point to each row as you name the toy: 'Some students chose bears. Some chose bikes. Others chose balls. Each toy equals one student. How many students liked the bears the best?", "(O) 3"],
            ["19. Say 'Which number is more?' Encourange the student to point","(P) 8"],
            ["20. Say 'Which number is less?' Encourage the student to point","(P) 10"],
            ["21. Say 'User your hand to cover up three birds. How many birds are left uncovered?'","(O) 5"],
            ["22. Say 'How many shapes in all?' Point in a circular motion across the entire page","(O) 10"],
            ["23. Say 'Point to the second apple from the bowl'","(P) Second apple from the bowl"],
            ["24. Say 'If you are counting in order, which of these numbers would you say first?'","(P or O) 2"],
            ["25. Say 'How many inches long is this pencil'","(O) 5"],
            ["Grade 3<br>26. Say 'If you are counting in order, which of these numbers would you say first?'","(P or O) 11"],
            ["27. Say 'And which of these number would come next?'","(P or O) 13"],
            ["28. Say 'If two of these ducks flew away, how many would be left?'","(O) 5"],
            ["29. Say 'If all the dots on the line had numbers, what number would go here?' Point to the A.", "(O) 30"],
            ["Grades 4-5<br>30. Say 'On what day of the week is the 14th?'","(O) Tuesday. If student points to the T, Q: What does the T mean?"],
            ["31. Say 'Neal had five marbles and was given three more. How many marbles does Neal have now?'", "(O) 8"],
            ["32. Say 'These beads form a pattern on the pegs. How many beads should be put on the empty pag to complete this pattern?'", "(O) 4"],
            ["33. Say ' How many pennis does it take to equal the value of one dime?'", "(O) 10"],
            ["Grades 6-8<br>34. Say 'This graph shows the number of books given to the city library by students from four different schools. Going across the bottom of the graph, the schools are' (point to each bar as you name the school) 'Central, Johnson, West and Eastman. The numbers on the side'(point to the y-axis) 'show the number of books given by each school. How many books did Eastman School give?'", "(O) 40"],
            ["Grades 9-10<br>35. Say 'What number goes here (point to he empty circle)?'", "(O) 7"],
            ["36. Say 'What time is shown on this clock", "(O) 8:15; Quarter after/past 8; 15 minutes after/past 8; 15 after/past 8"],
            ["37. Say 'Which is worth more: seven pennies, six nickels, or one quarter"],
            ["38. Say 'This graph shows the number of people who rode each fair ride. The rides were' (poin to each bar as you name the ride) 'the Ferris wheel, roller coaster, merry-go-round, water slide, pirate ship and train. The numbers on the side' (point to the y-axis) 'show the number of people who rode each ride. How many people rode the Ferris wheel?' Point to the Ferris wheel.", "(O) Any one of the following 14;15;16 "],
            ["39. Say 'Which number is in the tens place?'", "(P or O) 5"],
            ["Grades 11-12+<br>40. Say 'Which number is in the hundred-thousands place?", "(P or O) 9"],
            ["41. Say 'Robert has six toys. Together RObert and Max have 15 toys. How many toys does Max have?' ", "(O) 9"],
            ["42. Say 'If you flipped a coin 10 times, how many times would you expect the coint to land on heads?' ", "(O) 5"],
            ["43. Say 'Mrs. Rivera served cake for dessert. she cut the cake into six equal pieces. If Carlos eats two pieces and Jenna eats one piece, what fraction of the cake would be left?'", "(O) Half; 1/2;3/6"],
            ["44. Say 'A classroom has four rows of desks. Each row has the same number of desks. There are a total of 24 desks. How many desks are in each row?'", "(O) 6"],
            ["45. Say 'If today is the 3rd of the month, and Anita's cousin will come to visit on the 17th, how many weeks must Anita wait until her cousin Arrives?", "(O) 2"],
            ["46. Say 'If you cut a cake into six equal pieces, what fraction of the cake would each piece be?'", "(O) One-sixth; 1/6"],
            ["47. Say 'Which choice' (sweep finger across answer choices) 'shows what this triangle' (point to the triangle) 'will look like if the graph paper is rotated 90 degrees to the right' ", "(Por O) B" ],
            ["48. Say 'Pyut these fractions in order from smallest to largest'", "(P or O, in order) 1/5, 1/4, 1/3, 1/2"],
            ["49. Say 'Find the perimeter in meters", "(O) 18"],
            ["50. Say 'What is the next numebr in this pattern?' Point to the '?' in the pattern", "(O) 120"],
            ["51. Say, 'Assuming angle A is 90 degrees and angle B is 20 degrees, what is the number of degrees in angle C?'","(O) 70"],
            ["52. Say 'Kurt went to sleep at 10:30 pm and woke up at 7:00 am the next morning. How long did Kurt sleep?'","(O) 8 1/2 hours; 8 hours, 30 minutes"],
            ["53. Say 'Pay has scores of 95,80,85, and 80 on his first four math tests. What is his average test scor?'","(O) 85"],
            ["54. Say 'Which choice' (sweep finger across answer choice) 'shows what this figure' (point to the top figure) will look like if the graph paper is rotated 180 degrees?","(P or O) C"],
            ["55. Say 'Mary had 200 dollars. The she bought four tires. Each tire cose 35 dollars and 50 cents, plus 3 dollars each for balancing. How much money did she have left?'","(O) $46.00"],
            ["56. Say 'Which decimal is closest in value to 5/6?'","(P or O) 0.8"],
            ["57. Say 'This pie chart shows the money made by each booth at a fair. Which booth raised exactly 90 dollars?'","(P or O) Sweet Shop/the brown one "],
            ["58. Say 'The charity drive reached one-fourth of its goal in March, one-third of its goal in April, and one-sixth of its goal in May. What part of the goal was reached during those three months?'","(O) 75 percent; 9/12; 3/4"],
            ["59. Say 'What is the solution to this problem?'","(O) 48"],
            ["60. Say 'Of these numbers, which ones are prime numbers?'","(P or O in any order) 2,3,5,7  if fewer than four are given on the first try Q: Are there more?"],
            ["61. Say 'A bank charges a monthly fee of eight dollars. You may write 20 checks a month for free. After 20 checks, you are charged 30 cents for each addition check you write. What will your charges be for a month in which you write 40 checks?'","(O) $14.00"],
            ["62. Say 'How many different kinds of sandwiches can Kevin make using one kind of break, one kind of meat, and one kind of cheese. For his sanwich, Kevin can choose from two types of bread, two types of meat and two types of cheese.'","(O) 8"],
            ["63. Say 'What is the maximum number of two inch by two inch pieces that can be cut from a 10 inch by 8 inch cake?'","(O) 20"],
            ["64. Say 'The Carver baseball team bought 10 dozen candy bars at 3 dollars and 75 cents per dozen. They sold the candy as a money-making project for 50 cents per bar. What was their profit?'","(O) $22.50"],
            ["65. Say 'What are the mean, median and mode for these test scores?'","(O) Mean = 16.8 median = 16.5 mode = 17"],
            ["66. Say 'What are the slope and y-intercept for the red line?'","(O) Slope = 2/3, y-intercept = 2"],
            ["67. Say 'To answer this question, you may wish to use one or more of these formulas.' (point to formulas) 'If this ball were to roll exactly 100 complete revolutions, approximately how far would it travel in inches?'","(O) 3,140"],
            ["68. Say 'Jessica is mowing the lawn with a mower that has a 30-inch wide cut. If her lawn is 100 feet by 50 feet, what is the fewest number of trips needed, from one end to the other, to complete this job?'","(O) 20"],
            ["69. Say 'What is the probability that both spinners will stop on blue on the first spin?'","(O) 0.05; 5 percent, 1/20"],
            ["70. Say 'How many different ways are there to arrange four books on a shelf?'","(O) 24"],
            ["71. Say 'Scuba Bob is a planning to dive to a depth of 60 feet, and his scuba tank will last 19.5 minutes while on the surface. Assuming Suba Bob can safely descent and rise to the surface at 2 feet per second, and at a depth of 60 feet he uses more than 10% more air, how many minutes can he safely stay on the bottom?'","(O) Any response between 16.65 to 16.82 minutes; 16 minutes 39 to 49 seconds"],
            ["72. Say 'To answer this question, you may wish to use one or more of these formulas' (point to formula). 'Assume that each unit fo the grid is two inches by two inches and only paths that do not pass through a red sqaure are possible. What is the shortest distance between point A and point B? Round your answer to the nearest inch'","(O) 19"]
        ];
        for ( $i=0; $i<count($questions);$i++){
            $n = $i +1;
            $group[] =& $this->form->createElement("static",null,null,"{$questions[$i][0]}");
            $group[] =& $this->form->createElement("static",null,null,"{$questions[$i][1]}");

            $group[] =& $this->form->createElement("select","math_problem{$n}", "", $opts);
            $group[] =& $this->form->createElement("select", "math_problem_paperUsed{$n}", "", $paperUsed);
            $this->form->addGroup(
                $group,
                "math_problem_table{$n}",
                null,
                $this->_GUIDelimiter,
                false
            );
            unset($group);
            $this->XINRegisterRule("math_problem{$n}",
                array("math_problem{$n}{@}=={@}NEVER_REQUIRED"));
            $this->XINRegisterRule("math_problem_paperUsed{$n}",
                array("math_problem_paperUsed{$n}{@}=={@}NEVER_REQUIRED"));
        }
        $this->addLabel("<h2>Raw Score:</h2>");
        $this->addScoreColumn("math_problem_solving_total_raw_score", "Math Problem Solving Total Raw Score");
    }
    // page5 => Alphabet writing fluency
    function _page5(){
        $grade=$this->_getGradeCandidate();
        $include_grades_array= array("PK","K",1,2,3);
        if (!in_array($grade, $include_grades_array)) {
            $this->form->addElement("static", null, '<font color="Red">This test is not applicable for Grade '.$grade.' Candidate. Please skip this test.</font>');
        }
        $this->addHeader("Alphabet Writing Fluency");
        $this->addLabel("<h3>Grades PK-3</h3>");
        $this->addLabel("<h3>Item 1</h3>");
        $this->addSelect("elapsed_time", "Elapsed Time: ",
            array(null=> "",
                "30_sec" => "30 Seconds",
                "other"=>"Other"
            ));
        $this->addTextElement("if_other_time", "If other, number of seconds: ");
        $this->XINRegisterRule(
            "if_other_time",
            array("elapsed_time{@}=={@}other"),
            "Required",
            "if_other_group"
        );

        $letters = [
            ["B_or_b"],
            ["C_or_c"],
            ["D_or_d"],
            ["E_or_e"],
            ["F_or_f"],
            ["G_or_g"],
            ["H_or_h"],
            ["I_or_i"],
            ["J_or_j"],
            ["K_or_k"],
            ["L_or_l"],
            ["M_or_m"],
            ["N_or_n"],
            ["O_or_o"],
            ["P_or_p"],
            ["Q_or_q"],
            ["R_or_r"],
            ["S_or_s"],
            ["T_or_t"],
            ["U_or_u"],
            ["V_or_v"],
            ["W_or_w"],
            ["X_or_x"],
            ["Y_or_y"],
            ["Z_or_z"]
        ];
        $this->addLabel("<h3>Check letters that receive credit</h3>");
        $group[] =& $this->form->createElement("static", null, null, " ");
        $group[] =& $this->form->createElement("static", null, null, " ");

        $this->form->addGroup(
            $group,
            "WF_table_0",
            null,
            $this->_GUIDelimiter,
            false
        );
        unset($group);
        for ( $i=0; $i<count($letters);$i++){
            for ($j=0; $j<count($letters[0]); $j++){
                $group[] =& $this->form->createElement('advcheckbox', "wf_{$letters[$i][$j]}", "{$letters[$i][$j]}", array('class' => 'form-control input-sm') );
            }
            $this->form->addGroup(
                $group,
                "WF_table_{$letters[$i][0]}",
                null,
                $this->_GUIDelimiter,
                false
            );
            unset($group);
        }
        $this->addTextAreaElement("WF_errors", "Errors (optional): ");
        $this->addLabel("<h2>Raw Score:</h2>");
        $this->addScoreColumn("alphabet_writing_fluency_raw_score", "Alphabet Writing Fluency Raw Score");
    }
    // page6 => Sentence Composition
    function _page6(){
        $grade=$this->_getGradeCandidate();
        $exclude_grades_array= array("PK","K");
        if (in_array($grade, $exclude_grades_array)) {
            $this->form->addElement("static", null, '<font color="Red">This test is not applicable for Grade '.$grade.' Candidate. Please skip this test.</font>');

        }
        $this->addHeader("Sentence Composition");
        $this->addLabel("<h3>1.Sentence Combining</h3>");
        $this->addLabel("<h3>Grades 1-12+</h3>");
        $this->addLabel("Discontinue Rule: If score is 0 on first 2 items, record raw score of 0 and proceed to sentence building.");
        $this->addLabel("Note: Start points and rules are considered for scoring.");
        $group[]=& $this->form->createElement("static", null, null, "Item");
        $group[]=& $this->form->createElement("static", null, null, "Meets Prereqs");
        $group[]=& $this->form->createElement("static", null, null, "Semantics & Grammar");
        $group[]=& $this->form->createElement("static", null, null, "Mechanics");
        $group[]=& $this->form->createElement("static", null, null, "Extra Credit");
        $group[]=& $this->form->createElement("static", null, null, "Semantics & Grammar");
        $group[]=& $this->form->createElement("static", null, null, "Mechanics");
        $group[]=& $this->form->createElement("static", null, null, "If Extra Credit = 0, check error(s)");
        $this->form->addGroup(
            $group,
            "Sentence_combinig_table{0}",
            null,
            $this->_GUIDelimiter,
            false
        );
        unset($group);
        $items = [
            "1. Cats...",
            "2. The frog...",
            "3. Mark...",
            "4. Antonio...",
            "5. Marci..."
        ];

        $ynOpts=array(
            null => "",
            "Y"=> "Y",
            "N"=> "N"
        );
        $score1 = array(
            null => "",
            "1"=>"1",
            "0"=>"0"
        );
        $score2 = array(
            null => "",
            "2" => "2",
            "1"=>"1",
            "0"=>"0"
        );
        for ($i=0; $i<count($items); $i++){
            $n=$i+1;
            for ($j=0; $j<3;$j++){
                if ($j==0){
                    $group[] =& $this->form->createElement("static", null, null, "{$items[$i]}");
                    $group[] =& $this->form->createElement("select", "SC_meets_prereqs{$n}",null,
                        $ynOpts
                    );
                    $group[] =& $this->form->createElement("select","SC_semantics_grammar_score{$n}",null,
                        $score2
                    );
                    $group[] =& $this->form->createElement("select","SC_mechanics_score{$n}",null,
                        $score2
                    );
                    $group[] =& $this->form->createElement("select","SC_extra_credit{$n}",null,
                        $score1
                    );
                    $group[] =& $this->form->createElement("text","SC_semantic_grammar_text{$n}_1", "1. ",null);
                    $group[] =& $this->form->createElement("text","SC_mechanics_text{$n}_1","1. ",null);
                    $group[] =& $this->form->createElement('advcheckbox', "if_no_XC{2}{$n}_1", "1. 'and' joins 2 indep sentences", array('class' => 'form-control input-sm') );
                }else {
                    $group[] =& $this->form->createElement("static", null, null, " ");
                    $group[] =& $this->form->createElement("static", null, null, " ");
                    $group[] =& $this->form->createElement("static", null, null, " ");
                    $group[] =& $this->form->createElement("static", null, null, " ");
                    $group[] =& $this->form->createElement("static", null, null, " ");
                    if ($j ==1){
                        $group[] =& $this->form->createElement("text","SC_semantic_grammar_text{$n}_2","2. " ,null);
                        $group[] =& $this->form->createElement("text","SC_mechanics_text{$n}_2","2. ",null);
                        $group[] =& $this->form->createElement('advcheckbox', "if_no_XC{2}{$n}_2", "2. poor sentence structure", array('class' => 'form-control input-sm') );

                    }else if ($j = 2){
                        $group[] =& $this->form->createElement("text","SC_semantic_grammar_text{$n}_3","3. ",null);
                        $group[] =& $this->form->createElement("text","SC_mechanics_text{$n}_3","3. ",null);
                        $group[] =& $this->form->createElement('advcheckbox', "if_no_XC{2}{$n}_3", "3. meaning", array('class' => 'form-control input-sm') );
                    }
                }
                $this->form->addGroup(
                    $group,
                    "Sentence_combining_table{$n}.{$j}",
                    null,
                    $this->_GUIDelimiter,
                    false
                );
                unset($group);
                $this->XINRegisterRule("SC_meets_prereqs{$n}",
                    array("SC_meets_prereqs{$n}{@}=={@}NEVER_REQUIRED"));
                $this->XINRegisterRule("SC_semantics_grammar_score{$n}",
                    array("SC_semantics_grammar_score{$n}{@}=={@}NEVER_REQUIRED"));
                $this->XINRegisterRule("SC_mechanics_score{$n}",
                    array("SC_mechanics_score{$n}{@}=={@}NEVER_REQUIRED"));
                $this->XINRegisterRule("SC_extra_credit{$n}",
                    array("SC_extra_credit{$n}{@}=={@}NEVER_REQUIRED"));
                $this->XINRegisterRule("SC_semantic_grammar_text{$n}_1",
                    array("SC_semantic_grammar_text{$n}_1{@}=={@}NEVER_REQUIRED"));
                $this->XINRegisterRule("SC_mechanics_text{$n}_1",
                    array("SC_mechanics_text{$n}_1{@}=={@}NEVER_REQUIRED"));
                $this->XINRegisterRule("if_no_XC{2}{$n}_1",
                    array("if_no_XC{2}{$n}_1{@}=={@}NEVER_REQUIRED"));
                $this->XINRegisterRule("SC_semantic_grammar_text{$n}_2",
                    array("SC_semantic_grammar_text{$n}_2{@}=={@}NEVER_REQUIRED"));
                $this->XINRegisterRule("SC_mechanics_text{$n}_2",
                    array("SC_mechanics_text{$n}_2{@}=={@}NEVER_REQUIRED"));
                $this->XINRegisterRule("if_no_XC{2}{$n}_2",
                    array("if_no_XC{2}{$n}_2{@}=={@}NEVER_REQUIRED"));
                $this->XINRegisterRule("SC_semantic_grammar_text{$n}_3",
                    array("SC_semantic_grammar_text{$n}_3{@}=={@}NEVER_REQUIRED"));
                $this->XINRegisterRule("SC_mechanics_text{$n}_3",
                    array("SC_mechanics_text{$n}_3{@}=={@}NEVER_REQUIRED"));
                $this->XINRegisterRule("if_no_XC{2}{$n}_3",
                    array("if_no_XC{2}{$n}_3{@}=={@}NEVER_REQUIRED"));

            }
            $group[] =& $this->form->createElement("static", null, null, " ");
            $this->form->addGroup(
                $group,
                "Sentence_combining_table_blank{$n}",
                null,
                $this->_GUIDelimiter,
                false
            );
            unset($group);
        }
        $this->addLabel("<h2>Raw Scores:</h2>");
        $this->addScoreColumn("semantics_grammar_raw_score1", "Semantics & Grammar Raw score Raw Score");
        $this->addScoreColumn("mechanics_score1", "Sentence Combining Raw Score");
        $this->addScoreColumn("extra_credits_raw_score1", "Extra Credits Raw Score");
        $this->addScoreColumn("sentence_combining_raw_score", "Sentence Combining Raw Score");
        $this->addLabel("<h3>2.Sentence Building</h3>");
        $this->addLabel("<h3>Grades 1-12+</h3>");
        $this->addLabel("Discontinue Rule: If score is 0 on first 2 items, record raw score of 0.");
        $this->addLabel("Note: Start points and rules are considered for scoring.");
        $group[]=& $this->form->createElement("static", null, null, "Item");
        $group[]=& $this->form->createElement("static", null, null, "Meets Prereqs");
        $group[]=& $this->form->createElement("static", null, null, "Semantics & Grammar");
        $group[]=& $this->form->createElement("static", null, null, "Mechanics");
        $group[]=& $this->form->createElement("static", null, null, "Semantics & Grammar");
        $group[]=& $this->form->createElement("static", null, null, "Mechanics");

        $this->form->addGroup(
            $group,
            "Sentence_building_table{0}",
            null,
            $this->_GUIDelimiter,
            false
        );
        unset($group);
        $items = [
            "1. the",
            "2. or",
            "3. until",
            "4. of",
            "5. an",
            "6. than",
            "7. as"
        ];

        $ynOpts=array(
            null => "",
            "Y"=> "Y",
            "N"=> "N"
        );
        $score2 = array(
            null => "",
            "2" => "2",
            "1"=>"1",
            "0"=>"0"
        );
        for ($i=0; $i<count($items); $i++){
            $n=$i+1;
            for ($j=0; $j<3;$j++){
                if ($j==0){
                    $group[] =& $this->form->createElement("static", null, null, "{$items[$i]}");
                    $group[] =& $this->form->createElement("select","SB_meets_prereqs{$n}",null,
                        $ynOpts
                    );
                    $group[] =& $this->form->createElement("select","SB_semantics_grammar_score{$n}",null,
                        $score2
                    );
                    $group[] =& $this->form->createElement("select","SB_mechanics_score{$n}",null,
                        $score2
                    );
                    $group[] =& $this->form->createElement("text","SB_semantic_grammar_text{$n}_1", "1. " ,null);
                    $group[] =& $this->form->createElement("text","SB_mechanics_text{$n}_1","1. ",null );
                }else {
                    $group[] =& $this->form->createElement("static", null, null, " ");
                    $group[] =& $this->form->createElement("static", null, null, " ");
                    $group[] =& $this->form->createElement("static", null, null, " ");
                    $group[] =& $this->form->createElement("static", null, null, " ");
                    if ($j ==1){
                        $group[] =& $this->form->createElement("text","SB_semantic_grammar_text{$n}_2","2. ",null);
                        $group[] =& $this->form->createElement("text","SB_mechanics_text{$n}_2","2. ",null);

                    }else if ($j = 2){
                        $group[] =& $this->form->createElement("text","SB_semantic_grammar_text{$n}_3","3. ",null );
                        $group[] =& $this->form->createElement("text","SB_mechanics_text{$n}_3","3. ",null);
                    }
                }
                $this->form->addGroup(
                    $group,
                    "Sentence_building_table{$n}.{$j}",
                    null,
                    $this->_GUIDelimiter,
                    false
                );
                unset($group);
                $this->XINRegisterRule("SB_meets_prereqs{$n}",
                    array("SB_meets_prereqs{$n}{@}=={@}NEVER_REQUIRED"));
                $this->XINRegisterRule("SB_semantics_grammar_score{$n}",
                    array("SB_semantics_grammar_score{$n}{@}=={@}NEVER_REQUIRED"));
                $this->XINRegisterRule("SB_mechanics_score{$n}",
                    array("SB_mechanics_score{$n}{@}=={@}NEVER_REQUIRED"));
                $this->XINRegisterRule("SB_semantic_grammar_text{$n}_1",
                    array("SB_semantic_grammar_text{$n}_1{@}=={@}NEVER_REQUIRED"));
                $this->XINRegisterRule("SB_mechanics_text{$n}_1",
                    array("SB_mechanics_text{$n}_1{@}=={@}NEVER_REQUIRED"));
                $this->XINRegisterRule("SB_semantic_grammar_text{$n}_2",
                    array("SB_semantic_grammar_text{$n}_2{@}=={@}NEVER_REQUIRED"));
                $this->XINRegisterRule("SB_mechanics_text{$n}_2",
                    array("SB_mechanics_text{$n}_2{@}=={@}NEVER_REQUIRED"));
                $this->XINRegisterRule("SB_semantic_grammar_text{$n}_3",
                    array("SB_semantic_grammar_text{$n}_3{@}=={@}NEVER_REQUIRED"));
                $this->XINRegisterRule("SB_mechanics_text{$n}_3",
                    array("SB_mechanics_text{$n}_3{@}=={@}NEVER_REQUIRED"));
            }
            $group[] =& $this->form->createElement("static", null, null, " ");
            $this->form->addGroup(
                $group,
                "Sentence_building_table_blank{$n}",
                null,
                $this->_GUIDelimiter,
                false
            );
            unset($group);
        }
        $this->addLabel("<h2>Raw Scores:</h2>");
        $this->addScoreColumn("semantics_grammar_raw_score2", "Semantics & Grammar Raw score Raw Score");
        $this->addScoreColumn("mechanics_score2", "Sentence Mechanics Raw Score");
        $this->addScoreColumn("sentence_building_raw_score", "Sentence Building Raw Score");
    }
    // page7=> Word reading
    function _page7(){
        $grade=$this->_getGradeCandidate();
        $exclude_grades_array= array("PK","K");
        if (in_array($grade, $exclude_grades_array)) {
            $this->form->addElement("static", null, '<font color="Red">This test is not applicable for Grade '.$grade.' Candidate. Please skip this test.</font>');

        }
        $this->addHeader("Word Reading");
        $this->addLabel("<h3>Grades 1-12+</h3>");
        $this->addLabel("Discontinue Rule: Discontinue after 4 consecutive scores of 0.");
        $this->addLabel("Note: Start points and rules are considered for scoring.");
        $group[] =& $this->form->createElement("static", null, null, "Item");
        $group[] =& $this->form->createElement("static", null, null, "Score");
        $group[] =& $this->form->createElement("static", null, null, ">3");
        $group[] =& $this->form->createElement("static", null, null, "SC");
        $this->form->addGroup(
            $group,
            "word_reading_table{0}",
            null,
            $this->_GUIDelimiter,
            false
        );
        unset($group);
        $opts = array(null => "",
            "dk" => "DK",
            "1" => "1",
            "0" => "0");
        $questions = array(
            "1. in ",
            "2. to ",
            "3. my ",
            "4. they",
            "5. cow",
            "6. when",
            "7. bear",
            "8. don't",
            "9. shop",
            "10. other",
            "11. stone",
            "12. sky",
            "13. breeze",
            "14. fight",
            "15. between",
            "16. goat",
            "17. foot",
            "18. wrong",
            "19. seat",
            "20. cloud",
            "21. depend",
            "22. frozen",
            "23. knife",
            "24. distance",
            "25. equipment",
            "26. manage",
            "27. photograph",
            "28. crumb",
            "29. playfully",
            "30. rhyme",
            "31. posed",
            "32. budge",
            "33. ruin",
            "34. tough",
            "35. garnish",
            "36. ridiculous",
            "37. interject",
            "38. radiant",
            "39. poise",
            "40. custodian",
            "41. pier",
            "42. choir",
            "43. surgery",
            "44. idealism",
            "45. hymn",
            "46. philosophy",
            "47. magnetic",
            "48. acquaintance",
            "49. suspicious",
            "50. inflection",
            "51. technique",
            "52. insignificant",
            "53. elude",
            "54. symphony",
            "55. allure",
            "56. synthesis",
            "57. momentary",
            "58. adolescent",
            "59. sarcasm",
            "60. vestibule",
            "61. degenerative",
            "62. choreography",
            "63. isthmic",
            "64. plethora",
            "65. manipulative",
            "66. vacillate",
            "67. sanguine",
            "68. vociferous",
            "69. hierarchy",
            "70. euphonious",
            "71. autonomous",
            "72. demagogue",
            "73. vicissitude",
            "74. vitiate",
            "75. quincuncial"
        );
        for ($i=0;$i<count($questions);$i++){
            $n = $i+1;
            $group[]=&$this->form->createElement("static", null, null, "{$questions[$i]}");
            $group[]=&$this->form->createElement("select", "WR_score_{$n}", null,$opts);
            $group[]=&$this->form->createElement("advcheckbox", "WR_3_{$n}",null, array('class'=>'form-control input-sm'));
            $this->XINRegisterRule("WR_3_{$n}",
                array("WR_3_{$n}{@}=={@}NEVER_REQUIRED"));
            $group[]=&$this->form->createElement("advcheckbox", "WR_SC_{$n}",null, array('class'=>'form-control input-sm'));
            $this->XINRegisterRule("WR_SC_{$n}",
                array("WR_SC_{$n}{@}=={@}NEVER_REQUIRED"));
            $this->XINRegisterRule("WR_score_{$n}",
                array("WR_score_{$n}{@}=={@}NEVER_REQUIRED"));
            $this->form->addGroup(
                $group,
                "word_reading_table{$n}",
                null,
                $this->_GUIDelimiter,
                false
            );
            unset($group);
        }
        $this->addLabel("<h2>Raw Scores:</h2>");
        $this->addScoreColumn("word_reading_total_raw_score", "Word Reading Total Raw Score");
        $this->addScoreColumn("word_reading_total_3", "Word Reading Total >3");
        $this->addScoreColumn("word_reading_total_SC", "Word Reading Total SC");
        //$this->addScoreColumn("word_reading_speed_total_raw_score", "Word Reading Speed Total Raw Score(Item at 30sec)");
        //$this->form->createElement("text","word_reading_speed_total_raw_score", "Word Reading Speed Total Raw Score(Item at 30sec)");
        $this->addTextAreaElement("word_reading_speed_total_raw_score", "Word Reading Speed Total Raw Score(Item at 30sec)");
    }


}