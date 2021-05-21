<?php
/**
 *This file contains the NDB_BVL_TANNER_Boys class
 *
 * PHP Version 5
 *
 * @category Instrument
 * @package  Neuropsych
 * @author   Suzanne Lee <suzannelee.mcin@gmail.com>
 * @license  http://www.gnu.org/licenses/gpl-3.0.txt GPLv3
 * @link     https://www.github.com/aces/IBIS/
 */

/**
 * Creates the form elements for the TANNER_Boys instrument
 *
 * @category Instrument
 * @package  Neuropsych
 * @author   Suzanne Lee <suzannelee.mcin@gmail.com>
 * @license  http://www.gnu.org/licenses/gpl-3.0.txt GPLv3
 * @link     https://www.github.com/aces/IBIS/
 */
class NDB_BVL_Instrument_TANNER_Boys extends NDB_BVL_Instrument
{
    use LegacyInstrumentTrait;

    /**
    * Sets up basic data, such as the LorisForm object, and so on.
    *
    * @param string $commentID the CommentID identifying the data to load
    * @param string $page      if a multipage form, the page to show
    *
    * @return void
    *
    * @access public
    */
    function setup(?string $commentID = NULL, ?string $page = NULL): void
    {
        $this->formType ="XIN";
        $this->form     = new LorisForm('test_form');
        $this->page     = $page;            // page label (number or
        // string - used by
        // user-defined child classes)

        // set the object properties
        $this->testName = "TANNER_Boys";           // test_names.Test_name
        $this->table    = 'TANNER_Boys';              // name of database table corresponding to instrument
        // data keyed by commentID
        $this->commentID = $commentID;

        //The array of dates/timestamps to convert to database dates/timestamps
        //Any LorisForm date elements must be listed here
        $this->dateTimeFields =array("Date_taken");

        //The array of selects with multiple answers allowed
        //Any LorisForm multiple selects must be listed here
        $this->_selectMultipleElements = array();

        // required fields for data entry completion status
        $this->_requiredElements = array(
                                    'Examiner',
                                    'q1_height_growth',
                                   );

        // setup the form
        $this->_setupForm();

    }

    //If the instrument is not paged, remove the switch from the _setupForm method and add all the form Elements in this function.

    /**
    * Method to build the LorisForm object into a paged form
    *
    * @return void
    * @access private
    */
    function _setupForm()
    {
        if (preg_match("/TANNER_Boys(_page[0-9]+)/", $this->page, $matches)) {
            call_user_func(array($this, $matches[1]));
        } else {
            $this->_main();
        }
        //Defines the call back function for HTML Quickform to use when validating the form.
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
        $this->addHeader("TANNER Staging- Questionnaire (Boys)");

        // automatically adds examiner & date of administration
        $this->_addMetadataFields();

        $this->form->addElement("static", "tanner_score_boys", "Tanner Stage of Physical Development (Boys)");
    }
    /**
    * Generates the first page of the form.
    *
    *@return void
    */
    function _page1()
    {
        $this->addHeader("TANNER Staging- Questionnaire (Girls and Boys)");

        $this->addLabel("<h4><b>$this->indent Physical Development: Boys</b></h4>");

        $this->addLabel("I am going to ask you some questions about your physical development. Because these questions are very personal, I am giving you a form with the questions and possible answers on it. I'll read the questions along with you. As I go along, fill in the circle next to the answer that best describes you now.");

        $this->form->addElement("static", null, "<br/>");

        $options1 = array(
                     null => "",
                     "a"  => "a. Not yet begun to spurt (spurt means more growth than usual)",
                     "b"  => "b. Has barely started",
                     "c"  => "c. Is definitely underway",
                     "d"  => "d. Or does growth seem completed?",
                    );

        $options2 = array(
                     null => "",
                     "a"  => "a. Has not yet started",
                     "b"  => "b. Has barely started growing",
                     "c"  => "c. Has definitely started growing",
                     "d"  => "d. Or does growth seem completed?",
                    );

        $options3 = array(
                     null => "",
                     "a"  => "a. Not yet started showing changes",
                     "b"  => "b. Have barely started showing changes",
                     "c"  => "c. Skin changes are definitely underway",
                     "d"  => "d. Skin changes seem completed",
                    );

        $options4 = array(
                     null => "",
                     "a"  => "a. Not yet started changing",
                     "b"  => "b. Has barely started changing",
                     "c"  => "c. Voice change is definitely underway",
                     "d"  => "d. Voice change seems completed",
                    );

        $options5 = array(
                     null => "",
                     "a"  => "a. Not yet started growing hair",
                     "b"  => "b. Has barely started growing hair",
                     "c"  => "c. Facial hair growth is definitely underway",
                     "d"  => "d. Facial hair growth seems completed",
                    );

        $questions = array(
                      "q1_height_growth"     => "1. Would you say that your growth in height has:",
                      "q2_body_hair_growth"  => "2. How about the growth of body hair, meaning underarm and pubic hair? Would you say that your body hair:",
                      "q3_skin_changes"      => "3. Have you noticed any skin changes, especially pimples?",
                      "q4_voice_deepening"   => "4. Have you noticed a deepening of your voice?",
                      "q5_grow_hair_on_face" => "5. Have you begun to grow hair on your face?",
                     );

        $this->addSelect("q1_height_growth", "1. Would you say that your growth in height has:", $options1);

        $this->addSelect("q2_body_hair_growth", "2. How about the growth of body hair, meaning underarm and pubic hair? Would you say that your body hair:", $options2);

        $this->addSelect("q3_skin_changes", "3. Have you noticed any skin changes, especially pimples?", $options3);

        $this->addSelect("q4_voice_deepening", "4. Have you noticed a deepening of your voice?", $options4);

        $this->addSelect("q5_grow_hair_on_face", "5. Have you begun to grow hair on your face?", $options5);
    }

    function getScoreValue($value): int {
        switch ($value) {
            case "a":
                return 1;
            case "b":
                return 2;
            case "c":
                return 3;
            case "d":
                return 4;
        }
    }

    function score(): void {
        $db =& Database::singleton();

        // Get the item scores
        $record= $db->pselectRow("SELECT * FROM $this->table WHERE CommentID=:cid", array('cid'=>$this->getCommentID()));
        $sum = 0;

        $sum += $this->getScoreValue($record['q1_height_growth']);
        $sum += $this->getScoreValue($record['q2_body_hair_growth']);
        $sum += $this->getScoreValue($record['q3_skin_changes']);
        $sum += $this->getScoreValue($record['q4_voice_deepening']);
        $sum += $this->getScoreValue($record['q5_grow_hair_on_face']);

        $score = array('tanner_score_boys'=>$sum/5);

        $db->update($this->table, $score, array('CommentID'=>$this->getCommentID()));
    }
}
?>
