<?php
/**
 *
 * @category Instrument
 * @author   Stella Lee <slee.mcin@gmail.com>
 * @license  http://www.gnu.org/licenses/gpl-3.0.txt GPLv3
 * @link     https://www.github.com/aces/IBIS/
 */

/**
 * Creates the form elements for the ABC instrument
 *
 * @category Instrument
 * @author   Stella Lee <slee.mcin@gmail.com>
 * @license  http://www.gnu.org/licenses/gpl-3.0.txt GPLv3
 * @link     https://www.github.com/aces/IBIS/
 */
class NDB_BVL_Instrument_m_chat_rf extends NDB_BVL_Instrument
{
    use LegacyInstrumentTrait;

    var $questions = array(
                      'q1_point_across_room'                  => '1. If you point at something across the room, does your child look at it? (FOR EXAMPLE, if you point at a toy or an animal, does your child look at the toy or animal?)',
                      'q2_deaf'                               => '2. Have you ever wondered if your child might be deaf?',
                      'q3_play_pretend'                       => '3. Does your child play pretend or make-believe? (FOR EXAMPLE, pretend to drink from an empty cup, pretend to talk on a phone, or pretend to feed a doll or stuffed animal?)',
                      'q4_like_climbing'                      => '4. Does your child like climbing on things? (FOR EXAMPLE, furniture, playground Yes No equipment, or stairs?)',
                      'q5_unusual_finger_movements_near_eyes' => '5. Does your child make unusual finger movements near his or her eyes? (FOR EXAMPLE, does your child wiggle his or her fingers close to his or her eyes?)',
                      'q6_point_one_finger_for_help'          => '6. Does your child point with one finger to ask for something or to get help? (FOR EXAMPLE, pointing to a snack or toy that is out of reach)',
                      'q7_point_one_finger_show'              => '7. Does your child point with one finger to show you something interesting? (FOR EXAMPLE, pointing to an airplane in the sky or a big truck in the road)',
                      'q8_interested_other_children'          => '8. Is your child interested in other children? (FOR EXAMPLE, does your child watch other children, smile at them, or go to them?)',
                      'q9_show_things'                        => '9. Does your child show you things by bringing them to you or holding them up for you to see – not to get help, but just to share? (FOR EXAMPLE, showing you a flower, a stuffed animal, or a toy truck)',
                      'q10_respond_by_name'                   => '10. Does your child respond when you call his or her name? (FOR EXAMPLE, does he or she look up, talk or babble, or stop what he or she is doing when you call his or her name?)',
                      'q11_smile_back'                        => '11. When you smile at your child, does he or she smile back at you?',
                      'q12_upset_by_everyday_noises'          => '12. Does your child get upset by everyday noises? (FOR EXAMPLE, does your child scream or cry to noise such as a vacuum cleaner or loud music?)',
                      'q13_walk'                              => '13. Does your child walk?',
                      'q14_look_in_eye'                       => '14. Does your child look you in the eye when you are talking to him or her, playing with him or her, or dressing him or her?',
                      'q15_copy_you'                          => '15. Does your child try to copy what you do? (FOR EXAMPLE, wave bye-bye, clap, or make a funny noise when you do)',
                      'q16_look_around'                       => '16. If you turn your head to look at something, does your child look around to see what you are looking at?',
                      'q17_try_watch'                         => '17. Does your child try to get you to watch him or her? (FOR EXAMPLE, does your child look at you for praise, or say “look” or “watch me”?)',
                      'q18_understand_tell_something'         => '18. Does your child understand when you tell him or her to do something? (FOR EXAMPLE, if you don’t point, can your child understand “put the book on the chair” or “bring me the blanket”?)',
                      'q19_look_at_face'                      => '19. If something new happens, does your child look at your face to see how you feel about it? (FOR EXAMPLE, if he or she hears a strange or funny noise, or sees a new toy, will he or she look at your face?)',
                      'q20_movement_activities'               => '20. Does your child like movement activities? (FOR EXAMPLE, being swung or bounced on your knee)',
                     );

