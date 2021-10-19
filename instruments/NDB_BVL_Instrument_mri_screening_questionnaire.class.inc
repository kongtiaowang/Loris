<?php
/**
 * This file contains the NDB_BVL_Instrument_mri_screening_questionnaire
 * class
 *
 * PHP Version 7
 *
 * @category Instrument
 * @package  IBIS
 * @author   Ling Ma <lingyun.ma@mcin.ca>
 * @date     2019 Nov 18
 * @license  http://www.gnu.org/licenses/gpl-3.0.txt GPLv3
 * @link     https://www.github.com/aces/IBIS/
 */

class NDB_BVL_Instrument_mri_screening_questionnaire extends NDB_BVL_Instrument
{
    use LegacyInstrumentTrait;

    var $ValidityEnabled  = false;
    var $ValidityRequired = false;

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
    function setup(?string $commentID = NULL, ?string $page = NULL): void
    {
        $this->formType = 'XIN';
        $this->form     = new LorisForm('test_form');
        $this->page     = $page;

        // set the object properties
        $this->testName  = 'mri_screening_questionnaire'; // test_names.Test_name
        $this->table     = 'mri_screening_questionnaire';
        $this->commentID = $commentID; // data keyed by commentID

        //The array of dates/timestamps to convert to database dates/timestamps
        //Any LorisForm date elements must be listed here
        $this->dateTimeFields = array(
            "Date_taken",
            'metal_in_eye_set',
            'endoscopy_camera_set',
            'programmable_shunt_set',
            'neurostimulator_set',
            'penible_implant_set',
            'coils_filters_stents_set',
            'bullets_bbs_shrapnel_set',
            'aneurysm_clip_set',
            'implanted_drug_pumps_set',
            'implanted_metal_device_set',
            'artificial_heart_valve_set'
        );

        //The array of selects with multiple answers allowed
        //Any LorisForm multiple selects must be listed here
        //$this->selectMultipleElements = array();

        // required fields for data entry completion status
        $this->_requiredElements = array(
            'Examiner',
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

        $min_event_year = 1900;
        $this->otherDateOptions = array(
            'language'         => 'en',
            'format'           => 'YMd',
            'minYear'          => $min_event_year,
            'maxYear'          => $config->getSetting('endYear'),
            'addEmptyOption'   => true,
            'emptyOptionValue' => null,
        );

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
        if (preg_match("/mri_screening_questionnaire(_page[0-9]+)/", 
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
        $this->addHeader("MRI Screening Questionnaire: Patient");

        // automatically adds examiner & date of administration
        $this->_addMetadataFields();

        $this->addLabel('The following items may be harmful to you during your MR scan or may interfere with the MRI examination.
        Please check "Yes" or "No" to indicate whether you have or have had any of the following.
        Remove ALL metallic objects prior to MRI. Please provide any implant card.');

        $question_grp = [
            'cardiac_pacemaker' => 'Cardiac Pacemaker',
            'pacer_wires' => 'Pacer Wires',
            'implanted_cardiac_defibrillator' => 'Implanted Cardiac Defibrillator',
            'cochlear_other_ear_implants' => 'Cochlear or Other Ear Implants',
            'tissue_expanders' => 'Tissue Expanders (Breast or other)',
            'eyelid_spring_retina_tacks' => 'Eyelid Spring or Retinal Tacks'
        ];

        foreach ($question_grp as $key => $val) {
            $this->addYesNoElement($key, $val);
            $this->form->addRule($key, $val . ' must be set', 'required');
        }

        unset($question_grp);

        $this->addLabel('If you responded "Yes" to any of the above, you may NOT be eligible for MRI.
        Please contact a representative in MRI at 314-362-1695 or talk to a representative at the reception desk.');

        $XIN_required_rule = array("cardiac_pacemaker{@}=={@}no", "pacer_wires{@}=={@}no", "implanted_cardiac_defibrillator{@}=={@}no", "cochlear_other_ear_implants{@}=={@}no", "tissue_expanders{@}=={@}no", "eyelid_spring_retina_tacks{@}=={@}no");
        $question_grp = [
            ['age', 'Age'],
            ['weight', 'Weight'],
            ['height', 'Height']
        ];

        foreach ($question_grp as list($key, $val)) {
            $this->addBasicText($key, $val);
            $this->XINRegisterRule(
                "$key",
                $XIN_required_rule,
                "Required."
            );
        }

        unset($question_grp);

        $question_grp = [
            ['allergy_mri_contrast', 'Allergy to MRI Contrast', '', ''],
            ['pregnant_breastfeeding', 'Pregnant or Breastfeeding', '', ''],
            ['kidney_disease', 'Kidney Disease/Dialysis', '', ''],
            ['metal_in_eye', 'Metal in Eye', 1, ''],
            ['endoscopy_camera', 'Endoscopy Camera Pill', 1, ''],
            ['programmable_shunt', 'Programmable Shunt', 1, ''],
            ['neurostimulator', 'Neurostimulator', 1, ''],
            ['penile_implant', 'Penile Implant', 1, ''],
            ['coils_filters_stents', 'Coils, filters or stents', 1, ''],
            ['claustrophobic', 'Claustrophobic', '', 'If claustrophobic, then contact your MD prior to your MRI exam for anxiety-reducing medication.'],
            ['tracheotomy', 'Tracheotomy', '', ''],
            ['tattoos_eye_lip_liner', 'Tattoos, Tattoo Eye or Lip Liner', '', ''],
            ['bullets_bbs_shrapnel', 'Bullets, BBs, Shrapnel', 1, ''],
            ['aneurysm_clip', 'Aneurysm Clip', 1, ''],
            ['implanted_drug_pumps', 'Any Implanted Drug Pumps', 1, ''],
            ['implanted_metal_device', 'Any Implanted Metal or Device', 1, ''],
            ['artificial_heart_valve', 'Artificial Heart Valve', 1, '']
        ];

        foreach ($question_grp as list($key, $val, $flag, $comment)) {
            $this->addYesNoElement($key, $val);
            if ($flag) {
                $this->addBasicDate("{$key}_set", $this->indent . 'Date:', $this->otherDateOptions);
                $this->addBasicText("{$key}_type", $this->indent . 'Type (if known):');

                $this->XINRegisterRule(
                    "{$key}_set",
                    array("{$key}_type{@}=={@}NEVER_REQUIRED"),
                    "Not required",
                    "group2"
                );
                $this->XINRegisterRule(
                    "{$key}_type",
                    array("{$key}_type{@}=={@}NEVER_REQUIRED"),
                    "Not required",
                    "group2"
                );
            }

            $this->XINRegisterRule(
                "$key",
                $XIN_required_rule,
                "Required."
            );

            if ($comment) {
                $this->addLabel($comment);
            }
        }

        unset($question_grp);

        $this->addLabel('If you responded "Yes" to any of the items below, for your safety, then items MUST be removed');
        $question_grp = [
            'hearing_aid' => 'Hearing Aid',
            'medication_patch' => 'Medication Patch',
            'artificial_limb' => 'Artificial Limb',
            'false_teeth_partial_plate' => 'False Teeth or Partial Plate',
            'body_piercing' => 'Body Piercing',
            'wig_hair_implant_clips_pins' => 'Wig, Hair Implants, Clips or Pins'
        ];

        foreach ($question_grp as $key => $val) {
            $this->addYesNoElement($key, $val);
            $this->XINRegisterRule(
                "$key",
                $XIN_required_rule,
                "Required."
            );
        }
        unset($question_grp);

        $question_grp = [
            ["all_surgeries", "LIST ALL SURGERIES:"],
            ["comments", "COMMENTS:"]
        ];
        $this->createTextArea("all_surgeries", "LIST ALL SURGERIES:");
        foreach ($question_grp as list($key, $val)) {
            //$this->addLabel($val);
            $this->addTextAreaElement($key, $val, $XIN_required_rule); //array("{$key}{@}=={@}NEVER_REQUIRED"));
        }
        unset($question_grp);

        $completed_by_choices = [
            null => '',
            'patient' => 'Patient',
            'clinician_or_rn' => 'Clinician or RN'
        ];

        $this->addSelect(
            'form_completed_by',
            'Form Completed by:',
            $completed_by_choices
        );

    }

    /**
     * Page 1
     *
     * @return void
     */
    function _page1()
    {
        $typesOfData = array(
            null                => '',
            'participant'       => 'Participant',
            'human_phantom'     => 'Human Phantom',
            'geometric_phantom' => 'Geometric Phantom',
        );

        // Header
        $this->addHeader("MRI Safety Checklist");

        $question_grp = [
            ['injured_by_metallic', 'Have you/your child ever been injured by any metallic foreign body (e.g., bullets, BB, shrapnel, etc.)?', 1],
            ['injured_to_eye_metallic', 'Have you/your child ever had an injury to the eye involving a metallic object (e.g. metallic slivers, shavings, foreign body, etc.)?', 1],
            ['swallow_metal', 'Have you/your child ever swallowed any metal objects (e.g. metal marble, coin)?', ''],
            ['metal_in_ear', 'Have you/your child had a metal objects lodged in your ears or other bodily cavity?', ''],
            ['pregnant', 'Are you pregnant or do you suspect that you are pregnant?', ''],
            ['diaper_with_metal', 'If  your child wears a diaper, are any pins or other metal used to hold the diaper in place?', '']
        ];

        foreach ($question_grp as list($key, $val, $flag)) {
            $this->addYesNoElement($key, $val);
            $this->form->addRule($key, $val . ' must be set', 'required');

            if ($flag) {
                $this->addBasicTextArea("{$key}_desc", $this->indent . 'If yes, describe:');
                $this->XINRegisterRule(
                    "{$key}_desc",
                    array("$key{@}=={@}yes"),
                    "Required."
                );
            }
        }

        unset($question_grp);
        
        $this->addLabel('PLEASE INDICATE IF YOU / YOUR CHILD HAVE ANY OF THE FOLLOWING:');

        $question_grp = [
            ['biostimulator', 'Any type of biostimulator', 1, 'type:'],
            ['internal_electrode', 'Any type of internal electrode(s)', 1, 'describe:'],
            ['implanted_insulin_pump', 'Implanted insulin pump', '', ''],
            ['swan_ganz_atheter', 'Swan-Ganz Catheter', '', ''],
            ['halo_vest_metallic', 'Halo vest or metallic cervical fixation devices', '', ''],
            ['electronic_implant', 'Any type of electronic, mechanical, or magnetic implant', 1, 'type:'],
            ['ear_tubes', 'Ear tubes', '', ''],
            ['intravascular_coil', 'Any type of intravascular coil, filter or stent', '', ''],
            ['implanted_drug_infusion', 'Implanted drug infusion device', '', ''],
            ['foreign_body_shrapnel', 'Any type of foreign body, shrapnel or bullet', '', ''],
            ['heart_valve_prosthesis', 'Heart valve prosthesis', '', ''],
            ['orbital_prosthesis', 'Orbital (eye) prosthesis', '', ''],
            ['implant_held_by_magnet', 'Any type of implant held in place by a magnet', '', ''],
            ['surgical_clip', 'Any type of surgical clip(s) or staple(s)', '', ''],
            ['vascular_access_port', 'Vascular access port', '', ''],
            ['intraventricular_shunt', 'Intraventricular shunt', '', ''],
            ['braces', 'Braces', '', ''],
            ['wire_mesh', 'Wire mesh', '', ''],
            ['artificial_limb_joint', 'Artificial limb or joint', '', ''],
            ['implanted_orthopedic_item', 'Implanted orthopedic item(s), such as pins, rods, screws, nails, clips, plates, wire, etc.', 1, 'type:'],
            ['iud', 'IUD', '', ''],
            ['pessary', 'Pessary', '', ''],
            ['penile_prosthesis', 'Penile Prosthesis', '', ''],
            ['diaphragm', 'Diaphragm', '', '']
        ];

        foreach ($question_grp as list($key, $val, $flag, $label)) {
            $this->addYesNoElement($key, $val);
            $this->form->addRule($key, $val . ' must be set', 'required');

            if ($flag) {
                $this->addBasicTextArea("{$key}_desc", $this->indent . 'If yes, '. $label);
                $this->XINRegisterRule(
                    "{$key}_desc",
                    array("$key{@}=={@}yes"),
                    "Required."
                );
            }
        }
        unset($question_grp);

        $this->addLabel('Note that make-up containing metal (e.g., "glitter"), any type of metal hairpins or hair holders, or watches should NOT be worn in the scanner room.');
    }
}
