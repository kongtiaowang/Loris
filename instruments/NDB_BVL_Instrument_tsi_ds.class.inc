<?php

class NDB_BVL_Instrument_tsi_ds extends NDB_BVL_Instrument
{
    use LegacyInstrumentTrait;

    use instrument_validator;

    var $ValidityEnabled  = false;
    var $ValidityRequired = false;

    var $yesNo = array(
        null           => '',
        'yes'          => 'Yes',
        'no'           => 'No',
        'not_answered' => 'Not Answered'
    );

    var $educationChoices = array(
        null                      => '',
        'not_answered'            => 'Not Answered',
        'some_hs'                 => 'Some High School',
        'hs'                      => 'High School',
        'some_college_2yr_degree' => 'Some College/2yr. Degree',
        'college_degree'          => 'College Degree',
        'some_grad_school'        => 'Some Graduate School',
        'grad_degree'             => 'Graduate Degree',
    );

    var $ethnicityChoices  = array(
        null          => '',
       'hispanic'     => 'Hispanic',
       'non_hispanic' => 'Non-Hispanic',
       'not_answered' => 'Not Answered'
    );

    var $raceChoices = array(
        'white'                            => 'White',
        'black_african_american'           => 'Black or African American',
        'asian'                            => 'Asian',
        'unknown_not_reported'             => 'Unknown or not Reported',
        'american_indian_alaska_native'    => 'American Indian / Alaska Native',
        'native_hawaiian_pacific_islander' => 'Native Hawaiian / Other Pacific Islander',
    );

    var $notSavedInDbFields = array(
        'subject_name'                    => 'Subject\'s name:',
        'mother_first_name'               => 'First name:',
        'mother_middle_name'              => 'Middle name:',
        'mother_last_name'                => 'Last name:',
        'father_first_name'               => 'First name:',
        'father_middle_name'              => 'Middle name:',
        'father_last_name'                => 'Last name:',
        'phone_home'                      => 'Home phone:',
        'phone_best_time'                 => 'Best time to call:',
        'phone_work'                      => 'Phone number at work:',
        'phone_days'                      => 'Days/hrs',
        'phone_msg'                       => 'OK to leave message?',
        'phone_cell_mom'                  => 'Cell phone number (mom):',
        'phone_cell_dad'                  => 'Cell phone number (dad):',
        'phone_limited_minutes'           => 'Limited minutes?',
        'email'                           => 'Email:',
        'additional_contact_phone'        => 'Phone number of an additional contact:',
        'additional_contact_name'         => 'Contact name:',
        'additional_contact_relationship' => 'Contact relationship:',
        'parents_address'                 => 'Parent\'s address:',
        'name_sibling1'                   => 'Name:',
        'name_sibling2'                   => 'Name:',
        'name_sibling3'                   => 'Name:',
        'diagnoses'                       => 'Any diagnoses, dates and locations:',
        'cognitive_dev_testing'           => 'Has X had any other cognitive/developmental testing?',
        'evaluation_done_by'              => 'If yes, where was evaluation done/who conducted the evaluation?',
        'family_in_study'                 => 'Is any member of your family participating in a research study at this time?'
    );


