<?php
/**
 * This file contains the NDB_BVL_Instrument_mri_parameter_ep
 * class
 *
 * PHP Version 7
 *
 * @category Instrument
 * @package  IBIS
 * @author   Ling Ma <lingyun.ma@mcin.ca>
 * @date     2019 Dec 20
 * @license  http://www.gnu.org/licenses/gpl-3.0.txt GPLv3
 * @link     https://www.github.com/aces/IBIS/
 */

class NDB_BVL_Instrument_mri_parameter_ep extends NDB_BVL_Instrument
{
    var $ValidityEnabled  = false;
    var $ValidityRequired = false;

    const YES_NO_OPTIONS = array(
                               ""           => "",
                               "1"          => "Yes",
                               "0"          => "No",
                              );

    const PASS_FAIL = array(
                               ""           => "",
                               "1"          => "Console Pass",
                               "0"          => "Console Fail",
                              );
    const FINGER = array(
                               ""           => "",
                               "finger"     => "Finger",
                               "toe"        => "Toe",                               
                              );                
    const OPTION1TO5 = array(
	   		       ""           => "",
			       "0"          => "0",
                               "1"          => "1",
                               "2"          => "2",
                               "3"          => "3",
                               "4"          => "4",
                               "5"          => "5",                                                              
                              );     
    const OPTION1TO4 = array(
	   		       ""           => "",
                               "1"          => "1",
                               "2"          => "2",
                               "3"          => "3",
                               "4"          => "4",
                              ); 

    const T1_T2    = array(
                               ""           => "",
                               "t1"         => "T1w",
                               "t2"         => "T2w",
                              );      

    const S1_S4    = array(
                               ""          => "",
                               "1"         => "Session 1",
                               "2"         => "Session 2",
                               "3"         => "Session 3",
                               "4"         => "Session 4",
                              );      
    const R1_R9    = array(
                               ""          => "",
                               "0"         => "0",
                               "1"         => "1",
                               "2"         => "2",
                               "3"         => "3",
                               "4"         => "4",
                               "5"         => "5",
                               "6"         => "6",
                               "7"         => "7",
                               "8"         => "8",
                               "9"         => "9",                                                                                                                                                                                                                        
                              );                   

    const complete_partial_none = array(
                               ""        => "",
                               "1"       => "Complete",
                               "0"       => "Partial",
                               "none"    => "None",                                                                                                                                                                                                                     
                              );  

    private $yes_no = array(
            null => '',
            '0'  => 'No',
            '1'  => 'Yes'
    );

    private $study_grp = [
        'ep' => 'IBIS-EP',
        'ds' => 'Infant-DS',
        'ds_ctrl' => 'Infant-DS Ctrl'
    ];

    private $orientation_grp = [
        ''           => '',
        'supine'     => 'Supine',
        'leftlat'    => 'Left Lateral',
        'rightlat'   => 'Right Lateral'
    ];

    private $vitamine_grp = [
        ''      => '',
        'left'  => 'Left',
        'right' => 'Right'
    ];

    private $bold_grp = ['b1_' => 'Fieldmap (BOLD-1)',
            'b2_'     => 'Fieldmap (BOLD-2)',
            'b3_'     => 'Fieldmap (BOLD-3)',
            'blast1_' => 'Fieldmap (Last)'];

    private $bold_plus_grp = ['b4_'     => 'Fieldmap (BOLD-4)',
                              'blast2_' => 'Last'];

    private $bold_firmm_grp = ['bp1_' => 'BOLD_PA 1',
                               'bp2_' => 'BOLD_PA 2',
                               'bp3_' => 'BOLD_PA 3'];

    private $bold_plus_firmm_grp = ['bp4_' => 'BOLD_PA 4'];

    private $dti_grp = [
            '101b0' => [0 => '101 B0', 1 => 'DWI dir101 B0'],
            'dti1'  => [0 => 'DTI 1', 1  => 'DWI dir101 AP'],
            'dti2'  => [0 => 'DTI 2', 1  => 'DWI dir101 APinv'],
            '105b0' => [0 => '105 B0', 1 => 'DWI dir105 B0'],
            'dti3'  => [0 => 'DTI 3', 1  => 'DWI dir105 AP'],
            'dti4'  => [0 => 'DTI 4', 1  => 'DWI dir105 APinv']
        ];

    private $pg2_number_of_lines = 6;

    public function getFullName(): string
    {
        return 'IBIS EP & Infant DS param Form';
    }


    public function getSubtestList(): array {
        return [['Name' => 'mri_parameter_ep_page1', 'Description' => 'Record'],
                ['Name' => 'mri_parameter_ep_page2', 'Description' => 'Structural'],
                ['Name' => 'mri_parameter_ep_page3', 'Description' => 'BOLD'],
                ['Name' => 'mri_parameter_ep_page4', 'Description' => 'DTI'],
                ['Name' => 'mri_parameter_ep_page5', 'Description' => 'BOLD+'],
                ['Name' => 'mri_parameter_ep_page6', 'Description' => 'CSF Flow']];

    }


