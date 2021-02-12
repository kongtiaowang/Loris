<?php
/**
 *
 * @category Instrument
 * @author   Liza Levitis <llevitis.mcin@gmail.com>
 * @license  http://www.gnu.org/licenses/gpl-3.0.txt GPLv3
 * @link     https://www.github.com/aces/IBIS/
 */

/**
 * Creates the form elements for the ABC instrument
 *
 * @category Instrument
 * @author   Liza Levitis <llevitis.mcin@gmail.com>
 * @license  http://www.gnu.org/licenses/gpl-3.0.txt GPLv3
 * @link     https://www.github.com/aces/IBIS/
 */

class NDB_BVL_Instrument_conners_parent extends NDB_BVL_Instrument
{
    use LegacyInstrumentTrait;
    
    var $scoreLabels = array(
        'IN_raw_score',
        'HY_raw_score',
        'LP_raw_score',
        'EF_raw_score',
        'AG_raw_score',
        'PR_raw_score',
        'PI_raw_score',
        'NI_raw_score',
    );



    /**
     * Sets up basic data, such as the LorisForm object, and so on.
     *
     * @param  string $commentID the CommentID identifying the data to load
     * @param  string $page if a multipage form, the page to show
     * @return void
     * @access public
     */
    function setup(?string $commentID = NULL, ?string $page = NULL): void
    {
        $this->formType = 'XIN';
        $this->form     = new LorisForm('conners_parent_form');
        $this->page     = $page;

        // set the object properties
        $this->testName = 'conners_parent'; // test_names.Test_name
        $this->table    = 'conners_parent'; // name of database
        // table corresponding to instrument
        $this->commentID = $commentID; // data keyed by commentID

        //The array of dates/timestamps to convert to database dates/timestamps
        //Any LorisForm date elements must be listed here
        $this->dateTimeFields = array("Date_taken");

        //The array of selects with multiple answers allowed
        //Any LorisForm multiple selects must be listed here
        $this->_selectMultipleElements = array();

        // required fields for data entry completion status
        $this->_requiredElements = array(
            'CommentID',
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
     * method to build the LorisForm object into a paged form
     *
     * @return void
     * @access private
     */
    function _setupForm()
    {
        //determine page to display
        if (preg_match(
            "/conners_parent(_page[0-9]+)/",
            $this->page,
            $matches
        )) {
            call_user_func(array($this, $matches[1]));
        } else {
            $this->_main();
        }

        $this->form->addFormRule(array(&$this, 'XINValidate'));
        $this->form->addFormRule(array(&$this, 'addSpecialRules'));
    }

    /**
     * generates the main page of the form.
     *
     * @return void
     * @access private
     */
    function _main()
    {

        $this->addHeader("CONNERS 3 - Parent Short");
        $this->addBasicDate('Date_taken', 'Date of Administration', $this->dateOptions);
        $opts = array(
            null              => "",
            "mother"             => "Mother",
            "father"             => "Father",
            "step_mother"        => "Step Mother",
            "step_father"        => "Step Father",
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

        $this->addLabel("Please specify the grade: K-12 (or NA if you do not wish to answer)");
        $this->addBasicText("grade", "Grade:");

        $this->form->addElement('header', 'score', "Score Summary");


        //scoring column headers
        $group[] = $this->form->createElement('static', "raw_score", null, null);
        $group[] = $this->form->createElement('static', "T_score", null, null);
        $group[] = $this->form->createElement('static', "response_style", null, null);
        $this->form->addGroup($group, 'score_header_group', "<strong>Scale</strong>", $this->_GUIDelimiter, FALSE);
        unset($group);


        //score fields
        $domains=array("IN" => "Inattention","HY" => "Hyperactivity","LP" => "Learning Problems",
        "EF" => "Executive Functioning", "AG" => "Defiance/Aggression", "PR" => "Peer Relations", "PI" => "Positive Impression","NI" => "Negative Impression"
    );


        $columnHeaders = array("raw_score" => "Raw Score", "T_score" => "T Score", "response_style" => "Response Style"
        );

        foreach ($columnHeaders as $field => $label) {
            $columnHeaders[$field] .= "   ";
        }
        $this->localDefaults = array_merge($this->localDefaults, $columnHeaders);

        foreach ($domains as $field=>$label) {
            foreach ($columnHeaders as $scoreField => $scoreLabel) {

                $group[] = $this->form->createElement('static', "{$field}_{$scoreField}", null, null);
            }
            $this->form->addGroup($group, "{$label}_score_group", $label, $this->_GUIDelimiter, FALSE);
            unset($group);


        }


    }

    function _page1() {
        $this->addHeader("CONNERS 3 - Parent Short");
        $this->addHeader("<h4><b>Instructions:</b> Here are some things parents
                         might say about their children. Please tell us about
                         <i>your</i> child and what he/she has been like
                         in the <b><i>past month</i></b>. 
                         Read each item carefully, then mark how well
                         it describes your child or how frequently 
                         it has happened in the <b><i>past month</i></b>.<br><br>
                         $this->indent <b>0</b> = In the past month, 
                         this was <b><i>not true at all</i></b> about my child. It never
                         (or seldom) happened<br></h4><br>
                         $this->indent <b>1</b> = In the past month, this was 
                         <b><i>just a little true</i></b> about my child. 
                         It happened occasionally.<br>
                         $this->indent <b>2</b> = In the past month, 
                         this was <b><i>pretty much true</i></b> about<
                         my child. It happened often (or quite a bit).<br>
                         $this->indent <b>3</b> = In the past month, this 
                         was <b><i>very much true</i></b> about my child. It
                         happened very often (very frequently).<br><br>
                         Please pick one answer for each item. It is important
                         to respond to every item. For items that you find difficult
                         to answer, please give your best guess.");

        $options =
            array(
                null => "",
                0 => "0 - Not true at all",
                1 => "1 - Just a little true",
                2 => "2 - Pretty much true",
                3 => "3 - Very much true"
            );

        $options_na =
            array(
                null => "",
                0 => "0 - Not true at all",
                1 => "1 - Just a little true",
                2 => "2 - Pretty much true",
                3 => "3 - Very much true",
                'not_applicable'=> "Not Applicable"
            );
        $questions =
            array(
                "q1" => "1. Forgets to turn in completed work",
                "q2" => "2. Is perfect in every way.",
                "q3" => "3. Fidgets or squirms in seat.",
                "q4" => "4. Is one of the last to be picked for teams or games",
                "q5" => "5. Restless or overactive",
                "q6" => "6. Does not know how to make friends.",
                "q7" => "7. Runs or climbs when he/she is not supposed to.",
                "q8" => "8. Cannot grasp arithmetic.",
                "q9" => "9. Is difficult to please or amuse.",
                "q10" => "10. Needs extra explanation of instructions.",
                "q11" => "11. Is hard to motivate (even with rewards like candy or money.",
                "q12" => "12. Makes mistakes.",
                "q13" => "13. Acts as if driven by a motor.",
                "q14" => "14. Starts fight with others on purpose.",
                "q15" => "15. Has trouble getting started on tasks or projects.",
                "q16" => "16. Is happy, cheerful, and has a positive attitude",
                "q17" => "17. Doesn't pay attention to details; makes careless mistakes.",
                "q18" => "18. Has trouble keeping friends.",
                "q19" => "19. Bullies, threatens, or scares others.",
                "q20" => "20. Loses things (for example, schoolwork, pencils, books, tools or toys.",
                "q21" => "21. Tells lies to hurt other people.",
                "q22" => "22. I cannot figure out what makes him/her happy.",
                "q23" => "23. Threatens to hurt others.",
                "q24" => "24. Is constantly moving.",
                "q25" => "25. Has trouble with reading.",
                "q26" => "26. Is angry and resentful.",
                "q27" => "27. Has a short attention span.",
                "q28" => "28. Excitable, impulsive.",
                "q29" => "29. Cannot do things right.",
                "q30" => "30. Has trouble concentrating",
                "q31" => "31. Tells the truth; doesn't even tell \"little white lies.\"",
                "q32" => "32. Has trouble organizing tasks or activities.",
                "q33" => "33. Is fun to be around.",
                "q34" => "34. Inattentive, easily distracted.",
                "q35" => "35. Is messy or disorganized.",
                "q36" => "36. Spelling is poor",
                "q37" => "37. Is patient and content, even when waiting in a long line.",
                "q38" => "38. Has no friends.",
                "q39" => "39. Does not understand what he/she reads.",
                "q40" => "40. Behaves like an angel.",
                "q41" => "41. Has trouble keeping his/her mind on work or on play for long.",
                "q42" => "42. Has to struggle to complete hard tasks.",
                "q43" => "43. Does not get invited to play or go out with others."
            );

        foreach ($questions as $key => $question) {
            if($key=='q42' || $key=='q11')
            {
                $this->addSelect($key, $question, $options_na);
            }
            else{
                $this->addSelect($key, $question, $options);
            }
        }

        $this->addLabel("<h3>Additional Questions</h3>");
        $additional_questions =
            array(
                "q44" => "44. Do you have any other concerns about your child?",
                "q45" => "45. What strengths or skills does your child have?"
            );

        foreach($additional_questions as $key => $question) {
            $this->addBasicText($key, $question);
        }
    }
    
    function addSpecialRules($values)
    {
		$errors = array();
		
		if(isset($values['grade'])) {
			if(!preg_match('/^\s*(K|[1-9]|1[012]|NA)\s*$/', $values['grade'])) {
				$errors['grade'] = 'Please enter a grade (K-12) or NA';
			}
		}
		
		return $errors;
	}
// scoring Sruthy
    function score(): void
    {
        if ($this->_determineDataEntryCompletionStatus() == "Incomplete") {
            return;
        }


        //null scores
        $this->_nullScores($this->scoreLabels);
        $score_grid_q1=array(0=>0,1=>1,2=>2,3=>3);
        $score_grid_q2=array(0=>0,1=>0,2=>0,3=>1);
        $score_grid_q3=array(0=>0,1=>1,2=>2,3=>3);
        $score_grid_q4=array(0=>0,1=>1,2=>2,3=>3);
        $score_grid_q5=array(0=>0,1=>1,2=>2,3=>3);
        $score_grid_q6=array(0=>0,1=>1,2=>2,3=>3);
        $score_grid_q7=array(0=>0,1=>1,2=>2,3=>3);
        $score_grid_q8=array(0=>0,1=>1,2=>2,3=>3);
        $score_grid_q9=array(0=>0,1=>0,2=>1,3=>1);
        $score_grid_q10=array(0=>0,1=>1,2=>2,3=>3);
        $score_grid_q11=array(0=>0,1=>0,2=>1,3=>1);
        $score_grid_q12=array(0=>1,1=>0,2=>0,3=>0);
        $score_grid_q13=array(0=>0,1=>1,2=>2,3=>3);
        $score_grid_q14=array(0=>0,1=>1,2=>2,3=>3);
        $score_grid_q15=array(0=>0,1=>1,2=>2,3=>3);
        $score_grid_q16=array(0=>1,1=>1,2=>0,3=>0);
        $score_grid_q17=array(0=>0,1=>1,2=>2,3=>3);
        $score_grid_q18=array(0=>0,1=>1,2=>2,3=>3);
        $score_grid_q19=array(0=>0,1=>1,2=>2,3=>3);
        $score_grid_q20=array(0=>0,1=>1,2=>2,3=>3);
        $score_grid_q21=array(0=>0,1=>1,2=>2,3=>3);
        $score_grid_q22=array(0=>0,1=>0,2=>1,3=>1);
        $score_grid_q23=array(0=>0,1=>1,2=>2,3=>3);
        $score_grid_q24=array(0=>0,1=>1,2=>2,3=>3);
        $score_grid_q25=array(0=>0,1=>1,2=>2,3=>3);
        $score_grid_q26=array(0=>0,1=>1,2=>2,3=>3);
        $score_grid_q27=array(0=>0,1=>1,2=>2,3=>3);
        $score_grid_q28=array(0=>0,1=>1,2=>2,3=>3);
        $score_grid_q29=array(0=>0,1=>0,2=>1,3=>1);
        $score_grid_q30=array(0=>0,1=>1,2=>2,3=>3);
        $score_grid_q31=array(0=>0,1=>0,2=>0,3=>1);
        $score_grid_q32=array(0=>0,1=>1,2=>2,3=>3);
        $score_grid_q33=array(0=>1,1=>1,2=>0,3=>0);
        $score_grid_q34=array(0=>0,1=>1,2=>2,3=>3);
        $score_grid_q35=array(0=>0,1=>1,2=>2,3=>3);
        $score_grid_q36=array(0=>0,1=>1,2=>2,3=>3);
        $score_grid_q37=array(0=>0,1=>0,2=>0,3=>1);
        $score_grid_q38=array(0=>0,1=>1,2=>2,3=>3);
        $score_grid_q39=array(0=>0,1=>1,2=>2,3=>3);
        $score_grid_q40=array(0=>0,1=>0,2=>0,3=>1);
        $score_grid_q41=array(0=>0,1=>1,2=>2,3=>3);
        $score_grid_q42=array(0=>1,1=>0,2=>0,3=>0);
        $score_grid_q43=array(0=>0,1=>1,2=>2,3=>3);

        //get the saved scores
        $db =& Database::singleton();
        $query = "SELECT * FROM $this->table WHERE CommentID = '$this->commentID'";
        $record = $db->pselectRow($query, array());
        $IN_array = array(
            $score_grid_q17[$record['q17']],
            $score_grid_q27[$record['q27']],
            $score_grid_q30[$record['q30']],
            $score_grid_q34[$record['q34']],
            $score_grid_q41[ $record['q41']],
        );
        $HY_array=array(
            $score_grid_q3[$record['q3']],
            $score_grid_q5[$record['q5']],
            $score_grid_q7[$record['q7']],
            $score_grid_q13[$record['q13']],
            $score_grid_q24[$record['q24']],
            $score_grid_q28[$record['q28']],
        );
        $LP_array=array(
            $score_grid_q8[$record['q8']],
             $score_grid_q10[$record['q10']],
             $score_grid_q25[$record['q25']],
             $score_grid_q36[$record['q36']],
             $score_grid_q39[$record['q39']],
        );
        $EF_array=array(
             $score_grid_q1[$record['q1']],
             $score_grid_q15[$record['q15']],
             $score_grid_q20[$record['q20']],
             $score_grid_q32[$record['q32']],
             $score_grid_q35[$record['q35']],
        );
        $AG_array=array(
            $score_grid_q14[$record['q14']],
             $score_grid_q19[$record['q19']],
             $score_grid_q21[$record['q21']],
             $score_grid_q23[$record['q23']],
             $score_grid_q26[$record['q26']],
        );
        $PR_array=array(
            $score_grid_q4[$record['q4']],
             $score_grid_q6[$record['q6']],
             $score_grid_q18[$record['q18']],
             $score_grid_q38[$record['q38']],
             $score_grid_q43[$record['q43']],
        );
        $PI_array=array(
            $score_grid_q2[$record['q2']],
            $score_grid_q12[$record['q12']],
             $score_grid_q31[$record['q31']],
             $score_grid_q37[$record['q37']],
             $score_grid_q40[$record['q40']],
             $score_grid_q42[$record['q42']],
        );
        $NI_array=array(
            $score_grid_q9[$record['q9']],
            $score_grid_q11[ $record['q11']],
             $score_grid_q16[$record['q16']],
            $score_grid_q22[ $record['q22']],
             $score_grid_q29[$record['q29']],
            $score_grid_q33[ $record['q33']],
        );
        $scores['IN_raw_score']=$this->findRowScore($IN_array);
        $scores['HY_raw_score'] =$this->findRowScore($HY_array);
        $scores['LP_raw_score']=$this->findRowScore($LP_array);
        $scores['EF_raw_score']=$this->findRowScore($EF_array);
        $scores['AG_raw_score']=$this->findRowScore($AG_array);
        $scores['PR_raw_score']=$this->findRowScore($PR_array);
        $scores['PI_raw_score'] =$this->findRowScore($PI_array);
        $scores['NI_raw_score']=$this->findRowScore($NI_array);
        $timepoint =& TimePoint::singleton($this->getSessionID());
        $dob = $timepoint->getEffectiveDateOfBirth();

        $age = Utility::calculateAge($dob, $record["Date_taken"]);
        $valid="YES";
        $age_months = $age['year'] * 12 + $age['mon'] + ($age['day']/30);
        $age_years=$age_months/12;
        $age_years=floor($age_years);
        if($age_years>18 || $age_years<6)
        {
            $valid="NO";
            echo "T score unavailable...T score is applicable only for ages between 6 to 18";
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
        if($valid=='YES')
        {
            $scales = array("IN", "HY", "LP", "EF", "AG", "PR","PI","NI");
            foreach ($scales as $field) {
                $field_raw_score = $scores[$field . '_raw_score'];
                if ($field != 'NI' && $field !='PI') {
                    $scores[$field . '_response_style']="--";
                    if($field_raw_score==0) {
                        $query_scores1 = "SELECT * FROM conners_parent_lookup WHERE
                age_years='$age_years' AND sex='$gender'  AND (scale_raw_score ='$field_raw_score'  OR  '$field_raw_score' BETWEEN SUBSTRING_INDEX 
                (`scale_raw_score`,'-', 1) AND SUBSTRING_INDEX(`scale_raw_score`,'-', -1) ) AND scale='$field'";
                        $record_1 = $db->pselectRow($query_scores1, array());
                    }
                    else{
                        $query_scores1 = "SELECT * FROM conners_parent_lookup WHERE
                age_years='$age_years' AND sex='$gender'  AND (scale_raw_score =$field_raw_score  OR  $field_raw_score BETWEEN SUBSTRING_INDEX 
                (`scale_raw_score`,'-', 1) AND SUBSTRING_INDEX(`scale_raw_score`,'-', -1) ) AND scale='$field'";
                        $record_1 = $db->pselectRow($query_scores1, array());

                    }

                if (empty($record_1)) {
                    $max_range = "SELECT * FROM conners_parent_lookup WHERE
                age_years='$age_years' AND sex='$gender'  AND scale_raw_score like '%plus%' AND scale='$field'";
                    $max_range_array = $db->pselectRow($max_range, array());
                    if(empty($max_range_array))
                    {
                        $scores[$field . '_T_score'] = "NA";
                    }
                    else {
                        $max_number_array = explode("plus", $max_range_array['scale_raw_score']);
                        $max_number = $max_number_array[0];
                        //  echo $max_number;
                        if ($field_raw_score >= $max_number) {
                            $scores[$field . '_T_score'] = ($max_range_array['scale_T_score']);

                        }
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
                }
                }
                else{
                    if($field=='PI')
                    {
                        if ($field_raw_score>=5)
                        {
                            $scores[$field . '_response_style'] = "Possible Positive Response Style Indicated";
                        }

                        else{
                            $scores[$field . '_response_style'] = "NA";
                        }
                    }
                    if($field=='NI')
                    {
                       if ($field_raw_score>=5)
                        {
                            $scores[$field . '_response_style'] = "Possible Negative Response Style Indicated";
                        }
                        else{
                            $scores[$field . '_response_style'] = "NA";
                        }
                    }
                }
            }
        }

           $scores= str_replace(">", "Greater than or equal to ", $scores);

            $scores= str_replace("<", "Less than or equal to ", $scores);

        $result = $db->update($this->table, $scores, array('CommentID'=>$this->getCommentID()));
    }
    function findRowScore($scale_array)
    {
        $raw_score=0;
        foreach ($scale_array as $val)
        {
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
