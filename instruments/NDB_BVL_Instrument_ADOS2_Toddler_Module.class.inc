<?php

class NDB_BVL_Instrument_ADOS2_Toddler_Module extends NDB_BVL_Instrument_IBIS
{
    /*
        INSERT INTO test_names VALUES ('', 'ADOS2_Toddler_Module', 'ADOS-2 - Toddler Module', '0', '1');

        INSERT INTO instrument_subtests (Test_name, Subtest_name, Description, Order_number) VALUES('ADOS2_Toddler_Module', 'ADOS2_Toddler_Module_page1', 'Observation 1-5', 1);
        INSERT INTO instrument_subtests (Test_name, Subtest_name, Description, Order_number) VALUES('ADOS2_Toddler_Module', 'ADOS2_Toddler_Module_page2', 'Observation 6-11', 2);
        INSERT INTO instrument_subtests (Test_name, Subtest_name, Description, Order_number) VALUES('ADOS2_Toddler_Module', 'ADOS2_Toddler_Module_page3', 'Sections A-B', 3);
        INSERT INTO instrument_subtests (Test_name, Subtest_name, Description, Order_number) VALUES('ADOS2_Toddler_Module', 'ADOS2_Toddler_Module_page4', 'Sections C-E', 4);

        INSERT INTO test_battery (Test_name,AgeMinDays,AgeMaxDays, Active, Stage, SubprojectID) VALUES ("ADOS2_Toddler_Module", "660", "780","Y","Visit","1");
        INSERT INTO test_battery (Test_name,AgeMinDays,AgeMaxDays, Active, Stage, SubprojectID) VALUES ("ADOS2_Toddler_Module", "660", "780","Y","Visit","2");
        INSERT INTO test_battery (Test_name,AgeMinDays,AgeMaxDays, Active, Stage, SubprojectID) VALUES ("ADOS2_Toddler_Module", "660", "780","Y","Visit","3");
    */
    var $option01238 = array("" => NULL, 0 => 0, 1 => 1, 2 => 2, 3 => 3, 8 => 8, "not_answered" => "Not Answered");
    var $option01234 = array("" => NULL, 0 => 0, 1 => 1, 2 => 2, 3 => 3, 4 => 4, "not_answered" => "Not Answered");
    var $option0128 = array("" => NULL, 0 => 0, 1 => 1, 2 => 2, 8 => 8, "not_answered" => "Not Answered");
    var $option0123 = array("" => NULL, 0 => 0, 1 => 1, 2 => 2, 3 => 3, "not_answered" => "Not Answered");
    var $option02 = array("" => NULL, 0 => 0, 2 => 2, "not_answered" => "Not Answered");
    var $option012 = array("" => NULL, 0 => 0, 1 => 1, 2 => 2, "not_answered" => "Not Answered");
    var $option0127 = array("" => NULL, 0 => 0, 1 => 1, 2 => 2, 7 => 7, "not_answered" => "Not Answered");
    var $option01237 = array("" => NULL, 0 => 0, 1 => 1, 2 => 2, 3 => 3, 7 => 7, "not_answered" => "Not Answered");
    var $option012378 = array("" => NULL, 0 => 0, 1 => 1, 2 => 2, 3 => 3, 7 => 7, 8 => 8, "not_answered" => "Not Answered");
    var $scoreCols = array("social_affect_total", "restricted_repetitive_behavior_total", "social_affect_restricted_repetitive_behavior_total", "ADOS_classification", 'a2_weighted', 'a3_weighted', 'a8_weighted', 'b1_weighted', 'b3_weighted', 'b4_weighted', 'b5_weighted', 'b9_weighted', 'b10_weighted', 'b11_weighted', 'b12_weighted', 'd1_weighted', 'd2_weighted', 'd4_weighted', 'severity_score_lookup');
    /**
     * Array of column names to be ignored by the double data entry conflict detector.
     */
    /**
     * sets up basic data, such as the LorisForm object, and so on.
     * @param string $commentID the CommentID identifying the data to load
     * @param string $page if a multipage form, the page to show
     * @return void
     * @access public
     */
    function setup(?string $commentID = NULL, ?string $page = NULL): void
    {
        $this->formType = "XIN";
        $this->form = new LorisForm('ADOS2_Toddler_Module');
        $this->page = $page;            // page label (number or
        // string - used by
        // user-defined child classes)
        // set the object properties
        $this->testName = "ADOS2_Toddler_Module";           // test_names.Test_name
        $this->table = 'ADOS2_Toddler_Module';              // name of database table corresponding to instrument
        // data keyed by commentID
        $this->commentID = $commentID;
        //The array of dates/timestamps to convert to database dates/timestamps
        //Any LorisForm date elements must be listed here
        $this->dateTimeFields = array("Date_taken");
        //The array of selects with multiple answers allowed
        //Any LorisForm multiple selects must be listed here
        $this->_selectMultipleElements = array();
        // required fields for data entry completion status
        $this->_requiredElements = array('Examiner');
        $this->_doubleDataEntryDiffIgnoreColumns = array('CommentID', 'UserID', 'Testdate', 'Window_Difference', 'Candidate_Age', // Text entry column
            'Data_entry_completion_status');
        // setup the form
        $this->_setupForm();
    }

