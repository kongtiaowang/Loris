<?php
/*
 * This file contains the NDB_BVL_Instrument_BISQ_survey
 * class
 *
 * PHP Version 5
 *
 * @category Instrument
 * @package  Neuropsych
 * @author   sruthy.mathew@mcin.ca
 * @license  http://www.gnu.org/licenses/gpl-3.0.txt GPLv3
 * @link     https://www.github.com/aces/IBIS/
 */
/**
 * Creates the form elements for the BISQ instrument (Survey Version)
 *
 * @category Instrument
 * @package  Neuropsych
 * @author   sruthy.mathew@mcin.ca
 * @license  http://www.gnu.org/licenses/gpl-3.0.txt GPLv3
 * @link     https://www.github.com/aces/IBIS/
 */
class NDB_BVL_Instrument_BISQ_survey extends NDB_BVL_Instrument
{
	use LegacyInstrumentTrait;

       var $ValidityRequired = false;

       var $sleep_opts = array(
            "while_feeding" => "While feeding ",
            "being_rocked" => "Being rocked",
            "bed_alone" => "In bed alone",
            "bed_near_parent" => "In bed near parent",
            "not_answered" => "Not Known",
        );

    /**
     * sets up basic data, such as the LorisForm object, and so on.
     *
     * @param string $commentID the CommentID identifying the data to load
     * @param string $page if a multipage form, the page to show
     * @return void
     * @access public
     */
    function setup(?string $commentID = NULL, ?string $page = NULL): void
    {
        $this->formType = "XIN";
        $this->form = new LorisForm('BISQ_survey_form');
        $this->page = $page;            // page label (number or
        // string - used by
        // user-defined child classes)
        // set the object properties
        $this->testName = "BISQ_survey";           // test_names.Test_name
        $this->table = 'BISQ_survey';              // name of database table corresponding to instrument
        // data keyed by commentID
        $this->commentID = $commentID;
        //The array of dates/timestamps to convert to database dates/timestamps
        //Any LorisForm date elements must be listed here
        $this->dateTimeFields = array("Date_taken");
        //The array of selects with multiple answers allowed
        //Any LorisForm multiple selects must be listed here
        $this->selectMultipleElements = array("sleep_opts");
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
            "/BISQ_survey(_page[0-9]+)/",
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
    function _main()
    {
        // display test name
        $this->addHeader("Brief Infant Sleep Questionnaire (BISQ_survey)");
        $this->form->addElement('static', null, "<i><h3>*Please fill this form out with regard to your child who has enrolled in our study, NOT their older sibling with autism</i></h3>");
        $this->addBasicDate('Date_taken', 'Date of Administration', $this->dateOptions);
        $opts = array(
            null => "",
            "mother" => "Mother",
            "father" => "Father",
            "step_mother" => "Step Mother",
            "step_father" => "Step Father",
            "other" => "Other",
        );
        $this->addSelect("responder", "Responder:", $opts);
        $this->addBasicText("other_responder", $this->indent . "If Other, please specify:");
        $this->XINRegisterRule(
            "other_responder",
            array("responder{@}=={@}other"),
            "Required",
            "other_responder"
        );
        $opts1 = array(
            null => "",
            "oldest" => "Oldest",
            "middle" => "Middle",
            "youngest" => "Youngest",
            "not_answered" => "Not Known",

        );
        $this->addSelect("birth_order", "Birth order of the child:", $opts1);
        $where_opts = array(
            null => "",
            "infant_crib_seperate_room" => "Infant crib in a separate room",
            "infant_crib_parent_room" => "Infant crib in parents’ room",
            "parents_bed" => "In parents’ bed",
            "infant_crib_in_room_with_sibling" => "Infant crib in room with sibling",
            "other" => "Other",
        );
        $this->addSelect("sleeping_arrangement", "Sleeping arrangement:", $where_opts);
        $this->addBasicText("other_sleeping_arrangement", $this->indent . "If Other, please describe:");
        $this->XINRegisterRule(
            "other_sleeping_arrangement",
            array("sleeping_arrangement{@}=={@}other"),
            "Required",
            "other_sleeping_arrangement"
        );
        $pos_opts = array(
            null => "",
            "belly" => "On his/her belly ",
            "side" => "On his/her side",
            "back" => "On his/her back",
            "not_answered" => "Not Known",
        );

        $this->addSelect("sleep_position", "In what position does your child sleep most of the time?", $pos_opts);
        $this->displayHourMinElementCustom("night_sleep", "Night sleep", "How much time does your child spend in sleep during the NIGHT (between 7 in the evening and 7 in the morning)? ");
        $this->displayHourMinElementCustom("day_sleep", "Day sleep", "How much time does your child spend in sleep during the DAY (between 7 in the morning and 7 in the evening)?");
        $this->addTextElement("night_wakes_average_count","Average number of night wakings per night:");
        $this->displayHourMinElementCustom("night_wakefullness", 'Night wakefullness', "How much time during the night does your child spend in wakefulness (from 10 in the evening to 6 in the morning)? ");
        $this->displayHourMinElementCustom("time_to_put_to_sleep", "Time to put to sleep", "How long does it take to put your baby to sleep in the evening? ");

	$this->form->addElement("static", null, "How does your baby fall asleep?");
        foreach($this->sleep_opts as $sleep_optsID => $sleep_optsDescription) {
	      
	$this->form->addElement("advcheckbox", "$sleep_optsID", null, $sleep_optsDescription, null, array("not_used", "used"));
        $this->XINRegisterRule(
                "$sleep_optsID",
                array("$sleep_optsID{@}=={@}NEVER_REQUIRED"),
                "Not required"
            );
        }

        $this->displayHourMinElementCustom("when_fall_asleep", "When fall asleep", "When does your baby usually fall asleep for the night: ");
        $sleep_prob_opts = array(
         null => "",
         "belly" => " A very serious problem ",
         "side" => "A small problem",
         "back" => "Not a problem at all",
         "not_answered" => "Not Known"
        );
        $this->addSelect("is_sleep_problem", " Do you consider your child’s sleep as a problem?", $sleep_prob_opts);

	$this->form->addFormRule(array(&$this, 'customDateCheck'));
	$this->form->addFormRule(array(&$this, 'validate_main_page'));
    }

    function displayHourMinElementCustom($field, $field_label, $label)
    {
        for ($i = 0; $i < 24; $i ++) {
            $hours_options["$i"]="$i hour(s)";
        }
        for ($i = 0; $i < 60; $i+=5) {
            $min_options["$i"]="$i minutes";
        }

        $min_options['59']="59 minute(s)";

        $default_val = array(null => '');
        $hours_options=array_merge($default_val,$hours_options);
        $min_options=array_merge($default_val,$min_options);
        $group   = array();
        $group[] = $this->createSelect($field."_hours", $field_label.' hours', $hours_options);
        $group[] = $this->createSelect($field."_mins", $field_label.' minutes', $min_options);
        $group[] = $this->createSelect(
            $field."_status",
            $field_label . ' status',
            array(
                null           => '',
                "dnk"          => "Unknown",
                'not_answered' => 'Prefer not to answer',
            )
        );
        $this->addGroup($group, $field . "_group", $label, null, false);
        unset($group);
        $this->XINRegisterRule(
            $field . "_status",
            array("{$field}_hours{@}=={@}","{$field}_mins{@}=={@}"),
            "Please select one of the option if you don't want to enter the time details."
        );
        $this->XINRegisterRule(
            $field . "_hours",
            array("{$field}_status{@}=={@}","{$field}_mins{@}!={@}"),
            "Hours Required."
        );
        $this->XINRegisterRule(
            $field . "_mins",
            array("{$field}_status{@}=={@}","{$field}_hours{@}!={@}"),
            "Mins Required."
        );
    }

    function customDateCheck($values) {
	    $errors = [];
        foreach (['night_sleep', 'day_sleep', 'night_wakefullness', 'time_to_put_to_sleep', 'when_fall_asleep'] as $key) {
            if (!empty($values[$key. '_status'])) {
                if (!empty($values[$key. '_hours']) || !empty($values[$key. '_mins'])) {
                    $errors[$key. '_group'] = 'You have entered hours or minutes, you can not choose ' . ($values[$key. '_status'] == 'not_answered'? 'Prefer not to answer' : 'Unknown') . '.';
                }
            }
	}        
        return $errors;
    }

     function validate_main_page($values)
    {
	    $errors = [];
	     $nbChecked = 0;
      foreach ($this->sleep_opts as $sleep_optsID => $sleep_optsDescription) {
                if ($values["$sleep_optsID"] == 'used') {
                    $nbChecked++;
                }
            }

            if ($nbChecked == 0) {
                $errors["not_answered"] =
                    "You must check 'Not answered' if none of the choices apply or if you do not want to answer this question";
            } elseif ($nbChecked > 1 && $values["not_answered"] == 'used') {
                $errors["not_answered"] = 'If you check this box, it has to be the only one checked';
            }

         return $errors;
    }
}
