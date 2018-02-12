<?php


/*
 * This file contains the NDB_BVL_Instrument_UCD_Charge_GI_History
 * class
 *
 * PHP Version 5
 *
 * @category Instrument
 * @package  Neuropsych
 * @author   Liza Levitis <llevitis.mcin@gmail.com>
 * @license  http://www.gnu.org/licenses/gpl-3.0.txt GPLv3
 * @link     https://www.github.com/aces/IBIS/
 */

/**
 * Creates the form elements for the UCD_Charge_GI_History instrument
 *
 * @category Instrument
 * @package  Neuropsych
 * @author   Liza Levitis <llevitis.mcin@gmail.com>
 * @license  http://www.gnu.org/licenses/gpl-3.0.txt GPLv3
 * @link     https://www.github.com/aces/IBIS/
 */

class NDB_BVL_Instrument_UCD_Charge_GI_History extends NDB_BVL_Instrument
{
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
        $this->form = new LorisForm('UCD_Charge_GI_History_form');
        $this->page = $page;            // page label (number or
        // string - used by
        // user-defined child classes)

        // set the object properties
        $this->testName = "UCD_Charge_GI_History";           // test_names.Test_name
        $this->table = 'UCD_Charge_GI_History';              // name of database table corresponding to instrument
        // data keyed by commentID
        $this->commentID = $commentID;

        //The array of dates/timestamps to convert to database dates/timestamps
        //Any LorisForm date elements must be listed here
        $this->dateTimeFields=array("Date_taken");

        //The array of selects with multiple answers allowed
        //Any LorisForm multiple selects must be listed here
        $this->_selectMultipleElements = array();

