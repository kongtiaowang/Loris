<?php




class NDB_BVL_Instrument_WIAT_III_SA extends NDB_BVL_Instrument
{

    var $ValidityEnabled = false;
    var $ValidityRequired = false;

    /**
    * sets up basic data, such as the LorisForm object, and so on.
    *
    * @param string $commentID  the CommentID identifying the data to load
    * @param string $page       if a multipage form, the page to show
    * @return void
    * @access public
    */
    function _setup($commentID, $page){
        $this->formType="XIN";
        $this->form = new LorisForm('test_form');
        $this->page = $page;            // page label (number or

        $this->testName = "WIAT_III_SA";           // test_names.Test_name
        $this->table = 'WIAT_III_SA';

        // data keyed by commentID
        $this->commentID = $commentID;

        //The array of dates/timestamps to convert to database dates/timestamps
        //Any LorisForm date elements must be listed here
        $this->dateTimeFields=array("Date_taken");

        //The array of selects with multiple answers allowed
        //Any LorisForm multiple selects must be listed here
        $this->_selectMultipleElements = array();

        // required fields for data entry completion status
        $this->_requiredElements = array('Date_taken', 'Examiner', 'File_name');

        // setup the form
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
         if (preg_match(
             "/WIAT_III_SA(_page[0-9]+)/",
             $this->page,
             $matches
         )) {
             call_user_func(array($this, $matches[1]));
         } else {
             $this->_main();
         }
     }
    
    //If the instrument is not paged, remove the switch from the _setupForm method and add all the form Elements in this function.

     /**
     * method to build the LorisForm object into a paged form
     *
     * @return void
     * @access private
     */
     
    function _main(){

         $factory  = NDB_Factory::singleton();
         $baseURL = $factory->settings()->getBaseURL();
         // display test name
         $this->form->addElement('header', 'instrument_title', $this->getFullName());
         $testName = isset($_REQUEST['test_name']) ? $_REQUEST['test_name'] : '';
         $candID = isset($_REQUEST['candID']) ? $_REQUEST['candID'] : '';
         $sessionID = isset($_REQUEST['sessionID']) ? $_REQUEST['sessionID'] : '';
         $this->form->updateAttributes(
             array(
                 'action' =>"$baseURL/$testName/?candID=$candID&sessionID=$sessionID&commentID=".$this->getCommentID()
             )
         );

         // add examiner & date of administration
         //$this->form->addElement('static', 'Date_taken_display', 'Date of Administration');
         
         // Get the item scores


         $db =& Database::singleton();
         
         $query = "SELECT * FROM ".$this->table." WHERE CommentID='".$this->getCommentID()."'";
         $record = $db->pselectRow($query, array());
         

         $this->_addMetadataFields();


         $this->form->addElement('file', 'wiatIII_file', 'Upload the WIAT_III file');

         $this->form->addElement('static', "File_name", "Uploaded File");
         
         

         
          $this->form->addElement('header', null, "Subtest Score Summary");
         
         
         //scoring column headers
           $group[] = $this->form->createElement('static', "RAW", null, null);
           $group[] = $this->form->createElement('static', "STD_SCORE", null, null);
           $group[] = $this->form->createElement('static', "CI", null, null);
           $group[] = $this->form->createElement('static', "PER_RANK", null, null);
           $group[] = $this->form->createElement('static', "NCE", null, null);
           $group[] = $this->form->createElement('static', "STANINE", null, null);
           $group[] = $this->form->createElement('static', "GRADE_EQUIV", null, null);
           $group[] = $this->form->createElement('static', "AGE_EQUIV", null, null);
           $this->form->addGroup($group, 'score_header_group', "<strong>Domain/Subdomain</strong>", $this->_GUIDelimiter, FALSE);
           unset($group);


           //score fields
           $domains = array("RC"=>"Reading Comprehension", "MPS"=>"Math Problem Solving", "WR"=>"Word Reading", "PD"=>"Pseudoword Decoding",
                           "NO"=>"Numerical Operations");
           $columnHeaders = array("RAW" => "Raw Score", "STD_SCORE" => "Standard Score",
                          "CI" => "95% Confidence Interval", "PER_RANK" =>"Percentile Rank",
                           "NCE" => "Normal Curve Equiv", "STANINE" => "Stanine","GRADE_EQUIV" => "Grade Equivalent","AGE_EQUIV" => "Age Equivalent"
           );
           
           foreach($columnHeaders as $field=>$label) {
               $columnHeaders[$field] .= $this->indent;
           }
             $this->localDefaults = array_merge($this->localDefaults, $columnHeaders);

           foreach($domains as $field=>$label) {
               foreach($columnHeaders as $scoreField=>$scoreLabel) {
                  
                  // Domain scores and ABC don't have AGE_EQUIV, but add a blank column to keep the table aligned
                  if(($field == "COM" || $field == "DLS" || $field == "SOC" || $field == "MS" || $field == "ABC") && $scoreField == "AGE_EQUIV"){
                      $group[] = $this->form->createElement('static', null, "&nbsp;", null);
                      continue;
                  }
                  // Subdomains don't have STD_SCORE, %ILE_RANK, or STANINE, but again add a blank column to keep the table aligned
                  if(($field == 'REC' || $field == 'EXP' || $field == 'WRN' ||  // Communication subdomains
                      $field == 'PER' || $field == 'DOM' || $field == 'CMM' ||  // Daily Living Skills subdomains
                      $field == 'IPR' || $field == 'PL'  || $field == 'CS'  ||  // Socialization subdomains
                      $field == 'GMS' || $field == 'FMS') &&                    // Motor skills subdomains
                      ($scoreField == 'STD_SCORE' || $scoreField == '%ILE_RANK' || $scoreField == 'STANINE')
                      ) {
                      $group[] = $this->form->createElement('static', null, "&nbsp;", null);
                      continue;

                  }

                  if(($field == "COM" || $field == "DLS" || $field == "SOC" || $field == "MS") && $scoreField == "VSCALE"){
                     $scoreField = "SUM_VSCALES_FOR_DOMAIN";
                  }
                  if($field == "ABC" && $scoreField == "RAW"){
                     $scoreField = "SUM_ALL_DOM_STD_SCORES";
                  }
                  $group[] = $this->form->createElement('static', "{$field}_{$scoreField}", null, null);
               }
               $this->form->addGroup($group, "{$label}_group", $label, $this->_GUIDelimiter, FALSE);
               unset($group);
           }         

      
         // add rules
         // parent report question
         if($this->getFieldValue("File_name")===false){
             $this->form->addRule("wiatIII_file", "WIAT III file is required.", 'required', null, 'server');
         } else {
             $this->XINRegisterRule("wiatIII_file", array("wiatIII_file{@}==={@}NEVER_REQUIRED"));
         }
         // handedness questions
	   $this->form->addElement('static', null, "<br /><br />");
       $this->form->addElement("textarea", "other_comments", "Comments about Validity:", array('cols'=>25, 'rows'=>4));
       $this->XINRegisterRule("other_comments", array("{other_comments}{@}=={@}NEVER_REQUIRED"));


     } // end function _main

