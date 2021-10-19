<?php
/**
 *This file contains the NDB_BVL_Instrument_IEP_Extraction_Form class
 *
 * PHP Version 5
 *
 * @category Instrument
 * @package  Neuropsych
 * @author   Suzanne Lee <suzannelee.mcin@gmail.com>
 * @license  http://www.gnu.org/licenses/gpl-3.0.txt GPLv3
 * @link     https://www.github.com/aces/IBIS/
 */

/**
 * Creates the form elements for the NDB_BVL_Instrument_IEP_Extraction_Form instrument
 *
 * @category Instrument
 * @package  Neuropsych
 * @author   Suzanne Lee <suzannelee.mcin@gmail.com>
 * @license  http://www.gnu.org/licenses/gpl-3.0.txt GPLv3
 * @link     https://www.github.com/aces/IBIS/
 */
class NDB_BVL_Instrument_IEP_Extraction_Form extends NDB_BVL_Instrument
{
    use LegacyInstrumentTrait;

    /**
    * Sets up basic data, such as the HTML_Quickform object, and so on.
    *
    * @param string $commentID the CommentID identifying the data to load
    * @param string $page      if a multipage form, the page to show
    *
    * @return void
    * @access public
    */
    function setup(?string $commentID = NULL, ?string $page = NULL): void
    {
        $this->formType ="XIN";
        $this->form     = new LorisForm('test_form');
        $this->page     = $page;            // page label (number or
        // string - used by
        // user-defined child classes)

        // set the object properties
        $this->testName = "IEP_Extraction_Form";           // test_names.Test_name
        $this->table    = 'IEP_Extraction_Form';              // name of database table corresponding to instrument
        // data keyed by commentID
        $this->commentID = $commentID;

        //The array of dates/timestamps to convert to database dates/timestamps
        //Any HTML_Quickform date elements must be listed here
        $this->dateTimeFields =array("Date_taken");

        //The array of selects with multiple answers allowed
        //Any HTML_Quickform multiple selects must be listed here
        $this->selectMultipleElements = array();

        // required fields for data entry completion status
        $this->_requiredElements = array(
                                    "academic_year",
                                    "q2_participant_receive_paraprofessional_aid",
                                   );

        // setup the form
        $this->_setupForm();

    }

    //If the instrument is not paged, remove the switch from the _setupForm method and add all the form Elements in this function.

    /**
    * Method to build the HTML_Quickform object into a paged form
    *
    * @return void
    * @access private
    */
    function _setupForm()
    {
        if (preg_match("/IEP_Extraction_Form(_page[0-9]+)/", $this->page, $matches)) {
            call_user_func(array($this, $matches[1]));
        } else {
            $this->_main();
        }
        //Defines the call back function for HTML Quickform to use when validating the form.
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
        // display test name
        $this->addHeader("IEP School Supports Extraction Form");

        $this->form->addElement("static", null, "<br/>");

        $this->_addMetadataFields();
    }

