<?php
/**
 * This file contains the NDB_BVL_Instrument_perinatal_data
 * class
 *
 * PHP Version 7
 *
 * @category Instrument
 * @package  IBIS
 * @author   Ling Ma <lingyun.ma@mcin.ca>
 * @date     2020 March 23
 * @license  http://www.gnu.org/licenses/gpl-3.0.txt GPLv3
 * @link     https://www.github.com/aces/IBIS/
 */

class NDB_BVL_Instrument_perinatal_data extends NDB_BVL_Instrument
{
    var $ValidityRequired = false;

    var $indent = "&nbsp;&nbsp;";

    private const YesNo = [
        null => '',
        'y' => 'Yes',
        'n' => 'No'
    ];

    private const QUESTIONS = [
        'initial_weight' => ['l' => '1) Just before your pregnancy with [Child], about how much did you weigh?',
            'col' => 1,
            'o' => [
                null => '',
                'less100' => 'less than 100 lbs',
                '129lb' => '100 – 129 lbs',
                '149lb' => '130 – 149 lbs',
                '178lb' => '150 – 178 lbs',
                '199lb' => '180 – 199 lbs',
                '219lb' => '200 – 219 lbs',
                'over219' => 'over 219 lbs'
            ]
        ],
        'weight_gain' => ['l' => '2) During your pregnancy with [Child], about how much total weight did you gain?',
            'col' => 1,
            'o' => [
                null => '',
                'less10' => 'less than 10 lbs',
                '19lb' => '10 - 19 lbs',
                '29lb' => '20 - 29 lbs',
                '39lb' => '30 - 39 lbs',
                '49lb' => '40 - 49 lbs',
                'over49' => '50 or more lbs'
            ]
        ],
        'height' => ['l' => '3) What is your height without shoes?',
            'col' => 2,
            'type' => 'v',
            'c' => [
                'f' => 'feet',
                'i' => 'inches'
            ],
            'r' => [
                'f' => [0, 7],
                'i' => [0, 12]
            ]
        ],
        'supplement_3months_before' => [
            'l' => '4) During the 3 months before you became pregnant with [Child], were you taking a prenatal vitamin, multi-vitamin, or folic acid supplement?',
            'col' => 1,
            'o' => self::YesNo
        ],
        'supplement_during' => [
            'l' => '5) While you were pregnant with [Child], did you take a prenatal vitamin, multi-vitamin, or folic acid supplement (at least 3 times per week)?',
            'col' => 1,
            'o' => self::YesNo
        ],
        'condition' => ['l' => '6) During the time period from three months before you became pregnant with [Child] until his/her delivery or until you stopped breastfeeding completely, did you have any of the following conditions?',
            'col' => 10,
            'type' => 'o',
            'c' => ['flu' => ['l' => 'Flu',
                    'o' => self::YesNo
                ],
                'fever' => ['l' => 'Fever',
                    'o' => self::YesNo
                ],
                'diabete' => ['l' => 'Diabetes',
                    'o' => self::YesNo
                ],
                'eclampsia' => ['l' => 'Eclampsia (High Blood Pressure)',
                    'o' => self::YesNo
                ],
                'gestational_diabete' => ['l' => 'Gestational Diabetes',
                    'o' => self::YesNo
                ],
                'pre_eclampsia' => ['l' => 'Pre-Eclampsia (High Blood Pressure During Pregnancy)',
                    'o' => self::YesNo
                ],
                'hypermesis' => ['l' => 'Hypermesis',
                    'o' => self::YesNo
                ],
                'low_blood_pressure' => ['l' => 'Low Blood Pressure',
                    'o' => self::YesNo
                ],
                'preterm_early_labor' => ['l' => 'Pre-term or Early Labor',
                    'o' => self::YesNo
                ],
                'premature_membranes_rupture' => ['l' => 'Premature rupture of membranes (leaking of amniotic fluid or “water breaking” before the start of labor)?',
                    'o' => self::YesNo
                ]
            ]
        ],
        'smoking' => ['l' => '7) Have you ever smoked cigarettes?',
            'col' => 1,
            'o' => self::YesNo
        ],
        'tobacco' => ['l' => '8) At any time during your pregnancy with [Child], even before you knew you were pregnant, did you use tobacco products?',
            'col' => 1,
            'o' => self::YesNo
        ],
        'drinking' => ['l' => '9) At any time during your pregnancy with [Child], even before you knew you were pregnant, did you drink alcohol?',
            'col' => 1,
            'o' => self::YesNo
        ],
        'past_condition' => ['l' => '10) Have you EVER been diagnosed with any of the following conditions? ',
            'col' => 7,
            'type' => 'o',
            'c' => [
                'diabete' => ['l' => 'Diabetes',
                    'o' => self::YesNo
                ],
                'lupus' => ['l' => 'Lupus',
                    'o' => self::YesNo
                ],
                'high_blood_pressure' => ['l' => 'High Blood Pressure',
                    'o' => self::YesNo
                ],
                'asthma' => ['l' => 'Asthma',
                    'o' => self::YesNo
                ],
                'other_autoimmune_disorder' => ['l' => 'Other Autoimmune Disorder',
                    'o' => self::YesNo
                ],
                'mental_illness' => ['l' => 'Mental Illness',
                    'o' => self::YesNo
                ],
                'depression' => ['l' => 'Depression',
                    'o' => self::YesNo
                ]
            ]
        ]
    ];

