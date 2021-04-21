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
    use LegacyInstrumentTrait;

    use instrument_validator;

    var $ValidityEnabled = false;
    var $ValidityRequired = false;

    /**
     * Sets up basic data, such as the LorisForm object, and so on.
     *
     * @param string $commentID the CommentID identifying the data to load
     * @param string $page if a multipage form, the page to show
     * @return void
     * @access public
     */
    function setup(?string $commentID = NULL, ?string $page = NULL): void
    {
        $this->formType = "XIN";
        $this->form = new LorisForm('mri_parameter_form_sa_form');
        $this->page = $page;            // page label (number or
        // string - used by
        // user-defined child classes)

        // set the object properties
        $this->testName = "mri_parameter_form_sa";           // test_names.Test_name
        $this->table = 'mri_parameter_form_sa';             // name of table containing

        // data keyed by commentID
        $this->commentID = $commentID;

        //The array of dates/timestamps to convert to database dates/timestamps
        //Any LorisForm date elements must be listed here
        $this->dateTimeFields = array(
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

        $config = NDB_Config::singleton();
        $this->dateOptions = array(
            'language' => 'en',
            'format' => 'YMd',
            'minYear' => $config->getSetting('startYear'),
            'maxYear' => $config->getSetting('endYear'),
            'addEmptyOption' => true,
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
        $db =& Database::singleton();

        // Get the item scores
        $query = "SELECT * FROM $this->table WHERE CommentID='" . $this->getCommentID() . "'";
        $record = $db->pselectRow($query, array());
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

        $this->form->addElement('header', null, "Score Summary");


        //scoring column headers
        $group[] = $this->form->createElement('static', "scan_total_time", null, null);
        $group[] = $this->form->createElement('static', "t1w_run1_snr_header", null, null);
        $group[] = $this->form->createElement('static', "t1w_run2_snr_header", null, null);
        $group[] = $this->form->createElement('static', "t1w_run3_snr_header", null, null);
        $group[] = $this->form->createElement('static', "t1w_run4_snr_header", null, null);
        $group[] = $this->form->createElement('static', "t1w_run5_snr_header", null, null);
        $group[] = $this->form->createElement('static', "t1w_run6_snr_header", null, null);
        $group[] = $this->form->createElement('static', "t2w_run1_snr_header", null, null);
        $group[] = $this->form->createElement('static', "t2w_run2_snr_header", null, null);
        $group[] = $this->form->createElement('static', "t2w_run3_snr_header", null, null);
        $group[] = $this->form->createElement('static', "t2w_run4_snr_header", null, null);
        $group[] = $this->form->createElement('static', "t2w_run5_snr_header", null, null);
        $group[] = $this->form->createElement('static', "t2w_run6_snr_header", null, null);
        $this->form->addGroup($group, 'score_header_group', "<strong>Session/Scan</strong>", $this->_GUIDelimiter, FALSE);
        unset($group);


        //score fields
        $domains = array("session_1" => "Session 1", "session_2" => "Session 2", "session_3" => "Session 3",
            "session_4" => "Session 4",

        );
        $columnHeaders = array("scan_total_time" => "Scan Total Time",
            "t1w_run1_snr_header" => "T1w Run 1 SNR", "t1w_run2_snr_header" => "T1w Run 2 SNR",
            "t1w_run3_snr_header" => "T1w Run 3 SNR", "t1w_run4_snr_header" => "T1w Run 4 SNR",
            "t1w_run5_snr_header" => "T1w Run 5 SNR", "t1w_run6_snr_header" => "T1w Run 6 SNR",
            "t2w_run1_snr_header" => "T2w Run 1 SNR", "t2w_run2_snr_header" => "T2w Run 2 SNR",
            "t2w_run3_snr_header" => "T2w Run 3 SNR", "t2w_run4_snr_header" => "T2w Run 4 SNR",
            "t2w_run5_snr_header" => "T2w Run 5 SNR", "t2w_run6_snr_header" => "T2w Run 6 SNR",

        );

        foreach ($columnHeaders as $field => $label) {
            $columnHeaders[$field] .= "     ";
        }
        $this->localDefaults = array_merge($this->localDefaults, $columnHeaders);
        $count = 0;
        foreach ($domains as $field => $label) {
            $count++;
            foreach ($columnHeaders as $scoreField => $scoreLabel) {
                if ($scoreField == 'scan_total_time') {
                    $group[] = $this->form->createElement('static', "{$scoreField}_{$count}", null, null);
                } else {
                    $snr_score_col = substr("$scoreField", -20, 12);
                    if ($count == 1) {
                        $group[] = $this->form->createElement('static', "{$snr_score_col}", null, null);
                    } else {
                        $group[] = $this->form->createElement('static', "{$snr_score_col}_{$count}", null, null);
                    }
                }

            }
            $this->form->addGroup($group, "{$label}_score_group", $label, $this->_GUIDelimiter, FALSE);
            unset($group);


        }
        $this->form->addElement('static', null, '<BR>');


    }

    /**
     * Generates page 1 of the form
     */
    function _page1()
    {
        // SCAN SESSION SECTION
        $this->form->addFormRule(array(&$this, 'XINValidate'));
        $this->form->addElement('header', null, "<b><i>Scan Session Information</i></b><BR><BR>");
        $this->form->addElement("text", "MR_technologist", "MR Technologist:");
        $examiners = $this->_getExaminerNames();
        $this->form->addElement("select", "Bx_specialist", "Bx Specialist:", $examiners);

        $this->_displayHeadersScanSession();
        for ($i = 1; $i < 5; $i++) {
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
            $group[] = $this->createDate(
                "scan_date_$i",
                ""
            );
            $group[] = $this->form->createElement(
                "time",
                "time_enter_mri_room_$i"
            );
            $group[] = $this->form->createElement(
                "time",
                "scan_start_time_$i"
            );

            $group[] = $this->form->createElement(
                "time",
                "scan_end_time_$i"
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
                "scan_group_table{$i}",
                null,
                $this->_GUIDelimiter,
                false
            );
            unset($group);
            $this->XINRegisterRule(
                "scan_done_{$i}",
                array("scan_done_{$i}{@}=={@}NEVER_REQUIRED"), // rule
                "Not Required.", // message
                "scan_group_table{$i}" // group [if field is a part of a group]
            );
            $this->XINRegisterRule(
                "scan_date_$i",
                array("scan_done_$i{@}=={@}yes"),
                "All fields are required if corresponding session is marked as done.",
                "scan_group_table{$i}"
            );
            $this->XINRegisterRule(
                "time_enter_mri_room_$i",
                array("scan_done_$i{@}=={@}yes"),
                "All fields are required if corresponding session is marked as done.",
                "scan_group_table{$i}"
            );
            $this->XINRegisterRule(
                "scan_start_time_$i",
                array("scan_done_$i{@}=={@}yes"),
                "All fields are required if corresponding session is marked as done.",
                "scan_group_table{$i}"
            );
            $this->XINRegisterRule(
                "vit_e_right_$i",
                array("scan_done_$i{@}=={@}yes"),
                "All fields are required if corresponding session is marked as done.",
                "scan_group_table{$i}"
            );

            $this->XINRegisterRule(
                "scan_end_time_$i",
                array("scan_done_$i{@}=={@}yes"),
                "All fields are required if corresponding session is marked as done.",
                "scan_group_table{$i}"
            );

        }

        $this->form->addElement("textarea", "overall_session_comments", "<i>Overall Session Comments:</i>");
        $this->XINRegisterRule(
            "overall_session_comments",
            array("overall_session_comments{@}=={@}NEVER_REQUIRED")
        );


    }

    function _page2()
    {
        //Session Page 1

        // PRE-SESSION SECTION
        $check_page_done = $this->checkPageDone(1);

        if ($this->scanDoneCount() >= 1 && $check_page_done == 0) {
            $this->form->addElement('header', null, "<b><font color='Black'><i><h3>NOTE: *Please <b>ENTER</b> the information below as you have Session 1 Done</h3></i></h4></font></u><BR>");
        } else if ($this->scanDoneCount() >= 1 && $check_page_done != 0) {

        } else {
            $this->form->addElement('header', null, "<b><font color='black'><i><h3>NOTE: *You can <b>SKIP</b> this page as you have no information on Session 1</h3></i></h4></font></u><BR>");
        }
        $this->form->addElement('header', null, "<b><u>Session Info 1:</u></b><BR>");

        $this->form->addElement('header', null, "<b><i>Pre-Session</i></b><BR><BR>");

        $this->form->addElement('select', 'sedation', "Sedation?", array("" => null, "Yes" => "Yes", "No" => "No"));

        $this->form->addElement('text', 'weight', 'Weight:');
        $this->form->addElement('select', 'weight_units', 'Weight units:', array("" => null, "pounds" => "pounds", "kilograms" => "kilograms"));
        $this->form->addElement('text', 'height', 'Height:');
        $this->form->addElement('select', 'height_units', 'Height units:', array("" => null, "inches" => "inches", "centimeters" => "cm"));
        $this->form->addElement('text', 'head_circumference', "Head Circumference:<br><i>(Please enter a numeric value between 0-100 or select 'NA' below)</i>");
        $this->XINRegisterRule("head_circumference", array("head_circumference{@}=={@}NEVER_REQUIRED"));
        $this->addSelect('head_circumference_units', 'Head Circumference units:', array("" => null, "inches" => "inches", "centimeters" => "cm", "NA" => "NA"));

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


        // STRUCTURAL SECTION
        $this->form->addElement('header', null, "<b>Structural</b><BR><BR>");
        $this->form->addElement('select', 't1w_acquired', "<b>T1w acquired?</b>", array("" => null, "Yes_2" => 'At least 2 T1s acquired', "Yes_1" => 'Only one T1 acquired', 'none' => 'No T1 acquired'));
        $this->form->addElement('select', 't1w_num_attempts', "Total number of T1w runs and/or attempts", range(0, 10));
        $this->form->addElement('select', 't2w_acquired', "<b>T2w acquired?</b>", array("" => null, "Yes" => "Yes", "No" => "No"));
        $this->form->addElement('select', 't2w_num_attempts', "Total number of T2w runs and/or attempts", range(0, 10));


        $this->addLabel("<h4>$this->indent <BR><b>SNR Samples</b><BR></h4>");

        // First group of questions
        $this->form->addElement('static', null, "<i>*When determining Pass/Fail status:</i> <i> T1w Pass = Ant/Sup < 2 </i> | <i> T2w Pass = Ant/Sup < 3 </i>");

        $questions = array(
            "t1w_run1" => "T1w run1",
            "t1w_run2" => "T1w run2",
            "t1w_run3" => "T1w run3",
            "t1w_run4" => "T1w run4",
            "t1w_run5" => "T1w run5",
            "t1w_run6" => "T1w run6",
            "t2w_run1" => "T2w run1",
            "t2w_run2" => "T2w run2",
            "t2w_run3" => "T2w run3",
            "t2w_run4" => "T2w run4",
            "t2w_run5" => "T2w run5",
            "t2w_run6" => "T2w run6",
        );

        // Display questions with two columns, one for anterior/superior ratio, and one for a pass/fail rating. Required if preceding checkbox is filled.
        $this->_displayHeaders("questions");
        foreach ($questions as $question => $label) {
            $group[] = $this->createLabel($label);
            $group[] = $this->createText(
                $question . "_anterior",
                ""
            );
            $this->XINRegisterRule(
                $question . "_anterior",
                array($question . "_anterior{@}=={@}NEVER_REQUIRED"),
                $question . "_group",
                $question . "_group"
            );
            $group[] = $this->createText(
                $question . "_superior",
                ""
            );
            $this->XINRegisterRule(
                $question . "_superior",
                array($question . "_superior{@}=={@}NEVER_REQUIRED"),
                $question . "_group",
                $question . "_group"
            );
            $group[] = $this->createSelect(
                $question . "_passfail",
                "",
                array(
                    '' => null,
                    'Pass' => "Console Pass",
                    'Fail' => "Console Fail",
                )
            );
            $this->XINRegisterRule(
                $question . "_passfail",
                array($question . "_passfail{@}=={@}NEVER_REQUIRED"),
                $question . "_group",
                $question . "_group"
            );
            $group[] = $this->createSelect(
                $question . "_facemask",
                "",
                array(
                    '' => null,
                    'yes' => "Yes",
                    'no' => "No",
                )
            );
            $this->XINRegisterRule(
                $question . "_facemask",
                array($question . "_facemask{@}=={@}NEVER_REQUIRED"),
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

        // CMRR DTI SECTION
        $this->form->addElement('header', null, "<b>CMRR DTI</b><BR><BR>");
        $this->form->addElement('select', 'cmrr1_dti_sequences_acquired', "<b>DTI Sequences Acquired?<b>", array(null => "", "complete" => "Complete", "partial" => "Partial", "none" => "None"));

        $this->form->addElement('static', null, '*Repeat until pass QC; run DTI in order listed<BR><BR>');
        $this->form->addElement('static', null, '<BR>');

        $this->form->addElement('select', 'cmrr1_dti3_shell', "DWI 3 shell | <i>DWIcmrr_3shell_APinv</i>", array(null => "", "complete" => "Complete", "partial" => "Partial", "none" => "None"));
        $this->form->addElement('select', 'cmrr1_dti3_shell_attempts', "<b>Console Pass/Fail</b><BR><BR>", array(null => "", "console_pass" => "Console Pass", "console_fail" => "Console Fail"));
        $this->XINRegisterRule("cmrr1_dti3_shell_attempts", array("cmrr1_dti3_shell{@}=={@}complete"), "Required.");
        $this->form->addElement('select', 'cmrr1_dti3_shell_num_attempts', "<b>Number of Attempts</b>", range(0, 10));
        $this->XINRegisterRule("cmrr1_dti3_shell_num_attempts", array("cmrr1_dti3_shell{@}=={@}complete"), "Required.");
        $this->form->addElement('select', "cmrr1_dti3_shell_facemask", "Subject Wearing Face Mask?", array('' => null, 'yes' => "Yes", 'no' => "No"));
        $this->XINRegisterRule(
            "cmrr1_dti3_shell_facemask",
            array("cmrr1_dti3_shell_facemask{@}=={@}NEVER_REQUIRED")
        );
        $this->form->addElement('static', null, '<BR><BR>');

        $this->form->addElement('select', 'cmrr1_6b0', "6B0 | <i>DWIcmrr_B0_AP</i>", array(null => "", "complete" => "Complete", "partial" => "Partial", "none" => "None"));
        $this->form->addElement('select', 'cmrr1_6b0_attempts', "<b>Console Pass/Fail</b><BR><BR>", array(null => "", "console_pass" => "Console Pass", "console_fail" => "Console Fail"));
        $this->XINRegisterRule("cmrr1_6b0_attempts", array("cmrr1_6b0{@}=={@}complete"), "Required.");
        $this->form->addElement('select', 'cmrr1_6b0_num_attempts', "<b>Number of Attempts</b>", range(0, 10));
        $this->XINRegisterRule("cmrr1_6b0_num_attempts", array("cmrr1_6b0{@}=={@}complete"), "Required.");
        $this->form->addElement('select', "cmrr1_6b0_facemask", "Subject Wearing Face Mask?", array('' => null, 'yes' => "Yes", 'no' => "No"));
        $this->XINRegisterRule(
            "cmrr1_6b0_facemask",
            array("cmrr1_6b0_facemask{@}=={@}NEVER_REQUIRED")
        );
        $this->form->addElement('static', null, '<BR><BR>');

        $this->form->addElement('select', 'cmrr1_dti2_shell', "DWI 2 shell | <i>DWIcmrr_2shell_APinv</i>", array(null => "", "complete" => "Complete", "partial" => "Partial", "none" => "None"));
        $this->form->addElement('select', 'cmrr1_dti2_shell_attempts', "<b>Console Pass/Fail</b><BR><BR>", array(null => "", "console_pass" => "Console Pass", "console_fail" => "Console Fail"));
        $this->XINRegisterRule("cmrr1_dti2_shell_attempts", array("cmrr1_dti2_shell{@}=={@}complete"), "Required.");
        $this->form->addElement('select', 'cmrr1_dti2_shell_num_attempts', "<b>Number of Attempts</b>", range(0, 10));
        $this->XINRegisterRule("cmrr1_dti2_shell_num_attempts", array("cmrr1_dti2_shell{@}=={@}complete"), "Required.");
        $this->form->addElement('select', "cmrr1_dti2_shell_facemask", "Subject Wearing Face Mask?", array('' => null, 'yes' => "Yes", 'no' => "No"));
        $this->XINRegisterRule(
            "cmrr1_dti2_shell_facemask",
            array("cmrr1_dti2_shell_facemask{@}=={@}NEVER_REQUIRED")
        );
        $this->form->addElement('static', null, '<BR><BR>');

        $this->form->addElement('select', 'cmrr1_6b02', "6 B0 | <i>DWIcmrr_B0_AP</i>", array(null => "", "complete" => "Complete", "partial" => "Partial", "none" => "None"));
        $this->form->addElement('select', 'cmrr1_6b02_attempts', "<b>Console Pass/Fail</b><BR><BR>", array(null => "", "console_pass" => "Console Pass", "console_fail" => "Console Fail"));
        $this->XINRegisterRule("cmrr1_6b02_attempts", array("cmrr1_6b02{@}=={@}complete"), "Required.");
        $this->form->addElement('select', 'cmrr1_6b02_num_attempts', "<b>Number of Attempts</b>", range(0, 10));
        $this->XINRegisterRule("cmrr1_6b02_num_attempts", array("cmrr1_6b02{@}=={@}complete"), "Required.");
        $this->form->addElement('select', "cmrr1_6b02_facemask", "Subject Wearing Face Mask?", array('' => null, 'yes' => "Yes", 'no' => "No"));
        $this->XINRegisterRule(
            "cmrr1_6b02_facemask",
            array("cmrr1_6b02_facemask{@}=={@}NEVER_REQUIRED")
        );
        $this->form->addElement('static', null, '<BR><BR>');

        $this->form->addElement('select', 'cmrr1_dti1_shell', "DWI 1 shell | <i>DWIcmrr_1shell_APinv</i>", array(null => "", "complete" => "Complete", "partial" => "Partial", "none" => "None"));
        $this->form->addElement('select', 'cmrr1_dti1_shell_attempts', "<b>Console Pass/Fail</b><BR><BR>", array(null => "", "console_pass" => "Console Pass", "console_fail" => "Console Fail"));
        $this->XINRegisterRule("cmrr1_dti1_shell_attempts", array("cmrr1_dti1_shell{@}=={@}complete"), "Required.");
        $this->form->addElement('select', 'cmrr1_dti1_shell_num_attempts', "<b>Number of Attempts</b>", range(0, 10));
        $this->XINRegisterRule("cmrr1_dti1_shell_num_attempts", array("cmrr1_dti1_shell{@}=={@}complete"), "Required.");
        $this->form->addElement('select', "cmrr1_dti1_shell_facemask", "Subject Wearing Face Mask?", array('' => null, 'yes' => "Yes", 'no' => "No"));
        $this->XINRegisterRule(
            "cmrr1_dti1_shell_facemask",
            array("cmrr1_dti1_shell_facemask{@}=={@}NEVER_REQUIRED")
        );
        $this->form->addElement('static', null, '<BR><BR>');

        // Add DTI comments text area
        $this->form->addElement("textarea", "cmrr1_dti_comments", "<i>DTI Comments:</i>");
        $this->XINRegisterRule(
            "cmrr1_dti_comments",
            array("cmrr1_dti_comments{@}=={@}NEVER_REQUIRED")
        );
        $this->form->addElement('static', null, '<BR>');

        // BOLD SECTION
        $this->form->addElement('header', null, "<b>BOLD</b><BR><BR>");

        $this->form->addElement('select', 'bold_sequences_acquired', "<b>Sequences Acquired?<b>", array(null => "", 'complete' => "Complete", 'partial' => "Partial", 'none' => "None"));
        $this->form->addElement('select', 'bold_number_complete', "<b># of complete series:<b>", array(null => "", '0' => "0", '1' => "1", '2' => "2", '3' => "3", '4' => "4"));
        $this->XINRegisterRule("bold_number_complete", array("bold_sequences_acquired{@}=={@}complete"), "Required if 'Complete' selected in previous question.");

        $this->form->addElement('select', 'activity_during_scan', "<b>Activity During Scan:<b>", array('' => null, 'fixation_cross' => "Fixation Cross", 'asleep' => "Asleep", 'other' => "Other"));
        $this->form->addElement("text", "scan_activity_other", "If other, specify:");
        $this->XINRegisterRule("scan_activity_other", array("activity_during_scan{@}=={@}other"), "Required if 'Other' selected in previous question");

        $this->form->addElement('select', 'FieldMap_APinv_BOLD', "<i>FieldMap_APinv</i>", array('' => null, 'complete' => "Complete", 'partial' => "Partial", 'none' => "None"));
        $this->form->addElement('select', 'FieldMap_AP_BOLD', "<i>FieldMap_AP</i>", array('' => null, 'complete' => "Complete", 'partial' => "Partial", 'none' => "None"));

        $this->form->addElement('static', null, '<BR><BR><i>*If necessary, briefly speak to each subject before each run to encourage them to hold still. Do not speak during the runs.</i><BR>');
        $this->form->addElement('static', null, '<i>*QC BOLD runs with FIRMM: if > 30% of the frames in any run are FD > 0.04, encourage the subject to hold more still & repeat the run.</i><BR><BR>');
        $this->form->addElement('static', null, '<BR>');

        $this->form->addElement('select', 'bold_run1', "BOLD run 1 | <i>ep2d_bold_sms6_PA</i>", array(null => "", 'complete' => "Complete", 'partial' => "Partial", 'none' => "None"));
        $this->form->addElement('select', 'bold_run1_attempts', "<b>Console Pass/Fail</b>", array(null => "", "console_pass" => "Console Pass", "console_fail" => "Console Fail"));
        $this->form->addElement('select', 'bold_run1_num_attempts', "<b>Number of Attempts</b>", range(0, 10));
        $this->XINRegisterRule("bold_run1_num_attempts", array("bold_run1{@}=={@}complete"), "Required.");
        $this->XINRegisterRule("bold_run1_attempts", array("bold_run1{@}=={@}complete"), "Required.");
        $this->form->addElement('select', 'bold_run1_firmm', "<b>FIRMM used?<b>", array('' => null, 'Yes' => "Yes", 'No' => "No"));
        $this->XINRegisterRule("bold_run1_firmm", array("bold_run1{@}=={@}complete"), "Required.");
        $this->form->addElement('select', "bold_run1_facemask", "Subject Wearing Face Mask?", array('' => null, 'yes' => "Yes", 'no' => "No"));
        $this->XINRegisterRule(
            "bold_run1_facemask",
            array("bold_run1_facemask{@}=={@}NEVER_REQUIRED")
        );
        $this->form->addElement('static', null, '<BR><BR>');

        $this->form->addElement('select', 'bold_run2', "BOLD run 2 | <i>ep2d_bold_sms6_PA</i>", array(null => "", 'complete' => "Complete", 'partial' => "Partial", 'none' => "None"));
        $this->form->addElement('select', 'bold_run2_attempts', "<b>Console Pass/Fail</b>", array(null => "", "console_pass" => "Console Pass", "console_fail" => "Console Fail"));
        $this->form->addElement('select', 'bold_run2_num_attempts', "<b>Number of Attempts</b>", range(0, 10));
        $this->XINRegisterRule("bold_run2_num_attempts", array("bold_run2{@}=={@}complete"), "Required.");
        $this->XINRegisterRule("bold_run2_attempts", array("bold_run2{@}=={@}complete"), "Required.");
        $this->form->addElement('select', 'bold_run2_firmm', "<b>FIRMM used?<b>", array('' => null, 'Yes' => "Yes", 'No' => "No"));
        $this->XINRegisterRule("bold_run2_firmm", array("bold_run2{@}=={@}complete"), "Required.");
        $this->form->addElement('select', "bold_run2_facemask", "Subject Wearing Face Mask?", array('' => null, 'yes' => "Yes", 'no' => "No"));
        $this->XINRegisterRule(
            "bold_run2_facemask",
            array("bold_run2_facemask{@}=={@}NEVER_REQUIRED")
        );
        $this->form->addElement('static', null, '<BR><BR>');

        $this->form->addElement('select', 'bold_run3', "BOLD run 3 | <i>ep2d_bold_sms6_PA</i>", array(null => "", 'complete' => "Complete", 'partial' => "Partial", 'none' => "None"));
        $this->form->addElement('select', 'bold_run3_attempts', "<b>Console Pass/Fail</b>", array(null => "", "console_pass" => "Console Pass", "console_fail" => "Console Fail"));
        $this->form->addElement('select', 'bold_run3_num_attempts', "<b>Number of Attempts</b>", range(0, 10));
        $this->XINRegisterRule("bold_run3_num_attempts", array("bold_run3{@}=={@}complete"), "Required.");
        $this->XINRegisterRule("bold_run3_attempts", array("bold_run3{@}=={@}complete"), "Required.");
        $this->form->addElement('select', 'bold_run3_firmm', "<b>FIRMM used?<b>", array('' => null, 'Yes' => "Yes", 'No' => "No"));
        $this->XINRegisterRule("bold_run3_firmm", array("bold_run3{@}=={@}complete"), "Required.");
        $this->form->addElement('select', "bold_run3_facemask", "Subject Wearing Face Mask?", array('' => null, 'yes' => "Yes", 'no' => "No"));
        $this->XINRegisterRule(
            "bold_run3_facemask",
            array("bold_run3_facemask{@}=={@}NEVER_REQUIRED")
        );
        $this->form->addElement('static', null, '<BR><BR>');

        $this->form->addElement('select', 'bold_run4', "BOLD run 4 <i>(if needed/possible)</i>", array(null => "", 'complete' => "Complete", 'partial' => "Partial", 'none' => "None"));
        $this->form->addElement('select', 'bold_run4_attempts', "<b>Console Pass/Fail</b>", array(null => "", "console_pass" => "Console Pass", "console_fail" => "Console Fail"));
        $this->form->addElement('select', 'bold_run4_num_attempts', "<b>Number of Attempts</b>", range(0, 10));
        $this->XINRegisterRule("bold_run4_num_attempts", array("bold_run4{@}=={@}complete"), "Required.");
        $this->XINRegisterRule("bold_run4_attempts", array("bold_run4{@}=={@}complete"), "Required.");
        $this->form->addElement('select', 'bold_run4_firmm', "<b>FIRMM used?<b>", array('' => null, 'Yes' => "Yes", 'No' => "No"));
        $this->XINRegisterRule("bold_run4_firmm", array("bold_run4{@}=={@}complete"), "Required.");
        $this->form->addElement('select', "bold_run4_facemask", "Subject Wearing Face Mask?", array('' => null, 'yes' => "Yes", 'no' => "No"));
        $this->XINRegisterRule(
            "bold_run4_facemask",
            array("bold_run4_facemask{@}=={@}NEVER_REQUIRED")
        );
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
        $this->form->addElement('static', null, '<BR>');

        // DTI Siemens SECTION
        $this->form->addElement('header', null, "<b>Siemens DTI</b><BR><BR>");
        $this->form->addElement('select', 'siemens_dti_sequences_acquired', "<b>DTI Sequences Acquired?<b>", array(null => "", "complete" => "Complete", "partial" => "Partial", "none" => "None"));

        $this->form->addElement('static', null, '*Repeat until pass QC; run DTI in order listed<BR><BR>');
        $this->form->addElement('static', null, '<BR>');

        $this->form->addElement('select', 'siemens_dti3_shell', "DTI 3 Shell | <i>ep2d_diff_sms2_3shell_PA_1p7</i>", array(null => "", "complete" => "Complete", "partial" => "Partial", "none" => "None"));
        $this->form->addElement('select', 'siemens_dti3_shell_attempts', "<b>Console Pass/Fail</b><BR><BR>", array(null => "", "console_pass" => "Console Pass", "console_fail" => "Console Fail"));
        $this->XINRegisterRule("siemens_dti3_shell_attempts", array("siemens_dti3_shell{@}=={@}complete"), "Required.");
        $this->form->addElement('select', 'siemens_dti3_shell_num_attempts', "<b>Number of Attempts</b>", range(0, 10));
        $this->XINRegisterRule("siemens_dti3_shell_num_attempts", array("siemens_dti3_shell{@}=={@}complete"), "Required.");
        $this->form->addElement('select', "siemens_dti3_shell_facemask", "Subject Wearing Face Mask?", array('' => null, 'yes' => "Yes", 'no' => "No"));
        $this->XINRegisterRule(
            "siemens_dti3_shell_facemask",
            array("siemens_dti3_shell_facemask{@}=={@}NEVER_REQUIRED")
        );
        $this->form->addElement('static', null, '<BR><BR>');

        $this->form->addElement('select', 'siemens_6b0', "6B0 | <i>ep2d_diff_sms2_6B0_AP_1p7</i>", array(null => "", "complete" => "Complete", "partial" => "Partial", "none" => "None"));
        $this->form->addElement('select', 'siemens_6b0_attempts', "<b>Console Pass/Fail</b><BR><BR>", array(null => "", "console_pass" => "Console Pass", "console_fail" => "Console Fail"));
        $this->XINRegisterRule("siemens_6b0_attempts", array("siemens_6b0{@}=={@}complete"), "Required.");
        $this->form->addElement('select', 'siemens_6b0_num_attempts', "<b>Number of Attempts</b>", range(0, 10));
        $this->XINRegisterRule("siemens_6b0_num_attempts", array("siemens_6b0{@}=={@}complete"), "Required.");
        $this->form->addElement('select', "siemens_6b0_facemask", "Subject Wearing Face Mask?", array('' => null, 'yes' => "Yes", 'no' => "No"));
        $this->XINRegisterRule(
            "siemens_6b0_facemask",
            array("siemens_6b0_facemask{@}=={@}NEVER_REQUIRED")
        );
        $this->form->addElement('static', null, '<BR><BR>');

        $this->form->addElement('select', 'siemens_dti2_shell', "DTI 2 Shell | <i>ep2d_diff_sms2_2shell_PA_1p7</i>", array(null => "", "complete" => "Complete", "partial" => "Partial", "none" => "None"));
        $this->form->addElement('select', 'siemens_dti2_shell_attempts', "<b>Console Pass/Fail</b><BR><BR>", array(null => "", "console_pass" => "Console Pass", "console_fail" => "Console Fail"));
        $this->XINRegisterRule("siemens_dti2_shell_attempts", array("siemens_dti2_shell{@}=={@}complete"), "Required.");
        $this->form->addElement('select', 'siemens_dti2_shell_num_attempts', "<b>Number of Attempts</b>", range(0, 10));
        $this->XINRegisterRule("siemens_dti2_shell_num_attempts", array("siemens_dti2_shell{@}=={@}complete"), "Required.");
        $this->form->addElement('select', "siemens_dti2_shell_facemask", "Subject Wearing Face Mask?", array('' => null, 'yes' => "Yes", 'no' => "No"));
        $this->XINRegisterRule(
            "siemens_dti2_shell_facemask",
            array("siemens_dti2_shell_facemask{@}=={@}NEVER_REQUIRED")
        );
        $this->form->addElement('static', null, '<BR><BR>');

        $this->form->addElement('select', 'siemens_6b02', "6B0 | <i>ep2d_diff_sms2_6B0_AP_1p7</i>", array(null => "", "complete" => "Complete", "partial" => "Partial", "none" => "None"));
        $this->form->addElement('select', 'siemens_6b02_attempts', "<b>Console Pass/Fail</b><BR><BR>", array(null => "", "console_pass" => "Console Pass", "console_fail" => "Console Fail"));
        $this->XINRegisterRule("siemens_6b02_attempts", array("siemens_6b02{@}=={@}complete"), "Required.");
        $this->form->addElement('select', 'siemens_6b02_num_attempts', "<b>Number of Attempts</b>", range(0, 10));
        $this->XINRegisterRule("siemens_6b02_num_attempts", array("siemens_6b02{@}=={@}complete"), "Required.");
        $this->form->addElement('select', "siemens_6b02_facemask", "Subject Wearing Face Mask?", array('' => null, 'yes' => "Yes", 'no' => "No"));
        $this->XINRegisterRule(
            "siemens_6b02_facemask",
            array("siemens_6b02_facemask{@}=={@}NEVER_REQUIRED")
        );
        $this->form->addElement('static', null, '<BR><BR>');

        $this->form->addElement('select', 'siemens_dti1_shell', "DTI 1 Shell | <i>ep2d_diff_sms2_1shell_PA_1p7</i>", array(null => "", "complete" => "Complete", "partial" => "Partial", "none" => "None"));
        $this->form->addElement('select', 'siemens_dti1_shell_attempts', "<b>Console Pass/Fail</b><BR><BR>", array(null => "", "console_pass" => "Console Pass", "console_fail" => "Console Fail"));
        $this->XINRegisterRule("siemens_dti1_shell_attempts", array("siemens_dti1_shell{@}=={@}complete"), "Required.");
        $this->form->addElement('select', 'siemens_dti1_shell_num_attempts', "<b>Number of Attempts</b>", range(0, 10));
        $this->XINRegisterRule("siemens_dti1_shell_num_attempts", array("siemens_dti1_shell{@}=={@}complete"), "Required.");
        $this->form->addElement('select', "siemens_dti1_shell_facemask", "Subject Wearing Face Mask?", array('' => null, 'yes' => "Yes", 'no' => "No"));
        $this->XINRegisterRule(
            "siemens_dti1_shell_facemask",
            array("siemens_dti1_shell_facemask{@}=={@}NEVER_REQUIRED")
        );
        $this->form->addElement('static', null, '<BR><BR>');

        // Add DTI comments text area
        $this->form->addElement("textarea", "siemens_dti_comments", "<i>DTI Comments:</i>");
        $this->XINRegisterRule(
            "siemens_dti_comments",
            array("siemens_dti_comments{@}=={@}NEVER_REQUIRED")
        );
        $this->form->addElement('static', null, '<BR>');

        $this->form->addFormRule(array(&$this, 'validate_page2'));
    }

    function _page3()
    {
        //Session Page 2

        $this->scanPageDisplay(2);
    }

    function _page4()
    {
        //Session Page 3
        $this->scanPageDisplay(3);
    }

    function _page5()
    {
        //Session Page 4
        $this->scanPageDisplay(4);
    }

    /**
     * Numeric validations for appropriate questions
     */
    function validate_page2($values)
    {

        $errors = [];

        // If the user did not select NA in the unit section
        // ensure circumference is a float number between 0 and 100 inc.

        $this->validate_numeric_strict($values, "weight", $errors, 0, 200);
        $this->validate_numeric_strict($values, "height", $errors, 0, 200);
        if ($values['head_circumference_units'] != 'NA') {
            $this->validate_numeric_strict($values, "head_circumference", $errors, 0, 100);
        }
        // If the user selected NA in the unit section
        // ensure circumference field is empty
        elseif ($values['head_circumference'] != '') {
            $errors['head_circumference'] = 'You must leave this field blank since you answered NA below';
        }

        $questions = array(
            "t1w_run1" => "T1w run1",
            "t1w_run2" => "T1w run2",
            "t1w_run3" => "T1w run3",
            "t1w_run4" => "T1w run4",
            "t1w_run5" => "T1w run5",
            "t1w_run6" => "T1w run6",
            "t2w_run1" => "T2w run1",
            "t2w_run2" => "T2w run2",
            "t2w_run3" => "T2w run3",
            "t2w_run4" => "T2w run4",
            "t2w_run5" => "T2w run5",
            "t2w_run6" => "T2w run6",
        );

        $anterior = "_anterior";
        $superior = "_superior";
        $passfail = "_passfail";
        $facemask = "_facemask";
        $t1w_run_i = $values['t1w_num_attempts'];
        $t2w_run_i = $values['t2w_num_attempts'];

        if ($values['t1w_acquired'] == 'Yes_2') {
            if ($values['t1w_num_attempts'] < 2) {
                $errors['t1w_num_attempts'] = 'Since 2 T1s were acquired, you must select a number of attempts greater or equal to 2';
            }
        } elseif ($values['t1w_acquired'] == 'Yes_1') {
            if ($values['t1w_num_attempts'] < 1) {
                $errors['t1w_num_attempts'] = 'Since one T1 was acquired, you must select a number of attempts greater or equal to 1';
            }
        } else {
            if ($values['t1w_num_attempts'] > 0) {
                $errors['t1w_num_attempts'] = 'Since no T1s were acquired, you must select a number of attempts equal to 0';
            }
        }

        if ($values["t2w_acquired"] == 'Yes') {
            if ($values["t2w_num_attempts"] <= 0) {
                $errors["t2w_num_attempts"] = 'Since T2s were acquired, you must select a number of attempts greater or equal to 1';
            }
        } elseif ($values["t2w_acquired"] == 'No') {
            if ($values["t2w_num_attempts"] > 0) {
                $errors["t2w_num_attempts"] =
                    'Since T2s were not acquired, you must select a number of attempts equal to 0';
            }
        } else {
            $errors["t2w_acquired"] =
                'Required';
        }

        foreach ($questions as $question => $label) {
            $run_num = (int) substr($question, -1);
            if (substr($question, 0, 3 ) === "t1w") {
                if ($run_num <= $t1w_run_i) {
                    if ($values[$question . $anterior] == null ||
                        $values[$question . $anterior] == "" ||
                        $values[$question . $superior] == null ||
                        $values[$question . $superior] == "" ||
                        $values[$question . $passfail] == null ||
                        $values[$question . $passfail] == "" ||
                        $values[$question . $facemask] == null ||
                        $values[$question . $facemask] == "")
                        $errors[$question . "_group"] = "All fields of this row are required.";
                    else {
                        $this->validate_numeric_strict_group($values, $question.$anterior, $errors, 0, 100, $question."_group", "Anterior and Superior values");
                        $this->validate_numeric_strict_group($values, $question.$superior, $errors, 0, 100, $question."_group", "Anterior and Superior values");
                    }
                } else {
                    if ($values[$question . $anterior] != null ||
                        $values[$question . $anterior] != "" ||
                        $values[$question . $superior] != null ||
                        $values[$question . $superior] != "" ||
                        $values[$question . $passfail] != null ||
                        $values[$question . $passfail] != "" ||
                        $values[$question . $facemask] != null ||
                        $values[$question . $facemask] != "")
                        $errors[$question . "_group"] = "All fields of this row must be empty.";
                }
            } else {
                if ($run_num <= $t2w_run_i) {
                    if ($values[$question . $anterior] == null ||
                        $values[$question . $anterior] == "" ||
                        $values[$question . $superior] == null ||
                        $values[$question . $superior] == "" ||
                        $values[$question . $passfail] == null ||
                        $values[$question . $passfail] == "" ||
                        $values[$question . $facemask] == null ||
                        $values[$question . $facemask] == "")
                        $errors[$question . "_group"] = "All fields of this row are required.";
                    else {
                        $this->validate_numeric_strict_group($values, $question.$anterior, $errors, 0, 100, $question."_group", "Anterior and Superior values");
                        $this->validate_numeric_strict_group($values, $question.$superior, $errors, 0, 100, $question."_group", "Anterior and Superior values");
                    }
                } else {
                    if ($values[$question . $anterior] != null ||
                        $values[$question . $anterior] != "" ||
                        $values[$question . $superior] != null ||
                        $values[$question . $superior] != "" ||
                        $values[$question . $passfail] != null ||
                        $values[$question . $passfail] != "" ||
                        $values[$question . $facemask] != null ||
                        $values[$question . $facemask] != "")
                        $errors[$question . "_group"] = "All fields of this row must be empty.";
                }
            }
        }

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

    function validate_pages($values)
    {
        if ($values['page'] == 'mri_parameter_form_sa_page3') {
            $snum = 2;
        } else if ($values['page'] == 'mri_parameter_form_sa_page4') {
            $snum = 3;
        } else if ($values['page'] == 'mri_parameter_form_sa_page5') {
            $snum = 4;
        } else {
            $snum = 2;
        }
        $errors = [];


        $this->form->addFormRule(array(&$this, 'XINValidate'));

        $this->validate_numeric_strict($values, "weight_{$snum}", $errors, 0, 200);
        $this->validate_numeric_strict($values, "height_{$snum}", $errors, 0, 200);


        // If the user did not select NA in the unit section
        // ensure circumference is a float number between 0 and 100 inc.
        if ($values["head_circumference_units_{$snum}"] != 'NA') {
            $this->validate_numeric_strict($values, "head_circumference_{$snum}", $errors, 0, 100);
        }
        // If the user selected NA in the unit section
        // ensure circumference field is empty
        elseif ($values["head_circumference_units_{$snum}"] != '') {
            $errors["head_circumference_units_{$snum}"] = 'You must leave this field blank since you answered NA below';
        }

        $questions = array(
            "t1w_run1_{$snum}" => "T1w run1",
            "t1w_run2_{$snum}" => "T1w run2",
            "t1w_run3_{$snum}" => "T1w run3",
            "t1w_run4_{$snum}" => "T1w run4",
            "t1w_run5_{$snum}" => "T1w run5",
            "t1w_run6_{$snum}" => "T1w run6",
            "t2w_run1_{$snum}" => "T2w run1",
            "t2w_run2_{$snum}" => "T2w run2",
            "t2w_run3_{$snum}" => "T2w run3",
            "t2w_run4_{$snum}" => "T2w run4",
            "t2w_run5_{$snum}" => "T2w run5",
            "t2w_run6_{$snum}" => "T2w run6",
        );

        $anterior = "_anterior";
        $superior = "_superior";
        $passfail = "_passfail";
        $facemask = "_facemask";
        $t1w_run_i = $values['t1w_num_attempts_'.$snum];
        $t2w_run_i = $values['t2w_num_attempts_'.$snum];

        if ($values['t1w_acquired_'.$snum] == 'Yes_2') {
            if ($values['t1w_num_attempts_'.$snum] < 2) {
                $errors['t1w_num_attempts_'.$snum] = 'Since 2 T1s were acquired, you must select a number of attempts greater or equal to 2';
            }
        } elseif ($values['t1w_acquired_'.$snum] == 'Yes_1') {
            if ($values['t1w_num_attempts_'.$snum] < 1) {
                $errors['t1w_num_attempts_'.$snum] = 'Since one T1 was acquired, you must select a number of attempts greater or equal to 1';
            }
        } else {
            if ($values['t1w_num_attempts_'.$snum] > 0) {
                $errors['t1w_num_attempts_'.$snum] = 'Since no T1s were acquired, you must select a number of attempts equal to 0';
            }
        }

        if ($values["t2w_acquired_".$snum] == 'Yes') {
            if ($values["t2w_num_attempts_".$snum] <= 0) {
                $errors["t2w_num_attempts_".$snum] = 'Since T2s were acquired, you must select a number of attempts greater or equal to 1';
            }
        } elseif ($values["t2w_acquired_".$snum] == 'No') {
            if ($values["t2w_num_attempts_".$snum] > 0) {
                $errors["t2w_num_attempts_".$snum] =
                    'Since T2s were not acquired, you must select a number of attempts equal to 0';
            }
        } else {
            $errors["t2w_acquired_".$snum] =
                'Required';
        }

        foreach ($questions as $question => $label) {
            error_log($question);
            $run_num = (int) substr($question, -3, 1);
            error_log($run_num);
            if (substr($question, 0, 3) === "t1w") {
                error_log("t1w detected");
                if ($run_num <= $t1w_run_i) {
                    error_log($question.$anterior . ": " . $values[$question . $anterior]);
                    if ($values[$question . $anterior] == null ||
                        $values[$question . $anterior] == "" ||
                        $values[$question . $superior] == null ||
                        $values[$question . $superior] == "" ||
                        $values[$question . $passfail] == null ||
                        $values[$question . $passfail] == "" ||
                        $values[$question . $facemask] == null ||
                        $values[$question . $facemask] == "")
                        $errors[$question . "_group"] = "All fields of this row are required.";
                    else {
                        $this->validate_numeric_strict_group($values, $question.$anterior, $errors, 0, 100, $question."_group", "Anterior and Superior values");
                        $this->validate_numeric_strict_group($values, $question.$superior, $errors, 0, 100, $question."_group", "Anterior and Superior values");
                    }
                } else {
                    if ($values[$question . $anterior] != null ||
                        $values[$question . $anterior] != "" ||
                        $values[$question . $superior] != null ||
                        $values[$question . $superior] != "" ||
                        $values[$question . $passfail] != null ||
                        $values[$question . $passfail] != "" ||
                        $values[$question . $facemask] != null ||
                        $values[$question . $facemask] != "")
                        $errors[$question . "_group"] = "All fields of this row must be empty.";
                }
            } else {
                if ($run_num <= $t2w_run_i) {
                    if ($values[$question . $anterior] == null ||
                        $values[$question . $anterior] == "" ||
                        $values[$question . $superior] == null ||
                        $values[$question . $superior] == "" ||
                        $values[$question . $passfail] == null ||
                        $values[$question . $passfail] == "" ||
                        $values[$question . $facemask] == null ||
                        $values[$question . $facemask] == "")
                        $errors[$question . "_group"] = "All fields of this row are required.";
                    else {
                        $this->validate_numeric_strict_group($values, $question.$anterior, $errors, 0, 100, $question."_group", "Anterior and Superior values");
                        $this->validate_numeric_strict_group($values, $question.$superior, $errors, 0, 100, $question."_group", "Anterior and Superior values");
                    }
                } else {
                    if ($values[$question . $anterior] != null ||
                        $values[$question . $anterior] != "" ||
                        $values[$question . $superior] != null ||
                        $values[$question . $superior] != "" ||
                        $values[$question . $passfail] != null ||
                        $values[$question . $passfail] != "" ||
                        $values[$question . $facemask] != null ||
                        $values[$question . $facemask] != "")
                        $errors[$question . "_group"] = "All fields of this row must be empty.";
                }
            }
        }

        $error_message = "This field should be left blank if the previous field answer is not 'Other'.";
        if ($values["Scanner_type_{$snum}"] != "other") {
            if ($values["Scanner_type_other_{$snum}"] != "") {
                $errors["Scanner_type_other_{$snum}"] = $error_message;
            }
        }
        if ($values["Data_type_{$snum}"] != "other") {
            if ($values["Data_type_other_{$snum}"] != "") {
                $errors["Data_type_other_{$snum}"] = $error_message;
            }
        }
        if ($values["medication_{$snum}"] != "Yes") {
            if ($values["medication_specify_{$snum}"] != "") {
                $errors["medication_specify_{$snum}"] = "This field should be left blank if the previous field answer is not 'Yes'.";
            }
        }

        return $errors;
    }

    function score(): void
    {
        if ($this->_determineDataEntryCompletionStatus() == "Incomplete") {
            return;
        }

        // Get the item scores
        $db =& Database::singleton();
        $query = "SELECT * FROM " . $this->table . " WHERE CommentID=:cid";
        $record = $db->pselectRow($query, array('cid' => $this->getCommentID()));

        $scores = array();

        for ($i = 1; $i <= 5; $i++) {
            $start_time = "scan_start_time_$i";
            $end_time = "scan_end_time_$i";
            if ($record[$start_time] != NULL && $record[$end_time] != NULL) {
                $curr_total_time = "scan_total_time_$i";
                $timediff = $db->pselect("SELECT TIMEDIFF('" . $record[$end_time] . "', '" . $record[$start_time] . "')", array());
                $timediff = implode($timediff[0]);
            } else {
                $curr_total_time = "scan_total_time_$i";
                $timediff = NULL;
            }
            $scores[$curr_total_time] = $timediff;
        }

        for ($i = 1; $i <= 6; $i++) {
            $t1_curr_anterior = "t1w_run" . $i . "_anterior";
            $t1_curr_superior = "t1w_run" . $i . "_superior";
            $t1_curr_snr = "t1w_run" . $i . "_snr";
            $t2_curr_anterior = "t2w_run" . $i . "_anterior";
            $t2_curr_superior = "t2w_run" . $i . "_superior";
            $t2_curr_snr = "t2w_run" . $i . "_snr";
            error_log($record[$t1_curr_anterior] . " " . $record[$t1_curr_superior] . " " . $record[$t1_curr_snr] . " " . $record[$t2_curr_anterior] . " " . $record[$t2_curr_superior] . " " . $record[$t2_curr_snr]);
            if ($record[$t1_curr_anterior] != NULL && $record[$t1_curr_superior] != NULL) {
                try {
                    $scores[$t1_curr_snr] = number_format((floatval($record[$t1_curr_anterior]) / floatval($record[$t1_curr_superior])), 2);
                } catch (Exception $e) {
                    $scores[$t1_curr_snr] = 0.00;
                }
            }
            if ($record[$t2_curr_anterior] != NULL && $record[$t2_curr_superior] != NULL) {
                try {
                    $scores[$t2_curr_snr] = number_format((floatval($record[$t2_curr_anterior]) / floatval($record[$t2_curr_superior])), 2);
                } catch (Exception $e) {
                    $scores[$t2_curr_snr] = 0.00;
                }
            }

        }
        for ($f = 2; $f <= 4; $f++) {
            for ($g = 1; $g <= 6; $g++) {
                $t1_curr_anterior = "t1w_run" . $g . "_{$f}_anterior";
                $t1_curr_superior = "t1w_run" . $g . "_{$f}_superior";
                $t1_curr_snr = "t1w_run" . $g . "_snr_{$f}";
                $t2_curr_anterior = "t2w_run" . $g . "_{$f}_anterior";
                $t2_curr_superior = "t2w_run" . $g . "_{$f}_superior";
                $t2_curr_snr = "t2w_run" . $g . "_snr_{$f}";
                if ($record[$t1_curr_anterior] != NULL && $record[$t1_curr_superior] != NULL) {
                    try {
                        $scores[$t1_curr_snr] = number_format((floatval($record[$t1_curr_anterior]) / floatval($record[$t1_curr_superior])), 2);
                    } catch (Exception $e) {
                        $scores[$t1_curr_snr] = 0.00;
                    }
                }
                if ($record[$t2_curr_anterior] != NULL && $record[$t2_curr_superior] != NULL) {
                    try {
                        $scores[$t2_curr_snr] = number_format((floatval($record[$t2_curr_anterior]) / floatval($record[$t2_curr_superior])), 2);
                    } catch (Exception $e) {
                        $scores[$t2_curr_snr] = 0.00;
                    }
                }

            }
        }
        // save scores
        $db->update($this->table, $scores, array("CommentID" => $this->getCommentID()));
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
            "<b>Superior</b>"
        );
        $group[] = $this->form->createElement(
            "static",
            null,
            null,
            "<b>Console Pass/Fail</b>"
        );
        $group[] = $this->form->createElement(
            "static",
            null,
            null,
            "<b>Subject Wearing Face Mask?</b>"
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

    function _displayHeadersScanSession()
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
            "<b>Session Done<b>"
        );
        $group[] = $this->form->createElement(
            "static",
            null,
            null,
            "<b>Session Date<b>"
        );
        $group[] = $this->form->createElement(
            "static",
            null,
            null,
            "<b>Time Enter<br>MRI Room(HH:MM)<b>"
        );
        $group[] = $this->form->createElement(
            "static",
            null,
            null,
            "<b>Scan Start Time(HH:MM)</b>"
        );
        $group[] = $this->form->createElement(
            "static",
            null,
            null,
            "<b>Scan End Time(HH:MM)</b>"
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

    function scanPageDisplay($i)
    {

        $check_page_done = $this->checkPageDone($i);

        if ($this->scanDoneCount() >= $i && $check_page_done == 0) {
            $this->form->addElement('header', null, "<b><font color='black'><i><h3>*Please <b>ENTER</b> the information below as you have Session {$i} Done</h3></i></h4></font></u><BR>");
        } else if ($this->scanDoneCount() >= $i && $check_page_done != 0) {

        } else {
            $this->form->addElement('header', null, "<b><font color='black'><i><h3>NOTE: *You can <b>SKIP</b> this page as you have no information on Session {$i}</h3></i></h4></font></u><BR>");
        }
        $this->form->addElement('header', null, "<b><u>Session Info {$i}:</u></b><BR>");


        $this->form->addElement('header', null, "<b><i>Pre-Session</i></b><BR><BR>");

        $this->form->addElement('select', "sedation_{$i}", "Sedation?", array("" => null, "Yes" => "Yes", "No" => "No"));

        $this->form->addElement('text', "weight_{$i}", 'Weight:');
        $this->form->addElement('select', "weight_units_{$i}", 'Weight units:', array("" => null, "pounds" => "pounds", "kilograms" => "kilograms"));
        $this->form->addElement('text', "height_{$i}", 'Height:');
        $this->form->addElement('select', "height_units_{$i}", 'Height units:', array("" => null, "inches" => "inches", "centimeters" => "cm"));
        $this->form->addElement('text', "head_circumference_{$i}", "Head Circumference:<br><i>(Please enter a numeric value between 0-100 or select 'NA' below)</i>");
        $this->XINRegisterRule("head_circumference_{$i}", array("head_circumference_{$i}{@}=={@}NEVER_REQUIRED"));
        $this->addSelect("head_circumference_units_{$i}", 'Head Circumference units:', array("" => null, "inches" => "inches", "centimeters" => "cm", "NA" => "NA"));

        $this->form->addElement('select', "Scanner_type_{$i}", "Type of Scanner:", array("" => null, "hospital" => "Hospital", "research" => "Research", "other" => "Other"));
        $this->form->addElement("text", "Scanner_type_other_{$i}", "<i>If other, specify:</i>");
        $this->XINRegisterRule("Scanner_type_other_{$i}", array("Scanner_type_{$i}{@}=={@}other"), "Required if 'Other' selected in previous question");

        $this->form->addElement('select', "Data_type_{$i}", "Data type:", array("" => null, "subject" => "Subject", "other" => "Other"));
        $this->form->addElement("text", "Data_type_other_{$i}", "<i>If other, specify:</i>");
        $this->XINRegisterRule("Data_type_other_{$i}", array("Data_type_{$i}{@}=={@}other"), "Required if 'Other' selected in previous question");

        $this->form->addElement('select', "mock_scanner_training_{$i}", "Did the subject receive mock scanner training?", array("" => null, "Yes" => "Yes", "No" => "No"));

        $this->form->addElement('select', "additional_mock_training_{$i}", "For follow-up scans sessions, did the subject receive additional mock training since previous attempt(s)?", array("" => null, "Yes" => "Yes", "No" => "No", 'not_applicable' => "NA"));

        $this->form->addElement('select', "medication_{$i}", "Was the child on any medication?", array("" => null, "Yes" => "Yes", "No" => "No", 'not_answered' => 'Not Answered'));
        $this->form->addElement("text", "medication_specify_{$i}", "<i>If yes, specify:</i>");
        $this->XINRegisterRule("medication_specify_{$i}", array("medication_{$i}{@}=={@}Yes"), "Required if child is on medication.");

        $this->form->addElement("textarea", "comment_on_factors_{$i}", "<i>Comments on factors that may affect scan success (sleep, diet, illness, change in Bx specialist, success with mock, etc.):</i>");
        $this->XINRegisterRule(
            "comment_on_factors_{$i}",
            array("comment_on_factors_{$i}{@}=={@}NEVER_REQUIRED")
        );
        $this->form->addElement('static', null, '<BR>');


        // STRUCTURAL SECTION
        $this->form->addElement('header', null, "<b>Structural</b><BR><BR>");
        $this->form->addElement('select', "t1w_acquired_{$i}", "<b>T1w acquired?</b>", array("" => null, "Yes_2" => 'At least 2 T1s acquired', "Yes_1" => 'Only one T1 acquired', 'none' => 'No T1 acquired'));
        $this->form->addElement('select', "t1w_num_attempts_{$i}", "Total number of T1w runs and/or attempts", range(0, 10));
        $this->form->addElement('select', "t2w_acquired_{$i}", "<b>T2w acquired?</b>", array("" => null, "Yes" => "Yes", "No" => "No"));
        $this->form->addElement('select', "t2w_num_attempts_{$i}", "Total number of T2w runs and/or attempts", range(0, 10));


        $this->addLabel("<h4>$this->indent <BR><b>SNR Samples</b><BR></h4>");

        // First group of questions
        $this->form->addElement('static', null, "<i>*When determining Pass/Fail status:</i> <i> T1w Pass = Ant/Sup < 2 </i> | <i> T2w Pass = Ant/Sup < 3 </i>");

        $questions = array(
            "t1w_run1_{$i}" => "T1w run1",
            "t1w_run2_{$i}" => "T1w run2",
            "t1w_run3_{$i}" => "T1w run3",
            "t1w_run4_{$i}" => "T1w run4",
            "t1w_run5_{$i}" => "T1w run5",
            "t1w_run6_{$i}" => "T1w run6",
            "t2w_run1_{$i}" => "T2w run1",
            "t2w_run2_{$i}" => "T2w run2",
            "t2w_run3_{$i}" => "T2w run3",
            "t2w_run4_{$i}" => "T2w run4",
            "t2w_run5_{$i}" => "T2w run5",
            "t2w_run6_{$i}" => "T2w run6",
        );

        // Display questions with two columns, one for anterior/superior ratio, and one for a pass/fail rating. Required if preceding checkbox is filled.
        $this->_displayHeaders("questions");
        foreach ($questions as $question => $label) {
            $group[] = $this->createLabel($label);
            $group[] = $this->createText(
                $question . "_anterior",
                ""
            );
            $this->XINRegisterRule(
                $question . "_anterior",
                array($question . "_anterior{@}=={@}NEVER_REQUIRED"),
                $question . "_group",
                $question . "_group"
            );
            $group[] = $this->createText(
                $question . "_superior",
                ""
            );
            $this->XINRegisterRule(
                $question . "_superior",
                array($question . "_superior{@}=={@}NEVER_REQUIRED"),
                $question . "_group",
                $question . "_group"
            );
            $group[] = $this->createSelect(
                $question . "_passfail",
                "",
                array(
                    '' => null,
                    'Pass' => "Console Pass",
                    'Fail' => "Console Fail",
                )
            );
            $this->XINRegisterRule(
                $question . "_passfail",
                array($question . "_passfail{@}=={@}NEVER_REQUIRED"),
                $question . "_group",
                $question . "_group"
            );
            $group[] = $this->createSelect(
                $question . "_facemask",
                "",
                array(
                    '' => null,
                    'yes' => "Yes",
                    'no' => "No",
                )
            );
            $this->XINRegisterRule(
                $question . "_facemask",
                array($question . "_facemask{@}=={@}NEVER_REQUIRED"),
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

        // Add structural comments text area
        $this->form->addElement("textarea", "structural_comments_{$i}", "<i>Structural Comments:</i>");
        $this->XINRegisterRule(
            "structural_comments_{$i}",
            array("structural_comments_{$i}{@}=={@}NEVER_REQUIRED")
        );
        $this->form->addElement('static', null, '<BR><BR><BR>');

        // Auto align success
        $this->form->addElement('select', "auto_align_successful_{$i}", "<h3><b><u>Was AutoAlign Successful?<b><u></h3>", array('' => null, 'Yes' => "Yes", 'No' => "No"));
        $this->form->addElement('static', null, '<i>(If failed, verify encoding direction for each run of DTI and BOLD)</i>');
        $this->form->addElement('static', null, '<BR>');

        // CMRR DTI SECTION
        $this->form->addElement('header', null, "<b>CMRR DTI</b><BR><BR>");
        $this->form->addElement('select', "cmrr{$i}_dti_sequences_acquired_{$i}", "<b>DTI Sequences Acquired?<b>", array(null => "", "complete" => "Complete", "partial" => "Partial", "none" => "None"));

        $this->form->addElement('static', null, '*Repeat until pass QC; run DTI in order listed<BR><BR>');
        $this->form->addElement('static', null, '<BR>');

        $this->form->addElement('select', "cmrr{$i}_dti3_shell_{$i}", "DTI 3 Shell | <i>ep2d_diff_sms2_3shell_PA_1p7</i>", array(null => "", "complete" => "Complete", "partial" => "Partial", "none" => "None"));
        $this->form->addElement('select', "cmrr{$i}_dti3_shell_attempts_{$i}", "<b>Console Pass/Fail</b><BR><BR>", array(null => "", "console_pass" => "Console Pass", "console_fail" => "Console Fail"));
        $this->XINRegisterRule("cmrr{$i}_dti3_shell_attempts_{$i}", array("cmrr{$i}_dti3_shell_{$i}{@}=={@}complete"), "Required.");
        $this->form->addElement('select', "cmrr{$i}_dti3_shell_num_attempts_{$i}", "<b>Number of Attempts</b>", range(0, 10));
        $this->XINRegisterRule("cmrr{$i}_dti3_shell_num_attempts{$i}", array("cmrr{$i}_dti3_shell_{$i}{@}=={@}complete"), "Required.");
        $this->form->addElement('select', "cmrr{$i}_dti3_shell_{$i}_facemask_{$i}", "Subject Wearing Face Mask?", array('' => null, 'yes' => "Yes", 'no' => "No"));
        $this->XINRegisterRule(
            "cmrr{$i}_dti3_shell_{$i}_facemask_{$i}",
            array("cmrr{$i}_dti3_shell_{$i}_facemask_{$i}{@}=={@}NEVER_REQUIRED")
        );
        $this->form->addElement('static', null, '<BR><BR>');

        $this->form->addElement('select', "cmrr{$i}_6b0_{$i}", "6B0 | <i>ep2d_diff_sms2_6B0_AP_1p7</i>", array(null => "", "complete" => "Complete", "partial" => "Partial", "none" => "None"));
        $this->form->addElement('select', "cmrr{$i}_6b0_attempts_{$i}", "<b>Console Pass/Fail</b><BR><BR>", array(null => "", "console_pass" => "Console Pass", "console_fail" => "Console Fail"));
        $this->XINRegisterRule("cmrr{$i}_6b0_attempts_{$i}", array("cmrr{$i}_6b0_{$i}{@}=={@}complete"), "Required.");
        $this->form->addElement('select', "cmrr{$i}_6b0_num_attempts_{$i}", "<b>Number of Attempts</b>", range(0, 10));
        $this->XINRegisterRule("cmrr{$i}_6b0_num_attempts_{$i}", array("cmrr{$i}_6b0_{$i}{@}=={@}complete"), "Required.");
        $this->form->addElement('select', "cmrr{$i}_6b0_{$i}_facemask_{$i}", "Subject Wearing Face Mask?", array('' => null, 'yes' => "Yes", 'no' => "No"));
        $this->XINRegisterRule(
            "cmrr{$i}_6b0_{$i}_facemask_{$i}",
            array("cmrr{$i}_6b0_{$i}_facemask_{$i}{@}=={@}NEVER_REQUIRED")
        );
        $this->form->addElement('static', null, '<BR><BR>');

        $this->form->addElement('select', "cmrr{$i}_dti2_shell_{$i}", "DWI 2 shell | <i>DWIcmrr_2shell_APinv</i>", array(null => "", "complete" => "Complete", "partial" => "Partial", "none" => "None"));
        $this->form->addElement('select', "cmrr{$i}_dti2_shell_attempts_{$i}", "<b>Console Pass/Fail</b><BR><BR>", array(null => "", "console_pass" => "Console Pass", "console_fail" => "Console Fail"));
        $this->XINRegisterRule("cmrr{$i}_dti2_shell_attempts_{$i}", array("cmrr{$i}_dti2_shell_{$i}{@}=={@}complete"), "Required.");
        $this->form->addElement('select', "cmrr{$i}_dti2_shell_num_attempts_{$i}", "<b>Number of Attempts</b>", range(0, 10));
        $this->XINRegisterRule("cmrr{$i}_dti2_shell_num_attempts_{$i}", array("cmrr{$i}_dti2_shell_{$i}{@}=={@}complete"), "Required.");
        $this->form->addElement('select', "cmrr{$i}_dti2_shell_{$i}_facemask_{$i}", "Subject Wearing Face Mask?", array('' => null, 'yes' => "Yes", 'no' => "No"));
        $this->XINRegisterRule(
            "cmrr{$i}_dti2_shell_{$i}_facemask_{$i}",
            array("cmrr{$i}_dti2_shell_{$i}_facemask_{$i}{@}=={@}NEVER_REQUIRED")
        );
        $this->form->addElement('static', null, '<BR><BR>');

        $this->form->addElement('select', "cmrr{$i}_6b02_{$i}", "6 B0 | <i>DWIcmrr_B0_AP</i>", array(null => "", "complete" => "Complete", "partial" => "Partial", "none" => "None"));
        $this->form->addElement('select', "cmrr{$i}_6b02_attempts_{$i}", "<b>Console Pass/Fail</b><BR><BR>", array(null => "", "console_pass" => "Console Pass", "console_fail" => "Console Fail"));
        $this->XINRegisterRule("cmrr{$i}_6b02_attempts_{$i}", array("cmrr{$i}_6b02_{$i}{@}=={@}complete"), "Required.");
        $this->form->addElement('select', "cmrr{$i}_6b02_num_attempts_{$i}", "<b>Number of Attempts</b>", range(0, 10));
        $this->XINRegisterRule("cmrr{$i}_6b02_num_attempts_{$i}", array("cmrr{$i}_6b02_{$i}{@}=={@}complete"), "Required.");
        $this->form->addElement('select', "cmrr{$i}_6b02_{$i}_facemask_{$i}", "Subject Wearing Face Mask?", array('' => null, 'yes' => "Yes", 'no' => "No"));
        $this->XINRegisterRule(
            "cmrr{$i}_6b02_{$i}_facemask_{$i}",
            array("cmrr{$i}_6b02_{$i}_facemask_{$i}{@}=={@}NEVER_REQUIRED")
        );
        $this->form->addElement('static', null, '<BR><BR>');

        $this->form->addElement('select', "cmrr{$i}_dti1_shell_{$i}", "DWI 1 shell | <i>DWIcmrr_1shell_APinv</i>", array(null => "", "complete" => "Complete", "partial" => "Partial", "none" => "None"));
        $this->form->addElement('select', "cmrr{$i}_dti1_shell_attempts_{$i}", "<b>Console Pass/Fail</b><BR><BR>", array(null => "", "console_pass" => "Console Pass", "console_fail" => "Console Fail"));
        $this->XINRegisterRule("cmrr{$i}_dti1_shell_attempts_{$i}", array("cmrr{$i}_dti1_shell_{$i}{@}=={@}complete"), "Required.");
        $this->form->addElement('select', "cmrr{$i}_dti1_shell_num_attempts_{$i}", "<b>Number of Attempts</b>", range(0, 10));
        $this->XINRegisterRule("cmrr{$i}_dti1_shell_num_attempts_{$i}", array("cmrr{$i}_dti1_shell_{$i}{@}=={@}complete"), "Required.");
        $this->form->addElement('select', "cmrr{$i}_dti1_shell_{$i}_facemask_{$i}", "Subject Wearing Face Mask?", array('' => null, 'yes' => "Yes", 'no' => "No"));
        $this->XINRegisterRule(
            "cmrr{$i}_dti1_shell_{$i}_facemask_{$i}",
            array("cmrr{$i}_dti1_shell_{$i}_facemask_{$i}{@}=={@}NEVER_REQUIRED")
        );
        $this->form->addElement('static', null, '<BR><BR>');

        // Add DTI comments text area
        $this->form->addElement("textarea", "cmrr{$i}_dti_comments_{$i}", "<i>DTI Comments:</i>");
        $this->XINRegisterRule(
            "cmrr{$i}_dti_comments_{$i}",
            array("cmrr{$i}_dti_comments_{$i}{@}=={@}NEVER_REQUIRED")
        );
        $this->form->addElement("static", null, "<BR>");

        // BOLD SECTION
        $this->form->addElement("header", null, "<b>BOLD</b><BR><BR>");

        $this->form->addElement("select", "bold_sequences_acquired_{$i}", "<b>Sequences Acquired?<b>", array(null => "", "complete" => "Complete", "partial" => "Partial", "none" => "None"));
        $this->form->addElement("select", "bold_number_complete_{$i}", "<b># of complete series:<b>", array(null => "", "0" => "0", "1" => "1", "2" => "2", "3" => "3", "4" => "4"));
        $this->XINRegisterRule("bold_number_complete_{$i}", array("bold_sequences_acquired_{$i}{@}=={@}complete"), "Required if \"Complete\" selected in previous question.");

        $this->form->addElement("select", "activity_during_scan_{$i}", "<b>Activity During Scan:<b>", array("" => null, "fixation_cross" => "Fixation Cross", "asleep" => "Asleep", "other" => "Other"));
        $this->form->addElement("text", "scan_activity_other_{$i}", "If other, specify:");
        $this->XINRegisterRule("scan_activity_other_{$i}", array("activity_during_scan_{$i}{@}=={@}other"), "Required if \"Other\" selected in previous question");

        $this->form->addElement("select", "FieldMap_APinv_BOLD_{$i}", "<i>FieldMap_APinv</i>", array("" => null, "complete" => "Complete", "partial" => "Partial", "none" => "None"));
        $this->form->addElement("select", "FieldMap_AP_BOLD_{$i}", "<i>FieldMap_AP</i>", array("" => null, "complete" => "Complete", "partial" => "Partial", "none" => "None"));

        $this->form->addElement("static", null, "<BR><BR><i>*If necessary, briefly speak to each subject before each run to encourage them to hold still. Do not speak during the runs.</i><BR>");
        $this->form->addElement("static", null, "<i>*QC BOLD runs with FIRMM: if > 30% of the frames in any run are FD > 0.04, encourage the subject to hold more still & repeat the run.</i><BR><BR>");
        $this->form->addElement("static", null, "<BR>");

        $this->form->addElement("select", "bold_run1_{$i}", "BOLD run 1 | <i>ep2d_bold_sms6_PA</i>", array(null => "", "complete" => "Complete", "partial" => "Partial", "none" => "None"));
        $this->form->addElement("select", "bold_run1_attempts_{$i}", "<b>Console Pass/Fail</b>", array(null => "", "console_pass" => "Console Pass", "console_fail" => "Console Fail"));
        $this->form->addElement("select", "bold_run1_num_attempts_{$i}", "<b>Number of Attempts</b>", range(0, 10));
        $this->XINRegisterRule("bold_run1_num_attempts_{$i}", array("bold_run1_{$i}{@}=={@}Yes"), "Required.");
        $this->XINRegisterRule("bold_run1_attempts_{$i}", array("bold_run1_{$i}{@}=={@}Yes"), "Required.");
        $this->form->addElement("select", "bold_run1_firmm_{$i}", "<b>FIRMM used?<b>", array("" => null, "Yes" => "Yes", "No" => "No"));
        $this->XINRegisterRule("bold_run1_firmm_{$i}", array("bold_run1_{$i}{@}=={@}Yes"), "Required.");
        $this->form->addElement('select', "bold_run1_{$i}_facemask_{$i}", "Subject Wearing Face Mask?", array('' => null, 'yes' => "Yes", 'no' => "No"));
        $this->XINRegisterRule(
            "bold_run1_{$i}_facemask_{$i}",
            array("bold_run1_{$i}_facemask_{$i}{@}=={@}NEVER_REQUIRED")
        );
        $this->form->addElement("static", null, "<BR><BR>");

        $this->form->addElement("select", "bold_run2_{$i}", "BOLD run 2 | <i>ep2d_bold_sms6_PA</i>", array(null => "", "complete" => "Complete", "partial" => "Partial", "none" => "None"));
        $this->form->addElement("select", "bold_run2_attempts_{$i}", "<b>Console Pass/Fail</b>", array(null => "", "console_pass" => "Console Pass", "console_fail" => "Console Fail"));
        $this->form->addElement("select", "bold_run2_num_attempts_{$i}", "<b>Number of Attempts</b>", range(0, 10));
        $this->XINRegisterRule("bold_run2_num_attempts_{$i}", array("bold_run2_{$i}{@}=={@}Yes"), "Required.");
        $this->XINRegisterRule("bold_run2_attempts_{$i}", array("bold_run2_{$i}{@}=={@}Yes"), "Required.");
        $this->form->addElement("select", "bold_run2_firmm_{$i}", "<b>FIRMM used?<b>", array("" => null, "Yes" => "Yes", "No" => "No"));
        $this->XINRegisterRule("bold_run2_firmm_{$i}", array("bold_run2_{$i}{@}=={@}Yes"), "Required.");
        $this->form->addElement('select', "bold_run2_{$i}_facemask_{$i}", "Subject Wearing Face Mask?", array('' => null, 'yes' => "Yes", 'no' => "No"));
        $this->XINRegisterRule(
            "bold_run2_{$i}_facemask_{$i}",
            array("bold_run2_{$i}_facemask_{$i}{@}=={@}NEVER_REQUIRED")
        );
        $this->form->addElement("static", null, "<BR><BR>");

        $this->form->addElement("select", "bold_run3_{$i}", "BOLD run 3 | <i>ep2d_bold_sms6_PA</i>", array(null => "", "complete" => "Complete", "partial" => "Partial", "none" => "None"));
        $this->form->addElement("select", "bold_run3_attempts_{$i}", "<b>Console Pass/Fail</b>", array(null => "", "console_pass" => "Console Pass", "console_fail" => "Console Fail"));
        $this->form->addElement("select", "bold_run3_num_attempts_{$i}", "<b>Number of Attempts</b>", range(0, 10));
        $this->XINRegisterRule("bold_run3_num_attempts_{$i}", array("bold_run3_{$i}{@}=={@}Yes"), "Required.");
        $this->XINRegisterRule("bold_run3_attempts_{$i}", array("bold_run3_{$i}{@}=={@}Yes"), "Required.");
        $this->form->addElement("select", "bold_run3_firmm_{$i}", "<b>FIRMM used?<b>", array("" => null, "Yes" => "Yes", "No" => "No"));
        $this->XINRegisterRule("bold_run3_firmm_{$i}", array("bold_run3_{$i}{@}=={@}Yes"), "Required.");
        $this->form->addElement('select', "bold_run3_{$i}_facemask_{$i}", "Subject Wearing Face Mask?", array('' => null, 'yes' => "Yes", 'no' => "No"));
        $this->XINRegisterRule(
            "bold_run3_{$i}_facemask_{$i}",
            array("bold_run3_{$i}_facemask_{$i}{@}=={@}NEVER_REQUIRED")
        );
        $this->form->addElement("static", null, "<BR><BR>");

        $this->form->addElement("select", "bold_run4_{$i}", "BOLD run 4 <i>(if needed/possible)</i>", array(null => "", "complete" => "Complete", "partial" => "Partial", "none" => "None"));
        $this->form->addElement("select", "bold_run4_attempts_{$i}", "<b>Console Pass/Fail</b>", array(null => "", "console_pass" => "Console Pass", "console_fail" => "Console Fail"));
        $this->form->addElement("select", "bold_run4_num_attempts_{$i}", "<b>Number of Attempts</b>", range(0, 10));
        $this->XINRegisterRule("bold_run4_num_attempts_{$i}", array("bold_run4_{$i}{@}=={@}Yes"), "Required.");
        $this->XINRegisterRule("bold_run4_attempts_{$i}", array("bold_run4_{$i}{@}=={@}Yes"), "Required.");
        $this->form->addElement("select", "bold_run4_firmm_{$i}", "<b>FIRMM used?<b>", array("" => null, "Yes" => "Yes", "No" => "No"));
        $this->XINRegisterRule("bold_run4_firmm_{$i}", array("bold_run4_{$i}{@}=={@}Yes"), "Required.");
        $this->form->addElement('select', "bold_run4_{$i}_facemask_{$i}", "Subject Wearing Face Mask?", array('' => null, 'yes' => "Yes", 'no' => "No"));
        $this->XINRegisterRule(
            "bold_run4_{$i}_facemask_{$i}",
            array("bold_run4_{$i}_facemask_{$i}{@}=={@}NEVER_REQUIRED")
        );
        $this->form->addElement("static", null, "<BR><BR>");

        // Add BOLD comments text area
        $this->form->addElement("textarea", "bold_comments_{$i}", "<i>BOLD Comments:</i>");
        $this->XINRegisterRule(
            "bold_comments_{$i}",
            array("bold_comments_{$i}{@}=={@}NEVER_REQUIRED")
        );
        $this->form->addElement("static", null, "<b>*If the subject leaves scanner, or moves a lot, restart from the beginning of failed section (include localizers).</b>");
        $this->form->addElement("static", null, "<BR>");

        // POST SESSION SECTION
        $this->form->addElement("header", null, "<b><i>Post-Session</i></b><BR><BR>");
        $this->form->addElement("select", "overall_success_{$i}", "<b>Overall Scan Success</b> - to be completed following final scan session", array("" => null, "complete_protocol_acquired" => "Complete protocol acquired", "partial_protocol_acquired" => "Partial protocol acquired", "acquired_but_possibly_not_usable" => "Complete/partial acquired but may not be usable", "none_of_protocol_acquired" => "None of protocol acquired"));
        $this->form->addElement("select", "if_none_partial_unusable_{$i}", "<i>If none/partial/unusable:</i>", array("" => null, "unable_to_stay_still" => "Subject unable to stay still", "subject_refused" => "Subject refused", "family_canceled" => "Family canceled", "out_of_time" => "Ran out of time", "scanner_issues" => "Scanner issues", "family_declined" => "Family declined second attempt"));
        $this->XINRegisterRule("if_none_partial_unusable_{$i}", array("overall_success_$i{@}!={@}complete_protocol_acquired"), "Required if complete protocol was not acquired");
        $this->form->addElement("static", null, "<BR>");

        // DTI Siemens SECTION
        $this->form->addElement('header', null, "<b>Siemens DTI</b><BR><BR>");
        $this->form->addElement('select', "siemens{$i}_dti_sequences_acquired_{$i}", "<b>DTI Sequences Acquired?<b>", array(null => "", "complete" => "Complete", "partial" => "Partial", "none" => "None"));

        $this->form->addElement('static', null, '*Repeat until pass QC; run DTI in order listed<BR><BR>');
        $this->form->addElement('static', null, '<BR>');

        $this->form->addElement('select', "siemens{$i}_dti3_shell_{$i}", "DTI 3 Shell | <i>ep2d_diff_sms2_3shell_PA_1p7</i>", array(null => "", "complete" => "Complete", "partial" => "Partial", "none" => "None"));
        $this->form->addElement('select', "siemens{$i}_dti3_shell_attempts_{$i}", "<b>Console Pass/Fail</b><BR><BR>", array(null => "", "console_pass" => "Console Pass", "console_fail" => "Console Fail"));
        $this->XINRegisterRule("siemens{$i}_dti3_shell_attempts_{$i}", array("siemens{$i}_dti3_shell_{$i}{@}=={@}complete"), "Required.");
        $this->form->addElement('select', "siemens{$i}_dti3_shell_num_attempts_{$i}", "<b>Number of Attempts</b>", range(0, 10));
        $this->XINRegisterRule("siemens{$i}_dti3_shell_num_attempts{$i}", array("siemens{$i}_dti3_shell_{$i}{@}=={@}complete"), "Required.");
        $this->form->addElement('select', "siemens{$i}_dti3_shell_{$i}_facemask_{$i}", "Subject Wearing Face Mask?", array('' => null, 'yes' => "Yes", 'no' => "No"));
        $this->XINRegisterRule(
            "siemens{$i}_dti3_shell_{$i}_facemask_{$i}",
            array("siemens{$i}_dti3_shell_{$i}_facemask_{$i}{@}=={@}NEVER_REQUIRED")
        );
        $this->form->addElement('static', null, '<BR><BR>');

        $this->form->addElement('select', "siemens{$i}_6b0_{$i}", "6B0 | <i>ep2d_diff_sms2_6B0_AP_1p7</i>", array(null => "", "complete" => "Complete", "partial" => "Partial", "none" => "None"));
        $this->form->addElement('select', "siemens{$i}_6b0_attempts_{$i}", "<b>Console Pass/Fail</b><BR><BR>", array(null => "", "console_pass" => "Console Pass", "console_fail" => "Console Fail"));
        $this->XINRegisterRule("siemens{$i}_6b0_attempts_{$i}", array("siemens{$i}_6b0_{$i}{@}=={@}complete"), "Required.");
        $this->form->addElement('select', "siemens{$i}_6b0_num_attempts_{$i}", "<b>Number of Attempts</b>", range(0, 10));
        $this->XINRegisterRule("siemens{$i}_6b0_num_attempts_{$i}", array("siemens{$i}_6b0_{$i}{@}=={@}complete"), "Required.");
        $this->form->addElement('select', "siemens{$i}_6b0_{$i}_facemask_{$i}", "Subject Wearing Face Mask?", array('' => null, 'yes' => "Yes", 'no' => "No"));
        $this->XINRegisterRule(
            "siemens{$i}_6b0_{$i}_facemask_{$i}",
            array("siemens{$i}_6b0_{$i}_facemask_{$i}{@}=={@}NEVER_REQUIRED")
        );
        $this->form->addElement('static', null, '<BR><BR>');

        $this->form->addElement('select', "siemens{$i}_dti2_shell_{$i}", "DTI 2 Shell | <i>ep2d_diff_sms2_2shell_PA_1p7</i>", array(null => "", "complete" => "Complete", "partial" => "Partial", "none" => "None"));
        $this->form->addElement('select', "siemens{$i}_dti2_shell_attempts_{$i}", "<b>Console Pass/Fail</b><BR><BR>", array(null => "", "console_pass" => "Console Pass", "console_fail" => "Console Fail"));
        $this->XINRegisterRule("siemens{$i}_dti2_shell_attempts_{$i}", array("siemens{$i}_dti2_shell_{$i}{@}=={@}complete"), "Required.");
        $this->form->addElement('select', "siemens{$i}_dti2_shell_num_attempts_{$i}", "<b>Number of Attempts</b>", range(0, 10));
        $this->XINRegisterRule("siemens{$i}_dti2_shell_num_attempts_{$i}", array("siemens{$i}_dti2_shell_{$i}{@}=={@}complete"), "Required.");
        $this->form->addElement('select', "siemens{$i}_dti2_shell_{$i}_facemask_{$i}", "Subject Wearing Face Mask?", array('' => null, 'yes' => "Yes", 'no' => "No"));
        $this->XINRegisterRule(
            "siemens{$i}_dti2_shell_{$i}_facemask_{$i}",
            array("siemens{$i}_dti2_shell_{$i}_facemask_{$i}{@}=={@}NEVER_REQUIRED")
        );
        $this->form->addElement('static', null, '<BR><BR>');

        $this->form->addElement('select', "siemens{$i}_6b02_{$i}", "6B0 | <i>ep2d_diff_sms2_6B0_AP_1p7</i>", array(null => "", "complete" => "Complete", "partial" => "Partial", "none" => "None"));
        $this->form->addElement('select', "siemens{$i}_6b02_attempts_{$i}", "<b>Console Pass/Fail</b><BR><BR>", array(null => "", "console_pass" => "Console Pass", "console_fail" => "Console Fail"));
        $this->XINRegisterRule("siemens{$i}_6b02_attempts_{$i}", array("siemens{$i}_6b02_{$i}{@}=={@}complete"), "Required.");
        $this->form->addElement('select', "siemens{$i}_6b02_num_attempts_{$i}", "<b>Number of Attempts</b>", range(0, 10));
        $this->XINRegisterRule("siemens{$i}_6b02_num_attempts_{$i}", array("siemens{$i}_6b02_{$i}{@}=={@}complete"), "Required.");
        $this->form->addElement('select', "siemens{$i}_6b02_{$i}_facemask_{$i}", "Subject Wearing Face Mask?", array('' => null, 'yes' => "Yes", 'no' => "No"));
        $this->XINRegisterRule(
            "siemens{$i}_6b02_{$i}_facemask_{$i}",
            array("siemens{$i}_6b02_{$i}_facemask_{$i}{@}=={@}NEVER_REQUIRED")
        );
        $this->form->addElement('static', null, '<BR><BR>');

        $this->form->addElement('select', "siemens{$i}_dti1_shell_{$i}", "DTI 1 Shell | <i>ep2d_diff_sms2_1shell_PA_1p7</i>", array(null => "", "complete" => "Complete", "partial" => "Partial", "none" => "None"));
        $this->form->addElement('select', "siemens{$i}_dti1_shell_attempts_{$i}", "<b>Console Pass/Fail</b><BR><BR>", array(null => "", "console_pass" => "Console Pass", "console_fail" => "Console Fail"));
        $this->XINRegisterRule("siemens{$i}_dti1_shell_attempts_{$i}", array("siemens{$i}_dti1_shell_{$i}{@}=={@}complete"), "Required.");
        $this->form->addElement('select', "siemens{$i}_dti1_shell_num_attempts_{$i}", "<b>Number of Attempts</b>", range(0, 10));
        $this->XINRegisterRule("siemens{$i}_dti1_shell_num_attempts_{$i}", array("siemens{$i}_dti1_shell_{$i}{@}=={@}complete"), "Required.");
        $this->form->addElement('select', "siemens{$i}_dti1_shell_{$i}_facemask_{$i}", "Subject Wearing Face Mask?", array('' => null, 'yes' => "Yes", 'no' => "No"));
        $this->XINRegisterRule(
            "siemens{$i}_dti1_shell_{$i}_facemask_{$i}",
            array("siemens{$i}_dti1_shell_{$i}_facemask_{$i}{@}=={@}NEVER_REQUIRED")
        );
        $this->form->addElement('static', null, '<BR><BR>');

        $this->form->addElement("textarea", "siemens{$i}_dti_comments_{$i}", "<i>DTI Comments:</i>");
        $this->XINRegisterRule(
            "siemens{$i}_dti_comments_{$i}",
            array("siemens{$i}_dti_comments_{$i}{@}=={@}NEVER_REQUIRED")
        );
        $this->form->addElement("static", null, "<BR>");
        $this->form->addFormRule(array(&$this, "validate_pages"));
    }

    function scanDoneCount()
    {
        $db =& Database::singleton();
        $yes_count = 0;
        for ($i = 1; $i <= 4; $i++) {
            $commentID = $this->getCommentID();
            $value = $db->pselectOne(
                "SELECT scan_done_{$i} FROM mri_parameter_form_sa where CommentID='$commentID'", array());
            if ($value == 'yes') {
                $yes_count++;
            }
        }
        return $yes_count;
    }

    function checkPageDone($i)
    {
        $db =& Database::singleton();
        $commentID = $this->getCommentID();
        if ($i == 1) {
            $field = 'sedation';
        } else {
            $field = "sedation_{$i}";
        }
        $value = $db->pselectOne(
            "SELECT `$field` FROM mri_parameter_form_sa where CommentID='$commentID'", array());
        if ($value == '' || $value == NULL) {
            $page_done = 0;
        } else {
            $page_done = 1;
        }
        return $page_done;
    }

    function checkScanDone($i)
    {
        $db =& Database::singleton();
        $commentID = $this->getCommentID();

        $field = "scan_done_{$i}";
        $value = $db->pselectOne(
            "SELECT `$field` FROM mri_parameter_form_sa where CommentID='$commentID'", array());
        if ($value == 'yes') {
            $page_done = 1;
        } else {
            $page_done = 0;
        }
        return $page_done;
    }


}

?>
