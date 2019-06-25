<?php
/**
 *
 * @category Instrument
 * @author   Liza Levitis <llevitis.mcin@gmail.com>
 * @license  http://www.gnu.org/licenses/gpl-3.0.txt GPLv3
 * @link     https://www.github.com/aces/IBIS/
 */

/**
 * Creates the form elements for the ABC instrument
 *
 * @category Instrument
 * @author   Liza Levitis <llevitis.mcin@gmail.com>
 * @license  http://www.gnu.org/licenses/gpl-3.0.txt GPLv3
 * @link     https://www.github.com/aces/IBIS/
 */
class NDB_BVL_Instrument_conners_parent extends NDB_BVL_Instrument
{

    /**
     * Sets up basic data, such as the LorisForm object, and so on.
     *
     * @param  string $commentID the CommentID identifying the data to load
     * @param  string $page if a multipage form, the page to show
     * @return void
     * @access public
     */
    function setup($commentID, $page)
    {
        $this->formType = 'XIN';
        $this->form     = new LorisForm('conners_parent_form');
        $this->page     = $page;

        // set the object properties
        $this->testName = 'conners_parent'; // test_names.Test_name
        $this->table    = 'conners_parent'; // name of database
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
     * method to build the LorisForm object into a paged form
     *
     * @return void
     * @access private
     */
    function _setupForm()
    {
        //determine page to display
        if (preg_match(
            "/conners_parent(_page[0-9]+)/",
            $this->page,
            $matches
        )) {
            call_user_func(array($this, $matches[1]));
        } else {
            $this->_main();
        }

        $this->form->addFormRule(array(&$this, 'XINValidate'));
        $this->form->addFormRule(array(&$this, 'addSpecialRules'));
    }

    /**
     * generates the main page of the form.
     *
     * @return void
     * @access private
     */
    function _main()
    {

        $this->addHeader("CONNERS 3 - Parent Short");
        $this->addBasicDate('Date_taken', 'Date of Administration', $this->dateOptions);
        $opts = array(
            null              => "",
            "mother"             => "Mother",
            "father"             => "Father",
            "step_mother"        => "Step Mother",
            "step_father"        => "Step Father",
            "other"             => "Other",
        );
        $this->addSelect("relationship_to_child", "What is your relationship to the child?", $opts);
        $this->addBasicText("other_relationship_to_child", $this->indent."If Other, please describe:");
        $this->XINRegisterRule(
            "other_relationship_to_child",
            array("relationship_to_child{@}=={@}other"),
            "Required",
            "other_relationship_to_child"
        );

        $this->addLabel("Please specify the grade: K-12 (or NA if you do not wish to answer)");
        $this->addBasicText("grade", "Grade:");
    }

    function _page1() {
        $this->addHeader("CONNERS 3 - Parent Short");
        $this->addHeader("<h4><b>Instructions:</b> Here are some things parents
                         might say about their children. Please tell us about
                         <i>your</i> child and what he/she has been like
                         in the <b><i>past month</i></b>. 
                         Read each item carefully, then mark how well
                         it describes your child or how frequently 
                         it has happened in the <b><i>past month</i></b>.<br><br>
                         $this->indent <b>0</b> = In the past month, 
                         this was <b><i>not true at all</i></b> about my child. It never
                         (or seldom) happened<br></h4><br>
                         $this->indent <b>1</b> = In the past month, this was 
                         <b><i>just a little true</i></b> about my child. 
                         It happened occasionally.<br>
                         $this->indent <b>2</b> = In the past month, 
                         this was <b><i>pretty much true</i></b> about<
                         my child. It happened often (or quite a bit).<br>
                         $this->indent <b>3</b> = In the past month, this 
                         was <b><i>very much true</i></b> about my child. It
                         happened very often (very frequently).<br><br>
                         Please pick one answer for each item. It is important
                         to respond to every item. For items that you find difficult
                         to answer, please give your best guess.");

        $options =
            array(
                null => "",
                0 => "0 - Not true at all",
                1 => "1 - Just a little true",
                2 => "2 - Pretty much true",
                3 => "3 - Very much true"
            );

        $questions =
            array(
                "q1" => "1. Forgets to turn in completed work",
                "q2" => "2. Is perfect in every way.",
                "q3" => "3. Fidgets or squirms in seat.",
                "q4" => "4. Is one of the last to be picked for teams or games",
                "q5" => "5. Restless or overactive",
                "q6" => "6. Does not know how to make friends.",
                "q7" => "7. Runs or climbs when he/she is not supposed to.",
                "q8" => "8. Cannot grasp arithmetic.",
                "q9" => "9. Is difficult to please or amuse.",
                "q10" => "10. Needs extra explanation of instructions.",
                "q11" => "11. Is hard to motivate (even with rewards like candy or money.",
                "q12" => "12. Makes mistakes.",
                "q13" => "13. Acts as if driven by a motor.",
                "q14" => "14. Starts fight with others on purpose.",
                "q15" => "15. Has trouble getting started on tasks or projects.",
                "q16" => "16. Is happy, cheerful, and has a positive attitude",
                "q17" => "17. Doesn't pay attention to details; makes careless mistakes.",
                "q18" => "18. Has trouble keeping friends.",
                "q19" => "19. Bullies, threatens, or scares others.",
                "q20" => "20. Loses things (for example, schoolwork, pencils, books, tools or toys.",
                "q21" => "21. Tells lies to hurt other people.",
                "q22" => "22. I cannot figure out what makes him/her happy.",
                "q23" => "23. Threatens to hurt others.",
                "q24" => "24. Is constantly moving.",
                "q25" => "25. Has trouble with reading.",
                "q26" => "26. Is angry and resentful.",
                "q27" => "27. Has a short attention span.",
                "q28" => "28. Excitable, impulsive.",
                "q29" => "29. Cannot do things right.",
                "q30" => "30. Has trouble concentrating",
                "q31" => "31. Tells the truth; doesn't even tell \"little white lies.\"",
                "q32" => "32. Has trouble organizing tasks or activities.",
                "q33" => "33. Is fun to be around.",
                "q34" => "34. Inattentive, easily distracted.",
                "q35" => "35. Is messy or disorganized.",
                "q36" => "36. Spelling is poor",
                "q37" => "37. Is patient and content, even when waiting in a long line.",
                "q38" => "38. Has no friends.",
                "q39" => "39. Does not understand what he/she reads.",
                "q40" => "40. Behaves like an angel.",
                "q41" => "41. Has trouble keeping his/her mind on work or on play for long.",
                "q42" => "42. Has to struggle to complete hard tasks.",
                "q43" => "43. Does not get invited to play or go out with others."
            );

        foreach ($questions as $key => $question) {
            $this->addSelect($key, $question, $options);
        }

        $this->addLabel("<h3>Additional Questions</h3>");
        $additional_questions =
            array(
                "q44" => "44. Do you have any other concerns about your child?",
                "q45" => "45. What strengths or skills does your child have?"
            );

        foreach($additional_questions as $key => $question) {
            $this->addBasicText($key, $question);
        }
    }
    
    function addSpecialRules($values)
    {
		$errors = array();
		
		if(isset($values['grade'])) {
			if(!preg_match('/^\s*(K|[1-9]|1[012]|NA)\s*$/', $values['grade'])) {
				$errors['grade'] = 'Please enter a grade (K-12) or NA';
			}
		}
		
		return $errors;
	}

    function score()
    {
        if ($this->_determineDataEntryCompletionStatus() == "Incomplete") {
            return;
        }

        //null scores
        $this->_nullScores($this->scoreLabels);

        //get the saved scores
        $db =& Database::singleton();
        $query = "SELECT * FROM $this->table WHERE CommentID = '$this->commentID'";
        $record = $db->pselectRow($query, array());
        $IN_array = array($record['q1_is_fidgety'],
            $record['q17'],
            $record['q27'],
            $record['q30'],
            $record['q34'],
            $record['q41'],
        );
    }
}
