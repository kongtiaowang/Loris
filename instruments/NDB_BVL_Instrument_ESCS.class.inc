<?php
/**
 * This file contains the NDB_BVL_Instrument_ESCS
 * class
 *
 * PHP Version 7
 *
 * @category Instrument
 * @package  IBIS
 * @author   Ling Ma <lingyun.ma@mcin.ca>
 * @date     2019 Dec 11
 * @license  http://www.gnu.org/licenses/gpl-3.0.txt GPLv3
 * @link     https://www.github.com/aces/IBIS/
 */

class NDB_BVL_Instrument_ESCS extends NDB_BVL_Instrument
{
    use LegacyInstrumentTrait;
    var $ValidityEnabled  = false;
    var $ValidityRequired = false;

    private $max_trial = 20;

    private $yes_no = array(
             null           => '',
             '0'           => 'N',
             '1'          => 'Y'
        ); // Here we use N, Y instead of No, Yes because No Yes will not be visible with so many items on the same screen.

    private $ija_grp1 = [
            "ija_ec" => "Eye Contact (EC)",
            "ija_al" => "Alternate"
        ];

    private $ija_grp2 = [
            "ija_pt" => "Point",
            "ija_pt_ec" => "Point & EC",
            "ija_sh" => "Show"
        ];

    private $ija_grp3 = ["ija_care" => "Bid to Caregiver"];
        
    private $rja_grp1 = [
            'rja_fo' => 'Follows Point'
        ];

    private $rja_grp2 = [
            'rja_left' => 'Left',
            'rja_back_left' => 'Back Left',
            'rja_right' => 'Right',
            'rja_back_right' => 'Back Right'
        ];

    private $imitation_grp = [
            'im' => 'Point in Imitation'
        ];

    private $ibr_grp1 = [
            'ibr_ec' => 'Eye Contact (EC)',
            'ibr_re' => 'Reach',
            'ibr_ap' => 'Appeal'
        ];

    private $ibr_grp2 = [
            'ibr_pt' => 'Point',
            'ibr_pt_ec' => 'Point & EC',
            'ibr_gv' => 'Give',
            'ibr_gv_ec' => 'Give & EC'
        ];
    
    private $ibr_grp3 = ["ibr_care" => "Bid to Caregiver"];

    private $rbr_grp1 = [
            'rbr_wo_g_p' => 'Pass',
            'rbr_wo_g_f' => 'Fail'
        ];

    private $rbr_grp2 = [
            'rbr_w_g_p' => 'Pass',
            'rbr_w_g_f' => 'Fail'
        ];


    public function getFullName(): string
    {
        return "Early Social Communication Scales";
    }


