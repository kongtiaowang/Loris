<?php
/**
 *
 * @category Instrument
 * @author   Gregory Luneau <gluneau.mcin@gmail.com>
 * @license  http://www.gnu.org/licenses/gpl-3.0.txt GPLv3
 * @link     https://www.github.com/aces/IBIS/
 */

/**
 * Creates the form elements for the ABC instrument
 *
 * @category Instrument
 * @author   Gregory Luneau <gluneau.mcin@gmail.com>
 * @license  http://www.gnu.org/licenses/gpl-3.0.txt GPLv3
 * @link     https://www.github.com/aces/IBIS/
 */
class NDB_BVL_Instrument_DTIprep extends NDB_BVL_Instrument
{

    /**
     * Sets up basic data, such as the LorisForm object, and so on.
     *
     * @param  string $commentID the CommentID identifying the data to load
     * @param  string $page      if a multipage form, the page to show
     * @return void
     * @access public
     */
    function setup($commentID = null, $page = null)
    {
        $this->formType = 'XIN';
        $this->form     = new LorisForm('test_form');
        $this->page     = $page; // page label (number or string - used by user-defined child classes)

        // set the object properties
        $this->testName  = 'dtiprep'; // test_names.Test_name
        $this->table     = 'dtiprep'; // name of database table corresponding to instrument
        $this->commentID = $commentID; // data keyed by commentID

        $config            = NDB_Config::singleton();
        $this->dateOptions = array(
                              'language'         => 'en',
                              'format'           => 'YMd',
                              'minYear'          => $config->getSetting('startYear'),
                              'maxYear'          => $config->getSetting('endYear'),
                              'addEmptyOption'   => true,
                              'emptyOptionValue' => null,
                             );

        // $candidate = Candidate::singleton($commentID);
        // $this->centerID = $candidate->getData('CenterID');
        // $this->siteName = Site::singleton($this->centerID)->getCenterName();

        $this->fullaverage = array(
                              "ALIC_L",
                              "ALIC_R",
                              "Arcuate_L",
                              "Arcuate_L_temporofrontal",
                              "Arcuate_L_temporoparietal",
                              "Arcuate_R",
                              "Arcuate_R_frontoparietal",
                              "ATR_L",
                              "ATR_R",
                              "CCbody",
                              "CCGenu",
                              "CCSec1",
                              "CCSec2",
                              "CCSec3",
                              "CCSec4",
                              "CCSec5a",
                              "CCSec5b",
                              "CCSplenium",
                              "Cingulum_L",
                              "Cingulum_R",
                              "CST_L",
                              "CST_R",
                              "Fornix_column",
                              "IFOF_L",
                              "IFOF_R",
                              "ILF_L",
                              "ILF_R",
                              "MCP",
                              "PCT",
                              "SCP_L",
                              "SCP_R",
                              "Uncinate_L",
                              "Uncinate_R",
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
        //determine page to display
        if (preg_match("/dtiprep(_page[0-9]+)/", $this->page, $matches)) {
            call_user_func(array($this, $matches[1]));
        } else {
            $this->_main();
        }

        //Defines the call back function for LorisForm to use when validating the form.
        //$this->form->addFormRule(array(&$this, 'XINValidate'));
    }

    /**
     * generates the main page of the form.
     *
     * @return void
     * @access private
     */
    function _main()
    {
        $this->form->addElement('header', 'instrument_title_main', "DTIPrep and DTI Processing Output");

        $filetype = array(
                     'ad' => "Full Average AD",
                     'fa' => "Full Average FA",
                     'md' => "Full Average MD",
                     'rd' => "Full Average RD",
                    );
        $group[]  = $this->form->createElement("select", "filetype", "", $filetype);
        $this->XINRegisterRule("filetype", array("code{@}=={@}"), "Required.", "filetype_group");
        $this->form->addGroup($group, "filetype_group", "Select the right file type you are loading", null, false);
        unset($group);

        $this->form->addElement('file', 'dtiprep_file', 'Upload the dtiprep file');
        $this->form->addElement('static', "File_name", "Last Uploaded File");

    }

    function _page1()
    {
        $this->form->addElement('header', 'instrument_title_page1', "Full Average AD");

        foreach ($this->fullaverage as $value) {
            $this->form->addElement('static', $value . '_ad', '<strong>'. $value . '_ad:</strong>');
        }
    }

    function _page2()
    {
        $this->form->addElement('header', 'instrument_title_page2', "Full Average FA");

        foreach ($this->fullaverage as $value) {
            $this->form->addElement('static', $value . '_fa', '<strong>'. $value . '_fa:</strong>');
        }
    }

    function _page3()
    {
        $this->form->addElement('header', 'instrument_title_page3', "Full Average MD");

        foreach ($this->fullaverage as $value) {
            $this->form->addElement('static', $value . '_md', '<strong>'. $value . '_md:</strong>');
        }
    }

    function _page4()
    {
        $this->form->addElement('header', 'instrument_title_page4', "Full Average RD");

        foreach ($this->fullaverage as $value) {
            $this->form->addElement('static', $value . '_rd', '<strong>'. $value . '_rd:</strong>');
        }
    }

    // methods available to all children
    /**
     * preprocesses the array of values to be saved into the database
     * (such as to rearrange date fields)
     *
     * @param  array $values the array of values ready to be passed to an Database::update call as the set array
     * an Database::update call as the set array
     * @return void
     * @access private
     */
    function _saveValues($values)
    {
        $timepoint = TimePoint::singleton($this->getSessionID());
        $candidate = Candidate::singleton($timepoint->getCandID());

        if (isset($values['Date_taken'])) {
            $this->_saveCandidateAge($values);
        }

        include_once "File_Upload.class.inc";
        $file = new File_Upload;

        //pass the existing form ($form) by reference to File_Upload, and register the file_upload field names being used.
        $file->registerForm($this->form);

        //Tell File_Upload what file handlers to use.
        $file->setFileHandler("dtiprep_file", $this);

        //Set the target directory that you want files moved into once they are validated and processed.
        $config = NDB_Config::singleton();
        $dir    = $config->getSetting("UploadDir");
        if (empty($dir)) {
            $dir = ".";
        };
        $file->setBaseUploadDirectory($dir . "/dtiprep/");

        //Set the prefix to prepend to the filenames
        //$file->setFilenamePrefix($timepoint->getVisitLabel()."-".$this->testName."-");

        //set the the IDs to the handler functions.
        $user = User::singleton();
        $file->setHandlerArgs(
            array(
             "CommentID"  => $this->getCommentID(),
             "candID"     => $candidate->getCandID(),
             "PSCID"      => $candidate->getPSCID(),
             "visitLabel" => $timepoint->getVisitLabel(),
             "username"   => $user->getUsername(),
             "filetype"   => $values['filetype'],
             "values"     => $values,
            )
        );

        //If the form is validated, call File_Upload::processFiles() which loops through the files and
        //proccesses them (including verify, move, and import steps)
        if ($values['dtiprep_file']['name'] != false) {
            $file->processFiles();
        }

        //echo error messages
        if (!empty($file->errorLog)) {
            while (list($fileType,$fileErrors)=each($file->errorLog)) {
                foreach ($fileErrors AS $error) {
                    echo "<span style='color:red'><b>Upload Error</b> " .
                    "$fileType: $error</span><br>";
                }
            }
        }
        unset(
            $values['candID'],
            $values['sessionID'],
            $values['commentID'],
            $values['test_name'],
            $values['page'],
            $values['fire_away'],
            $values['subtest'],
            $values['MAX_FILE_SIZE'],
            $values['dtiprep_file']
        );
        $this->_save($values);
    }

    /**
    * isValid checks the validity of the file.
    *
    * @param string $file The full filename including directory.
    *
    * @return bool    $success        if operation succeeded
    * @access public
    */
    function isValid(&$file, $args)
    {
        $objPHPExcel = PHPExcel_IOFactory::load($file->fileInfo['tmp_name']);
        $sheetData   = $objPHPExcel->getActiveSheet()->toArray(
            null,
            true,
            true,
            true
        );
        $SheetCount  = $objPHPExcel->getSheetCount();
        $sheet       = $objPHPExcel->getSheet(0);
        $highestRow  = $sheet->getHighestRow();
        $highestCol  = $sheet->getHighestColumn();
        $headings    = $sheet->rangeToArray(
            'A1:' . $highestCol . 1,
            null,
            true,
            false
        );

        if (strrpos(
            $file->fileInfo['name'],
            "_" . $args['filetype'] . ".xlsx"
        ) != strlen(
            $file->fileInfo['name']
        ) - strlen(
            "_" . $args['filetype'] . ".xlsx"
        )) {
             $errors[] = "Incorrect Filename: Your filename should end with: '_" .
             $args['filetype'] . ".xlsx' or you should change the file type";
             return $errors;
        }

        if ($SheetCount > 1) {
             $errors[] = "You have more than one worksheet";
             return $errors;
        }

        $org_hdr = array(
                    (array_merge(
                        array(
                         "subjectID",
                         "CandID",
                         "Visit_label",
                        ),
                        $this->fullaverage
                    )),
                   );

        if ($headings !== $org_hdr) {
            $errors[] = "Incorrect columns in file, we expect this: " .
            implode(
                ", ",
                (array_merge(
                    array(
                     "subjectID",
                     "CandID",
                     "Visit_label",
                    ),
                    $this->fullaverage
                ))
            );
            return $errors;
        }

            return true;
    }

    /**
    * importFile imports the dtiprep file into the database.
    *
    * @param object      $file A reference to the file object (passed automatically by callFileHandler)
    * @param assoc_array $args The arguments passed to the function they must be: - -
    *   -
    *
    * @return bool    $success        if operation succeeded
    * @access public
    */
    function importFile(&$file, $args)
    {
        $db =& Database::singleton();

        $objPHPExcel = PHPExcel_IOFactory::load($file->fileInfo['tmp_name']);
        $sheetData   = $objPHPExcel->getActiveSheet()->toArray(
            null,
            true,
            true,
            true
        );
        $SheetCount  = $objPHPExcel->getSheetCount();
        $sheet       = $objPHPExcel->getSheet(0);
        $highestRow  = $sheet->getHighestRow();
        $highestCol  = $sheet->getHighestColumn();
        $headings    = $sheet->rangeToArray(
            'A1:' . $highestCol . 1,
            null,
            true,
            false
        );

        $firstrow = true;
        foreach ($sheetData as $row) {
            // var_dump($row);
            if ($firstrow) {
                $firstrow = false;
            } else {
                // Data for everyone
                $values = array_combine(
                    array_merge(
                        array(
                         "File_name",
                         "CandID",
                         "Visit_label",
                        ),
                        preg_filter(
                            '/$/',
                            '_' . $args['filetype'],
                            $this->fullaverage
                        )
                    ),
                    $row
                );

                //var_dump($values);
                $commentid = $db->pselectOne(
                    "select f.CommentID from flag as f
                  left join `session` as s on f.SessionID=s.ID
                  WHERE s.Visit_label=:visla and s.CandID=:canid 
                  and f.Test_name=:tesna and f.CommentID not like 'DDE_%'",
                    array(
                     'visla' => $values['Visit_label'],
                     'canid' => $values['CandID'],
                     'tesna' => $this->testName,
                    )
                );

                if (!empty($commentid)) {
                    unset($values['CandID'], $values['Visit_label']);

                    $result = $db->update(
                        $this->testName,
                        $values,
                        array('CommentID' => $commentid)
                    );
                } else {
                    $errors[] = "No CommentID for {$values['Visit_label']} " .
                      "{$values['CandID']}";
                }

            }
        }

        /*
        $fp=fopen($file->fileInfo['tmp_name'], "r");
        $contents=fread($fp,filesize($file->fileInfo['tmp_name']));
        fclose($fp);

        $values=array(
            'UserID'    =>$args['username'],
            'Status'    =>'assembly',
            'File_type' =>'dtiprep',
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

        if (empty($values['ABC_95%_CI'])){
           $values['ABC_95%_CI'] = '';
        }

        if (empty($values['ABC_90%_CI'])){
            $values['ABC_90%_CI'] = '';
         }

         if (empty($values['ABC_85%_CI'])){
              $values['ABC_85%_CI'] = '';
          }

        $values['TEST_DATE'] = $this->formatDate($values['TEST_DATE']);
        $values['BIRTH_DATE'] = $this->formatDate($values['BIRTH_DATE']);
        $values['INTEL_TEST_DATE'] = $this->formatDate($values['INTEL_TEST_DATE']);

        unset($values['EXAMINER']);
        unset($values['TEST_DATE']);

        $db=& Database::singleton();

        ///Setting trackchanges to false because getting error messages
        $db->_trackChanges = false;
        ////////////////////////////////////////////////////////////////

        $result = $db->update($this->testName, $values,
        array('CommentID'=>$args['CommentID']));
        */

        if (!empty($errors)) {
            return $errors;
        } else {
            return true;
        }
    }

    /**
    * getTargetDirectory retrieves info about where the file should be stored.
    *
    * The returned directory is ADDED to the baseUploadDirectory proprety.
    * It should have a trailing slash.
    *
    * @param string $file The full filename including directory.
    *
    * @return bool    $success        if operation succeeded
    * @access public
    */
    function getTargetDirectory(&$file, $args)
    {
        $output = "";
        return $output;
    }
}

