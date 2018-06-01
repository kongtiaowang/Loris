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
        $this->_requiredElements = array('CommentID');

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

        $this->addBasicDate('Date_taken', 'Date of Administration', $this->dateOptions);
    }

    /*
     * Header function for yes/no questions
     *
     */

    function displayHeaders($header_count) {
        $group[] =& $this->form->createElement(
            "static",
            null,
            null,
            "<b>Previous</b>");
        $group[] =& $this->form->createElement(
            "static",
            null,
            null,
            "<b>Current (past 3 months)</b>");
        $group[] =& $this->form->createElement(
            "static",
            null,
            null,
            "");
        $group[] =& $this->form->createElement(
            "static",
            null,
            null,
            "");
        $group[] =& $this->form->createElement(
            "static",
            null,
            null,
            "");
        $this->form->addGroup(
            $group,
            "headers_$header_count",
            null,
            $this->_GUIDelimiter,
            false
        );
        unset($group);
    }

    function _page1(){
        $this->addHeader("CHARGE GI History");
        $this->addLabel("<h4>$this->indent (0) = Never $this->indent (1) = Rarely $this->indent (2) = Sometimes $this->indent (3) = Frequently $this->indent (4) = Always</h4>");
        $commonOptions = array(
            null => "",
            0 => "0 Never" ,
            1 => "1 Rarely",
            2 => "2 Sometimes",
            3 => "3 Frequently",
            4 => "4 Always"
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
                "q7" => "Sensitivity to foods.",
                "q8" => "Difficulty swallowing",
                "q9" => "Blood in stools",
                "q10" => "Blood in vomit"
            );

        $currentYesNoQuestions = array(
            "q11" => "Any allergies to foods?",
            "q12" => "Any diet restrictions",
            "q12_additional_1" => "Reasons/Symptoms",
            "q12_additional_2" => "Foods that cause or worsen any symptoms",
            "q13" => "Does child have any strong food dislikes?"
        );
        $this->displayHeaders(1);
        foreach($currentNumericQuestions as $key => $question) {
            if ($key == "q7") {
                $group[] =& $this->createSelect($key . "_previous", $question." - Previous", $commonOptions);
                $group[] =& $this->createSelect($key . "_current", $question." - Current (past 3 months)", $commonOptions);
                $group[] =& $this->createLabel($question);
                $group[] =& $this->createLabel("If Yes, please describe");
                $group[] =& $this->createText($key . "_description", "If yes, please describe");
                $key_previous = $key . "_previous";
                $key_current = $key . "_current";
                $this->XINRegisterRule(
                    $key . "_description",
                    array("q7_previous{@}!={@}0|q7_current{@}!={@}0"),
                    "Required if any answer other than 'Never' is selected for 'current' or 'previous'."
                );
            } else {
                $group[] =& $this->createSelect($key . "_previous", $question." - Previous", $commonOptions);
                $group[] =& $this->createSelect($key . "_current", $question." - Current (past 3 months)", $commonOptions);
                $group[] =& $this->createLabel($question);
                $group[] =& $this->createLabel("");
    }
            $key_previous = $key . "_previous";
            $key_current = $key . "_current";
            $this->XINRegisterRule(
                $key_previous,
                array("$key_previous{@}=={@}"),
                "Required."

            );
            $this->XINRegisterRule(
                $key_current,
                array("$key_current{@}=={@}"),
                "Required."
            );
            $this->form->addGroup(
                $group,
                $key . "_group",
                null,
                $this->_GUIDelimiter,
                false
            );
            unset($group);
        }
        $this->displayHeaders(2);
        foreach ($currentYesNoQuestions as $key => $question) {
            if ($key == "q11") {
                $group[] =& $this->createSelect($key . "_previous", $question." - Previous", $yesNoOptions);
                $group[] =& $this->createSelect($key . "_current", $question." - Current (past 3 months)", $yesNoOptions);
                $group[] =& $this->createLabel($question);
                $group[] =& $this->createLabel("If yes, what foods?");
                $group[] =& $this->createText($key . "_description", "If yes, what foods?");
                $key_previous = $key . "_previous";
                $key_current = $key . "_current";
                $this->XINRegisterRule(
                    $key . "_description",
                    array("q11_previous{@}=={@}yes|q11_current{@}=={@}yes"),
                    "Required if yes is selected for either 'current' or 'previous'."
                );
            } elseif ($key == "q12") {
                $group[] =& $this->createSelect($key . "_previous", $question." - Previous", $yesNoOptions);
                $group[] =& $this->createSelect($key . "_current", $question." - Current (past 3 months)", $yesNoOptions);
                $group[] =& $this->createLabel($question);
                $group[] =& $this->createLabel("If yes, is diet restricted by:");
                $group[] =& $this->createSelect(
                    $key . "_diet_restricted_by",
                    "If yes, is diet restricted by:",
                    array(null => "", "child" => "Child", "parent" => "Parent", "doctor" => "Doctor"));


                $this->XINRegisterRule(
                    $key . "_diet_restricted_by",
                    array("q12_previous{@}=={@}yes|q12_current{@}=={@}yes"),
                    "Required if yes is selected for either 'current' or 'previous'."
                );

            }
            elseif ($key == "q12_additional_1")
            {
                $org_key="q12";
                $group[] =& $this->form->createElement("static", null, null, "");
                $group[] =& $this->form->createElement("static", null, null, "");
                $group[] =& $this->form->createElement("static", null, null, "");
                $group[] =& $this->createLabel($question);
                $group[] =& $this->createText($org_key . "_reasons", "Reasons/Symptoms");
                $this->XINRegisterRule(
                    $org_key . "_reasons",
                    array("q12_previous{@}=={@}yes|q12_current{@}=={@}yes"),
                    "Required if yes is selected for either 'current' or 'previous'.");

            }
            elseif ($key == "q12_additional_2")
            {
                $org_key="q12";
                $group[] =& $this->form->createElement("static", null, null, "");
                $group[] =& $this->form->createElement("static", null, null, "");
                $group[] =& $this->form->createElement("static", null, null, "");
                $group[] =& $this->createLabel($question);
                $group[] =& $this->createText($org_key . "_foods", "Foods that cause or worsen any symptoms");
                $this->XINRegisterRule(
                    $org_key . "_foods",
                    array("q12_previous{@}=={@}yes|q12_current{@}=={@}yes"),
                    "Required if yes is selected for either 'current' or 'previous'."
                );


            }
            else {
                $group[] =& $this->createSelect($key . "_previous", $question." - Previous", $yesNoOptions);
                $group[] =& $this->createSelect($key . "_current", $question." - Current (past 3 months)", $yesNoOptions);
                $group[] =& $this->createLabel($question);
                $group[] =& $this->createLabel("If yes, what foods?");
                $group[] =& $this->createText($key . "_description", "If yes, what foods?");
                $key_previous = $key . "_previous";
                $key_current = $key . "_current";
                $this->XINRegisterRule(
                    $key . "_description",
                    array("q13_previous{@}=={@}yes|q13_current{@}=={@}yes"),
                    "Required if yes is selected for either 'current' or 'previous'."
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
            "Required"
        );
        $this->form->addFormRule(array(&$this, 'UCD_GI_special_rules'));
    }
function UCD_GI_special_rules($values)
{
    $errors = array();
    $error_message = "This field should be left blank OR response in the related question should be changed.";
    $check_array = array("q12_diet_restricted_by", "q12_reasons", "q12_foods");
foreach ($check_array as $val) {
    if (($values[$val] ?? '') != '') {
        if((($values['q12_previous']?? '' )!= 'yes') && ($values['q12_current']?? '' )!= 'yes') {
               $errors[$val] = $error_message;
        }
    }
}
    if(($values['gastrointestinal_diagnosis']?? '') != '') {
        if (($values['gastrointestinal_diagnosis_given']?? '' )!= 'yes') {
            $errors['gastrointestinal_diagnosis'] = $error_message;
        }
    }
    if(($values['q13_description'] ?? '') != '') {
        if((($values['q13_previous']?? '' )!= 'yes') && ($values['q13_current']?? '' )!= 'yes') {
            $errors['q13_description'] = $error_message;
        }
    }
    if (($values['q11_description'] ?? '') != '') {
        if((($values['q11_previous']?? '' )!= 'yes') && ($values['q11_current']?? '' )!= 'yes') {
           $errors['q11_description'] = $error_message;
        }
    }

    if (($values['q7_description'] ?? '') != ''){
        if((($values['q7_previous']?? '')=='0') && ($values['q7_current']?? '' )=='0') {
        $errors['q7_description'] = $error_message;
    }
}


   return $errors;
}

}
?>