    /**
     * Sets up basic data, such as the LorisForm object, and so on.
     *
     * @param string $commentID  the CommentID identifying the data to load
     * @param string $page       if a multipage form, the page to show
     * @return void
     * @access public
     */
    function setup(?string $commentID = NULL, ?string $page = NULL): void
    {
        $this->formType  = 'XIN';
        $this->form      = new LorisForm('test_form');
        $this->page      = $page;                      // page label
        $this->testName  = 'tsi_ds';                   // test_names.Test_name
        $this->table     = 'tsi_ds';                   // name of database table corresponding to instrument
        $this->commentID = $commentID;

        //The array of dates/timestamps to convert to database dates/timestamps
        //Any LorisForm date elements must be listed here
        $this->dateTimeFields=array('Date_taken');

        //The array of selects with multiple answers allowed
        //Any LorisForm multiple selects must be listed here
        $this->selectMultipleElements = array('candidate_race', 'mother_race', 'father_race');

        $this->_doubleDataEntryDiffIgnoreColumns = array(
            'CommentID',
            'UserID',
            'Testdate',
            'Window_Difference',
            'Candidate_Age',
            'Data_entry_completion_status',
            'contacted_by',
            'primary_language',
            'mother_occupation',
            'father_occupation',
            'dx_sibling1',
            'dx_sibling2',
            'dx_sibling3',
            'nature_referral_other',
            'enrolled_research_registry_list',
            'enrolled_research_study_list',
            'in_utero_substance',
            'in_utero_substance_amount',
            'in_utero_time_exposure',
            'further_information',
            'med_his_q_3_surgery_describe',
            'med_his_q_5_medications_describe',
            'med_his_q_6_allergies_describe',
            'med_his_q_8_brain_MRI_results',
            'med_his_q_9_anethesia_problems',
            'med_his_q_9_anethesia_notes',
            'med_his_q_10_nap_how_long',
            'city_of_birth',
            'review_details'
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
    function _setupForm(){
        if(preg_match("/tsi_ds(_page[0-9]+)/",$this->page,$matches)){
            call_user_func(array($this, $matches[1]));
        } else {
            $this->_main();
        }

        //Defines the call back function for HTML Quickform to use when validating the form.
        $this->form->addFormRule(array(&$this,'XINValidate'));
    }

    function _setDefaultsArray(array $defaults): array {
        //------------------------------------------------------------//
        // The subject's PSCID, DoB, age im months and Sex         //
        // are not entered manually: they all come from the database  //
        //------------------------------------------------------------//
        $defaults = parent::_setDefaultsArray($defaults);

        $ageInMonthsFormula  = '   TIMESTAMPDIFF( YEAR , DoB, CURDATE()) * 12'
                             . ' + TIMESTAMPDIFF( MONTH, DoB, CURDATE()) % 12';
        $query = "
            SELECT c.PSCID                         AS subject_pscid,
                   c.DoB                           AS subject_dob,
                   ($ageInMonthsFormula)           AS subject_age_month,
                   COALESCE(c.EDC,'UNKNOWN')       AS subject_edc,
                   c.Sex                        AS subject_gender
            FROM candidate c
            JOIN session s USING (candid)
            JOIN flag f ON (s.ID=f.sessionID)
            WHERE f.CommentID =:cid
        ";
        $db =& Database::singleton();
        $row = $db->pselectRow($query, array('cid' => $this->commentID));

        $defaults = array_merge($defaults, $row);

        //---------------------------------------------------------------------//
        // The PII fields are not saved in the database: display them          //
        // on the form anyway with read-only value 'NOT SAVED IN THE DATABASE' //
        //---------------------------------------------------------------------//
        foreach($this->notSavedInDbFields as $field => $label) {
            $defaults[$field] = 'NOT SAVED IN THE DATABASE';
        }

        $fieldsFetchedFromDb = array(
            'subject_pscid',
            'subject_dob',
            'subject_edc',
            'subject_age_month',
            'subject_gender'
        );
        foreach($fieldsFetchedFromDb as $f) {
            $defaults[$f] = $row[$f] ?? 'UNKNOWN';
        }

        return $defaults;
    }

    /**
     * generates the main ('Top') page of the form.
     *
     * @return void
     */
    function _main(){
        // display test name
        $this->form->addElement('header', 'instrument_title', 'Telephone Screening Interview - Down Syndrome Study');

        $this->addCheckbox('not_finish0', 'Form not acquired to completion due to candidate determined as ineligible during screening interview.', array('value' => '1'));

        // automatically adds examiner & date of administration
        $this->_addMetadataFields();

        $this->form->addElement('header', null, 'Identifying information');

        $subjectInfoFields = array(
            'subject_name'      => $this->notSavedInDbFields['subject_name'],
            'subject_pscid'     => 'Subject ID:',
            'contact'           => 'Date of Contact:',
            'contacted_by'      => 'Contacted By:',
            'subject_dob'       => 'Date of Birth:',
            'subject_age_month' => 'Subject\'s age (in months):',
            'subject_edc'       => 'Expected Due Date:',
            'subject_gender'    => 'Subject\'s Gender:'
        );

        //---------------------//
        // PII subject info    //
        //---------------------//
        foreach ($subjectInfoFields as $field => $label) {
            switch ($label) {
                case 'Date of Contact:':
                    $this->addDateElement($field, $label);
                    break;
                case 'Contacted By:':
                    $this->addTextElement($field, $label);
                    break;
                default;
                    $this->addScoreColumn($field, $label);
            }
        }

        //--------------------//
        //     Ethnicity      //
        //--------------------//
        $this->form->addSelect('child_ethnicity' , 'Candidate Ethnicity:', $this->ethnicityChoices);
        $this->form->addSelect('mother_ethnicity', 'Mother Ethnicity:'   , $this->ethnicityChoices);
        $this->form->addSelect('father_ethnicity', 'Father Ethnicity:'   , $this->ethnicityChoices);

        //-----------------//
        //      Race       //
        //-----------------//
        $this->addSelect('candidate_race', 'Candidate Race (select all that apply):', $this->raceChoices, array('multiple'));
        $this->addSelect('mother_race'   , 'Mother Race (select all that apply):'   , $this->raceChoices, array('multiple'));
        $this->addSelect('father_race'   , 'Father Race (select all that apply):'   , $this->raceChoices, array('multiple'));

        $this->form->addRule('candidate_race', 'Must answer this race question', 'required');
        $this->form->addRule('mother_race'   , 'Must answer this race question', 'required');
        $this->form->addRule('father_race'   , 'Must answer this race question', 'required');

        $this->addTextElement('primary_language', 'Primary language spoken in the home:');

        $this->form->addElement('header', null, 'Parents Information');


        //------------------------//
        //  Mother information    //
        //------------------------//
        $this->form->addElement('static', null, '<u>Mother\'s Information</u>');

        $this->addScoreColumn('mother_first_name' , $this->indent . $this->notSavedInDbFields['mother_first_name']);
        $this->addScoreColumn('mother_middle_name', $this->indent . $this->notSavedInDbFields['mother_middle_name']);
        $this->addScoreColumn('mother_last_name'  , $this->indent . $this->notSavedInDbFields['mother_last_name']);

        $this->addSelect('mother_education', "{$this->indent}Highest Level of Education", $this->educationChoices);

        $config =& NDB_Config::singleton();
        $this->dateOptions = array(
            'language'         => 'en',
            'format'           => 'YMd',
            'minYear'          => $config->getSetting('startYear') - 80,
            'maxYear'          => $config->getSetting('endYear'),
            'addEmptyOption'   => true,
            'emptyOptionValue' => null
        );
        $this->addDateElement('mother_dob', "{$this->indent}Date of Birth:");
        $this->addTextElement('mother_occupation', "{$this->indent}Occupation:");

        $this->form->addElement('static', null, '<br>');

        //------------------------//
        //  Mother information    //
        //------------------------//
        $this->form->addElement('static', null, '<u>Father\'s Information</u>');

        $this->addScoreColumn('father_first_name' , $this->indent . $this->notSavedInDbFields['father_first_name']);
        $this->addScoreColumn('father_middle_name', $this->indent . $this->notSavedInDbFields['father_middle_name']);
        $this->addScoreColumn('father_last_name'  , $this->indent . $this->notSavedInDbFields['father_last_name']);

        $this->addSelect('father_education', "{$this->indent}Highest Level of Education", $this->educationChoices);
        $this->addDateElement('father_dob', "{$this->indent}Date of Birth:");
        $this->addTextElement('father_occupation', "{$this->indent}Occupation:");

        $this->form->addElement('static', null, '<br>');
        $this->addSelect(
            'ses_income',
            'SES:',
            array(
                null           => '',
                'less_than_25K'=>'less than $24,999',
                '25K-35K'      => '$25,000 - 34,999',
                '35K-50K'      => '$35,000 - 49,999',
                '50K-75K'      => '$50,000 - 74,999',
                '75K-100K'     => '$75,000 - 99,999',
                '100K-150K'    => '$100,000 - 149,999',
                '150K-200K'    => '$150,000 - 199,000',
                'over_200K'    => 'over $200,000',
                'not_answered' => 'Not Answered'
            )
        );

        //-------------------------------------------//
        //  PII: parent's phone/email information    //
        //-------------------------------------------//
        $this->form->addElement('static', null, '<br>');
        $this->form->addElement('static', null, '<u>Parent\'s telephone:</u>');
        $phoneFields = array(
            'phone_home',
            'phone_best_time',
            'phone_work',
            'phone_days',
            'phone_msg',
            'phone_cell_mom',
            'phone_cell_dad',
            'phone_limited_minutes',
            'email',
            'additional_contact_phone',
            'additional_contact_name',
            'additional_contact_relationship',
        );
        foreach ($phoneFields as $field) {
            $this->addScoreColumn($field, $this->indent . $this->notSavedInDbFields[$field]);
        }

        $this->addScoreColumn('parents_address', $this->notSavedInDbFields['parents_address']);

        $this->form->addElement('static', null, '<br>');

        //-----------------------------//
        // Other siblings information  //
        //-----------------------------//
        $this->form->addElement('static', null, '<u>Other Siblings</u>');
        $this->addSelect(
            'nb_siblings',
            "{$this->indent}Number of siblings:",
            array(
                ''             => null,
                '0'            => '0',
                '1'            => '1',
                '2'            => '2',
                '3'            => '3',
                'not_answered' => 'Not Answered'
             )
        );

        $this->dateOptions = array(
            'language'         => 'en',
            'format'           => 'YMd',
            'minYear'          => $config->getSetting('startYear') - 20,
            'maxYear'          => $config->getSetting('endYear'),
            'addEmptyOption'   => true,
            'emptyOptionValue' => null
        );

        for($i = 1; $i<=3; $i++) {
            $this->form->addElement('static', null, "{$this->indent}<u>Sibling $i (if applicable)</u>");

            $this->addScoreColumn("name_sibling$i", $this->indent . $this->indent . $this->notSavedInDbFields["name_sibling$i"]);

            $this->addDateElement("dob_sibling$i", "{$this->indent}{$this->indent}Date of birth:");
            $this->XINRegisterRule("dob_sibling{$i}_date", array("dob_sibling{$i}_date{@}=={@}NEVER_REQUIRED"));
            $this->XINRegisterRule("dob_sibling{$i}_date_status", array("dob_sibling{$i}_date_status{@}=={@}NEVER_REQUIRED"));

            $this->addTextElement("dx_sibling$i", "{$this->indent}{$this->indent}Dx:");
            $this->XINRegisterRule("dx_sibling$i", array("dx_sibling$i{@}=={@}NEVER_REQUIRED"));
            $this->XINRegisterRule("dx_sibling{$i}_status", array("dx_sibling{$i}_status{@}=={@}NEVER_REQUIRED"));

            $this->addSelect(
                "relation_sibling$i",
                "{$this->indent}{$this->indent}Specify relationship:",
                array(
                    ''             => null,
                    'half_sibling' => 'Half sibling',
                    'full_sibling' => 'Full sibling',
                    'step_sibling' => 'Step sibling',
                    'not_answered' => 'Not Answered'
                )
            );
            $this->XINRegisterRule("relation_sibling$i", array("relation_sibling$i{@}=={@}NEVER_REQUIRED"));

            $this->addSelect(
                "live_at_home_sibling$i",
                "{$this->indent}{$this->indent}Live in home:",
                array(
                    ''            => null,
                    'yes'         => 'Yes',
                    'no'          => 'No',
                    'part_time'   => 'Part time',
                    'not_answered'=> 'Not Answered'
                )
            );
            $this->XINRegisterRule("live_at_home_sibling$i", array("live_at_home_sibling$i{@}=={@}NEVER_REQUIRED"));
         }

         //----------------------------------//
         // Referral/other studies section   //
         //----------------------------------//
         $this->form->addElement('static', null, '<br><br>');
         $this->addSelect(
             'nature_referral',
             'Nature of referral:',
             array(
                 ''                 => null,
                 'self_referred'    => 'Self referred',
                 'referred_registry'=> 'Referred by registry',
                 'referred_clinic'  => 'Referred by clinic',
                 'other'            => 'Other (specify):',
                 'not_answered'     => 'Not answered'
             )
         );
         $this->addTextAreaElement('nature_referral_other', "{$this->indent}If other, please specify:");
         $this->XINRegisterRule('nature_referral_other', array('nature_referral_other{@}=={@}NEVER_REQUIRED'));
         $this->XINRegisterRule('nature_referral_other_status', array('nature_referral_other_status{@}=={@}NEVER_REQUIRED'));

         $this->addSelect('enrolled_research_registry', 'Enrolled in a Research Registry?', $this->yesNo);
         $this->addTextAreaElement('enrolled_research_registry_list', "{$this->indent}If yes, please list:");
         $this->XINRegisterRule('enrolled_research_registry_list'       , array('enrolled_research_registry_list{@}=={@}NEVER_REQUIRED'));
         $this->XINRegisterRule('enrolled_research_registry_list_status', array('enrolled_research_registry_list_status{@}=={@}NEVER_REQUIRED'));

         $this->addSelect('enrolled_research_study', 'Enrolled in any other Research Studies?', $this->yesNo);
         $this->addTextAreaElement('enrolled_research_study_list', "{$this->indent}If yes, please list:");
         $this->XINRegisterRule('enrolled_research_study_list'       , array('enrolled_research_study_list{@}=={@}NEVER_REQUIRED'));
         $this->XINRegisterRule('enrolled_research_study_list_status', array('enrolled_research_study_list_status{@}=={@}NEVER_REQUIRED'));

         $this->XINRegisterRule("primary_language", array("not_finish0{@}!={@}1"), 'Required.');
         $this->XINRegisterRule("primary_language_status", array("not_finish0{@}!={@}1"), 'Required.');
         $this->XINRegisterRule("mother_education", array("not_finish0{@}!={@}1"), 'Required.');
         $this->XINRegisterRule("mother_ethnicity", array("not_finish0{@}!={@}1"), 'Required.');
         $this->XINRegisterRule("father_ethnicity", array("not_finish0{@}!={@}1"), 'Required.');
         $this->XINRegisterRule("child_ethnicity", array("not_finish0{@}!={@}1"), 'Required.');
         $this->XINRegisterRule("contacted_by", array("not_finish0{@}!={@}1"), 'Required.');
         $this->XINRegisterRule("contacted_by_status", array("not_finish0{@}!={@}1"), 'Required.');
         $this->XINRegisterRule("contact_date", array("not_finish0{@}!={@}1"), 'Required.');
         $this->XINRegisterRule("contact_date_status", array("not_finish0{@}!={@}1"), 'Required.');
         $this->XINRegisterRule("mother_dob_date", array("not_finish0{@}!={@}1"), 'Required.');
         $this->XINRegisterRule("mother_dob_date_status", array("not_finish0{@}!={@}1"), 'Required.');
         $this->XINRegisterRule("mother_occupation", array("not_finish0{@}!={@}1"), 'Required.');
         $this->XINRegisterRule("mother_occupation_status", array("not_finish0{@}!={@}1"), 'Required.');
         $this->XINRegisterRule("father_education", array("not_finish0{@}!={@}1"), 'Required.');
         $this->XINRegisterRule("father_dob_date", array("not_finish0{@}!={@}1"), 'Required.');
         $this->XINRegisterRule("father_dob_date_status", array("not_finish0{@}!={@}1"), 'Required.');
         $this->XINRegisterRule("father_occupation", array("not_finish0{@}!={@}1"), 'Required.');
         $this->XINRegisterRule("father_occupation_status", array("not_finish0{@}!={@}1"), 'Required.');
         $this->XINRegisterRule("ses_income", array("not_finish0{@}!={@}1"), 'Required.');
         $this->XINRegisterRule("nb_siblings", array("not_finish0{@}!={@}1"), 'Required.');
         $this->XINRegisterRule("nature_referral", array("not_finish0{@}!={@}1"), 'Required.');
         $this->XINRegisterRule("enrolled_research_registry", array("not_finish0{@}!={@}1"), 'Required.');
         $this->XINRegisterRule("enrolled_research_study", array("not_finish0{@}!={@}1"), 'Required.');


         $this->form->addFormRule(array(&$this, 'validate_main'));
    }










    /**
     * Displays page 1 of the form.
     *
     * @return void
     */
    function _page1(){

        $this->form->addElement('header', null, 'Section B: Exclusionary Factors INFANT SUBJECTS');

        $this->addCheckbox('not_finish1', 'Form not acquired to completion due to candidate determined as ineligible during screening interview.', array('value' => '1'));

        $questionArray = array(
            'neurological_problems'        => 'Any neurological problems such as cerebral palsy or tuberous sclerosis in SUBJECT?',
            'genetic_conditions'           => 'Diagnosed/suspected genetic conditions or syndromes besides Down Syndrome?',
            'seizures_or_neuro_disorder'   => 'Seizures or other neurological disorder?',
            'cns_problems'                 => 'CNS problems?',
            'congenital_heart_problems'    => 'Congenital heart problems or abnormalities?',
            'atriaseptal_defects'          => 'Significant atrialseptal defects?',
            'hearing_vision_impairments'   => 'Significant hearing/vision problems?',
            'diabetes'                     => 'Diabetes or gestational diabetes?',
            'complications_birth'          => 'Any complications at birth?(Ex: vaccum extraction?)',
            'premature_birth'              => 'Premature birth (<37 weeks )?',
            'low_birth_weight'             => 'Birth weight <4lbs. 6oz. (2000 grams)?',
            'delivery_problems'            => 'Problems during delivery?',
            'tetralogy_fallot'             => 'Tetralogy of fallot?',
            'gastrointestinal_malformation'=> 'Severe gastrointestinal malformations, such as a significant trachea-esphogeal fistula?'
        );

        foreach($questionArray as $field=>$label) {
            $this->addYesNoSelect($field, $label);
            if ($field == 'premature_birth') {
                $this->addTextElement(
                    'weeks_gestation',
                    "{$this->indent}If yes, indicate the number of weeks of gestation",
                    array('premature_birth{@}=={@}yes'),
                    'Please enter a number between 1 and 37'
                );
            }
        }
        $this->addYesNoSelect(
            'in_utero_exposure',
            'Exposure in-utero to meds,tobacco, alcohol, or drugs (Rx or non)'
        );

        $questionArray = array(
            'substance'        => 'Name of substance (get spelling):',
            'substance_amount' => 'Amount of substance at one time:',
            'time_exposure'    => 'Time period of exposure (weeks of pregnancy):'
         );
        foreach($questionArray as $field=>$label) {
            $this->addTextElement(
                "in_utero_$field",
                $this->indent . $label,
                array('in_utero_exposure{@}=={@}yes'),
                'This field is required if there was exposure in-utero'
            );
        }

        $this->addTextAreaElement('further_information', 'If yes to any of the above, obtain further information.');

         $this->XINRegisterRule("neurological_problems", array("not_finish1{@}!={@}1"), 'Required.');
         $this->XINRegisterRule("genetic_conditions", array("not_finish1{@}!={@}1"), 'Required.');
         $this->XINRegisterRule("seizures_or_neuro_disorder", array("not_finish1{@}!={@}1"), 'Required.');
         $this->XINRegisterRule("cns_problems", array("not_finish1{@}!={@}1"), 'Required.');
         $this->XINRegisterRule("congenital_heart_problems", array("not_finish1{@}!={@}1"), 'Required.');
         $this->XINRegisterRule("atriaseptal_defects", array("not_finish1{@}!={@}1"), 'Required.');
         $this->XINRegisterRule("hearing_vision_impairments", array("not_finish1{@}!={@}1"), 'Required.');
         $this->XINRegisterRule("diabetes", array("not_finish1{@}!={@}1"), 'Required.');
         $this->XINRegisterRule("complications_birth", array("not_finish1{@}!={@}1"), 'Required.');
         $this->XINRegisterRule("premature_birth", array("not_finish1{@}!={@}1"), 'Required.');
         $this->XINRegisterRule("low_birth_weight", array("not_finish1{@}!={@}1"), 'Required.');
         $this->XINRegisterRule("delivery_problems", array("not_finish1{@}!={@}1"), 'Required.');
         $this->XINRegisterRule("tetralogy_fallot", array("not_finish1{@}!={@}1"), 'Required.');
         $this->XINRegisterRule("gastrointestinal_malformation", array("not_finish1{@}!={@}1"), 'Required.');
         $this->XINRegisterRule("further_information", array("not_finish1{@}!={@}1"), 'Required.');
         $this->XINRegisterRule("further_information_status", array("not_finish1{@}!={@}1"), 'Required.');
         $this->XINRegisterRule("in_utero_exposure", array("not_finish1{@}!={@}1"), 'Required.');

        $this->form->addFormRule(array(&$this, 'validate_page1'));
    }

    /**
     * Displays page 2 of the form.
     *
     * @return void
     */
    function _page2() {
        $this->form->addElement('header', null, 'Medical History Pertaining to MRI/Sedation');

        $this->addCheckbox('not_finish2', 'Form not acquired to completion due to candidate determined as ineligible during screening interview.', array('value' => '1'));

        $this->addYesNoSelect(
            'med_his_q_1_med_surgical_problems',
            '1. Has X ever had any serious medical or surgical problems?'
        );
        $this->addYesNoSelect(
            'med_his_q_2_hospitalized',
            '2. Has X ever been hospitalized?'
        );
        $this->addYesNoSelect(
            'med_his_q_3_surgery',
            '3. Surgery of any type?'
        );
        $this->addTextElement(
            'med_his_q_3_surgery_describe',
            "{$this->indent}Describe:",
            array('med_his_q_3_surgery{@}=={@}yes'),
            'This field is required if there was surgery'
        );
        $this->addYesNoSelect(
            'med_his_q_4_metal',
            '4. Does X have any metal plates, clips, etc. from surgery?<br>(pacemaker, vascular stints, metallic ear tubes, other metal implants or braces)'
        );
        $this->addYesNoSelect(
            'med_his_q_5_medications',
            '5. Has X taken any medications over the last 12 months?'
        );
        $this->addTextElement(
            'med_his_q_5_medications_describe',
            "{$this->indent}If yes, list medications:",
            array('med_his_q_5_medications{@}=={@}yes'),
            'This field is required if there were medications'
        );
        $this->addYesNoSelect(
            'med_his_q_6_allergies',
            '6. Does X have any allergies to medicines?'
        );
        $this->addTextElement(
            'med_his_q_6_allergies_describe',
            "{$this->indent}If yes, describe:",
            array('med_his_q_6_allergies{@}=={@}yes'),
            'This field is required if there are allergies'
        );
        $this->addYesNoSelect(
            'med_his_q_7_doctor',
            '7. Has X seen a doctor over the last 12 months?'
        );
        $this->addYesNoSelect(
            'med_his_q_8_brain_MRI',
            '8. Has X ever had an MRI of the brain?'
        );
        $this->addSelect(
            'med_his_q_8_brain_MRI_results',
            "{$this->indent}If yes, what were the results?",
            array(null => '', 'typical' => 'Typical', 'atypical' => 'Atypical', 'not_answered' => 'Not Answered')
        );
        $this->XINRegisterRule ('med_his_q_8_brain_MRI_results', array('med_his_q_8_brain_MRI{@}=={@}yes'), 'Please specify the results of the MRI');
        $this->addTextElement(
            'med_his_q_8_brain_MRI_notes',
            "{$this->indent}Notes"
        );
        $this->XINRegisterRule (
            'med_his_q_8_brain_MRI_notes',
            array('med_his_q_8_brain_MRI_results{@}=={@}atypical'),
            'Please enter notes or select \'Not answered\'',
            'med_his_q_8_brain_MRI_notes_group'
        );

        $this->addYesNoSelect(
            'med_his_q_9_anethesia',
            '9. Has X ever had anesthesia or other forms of sedation?'
        );
        $this->addYesNoSelect(
            'med_his_q_9_anethesia_problems',
            "{$this->indent}Problems with sedation?"
        );
        $this->addTextElement(
            'med_his_q_9_anethesia_notes',
            "{$this->indent}Notes:"
        );
        $this->XINRegisterRule (
            'med_his_q_9_anethesia_notes',
            array('med_his_q_9_anethesia{@}=={@}yes'),
            'Please enter notes or select \'Not answered\'',
            'med_his_q_9_anethesia_notes_group'
        );

        $this->addYesNoSelect('med_his_q_10_nap', '10. Does X nap during the day?');
        $this->addTextElement('med_his_q_10_nap_how_long', "{$this->indent}If yes, when & how long?");
        $this->XINRegisterRule ('med_his_q_10_nap_how_long', array('med_his_q_10_nap{@}=={@}yes'), 'Please specify a duration');
        $this->addSelect(
            'med_his_q_11_likelihood_sleep',
            '11. On a scale of 1-10, please rate the likelihood of your child sleeping through a scan.',
            array(null => '', 1=>'1', 2=>'2',  3=>'3', 4=>'4', 5=>'5', 6=>'6', 7=>'7', 8=>'8', 9=>'9', 10=>'10', 'not_answered'=>'Not Answered')
        );

         $this->XINRegisterRule("med_his_q_1_med_surgical_problems", array("not_finish2{@}!={@}1"), 'Required.');
         $this->XINRegisterRule("med_his_q_2_hospitalized", array("not_finish2{@}!={@}1"), 'Required.');
         $this->XINRegisterRule("med_his_q_3_surgery", array("not_finish2{@}!={@}1"), 'Required.');
         $this->XINRegisterRule("med_his_q_4_metal", array("not_finish2{@}!={@}1"), 'Required.');
         $this->XINRegisterRule("med_his_q_5_medications", array("not_finish2{@}!={@}1"), 'Required.');
         $this->XINRegisterRule("med_his_q_6_allergies", array("not_finish2{@}!={@}1"), 'Required.');
         $this->XINRegisterRule("med_his_q_7_doctor", array("not_finish2{@}!={@}1"), 'Required.');
         $this->XINRegisterRule("med_his_q_8_brain_MRI", array("not_finish2{@}!={@}1"), 'Required.');
         $this->XINRegisterRule("med_his_q_9_anethesia", array("not_finish2{@}!={@}1"), 'Required.');
         $this->XINRegisterRule("med_his_q_9_anethesia_problems", array("not_finish2{@}!={@}1"), 'Required.');
         $this->XINRegisterRule("med_his_q_10_nap", array("not_finish2{@}!={@}1"), 'Required.');
         $this->XINRegisterRule("med_his_q_11_likelihood_sleep", array("not_finish2{@}!={@}1"), 'Required.');
    }


    /**
     * Adds a drop down list widget with choices '', 'Yes', 'No' and 'Not answered'.
     *
     * @param string $field drop-down name.
     * @param string $text  text to display in front of the drop-down list.
     *
     * @return void
     */
    function addYesNoSelect(string $field, string $text) {
        $this->form->addElement('select', $field, $text, $this->yesNo);
    }

    /**
     * Displays page 3 of the form.
     *
     * @return void
     */
    function _page3() {
        $this->form->addElement('header', null, 'Medical Records');

        $this->addCheckbox('not_finish3', 'Form not acquired to completion due to candidate determined as ineligible during screening interview.', array('value' => '1'));

        $this->addTextElement('city_of_birth', 'City of Birth:');

        $this->addScoreColumn('diagnoses'            , $this->notSavedInDbFields['diagnoses']);
        $this->addScoreColumn('cognitive_dev_testing', $this->notSavedInDbFields['cognitive_dev_testing']);
        $this->addScoreColumn('evaluation_done_by'   , "{$this->indent}{$this->notSavedInDbFields['evaluation_done_by']}");
        $this->addScoreColumn('family_in_study'      , $this->notSavedInDbFields['family_in_study']);

        $this->form->addElement('header', null, 'FOR RESEARCH STAFF TO COMPLETE');

        $this->form->addElement('static', null, '<u>Exclusion/Inclusion</u>');
        $this->addYesNoSelect(
            'exc_inc_meets_criteria',
            "{$this->indent}1. This infant meets any of the medical or neurological exclusion criteria for this study."
        );
        $this->addYesNoSelect(
            'exc_inc_contraindication',
            "{$this->indent}2. This subject has evidence for contraindication to MRI."
        );

        $this->form->addElement('static', null, '<u>Disposition</u>');
        $this->addYesNoSelect(
            'goto_next_level',
            "{$this->indent}Proceed to next level beyond screening?"
        );
        $this->addYesNoSelect('possible_exclusion', "{$this->indent}Possible exclusion reviewed by KB?");
        $this->addTextElement('review_details'    , "{$this->indent}{$this->indent}If yes, what was reviewed and what decision was made?");
        $this->XINRegisterRule('review_details', array('possible_exclusion{@}=={@}yes'), 'Please specify the details', 'review_details_group');

        $config =& NDB_Config::singleton();
        $this->dateOptions = array(
            'language'         => 'en',
            'format'           => 'YMd',
            'minYear'          => $config->getSetting('startYear') - 20,
            'maxYear'          => $config->getSetting('endYear'),
            'addEmptyOption'   => true,
            'emptyOptionValue' => null
        );

        $this->addDateElement('review'            , "{$this->indent}{$this->indent}Date received exclusion review decision:");
        $this->XINRegisterRule('review_date', array('possible_exclusion{@}=={@}yes'), 'Please specify the date of the review', 'review_date_group');

         $this->XINRegisterRule("city_of_birth", array("not_finish3{@}!={@}1"), 'Required.');
         $this->XINRegisterRule("city_of_birth_status", array("not_finish3{@}!={@}1"), 'Required.');
         $this->XINRegisterRule("exc_inc_meets_criteria", array("not_finish3{@}!={@}1"), 'Required.');
         $this->XINRegisterRule("exc_inc_contraindication", array("not_finish3{@}!={@}1"), 'Required.');
         $this->XINRegisterRule("goto_next_level", array("not_finish3{@}!={@}1"), 'Required.');
         $this->XINRegisterRule("possible_exclusion", array("not_finish3{@}!={@}1"), 'Required.');

    }

    /**
     * Validates the main ('Top') page of the form
     *
     * @param array $values Values entered in the form.
     *
     * @return void
     */
    function validate_main($values) {
        $errors = array();

        $races = array('candidate_race', 'mother_race', 'father_race');
        foreach($races as $r) {
            if(in_array('unknown_not_reported', $values[$r]) && count($values[$r]) > 1) {
                $errors[$r] = 'If you choose unknown, it must be the only item selected';
            }
        }

        if($values['nature_referral'] == 'other') {
            if($values['nature_referral_other'] == '' && $values['nature_referral_other_status'] != 'not_answered') {
                $errors['nature_referral_other_group'] = 'Specify the nature of the referral';
            }
        }

        if($values['enrolled_research_study'] == 'yes') {
            if($values['enrolled_research_study_list'] == '' && $values['enrolled_research_study_list_status'] != 'not_answered') {
                $errors['enrolled_research_study_list_group'] = 'Specify the nature of the referral';
            }
        }

        if($values['enrolled_research_registry'] == 'yes') {
            if($values['enrolled_research_registry_list'] == '' && $values['enrolled_research_registry_list_status'] != 'not_answered') {
                $errors['enrolled_research_registry_list_group'] = 'Specify the nature of the referral';
            }
        }

        if($values['nb_siblings'] != '') {
            $this->validateSiblingSection(1, $values, $errors);
            $this->validateSiblingSection(2, $values, $errors);
            $this->validateSiblingSection(3, $values, $errors);
        }

        return $errors;
    }

    /**
     * Validates a given sibling section on the main page.
     *
     * @param int   $idx    Index (1,2 or 3) of the section to validate.
     * @param array $values Values entered on page 1.
     * @param array $values Errors found on page 1.
     *
     * @return array $errors found in the given sibling section.
     */
    function validateSiblingSection($idx, $values, &$errors) {
        $fields = array(
            "dob_sibling{$idx}_date",
            "dx_sibling{$idx}",
            "relation_sibling{$idx}",
            "live_at_home_sibling{$idx}"
        );

        foreach($fields as $f) {
            //-------------------------------------------------------//
            // Validate that if the section should be filled, it is  //
            //-------------------------------------------------------//
            if($values['nb_siblings'] != 'not_answered' && $values['nb_siblings'] >= $idx) {
                if($values["dob_sibling{$idx}_date"] == '' && $values["dob_sibling{$idx}_date_status"] == '') {
                    $errors["dob_sibling{$idx}_date_group"] = "You have to either specify a date of birth or choose 'Not Answered'";
                }
                if($values["dx_sibling{$idx}"] == '' && $values["dx_sibling{$idx}_status"] == '') {
                    $errors["dx_sibling{$idx}_group"] = "You have to either specify a date of birth or choose 'Not Answered'";
                }
                if($values["relation_sibling{$idx}"] == '') {
                    $errors["relation_sibling{$idx}"] = "This field is required";
                }
                if($values["live_at_home_sibling{$idx}"] == '') {
                    $errors["live_at_home_sibling{$idx}"] = "This field is required";
                }
            //--------------------------------------------------------------------------//
            // Validate that if the section should not be filled, all fields are blank  //
            //--------------------------------------------------------------------------//
            } else {
                $nbSiblings = $values['nb_siblings'] == 'not_answered' ? "'Not Answered'" : $values['nb_siblings'];
                if($values["dob_sibling{$idx}_date"] != '' || $values["dob_sibling{$idx}_date_status"] != '') {
                    $errors["dob_sibling{$idx}_date_group"] = "You must leave this field blank as the number of siblings is $nbSiblings";
                }
                if($values["dx_sibling{$idx}"] != '' || $values["dx_sibling{$idx}_status"] != '') {
                    $errors["dx_sibling{$idx}_group"] = "You must leave this field blank as the number of siblings is $nbSiblings";
                }
                if($values["relation_sibling{$idx}"] != '') {
                    $errors["relation_sibling{$idx}"] = "You must leave this field blank as the number of siblings is $nbSiblings";
                }
                if($values["live_at_home_sibling{$idx}"] != '') {
                    $errors["live_at_home_sibling{$idx}"] = "You must leave this field blank as the number of siblings is $nbSiblings";
                }
            }
        }
    }

    /**
     * Validates page 1.
     *
     * @param array $values Values entered in the form.
     *
     * @return void
     */
    function validate_page1($values) {

        $errors = array();

        if($values['premature_birth'] == 'yes' && $values['weeks_gestation_status'] != 'not_answered') {
            $this->validate_numeric_strict_group($values, 'weeks_gestation', $errors, 1, 37, 'weeks_gestation_group', 'weeks of gestation');
        }

        return $errors;
    }
}