    /**
     * Sets up basic data, such as the LorisForm object, and so on.
     *
     * @param string $commentID The CommentID identifying the data to load
     * @param string $page      If a multipage form, the page to show
     *
     * @return   void
     * @access   public
     * @abstract
     */
    function setup(?string $commentID = NULL, ?string $page = NULL): void
    {
        $this->formType = 'XIN';
        $this->form     = new LorisForm('test_form');
        $this->page     = $page;

        // set the object properties
        $this->testName  = 'mri_parameter_ep'; // test_names.Test_name
        $this->table     = 'mri_parameter_ep';
        $this->commentID = $commentID; // data keyed by commentID

        //The array of dates/timestamps to convert to database dates/timestamps
        //Any LorisForm date elements must be listed here
        $this->dateTimeFields = array(
            'Date_taken'
        );

        // required fields for data entry completion status
        $this->_requiredElements = array(
            'Examiner',
            'CommentID',
        );

        //The array of selects with multiple answers allowed
        //Any LorisForm multiple selects must be listed here
        $this->selectMultipleElements = [
		'study',
		'face_mask',
		'face_shield',
            ];

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
        if (preg_match("/mri_parameter_ep(_page[0-9]+)/",
            $this->page, $matches)) {
            call_user_func(array($this, $matches[1]));
        } else {
            $this->_main();
        }

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
        // Header
        $this->addHeader("IBIS EP and Infant DS");

        // automatically adds examiner & date of administration
        $this->_addMetadataFields();
        $this->form->addElement('select','session_number','Number of sessions:',self::OPTION1TO4);

        $this->form->addElement('static', 't1_pass_msg', 'T1 Passed?');
        $this->form->addElement('static', 't2_pass_msg', 'T2 Passed?');
        $this->form->addElement('static', 'bold_pass_msg', 'BOLD Passed?');
        $this->form->addElement('static', 'dti_pass_msg', 'DTI Passed?');

        $this->addLabel(''); // Only to add an empty line

        $this->addLabel('Phase encode angle calculation:');
        $group = array();
        $group[] = $this->form->createElement('static', null, null, '');
        $group[] = $this->form->createElement('static', null, null, 'if AP angle is Positive');
        $group[] = $this->form->createElement('static', null, null, '  ');
        $group[] = $this->form->createElement('static', null, null, '');
        $group[] = $this->form->createElement('static', null, null, 'if AP angle is Negative');
        $this->form->addGroup($group, 'sec01_header', '', $this->_GUIDelimiter, FALSE);
        unset($group);

        $group = array();
        $grp = ['-180', '180'];
        $cnt = 0;
        foreach ($grp as $key) {
            $group[] = $this->form->createElement('static', null, null, '');
            $group[] = $this->form->createElement('static', null, null, $key);
            if ($cnt ++ == 0) {
                $group[] = $this->form->createElement('static', null, null, '');
            }
        }

        $this->form->addGroup($group, 'sec01_row', '', $this->_GUIDelimiter, FALSE);
        unset($group);

        $grp = ['ap_p', 'ap_n'];
        $angle_record_lines = 2;
        for ($i = 0; $i < $angle_record_lines; $i++) {
            $group = [];
            $cnt = 0;
            foreach ($grp as $key) {

                if ($cnt ++ == 1) {
                    $group[] = $this->form->createElement('static', null, null, '');
                }
                $group[] = $this->form->createElement('static', null, null, ($i == 0)? '+': '');

                $group[] = $this->createText("$key{$i}");
                $this->not_required_field("$key{$i}");
            }
            $this->form->addGroup($group, "sec01_row{$i}", "", $this->_GUIDelimiter, FALSE);
            unset($group);
        }

        $this->addLabel(''); // Only to add an empty line

        $group = array();
        $group[] = $this->form->createElement('static', null, null, 'AP angle');
        $group[] = $this->form->createElement('static', null, null, 'PA angle');
        $this->form->addGroup($group, 'sec02_header', '', $this->_GUIDelimiter, FALSE);
        unset($group);

        $grp = ['-10' => '170',
                '-5'  => '175',
                '0'   => '180',
                '5'   => '-175',
                '10'  => '-170'];

        $i = 0;
        foreach ($grp as $key => $val) {
            $group = array();
            $group[] = $this->form->createElement('static', null, null, $key);
            $group[] = $this->form->createElement('static', null, null, $val);

            $this->form->addGroup($group, "sec02_row{$i}", '', $this->_GUIDelimiter, FALSE);
            unset($group);
            $i ++;
        }
        $this->addLabel('');

        $grp = ['Field Map APinv' => '_SpinEchoFieldMap_APinv3mm',
                'Field Map AP'    => '_SpinEchoFieldMap_AP3mm',
                'BOLD_PA'         => 'BOLD_PA_ep2d_3mm52sl475slMB4',
                '101_AP'          => 'DWIcmrr_AP_dir101_3shell',
                '101_APinv'       => 'DWIcmrr_APinv_dir101_3shell',
                '105_AP'          => 'DWIcmrr_AP_dir105_3shell',
                '105_Apinv'       => 'DWIcmrr_APinv_dir105_3shell'];

        $group = array();
        $group[] = $this->form->createElement('static', null, null, '');
        $group[] = $this->form->createElement('static', null, null, '');
        $this->form->addGroup($group, 'sec03_header', '', $this->_GUIDelimiter, FALSE);
        unset($group);

        foreach ($grp as $key => $val) {
            $group = array();
            $group[] = $this->form->createElement('static', null, null, $key);
            $group[] = $this->form->createElement('static', null, null, $val);

            $this->form->addGroup($group, "sec03_row{$i}", '', $this->_GUIDelimiter, FALSE);
            unset($group);
            $i ++;
        }
        $this->form->addElement("textarea", "page0_comment", "Comments:", array('cols'=>25, 'rows'=>4));
        $this->XINRegisterRule("page0_comment", array("page0_comment{@}=={@}NEVER_REQUIRED"));
    }


