<?php
/**
 *This file contains the NDB_BVL_acesubjectmedical_survey class
 *
 * PHP Version 7
 *
 * @category Instrument
 * @package  Neuropsych
 * @author   Ling Ma
 * @license  http://www.gnu.org/licenses/gpl-3.0.txt GPLv3
 * @link     https://www.github.com/aces/IBIS/
 */
class NDB_BVL_Instrument_acesubjectmedical_survey extends NDB_BVL_Instrument
{
    var $ValidityRequired = false;

    public function getFullName(): string
    {
        return 'ACE Subject Medical History Survey';
    }

    function getSubtestList(): array {
        return [['Name' => 'acesubjectmedical_survey_page1', 'Description' => 'Page 1'],
            ['Name' => 'acesubjectmedical_survey_page2', 'Description' => 'Page 2'],
            ['Name' => 'acesubjectmedical_survey_page3', 'Description' => 'Page 3']
        ];
    }

    private const default_option = [
        NULL => '',
        'No' => 'No',
        'Yes' => 'Yes',
        'nk' => 'Not Known'
    ];

    /**
    * Sets up basic data, such as the LorisForm object, and so on.
    *
    * @param string $commentID the CommentID identifying the data to load
    * @param string $page      if a multipage form, the page to show
    *
    * @return void
    *
    * @access public
    */
    function setup(?string $commentID = NULL, ?string $page = NULL): void
    {
        $this->formType ='XIN';
        $this->form     = new LorisForm('test_form');
        $this->page     = $page;            // page label (number or string - used by user-defined child classes)

        // set the object properties
        $this->testName = 'acesubjectmedical_survey';           // test_names.Test_name
        $this->table    = 'acesubjectmedical_survey';              // name of database table corresponding to instrument
        // data keyed by commentID
        $this->commentID = $commentID;

        //The array of dates/timestamps to convert to database dates/timestamps
        //Any LorisForm date elements must be listed here
        $this->dateTimeFields =array('Date_taken');

        // required fields for data entry completion status
        $this->_requiredElements = ['Date_taken', 'rev_skinabscesses', 'rev_immunoimmunization', 'touret'];

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
        if (preg_match("/acesubjectmedical_survey(_page[0-9]+)/", $this->page, $matches)) {
            call_user_func(array($this, $matches[1]));
        } else {
            $this->_main();
        }

        //Defines the call back function for HTML Quickform to use when validating the form.
        $this->form->addFormRule(array(&$this, 'XINValidate'));
    }

    function create_form_item($item_def) {
        foreach ($item_def as $key => $item) {
            if (isset($item['t']) && ($item['t'] == 'sec')) {
                $this->addLabel('<b>' . $item['l'] . '<b>');
            }
            else {
                if (isset($item['o'])) {
                    $multiple = isset($item['multiple'])? true: false;
                    if ($multiple) {
                        $group = [];
                        $option = ['No', 'Yes']; // Full text necessary because of the way advcheckbox and survey_module implemented.
                        foreach ($item['o'] as $itmKey => $itmLabel) {
                            $localKey = "{$key}_{$itmKey}";
                            $group[] = $this->form->createElement('advcheckbox', $localKey, $item['l'] . ' ' . $itmLabel . ':', $itmLabel, null, $option);
                            $this->XINRegisterRule(
                                $localKey,
                                array("$localKey{@}=={@}NEVER_REQUIRED"),
                                'Not required'
                            );
                        }
                        $this->addGroup($group, $key . "_group", $item['l'], null, false);
                        unset($group);
                    }
                    else {
                        $this->addSelect($key, $item['l'], $item['o']);
                    }

                }
                else {
                    $this->addBasicText($key, $item['l']);
                }
            }
        }
    }

    /**
    * Generates the main page of the form.
    *
    * @return void
    * @access private
    */
    function _main()
    {
        // display test name
        $this->addHeader('ACE Subject Medical History');

        $config      =& NDB_Config::singleton();

        $dateOptions = array(
            'language'         => 'en',
            'format'           => 'YMd',
            'minYear'          => $config->getSetting('startYear'),
            'maxYear'          => $config->getSetting('endYear'),
            'addEmptyOption'   => true,
            'emptyOptionValue' => null,
        );
        $this->form->addElement('static', null, "<i><h3>*Please fill this form out with regard to your child who has enrolled in our study, NOT their older sibling with autism</i></h3>");

        $this->addBasicDate('Date_taken', 'Date Taken', $dateOptions);

        $this->create_form_item(self::Items1);

        $this->form->addFormRule(array(&$this, 'main_valueControl'));

        $rules = [
            'info_gest' => ['l' => 'Specify gestation period', 'r' => 'full_term{@}=={@}No'],
            'verb_words' => ['l' => 'Specify how many words', 'r' => 'current_lang{@}=={@}Yes']
        ];

        foreach ($rules as $key => $itm) {
            $this->XINRegisterRule(
                $key,
                array($itm['r']),
                $itm['l']);
        }
    }