    /**
     * Sets up basic data, such as the LorisForm object, and so on.
     *
     * @param  string $commentID the CommentID identifying the data to load
     * @param  string $page      if a multipage form, the page to show
     * @return void
     * @access public
     */
    function setup(?string $commentID = null, ?string $page = null): void
    {
        $this->formType = 'XIN';
        $this->form     = new LorisForm('test_form');
        $this->page     = $page; // page label (number or string - used by user-defined child classes)

        // set the object properties
        $this->testName = 'm_chat_rf'; // test_names.Test_name
        $this->table    = 'm_chat_rf'; // name of database table corresponding to instrument

        $this->commentID   = $commentID; // data keyed by commentID
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
        if (preg_match("/m_chat_rf(_page[0-9]+)/", $this->page, $matches)) {
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
        // Header
        $this->addHeader("Modified Checklist for Autism in Toddlers, Revised with Follow-Up");
        $this->addBasicDate('Date_taken', 'Date of Administration', $this->dateOptions);
        $yesNo = array(
                  null  => '',
                  'yes' => 'Yes',
                  'no'  => 'No',
                 );

        //        $this->addNumericElement('age', 'Age');
        $group[] =&$this->form->createElement("text", 'age', "", null);
        $this->XINRegisterRule("age", array("age{@}=={@}"), "Required.", "age_group");
        $this->form->addGroup($group, "age_group", 'Age', null, false);
        unset($group);
        $this->addGroupRule(
            "age_group",
            array(array(array("Value must be numeric.", 'numeric')))
        );

        $dateOptions = array(
                        'language'       => 'en',
                        'format'         => 'YMd',
                        'addEmptyOption' => true,
                       );

        $this->addBasicDate('Date_taken', 'Date', $dateOptions);

        $informant = array(
                      ''            => null,
                      'mother'      => 'Mother',
                      'father'      => 'Father',
                      'step_mother' => 'Step Mother',
                      'step_father' => 'Step Father',
                      'other'       => 'Other',
                     );

        $this->addSelect('relationship_to_child', "Relationship to child", $informant);
        $group[] = $this->createText('relationship_to_child_other', $this->indent."If Other please specify");
        $this->addGroup($group, "relationship_to_child_other_group", $this->indent."If Other please specify", null, false);
        unset($group);
        $rules_array = array("relationship_to_child{@}=={@}other");
        $this->XINRegisterRule('relationship_to_child_other', $rules_array, "Please specify relationship", 'relationship_to_child_other_group');

        $this->addLabel(
            '<strong>Instructions:</strong><BR>Please answer these questions about your child.
            Keep in mind how your child <strong>usually</strong> behaves.
            If you have seen your child do the behavior a few times, but he or she does not usually do it, then please answer <strong>no</strong>.
            Please choose <strong>yes or no</strong> for every question. Thank you very much.'
        );

        foreach ($this->questions as $field => $label) {
            $this->form->addElement('select', $field, $label, $yesNo);
        }

        $this->addLabel('2009 Diana Robins, Deborah Fein, & Marianne Barton');

    }


    // score function
    //    function score(): void
    //    {
    //        if ($this->_determineDataEntryCompletionStatus() == "Incomplete") {
    //            return;
    //        }
    //        //holds raw question values
    //        $score = array();
    //        $score['score_raw'] = null;
    //
    //        //holds calculated
    //        $db =& Database::singleton();
    //        //Get raw questions point values
    //        $query = "SELECT * FROM " . $this->table . " WHERE CommentID='" . $this->getCommentID() . "'";
    //        $db->pselectRow($query, $record);
    //
    //
    //        $sum = 0;
    //        $i = 1;
    //        foreach ($this->questions as $field => $label) {
    //            $sum += scoringAlgorithm($i, $record[$field]);
    //            $i++;
    //        }
    //
    //        $score['score_raw'] = $sum;
    //
    //        // save the scores
    //        $db->update(
    //            $this->table,
    //            $score,
    //            array('CommentID' => $this->getCommentID())
    //        );
    //
    //    }

    /**
     * Look up score values
     *
     * @return int
     * @access public
     */
    //    function scoringAlgorithm($question, $answer)
    //    {
    //        if ($question == 2 || $question == 5 || $question == 12) {
    //            if ($answer == "yes") return 1;
    //            else return 0;
    //        } else {
    //            if ($answer == "no") return 1;
    //            else return 0;
    //        }
    //    }
    //
    //    function calculateRisk($score)
    //    {
    //        if ($score < 3) {
    //            return "LOW-RISK";
    //        } else if ($score > 7) {
    //            return "HIGH-RISK";
    //        } else {
    //            return "MEDIUM-RISK";
    //        }
    //    }

}


/**
 * Return the HTML for the review section of the survey module
 * By default, this will show every question from the parameter_type
 * table for this instrument, but it can be overridden/customized by
 * a instrument if that isn't the desired behaviour.
 *
 * @return string The HTML to be inserted into the review section of
 *                the final page of the survey module for this instrument.
 */
function getReview()
{
    $DB = Database::singleton();

    $smarty   = new Smarty_neurodb();
    $tpl_data = array();

    $tpl_data['questions'] = $DB->pselect(
        "SELECT Description as question,
            SourceField FROM parameter_type
            WHERE SourceFrom=:TN AND
            SourceField NOT IN ('Validity', 'Administration')",
        array('TN' => $this->testName)
    );

    $Responses = $DB->pselectRow(
        "SELECT * FROM " . $this->testName . " WHERE CommentID=:CID",
        array('CID' => $this->getCommentID())
    );

    foreach ($tpl_data['questions'] as &$row) {
        if (isset($Responses[$row['SourceField']])) {
            $row['response'] = $Responses[$row['SourceField']];
        }
    }

    $smarty->assign($tpl_data);
    $html = $smarty->fetch("directentry_review.tpl");
    return $html;
}
