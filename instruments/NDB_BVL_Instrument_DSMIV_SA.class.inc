<?php

class NDB_BVL_Instrument_DSMIV_SA extends NDB_BVL_Instrument
{
    use LegacyInstrumentTrait;

    var $yesNo = array(null => "", 'no' => "No", 'yes' => "Yes");
    var $confidence = array(null => "", 'very_confident' => "Very Confident", 'somewhat_confident' => "Somewhat Confident", 'not_confident' => "Not Confident");

    var $ValidityEnabled = false;
    var $ValidityRequired = false;


    /**
     * sets up basic data, such as the LorisForm object, and so on.
     *
     * @param string $page       if a multipage form, the page to show
     * @return void
     * @access public
     */
    function setup(?string $commentID = NULL, ?string $page = NULL): void
    {
        $this->formType="XIN";
        $this->form = new LorisForm('DSMIV_SA');
        $this->page = $page;            // page label (number or
        // string - used by
        // user-defined child classes)

        // set the object properties
        $this->testName = "DSMIV_SA";           // test_names.Test_name
        $this->table = 'DSMIV_SA';              // name of database table corresponding to instrument

        // data keyed by commentID
        $this->commentID = $commentID;

        //The array of dates/timestamps to convert to database dates/timestamps
        //Any LorisForm date elements must be listed here
        $this->dateTimeFields=array("Date_taken", "date_taken_diagnostic_assessor", "date_taken_confirming_clinician");

        $this->_requiredElements = array('Examiner', 'Date_taken');


        $config =& NDB_Config::singleton();
        $this->dateOptions = array(
            'language' => 'en',
            'format'   => 'YMd',
            'minYear'  => $config->getSetting('startYear'), //allows for siblings up to 20 years older than candidate
            'maxYear'  => $config->getSetting('endYear'),
            'addEmptyOption' => true,
            'emptyOptionValue' => null
        );

        $this->_setupForm();

    }

    //If the instrument is not paged, remove the switch from the _setupForm method and add all the form Elements in this function.

    /**
     * method to build the LorisForm object into a paged form
     *
     * @return void
     * @access private
     */
    function _setupForm(){

        //determine page to display
        if(preg_match("/DSMIV_SA(_page[1-9]+)/",$this->page,$matches)){
            call_user_func(array($this, $matches[1]));
        } else {
            $this->_main();
        }

        //Defines the call back function for HTML Quickform to use when validating the form.
        $this->form->addFormRule(array(&$this,'XINValidate'));
    }

    /**
     * generates the main page of the form.
     *
     * @return void
     * @access private
     *
     */
    function _main(){
        // display test name
        $this->form->addElement('header', 'instrument_title', "DSM-IV Autistic Disorder Checklist (School Age)");

        // automatically adds examiner & date of administration
        $this->_addMetadataFields();
    }

    function _page1()
    {
        $this->addHeader("DSM-IV Autistic Disorder Checklist (School Age)");
        $section_headers = array(
            "(1) Qualitative impairment in social interaction",
            "(2) Qualitative impairment in communication",
            "(3) Restricted repetitive and stereotyped patterns of behavior, interests, and activities"
        );
        $questions = array(
            array(
                "q1a" => "(a) marked impairment in the use of nonverbal behaviors such as eye-to-eye gaze, facial expression, 
                        body posture and gestures used to regulate social interaction",
                "q1b" => "(b) failure to develop peer relationships appropriate to developmental level",
                "q1c" => "(c) a lack of seeking to share enjoyment, interests, achievement with others (e.g. by a lack of showing, 
                         bringing, or pointing out objects of interest",
                "q1d" => "(d) lack of social-emotional reciprocity."),
            array(
                "q2a" => "(a) delay in, or total lack of, spoken language (not accompanied by an attempt to compensate through alternative
                modes of communication such as gesture or mime)",
                "q2b" => "(b) in individuals with adequate speech, marked impairment in the ability to initiate or sustain a conversation with others",
                "q2c" => "(c) stereotyped (e.g. echolaic) and repetitive use of language or idiosyncratic language",
                "q2d" => "(d) lack of varied, spontaneous, make-believe play or social imitative play appropriate to developmental level"
            ),
            array(
                "q3a" => "(a) encompass preoccupation with one or more stereotyped or restrictive patterns of interest that is abnormal in etiher intensity or focus",
                "q3b" => "(b) apparently inflexible adherence to specific, non-functional routines or rituals",
                "q3c" => "(c) stereotyped and repetitive motor mannerisms (e.g. hand or finger flapping or twisting, or complex whole-body movements)",
                "q3d" => "(d) persistent preoccupation with parts of objects"
            )
        );

