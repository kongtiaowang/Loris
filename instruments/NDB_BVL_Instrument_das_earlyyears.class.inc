<?php

class NDB_BVL_Instrument_das_earlyyears extends NDB_BVL_Instrument
{
    use LegacyInstrumentTrait;

    /*
     * NOTE! WHEN GENERATING THE SQL FILE, MUST CHANGE VARCHARS TO TEXT
     * (EXCEPT THE DEFAULT `CommentID`,`UserID`,`Examiner`,`Testdate`,`Data_entry_completion_status`,`Candidate_Age`,`Window_Difference`)
     * OR SPACE WILL RUN OUT AND CANNOT SOURCE THE SQL FILE
     */


    // TO DO:

    // _score()

    // ASP & DPs
    // age constraints
    // second attempts??
    // forced numbers

    // FIX CODE FOR NUMBER CORRECT

    // END


    /*
    INSERT INTO test_names (Test_name, Full_name, Sub_group) VALUES ('das_earlyyears', 'DAS (Differential Ability
    Scales) - Early Years', '1');

    INSERT INTO instrument_subtests (Test_name, Subtest_name, Description, Order_number) VALUES ('das_earlyyears',
    'das_earlyyears_page1', 'Verbal Comprehension', 1);
    INSERT INTO instrument_subtests (Test_name, Subtest_name, Description, Order_number) VALUES ('das_earlyyears',
    'das_earlyyears_page2', 'Picture Similarities', 2);
    INSERT INTO instrument_subtests (Test_name, Subtest_name, Description, Order_number) VALUES ('das_earlyyears',
    'das_earlyyears_page3', 'Naming Vocabulary', 3);
    INSERT INTO instrument_subtests (Test_name, Subtest_name, Description, Order_number) VALUES ('das_earlyyears',
    'das_earlyyears_page4', 'Recall of Objects - Immediate', 4);
    INSERT INTO instrument_subtests (Test_name, Subtest_name, Description, Order_number) VALUES ('das_earlyyears',
    'das_earlyyears_page5', 'Pattern Construction', 5);
    INSERT INTO instrument_subtests (Test_name, Subtest_name, Description, Order_number) VALUES ('das_earlyyears',
    'das_earlyyears_page6', 'Matrices', 6);
    INSERT INTO instrument_subtests (Test_name, Subtest_name, Description, Order_number) VALUES ('das_earlyyears',
    'das_earlyyears_page7', 'Recall of Objects - Delayed', 7);
    INSERT INTO instrument_subtests (Test_name, Subtest_name, Description, Order_number) VALUES ('das_earlyyears',
    'das_earlyyears_page8', 'Copying', 8);
    INSERT INTO instrument_subtests (Test_name, Subtest_name, Description, Order_number) VALUES ('das_earlyyears',
    'das_earlyyears_page9', 'Recall of Digits Forward', 9);
    INSERT INTO instrument_subtests (Test_name, Subtest_name, Description, Order_number) VALUES ('das_earlyyears',
    'das_earlyyears_page10', 'Recognition of Pictures', 10);
    INSERT INTO instrument_subtests (Test_name, Subtest_name, Description, Order_number) VALUES ('das_earlyyears',
    'das_earlyyears_page11', 'Early Number Concepts', 11);
    INSERT INTO instrument_subtests (Test_name, Subtest_name, Description, Order_number) VALUES ('das_earlyyears',
    'das_earlyyears_page12', 'Matching Letter-Like Forms', 12);
    INSERT INTO instrument_subtests (Test_name, Subtest_name, Description, Order_number) VALUES ('das_earlyyears',
    'das_earlyyears_page13', 'Recall of Sequential Order', 13);
    INSERT INTO instrument_subtests (Test_name, Subtest_name, Description, Order_number) VALUES ('das_earlyyears',
    'das_earlyyears_page14', 'Speed of Information Processing', 14);
    INSERT INTO instrument_subtests (Test_name, Subtest_name, Description, Order_number) VALUES ('das_earlyyears',
    'das_earlyyears_page15', 'Recall of Digits Backward', 15);
    INSERT INTO instrument_subtests (Test_name, Subtest_name, Description, Order_number) VALUES ('das_earlyyears',
    'das_earlyyears_page16', 'Phonological Processing', 16);
    INSERT INTO instrument_subtests (Test_name, Subtest_name, Description, Order_number) VALUES ('das_earlyyears',
    'das_earlyyears_page17', 'Optional Core Analysis', 17);
    INSERT INTO instrument_subtests (Test_name, Subtest_name, Description, Order_number) VALUES ('das_earlyyears',
    'das_earlyyears_page18', 'Behavioral Observations', 18);

    INSERT INTO test_battery (Test_name, AgeMinDays, AgeMaxDays, Active, Stage, SubprojectID, Visit_label, CenterID)
    VALUES ('das_earlyyears', '1', '99999', 'Y', 'Visit', '1', 'V37Plus', NULL);
    */


