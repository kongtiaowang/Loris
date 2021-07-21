<?php


class NDB_BVL_Instrument_FOHFamilyMedicalHistory extends NDB_BVL_Instrument
{
    use LegacyInstrumentTrait;
    use instrument_validator;
    var $ValidityEnabled = false;
    var $ValidityRequired = false;

    var $indent = "&nbsp;&nbsp;&nbsp;&nbsp;";

    function setup(?string $commentID = NULL, ?string $page = NULL): void
    {

        $this->formType = "XIN";
        $this->form = new LorisForm('test_form');
        $this->page = $page;            // page label (number or
        // string - used by
        // user-defined child classes)

        // set the object properties
        $this->testName = "FOHFamilyMedicalHistory";           // test_names.Test_name
        $this->table = 'FOHFamilyMedicalHistory';             // name of table containing

        // data keyed by commentID
        $this->commentID = $commentID;

        //The array of dates/timestamps to convert to database dates/timestamps
        //Any LorisForm date elements must be listed here
        //rathi updatethis

        $this->_requiredElements = array('Date_taken', 'Examiner');

        $config = NDB_Config::singleton();
        $this->dateOptions = array(
            'language' => 'en',
            'format' => 'YMd',
            'minYear' => $config->getSetting('startYear'),
            'maxYear' => $config->getSetting('endYear'),
            'addEmptyOption' => true,
            'emptyOptionValue' => null
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
        if (preg_match("/FOHFamilyMedicalHistory(_page[0-9]+)/", $this->page, $matches)) {
            $this->_page($matches[1]);
            //call_user_func(array($this, $matches[1]));
        } else {
            $this->_main();
        }

        //Defines the call back function for HTML Quickform to use when validating the form.
        $this->form->addFormRule(array(&$this, 'XINValidate'));
    }

    /**
     * generates the main page of the form.
     *
     * @return void
     * @access private
     *
     */
    function _main()
    {
        $this->addHeader("FOH - Family Medical History");

        $this->addBasicDate('Date_taken', 'Date Taken', $this->dateOptions, ['required' => true]);

        $examiners = $this->_getExaminerNames();
        $this->addSelect('Examiner', 'Examiner', $examiners, ['required' => true]);

        $table_heading = array('mother' => 'Biological Mother', 'father' => 'Biological Father', 'sibling1' => 'Subject', 'sibling2' => 'Sibling 1',
            'sibling3' => 'Sibling 2', 'sibling4' => 'Sibling 3', 'sibling5' => 'Sibling 4', 'sibling6' => 'Sibling 5');
        $questions = array('header' => null, 'relation' => 'Specify Relation', 'sibling_subject' => 'Sibling Subject', 'dob' => 'Date of birth', 'currentage' => 'Current age(months)', 'gender' => 'Sex: Male(M) or Female(F)',
             'asd' => '1. Autism Spectrum Disorder', 'autistic_disorder' => '2. Autistic Disorder',
            'asperger_syndrome' => '3. Asperger Syndrome', 'rett_syndrome' => '4. Rett Syndrome', 'pdd_nos' => '5. PDD-NOS', 'age_first_diagnosis' => 'If “Yes” to any of #1-5, age at first diagnosis (years)', 'history_speechdelay' => '6. History Speech Delay',
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
        foreach ($questions as $key => $val) {
            $groupname = $key . "_group";

            foreach ($table_heading as $k => $v) {
                if ($key == 'header') {
                    $group[] = $this->form->createElement("static", null, null, $v);
                } else {
                    $field = $key . "_" . $k;
                    if ($key == 'currentage') {
                        $group[] = $this->form->createElement("text", $field, null, null);
                        $this->fieldNotRequired($field);
                    } elseif ($key == 'dob') {
                        $group[] = $this->form->createElement("date", $field, null);
                        $this->fieldNotRequired($field);
                    } else if ($key == 'relation') {
                        if ($k == 'mother' || $k == 'father') {
                            $group[] = $this->form->createElement("static", null, null, null);
                        } else {
                            $group[] = $this->form->createElement("select", $field, null, $relation);
                            $this->fieldNotRequired($field);
                        }
                    } else if ($key == 'sibling_subject') {
                        if ($k == 'mother' || $k == 'father') {
                            $group[] = $this->form->createElement("static", null, null, null);
                        } else {
                            $group[] = $this->form->createElement("select", $field, null, $options);
                            $this->fieldNotRequired($field);
                        }
                    } else if ($key == 'age_first_diagnosis') {
                        $group[] = $this->form->createElement("text", $field, null, null);
                        $this->fieldNotRequired($field);
                    } else {
                        if ($key == 'gender') {
                            $group[] = $this->form->createElement("select", $field, null, $gender);
                        } else {
                            $group[] = $this->form->createElement("select", $field, null, $options);
                        }
                        $this->fieldNotRequired($field);
                    }
                }
            }
            $this->form->addGroup($group, $groupname, $val, $this->_GUIDelimiter, false);
            unset($group);
        }
        $this->form->addFormRule(array(&$this, 'validate_main'));
    }

    function fieldNotRequired($name)
    {
        $this->XINRegisterRule(
            $name,
            array("$name{@}=={@}NEVER_REQUIRED"),
            'Not required'
        );
    }

    function validate_main($values) {
        $errors = array();

        $table_heading = array('mother', 'father', 'sibling1', 'sibling2', 'sibling3', 'sibling4', 'sibling5','sibling6');
        $questions = array('asd', 'autistic_disorder', 'asperger_syndrome', 'rett_syndrome', 'pdd_nos');
        $hasAYes = false;
        foreach ($questions as $q) {
            foreach ($table_heading as $h) {
                $question = $q . "_" . $h;
                if ($values[$question] == "yes") {
                    $hasAYes = true;
                    break;
                }
            }
        }
        if ($hasAYes) {
            foreach ($table_heading as $option) {
                $question = "age_first_diagnosis_" . $option;
                if ($values[$question] != null && $values[$question] != "") {
                    if (!is_numeric($values[$question])) {
                        $errors[$question] = "The age must be a number.";
                    }
                }
            }
        } else {
            foreach ($table_heading as $option) {
                $question = "age_first_diagnosis_" . $option;
                if ($values[$question] != null && $values[$question] != "") {
                    $errors[$question] = "You must leave this empty.";
                }
            }
        }

        return $errors;
    }
}

?>
