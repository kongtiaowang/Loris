<?php
/**
 *This file contains the NDB_BVL_tanner_girls_survey class
 *
 * PHP Version 7
 *
 * @category Instrument
 * @package  Neuropsych
 * @author   Suzanne Lee <suzannelee.mcin@gmail.com>, modified by Ling Ma
 * @license  http://www.gnu.org/licenses/gpl-3.0.txt GPLv3
 * @link     https://www.github.com/aces/IBIS/
 */

/**
 * Creates the form elements for the tanner_girls_survey instrument
 *
 * @category Instrument
 * @package  Neuropsych
 * @author   Suzanne Lee <suzannelee.mcin@gmail.com>
 * @license  http://www.gnu.org/licenses/gpl-3.0.txt GPLv3
 * @link     https://www.github.com/aces/IBIS/
 */
class NDB_BVL_Instrument_tanner_girls_survey extends NDB_BVL_Instrument
{
    var $ValidityRequired = false;

    public function getFullName(): string
    {
        return 'TANNER Staging Questionnaire (Girls) Survey';
    }

    function getSubtestList(): array {
        return [];
    }

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
        $this->formType ='XIN';
        $this->form     = new LorisForm('test_form');
        $this->page     = $page;            // page label (number or
        // string - used by
        // user-defined child classes)

        // set the object properties
        $this->testName = 'tanner_girls_survey';           // test_names.Test_name
        $this->table    = 'tanner_girls_survey';              // name of database table corresponding to instrument
        // data keyed by commentID
        $this->commentID = $commentID;

        //The array of dates/timestamps to convert to database dates/timestamps
        //Any LorisForm date elements must be listed here
        $this->dateTimeFields =array('Date_taken');

        //The array of selects with multiple answers allowed
        //Any LorisForm multiple selects must be listed here
        $this->selectMultipleElements = array();

        // required fields for data entry completion status
        $this->_requiredElements = ['Date_taken', 'q1_height_growth'];

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
        $this->_main();

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
        $this->addHeader('TANNER Staging- Questionnaire (Girls) Survey');

        $config      =& NDB_Config::singleton();
        $dateOptions = array(
            'language'         => 'en',
            'format'           => 'YMd',
            'minYear'          => $config->getSetting('startYear'),
            'maxYear'          => $config->getSetting('endYear'),
            'addEmptyOption'   => true,
            'emptyOptionValue' => null,
        );

        $this->addLabel('I am going to ask you some questions about your physical development. Because these questions are very personal, I am giving you a form with the questions and possible answers on it. Fill in the circle next to the answer that best describes you now.');

        $this->addBasicDate('Date_taken', 'Date Taken', $dateOptions);

        $options1 = array(
            null => '',
            'a'  => 'a. Not yet begun to spurt (spurt means more growth than usual)',
            'b'  => 'b. Has barely started',
            'c'  => 'c. Is definitely underway',
            'd'  => 'd. Or does growth seem completed?',
        );

        $options2 = array(
            null => '',
            'a'  => 'a. Has not yet started',
            'b'  => 'b. Has barely started growing',
            'c'  => 'c. Has definitely started growing',
            'd'  => 'd. Or does growth seem completed?',
        );

        $options3 = array(
            null => '',
            'a'  => 'a. Not yet started showing changes',
            'b'  => 'b. Have barely started showing changes',
            'c'  => 'c. Skin changes are definitely underway',
            'd'  => 'd. Skin changes seem completed',
        );

        $options4 = array(
            null => '',
            'a'  => 'a. Not yet started growing',
            'b'  => 'b. Have barely started growing',
            'c'  => 'c. Breast growth is definitely underway',
            'd'  => 'd. Breast growth seems completed',
        );

        $options5 = array(
            null => '',
            'n'  => '(n) No',
            'y'  => '(y) Yes',
        );

        $this->addSelect('q1_height_growth', '1. Would you say that your growth in height has:', $options1);

        $this->addSelect('q2_body_hair_growth', '2. How about the growth of body hair, meaning underarm and pubic hair? Would you say that your body hair:', $options2);

        $this->addSelect('q3_skin_changes', '3. Have you noticed any skin changes, especially pimples?', $options3);

        $this->addSelect('q4_breast_growth', '4. Have your breasts begun to grow?', $options4);

        $this->addSelect('q5_begun_to_menstruate', '5. Have you begun to menstruate?', $options5);

        $this->addLabel("If yes, <br>a. What was the date of your first menstruation?");

        $this->addBasicText('q5a_month', '(month)');

        $this->XINRegisterRule(
            'q5a_month',
            array('q5_begun_to_menstruate{@}=={@}b'),
            'Required.'
        );

        $this->addBasicText('q5a_year', '(year)');

        $this->XINRegisterRule(
            'q5a_year',
            array('q5_begun_to_menstruate{@}=={@}b'),
            'Required.'
        );

        $this->addBasicDate('q5b_first_day_of_last_menstrual_period', 'b. What was the date of the first day of your last menstrual period?');

        $this->XINRegisterRule(
            'q5b_first_day_of_last_menstrual_period',
            array('q5_begun_to_menstruate{@}=={@}b'),
            'Required.'
        );

        $this->form->addFormRule(array(&$this, 'tanner_girls_special_rules'));
    }

    function tanner_girls_special_rules($values)
    {
        $errors = array();
        if (isset($values['q5_begun_to_menstruate']) && $values['q5_begun_to_menstruate'] == 'n') {
            $fields = ['q5a_month', 'q5a_year', 'q5b_first_day_of_last_menstrual_period'];
            foreach ($fields as $field) {
                if (!empty($values[$field])) {
                    $errors[$field] = 'This field should be empty because you have choose "No" for the question 5.';
                }
            }
        }
        return $errors;
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
            default:
                throw new Exception('Unknown Value');
        }
    }

    function getDerivedValue($raw_score): string {
        if ($raw_score <= 1.7) {
            return "pre_pubertal";
        }

        if ($raw_score > 1.7 && $raw_score <= 2.4) {
            return "early_pubertal";
        }

        if ($raw_score > 2.4 && $raw_score <= 3) {
            return "mid_pubertal";
        }

        if ($raw_score > 3 && $raw_score <= 3.6) {
            return "late_pubertal";
        }

        return "post_pubertal";
    }

    function score(): void {
        $db =& Database::singleton();

        // Get the item scores
        $record= $db->pselectRow("SELECT * FROM $this->table WHERE CommentID=:cid", array('cid'=>$this->getCommentID()));
        $sum = 0;

        try {
            $sum += $this->getScoreValue($record['q1_height_growth']);
            $sum += $this->getScoreValue($record['q2_body_hair_growth']);
            $sum += $this->getScoreValue($record['q3_skin_changes']);
            $sum += $this->getScoreValue($record['q4_breast_growth']);

            $raw_score = $sum/4;

            $score = array(
                'tanner_score_girls'=>$raw_score,
                'tanner_pubertal_stage_girls'=>$this->getDerivedValue($raw_score)
            );

            $db->update($this->table, $score, array('CommentID'=>$this->getCommentID()));
        } catch (Exception $e) {
            // Unknown value seen, silently fail.
        }

    }
}