    var $j = 1;
    var $answerArray = array(""=>NULL, 0=>0, 1=>1, "not_answered"=>"Not Answered");
    var $responseArray = array(""=>NULL, 1=>1, 2=>2, 3=>3, 4=>4, "not_answered"=>"Not
        Answered");
    var $yesNoNa = array(""=>NULL, "yes"=>"Yes", "no"=>"No", "not_answered"=>"Not Answered");


    /*
     * sets up basic data, such as the LorisForm object, and so on.
     *
     * @param string $commentID  the CommentID identifying the data to load
     * @param string $page       if a multipage form, the page to show
     * @return void
     * @access public
     */
    function setup(?string $commentID = NULL, ?string $page = NULL): void
    {

        $this->formType="XIN";
        $this->form = new LorisForm('test_form');
        $this->page = $page;            // page label (number or
        // string - used by
        // user-defined child classes)

        // object properties
        $this->testName = "das_earlyyears";
        $this->table = 'das_earlyyears';
        // data keyed by commentID
        $this->commentID = $commentID;

        //The array of dates/timestamps to convert to database dates/timestamps
        //Any LorisForm date elements must be listed here
        $this->dateTimeFields=array("Date_taken");

        //The array of selects with multiple answers allowed
        //Any LorisForm multiple selects must be listed here
        $this->selectMultipleElements = array();

        // required fields for data entry completion status
        $this->_requiredElements = array('Examiner');

        // Array of column names to be ignored by the double data entry conflict detector
        $this->_doubleDataEntryDiffIgnoreColumns =
            array('CommentID', 'UserID', 'Testdate',  'Window_Difference', 'Candidate_Age',
                'other_comments1',
                'other_comments2',
                'other_comments3',
                'other_comments4',
                'other_comments5',
                'other_comments6',
                'other_comments7',
                'other_comments8',
                'other_comments9',
                'other_comments10',
                'other_comments11',
                'other_comments12',
                'other_comments13',
                'other_comments14',
                'other_comments15',
                'other_comments16',
                'other_comments17'
            );

        // setup the form
        $this->_setupForm();

    }


    /*
     * method to build the LorisForm object into a paged form
     *
     * @return void
     * @access private
     */
    function _setupForm() {

        if (preg_match("/das_earlyyears(_page[0-9]+)/", $this->page, $matches)) {
            call_user_func(array($this, $matches[1]));
        } else {
            $this->_main();
        }
        //Defines the call back function for HTML Quickform to use when validating the form.
        $this->form->addFormRule(array(&$this,'XINValidate'));

    }


    /*
     * generates the main page of the form
     *
     * @return void
     * @access private
     *
     */
    function _main() {

        // display test name
        $this->form->addElement('header', 'instrument_title', "DAS - Early Years Record Form");

        // automatically adds examiner & date of administration
        $this->_addMetadataFields();

//        $this->form->addElement('static', null, "<br />");
//        $this->form->addElement('header', 'raw_scores', "Raw Scores");
//        $this->form->addElement("static", null, "NOTE: Final scores still need to be calculated.");

//        $this->form->addElement("static", null, "<br />");

        $this->form->addElement('static', null, "<br />");
        $this->form->addElement("textarea", "other_comments", "Comments:", array('cols'=>25, 'rows'=>4));
        $this->XINRegisterRule("other_comments", array("{other_comments}{@}=={@}NEVER_REQUIRED"));
        $this->form->addElement('static', null, "<br />");


    }


    /*  function _score() {

          $db =& Database::singleton();

          // skip scoring if proband DoB was not entered, i.e. data entry is not completed
          if(empty($this->respondentAgeMonths)){
              return;
          }

          $age = $this->respondentAgeMonths;

          // null scores
          $this->_nullScores($this->scoreCols);
          // Get the item scores
          $query = "SELECT * FROM $this->table WHERE CommentID='".$this->getCommentID()."'";
          $record=array();
          $db->pselectRow($query, $record);
*/


    function _page1() {

        // 1.

        $this->form->addElement("header", null, "Verbal Comprehension");
        $this->form->addElement('static', null, "<br />");

        $page = 1;

        $group[] = &$this->form->createElement("static", null, null, "Score");
        $this->form->addGroup($group, null, "", $this->_GUIDelimiter, false);
        unset($group);

        $numItems=42;
        for ($i = 1; $i <= $numItems; $i++) {

            $group[]=&$this->form->createElement("select", "q_{$this->j}_item{$i}_score", null, $this->answerArray);
            $this->XINRegisterRule("q_{$this->j}_item{$i}_score", array("q_{$this->j}_item{$i}_score{@}=={@}NEVER_REQUIRED"), "Not Required.", "q_{$this->j}_{$i}_answer");

            $this->form->addGroup($group, "q_{$this->j}_{$i}_answer", "Item $i: ", $this->_GUIDelimiter,
                false);
            unset($group);


            $this->j++;
        }

        // Item Set Administered
        $this->form->addElement('static', null, "<br />");
        $group[] = &$this->form->createElement("static", null, null, "From");
        $group[] = &$this->form->createElement("static", null, null, "To");
        $this->form->addGroup($group, null, "", $this->_GUIDelimiter, false);
        unset($group);
        $itemSetArray = array_merge(array("" => null), range(0, $numItems));
        $group[]=&$this->form->createElement("select", "page_{$page}_item_set_from", null, $itemSetArray);
        $group[]=&$this->form->createElement("select", "page_{$page}_item_set_to", null, $itemSetArray);
        $this->XINRegisterRule("page_{$page}_item_set_from", array("page_{$page}_item_set_from{@}=={@}NEVER_REQUIRED"), "Not Required.", "page_{$page}_item_set");
        $this->XINRegisterRule("page_{$page}_item_set_to", array("page_{$page}_item_set_to{@}=={@}NEVER_REQUIRED"), "Not Required.", "page_{$page}_item_set");

        $this->form->addGroup($group, "page_{$page}_item_set", "Item Set Administered", $this->_GUIDelimiter, false);
        unset($group);

        $this->form->addElement('static', null, "<br />");
        $this->form->addElement("textarea", "other_comments{$page}", "Comments:", array('cols'=>25, 'rows'=>4));
        $this->XINRegisterRule("other_comments{$page}", array("{other_comments{$page}}{@}=={@}NEVER_REQUIRED"));
        $this->form->addElement('static', null, "<br />");

    }

    function _page2() {

        $this->form->addElement("header", null, "Picture Similarities");
        $this->form->addElement('static', null, "<br />");

        $page = 2;

        $this->j = 43;

        $group[] = &$this->form->createElement("static", null, null, "Response");
        $group[] = &$this->form->createElement("static", null, null, "Score");
        $this->form->addGroup($group, null, "", $this->_GUIDelimiter, false);
        unset($group);

        $numItems=32;
        for ($i = 1; $i <= $numItems; $i++) {

            $group[]=&$this->form->createElement("select", "q_{$this->j}_item{$i}_response", null,
                $this->responseArray);
            $group[]=&$this->form->createElement("select", "q_{$this->j}_item{$i}_score", null, $this->answerArray);
            $this->XINRegisterRule("q_{$this->j}_item{$i}_response", array("q_{$this->j}_item{$i}_response{@}=={@}NEVER_REQUIRED"), "Not Required.", "q_{$this->j}_{$i}_answer");
            $this->XINRegisterRule("q_{$this->j}_item{$i}_score", array("q_{$this->j}_item{$i}_score{@}=={@}NEVER_REQUIRED"), "Not Required.", "q_{$this->j}_{$i}_answer");

            $this->form->addGroup($group, "q_{$this->j}_{$i}_answer", "Item $i", $this->_GUIDelimiter, false);
            unset($group);

            $this->j++;
        }

        // Item Set Administered
        $this->form->addElement('static', null, "<br />");
        $group[] = &$this->form->createElement("static", null, null, "From");
        $group[] = &$this->form->createElement("static", null, null, "To");
        $this->form->addGroup($group, null, "", $this->_GUIDelimiter, false);
        unset($group);
        $itemSetArray = array_merge(array("" => null), range(0, $numItems));
        $group[]=&$this->form->createElement("select", "page_{$page}_item_set_from", null, $itemSetArray);
        $group[]=&$this->form->createElement("select", "page_{$page}_item_set_to", null, $itemSetArray);
        $this->XINRegisterRule("page_{$page}_item_set_from", array("page_{$page}_item_set_from{@}=={@}NEVER_REQUIRED"), "Not Required.", "page_{$page}_item_set");
        $this->XINRegisterRule("page_{$page}_item_set_to", array("page_{$page}_item_set_to{@}=={@}NEVER_REQUIRED"), "Not Required.", "page_{$page}_item_set");

        $this->form->addGroup($group, "page_{$page}_item_set", "Item Set Administered", $this->_GUIDelimiter, false);
        unset($group);

        $this->form->addElement('static', null, "<br />");
        $this->form->addElement("textarea", "other_comments{$page}", "Comments:", array('cols'=>25, 'rows'=>4));
        $this->XINRegisterRule("other_comments{$page}", array("{other_comments{$page}}{@}=={@}NEVER_REQUIRED"));
        $this->form->addElement('static', null, "<br />");

    }

    function _page3() {

        $this->form->addElement("header", null, "Naming Vocabulary");
        $this->form->addElement('static', null, "<br />");

        $page = 3;

        $this->j = 75;

        $group[] = &$this->form->createElement("static", null, null, "Response");
        $group[] = &$this->form->createElement("static", null, null, "Score");
        $this->form->addGroup($group, null, "", $this->_GUIDelimiter, false);
        unset($group);

        $rule_message='This field is not required.';

        $numItems=34;
        for ($i = 1; $i <= $numItems; $i++) {

            $field = "q_{$this->j}_item{$i}_response";
            $group[]=&$this->form->createElement("text", $field, "");
            $this->WrapperTextElements[$field] = $group[0];
            $group[] = $this->createSelect(
                $field . "_status",
                "",
                array(
                    null           => '',
                    'not_answered' => 'Not Answered',
                ),
                array('class' => 'form-control input-sm not-answered')
            );

            $group[]=&$this->form->createElement("select", "q_{$this->j}_item{$i}_score", "",
                $this->answerArray);

            $this->form->addGroup($group, "q_{$this->j}_item{$i}", "Item $i", null, false);
            unset($group);

            $this->XINRegisterRule(
                $field,
                array($field.'_status{@}=={@}NEVER_REQUIRED'),
                $rule_message,
                "q_{$this->j}_item{$i}"
            );

            $this->XINRegisterRule(
                "q_{$this->j}_item{$i}_score",
                array("q_{$this->j}_item{$i}_score{@}=={@}NEVER_REQUIRED"),
                $rule_message,
                "q_{$this->j}_item{$i}"
            );

            $this->j++;
        }

        // Item Set Administered
        $this->form->addElement('static', null, "<br />");
        $group[] = &$this->form->createElement("static", null, null, "From");
        $group[] = &$this->form->createElement("static", null, null, "To");
        $this->form->addGroup($group, null, "", $this->_GUIDelimiter, false);
        unset($group);
        $itemSetArray = array_merge(array("" => null), range(0, $numItems));
        $group[]=&$this->form->createElement("select", "page_{$page}_item_set_from", null, $itemSetArray);
        $group[]=&$this->form->createElement("select", "page_{$page}_item_set_to", null, $itemSetArray);
        $this->XINRegisterRule("page_{$page}_item_set_from", array("page_{$page}_item_set_from{@}=={@}NEVER_REQUIRED"), "Not Required.", "page_{$page}_item_set");
        $this->XINRegisterRule("page_{$page}_item_set_to", array("page_{$page}_item_set_to{@}=={@}NEVER_REQUIRED"), "Not Required.", "page_{$page}_item_set");

        $this->form->addGroup($group, "page_{$page}_item_set", "Item Set Administered", $this->_GUIDelimiter, false);
        unset($group);

        $this->form->addElement('static', null, "<br />");
        $this->form->addElement("textarea", "other_comments{$page}", "Comments:", array('cols'=>25, 'rows'=>4));
        $this->XINRegisterRule("other_comments{$page}", array("{other_comments{$page}}{@}=={@}NEVER_REQUIRED"));
        $this->form->addElement('static', null, "<br />");

    }

    function _page4() {

        $this->form->addElement("header", null, "Recall of Objects - Immediate");
        $this->form->addElement('static', null, "<br />");

        $page = 4;

        $this->j = 109;

        // If you suspect that a child will have difficulty with the starting items for his or her age,
        // use the Starting and Decision Points for a younger age group.
        // Out-of-level testing for children of average or low ability only

        $item = array(1=>"Ball", 2=>"Basket", 3=>"Bicycle", 4=>"Bird", 5=>"Boat", 6=>"Bottle", 7=>"Bowl", 8=>"Bus",
            9=>"Clock", 10=>"Cup", 11=>"Fire", 12=>"Fish", 13=>"Hat", 14=>"Horse", 15=>"Ladder", 16=>"Mouse",
            17=>"Ring", 18=>"Shoe", 19=>"Tractor", 20=>"Zipper");


        $group[] = &$this->form->createElement("static", null, null, "Trial 1");
        $group[] = $this->form->createElement("static", null, $this->indent);
        $group[] = $this->form->createElement("static", null, $this->indent);
        $group[] = &$this->form->createElement("static", null, null, "Trial 2");
        $group[] = $this->form->createElement("static", null, $this->indent);
        $group[] = $this->form->createElement("static", null, $this->indent);
        $group[] = &$this->form->createElement("static", null, null, "Trial 3");
        $group[] = $this->form->createElement("static", null, $this->indent);
        $group[] = $this->form->createElement("static", null, $this->indent);
        $this->form->addGroup($group, null, "", $this->_GUIDelimiter, false);
        unset($group);

        $group[] = &$this->form->createElement("static", null, null, "Response");
        $group[] = $this->form->createElement("static", null, $this->indent);
        $group[] = &$this->form->createElement("static", null, null, "Score");
        $group[] = &$this->form->createElement("static", null, null, "Response");
        $group[] = $this->form->createElement("static", null, $this->indent);
        $group[] = &$this->form->createElement("static", null, null, "Score");
        $group[] = &$this->form->createElement("static", null, null, "Response");
        $group[] = $this->form->createElement("static", null, $this->indent);
        $group[] = &$this->form->createElement("static", null, null, "Score");

        $this->form->addGroup($group, null, "", $this->_GUIDelimiter, false);
        unset($group);

        $rule_message='This field is not required.';

        $numItems=count($item);
        for ($i = 1; $i <= $numItems; $i++) {
            for ($k = 1; $k <=3; $k++) {

                $field = "q_{$this->j}_item{$i}_response_trial{$k}";
                $group[]=&$this->form->createElement("text", $field, "");
                $this->WrapperTextElements[$field] = $group[0];
                $group[] = $this->createSelect(
                    $field . "_status",
                    "",
                    array(
                        null           => '',
                        'not_answered' => 'Not Answered',
                    ),
                    array('class' => 'form-control input-sm not-answered')
                );

                $group[]=&$this->form->createElement("select", "q_{$this->j}_item{$i}_score_trial{$k}", "",
                    $this->answerArray);

            }

            $this->form->addGroup($group, "q_{$this->j}_item{$i}", "Item $i", null, false);
            unset($group);

            $this->XINRegisterRule(
                $field,
                array($field.'_status{@}=={@}NEVER_REQUIRED'),
                $rule_message,
                "q_{$this->j}_item{$i}"
            );

            $this->XINRegisterRule(
                "q_{$this->j}_item{$i}_score_trial{$k}",
                array("q_{$this->j}_item{$i}_score_trial{$k}{@}=={@}NEVER_REQUIRED"),
                $rule_message,
                "q_{$this->j}_item{$i}"
            );


        }

        $this->form->addElement('static', null, "<br />");
        $this->form->addElement("textarea", "other_comments{$page}", "Comments:", array('cols'=>25, 'rows'=>4));
        $this->XINRegisterRule("other_comments{$page}", array("{other_comments{$page}}{@}=={@}NEVER_REQUIRED"));
        $this->form->addElement('static', null, "<br />");

    }

    function _page5() {

        // 5. Pattern Construction
        // Usual Age Range: 3 years 6 months to 17 years 11 months
        // Out of Level: 3 years 0 months to 3 years 5 months
        // DP
        // ASP

        $this->form->addElement("header", null, "Pattern Construction");
        $this->form->addElement('static', null, "<br />");

        $page = 5;

        $this->j = 129;

        $pfArray = array("" => NULL, "p" => "Pass", "f" => "Fail", "not_answered" => "Not Answered");
        $na = array("not_answered" => "Not Answered");
        $scoreArray = array("" => NULL, 0 => 0, 1 => 1, 2 => 2, "not_answered" => "Not Answered");

        $doubleTrialItems = array(1, 13, 14, 16, 20, 21, 26, 27);

        $numItemsSetA = 12;
        $numItemsSetB = 19;
        $numItemsSetC = 38;


        $this->form->addElement("header", null, "Set A");

        $group[] = $this->form->createElement("static", null, $this->indent);
        $group[] = &$this->form->createElement("static", null, null, "Score");
        $this->form->addGroup($group, null, "", $this->_GUIDelimiter, false);
        unset($group);

        for ($i = 1; $i <= $numItemsSetA; $i++) {

            if (in_array($i, $doubleTrialItems)) {
                for ($k = 1; $k <= 2; $k++) {

                    $group[] =& $this->form->createElement("static", null, null, "Trial $k");
                    $group[] =& $this->form->createElement("select", "q_{$this->j}_item{$i}_trial{$k}", null, $scoreArray);
                    $this->XINRegisterRule("q_{$this->j}_item{$i}_trial{$k}", array("q_{$this->j}_item{$i}_trial{$k}{@}=={@}NEVER_REQUIRED"), "Not Required.", "q_{$this->j}_{$i}_answer_trial{$k}");

                    if ($k == 1) {
                        $this->form->addGroup($group, "q_{$this->j}_{$i}_answer_trial{$k}", "Item $i", $this->_GUIDelimiter,
                            false);
                    } else {
                        $this->form->addGroup($group, "q_{$this->j}_{$i}_answer_trial{$k}", null, $this->_GUIDelimiter,
                            false);
                    }
                    unset($group);
                }
            }
            else {
                $group[] = $this->form->createElement("static", null, $this->indent);
                if ($i != 2) {
                    $group[] =& $this->form->createElement("select", "q_{$this->j}_item{$i}", null, $this->answerArray);
                }
                else {
                    $group[] =& $this->form->createElement("select", "q_{$this->j}_item{$i}", null, $scoreArray);
                }
                $this->XINRegisterRule("q_{$this->j}_item{$i}", array("q_{$this->j}_item{$i}{@}=={@}NEVER_REQUIRED"), "Not Required.", "q_{$this->j}_{$i}_answer");

                $this->form->addGroup($group, "q_{$this->j}_{$i}_answer", "Item $i", $this->_GUIDelimiter,
                    false);
                unset($group);
            }
        }

        $this->form->addElement("header", null, "Set B");

        $group[] = $this->form->createElement("static", null, $this->indent);
        $group[] = &$this->form->createElement("static", null, null, "Time");
        $group[] = &$this->form->createElement("static", null, null, "P/F");
        $this->form->addGroup($group, null, "", $this->_GUIDelimiter, false);
        unset($group);

        $items_30 = array(13, 14, 20, 21, 22, 23);
        $items_45 = array(15, 16, 24, 25);
        $items_60 = array(17, 18, 19, 26);
        $items_90 = array(27, 28, 29, 30, 31, 32);
        $items_120 = array(33, 34, 35, 36, 37, 38);

        $item_time = array();

        for ($i = 0; $i <= $numItemsSetC; $i++)
        {
            if ($i < 13) {
                $time= "";
            }
            if (in_array($i, $items_30)) {
                $time = 30;
            }
            if (in_array($i, $items_45)) {
                $time = 45;
            }
            if (in_array($i, $items_60)) {
                $time = 60;
            }
            if (in_array($i, $items_90)) {
                $time = 90;
            }
            if (in_array($i, $items_120)) {
                $time = 120;
            }
            array_push($item_time, $time);
        }

        for ($i = $numItemsSetA + 1; $i <= $numItemsSetB; $i++) {

            $options = array_merge(array("" => NULL), range(0,  $item_time[$i]), $na);

            if (in_array($i, $doubleTrialItems)) {
                for ($k = 1; $k <= 2; $k++) {

                    $group[] =& $this->form->createElement("static", null, null, "Trial $k");
                    $group[] =& $this->form->createElement("select", "q_{$this->j}_item{$i}_trial{$k}", null, $options);
                    $group[] =& $this->form->createElement("select", "q_{$this->j}_item{$i}_response_time2_trial{$k}", null, $pfArray);
                    $this->XINRegisterRule("q_{$this->j}_item{$i}_trial{$k}", array("q_{$this->j}_item{$i}_trial{$k}{@}=={@}NEVER_REQUIRED"), "Not Required.", "{$i}_answer_trial{$k}");
                    $this->XINRegisterRule("q_{$this->j}_item{$i}_response_time2_trial{$k}", array("q_{$this->j}_item{$i}_response_time2_trial{$k}{@}=={@}NEVER_REQUIRED"), "Not Required.", "{$i}_answer_trial{$k}");

                    if ($k == 1) {
                        $this->form->addGroup($group, "{$i}_answer_trial{$k}", "Item $i", $this->_GUIDelimiter,
                            false);
                    } else {
                        $this->form->addGroup($group, "{$i}_answer_trial{$k}", null, $this->_GUIDelimiter,
                            false);
                    }
                    unset($group);
                }
            }
            else {
                $group[] = $this->form->createElement("static", null, $this->indent);
                $group[] =& $this->form->createElement("select", "q_{$this->j}_item{$i}", null, $options);
                $group[] =& $this->form->createElement("select", "q_{$this->j}_item{$i}_pf", null, $pfArray);
                $this->XINRegisterRule("q_{$this->j}_item{$i}", array("q_{$this->j}_item{$i}{@}=={@}NEVER_REQUIRED"), "Not Required.", "q_{$this->j}_{$i}_answer");
                $this->XINRegisterRule("q_{$this->j}_item{$i}_pf", array("q_{$this->j}_item{$i}_pf{@}=={@}NEVER_REQUIRED"), "Not Required.", "q_{$this->j}_{$i}_answer");

                $this->form->addGroup($group, "q_{$this->j}_{$i}_answer", "Item $i", $this->_GUIDelimiter,
                    false);
                unset($group);
            }
            $this->j++;
        }

        $this->form->addElement("header", null, "Set C");

        $group[] = $this->form->createElement("static", null, $this->indent);
        $group[] = &$this->form->createElement("static", null, null, "Time");
        $group[] = &$this->form->createElement("static", null, null, "P/F");
        $this->form->addGroup($group, null, "", $this->_GUIDelimiter, false);
        unset($group);

        for ($i = $numItemsSetB + 1; $i <= $numItemsSetC; $i++) {

            $options = array_merge(array("" => NULL), range(0,  $item_time[$i]), $na);

            if (in_array($i, $doubleTrialItems)) {
                for ($k = 1; $k <= 2; $k++) {

                    $group[] =& $this->form->createElement("static", null, null, "Trial $k");
                    $group[] =& $this->form->createElement("select", "q_{$this->j}_item{$i}_trial{$k}", null, $options);
                    $group[] =& $this->form->createElement("select", "q_{$this->j}_item{$i}_response_time2_trial{$k}", null, $pfArray);
                    $this->XINRegisterRule("q_{$this->j}_item{$i}_trial{$k}", array("q_{$this->j}_item{$i}_trial{$k}{@}=={@}NEVER_REQUIRED"), "Not Required.", "{$i}_answer_trial{$k}");
                    $this->XINRegisterRule("q_{$this->j}_item{$i}_response_time2_trial{$k}", array("q_{$this->j}_item{$i}_response_time2_trial{$k}{@}=={@}NEVER_REQUIRED"), "Not Required.", "{$i}_answer_trial{$k}");

                    if ($k == 1) {
                        $this->form->addGroup($group, "{$i}_answer_trial{$k}", "Item $i", $this->_GUIDelimiter,
                            false);
                    } else {
                        $this->form->addGroup($group, "{$i}_answer_trial{$k}", null, $this->_GUIDelimiter,
                            false);
                    }
                    unset($group);
                }
            }
            else {
                $group[] = $this->form->createElement("static", null, $this->indent);
                $group[] =& $this->form->createElement("select", "q_{$this->j}_item{$i}", null, $options);
                $group[] =& $this->form->createElement("select", "q_{$this->j}_item{$i}_pf", null,
                    $pfArray);
                $this->form->addGroup($group, "q_{$this->j}_{$i}_answer", "Item $i", $this->_GUIDelimiter,
                    false);
                unset($group);
            }
            $this->j++;
        }

        // Alternative (Unspeeded) Administration????

        // Item Set Administered
        $this->form->addElement('static', null, "<br />");
        $group[] = &$this->form->createElement("static", null, null, "From");
        $group[] = &$this->form->createElement("static", null, null, "To");
        $this->form->addGroup($group, null, "", $this->_GUIDelimiter, false);
        unset($group);
        $itemSetArray = array_merge(array("" => null), range(0, $numItemsSetC));
        $group[]=&$this->form->createElement("select", "page_{$page}_item_set_from", null, $itemSetArray);
        $group[]=&$this->form->createElement("select", "page_{$page}_item_set_to", null, $itemSetArray);
        $this->XINRegisterRule("page_{$page}_item_set_from", array("page_{$page}_item_set_from{@}=={@}NEVER_REQUIRED"), "Not Required.", "page_{$page}_item_set");
        $this->XINRegisterRule("page_{$page}_item_set_to", array("page_{$page}_item_set_to{@}=={@}NEVER_REQUIRED"), "Not Required.", "page_{$page}_item_set");

        $this->form->addGroup($group, "page_{$page}_item_set", "Item Set Administered", $this->_GUIDelimiter, false);
        unset($group);

        $this->form->addElement('static', null, "<br />");
        $this->form->addElement("textarea", "other_comments{$page}", "Comments:", array('cols'=>25, 'rows'=>4));
        $this->XINRegisterRule("other_comments{$page}", array("{other_comments{$page}}{@}=={@}NEVER_REQUIRED"));
        $this->form->addElement('static', null, "<br />");

    }

    function _page6() {

        // 6. Matrices
        // Usual Age Range: 6 years 0 months to 17 years 11 months
        // Extended Age Range: 5 years 0 months to 5 years 11 months


        $this->form->addElement("header", null, "Matrices");
        $this->form->addElement('static', null, "<br />");

        $page = 6;

        $this->j = 155;

        $setAResponseArray = array(""=>NULL, 1=>1, 2=>2, 3=>3, 4=>4, "not_answered"=>"Not Answered");
        $setBResponseArray = array(""=>NULL, 1=>1, 2=>2, 3=>3, 4=>4, 5=>5, 6=>6, "not_answered"=>"Not Answered");

        // include score? or automatic??

        $numItemsSetA = 19;
        $numItemsSetB = 56;

        $this->form->addElement("header", null, "Set A");

        $group[] = &$this->form->createElement("static", null, null, "Response");
        $group[] = &$this->form->createElement("static", null, null, "Score");
        $this->form->addGroup($group, null, "", $this->_GUIDelimiter, false);
        unset($group);

        for ($i = 1; $i <= $numItemsSetA; $i++) {
            $group[] =&$this->form->createElement("select", "q_{$this->j}_item{$i}_response", "",
                $setAResponseArray);
            $group[] =&$this->form->createElement("select", "q_{$this->j}_item{$i}_score", "",
                $this->answerArray);
            $this->XINRegisterRule("q_{$this->j}_item{$i}_response", array("q_{$this->j}_item{$i}_response{@}=={@}NEVER_REQUIRED"), "Not Required.", "q_{$this->j}_{$i}_answer");
            $this->XINRegisterRule("q_{$this->j}_item{$i}_score", array("q_{$this->j}_item{$i}_score{@}=={@}NEVER_REQUIRED"), "Not Required.", "q_{$this->j}_{$i}_answer");

            $this->form->addGroup($group, "q_{$this->j}_{$i}_answer", "Item $i", $this->_GUIDelimiter, false);
            unset($group);

            $this->j++;
        }

        $this->form->addElement("header", null, "Set B");

        $group[] = &$this->form->createElement("static", null, null, "Response");
        $group[] = &$this->form->createElement("static", null, null, "Score");
        $this->form->addGroup($group, null, "", $this->_GUIDelimiter, false);
        unset($group);


        for ($i = 20; $i <= $numItemsSetB; $i++) {
            $group[] =&$this->form->createElement("select", "q_{$this->j}_item{$i}_response", "",
                $setBResponseArray);
            $group[] =&$this->form->createElement("select", "q_{$this->j}_item{$i}_score", "",
                $this->answerArray);
            $this->XINRegisterRule("q_{$this->j}_item{$i}_response", array("q_{$this->j}_item{$i}_response{@}=={@}NEVER_REQUIRED"), "Not Required.", "q_{$this->j}_{$i}_answer");
            $this->XINRegisterRule("q_{$this->j}_item{$i}_score", array("q_{$this->j}_item{$i}_score{@}=={@}NEVER_REQUIRED"), "Not Required.", "q_{$this->j}_{$i}_answer");

            $this->form->addGroup($group, "q_{$this->j}_{$i}_answer", "Item $i", $this->_GUIDelimiter, false);
            unset($group);

            $this->j++;
        }

        // Item Set Administered
        $this->form->addElement('static', null, "<br />");
        $group[] = &$this->form->createElement("static", null, null, "From");
        $group[] = &$this->form->createElement("static", null, null, "To");
        $this->form->addGroup($group, null, "", $this->_GUIDelimiter, false);
        unset($group);
        $itemSetArray = array_merge(array("" => null), range(0, $numItemsSetB));
        $group[]=&$this->form->createElement("select", "page_{$page}_item_set_from", null, $itemSetArray);
        $group[]=&$this->form->createElement("select", "page_{$page}_item_set_to", null, $itemSetArray);
        $this->XINRegisterRule("page_{$page}_item_set_from", array("page_{$page}_item_set_from{@}=={@}NEVER_REQUIRED"), "Not Required.", "page_{$page}_item_set");
        $this->XINRegisterRule("page_{$page}_item_set_to", array("page_{$page}_item_set_to{@}=={@}NEVER_REQUIRED"), "Not Required.", "page_{$page}_item_set");

        $this->form->addGroup($group, "page_{$page}_item_set", "Item Set Administered", $this->_GUIDelimiter, false);
        unset($group);

        $this->form->addElement('static', null, "<br />");
        $this->form->addElement("textarea", "other_comments{$page}", "Comments:", array('cols'=>25, 'rows'=>4));
        $this->XINRegisterRule("other_comments{$page}", array("{other_comments{$page}}{@}=={@}NEVER_REQUIRED"));
        $this->form->addElement('static', null, "<br />");
    }

    function _page7() {

        $this->form->addElement("header", null, "Recall of Objects - Delayed");
        $this->form->addElement('static', null, "<br />");

        $page = 7;

        $this->j = 211;

        $item = array(1=>"Ball", 2=>"Basket", 3=>"Bicycle", 4=>"Bird", 5=>"Boat", 6=>"Bottle", 7=>"Bowl", 8=>"Bus",
            9=>"Clock", 10=>"Cup", 11=>"Fire", 12=>"Fish", 13=>"Hat", 14=>"Horse", 15=>"Ladder", 16=>"Mouse",
            17=>"Ring", 18=>"Shoe", 19=>"Tractor", 20=>"Zipper");

        $group[] = &$this->form->createElement("static", null, null, "Response");
        $group[] = &$this->form->createElement("static", null, null, "Score");
        $this->form->addGroup($group, null, "", $this->_GUIDelimiter, false);
        unset($group);

        $rule_message='This field is not required.';

        $numItems=count($item);
        for ($i = 1; $i <= $numItems; $i++) {

            $field = "q_{$this->j}_item{$i}_response";
            $group[]=&$this->form->createElement("text", $field, "");
            $this->WrapperTextElements[$field] = $group[0];
            $group[] = $this->createSelect(
                $field . "_status",
                "",
                array(
                    null           => '',
                    'not_answered' => 'Not Answered',
                ),
                array('class' => 'form-control input-sm not-answered')
            );

            $group[]=&$this->form->createElement("select", "q_{$this->j}_item{$i}_score", "",
                $this->answerArray);

            $this->form->addGroup($group, "q_{$this->j}_item{$i}", "Item $i", null, false);
            unset($group);

            $this->XINRegisterRule(
                $field,
                array($field.'_status{@}=={@}NEVER_REQUIRED'),
                $rule_message,
                "q_{$this->j}_item{$i}"
            );

            $this->XINRegisterRule(
                "q_{$this->j}_item{$i}_score",
                array("q_{$this->j}_item{$i}_score{@}=={@}NEVER_REQUIRED"),
                $rule_message,
                "q_{$this->j}_item{$i}"
            );

            $this->j++;
        }

        $this->form->addElement('static', null, "<br />");
        $this->form->addElement("textarea", "other_comments{$page}", "Comments:", array('cols'=>25, 'rows'=>4));
        $this->XINRegisterRule("other_comments{$page}", array("{other_comments{$page}}{@}=={@}NEVER_REQUIRED"));
        $this->form->addElement('static', null, "<br />");

    }

    function _page8() {

        $this->form->addElement("header", null, "Copying");
        $this->form->addElement('static', null, "<br />");

        $page = 8;

        $this->j = 231;

        $group[] = &$this->form->createElement("static", null, null, "Response");
        $group[] = &$this->form->createElement("static", null, null, "Score");
        $this->form->addGroup($group, null, "", $this->_GUIDelimiter, false);
        unset($group);

        $answerArray_2 = array(""=>NULL, 0=>0, 1=>1, 2=>2, "not_answered"=>"Not Answered");
        $answerArray_3 = array(""=>NULL, 0=>0, 1=>1, 2=>2, 3=>3, "not_answered"=>"Not Answered");
        $pfArray = array(""=>NULL, 0=>"F", 1=>"P", 2=>"P+"); /// NEEDS TO BE UPDATED

        $maxScore1 = array(1);
        $maxScore2 = array(2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 13, 14, 15, 19, 20);

        $numItems = 20;

        for ($i = 1; $i <= $numItems; $i++) {

            $group[]=&$this->form->createElement("select", "q_{$this->j}_item{$i}_pf", null, $pfArray);

            if (in_array($i, $maxScore1)) {
                $answers = $this->answerArray;
            }
            else if (in_array($i, $maxScore2)) {
                $answers = $answerArray_2;
            }
            else {
                $answers = $answerArray_3;
            }
            $group[]=&$this->form->createElement("select", "q_{$this->j}_item{$i}_score", null, $answers);
            $this->XINRegisterRule("q_{$this->j}_item{$i}_score", array("q_{$this->j}_item{$i}_score{@}=={@}NEVER_REQUIRED"), "Not Required.", "q_{$this->j}_{$i}_answer");

            $this->form->addGroup($group, "q_{$this->j}_{$i}_answer", "Item $i: ", $this->_GUIDelimiter,
                false);
            unset($group);

            $this->j++;
        }

        // Item Set Administered
        $this->form->addElement('static', null, "<br />");
        $group[] = &$this->form->createElement("static", null, null, "From");
        $group[] = &$this->form->createElement("static", null, null, "To");
        $this->form->addGroup($group, null, "", $this->_GUIDelimiter, false);
        unset($group);
        $itemSetArray = array_merge(array("" => null), range(0, $numItems));
        $group[]=&$this->form->createElement("select", "page_{$page}_item_set_from", null, $itemSetArray);
        $group[]=&$this->form->createElement("select", "page_{$page}_item_set_to", null, $itemSetArray);
        $this->XINRegisterRule("page_{$page}_item_set_from", array("page_{$page}_item_set_from{@}=={@}NEVER_REQUIRED"), "Not Required.", "page_{$page}_item_set");
        $this->XINRegisterRule("page_{$page}_item_set_to", array("page_{$page}_item_set_to{@}=={@}NEVER_REQUIRED"), "Not Required.", "page_{$page}_item_set");

        $this->form->addGroup($group, "page_{$page}_item_set", "Item Set Administered", $this->_GUIDelimiter, false);
        unset($group);

        $this->form->addElement('static', null, "<br />");
        $this->form->addElement("textarea", "other_comments{$page}", "Comments:", array('cols'=>25, 'rows'=>4));
        $this->XINRegisterRule("other_comments{$page}", array("{other_comments{$page}}{@}=={@}NEVER_REQUIRED"));
        $this->form->addElement('static', null, "<br />");

    }

    function _page9() {

        $this->form->addElement("header", null, "Recall of Digits Forward");
        $this->form->addElement('static', null, "<br />");

        $page = 9;

        $this->j = 251;

        $group[] = &$this->form->createElement("static", null, null, "Response");
        $group[] = &$this->form->createElement("static", null, null, "Score");
        $this->form->addGroup($group, null, "", $this->_GUIDelimiter, false);
        unset($group);

        $numItems = 38;

        $rule_message='This field is not required.';

        for ($i = 1; $i <= $numItems; $i++) {

            $field = "q_{$this->j}_item{$i}_response";
            $group[]=&$this->form->createElement("text", $field, "");
            $this->WrapperTextElements[$field] = $group[0];
            $group[] = $this->createSelect(
                $field . "_status",
                "",
                array(
                    null           => '',
                    'not_answered' => 'Not Answered',
                ),
                array('class' => 'form-control input-sm not-answered')
            );

            $group[]=&$this->form->createElement("select", "q_{$this->j}_item{$i}_score", "",
                $this->answerArray);

            $this->form->addGroup($group, "q_{$this->j}_item{$i}", "Item $i", null, false);
            unset($group);

            $this->XINRegisterRule(
                $field,
                array($field.'_status{@}=={@}NEVER_REQUIRED'),
                $rule_message,
                "q_{$this->j}_item{$i}"
            );

            $this->XINRegisterRule(
                "q_{$this->j}_item{$i}_score",
                array("q_{$this->j}_item{$i}_score{@}=={@}NEVER_REQUIRED"),
                $rule_message,
                "q_{$this->j}_item{$i}"
            );
            $this->j++;
        }

        $itemSetArray = array_merge(array("" => null), range(0, $numItems));
        $group[]=&$this->form->createElement("select", "page_{$page}_number_correct", null, $itemSetArray);
        $this->XINRegisterRule("page_{$page}_number_correct", array("page_{$page}_number_correct{@}=={@}NEVER_REQUIRED"), "Not Required.", "page_{$page}_item_set");

        $this->form->addGroup($group, "page_{$page}_item_set", "Number Correct", $this->_GUIDelimiter, false);
        unset($group);

        $this->form->addElement('static', null, "<br />");
        $this->form->addElement("textarea", "other_comments{$page}", "Comments:", array('cols'=>25, 'rows'=>4));
        $this->XINRegisterRule("other_comments{$page}", array("{other_comments{$page}}{@}=={@}NEVER_REQUIRED"));
        $this->form->addElement('static', null, "<br />");

    }

    function _page10() {


        $this->form->addElement("header", null, "Recognition of Pictures");
        $this->form->addElement('static', null, "<br />");

        $page = 10;

        $this->j = 289;

        $group[] = &$this->form->createElement("static", null, null, "Score");
        $this->form->addGroup($group, null, "", $this->_GUIDelimiter, false);
        unset($group);

        $numItems = 20;

        for ($i = 1; $i <= $numItems; $i++) {

            $group[]=&$this->form->createElement("select", "q_{$this->j}_item{$i}_score", null, $this->answerArray);
            $this->XINRegisterRule("q_{$this->j}_item{$i}_score", array("q_{$this->j}_item{$i}_score{@}=={@}NEVER_REQUIRED"), "Not Required.", "q_{$this->j}_{$i}_answer");

            $this->form->addGroup($group, "q_{$this->j}_{$i}_answer", "Item $i: ", $this->_GUIDelimiter,
                false);
            unset($group);

            $this->j++;
        }

        // Item Set Administered
        $this->form->addElement('static', null, "<br />");
        $group[] = &$this->form->createElement("static", null, null, "From");
        $group[] = &$this->form->createElement("static", null, null, "To");
        $this->form->addGroup($group, null, "", $this->_GUIDelimiter, false);
        unset($group);
        $itemSetArray = array_merge(array("" => null), range(0, $numItems));
        $group[]=&$this->form->createElement("select", "page_{$page}_item_set_from", null, $itemSetArray);
        $group[]=&$this->form->createElement("select", "page_{$page}_item_set_to", null, $itemSetArray);
        $this->XINRegisterRule("page_{$page}_item_set_from", array("page_{$page}_item_set_from{@}=={@}NEVER_REQUIRED"), "Not Required.", "page_{$page}_item_set");
        $this->XINRegisterRule("page_{$page}_item_set_to", array("page_{$page}_item_set_to{@}=={@}NEVER_REQUIRED"), "Not Required.", "page_{$page}_item_set");

        $this->form->addGroup($group, "page_{$page}_item_set", "Item Set Administered", $this->_GUIDelimiter, false);
        unset($group);

        $this->form->addElement('static', null, "<br />");
        $this->form->addElement("textarea", "other_comments{$page}", "Comments:", array('cols'=>25, 'rows'=>4));
        $this->XINRegisterRule("other_comments{$page}", array("{other_comments{$page}}{@}=={@}NEVER_REQUIRED"));
        $this->form->addElement('static', null, "<br />");

    }

    function _page11() {


        $this->form->addElement("header", null, "Early Number Concepts");
        $this->form->addElement('static', null, "<br />");

        $page = 11;

        $this->j = 309;

        $group[] = &$this->form->createElement("static", null, null, "Response");
        $group[] = &$this->form->createElement("static", null, null, "Score");
        $this->form->addGroup($group, null, "", $this->_GUIDelimiter, false);
        unset($group);

        $numItems = 33;

        $rule_message='This field is not required.';

        for ($i = 1; $i <= $numItems; $i++) {

            if ($i != 3) {
                $field = "q_{$this->j}_item{$i}_response";
                $group[]=&$this->form->createElement("text", $field, "");
                $this->WrapperTextElements[$field] = $group[0];
                $group[] = $this->createSelect(
                    $field . "_status",
                    "",
                    array(
                        null           => '',
                        'not_answered' => 'Not Answered',
                    ),
                    array('class' => 'form-control input-sm not-answered')
                );

                $group[]=&$this->form->createElement("select", "q_{$this->j}_item{$i}_score", "",
                    $this->answerArray);

                $this->form->addGroup($group, "q_{$this->j}_item{$i}", "Item $i", null, false);
                unset($group);

                $this->XINRegisterRule(
                    $field,
                    array($field.'_status{@}=={@}NEVER_REQUIRED'),
                    $rule_message,
                    "q_{$this->j}_item{$i}"
                );

                $this->XINRegisterRule(
                    "q_{$this->j}_item{$i}_score",
                    array("q_{$this->j}_item{$i}_score{@}=={@}NEVER_REQUIRED"),
                    $rule_message,
                    "q_{$this->j}_item{$i}"
                );

            }
            else {
                for ($k = 1; $k <= 2; $k++) {
                    $field = "q_{$this->j}_item{$i}_response{$k}";
                    $group[] =& $this->form->createElement("text", $field, "");
                    $this->WrapperTextElements[$field] = $group[0];
                    $group[] = $this->createSelect(
                        $field . "_status",
                        "",
                        array(
                            null => '',
                            'not_answered' => 'Not Answered',
                        ),
                        array('class' => 'form-control input-sm not-answered')
                    );

                    $group[] =& $this->form->createElement("select", "q_{$this->j}_item{$i}_score{$k}", "",
                        $this->answerArray);

                    if ($k == 1) {
                        $this->form->addGroup($group, "q_{$this->j}_item{$i}_{$k}", "Item $i", null, false);
                    }
                    else {
                        $this->form->addGroup($group, "q_{$this->j}_item{$i}_{$k}", "", null, false);
                    }
                    unset($group);

                    $this->XINRegisterRule(
                        $field,
                        array($field . '_status{@}=={@}NEVER_REQUIRED'),
                        $rule_message,
                        "q_{$this->j}_item{$i}"
                    );

                    $this->XINRegisterRule(
                        "q_{$this->j}_item{$i}_score{$k}",
                        array("q_{$this->j}_item{$i}_score{$k}{@}=={@}NEVER_REQUIRED"),
                        $rule_message,
                        "q_{$this->j}_item{$i}"
                    );
                }
            }
            $this->j++;
        }


        // Item Set Administered
        $this->form->addElement('static', null, "<br />");
        $group[] = &$this->form->createElement("static", null, null, "From");
        $group[] = &$this->form->createElement("static", null, null, "To");
        $this->form->addGroup($group, null, "", $this->_GUIDelimiter, false);
        unset($group);
        $itemSetArray = array_merge(array("" => null), range(0, $numItems));
        $group[]=&$this->form->createElement("select", "page_{$page}_item_set_from", null, $itemSetArray);
        $group[]=&$this->form->createElement("select", "page_{$page}_item_set_to", null, $itemSetArray);
        $this->XINRegisterRule("page_{$page}_item_set_from", array("page_{$page}_item_set_from{@}=={@}NEVER_REQUIRED"), "Not Required.", "page_{$page}_item_set");
        $this->XINRegisterRule("page_{$page}_item_set_to", array("page_{$page}_item_set_to{@}=={@}NEVER_REQUIRED"), "Not Required.", "page_{$page}_item_set");

        $this->form->addGroup($group, "page_{$page}_item_set", "Item Set Administered", $this->_GUIDelimiter, false);
        unset($group);

        $this->form->addElement('static', null, "<br />");
        $this->form->addElement("textarea", "other_comments{$page}", "Comments:", array('cols'=>25, 'rows'=>4));
        $this->XINRegisterRule("other_comments{$page}", array("{other_comments{$page}}{@}=={@}NEVER_REQUIRED"));
        $this->form->addElement('static', null, "<br />");

    }

    function _page12() {

        $this->form->addElement("header", null, "Matching Letter-Like Forms");
        $this->form->addElement('static', null, "<br />");

        $page = 12;

        $this->j = 342;

        $group[] = &$this->form->createElement("static", null, null, "Response");
        $group[] = &$this->form->createElement("static", null, null, "Score");
        $this->form->addGroup($group, null, "", $this->_GUIDelimiter, false);
        unset($group);

        $responseArray = array("" => NULL, 0=>0, 1=>1, 2=>2, 3=>3, 4=>4, 5=>5, 6=>6, "not_answered" => "Not Answered");

        $numItems = 27;

        for ($i = 1; $i <= $numItems; $i++) {

            $group[]=&$this->form->createElement("select", "q_{$this->j}_item{$i}_response", null, $responseArray);
            $group[]=&$this->form->createElement("select", "q_{$this->j}_item{$i}_score", null, $this->answerArray);
            $this->XINRegisterRule("q_{$this->j}_item{$i}_response", array("q_{$this->j}_item{$i}_response{@}=={@}NEVER_REQUIRED"), "Not Required.", "q_{$this->j}_{$i}_answer");
            $this->XINRegisterRule("q_{$this->j}_item{$i}_score", array("q_{$this->j}_item{$i}_score{@}=={@}NEVER_REQUIRED"), "Not Required.", "q_{$this->j}_{$i}_answer");

            $this->form->addGroup($group, "q_{$this->j}_{$i}_answer", "Item $i: ", $this->_GUIDelimiter,
                false);
            unset($group);

            $this->j++;
        }

        // Item Set Administered
        $this->form->addElement('static', null, "<br />");
        $group[] = &$this->form->createElement("static", null, null, "From");
        $group[] = &$this->form->createElement("static", null, null, "To");
        $this->form->addGroup($group, null, "", $this->_GUIDelimiter, false);
        unset($group);
        $itemSetArray = array_merge(array("" => null), range(0, $numItems));
        $group[]=&$this->form->createElement("select", "page_{$page}_item_set_from", null, $itemSetArray);
        $group[]=&$this->form->createElement("select", "page_{$page}_item_set_to", null, $itemSetArray);
        $this->XINRegisterRule("page_{$page}_item_set_from", array("page_{$page}_item_set_from{@}=={@}NEVER_REQUIRED"), "Not Required.", "page_{$page}_item_set");
        $this->XINRegisterRule("page_{$page}_item_set_to", array("page_{$page}_item_set_to{@}=={@}NEVER_REQUIRED"), "Not Required.", "page_{$page}_item_set");

        $this->form->addGroup($group, "page_{$page}_item_set", "Item Set Administered", $this->_GUIDelimiter, false);
        unset($group);

        $this->form->addElement('static', null, "<br />");
        $this->form->addElement("textarea", "other_comments{$page}", "Comments:", array('cols'=>25, 'rows'=>4));
        $this->XINRegisterRule("other_comments{$page}", array("{other_comments{$page}}{@}=={@}NEVER_REQUIRED"));
        $this->form->addElement('static', null, "<br />");

    }


    function _page13() {

        $this->form->addElement("header", null, "Recall of Sequential Order");
        $this->form->addElement('static', null, "<br />");

        $page = 13;

        $this->j = 369;

        $group[] = &$this->form->createElement("static", null, null, "Response");
        $group[] = &$this->form->createElement("static", null, null, "Score");
        $this->form->addGroup($group, null, "", $this->_GUIDelimiter, false);
        unset($group);

        $responseArray = array("" => NULL, "p"=>"P", "f"=>"F", "not_answered" => "Not Answered");

        $numItems = 32;

        for ($i = 1; $i <= $numItems; $i++) {

            $group[]=&$this->form->createElement("select", "q_{$this->j}_item{$i}_response", null, $responseArray);
            $group[]=&$this->form->createElement("select", "q_{$this->j}_item{$i}_score", null, $this->answerArray);
            $this->XINRegisterRule("q_{$this->j}_item{$i}_response", array("q_{$this->j}_item{$i}_response{@}=={@}NEVER_REQUIRED"), "Not Required.", "q_{$this->j}_{$i}_answer");
            $this->XINRegisterRule("q_{$this->j}_item{$i}_score", array("q_{$this->j}_item{$i}_score{@}=={@}NEVER_REQUIRED"), "Not Required.", "q_{$this->j}_{$i}_answer");

            $this->form->addGroup($group, "q_{$this->j}_{$i}_answer", "Item $i: ", $this->_GUIDelimiter,
                false);
            unset($group);

            $this->j++;
        }

        $itemSetArray = array_merge(array("" => null), range(0, $numItems));
        $group[]=&$this->form->createElement("select", "page_{$page}_number_correct", null, $itemSetArray);
        $this->XINRegisterRule("page_{$page}_number_correct", array("page_{$page}_number_correct{@}=={@}NEVER_REQUIRED"), "Not Required.", "page_{$page}_item_set");

        $this->form->addGroup($group, "page_{$page}_item_set", "Number Correct ", $this->_GUIDelimiter, false);
        unset($group);

        $this->form->addElement('static', null, "<br />");
        $this->form->addElement("textarea", "other_comments{$page}", "Comments:", array('cols'=>25, 'rows'=>4));
        $this->XINRegisterRule("other_comments{$page}", array("{other_comments{$page}}{@}=={@}NEVER_REQUIRED"));
        $this->form->addElement('static', null, "<br />");

    }

    function _page14() {


        $this->form->addElement("header", null, "Speed of Information Processing");
        $this->form->addElement('static', null, "<br />");

        $page = 14;

        $this->j = 401;

        $this->form->addElement("header", null, "Response Booklet A");

        $group[] = &$this->form->createElement("static", null, null, "Time");
        $group[] = &$this->form->createElement("static", null, null, "Errors");
        $group[] = &$this->form->createElement("static", null, null, "Score");
        $this->form->addGroup($group, null, "", $this->_GUIDelimiter, false);
        unset($group);

        $scoreArray = array("" => NULL, 0=>0, 1=>1, 2=>2, 3=>3, 4=>4, "not_answered" => "Not Answered");

        $numItems = 18;

        $rule_message='This field is not required.';

        for ($i = 1; $i <= $numItems; $i++) {

            if ($i == 7) {
                $this->form->addElement("header", null, "Response Booklet B");
                $group[] = &$this->form->createElement("static", null, null, "Time");
                $group[] = &$this->form->createElement("static", null, null, "Errors");
                $group[] = &$this->form->createElement("static", null, null, "Score");
                $this->form->addGroup($group, null, "", $this->_GUIDelimiter, false);
                unset($group);
            }
            if ($i == 13) {
                $this->form->addElement("header", null, "Response Booklet C");
                $group[] = &$this->form->createElement("static", null, null, "Time");
                $group[] = &$this->form->createElement("static", null, null, "Errors");
                $group[] = &$this->form->createElement("static", null, null, "Score");
                $this->form->addGroup($group, null, "", $this->_GUIDelimiter, false);
                unset($group);
            }

            $field = "q_{$this->j}_item{$i}_time";
            $field2 = "q_{$this->j}_item{$i}_errors";
            $group[]=&$this->form->createElement("text", $field, "");
            $this->WrapperTextElements[$field] = $group[0];
            $group[] = $this->createSelect(
                $field . "_status",
                "",
                array(
                    null           => '',
                    'not_answered' => 'Not Answered',
                ),
                array('class' => 'form-control input-sm not-answered')
            );
            $group[]=&$this->form->createElement("text", $field2, "");
            $this->WrapperTextElements[$field] = $group[0];
            $group[] = $this->createSelect(
                $field2 . "_status",
                "",
                array(
                    null           => '',
                    'not_answered' => 'Not Answered',
                ),
                array('class' => 'form-control input-sm not-answered')
            );

            $group[]=&$this->form->createElement("select", "q_{$this->j}_item{$i}_score", "",
                $this->answerArray);

            $this->form->addGroup($group, "q_{$this->j}_item{$i}", "Item $i", null, false);
            unset($group);

            $this->XINRegisterRule(
                $field,
                array($field.'_status{@}=={@}NEVER_REQUIRED'),
                $rule_message,
                "q_{$this->j}_item{$i}"
            );

            $this->XINRegisterRule(
                $field2,
                array($field.'_status{@}=={@}NEVER_REQUIRED'),
                $rule_message,
                "q_{$this->j}_item{$i}"
            );

            $this->XINRegisterRule(
                "q_{$this->j}_item{$i}_score",
                array("q_{$this->j}_item{$i}_score{@}=={@}NEVER_REQUIRED"),
                $rule_message,
                "q_{$this->j}_item{$i}"
            );

            $this->j++;
        }

        // Item Set Administered
        $this->form->addElement('static', null, "<br />");
        $group[] = &$this->form->createElement("static", null, null, "From");
        $group[] = &$this->form->createElement("static", null, null, "To");
        $this->form->addGroup($group, null, "", $this->_GUIDelimiter, false);
        unset($group);
        $itemSetArray = array_merge(array("" => null), range(0, $numItems));
        $group[]=&$this->form->createElement("select", "page_{$page}_item_set_from", null, $itemSetArray);
        $group[]=&$this->form->createElement("select", "page_{$page}_item_set_to", null, $itemSetArray);
        $this->XINRegisterRule("page_{$page}_item_set_from", array("page_{$page}_item_set_from{@}=={@}NEVER_REQUIRED"), "Not Required.", "page_{$page}_item_set");
        $this->XINRegisterRule("page_{$page}_item_set_to", array("page_{$page}_item_set_to{@}=={@}NEVER_REQUIRED"), "Not Required.", "page_{$page}_item_set");

        $this->form->addGroup($group, "page_{$page}_item_set", "Item Set Administered", $this->_GUIDelimiter, false);
        unset($group);

        $this->form->addElement('static', null, "<br />");
        $this->form->addElement("textarea", "other_comments{$page}", "Comments:", array('cols'=>25, 'rows'=>4));
        $this->XINRegisterRule("other_comments{$page}", array("{other_comments{$page}}{@}=={@}NEVER_REQUIRED"));
        $this->form->addElement('static', null, "<br />");

    }

    function _page15() {


        $this->form->addElement("header", null, "Recall of Digits Backward");
        $this->form->addElement('static', null, "<br />");

        $page = 15;

        $this->j = 419;

        $group[] = &$this->form->createElement("static", null, null, "Response");
        $group[] = &$this->form->createElement("static", null, null, "Score");
        $this->form->addGroup($group, null, "", $this->_GUIDelimiter, false);
        unset($group);

        $numItems = 30;

        $rule_message='This field is not required.';

        for ($i = 1; $i <= $numItems; $i++) {

            $field = "q_{$this->j}_item{$i}_response";
            $group[]=&$this->form->createElement("text", $field, "");
            $this->WrapperTextElements[$field] = $group[0];
            $group[] = $this->createSelect(
                $field . "_status",
                "",
                array(
                    null           => '',
                    'not_answered' => 'Not Answered',
                ),
                array('class' => 'form-control input-sm not-answered')
            );

            $group[]=&$this->form->createElement("select", "q_{$this->j}_item{$i}_score", "",
                $this->answerArray);

            $this->form->addGroup($group, "q_{$this->j}_item{$i}", "Item $i", null, false);
            unset($group);

            $this->XINRegisterRule(
                $field,
                array($field.'_status{@}=={@}NEVER_REQUIRED'),
                $rule_message,
                "q_{$this->j}_item{$i}"
            );

            $this->XINRegisterRule(
                "q_{$this->j}_item{$i}_score",
                array("q_{$this->j}_item{$i}_score{@}=={@}NEVER_REQUIRED"),
                $rule_message,
                "q_{$this->j}_item{$i}"
            );

            $this->j++;
        }

        $itemSetArray = array_merge(array("" => null), range(0, $numItems));
        $group[]=&$this->form->createElement("select", "page_{$page}_number_correct", null, $itemSetArray);
        $this->XINRegisterRule("page_{$page}_number_correct", array("page_{$page}_number_correct{@}=={@}NEVER_REQUIRED"), "Not Required.", "page_{$page}_item_set");

        $this->form->addGroup($group, "page_{$page}_item_set", "Number Correct", $this->_GUIDelimiter, false);
        unset($group);

        $this->form->addElement('static', null, "<br />");
        $this->form->addElement("textarea", "other_comments{$page}", "Comments:", array('cols'=>25, 'rows'=>4));
        $this->XINRegisterRule("other_comments{$page}", array("{other_comments{$page}}{@}=={@}NEVER_REQUIRED"));
        $this->form->addElement('static', null, "<br />");

    }

    function _page16() {

        $this->form->addElement("header", null, "Phonological Processing");
        $this->form->addElement('static', null, "<br />");

        $page = 16;

        $this->j = 449;

        $numItems1 = 11;
        $numItems2 = 26;
        $numItems3 = 41;
        $numItems4 = 53;

        $k = 1;

        $rule_message='This field is not required.';

        for ($i = 1; $i <= $numItems4; $i++) {

            if ($i == 1 || $i == ($numItems1 + 1) || $i == ($numItems2 + 1) || $i == ($numItems3 +1)) {
                $this->form->addElement("header", null, "Task $k");
                $group[] = &$this->form->createElement("static", null, null, "Response");
                $group[] = &$this->form->createElement("static", null, null, "Score");
                $this->form->addGroup($group, null, "", $this->_GUIDelimiter, false);
                unset($group);
                $k++;
            }

            $field = "q_{$this->j}_item{$i}_response";
            $group[]=&$this->form->createElement("text", $field, "");
            $this->WrapperTextElements[$field] = $group[0];
            $group[] = $this->createSelect(
                $field . "_status",
                "",
                array(
                    null           => '',
                    'not_answered' => 'Not Answered',
                ),
                array('class' => 'form-control input-sm not-answered')
            );

            $group[]=&$this->form->createElement("select", "q_{$this->j}_item{$i}_score", "",
                $this->answerArray);

            $this->form->addGroup($group, "q_{$this->j}_item{$i}", "Item $i", null, false);
            unset($group);

            $this->XINRegisterRule(
                $field,
                array($field.'_status{@}=={@}NEVER_REQUIRED'),
                $rule_message,
                "q_{$this->j}_item{$i}"
            );

            $this->XINRegisterRule(
                "q_{$this->j}_item{$i}_score",
                array("q_{$this->j}_item{$i}_score{@}=={@}NEVER_REQUIRED"),
                $rule_message,
                "q_{$this->j}_item{$i}"
            );

            $this->j++;
        }

        $this->form->addElement('static', null, "<br />");
        $this->form->addElement("textarea", "other_comments{$page}", "Comments:", array('cols'=>25, 'rows'=>4));
        $this->XINRegisterRule("other_comments{$page}", array("{other_comments{$page}}{@}=={@}NEVER_REQUIRED"));
        $this->form->addElement('static', null, "<br />");

    }

    // NEED TO DO THIS
    function _page17() {

        $this->form->addElement("header", null, "Optional Core Analysis");
        $this->form->addElement('static', null, "<br />");

        $page = 17;

        $this->j = 502;

        $array1 = array(""=>NULL, "overall_sample"=>"Overall Sample", "ability_level"=>"Ability Level",
        "not_answered"=>"Not 
        Answered");
        $array2 = array(""=>NULL, "gca"=>"Mean T for GCA", "snc"=>"Mean T for SNC", "not_answered"=>"Not Answered");
        $statisticalSignificanceArray = array(""=>NULL, "0.15"=>"0.15", "0.05"=>"0.05", "0.01"=>"0.01", "not_answered"=>"Not Answered");

        $this->form->addElement("header", null, "Discrepancy Comparisons");
        $this->form->addElement("select", "q_{$this->j}_check_one_discrepancy", "Check One", $array1);
        $this->form->addElement("select", "q_{$this->j}_stat_sig_discrepancy",
            "Statistical Significance Level", $statisticalSignificanceArray);
        $this->XINRegisterRule("q_{$this->j}_check_one_discrepancy", array("q_{$this->j}_check_one_discrepancy{@}=={@}NEVER_REQUIRED"), "Not Required.");
        $this->XINRegisterRule("q_{$this->j}_stat_sig_discrepancy", array("q_{$this->j}_stat_sig_discrepancy{@}=={@}NEVER_REQUIRED"), "Not Required.");

        $this->j++;

        $this->form->addElement("header", null, "Determining Strengths and Weaknesses");
        $this->form->addElement("select", "q_{$this->j}_check_one_strengths_weaknesses", "Check One", $array2);
        $this->form->addElement("select", "q_{$this->j}_stat_sig_strengths_weaknesses",
            "Statistical Significance Level", $statisticalSignificanceArray);
        $this->XINRegisterRule("q_{$this->j}_check_one_strengths_weaknesses", array("q_{$this->j}_check_one_strengths_weaknesses{@}=={@}NEVER_REQUIRED"), "Not Required.");
        $this->XINRegisterRule("q_{$this->j}_stat_sig_strengths_weaknesses", array("q_{$this->j}_stat_sig_strengths_weaknesses{@}=={@}NEVER_REQUIRED"), "Not Required.");
        $this->j++;

        $this->form->addElement("header", null, "Out-of-Level Subtest Discrepancy Comparisons");
        $this->form->addElement("select", "q_{$this->j}_stat_sig_subtest",
            "Statistical Significance Level", $statisticalSignificanceArray);
        $this->XINRegisterRule("qq_{$this->j}_stat_sig_subtest", array("q_{$this->j}_stat_sig_subtest{@}=={@}NEVER_REQUIRED"), "Not Required.");
        $this->j++;


        $this->form->addElement('static', null, "<br />");
        $this->form->addElement("textarea", "other_comments{$page}", "Comments:", array('cols'=>25, 'rows'=>4));
        $this->XINRegisterRule("other_comments{$page}", array("{other_comments{$page}}{@}=={@}NEVER_REQUIRED"));
        $this->form->addElement('static', null, "<br />");

    }

    function _page18() {


        $this->form->addElement("header", null, "Behavioral Observations");
        $this->form->addElement('static', null, "<br />");

        $page = 18;

        $this->j = 505;

        $observations = array("referral"=>"Referral source / Reason for referral",
            "language"=>"Language",
            "physical_appearance"=>"Physical appearance",
            "visual_auditory_motor_problems"=>"Visual/Auditory/Motor problems",
            "attention_concentration"=>"Attention and concentration",
            "attitude"=>"Attitude toward testing",
            "affect_mood"=>"Affect/Mood",
            "unusual_behavior"=>"Uusual behaviours/Verbalizations",
            "other_notes"=>"Other notes"
            );

        foreach ($observations as $key => $label) {
            $this->addTextAreaElement("q_{$this->j}_{$key}", $label);
            $this->XINRegisterRule("q_{$this->j}_{$key}", array("{q_{$this->j}_{$key}}{@}=={@}NEVER_REQUIRED"));
            $this->j++;
        }
    }

}

?>
