<?php


set_include_path(get_include_path().":../libraries:../../php/libraries:");

class NDB_BVL_Instrument_Radiology_Review_VSA extends NDB_BVL_Instrument
{


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
    var $options = array(""=>"Choose one", "mild"=>"Mild", "moderate"=>"Moderate", "marked"=>"Marked");
    function setup($commentID, $page): void{
        $this->formType="XIN";
        $this->form = new LorisForm('test_form');
        $this->page = $page;            // page label (number or
        // string - used by
        // user-defined child classes)
        
        // set the object properties
        $this->testName = "Radiology_Review_VSA";           // test_names.Test_name
        $this->table = 'Radiology_Review_VSA';              // name of database table corresponding to instrument
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
        $this->_setupForm();

    }
    
    /**
    * method to build the LorisForm object into a paged form
    *
    * @return void
    * @access private
    */
    function _setupForm(){
        if(preg_match("/Radiology_Review_VSA(_page[0-9]+)/",$this->page,$matches)){
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
          $timepoint = \TimePoint::singleton($session);
          $visitLabel = $timepoint->getVisitLabel();
          $candidate = \Candidate::singleton($timepoint->getCandID());
          $pscid     = $candidate->getPSCID();
        }
        //PSCID:
        $this->form->addElement('static', "pscid", "PSCID:  ".$pscid);        
        //Visit Label:
        $this->form->addElement('static', "visitLabel", "Visit Label:  ".$visitLabel);
 
        // this date doesn't work at all ????????????
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
                                "subtest_2_1" => "Cavum septum pellucidum,<br>vergae, or velum interpositum",
                                "subtest_2_2" => "Mega Cisterna Magna",
                                "subtest_2_3" => "Empty Sella Configuration",
                               );
        $f=0;
        foreach ($subtest_2_questions as $key => $category) {
            $f++;
            $group[] = $this->createLabel($category."<br><br>");
            $group[] = $this->form->createElement("advcheckbox",$key."_check", null, null, null, array("no", "yes"));
            $group[] = $this->createText($key . "_size_","");
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
                                "subtest_3_1" => "Chiari 1 Malformation",
                                "subtest_3_2" => "Dysgenesis of the Corpus Callosum",
                                "subtest_3_3" => "Agenesis of the Septum Pellucidum",
                                "subtest_3_4" => "Ventriculomegaly",
                               );
        $f=0;
        foreach ($subtest_3_questions as $key => $category) {
            $f++;
            $group[] = $this->createLabel($category."<br><br>");
            $group[] = $this->form->createElement("advcheckbox",$key."_check", null, null, null, array("no", "yes"));
            if ($category == "Ventriculomegaly") {
                $group[] = $this->createSelect($key . "_circleOne", null, $this->options);
            } else {
                $group[] = $this->createText($key . "_size","");
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
            $group[] = $this->createText($key . "_size","");
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
                $group[] = $this->createText($key . "_size","");
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
                                "subtest_8_3" => "Focal cortical dysplasia",
                                "subtest_8_4" => "Orbital Findings",
                                "subtest_8_5" => "Lesions in the bone",
                                "subtest_8_6" => "Lesions in the scalp",
                                "subtest_8_7" => "Lesions of the skull base",
                               );
        $f=0;
        foreach ($subtest_8_questions as $key => $category) {
            $f++;
            $group[] = $this->createLabel($category."<br><br>");
            $group[] = $this->form->createElement("advcheckbox",$key."_check", null, null, null, array("no", "yes"));
            if ($category == "Sinus Opacification" || $category == "Mastoid Opacification") {
                $group[] = $this->createSelect($key . "_circleOne", null, $this->options);
            } else {
                $group[] = $this->createText($key . "_size","");
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
            "<b>Comments (ie: confluentlesions)</b>"
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
                                "subtest_9_2" => "Deep white",
                                "subtest_9_3" => "matter",
                                "subtest_9_4" => "Periventricular white matter",
                                "subtest_9_5" => "Corpus Callosum",
                                "subtest_9_6" => "Brain Stem",
                                "subtest_9_7" => "Cerebellum",
                                "subtest_9_8" => "Cervical Cord",
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
            $group[] = $this->createText($key . "_wm","");
            $group[] = $this->createText($key . "_blackholes",""); 
            $group[] = $this->createTextArea($key . "_comment","");

            $this->form->addGroup(
                $group,
                "section9_row{$f}",
                null,
                $this->_GUIDelimiter,
                false
            );
            unset($group);

        }
     
    }
    function _page3(){
         $this->addLabel("<h3>Additional Comments:</h3>");
         $this->form->addElement("textarea", "additional_comments", "Additional Comments", array('cols'=>50, 'rows'=>4));
    }
    function _saveValues($values){
              if(isset($values['Date_taken'])) {
                  $date = $values['Date_taken'];
                  if(!empty($date['Y']) && !empty($date['M']) && !empty($date['d'])) {
                      $values['Date_taken'] = $this->_getDatabaseDate($date); //sprintf("%04d-%02d-%02d", $date['Y'], $date['M'], $date['d']);
                      $this->_saveCandidateAge($values);
                  }  else {
                      unset($values['Date_taken']);
                  }
             }


    }
}