        for ($i=0; $i < count($section_headers); $i++) {
            $this->_displayHeader($section_headers[$i], $i);
            foreach ($questions[$i] as $key => $question) {
                $group[] =& $this->createLabel(
                    $question);
                $group[] =& $this->createSelect(
                    $key,
                    "",
                    $this->yesNo
                );
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

        $this->addHeader("<h4><b>Meets DSM-IV Criteria for Autistic Disorder</b>
                                 <BR><ul><li>Total of at least 6 symptoms</li><BR>
                                 <li>At least 2 from category 1</li><BR>
                                 <li>At least 1 from category 2</li><BR>
                                 <li>At least 1 from category 3</li><BR>
                                 <li>Onset before age 3</li><BR>
                                 <li>No other explanation</li></ul></h4>");
        $this->addSelect("meets_dsmiv_criteria_autistic_disorder", "", $this->yesNo);

        $this->addHeader("<h4>Does he/she meet <b>DSM-IV Criteria for Pervasive Developmental Disorder - Not Otherwise Specified?</b>
                                 <BR><ul><li>Total of at least 3 symptoms</li><BR>
                                 <li>At least 1 from category 1 (\"Failure to develop peer relationships...\" may NOT be the only category 1 item)</li><BR>
                                 <li>At least 1 from <u>either</u> category 2 OR category 3</li><BR>
                                 <li>No other explanation</li></ul></h4>");

        $this->addSelect(
            "meets_dsmiv_criteria_pervasive_developmental_disorder",
            "",
            array(
                null => "",
                "no_na" => "No or N/A (e.g. has autism)",
                "yes" => "Yes"
            )
        );

        $this->addHeader("<h4>IF child does NOT meet criteria for an ASD - <b><u>check NON ASD below and specify other dx/comment</u></b></h4>");
        $this->addCheckbox('nonasd', 'NA', array('value' => '1'));
        $this->XINRegisterRule('nonasd', array('nonasd{@}=={@}NEVER_REQUIRED'));
        $this->addBasicText('nonasd_comments', "Other dx/comment:");
        $this->XINRegisterRule('nonasd_comments', array("nonasd{@}=={@}Yes"), "Required if non-ASD box is checked.");


        $this->addHeader("<h4><b>Confidence rating.</b> Given all the data that you have on this child, how confident are you about the classification
                         of this child <u>based on the DSM-IV criteria?</h4>");

        $this->addSelect(
            "confidence_rating",
            "",
            array(
                null => "",
                3 => "3 - Very Confident",
                2 => "2 - Somewhat Confident",
                1 => "1 - Not Confident"
            )
        );

        $this->addBasicText("comments", "Comments (required for a rating of 2 or 1");
        $this->XINRegisterRule("comments", array("confidence_rating{@}=={@}2|1"), "Required for a rating of 2 or 1.");

    }

    function _displayHeader($section_header, $groupname){
        $group[] =& $this->form->createElement(
            "static",
            null,
            null,
            "<b><u>$section_header</u></b>");
        $group[] =& $this->form->createElement(
            "static",
            null,
            null,
            "<b><u>Present</u></b>");
        $this->addGroup(
            $group,
            $groupname . "_header",
            null,
            $this->_GUIDelimiter,
            false
        );
    }


}
?>