    /**
    * Generates the first page of the form.
    *
    *@return void
    */
    function _page1()
    {
        $this->addHeader("IEP School Supports Extraction Form");

        $this->form->addElement("static", null, "<br/>");

        $yes_no_options = array(
                           null  => "",
                           "no"  => "No",
                           "yes" => "Yes",
                          );

        $this->addBasicText("academic_year", "<h4>Academic Year:</h4>");

        $this->addLabel("<h3>1. 504 Plan</h3>");

        $this->form->addElement("static", null, "<br/>");

        $this->addSelect("q1_does_participant_have_504_plan", "<h4>Does the participant have a 504 Plan in place?</h4>", $yes_no_options);

        $this->addLabel("<h4>If yes:</h4>");

        $this->form->addElement("static", null, "<br/>");

        $documented_impairment_options = array(
                                          null         => "",
                                          "physical"   => "Physical",
                                          "behavioral" => "Behavioral",
                                          "emotional"  => "Emotional",
                                          "other"      => "Other",
                                         );

        $this->addSelect("q1_if_yes_select_applicable_category", "$this->indent Select the most applicable category for the documented impairment:", $documented_impairment_options);

        $this->XINRegisterRule(
            "q1_if_yes_select_applicable_category",
            array("q1_does_participant_have_504_plan{@}=={@}yes"),
            "Required."
        );

        $this->addTextAreaElement("q1_if_yes_summarize_accommodations", "$this->indent Narratively summarize the accommodations the participant is receiving:");

        $this->XINRegisterRule(
            "q1_if_yes_summarize_accommodations",
            array("q1_does_participant_have_504_plan{@}=={@}yes"),
            "Required."
        );

        $this->form->addElement("static", null, "<br/>");

        $this->addLabel("<h3>2. IEP</h3>");

        $this->form->addElement("static", null, "<br/>");

        $this->addSelect("q2_does_participant_have_IEP", "<h4>Does the participant have an IEP in place?</h4>", $yes_no_options);

        $this->addLabel("<h4>If yes:</h4>");

        $this->form->addElement("static", null, "<br/>");

        $educational_classification_options = array(
                                               null                            => "",
                                               "autism"                        => "Autism",
                                               "deafness"                      => "Deafness",
                                               "emotional_disturbance"         => "Emotional Disturbance",
                                               "hearing_impairment"            => "Hearing Impairment",
                                               "intellectual_disability"       => "Intellectual Disability",
                                               "multiple_disabilities"         => "Multiple Disabilities",
                                               "orthopedic_impairment"         => "Orthopedic Impairment",
                                               "other_health_impairment"       => "Other Health Impairment",
                                               "specific_learning_disability"  => "Specific Learning Disability",
                                               "speech_or_language_impairment" => "Speech or Language Impairment",
                                               "traumatic_brain_injury"        => "Traumatic Brain Injury",
                                               "visual_impairment"             => "Visual Impairment",
                                               "developmental_delay"           => "Developmental Delay",
                                              );

        $this->addSelect("q2_participant_primary_education", "$this->indent What is the participant's primary educational classification?", $educational_classification_options);

        $this->XINRegisterRule(
            "q2_participant_primary_education",
            array("q2_does_participant_have_IEP{@}=={@}yes"),
            "Required."
        );

        $this->addSelect("q2_participant_secondary_education", "$this->indent What is the participant's secondary educational classification?", $educational_classification_options);

        $this->XINRegisterRule(
            "q2_participant_secondary_education",
            array("q2_does_participant_have_IEP{@}=={@}yes"),
            "Required."
        );

        $special_education_options = array(
                                      null                            => "",
                                      "autistic_support"              => "Autistic Support",
                                      "learning_support"              => "Learning Support",
                                      "life_skills_support"           => "Life Skills Support",
                                      "multiple_disabilities_support" => "Multiple Disabilities Support",
                                      "physical_support"              => "Physical Support",
                                      "speech_and_language_support"   => "Speech and Language Support",
                                      "emotional_support"             => "Emotional Support",
                                      "deaf_and_hard_hearing_support" => "Deaf and Hard of Hearing Support",
                                      "blind_support"                 => "Blind - Visually Impaired Support",
                                      "other"                         => "Other",
                                     );

        $this->addSelect("q2_specify_special_education_support_provided", "$this->indent Specify type of special education support provided", $special_education_options);

        $this->XINRegisterRule(
            "q2_specify_special_education_support_provided",
            array("q2_does_participant_have_IEP{@}=={@}yes"),
            "Required."
        );

        $this->addTextAreaElement("q2_special_education_support_notes", "$this->indent $this->indent Notes:");

        $this->XINRegisterRule(
            "q2_special_education_support_notes",
            array("q2_special_education_support_notes{@}=={@}NEVER_REQUIRED"),
            "Never required."
        );

        $support_level_options = array(
                                  null                          => "",
                                  "special_education_full_time" => "Special Education Classroom Full Time",
                                  "special_education_part_time" => "Special Education Classroom Part Time",
                                  "general_education_full_time" => "General Education Classroom Full Time",
                                 );

        $this->addSelect("q2_specify_level_of_support", "$this->indent Specify level of support", $support_level_options);

        $this->XINRegisterRule(
            "q2_specify_level_of_support",
            array("q2_does_participant_have_IEP{@}=={@}yes"),
            "Required."
        );

        $services_options = array(
                             null            => "",
                             "social_skills" => "Social skills",
                             "mathematics"   => "Mathematics",
                             "reading"       => "Reading",
                             "na"            => "None of the above"
                            );

        $this->addSelect("q2_specify_pull_out_services", "$this->indent Specify if the participant receives any of the following pull-out services:", $services_options);

        $this->XINRegisterRule(
            "q2_specify_pull_out_services",
            array("q2_does_participant_have_IEP{@}=={@}yes"),
            "Required."
        );

        $this->form->addElement("static", null, "<br/>");

        $this->addLabel("Does participant receive \"related services\", as specified below?");

        $this->form->addElement("static", null, "<br/>");

        $format_options = array(
                           null           => "",
                           "individual"   => "Individual",
                           "group"        => "Group",
                           "consultation" => "Consultation",
                          );

        $session_length_options = array(
                                   null         => "",
                                   "15_minutes" => "15 minutes",
                                   "30_minutes" => "30 minutes",
                                   "60_minutes" => "60 minutes",
                                  );

        $period_options = array(
                           null       => "",
                           "weekly"   => "Weekly",
                           "biweekly" => "Biweekly",
                           "monthly"  => "Monthly",
                          );

        $num_sessions_per_period = array(
                                    null => "",
                                    "1"  => "1",
                                    "2"  => "2",
                                    "3"  => "3",
                                    "4"  => "4",
                                    "5"  => "5",
                                   );

        $related_services = array(
                             "speech_therapy"       => "Speech Therapy",
                             "occupational_therapy" => "Occupational Therapy",
                             "physical_therapy"     => "Physical Therapy",
                            );

        $triple_indent = "$this->indent $this->indent $this->indent";

        foreach ($related_services as $key => $question) {

            $this->addSelect("q2_" . $key, "$this->indent" . $question . "?", $yes_no_options);

            $this->XINRegisterRule(
                "q2_" . $key,
                array("q2_does_participant_have_IEP{@}=={@}yes"),
                "Required."
            );

            $this->addLabel("$this->indent If yes, please specify:");

            $this->form->addElement("static", null, "<br/>");

            $this->addSelect($key . "_format", $triple_indent . "Format:", $format_options);

            $this->XINRegisterRule(
                $key . "_format",
                array("q2_{$key}{@}=={@}yes"),
                "Required."
            );

            $this->addSelect($key . "_length", $triple_indent . "Session Length:", $session_length_options);

            $this->XINRegisterRule(
                $key . "_length",
                array("q2_{$key}{@}=={@}yes"),
                "Required."
            );

            $this->addSelect($key . "_period", $triple_indent . "Period:", $period_options);

            $this->XINRegisterRule(
                $key . "_period",
                array("q2_{$key}{@}=={@}yes"),
                "Required."
            );

            $this->addSelect($key . "_num_sessions", $triple_indent . "Number of Sessions per Period:", $num_sessions_per_period);

            $this->XINRegisterRule(
                $key . "_num_sessions",
                array("q2_{$key}{@}=={@}yes"),
                "Required."
            );

            $this->addTextAreaElement($key . "_notes", "$this->indent $this->indent Notes:");

            $this->XINRegisterRule(
                $key . "_notes",
                array("$key . _notes{@}=={@}NEVER_REQUIRED"),
                "Never required."
            );
        }

        $this->addSelect("q2_other", "$this->indent Other?", $yes_no_options);

        $this->XINRegisterRule(
            "q2_other",
            array("q2_does_participant_have_IEP{@}=={@}yes"),
            "Required."
        );

        $this->addTextAreaElement("q2_other_describe", "$this->indent $this->indent If yes, please describe:");

        $this->XINRegisterRule(
            "q2_other_describe",
            array("q2_other{@}=={@}yes"),
            "Required."
        );
    }