    //If the instrument is not paged, remove the switch from the _setupForm method and add all the form Elements in this function.

    /**
     * method to build the LorisForm object into a paged form
     * @return void
     * @access private
     */
    function _setupForm()
    {
        if (preg_match("/ADOS2_Toddler_Module(_page[0-9]+)/", $this->page, $matches)) {
            call_user_func(array($this, $matches[1]));
        } else {
            $this->_main();
        }
        //Defines the call back function for HTML Quickform to use when validating the form.
        $this->form->addFormRule(array(&$this, 'XINValidate'));
    }

    /**
     * generates the main page of the form.
     * @return void
     * @access private
     */
    function _main()
    {
        $this->form->addElement('header', 'instrument_title', "ADOS-2 Toddler Module");
        $this->_addMetadataFields();
        $this->form->addElement("header", null, "SUMMARY SCORES:");
        $this->form->addElement('static', "social_affect_total", "Social Affect Total:");
        $this->form->addElement('static', "restricted_repetitive_behavior_total", "Restricted and Repetitive Behavior Total:");
        $this->form->addElement('static', "social_affect_restricted_repetitive_behavior_total", "Social Affect and Restricted and Repetitive Behavior Total:");
        $this->form->addElement('static', "ADOS_SA_CSS", "ADOS_SA_CSS:");
        $this->form->addElement('static', "ADOS_RRB_CSS", "ADOS_RRB_CSS:");
        $this->form->addElement('static', "ADOS_classification", "ADOS Classification:");
        $this->form->addElement('header', null, 'Severity Scores:');
        $this->form->addElement('static', 'severity_score_lookup', 'Severity Score:');
        /*
            $group[]= &$this->form->createElement("static", "ADOS_classification", null);
             $this->form->addGroup($group, null, "ADOS Classification:", $this->_GUIDelimiter, false);
            unset($group);

            $this->form->addElement("static",null,null);
            $this->form->addElement("static",null,null);
            */
    }