    function main_valueControl($values) {
        $def = [];
        foreach (self::Items1 as $key => $itm) {
            if (isset($itm['r'])) {
                $def[$key] = $itm['r'];
            }
        }

        $errors = array();

        foreach ($def as $key => $range) {
            if (!empty($values[$key])) {
                if ($values[$key] < $range[0]) {
                    $errors[$key] = "Must be no less than $range[0].";
                }
                else if ($values[$key] > $range[1]) {
                    $errors[$key] = "Must be no more than $range[1].";
                }
            }
        }
        if (in_array($values['full_term'], ['Yes', 'nk']) && !empty($values['info_gest'])) {
            $errors['info_gest'] = 'You have chosen ' . ($values['full_term'] == 'Yes' ? "Yes" : "Not Known") . ', a value should not be here.';
        }
        if ($values['current_lang'] == 'No' && !empty($values['verb_words'])) {
            $errors['verb_words'] = 'You have chosen No for "Current speech/language: Verbal?", a choice should not be made here.';
        }
        return $errors;
    }

    /**
     * Generates the first page of the form.
     *
     *@return void
     */
    function _page1()
    {
        $this->addHeader('Review of Systems');

        $items2 = [
            '1' => ['t' => 'sec', 'l' => 'Head/Brain'],
            'rev_headmeningitis' => ['l' => '23. Meningitis',
                'o' => self::default_option
            ],
            'rev_headmeningitisage' => [
                'l' => 'Meningitis: Age (in months)',
            ],
            'rev_headmeningitisorg' => [
                'l' => 'Meningitis: Organism',
            ],
            'rev_headencephalitis' => ['l' => '24. Encephalitis',
                'o' => self::default_option
            ],
            'rev_headencephalitisage' => ['l' => 'Encephalitis: Age (in months)',
            ],
            'rev_headencephalitisorg' => ['l' => 'Encephalitis: Organism',
            ],
            'rev_headfebseiz' => ['l' => '25. Febrile Seizures',
                'o' => self::default_option
            ],
            'rev_headfebseizage' => ['l' => 'Febrile Seizures: Age (months)',
            ],
            'rev_headseizure' => ['l' => '26. Non-Febrile Seizures',
                'o' => self::default_option
            ],
            'rev_headseizureonset' => ['l' => 'Non-Febrile Seizures: Onset',
            ],
            'rev_headseizurecontrol' => ['l' => 'Non-Febrile Seizures: Controlled',
                'o' => self::default_option
            ],
            'fhxcp' => ['l' => '27. Cerebral Palsy',
                'o' => self::default_option
            ],
            'hist_trauma' => ['l' => '28. History of head trauma',
                'o' => self::default_option
            ],
            'rev_headimagestudy' => ['l' => '29. Imaging Studies',
                'o' => self::default_option + ['na'=>'Not Applicable']
            ],
            'rev_headimagestudytype' => ['l' => 'Imaging Studies: Type',
                'o' => [
                    NULL=>'',
                    'us'=>'US',
                    'ct'=>'CT',
                    'mr'=>'MR',
                    'pet'=>'PET',
                    'eeg'=>'EEG',
                    'nk'=>'Not Known'
                ]
            ],
            'rev_headimagestudyresult' => ['l' => 'Imaging Studies: Results',
                'o' => [
                    NULL=>'',
                    'normal'=>'Normal',
                    'abnormal'=>'Abnormal',
                    'nk'=>'Not Known'
                ]
            ],
            '2' => ['t' => 'sec', 'l' => 'Eyes'],
            'vis_blind' => ['l' => '30. Significant visual loss or congenital blindness',
                'o' => self::default_option
            ],
            '3' => ['t' => 'sec', 'l' => 'Ears'],
            'rev_eartest' => ['l' => '31. Hearing Testing',
                'o' => self::default_option
            ],
            'rev_eartestages' => ['l' => 'Hearing Testing: Age (months)'],
            'rev_eartestresult' => ['l' => 'Hearing Testing: Result',
                'o' => [
                    NULL=>'',
                    'normal'=>'Normal',
                    'abnormal'=>'Abnormal',
                    'nk'=>'Not Known']
            ],
            'hear_loss' => ['l' => '32. Deafness or significant hearing loss',
                'o' => self::default_option
            ],
            'othmem_hearingcor' => ['l' => 'If yes, was hearing corrected with hearing aid(s) or cochlear implant?',
                'o' => self::default_option
            ],
            'rev_earrecuotitis' => ['l' => '33. Recurrent Otitis Media',
                'o' => self::default_option
            ],
            'rev_earrecuotitisyear' => ['l' => 'Recurrent Otitis Media:', #/Year
                't' => 'numeric'
            ],
            'rev_earrecuotitisage' => ['l' => 'Recurrent Otitis Media: Age of Onset (in months)',
                't' => 'numeric'
            ],
            'rev_earpetube' => ['l' => '34. PE (ear) tubes',
                'o' => self::default_option
            ],
            '4' => ['t' => 'sec', 'l' => 'Mouth'],
            'rev_mouthcleftlip' => ['l' => '35. Cleft Lip',
                'o' => self::default_option
            ],
            'rev_mouthcleftpalate' => ['l' => '36. Cleft Palate',
                'o' => self::default_option
            ],
            '4' => ['t' => 'sec', 'l' => 'Teeth'],
            'rev_teethdentalab' => ['l' => '37. Dental abnormalities',
                'o' => self::default_option
            ],
            '5' => ['t' => 'sec', 'l' => 'Neck/Back'],
            'rev_neckspinalab' => ['l' => '38. Spinal abnormalities',
                'o' => self::default_option
            ],
            //<b>Skin</b>
            'rev_skinbirthmark' => ['l' => '39. Birthmarks (e.g., café-au-lait spots, white spots)',
                'o' => self::default_option
            ],
            'rev_skineczema' => ['l' => '40. Eczema',
                'o' => self::default_option
            ],
            'rev_skinabscesses' => ['l' => '41. Skin Infections/Abscesses',
                'o' => self::default_option
            ]
        ];

        $this->create_form_item($items2);

        $rules = [
            'rev_headimagestudytype' => ['l' => 'Specify type(s) of brain imaging study', 'r' => 'rev_headimagestudy{@}=={@}Yes'],
            'rev_headmeningitisage' => ['l' => 'Specify age', 'r' => 'rev_headmeningitis{@}=={@}Yes'],
            'rev_headmeningitisorg' => ['l' => 'Specify status', 'r' => 'rev_headmeningitis{@}=={@}Yes'],
            'rev_headencephalitisage' => ['l' => 'Specify age', 'r' => 'rev_headencephalitis{@}=={@}Yes'],
            'rev_headencephalitisorg' => ['l' => 'Specify status', 'r' => 'rev_headencephalitis{@}=={@}Yes'],
            'rev_headfebseizage' => ['l' => 'Specify age', 'r' => 'rev_headfebseiages{@}=={@}Yes'],
            'rev_headseizureonset' => ['l' => 'Specify age', 'r' => 'rev_headseizure{@}=={@}Yes'],
            'rev_headseizurecontrol' => ['l' => 'Specify control', 'r' => 'rev_headseizure{@}=={@}Yes'],
            'rev_eartestsages' => ['l' => 'Specify age', 'r' => 'rev_eartest{@}=={@}Yes'],
            'othmem_hearingcor' => ['l' => 'Specify whether corrected with hearing aid(s) or cochlear implant?', 'r' => 'hear_loss{@}=={@}Yes'],
            'rev_earrecuotitisyear' => ['l' => 'Specify yea', 'r' => 'rev_earrecuotitis{@}=={@}Yes'],
            'rev_earrecuotitisage' => ['l' => 'Specify age', 'r' => 'rev_earrecuotitis{@}=={@}Yes'],
            'rev_endoprecociousage' => ['l' => 'Specify age', 'r' => 'rev_endoprecocious{@}=={@}Yes'],
            'rev_headimagestudyresult' => ['l' => 'Specify result', 'r' => 'rev_headimagestudy{@}=={@}Yes'],
            'rev_eartestages' => ['l' => 'Specify age', 'r' => 'rev_eartest{@}=={@}Yes'],
            'rev_eartestresult' => ['l' => 'Specify result', 'r' => 'rev_eartest{@}=={@}Yes'],
            'rev_endodiabetestype' => ['l' => 'Specify type', 'r' => 'rev_endodiabetes{@}=={@}Yes']
        ];

        foreach ($rules as $key => $itm) {
            $this->XINRegisterRule(
                $key,
                array($itm['r']),
                $itm['l']);
        }

        $this->form->addFormRule(array(&$this, 'page1Control'));
    }

