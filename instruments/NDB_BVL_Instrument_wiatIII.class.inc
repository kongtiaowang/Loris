<?php
/**
 * This file contains the NDB_BVL_Instrument_wiatIII
 * class
 *
 * PHP Version 5
 *
 * @category Instrument
 * @package  Neuropsych
 * @author   Sruthy Mathew <sruthy.mcin@gmail.com>
 * @license  http://www.gnu.org/licenses/gpl-3.0.txt GPLv3
 * @link     https://www.github.com/aces/
 */
/**
 * Creates the form elements for the wiatIII instrument
 *
 * @category Instrument
 * @package  Neuropsych
 * @author   Sruthy Mathew <sruthy.mcin@gmail.com>
 * @license  http://www.gnu.org/licenses/gpl-3.0.txt GPLv_
 * @link     https://www.github.com/aces/
 */

class NDB_BVL_Instrument_wiatIII extends NDB_BVL_Instrument
{
    public function getFullName(): string
    {
        return '';
    }

    function getSubtestList(): array {
        return [];
    }

    var $ValidityEnabled  = false;
    var $ValidityRequired = false;



    function _rawScoreCalculatorRule($start_count,$end_count,$stop_point,$q_array_name) {

        $db =& Database::singleton();

        // Get the item scores
        $record= $db->pselectRow("SELECT * FROM $this->table WHERE CommentID=:cid", array('cid'=>$this->getCommentID()));
        $raw_score=0;
        if($q_array_name=='math_problem')
        {
            $grade=$record['grade'];
            switch($grade) {
                case ("PK"):
                    $start_count = 1;
                    break;
                case ("K"):
                    $start_count = 8;
                    //adding credits before the start point
                    $raw_score=($start_count-1)*1;
                    break;
                case (1):
                case (2):
                    $start_count = 16;
                    $raw_score=($start_count-1)*1;
                    break;
                case (3):
                    $start_count = 26;
                    $raw_score=($start_count-1)*1;
                    break;
                case (4):
                case (5):
                    $start_count = 30;
                    $raw_score=($start_count-1)*1;
                    break;
                case (6):
                case (7):
                case (8):
                    $start_count = 34;
                    $raw_score=($start_count-1)*1;
                    break;
                case (9):
                case (10):
                    $start_count = 35;
                    $raw_score=($start_count-1)*1;
                    break;

                default:
                    $start_count=40;
                    $raw_score=($start_count-1)*1;


            }
        }
        if($q_array_name=='numerical_operation')
        {
            $grade=$record['grade'];
            switch($grade) {
                case ("PK"):
                    $raw_score=0;
                    break;
                case ("K"):
                case (1):
                    $start_count = 1;
                    break;
                case (2):
                case (3):
                case (4):
                    $start_count = 14;
                    $raw_score=($start_count-1)*1;
                    break;
                default:
                    $start_count=18;
                    $raw_score=($start_count-1)*1;


            }
        }
        if($q_array_name=='oral_discourse')
        {
            $grade=$record['grade'];
            switch($grade) {
                case ("K"):
                case ("PK"):
                case (2):
                case (3):
                case (1):
                    $start_count = 1;
                    break;
                default:
                    $start_count=6;
                    $raw_score=($start_count-1)*1;


            }
        }
        if($q_array_name=='spelling')
        {
            $grade=$record['grade'];
            switch($grade) {
                case ("PK"):
                    $raw_score=0;
                    break;
                case ("K"):
                case (1):
                    $start_count = 1;
                    break;
                case (2):
                    $start_count = 7;
                    $raw_score=($start_count-1)*1;
                    break;
                case (3):
                    $start_count = 9;
                    $raw_score=($start_count-1)*1;
                    break;
                case (4):
                case (5):
                case (6):
                case (7):
                case (8):
                    $start_count = 16;
                    $raw_score=($start_count-1)*1;
                    break;
                default:
                    $start_count=20;
                    $raw_score=($start_count-1)*1;


            }
        }
        for($i=$start_count;$i<=$end_count; $i++)
        {
            $score_stop = array();
            $valid_points= array(1,2);
            if($stop_point==4) {
                array_push($score_stop, $record[$q_array_name . $i], $record[$q_array_name . ($i + 1)], $record[$q_array_name . ($i + 2)], $record[$q_array_name . ($i + 3)]);
            }
            if($stop_point==2)
            {
                array_push($score_stop, $record[$q_array_name . $i], $record[$q_array_name . ($i + 1)]);
            }
            if(count(array_intersect($score_stop,$valid_points)) == 0){
                //if valid points doesn't include in the score_stop array
                return $raw_score;
            }
            if($record[$q_array_name.$i]==1)
            {
                  $raw_score++;
            }
            if($record[$q_array_name.$i]==2)
            {
                $raw_score=$raw_score+2;
            }

        }
        return $raw_score;


    }
    function _rawScoreCalculator($start_count,$end_count, $q_array_name) {

        $db =& Database::singleton();

        // Get the item scores
        $record= $db->pselectRow("SELECT * FROM $this->table WHERE CommentID=:cid", array('cid'=>$this->getCommentID()));
        $raw_score=0;
        if($q_array_name=='wf_')
        {
            $letters = [
                ["B_or_b"],
                ["C_or_c"],
                ["D_or_d"],
                ["E_or_e"],
                ["F_or_f"],
                ["G_or_g"],
                ["H_or_h"],
                ["I_or_i"],
                ["J_or_j"],
                ["K_or_k"],
                ["L_or_l"],
                ["M_or_m"],
                ["N_or_n"],
                ["O_or_o"],
                ["P_or_p"],
                ["Q_or_q"],
                ["R_or_r"],
                ["S_or_s"],
                ["T_or_t"],
                ["U_or_u"],
                ["V_or_v"],
                ["W_or_w"],
                ["X_or_x"],
                ["Y_or_y"],
                ["Z_or_z"]
            ];
            for ($i=0; $i<count($letters);$i++){
                for ($j=0; $j<count($letters[0]); $j++){
                    if($record[ "wf_{$letters[$i][$j]}"]=='on')
                    {
                        $raw_score++;
                    }

                }

            }

        }
        else {
            for ($i = $start_count; $i <= $end_count; $i++) {


                if ($record[$q_array_name . $i] == 1 || $record[$q_array_name . $i] =='on') {
                    $raw_score++;
                }
                if ($record[$q_array_name . $i] == 2) {
                    $raw_score = $raw_score + 2;
                }

            }
        }
        return $raw_score;


    }
    function _getGradeCandidate()
    {
        $db =& Database::singleton();

        // Get the item scores
        $record= $db->pselectRow("SELECT grade FROM $this->table WHERE CommentID=:cid", array('cid'=>$this->getCommentID()));
            $grade=$record['grade'];
            return $grade;
    }
    function wiatIII_Rules($values) {
        $errors = array();
        for ($i=0; $i<16; $i++) {
            $array_vals_1 = array("oral_completion_", "oral_additional_errors_", "oral_errors_");
            foreach ($array_vals_1 as $vals1) {
                if (!is_numeric($values[$vals1.$i]) && $values[$vals1.$i]!=="") {
                    $errors["oral_fluency_raw_table".$i] = "Value must be numeric";
                }

            }
        }

        return $errors;
    }
    function _scoreOR($score_subset,$t,$a,$o)
    {
        $db =& Database::singleton();

        // Get the item scores
        $record= $db->pselectRow("SELECT * FROM $this->table WHERE CommentID=:cid", array('cid'=>$this->getCommentID()));
        $grade=$record['grade'];
        $items = [
            ["Passage A",1,33],
            ["Passage A",1,33],
            ["Passage B",2,93],
            ["Passage C",3,97],
            ["Passage D",4,96],
            ["Passage E",5,99],
            ["Passage F",6,113],
            ["Passage G",7,119],
            ["Passage H",8,136],
            ["Passage I",9,201],
            ["Passage J",10,258],
            ["Passage K",11,213],
            ["Passage L",12,207],
            ["Passage M",13,298],
            ["Passage N",14,194],
            ["Passage O",15,212],
            ["Passage P",16,163]
        ];
        $score_orf=0;
        $g=2;
        switch ($grade){
            case 1:
                $i=1;
                $f=2;
                $w_sum=$items[$i][$g]+$items[$f][$g];
                $t_sum=$record[$t.$i]+$record[$t.$f];
                $a_sum= $record[$a.$i]+$record[$a.$f];
                $o_sum= $record[$o.$i]+$record[$o.$f];
                $score_orf=round((($w_sum-$o_sum)/$t_sum)*60);
                $score_ora=$w_sum-($a_sum+$o_sum);
                $score_orr=$t_sum;
                break;
            case 2:
                $i=3;
                $f=4;
                $w_sum=$items[$i][$g]+$items[$f][$g];
                $t_sum=$record[$t.$i]+$record[$t.$f];
                $a_sum= $record[$a.$i]+$record[$a.$f];
                $o_sum= $record[$o.$i]+$record[$o.$f];
                $score_orf=round((($w_sum-$o_sum)/$t_sum)*60);
                $score_ora=$w_sum-($a_sum+$o_sum);
                $score_orr=$t_sum;
                break;
            case 3:
                $i=5;
                $f=6;
                $w_sum=$items[$i][$g]+$items[$f][$g];
                $t_sum=$record[$t.$i]+$record[$t.$f];
                $a_sum= $record[$a.$i]+$record[$a.$f];
                $o_sum= $record[$o.$i]+$record[$o.$f];
                $score_orf=round((($w_sum-$o_sum)/$t_sum)*60);
                $score_ora=$w_sum-($a_sum+$o_sum);
                $score_orr=$t_sum;
                break;
            case 4:
                $i=7;
                $f=8;
                $w_sum=$items[$i][$g]+$items[$f][$g];
                $t_sum=$record[$t.$i]+$record[$t.$f];
                $a_sum= $record[$a.$i]+$record[$a.$f];
                $o_sum= $record[$o.$i]+$record[$o.$f];
                $score_orf=round((($w_sum-$o_sum)/$t_sum)*60);
                $score_ora=$w_sum-($a_sum+$o_sum);
                $score_orr=$t_sum;
                break;
            case 5:
                $i=9;
                $f=10;
                $w_sum=$items[$i][$g]+$items[$f][$g];
                $t_sum=$record[$t.$i]+$record[$t.$f];
                $a_sum= $record[$a.$i]+$record[$a.$f];
                $o_sum= $record[$o.$i]+$record[$o.$f];
                $score_orf=round((($w_sum-$o_sum)/$t_sum)*60);
                $score_ora=$w_sum-($a_sum+$o_sum);
                $score_orr=$t_sum;
                break;
            case 6:
                $i=11;
                $f=12;
                $w_sum=$items[$i][$g]+$items[$f][$g];
                $t_sum=$record[$t.$i]+$record[$t.$f];
                $a_sum= $record[$a.$i]+$record[$a.$f];
                $o_sum= $record[$o.$i]+$record[$o.$f];
                $score_orf=round((($w_sum-$o_sum)/$t_sum)*60);
                $score_ora=$w_sum-($a_sum+$o_sum);
                $score_orr=$t_sum;
                break;
            case 7:
            case 8:
                $i=13;
                $f=14;
                $w_sum=$items[$i][$g]+$items[$f][$g];
                $t_sum=$record[$t.$i]+$record[$t.$f];
                $a_sum= $record[$a.$i]+$record[$a.$f];
                $o_sum= $record[$o.$i]+$record[$o.$f];
                $score_orf=round((($w_sum-$o_sum)/$t_sum)*60);
                $score_ora=$w_sum-($a_sum+$o_sum);
                $score_orr=$t_sum;
                break;
            default:
                $i=15;
                $f=16;
                $w_sum=$items[$i][$g]+$items[$f][$g];
                $t_sum=$record[$t.$i]+$record[$t.$f];
                $a_sum= $record[$a.$i]+$record[$a.$f];
                $o_sum= $record[$o.$i]+$record[$o.$f];
                $score_orf=round((($w_sum-$o_sum)/$t_sum)*60);
                $score_ora=$w_sum-($a_sum+$o_sum);
                $score_orr=$t_sum;


        }
        if($score_subset=="orf")
        {
            return $score_orf;
        }
        if($score_subset=="ora")
        {
            return $score_ora;
        }
        if($score_subset=="orr")
        {
            return $score_orr;
        }
    }
    
}