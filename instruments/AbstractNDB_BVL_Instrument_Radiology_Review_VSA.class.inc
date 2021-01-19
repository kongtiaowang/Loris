<?php

abstract class AbstractNDB_BVL_Instrument_Radiology_Review_VSA extends NDB_BVL_Instrument
{
    use LegacyInstrumentTrait;

    use instrument_validator;

    /**
     * Gets the test name.
     *
     * return string test name.
     */
    abstract function getTestName() : string;

    /**
     * Gets the name of the database table where the instrument data
     * is saved.
     *
     * return string table name.
     */
    abstract function getTableName() : string;

    /**
    * sets up basic data, such as the LorisForm object, and so on.
    *
    * @param string $commentID  the CommentID identifying the data to load
    * @param string $page       if a multipage form, the page to show
    * @return void
    * @access public
    */
    static $cssStyle = "style='color:white; background-color: black;border: 10px solid black;margin-left:0'";
    static $cssStyle2 = "style='background-color: gray;border: 10px solid gray;height:100%;width:100%;float:left;'";
    var $options = array(NULL=>"Choose one", "mild"=>"Mild", "moderate"=>"Moderate", "marked"=>"Marked");
    var $rating_options = array(NULL=>"Choose one", "0"=>"0", "0-5"=>"0-5", "5-10"=>"5-10","more_than_10"=>">10","confluent"=>"confluent" );
    function setup(?string $commentID = NULL, ?string $page = NULL): void
    {
        $this->formType="XIN";
        $this->form = new LorisForm('test_form');
        $this->page = $page;            // page label (number or
        
        // set the object properties
        $this->testName = $this->getTestName();
        $this->table    = $this->getTableName();

        // data keyed by commentID
        $this->commentID = $commentID;
        //The array of dates/timestamps to convert to database dates/timestamps
        //Any LorisForm date elements must be listed here
        $this->dateTimeFields=array("Date_taken");
        $config              = NDB_Config::singleton();
        $this->dateOptions   = array(
                              'language'         => 'en',
                              'format'           => 'YMd',
                              'minYear'          => $config->getSetting('startYear'),
                              'maxYear'          => $config->getSetting('endYear'),
                              'addEmptyOption'   => true,
                              'emptyOptionValue' => null,
                             );
        // setup the form
        $db =& Database::singleton();
        $this->_setupForm();

    }
    
