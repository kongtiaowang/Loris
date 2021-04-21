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
        $this->_selectMultipleElements = [
            'study',
            'orientation',
            'vitamine'];

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
            $this->addSelect($key, $label, $this->$group_arr, ['multiple' => true, 'required'=> true]);
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
        $this->addLabel('Structural');

        $group = [];
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

        for ($i = 0; $i < $this->pg2_number_of_lines; $i++) {

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

        $this->addLabel('Fails if Ant/Sup > 2.5; needs one T1 and one T2 to pass.');
        $this->form->addFormRule(array(&$this, 'constraint_rules_pg2'));
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
                    $errors["sec2_row{$i}"] = 'The value should be numeric.';
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

        $grp = ['t1_', 't2_'];

        $cnt = [];
        foreach ($grp as $key) {
            $cnt[$key] = 0;
        }

        for ($i = 0; $i < $this->pg2_number_of_lines; $i++) {
            foreach ($grp as $key) {
                if ($values["$key{$i}"] == '1') {
                    $cnt[$key] ++;
                }
            }
        }
        $already_failed = false;
        if ($values["t1_pass"] == '1' && $cnt['t1_'] == 0) {
            $errors["t1_pass"] = 'Needs one T1 to pass.';
            $already_failed = true;
        }

        if ($values["t2_pass"] == '1' && $cnt['t2_'] == 0) {
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
        $group[] = $this->form->createElement('static', null, null, '% 0.2mm');
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

        $this->addLabel('Verify phase encode direction : should be AP for both AP and APinv sequences');
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
}
