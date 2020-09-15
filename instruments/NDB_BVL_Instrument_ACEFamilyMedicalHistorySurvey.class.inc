<?php


class NDB_BVL_Instrument_ACEFamilyMedicalHistorySurvey extends NDB_BVL_Instrument
{
    use LegacyInstrumentTrait;
   var $indent = "&nbsp;&nbsp;&nbsp;&nbsp;";

    function setup(?string $commentID = NULL, ?string $page = NULL): void{

        $this->formType="XIN";
        $this->form = new LorisForm('test_form');
        $this->page = $page;            // page label (number or
        // string - used by
        // user-defined child classes)

        // set the object properties
        $this->testName = "ACEFamilyMedicalHistorySurvey";           // test_names.Test_name
        $this->table = 'ACEFamilyMedicalHistorySurvey';             // name of table containing

        // data keyed by commentID
        $this->commentID = $commentID;

        //The array of dates/timestamps to convert to database dates/timestamps
        //Any LorisForm date elements must be listed here
        //rathi updatethis


        $config = NDB_Config::singleton();
        $this->dateOptions = array(
        'language' => 'en',
        'format'   => 'YMd',
        'minYear'  => $config->getSetting('startYear'),
        'maxYear'  => $config->getSetting('endYear'),
        'addEmptyOption' => true,
        'emptyOptionValue' => null
        );

        $db = Database::singleton();
        // setup the form
        $this->_setupForm();

    }
       /**
     * method to build the LorisForm object into a paged form
     *
     * @return void
     * @access private
     */
    function _setupForm(){
        if(preg_match("/ACEFamilyMedicalHistorySurvey(_page[0-9]+)/",$this->page,$matches)){
            $this->_page($matches[1]);
            //call_user_func(array($this, $matches[1]));
        } else {
            $this->_main();
        }

        //Defines the call back function for HTML Quickform to use when validating the form.
       // $this->form->addFormRule(array(&$this,'XINValidate'));
    }
   /**
     * generates the main page of the form.
     *
     * @return void
     * @access private
     *
     */


    function displayHeaders($header_count) {
        $group[] =& $this->form->createElement(
            "static",
            null,
            null,
            "");
        $group[] =& $this->form->createElement(
            "static",
            null,
            null,
            "Biological Mother");
        $group[] =& $this->form->createElement(
            "static",
            null,
            null,
            "Biological Father");
        $group[] =& $this->form->createElement(
            "static",
            null,
            null,
            "Sibling 1");
        $group[] =& $this->form->createElement(
            "static",
            null,
            null,
            "Sibling 2");
        $group[] =& $this->form->createElement(
            "static",
            null,
            null,
            "Sibling 3");
        $group[] =& $this->form->createElement(
            "static",
            null,
            null,
            "Sibling 4");
        $group[] =& $this->form->createElement(
            "static",
            null,
            null,
            "Sibling 5");
        $this->form->addGroup(
            $group,
            "headers_$header_count",
            null,
            $this->_GUIDelimiter,
            false
        );
        unset($group);
    }