      function _saveValues($values)
      {
          $timepoint =& TimePoint::singleton($this->getSessionID());
          $candidate =& Candidate::singleton($timepoint->getCandID());

          if(isset($values['Date_taken'])) {
              $this->_saveCandidateAge($values);
          }

          require_once "File_Upload.class.inc";
          $file=new File_Upload;

          //pass the existing form ($form) by reference to File_Upload, and register the file_upload field names being used.
          $file->registerForm($this->form);

          //Tell File_Upload what file handlers to use.
          $file->setFileHandler("wiatIII_file", $this);
                    
          //Set the target directory that you want files moved into once they are validated and processed.
          $config = NDB_Config::singleton();
          $dir = $config->getSetting("UploadDir");
          if(empty($dir)) {
            $dir = ".";
          };
          $file->setBaseUploadDirectory($dir . "/wiatIII/");

          //Set the prefix to prepend to the filenames
          //$file->setFilenamePrefix($timepoint->getVisitLabel()."-".$this->testName."-");

          //set the the IDs to the handler functions.
          $user =& User::singleton();
          $file->setHandlerArgs(array("CommentID"=>$this->getCommentID(),
                                      "candID"=>$candidate->getCandID(),
                                      "PSCID"=>$candidate->getPSCID(),
                                      "visitLabel"=>$timepoint->getVisitLabel(),
                                      "username"=>$user->getUsername(),
                                      "values"=>$values)
          
          
                               );

          //If the form is validated, call File_Upload::processFiles() which loops through the files and 
          //proccesses them (including verify, move, and import steps)
          if ($values['wiatIII_file']['name'] != false) {
            $file->processFiles();
          }
          
          //echo error messages
          if(!empty($file->errorLog)){
             while(list($fileType,$fileErrors)=each($file->errorLog)){
                 foreach($fileErrors AS $error){
                      echo "<span style='color:red'><b>Upload Error</b> $fileType: $error</span><br>";
                 }
             }
          } 
          unset($values['candID'], $values['sessionID'], $values['commentID'], $values['test_name'], $values['page'], $values['fire_away'], $values['subtest'], $values['MAX_FILE_SIZE'], $values['wiatIII_file']);
          $this->_save($values);
      }