    /**
     * Page 1
     *
     * @return void
     */
    function _page1()
    {

	    $option1 = [
		    null                 =>'',
		    'By_Specialist'      =>'By Specialist',
		    'MR_Tech'            =>'MR Tech',
		    'Parent_or_Guardian' =>'Parent or Guardian',
	               ];


	    $option2 = [
		    null =>'',
		    'full_protocol_acquired'   =>'Full Protocol Acquired',
                    'only_core_acquired'       =>'Only Core Acquired',
                    'partial_core_acquired'    =>'Partial Core Acquired',
                    'none_core_acquired'       =>'None',
                       ];
	    
	    
	    $option3 = [
		    null                           =>'',
		    'subject_woke_up'              =>'Subject woke up',
                    'ran_out_of_time'              =>'Ran out of time',
                    'subject_did_not_sleep'        =>'Subject did not sleep',
                    'none_core_acquired'           =>'Scanner issues',
                    'family_canceled'              =>'Family canceled',
                    'family_declined_2nd_attempt'  =>'Family declined 2nd attempt',
                       ];        

        $this->form->addElement('header', null, "Record");

        $this->addLabel('PPE worn during the session?');

        $this->addSelect("face_mask", 'Face Mask:', $option1, ['multiple' => true]);
        $this->XINRegisterRule("face_mask", array("face_mask{@}=={@}NEVER_REQUIRED"));



        $this->addSelect('face_shield','Face Shield:', $option1, ['multiple' => true]);
        $this->XINRegisterRule("face_shield", array("face_shield{@}=={@}NEVER_REQUIRED"));


        $this->form->addElement("textarea", "other_comment", "Comments:", array('cols'=>25, 'rows'=>4));
        $this->XINRegisterRule("other_comment", array("other_comment{@}=={@}NEVER_REQUIRED"));

        $this->addLabel('Post-Session');

        $group = [];
        $group[] = $this->form->createElement('static', null, null, 'Overall Success');
        $group[] = $this->form->createElement('static', null, null, 'If partial/none');
        $this->form->addGroup($group, 'sec1_header', '', $this->_GUIDelimiter, FALSE);
        unset($group);

                $group[] = $this->createSelect("overall_success", '', $option2);
                $this->not_required_field("overall_success");
                $group[] = $this->createSelect("if_partial_or_none", '', $option3);
                $this->not_required_field("if_partial_or_none");


            $this->form->addGroup($group, "page1_group", '', $this->_GUIDelimiter, FALSE);
            unset($group);


        $grp = ["study" => 'Study:'];

        foreach ($grp as $key => $label) {
            $group_arr = "{$key}_grp";
            $this->addSelect($key, $label, $this->$group_arr, ['multiple' => true, 'required'=> true]);
        }

        $this->addTextElement(
            'head_circumference',
            'Head Circumference (Inches):'
        );
                $this->XINRegisterRule("head_circumference", array("head_circumference{@}=={@}NEVER_REQUIRED"));

        $this->addTextElement(
            'height',
            'Height (Inches):'
        );

                $this->XINRegisterRule("height", array("height{@}=={@}NEVER_REQUIRED"));

        $this->addTextElement(
            'weight',
            'Weight (lbs):'
        );
                $this->XINRegisterRule("weight", array("weight{@}=={@}NEVER_REQUIRED"));


        $this->addTextElement(
            'mr_tech',
            'MR Tech:'
        );

                $this->XINRegisterRule("mr_tech", array("mr_tech{@}=={@}NEVER_REQUIRED"));


        $this->addTextElement(
            'behavioral_specialist',
            'Behavioral specialist:'
        );

        $this->XINRegisterRule("behavioral_specialist", array("behavioral_specialist{@}=={@}NEVER_REQUIRED"));


        $this->form->addElement('select','Medications','Medications:',self::YES_NO_OPTIONS);

        $this->XINRegisterRule("Medications", array("Medications{@}=={@}NEVER_REQUIRED"));
        $this->form->addElement("text", "record_medications_other", "Other :");

        $this->XINRegisterRule("record_medications_other", array("record_medications_other{@}=={@}NEVER_REQUIRED"));

        $this->_displayHeadersScanSession();
        for ($i = 1; $i < 5; $i++) {
            $group[] = $this->createLabel($i . ".");
            $group[] = $this->createSelect(
                "record_scan_done_$i",
                "",
                array(
                    null => "",
                    "1"  => "Yes",
                    "0"  => "No"
                )
	);
            $group[] = $this->createDate(
                "record_scan_date_$i",
                ""
            );
           $group[] = $this->form->createElement(
                "time",
                "time_entered_room_$i"
            );

            $group[] = $this->form->createElement(
                "time",
                "record_scan_start_time_$i"
            );

            $group[] = $this->form->createElement(
                "time",
                "record_scan_end_time_$i"
            );
            $group[] = $this->createSelect(
                "record_orientation_$i",
                "",
                $this->orientation_grp
            );
            $group[] = $this->createSelect(
                "record_vitamine_$i",
                "",
                 $this->vitamine_grp
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
                "record_scan_done_{$i}",
                array("record_scan_done_{$i}{@}=={@}NEVER_REQUIRED"), // rule
                "Not Required.", // message
                "scan_group_table{$i}" // group [if field is a part of a group]
            );
            $this->XINRegisterRule(
                "record_scan_date_$i",
                array("record_scan_done_$i{@}=={@}1"),
                "All fields are required if corresponding session is marked as done.",
                "scan_group_table{$i}"
            );
            $this->XINRegisterRule(
                "record_scan_start_time_$i",
                array("scan_done_$i{@}=={@}1"),
                "All fields are required if corresponding session is marked as done.",
                "scan_group_table{$i}"
            );

            $this->XINRegisterRule(
                "record_scan_end_time_$i",
                array("scan_done_$i{@}=={@}1"),
                "All fields are required if corresponding session is marked as done.",
                "scan_group_table{$i}"
            );
            $this->XINRegisterRule(
                "record_orientation_$i",
                array("scan_done_$i{@}=={@}1"),
                "All fields are required if corresponding session is marked as done.",
                "scan_group_table{$i}"
            );
            $this->XINRegisterRule(
                "record_vitamine_$i",
                array("scan_done_$i{@}=={@}1"),
                "All fields are required if corresponding session is marked as done.",
                "scan_group_table{$i}"
            );
        }    
    
                $this->form->addElement("textarea", "page1_comment", "Comments:", array('cols'=>25, 'rows'=>4));
                $this->XINRegisterRule("page1_comment", array("page1_comment{@}=={@}NEVER_REQUIRED"));

    }