    function _main()
    {

        $this->addHeader("ACE Family Medical History - Survey Version");
        $this->form->addElement('static', 'lorisSubHeader', "<strong>Instructions:</strong><BR>1. To be completed by the study subject’s primary caregiver.
<br>2. Do not include the study subject in responses about biological siblings");
        $this->form->addElement('static', null, "<i><h3>*Please fill this form out with regard to your child who has enrolled in our study, NOT their older sibling with autism</i></h3>");
        $this->addBasicDate('Date_taken', 'Date of Administration', $this->dateOptions);
        $table_heading = array('mother' => 'Biological Mother', 'father' => 'Biological Father', 'sibling1' => 'Sibling 1', 'sibling2' => 'Sibling 2',
            'sibling3' => 'Sibling 3', 'sibling4' => 'Sibling 4', 'sibling5' => 'Sibling 5');
        $questions = array('relation' => 'Specify Relation', 'currentage' => "Current age (Parent's age can be entered in years)", 'gender' => 'Sex: Male(M) or Female(F)',
            'last_grade_completed' => 'Last Grade Completed', 'asd' => '1. Autism Spectrum Disorder', 'autistic_disorder' => '2. Autistic Disorder',
            'asperger_syndrome' => '3. Asperger Syndrome', 'rett_syndrome' => '4. Rett Syndrome', 'pdd_nos' => '5. PDD-NOS', 'history_speechdelay' => '6. History Speech Delay',
            'history_development_delay' => '7. History Development Delay', 'history_learndisability' => '8. History Learning Disability',
            'seizure_epilepsy' => '9. Seizure disorder/Epilepsy', 'cerebral_palsy' => '10. Cerebral Palsy', 'down_syndrome' => '11. Down Syndrome',
            'mental_retardation' => '12. Intellectual Disability', 'tuberoussclerosis' => '13. Tuberous Sclerosis (Alt. Tuberosclerosis)', 'fragilex' => '14. FragileX',
            'neurofibomarosis' => '15. Neurofibromatosis', 'congenitalblindness' => '16. Congenital blindness', 'deafness' => '17. Hearing Impairment',
            'hearingcorrect_aid' => $this->indent . 'a. Hearing corrected', 'bipolar' => '18. Bipolar', 'depression' => '19. Depression',
            'anxiety' => '20. Anxiety', 'ocd' => '21. Obsessive Compulsive', 'schizophernai' => '22. Schizophrenia', 'selfinjuring' => '23. Self injuring',
            'adhd' => '24. ADHD', 'eating_disorder' => '25. Eating disorder', 'disrupted_sleeppatterns' => '26. Disrupted sleep patterns',
            'tournette' => '27. Tourette Syndrome');
        $options = array('' => '', 'yes' => 'Yes', 'no' => 'No');
        $relation = array("" => null, 'full_sibling' => 'Full', 'maternal_half' => 'Maternal Half', 'paternal_half' => 'Paternal Half');
        $gender = array('' => null, 'male' => 'Male', 'female' => 'Female');
        // $this->displayHeaders(1);
        $c=0;
        foreach ($questions as $key => $question) {
            $c++;

                $this->displayHeaders($c);
            

            if ($key == "relation") {


                $group[] =& $this->form->createElement("static",null,null, '<b>'.$question.'</b>');
                $group[] =& $this->form->createElement("static",null,null, null);
                $group[] =& $this->form->createElement("static",null,null, null);
                $group[] =& $this->createSelect($key . "_sibling1", $question . "_sibling1", $relation);
                $group[] =& $this->createSelect($key . "_sibling2", $question . "_sibling2", $relation);
                $group[] =& $this->createSelect($key . "_sibling3", $question . "_sibling3", $relation);
                $group[] =& $this->createSelect($key . "_sibling4", $question . "_sibling4", $relation);
                $group[] =& $this->createSelect($key . "_sibling5", $question . "_sibling5", $relation);

            }
            elseif ($key=='gender')
            {
                $group[] =& $this->form->createElement("static",null,null, '<b>'.$question.'</b>');
                $group[] =& $this->createSelect($key . "_mother", $question . "_mother", $gender);
                $group[] =& $this->createSelect($key . "_father", $question . "_father", $gender);
                $group[] =& $this->createSelect($key . "_sibling1", $question . "_sibling1", $gender);
                $group[] =& $this->createSelect($key . "_sibling2", $question . "_sibling2", $gender);
                $group[] =& $this->createSelect($key . "_sibling3", $question . "_sibling3", $gender);
                $group[] =& $this->createSelect($key . "_sibling4", $question . "_sibling4", $gender);
                $group[] =& $this->createSelect($key . "_sibling5", $question . "_sibling5", $gender);

            }
            elseif ($key == 'currentage') {
                $group[] =& $this->form->createElement("static",null,null, '<b>'.$question.'</b>');
                $group[] =&$this->form->createElement("text",$key. "_mother",null,null);
                $group[] =&$this->form->createElement("text",$key . "_father",null,null);
                $group[] =& $this->form->createElement("text",$key . "_sibling1",null,null);
                $group[] =& $this->form->createElement("text",$key . "_sibling2",null,null);
                $group[] =& $this->form->createElement("text",$key . "_sibling3",null,null);
                $group[] =& $this->form->createElement("text",$key . "_sibling4",null,null);
                $group[] =& $this->form->createElement("text",$key . "_sibling5",null,null);
            }
            else if ($key == 'last_grade_completed') {
                $group[] =& $this->form->createElement("static",null,null, '<b>'.$question.'</b>');
                $group[] =& $this->form->createElement("text", $key . "_mother", null, null);
                $group[] =& $this->form->createElement("text", $key . "_father", null, null);
                $group[] =& $this->form->createElement("static",null,null, null);
                $group[] =& $this->form->createElement("static",null,null, null);
                $group[] =& $this->form->createElement("static",null,null, null);
                $group[] =& $this->form->createElement("static",null,null, null);
                $group[] =& $this->form->createElement("static",null,null, null);
            }
            else {
                $group[] =& $this->form->createElement("static",null,null, '<b>'.$question.'</b>');
                $group[] =& $this->createSelect($key . "_mother", $question . "_mother", $options);
                $group[] =& $this->createSelect($key . "_father", $question . "_father", $options);
                $group[] =& $this->createSelect($key . "_sibling1", $question . "_sibling1", $options);
                $group[] =& $this->createSelect($key . "_sibling2", $question . "_sibling2", $options);
                $group[] =& $this->createSelect($key . "_sibling3", $question . "_sibling3", $options);
                $group[] =& $this->createSelect($key . "_sibling4", $question . "_sibling4", $options);
                $group[] =& $this->createSelect($key . "_sibling5", $question . "_sibling5", $options);
            }
            $this->form->addGroup(
                $group,
                $key . "_group",
                null,
                $this->_GUIDelimiter,
                false
            );
            unset($group);

        }
    }


}
?>
