<?php
/**
 * This file contains the NDB_BVL_Instrument_mcdi_words_gestures_sentences_survey
 * class
 *
 * PHP Version 7
 *
 * @category Instrument
 * @package  IBIS
 * @author   Ling Ma <lingyun.ma@mcin.ca>
 * @date     2020 Apr 22
 * @license  http://www.gnu.org/licenses/gpl-3.0.txt GPLv3
 * @link     https://www.github.com/aces/IBIS/
 */

class NDB_BVL_Instrument_mcdi_words_gestures_sentences_survey extends NDB_BVL_Instrument
{
    use LegacyInstrumentTrait;

    var $ValidityEnabled  = false;
    var $ValidityRequired = false;

    var $scoreLabels = array(
                        "words_produced_number",
                        "early_gestures_number",
                        "later_gestures_number",
                        "total_gestures_number",
                        "word_endings",
                        "word_forms",
                        "word_endings_pt_2",
                        "grammatical_complexity",
                        "words_produced_number_percentile",
                        "early_gestures_number_percentile",
                        "later_gestures_number_percentile",
                        "total_gestures_number_percentile",
                        "word_forms_percentile",
                        "grammatical_complexity_percentile",
                       );

    var $_doubleDataEntryDiffIgnoreColumns = array(
                                              'CommentID',
                                              'Testdate',
                                              'Window_Difference',
                                              'Candidate_Age',
                                              "words_produced_number",
                                              "early_gestures_number",
                                              "later_gestures_number",
                                              "total_gestures_number",
                                              "words_produced_number_percentile",
                                              "early_gestures_number_percentile",
                                              "later_gestures_number_percentile",
                                              "total_gestures_number_percentile",
                                              "word_endings",
                                              "word_forms",
                                              "word_endings_pt_2",
                                              "grammatical_complexity",
                                              "word_forms_percentile",
                                              "grammatical_complexity_percentile",
                                              "Data_entry_completion_status",
                                             );

    /**
     * sets up basic data, such as the LorisForm object, and so on.
     *
     * @param  string $commentID the CommentID identifying the data to load
     * @param  string $page      if a multipage form, the page to show
     * @return void
     * @access public
     */
    function setup(?string $commentID = null, ?string $page = null): void
    {
        $this->formType ="XIN";
        $this->form     = new LorisForm('test_form');
        $this->page     = $page;            // page label (number or string - used by user-defined child classes)

        // set the object properties
        $this->testName = "mcdi_words_gestures_sentences_survey";           // test_names.Test_name
        $this->table    = 'mcdi_words_gestures_sentences_survey';              // name of database table corresponding to instrument
        // data keyed by commentID
        $this->commentID = $commentID;

        //The array of dates/timestamps to convert to database dates/timestamps
        //Any LorisForm date elements must be listed here
        $this->dateTimeFields =array("Date_taken");

        //The array of selects with multiple answers allowed
        //Any LorisForm multiple selects must be listed here
        $this->_selectMultipleElements = array();

        // setup the form
        $this->_setupForm();
    }

    //If the instrument is not paged, remove the switch from the _setupForm method and add all the form Elements in this function.

    /**
     * method to build the LorisForm object into a paged form
     *
     * @return void
     * @access private
     */
    function _setupForm()
    {
        if (preg_match("/mcdi_words_gestures_sentences_survey(_page[0-9]+)/", $this->page, $matches)) {
            call_user_func(array($this, $matches[1]));
        } else {
            $this->_main();
        }

        //Defines the call back function for HTML Quickform to use when validating the form.
        $this->form->addFormRule(array(&$this, 'XINValidate'));
    }

    /**
     * generates the main page of the form.
     *
     * @return void
     * @access private
     */
    function _main()
    {
        // display test name
        $this->form->addElement('header', 'instrument_title', "MCDI - Words, Gestures & Sentences");
        $this->form->addElement('static', null, "<i><h3>*Please fill this form out with regard to your child who has enrolled in our study, NOT their older sibling with autism</i></h3>");

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

        $opts = array(
                 null     => "",
                 "mother" => "Mother",
                 "father" => "Father",
                 "other"  => "Other",
                );

        $this->addSelect("relationship_to_child", "What is your relationship to the child?", $opts);
        $this->addBasicText("other_relationship_to_child", $this->indent."If Other, please describe:");
        $this->XINRegisterRule(
            "other_relationship_to_child",
            array("relationship_to_child{@}=={@}other"),
            "Required",
            "other_relationship_to_child"
        );

        // SCORING TABLE

        $this->form->addElement('header', null, "Score Summary");

        $group[] = $this->form->createElement('static', "raw_score", null, null);
        $group[] = $this->form->createElement('static', "percentile", null, null);

        $this->form->addGroup($group, 'score_header_group', "<strong>Scale</strong>", $this->_GUIDelimiter, false);
        unset($group);

        $scales = array(
                   "words_produced_number"  => "Words Produced Number",
                   "early_gestures_number"  => "Early Gestures Number",
                   "later_gestures_number"  => "Later Gestures Number",
                   "total_gestures_number"  => "Total Gestures Number",
                   "word_endings"           => "Word Endings", // Percentile omitted
                   "word_forms"             => "Word Forms",
                   "word_endings_pt_2"      => "Word Endings Part 2", // Percentile omitted
                   "grammatical_complexity" => "Grammatical Complexity",
                  );

        $columnHeaders = array(
                          "raw_score"  => "Raw Score",
                          "percentile" => "Percentile",
                         );

        foreach ($columnHeaders as $field => $label) {
            $columnHeaders[$field] .= "     ";
        }

        $this->localDefaults = array_merge($this->localDefaults, $columnHeaders);

        foreach ($scales as $field => $label) {
            foreach ($columnHeaders as $scoreField => $scoreLabel) {
                if ($scoreField == "raw_score") {
                    $group[] = $this->form->createElement('static', "{$field}", null, null);
                } elseif ($scoreField == "percentile") {
                    $group[] = $this->form->createElement('static', "{$field}_{$scoreField}", null, null);
                }
            }
            $this->form->addGroup($group, "{$field}_score_group", $label, $this->_GUIDelimiter, false);
            unset($group);
        }
    }