    /**
     * Page 2
     *
     * @return void
     */
    function _page2()
    {
        $this->form->addElement('header', null, "Structural");

        $group = [];
        $group[] = $this->form->createElement('static', null, null, 'Session');
        $group[] = $this->form->createElement('static', null, null, 'Scan Type');
        $group[] = $this->form->createElement('static', null, null, 'Anterior');
        $group[] = $this->form->createElement('static', null, null, 'Superior');
        $group[] = $this->form->createElement('static', null, null, 'Anterior / Superior');
        $group[] = $this->form->createElement('static', null, null, 'Console Pass?');
        $this->form->addGroup($group, 'sec1_header', '', $this->_GUIDelimiter, FALSE);
        unset($group);
        $grp0 = ['structural_session_'];
        $grp1 = ['s_'];
        $grp2 = ['anterior', 'superior', 'ant_d_sup'];

        for ($i = 0; $i < $this->pg2_number_of_lines; $i++) {
            foreach ($grp0 as $key) {
                $group[] = $this->createSelect("$key{$i}", '', self::S1_S4);
                $this->not_required_field("$key{$i}");
            }

            foreach ($grp1 as $key) {
                $group[] = $this->createSelect("$key{$i}", '', self::T1_T2);
                $this->not_required_field("$key{$i}");
            }

            foreach ($grp2 as $key) {
                $group[] = $this->createText("$key{$i}");
                $this->not_required_field("$key{$i}");
            }

            $group[] = $this->createSelect("s_pass{$i}", '', self::PASS_FAIL);
            $this->not_required_field("s_pass{$i}");

            $this->form->addGroup($group, "sec2_row{$i}", '', $this->_GUIDelimiter, FALSE);
            unset($group);
        }

        for ($i = 1; $i < 3; $i ++) {
            $this->addSelect("t{$i}_pass", "T{$i} Passed", $this->yes_no);
           // $this->form->addRule("t{$i}_pass", "T{$i} Passed must be set", 'required');
        }

            $this->addSelect("t1w_pass", "T1w total attempts", self::R1_R9);
            $this->XINRegisterRule("t1w_pass", array("t1w_pass{@}=={@}NEVER_REQUIRED"));

            $this->addSelect("t2w_pass", "T2w total attempts", self::R1_R9);
            $this->XINRegisterRule("t2w_pass", array("t2w_pass{@}=={@}NEVER_REQUIRED"));



        $this->addLabel('Fails if Ant/Sup > 2.5; needs one T1 and one T2 to pass.');
        $this->form->addFormRule(array(&$this, 'constraint_rules_pg2'));

         $this->form->addElement("textarea", "page2_comment", "Comments:", array('cols'=>25, 'rows'=>4));
         $this->XINRegisterRule("page2_comment", array("page2_comment{@}=={@}NEVER_REQUIRED"));
    }


    /**
     * constraint check for page 2
     */
    function constraint_rules_pg2($values) {
        $errors = [];

        $grp2 = ['anterior', 'superior'];
        for ($i = 0; $i < $this->pg2_number_of_lines; $i++) {

            foreach ($grp2 as $key) {
                $val = $values["$key{$i}"];
                if (!empty($val) && !is_numeric($val)) {
                    $errors["sec2_row{$i}"] = 'The value of Anterior and Superior should be numeric.';
                }
            }

            if (empty($values["superior{$i}"]) && empty($values["anterior{$i}"]) && !empty($values["ant_d_sup{$i}"])) {
                $errors["sec2_row{$i}"] = 'The Anterior, Superior are not provided while you have an Anterior / Superior provided.';
            }

            if (empty($values["superior{$i}"]) && !empty($values["anterior{$i}"])) {
                $errors["sec2_row{$i}"] = 'The Superior is not provided while you have an Anterior provided.';
            }
            else {
                if ((floatval($values["superior{$i}"]) != 0) && abs(round(floatval($values["anterior{$i}"]) / floatval($values["superior{$i}"]), 2) - floatval($values["ant_d_sup{$i}"])) > 0.05) {
                    $errors["sec2_row{$i}"] = 'The value Anterior / Superior differences that of the Anterior divided by Superior too much (over 0.05).';
                }
            }

            $val = $values["ant_d_sup{$i}"];
            if (!empty($val) && !is_numeric($val)) {
                $errors["sec2_row{$i}"] = 'The value should be numeric.';
            }
            else if (floatval($values["ant_d_sup{$i}"]) > 2.5 && $values["s_pass{$i}"]) {
                $errors["sec2_row{$i}"] = 'Because Ant/Sup > 2.5, this line doesn\'t pass.';
            }
        }

        $grp = ['s_'];

        $cnt = [];
        foreach ($grp as $key) {
            $cnt[$key] = 0;
        }

        for ($i = 0; $i < $this->pg2_number_of_lines; $i++) {
            foreach ($grp as $key) {
                if ($values["$key{$i}"] == 't1') {
                    $cnt[$key] ++;
                }
            }
        }
        $already_failed = false;
        if ($values["t1_pass"] == '1' && $cnt['s_'] == 0) {
            $errors["t1_pass"] = 'Needs one T1 to pass.';
            $already_failed = true;
        }

        if ($values["t2_pass"] == '1' && $cnt['s_'] == 0) {
            if ($already_failed) {
                foreach ($grp as $key) {
                    $errors["{$key}pass"] = 'Needs one T1 and one T2 to pass.';
                }
            }
            else {
                $errors['t2_pass'] = 'Needs one T2 to pass.';
            }
        }

        return $errors;
    }