    /**
    * method to build the LorisForm object into a paged form
    *
    * @return void
    * @access private
    */
    function _setupForm(){
        $testName = $this->getTestName();
        if(preg_match("/$testName(_page[0-9]+)/",$this->page,$matches)){
            call_user_func(array($this, $matches[1]));
        } else {
            $this->_main();
        }
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
        $this->form->addElement('header', 'instrument_title', "Site Radiological Review Form");
        $config = \NDB_Config::singleton();
        $yes_no_option= array(NULL=>"", "no"=>"No", "yes"=>"Yes");
        $pscid = '';
        $visitLabel = '';
        $session = $this->getSessionID();
        if (!empty($session)) {
            if($session!=-1) {
                $timepoint = \TimePoint::singleton($session);
                $visitLabel = $timepoint->getVisitLabel();
                $candidate = \Candidate::singleton($timepoint->getCandID());
                $pscid = $candidate->getPSCID();
            }
        }
        //PSCID:
        $this->form->addElement('static', "pscid", "PSCID:  ".$pscid);        
        //Visit Label:
        $this->form->addElement('static', "visitLabel", "Visit Label:  ".$visitLabel);
 
        // Date of Administration
        $this->addBasicDate('Date_taken', 'Date of Administration', $this->dateOptions);
        //Reviewed By:
        $this->form->addElement('text', "reviewed", "Reviewed By:");

        //Recommend Referral for Clinical MRI: Y/N
        $this->form->addElement('select', 'clinical_mri', 'Recommend Referral for Clinical MRI:', $yes_no_option);

        //Recommend Clinical Follow up: Y/N
        $this->form->addElement('select', 'clinical_follow', 'Recommend Clinical Follow up:', $yes_no_option);
        //1. Results of Radiological Review"

        $this->addLabel("<h3>Results of Radiological Review</h3>");
        $group[] = $this->form->createElement(
            "static",
            null,
            null,
            "<b ".self::$cssStyle2.">Rating</b>"
        );
        $group[] = $this->form->createElement(
            "static",
            null,
            null,
            "<b ".self::$cssStyle2.">Check</b>"
        );
        $group[] = $this->form->createElement(
            "static",
            null,
            null,
            "<b ".self::$cssStyle2.">Comments (optional)</b>"
        );
        $this->form->addGroup(
            $group,
            "subtest_1_headers",
            null,
            $this->_GUIDelimiter,
            false
        );
        unset($group);
        $subtest_1_questions = array(
                                "subtest_1_1" => "Normal",
                                "subtest_1_2" => "Atypical<br>Observations on scan not part of normal
spectrum but not clinically relevant",
                                "subtest_1_3" => "Abnormal<br>Potentially Clinically relevant finding",
                               );

        $subtest_1_options = array(
                              null => "",
                              0    => 0,
                              1    => 1,
                             );
        // Section 2: Adding Group and group validations
        $f=0;
        foreach ($subtest_1_questions as $key => $category) {
            $f++;
            $group[] = $this->createLabel($category."<br><br>");
            $group[] = $this->form->createElement("advcheckbox",$key."_check", null, null, null, array("no", "yes"));
            $group[] = $this->createTextArea($key . "_comment","");

            $this->form->addGroup(
                $group,
                "section1_row{$f}",
                null,
                $this->_GUIDelimiter,
                false
            );
            unset($group);
        }
    }
    function _page1(){

        $this->addLabel("<h3>Results of Radiological Review</h3>");
        //section start
        $this->addLabel("<h4>Please only check if finding is present (default if not indicated is “not present”):</h4>");
        $this->addLabel("<h4 ".self::$cssStyle.">Common Variations</h4>");
        $group[] = $this->form->createElement(
            "static",
            null,
            null,
            "<b ".self::$cssStyle2.">Incidental Finding</b>"
        );
        $group[] = $this->form->createElement(
            "static",
            null,
            null,
            "<b ".self::$cssStyle2.">Present (check ONLY if yes)</b>"
        );
        $group[] = $this->form->createElement(
            "static",
            null,
            null,
            "<b ".self::$cssStyle2.">Size (mm)</b>"
        );
        $group[] = $this->form->createElement(
            "static",
            null,
            null,
            "<b ".self::$cssStyle2.">Additional Comments</b>"
        );
        $this->form->addGroup(
            $group,
            "subtest_2_headers",
            null,
            $this->_GUIDelimiter,
            false
        );
        unset($group);
        $subtest_2_questions = array(
                                "subtest_2_1" => array("question"=>"Cavum septum pellucidum,<br>vergae, or velum interpositum","answer"=>"NA"),
                                "subtest_2_2" => array("question"=>"Mega Cisterna Magna","answer"=>"NA"),
                                "subtest_2_3" => array("question"=>"Empty Sella Configuration","answer"=>"NA"),
                               );
        $f=0;
        foreach ($subtest_2_questions as $key => $value) {
            $f++;
            $group[] = $this->createLabel($value["question"]."<br><br>");
            $group[] = $this->form->createElement("advcheckbox",$key."_check", null, null, null, array("no", "yes"));
          //  $group[] = $this->createText($key . "_size_","");
            $group[] = $this->createLabel($value["answer"]);
            $group[] = $this->createTextArea($key . "_comment","");

            $this->form->addGroup(
                $group,
                "section2_row{$f}",
                null,
                $this->_GUIDelimiter,
                false
            );
            unset($group);

        }
       // section finish
       // section start
        $this->addLabel("<h4 ".self::$cssStyle." >Other Anomalies</h4>");
        $group[] = $this->form->createElement(
            "static",
            null,
            null,
            "<b ".self::$cssStyle2.">Incidental Finding</b>"
        );
        $group[] = $this->form->createElement(
            "static",
            null,
            null,
            "<b ".self::$cssStyle2.">Present (check ONLY if yes)</b>"
        );
        $group[] = $this->form->createElement(
            "static",
            null,
            null,
            "<b ".self::$cssStyle2.">Size (mm)</b>"
        );
        $group[] = $this->form->createElement(
            "static",
            null,
            null,
            "<b ".self::$cssStyle2.">Additional Comments</b>"
        );
        $this->form->addGroup(
            $group,
            "subtest_3_headers",
            null,
            $this->_GUIDelimiter,
            false
        );
        unset($group);
        $subtest_3_questions = array(
                                "subtest_3_1" => array("question"=>"Chiari 1 Malformation (indicate size(mm) and with or w/out spinal cord syrinx)"),
                                "subtest_3_2" => array("question"=>"Dysgenesis of the Corpus Callosum","answer"=>"NA"),
                                "subtest_3_3" => array("question"=>"Agenesis of the Septum Pellucidum","answer"=>"NA"),
                                "subtest_3_4" => array("question"=>"Ventriculomegaly"),
                               );
        $f=0;
        foreach ($subtest_3_questions as $key => $value) {
            $f++;
            $group[] = $this->createLabel($value["question"]."<br><br>");
            $group[] = $this->form->createElement("advcheckbox",$key."_check", null, null, null, array("no", "yes"));
            if ($value["question"] == "Ventriculomegaly") {
                $group[] = $this->createSelect($key . "_circleOne", null, $this->options);
            } elseif ($value["question"] == "Chiari 1 Malformation (indicate size(mm) and with or w/out spinal cord syrinx)") {
                $group[] = $this->createText($key . "_size","");
            } else {
                $group[] = $this->createLabel("NA");
            }
            
            $group[] = $this->createTextArea($key . "_comment","");

            $this->form->addGroup(
                $group,
                "section3_row{$f}",
                null,
                $this->_GUIDelimiter,
                false
            );
            unset($group);

        }
       // section finish
       // section start
        $this->addLabel("<h4 ".self::$cssStyle.">Cysts and Fluid Collections</h4>");
        $group[] = $this->form->createElement(
            "static",
            null,
            null,
            "<b ".self::$cssStyle2.">Incidental Finding</b>"
        );
        $group[] = $this->form->createElement(
            "static",
            null,
            null,
            "<b ".self::$cssStyle2.">Present (check ONLY if yes)</b>"
        );
        $group[] = $this->form->createElement(
            "static",
            null,
            null,
            "<b ".self::$cssStyle2.">Size (mm)</b>"
        );
        $group[] = $this->form->createElement(
            "static",
            null,
            null,
            "<b ".self::$cssStyle2.">Additional Comments</b>"
        );
        $this->form->addGroup(
            $group,
            "subtest_4_headers",
            null,
            $this->_GUIDelimiter,
            false
        );
        unset($group);
        $subtest_4_questions = array(
                                "subtest_4_1" => "Arachnoid Cyst",
                                "subtest_4_2" => "Pineal Gland Cyst",
                                "subtest_4_3" => "Rathke cleft cyst or pars intermedia cyst",
                                "subtest_4_4" => "Choroidal fissure cyst",
                                "subtest_4_5" => "Prominent perivascular (Virchow-Robin) spaces",
                                "subtest_4_6" => "Prominent subarachnoid spaces",
                               );
        $f=0;
        foreach ($subtest_4_questions as $key => $category) {
            $f++;
            $group[] = $this->createLabel($category."<br><br>");
            $group[] = $this->form->createElement("advcheckbox",$key."_check", null, null, null, array("no", "yes"));
            if ($category == "Prominent subarachnoid spaces" || $category == "Prominent perivascular (Virchow-Robin) spaces") {
                $group[] = $this->createSelect($key . "_circleOne", null, $this->options);
            } else {
                $group[] = $this->createText($key . "_size","");
            }
            $group[] = $this->createTextArea($key . "_comment","");

            $this->form->addGroup(
                $group,
                "section4_row{$f}",
                null,
                $this->_GUIDelimiter,
                false
            );
            unset($group);

        }
       // section finish
       // section start
        $this->addLabel("<h4 ".self::$cssStyle.">Migration Disorders</h4>");
        $group[] = $this->form->createElement(
            "static",
            null,
            null,
            "<b ".self::$cssStyle2.">Incidental Finding</b>"
        );
        $group[] = $this->form->createElement(
            "static",
            null,
            null,
            "<b ".self::$cssStyle2.">Present (check ONLY if yes)</b>"
        );
        $group[] = $this->form->createElement(
            "static",
            null,
            null,
            "<b ".self::$cssStyle2.">Size (mm)</b>"
        );
        $group[] = $this->form->createElement(
            "static",
            null,
            null,
            "<b ".self::$cssStyle2.">Additional Comments</b>"
        );
        $this->form->addGroup(
            $group,
            "subtest_5_headers",
            null,
            $this->_GUIDelimiter,
            false
        );
        unset($group);
        $subtest_5_questions = array(
                                "subtest_5_1" => "Subependymal gray-matter heterotopia",
                                "subtest_5_2" => "Transmantle dysplasia",
                                "subtest_5_3" => "Focal cortical dysplasia",
                               );
        $f=0;
        foreach ($subtest_5_questions as $key => $category) {
            $f++;
            $group[] = $this->createLabel($category."<br><br>");
            $group[] = $this->form->createElement("advcheckbox",$key."_check", null, null, null, array("no", "yes"));
	    $group[] = $this->createLabel("NA");
            $group[] = $this->createTextArea($key . "_comment","");

            $this->form->addGroup(
                $group,
                "section5_row{$f}",
                null,
                $this->_GUIDelimiter,
                false
            );
            unset($group);

        }
       // section finish
       // section start
        $this->addLabel("<h4 ".self::$cssStyle.">Grey-matter and White-matter Abnormalities</h4>");
        $group[] = $this->form->createElement(
            "static",
            null,
            null,
            "<b ".self::$cssStyle2.">Incidental Finding</b>"
        );
        $group[] = $this->form->createElement(
            "static",
            null,
            null,
            "<b ".self::$cssStyle2.">Present (check ONLY if yes)</b>"
        );
        $group[] = $this->form->createElement(
            "static",
            null,
            null,
            "<b ".self::$cssStyle2.">Size (mm)</b>"
        );
        $group[] = $this->form->createElement(
            "static",
            null,
            null,
            "<b ".self::$cssStyle2.">Additional Comments</b>"
        );
        $this->form->addGroup(
            $group,
            "subtest_6_headers",
            null,
            $this->_GUIDelimiter,
            false
        );
        unset($group);
        $subtest_6_questions = array(
                                "subtest_6_1" => "Focal white-matter hyperintensity",
                                "subtest_6_2" => "Periventricular leukomalacia",
                                "subtest_6_3" => "Encephalomalacia",
                               );
        $f=0;
        foreach ($subtest_6_questions as $key => $category) {
            $f++;
            $group[] = $this->createLabel($category."<br><br>");
            $group[] = $this->form->createElement("advcheckbox",$key."_check", null, null, null, array("no", "yes"));
            if ($category == "Periventricular leukomalacia" || $category == "Encephalomalacia" ) {
                $group[] = $this->createSelect($key . "_circleOne", null, $this->options);
            } else {
                $group[] = $this->createLabel('(If present, please fill out page 2)');
            }
            $group[] = $this->createTextArea($key . "_comment","");

            $this->form->addGroup(
                $group,
                "section6_row{$f}",
                null,
                $this->_GUIDelimiter,
                false
            );
            unset($group);

        }
       // section finish
       // section start
        $this->addLabel("<h4 ".self::$cssStyle.">Neoplasms</h4>");
        $group[] = $this->form->createElement(
            "static",
            null,
            null,
            "<b ".self::$cssStyle2.">Incidental Finding</b>"
        );
        $group[] = $this->form->createElement(
            "static",
            null,
            null,
            "<b ".self::$cssStyle2.">Present (check ONLY if yes)</b>"
        );
        $group[] = $this->form->createElement(
            "static",
            null,
            null,
            "<b ".self::$cssStyle2.">Size (mm)</b>"
        );
        $group[] = $this->form->createElement(
            "static",
            null,
            null,
            "<b ".self::$cssStyle2.">Additional Comments</b>"
        );
        $this->form->addGroup(
            $group,
            "subtest_7_headers",
            null,
            $this->_GUIDelimiter,
            false
        );
        unset($group);
        $subtest_7_questions = array(
                                "subtest_7_1" => "Cerebellum",
                                "subtest_7_2" => "Brainstem",
                                "subtest_7_3" => "Supersellar/Hypothalamic",
                                "subtest_7_4" => "Intraventricular",
                                "subtest_7_5" => "Basal Ganglia/Thalamus",
                                "subtest_7_6" => "Lobar",

                               );
        $f=0;
        foreach ($subtest_7_questions as $key => $category) {
            $f++;
            $group[] = $this->createLabel($category."<br><br>");
            $group[] = $this->form->createElement("advcheckbox",$key."_check", null, null, null, array("no", "yes"));
            $group[] = $this->createText($key . "_size","");
            $group[] = $this->createTextArea($key . "_comment","");

            $this->form->addGroup(
                $group,
                "section7_row{$f}",
                null,
                $this->_GUIDelimiter,
                false
            );
            unset($group);

        }
       // section finish
       // section start
        $this->addLabel("<h4 ".self::$cssStyle.">Calvarial and Extra-cranial Findings</h4>");
        $group[] = $this->form->createElement(
            "static",
            null,
            null,
            "<b ".self::$cssStyle2.">Incidental Finding</b>"
        );
        $group[] = $this->form->createElement(
            "static",
            null,
            null,
            "<b ".self::$cssStyle2.">Present (check ONLY if yes)</b>"
        );
        $group[] = $this->form->createElement(
            "static",
            null,
            null,
            "<b ".self::$cssStyle2.">Size (mm)</b>"
        );
        $group[] = $this->form->createElement(
            "static",
            null,
            null,
            "<b ".self::$cssStyle2.">Additional Comments</b>"
        );
        $this->form->addGroup(
            $group,
            "subtest_8_headers",
            null,
            $this->_GUIDelimiter,
            false
        );
        unset($group);
        $subtest_8_questions = array(
                                "subtest_8_1" => "Sinus Opacification",
                                "subtest_8_2" => "Mastoid Opacification",
                                "subtest_8_3" => "Orbital Findings",
                                "subtest_8_4" => "Lesions in the bone",
                                "subtest_8_5" => "Lesions in the scalp",
                                "subtest_8_6" => "Lesions of the skull base",
                               );
        $f=0;	
        foreach ($subtest_8_questions as $key => $category) {
            $f++;
            $group[] = $this->createLabel($category."<br><br>");
            $group[] = $this->form->createElement("advcheckbox",$key."_check", null, null, null, array("no", "yes"));
            if ($category == "Sinus Opacification" || $category == "Mastoid Opacification") {
                $group[] = $this->createSelect($key . "_circleOne", null, $this->options);
            } else {
                $group[] = $this->createLabel("NA");
            } 
            $group[] = $this->createTextArea($key . "_comment","");

            $this->form->addGroup(
                $group,
                "section8_row{$f}",
                null,
                $this->_GUIDelimiter,
                false
            );
            unset($group);

        }
       // section finish
       $this->form->addFormRule(array(&$this, 'size_rules'));

    }
    function _page2(){

        $this->addLabel("<h3>2. White Matter Lesion Rating (Please, only fill out if indicated above)</h3>");
        $group[] = $this->form->createElement(
            "static",
            null,
            null,
            "<b>Lesion Location</b>"
        );
        $group[] = $this->form->createElement(
            "static",
            null,
            null,
            "<b>WM Hyperintensities<br>Rating Options: (0, 0-5,<br>5-10, >10, confluent)</b>"
        );
        $group[] = $this->form->createElement(
            "static",
            null,
            null,
            "<b>Blackholes [defined as white<br>matter lesions<br>hypointense to gray matter on MPRAGE]<br>Rating Options: 
(0, 0-5, 5-10, >10,<br>confluent)</b>"
        );
        $group[] = $this->form->createElement(
            "static",
            null,
            null,
            "<b>Comments (ie: confluent lesions)</b>"
        );
        $this->form->addGroup(
            $group,
            "subtest_9_headers",
            null,
            $this->_GUIDelimiter,
            false
        );
        unset($group);
        $subtest_9_questions = array(
                                "subtest_9_1" => "Juxta cortical",
                                "subtest_9_2" => "Deep white matter",
                                "subtest_9_3" => "Periventricular white matter",
                                "subtest_9_4" => "Corpus Callosum",
                                "subtest_9_5" => "Brain Stem",
                                "subtest_9_6" => "Cerebellum",
                                "subtest_9_7" => "Cervical Cord",
                               );

        $subtest_9_options = array(
                              null => "",
                              0    => 0,
                              1    => 1,
                             );
        // Section 2: Adding Group
        $f=0;
        foreach ($subtest_9_questions as $key => $category) {
            $f++;
            $group[] = $this->createLabel($category."<br><br>");
            $group[] = $this->createSelect($key . "_wm", null, $this->rating_options);
            $group[] = $this->createSelect($key . "_blackholes", null, $this->rating_options);
            $group[] = $this->createText($key . "_comment",null);

            $this->form->addGroup(
                $group,
                "section9_row{$f}",
                null,
                $this->_GUIDelimiter,
                false
            );
            unset($group);
        }
        $this->form->addFormRule(array(&$this, 'page2_rules'));
    }
    function _page3(){
         $this->addLabel("<h3>Additional Comments:</h3>");
         $this->form->addElement("textarea", "additional_comments", "Additional Comments", array('cols'=>50, 'rows'=>4));
    }
    function size_rules($values)
    {
        $errors = [];
        $check_greater_than_0 = [
                                 ["subtest_3_1_size", "section3_row1"],
                                 ["subtest_4_1_size", "section4_row1"],
                                 ["subtest_4_2_size", "section4_row2"],
                                 ["subtest_4_3_size", "section4_row3"],
                                 ["subtest_4_4_size", "section4_row4"],
                                 ["subtest_7_1_size", "section7_row1"],
                                 ["subtest_7_2_size", "section7_row2"],
                                 ["subtest_7_3_size", "section7_row3"],
                                 ["subtest_7_4_size", "section7_row4"],
                                 ["subtest_7_5_size", "section7_row5"],
                                 ["subtest_7_6_size", "section7_row6"],
                                ];
        for ( $i=0; $i<count($check_greater_than_0);$i++){
           $field = $check_greater_than_0[$i][0];
           $group = $check_greater_than_0[$i][1];
           if ($values["$field"] != "") {
           $this->validate_positive_numeric($values, $field, $errors, $group);
           }
           $check = $field;
           $check = str_replace("size","check",$check);
           if ($values[$field] != '' && $values["$check"] != "yes") {
            $errors[$group] = "You must check the 'Present' box if you specify a size";
           }
        }

        $check_present = [
            "subtest_3_4" => "section3_row4",
            "subtest_4_5" => "section4_row5",
            "subtest_4_6" => "section4_row6",
            "subtest_6_2" => "section6_row2",
            "subtest_6_3" => "section6_row3",
            "subtest_8_1" => "section8_row1",
            "subtest_8_2" => "section8_row2",
        ];
        foreach($check_present as $subtest => $group){
           if ($values["{$subtest}_circleOne"] != '' && $values["{$subtest}_check"] != "yes") {
            $errors[$group] = "You must check the 'Present' box if you specify a size";
           }
        }
 
                $page2_entry = [
                                 "subtest_9_1_wm",
                                 "subtest_9_1_blackholes",
                                 "subtest_9_1_comment",
                                 "subtest_9_2_wm",
                                 "subtest_9_2_blackholes",
                                 "subtest_9_2_comment",                                 
                                 "subtest_9_3_wm",
                                 "subtest_9_3_blackholes",
                                 "subtest_9_3_comment",
                                 "subtest_9_4_wm",
                                 "subtest_9_4_blackholes",
                                 "subtest_9_4_comment",
                                 "subtest_9_5_wm",
                                 "subtest_9_5_blackholes",
                                 "subtest_9_5_comment",
                                 "subtest_9_6_wm",
                                 "subtest_9_6_blackholes",
                                 "subtest_9_6_comment",
                                 "subtest_9_7_wm",
                                 "subtest_9_7_blackholes",
                                 "subtest_9_7_comment",
                                ]; 
              $db =& Database::singleton();
              for ( $i=0; $i<count($page2_entry);$i++){
                  $item  = $page2_entry[$i];
                  $commentID=$this->getCommentID();
                  $value = $db->pselectOne(
                  "SELECT $item FROM $this->testName} where CommentID='$commentID'",array());
                  if ($value != "" && $value != NULL && ($values["subtest_6_1_check"] != "yes" 
                      || $values["subtest_6_1_check"] != "yes")){
                     $errors['section6_row1'] = "You must check the 'Present' box since you entered information on page 2";
                     return $errors;
                  }
              }
              
        return $errors;
    }

