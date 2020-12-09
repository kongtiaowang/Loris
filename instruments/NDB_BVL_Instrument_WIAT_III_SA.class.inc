<?php
/*
 * This file contains the NDB_BVL_Instrument_WIAT_III_SA
 * class
 *
 * PHP Version 7
 *
 * @category Instrument
 * @package  Neuropsych
 * @author   Sruthy Mathew <sruthy.mathew@mcgill.ca>
 * @license  http://www.gnu.org/licenses/gpl-3.0.txt GPLv3
 * @link     https://www.github.com/aces/IBIS/
 */

/**
 * Creates the form elements for the WIAT_III_SA instrument
 *
 * @category Instrument
 * @package  Neuropsych
 * @author   Sruthy Mathew <sruthy.mathew@mcgill.ca>
 * @license  http://www.gnu.org/licenses/gpl-3.0.txt GPLv3
 * @link     https://www.github.com/aces/IBIS/
 */


class NDB_BVL_Instrument_WIAT_III_SA extends NDB_BVL_Instrument
{
    use LegacyInstrumentTrait;

    var $ValidityEnabled = false;
    var $ValidityRequired = false;

    //-------------------------------------------------//
    // Definition for section "Subtest Score Summary"  //
    //-------------------------------------------------//
    var $sssSectionDefinition = [
        "ID"      => "SSS",
        "TITLE"   => "Subtest Score Summary",
        "DOMAINS" => [
            "Listening Comprehension"     => "LC",
            "Early Reading Skills"        => "ERS",
            "Reading Comprehension"       => "RC",
            "Math Problem Solving"        => "MPS",
            "Alphabet Writing Fluency"    => "AWF",
            "Sentence Composition"        => "SC",
            "Word Reading"                => "WR",
            "Essay Composition"           => "EC",
            "Pseudoword Decoding"         => "PD",
            "Oral Expression"             => "OE",
            "Numerical Operations"        => "NO",
            "Oral Reading Fluency"        => "ORF",
            "Spelling"                    => "SP",
            "Math Fluency-Addition"       => "MFA",
            "Math Fluency-Subtraction"    => "MFS",
            "Math Fluency-Multiplication" => "MFM",
        ],
        "HEADERS" => [
            "Subtest"                 => null,
            "Raw Score"               => "RAW",
            "Standard Score"          => "STD_SCORE",
            "95% Confidence Interval" => "CI",
            "Percentile Rank"         => "PER_RANK",
            "Normal Curve Equiv."     => "NCE",
            "Stanine"                 => "STANINE",
            "Age Equiv."              => "GRADE_EQUIV",
            "Grade Equiv."            => "AGE_EQUIV",
            "Growth Score"            => "GROWTH"
        ]
    ];

    //--------------------------------------------------------------//
    // Definition for section "Supplemental Subtest Score Summary"  //
    //--------------------------------------------------------------//
    var $ssssSectionDefinition = [
        "ID"      => "SSSS",
        "TITLE"   => "Supplemental Subtest Score Summary",
        "DOMAINS" => [
            "Oral Reading Accuracy" => "ORA",
            "Oral Reading Rate"     => "ORR"
        ],
        "HEADERS" => [
            "Score Name"              => null,
            "Subtest"                 => null,
            "Raw Score"               => "RAW",
            "Standard Score"          => "STD_SCORE",
            "95% Confidence Interval" => "CI",
            "Percentile Rank"         => "PER_RANK",
            "Normal Curve Equiv."     => "NCE",
            "Stanine"                 => "STANINE",
            "Age Equiv."              => "GRADE_EQUIV",
            "Grade Equiv."            => "AGE_EQUIV",
            "Growth Score"            => "GROWTH"
        ]
    ];

