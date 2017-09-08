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
        if (preg_match("/". $this->testName ."(_page[0-9]+)/", $this->page, $matches)) {
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
     */
    function _main()
    {
        // Permissions?
        $record =array();
        $db     =& Database::singleton();
        $query  = "SELECT * FROM ".$this->table." WHERE CommentID='".$this->getCommentID()."'";
        $record = $db->pselectRow($query, array());

        $this->form->addElement('header', 'instrument_title_main', "DTIPrep and DTI Processing Output");

        $filetype = array(
                     'ad' => "Full Average AD",
                     'fa' => "Full Average FA",
                     'md' => "Full Average MD",
                     'rd' => "Full Average RD",
                    );

        $this->form->addElement('select', 'filetype', 'Select the right file type you are loading', $filetype);
        $this->form->addElement('file', 'dtiprep_file', 'Upload the dtiprep file');
        $this->form->addElement('static', 'File_name', 'Last Uploaded File');
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

        $SheetCount = $objPHPExcel->getSheetCount();
        $sheet      = $objPHPExcel->getSheet(0);
        $highestRow = $sheet->getHighestRow();
        $highestCol = $sheet->getHighestColumn();
        $headings   = $sheet->rangeToArray(
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
            $errors[] = "Incorrect columns in file, we expect this: \n" .
            serialize($org_hdr) . "\n and got this: \n" .
            serialize($headings);
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
            // Handling case where the first row are the headers
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

                // Update all of the data found
                if (!empty($commentid)) {
                    unset($values['CandID'], $values['Visit_label']);

                    // Check if the File_name has changed if it is not null
                    $File_name = $db->pselectOne(
                        "select i.File_name from ". $this->testName ." as i
                      WHERE i.CommentID = :comid",
                        array('comid' => $commentid)
                    );

                    // Handling of conflicts of different DTI file result
                    if ($File_name != null && $File_name != $values['File_name']) {
                        $errors[] = "Conflict: A different DTI file result! \n" .
                        "In   db: {$File_name}\n" .
                        "In file: {$values['File_name']}\n";
                        return $errors;
                    }

                    $result = $db->update(
                        $this->testName,
                        $values,
                        array('CommentID' => $commentid)
                    );
                } else {
                    // Handling case of the last line "Atlas"
                    if ($values['File_name'] != "Atlas") {
                        $errors[] = "No CommentID for {$values['Visit_label']} " .
                        "{$values['CandID']}\n";
                    }
                }

            }
        }

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