    function _page01()
    {
        $headings = array(
            "1." => "Free Play",
            "1a." => "Free Play - Ball",
            "2." => "Blocking Toy Play",
            "3." => "Response to Name",
            "4." => "Bubble Play",
            "4a." => "Bubble Play - Teasing Toy Play",
            "5." => "Anticipation of a Routine With Objects",
            "5a." => "Anticipation of a Routine With Objects - Unable Toy Play"
        );
        $headingSuffix = "heading";
        $level1 = array(
            "1.1." => "Does the child spontaneously seek engagement with the parent/caregiver?",
            "1.2." => "Does the child direct affect to others?",
            "1.3." => "Does the child explore materials, either symbolically or functionally?",
            "1.4." => "Does the child stay with activities, flit from object to object, or engage in repetitive actions?",
            "1a.1." => "How does the child respond to the introduction of a ball?",
            "1a.2." => "Does the child initiate or respond to common games using the ball?",
            "1a.3." => "Note behaviors relevant to the general focus of observation specified for \"Free Play.\"",
            "2.1." => "How does the child respond to the socially ambiguous situation in which you intentionally prevent access to a toy for no apparent reason?",
            "2.2." => "Is the child able to use eye contact to infer your intent?",
            "2.3." => "Does the child manipulate your hand as a form of communicative response?",
            "2.4." => "Does the child display any directed facial expressions (e.g., a confused facial expression)?",
            "2.5." => "Choose for each behavior observed:",
            "3.1." => "Observe and evaluate the consistency of the child's response to the hierarchy of presses.",
            "3.2." => "What sounds and actions must you or the parent/caregiver make to get the child's attention?",
            "3.3." => "How does the child respond? does the child...",
            "4.1." => "Observe the child's affect, initiation of joint attention, shared enjoyment, requesting, and motor behavior while the bubbles are present.",
            "4.2." => "Does the child display any unusual sensory behaviors or movements?",
            "4a.1." => "How does the child respond to the socially ambiguous situation in which you intentionally prevent access to a toy in a playful manner?",
            "4a.2." => "Observe the child's use of eye contact, vocalization, or other communicative behaviors to determine your intention and to express displeasure or other emotions.",
            "4a.3." => "Note the child's use of directed facial expression and motor behavior.",
            "4a.4." => "Choose for each behavior observed:",
            "5.1." => "Observe the child's affect, initiation of joint attention, shared enjoyment, requesting, and motor responses, particularly repetitive mannerisms.",
            "5a.1." => "How does the child respond to the socially ambiguous situation in which you appear unintentionally unable to complete a play activity?",
            "5a.2." => "Observe the child's use Of eye contact, vocalization, or other communicative behaviors to decipher the situation, as well as any directed facial expressions, gestures, and motor responses.",
            "5a.3." => "Choose for each behavior observed:"

        );
        $level1Suffix = "l1";
        $level2 = array(
            "1.1.a." => "If so, how does he or she do this?",
            "1.1.b." => "Does it involve joint reference to objects, such as giving and showing, or is it limited to seeking affection or help?",
            "1.1.c." => "How does the child communicate, if at all?",
            "1.2.a." => "How is it conveyed?",
            "2.2.a." => "In the absence of gaze, can the child indicate an awareness of an unusual situation through vocalization?",
            "2.3.a." => "Is such manipulation combined with other forms of communication?",
            "3.3.a." => "Display eye contact?",
            "3.3.b." => "Look at your face or in your general direction and/or 100k at the parent/caregiver's face or in the parent/caregiver's general direction?",
            "3.3.c." => "Vocalize?",
        );
        $level2Suffix = "l2";
        $trialQuestions = array("_trial1" => "Trial 1", "_trial2" => "Trial 2");
        $trialOptions = array(null => "", "ec_examiner" => "EC (examiner)", "ec_other" => "EC (other)", "moves_hand" => "Moves hand", "vocal_distress" => "Vocal distress", "other_vocal" => "Other vocal", "no_response" => "No response", "na" => "N/A", "other" => "Other");

        $this->form->addElement('header', null, "OBSERVATION");
        $this->form->addElement('static', null, "<h4><b>Note: Initiation of joint attention</b> requires a spontaneous <i>3-point gaze shift</i> between an object and person with no apparent purpose other than to share interest or pleasure (it may or may not involve a pointing gesture as well).<br />A <i>3-point gaze shift</i> is defined by the child looking at an object, looking at a person (with the goal of catching his or her gaze in order to direct it to the object), and then looking back at the object, or by the child looking at the person first, then the object, and then looking back at the person.</h4>");
        foreach ($headings as $headingKey => $headingValue) {
            $this->addStaticText($headingSuffix . $this->removeDot($headingKey), "<h3><b>" . $headingKey . " " . $headingValue . "</b></h3>");
            $this->form->addElement("static", null, "<b>Focus of Observation:</b>");
            foreach ($level1 as $l1Key => $l1Value) {
                if ($this->startsWith($l1Key, $headingKey)) {
                    if ($this->isQuestion($l1Value)) {
                        $this->addText($level1Suffix . $this->removeDot($l1Key), $this->remove_prefix($l1Key, $headingKey) . " " . $l1Value);
                    } else $this->addStaticText($level1Suffix . $this->removeDot($l1Key), $this->remove_prefix($l1Key, $headingKey) . " " . $l1Value);
                    foreach ($level2 as $l2Key => $l2Value) {
                        if ($this->startsWith($l2Key, $l1Key)) {
                            if ($this->isQuestion($l2Value))
                                $this->addText($level2Suffix . $this->removeDot($l2Key), "<h5>" . $this->indent . $this->remove_prefix($l2Key, $l1Key) . " " . $l2Value . "</h5>");
                            else $this->addStaticText($level2Suffix . $this->removeDot($l2Key), "<h5>" . $this->indent . $this->remove_prefix($l2Key, $l1Key) . " " . $l2Value . "</h5>");
                        }
                    }
                    if ($l1Key == "1.4.") {
                        $this->form->addTextArea("communicationSample", "Communication Sample:");
                        $this->XINRegisterRule("communicationSample", array("communicationSample{@}=={@}NEVER_REQUIRED"));
                    }
                    if ($l1Key == "2.5.") {
                        foreach ($trialQuestions as $k => $v) {
                            $suffix = "blockingToyPlayTrial";
                            $this->form->addSelect($suffix . $k, $v, $trialOptions);
                            $this->form->addText($suffix . $k . "_other", "Other: ");
                            $this->XINRegisterRule($suffix . $k . "_other", array($suffix . $k . "_other" . "{@}=={@}NEVER_REQUIRED"));
                        }
                    }
                    if ($l1Key == "3.3.") {
                        $this->form->addElement('static', null, "<b>Hierarchy of Presses</b>");
                        $this->form->addElement('static', null, "<h5>(1) Call the child's name UPTO four times.<br>
If the child makes an appropriate vocal response without orienting toward your face upon one of the first two presses, start the task over with four new tries calling the child's name.<br>
(2) Ask the parent/caregiver to call the child's name UP TO two times.<br>
(3) Ask the parent/caregiver to Say other words or make a familiar noise or sound (this can be in a way that implies physical contact but does not actually involve touching the child, e.g., \"I'm gonna get you!\") UP TO two times.<br>
(4) Ask the parent/caregiver to do whatever necessary, including touching the child, to get him or her to look at the parent/caregiver.</h5>");
                    }
                    if ($l1Key == "4a.4.") {
                        foreach ($trialQuestions as $k => $v) {
                            $suffix = "bubblePlayTeasingToyPlayTrial";
                            $this->form->addSelect($suffix . $k, $v, $trialOptions);
                            $this->form->addText($suffix . $k . "_other", "Other: ");
                            $this->XINRegisterRule($suffix . $k . "_other", array($suffix . $k . "_other" . "{@}=={@}NEVER_REQUIRED"));
                        }
                    }
                    if ($l1Key == "5a.3.") {
                        foreach ($trialQuestions as $k => $v) {
                            $suffix = "anticipationRoutineObjectsUnableToyPlayTrial";
                            $this->form->addSelect($suffix . $k, $v, $trialOptions);
                            $this->form->addText($suffix . $k . "_other", "Other: ");
                            $this->XINRegisterRule($suffix . $k . "_other", array($suffix . $k . "_other" . "{@}=={@}NEVER_REQUIRED"));
                        }
                    }
                }
            }
        }

        $this->form->addFormRule(array(&$this, 'validate_page01'));
    }

    function validate_page01($values)
    {
        $errors = [];
        $trialFieldNames = array(
            "blockingToyPlayTrial",
            "bubblePlayTeasingToyPlayTrial",
            "anticipationRoutineObjectsUnableToyPlayTrial"
        );
        $trials = array("_trial1", "_trial2");
        foreach ($trialFieldNames as $trialFieldName) {
            foreach ($trials as $trial) {
                if ($values[$trialFieldName . $trial] == "other" && ($values[$trialFieldName . $trial . "_other"] == null || $values[$trialFieldName . $trial . "_other"] == ""))
                    $errors[$trialFieldName . $trial . "_other"] = "Required if other.";
                if ($values[$trialFieldName . $trial] != "other" && ($values[$trialFieldName . $trial . "_other"] != null || $values[$trialFieldName . $trial . "_other"] != ""))
                    $errors[$trialFieldName . $trial . "_other"] = "Not required.";
            }
        }
        return $errors;
    }

    function _page02()
    {
        $headings = array(
            "6." => "Anticipation of a Social Routine",
            "7." => "Response to Joint Attention",
            "8." => "Responsive Social Smile",
            "9." => "Bath Time",
            "9a." => "Bath Time - Ignore",
            "10." => "Functional and Symbolic Imitation",
            "11." => "Snack"
        );
        $headingSuffix = "heading";
        $level1 = array(
            "6.1." => "Evaluate the child's affect and his or her attempts to initiate repetition of the routine.",
            "6.2." => "Pay particular attention to the social directedness of the child's behaviors and the extent to which he or she integrates gaze, facial expression, vocalization, and gesture in actions directed to you or the parent/caregiver, especially those behaviors that are indicative of shared enjoyment.",
            "7.1." => "Does the child follow a shift in gaze alone or follow a shift in gaze when it is accompanied by pointing?",
            "7.2." => "Pay attention to the child's behaviors when playing with the remote-controlled toy, including eye contact, vocalizations, requesting, shared enjoyment, initiations of joint attention, and pretend play (e.g., hugging or kissing the toy animal).",
            "8.1." => "Evaluate the occurrence of the child's smile in response to:",
            "9.1." => "Evaluate the child's interest in and ability to join in the social \"script\" of a doll's bath time routine.",
            "9.2." => "Does the child treat the doll as a representation of an animate being?",
            "9.3." => "Does the child spontaneously contribute to, and build upon, the enactment of the bath time routine?",
            "9.4." => "Note any use of a non-meaningful object to represent another object (e.g., using a block as a shampoo bottle).",
            "9a.1." => "How does the child behave when ignored by you and the parent/caregiver?",
            "9a.2." => "Pay attention to:",
            "10.1." => "How does the child use miniature objects and a placeholder in imitation of familiar actions?",
            "10.2." => "Are these acts carried out with social awareness and shared enjoyment?",
            "11.1." => "Does the child indicate a preference and request food?",
            "11.2." => "How does the child use gaze, gesture, reaching, facial expression, and vocalization to communicate requests to you and to make social overtures?",
            "11.3." => "Does the child show his or her snack to the parent/caregiver or try to feed and/or share with the adults in the room?"
        );
        $level1Suffix = "l1";
        $level2 = array(
            "8.1.a." => "the parent/caregiver smiling,",
            "8.1.b." => "the parent/caregiver smiling and making a familiar noise or calling in a way that implies physical contact but without actually touching the child (e.g., \"I'm gonna get you!\"), or",
            "8.1.c." => "being touched.",
            "9.3.a." => "If not, will the child imitate your actions spontaneously or participate when asked or directed to do so?",
            "9a.2.a." => "how the child occupies himself or herself,",
            "9a.2.b." => "how the child responds to your and the parent/caregiver's withdrawal from the interaction, and",
            "9a.2.c." => "if and how the child initiates interaction with you or the parent/caregiver.",
            "11.1.a." => "If so, how does he or she do this?"
        );
        $level2Suffix = "l2";

        $this->form->addElement('header', null, "OBSERVATION");
        $this->form->addElement('static', null, "<h4><b>Note: Initiation of joint attention</b> requires a spontaneous <i>3-point gaze shift</i> between an object and person with no apparent purpose other than to share interest or pleasure (it may or may not involve a pointing gesture as well).<br />A <i>3-point gaze shift</i> is defined by the child looking at an object, looking at a person (with the goal of catching his or her gaze in order to direct it to the object), and then looking back at the object, or by the child looking at the person first, then the object, and then looking back at the person.</h4>");
        foreach ($headings as $headingKey => $headingValue) {
            $this->addStaticText($headingSuffix . $this->removeDot($headingKey), "<h3><b>" . $headingKey . " " . $headingValue . "</b></h3>");
            $this->form->addElement("static", null, "<b>Focus of Observation:</b>");
            foreach ($level1 as $l1Key => $l1Value) {
                if ($this->startsWith($l1Key, $headingKey)) {
                    if ($this->isQuestion($l1Value)) {
                        $this->addText($level1Suffix . $this->removeDot($l1Key), $this->remove_prefix($l1Key, $headingKey) . " " . $l1Value);
                    } else $this->addStaticText($level1Suffix . $this->removeDot($l1Key), $this->remove_prefix($l1Key, $headingKey) . " " . $l1Value);
                    foreach ($level2 as $l2Key => $l2Value) {
                        if ($this->startsWith($l2Key, $l1Key)) {
                            if ($this->isQuestion($l2Value))
                                $this->addText($level2Suffix . $this->removeDot($l2Key), "<h5>" . $this->indent . $this->remove_prefix($l2Key, $l1Key) . " " . $l2Value . "</h5>");
                            else $this->addStaticText($level2Suffix . $this->removeDot($l2Key), "<h5>" . $this->indent . $this->remove_prefix($l2Key, $l1Key) . " " . $l2Value . "</h5>");
                        }
                    }
                    if ($l1Key == "6.2.") {
                        $this->form->addSelect("anticipationOfSocialRoutine", "Follow this order and choose routine used:", array(null => "", "peekaboo" => "Peekaboo", "tickle" => "Tickle", "swingInAir" => "Swing in air"));
                    }
                    if ($l1Key == "7.2.") {
                        $this->addStaticText(null, "<b>Hierarchy of Presses</b>");
                        $this->addStaticText(null, "<h5>(1) Orient the child's body toward your face, if possible.<br>
a. Up to five attempts should be made to attract the child's attention toward your face before administering the activity.<br>
b. If the child's attention is NOT obtained, you should still proceed through the hierarchy of presses, including activation of the toy.<br>
(2) Say: <b>\"(Child's name), look!\"</b> (exaggerate your gaze shift).<br>
(3) Say: <b>\"(Child's name), look at that!\"</b> (exaggerate your gaze shift), UP TO two times.<br>
(4) Say: <b>\"(Child's name), look at that!\"</b> (with a gaze shift and a point), UP TO two times.<br>
(5) Activate the toy.</h5>");
                    }
                    if ($l1Key == "9a.2.") {
                        $this->addNumericElement("bathTimeIgnoreDuration", "Duration of Ignore (seconds):");
                    }
                    if ($l1Key == "10.2.") {
                        $this->addStaticText(null, "<b>Hierarchy of Presses</b>");
                        $this->addStaticText(null, "<h5>(1) Teaching trial(s): Real object (car or frog) UP TO three trials total.<br>
(2) Imitation trials, Phase 1: Real object UP TO three trials per object; use only objects not used in the teaching trials.<br>
(3) Imitation trials, Phase 2: Placeholder representing object just demonstrated in Phase 1; UP TO three trials per object.<br>
(4) Imitation trials, Phase 3: Placeholder representing object not previously demonstrated; UP TO three trials per object.<br>
a. The child has \"successfully\" completed the full hierarchy of presses when he or she is able to imitate your use of the placeholder as an object that has not been previously demonstrated in the task.<br>
b. Once all of the objects have been used, the child is out of chances and the activity is complete, regardless of whether there are remaining trials or not.</h5>");
                    }
                }
            }
        }
        $this->form->addFormRule(array(&$this, 'validate_page2'));
    }

    function validate_page02($values)
    {
        $errors = [];

        return $errors;
    }

    function remove_prefix($text, $prefix)
    {
        if (0 === strpos($text, $prefix))
            $text = substr($text, strlen($prefix));
        return $text;
    }

    function isQuestion($text): bool
    {
        return $this->endsWith($text, "?");
    }

    function removeDot($text): string
    {
        return rtrim($text, ".");
    }

    function startsWith($haystack, $needle): bool
    {
        $length = strlen($needle);
        return (substr($haystack, 0, $length) === $needle);
    }

    function endsWith($haystack, $needle): bool
    {
        $length = strlen($needle);
        if ($length == 0) {
            return true;
        }

        return (substr($haystack, -$length) === $needle);
    }

    function addStaticText($name, $label)
    {
        $this->form->addElement('static', $name, $label);
    }

    function addText($name, $label)
    {
        $this->form->addText($name, $label);
    }

    function _page1(){
        //CODING
        //Section A: Language and Communication
        $this->form->addElement('header', null, "CODING:");

        $this->form->addElement('header', null, "Section A: Language and Communication");
        $this->form->addElement('select', 'a1', '1. Overall Level of Non-Echoed Spoken Language', $this->option01234);
        $this->form->addElement('select', 'a1a', '1a. Frequency of Babbling', $this->option01238);
        $this->form->addElement('select', 'a2', '2. Frequency of Spontaneous Vocalization Directed to Others', $this->option0123);
        $this->form->addElement('select', 'a3', '3. Intonation of Vocalizations or Verbalization', $this->option01238);
        $this->form->addElement('select', 'a4', '4. Immediate Echolalia', $this->option01238);
        $this->form->addElement('select', 'a5', '5. Stereotyped/Idiosyncratic Use of Words or Phrases', $this->option01238);
        $this->form->addElement('select', 'a6', '6. Use of Another\'s Body', $this->option01238);
        $this->form->addElement('select', 'a7', '7. Pointing', $this->option0123);
        $this->form->addElement('select', 'a8', '8. Gestures', $this->option01238);
        $this->form->addElement('select', 'a9', '9. Frequency of Undirected Vocalization', $this->option01238);

       //Section B: Reciprocal Social Interaction
        $this->form->addElement('header', null, "Section B: Reciprocal Social Interaction");
        $this->form->addElement('select', 'b1', '1. Unusual Eye Contact', $this->option0123);
        $this->form->addElement('select', 'b2', '2. Teasing Toy Play', $this->option01238);
        $this->form->addElement('select', 'b3', '3. Unable Toy Play', $this->option01238);
        $this->form->addElement('select', 'b4', '4. Facial Expressions Directed to Others', $this->option0123);
        $this->form->addElement('select', 'b5', '5. Integration of Gaze and Other Behaviors During Social Overtures', $this->option0123);
        $this->form->addElement('select', 'b6', '6. Shared Enjoyment in Interaction', $this->option0123);
        $this->form->addElement('select', 'b7', '7. Response to Name', $this->option0123);
        $this->form->addElement('select', 'b8', '8. Ignore', $this->option0123);
        $this->form->addElement('select', 'b9', '9. Requesting', $this->option0123);
        $this->form->addElement('select', 'b10', '10. Amount of Requesting', $this->option0123);
        $this->form->addElement('select', 'b11', '11. Giving', $this->option0123);
        $this->form->addElement('select', 'b12', '12. Showing', $this->option0123);
        $this->form->addElement('select','b13','13. Spontaneous Initiation of Joint Attention',$this->option0123);
        $this->form->addElement('select','b14','14. Response to Joint Attention',$this->option0123);
        $this->form->addElement('select','b15','15. Quality of Social Overtures',$this->option0123);
        $this->form->addElement('select','b16a','16a. Amount of Social Overtures/Maintenance of Attention: EXAMINER',$this->option01237);
        $this->form->addElement('select','b17','17. Level of Engagement',$this->option0123);
        $this->form->addElement('select','b18','18. Overall Quality of Rapport',$this->option0123);
    }

    function _page2(){
        //Section C: Play
        $this->form->addElement('header', null, "Section C: Play");
        $this->form->addElement('select', 'c1', '1. Functional Play with Objects', $this->option0123);
        $this->form->addElement('select', 'c2', '2. Imagination/Creativity', $this->option0123);
        $this->form->addElement('select', 'c3', '3. Functional and Symbolic Imitation', $this->option0123);

        //Section D: Stereotyped Behaviors and Restricted Interests
        $this->form->addElement('header', null, "Section D: Stereotyped Behaviors and Restricted Interests");
        $this->form->addElement('select', 'd1', '1. Unusual Sensory Interest in Play Material/Person', $this->option0123);
         $this->addTextAreaElement('d1_specify', $this->indent . "Please specify:");
        $this->form->addElement('select', 'd2', '2. Hand and Finger and Other Complex Mannerisms', $this->option0123);
        $this->addTextAreaElement('d2_specify', $this->indent . "Please specify:");
        $this->form->addElement('select', 'd3', '3. Other Complex Mannerisms', $this->option0123);
        $this->addTextAreaElement('d3_specify', $this->indent . "Please specify:");
        $this->form->addElement('select', 'd4', '4. Self-Injurious Behavior', $this->option0123);
        $this->form->addElement('select', 'd5', '5. Unusually Repetitive Interests or Stereotyped Behaviors', $this->option0123);
        $this->addTextAreaElement('d5_specify', $this->indent . "Please specify unusual preoccupations, rituals, repetitive behaviors:");

        //Section E: Other Behaviors
        $this->form->addElement('header', null, "Section E: Other Abnormal Behaviors");
        $this->form->addElement('select', 'e1', '1. Overactivity', $this->option01237);
        $this->form->addElement('select', 'e2', '2. Fussiness/Irritability', $this->option0123);
        $this->form->addElement('select', 'e3', '3. Aggression and Disruptive Behavior', $this->option0123);
        $this->form->addElement('select', 'e4', '4. Anxiety', $this->option0123);
    } // End Form

    function score(): void{
        if ($this->_determineDataEntryCompletionStatus() == "Incomplete") {
            return;
        }

        // null scores
        $this->_nullScores($this->scoreCols);

        //get the saved scores
        $db =& Database::singleton();

        $record = $db->pselectRow("SELECT * FROM $this->table WHERE CommentID=:cid",array("cid" =>$this->getCommentID() ));


        //Convert the entered scores to countable scores:
        //"Convert scores of 3 on the protocol to 2, and treat all other scores other than 0-3 as 0."
        $scores = array(); //holds converted scores
        foreach($record as $field=>$value) {
            if($value == 0) {
                $scores[$field] = 0;
            } elseif ($value == 1 && $field != 'b1') {
                $scores[$field] = 1;
            } elseif ($value == 2) {
                $scores[$field] = 2;
            } elseif ($value == 3 && $field != 'b1') {
                $scores[$field] = 2;
            } elseif ($value >= 4) {
                $scores[$field] = 0;
            } elseif ($value == "not_answered") {
                $scores[$field] = 0;
            } elseif ($field == 'b1' && ($value == 1 || $value == 3)) {
                $scores[$field] = 2;
            }
        }

        $module = '';

        // NO WORDS scoring
        if($record["a1"] == 3 || $record["a1"] == 4) {
            $module = '1-NoWords';

            $scoreCols["social_affect_total"] = $scores["a2"] + $scores["a8"] + $scores["b1"] + $scores["b4"] +
                $scores["b5"] + $scores["b6"] + $scores["b12"] + $scores["b13"] + $scores["b14"] + $scores["b15"];
            $scoreCols["restricted_repetitive_behavior_total"] = $scores["a3"] + $scores["d1"] + $scores["d2"] + $scores["d5"];
            $scoreCols["social_affect_restricted_repetitive_behavior_total"] = $scoreCols["social_affect_total"] + $scoreCols["restricted_repetitive_behavior_total"];

            if($scoreCols["social_affect_restricted_repetitive_behavior_total"] >= 10 && $scoreCols["social_affect_restricted_repetitive_behavior_total"] <= 13){
                $scoreCols["ADOS_classification"] = "Mild-to-Moderate Concern";
            } elseif ($scoreCols["social_affect_restricted_repetitive_behavior_total"] >= 14) {
                $scoreCols["ADOS_classification"] = "Moderate-to-Severe Concern";
            } else {
                   $scoreCols["ADOS_classification"] = "Little-to-No Concern";
            }

            // Weightings from Risi, Pickles and Lord 2007 Table 2
            // Put in the same order as the paper, which happens to be different than
            // how Loris orders it, which is why this looks a little weird
            // Social Affect
            $scoreCols['b1_weighted'] = $scores['b1'] * 0.64; // Unusual Eye Contact
            $scoreCols['b4_weighted'] = $scores['b4'] * 0.76; // Gaze and Other
            $scoreCols['b3_weighted'] = $scores['b3'] * 0.85; // Facial Expressions
            $scoreCols['a2_weighted'] = $scores['a2'] * 0.69; // Frequency of vocalization
            $scoreCols['b5_weighted'] = $scores['b5'] * 0.71; // Shared Enjoyment
            $scoreCols['b12_weighted'] = $scores['b12'] * 0.74; // Quality of Social Overtures
            $scoreCols['b11_weighted'] = $scores['b11'] * 0.60;// Response to Joint Attention
            $scoreCols['a8_weighted'] = $scores['a8'] * 0.73; // Gestures
            $scoreCols['b9_weighted'] = $scores['b9'] * 0.69; // Showing
            $scoreCols['b10_weighted'] = $scores['b10'] * 0.77;// Initiation of Joint Attention
            // Restricted Repetitive Behaviours
            $scoreCols['a3_weighted'] = $scores['a3'] * 0.44; // Intonation
            $scoreCols['d1_weighted'] = $scores['d1'] * 0.78; // Unusual Sensory Interest
            $scoreCols['d4_weighted'] = $scores['d4'] * 0.44; // Repetitive Interests
            $scoreCols['d2_weighted'] = $scores['d2'] * 0.66; // Hand Mannerisms
        }

        //SOME WORDS Scoring
        if($record["a1"] == 0 || $record["a1"] == 1 || $record["a1"] == 2) {
            $module = '1-Words';

            $scoreCols["social_affect_total"] = $scores["a2"] + $scores["a7"] + $scores["a8"] + $scores["b1"] +
                $scores["b4"] + $scores["b5"] + $scores["b6"] + $scores["b7"] + $scores["b8"] + $scores["b9"] +
                $scores["b12"] + $scores["b13"] + $scores["b14"] + $scores["b15"] + $scores["b16b"] + $scores["b18"];
            $scoreCols["restricted_repetitive_behavior_total"] = $scores["a3"] + $scores["d1"] + $scores["d2"] + $scores["d5"];
            $scoreCols["social_affect_restricted_repetitive_behavior_total"] = $scoreCols["social_affect_total"] + $scoreCols["restricted_repetitive_behavior_total"];
            if($scoreCols["social_affect_restricted_repetitive_behavior_total"] >= 8 && $scoreCols["social_affect_restricted_repetitive_behavior_total"] <= 11){
                $scoreCols["ADOS_classification"] = "Mild-to-Moderate Concern";
            } elseif ($scoreCols["social_affect_restricted_repetitive_behavior_total"] >= 12) {
                $scoreCols["ADOS_classification"] = "Moderate-to-Severe Concern";
            } else {
                $scoreCols["ADOS_classification"] = "Little-to-No Concern";
            }
        }

        //Determine Severity score from ados_lookup table
        //Requires age in months:
        $Answers = $db->pselectRow("SELECT * FROM $this->table WHERE CommentID=:cid",array("cid" =>$this->getCommentID() ));
        $age_months = 0;
        if($this->getSessionID() != NULL) { //quickform_parser doesn't use any specific session
            $timepoint =& TimePoint::singleton($this->getSessionID());
            $dob = $timepoint->getEffectiveDateOfBirth();
        }

        if(!empty($dob) && !empty($Answers['Date_taken'])) {
            $age = Utility::calculateAge($dob, $Answers["Date_taken"]);
            if(is_array($age)) {
                $age_months = $age['year'] * 12 + $age['mon'];
            }
        }
        //Severity score lookup:  column limits for age (min, max), raw score (min, max)
        // ados_lookup table columns : sevscore module minagemos maxagemos minraw maxraw
        if ( $module != '' && $age_months != 0) {
           $query_severity_lookup = "SELECT sevscore FROM ados_lookup WHERE module = :modname AND minagemos <= :agemonths AND maxagemos >= :agemonths AND minraw <= :rawscore AND maxraw >= :rawscore";
            $record_lookup = array();
            $sevscore = $db->pselectOne($query_severity_lookup, array(
                'modname' => $module,
                'agemonths' => $age_months,
                'rawscore' => $scoreCols['social_affect_restricted_repetitive_behavior_total']
            ));
            if(empty($sevscore)) {
                $scoreCols['severity_score_lookup']= "N/A";
            } else {
                $scoreCols['severity_score_lookup']=$sevscore;
            }

            //($record_lookup['sevscore']);
        }

        // CSS Calculations

        // if the candidate is 23 months old, round to 24 months
        if ($age_months >= 23 && $age_months < 24) {
            $age_months = 24;
        }

        for ($i = 2; $i <= 14; $i++) {
            $low = $i*12;
            $high = ($i+1)*12;
            if ($age_months >= $low && $age_months < $high) {
                $ados_age = $i;
            }
        }
        $scoreCols["ADOS_SA_CSS"]  = $this->ADOS_SA_CSS( $this->table, $record['a1'], $scoreCols['social_affect_total'], $ados_age);
        $scoreCols["ADOS_RRB_CSS"] = $this->ADOS_RRB_CSS($this->table, $record['a1'], $scoreCols['restricted_repetitive_behavior_total'], $ados_age);

        // save scores to database
         $result = $db->update($this->table, $scoreCols, array("CommentID"=>$this->getCommentID()));
    }   // end score function
}

?>