    /**
    * Generates the second page of the form.
    *
    *@return void
    */
    function _page2()
    {
        $this->addHeader("IEP School Supports Extraction Form");

        $this->form->addElement("static", null, "<br/>");

        $this->addLabel("<h3>2. IEP</h3>");

        $this->form->addElement("static", null, "<br/>");

        $yes_no_options = array(
                           null  => "",
                           "no"  => "No",
                           "yes" => "Yes",
                          );

        $this->addSelect("q2_participant_receive_paraprofessional_aid", "<h4>Does the participant receive 1-1 support from a paraprofessional/aid?</h4>", $yes_no_options);

        $this->addTextAreaElement("q2_paraprofessional_aid_notes", "$this->indent Notes:");

        $this->XINRegisterRule(
            "q2_paraprofessional_aid_notes",
            array("q2_paraprofessional_aid_notes{@}=={@}NEVER_REQUIRED"),
            "Never required."
        );

        $this->form->addElement("static", null, "<br/>");

        $yes_no_options += ["not_yet_determined" => "Not Yet Determined"];

        $this->addSelect("q2_participant_receive_ESY_services", "<h4>Does the participant receive extended school year (ESY) services?</h4>", $yes_no_options);

        unset($yes_no_options["not_yet_determined"]);

        $this->addTextAreaElement("q2_ESY_notes", "$this->indent Notes:");

        $this->XINRegisterRule(
            "q2_ESY_notes",
            array("q2_ESY_notes{@}=={@}NEVER_REQUIRED"),
            "Never required."
        );

        $this->form->addElement("static", null, "<br/>");

        $this->addSelect("q2_participant_FBA_completed_BIP_implemented", "<h4>Has the participant had a functional behavior assessment (FBA) completed and behavior intervention plan (BIP) implemented?</h4>", $yes_no_options);

        $this->addTextAreaElement("q2_FBA_BIP_notes", "$this->indent Notes:");

        $this->XINRegisterRule(
            "q2_FBA_BIP_notes",
            array("q2_FBA_BIP_notes{@}=={@}NEVER_REQUIRED"),
            "Never required."
        );

        $this->form->addElement("static", null, "<br/>");

        $this->addTextAreaElement("q2_describe_other_supports_provided_by_school", "<h4>Please describe any other supports provided by the school not captured previously:</h4>");

        $this->XINRegisterRule(
            "q2_describe_other_supports_provided_by_school",
            array("q2_describe_other_supports_provided_by_school{@}=={@}NEVER_REQUIRED"),
            "Never required."
        );
    }
}
?>