    /**
     * Page 3
     *
     * @return void
     */
    function _page3()
    {
        $this->form->addElement('header', null, "BOLD");

        $group = array();
        $group[] = $this->form->createElement('static', null, null, '');
        $group[] = $this->form->createElement('static', null, null, 'Ran?');
        $group[] = $this->form->createElement('static', null, null, '');
        $this->form->addGroup($group, 'sec3_header', '', $this->_GUIDelimiter, FALSE);
        unset($group);

        $i = 0;
        foreach ($this->bold_grp as $key => $label) {
            $group = array();
            $group[] = $this->form->createElement('static', null, null, $label);
            $group[] = $this->createSelect("{$key}run{$i}", '', $this->yes_no);
            $this->not_required_field("{$key}run{$i}");
            $group[] = $this->form->createElement('static', null, null, 'Field Map Apinv, Field Map AP');

            $this->form->addGroup($group, "sec3_row{$i}", "", $this->_GUIDelimiter, FALSE);
            unset($group);
            $i++;
        }

        $group = array();
        $group[] = $this->form->createElement('static', null, null, 'Session');
        $group[] = $this->form->createElement('static', null, null, 'Ran?');
        $group[] = $this->form->createElement('static', null, null, '');
        $group[] = $this->form->createElement('static', null, null, 'FIRMM');
        $group[] = $this->form->createElement('static', null, null, '% 0.2mm');
        $group[] = $this->form->createElement('static', null, null, 'Console Pass?');
        $this->form->addGroup($group, 'sec3_2_header', '', $this->_GUIDelimiter, FALSE);
        unset($group);

        $grp0 = "bold_session_";

        $i = 0;
        foreach ($this->bold_firmm_grp as $key => $label) {
            $group = array();

            $group[] = $this->createSelect("$grp0{$i}", '', self::S1_S4);
            $this->not_required_field("$grp0{$i}");

            $group[] = $this->createSelect("{$key}run{$i}", '', self::complete_partial_none);
            $this->not_required_field("{$key}run{$i}");

            $group[] = $this->form->createElement('static', null, null, $label);

            $group[] = $this->createSelect("{$key}firmm_{$i}", '', $this->yes_no);
            $this->not_required_field("{$key}firmm_{$i}");

            $group[] = $this->createText("{$key}02_{$i}", '');
            $this->not_required_field("{$key}02_{$i}");

            $group[] = $this->createSelect("{$key}pass_{$i}", '', self::PASS_FAIL);
            $this->not_required_field("{$key}pass_{$i}");

            $this->form->addGroup($group, "sec3_2_row{$i}", '', $this->_GUIDelimiter, FALSE);
            unset($group);
            $i++;
        }
        $this->addLabel('run fails if % 0.2mm < 70%; needs 3 BOLD runs to pass');
        $this->addCheckbox('firm_not_used', 'FIRMM NOT USED', array('value' => '1'));

        $this->addSelect('bold_pass', 'BOLD Passed', $this->yes_no);
        //$this->form->addRule("bold_pass", "BOLD Passed must be set", 'required');
        
        $this->addSelect("bold_attempts", "BOLD Attempts", self::R1_R9);

        $this->addLabel('PE direction will default to L >> R. Please set to A >> P, then edit the angle to set P >> A');
        $this->form->addFormRule(array(&$this, 'constraint_rules2'));

        $this->form->addElement("textarea", "page3_comment", "Comments:", array('cols'=>25, 'rows'=>4));
        $this->XINRegisterRule("page3_comment", array("page3_comment{@}=={@}NEVER_REQUIRED"));
    }


    /**
     * constraint check for page 3
     */
    function constraint_rules2($values) {
        $errors = [];
        $i = 0;
        foreach ($this->bold_firmm_grp as $key => $label) {
          if (!isset($values['firm_not_used'])) {  
            if (!empty($values["{$key}02_{$i}"]) && !is_numeric($values["{$key}02_{$i}"])) {
                $errors["sec3_2_row{$i}"] = '% 0.2mm should not have a non-numeric value.';
            }
            else {
                $tmp_02val = intval($values["{$key}02_{$i}"]);
                if (!($tmp_02val >= 0 && $tmp_02val <= 100)) {
                    $errors["sec3_2_row{$i}"] = '% 0.2mm value is not valid. It should be a value between 0 and 100.';
                }
                else if (intval($values["{$key}02_{$i}"]) < 70 && !empty($values["{$key}pass_{$i}"])) {
                    $errors["sec3_2_row{$i}"] = 'Because % 0.2mm < 70%, this line doesn\'t pass';
                }
            }
          }    
            $i ++;
        }

        $i = 0;
        foreach ($this->bold_grp as $key => $label) {
            if (!empty($values["{$key}run{$i}"])) {
                $i ++;
            }
        }
        if ($i < 3 && !empty($values['bold_pass'])) {
            $errors["bold_pass"] = "needs 3 BOLDS runs to pass";
        }
        return $errors;
    }