    //---------------------------------------------------//
    // Definition for section "Composite Score Summary"  //
    //---------------------------------------------------//
    var $cssSectionDefinition = [
        "ID"      => "CSS",
        "TITLE"   => "Composite Score Summary",
        "DOMAINS" => [
            "Total Reading"                      => "TR",
            "Basic Reading"                      => "BR",
            "Reading Comprehension and Fluency"  => "RCF",
            "Mathematics"                        => "MATH",
            "Math Fluency"                       => "MATHF"
        ],
        "HEADERS" => [
            "Composite"                      => null,
            "Sum of Subtest Standard Scores" => "SUM",
            "Standard Score"                 => "STD_SCORE",
            "95% Confidence Interval"        => "CI",
            "Percentile Rank"                => "PER_RANK",
            "Normal Curve Equiv."            => "NCE",
            "Stanine"                        => "STANINE",
            "Qualitative Description"        => "QUAL"
        ]
    ];

    //-----------------------------------------------------------//
    // Definition for section "Subtest Component Score Summary"  //
    //-----------------------------------------------------------//
    var $scssSectionDefinition = [
        "ID"      => "SCSS",
        "TITLE"   => "Subtest Component Score Summary",
        "DOMAINS" => [
            "Listening Comprehension"        => "LC",
            "Receptive Vocabulary"           => "RV",
            "Oral Discourse Comprehension"   => "ODC",
            "Oral Reading Accuracy"          => "ORA"
        ],
        "HEADERS" => [
            "Subtest Component"           => null,
            "Raw Score"                   => "RAW",
            "Standard Score"              => "STD_SCORE",
            "Percentile Rank"             => "PER_RANK",
            "Normal Curve Equivalent"     => "NCE",
            "Stanine"                     => "STANINE",
            "Qualitative Description"     => "QUAL"
        ]
    ];

    //-----------------------------------//
    // Will contain all the definitions  //
    //-----------------------------------//
    var $sectionDefinitions;

    /**
     * sets up basic data, such as the LorisForm object, and so on.
     *
     * @param string $commentID the CommentID identifying the data to load
     * @param string $page if a multipage form, the page to show
     * @return void
     * @access public
     */
    function setup(?string $commentID = NULL, ?string $page = NULL): void
    {

        $this->formType = "XIN";
        $this->form = new LorisForm('test_form');
        $this->page = $page;

        // set the object properties
        $this->testName = "WIAT_III_SA";           // test_names.Test_name
        $this->table = 'WIAT_III_SA';             // name of table containing

        // data keyed by commentID
        $this->commentID = $commentID;

        // setup the form
        $this->_setupForm();

        $this->sectionDefinitions = [
            $this->sssSectionDefinition,
            $this->ssssSectionDefinition,
            $this->cssSectionDefinition,
            $this->scssSectionDefinition
        ];
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
        if (preg_match(
            "/WIAT_III_SA(_page[0-9]+)/",
            $this->page,
            $matches
        )) {
            call_user_func(array($this, $matches[1]));
        } else {
            $this->_main();
        }
        $this->form->addFormRule(array(&$this, 'XINValidate'));
    }


    function _main()
    {
        //------------------------------------//
        // Examiner & date of administration  //
        //------------------------------------//
        $this->_addMetadataFields();

        //------------------------------------//
        // File upload widget & instructions  //
        //------------------------------------//
        $this->form->addElement(
           'file',
           'wiatIII_file',
           'Upload the WIAT_III file<br><h6><i>(Ex: WIAT_III_SA_PSCID_VSA.txt)</i></h6>'
        );
        $this->form->addElement('static', "File_name", "Uploaded File");
        $this->XINRegisterRule(
            "wiatIII_file",
            array("wiatIII_file{@}=={@}NEVER_REQUIRED")
        );

        //-------------------//
        // All the sections  //
        //-------------------//
        $this->addSection($this->sssSectionDefinition);
        $this->addSection($this->ssssSectionDefinition);
        $this->addSection($this->cssSectionDefinition);
        $this->addSection($this->scssSectionDefinition);

        //-------------------//
        // General comments  //
        //-------------------//
        $this->form->addElement('static', null, "<br /><br />");
        $this->form->addElement("textarea", "other_comments", "Comments:", array('cols'=>25, 'rows'=>4));
        $this->XINRegisterRule("other_comments", array("{other_comments}{@}=={@}NEVER_REQUIRED"));
    }

