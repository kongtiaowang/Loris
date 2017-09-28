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
class NDB_BVL_Instrument_connors_teacher extends NDB_BVL_Instrument
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
        $this->form     = new LorisForm('connors_teacher_form');
        $this->page     = $page;

        // set the object properties
        $this->testName = 'connors_teacher'; // test_names.Test_name
        $this->table    = 'connors_teacher'; // name of database
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
     * method to build the LorisForm object into a paged form
     *
     * @return void
     * @access private
     */
    function _setupForm()
    {
        //determine page to display
        if (preg_match(
            "/connors_teacher(_page[0-9]+)/",
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
     * generates the main page of the form.
     *
     * @return void
     * @access private
     */
    function _main()
    {
        $this->form->addHeader("CONNORS 3 - Teacher Short");
        $this->_addMetadataFields();

        $this->addBasicText("childs_name_id", "Child's Name/ID:");
        $this->addBasicText("teachers_name_id", "Teacher's Name/ID:");
        $this->addBasicText("grade", "Grade:");
    }

    function _page1() {
        $this->addHeader("CONNORS 3 - Teacher Short");
        $this->addLabel("<h4><b>Instructions:</b> Here are some things teachers
                         might say about their students. Please tell us about
                         <i>this</i> student and what he/she has been like
                         in the <b><i>past month</i></b>. 
                         Read each item carefully, then mark how well
                         it describes this student or how frequently 
                         it has happened in the <b><i>past month</i></b>.</h4>");

        $this->addLabel("<h4>$this->indent <b>0</b> = In the past month, 
                         this was <b><i>not true at all</i></b> about this student. It never
                         (or seldom) happened</h4>.");
        $this->addLabel("<h4>$this->indent <b>1</b> = In the past month, this was 
                         <b><i>just a little true</i></b> about this student. 
                         It happened occasionally.</h4>");
        $this->addLabel("<h4>$this->indent <b>2</b> = In the past month, 
                         this was <b><i>pretty much true</i></b> about
                         this student. It happened often (or quite a bit).\r\n</h4>");
        $this->addLabel("<h4>$this->indent <b>3</b> = In the past month, this 
                         was <b><i>very much true</i></b> about this student. It
                         happened very often (very frequently).</h4>");

        $this->addLabel("<h4>Please pick one answer for each item. It is important
                         to respond to every item. For items that you find difficult
                         to answer, please give your best guess.</h4>");

        $options =
            array(
                null => "",
                0 => 0,
                1 => 1,
                2 => 2,
                3 => 3
            );

        $questions =
            array(
                "q1"  => "1. Is constantly moving",
                "q2"  => "2. Has to struggle to complete hard tasks.",
                "q3"  => "3. Inattentive, easily distracted.",
                "q4"  => "4. Makes mistakes",
                "q5"  => "5. Bullies, threatens, or scares others.",
                "q6"  => "6. Cannot do things right.",
                "q7"  => "7. Is angry and resentful.",
                "q8"  => "8. Excitable, impulsive.",
                "q9"  => "9. Is fun to be around.",
                "q10" =>
                    "10. Has trouble keeping his/her mind on work or play for long.",
                "q11" => "11. Has poor social skills.",
                "q12" =>
                    "12. Actively refuses to do what adults tell him/her to do.",
                "q13" => "13. Is happy, cheerful, and has a positive attitude.",
                "q14" => "14. Cannot grasp arithmetic.",
                "q15" => "15. Tries to get even with people.",
                "q16" => "16. Has trouble getting started on tasks or projects.",
                "q17" => "17. Acts in sneaky or manipulative ways.",
                "q18" => "18. Does not understand what he/she reads.",
                "q19" => "19. Tells the truth; does not even tell \"little white lies.\"",
                "q20" => "20. Appears to be unaccepted by group.",
                "q21" => "21. Is hard to motivate (even with highly desirable rewards).",
                "q22" => "22. Restless or overactive.",
                "q23" => "23. Is good at planning ahead.",
                "q24" => "24. Fidgets or squirms in seat.",
                "q25" => "25. Is patient and content, even when waiting in a long line.",
                "q26" => "26. Doesn't pay attention to details; makes careless mistakes.",
                "q27" => "27. Is one of the last to be picked for teams or games.",
                "q28" => "28. Spelling is poor.",
                "q29" => "29. Has trouble keeping friends.",
                "q30" => "30. Leaves seat when he/she should stay seated.",
                "q31" => "31. Behaves like an angel.",
                "q32" => "32. Talks out of turn.",
                "q33" => "33. Is difficult to please or amuse.",
                "q34" => "34. Is perfect in every way.",
                "q35" => "35. Forgets things already learned.",
                "q36" => "36. Has a short attention span.",
                "q37" => "37. Does not know how to make friends.",
                "q38" => "38. I cannot figure out what makes him/her happy.",
                "q39" => "39. Is sidetracked easily.",
            );

        foreach ($questions as $key => $question) {
            $this->addSelect($key, $question, $options);
        }

        $this->addLabel("<h3>Additional Questions</h3>");
        $additional_questions =
            array(
                "q40" => "40. Do you have any other concerns about this student?",
                "q41" => "41. What strengths or skills does this student have?"
            );

        foreach($additional_questions as $key => $question) {
            $this->addBasicText($key, $question);
        }
    }
}