    public function getFullName(): string
    {
        return "IBIS Perinatal Data Form – To be Completed By the Biologic Mother of the Sibling";
    }

    function getSubtestList(): array {
        return [];
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
    function setup(string $commentID=null, string $page=null) : void
    {
        $this->formType = 'XIN';
        $this->form     = new LorisForm('test_form');
        $this->page     = $page;

        // set the object properties
        $this->testName  = 'perinatal_data'; // test_names.Test_name
        $this->table     = 'perinatal_data';
        $this->commentID = $commentID; // data keyed by commentID

        //The array of dates/timestamps to convert to database dates/timestamps
        //Any LorisForm date elements must be listed here
        $this->dateTimeFields = array(
            "Date_taken"
        );

        //The array of selects with multiple answers allowed
        //Any LorisForm multiple selects must be listed here
        $this->selectMultipleElements = array();

        // required fields for data entry completion status
        $this->_requiredElements = array(
            'Examiner',
            'CommentID',
            'initial_weight'
        );

        //The array of selects with multiple answers allowed
        //Any LorisForm multiple selects must be listed here
        $this->selectMultipleElements = [];

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
        /*if (preg_match("/perinatal_data(_page[0-9]+)/",
            $this->page, $matches)) {
            call_user_func(array($this, $matches[1]));
        } else {*/
            $this->_main();
        //}

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
        $this->addHeader("IBIS Perinatal Data Form – To be Completed By the Biologic Mother of the Sibling");

        $this->form->addElement("header", null, "Thank you for your continued participation in IBIS!  As part of our work to understand autism spectrum disorder and brain development we would like to gather some information from you, about your pregnancy with [Child]");

        $config      =& NDB_Config::singleton();

        $dateOptions = array(
            'language'         => 'en',
            'format'           => 'YMd',
            'minYear'          => $config->getSetting('startYear'),
            'maxYear'          => $config->getSetting('endYear'),
            'addEmptyOption'   => true,
            'emptyOptionValue' => null,
        );
        $this->addBasicDate('Date_taken', 'Date Taken', $dateOptions, ['required' => true]);

        foreach (self::QUESTIONS as $key => $itm) {
            if ($itm['col'] == 1) {
                $this->addSelect($key, $itm['l'], $itm['o'], ['required' => true]);
            }
            else if ($itm['col'] > 1) {
                $this->addLabel($itm['l']);
                if ($itm['type'] == 'o') {
                    foreach ($itm['c'] as $itmKey => $itmVal) {
                        $this->addSelect("{$key}_$itmKey", $this->indent . $itmVal['l'], $itmVal['o'], ['required' => true]);
                    }
                }
                else if ($itm['type'] == 'v') {
                    foreach ($itm['c'] as $itmKey => $itmLabel) {
                        $required = true;
                        if ($itmKey == 'i') {
                            $required = false;
                        }
                        $this->addBasicText("{$key}_$itmKey", (!$required?$this->indent:'') . $this->indent . $itmLabel, ['required' => $required]);
                        if (!$required) {
                            $this->not_required_field("{$key}_$itmKey");
                        }
                    }
                }
            }
        }
        $this->form->addFormRule(array(&$this, 'valueControl'));
    }

    private function not_required_field($key) {
        return $this->XINRegisterRule($key, array("{$key}{@}=={@}NEVER_REQUIRED"), "Not required");
    }

    function valueControl($values) {
        $errors = array();
        $itm = 'height';
        foreach (self::QUESTIONS[$itm]['c'] as $key => $label) {
            $subKey = "{$itm}_{$key}";
            $ranges = self::QUESTIONS[$itm]['r'];
            if (!empty($values[$subKey])) {
                $range = $ranges[$key];
                if ($values[$subKey] < $range[0]) {
                    $errors[$subKey] = "Must be no less than $range[0].";
                }
                else if ($values[$subKey] > $range[1]) {
                    $errors[$subKey] = "Must be no more than $range[1].";
                }
            }
        }
        return $errors;
    }
}