        // required fields for data entry completion status
        $this->_requiredElements = array('Examiner', 'CommentID');

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
        //determine page to display
        if (preg_match(
            "/UCD_Charge_GI_History(_page[0-9]+)/",
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
     *
     */
    function _main(){
        // display test name
        $this->addHeader("CHARGE GI History");

        // automatically adds examiner & date of administration
        $this->_addMetadataFields();
    }

    /*
     * Header function for yes/no questions
     *
     */

    function displayHeaders($message1, $message2, $message3, $headerNum) {
        $group[] =& $this->form->createElement(
            "static",
            null,
            null,
            "Previous");
        $group[] =& $this->form->createElement(
            "static",
            null,
            null,
            "Current (past 3 months)");
        $group[] =& $this->form->createElement(
            "static",
            null,
            null,
            "");
        $group[] =& $this->form->createElement(
            "static",
            null,
            null,
            $message1);
        $group[] =& $this->form->createElement(
            "static",
            null,
            null,
            $message2);
        $group[] =& $this->form->createElement(
            "static",
            null,
            null,
            $message3);
        $this->form->addGroup(
            $group,
            "headers_" . $headerNum,
            null,
            $this->_GUIDelimiter,
            false
        );
        unset($group);
    }

    function _page1(){
        $this->addHeader("CHARGE GI History");
        $this->addLabel("<h4>$this->indent (0) = Never </h4>");
        $this->addLabel("<h4>$this->indent (1) = Rarely </h4>");
        $this->addLabel("<h4>$this->indent (2) = Sometimes </h4>");
        $this->addLabel("<h4>$this->indent (3) = Frequently </h4>");
        $this->addLabel("<h4>$this->indent (4) = Never </h4>");

        $commonOptions = array(
            null => "",
            0 => 0,
            1 => 1,
            2 => 2,
            3 => 3,
            4 => 4
        );

        $yesNoOptions = array(
            null => "",
            "yes" => "Yes",
            "no" => "No"
        );

        $currentNumericQuestions =
            array(
                "q1" => "Abdominal pain",
                "q2" => "Gaseousness or bloating sensation",
                "q3" => "Diarrhea",
                "q4" => "Constipation",
                "q5" => "Pain on stooling",
                "q6" => "Vomiting",
                "q7" => "Sensitivity to foods",
                "q8" => "Difficulty swallowing",
                "q9" => "Blood in stools",
                "q10" => "Blood in vomit"
            );

        $currentYesNoQuestions = array(
            "q11" => "Any allergies to foods?",
            "q12" => "Any diet restrictions",
            "q13" => "Does child have any strong food dislikes?"
        );

        $group[] =& $this->form->createElement(
            "static",
            null,
            null,
            "Previous");
        $group[] =& $this->form->createElement(
            "static",
            null,
            null,
            "Current (past 3 months)");
        $group[] =& $this->form->createElement(
            "static",
            null,
            null,
            "");
        $group[] =& $this->form->createElement(
            "static",
            null,
            null,
            "If yes, please describe.");
        $this->form->addGroup(
            $group,
            "headers_1",
            null,
            $this->_GUIDelimiter,
            false
        );
        unset($group);

        foreach($currentNumericQuestions as $key => $question) {
            if ($key == "q7") {
                $group[] =& $this->createSelect($key . "_previous", "", $commonOptions);
                $group[] =& $this->createSelect($key . "_current", "", $commonOptions);
                $group[] =& $this->createLabel($question);
                $group[] =& $this->createText($key . "_description", "If yes, please describe");
                $key_previous = $key . "_previous";
                $key_current = $key . "_current";
                $this->XINRegisterRule(
                    $key . "_description",
                    array("q7_previous{@}!={@}0|q7_current{@}!={@}0"),
                    "Required if an answer other than '0' is selected for 'current' or 'previous'.",
                    $key . "_group"
                );
            } else {
                $group[] =& $this->createSelect($key . "_previous", "", $commonOptions);
                $group[] =& $this->createSelect($key . "_current", "", $commonOptions);
                $group[] =& $this->createLabel($question);
                $group[] =& $this->form->createElement(
                    "static",
                    null,
                    null,
                    "");
            }
            $this->form->addGroup(
                $group,
                $key . "_group",
                null,
                $this->_GUIDelimiter,
                false
            );
            unset($group);
        }

        foreach ($currentYesNoQuestions as $key => $question) {
            if ($key == "q11") {
                $this->addHeader("");
                $this->displayHeaders("If yes, what food?", "", "", 2);
                $group[] =& $this->createSelect($key . "_previous", "", $yesNoOptions);
                $group[] =& $this->createSelect($key . "_current", "", $yesNoOptions);
                $group[] =& $this->createLabel($question);
                $group[] =& $this->createText($key . "_description", "If yes, what foods?");
                $key_previous = $key . "_previous";
                $key_current = $key . "_current";
                $this->XINRegisterRule(
                    $key . "_description",
                    array("q11_previous{@}=={@}yes|q11_current{@}=={@}yes"),
                    "Required if yes is selected for either 'current' or 'previous'.",
                    $key . "_group"
                );
            } elseif ($key == "q12") {
                $this->addHeader("");
                $this->displayHeaders("If yes, is diet restricted by:", "Reasons/Symptoms", "Foods that case or worsen any symptoms", 3);
                $group[] =& $this->createSelect($key . "_previous", "", $yesNoOptions);
                $group[] =& $this->createSelect($key . "_current", "", $yesNoOptions);
                $group[] =& $this->createLabel($question);
                $group[] =& $this->createSelect(
                    $key . "_diet_restricted_by",
                    "If yes, is diet restricted by:",
                    array(null => "", "child" => "Child", "parent" => "Parent", "doctor" => "Doctor"));
                $group[] =& $this->createText($key . "_reasons", "Reasons/Symptoms");
                $group[] =& $this->createText(
                    $key . "_foods",
                    "Foods that cause or worsen any symptoms");
                $key_previous = $key . "_previous";
                $key_current = $key . "_current";
                $this->XINRegisterRule(
                    $key . "_reasons",
                    array("q12_previous{@}=={@}yes|q12_current{@}=={@}yes"),
                    "Required if yes is selected for either 'current' or 'previous'.",
                    $key . "_group"
                );
                $this->XINRegisterRule(
                    $key . "_foods",
                    array("q12_previous{@}=={@}yes|q12_current{@}=={@}yes"),
                    "Required if yes is selected for either 'current' or 'previous'.",
                    $key . "_group"
                );
                $this->XINRegisterRule(
                    $key . "_diet_restricted_by",
                    array("q12_previous{@}=={@}yes|q12_current{@}=={@}yes"),
                    "Required if yes is selected for either 'current' or 'previous'.",
                    $key . "_group"
                );
            } else {
                $this->addHeader("");
                $this->displayHeaders("If yes, what foods?", "", "", 4);
                $group[] =& $this->createSelect($key . "_previous", "", $yesNoOptions);
                $group[] =& $this->createSelect($key . "_current", "", $yesNoOptions);
                $group[] =& $this->createLabel($question);
                $group[] =& $this->createText($key . "_description", "If yes, what foods?");
                $key_previous = $key . "_previous";
                $key_current = $key . "_current";
                $this->XINRegisterRule(
                    $key . "_description",
                    array("q13_previous{@}=={@}yes|q13_current{@}=={@}yes"),
                    "Required if yes is selected for either 'current' or 'previous'.",
                    $key . "_group"
                );
            }
            $this->form->addGroup(
                $group,
                $key . "_group",
                null,
                $this->_GUIDelimiter,
                false
            );
            unset($group);
        }

        $this->addSelect(
            "gastrointestinal_diagnosis_given",
            "Has any gastrointestinal diagnosis been given?",
            $yesNoOptions);

        $this->addBasicTextArea("gastrointestinal_diagnosis", "If yes, what?");
        $this->XINRegisterRule(
            "gastrointestinal_diagnosis",
            array("gastrointestinal_diagnosis_given{@}=={@}yes"),
            "gastrointestinal_diagnosis_group"
        );
    }
}
?>