    function getSubtestList(): array {
        return [['Name' => 'ESCS_page1', 'Description' => "IJA & RJA"],
                ['Name' => 'ESCS_page2', 'Description' => "IBR & RBR"]];
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
        $this->testName  = 'ESCS'; // test_names.Test_name
        $this->table     = 'ESCS';
        $this->commentID = $commentID; // data keyed by commentID

        //The array of dates/timestamps to convert to database dates/timestamps
        //Any LorisForm date elements must be listed here
        $this->dateTimeFields = array(
            "Date_taken"
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
        $this->_selectMultipleElements = [];

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
        if (preg_match("/ESCS(_page[0-9]+)/", 
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
        $this->addHeader("Early Social Communication Scales");

        // automatically adds examiner & date of administration
        $this->_addMetadataFields();

        $this->addLabel('');
        $group = array();
        
        $group_total = ['',
            "Lower-Level Total",
            "Higher-Level Total",
            "Total",
            "Bid to Caregiver Total"];

        foreach ($group_total as $label) {
            $group[] = $this->form->createElement('static', null, null, $label);
        }
        $this->form->addGroup($group, "sec1_header", "", $this->_GUIDelimiter, FALSE);
        unset($group);

        $ija_ibr_lst = [
            'Initiating Joint Attention' => ['ija_lower_total',
                'ija_higher_total',
                'ija_total',
                'ija_bid_caregiver_total'],
            'Initiating Behavioral Requests' => ['ibr_lower_total',
                'ibr_higher_total',
                'ibr_total',
                'ibr_bid_caregiver_total']
        ];

        $cnt = 0;
        foreach ($ija_ibr_lst as $label => $lst) {
            $cnt ++;
            $group = array();
            $group[] = $this->form->createElement('static', null, null, $label);
            
            foreach ($lst as $key) {
                $group[] = $this->form->createElement('static', $key);
            }
            $this->form->addGroup($group, "sec1_row{$cnt}", "", $this->_GUIDelimiter, FALSE);
            unset($group);
        }

        $this->addLabel("Responding to Joint Attention");

        $this->form->addElement('static', 'rja_follows_pt_sum', "Follows Point Total:");
        
        $this->form->addElement('static', 'rja_line_regard_pt_correct', "Line of Regard % Correct:");
        $this->form->addElement('static', 'rja_pt_sum', "RJA Total:");

        $this->addLabel("");
        $this->addLabel("Responding to Behavioral Requests");

        $group_total = ["",
            "Pass Total",
            "Fail Total"];
        
        foreach ($group_total as $label) {
            $group[] = $this->form->createElement('static', null, null, $label);
        }
        $this->form->addGroup($group, "sec2_header", "", $this->_GUIDelimiter, FALSE);
        unset($group);

        $rbr_lst = [
            'Without Gesture' => [
                'rbr_without_g_pass_sum',
                'rbr_without_g_fail_sum'
            ],
            'With Gesture' => [
                'rbr_with_g_pass_sum',
                'rbr_with_g_fail_sum'
            ]
        ];

        $cnt = 0;
        foreach ($rbr_lst as $label => $lst) {
            $cnt ++;
            $group = array();
            $group[] = $this->form->createElement('static', null, null, $label);

            foreach ($lst as $key) {
                $group[] = $this->form->createElement('static', $key);
            }
            $this->form->addGroup($group, "sec2_row{$cnt}", "", $this->_GUIDelimiter, FALSE);
            unset($group);
        }

        $this->form->addElement('static', 'rbr_correct', "RBR % Correct: ");
        $this->form->addElement('static', 'rbr_total', "RBR Total:");

        $this->form->addElement('static', 'pt_imitation_sum', "Point in Imitation Total:");
       
        $this->addLabel("Notes:");
        $this->form->addElement('static', 'note1');
        $this->form->addElement('static', 'note2');
    }


    private function page_section($group_arr, $section, $info='') {
        $group = array();

        for ($i = 0; $i <= $this->max_trial; $i++) {
            if ($i == 0){
                $group[] = $this->form->createElement('static', null, null, $info);
            }
            else {
                $group[] = $this->form->createElement('static', null, null, $i);
            }
        }

        $this->form->addGroup($group, "sec{$section}_header", "", $this->_GUIDelimiter, FALSE);
        unset($group);

        foreach ($group_arr as $key => $label) {
            $group = array();
            for ($i = 0; $i <= $this->max_trial; $i++) {
                if ($i == 0) {
                    $group[] = $this->form->createElement('static', null, null, $label);
                }
                else {
                    $group[] = $this->createSelect("$key$i", "", $this->yes_no);
                    $this->not_required_field("$key$i");
                }
            }
            $this->form->addGroup($group, "sec{$section}_row{$key}", "", $this->_GUIDelimiter, FALSE);
            unset($group);
        }
    }


    private function page_section2($group_arr, $section) {
        $group = array();

        $group[] = $this->form->createElement('static', null, null, '');
        foreach ($group_arr as $key => $label) {
            $group[] = $this->form->createElement('static', null, null, $label);
        }

        $this->form->addGroup($group, 'sec{$section}_header', "", $this->_GUIDelimiter, FALSE);
        unset($group);

        for ($i = 1; $i <= 2; $i++) {
            $group = array();
            $group[] = $this->form->createElement('static', null, null, "Trail {$i}");
            
            foreach ($group_arr as $key => $label) {
                $group[] = $this->createSelect("$key$i", "", $this->yes_no);
                $this->not_required_field("$key$i");
            }
            $this->form->addGroup($group, "sec{$section}_row$i", "", $this->_GUIDelimiter, FALSE);
            unset($group);

            $group = array();
            $group[] = $this->form->createElement('static', null, null, "&nbsp;&nbsp;Delayed");
            
            foreach ($group_arr as $key => $label) {
                $group[] = $this->createSelect("{$key}_d_{$i}", "", $this->yes_no);
                $this->not_required_field("{$key}_d_{$i}");
            }
            $this->form->addGroup($group, "sec{$section}_row{$i}d", "", $this->_GUIDelimiter, FALSE);
        }
    }


    /**
     * Page 1
     *
     * @return void
     */
    function _page1()
    {
        $this->addLabel('Initiating Joint Attention');

        $this->page_section($this->ija_grp1, 1);
        $this->addLabel('');
        
        $this->page_section($this->ija_grp2, 2);
        
        $this->addLabel('Bid to caregiver');
        $this->page_section($this->ija_grp3, 3);

        $this->addLabel('Responding to Joint Attention');

        $this->page_section($this->rja_grp1, 4);

        $this->addLabel('');
        $this->page_section2($this->rja_grp2, 5);
        $this->addLabel('');

        $this->page_section($this->imitation_grp, 6);

        $this->addBasicTextArea('note1', 'Notes');
        
        $this->not_required_field('note1');

        $this->form->addFormRule(array(&$this, 'conflict_rules1'));
    }


    /**
     * Page 2
     *
     * @return void
     */
    function _page2()
    {
        $this->addLabel('Initiating Behavioral Requests');

        $this->page_section($this->ibr_grp1, 1);
        $this->addLabel('');
        
        $this->page_section($this->ibr_grp2, 2);
        
        $this->addLabel('Bid to caregiver');
        $this->page_section($this->ibr_grp3, 3);

        $this->addLabel('Responding to Behavioral Requests');

        $this->page_section($this->rbr_grp1, 4, "Without Gesture");

        $this->addLabel('');
        $this->page_section($this->rbr_grp2, 5, "With Gesture");

        $this->addBasicTextArea('note2', 'Notes');

        $this->not_required_field('note2');

        $this->form->addFormRule(array(&$this, 'conflict_rules2'));
    }


    /**
     * Conflict check for page 1
     */
    function conflict_rules1($values) {
        $errors = [];
        for ($i = 1; $i <= 2; $i++) {
            foreach ($this->rja_grp2 as $key => $label) {
                if (!empty($values["{$key}{$i}"]) && !empty($values["{$key}_d_{$i}"])) {
                    $errors["sec5_row{$i}"] = "You could not have both $label and delayed as passed.";
                    $errors["sec5_row{$i}d"] = "You could not have both $label and delayed as passed.";
                }
            }
        }
        return $errors;
    }


    /**
     * Conflict check for page 2
     */
    function conflict_rules2($values) {
        $errors = [];
        for ($i = 1; $i <= $this->max_trial; $i++) {
            if (!empty($values["rbr_wo_g_p$i"]) && !empty($values["rbr_wo_g_f$i"])) {
                $errors["sec4_rowrbr_wo_g_p"] = "You could not have both pass and fail at the same time at Without Gesture $i";
                $errors["sec4_rowrbr_wo_g_f"] = "You could not have both pass and fail at the same time at Without Gesture $i";
            }
        }

        for ($i = 1; $i <= $this->max_trial; $i++) {
            if (!empty($values["rbr_w_g_p$i"]) && !empty($values["rbr_w_g_f$i"])) {
                $errors["sec5_rowrbr_w_g_p"] = "You could not have both pass and fail at the same time at With Gesture $i";
                $errors["sec5_rowrbr_w_g_f"] = "You could not have both pass and fail at the same time at With Gesture $i";
            }
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


    /**
     * Score
     */
    function score(): void
    {
        if($this->_determineDataEntryCompletionStatus() == "Incomplete") {
            return;
        }

        $record = $this->db->pselectRow("SELECT * FROM $this->table WHERE CommentID=:cid", array("cid" =>$this->getCommentID() ));

        $calculated = [];

        $lst = ['ija_lower_total' => 'ija_grp1',
            'ija_higher_total' => 'ija_grp2',
            'ija_bid_caregiver_total' => 'ija_grp3',
            'rja_follows_pt_sum' => 'rja_grp1',
            'pt_imitation_sum' => 'imitation_grp',
            'ibr_lower_total' => 'ibr_grp1',
            'ibr_higher_total' => 'ibr_grp2',
            'ibr_bid_caregiver_total' => 'ibr_grp3'];

        foreach ($lst as $lst_index => $grp_index) {
            $cnt = 0;
            foreach ($this->$grp_index as $key => $label) {
                for ($i = 1; $i <= $this->max_trial; $i++) {
                    if (!empty($record["$key$i"])) {
                        $cnt ++;
                    }
                }
            }
            $calculated[$lst_index] = $cnt;
        }
        $calculated['ija_total'] = $calculated['ija_lower_total'] + $calculated['ija_higher_total'];
        $calculated['ibr_total'] = $calculated['ibr_lower_total'] + $calculated['ibr_higher_total'];

        $cnt = 0;
        $zero_cnt = 0;
        for ($i = 1; $i <= 2; $i++) {
            foreach ($this->rja_grp2 as $key => $label) {
                if ($record["{$key}{$i}"] == 1 || $record["{$key}_d_{$i}"] == 1) {
                    $cnt ++;
                }
                else if ((!is_null($record["{$key}{$i}"]) && $record["{$key}{$i}"] == 0) || (!is_null($record["{$key}_d_{$i}"]) && $record["{$key}_d_{$i}"] == 0)) {
                    $zero_cnt ++;
                }
            }
        }

        $cnt_sum = $cnt + $zero_cnt;
        if ($cnt_sum > 0) {
            $calculated['rja_line_regard_pt_correct'] = round($cnt / $cnt_sum * 100, 2);
        }
        else {
            $calculated['rja_line_regard_pt_correct'] = null;
        }
        $calculated['rja_pt_sum'] = $cnt + $calculated['rja_follows_pt_sum'];

        $lst = ['rbr_without_g_pass_sum' => 'rbr_wo_g_p', // rbr_grp1_pass
            'rbr_without_g_fail_sum' => 'rbr_wo_g_f', //rbr_grp1_fail
            'rbr_with_g_pass_sum' =>'rbr_w_g_p',
            'rbr_with_g_fail_sum' => 'rbr_w_g_f'];

        foreach ($lst as $lst_index => $key) {
            $cnt = 0;
            for ($i = 1; $i <= $this->max_trial; $i++) {
                if (!empty($record["$key$i"])) {
                    $cnt ++;
                }
            }
            $calculated[$lst_index] = $cnt;
        }

        $rbr_pass_sum = $calculated['rbr_without_g_pass_sum'] + $calculated['rbr_with_g_pass_sum'];
        $rbr_fail_sum = $calculated['rbr_without_g_fail_sum'] + $calculated['rbr_with_g_fail_sum'];

        $rbr_sum = $rbr_pass_sum + $rbr_fail_sum;
        if (!empty($rbr_sum)) {
            $calculated['rbr_correct'] = round(($rbr_pass_sum / $rbr_sum * 100), 2);
        }
        else {
            $calculated['rbr_correct'] = null;
        }
        $calculated['rbr_total'] = $rbr_sum;

        // Clean the JA section if all are 0 or null
        $ija_rja = ['ija_lower_total',
                'ija_higher_total',
                'ija_total',
                'ija_bid_caregiver_total',
                'rja_follows_pt_sum',
                'rja_line_regard_pt_correct',
                'rja_pt_sum'];
        
        $cnt = 0;
        foreach ($ija_rja as $key) {
            if (!empty($calculated[$key])) {
                $cnt ++;
            }
        }

        if ($cnt == 0) {
            foreach ($ija_rja as $key) {
                $calculated[$key] = null;
            }
        }

        // Clean the BR section if all are 0 or null
        $ibr_rbr = ['ibr_lower_total',
                'ibr_higher_total',
                'ibr_total',
                'ibr_bid_caregiver_total',
                'rbr_without_g_pass_sum',
                'rbr_without_g_fail_sum',
                'rbr_with_g_pass_sum',
                'rbr_with_g_fail_sum',
                'rbr_correct',
                'rbr_total'];

        $cnt = 0;
        foreach ($ibr_rbr as $key) {
            if (!empty($calculated[$key])) {
                $cnt ++;
            }
        }

        if ($cnt == 0) {
            foreach ($ibr_rbr as $key) {
                $calculated[$key] = null;
            }
        }

        //save scores
        if (!empty($calculated)) {
            $result = $this->db->update($this->table, $calculated, array('CommentID'=>$this->getCommentID()));
        }
    }
}
