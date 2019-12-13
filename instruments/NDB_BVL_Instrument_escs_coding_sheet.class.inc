<?php
/**
 * This file contains the NDB_BVL_Instrument_escs_coding_sheet
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

class NDB_BVL_Instrument_escs_coding_sheet extends NDB_BVL_Instrument
{
    var $ValidityEnabled  = false;
    var $ValidityRequired = false;

    private $optional = array('class' => 'form-control input-sm');

    private $max_trial = 20;

    private $yes_no = array(
             null           => '',
             '0'           => '0',
             '1'          => '1'
        );

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
            'ija_fo' => 'Follows Point'
        ];

    private $rja_grp2 = [
            'left' => 'Left',
            'back_left' => 'Back Left',
            'rigft' => 'Rigft',
            'back_rigft' => 'Back Rigft'
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
            'ibr_pt_ec' => 'Pint & EC',
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
        $this->testName  = 'escs_coding_sheet'; // test_names.Test_name
        $this->table     = 'escs_coding_sheet';
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
        if (preg_match("/escs_coding_sheet(_page[0-9]+)/", 
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
        $this->addHeader("Early Social Communication Scales - Coding Sheet");

        // automatically adds examiner & date of administration
        $this->_addMetadataFields();

        $this->addLabel('Initiating Joint Attention');

        $this->form->addElement('static', 'ija_lower_total', "Lower-Level Total:");
        $this->form->addElement('static', 'ija_higher_total', "Higher-Level Total:");
        $this->form->addElement('static', 'ija_total', "IJA Total:");

        $this->form->addElement('static', 'ija_bid_caregiver_total', "Bid to Caregiver Total:");

        $this->addLabel("Responding to Joint Attention");

        $this->form->addElement('static', 'rja_follows_pt_sum', "Follows Point Total:");
        $this->form->addElement('static', 'rja_line_regard_pt_correct', "% Correct (in %):");
        $this->form->addElement('static', 'rja_pt_sum', "RJA Total:");

        $this->form->addElement('static', 'pt_imitation_sum', "Point in Imitation Total:");

        $this->addLabel('Initiating Behavioral Requests');

        $this->form->addElement('static', 'ibr_lower_total', "Lower-Level Total:");
        $this->form->addElement('static', 'ibr_higher_total', "Higher-Level Total:");
        $this->form->addElement('static', 'ibr_total', "IBR Total:");

        $this->form->addElement('static', 'ibr_bid_caregiver_total', "Bid to Caregiver Total:");

        $this->addLabel("Responding to Behavioral Requests");

        $this->addLabel("Without Gesture");
        $this->form->addElement('static', 'rbr_without_g_pass_sum', "Pass Total:");
        $this->form->addElement('static', 'rbr_without_g_fail_sum', "Fail Total:");

        $this->addLabel("With Gesture");
        $this->form->addElement('static', 'rbr_with_g_pass_sum', "Pass Total:");
        $this->form->addElement('static', 'rbr_with_g_fail_sum', "Fail Total:");
        $this->form->addElement('static', 'rbr_correct', "% Correct (in %): ");
        $this->form->addElement('static', 'rbr_total', "RBR Total:");
       
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
            $this->form->addGroup($group, "sec{$section}_row{$key}$i", "", $this->_GUIDelimiter, FALSE);
            unset($group);

            $group = array();
            $group[] = $this->form->createElement('static', null, null, "&nbsp;&nbsp;Delayed");
            
            foreach ($group_arr as $key => $label) {
                $group[] = $this->createSelect("{$key}_d_{$i}", "", $this->yes_no);
                $this->not_required_field("{$key}_d_{$i}");
            }
            $this->form->addGroup($group, "sec{$section}_row{$key}{$i}d", "", $this->_GUIDelimiter, FALSE);
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
    }


    function not_required_field($key) {
        return $this->XINRegisterRule(
                    $key,
                    array("{$key}{@}=={@}NEVER_REQUIRED"),
                    "Not required"
                );
    }


    /**
     * Page 2
     *
     * @return void
     */
    function _page2() {

        $this->addLabel('Initiating Behavioral Requests');

        $this->page_section($this->ibr_grp1, 1);
        $this->addLabel('');
        
        $this->page_section($this->ibr_grp2, 2);
        
        $this->addLabel('Bid to caregiver');
        $this->page_section($this->ija_grp3, 3);

        $this->addLabel('Responding to Behavioral Requests');

        $this->page_section($this->rbr_grp1, 4, "Without Gesture");

        $this->addLabel('');
        $this->page_section($this->rbr_grp2, 5, "With Gesture");

        $this->addBasicTextArea('note2', 'Notes');

        $this->not_required_field('note2');
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

        $cnt = 0;
        foreach ($this->ija_grp1 as $key => $label) {
            for ($i = 1; $i <= $this->max_trial; $i++) {
                if (!empty($record["$key$i"])) {
                    $cnt ++;
                }
            }
        }
        $calculated['ija_lower_total'] = $cnt;

        $cnt = 0;
        foreach ($this->ija_grp2 as $key => $label) {
            for ($i = 1; $i <= $this->max_trial; $i++) {
                if (!empty($record["$key$i"])) {
                    $cnt ++;
                }
            }
        }
        $calculated['ija_higher_total'] = $cnt;
        $calculated['ija_total'] = $cnt + $calculated['ija_lower_total'];

        $cnt = 0;
        foreach ($this->ija_grp3 as $key => $label) {
            for ($i = 1; $i <= $this->max_trial; $i++) {
                if (!empty($record["$key$i"])) {
                    $cnt ++;
                }
            }
        }
        $calculated['ija_bid_caregiver_total'] = $cnt;

        $cnt = 0;
        foreach ($this->rja_grp1 as $key => $label) {
            for ($i = 1; $i <= $this->max_trial; $i++) {
                if (!empty($record["$key$i"])) {
                    $cnt ++;
                }
            }
        }
        $calculated['rja_follows_pt_sum'] = $cnt;

        $cnt = 0;
        for ($i = 1; $i <= 2; $i++) {
            foreach ($this->rja_grp2 as $key => $label) {
                if (!empty($record["$key$i"])) {
                    $cnt ++;
                }
                if (!empty($record["{$key}_d_{$i}"])) {
                    $cnt ++;
                }
            }
        }
        $calculated['rja_line_regard_pt_correct'] = round($cnt / (4*4) * 100, 2);
        $calculated['rja_pt_sum'] = $cnt + $calculated['rja_follows_pt_sum'];

        
        $cnt = 0;
        foreach ($this->imitation_grp as $key => $label) {
            for ($i = 1; $i <= $this->max_trial; $i++) {
                if (!empty($record["$key$i"])) {
                    $cnt ++;
                }
            }
        }
        $calculated['pt_imitation_sum'] = $cnt;

        $cnt = 0;
        foreach ($this->ibr_grp1 as $key => $label) {
            for ($i = 1; $i <= $this->max_trial; $i++) {
                if (!empty($record["$key$i"])) {
                    $cnt ++;
                }
            }
        }
        $calculated['ibr_lower_total'] = $cnt;

        $cnt = 0;
        foreach ($this->ibr_grp2 as $key => $label) {
            for ($i = 1; $i <= $this->max_trial; $i++) {
                if (!empty($record["$key$i"])) {
                    $cnt ++;
                }
            }
        }
        $calculated['ibr_higher_total'] = $cnt;
        $calculated['ibr_total'] = $calculated['ibr_lower_total'] + $cnt;

        $cnt = 0;
        foreach ($this->ibr_grp3 as $key => $label) {
            for ($i = 1; $i <= $this->max_trial; $i++) {
                if (!empty($record["$key$i"])) {
                    $cnt ++;
                }
            }
        }
        $calculated['ibr_bid_caregiver_total'] = $cnt;

        $key = 'rbr_wo_g_p'; //rbr_grp1_pass
        $cnt = 0;
        for ($i = 1; $i <= $this->max_trial; $i++) {
            if (!empty($record["$key$i"])) {
                $cnt ++;
            }
        }
        $calculated['rbr_without_g_pass_sum'] = $cnt;

        $key = 'rbr_wo_g_f'; //rbr_grp1_fail
        $cnt = 0;
        for ($i = 1; $i <= $this->max_trial; $i++) {
            if (!empty($record["$key$i"])) {
                $cnt ++;
            }
        }
        $calculated['rbr_without_g_fail_sum'] = $cnt;


        $rbr_grp1_pass = 'rbr_w_g_p'; // pass
        $cnt = 0;
        for ($i = 1; $i <= $this->max_trial; $i++) {
            if (!empty($record["$key$i"])) {
                $cnt ++;
            }
        }
        $calculated['rbr_with_g_pass_sum'] = $cnt;

        $rbr_grp1_pass = 'rbr_w_g_f'; // fail
        $cnt = 0;
        for ($i = 1; $i <= $this->max_trial; $i++) {
            if (!empty($record["$key$i"])) {
                $cnt ++;
            }
        }
        $calculated['rbr_with_g_fail_sum'] = $cnt;

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

        //save scores
        if (!empty($calculated)) {
            $result = $this->db->update($this->table, $calculated, array('CommentID'=>$this->getCommentID()));
        }
    }
}