      /**
      * isValid checks the validity of the file.
      *
      * @param     string  $file    The full filename including directory.
      *
      * @return    bool    $success		if operation succeeded
      * @access    public
      */
      function isValid(&$file, $args){
         $correct_filename = strtolower($this->testName .'_'. $args['candID'] .'_'. $args['PSCID'] .'_'. $args['visitLabel'] . ".txt");
         if(strtolower($file->fileInfo['name']) != $correct_filename){
               $errors[]="Incorrect Filename: Filename should be: " . $correct_filename;
               return $errors;
           }

           $fp=fopen($file->fileInfo['tmp_name'], "r");
           $contents=fread($fp,filesize($file->fileInfo['tmp_name']));
           fclose($fp);
           
           $lines=explode("\n",$contents);
            $keys = explode("\t", $lines[0]);
            $vals = explode("\t", $lines[1]);
            for($i = 0; $i < count($keys); $i++){
                if (!empty($keys[$i]) && !preg_match("/^\s+$/", $keys[$i])){
                  $values[$keys[$i]] = $vals[$i];   
                }
             }

        /* if(count($values) != 1025){
            $errors[]="Incorrect number of columns in file: should be 1025, is " . count($values);
             return $errors;
         }*/
          

         
         $visit = $args['visitLabel'];

          $correct_id = $args['candID'] . '-' . substr($args['PSCID'], -4, 4) . '-' . substr($visit, -2, 2);


            
         $values['Date of Report'] = $this->formatDate($values['Date of Report']);

         if(!empty($args['values']['Date_taken']) && !empty($values['Date of Report']) && ($args['values']['Date_taken'] != $values['Date of Report'])){
             $errors[]="Date of administration in the file ({$values['Date of Report']}) does not match the date of administration entered ({$args['values']['Date_taken']})." ;
             return $errors;
           }

          return true;
      }

      /**
      * importFile imports the vineland file into the database.
      *
      * @param     object       $file    A reference to the file object (passed automatically by callFileHandler)
      * @param     assoc_array  $args    The arguments passed to the function they must be:
      *   -
      *
      * @return    bool    $success		if operation succeeded
      * @access    public
      */
      function importFile(&$file, $args){
          $fp=fopen($file->fileInfo['tmp_name'], "r");
          $contents=fread($fp,filesize($file->fileInfo['tmp_name']));
          fclose($fp);

          $values=array(
              'UserID'    =>$args['username'],
              'Status'    =>'assembly',
              'File_type' =>'WIAT_III_SA',
              'File_name' =>$file->getDestinationFilename(),
              'Data_dir'  =>$file->getDestinationDirectory()
          );


          //Cycle through the lines and extract the data
          $lines=explode("\n",$contents);
          $keys = explode("\t", $lines[0]);
          $vals = explode("\t", $lines[1]);
          for($i = 0; $i < count($keys); $i++){
             if (!empty($keys[$i]) && !preg_match("/^\s+$/", $keys[$i])){
               $values[$keys[$i]] = $vals[$i];   
             }
          }

                    
          $values['Date of Report'] = $this->formatDate($values['TEST_DATE']);

          unset($values['Date of Report']);
          
          $db=& Database::singleton();

///Setting trackchanges to false because getting error messages
$db->_trackChanges = false;
////////////////////////////////////////////////////////////////

          $result = $db->update($this->testName, $values, array('CommentID'=>$args['CommentID']));
          return true;
      }

      function formatDate($date){
         if(empty($date)){
            return null;
         }
         $dateBits = explode('/', $date);
         return sprintf("%04d-%02d-%02d", $dateBits[2], $dateBits[0], $dateBits[1]); 
      }

      /**
      * getTargetDirectory retrieves info about where the file should be stored.
      *
      * The returned directory is ADDED to the baseUploadDirectory proprety.  It should have a trailing slash.
      *
      * @param     string  $file    The full filename including directory.
      *
      * @return    bool    $success		if operation succeeded
      * @access    public
      */
      function getTargetDirectory(&$file, $args){
          $output=$args['candID']."/";
          return $output;
      }

