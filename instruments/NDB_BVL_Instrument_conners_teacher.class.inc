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
class NDB_BVL_Instrument_conners_teacher extends NDB_BVL_Instrument
{
    use LegacyInstrumentTrait;

    var $ValidityEnabled  = true;
    var $ValidityRequired = false;

    var $scoreLabels = array(
        'IN_raw_score', 'IN_T_score', 'IN_validity',
        'HY_raw_score', 'HY_T_score', 'HY_validity',
        'LE_raw_score', 'LE_T_score', 'LE_validity',
        'AG_raw_score', 'AG_T_score', 'AG_validity',
        'PR_raw_score', 'PR_T_score', 'PR_validity',
        'PI_raw_score', 'PI_T_score', 'PI_validity',
        'NI_raw_score', 'NI_T_score', 'NI_validity'
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
        $this->form     = new LorisForm('conners_teacher_form');
        $this->page     = $page;

        // set the object properties
        $this->testName = 'conners_teacher'; // test_names.Test_name
        $this->table    = 'conners_teacher'; // name of database
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
            "/conners_teacher(_page[0-9]+)/",
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

        $this->addHeader("CONNERS 3 - Teacher Short");
        $this->addBasicDate('Date_taken', 'Date of Administration', $this->dateOptions);
        $this->addLabel("Please specify the grade: K-12 (or NA if you do not wish to answer)");
        $this->addBasicText("grade", "Grade:");
        $this->form->addElement('header', null, "Score Summary");
        //scoring column headers
        $group[] = $this->form->createElement('static', "raw_score", null, null);
        $group[] = $this->form->createElement('static', "T_score", null, null);
        $group[] = $this->form->createElement('static', "validity", null, null);
        $this->form->addGroup($group, 'score_header_group', "<strong>Scale</strong>", $this->_GUIDelimiter, FALSE);
        unset($group);
        //score fields
        $domains = array("IN" => "Inattention","HY" => "Hyperactivity","LE" => "Learning Problems/Executive Functioning", "AG" => "Defiance/Aggression",
            "PR" => "Peer Relations","PI" => "Positive Impression","NI" => "Negative Impression"
        );
        $columnHeaders = array("raw_score" => "Raw Score", "T_score" => "T Score", "validity" => "Validity",
        );
        foreach ($columnHeaders as $field => $label) {
            $columnHeaders[$field] .= "     ";
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
        $this->addHeader("CONNERS 3 - Teacher Short");
        $this->addHeader("<h4><b>Instructions:</b> Here are some things teachers
                         might say about their students. Please tell us about
                         <i>this</i> student and what he/she has been like
                         in the <b><i>past month</i></b>. 
                         Read each item carefully, then mark how well
                         it describes this student or how frequently 
                         it has happened in the <b><i>past month</i></b>.<br><br>
                         $this->indent <b>0</b> = In the past month, 
                         this was <b><i>not true at all</i></b> about this student. It never
                         (or seldom) happened<br>
                         $this->indent <b>1</b> = In the past month, this was 
                         <b><i>just a little true</i></b> about this student. 
                         It happened occasionally.<br>
                         $this->indent <b>2</b> = In the past month, 
                         this was <b><i>pretty much true</i></b> about
                         this student. It happened often (or quite a bit).<br>
                         $this->indent <b>3</b> = In the past month, this 
                         was <b><i>very much true</i></b> about this student. It
                         happened very often (very frequently).<br><br>
                         Please pick one answer for each item. It is important
                         to respond to every item. For items that you find difficult
                         to answer, please give your best guess.</h4>");

        $options =
            array(
                null => "",
                0 => "0 - Not true at all",
                1 => "1 - Just a little true",
                2 => "2 - Pretty much true",
                3 => "3 - Very much true"
            );

        $questions =
            array(
                "q1"  => "1. Is constantly moving",
                "q2"  => "2. Has to struggle to complete hard tasks.",
                "q3"  => "3. Inattentive, easily distracted.",
                "q4"  => "4. Makes mistakes",
                "q5"  => "5. Bullies, threatens, or scares others.",
                "q6"  => "6. Cannot do things right.",
                "q7"  => "7. Is angry and resentful.",
                "q8"  => "8. Excitable, impulsive.",
                "q9"  => "9. Is fun to be around.",
                "q10" =>
                    "10. Has trouble keeping his/her mind on work or play for long.",
                "q11" => "11. Has poor social skills.",
                "q12" =>
                    "12. Actively refuses to do what adults tell him/her to do.",
                "q13" => "13. Is happy, cheerful, and has a positive attitude.",
                "q14" => "14. Cannot grasp arithmetic.",
                "q15" => "15. Tries to get even with people.",
                "q16" => "16. Has trouble getting started on tasks or projects.",
                "q17" => "17. Acts in sneaky or manipulative ways.",
                "q18" => "18. Does not understand what he/she reads.",
                "q19" => "19. Tells the truth; does not even tell \"little white lies.\"",
                "q20" => "20. Appears to be unaccepted by group.",
                "q21" => "21. Is hard to motivate (even with highly desirable rewards).",
                "q22" => "22. Restless or overactive.",
                "q23" => "23. Is good at planning ahead.",
                "q24" => "24. Fidgets or squirms in seat.",
                "q25" => "25. Is patient and content, even when waiting in a long line.",
                "q26" => "26. Doesn't pay attention to details; makes careless mistakes.",
                "q27" => "27. Is one of the last to be picked for teams or games.",
                "q28" => "28. Spelling is poor.",
                "q29" => "29. Has trouble keeping friends.",
                "q30" => "30. Leaves seat when he/she should stay seated.",
                "q31" => "31. Behaves like an angel.",
                "q32" => "32. Talks out of turn.",
                "q33" => "33. Is difficult to please or amuse.",
                "q34" => "34. Is perfect in every way.",
                "q35" => "35. Forgets things already learned.",
                "q36" => "36. Has a short attention span.",
                "q37" => "37. Does not know how to make friends.",
                "q38" => "38. I cannot figure out what makes him/her happy.",
                "q39" => "39. Is sidetracked easily.",
            );

        foreach ($questions as $key => $question) {
            $this->addSelect($key, $question, $options);
        }

        $this->addLabel("<h3>Additional Questions</h3>");
        $additional_questions =
            array(
                "q40" => "40. Do you have any other concerns about this student?",
                "q41" => "41. What strengths or skills does this student have?"
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
        //
        //
        //Teacher Score Grid
        $score_grid_q1=array(0=>0,1=>1,2=>2,3=>3);
        $score_grid_q2=array(0=>1,1=>0,2=>0,3=>0);
        $score_grid_q3=array(0=>0,1=>1,2=>2,3=>3);
        $score_grid_q4=array(0=>1,1=>0,2=>0,3=>0);
        $score_grid_q5=array(0=>0,1=>1,2=>2,3=>3);
        $score_grid_q6=array(0=>0,1=>0,2=>1,3=>1);
        $score_grid_q7=array(0=>0,1=>1,2=>2,3=>3);
        $score_grid_q8=array(0=>0,1=>1,2=>2,3=>3);
        $score_grid_q9=array(0=>1,1=>1,2=>0,3=>0);
        $score_grid_q10=array(0=>0,1=>1,2=>2,3=>3);
        $score_grid_q11=array(0=>0,1=>1,2=>2,3=>3);
        $score_grid_q12=array(0=>0,1=>1,2=>2,3=>3);
        $score_grid_q13=array(0=>1,1=>1,2=>0,3=>0);
        $score_grid_q14=array(0=>0,1=>1,2=>2,3=>3);
        $score_grid_q15=array(0=>0,1=>1,2=>2,3=>3);
        $score_grid_q16=array(0=>0,1=>1,2=>2,3=>3);
        $score_grid_q17=array(0=>0,1=>1,2=>2,3=>3);
        $score_grid_q18=array(0=>0,1=>1,2=>2,3=>3);
        $score_grid_q19=array(0=>0,1=>0,2=>0,3=>1);
        $score_grid_q20=array(0=>0,1=>1,2=>2,3=>3);
        $score_grid_q21=array(0=>0,1=>0,2=>1,3=>1);
        $score_grid_q22=array(0=>0,1=>1,2=>2,3=>3);
        $score_grid_q23=array(0=>3,1=>2,2=>1,3=>0);
        $score_grid_q24=array(0=>0,1=>1,2=>2,3=>3);
        $score_grid_q25=array(0=>0,1=>0,2=>0,3=>1);
        $score_grid_q26=array(0=>0,1=>1,2=>2,3=>3);
        $score_grid_q27=array(0=>0,1=>1,2=>2,3=>3);
        $score_grid_q28=array(0=>0,1=>1,2=>2,3=>3);
        $score_grid_q29=array(0=>0,1=>1,2=>2,3=>3);
        $score_grid_q30=array(0=>0,1=>1,2=>2,3=>3);
        $score_grid_q31=array(0=>0,1=>0,2=>0,3=>1);
        $score_grid_q32=array(0=>0,1=>1,2=>2,3=>3);
        $score_grid_q33=array(0=>0,1=>0,2=>1,3=>1);
        $score_grid_q34=array(0=>0,1=>0,2=>0,3=>1);
        $score_grid_q35=array(0=>0,1=>1,2=>2,3=>3);
        $score_grid_q36=array(0=>0,1=>1,2=>2,3=>3);
        $score_grid_q37=array(0=>0,1=>1,2=>2,3=>3);
        $score_grid_q38=array(0=>0,1=>0,2=>1,3=>1);
        $score_grid_q39=array(0=>0,1=>1,2=>2,3=>3);

        //get the saved scores
        $db =& Database::singleton();
        $query = "SELECT * FROM $this->table WHERE CommentID = '$this->commentID'";
        $record = $db->pselectRow($query, array());
       //3,10,26,36,39
        $IN_array = array(
            $score_grid_q3[$record['q3']],
            $score_grid_q10[$record['q10']],
            $score_grid_q26[$record['q26']],
            $score_grid_q36[$record['q36']],
            $score_grid_q39[$record['q39']],
        );
       // 1,8,22,24,30,32
        $HY_array=array(
            $score_grid_q1[$record['q1']],
            $score_grid_q8[$record['q8']],
            $score_grid_q22[$record['q22']],
            $score_grid_q24[$record['q24']],
            $score_grid_q30[$record['q30']],
            $score_grid_q32[$record['q32']],
        );
        //14,16,18,23,28,35
        $LE_array=array(
            $score_grid_q14[$record['q14']],
            $score_grid_q16[$record['q16']],
            $score_grid_q18[$record['q18']],
            $score_grid_q23[$record['q23']],
            $score_grid_q28[$record['q28']],
            $score_grid_q35[$record['q35']],
        );
        //5,7,12,15,17
        $AG_array=array(
            $score_grid_q5[$record['q5']],
            $score_grid_q7[$record['q7']],
            $score_grid_q12[$record['q12']],
            $score_grid_q15[$record['q15']],
            $score_grid_q17[$record['q17']],
        );
        //11,20,27,29,37
        $PR_array=array(
            $score_grid_q11[$record['q11']],
            $score_grid_q20[$record['q20']],
            $score_grid_q27[$record['q27']],
            $score_grid_q29[$record['q29']],
            $score_grid_q37[$record['q37']],
        );
        //2,4,19,25,31,34
        $PI_array=array(
            $score_grid_q2[$record['q2']],
            $score_grid_q4[$record['q4']],
            $score_grid_q19[$record['q19']],
            $score_grid_q25[$record['q25']],
            $score_grid_q31[$record['q31']],
            $score_grid_q34[$record['q34']],
        );
        //6,9,13,21,33,38
        $NI_array=array(
            $score_grid_q6[$record['q6']],
            $score_grid_q9[$record['q9']],
            $score_grid_q13[$record['q13']],
            $score_grid_q21[$record['q21']],
            $score_grid_q33[$record['q33']],
            $score_grid_q38[$record['q38']],
        );
        $scores['IN_raw_score']=$this->findRowScore($IN_array);
        $scores['HY_raw_score'] =$this->findRowScore($HY_array);
        $scores['LE_raw_score']=$this->findRowScore($LE_array);
        $scores['AG_raw_score']=$this->findRowScore($AG_array);
        $scores['PR_raw_score']=$this->findRowScore($PR_array);
        $scores['PI_raw_score'] =$this->findRowScore($PI_array);
        $scores['NI_raw_score']=$this->findRowScore($NI_array);
        $timepoint =& TimePoint::singleton($this->getSessionID());

        // If the date taken field was not filled out, we won't be able to calculate
        // the kid's age at the time the instrument was administered:
        // all T-Scores and Validity will remain null
        if (is_null($record["Date_taken"])) {
            $scores= str_replace(">", "Greater than or equal to ", $scores);
            $scores=str_replace("<", "Less than or equal to", $scores);
            $result = $db->update($this->table, $scores, array('CommentID'=>$this->getCommentID()));

            return;
        }

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
            $scales = array("IN", "HY", "LE", "AG", "PR","PI","NI");
            foreach ($scales as $field) {
                $field_raw_score = $scores[$field . '_raw_score'];
                if ($field != 'NI' && $field !='PI') {
                    $scores[$field . '_validity']="--";
                    if($field_raw_score==0)
                    {
                        $query_scores1 = "SELECT * FROM conners_teacher_lookup WHERE
                age_years='$age_years' AND sex='$gender'  AND (scale_raw_score ='$field_raw_score'  OR  '$field_raw_score' BETWEEN SUBSTRING_INDEX 
                (`scale_raw_score`,'-', 1) AND SUBSTRING_INDEX(`scale_raw_score`,'-', -1) ) AND scale='$field'";
                        $record_1 = $db->pselectRow($query_scores1, array());
                    }
                    else{
                        $query_scores1 = "SELECT * FROM conners_teacher_lookup WHERE
                age_years='$age_years' AND sex='$gender'  AND (scale_raw_score =$field_raw_score  OR  $field_raw_score BETWEEN SUBSTRING_INDEX 
                (`scale_raw_score`,'-', 1) AND SUBSTRING_INDEX(`scale_raw_score`,'-', -1) ) AND scale='$field'";
                        $record_1 = $db->pselectRow($query_scores1, array());

                    }

                    if (empty($record_1)) {
                        $max_range = "SELECT * FROM conners_teacher_lookup WHERE
                age_years='$age_years' AND sex='$gender'  AND scale_raw_score like '%plus%' AND scale='$field'";
                        $max_range_array = $db->pselectRow($max_range, array());
                        if (empty($max_range_array)) {
                            $scores[$field . '_T_score'] = "NA";
                        } else {
                            $max_number_array = explode("plus", $max_range_array['scale_raw_score']);
                            $max_number = $max_number_array[0];
                            //  echo $max_number;
                            if ($field_raw_score >= $max_number) {
                                $scores[$field . '_T_score'] = ($max_range_array['scale_T_score']);
                            }
                        }
                    } else {
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
                        if ( in_array($field_raw_score, range(0,3)) ) {
                            $scores[$field . '_validity'] = "Probably Valid";
                        }
                        elseif ($field_raw_score==4)
                        {
                            $scores[$field . '_validity'] = "Possibly Invalid";
                        }
                        elseif(in_array($field_raw_score, range(5,6)) )
                        {
                            $scores[$field . '_validity'] = "Probably Invalid";
                        }
                        else{
                            $scores[$field . '_validity'] = "NA";
                        }
                    }
                    if($field=='NI')
                    {
                        if ( in_array($field_raw_score, range(0,2)) ) {
                            $scores[$field . '_validity'] = "Probably Valid";
                        }
                        elseif ($field_raw_score==3)
                        {
                            $scores[$field . '_validity'] = "Possibly Invalid";
                        }
                        elseif(in_array($field_raw_score, range(4,6)) )
                        {
                            $scores[$field . '_validity'] = "Probably Invalid";
                        }
                        else{
                            $scores[$field . '_validity'] = "NA";
                        }
                    }
                }
            }
        }
        $scores= str_replace(">", "Greater than or equal to ", $scores);
        $scores=str_replace("<", "Less than or equal to", $scores);
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
