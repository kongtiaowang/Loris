<?php
/**
 * This file contains the NDB_BVL_Instrument_wiatIII
 * class
 *
 * PHP Version 5
 *
 * @category Instrument
 * @package  Neuropsych
 * @author   Sruthy Mathew <sruthy.mcin@gmail.com>
 * @license  http://www.gnu.org/licenses/gpl-3.0.txt GPLv3
 * @link     https://www.github.com/aces/
 */
/**
 * Creates the form elements for the wiatIII instrument
 *
 * @category Instrument
 * @package  Neuropsych
 * @author   Sruthy Mathew <sruthy.mcin@gmail.com>
 * @license  http://www.gnu.org/licenses/gpl-3.0.txt GPLv_
 * @link     https://www.github.com/aces/
 */
require_once('NDB_BVL_Instrument_wiatIII.class.inc');
class NDB_BVL_Instrument_wiatIII_part_2 extends NDB_BVL_Instrument_wiatIII
{
    var $scoreLabels = array(
    "essay_composition_raw_score",
    "ec_CIWS_raw_score",
    "pwd_raw_score",
    "numerical_operation_raw_score",
    "orf_total_raw_score",
    "ora_total_raw_score",
    "orr_total_raw_score"


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
    function setup(?string $commentID = NULL, ?string $page = NULL): void
    {
        $this->formType = 'XIN';
        $this->form     = new LorisForm('wiatIII_part_2_form');
        $this->page     = $page;

        // set the object properties
        $this->testName = 'wiatIII_part_2'; // test_names.Test_name
        $this->table    = 'wiatIII_part_2'; // name of database
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
            "/wiatIII_part_2(_page[0-9]+)/",
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
        $this->addHeader("WIAT-III PART 2");

        $this->_addMetadataFields();
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


    function score(): void {
        if($this->_determineDataEntryCompletionStatus() == "Incomplete") {
            return;
        }
        //null scores
        $this->_nullScores($this->scoreLabels);
        $db =& Database::singleton();
        // Get the item scores
        $record= $db->pselectRow("SELECT * FROM $this->table WHERE CommentID=:cid", array('cid'=>$this->getCommentID()));
        $score = array();
        $scores["essay_composition_raw_score"]=$this->_rawScoreCalculator(1,6, "EC_score_");
        $scores["ec_CIWS_raw_score"]=$record["ec_CWS"] - $record["ec_IWS"];
        $scores["pwd_raw_score"]=$this->_rawScoreCalculatorRule(1,52,4, "PD_score_");
        $scores["numerical_operation_raw_score"]=$this->_rawScoreCalculatorRule(1,61,4, "numerical_operation");
        $scores["expressive_vocabulary_raw_score"]=$this->_rawScoreCalculatorRule(1,17,4, "ev");
        $scores["sentence_repetition_raw_score"]=$this->_rawScoreCalculatorRule(1,15,4, "sr");
        $scores["owf_grant_raw_score"] =  $record['owf_1_raw_score']+$record['owf_2_raw_score'];
        $scores["orf_total_raw_score"] = $this->_scoreOR("orf","oral_completion_","oral_additional_errors_","oral_errors_");
        $scores["ora_total_raw_score"] = $this->_scoreOR("ora","oral_completion_","oral_additional_errors_","oral_errors_");
        $scores["orr_total_raw_score"] = $this->_scoreOR("orr","oral_completion_","oral_additional_errors_","oral_errors_");
        $scores["spelling_raw_score"]=$this->_rawScoreCalculatorRule(1,63,4, "spelling");
        $result = $db->update($this->table, $scores, array('CommentID'=>$this->getCommentID()));
    }
    // page1 => Essay Composition
    function _page1(){
        $grade=$this->_getGradeCandidate();
        $exclude_grades_array= array("PK","K",1,2);
        if (in_array($grade, $exclude_grades_array)) {
            $this->form->addElement("static", null, '<font color="Red">This test is not applicable for Grade '.$grade.' Candidate. Please skip this test.</font>');

          }
        $this->addHeader("Essay Composition");
        $this->addLabel("<h3>Grades 3-12+</h3>");
        $group[] =& $this->form->createElement("static", null, null, "Item");
        $group[] =& $this->form->createElement("static", null, null, "Score");


        $this->form->addGroup(
            $group,
            "essay_composition_table{0}",
            null,
            $this->_GUIDelimiter,
            false
        );

        unset($group);

        $score1 = array(
            null => "",
            "3" => "3",
            "2" => "2",
            "1"=>"1",
            "0"=>"0"
        );
        $score2 = array(
            null => "",
            "5" => "5",
            "4"=>"4",
            "3"=>"3",
            "2" => "2",
            "1"=>"1",
            "0"=>"0"
        );
        $score3 = array(
            null => "",
            "2" => "2",
            "1"=>"1",
            "0"=>"0"
        );
        $questions = array(
            "Introduction",
            "Conclusion",
            "Paragraphs",
            "Transitions",
            "Reasons Why?",
            "Elaborations"
        );

        for ($i=0;$i<count($questions);$i++){
            $n = $i+1;
            if($n==1 ||$n==2)
                $opts=$score3;
            $group[]=&$this->form->createElement("static", null, null, "{$questions[$i]}");
            $group[]=&$this->form->createElement("select",  "EC_score_{$n}",null, $opts);


            $this->form->addGroup(
                $group,
                "essay_composition_table{$n}",
                null,
                $this->_GUIDelimiter,
                false
            );
            unset($group);
            $this->XINRegisterRule(
                "EC_score_{$n}",
                array("EC_score_{$n}{@}=={@}NEVER_REQUIRED"), // rule
                "Required.", // message
                "essay_composition_table{$n}" // group [if field is a part of a group]
            );

        }
        $this->addLabel("<h2>Raw Scores:</h2>");
        $this->addNumericElement("ec_word_count_raw_score", "Word Count Raw Score");
        $this->addScoreColumn("essay_composition_raw_score", "Word Reading Total Raw Score");
        $this->addNumericElement("ec_CWS", "CWS");
        $this->addNumericElement("ec_IWS", "IWS");
        $this->addScoreColumn("ec_CIWS_raw_score", "CIWS Total Raw Score");
        $this->XINRegisterRule(
            "ec_word_count_raw_score",
            array("ec_word_count_raw_score{@}=={@}NEVER_REQUIRED"),
            "Required."
        );
        $this->XINRegisterRule(
            "ec_CWS",
            array("ec_CWS{@}=={@}NEVER_REQUIRED"),
            "Required."
        );
        $this->XINRegisterRule(
            "ec_IWS",
            array("ec_IWS{@}=={@}NEVER_REQUIRED"),
            "Required."
        );

    }
    // page 2 Pseudoword Decoding
    function _page2(){
        $grade=$this->_getGradeCandidate();
        $exclude_grades_array= array("PK","K");
        if (in_array($grade, $exclude_grades_array)) {
            $this->form->addElement("static", null, '<font color="Red">This test is not applicable for Grade '.$grade.' Candidate. Please skip this test.</font>');

        }
        $this->addHeader("PseudoWord Decoding");
        $this->addLabel("<h3>(Grades 1-12+)</h3>");
        $this->addLabel("Discontinue Rule: Discontinue after 4 consecutive scores of 0.");
        $this->addLabel("Note: Start points and rules are considered for scoring.");

        $group[] =& $this->form->createElement("static", null, null, "Item");
        $group[] =& $this->form->createElement("static", null, null, "Score");


        $this->form->addGroup(
            $group,
            "word_decoding_table{0}",
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
            "1. ik",
            "2. ab",
            "3. fip",
            "4. rix",
            "5. seb",
            "6. zad",
            "7. sluck",
            "8. rith",
            "9. dreep",
            "10. snay",
            "11. droy",
            "12. joom",
            "13. clurt",
            "14. plid",
            "15. caft",
            "16. lirst",
            "17. ched",
            "18. glatch",
            "19. taph",
            "20. sorb",
            "21. tuffle ",
            "22. ruckid",
            "23. heffle",
            "24. pragment",
            "25. scaw",
            "26. broan",
            "27. wung",
            "28. waim",
            "29. stight",
            "30. style",
            "31. floit",
            "32. unfrodding",
            "33. smaut",
            "34. knep",
            "35. retashment",
            "36. intrections",
            "37. tellitry",
            "38. mudger",
            "39. tumingly",
            "40. ostique",
            "41. rinion",
            "42. tufle",
            "43. libnations",
            "44. hefle",
            "45. eminacious",
            "46. purellian",
            "47. psibertarian",
            "48. apturarial",
            "49. diminecial",
            "50. millemignalian",
            "51. preembutryic",
            "52. diphthalbarbadinyl"
        );

        for ($i=0;$i<count($questions);$i++){
            $n = $i+1;
            $group[]=&$this->form->createElement("static", null, null, "{$questions[$i]}");
            $group[]=&$this->form->createElement("select",  "PD_score_{$n}",null, $opts);


            $this->form->addGroup(
                $group,
                "pseudo_decode_table{$n}",
                null,
                $this->_GUIDelimiter,
                false
            );
            unset($group);
            $this->XINRegisterRule(
                "PD_score_{$n}",
                array("PD_score_{$n}{@}=={@}NEVER_REQUIRED"), // rule
                "Required.", // message
                "pseudo_decode_table{$n}" // group [if field is a part of a group]
            );

        }
        $this->addLabel("<h2>Raw Scores:</h2>");
        $this->addScoreColumn("pwd_raw_score", "Pseudocode Word Decoding Total Raw Score");
        $this->addTextElement("pwd_speed_raw_score", "Pseudocode Word Decoding Speed Total Raw Score(Item completed at 30 secs)");
        $this->XINRegisterRule(
            "pwd_speed_raw_score",
            array("pwd_speed_raw_score{@}=={@}NEVER_REQUIRED"),
            "Required."
        );

    }
    function _page3()
    {    $grade=$this->_getGradeCandidate();
        $exclude_grades_array= array("PK");
        if (in_array($grade, $exclude_grades_array)) {
            $this->form->addElement("static", null, '<font color="Red">This test is not applicable for Grade '.$grade.' Candidate. Please skip this test.</font>');

        }
        $this->addLabel("<h2>Numerical Operation</h2>");
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
            "numerical_operation_table{0}",
            null,
            $this->_GUIDelimiter,
            false
        );
        unset($group);


        $questions = [
            ["Grades K-1<br>1. Point to Item 1 and say, Here are some boils. Count them. How many balls are there?",
                "(0) 5" ],
            ["2. Point to the box beside Item 2 and say, Write that number here. Write the number of balls you counted.","(W) 5 Penalize for reversed and unrecognizable numbers."],
            ["3. Point to Item 3 and say, Here are some fetters and numbers. Draw a circle around each number. Circle only the numbers.","No letters, circles all numbers: 3, 2, 5, 4"],
            ["4. Point to each box in Item 4 and say, Here are groups of triangles. Draw a circle 	around the group of 6 triangles","Circles 6 triangles (bottom left)"],
            ["5. Point to Item 5 and say, Here are numbers from 1 to 10, but one number has been left out. Point to the blank line. Write the number that was left out.","(W) 8"],
            ["6. Sweep your finger from left to right across the row for Items 6-7 and say, Look at each of these. Point to the one that means \"add\" or \"plus.\"","(P) +"],
            ["7. Again, sweep your finger from left to right across the row for Items 6-7 and say, Look at each of these again. Point to the one that means \"subtract\" or \"take away","(P) -"],
            ["8. 1 + 1","2"],
            ["9. 1 + 2","3"],
            ["10. 3 + 1.", "4"],
            ["11. 3 + 3","6"],
            ["12. 4 + 1","5"],
            ["13. 5 + 5 ","10"],
            ["Grades 2-4<br>14. 3 - 1 ","2"],
            ["15. 6 - 2","4"],
            ["16. 5 + 1 + 5 + 2","13"],
            ["17. 7 + 6","13"],
            ["Grades 5-12+<br>18. 12 - 5","7"],
            ["19. 63 + 16","79"],
            ["20. 5 x 5 ","25"],
            ["21. 4 x 3 ","12"],
            ["22. 6 x 5 ","30"],
            ["23. 865 + 236","1106"],
            ["24. 70 - 24 ","46"],
            ["25. 140 - 15 ","125"],
            ["26. 24  ÷ 6","4"],
            ["27. 	29 x 6 ","174"],
            ["28. 	7 x 9 ","53"],
            ["29. 	49 ÷ 7 +3 ","10"],
            ["30. 6/7 + 3/7", "9/7 or 1 2/7"],
            ["31. 72 ÷ 3","24"],
            ["32. 4z + 1 = 9","2"],
            ["33. 906 + 488","418"],
            ["34. -25 + (-2)","-27"],
            ["35. 834 ÷ 6","139"],
            ["36. pi","3.14"],
            ["37. Simplify 10/55","2/11"],
            ["38. 5z- 3 = 11 + 3z","7"],
            ["39. 594 ÷ 22 ","27"],
            ["40. 12x -6 =6x ÷ 18","4"],
            ["41. 408 x 321", "130,968"],
            ["42. 2/3 x 30","20"],
            ["43. order of operations","225"],
            ["44. (z+ 2)(z- 1)=0","-2,1"],
            ["45. 400% of 80","320"],
            ["46. 4/5 ÷ 2/10","4"],
            ["47. area of triangle","50 sq.inches"],
            ["48. solve for x and y","x =15, y =3"],
            ["49. geometry","Solve al three:AB=12 BC=12, AC=6"],
            ["50. find f(1)","0"],
            ["51. simplify","b5"],
            ["52. 21.5 ÷ 4","5.375"],
            ["53. geometry","17"],
            ["54. logarithm","16"],
            ["55. simplify","z9"],
            ["56. trigonometry","Solves all three:tan A = 4/3 sin B = 3/5 cos A =3/5"],
            ["57, factor","3xy(xy + 2y -1)"],
            ["58. find the limit","0"],
            ["59. find the limit","0"],
            ["60. differentiate","15(5x -4)2"],
            ["61. integrate","10.5 or 10 1/2 or 21/2"]
        ];

        for ($i = 0; $i<count($questions); $i++){
            $n = 1 + $i;
            $group[] =& $this->form->createElement("static", null, null, "{$questions[$i][0]}");
            $group[] =& $this->form->createElement("static", null, null, "{$questions[$i][1]}");
            $group[] =& $this->form->createElement("select", "numerical_operation{$n}", null, $opts);
            $this->form->addGroup(
                $group,
                "numerical_operation_table{$n}",
                null,
                $this->_GUIDelimiter,
                false
            );
            unset($group);
            $this->XINRegisterRule(
                "numerical_operation{$n}",
                array("numerical_operation{$n}{@}=={@}NEVER_REQUIRED"), // rule
                "Required.", // message
                "numerical_operation_table{$n}" // group [if field is a part of a group]
            );

        }

        $this->addLabel("<h2>Raw Scores:</h2>");

        $this->addScoreColumn("numerical_operation_raw_score", "Numerical Operation Raw Score");
    }
    function _page4()
    {
        $this->addLabel("<h2>Oral Expression</h2>");
        $this->addLabel("<h3>1. Expressive Vocabulary</h3>");
        $this->addLabel("<h4>Grades PK-12+</h4>");
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
            "oe_ev_table{0}",
            null,
            $this->_GUIDelimiter,
            false
        );
        unset($group);


        $questions = [
            ["1. Say, Look at this picture. Tell me the word that means a brush for cleaning teeth", "Toothbrush" ],
            ["2. Say, Tell me the word that means a flying insect with large, brightly colored wings.","Butterfly; Moth"],
            ["3. Say, Tell me the word that means a small place where clothes are stored.","Closet; Wardrobe"],
            ["4. Say, Tell me the word that means to move on hands and knees.","Crawl; Crawling"],
            ["5. Say, Tell me the word that means a small electronic device used to do math problems.","Calculator"],
            ["6. Say, Tell me the word that means not crooked","Straight"],
            ["7. Say, Tell me the word that means to find how long something is.","Measure; Measuring"],
            ["8. Say, Tell me the word that means the port of the piano played with the fingers.","Keys; Keyboard"],
            ["9. Say, Tell me the word that means the place where two roads cross.f the student says crossroad or corner, Q: Tell me another word that means the place where two roads cross.","Intersection"],
            ["10. Say, Tell me the word that means to make your choice known in an election.", "Vote; Voting"],
            ["11. Say, Tell me the word that means to change the way you look, so others won't recognize you.If the student says mask, Q: Tell me another word that means to change the way you look, so others won't recognize you.","Disguise;
Masquerade "],
            ["12. Say, Tell me the word that means to break loose or get free.","Escape; Liberate; 	Emancipate;Extricate"],
            ["13. Say, Tell me the ward that means a person who is walking.If the student says walker, Q: Tell me another word that means a person who is walking,","Pedestrian"],
            ["14. Say, Tell use the word that means a long piece of land that Juts out into a sea or lake. ","Peninsula"],
            ["15. Say, Tell me the word that means able to use both hands equally well.","Ambidextrous"],
            ["16. Say, Tell me the word that means a fertile, green area where water can be found in a desert","Oasis"],
            ["17. Say, Tell me the ward that means a person who is at least 100 years old.","Centenarian"]
        ];

        for ($i = 0; $i<count($questions); $i++){
            $n = 1 + $i;
            $group[] =& $this->form->createElement("static", null, null, "{$questions[$i][0]}");
            $group[] =& $this->form->createElement("static", null, null, "{$questions[$i][1]}");
            $group[] =& $this->form->createElement("select", "ev{$n}", null, $opts);
            $this->form->addGroup(
                $group,
                "oe_ev_table{$n}",
                null,
                $this->_GUIDelimiter,
                false
            );
            unset($group);
            $this->XINRegisterRule(
                "ev{$n}",
                array("ev{$n}{@}=={@}NEVER_REQUIRED"), // rule
                "Required.", // message
                "oe_ev_table{$n}" // group [if field is a part of a group]
            );

        }


        $this->addHeader("Oral Expression - Oral Word Fluency");
        $this->addTextAreaElement("owf_1", "Item 1:Animals: ");
        $this->addNumericElement("owf_1_raw_score", "Item 1 Raw Score ");
        $this->addTextAreaElement("owf_2", "Item 2:Colors: ");
        $this->addNumericElement("owf_2_raw_score", "Item 1 Raw Score ");

        $this->addLabel("<h2>Oral Expression - Sentence Repetition</h2>");

        $opts = array(null => "",
            "dk" => "DK",
            "2" => "2",
            "1" => "1",
            "0" => "0");

        $group[]=& $this->form->createElement("static", null, null, "Item");
        $group[]=& $this->form->createElement("static", null, null, "Score");
        $this->form->addGroup(
            $group,
            "oe_sr_table{0}",
            null,
            $this->_GUIDelimiter,
            false
        );
        unset($group);


        $questions=[
            "Games are fun.",
            "Cats don't like to swim.",
            "That is mine, but this one is yours.",
            "It is cold outside and many of the roads are icy.",
            "When you go climbing, watch for falling rocks.",
            "The bird escaped from the cage and flew out the window.",
            "Unless you have permission, you are not allow to go to swimming",
            "I walked tothe store and bought a sandwich, an apple, and a drink.",
            "The cat was asleep by the window while the dog chased butterflies in the grass.",
            "I studied every day this week for the exam, so I think I will get a good grade.",
            "That restaurant has become popular since it moved to a new location last summer.",
            "The man wanted to keep the wallet he found on the ground, yet he knew it was not the right thing to do.",
            "The animals at the zoo had gone inside because of the heat, so we did not see a single one.",
            "The baby always used to cry when her mother leftthe room, and nothing but hers mother's return would stop her crying.",
            "The driver charged everyone the same fee for the trip, but when the bus got stuck in the mud all the money had to be refunded."
        ];

        for ($i = 0; $i<count($questions); $i++){
            $n = 1 + $i;
            $group[] =& $this->form->createElement("static", null, null, "{$n}. {$questions[$i]}");
            $group[] =& $this->form->createElement("select", "sr{$n}", null, $opts);
            $this->form->addGroup(
                $group,
                "oe_sr_table{$n}",
                null,
                $this->_GUIDelimiter,
                false
            );
            unset($group);
            $this->XINRegisterRule(
                "sr{$n}",
                array("sr{$n}{@}=={@}NEVER_REQUIRED"), // rule
                "Required.", // message
                "oe_sr_table{$n}" // group [if field is a part of a group]
            );

        }

        $this->addLabel("<h2>Raw Scores:</h2>");
        $this->addScoreColumn("expressive_vocabulary_raw_score", "Expressive Vocabulary Raw Score");
        $this->addScoreColumn("owf_grant_raw_score", "Oral Word Fluency Raw Score");
        $this->addScoreColumn("sentence_repetition_raw_score", "Sentence Repetition Raw Score");


    }
    // Oral Reading Fluency
    function _page5()
    {
        $grade=$this->_getGradeCandidate();
        $exclude_grades_array= array("PK","K");
        if (in_array($grade, $exclude_grades_array)) {
            $this->form->addElement("static", null, '<font color="Red">This test is not applicable for Grade '.$grade.' Candidate. Please skip this test.</font>');

        }
        $this->addHeader("Oral Reading Fluency");
        $this->addLabel("<h3>(Grades 1-12+)</h3>");
        $this->addLabel("Item Set Reverse Rule");
        $this->addLabel("Note: Start points, stop points and rules are considered for scoring.");
        switch($grade)
        {
            case 1:
                $this->addLabel("The grade appropriate passages are A & B.");
                break;
            case 2:
                $this->addLabel("The grade appropriate passages are C & D.");
                break;
            case 3:
                $this->addLabel("The grade appropriate passages are E & F.");
                break;
            case 4:
                $this->addLabel("The grade appropriate passages are G & H.");
                break;
            case 5:
                $this->addLabel("The grade appropriate passages are I & J.");
                break;
            case 6:
                $this->addLabel("The grade appropriate passages are K & L.");
                break;
            case 7:
            case 8:
                $this->addLabel("The grade appropriate passages are M & N.");
                break;
            default:
                $this->addLabel("The grade appropriate passages are O & P.");



        }
        $group[]=& $this->form->createElement("static", null, null, "Passage");
        $group[]=& $this->form->createElement("static", null, null, "Question");
        $group[]=& $this->form->createElement("static", null, null, "Correct Answer");
        $group[]=& $this->form->createElement("static", null, null, "Student response");
        $group[]=& $this->form->createElement("static", null, null, "Correct/Incorrect");
        $opts = array(null => "",
            "correct" => "Correct",
            "Incorrect" => "Incorrect",
            );
        $items = [
            ["Passage A","Which three animals were seen?","Cat, Fish, Dog"],
            ["Passage B","Where did Pat put the little ball?", "In the box"],
            ["Passage C","When young turtles come out of their nests, what do they look for?","Bright lights"],
            ["Passage D","According to the passage, what should you bring with you when exploring caves?","Flashlight, extra batteris and light bulbs"],
            ["Passage E","According to the passage, what kind of tree might you find in a healthy forest?", "Snag/dead tree"],
            ["Passage F","What did Maria's great grandfather strap to the pigeons?","(Tiny) camera(s)"],
            ["Passage G","What does the author like to do by moonlight?","Take a walk"],
            ["Passage H","According to the passage, what happens to a peacock's feathers every spring?","They are renewed /They grow back"],
            ["Passage I","What does the passage say people should stay away front while walking along the beach?","Logs"],
            ["Passage J","Why did the boy steal Mark Twain's boots?","To become a great writer"],
            ["Passage K","According to the passage, what problems did oceans cause for people in the past?","Made travel and trade difficult"],
            ["Passage L","According to the passage, how do greyhounds tend to act around strangers?", "Shy"],
            ["Passage M","What mistake did the author make when building a fish tank?",    "Stuck the glass in upside down"],
            ["Passage N","According to the passage, why is Antarctica called the most peaceful place on Earth?","No wars; No country rules over it; Anyone can visit"],
            ["Passage O","According to the passage, what do many people mistakenly believe comes out of an active volcano", "Smoke and flame"],
            ["Passage P","According to the passage, what was the purpose of the Chicago Transit Posters?","Advertise the\"L\" train; Encourage     people to ride the \"L\" more"]
        ];
        $this->form->addGroup(
            $group,
            "oral_fluency_raw_table_one{0}",
            null,
            $this->_GUIDelimiter,
            false
        );
        unset($group);
        for ($i=0; $i<count($items); $i++) {
            $n = $i + 1;
            $group[] =& $this->form->createElement("static", null, null, "{$items[$i][0]}");
            $group[] =& $this->form->createElement("static", null, null, "{$items[$i][1]}");
            $group[] =& $this->form->createElement("static", null, null, "{$items[$i][2]}");
            $group[] =& $this->form->createElement("textarea", "oral_reading_response{$n}", null,null);
            $group[] =& $this->form->createElement("select", "oral_reading_response_status{$n}", null,
                $opts
            );

            $this->form->addGroup(
                $group,
                "oral_fluency_raw_table_one{$n}",
                null,
                $this->_GUIDelimiter,
                false
            );
            unset($group);
            $array_vals_1=array("oral_reading_response_status","oral_reading_response");


                   foreach($array_vals_1 as $vals1) {
                            $this->XINRegisterRule(
                                "$vals1{$n}",
                                array("$vals1{$n}{@}=={@}NEVER_REQUIRED"), // rule
                                "Required.", // message
                                "oral_fluency_raw_table_one{$n}" // group [if field is a part of a group]
                            );

                   }


        }
        $this->addHeader("Oral Reading Fluency Subtotal Raw Scores");
        $this->addLabel("<h5><i>*Please add numeric values only for accurate scoring</i></h5>");

        $group[]=& $this->form->createElement("static", null, null, "Passage");
        $group[]=& $this->form->createElement("static", null, null, "Completion Time");
        $group[]=& $this->form->createElement("static", null, null, "Additional Errors");
        $group[]=& $this->form->createElement("static", null, null, "Other Errors");
        $group[]=& $this->form->createElement("static", null, null, "Word Count");
        $items = [
            ["Passage A",33],
            ["Passage B",93],
            ["Passage C",97],
            ["Passage D",96],
            ["Passage E",99],
            ["Passage F",113],
            ["Passage G",119],
            ["Passage H",136],
            ["Passage I",201],
            ["Passage J",258],
            ["Passage K",213],
            ["Passage L",207],
            ["Passage M",298],
            ["Passage N",194],
            ["Passage O",212],
            ["Passage P",163]
        ];

        $this->form->addGroup(
            $group,
            "oral_fluency_raw_table{0}",
            null,
            $this->_GUIDelimiter,
            false
        );
        unset($group);


        for ($i=0; $i<count($items); $i++) {
            $n = $i + 1;



            $group[] =& $this->form->createElement("static", null, null, "{$items[$i][0]}");
            $group[] =& $this->form->createElement("text", "oral_completion_$n",null,null);
            $group[] =& $this->form->createElement("text", "oral_additional_errors_$n",null,null);
            $group[] =& $this->form->createElement("text", "oral_errors_$n", null,null);
            $group[] =& $this->form->createElement("static", null, null, "{$items[$i][1]}");

            $this->form->addGroup(
                $group,
                "oral_fluency_raw_table$n",
                null,
                $this->_GUIDelimiter,
                false
            );
            unset($group);



            $array_vals_1=array("oral_completion_","oral_additional_errors_","oral_errors_");


                        foreach ($array_vals_1 as $vals1) {

                            $this->XINRegisterRule(
                                "$vals1{$n}",
                                array("$vals1{$n}{@}=={@}NEVER_REQUIRED"),
                                "Required.", // message
                                "oral_fluency_raw_table{$n}" // group [if field is a part of a group]
                            );
                            //$this->XINRegisterRule($field,array("$field{@}=={@}NEVER_REQUIRED"), $field . "_group");
                            unset($group);
                            //
                            //$this->addGroupRule("oral_fluency_raw_table{$n}", array(array(array("Value must be numeric.", 'numeric'))));
                        }

                    $group[] =& $this->form->createElement("static", null, null, " ");

            $this->form->addGroup(
                $group,
                "oral_fluency_raw_table_blank{$n}",
                null,
                $this->_GUIDelimiter,
                false
            );
            unset($group);

        }

        $this->addLabel("<h3>Raw Scores:</h3>");
        $this->addLabel("<h4><i>Only grade appropriate raw scores will be calculated.</i></h4>");
        $this->addScoreColumn("orf_total_raw_score", "Oral Reading Fluency Total Raw Score");
        $this->addScoreColumn("ora_total_raw_score", "Oral Reading Accuracy Total Raw Score");
        $this->addScoreColumn("orr_total_raw_score", "Oral Reading Rate Total Raw Score");

       // $this->form->addFormRule(array(&$this, 'wiatIII_Rules'));



    }
    function _page6()
    {
        $grade=$this->_getGradeCandidate();
        $exclude_grades_array= array("PK");
        if (in_array($grade, $exclude_grades_array)) {
            $this->form->addElement("static", null, '<font color="Red">This test is not applicable for Grade '.$grade.' Candidate. Please skip this test.</font>');

        }
        $this->addLabel("<h2>Spelling</h2>");
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
            "spelling_table{0}",
            null,
            $this->_GUIDelimiter,
            false
        );
        unset($group);


        $questions = [
            ["Grades K-1<br> 1. Next to number 1 (point to the appropriate line), please write your first name.",
                "First name spelled correctly, disregard capitalization"],
            ["Say, 2. Write the letter that makes the \a\ sound In apple.","A or a, disregard reversals."],
            ["Say, 3. Write the letter that makes the \z\ sound In zoo.","Z or z, disregard reversals."],
            ["Say, 4. Write the letterthatmakes the \j\ sound In jump.","J or j, disregard reversals."],
            ["Say, 5. Write the letter that makes the \k\ sound in kite","K or k, disregard reversals."],
            ["Say, 6. Cat.The cat is chasing a mouse.Cat.","cat"],
            ["Grade 2<br> Say, 7. In.My books are in my room.In. ","in"],
            ["Say, 8. Be.Be careful.Be.","be"],
            ["Grade 3<br> Say, 9.  Game.The children played a game outside.Game.","game"],
            ["Say, 10. Fix.She used tape to fix the book. Fix.", "fix"],
            ["Say, 11. Cake. I had cake for dessert. Cake.","cake"],
            ["Say, 12. Cold.It is cold outside.Cold.","cold"],
            ["Say, 13. Tall.The bird made a nest in a tall tree.TaIl.","tall"],
            ["Say, 14. Mother.The child asked his mother for a cookie.Mother.","mother"],
            ["Say, 15. Night.The stars can be seen at night. Night.","night"],
            ["Grades 4-8<br> Say, 16. Page.The book was missing a page.Page","page"],
            ["Say, 17.  Began.Class began five minutes late.Began.","began"],
            ["Say, 18. Windy. On windy days, the leaves blow through the air. Windy","windy"],
            ["Say, 19. Camped. We camped in the forest and slept in a tent. Camped.","camped"],
            ["Grades 9-12+<br>Say, 20. Suspect, The suspect was arrested at the bank. Suspect.","Suspect"],
            ["Say, 21. Inactive. People are usually inactive while watching television. Inactive.","inactive"],
            ["Say, 22. Known.The author was known throughout the world. Known.","known"],
            ["Say, 23. Happily. The characters lived happily ever after. Happily.","happily"],
            ["Say, 24. Stationary. Stationary objects do not move. Stationary.","stationary"],
            ["Say, 25. Collection. I have a collection of coins. Collection.","collection"],
            ["Say, 26. Budget. A budget helps to organize finances, Budget.","budget"],
            ["Say, 27. Width.The width of the door was too narrow for the box to fit through. Width.","width"],
            ["Say, 28. Guitar. I am learning how to play the guitar. Guitar.","guitar"],
            ["Say, 29. Photography. Photography Is a hobby of mine. Photography.","photography"],
            ["Say, 30. Factual. A factual statement Is true. Factual.", "factual"],
            ["Say, 31. Resig n.1 want to resign and start a new job. Resign.","resign"],
            ["Say, 32. Doubt. I doubt it will rain today because the sky is clear. Doubt.","doubt"],
            ["Say, 33. Progressive. Progressive research uses new ideas to make advances. Progressive.","progressive"],
            ["Say, 34. Suppose. I studied for the test, so I suppose VII do well, Suppose.","suppose"],
            ["Say, 35. Confide. I will confide in you If you will keep a secret. ","confide"],
            ["Say, 36. Resistance. A healthy diet may improve our resistance to illness. Resistance.","resistance"],
            ["Say, 37. Exerting. I opened the heavy door by exerting pressure. Exerting.","exerting"],
            ["Say, 38, Presence. The dog barks in the presence of a stranger. Presence,","presence"],
            ["Say, 39. Reign, The queen would reign for fifty years. Reign.","reign"],
            ["Say, 40. Ambitious. To become a world leader is an ambitious goal. Ambitious.","ambitious"],
            ["Say, 41, Outrageous. The announcer's outrageous comments made the crowd laugh. Outrageous.", "Outrageous"],
            ["Say, 42. Sympathetic. I felt sympathetic towards the crying baby. Sympathetic.","sympathetic"],
            ["Say, 43, Leisure. In my leisure time, I enjoy watching movies. Leisure.","leisure"],
            ["Say, 44. Oxidize. Oxygen causes copper to oxidize. Oxidize.","oxidize"],
            ["Say, 45. Achievement. Graduating from high school is an important achievement. Achievement.","achievement"],
            ["Say, 46. Absurd. It is absurd to think you can get water out of a stone. Absurd.","absurd"],
            ["Say, 47. Kindliness. I try to practice kindliness with everyone I meet. Kindliness.","kindliness"],
            ["Say, 48. Metabolize. Exercise helps our bodies metabolize food. Metabolize.","metabolize"],
            ["Say, 49. Exhaustion.The runner collapsed from exhaustion after the marathon. Exhaustion.","exhausition"],
            ["Say, 50. Affluent. Many people cannot afford to live in an affluent neighborhood. Affluent.","affluent"],
            ["Say, 51. Flirtatious. The male peacock showed off his feathers in a flirtatious manner. Flirtatious.","flirtatious"],
            ["Say, 52, Stasis. During a time of stasis, little or no change occurs. Stasis.","statsis"],
            ["Say, 53. Recieving. My teacher enjoys recieving letters from students. Recieving.","recieving"],
            ["Say, 54. Heterodox. Heterodox beliefs do not agree with traditional beliefs. Heterodox.","heterodox"],
            ["Say, 55. Vacuum. I vacuum the rug once a week. Vacuum.","vaccum"],
            ["Say, 56. Conferred. I conferred with my lawyer before making a decision. Conferred.","conferred"],
            ["Say, 57. Physicist. A physicist studies the natural world. Physicist.","physcist"],
            ["Say, 58. Recede. L waited for the tide to recede before looking for seashells. Recede.","recede"],
            ["Say, 59. Perceived. The audience percefvedthe nervousness in the speaker's voice. Perceived.","percieved"],
            ["Say, 60. Abhors. My friend abhors insects and avoids them at all cost. Abhors.","adhors"],
            ["Say, 61. Marionette. There was a dancing marionette in the talent show. Marionette.","marionette"],
            ["Say, 62 Impeccable. After studying for many years, the student speaks impeccable French.", "impeccable"],
            ["Say, 63. Gherkin. A gherkin is a young, pickled cucumber. Gherkin.","gherkin"]
        ];

        for ($i = 0; $i<count($questions); $i++){
            $n = 1 + $i;
            $group[] =& $this->form->createElement("static", null, null, "{$questions[$i][0]}");
            $group[] =& $this->form->createElement("static", null, null, "{$questions[$i][1]}");
            $group[] =& $this->form->createElement("select", "spelling{$n}", null, $opts);
            $this->form->addGroup(
                $group,
                "spelling_table{$n}",
                null,
                $this->_GUIDelimiter,
                false
            );
            unset($group);
            $this->XINRegisterRule(
                "spelling{$n}",
                array("spelling{$n}{@}=={@}NEVER_REQUIRED"), // rule
                "Required.", // message
                "spelling_table{$n}" // group [if field is a part of a group]
            );

        }

        $this->addLabel("<h2>Raw Scores:</h2>");

        $this->addScoreColumn("spelling_raw_score", "Spelling Raw Score");

    }
    function _page7()
    {
        $this->addHeader("Math Fluency - Addition");
        $this->addSelect("math_addition_elapsed_time", "Elapsed Time: ",
            array(null=> "",
                "30_sec" => "60 Seconds",
                "other"=>"Other"
            ));
        $this->addTextElement("math_addition_other_time", "If other, number of seconds: ");
        $this->addNumericElement("math_addition_raw_score", "Math Fluency- Addition - Total Row Score: ");
        $this->XINRegisterRule(
            "math_addition_other_time",
            array("math_addition_elapsed_time{@}=={@}other"),
            "Required",
            "math_addition_other_time_group"
        );
        $this->addHeader("Math Fluency - Subtraction");
        $this->addSelect("math_subtr_elapsed_time", "Elapsed Time: ",
            array(null=> "",
                "30_sec" => "60 Seconds",
                "other"=>"Other"
            ));
        $this->addTextElement("math_subtr_other_time", "If other, number of seconds: ");
        $this->addNumericElement("math_subtr_raw_score", "Math Fluency- Subtraction - Total Row Score: ");
        $this->XINRegisterRule(
            "math_subtr_other_time",
            array("math_subtr_elapsed_time{@}=={@}other"),
            "Required",
            "math_subtr_other_time_group"
        );
        $this->addHeader("Math Fluency - Multiplication");
        $this->addSelect("math_mult_elapsed_time", "Elapsed Time: ",
            array(null=> "",
                "30_sec" => "60 Seconds",
                "other"=>"Other"
            ));
        $this->addTextElement("math_mult_other_time", "If other, number of seconds: ");
        $this->addNumericElement("math_mult_raw_score", "Math Fluency- Multiplication - Total Row Score:");
        $this->XINRegisterRule(
            "math_mult_other_time",
            array("math_mult_elapsed_time{@}=={@}other"),
            "Required",
            "math_mult_other_time_group"
        );
    }


}