      function _setDefaultsArray($vals) {
          $vals['Date_taken_display'] = $vals['Date_taken'];
          return parent::_setDefaultsArray($vals);
      }
    /**
    * Constructs a section (page) of the instrument in a uniform fashion.
    *
    * @param string $prefix Prefix used to identify this section.
    * @param array $questionArray 0-based array containing the text of all section questions.
    * @param array $ageBreaks Suggested age-based start points. 
    * @param array $noOpp Questions where a `No Opportunity` option is presented.
    * @param array $not1 Questions that don't allow the `1) Sometimes` option.
    */
    function _generateSection($prefix, $questionArray, $ageBreaks, $noOpp, $not1) {
        foreach($questionArray as $number=>$label) {
            $answerArray = array(""=>NULL, "2_usually"=>"2) Usually", "1_sometimes"=>"1) Sometimes", "0_never"=>"0) Never", "dont_know"=>"Don't know", "not_answered"=>"Not Answered");
            //$questionArray is 0-indexed, so we add 1 to get the true question number
            if (array_key_exists($number + 1, $ageBreaks)) {
                $this->form->addElement("header", null, $ageBreaks[$number + 1] . " ->");
            }
            if(in_array($number + 1, $noOpp)) {
                $answerArray += array("no_opportunity"=>"No Opportunity");
            }
            if(in_array($number + 1, $not1)) {
                unset($answerArray["1_sometimes"]);
            }
            $this->form->addElement("select", $prefix . ($number + 1), $this->indent . $label, $answerArray);
            
            //Due to age of child, most questions will go unanswered.
            //For now, no question after the first page (except section comments) is required.
            $this->XINRegisterRule($prefix . ($number + 1), array("Examiner{@}=={@}Pee Wee Herman"));
        }

        $this->form->addElement("static", null, "&nbsp;");

        $group[]=&$this->form->createElement("textarea", "{$prefix}comments", null, array('cols'=>60, 'rows'=>6));
        $group[]=&$this->form->createElement("select", "{$prefix}comments" . "_status", "", array(NULL=>'', 'not_answered'=>'Not Answered'));
        $this->form->addGroup($group, "{$prefix}comments" . '_group', "Comments", null, false);
        unset($group);
        $rules_array=array("{$prefix}comments" . '_status{@}=={@}');
        $this->XINRegisterRule("{$prefix}comments", $rules_array, "Please record this section's comments, or mark it as 'Not Answered'.", "{$prefix}comments" . '_group');
    }

    // Based on Mia's vineland_NDAR script from Redmine ticket #2558, this
    // updates the ..._NDAR fields
    function setValueScore($item, $corritem) {
        $db =& Database::singleton();

        $ndar_item = $item . "_NDAR";
        $commentid = $this->getCommentID();

        $record = $db->pSelectRow("select $item, $corritem from " . $this->table . " WHERE CommentID=:cid", array('cid' => $commentid));

        if($record[$corritem] == "") {
            $setvalue = $record[$item];
            $success = $db->update($this->table, array($ndar_item=> $setvalue),
                array('CommentID' => $commentid)
            );
        } else {
            $setvalue = $record[$corritem];
        }
    }

    function scoreNDARGroup($qprefix, $qcorrprefix, $numq) {
        for($i = 1; $i < $numq; $i++) {
            $this->setValueScore($qprefix . $i, $qcorrprefix . $i);
        }
    }

    function score() {
        $sections = array(
            array('Name' => "REC", 'Items' => 21),
            array('Name' => "EXP", 'Items' => 55),
            array('Name' => "WRN", 'Items' => 26),
            array('Name' => "PER", 'Items' => 42),
            array('Name' => "DOM", 'Items' => 25),
            array('Name' => "CMM", 'Items' => 45),
            array('Name' => "IPR", 'Items' => 39),
            array('Name' => "PL", 'Items' => 32),
            array('Name' => "CS", 'Items' => 31),
            array('Name' => "GMS", 'Items' => 41),
            array('Name' => "FMS", 'Items' => 37),
            array('Name' => "INT", 'Items' => 12),
            array('Name' => "EXT", 'Items' => 11),
            array('Name' => "OTH", 'Items' => 16)
        );
        foreach($sections as $section) {
            $this->scoreNDARGroup($section['Name'] . "_ITEM_", 
                $section['Name'] . "_CORRECTED_ITEM_", 
                $section['Items']
            );
        }
    }
}
?>
