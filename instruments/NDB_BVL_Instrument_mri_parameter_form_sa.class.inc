<?php

/**
 * This file contains the NDB_BVL_Instrument_mri_parameter_form_sa
 * class
 *
 * PHP Version 5
 *
 * @category Instrument
 * @package  Neuropsych
 * @author   Cole Zweber <colezweber@gmail.com>
 * @license  http://www.gnu.org/licenses/gpl-3.0.txt GPLv3
 * @link     https://www.github.com/aces/IBIS/
 */

/**
 * Creates the form elements for the MRI Parameter Form - School Age
 * instrument
 *
 * @category Instrument
 * @package  Neuropsych
 * @author   Cole Zweber <colezweber@gmail.com>
 * @license  http://www.gnu.org/licenses/gpl-3.0.txt GPLv3
 * @link     https://www.github.com/aces/IBIS/
 */


class NDB_BVL_Instrument_mri_parameter_form_sa extends NDB_BVL_Instrument
{
    use instrument_validator;
    var $ValidityEnabled  = false;
    var $ValidityRequired = false;

    /**
    * Sets up basic data, such as the LorisForm object, and so on.
    *
    * @param  string $commentID the CommentID identifying the data to load
    * @param  string $page      if a multipage form, the page to show
    * @return void
    * @access public
    */
    function setup($commentID, $page)
    {
        $this->formType ="XIN";
        $this->form     = new LorisForm('mri_parameter_form_sa_form');
        $this->page     = $page;            // page label (number or
        // string - used by
        // user-defined child classes)

        // set the object properties
        $this->testName = "mri_parameter_form_sa";           // test_names.Test_name
        $this->table    = 'mri_parameter_form_sa';             // name of table containing

        // data keyed by commentID
        $this->commentID = $commentID;

        //The array of dates/timestamps to convert to database dates/timestamps
        //Any LorisForm date elements must be listed here
        $this->dateTimeFields =array(
                                "Date_taken",
                                "time_enter_mri_rm",
                                "start_time",
                                "end_time",
                                "total_scan_time",
                               );

        $this->_requiredElements = array(
                                    'CommentID',
                                    'Date_taken',
                                    'Examiner',
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
    * Method to build the LorisForm object into a paged form
    *
    * @return void
    * @access private
    */
    function _setupForm()
    {
        //determine page to display
        if (preg_match(
            "/mri_parameter_form_sa(_page[0-9]+)/",
            $this->page,
            $matches
        )) {
            call_user_func(array($this, $matches[1]));
        } else {
            $this->_main();
        }
        $this->form->addFormRule(array(&$this, 'XINValidate'));
    }

    /*
     * Generates main page of the form
     *
     */
    function _main()
    {
        // Display test name
        $this->form->addElement('header', 'instrument_title', "MRI Parameter Form - School Age");
        $this->form->addElement('static', null, '<BR>');

        // Automatically adds examiner & date of administration
        $this->_addMetadataFields();
        $this->form->addElement('static', null, '<BR>');
    }

    /**
     * Generates page 1 of the form
     */
    function _page1()
    {
        // PRE-SESSION SECTION
        $this->form->addElement('header', null, "<b><i>Pre-Session</i></b><BR><BR>");

        $this->form->addElement('select', 'sedation', "Sedation?", array("" => null, "Yes" => "Yes", "No" => "No"));

        $this->form->addElement('select', 'weight', 'Weight (lbs):', range(0, 200));
        $this->form->addElement('select', 'height', 'Height (inches):', range(0, 70));
        $this->form->addElement('select', 'head_circumference', 'Head Circumference (inches):', range(0, 25));
        //$this->form->addElement('text', 'head_circumference', 'Head Circumference (inches):');

        $this->form->addElement('select', "Scanner_type", "Type of Scanner:", array("" => null, "hospital" => "Hospital", "research" => "Research", "other" => "Other"));
        $this->form->addElement("text", "Scanner_type_other", "<i>If other, specify:</i>");
        $this->XINRegisterRule("Scanner_type_other", array("Scanner_type{@}=={@}other"), "Required if 'Other' selected in previous question");

        $this->form->addElement('select', "Data_type", "Data type:", array("" => null, "subject" => "Subject", "other" => "Other"));
        $this->form->addElement("text", "Data_type_other", "<i>If other, specify:</i>");
        $this->XINRegisterRule("Data_type_other", array("Data_type{@}=={@}other"), "Required if 'Other' selected in previous question");

        $this->form->addElement('select', 'mock_scanner_training', "Did the subject receive mock scanner training?", array("" => null, "Yes" => "Yes", "No" => "No"));

        $this->form->addElement('select', 'additional_mock_training', "For follow-up scans sessions, did the subject receive additional mock training since previous attempt(s)?", array("" => null, "Yes" => "Yes", "No" => "No", 'not_applicable' => "NA"));

        $this->form->addElement('select', 'medication', "Was the child on any medication?", array("" => null, "Yes" => "Yes", "No" => "No", 'not_answered' => 'Not Answered'));
        $this->form->addElement("text", "medication_specify", "<i>If yes, specify:</i>");
        $this->XINRegisterRule("medication_specify", array("medication{@}=={@}Yes"), "Required if child is on medication.");

        $this->form->addElement("textarea", "comment_on_factors", "<i>Comments on factors that may affect scan success (sleep, diet, illness, change in Bx specialist, success with mock, etc.):</i>");
        $this->XINRegisterRule(
            "comment_on_factors",
            array("comment_on_factors{@}=={@}NEVER_REQUIRED")
        );
        $this->form->addElement('static', null, '<BR>');

        // SCAN SESSION SECTION
        $this->form->addElement('header', null, "<b><i>Scan Session Information</i></b><BR><BR>");
        $this->form->addElement("text", "MR_technologist", "MR Technologist:");
        $examiners = $this->_getExaminerNames();
        $this->form->addElement("select", "Bx_specialist", "Bx Specialist:", $examiners);

        //$this->form->addElement("text", "session_attempts", "Session #");
        $this->_displayHeadersScanSession();
        for ($i=1; $i < 6; $i++) {
            $group[] = $this->createLabel($i . ".");
            $group[] = $this->createSelect(
                "scan_done_$i",
                "",
                array(
                    null => "",
                    "yes" => "Yes",
                    "no" => "No"
                )
            );
            $this->XINRegisterRule(
                "scan_done_$i",
                array("scan_done_$i{@}=={@}NEVER_REQUIRED"),
                "Not required.",
                "scan_" . $i . "_group"
            );
            $group[] = $this->createText(
                "time_enter_mri_room_$i",
                ""
            );
            $this->XINRegisterRule(
                "time_enter_mri_room_$i",
                array("scan_done_$i{@}=={@}yes"),
                "Required if session is marked as done.",
                "scan_" . $i . "_group"
            );
           $group[] = $this->createText(
                "scan_start_time_$i",
                ""
            );
            $this->XINRegisterRule(
                "time_enter_mri_room_$i",
                array("scan_start_time_$i{@}=={@}yes"),
                "Required if session is marked as done.",
                "scan_" . $i . "_group"
            );
            $group[] = $this->createText(
                "scan_end_time_$i",
                ""
            );
            $this->XINRegisterRule(
                "time_enter_mri_room_$i",
                array("scan_end_time_$i{@}=={@}yes"),
                "Required if session is marked as done.",
                "scan_" . $i . "_group"
            );
            $group[] = $this->createSelect(
                "vit_e_right_$i",
                "",
                array(
                    null => "",
                    "yes" => "Yes",
                    "no" => "No"
                )
            );
            $this->form->addGroup(
                $group,
                "scan_" . $i . "_group",
                null,
                $this->_GUIDelimiter,
                false
            );
            unset($group);
        }

        $this->form->addElement("textarea", "overall_session_comments", "<i>Overall Session Comments:</i>");
        $this->XINRegisterRule(
            "overall_session_comments",
            array("overall_session_comments{@}=={@}NEVER_REQUIRED")
        );
        $this->form->addElement('static', null, '<BR>');

        // STRUCTURAL SECTION
        $this->form->addElement('header', null, "<b>Structural</b><BR><BR>");
        $this->form->addElement('select', 't1w_acquired', "<b>T1w acquired?</b>", array("" => null, "Yes_2" => "Yes (2)", "Yes_1" => "Yes (1)", 'none' => 'None'));
        $this->form->addElement('select', 't2w_acquired', "<b>T2w acquired?</b>", array("" => null, "Yes" => "Yes", "No" => "No"));

        $this->addLabel("<h4>$this->indent <BR><b>SNR Samples</b><BR></h4>");

        // First group of questions
        $this->form->addElement('static', null, "<i>*When determining Pass/Fail status:</i> <i> T1w Pass = Ant/Sup < 2 </i> | <i> T2w Pass = Ant/Sup < 3 </i>");

        $questions        = array(
                             "t1w_run1" => "T1w run1",
                             "t1w_run2" => "T1w run2",
                             "t2w"      => "T2w",
                            );
        $repeat_questions = array(
                             "t1w_run1_repeat" => "T1w run1 repeat",
                             "t1w_run2_repeat" => "T1w run2 repeat",
                             "t2w_repeat"      => "T2w repeat",
                            );

        // Display questions with three columns, one for anterior rating, one for superior rating, and one for a pass/fail rating. Required if preceding checkbox is filled.
        $this->_displayHeaders("questions");
        foreach ($questions as $question => $label) {
            $group[] = $this->createLabel($label);
            $group[] = $this->createText(
                $question . "_anterior",
                ""
            );
            $this->XINRegisterRule(
                $question . "_anterior",
                array($question . "_check{@}=={@}Yes"),
                "Required.",
                $question . "_group"
            );
            $group[] = $this->createSelect(
                $question . "_passfail",
                "",
                array(  
                 ''     => null,
                 'Pass' => "Pass",
                 'Fail' => "Fail",
                )
            );
            $this->XINRegisterRule(
                $question . "_passfail",
                array($question . "_passfail{@}=={@}NEVER_REQUIRED"),
                $question . "_group",
                $question . "_group"
            );
            $this->form->addGroup(
                $group,
                $question . "_group",
                null,
                $this->_GUIDelimiter,
                false
            );
            unset($group);

        }

        // Display optional repeat questions with three columns, one for anterior rating, one for superior rating, and one for a pass/fail rating.
        foreach ($repeat_questions as $question => $label) {
            $group[] = $this->createLabel($label);
            $group[] = $this->createText(
                $question . "_anterior",
                ""
            );
            $this->XINRegisterRule(
                $question . "_anterior",
                array($question . "_anterior{@}=={@}NEVER_REQUIRED"),
                $question . "_group",
                $question . "_group_repeat"
            );

            $group[] = $this->createSelect(
                $question . "_passfail",
                "",
                array(
                 ''     => null,
                 'Pass' => "Pass",
                 'Fail' => "Fail",
                )
            );
            $this->XINRegisterRule(
                $question . "_passfail",
                array($question . "_passfail{@}=={@}NEVER_REQUIRED"),
                $question . "_group",
                $question . "_group_repeat"
            );
            $this->form->addGroup(
                $group,
                $question . "_group_repeat",
                null,
                $this->_GUIDelimiter,
                false
            );
            unset($group);

        }

        // Add structural comments text area
        $this->form->addElement("textarea", "structural_comments", "<i>Structural Comments:</i>");
        $this->XINRegisterRule(
            "structural_comments",
            array("structural_comments{@}=={@}NEVER_REQUIRED")
        );
        $this->form->addElement('static', null, '<BR><BR><BR>');

        // Auto align success
        $this->form->addElement('select', 'auto_align_successful', "<h3><b><u>Was AutoAlign Successful?<b><u></h3>", array('' => null, 'Yes' => "Yes", 'No' => "No"));
        $this->form->addElement('static', null, '<i>(If failed, verify encoding direction for each run of DTI and BOLD)</i>');
        $this->form->addElement('static', null, '<BR>');

        // DTI SECTION
        $this->form->addElement('header', null, "<b>DTI</b><BR><BR>");
        $this->form->addElement('select', 'dti_sequences_acquired', "<b>DTI Sequences Acquired?<b>", array('' => null, 'complete' => "Complete", 'partial' => "Partial", 'No' => "No"));

        $this->form->addElement('static', null, '*Repeat until pass QC; run DTI in order listed<BR><BR>');
        $this->form->addElement('static', null, '<BR>');

        $this->form->addElement('advcheckbox', 'dti3_shell', "DTI 3 Shell | <i>ep2d_diff_sms2_3shell_PA_1p7</i>", null, null, array(null, "Yes"));
        $this->form->addElement('select', 'dti3_shell_attempts', "<b>Console Pass/Fail</b><BR><BR>", array(null => "", "console_pass" => "Console Pass", "console_fail" => "Console Fail"));
        $this->XINRegisterRule("dti3_shell_attempts", array("dti3_shell{@}=={@}Yes"), "Required.");
        $this->form->addElement('select', 'dti3_shell_num_attempts', "<b>Number of Attempts</b>", range(0, 10));
        $this->XINRegisterRule("dti3_shell_num_attempts", array("dti3_shell{@}=={@}Yes"), "Required.");
        $this->form->addElement('static', null, '<BR><BR>');

        $this->form->addElement('advcheckbox', '6b0', "6B0 | <i>ep2d_diff_sms2_6B0_AP_1p7</i>", null, null, array(null, "Yes"));
        $this->form->addElement('select', '6b0_attempts', "<b>Console Pass/Fail</b><BR><BR>", array(null => "", "console_pass" => "Console Pass", "console_fail" => "Console Fail"));
        $this->XINRegisterRule("6b0_attempts", array("6b0{@}=={@}Yes"), "Required.");
        $this->form->addElement('select', '6b0_num_attempts', "<b>Number of Attempts</b>", range(0, 10));
        $this->XINRegisterRule("6b0_num_attempts", array("6b0{@}=={@}Yes"), "Required.");
        $this->form->addElement('static', null, '<BR><BR>');

        $this->form->addElement('advcheckbox', 'dti2_shell', "DTI 2 Shell | <i>ep2d_diff_sms2_2shell_PA_1p7</i>", null, null, array(null, "Yes"));
        $this->form->addElement('select', 'dti2_shell_attempts', "<b>Console Pass/Fail</b><BR><BR>", array(null => "", "console_pass" => "Console Pass", "console_fail" => "Console Fail"));
        $this->XINRegisterRule("dti2_shell_attempts", array("dti2_shell{@}=={@}Yes"), "Required.");
        $this->form->addElement('select', 'dti2_shell_num_attempts', "<b>Number of Attempts</b>", range(0, 10));
        $this->XINRegisterRule("dti2_shell_num_attempts", array("dti2_shell{@}=={@}Yes"), "Required.");
        $this->form->addElement('static', null, '<BR><BR>');

        $this->form->addElement('advcheckbox', '6b0_2', "6B0 | <i>ep2d_diff_sms2_6B0_AP_1p7</i>", null, null, array(null, "Yes"));
        $this->form->addElement('select', '6b0_2_attempts', "<b>Console Pass/Fail</b><BR><BR>", array(null => "", "console_pass" => "Console Pass", "console_fail" => "Console Fail"));
        $this->XINRegisterRule("6b0_2_attempts", array("6b0_2{@}=={@}Yes"), "Required.");
        $this->form->addElement('select', '6b0_2_num_attempts', "<b>Number of Attempts</b>", range(0, 10));
        $this->XINRegisterRule("6b0_2_num_attempts", array("6b0_2{@}=={@}Yes"), "Required.");
        $this->form->addElement('static', null, '<BR><BR>');

        $this->form->addElement('advcheckbox', 'dti1_shell', "DTI 1 Shell | <i>ep2d_diff_sms2_1shell_PA_1p7</i>", null, null, array(null, "Yes"));
        $this->form->addElement('select', 'dti1_shell_attempts', "<b>Console Pass/Fail</b><BR><BR>", array(null => "", "console_pass" => "Console Pass", "console_fail" => "Console Fail"));
        $this->XINRegisterRule("dti1_shell_attempts", array("dti1_shell{@}=={@}Yes"), "Required.");
        $this->form->addElement('select', 'dti1_shell_num_attempts', "<b>Number of Attempts</b>", range(0, 10));
        $this->XINRegisterRule("dti1_shell_num_attempts", array("dti1_shell{@}=={@}Yes"), "Required.");
        $this->form->addElement('static', null, '<BR><BR>');

        // Add DTI comments text area
        $this->form->addElement("textarea", "dti_comments", "<i>DTI Comments:</i>");
        $this->XINRegisterRule(
            "dti_comments",
            array("dti_comments{@}=={@}NEVER_REQUIRED")
        );
        $this->form->addElement('static', null, '<BR>');

        // BOLD SECTION
        $this->form->addElement('header', null, "<b>BOLD</b><BR><BR>");

        $this->form->addElement('select', 'bold_sequences_acquired', "<b>Sequences Acquired?<b>", array('' => null, 'complete' => "Complete", 'partial' => "Partial", 'No' => "No"));
        $this->form->addElement('select', 'bold_number_complete', "<b># of complete series:<b>", array('' => null, '0' => "0", '1' => "1", '2' => "2", '3' => "3", '4' => "4"));
        $this->XINRegisterRule("bold_number_complete", array("bold_sequences_acquired{@}=={@}complete"), "Required if 'Complete' selected in previous question.");

        $this->form->addElement('select', 'activity_during_scan', "<b>Activity During Scan:<b>", array('' => null, 'fixation_cross' => "Fixation Cross", 'asleep' => "Asleep", 'other' => "Other"));
        $this->form->addElement("text", "scan_activity_other", "If other, specify:");
        $this->XINRegisterRule("scan_activity_other", array("activity_during_scan{@}=={@}other"), "Required if 'Other' selected in previous question");

        $this->form->addElement('static', null, '*Repeat as long as subject is able & time remains<BR><BR>');

        $this->form->addElement('advcheckbox', 'FieldMap_APinv_BOLD', "<i>FieldMap_APinv</i>", null, null, array(null, "Yes"));
        $this->form->addElement('advcheckbox', 'FieldMap_AP_BOLD', "<i>FieldMap_AP</i>", null, null, array(null, "Yes"));

        $this->form->addElement('static', null, '<BR><BR><i>*If necessary, briefly speak to each subject before each run to encourage them to hold still. Do not speak during the runs.</i><BR>');
        $this->form->addElement('static', null, '<i>*QC BOLD runs with FIRMM: if > 30% of the frames in any run are FD > 0.04, encourage the subject to hold more still & repeat the run.</i><BR><BR>');
        $this->form->addElement('static', null, '<BR>');

        $this->form->addElement('advcheckbox', 'bold_run1', "BOLD run 1 | <i>ep2d_bold_sms6_PA</i>", null, null, array(null, "Yes"));
        $this->form->addElement('select', 'bold_run1_attempts', "<b>Console Pass/Fail</b>", array(null => "", "console_pass" => "Console Pass", "console_fail" => "Console Fail"));
        $this->form->addElement('select', 'bold_run1_num_attempts', "<b>Number of Attempts</b>", range(0, 10));
        $this->XINRegisterRule("bold_run1_num_attempts", array("bold_run1{@}=={@}Yes"), "Required.");
        $this->XINRegisterRule("bold_run1_attempts", array("bold_run1{@}=={@}Yes"), "Required.");
        $this->form->addElement('select', 'bold_run1_firmm', "<b>FIRMM used?<b>", array('' => null, 'Yes' => "Yes", 'No' => "No"));
        $this->XINRegisterRule("bold_run1_firmm", array("bold_run1{@}=={@}Yes"), "Required.");
        $this->form->addElement('static', null, '<BR><BR>');

        $this->form->addElement('advcheckbox', 'bold_run2', "BOLD run 2 | <i>ep2d_bold_sms6_PA</i>", null, null, array(null, "Yes"));
        $this->form->addElement('select', 'bold_run2_attempts', "<b>Console Pass/Fail</b>", array(null => "", "console_pass" => "Console Pass", "console_fail" => "Console Fail"));
        $this->form->addElement('select', 'bold_run2_num_attempts', "<b>Number of Attempts</b>", range(0, 10));
        $this->XINRegisterRule("bold_run2_num_attempts", array("bold_run2{@}=={@}Yes"), "Required.");
        $this->XINRegisterRule("bold_run2_attempts", array("bold_run2{@}=={@}Yes"), "Required.");
        $this->form->addElement('select', 'bold_run2_firmm', "<b>FIRMM used?<b>", array('' => null, 'Yes' => "Yes", 'No' => "No"));
        $this->XINRegisterRule("bold_run2_firmm", array("bold_run2{@}=={@}Yes"), "Required.");
        $this->form->addElement('static', null, '<BR><BR>');

        $this->form->addElement('advcheckbox', 'bold_run3', "BOLD run 3 | <i>ep2d_bold_sms6_PA</i>", null, null, array(null, "Yes"));
        $this->form->addElement('select', 'bold_run3_attempts', "<b>Console Pass/Fail</b>", array(null => "", "console_pass" => "Console Pass", "console_fail" => "Console Fail"));
        $this->form->addElement('select', 'bold_run3_num_attempts', "<b>Number of Attempts</b>", range(0, 10));
        $this->XINRegisterRule("bold_run3_num_attempts", array("bold_run3{@}=={@}Yes"), "Required.");
        $this->XINRegisterRule("bold_run3_attempts", array("bold_run3{@}=={@}Yes"), "Required.");
        $this->form->addElement('select', 'bold_run3_firmm', "<b>FIRMM used?<b>", array('' => null, 'Yes' => "Yes", 'No' => "No"));
        $this->XINRegisterRule("bold_run3_firmm", array("bold_run3{@}=={@}Yes"), "Required.");
        $this->form->addElement('static', null, '<BR><BR>');

        $this->form->addElement('advcheckbox', 'bold_run4', "BOLD run 4 <i>(if needed/possible)</i>", null, null, array(null, "Yes"));
        $this->form->addElement('select', 'bold_run4_attempts', "<b>Console Pass/Fail</b>", array(null => "", "console_pass" => "Console Pass", "console_fail" => "Console Fail"));
        $this->form->addElement('select', 'bold_run4_num_attempts', "<b>Number of Attempts</b>", range(0, 10));
        $this->XINRegisterRule("bold_run4_num_attempts", array("bold_run4{@}=={@}Yes"), "Required.");
        $this->XINRegisterRule("bold_run4_attempts", array("bold_run4{@}=={@}Yes"), "Required.");
        $this->form->addElement('select', 'bold_run4_firmm', "<b>FIRMM used?<b>", array('' => null, 'Yes' => "Yes", 'No' => "No"));
        $this->XINRegisterRule("bold_run4_firmm", array("bold_run4{@}=={@}Yes"), "Required.");
        $this->form->addElement('static', null, '<BR><BR>');

        // Add BOLD comments text area
        $this->form->addElement("textarea", "bold_comments", "<i>BOLD Comments:</i>");
        $this->XINRegisterRule(
            "bold_comments",
            array("bold_comments{@}=={@}NEVER_REQUIRED")
        );
        $this->form->addElement('static', null, '<b>*If the subject leaves scanner, or moves a lot, restart from the beginning of failed section (include localizers).</b>');
        $this->form->addElement('static', null, '<BR>');

        // POST SESSION SECTION
        $this->form->addElement('header', null, "<b><i>Post-Session</i></b><BR><BR>");
        $this->form->addElement('select', 'overall_success', "<b>Overall Scan Success</b> - to be completed following final scan session", array("" => null, 'complete_protocol_acquired' => "Complete protocol acquired", 'partial_protocol_acquired' => "Partial protocol acquired", 'acquired_but_possibly_not_usable' => "Complete/partial acquired but may not be usable", 'none_of_protocol_acquired' => "None of protocol acquired"));
        $this->form->addElement('select', 'if_none_partial_unusable', "<i>If none/partial/unusable:</i>", array("" => null, 'unable_to_stay_still' => "Subject unable to stay still", 'subject_refused' => "Subject refused", 'family_canceled' => "Family canceled", 'out_of_time' => "Ran out of time", 'scanner_issues' => "Scanner issues", 'family_declined' => "Family declined second attempt"));
        $this->XINRegisterRule("if_none_partial_unusable", array("overall_success{@}!={@}complete_protocol_acquired"), "Required if complete protocol was not acquired");

        $this->form->addFormRule(array(&$this, 'validate_page1'));
        $this->form->addFormRule(array(&$this, 'specialRules'));

        // Creates array of all checkbox questions for use in following XIN rule
        $checkboxquestions = array(
                              'dti3_shell',
                              '6b0',
                              'dti2_shell',
                              '6b0_2',
                              'dti1_shell',
                              'FieldMap_APinv_BOLD',
                              'FieldMap_AP_BOLD',
                              'bold_run1',
                              'bold_run2',
                              'bold_run3',
                              'bold_run4',
                             );

        // Makes checkbox questions not required
        foreach ($checkboxquestions as $check) {
            $this->XINRegisterRule(
                $check,
                array("check{@}=={@}NEVER_REQUIRED")
            );
        }

    }
    // End setupForm

    /**
     * Prevents contradictory text field entry
     */
    function specialRules($values)
    {
        $errors        = array();
        $error_message = "This field should be left blank if the previous field answer is not 'Other'.";
        if ($values['Scanner_type'] != 'other') {
            if ($values['Scanner_type_other'] != '') {
                $errors['Scanner_type_other'] = $error_message;
            }
        }
        if ($values['Data_type'] != 'other') {
            if ($values['Data_type_other'] != '') {
                $errors['Data_type_other'] = $error_message;
            }
        }
        if ($values['medication'] != 'Yes') {
            if ($values['medication_specify'] != '') {
                $errors['medication_specify'] = "This field should be left blank if the previous field answer is not 'Yes'.";
            }
        }
        return $errors;
    }

    /**
     * Numeric validations for appropriate questions
     */
    function validate_page1($values)
    {
        $errors = [];
        $this->validate_numeric($values, "weight", $errors, 0, 500);
        $this->validate_numeric($values, "height", $errors, 0, 100);
        $this->validate_numeric($values, "head_circumference", $errors, 0, 50);
        $this->validate_numeric($values, "session_attempts", $errors, 0, 20);
        $this->validate_numeric($values, "total_number_scans", $errors, 0, 50);
        $this->validate_numeric($values, "total_attempts_t1w", $errors, 0, 10);
        $this->validate_numeric($values, "total_attempts_t2w", $errors, 0, 10);
        $this->validate_numeric($values, "total_attempts_dti", $errors, 0, 10);
        $this->validate_numeric($values, "total_attempts_bold", $errors, 0, 10);
        return $errors;
    }

    /**
     * Displays headers for column section
     */
    function _displayHeaders($category)
    {
            $group[] = $this->form->createElement(
                "static",
                null,
                null,
                ""
            );
            $group[] = $this->form->createElement(
                "static",
                null,
                null,
                "<b>Anterior</b>"
            );
            $group[] = $this->form->createElement(
                "static",
                 null,
                 null,
                 "<b>Console Pass/Fail"
            );
            $this->form->addGroup(
                $group,
                $category . "_group",
                null,
                $this->_GUIDelimiter,
                false
            );
            unset($group);
    }

    function _displayHeadersScanSession() {
        $group[] = $this->form->createElement(
            "static",
            null,
            null,
            ""
        );
        $group[] = $this->form->createElement(
            "static",
            null,
            null,
            "<b>Session Done<b>"
        );
        $group[] = $this->form->createElement(
            "static",
            null,
            null,
            "<b>Time Enter MRI Room<b>"
        );
        $group[] = $this->form->createElement(
            "static",
            null,
            null,
            "<b>Scan Start Time</b>"
        );
        $group[] = $this->form->createElement(
            "static",
            null,
            null,
            "<b>Scan End Time</b>"
        );
        $group[] = $this->form->createElement(
            "static",
            null,
            null,
            "<b>Vit E (Sbj Right)<b>"
        );
        $this->form->addGroup(
            $group,
            "scan_session_headers",
            null,
            $this->_GUIDelimiter,
            false
        );
        unset($group);
    }
}
?>
