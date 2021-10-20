<?php
/*
 * This file contains the NDB_BVL_Instrument_MASC2_Self_Report
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
 * Creates the form elements for the CDI_Words_Sentences instrument
 *
 * @category Instrument
 * @package  Neuropsych
 * @author   Liza Levitis <llevitis.mcin@gmail.com>
 * @license  http://www.gnu.org/licenses/gpl-3.0.txt GPLv3
 * @link     https://www.github.com/aces/IBIS/
 */

class NDB_BVL_Instrument_MASC2_Self_Report extends NDB_BVL_Instrument
{
    use LegacyInstrumentTrait;

    var $ValidityRequired = false;


    var $scoreLabels = array(
        'masc2_total_score',
        'SP_score',
        'GAD_score',
        'SA_total_score',
        'HR_score',
        'PF_score',
        'OC_score',
        'PS_total_score',
        'Panic_score',
        'TR_score',
        'HA_score'
    );

    /**
     * Sets up basic data, such as the LorisForm object, and so on.
     *
     * @param string $commentID the CommentID identifying the data to load
     * @param string $page if a multipage form, the page to show
     *
     * @return void
     * @access public
     */
    function setup(?string $commentID = NULL, ?string $page = NULL): void
    {
        $this->formType = "XIN";
        $this->form = new LorisForm('MASC2_Self_Report_form');
        $this->page = $page;            // page label (number or
        // string - used by
        // user-defined child classes)

        // set the object properties
        $this->testName = 'MASC2_Self_Report';           // test_names.Test_name
        $this->table = 'MASC2_Self_Report';              // name of database table corresponding to instrument
        // data keyed by commentID
        $this->commentID = $commentID;

        //The array of dates/timestamps to convert to database dates/timestamps
        //Any HTML_Quickform date elements must be listed here
        $this->dateTimeFields = array("Date_taken");

        //The array of selects with multiple answers allowed
        //Any HTML_Quickform multiple selects must be listed here
        $this->selectMultipleElements = array();

        // required fields for data entry completion status
        $this->_requiredElements = array(
            'CommentID',
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

    /*
    * Method to build the LorisForm object into a paged form
    *
    * @return void
    * @access private
    */
    function _setupForm()
    {
        //determine page to display
        if (preg_match(
            "/MASC2_Self_Report(_page[0-9]+)/",
            $this->page,
            $matches
        )) {
            call_user_func(array($this, $matches[1]));
        } else {
            $this->_main();
        }
        $this->form->addFormRule(array(&$this, 'XINValidate'));
    }

    function displayHeaders($headerNum) {
        $group[] =& $this->form->createElement(
            "static",
            null,
            null,
            "");
        $group[] =& $this->form->createElement(
            "static",
            null,
            null,
            "0-Never True  1-Rarely True  2-Sometimes True  3-Often True");
        $this->form->addGroup(
            $group,
            "headers_" . $headerNum,
            null,
            $this->_GUIDelimiter,
            false
        );
        unset($group);
    }

    function _main()
    {
        // display test name
        $this->addHeader("MASC2: SELF-REPORT");
        $this->addBasicDate('Date_taken', 'Date of Administration', $this->dateOptions);
        $opts = array(
            null              => "",
            "mother"             => "Mother",
            "father"             => "Father",
            "step_mother"        => "Step Mother",
            "step_father"        => "Step Father",
            "clinician"          =>"Clinician",
            "self_report"        => "Self Report",
            "other"             => "Other",
        );
        $this->addSelect("relationship_to_child", "What is your relationship to the child?", $opts);
        $this->addBasicText("other_relationship_to_child", $this->indent."If Other, please describe:");
        $this->XINRegisterRule(
            "other_relationship_to_child",
            array("relationship_to_child{@}=={@}other"),
            "Required",
            "other_relationship_to_child"
        );

        $this->form->addElement('header', null, "Score Summary");
        //scoring column headers
        $group[] = $this->form->createElement('static', "score", null, null);
        $group[] = $this->form->createElement('static', "T_score", null, null);
        $group[] = $this->form->createElement('static', "classification", null, null);
        $this->form->addGroup($group, 'score_header_group', "<strong>Domain</strong>", $this->_GUIDelimiter, FALSE);
        unset($group);
        //score fields
        $domains = array("masc2_total" => "MASC2 Total Score","SP" => "Separation Anxiety/Phobias(S/P)","GAD" => "Gad Index(GAD)",
            "SA_total" => "Social Anxiety Total Score(SA:T)", "HR" => "Humiliation/Rejection", "PF" => "Performance Fears",
            "OC" => "Obsessions & Compulsions","PS_total" => "Physical Symptoms Total(PS:T)","Panic" => "Panic(P)","TR" => "Tense/Restless(T/R)",
            "HA" => "Harm Avoidance(HA)"
        );

        $columnHeaders = array("score" => "Score", "T_score" => "T Score","classification" =>"Classification");
        foreach ($columnHeaders as $field => $label) {
            $columnHeaders[$field] .= "     ";
        }
        $this->localDefaults = array_merge($this->localDefaults, $columnHeaders);

        foreach ($domains as $field=>$label)  {
            foreach ($columnHeaders as $scoreField => $scoreLabel) {
                $group[] = $this->form->createElement('static', "{$field}_{$scoreField}", null, null);
            }
            $this->form->addGroup($group, "{$label}_score_group", $label, $this->_GUIDelimiter, FALSE);
            unset($group);
        }
        $group[] = $this->form->createElement('static', "anxiety_probability_score", null, null);
        $this->form->addGroup($group, "anxiety_probability_score_group", "Anxiety Probability Score:", $this->_GUIDelimiter, FALSE);
        unset($group);
    }

    function _page1() {
        $this->addHeader("<h4><BR>Instructions: These sentences ask how you might have been thinking, feeling, or acting recently.  
                         For each item, please circle the number that describes how often the statement is true about 
                         you.<BR><BR>$this->indent Choose 0 if a sentence is Never true about you.<BR>
                         $this->indent Choose 1 if a sentence is Rarely true about you.<BR>
                         $this->indent Choose 2 if a sentence is Sometimes true about you.<BR>
                         $this->indent Choose 3 if a sentence is Often true about you.<BR><BR>
                         Remember, there are no right or wrong answers, just answer how you might have been feeling recently.</h4>");

        $options =
            array(
                null=>"",
                0 => "0 - Never true",
                1 => "1 - Rarely true",
                2 => "2 - Sometimes true",
                3 => "3 - Often true"
            );
        $options_NA =
            array(
                null=>"",
                0 => "0 - Never true",
                1 => "1 - Rarely true",
                2 => "2 - Sometimes true",
                3 => "3 - Often true",
                "NA"=>"Not Answered",
            );

        $questions =
            array(
                "q1" => "1. I feel tense or uptight.",
                "q2" => "2. I usually ask permission to do things.",
                "q3" => "3. I worry about other people.",
                "q4" => "4. I get scared when my parents go away.",
                "q5" => "5. I keep my eyes open for danger.",
                "q6" => "6. I have trouble getting my breath.",
                "q7" => "7. The idea of going away to camp scares me.",
                "q8" => "8. I get shaky or jittery.",
                "q9" => "9. I try to stay near my mom or dad.",
                "q10" => "10. I'm afraid that other kids will make fun of me.",
                "q11" => "11. I try hard to obey my parents and teachers.",
                "q12" => "12. I get dizzy or faint feelings.",
                "q13" => "13. I check things out first.",
                "q14" => "14. I worry about getting called on in class.",
                "q15" => "15. I'm jumpy.",
                "q16" => "16. I'm afraid other people will think I'm is stupid.",
                "q17" => "17. I keep the light on at night.",
                "q18" => "18. I have pains in my chest.",
                "q19" => "19. I avoid going places without my family.",
                "q20" => "20. I feel strange, weird, or unreal.",
                "q21" => "21. I try to do things other people will like.",
                "q22" => "22. I worry about what other people think of me.",
                "q23" => "23. I avoid watching scary movies or TV shows.",
                "q24" => "24. My heart races or skips beat.",
                "q25" => "25. I stay away from things that upset him/her."
            );
        $na_quest_array=array("q3");

        $this->displayHeaders(1);
        foreach ($questions as $qNum=>$qLabel) {
            $group[] =& $this->createLabel($qLabel);
            if (in_array($qNum, $na_quest_array))
            {
                $group[] =& $this->createSelect($qNum, $qLabel, $options_NA);
            }
            else{
                $group[] =& $this->createSelect($qNum, $qLabel, $options);
            }

            $this->form->addGroup(
                $group,
                "page1_questions_" . $qNum,
                null,
                $this->_GUIDelimiter,
                false
            );
            unset($group);
        }
    }

    function _page2() {
        $options =
            array(
                null=>"",
                0 => "0 - Never true",
                1 => "1 - Rarely true",
                2 => "2 - Sometimes true",
                3 => "3 - Often true"
            );

        $this->displayHeaders(2);
        $questions =
            array(
                "q26" => "26. I sleep next to someone from my family.",
                "q27" => "27. I feel restless and on edge.",
                "q28" => "28. I try to do everything exactly right.",
                "q29" => "29. I worry about doing something stupid or embarrassing.",
                "q30" => "30. I get scared riding in the car or on the bus.",
                "q31" => "31. I feel sick to my stomach.",
                "q32" => "32. I get nervous if I have to perform in public.",
                "q33" => "33. Bad weather, the dark, heights, animals, or bugs scare me.",
                "q34" => "34. My hands shake.",
                "q35" => "35. I check to make sure things are safe.",
                "q36" => "36. I have trouble asking other kids to play with me.",
                "q37" => "37. My hands feel sweaty or cold.",
                "q38" => "38. I feel shy.",
                "q39" => "39. I have trouble making up my mind about simple things.",
                "q40" => "40. I get upset over the thought that I might get sick.",
                "q41" => "41. I have bad or silly thoughts that I can't stop.",
                "q42" => "42. I have to do things over and over again for no reason.",
                "q43" => "43. I get really upset about dirt, germs, chemicals, radiation or sticky things.",
                "q44" => "44. I feel that I have to wash or clean more than I really need to.",
                "q45" => "45. I fear I'll be responsible for something bad happening.",
                "q46" => "46. I have to check that nothing terrible has happened.",
                "q47" => "47. I have to check things several times or more.",
                "q48" => "48. I count things for no reason.",
                "q49" => "49. I get too concerned with sin or wrongdoing.",
                "q50" => "50. I have to repeat things until it feels just right."
            );

        foreach ($questions as $qNum=>$qLabel) {
            $group[] =& $this->createLabel($qLabel);
            $group[] =& $this->createSelect($qNum, $qLabel, $options);
            $this->form->addGroup(
                $group,
                "page2_questions_" . $qNum,
                null,
                $this->_GUIDelimiter,
                false
            );
            unset($group);
        }
    }
    function score(): void
    {
        if($this->_determineDataEntryCompletionStatus() == "Incomplete") {
            return;
        }
        $scores['score_validity'] =NULL;

        //null scores
        $this->_nullScores($this->scoreLabels);

        //get the saved scores
        $db =& Database::singleton();
        $query = "SELECT * FROM $this->table WHERE CommentID = '$this->commentID'";
        $record = $db->pselectRow($query, array());
        $sp_array=array($record['q26'],
            $record['q30'],
            $record['q33'],
            $record['q4'],
            $record['q7'],
            $record['q9'],
            $record['q17'],
            $record['q19'],
            $record['q23'],
        );
        $gad_array=array($record['q27'],
            $record['q29'],
            $record['q31'],
            $record['q1'],
            $record['q7'],
            $record['q6'],
            $record['q39'],
            $record['q40'],
            $record['q13'],
            $record['q17'],
            $record['q22'],
        );
        $HR_array=array($record['q29'],
            $record['q3'],
            $record['q10'],
            $record['q16'],
            $record['q22'],
        );
        $PF_array=array($record['q32'],
            $record['q36'],
            $record['q38'],
            $record['q14'],
        );
        $OC_array=array($record['q41'],
            $record['q42'],
            $record['q43'],
            $record['q44'],
            $record['q45'],
            $record['q46'],
            $record['q47'],
            $record['q48'],
            $record['q49'],
            $record['q50'],
        );
        $panic_array=array(
            $record['q31'],
            $record['q37'],
            $record['q6'],
            $record['q12'],
            $record['q18'],
            $record['q20'],
            $record['q24'],
        );
        $TR_array=array($record['q27'],
            $record['q1'],
            $record['q34'],
            $record['q8'],
            $record['q15'],
        );
        $HA_array=array($record['q28'],
            $record['q2'],
            $record['q35'],
            $record['q5'],
            $record['q11'],
            $record['q13'],
            $record['q21'],
            $record['q25'],
        );

        $scores['SP_score']=$this->findRawScore($sp_array);
        $scores['GAD_score'] =$this->findRawScore($gad_array);
        $scores['HR_score']=$this->findRawScore($HR_array);
        $scores['PF_score']=$this->findRawScore($PF_array);
        $scores['OC_score']=$this->findRawScore($OC_array);
        $scores['Panic_score']=$this->findRawScore($panic_array);
        $scores['TR_score'] =$this->findRawScore($TR_array);
        $scores['HA_score']=$this->findRawScore($HA_array);
        $scores['SA_total_score']=$scores['HR_score'] +$scores['PF_score'];
        $scores['PS_total_score']=$scores['Panic_score']+$scores['TR_score'];
        $scores['masc2_total_score']=$scores['SP_score'] + $scores['PS_total_score'] +  $scores['OC_score']+ $scores['SA_total_score']+ $scores['HA_score']+$record['q39']+$record['q40'];
        $timepoint =& TimePoint::singleton($this->getSessionID());
        $dob = $timepoint->getEffectiveDateOfBirth();

        $age = Utility::calculateAge($dob, $record["Date_taken"]);

        $age_months = $age['year'] * 12 + $age['mon'] + ($age['day']/30);
        $age_years=$age_months/12;
        $age_years=floor($age_years);
        if(in_array($age_years, range(8, 11))) {
            $age_range="8 to 11";
        }
        else if(in_array($age_years, range(12, 15))) {
            $age_range="12 to 15";
        }
        else if(in_array($age_years, range(16, 19))) {
            $age_range="16 to 19";
        }

        else if($age_years<8)
        {
            $scores['score_validity'] ="Age not valid for scoring";
        }

        if($scores['score_validity']!=NULL) {
            echo "T score and classification are applicable only for ages above 8 years";
            echo "\n";
        }


        $query_gender = "SELECT Sex FROM candidate as c, session as s, flag as f, $this->table as t WHERE t.CommentID = '$this->commentID' 
AND f.CommentID=t.CommentID AND s.ID=f.SessionID AND s.CandID=c.CandID";
        $record_gender = $db->pselectRow($query_gender, array());
        if($record_gender['Sex']=='Male')
        {
            $gender='M';
        }
        if($record_gender['Sex']=='Female')
        {
            $gender='F';
        }
        if($age_range!="NA") {
            $scales = array("masc2_total", "SP", "GAD", "SA_total", "HR", "PF", "OC", "PS_total", "Panic", "TR", "HA");
            foreach ($scales as $field) {
                $field_raw_score = $scores[$field . '_score'];
                      if($field_raw_score==0)
                      {
                          $query_scores1 = "SELECT * FROM MASC2_Self_Report_lookup WHERE
                age_years='$age_range' AND sex='$gender'  AND (scale_raw_score ='$field_raw_score'  OR  '$field_raw_score' BETWEEN SUBSTRING_INDEX 
                (`scale_raw_score`,'-', 1) AND SUBSTRING_INDEX(`scale_raw_score`,'-', -1) ) AND scale='$field'";
                          $record_1 = $db->pselectRow($query_scores1, array());
                      }
                      else{
                          $query_scores1 = "SELECT * FROM MASC2_Self_Report_lookup WHERE
                age_years='$age_range' AND sex='$gender'  AND (scale_raw_score =$field_raw_score  OR  $field_raw_score BETWEEN SUBSTRING_INDEX 
                (`scale_raw_score`,'-', 1) AND SUBSTRING_INDEX(`scale_raw_score`,'-', -1) ) AND scale='$field'";
                          $record_1 = $db->pselectRow($query_scores1, array());
                      }

                if (empty($record_1)) {
                    $max_range = "SELECT * FROM MASC2_Self_Report_lookup WHERE
                age_years='$age_range' AND sex='$gender'  AND scale_raw_score like '%+%'  AND scale='$field'";
                    $max_range_array = $db->pselectRow($max_range, array());
                    //  print_r($max_range_array);
                    $max_number_array = explode("+", $max_range_array['scale_raw_score']);
                    $max_number = $max_number_array[0];
                    //  echo $max_number;
                    if ($field_raw_score >= $max_number) {
                        $scores[$field . '_T_score'] = ($max_range_array['scale_T_score']);
                        $scores[$field . '_classification'] = ($max_range_array['scale_classification']);

                    }
                    $min_range="SELECT * FROM MASC2_Self_Report_lookup WHERE
                age_years='$age_range' AND sex='$gender'  AND scale_raw_score like '%<%'  AND scale='$field'";
                    $min_range_array = $db->pselectRow($min_range, array());
                    $min_number_array = explode("<=", $min_range_array['scale_raw_score']);
                    $min_number = $min_number_array[1];
                    //  echo $min_number;
                    if ($field_raw_score <= $min_number) {
                        $scores[$field . '_T_score'] = ($min_range_array['scale_T_score']);
                        $scores[$field . '_classification'] = ($min_range_array['scale_classification']);
                    }

                } else{
                    if (array_key_exists('scale_T_score', $record_1)) {
                        if ($record_1['scale_T_score'] == "" || ($record_1['scale_T_score'] == NULL)) {
                            $scores[$field . '_T_score'] = "NA";
                        } else {
                            $scores[$field . '_T_score'] = ($record_1['scale_T_score']);
                        }
                    } else {
                        $scores[$field . '_T_score'] = "NA";
                    }
                    if (array_key_exists('scale_classification', $record_1)) {
                        if ($record_1['scale_classification'] == "" || ($record_1['scale_classification'] == NULL)) {
                            $scores[$field . 'classification'] = "NA";
                        } else {
                            $scores[$field . '_classification'] = ($record_1['scale_classification']);
                        }
                    } else {
                        $scores[$field . '_classification'] = "NA";
                    }

                }
            }
            $anxiety_score=0;
            if($scores['GAD_T_score']>=60)
            {
                $anxiety_score=$anxiety_score+1;
            }
            if($scores['SP_T_score']>=60)
            {
                $anxiety_score=$anxiety_score+1;
            }
            if($scores['SA_total_T_score']>=60)
            {
                $anxiety_score=$anxiety_score+1;
            }
            if($anxiety_score==0)
            {
                $scores['anxiety_probability_score']="Low Probability";
            }
            if($anxiety_score==1)
            {
                $scores['anxiety_probability_score']="Borderline Probability";
            }
            if($anxiety_score==2)
            {
                $scores['anxiety_probability_score']="High Probability";
            }
            if($anxiety_score==3)
            {
                $scores['anxiety_probability_score']="Very High Probability";
            }

        }
        $result = $db->update($this->table, $scores, array('CommentID'=>$this->getCommentID()));
    }


    function findRawScore($scale_array)
    {
        $raw_score=0;
        foreach ($scale_array as $val)
        {
            if($val=='0')
            {
                $raw_score=$raw_score+0;
            }
            if($val=='1')
            {
                $raw_score=$raw_score+1;
            }
            if($val=='2')
            {
                $raw_score=$raw_score+2;
            }
            if($val=='3')
            {
                $raw_score=$raw_score+3;
            }
        }
        return $raw_score;
    }



}