    /**
     * Adds a given section to the form.
     *
     * @param $sectionDefinition array definition (spec) for the section to add.
     */
    function addSection(array $sectionDefinition) : void
    {
        //-----------------//
        // Section title   //
        //-----------------//
        $this->form->addElement('header', null, $sectionDefinition["TITLE"]);

        //-------------------//
        // Section headers   //
        //-------------------//
        $groupLabel = '';
        foreach ($sectionDefinition["HEADERS"] as $headerText => $headerID) {
            if (!$headerID) {
                $groupLabel = $headerText;
            } else {
                $group[] = $this->form->createElement(
                    'static',
                    null,
                    null,
                    $headerText
                );
            }
        }

        $this->form->addGroup(
                $group,
                "{$sectionDefinition['ID']}_header_group",
                "<strong>$groupLabel</strong>",
                $this->_GUIDelimiter,
                FALSE
            );
        unset($group);

        //---------------------------------//
        // Set of scores for each domain   //
        //---------------------------------//
        foreach ($sectionDefinition["DOMAINS"] as $domainText => $domainID) {
            foreach ($sectionDefinition["HEADERS"] as $headerText => $headerID) {
                if ($headerID) {
                    $group[] = $this->form->createElement(
                        'static',
                        $this->getDbColumn($sectionDefinition, $domainID, $headerID),
                        null,
                        null
                    );
                }
            }

            $this->form->addGroup(
                $group,
                "{$sectionDefinition['ID']}_{$domainID}_group",
                $domainText,
                $this->_GUIDelimiter, FALSE
            );
            unset($group);
        }
    }

    /**
     * Gets the name of the column in table WIAT_III_SA that will contain the
     * score for a given triplet (section, domain, type_of_score).
     *
     * @param $sectionDefinition array definition (spec) for the section to add.
     * @param $domainID          string domain domain for this score.
     * @param $headerID          string domain ID of the header describing the type of score
     *                                  (i.e raw score, 95% perc., etc...)
     */
    function getDbColumn(array $sectionDefinition, string $domainID, string $headerID)
    {
        return "{$sectionDefinition['ID']}_{$domainID}_$headerID";
    }

    /**
     * {@inheritdoc}
     */
    function _saveValues(array $values): void
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
        $file->setBaseUploadDirectory($dir . "/WIAT_III_SA/");

        //Set the prefix to prepend to the filenames
        //$file->setFilenamePrefix($timepoint->getVisitLabel()."-".$this->testName."-");