    function page1Control($values) {
        $errors = array();
        $section = [
            'rev_headmeningitis' => ['l' => 'Meningitis',
                't' => 'text',
                'o' => ['rev_headmeningitisage', 'rev_headmeningitisorg']
            ],
            'rev_headimagestudy' => ['l' => 'Imaging Studies' ,
                't' => 'choice',
                'o' => ['rev_headimagestudytype', 'rev_headimagestudyresult']
            ]
        ];

        foreach ($section as $parentKey => $itm) {
            if ($values[$parentKey] == 'No') {
                foreach ($itm['o'] as $key) {
                    if (!empty($values[$key])) {
                        $errors[$key] = 'You have chosen No ' . $itm['l'] . ', a ' .
                            ($itm['t'] =='choice' ? 'choice should not be made' : ' value should not be entered') . ' here.';
                    }
                }
            }
        }
        return $errors;
    }

    /**
     * Generates the first page of the form.
     *
     *@return void
     */
    function _page2()
    {
        $this->addHeader('Review of Systems');

        $items3 = [
            '1' => ['t' => 'sec', 'l' => 'Pulmonary'],
            'rev_pulbreathab' => ['l' => '42. Abnormal Breathing',
                'o' => self::default_option
            ],
            'rev_pulbrasthma' => ['l' => '43. Asthma',
                'o' => self::default_option
            ],
            'rev_lung' => ['l' => '44. Lung disease',
                'o' => self::default_option
            ],
            '2' => ['t' => 'sec', 'l' => 'Cardiovascular'],
            'rev_cardiomalfunc' => ['l' => '45. Cardiac Malformation',
                'o' => self::default_option
            ],
            'rev_cardiocyanosis' => ['l' => '46. Cyanosis',
                'o' => self::default_option
            ],
            'rev_rhythm' => ['l' => '47. Abnormal rhythm or heart rate',
                'o' => self::default_option
            ],
            '3' => ['t' => 'sec', 'l' => 'Gastrointestinal'],
            'rev_gastrodysphagia' => ['l' => '48. Dysphagia',
                'o' => self::default_option
            ],

            'rev_gastroreflux' => ['l' => '49. Reflux',
                'o' => self::default_option
            ],

            'rev_gastrorefluxmed' => ['l' => 'Reflux: Medication Required',
                'o' => self::default_option
            ],
            'rev_gastroother' => ['l' => '50. Other feeding difficulties',
                'o' => self::default_option
            ],
            '4' => ['t' => 'sec', 'l' => 'Endocrine/Metabolic'],
            'rev_endoprecocious' => ['l' => '51. Precocious Puberty',
                'o' => self::default_option
            ],
            'rev_endoprecociousage' => ['l' => 'Precocious Puberty: Age (in months)'],
            'rev_endohypothyroidism' => ['l' => '52. Hypothyroidism',
                'o' => self::default_option
            ],
            'rev_endohyperthyroidism' => ['l' => '53. Hyperthyroidism',
                'o' => self::default_option
            ],
            'rev_endodiabetes' => ['l' => '54. Diabetes',
                'o' => self::default_option
            ],
            'rev_endodiabetestype' => ['l' => 'Diabetes: Type',
                'o' => [
                    NULL=>'',
                    'type_1'=>'Type 1',
                    'type_2'=>'Type 2',
                    'nk'=>'Not Known'
                ]
            ],
            'rev_endohypoglycemia' => ['l' => '55. Hypoglycemia',
                'o' => self::default_option
            ],
            '5' => ['t' => 'sec', 'l' => 'Hematologic'],
            'rev_hemanemia' => ['l' => '56. Anemia',
                'o' => self::default_option
            ],
            'rev_hembleeddisorder' => ['l' => '57. Bleeding disorder',
                'o' => self::default_option
            ],
            '6' => ['t' => 'sec', 'l' => 'Immunologic'],
            'rev_immunorecurinfection' => ['l' => '58. Recurrent Infections (>2 pneumonia or sinus infections/yr, >8 OM/yr, abscesses)',
                'o' => self::default_option
            ],
            'rev_immunoigdeficiency' => ['l' => '59. Immunoglobulin deficiency',
                'o' => self::default_option
            ],
            'rev_immunocellimmunedef' => ['l' => '60. Cell-Mediated Immune Deficiency',
                'o' => self::default_option
            ],
            'rev_immunoenvallergy' => ['l' => '61. Environmental Allergies',
                'o' => self::default_option
            ],
            'rev_immunomedallergy' => ['l' => '62. Medication Allergies',
                'o' => self::default_option
            ],
            'rev_immunoimmunization' => ['l' => '63. Immunizations',
                'o' => [
                    NULL=>'',
                    'up-to-date'=>'Up-to-date',
                    'behind'=>'Behind',
                    'nk'=>'Not Known'
                ]
            ]
        ];

        $this->create_form_item($items3);

        $rules = [
            'rev_endoprecociousage' => ['l' => 'Specify age', 'r' => 'rev_endoprecocious{@}=={@}Yes'],
            'rev_endodiabetestype' => ['l' => 'Specify type', 'r' => 'rev_endodiabetes{@}=={@}Yes'],

        ];

        foreach ($rules as $key => $itm) {
            $this->XINRegisterRule(
                $key,
                array($itm['r']),
                $itm['l']);
        }
    }