    /**
     * Page 4
     *
     * @return void
     */
    function _page4()

    {
        $this->form->addElement('header', null, "DTI");

        $group = array();
        $group[] = $this->form->createElement('static', null, null, 'Session');
        $group[] = $this->form->createElement('static', null, null, '');
        $group[] = $this->form->createElement('static', null, null, 'Ran?');
        $group[] = $this->form->createElement('static', null, null, '');
        $group[] = $this->form->createElement('static', null, null, 'Total number of attempts');
        $group[] = $this->form->createElement('static', null, null, 'Volumes that failed');
        $group[] = $this->form->createElement('static', null, null, 'Console Pass?');
        $this->form->addGroup($group, 'sec4_header', '', $this->_GUIDelimiter, FALSE);
        unset($group);
        $grp0 = "dti_session_";

        $i = 0;
        foreach ($this->dti_grp as $key => $label) {
            $group = array();
            $group[] = $this->createSelect("$grp0{$i}", '', self::S1_S4);
            $this->not_required_field("$grp0{$i}");

            $group[] = $this->form->createElement('static', null, null, $label[0]);
            $group[] = $this->createSelect("{$key}run{$i}", '', self::complete_partial_none);
            $this->not_required_field("{$key}run{$i}");


            $group[] = $this->form->createElement('static', null, null, $label[1]);
            $group[] = $this->createText("{$key}try{$i}", '');
            $this->not_required_field("{$key}try{$i}");

            $group[] = $this->createText("{$key}fail{$i}", '');
            $this->not_required_field("{$key}fail{$i}");


            $group[] = $this->createSelect("{$key}pass{$i}", '', self::PASS_FAIL);
            $this->not_required_field("{$key}pass{$i}");

            $this->form->addGroup($group, "sec4_row{$i}", "", $this->_GUIDelimiter, FALSE);
            unset($group);
            $i++;
        }

        $this->addLabel('Verify phase encode direction : should be AP for both AP and APinv sequences');
        $this->addLabel('PE direction will default to L >> R. Please set to A >> P, then edit the angle to set P >> A');


        $this->form->addElement("textarea", "page4_comment", "Comments:", array('cols'=>25, 'rows'=>4));
        $this->XINRegisterRule("page4_comment", array("page4_comment{@}=={@}NEVER_REQUIRED"));
    }