        //set the the IDs to the handler functions.
        $user =& User::singleton();
        $file->setHandlerArgs(
          array(
            "CommentID"  => $this->getCommentID(),
            "candID"     => $candidate->getCandID(),
            "PSCID"      => $candidate->getPSCID(),
            "visitLabel" => $timepoint->getVisitLabel(),
            "username"   => $user->getUsername(),
            "values"     => $values
          )
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
                    echo "UPLOAD ERROR ($fileType) : $error";
                }
            }
        }
        unset($values['candID'], $values['sessionID'], $values['commentID'], $values['test_name'], $values['page'], $values['fire_away'], $values['subtest'], $values['MAX_FILE_SIZE'], $values['wiatIII_file']);
        parent::_saveValues($values);
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
        $correct_filename = ($this->testName.'_'. $args['PSCID'].'_'.$args['visitLabel']. ".txt");
        if($file->fileInfo['name'] != $correct_filename){
            return [ "Incorrect Filename: Filename should be: $correct_filename" ];
        }

        $fp       = fopen($file->fileInfo['tmp_name'], "r");
        if ($fp === FALSE) {
            return [ "Cannot read file {$file->fileInfo['tmp_name']}" ];
        }
        $contents = fread($fp,filesize($file->fileInfo['tmp_name']));
        fclose($fp);

        //PHI have very old UTF 16 encoding on their file
        if ($contents[0]==chr(0xff) && $contents[1]==chr(0xfe)) {
            $contents = iconv("UTF-16LE", "UTF-8", $contents);
        }
        $contents         = utf8_decode($contents);
        $current_encoding = mb_detect_encoding($contents, 'auto');
        $contents         = iconv($current_encoding, 'UTF-8//IGNORE', $contents);
        $contents         = str_replace("?","-",$contents);

        if (strpos($contents, '>') !== false) {
           $contents = str_replace(">", "higher than ", $contents);
        }

        $lines = preg_split("/\\r\\n|\\r|\\n/", $contents);

        if (strpos($contents,'Student Name') || strpos($contents,'Examinee Name')) {
            $actual_pscid = $args['PSCID'];
            if(!preg_match("/{$actual_pscid}/i", $contents)) {
                return [ "PSCID in the file given doesn't match with the actual PSCID ($actual_pscid)" ];
            }
        } else {
            return [ "Neither Student Name or Examinee Name exist in your txt file. Please check and try again." ];
        }

        //-------------------------------------------------------------------//
        // Search for each section in the file, as if actually importing it. //
        // See if that triggers any error.                                   //
        //-------------------------------------------------------------------//
        $hasOneSection = false;
        foreach ($this->sectionDefinitions as $sectionDefinition) {
            try {
                $sectionHeaders = $this->getSectionHeaders($lines, $sectionDefinition);
                $hasOneSection = $hasOneSection || !empty($sectionHeaders);
                $sectionScores = $this->getSectionScores($lines, $sectionDefinition, $sectionHeaders);
            } catch (LorisException $e) {
                return [ $e->getMessage() ];
            }
        }

        //------------------------------------//
        // Got to have at least one section   //
        //------------------------------------//
        if (!$hasOneSection) {
            return [ "Uploaded file does not contain a valid score section" ];
        }

        return true;
    }

    /**
     * importFile imports the wiatIII file into the database.
     *
     * @param     object       $file    A reference to the file object (passed automatically by callFileHandler)
     * @param     assoc_array  $args    The arguments passed to the function they must be:
     *   -
     *
     * @return    bool    $success		if operation succeeded
     * @access    public
     */
    function importFile(&$file, $args){
        $fp       = fopen($file->fileInfo['tmp_name'], "r");
        $contents = fread($fp,filesize($file->fileInfo['tmp_name']));
        fclose($fp);
        if ($contents[0] == chr(0xff) && $contents[1] == chr(0xfe)) {
            $contents = iconv("UTF-16LE", "UTF-8", $contents);
        }

        $contents         = utf8_decode($contents);
        $current_encoding = mb_detect_encoding($contents, 'auto');
        $contents         = iconv($current_encoding, 'UTF-8//IGNORE', $contents);
        $contents         = str_replace("?","-",$contents);

        if (strpos($contents, '>') !== false) {
           $contents = str_replace(">","higher than ",$contents);
        }

        //Cycle through the lines and extract the data
        $lines = preg_split("/\\r\\n|\\r|\\n/", $contents);

        $values = [
            'UserID'    => $args['username'],
            'File_name' => $file->getDestinationFilename(),
            'Data_dir'  =>$file->getDestinationDirectory()
        ];

        //------------------------------------------------//
        // Get the headers and scores for each section    //
        //------------------------------------------------//
        foreach ($this->sectionDefinitions as $sectionDefinition) {
            $sectionHeaders = $this->getSectionHeaders($lines, $sectionDefinition);
            $sectionScores  = $this->getSectionScores($lines, $sectionDefinition, $sectionHeaders);
            $values         = array_merge($values, $sectionScores);
        }

        //---------------------------------//
        // Save everything in the database //
        //---------------------------------//
        $db=& Database::singleton();

        // Setting trackchanges to false because getting error messages
        $db->_trackChanges = false;
        $db->update($this->testName, $values, array('CommentID'=>$args['CommentID']));

        return true;
    }

    /**
     * Get the headers found in the file for a given section. Note all section headers
     * are mandatory and they can appear in any order.
     *
     * @param $lines             array all the lines of the file.
     * @param $sectionDefinition array definition (spec) for the section.
     *
     * @return array the ID of the headers found (key) with the line index at which
     *               the header stops (Note: headers can span multiple lines. For example
     *               header with ID RAW might start on line 100 and end on line 101, so
     *               if array $r is the return value of a call to this function, we'll have
     *               $r['RAW'] == 101).
     */
    function getSectionHeaders(array $lines, array $sectionDefinition) : array
    {
        // Find index of line containing the section title
        $sectionTitleIdx = array_search($sectionDefinition["TITLE"], $lines);
        if ($sectionTitleIdx === FALSE) {
            return [];
        }

        // Check the lines, starting at $sectionTitleIdx+1
        $sectionHeaders       = [];
        $currentHeader = '';
        for ($i=$sectionTitleIdx+1; $i < count($lines); $i++) {
            $curLine = trim($lines[$i]);

            // Blank lines are ignored
            if ($curLine != '') {
                // Since headers can span multiple lines we append the curent line to the
                // current header value
                $currentHeader = $currentHeader ? "$currentHeader $curLine" : $curLine;

                // If we hit one of the domain identifiers, then we have gone far enough:
                // we are right at the start of the scores section
                if (in_array($currentHeader, array_keys($sectionDefinition["DOMAINS"]))) {
                    $currentHeader = '';
                    break;
                }
 
                // If its a header know to us
                if (in_array($currentHeader, array_keys($sectionDefinition["HEADERS"]))) {
                    $headerID = $sectionDefinition["HEADERS"][$currentHeader];

                    // If $headerID is null, then this header is the label for the column
                    // containing the domain text. We only store the header of columns that
                    // contain actual scores so we skip this
                    if ($headerID) {
                        $sectionHeaders[$headerID] = $i;
                    }
                    $currentHeader = '';
                }
            }
        }

        // If $currentHeader is not '', then there's some unknown header in the file
        if ($currentHeader != '') {
            throw new LorisException("Unexpected header for section {$sectionDefinition['TITLE']}: $currentHeader");
        }

        // If we found the section title but no headers, then we report an error 
        if (empty($sectionHeaders)) {
            throw new LorisException("No headers found for section {$sectionDefinition['TITLE']}");
        }

        return $sectionHeaders;
    }

    /**
     * Gets the scores contained in the file for a given section.
     *
     * @param $lines             array all the lines of the file.
     * @param $sectionDefinition array definition (spec) for the section.
     * @param $sectionHeaders    array the ID of the headers found (key) with the line index at
     *                                 which the header stops (Note: headers can span multiple lines.
     *                                 For example header with ID RAW might start on line 100 and end
     *                                 on line 101, so if array $r is the return value of a call to
     *                                 this function, we'll have $r['RAW'] == 101).
     * @return array hash for the section scores. Key: database column name in which the score will go.
     *               Value: the score value.
     */
    function getSectionScores(array $lines, array $sectionDefinition, array $sectionHeaders) : array
    {
        //----------------------------------//
        // Initialize all scores to '--'    //
        //----------------------------------//
        $scores = [];
        foreach ($sectionDefinition["DOMAINS"] as $domainText => $domainID) {
            foreach ($sectionDefinition["HEADERS"] as $headerText => $headerID) {
                if ($headerID) {
                    $dbColumn = $this->getDbColumn($sectionDefinition, $domainID, $headerID);
                    $scores[$dbColumn] = "--";
                }
            }
        }

        //---------------------------------------------------------------------------//
        // If $sectionHeaders is empty, then the section does not exist in the file: //
        // return the default scores.                                                //
        //---------------------------------------------------------------------------//
        if (empty($sectionHeaders)) {
            return $scores;
        }

        $lastHeaderIdx = max(array_values($sectionHeaders));
        $currentLineIdx = $lastHeaderIdx+1;
        $currentDomain = '';
        while ($currentLineIdx < count($lines)) {
            $line = trim($lines[$currentLineIdx]);
            if ($line == '') {
                $currentLineIdx++;
                continue;
            }

            // If we hit a line that indicates the section's end.
            if ($this->isSectionEnd($line)) {
                break;
            }

            // Since a domain can span multiple lines, we append the current line to the
            // current domain
            $currentDomain = $currentDomain == '' ? $line : "$currentDomain $line";

            // If it's a domain know to us
            if (isset($sectionDefinition["DOMAINS"][$currentDomain])) {
                $domainID = $sectionDefinition["DOMAINS"][$currentDomain];
                // Get all scores for the given domain
                foreach ($sectionHeaders as $headerID => $headerIdx) {
                    $this->splitLineIfNeeded($lines, $currentLineIdx, $sectionDefinition["DOMAINS"]);
                    $dbColumn = $this->getDbColumn($sectionDefinition, $domainID, $headerID);
                    $score = $lines[++$currentLineIdx];
                    // If the score is '', we leave it to its default value
                    if ($score != '') {
                        $scores[$dbColumn] = $score;
                    }
                }
                $currentDomain = '';
            }

            $currentLineIdx++;
        }

        // If $currentDomain != '', then we parsed an unknown domain
        if ($currentDomain != '') {
            throw new LorisException("Invalid domain found $currentDomain\n");
        }

        return $scores;
    }

    /**
     * Determines if a line is used to signal the end of a section.
     *
     * @param $line string line to examine.
     *
     * @return bool true if the line is used to signal the end of a section, false otherwise.
     */
    function isSectionEnd(string $line)
    {
        return preg_match("/Indicates a/", $line)
            || preg_match("/End of Report/", $line)
            || $line == 'Subtest Score Summary'
            || $line == 'Supplemental Subtest Score Summary'
            || $line == 'Composite Score Summary'
            || $line == 'Composite Score Profile'
            || preg_match("/Differences Between Composite Standard Scores/", $line)
            || preg_match("/WIAT-III INTERVENTION GOAL STATEMENTS REPORT/", $line);
    }

    /**
     * Determines if a given line needs to be split in two or not. In some cases, there
     * might be a line containing both a score and a domain name, as in
     * "500Listening Comprehension". This function will split the preceeding line in two
     * ("500" and "Listening Comprehension") as scores and domain text are expected to be
     * on different lines by the parsing algorithms in this class.
     *
     * @param $lines          array all the lines for the uploaded file.
     * @param $currentLineIdx int   index of the line to check.
     * @param $domains        array domains for the current section.
     */
    function splitLineIfNeeded(array &$lines, int $currentLineIdx, array $domains) : void
    {
        $scoreIdx = $currentLineIdx+1;

        // Negative scores do not exist. If we find what appears to be a negative number, it
        // is in effect an unspecified score ("-") for a given score type followed by a
        // numerical score for a different score type (yuk...)
        if (preg_match("/^(-)(.+)$/", $lines[$scoreIdx], $matches)) {
            array_splice($lines, $scoreIdx, 1, [$matches[1], $matches[2]] );
            return;
        }

        foreach (array_keys($domains) as $domainText) {
            $domainTextPos = strpos($lines[$scoreIdx], $domainText);
            // If the domain text is not all by itself on a line, then we put whatever
            // preceeds it on another line
            if ($domainTextPos !== FALSE && $domainTextPos > 0) {
                array_splice(
                    $lines,
                    $scoreIdx,
                    1,
                    [
                      substr($lines[$scoreIdx], 0, $domainTextPos),
                      substr($lines[$scoreIdx], $domainTextPos)
                    ]
                );
                return;
            }
        }
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
}