    /**
     * Generates the first page of the form.
     *
     *@return void
     */
    function _page3()
    {
        $this->addHeader('Review of Systems');

        $items4 = [
            '1' => ['t' => 'sec', 'l' => 'Genetic'],
            'gen_dis' => [
                'l' => '64. Does the study subject have any of the following genetic disorders?',
                'o' => [
                    '1_rett_syndrome'=>'Rett syndrome',
                    '2_down_syndrome'=>'Down syndrome',
                    '3_tuberous_sclerosis_complex'=>'Tuberous Sclerosis Complex',
                    '4_fragile_x_syndrome'=>'Fragile X syndrome',
                    '5_neurofibromatosis_i'=>'Neurofibromatosis I'
                ],
                'multiple'=>true
            ],
            'gen_dis_conf' => ['l' => 'If checked above, is the genetic disorder confirmed by a physician-ordered genetic analysis?',
                'o' => self::default_option
            ],
            '7' => ['t' => 'sec', 'l' => 'Mental Health'],
            'othmem_bipolar' => ['l' => '65. Bipolar disorder (Manic/depression)',
                'o' => self::default_option
            ],
            'othmem_depression' => ['l' => '66. Depression',
                'o' => self::default_option
            ],
            'othmem_anxiety' => ['l' => '67. Anxiety disorder',
                'o' => self::default_option
            ],
            'cfmh_othr_ocd' => ['l' => '68. Obsessive compulsive disorder',
                'o' => self::default_option
            ],
            'othmem_schizophrenia' => ['l' => '69. Schizophrenia',
                'o' => self::default_option
            ],
            'othmem_selfinj' => ['l' => '70. Self-injuring behavior',
                'o' => self::default_option
            ],
            'othmem_adhd' => ['l' => '71. Attention deficit hyperactivity disorder (ADHD)',
                'o' => self::default_option
            ],
            'othmem_eatingdis' => ['l' => '72. Eating disorder',
                'o' => self::default_option
            ],
            'othmem_eatingdis_type' => ['l' => 'If yes, specify type',
                'o' => [
                    NULL=>'',
                    'anorexia'=>'Anorexia',
                    'bulimia'=>'Bulimia',
                    'other'=>'Other',
                    'nk'=>'Not Known'
                ]
            ],
            'sleep_pat' => ['l' => '73. Disrupted sleep patterns',
                'o' => self::default_option
            ],
            'touret' => ['l' => '74. Tourette Syndrome',
                'o' => self::default_option
            ]
        ];

        $this->create_form_item($items4);

        $rules = [
            'gen_dis_conf' => ['l' => 'Specify genetic disorder confirmation', 'r' => 'gen_dis_1_rett_syndrome{@}=={@}Yes|gen_dis_2_down_syndrome{@}=={@}Yes|gen_dis_3_tuberous_sclerosis_complex{@}=={@}Yes|gen_dis_4_fragile_x_syndrome{@}=={@}Yes|gen_dis_5_neurofibromatosis_i{@}=={@}Yes'],
            'othmem_eatingdis_type' => ['l' => 'Specify type', 'r' => 'othmem_eatingdis{@}=={@}Yes']
        ];

        foreach ($rules as $key => $itm) {
            $this->XINRegisterRule(
                $key,
                array($itm['r']),
                $itm['l']);
        }
    }

