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

    private $yes_no = array(
            null           => '',
            '0'           => 'No',
            '1'          => 'Yes'
    );

    private $study_grp = [
        'ep' => 'IBIS-EP',
        'ds' => 'Infant-DS',
        'ds_ctrl' => 'Infant-DS Ctrl'
    ];

    
    private $orientation_grp = [
        'supine' => 'Supine',
        'leftlat' => 'Left Lateral',
        'rightlat' => 'Right Lateral'
    ];

    private $vitamine_grp = [
        'left' => 'Left',
        'right' => 'Right'
    ];

    private $bold_grp = ['b1_' => 'Bold 1',
            'b2_' => 'Bold 2',
            'b3_' => 'Bold 3',
            'blast1_' => 'Last'];

    private $bold_plus_grp = ['b4_' => 'Bold 4',
            'blast2_' => 'Last'];

    private $bold_firmm_grp = ['bp1_' => 'BOLD_PA 1',
            'bp2_' => 'BOLD_PA 2',
            'bp3_' => 'BOLD_PA 3'];

    private $bold_plus_firmm_grp = ['bp4_' => 'BOLD_PA 4'];

    private $dti_grp = [
            '101b0' => [0 => '101 B0', 1 => 'DWI dir101 B0'],
            'dti1' => [0 => 'DTI 1', 1 => 'DWI dir101 AP'],
            'dti2' => [0 => 'DTI 2', 1 => 'DWI dir101 APinv'],
            '105b0' => [0 => '105 B0', 1 => 'DWI dir105 B0'],
            'dti3' => [0 => 'DTI 3', 1 => 'DWI dir105 AP'],
            'dti4' => [0 => 'DTI 4', 1 => 'DWI dir105 APinv']
        ];

    public function getFullName(): string
    {
        return 'IBIS EP & Infant DS param Form';
    }


    function getSubtestList(): array {
        return [['Name' => 'mri_parameter_ep_page1', 'Description' => 'Record'],
                ['Name' => 'mri_parameter_ep_page2', 'Description' => 'Structuaral'],
                ['Name' => 'mri_parameter_ep_page3', 'Description' => 'BOLD'],
                ['Name' => 'mri_parameter_ep_page4', 'Description' => 'DTI'],
                ['Name' => 'mri_parameter_ep_page5', 'Description' => 'BOLD+']];
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
    function setup($commentID = null, $page = null)
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

        //The array of selects with multiple answers allowed
        //Any LorisForm multiple selects must be listed here
        $this->_selectMultipleElements = array();

        // required fields for data entry completion status
        $this->_requiredElements = array(
            'Examiner',
            'CommentID',
        );

        //The array of selects with multiple answers allowed
        //Any LorisForm multiple selects must be listed here
        $this->_selectMultipleElements = [
            'study',
            'orientation',
            'vitamine'];

        $this->db =& Database::singleton();

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

        $this->form->addElement('static', 't1_pass_msg', 'T1 Passed');
        $this->form->addElement('static', 't2_pass_msg', 'T2 Passed');
        $this->form->addElement('static', 'bold_pass_msg', 'BOLD Passed');
        $this->form->addElement('static', 'dti_pass_msg', 'DTI Passed');

        $this->addLabel('');

        $this->addLabel('Phase encode angle calculation:');
        $group = array();
        $group[] = $this->form->createElement('static', null, null, 'if AP angle is Positive');
        $group[] = $this->form->createElement('static', null, null, 'if AP angle is Negative');
        $this->form->addGroup($group, 'sec01_header', '', $this->_GUIDelimiter, FALSE);
        unset($group);

        $group = array();
        $grp = ['-180', '180'];
        foreach ($grp as $key) {
            $group[] = $this->form->createElement('static', null, null, "$key +");
        }

        $this->form->addGroup($group, 'sec01_row', '', $this->_GUIDelimiter, FALSE);
        unset($group);

        $grp = ['ap_p', 'ap_n'];
        for ($i = 0; $i < 2; $i++) {
            $group = array();
            foreach ($grp as $idx => $key) {

                $group[] = $this->createText("$key{$i}");
                $this->not_required_field("$key{$i}");
            }
            $this->form->addGroup($group, "sec01_row{$i}", "", $this->_GUIDelimiter, FALSE);
            unset($group);
        }

        $this->addLabel('');

        $group = array();
        $group[] = $this->form->createElement('static', null, null, 'AP angle');
        $group[] = $this->form->createElement('static', null, null, 'PA angle');
        $this->form->addGroup($group, 'sec02_header', '', $this->_GUIDelimiter, FALSE);
        unset($group);

        $grp = ['-10' => '170',
                '-5' => '175',
                '0' => '180',
                '5' => '-175',
                '10' => '-170'];

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
                'Field Map AP' => '_SpinEchoFieldMap_AP3mm',
                'BOLD_PA' => 'BOLD_PA_ep2d_3mm52sl475slMB4',
                '101_AP' => 'DWIcmrr_AP_dir101_3shell',
                '101_APinv' => 'DWIcmrr_APinv_dir101_3shell',
                '105_AP' => 'DWIcmrr_AP_dir105_3shell',
                '105_Apinv' => 'DWIcmrr_APinv_dir105_3shell'];

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
    }


    /**
     * Page 1
     *
     * @return void
     */
    function _page1()
    {
        $this->addLabel('Record');

        $grp = ["study" => 'Study:',
                "orientation" => 'Orientation:',
                "vitamine" => 'Vitamin E:'];

        foreach ($grp as $key => $label) {
            $group_arr = "{$key}_grp";
            $this->addSelect($key, $label, $this->$group_arr, array('multiple'));
            $this->form->addRule($key, $label . ' must be set', 'required');
         
        }
        
        $this->addTextElement(
            'time_enter',
            'Time entered room:'
        );

        $group = array();
        $group[] = $this->form->createElement('static', null, null, 'Scan start:');
        $group[] = $this->form->createElement('static', null, null, 'Scan end:');
        $this->form->addGroup($group, 'sec1_header', '', $this->_GUIDelimiter, FALSE);
        unset($group);

        $grp = ['start', 'end'];
        for ($i = 0; $i < 4; $i++) {
            $group = array();
            foreach ($grp as $key) {
                $group[] = $this->createText("$key{$i}");
                $this->not_required_field("$key{$i}");
            }
            $this->form->addGroup($group, "sec1_row{$i}", '', $this->_GUIDelimiter, FALSE);
            unset($group);
        }

    }


    /**
     * Page 2
     *
     * @return void
     */
    function _page2()
    {
        $this->addLabel('Structuaral');

        $group = array();
        $group[] = $this->form->createElement('static', null, null, 'T1');
        $group[] = $this->form->createElement('static', null, null, 'T2');
        $group[] = $this->form->createElement('static', null, null, 'Anterior');
        $group[] = $this->form->createElement('static', null, null, 'Superior');
        $group[] = $this->form->createElement('static', null, null, 'Anterior / Superior');
        $group[] = $this->form->createElement('static', null, null, 'Pass?');
        $this->form->addGroup($group, 'sec1_header', '', $this->_GUIDelimiter, FALSE);
        unset($group);

        $grp1 = ['t1_', 't2_'];
        $grp2 = ['anterior', 'superior', 'ant_d_sup'];

        for ($i = 0; $i < 6; $i++) {

            foreach ($grp1 as $key) {
                $group[] = $this->createSelect("$key{$i}", '', $this->yes_no);
                $this->not_required_field("$key{$i}");
            }

            foreach ($grp2 as $key) {
                $group[] = $this->createText("$key{$i}");
                $this->not_required_field("$key{$i}");
            }

            $group[] = $this->createSelect("s_pass{$i}", '', $this->yes_no);
            $this->not_required_field("s_pass{$i}");

            $this->form->addGroup($group, "sec2_row{$i}", '', $this->_GUIDelimiter, FALSE);
            unset($group);
        }

        for ($i = 1; $i < 3; $i ++) {
            $this->addSelect("t{$i}_pass", "T{$i} Passed", $this->yes_no);
            $this->form->addRule("t{$i}_pass", "T{$i} Passed must be set", 'required');
        }

        $this->addLabel('Fails if Ant/Sup > 2.5; needs one T1 and one T2 to pass');
        $this->form->addFormRule(array(&$this, 'constraint_rules1'));
    }


    /**
     * constraint check for page 2
     */
    function constraint_rules1($values) {
        $errors = [];
       
        $fail = false;
        for ($i = 0; $i < 6; $i++) {
            if (floatval($values["ant_d_sup{$i}"]) > 2.5 && $values["s_pass{$i}"]) {
                $errors["sec2_row{$i}"] = 'Because Ant/Sup > 2.5, this line doesn\'t pass';
                $fail = true;
            }
        }
        $grp = ['t1_', 't2_'];
        $cnt_1 = 0;
        $cnt_2 = 0;
        for ($i = 0; $i < 6; $i++) {
            if ($values["t1_{$i}"] == '1') {
                $cnt_1 ++;
            }
            if ($values["t2_{$i}"] == '1') {
                $cnt_2 ++;
            }
        }
        if ($values["t1_pass"] == '1' && $cnt_1 == 0) {
            $errors["sec2_row0"] = 'Needs one T1 to pass';
        }
        else if ($values["t2_pass"] == '1' && $cnt_2 == 0) {
            $errors["sec2_row0"] = 'Needs one T2 to pass';
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
        $this->addLabel('BOLD');

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
        $group[] = $this->form->createElement('static', null, null, 'Ran?');
        $group[] = $this->form->createElement('static', null, null, '');
        $group[] = $this->form->createElement('static', null, null, 'FIRMM');
        $group[] = $this->form->createElement('static', null, null, '%0.2mm');
        $group[] = $this->form->createElement('static', null, null, 'Pass?');
        $this->form->addGroup($group, 'sec3_2_header', '', $this->_GUIDelimiter, FALSE);
        unset($group);

        $i = 0;
        foreach ($this->bold_firmm_grp as $key => $label) {
            $group = array();
            $group[] = $this->createSelect("{$key}run{$i}", '', $this->yes_no);
            $this->not_required_field("{$key}run{$i}");
            
            $group[] = $this->form->createElement('static', null, null, $label);
            
            $group[] = $this->createSelect("{$key}firmm_{$i}", '', $this->yes_no);
            $this->not_required_field("{$key}firmm_{$i}");

            $group[] = $this->createText("{$key}02_{$i}", '');
            $this->not_required_field("{$key}02_{$i}");

            $group[] = $this->createSelect("{$key}pass_{$i}", '', $this->yes_no);
            $this->not_required_field("{$key}pass_{$i}");

            $this->form->addGroup($group, "sec3_2_row{$i}", '', $this->_GUIDelimiter, FALSE);
            unset($group);
            $i++;
        }
        $this->addLabel('run fails if % 0.2mm < 70%; needs 3 BOLD runs to pass');

        $this->addSelect('bold_pass', 'BOLD Passed', $this->yes_no);
        //$this->form->addRule("bold_pass", "BOLD Passed must be set", 'required');

        $this->addLabel('PE direction will default to L >> R. Please set to A >> P, then edit the angle to set P >> A');
        $this->form->addFormRule(array(&$this, 'constraint_rules2'));
    }


    /**
     * constraint check for page 3
     */
    function constraint_rules2($values) {
        $errors = [];
        $i = 0;
        foreach ($this->bold_firmm_grp as $key => $label) {
            if (floatval($values["{$key}02_{$i}"]) < 70 && !empty($values["{$key}pass_{$i}"])) {
                $errors["sec3_2_row{$i}"] = 'Because % 0.2mm < 70%, this line doesn\'t pass';
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
        $this->addLabel('DTI');

        $group = array();
        $group[] = $this->form->createElement('static', null, null, '');
        $group[] = $this->form->createElement('static', null, null, 'Ran?');
        $group[] = $this->form->createElement('static', null, null, '');
        $group[] = $this->form->createElement('static', null, null, 'slices that failed');
        $group[] = $this->form->createElement('static', null, null, 'Pass?');
        $this->form->addGroup($group, 'sec4_header', '', $this->_GUIDelimiter, FALSE);
        unset($group);

        $i = 0;
        foreach ($this->dti_grp as $key => $label) {
            $group = array();
            $group[] = $this->form->createElement('static', null, null, $label[0]);
            $group[] = $this->createSelect("{$key}run{$i}", '', $this->yes_no);
            $this->not_required_field("{$key}run{$i}");

            $group[] = $this->form->createElement('static', null, null, $label[1]);
            $group[] = $this->createText("{$key}fail{$i}", '');
            $this->not_required_field("{$key}fail{$i}");

            $group[] = $this->createSelect("{$key}pass{$i}", '', $this->yes_no);
            $this->not_required_field("{$key}pass{$i}");

            $this->form->addGroup($group, "sec4_row{$i}", "", $this->_GUIDelimiter, FALSE);
            unset($group);
            $i++;
        }

        $this->addLabel('Verify phase encode dirction : should be AP for both AP and APinv sequences');
        $this->addSelect('dti_pass', 'DTI Passed', $this->yes_no);
        $this->addLabel('PE direction will default to L >> R. Please set to A >> P, then edit the angle to set P >> A');
    }


    /**
     * Page 5
     *
     * @return void
     */
    function _page5()
    {
        $this->addLabel('BOLD');

        $group = array();
        $group[] = $this->form->createElement('static', null, null, '');
        $group[] = $this->form->createElement('static', null, null, 'Ran?');
        $group[] = $this->form->createElement('static', null, null, '');
        $this->form->addGroup($group, 'sec5_header', '', $this->_GUIDelimiter, FALSE);
        unset($group);

        $i = 0;
        foreach ($this->bold_plus_grp as $key => $label) {
            $group = array();
            $group[] = $this->form->createElement('static', null, null, $label);

            $group[] = $this->createSelect("{$key}run{$i}", '', $this->yes_no);
            $this->not_required_field("{$key}run{$i}");

            $group[] = $this->form->createElement('static', null, null, 'Field Map Apinv, Field Map AP');

            $this->form->addGroup($group, "sec5_row{$i}", '', $this->_GUIDelimiter, FALSE);
            unset($group);
            $i++;
        }

        $group = array();
        $group[] = $this->form->createElement('static', null, null, 'Ran?');
        $group[] = $this->form->createElement('static', null, null, '');
        $group[] = $this->form->createElement('static', null, null, 'FIRMM');
        $group[] = $this->form->createElement('static', null, null, '%0.2mm');
        $group[] = $this->form->createElement('static', null, null, 'Pass?');
        $this->form->addGroup($group, 'sec5_2_header', '', $this->_GUIDelimiter, FALSE);
        unset($group);

        $i = 0;
        foreach ($this->bold_plus_firmm_grp as $key => $label) {
            $group = array();

            $group[] = $this->createSelect("{$key}run{$i}", '', $this->yes_no);
            $this->not_required_field("{$key}run{$i}");

            $group[] = $this->form->createElement('static', null, null, $label);
            $group[] = $this->createSelect("{$key}firmm_{$i}", '', $this->yes_no);
            $this->not_required_field("{$key}firmm_{$i}");

            $group[] = $this->createText("{$key}02_{$i}", '');
            $this->not_required_field("{$key}02_{$i}");

            $group[] = $this->createSelect("{$key}pass_{$i}", '', $this->yes_no);
            $this->not_required_field("{$key}pass_{$i}");

            $this->form->addGroup($group, "sec5_2_row{$i}", '', $this->_GUIDelimiter, FALSE);
            unset($group);
            $i++;
        }
        $this->addLabel('Please set to A >> P, then edit the angle to set P >> A');
    }

    private function not_required_field($key) {
        return $this->XINRegisterRule(
            $key,
            array("{$key}{@}=={@}NEVER_REQUIRED"),
            "Not required"
        );
    }

    private function translate_yes_no_msg($key) {
        if (isset($this->yes_no[$key])) {
            return $this->yes_no[$key];
        }
        return $key;
    }

    function score() {
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
            $scores["{$key}_msg"] = $this->translate_yes_no_msg($record[$key]);
        }

        // save scores
        $db->update($this->table, $scores, array('CommentID'=>$this->getCommentID()));
    }
}