    function _page1()
    {
        $this->form->addElement('header', null, "Part I: Words Children Use");

        $this->form->addElement('header', null, 'A. Vocabulary Checklist');

        $this->form->addElement(
            'static',
            null,
            'Children understand many more words than they say. We are particularly interested in the words your child SAYS.
            Please go through the list and mark the words you have heard your child use. If your child uses a different pronunciation of a word (for example, "raffe" instead of "giraffe" or "sketti" for spaghetti"), mark the word anyway.
            Remember that this is a "catalogue" of all the words that are used by many different children. Don\'t worry if your child knows only a few of these right now.'
        );

        $this->form->addElement('header', null, "1. Sounds Effects and Animal Sounds (12)");

        $this->makeWordPickItem(self::WordQuestion_I_A_1, 'I_A_1_');

        $this->form->addElement('header', null, '2. Animals (Real or Toy) (43)');
        $this->makeWordPickItem(self::WordQuestion_I_A_2, 'I_A_2_');

        $this->form->addElement('header', null, '3. Vehicles (Real or Toy) (14)');
        $this->makeWordPickItem(self::WordQuestion_I_A_3, 'I_A_3_');
    }

    function _page2()
    {
        $this->form->addElement('header', null, '4. Toys (18)');
        $this->makeWordPickItem(self::WordQuestion_I_A_4, 'I_A_4_');

        $this->form->addElement('header', null, '5. Food and Drink (68)');
        $this->makeWordPickItem(self::WordQuestion_I_A_5, 'I_A_5_');
    }

    function _page3()
    {
        $this->form->addElement('header', null, '6. Clothing (28)');
        $this->makeWordPickItem(self::WordQuestion_I_A_6, 'I_A_6_');

        $this->form->addElement('header', null, '7. Body Parts (27)');
        $this->makeWordPickItem(self::WordQuestion_I_A_7, 'I_A_7_');

        $this->form->addElement('header', null, '8. Small Household Items (50)');
        $this->makeWordPickItem(self::WordQuestion_I_A_8, 'I_A_8_');
    }

    function _page4()
    {
        $this->form->addElement('header', null, '9. Furniture and Rooms (33)');
        $this->makeWordPickItem(self::WordQuestion_I_A_9, 'I_A_9_');

        $this->form->addElement('header', null, '10. Outside Things (31)');
        $this->makeWordPickItem(self::WordQuestion_I_A_10, 'I_A_10_');

        $this->form->addElement('header', null, '11. Places To Go (22)');
        $this->makeWordPickItem(self::WordQuestion_I_A_11, 'I_A_11_');
    }

    function _page5()
    {
        $this->form->addElement('header', null, '12. People (29)');
        $this->makeWordPickItem(self::WordQuestion_I_A_12, 'I_A_12_');

        $this->form->addElement('header', null, '13. Games and Routines (25)');
        $this->makeWordPickItem(self::WordQuestion_I_A_13, 'I_A_13_');

        $this->form->addElement('header', null, '14. Action Words (103)');
        $this->makeWordPickItem(self::WordQuestion_I_A_14, 'I_A_14_');
    }

    function _page6()
    {
        $this->form->addElement('header', null, '15. Descriptive Words (63)');
        $this->makeWordPickItem(self::WordQuestion_I_A_15, 'I_A_15_');

        $this->form->addElement('header', null, '16. Words About Time (12)');
        $this->makeWordPickItem(self::WordQuestion_I_A_16, 'I_A_16_');

        $this->form->addElement('header', null, '17. Pronouns (25)');
        $this->makeWordPickItem(self::WordQuestion_I_A_17, 'I_A_17_');

        $this->form->addElement('header', null, '18. Question Words (6)');
        $this->makeWordPickItem(self::WordQuestion_I_A_18, 'I_A_18_');
    }

    function _page7()
    {
        $this->form->addElement('header', null, '19. Prepositions and Locations (26)');
        $this->makeWordPickItem(self::WordQuestion_I_A_19, 'I_A_19_');

        $this->form->addElement('header', null, '20. Quantifiers and Articles (17)');
        $this->makeWordPickItem(self::WordQuestion_I_A_20, 'I_A_20_');

        $this->form->addElement('header', null, '21) Helping Verbs (21)');
        $this->makeWordPickItem(self::WordQuestion_I_A_21, 'I_A_21_');

        $this->form->addElement('header', null, '22. Connecting Words (6)');
        $this->makeWordPickItem(self::WordQuestion_I_A_22, 'I_A_22_');

        $this->form->addElement('header', null, 'B. How Children Use Words');

        $qNum = 1;
        foreach (self::Question_I_B as $label) {
            $this->form->addElement('select', 'I_B_' . $qNum, $label, self::FrequencyOption);
            $qNum++;
        }
    }

    function _page8()
    {
        $this->form->addElement('header', null, 'Part II: Actions and Gestures');

        $this->form->addElement('header', null, 'A. First Communicative Gestures');
        $this->addLabel('When infants are first learning to communicate, they often use gestures to make their wishes known. For each item below, mark the line that describes your child\'s actions right now.');

        $qNum = 1;
        foreach (self::Question_II_A as $label) {
            $this->form->addElement('select', 'II_A_' . $qNum, $label, self::FrequencyOption);
            $qNum++;
        }

        $this->form->addElement('header', null, 'B. Games and Routines');
        $this->addLabel('Does your child do any of the following?');

        $qNum = 1;
        foreach (self::Question_II_B as $label) {
            $this->form->addElement('select', 'II_B_' . $qNum, $label, self::YesNoOption);
            $qNum++;
        }

        $this->form->addElement('header', null, 'C. Actions with Objects');
        $this->addLabel('Does your child do or <u>try to do</u> any of the following?');

        $qNum = 1;
        foreach (self::Question_II_C as $label) {
            $this->form->addElement('select', 'II_C_' . $qNum, $label, self::YesNoOption);
            $qNum++;
        }

        $this->form->addElement('header', null, 'D. Pretending to be a Parent');
        $this->addLabel('Here are some things that young children sometimes do with stuffed animals or dolls. Please mark the actions that you have seen your child do.');

        $qNum = 1;
        foreach (self::Question_II_D as $label) {
            $this->form->addElement('select', 'II_D_' . $qNum, $label, self::YesNoOption);
            $qNum++;
        }

        $this->form->addElement('header', null, 'E. Imitating Other Adult Actions (using real or toy implements)');
        $this->addLabel('Does your child do or <u>try to do</u> any of the following?');

        $qNum = 1;
        foreach (self::Question_II_E as $label) {
            $this->form->addElement('select', 'II_E_' . $qNum, $label, self::YesNoOption);
            $qNum++;
        }
    }

    function _page9()
    {
        $this->form->addElement('header', null, 'Part III: Sentences and Grammar');

        $this->form->addElement('header', null, 'A. Word Endings/ Part 1');

        $qNum = 1;
        foreach (self::Question_III_A as $label) {
            $this->form->addElement('select', 'III_A_' . $qNum, $label, self::FrequencyOption);
            $qNum++;
        }

        $this->form->addElement('header', null, 'B. Word forms');
        $this->addLabel('Following are some other words children learn. Please mark any of these words that your child uses.');

        $this->addLabel('Nouns:');
        $this->makeWordPickItem(self::WordQuestion_III_B_N, 'III_B_N_');

        $this->addLabel('Verbs:');
        $this->makeWordPickItem(self::WordQuestion_III_B_V, 'III_B_V_');

        $this->form->addElement('header', null, 'C. Word Endings/ Part 2');

        $this->addLabel('Young children often place the wrong endings on words. For example, a child might say "Auntie goed home." Mistakes like this are often a sign of progress in language. In the following lists, please mark all the mistakes of this kind you have heard your child say recently. ');

        $this->addLabel('Nouns:');
        $this->makeWordPickItem(self::WordQuestion_III_C_N, 'III_C_N_');

        $this->addLabel('Verbs:');
        $this->makeWordPickItem(self::WordQuestion_III_C_V, 'III_C_V_');

        $this->form->addElement('select', 'III_C_additional', 'Has your child begun to combine words yet, such as "Nother Cracker", or "Doggie Bite?"', self::FrequencyOption);

        $this->form->addElement('header', null, 'D. Examples:');

        $this->addTextAreaElement('III_D', 'Please list three of the longest sentences you have heard your child say recently.');

        $this->form->addElement('header', null, 'E. Complexity');

        $this->addLabel('In each of the following pairs, please mark the one that sounds most like the way your child talks right now. If your child is saying sentences even longer or more complicated than the two provided, just pick the second one.');

        $qNum = 1;
        foreach (self::Question_III_E as list($label1, $label2)) {
            $this->form->addElement('select', 'III_E_' . $qNum, $label1 . ' / ' . $label2, [null => '', '1' => $label1, '2' => $label2, 'NK' => 'Not Known']);
            $qNum++;
        }

        $this->form->addFormRule(array(&$this, 'page9_validate'));
    }

    function page9_validate($values)
    {
        $errors = array();
        if (!empty($values['III_D']) && ($values['III_D_status'] == 'not_answered')) {
            $errors['III_D'] = 'You have chosen "Not Answered", you should not enter a text as response.';
        }
        return $errors;
    }

    private function makeWordPickItem($QuestionArray, $prefix)
    {
        $qNum = 1;
        foreach ($QuestionArray as $label) {
            $column = $prefix . $qNum;
            $this->form->addElement('advcheckbox', $column, $label, $label, null, self::NoYesCheckbox);
            $this->XINRegisterRule($column, array($column . '{@}=={@}NEVER_REQUIRED'));
            $qNum++;
        }
    }

    function Sum($question_count, &$record, $question_prefix, &$count)
    {
        for ($qNum = 1; $qNum <= $question_count; $qNum++) {
            if ($record[$question_prefix . $qNum] == "Y") {
                $count++;
            }
        }
    }

    function CalculateMacarthurPercentile($scale, $age_months, $gender, &$scores)
    {
        $db = Database::singleton();

	$scale_number     = $scale;

        $scale_percentile = $scale . "_percentile";

	$query_scores    = "
		SELECT * 
		FROM macarthur_lookup 
		WHERE age_months=:ageMonths 
		AND sex=:gender  
		AND score_raw=:scoreRaw 
		AND subscale=:subScale";
	$PercentileScore = $db->pselectRow(
		$query_scores,
	       	[
       		  'ageMonths'    => $age_months,
       		  'gender'       => $gender,
       		  'scoreRaw'     => $scores[$scale_number],
       		  'subScale'     => $scale_number
   		]
	 );

        $scores[$scale_percentile] = $PercentileScore['score_percentile'];

        if ($PercentileScore == null) {
            $score_holder   = $scores[$scale_number];
            $query_scores1a = "
                SELECT
                    *
                FROM
                    macarthur_lookup
                WHERE
                    age_months = $age_months AND
                    sex = '$gender' AND
                    subscale = '$scale_number' AND
                    score_raw > $score_holder
                ORDER BY
                    score_raw
                ASC
                    limit 1"
            ;

            $record_1a = $db->pselect($query_scores1a, array());
            if (empty($record_1a)) {
                $db->pselect(
                    "
                    SELECT
                        *
                    FROM
                        macarthur_lookup
                    WHERE
                        age_months = $age_months AND
                        sex = '$gender' AND
                        subscale = '$scale_number'
                    ORDER BY
                        score_raw
                    ASC
                        limit 1",
                    array()
                );
            }

            $query_scores1b = "
                SELECT
                    *
                FROM
                    macarthur_lookup
                WHERE
                    age_months = " . $age_months . " AND
                    sex = '$gender' AND
                    subscale = '$scale_number' AND
                    score_raw < $score_holder
                ORDER BY
                    score_raw
                DESC
                    limit 1";

            $record_1b = $db->pselect($query_scores1b, array());

            $percentile_calculation1 = (
                    ($scores[$scale_number]-$record_1b[0]['score_raw'])/
                    ($record_1a[0]['score_raw']-$record_1b[0]['score_raw'])
                    )*($record_1a[0]['score_percentile']-$record_1b[0]['score_percentile'])+$record_1b[0]['score_percentile'];

            $scores[$scale_percentile] =abs(round($percentile_calculation1));
        }

        if ($scores[$scale_percentile] > 99) {
            $scores[$scale_percentile] = 99;
        }
    }

    function CalculateCDIPercentile($scale, $age_months, $gender, &$scores)
    {
        $db = Database::singleton();

        $scale_percentile = $scale . "_percentile";

        // word_forms scores are not affected by the Sex of the candidate
        if ($scale != "word_forms") {
		$query_scores    = "
			SELECT * 
			FROM CDI_WS_percentiles_lookup 
			WHERE age_months=:ageMonths 
			AND sex=:gender
			AND score_raw=:scoreRaw 
			AND subscale=:subScale";
		$PercentileScore = $db->pselectRow(
			$query_scores,
		       [
       			  'ageMonths'    => $age_months,
       			  'gender'       => $gender,
       			  'scoreRaw'     => $scores[$scale_number],
       			  'subScale'     => $scale_number
    		       ]	
		);

            $scores[$scale_percentile] = $PercentileScore['score_percentile'];

            if ($PercentileScore == null) {
                $score_holder   = $scores[$scale];
                $query_scores1a = "
                    SELECT
                        *
                    FROM
                        macarthur_lookup
                    WHERE
                        age_months = $age_months AND
                        subscale = '$scale' AND
                        score_raw > $score_holder
                    ORDER BY
                        score_raw
                    ASC
                        limit 1"
                ;

                $record_1a = $db->pselect($query_scores1a, array());
                if (empty($record_1a)) {
                    $db->pselect(
                        "
                        SELECT
                            *
                        FROM
                            macarthur_lookup
                        WHERE
                            age_months = $age_months AND
                            subscale = '$scale'
                        ORDER BY
                            score_raw
                        ASC
                            limit 1",
                        array()
                    );
                }

                $query_scores1b = "
                    SELECT
                        *
                    FROM
                        macarthur_lookup
                    WHERE
                        age_months = " . $age_months . " AND
                        subscale = '$scale' AND
                        score_raw < $score_holder
                    ORDER BY
                        score_raw
                    DESC
                        limit 1";

                $record_1b = $db->pselect($query_scores1b, array());

                $percentile_calculation1 = (
                        ($scores[$scale]-$record_1b[0]['score_raw'])/
                        ($record_1a[0]['score_raw']-$record_1b[0]['score_raw'])
                        )*($record_1a[0]['score_percentile']-$record_1b[0]['score_percentile'])+$record_1b[0]['score_percentile'];

                $scores[$scale_percentile] = abs(round($percentile_calculation1));
            }
        } else {
		$query_scores    = "
			SELECT * 
			FROM CDI_WS_percentiles_lookup 
			WHERE age_months=:ageMonths 
			AND sex=:gender 
			AND score_raw=:scoreRaw 
			AND subscale=:subScale";

		$PercentileScore = $db->pselectRow(
			$query_scores, 
			[
       			   'ageMonths'    => $age_months,
       			   'gender'       => $gender,
       			   'scoreRaw'     => $scores[$scale_number],
       			   'subScale'     => $scale_number
   			]	
		);

            $scores[$scale_percentile] = $PercentileScore['score_percentile'];

            if ($PercentileScore == null) {
                $score_holder   = $scores[$scale];
                $query_scores1a = "
                    SELECT
                        *
                    FROM
                        macarthur_lookup
                    WHERE
                        age_months = $age_months AND
                        subscale = '$scale' AND
                        score_raw > $score_holder
                    ORDER BY
                        score_raw
                    ASC
                        limit 1"
                ;

                $record_1a = $db->pselect($query_scores1a, array());
                if (empty($record_1a)) {
                    $db->pselect(
                        "
                        SELECT
                            *
                        FROM
                            macarthur_lookup
                        WHERE
                            age_months = $age_months AND
                            subscale = '$scale'
                        ORDER BY
                            score_raw
                        ASC
                            limit 1",
                        array()
                    );
                }

                $query_scores1b = "
                    SELECT
                        *
                    FROM
                        macarthur_lookup
                    WHERE
                        age_months = " . $age_months . " AND
                        subscale = '$scale' AND
                        score_raw < $score_holder
                    ORDER BY
                        score_raw
                    DESC
                        limit 1";

                $record_1b = $db->pselect($query_scores1b, array());

                $percentile_calculation1 = (
                        ($scores[$scale]-$record_1b[0]['score_raw'])/
                        ($record_1a[0]['score_raw']-$record_1b[0]['score_raw'])
                        )*($record_1a[0]['score_percentile']-$record_1b[0]['score_percentile'])+$record_1b[0]['score_percentile'];

                $scores[$scale_percentile] = abs(round($percentile_calculation1));

            }

            if ($scores[$scale_percentile] > 99) {
                $scores[$scale_percentile] = 99;
            }

        }
    }

    function score(): void
    {
        if ($this->_determineDataEntryCompletionStatus() == "Incomplete") {
            return;
        }

        // Null scores
        $this->_nullScores($this->scoreLabels);

        // Get saved data
        $db     = Database::singleton();
        $record = $db->pselectRow("SELECT * FROM $this->table WHERE CommentID=:cid", array("cid" => $this->getCommentID()));

        // Get the subject's Sex
        $query_gender  = "
        SELECT
            Sex
        FROM
            candidate as c,
            session as s,
            flag as f,
            $this->table as t
        WHERE
            t.CommentID = '$this->commentID' AND
            f.CommentID=t.CommentID AND
            s.ID=f.SessionID AND
            s.CandID=c.CandID
        ";
        $record_gender = $db->pselectRow($query_gender, array());
        $gender        = strtolower($record_gender['Sex']);

        // Get the subject's Age in months
        $timepoint  = TimePoint::singleton($this->getSessionID());
        $dob        = $timepoint->getEffectiveDateOfBirth();
        $age        = Utility::calculateAge($dob, $record["Date_taken"]);
        $age_months = $age['year'] * 12 + $age['mon'];

        // Initialize scores
        $scores = array(
                   "words_produced_number"             => 0, // Part I: A, B
                   "early_gestures_number"             => 0, // Part II: A, B
                   "later_gestures_number"             => 0, // Part II: C, D, E
                   "total_gestures_number"             => 0, // Part II: A, B, C, D, E
                   "word_endings"                      => 0, // Part III: A
                   "word_forms"                        => 0, // Part III: B
                   "word_endings_pt_2"                 => 0, // Part III: C
                   "grammatical_complexity"            => 0, // Part III: E
                   "words_produced_number_percentile"  => 0,
                   "early_gestures_number_percentile"  => 0,
                   "later_gestures_number_percentile"  => 0,
                   "total_gestures_number_percentile"  => 0,
                   "word_forms_percentile"             => 0,
                   "grammatical_complexity_percentile" => 0,
                  );

        /******************************
         * Part I: Words Children Use *
         ******************************/

        // Section A: Vocabulary Checklist

        $I_A_question_count = array(
                               1  => count(self::WordQuestion_I_A_1),
                               2  => count(self::WordQuestion_I_A_2),
                               3  => count(self::WordQuestion_I_A_3),
                               4  => count(self::WordQuestion_I_A_4),
                               5  => count(self::WordQuestion_I_A_5),
                               6  => count(self::WordQuestion_I_A_6),
                               7  => count(self::WordQuestion_I_A_7),
                               8  => count(self::WordQuestion_I_A_8),
                               9  => count(self::WordQuestion_I_A_9),
                               10 => count(self::WordQuestion_I_A_10),
                               11 => count(self::WordQuestion_I_A_11),
                               12 => count(self::WordQuestion_I_A_12),
                               13 => count(self::WordQuestion_I_A_13),
                               14 => count(self::WordQuestion_I_A_14),
                               15 => count(self::WordQuestion_I_A_15),
                               16 => count(self::WordQuestion_I_A_16),
                               17 => count(self::WordQuestion_I_A_17),
                               18 => count(self::WordQuestion_I_A_18),
                               19 => count(self::WordQuestion_I_A_19),
                               20 => count(self::WordQuestion_I_A_20),
                               21 => count(self::WordQuestion_I_A_21),
                               22 => count(self::WordQuestion_I_A_22),
                              );

        $says       = array();
        $says_total = 0;

        for ($i = 1; $i <= 22; $i++) {
            $says[$i] = 0;
            $this->Sum($I_A_question_count[$i], $record, "I_A_" . $i . "_", $says[$i]);
            $says_total += $says[$i];
        }

        // Total # of words produced
        $scores["words_produced_number"] = $says_total;

        // Section B: How Children Use Words
        $I_B_question_count = count(self::Question_I_B); // == 5

        $how_children_use_words_ST_or_OF = 0;

        // Count # of questions answered Sometimes or Often
        for ($qNum = 1; $qNum <= $I_B_question_count; $qNum++) {
            if ($record["I_B_" . $qNum] == "ST" || $record["I_B_" . $qNum] == "OF") {
                $how_children_use_words_ST_or_OF++;
            }
        }

        $scores["words_produced_number"] += $how_children_use_words_ST_or_OF;

        /********************************
         * Part II: Action and Gestures *
         ********************************/

	// p
        // Section A: First Communicative Gestures

        $II_A_question_count = count(self::Question_II_A); // == 13

        $first_gestures_ST_or_OF = 0;

        // Count # of questions answered Sometimes or Often
        for ($qNum = 1; $qNum <= $II_A_question_count; $qNum++) {
            if ($record["II_A_" . $qNum] == "ST" || $record["II_A_" . $qNum] == "OF") {
                $first_gestures_ST_or_OF++;
            }
        }

        // Part B: Games and Routines
        // Part C: Actions with Objects
        // Part D: Pretending to be a Parent
        // Part E: Imitating Other Adult Actions

        $YesActions = array(
                       'B' => 0,
                       'C' => 0,
                       'D' => 0,
                       'E' => 0,
                      );

        $II_B_question_count = count(self::Question_II_B); // == 6
        $II_C_question_count = count(self::Question_II_C); // == 17
        $II_D_question_count = count(self::Question_II_D); // == 13
        $II_E_question_count = count(self::Question_II_E); // == 16

        $this->Sum($II_B_question_count, $record, "II_B_", $YesActions['B']);
        $this->Sum($II_C_question_count, $record, "II_C_", $YesActions['C']);
        $this->Sum($II_D_question_count, $record, "II_D_", $YesActions['D']);
        $this->Sum($II_E_question_count, $record, "II_E_", $YesActions['E']);

        $scores["early_gestures_number"] = $first_gestures_ST_or_OF + $YesActions['B'];
        $scores["later_gestures_number"] = $YesActions['C'] + $YesActions['D'] + $YesActions['E'];
        $scores["total_gestures_number"] = $scores["early_gestures_number"] + $scores["later_gestures_number"];

        /***********************************
         * Part III: Sentences and Grammar *
         ***********************************/

        // Section A: Word Endings
        $III_A_question_count = count(self::Question_III_A); // == 5

        $word_endings = 0;

        for ($qNum = 1; $qNum <= $III_A_question_count; $qNum++) {
            if ($record["III_A_" . $qNum] == "ST" || $record["III_A_" . $qNum] == "OF") {
                $word_endings++;
            }
        }

        // $this->Sum($III_A_question_count, $record, "III_A_", $word_endings);

        $scores["word_endings"] = $word_endings;

        // Section B: Word Forms
        $III_B_nouns_count = count(self::WordQuestion_III_B_N); // == 5
        $III_B_verbs_count = count(self::WordQuestion_III_B_V); // == 20

        $word_forms_nouns = 0;
        $word_forms_verbs = 0;

        $this->Sum($III_B_nouns_count, $record, "III_B_N_", $word_forms_nouns);
        $this->Sum($III_B_verbs_count, $record, "III_B_V_", $word_forms_verbs);

        $scores["word_forms"] = $word_forms_nouns + $word_forms_verbs;

        // Section C: Word Endings Part 2
        $III_C_nouns_count = count(self::WordQuestion_III_C_N); // == 14
        $III_C_verbs_count = count(self::WordQuestion_III_C_V); // == 31

        $word_endings_pt_2_nouns = 0;
        $word_endings_pt_2_verbs = 0;

        $this->Sum($III_C_nouns_count, $record, "III_C_N_", $word_endings_pt_2_nouns);
        $this->Sum($III_C_verbs_count, $record, "III_C_V_", $word_endings_pt_2_verbs);

        $scores["word_endings_pt_2"] = $word_endings_pt_2_nouns + $word_endings_pt_2_verbs;

        // Section D: Examples
        // No Scoring

        // Section E: Complexity
        $III_E_question_count = count(self::Question_III_E);
        $III_E_complex_question_count = 0;

        for ($i = 1; $i < $III_E_question_count; $i++) {
            if ($record["III_E_" . $i] == '2') {
                $III_E_complex_question_count += 1;
            }
        }

        $scores["grammatical_complexity"] = $III_E_complex_question_count;

        // Establish standard scores and percentile rank for subscales
        // This only has data for the ages 8-18 months. After that,
        // percentile ranks only exist for Macarthur Words and Sentences scale,
        // but we still use words and gestures in V24
        // to compare the subject against him/herself.

        // 8-18 months
        $macarthur_lookup_scales = array(
                                    "words_produced_number",
                                    "early_gestures_number",
                                    "later_gestures_number",
                                    "total_gestures_number",
                                   );

        // 16-30 months
        $CDI_WS_percentiles_lookup_scales = array(
                                          //  "words_produced_number",
                                             "word_forms",
                                             "grammatical_complexity",
                                            );

        // Age range for instrument scoring is 8-24 months

        foreach ($macarthur_lookup_scales as $scale) {
            $scale_percentile = $scale . "_percentile";

            if ($age_months >= 8 && $age_months <= 24) {
                // The macarthur_lookup table currently only has data for 8-18 months
                if ($age_months <= 18) {
                    $this->CalculateMacarthurPercentile($scale, $age_months, $gender, $scores);
                } else {
                    $scores[$scale_percentile] = "Data Not Found in macarthur_lookup Table";
                }
            } elseif ($age_months < 8) {
                $scores[$scale_percentile] = "Candidate too young to score";
            } elseif ($age_months > 24) {
                $scores[$scale_percentile] = "Candidate too old to score";
            }
        }

        foreach ($CDI_WS_percentiles_lookup_scales as $scale) {
            $scale_percentile = $scale . "_percentile";

            if ($age_months >= 8 && $age_months <= 24) {
                // The CDI_WS_percentiles_lookup table currently only has data for 16-30 months
                if ($age_months >= 16) {
                    $this->CalculateCDIPercentile($scale, $age_months, $gender, $scores);
                } else {
                    $scores[$scale_percentile] = "Data Not Found in CDI_WS_percentiles_lookup Table";
                }
            } elseif ($age_months < 8) {
                $scores[$scale_percentile] = "Candidate too young to score";
            } elseif ($age_months > 24) {
                $scores[$scale_percentile] = "Candidate too old to score";
            }
        }

        // End percentiles calculation

        // Save scores
        $result = $db->update($this->table, $scores, array("CommentID" => $this->getCommentID()));
    }

    // Answers to often asked questions
    private const YesNoOption     = array(
                                     null => '',
                                     'Y'  => 'Yes',
                                     'N'  => 'No',
                                     'NK' => 'Not Known',
                                    );
    private const FrequencyOption = array(
                                     null => '',
                                     'NY' => 'Not Yet',
                                     'ST' => 'Sometimes',
                                     'OF' => 'Often',
                                     'NK' => 'Not Known',
                                    );
    private const NoYesCheckbox   = [
                                     'N',
                                     'Y',
                                    ];

    // Data section
    private const WordQuestion_I_A_1 = [
                                        'baa baa',
                                        'choo choo',
                                        'cockadoodledoo',
                                        'grrr',
                                        'meow',
                                        'moo',
                                        'ouch',
                                        'quack quack',
                                        'uh oh',
                                        'vroom',
                                        'woof woof',
                                        'yum yum',
                                       ];

    private const WordQuestion_I_A_2 = [
                                        'alligator',
                                        'animal',
                                        'ant',
                                        'bear',
                                        'bee',
                                        'bird',
                                        'bug',
                                        'bunny',
                                        'butterfly',
                                        'cat',
                                        'chicken',
                                        'cow',
                                        'deer',
                                        'dog',
                                        'donkey',
                                        'duck',
                                        'elephant',
                                        'fish',
                                        'frog',
                                        'giraffe',
                                        'goose',
                                        'hen',
                                        'horse',
                                        'kitty',
                                        'lamb',
                                        'lion',
                                        'monkey',
                                        'moose',
                                        'mouse',
                                        'owl',
                                        'penguin',
                                        'pig',
                                        'pony',
                                        'puppy',
                                        'rooster',
                                        'sheep',
                                        'squirrel',
                                        'teddy bear',
                                        'tiger',
                                        'turkey',
                                        'turtle',
                                        'wolf',
                                        'zebra',
                                       ];

    private const WordQuestion_I_A_3 = [
                                        'airplane',
                                        'bicycle',
                                        'boat',
                                        'bus',
                                        'car',
                                        'firetruck',
                                        'helicopter',
                                        'motorcycle',
                                        'sled',
                                        'stroller',
                                        'tractor',
                                        'train',
                                        'tricycle',
                                        'truck',
                                       ];

    private const WordQuestion_I_A_4 = [
                                        'ball',
                                        'balloon',
                                        'bat',
                                        'block',
                                        'book',
                                        'bubbles',
                                        'chalk',
                                        'crayon',
                                        'doll',
                                        'game',
                                        'glue',
                                        'pen',
                                        'pencil',
                                        'play dough',
                                        'present',
                                        'puzzle',
                                        'story',
                                        'toy',
                                       ];

    private const WordQuestion_I_A_5 = [
                                        'apple',
                                        'applesauce',
                                        'banana',
                                        'beans',
                                        'bread',
                                        'butter',
                                        'cake',
                                        'candy',
                                        'carrots',
                                        'cereal',
                                        'cheerios',
                                        'cheese',
                                        'chicken',
                                        'chocolate',
                                        'coffee',
                                        'coke',
                                        'cookie',
                                        'corn',
                                        'cracker',
                                        'donut',
                                        'drink',
                                        'egg',
                                        'fish',
                                        'food',
                                        'french fries',
                                        'grapes',
                                        'green beans',
                                        'gum',
                                        'hamburger',
                                        'ice',
                                        'ice cream',
                                        'jello',
                                        'jelly',
                                        'juice',
                                        'lollipop',
                                        'meat',
                                        'melon',
                                        'milk',
                                        'muffin',
                                        'noodles',
                                        'nuts',
                                        'orange',
                                        'pancake',
                                        'peanut butter',
                                        'peas',
                                        'pickle',
                                        'pizza',
                                        'popcorn',
                                        'popsicle',
                                        'potato',
                                        'potato chip',
                                        'pretzel',
                                        'pudding',
                                        'pumpkin',
                                        'raisin',
                                        'salt',
                                        'sandwich',
                                        'sauce',
                                        'soda/pop',
                                        'soup',
                                        'spaghetti',
                                        'strawberry',
                                        'toast',
                                        'tuna',
                                        'vanilla',
                                        'vitamins',
                                        'water',
                                        'yogurt',
                                       ];

    private const WordQuestion_I_A_6 = [
                                        'beads',
                                        'belt',
                                        'bib',
                                        'boots',
                                        'button',
                                        'coat',
                                        'diaper',
                                        'dress',
                                        'gloves',
                                        'hat',
                                        'jacket',
                                        'jeans',
                                        'mittens',
                                        'necklace',
                                        'pajamas',
                                        'pants',
                                        'scarf',
                                        'shirt',
                                        'shoe',
                                        'shorts',
                                        'slipper',
                                        'sneaker',
                                        'snowsuit',
                                        'sock',
                                        'sweater',
                                        'tights',
                                        'underpants',
                                        'zipper',
                                       ];

    private const WordQuestion_I_A_7 = [
                                        'ankle',
                                        'arm',
                                        'belly button',
                                        'buttocks/bottom (or word used in your family)',
                                        'cheek',
                                        'chin',
                                        'ear',
                                        'eye',
                                        'face',
                                        'feet',
                                        'finger',
                                        'hair',
                                        'hand',
                                        'head',
                                        'knee',
                                        'leg',
                                        'lips',
                                        'mouth',
                                        'nose',
                                        'owie/boo boo',
                                        'penis (or word used in your family)',
                                        'shoulder',
                                        'tooth',
                                        'toe',
                                        'tongue',
                                        'tummy',
                                        'vagina (or word used in your family)',
                                       ];

    private const WordQuestion_I_A_8 = [
                                        'basket',
                                        'blanket',
                                        'bottle',
                                        'bowl',
                                        'box',
                                        'broom',
                                        'brush',
                                        'bucket',
                                        'camera',
                                        'can',
                                        'clock',
                                        'comb',
                                        'cup',
                                        'dish',
                                        'fork',
                                        'garbage',
                                        'glass',
                                        'glasses',
                                        'hammer',
                                        'jar',
                                        'keys',
                                        'knife',
                                        'lamp',
                                        'light',
                                        'medicine',
                                        'money',
                                        'mop',
                                        'nail',
                                        'napkin',
                                        'paper',
                                        'penny',
                                        'picture',
                                        'pillow',
                                        'plant',
                                        'plate',
                                        'purse',
                                        'radio',
                                        'scissors',
                                        'soap',
                                        'spoon',
                                        'tape',
                                        'telephone',
                                        'tissue/kleenex',
                                        'toothbrush',
                                        'towel',
                                        'trash',
                                        'tray',
                                        'vacuum',
                                        'walker',
                                        'watch',
                                       ];

    private const WordQuestion_I_A_9 = [
                                        'basement',
                                        'bathroom',
                                        'bathtub',
                                        'bed',
                                        'bedroom',
                                        'bench',
                                        'chair',
                                        'closet',
                                        'couch',
                                        'crib',
                                        'door',
                                        'drawer',
                                        'dryer',
                                        'garage',
                                        'high chair',
                                        'kitchen',
                                        'living room',
                                        'oven',
                                        'play pen',
                                        'porch',
                                        'potty',
                                        'refrigerator',
                                        'rocking chair',
                                        'room',
                                        'shower',
                                        'sink',
                                        'sofa',
                                        'stairs',
                                        'stove',
                                        'table',
                                        'TV',
                                        'washing machine',
                                        'window',
                                       ];

    private const WordQuestion_I_A_10 = [
                                         'backyard',
                                         'cloud',
                                         'flag',
                                         'flower',
                                         'garden',
                                         'grass',
                                         'hose',
                                         'ladder',
                                         'lawn mower',
                                         'moon',
                                         'pool',
                                         'rain',
                                         'rock',
                                         'roof',
                                         'sandbox',
                                         'shovel',
                                         'sidewalk',
                                         'sky',
                                         'slide',
                                         'snow',
                                         'snowman',
                                         'sprinkler',
                                         'star',
                                         'stick',
                                         'stone',
                                         'street',
                                         'sun',
                                         'swing',
                                         'tree',
                                         'water',
                                         'wind',
                                        ];

    private const WordQuestion_I_A_11 = [
                                         'beach',
                                         'camping',
                                         'church (or word used in your family)',
                                         'circus',
                                         'country',
                                         'downtown',
                                         'farm',
                                         'gas station',
                                         'home',
                                         'house',
                                         'movie',
                                         'outside',
                                         'park',
                                         'party',
                                         'picnic',
                                         'playground',
                                         'school',
                                         'store',
                                         'woods',
                                         'work',
                                         'yard',
                                         'zoo',
                                        ];

    private const WordQuestion_I_A_12 = [
                                         'aunt',
                                         'baby',
                                         'babysitter',
                                         'babysitter\'s name',
                                         'boy',
                                         'brother',
                                         'child',
                                         'clown',
                                         'cowboy',
                                         'daddy (or word used in your family)',
                                         'doctor',
                                         'fireman',
                                         'friend',
                                         'girl',
                                         'grandma (or word used in your family)',
                                         'grandpa (or word used in your family)',
                                         'lady',
                                         'mailman',
                                         'man',
                                         'mommy (or word used in your family)',
                                         'nurse',
                                         'child\'s own name',
                                         'people',
                                         'person',
                                         'pet\'s name',
                                         'police',
                                         'sister',
                                         'teacher',
                                         'uncle',
                                        ];

    private const WordQuestion_I_A_13 = [
                                         'bath',
                                         'breakfast',
                                         'bye',
                                         'call (on phone)',
                                         'dinner',
                                         'give me five!',
                                         'gonna get you!',
                                         'go potty!',
                                         'hello',
                                         'hi',
                                         'lunch',
                                         'nap',
                                         'night night',
                                         'no',
                                         'patty cake',
                                         'peekaboo',
                                         'please',
                                         'shh/shush/hush',
                                         'shopping',
                                         'snack',
                                         'so big!',
                                         'thank you',
                                         'this little piggy',
                                         'turn around',
                                         'yes',
                                        ];

    private const WordQuestion_I_A_14 = [
                                         'bite',
                                         'blow',
                                         'break',
                                         'bring',
                                         'build',
                                         'bump',
                                         'buy',
                                         'carry',
                                         'catch',
                                         'chase',
                                         'clap',
                                         'clean',
                                         'climb',
                                         'close',
                                         'cook',
                                         'cover',
                                         'cry',
                                         'cut',
                                         'dance',
                                         'draw',
                                         'drink',
                                         'drive',
                                         'drop',
                                         'dry',
                                         'dump',
                                         'eat',
                                         'fall',
                                         'feed',
                                         'find',
                                         'finish',
                                         'fit',
                                         'fix',
                                         'get',
                                         'give',
                                         'go',
                                         'hate',
                                         'have',
                                         'hear',
                                         'help',
                                         'hide',
                                         'hit',
                                         'hold',
                                         'hug',
                                         'hurry',
                                         'jump',
                                         'kick',
                                         'kiss',
                                         'knock',
                                         'lick',
                                         'like',
                                         'listen',
                                         'look',
                                         'love',
                                         'make',
                                         'open',
                                         'paint',
                                         'pick',
                                         'play',
                                         'pour',
                                         'pretend',
                                         'pull',
                                         'push',
                                         'put',
                                         'read',
                                         'ride',
                                         'rip',
                                         'run',
                                         'say',
                                         'see',
                                         'shake',
                                         'share',
                                         'show',
                                         'sing',
                                         'sit',
                                         'skate',
                                         'sleep',
                                         'slide',
                                         'smile',
                                         'spill',
                                         'splash',
                                         'stand',
                                         'stay',
                                         'stop',
                                         'sweep',
                                         'swim',
                                         'swing',
                                         'take',
                                         'talk',
                                         'taste',
                                         'tear',
                                         'think',
                                         'throw',
                                         'tickle',
                                         'touch',
                                         'wait',
                                         'wake',
                                         'walk',
                                         'wash',
                                         'watch',
                                         'wipe',
                                         'wish',
                                         'work',
                                         'write',
                                        ];

    private const WordQuestion_I_A_15 = [
                                         'all gone',
                                         'asleep',
                                         'awake',
                                         'bad',
                                         'better',
                                         'big',
                                         'black',
                                         'blue',
                                         'broken',
                                         'brown',
                                         'careful',
                                         'clean',
                                         'cold',
                                         'cute',
                                         'dark',
                                         'dirty',
                                         'dry',
                                         'empty',
                                         'fast',
                                         'fine',
                                         'first',
                                         'full',
                                         'gentle',
                                         'good',
                                         'green',
                                         'happy',
                                         'hard',
                                         'heavy',
                                         'high',
                                         'hot',
                                         'hungry',
                                         'hurt',
                                         'last',
                                         'little',
                                         'long',
                                         'loud',
                                         'mad',
                                         'naughty',
                                         'new',
                                         'nice',
                                         'noisy',
                                         'old',
                                         'orange',
                                         'poor',
                                         'pretty',
                                         'quiet',
                                         'red',
                                         'sad',
                                         'scared',
                                         'sick',
                                         'sleepy',
                                         'slow',
                                         'soft',
                                         'sticky',
                                         'stuck',
                                         'thirsty',
                                         'tiny',
                                         'tired',
                                         'wet',
                                         'white',
                                         'windy',
                                         'yellow',
                                         'yucky',
                                        ];

    private const WordQuestion_I_A_16 = [
                                         'after',
                                         'before',
                                         'day',
                                         'later',
                                         'morning',
                                         'night',
                                         'now',
                                         'time',
                                         'today',
                                         'tomorrow',
                                         'tonight',
                                         'yesterday',
                                        ];

    private const WordQuestion_I_A_17 = [
                                         'he',
                                         'her',
                                         'hers',
                                         'him',
                                         'his',
                                         'I',
                                         'it',
                                         'me',
                                         'mine',
                                         'my',
                                         'myself',
                                         'our',
                                         'she',
                                         'that',
                                         'their',
                                         'them',
                                         'these',
                                         'they',
                                         'this',
                                         'those',
                                         'us',
                                         'we',
                                         'you',
                                         'your',
                                         'yourself',
                                        ];

    private const WordQuestion_I_A_18 = [
                                         'how',
                                         'what',
                                         'when',
                                         'where',
                                         'who',
                                         'why',
                                        ];

    private const WordQuestion_I_A_19 = [
                                         'about',
                                         'above',
                                         'around',
                                         'at',
                                         'away',
                                         'back',
                                         'behind',
                                         'beside',
                                         'by',
                                         'down',
                                         'for',
                                         'here',
                                         'inside/in',
                                         'into',
                                         'next to',
                                         'of',
                                         'off',
                                         'on',
                                         'on top of',
                                         'out',
                                         'over',
                                         'there',
                                         'to',
                                         'under',
                                         'up',
                                         'with',
                                        ];

    private const WordQuestion_I_A_20 = [
                                         'a',
                                         'all',
                                         'a lot',
                                         'an',
                                         'another',
                                         'any',
                                         'each',
                                         'every',
                                         'more',
                                         'much',
                                         'not',
                                         'none',
                                         'other',
                                         'same',
                                         'some',
                                         'the',
                                         'too',
                                        ];

    private const WordQuestion_I_A_21 = [
                                         'am',
                                         'are',
                                         'be',
                                         'can',
                                         'could',
                                         'did/did ya',
                                         'do',
                                         'does',
                                         'don\'t',
                                         'gonna/going to',
                                         'gotta/got to',
                                         'hafta/have to',
                                         'is',
                                         'lemme/let me',
                                         'need/need to',
                                         'try/try to',
                                         'wanna/want to',
                                         'was',
                                         'were',
                                         'will',
                                         'would',
                                        ];

    private const WordQuestion_I_A_22 = [
                                         'and',
                                         'because',
                                         'but',
                                         'if',
                                         'so',
                                         'then',
                                        ];

    private const Question_I_B = [
                                  '1) Does your child ever talk about past events or people who are not present? For example, a child who saw a parade last week might later say parade, clown, or band.',
                                  '2) Does your child ever talk about something that\'s going to happen in the future, for example, saying "choo choo" or "airplane" before you leave the house for a trip, or saying "swing" when you are going to the park? ',
                                  '3) Does your child talk about objects that are not present such as asking about a missing or absent toy, referring to a pet out of view, or asking about someone not present? ',
                                  '4) Does your child understand if you ask for something that is not in the room, for example, by going to the bedroom to get a teddy bear when you say "where\'s the bear?"',
                                  '5) Does your child ever pick up or point to an object and name an absent person to whom the object belongs? For example, a child might point to mommy\'s shoe and say "mommy". ',
                                 ];

    private const Question_II_A = [
                                   'Extends arm to show you something s/he is holding.',
                                   'Reaches out and gives you a toy or some object that s/he is holding.',
                                   'Points (with arm and index finger extended) at some interesting object or event.',
                                   'For quality checking purposes, please choose the Sometimes option.',
                                   'Waves bye-bye on his/her own when someone leaves.',
                                   'Extends his/her arm upward to signal a wish to be picked up.',
                                   'Shakes head "no".',
                                   'Nods head "yes".',
                                   'Gestures "hush" by placing finger to lips.',
                                   'Requests something by extending arm and opening and closing hand.',
                                   'Blows kisses from a distance.',
                                   'Smacks lips in a "yum yum" gesture to indicate that something tastes good.',
                                   'Shrugs to indicate "all gone" or "where\'d it go".',
                                  ];

    private const Question_II_B = [
                                   'Play peekaboo.',
                                   'Play patty cake.',
                                   'Play "so big".',
                                   'Play chasing games.',
                                   'Sing.',
                                   'Dance.',
                                  ];

    private const Question_II_C = [
                                   'Eat with a spoon or fork.',
                                   'Drink from a cup containing liquid.',
                                   'Comb or brush own hair.',
                                   'Brush teeth.',
                                   'Wipe face or hands with a towel or cloth.',
                                   'Put on hat.',
                                   'Put on a shoe or sock.',
                                   'Put on a necklace, bracelet, or watch.',
                                   'Lay head on hands and squeeze eyes shut as if sleeping.',
                                   'Blow to indicate something is hot.',
                                   'Hold plane and make it "fly".',
                                   'Put telephone to ear.',
                                   'Sniff flowers.',
                                   'Push toy car or truck.',
                                   'Throw a ball.',
                                   'Pour pretend liquid from one container to another.',
                                   'Stir pretend liquid in a cup or pan with a spoon.',
                                  ];

    private const Question_II_D = [
                                   'Put to bed.',
                                   'Cover with blanket.',
                                   'Feed with bottle.',
                                   'Feed with spoon.',
                                   'Brush/comb its hair.',
                                   'Pat or burp it.',
                                   'Push in stroller/buggy.',
                                   'Rock it.',
                                   'Kiss or hug it.',
                                   'Try to put shoe or sock or hat on it.',
                                   'Wipe its face or hands.',
                                   'Talk to it.',
                                   'Try to put diaper on it.',
                                  ];

    private const Question_II_E = [
                                   'Sweep with broom or mop.',
                                   'Put key in door or lock.',
                                   'Pound with hammer or mallet.',
                                   'Attempt to use saw.',
                                   '"Type" at a typewriter or computer keyboard.',
                                   '"Read" (opens book, turns page).',
                                   'Vacuum.',
                                   'Water plants.',
                                   'Play musical instrument (e.g., piano, trumpet).',
                                   'For quality checking purposes, please choose the Yes option.',
                                   '"Drive" car by turning steering wheel.',
                                   'Wash dishes.',
                                   'Clean with cloth or duster.',
                                   'Write with a pen, pencil, or marker.',
                                   'Dig with a shovel.',
                                   'Put on glasses.',
                                  ];

    private const Question_III_A = [
                                    '1) To talk about more than one thing, we add an "s" to many words. Examples include cars (for more than one car), shoes, dogs, and keys. Has your child begun to do this?',
                                    '2) To talk about ownership, we add an "\'s", for example, Daddy\'s key, kitty\'s dish, and baby\'s bottle. Has your child begun to do this?',
                                    '3) To talk about activities, we sometimes add "ing" to verbs. Examples include looking, running, and crying. Has your child begun to do this?',
                                    '4) For quality checking purposes, please choose the Sometimes option.',
                                    '5) To talk about things that happened in the past, we often add "ed" to the verb. Examples include kissed, open, and pushed. Has your child begun to do this?',

                                   ];

    private const WordQuestion_III_B_N = [
                                          'children',
                                          'feet',
                                          'men',
                                          'mice',
                                          'teeth',
                                         ];

    private const WordQuestion_III_B_V = [
                                          'ate',
                                          'blew',
                                          'bought',
                                          'broke',
                                          'came',
                                          'drank',
                                          'drove',
                                          'fell',
                                          'flew',
                                          'got',
                                          'had',
                                          'heard',
                                          'held',
                                          'lost',
                                          'made',
                                          'ran',
                                          'sat',
                                          'saw',
                                          'took',
                                          'went',
                                         ];

    private const WordQuestion_III_C_N = [
                                          'blockses',
                                          'childrens',
                                          'childs',
                                          'feets',
                                          'foots',
                                          'mans',
                                          'mens',
                                          'mices',
                                          'mouses',
                                          'shoeses',
                                          'sockses',
                                          'teeths',
                                          'toeses',
                                          'tooths',
                                         ];

    private const WordQuestion_III_C_V = [
                                          'ated',
                                          'blewed',
                                          'blowed',
                                          'bringed',
                                          'buyed',
                                          'breaked',
                                          'broked',
                                          'camed',
                                          'comed',
                                          'doed',
                                          'dranked',
                                          'drinked',
                                          'eated',
                                          'falled',
                                          'flied',
                                          'getted',
                                          'goed',
                                          'gotted',
                                          'haved',
                                          'heared',
                                          'holded',
                                          'losed',
                                          'losted',
                                          'maked',
                                          'ranned',
                                          'runned',
                                          'seed',
                                          'satted',
                                          'sitted',
                                          'taked',
                                          'wented',
                                         ];

    private const Question_III_E = [
                                    [
                                     'Two shoe',
                                     'Two Shoes',
                                    ],
                                    [
                                     'Two foot',
                                     'Two feet',
                                    ],
                                    [
                                     'Daddy car',
                                     'Daddy\'s car',
                                    ],
                                    [
                                     'Kitty sleep (talking about right now)',
                                     'Kitty sleeping (talking about right now)',
                                    ],
                                    [
                                     'I make tower (talking about right now)',
                                     'I making tower (talking about right now)',
                                    ],
                                    [
                                     'I fall down (talking about something that already happened)',
                                     'I fell down (talking about something that already happened)',
                                    ],
                                    [
                                     'More cookie!',
                                     'More cookies!',
                                    ],
                                    [
                                     'These my tooth',
                                     'These my teeth',
                                    ],
                                    [
                                     'Baby blanket',
                                     'Baby\'s blanket',
                                    ],
                                    [
                                     'Doggie kiss me (talking about something that already happened)',
                                     'Doggie kissed me (talking about something that already happened)',
                                    ],
                                    [
                                     'Daddy pick me up (talking about something that already happened)',
                                     'Daddy picked me up (talking about something that already happened)',
                                    ],
                                    [
                                     'Kitty go away (talking about something that already happened)',
                                     'Kitty went away (talking about something that already happened)',
                                    ],
                                    [
                                     'Doggie table',
                                     'Doggie on table',
                                    ],
                                    [
                                     'That my truck',
                                     'That\'s my truck',
                                    ],
                                    [
                                     'Baby crying',
                                     'Baby is crying',
                                    ],
                                    [
                                     'You fix it?',
                                     'Can you fix it?',
                                    ],
                                    [
                                     'Read me story, Mommy',
                                     'Read me a story, Mommy',
                                    ],
                                    [
                                     'No wash dolly',
                                     'Don\'t wash dolly',
                                    ],
                                    [
                                     'Want more juice',
                                     'Want juice in there',
                                    ],
                                    [
                                     'There a kitty',
                                     'There\'s a kitty',
                                    ],
                                    [
                                     'Go bye-bye',
                                     'Wanna go bye-bye',
                                    ],
                                    [
                                     'Where mommy go?',
                                     'Where did Mommy go?',
                                    ],
                                    [
                                     'Coffee hot',
                                     'That coffee hot',
                                    ],
                                    [
                                     'I no do it',
                                     'I can\'t do it',
                                    ],
                                    [
                                     'I like read stories',
                                     'I like to read stories',
                                    ],
                                    [
                                     'Don\'t read book',
                                     'Don\'t want you read that book',
                                    ],
                                    [
                                     'Turn on light',
                                     'Turn on the light so I can see',
                                    ],
                                    [
                                     'I want that',
                                     'I want that one you got',
                                    ],
                                    [
                                     'Want cookies',
                                     'Want cookies and milk',
                                    ],
                                    [
                                     'Cookie mommy',
                                     'Cookie for mommy',
                                    ],
                                    [
                                     'Baby want eat',
                                     'Baby want to eat',
                                    ],
                                    [
                                     'Lookit me!',
                                     'Lookit me dancing!',
                                    ],
                                    [
                                     'Lookit!',
                                     'Lookit what I got!',
                                    ],
                                    [
                                     'Where\'s my dolly?',
                                     'Where\'s my dolly name Sam?',
                                    ],
                                    [
                                     'We made this',
                                     'Me and Paul made this',
                                    ],
                                    [
                                     'I sing song',
                                     'I sing song for you',
                                    ],
                                    [
                                     'Baby crying',
                                     'Baby crying cuz she\'s sad',
                                    ],
                                   ];
}