    private const Items1 = [
        '1' => ['t' => 'sec', 'l' => 'Diagnostic History'],
        'diag_aofc' => ['l' => '1. Age of first concern (in months)',
            'r' => [1, 150]
        ],
        'devel_concern' => ['l' => '2. Developmental concern',
            'o' => [
                NULL=>'',
                '1_cognitive/learning'=>'1. Cognitive/learning',
                '2_behavior'=>'2. Behavior',
                '3_hearing'=>'3. Hearing',
                '4_motor'=>'4. Motor',
                '5_language'=>'5. Language',
                'nk'=>'Not Known',
                'none'=>'None'
            ]
        ],
        'aut_diag' => ['l' => '3. Autism-related diagnosis',
            'o' => [
                NULL=>'',
                '1_autism'=>'1. Autism',
                '2_autism_spectrum_disorder'=>'2. Autism Spectrum Disorder',
                '3_asperger_syndrome'=>'3. Asperger syndrome',
                '4_pdd-nos'=>'4. PDD-NOS',
                'nk'=>'Not Known',
                'none'=>'None'
            ]
        ],
        'diag_ageatdiag' => ['l' => '4. Age at diagnosis (in months)',
            'r' => [1, 360]
        ],
        'diag_diagnosismadeby' => ['l' => '5.Diagnosis made by',
            'o' => [
                NULL=>'',
                'physician'=>'Physician',
                'psychologist'=>'Psychologist',
                'other'=>'Other',
                'nk'=>'Not Known',
                'none'=>'None'
            ]
        ],
        '2' => ['t' => 'sec', 'l' => 'Prenatal/Early Postnatal History'],
        'preg_complic' => ['l' => '6. Complications during pregnancy?',
            'o' => self::default_option
        ],
        'preg_dxdrug' => ['l' => '7. Used prescription medications during pregnancy?',
            'o' => self::default_option
        ],
        'birth_weight_lbs' => ['l' => '8. Birth weight pounds',
            'r' => [0.5, 25]
        ],
        'ldnb_lgthin' => [
            'l' => '9. What was the baby\'s length at birth (inches)',
            'r' => [10, 28]
        ],
        'full_term' => ['l' => '10. Full-term delivery?',
            'o' => self::default_option
        ],
        'info_gest' => ['l' => 'If No, how many weeks gestation?',
            'r' => [1, 45]
        ],
        'ldnb_hosptotalmom' => [
            'l' => '11. How many days in the hospital after birth?',
        ],
        '3' => ['t' => 'sec', 'l' => 'Developmental History'],
        'earlydev_walk' => ['l' => '12. Age when first walked unaided (in months)'],
        'age_firstword' => ['l' => '13. Age of first single words (in months)'],
        'age_3word' => ['l' => '14. Age at 3-word sentences (in months)', 'r' => [1, 150]],
        'current_lang' => ['l' => '15. Current speech/language: Verbal?',
            'o' => self::default_option
        ],
        'verb_words' => ['l' => 'If yes, how many words?',
            'o' => [
                NULL=>'',
                '1_max9_single_words'=>'1. <10 single words',
                '2_10_or_more_single_words'=>'2. Speaks in 10 or more single words',
                '3_2_word_combinations'=>'3. Speaks in 2 word combinations',
                '4_3_or_more_word_combinations'=>'4. Speaks in 3 or more word combinations',
                'nk'=>'Not Known',
            ]
        ],
        'othmem_devdelay' => ['l' => '16. Developmental Delay',
            'o' => self::default_option
        ],
        'school_perf' => ['l' => '17. School Performance',
            'o' => [
                NULL=>'',
                '1_below_grade_level'=>'1. Below grade level',
                '2_at_grade_level'=>'2. At grade level',
                '3_above_grade_level'=>'3. Above grade level',
                '4_mixed'=>'4. Mixed',
                'nk'=>'Not Known',
                'none'=>'None'
            ]
        ],
        '4' => ['t' => 'sec', 'l' => 'Current Medications'],
        'rx_behav' => ['l' => '18. Prescription medications for behavioral concerns',
            'o' => self::default_option
        ],
        'rx_phys' => ['l' => '19. Prescription medications for physical health concerns',
            'o' => self::default_option
        ],
        'otc_med' => ['l' => '20. Over-the-counter medications',
            'o' => self::default_option
        ],
        'ds_med' => ['l' => '21. Dietary Supplements',
            'o' => self::default_option
        ],
        'gastro_spec_diet' => ['l' => '22. Does subject have a special diet?',
            'o' => self::default_option
        ]
    ];
}