    /**
     * Page 5
     *
     * @return void
     */
    function _page5()
    {

        $this->form->addElement('header', null, "BOLD +");

        $group = array();
        $group[] = $this->form->createElement('static', null, null, '');
        $group[] = $this->form->createElement('static', null, null, 'Ran?');
        $group[] = $this->form->createElement('static', null, null, '');
        $this->form->addGroup($group, 'sec5_header', '', $this->_GUIDelimiter, FALSE);
        unset($group);

        $i = 0;
        foreach ($this->bold_plus_grp as $key => $label) {
            $group   = array();
            $group[] = $this->form->createElement('static', null, null, $label);

            $group[] = $this->createSelect("{$key}run{$i}", '', $this->yes_no);
            $this->not_required_field("{$key}run{$i}");

            $group[] = $this->form->createElement('static', null, null, 'Field Map Apinv, Field Map AP');

            $this->form->addGroup($group, "sec5_row{$i}", '', $this->_GUIDelimiter, FALSE);
            unset($group);
            $i++;
        }

        $group = array();
        $group[] = $this->form->createElement('static', null, null, 'Session');
        $group[] = $this->form->createElement('static', null, null, 'Ran?');
        $group[] = $this->form->createElement('static', null, null, '');
        $group[] = $this->form->createElement('static', null, null, 'FIRMM');
        $group[] = $this->form->createElement('static', null, null, '%0.2mm');
        $group[] = $this->form->createElement('static', null, null, 'Console Pass?');
        $this->form->addGroup($group, 'sec5_2_header', '', $this->_GUIDelimiter, FALSE);
        unset($group);
        $grp0 = "bold_plus_session_";
        $i = 0;
        foreach ($this->bold_plus_firmm_grp as $key => $label) {
            $group   = array();
            $group[] = $this->createSelect("$grp0{$i}", '', self::S1_S4);
            $this->not_required_field("$grp0{$i}");

            $group[] = $this->createSelect("{$key}run{$i}", '', self::complete_partial_none);
            $this->not_required_field("{$key}run{$i}");

            $group[] = $this->form->createElement('static', null, null, $label);
            $group[] = $this->createSelect("{$key}firmm_{$i}", '', $this->yes_no);
            $this->not_required_field("{$key}firmm_{$i}");

            $group[] = $this->createText("{$key}02_{$i}", '');
            $this->not_required_field("{$key}02_{$i}");

            $group[] = $this->createSelect("{$key}pass_{$i}", '', self::PASS_FAIL);
            $this->not_required_field("{$key}pass_{$i}");

            $this->form->addGroup($group, "sec5_2_row{$i}", '', $this->_GUIDelimiter, FALSE);
            unset($group);
            $i++;
        }
        $this->addCheckbox('firm_not_used_plus', 'FIRMM NOT USED', array('value' => '1'));
        $this->addLabel('Please set to A >> P, then edit the angle to set P >> A');
        $this->addSelect("boldplus_attempts", "BOLD Attempts", self::R1_R9);

        $this->form->addElement("textarea", "page5_comment", "Comments:", array('cols'=>25, 'rows'=>4));
        $this->XINRegisterRule("page5_comment", array("page5_comment{@}=={@}NEVER_REQUIRED"));
        $this->form->addFormRule(array(&$this, 'constraint_rules_pg5'));

    }
    /**
     * constraint check for page 5
     */
    function constraint_rules_pg5($values) {
        $errors = [];
            if (!isset($values['firm_not_used_plus'])) {
                if (!empty($values["bp4_02_0"]) && !is_numeric($values["bp4_02_0"])) {
                    $errors["sec5_2_row0"] = '% 0.2mm should not have a non-numeric value.';
                }
                else {
                    $tmp_02val = intval($values["bp4_02_0"]);
                    if (!($tmp_02val >= 0 && $tmp_02val <= 100)) {
                        $errors["sec5_2_row0"] = '% 0.2mm value is not valid. It should be a value between 0 and 100.';
                    }
                    else if (intval($values["bp4_02_0"]) < 70 && !empty($values["bp4_pass_0"])) {
                        $errors["sec5_2_row0"] = 'Because % 0.2mm < 70%, this line doesn\'t pass';
                    }
                }
            }

        return $errors;
    }
    /**
     * Page 6
     *
     * @return void
     */
    function _page6()
    {
        $this->form->addElement('header', null, "CSF Flow");


        $group   = [];
        $group[] = $this->form->createElement('static', null, null, 'Run?');
        $group[] = $this->form->createElement('static', null, null, 'CSF flow total number of attempts');
        $group[] = $this->form->createElement('static', null, null, 'Console Pass?');
        $this->form->addGroup($group, 'sec1_header', '', $this->_GUIDelimiter, FALSE);
        unset($group);

                $group[] = $this->createSelect("csf_run", '', self::complete_partial_none);
                $this->not_required_field("csf_run");
                $group[] = $this->createSelect("csf_attempts", '', self::OPTION1TO5);
                $this->not_required_field("csf_attempts");
                $group[] = $this->createSelect("csf_pass", '', self::PASS_FAIL);
                $this->not_required_field("csf_pass");

            $this->form->addGroup($group, "csf_flow", '', $this->_GUIDelimiter, FALSE);
            unset($group);
                    
         $this->form->addElement("select", "pulse", "Pulse Ox placement:", self::FINGER);
         $this->XINRegisterRule(
            "pulse",
            array("csf_pass{@}=={@}1"),
            "Required."
    );
	$this->addNumericElement("start_hr","Start HR");
	 $this->addNumericElement("end_hr", "End HR");
	 $this->form->addElement("advcheckbox", 'did_not_collect_this_data', 'Did not collect this data.', null, null,array("0", "1"));
	 $this->XINRegisterRule(
            "start_hr",
            array("did_not_collect_this_data{@}!={@}1"),
            "Required. check this box if data are not collected"
    );
	    $this->XINRegisterRule(
            "end_hr",
            array("did_not_collect_this_data{@}!={@}1"),
            "Required. check this box if data are not collected"
    );
         $this->form->addElement("text", "captured_cycle", "Captured cycle (ms):");
         $this->form->addElement("text", "acquisition_window", "Acquisition window (ms):");

         
        $this->not_required_field("captured_cycle");
        $this->not_required_field("acquisition_window");

	$this->form->addElement('file', 'mri_parameter_file', 'Upload the MRI Parameter EP Parser file
       <br><h6><i>(Ex: PSCID_DCCID_visitlabel_CL)</i></h6>');

        $this->form->addElement('static', "File_name", "Uploaded File");
	$this->form->addElement("advcheckbox", 'cardiac_log_not_acquired', 'Cardiac log not acquired', null, null,array("0", "1"));
	$this->XINRegisterRule(
            "mri_parameter_file",
            array("cardiac_log_not_acquired{@}!={@}1),
            "Required. check this box if no file to upload"
    );
         $this->form->addElement("textarea", "page6_comment", "Comments:", array('cols'=>25, 'rows'=>4));
         $this->XINRegisterRule("page6_comment", array("page6_comment{@}=={@}NEVER_REQUIRED"));
         $this->form->addFormRule(array(&$this, 'constraint_rules_pg6'));

    }

        function _saveValues(array $values): void
    {
	$timepoint =& TimePoint::singleton($this->getSessionID());
        $candidate =& Candidate::singleton($timepoint->getCandID());

        if(isset($values['Date_taken'])) {
            $this->_saveCandidateAge($values);
        }

        require_once "File_Upload.class.inc";
        $file=new File_Upload;

        //pass the existing form ($form) by reference to File_Upload, and register the file_upload field names being used.
        $file->registerForm($this->form);

        //Tell File_Upload what file handlers to use.
        $file->setFileHandler("mri_parameter_file", $this);

        // The uploaded file will go into the directory where all media files go
        $config = NDB_Config::singleton();
        $dir = $config->getSetting("mediaPath");
        $file->setBaseUploadDirectory($dir);

        //set the the IDs to the handler functions.
        $user =& User::singleton();
        $file->setHandlerArgs(
            [
              "CommentID"  => $this->getCommentID(),
              "candID"     => $candidate->getCandID(),
              "PSCID"      => $candidate->getPSCID(),
              "visitLabel" => $timepoint->getVisitLabel(),
              "username"   => $user->getUsername(),
              "values"     => $values
            ]
        );

        //If the form is validated, call File_Upload::processFiles() which loops through the files and
        //proccesses them (including verify, move, and import steps)
        if ($values['mri_parameter_file']['name'] != false) {
            $file->processFiles();
        }

        //echo error messages
        if(!empty($file->errorLog)){
            while(list($fileType,$fileErrors)=each($file->errorLog)){
                foreach($fileErrors AS $error){
                    echo "UPLOAD ERROR ($fileType) : $error";
                }
            }
	}

        unset($values['candID'], $values['sessionID'], $values['commentID'], $values['test_name'], $values['page'], $values['fire_away'], $values['subtest'], $values['MAX_FILE_SIZE'], $values['mri_parameter_file']);
	$this->_save($values);

	}

    function isValid(&$file, $args){
	error_log("isValid func");	  
    $correct_filename = ($args['PSCID'].'_'.$args['candID'].'_'.$args['visitLabel']."_CL");
    if($file->fileInfo['name'] != $correct_filename){
            $errors[]="Incorrect Filename: Filename should be: " . $correct_filename;
            return $errors;
    }

    $fp=fopen($file->fileInfo['tmp_name'], "r");
        $contents=fread($fp,filesize($file->fileInfo['tmp_name']));
    	fclose($fp);

     return true;
    }

    /**
     * importFile imports the Actigraph Export file into the database.
     *
     * @param     object       $file    A reference to the file object (passed automatically by callFileHandler)
     * @param     assoc_array  $args    The arguments passed to the function they must be:
     *   -
     *
     * @return    bool $success if operation succeeded
     *
     * @access    public
     */
    function importFile(&$file, $args){
        $fp=fopen($file->fileInfo['tmp_name'], "r");
        $contents=fread($fp,filesize($file->fileInfo['tmp_name']));
        fclose($fp);

        $timepoint =& TimePoint::singleton($this->getSessionID());
	$candidate =& Candidate::singleton($timepoint->getCandID());
        $user      =& User::singleton();

        // Compute the directory where all media files are stored
        $config    = NDB_Config::singleton();
        $mediaPath = $config->getSetting('mediaPath');

        $values=array(
            'UserID'    => $args['username'],
            'Status'    => 'assembly',
            'File_type' => 'Cardiac Logs',
            'File_name' => $file->getDestinationFilename(),
            'Data_dir'  => $mediaPath
    );

	        $db=& Database::singleton();

        //-------------------------------------------------------------------//
        // Check if there is a file in the media module with the same name   //
        // as the uploaded file.                                             //
	//-------------------------------------------------------------------//

        $row          = $db->pselectRow(
                "SELECT e.Date_Taken, m.ID FROM {$this->table} e LEFT JOIN media m ON (e.File_name=m.file_name) WHERE e.CommentID=:CommentID",
                array("CommentID" => $this->getCommentID())
        );
        $dateTaken = $row['Date_Taken'];
	$mediaID   = $row['ID'];

        $query = [
                      'session_id'  => $timepoint->getSessionID(),
                      'instrument'  => $this->table,
		      'date_taken'  => $dateTaken,
		      'comments'    => $comments,
                      'file_name'   => $file->getDestinationFilename(),
                      'file_type'   => 'Cardiac Logs',
                      'data_dir'    => $mediaPath,
		      'uploaded_by' => $user->getData('UserID'),
        ];

        try {
            // File alread exists in media module: update
            if (!is_null($mediaID)) {
               $db->update('media', $query, array('ID' => $mediaID));
            // File does not exist in media module: insert new
            } else {
                $db->insert('media', $query);
            }
        } catch (DatabaseException $e) {
            print_r($e);
        }

        // Update the mri_parameter_ep table
        $result = $db->update($this->testName, $values, array('CommentID'=>$args['CommentID']));
        return true;
    }

    function formatDate($date){
        if(empty($date)){
            return null;
        }
        $dateBits = explode('/', $date);
        return sprintf("%04d-%02d-%02d", $dateBits[2], $dateBits[0], $dateBits[1]);
    }

    /**
     * getTargetDirectory retrieves info about where the file should be stored.
     *
     * The returned directory is ADDED to the baseUploadDirectory proprety.  It should have a trailing slash.
     *
     * @param     string  $file    The full filename including directory.
     *
     * @return    bool    $success		if operation succeeded
     * @access    public
     */
    function getTargetDirectory(&$file, $args){
        // Uploaded file goes directly in the media directory (no subdirectory needs to be created)
        return "";
    }

    /**
     * constraint check for page 6
     */
    function constraint_rules_pg6($values) {
        $errors = [];
        if (!empty($values["captured_cycle"]) && !is_numeric($values["captured_cycle"])) {
            $errors["captured_cycle"] = 'The value should be three digits.';
        }
        if (!empty($values["acquisition_window"]) && !is_numeric($values["acquisition_window"])) {
            $errors["acquisition_window"] = 'The value should be three digits.';
        }

        return $errors;
    }


    private function not_required_field($key) {
        return $this->XINRegisterRule(
            $key,
            array("{$key}{@}=={@}NEVER_REQUIRED"),
            "Not required"
        );
    }

    function score(): void{
        if ($this->_determineDataEntryCompletionStatus() == 'Incomplete') {
            return;
        }

        // Get the item scores
        $db =& Database::singleton();
        $query = "SELECT * FROM ".$this->table." WHERE CommentID=:cid";
        $record = $db->pselectRow($query, array('cid' => $this->getCommentID()));

        $scores = array();

        $grp = ['t1_pass', 't2_pass', 'bold_pass', 'dti_pass'];
        foreach ($grp as $key) {
            $scores["{$key}_msg"] = $this->yes_no[$record[$key]] ?? $record[$key];
        }

        // save scores
        $db->update($this->table, $scores, array('CommentID'=>$this->getCommentID()));
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
            "<b>Session Date<b>"
         );
	   $group[] = $this->form->createElement(
            "static",
            null,
            null,
            "<b>Time Entered Room(HH:MM)</b>"
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
            "<b>Orientation<b>"
        );
        $group[] = $this->form->createElement(
            "static",
            null,
            null,
            "<b>Vitamin E<b>"
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