    function page2_rules($values)
    {
        $errors = [];
        
        $db =& Database::singleton();
        $commentID=$this->getCommentID();
        $value = $db->pselectOne(
            "SELECT subtest_6_1_check FROM {$this->testName} where CommentID='$commentID'",
            array()
        );
        if ($value != 'yes'){
            $page2_entry = [
                "subtest_9_1_wm"              => 'section9_row1',
                "subtest_9_1_blackholes"      => 'section9_row1',
                "subtest_9_1_comment"         => 'section9_row1',
                "subtest_9_2_wm"              => 'section9_row2',
                "subtest_9_2_blackholes"      => 'section9_row2',
                "subtest_9_2_comment"         => 'section9_row2',
                "subtest_9_3_wm"              => 'section9_row3',
                "subtest_9_3_blackholes"      => 'section9_row3',
                "subtest_9_3_comment"         => 'section9_row3',
                "subtest_9_4_wm"              => 'section9_row4',
                "subtest_9_4_blackholes"      => 'section9_row4',
                "subtest_9_4_comment"         => 'section9_row4',
                "subtest_9_5_wm"              => 'section9_row5',
                "subtest_9_5_blackholes"      => 'section9_row5',
                "subtest_9_5_comment"         => 'section9_row5',
                "subtest_9_6_wm"              => 'section9_row6',
                "subtest_9_6_blackholes"      => 'section9_row6',
                "subtest_9_6_comment"         => 'section9_row6',
                "subtest_9_7_wm"              => 'section9_row7',
                "subtest_9_7_blackholes"      => 'section9_row7',
                "subtest_9_7_comment"         => 'section9_row7'
            ];
        
            foreach($page2_entry as $field => $group) {
                if($values[$field] != '') {
                     $errors[$group] = "You cannot enter information on that line since you did not indicate the presence of Focal white-matter hyperintensity  on page 1";
                }
            }
        }

        return $errors;
    }
}
