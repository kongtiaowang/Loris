<?php
/**
 * This file contains the NDB_BVL_Instrument_LENA_LanguageSampleActivityLog class
 *
 * PHP Version 7
 *
 * @category Instrument
 * @package  IBIS
 * @author   Suzanne Lee <suzannelee.mcin@gmail.com>
 * @license  http://www.gnu.org/licenses/gpl-3.0.txt GPLv3
 * @link     https://www.github.com/aces/IBIS/
 */

/**
 * Creates the form elements for the LENA_LanguageSampleActivityLog instrument
 *
 * @category Instrument
 * @package  Neuropsych
 * @author   Suzanne Lee <suzannelee.mcin@gmail.com>
 * @license  http://www.gnu.org/licenses/gpl-3.0.txt GPLv3
 * @link     https://www.github.com/aces/IBIS/
 */
class NDB_BVL_Instrument_LENA_LanguageSampleActivityLog extends NDB_BVL_Instrument
{
    use LegacyInstrumentTrait;
    use instrument_validator;

    static $FILE_FIELDS = array(
        'its_file'        => [
                              'required' => 0,
                              'page'     => '',
                              'name'     => 'LENA_CandID_PSCID_VisitLabel.its',
                             ],
        'upl_file' => [
                              'required' => 0,
                              'page'     => '',
                              'name'     => 'LENA_CandID_PSCID_VisitLabel.upl',
                             ],
        'wav_file' => [
                                'required' => 0,
                                'page'     => '',
                                'name'     => 'LENA_CandID_PSCID_VisitLabel.wav/.mp3',
                               ],
       );
    /**
     * Sample SQL statement for test_names table and instrument subtests table
     *
     * INSERT INTO test_names (Test_name, Full_name, Sub_Group, isDirectEntry) VALUES ('LENA_LanguageSampleActivityLog', "LENA Language Sample Activity Log Form", 1, 0);
     * INSERT INTO instrument_subtests (Test_name, Subtest_name, Description, Order_number) VALUES ('LENA_LanguageSampleActivityLog','LENA_LanguageSampleActivityLog_page1', "Page 1", 1);
     */

    /**
     * Sets up basic data, such as the LorisForm object, and so on.
     *
     * @param string $commentID the CommentID identifying the data to load
     * @param string $page      if a multipage form, the page to show
     *
     * @return void
     * @access public
     */
    function setup(?string $commentID = NULL, ?string $page = NULL): void
    {
        $this->formType = "XIN";
        $this->form     = new LorisForm('LENA_LanguageSampleActivityLog_form');
        $this->page     = $page;            // page label (number or
        // string - used by
        // user-defined child classes)

        // set the object properties
        $this->testName = "LENA_LanguageSampleActivityLog";           // test_names.Test_name
        $this->table    = 'LENA_LanguageSampleActivityLog';           // name of database table corresponding to instrument
        // data keyed by commentID
        $this->commentID = $commentID;

        //The array of dates/timestamps to convert to database dates/timestamps
        //Any LorisForm date elements must be listed here
        $this->dateTimeFields =array("Date_taken");

        //The array of selects with multiple answers allowed
        //Any LorisForm multiple selects must be listed here
        $this->selectMultipleElements = array();

        // required fields for data entry completion status
        $this->_requiredElements = array("todays_date");

        // setup the form
        $this->_setupForm();
    }

    //If the instrument is not paged, remove the switch from the _setupForm method and add all the form Elements in this function.

    /**
    * Method to build the LorisForm object into a paged form
    *
    * @return void
    * @access private
    */
    function _setupForm()
    {
        if (preg_match("/LENA_LanguageSampleActivityLog(_page[0-9]+)/", $this->page, $matches)) {
            call_user_func(array($this, $matches[1]));
        } else {
            $this->_main();
        }

        //Defines the call back function for HTML Quickform to use when validating the form.
        $this->form->addFormRule(array(&$this, 'XINValidate'));
        $this->form->addFormRule(array(&$this, 'lena_rules'));
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
        $this->addHeader("LENA Language Sample Activity Log Form");

        $this->_addMetadataFields();

        $this->addBasicDate('Date_taken', 'Date of Administration', $this->dateOptions);

	$this->form->addElement("static", null, "<br><br>");

	$this->form->addElement('file', 'its_file_lena', 'Upload the .its file
        <br><h6><i>(Ex: Filename should be LENA_CandID_PSCID_VisitLabel.its)</i></h6>');
        $this->XINRegisterRule("its_file_lena", array("its_file_lena{@}=={@}NEVER_REQUIRED"));
        $this->form->addElement('static', "its_file", "Uploaded File");

        $this->form->addElement('file', 'upl_file_lena', 'Upload the .upl file
        <br><h6><i>(Ex: Filename should be LENA_CandID_PSCID_VisitLabel.upl)</i></h6>');
        $this->XINRegisterRule("upl_file_lena", array("upl_file_lena{@}=={@}NEVER_REQUIRED"));
        $this->form->addElement('static', "upl_file", "Uploaded File");

        $this->form->addElement('file', 'wav_file_lena', 'Upload the .wav/.mp3 file
        <br><h6><i>(Ex: Filename should be LENA_CandID_PSCID_VisitLabel.wav/.mp3)</i></h6>');
        $this->XINRegisterRule("wav_file_lena", array("wav_file_lena{@}=={@}NEVER_REQUIRED"));
        $this->form->addElement('static', "wav_file", "Uploaded File");
    }

    /**
    * Generates the first page of the form.
    *
    * @return void
    */
    function _page1()
    {
        $this->addHeader("LENA Language Sample Activity Log Form");

        // Instructions
        $this->form->addElement(
            'static',
            null,
            "Dear Parent/Legal Guardian: Please complete this form and return with LENA materials."
        );

        $this->form->addElement("static", null, "<br><br>");

        $this->addBasicDate('todays_date', 'Today’s Date:', $this->dateOptions);

        $this->form->addElement('text', 'pg1_recorder_number','Recorder Number');
	$this->XINRegisterRule('pg1_recorder_number', array("pg1_recorder_number{@}=={@}NEVER_REQUIRED"), 'Not Required');

        $hour_options = array(null => "");

        $minute_options = array(null => "");

        $period_options = array(
                           null => "",
                           "am" => "AM",
                           "pm" => "PM",
                          );

        // populates hour_options array
        for ($i = 1; $i <= 12; $i++) {
            $hour_options[$i] = strval($i);
        }

        // populates minute_options array
        for ($i = 0; $i < 60; $i++) {
            if ($i < 10) {
                $minute_options[$i] = "0" . strval($i);
            } else {
                $minute_options[$i] = strval($i);
            }
        }

	$group[] = $this->form->createElement('select',"pg1_hour_timestamp","Hour:", $hour_options);
	$group[] = $this->form->createElement('select',"pg1_minute_timestamp","Minute:", $minute_options);
        $group[] = $this->form->createElement('select',"pg1_period_timestamp","AM/PM:", $period_options);
        $this->form->addGroup($group, "pg1_timestamp_group", "Timestamp:",null, false);
	unset($group);

        $this->form->addElement(
            'static',
            null,
            "Time Language Sample Started:"
        );

        $this->addSelect("time_language_sample_started_hour", $this->indent . "Hour:", $hour_options);
        $this->addSelect("time_language_sample_started_minute", $this->indent . "Minute:", $minute_options);
        $this->addSelect("time_language_sample_started_period", $this->indent . "AM/PM:", $period_options);

        $this->form->addElement("static", null, "<br><br>");

        $yes_no_options = array(
                           null  => "",
                           "yes" => "Yes",
                           "no"  => "No",
                          );

        $this->addSelect("did_you_do_free_play_session_today", "Did you do a Free Play Session Today?", $yes_no_options);

        $this->form->addElement(
            'static',
            null,
            $this->indent . "If yes, what time?"
        );

        $this->addSelect("free_play_session_time_specify_hour", $this->indent . "Hour:", $hour_options);
        $this->addSelect("free_play_session_time_specify_minute", $this->indent . "Minute:", $minute_options);
        $this->addSelect("free_play_session_time_specify_period", $this->indent . "AM/PM:", $period_options);

        $this->XINRegisterRule('free_play_session_time_specify_hour', array('did_you_do_free_play_session_today{@}=={@}yes'), 'Required.');
        $this->XINRegisterRule('free_play_session_time_specify_minute', array('did_you_do_free_play_session_today{@}=={@}yes'), 'Required.');
        $this->XINRegisterRule('free_play_session_time_specify_period', array('did_you_do_free_play_session_today{@}=={@}yes'), 'Required.');

        $feeling_options = array(
                            null   => "",
                            "well" => "Well",
                            "sick" => "Sick",
                           );

        $this->addSelect("how_is_child_feeling_today", "How is your child feeling today?", $feeling_options);

        $this->form->addElement('text', 'feeling_sick_specify', $this->indent . 'If sick, what illness?');

        $this->XINRegisterRule('feeling_sick_specify', array('how_is_child_feeling_today{@}=={@}sick'), 'Required if child is feeling sick');

        $this->form->addElement("static", null, "<br><br>");

        $talk_time_rating = array(
                             null                          => "",
                             "1_less_talkative_than_usual" => "1 = Less talkative than usual",
                             "2"                           => "2 = A little less talkative than usual",
                             "3_typical_normal"            => "3 = Typical/Normal",
                             "4"                           => "4 = A little more talkative than usual",
                             "5_more_talkative_than_usual" => "5 = More talkative than usual",
                            );

        $this->addSelect("how_would_you_rate_today_amount_of_parent_child_talk_time", "How would you rate today in terms of amount of parent-child talk time?", $talk_time_rating);

	$this->form->addElement("static", null, "<br><br>");

        $this->form->addElement("static", null, "How many children under the age of 18 are living in the home right now and what are their ages?");

        $group[] =& $this->form->createElement("static", null, null, "Age");
        $group[] =& $this->form->createElement("static", null, null, "Lives in the Home");
        $this->form->addGroup($group, "section_headers_group", "Child", $this->_GUIDelimiter, false);
        unset($group);

	for($i=1;$i<5;$i++){
        $group[] =& $this->form->createElement("text", "age{$i}", null,null);
	$group[] =& $this->form->createElement("select", "lives_home{$i}", null, array(null => '', "full_time" => "Full Time", "part_time" => "Part Time"));
	$this->XINRegisterRule("age{$i}", array("age{$i}{@}=={@}never_required"), 'Not Required');
	$this->XINRegisterRule("lives_home{$i}", array("lives_home{$i}{@}=={@}never_required"), 'Not Required');
        $this->form->addGroup($group, "child{$i}", "Child{$i}", $this->_GUIDelimiter, false);
        unset($group);
	}

        $this->form->addElement("static", null, "<br><br>");

        $language_options = array(
                             null      => "",
                             "english" => "English",
                             "other"   => "Other (Specify)",
                            );

        $this->addSelect("primary_language", "What is the primary language spoken in the home?", $language_options);

        $this->form->addElement('text', 'primary_language_specify', $this->indent . 'If other, specify:');

        $this->XINRegisterRule('primary_language_specify', array('primary_language{@}=={@}other'), 'Required if other language.');

        $this->form->addElement("static", null, "<br><br>");
        
	$child_care_questionnaire_labels = array(
                                           "pg2_in_home_cared"     => "In home: Cared for by Parents",
                                           "in_home_family_member" => "In home: Family member other than parent  (e.g., grandparents, aunt)",
                                           "in_home_nanny"         => "In home: Nanny",
					   "in_home_non_family"    => "In home: Non-family (e.g., private daycare run out of home)",
					   "center_based"          => "Center-based",
				   );
                                           					   

        $days_per_week_options = array(
                                  null => "",
                                  0    => "0",
                                  1    => "1",
                                  2    => "2",
                                  3    => "3",
                                  4    => "4",
                                  5    => "5",
                                  6    => "6",
                                  7    => "7",
                                 );

        $hours_per_day_options = array(null => "");

        for ($i = 0; $i <= 24; $i++) {
            $hours_per_day_options[$i] = strval($i);
        }

        $group[] =& $this->form->createElement("static", null, null, "CHILD CARE QUESTIONNAIRE");
        $group[] =& $this->form->createElement("static", null, null, "Days per Week");
        $group[] =& $this->form->createElement("static", null, null, "Hours per Day");
        $group[] =& $this->form->createElement("static", null, null, "Size of Peer Group");
        $group[] =& $this->form->createElement("static", null, null, "Start Age");
        $group[] =& $this->form->createElement("static", null, null, "End Age");

        $this->form->addGroup($group, "section_headers", null, $this->_GUIDelimiter, false);
        unset($group);

        $k = 0;
        foreach ($child_care_questionnaire_labels as $key => $category) {
            $k++;
            $group[] = $this->createLabel($category);

            $group[] =& $this->createSelect(
                $key . "_days_per_week",
                "",
                $days_per_week_options
            );

            $group[] =& $this->createSelect(
                $key . "_hours_per_week",
                "",
                $hours_per_day_options
            );

            $group[] =& $this->createText(
                $key . "_size_of_peer_group",
                "Size of Peer Group {$key}"
            );

            $group[] =& $this->createText(
                $key . "_start_age",
                "Start Age {$key}"
            );

            $group[] =& $this->createText(
                $key . "_end_age",
                "End Age {$key}"
            );

            $this->form->addGroup(
                $group,
                "section_row{$k}",
                null,
                $this->_GUIDelimiter,
                false
            );
            unset($group);
        }

        $this->form->addElement("static", null, "<br><br>");

        $this->form->addElement('advcheckbox', 'pg2_if_uncomfortable_with_todays_language_sample', 'If you feel uncomfortable with a portion of today’s language sample and would like for it not to be used, we will delete the entire language sample and send you another LENA DLP for a replacement recording day. Please mark checkbox accordingly.', null, null, array('0','1'));	
      
      $this->form->addElement('advcheckbox','yes_parent_signed','Yes: Parents signed this section and asked that the recording be deleted.',null,null,array('0','1'));
      $this->form->addElement('advcheckbox','no_parent_signed','No: The parent did not sign this section and the recording can be used.',null,null,array('0','1'));


        $this->form->addFormRule(array(&$this, 'validate_page1'));
    }

    function _page2()
    {

	$this->addHeader("LENA Language Sample Activity Log Form");
            // Instructions
        $this->form->addElement(
            'static',
            null,
            "Dear Parent/Legal Guardian: Please complete this form and return with LENA materials."
        );

        $this->form->addElement("static", null, "<br><br>");

        $this->addBasicDate('pg2_todays_date', 'Today’s Date:', $this->dateOptions);

	$this->form->addElement('text', 'recorder_number','Recorder Number');
	$this->XINRegisterRule('recorder_number', array("recorder_number{@}=={@}NEVER_REQUIRED"), 'Not Required');

        $hour_options = array(null => "");

        $minute_options = array(null => "");

        $period_options = array(
                           null => "",
                           "am" => "AM",
                           "pm" => "PM",
                          );

        // populates hour_options array
        for ($i = 1; $i <= 12; $i++) {
            $hour_options[$i] = strval($i);
        }

        // populates minute_options array
        for ($i = 0; $i < 60; $i++) {
            if ($i < 10) {
                $minute_options[$i] = "0" . strval($i);
            } else {
                $minute_options[$i] = strval($i);
            }
        }

	$group[] = $this->form->createElement('select',"hour_timestamp","Hour:", $hour_options);
	$group[] = $this->form->createElement('select',"minute_timestamp","Minute:", $minute_options);
        $group[] = $this->form->createElement('select',"period_timestamp","AM/PM:", $period_options);
        $this->form->addGroup($group, "timestamp_group", "Timestamp:",null, false);
        unset($group);

        $this->form->addElement(
            'static',
            null,
            "Time Language Sample Started:"
        );

        $this->addSelect("pg2_time_language_sample_started_hour", $this->indent . "Hour:", $hour_options);
        $this->addSelect("pg2_time_language_sample_started_minute", $this->indent . "Minute:", $minute_options);
        $this->addSelect("pg2_time_language_sample_started_period", $this->indent . "AM/PM:", $period_options);

        $this->form->addElement("static", null, "<br><br>");

        $yes_no_options = array(
                           null  => "",
                           "yes" => "Yes",
                           "no"  => "No",
                          );

        $this->addSelect("pg2_did_you_do_free_play_session_today", "Did you do a Free Play Session Today?", $yes_no_options);

        $this->form->addElement(
            'static',
            null,
            $this->indent . "If yes, what time?"
        );

        $this->addSelect("pg2_free_play_session_time_specify_hour", $this->indent . "Hour:", $hour_options);
        $this->addSelect("pg2_free_play_session_time_specify_minute", $this->indent . "Minute:", $minute_options);
        $this->addSelect("pg2_free_play_session_time_specify_period", $this->indent . "AM/PM:", $period_options);

        $this->XINRegisterRule('pg2_free_play_session_time_specify_hour', array('pg2_did_you_do_free_play_session_today{@}=={@}yes'), 'Required.');
        $this->XINRegisterRule('pg2_free_play_session_time_specify_minute', array('pg2_did_you_do_free_play_session_today{@}=={@}yes'), 'Required.');
        $this->XINRegisterRule('pg2_free_play_session_time_specify_period', array('pg2_did_you_do_free_play_session_today{@}=={@}yes'), 'Required.');

        $feeling_options = array(
                            null   => "",
                            "well" => "Well",
                            "sick" => "Sick",
                           );

        $this->addSelect("pg2_how_is_child_feeling_today", "How is your child feeling today?", $feeling_options);

        $this->form->addElement('text', 'pg2_feeling_sick_specify', $this->indent . 'If sick, what illness?');

        $this->XINRegisterRule('pg2_feeling_sick_specify', array('pg2_how_is_child_feeling_today{@}=={@}sick'), 'Required if child is feeling sick');

        $this->form->addElement("static", null, "<br><br>");

        $talk_time_rating = array(
                             null                                 => "",
                             "1_lot_less_talkative_than_usual"    => "1 = A lot less talkative than usual",
                             "2_little_less_talkative_than_usual" => "2 = A little less talkative than usual",
                             "3_typical_normal"                   => "3 = Typical/Normal",
                             "4_little_more_talkative_than_usual" => "4 = A little more talkative than usual",
                             "5_more_talkative_than_usual"        => "5 = More talkative than usual",
                            );

        $this->addSelect("pg2_how_would_you_rate_today_amount_of_parent_child_talk_time", "How would you rate today in terms of amount of parent-child talk time?", $talk_time_rating);
             

      $this->form->addFormRule(array(&$this, 'validate_page2'));
    }

    function _saveValues(array $values): void
    {

               //----------------------------------------------------------//
        // *_chooser fields are always posted but do not exist in   //
        // the DB. Save their values in $files and unset these      //
        // otherwise parent::_saveValues will crash                 //
        //----------------------------------------------------------//
        foreach (self::$FILE_FIELDS as $k => $v) {
            if ($v['page'] == $this->page) {
                $files["{$k}_lena"] = $values["{$k}_lena"];
                unset($values["${k}_lena"]);
            }
        }

        $session   = $this->getSessionID();
        $timepoint = \TimePoint::singleton($session);
        $candidate = \Candidate::singleton($timepoint->getCandID());

        parent::_saveValues($values);

        //--------------------------//
        // Process all file fields  //
        //--------------------------//
        foreach (self::$FILE_FIELDS as $k => $v) {
            //---------------------------------------------//
            // If the associated file chooser was used and //
            // the chooser is on the current page          //
            //---------------------------------------------//
            if ($v['page'] != $this->page || $files["{$k}_lena"]["name"] == '') {
                continue;
            }

            //-------------------------------------------------------------------//
            // Check that there is no file in the media module with              //
            // the same name as the file. If there is a file with the sam        //
            // but the file was uploaded through the LENA form for field $k, then //
            // that's OK (counts as an update)                                   //
            //-------------------------------------------------------------------//
            $db           =& Database::singleton();
            $row          = $db->pselectRow(
                "SELECT e.Date_Taken, m.ID FROM {$this->table} e LEFT JOIN media m ON (e.{$k}=m.file_name) WHERE e.CommentID=:CommentID",
                array("CommentID" => $this->getCommentID())
            );
            $lenaDateTaken = $row['Date_Taken'];
            $mediaID      = $row['ID'];

            // Build insert query
            $config    = NDB_Config::singleton();
            $mediaPath = $config->getSetting('mediaPath');
            $user      =& User::singleton();

            $query = [
                      'session_id'  => $values["sessionID"],
                      'instrument'  => $values["test_name"],
                      'date_taken'  => $lenaDateTaken,
                      'file_name'   => $files["{$k}_lena"]["name"],
                      'file_type'   => $_FILES["{$k}_lena"]["type"],
                      'data_dir'    => $mediaPath,
                      'uploaded_by' => $user->getData('UserID'),
                     ];

            //-----------------------------------------------------------//
            // Try to move the file from the tmp upload directory to the //
            // media module upload directory                             //
            //-----------------------------------------------------------//
            if (move_uploaded_file($files["{$k}_lena"]["tmp_name"], $mediaPath . $files["{$k}_lena"]['name'])) {
                try {
                    // File alread exists in media module: update
                    if (!is_null($mediaID)) {
                        $db->update('media', $query, array('ID' => $mediaID));
                        // File does not exist in media module: insert new
                    } else {
                        $db->insert('media', $query);
                    }

                    // Update field $k in the LENA table for the current record
                    // Note that this was not done by parent::_saveValues since $k
                    // was defined as a "score" (i.e not submitted by the POST)
                    $db->update(
                        $this->table,
                        array($k => $files["{$k}_lena"]["name"]),
                        array('CommentID' => $this->getCommentID())
                    );
                } catch (DatabaseException $e) {
                    print_r($e);
                }
            } // if move_upload
        } // foreach
        
    }

        function validate_page1($values)
    {
        $errors = [];

        if ($values["did_you_do_free_play_session_today"] != "yes") {
            $this->validate_empty_subquestions($values, ["free_play_session_time_specify_hour"], $errors);
            $this->validate_empty_subquestions($values, ["free_play_session_time_specify_minute"], $errors);
            $this->validate_empty_subquestions($values, ["free_play_session_time_specify_period"], $errors);
        }

        if ($values["how_is_child_feeling_today"] != "sick") {
            $this->validate_empty_subquestions($values, ["feeling_sick_specify"], $errors);
        }

        if ($values["primary_language"] != "other") {
            $this->validate_empty_subquestions($values, ["primary_language_specify"], $errors);
        }

	$child_care_questionnaire_labels = array(
		                           "pg2_in_home_cared"     => "In home: Cared for by Parents",
                                           "in_home_family_member" => "In home: Family member (e.g., grandparents)",
                                           "in_home_nanny"         => "In home: Nanny",
                                           "in_home_non_family"    => "In home: Non-family (e.g., private daycare run out of home)",
                                           "center_based"          => "Center-based",
                                   );


        $k = 0;
        foreach ($child_care_questionnaire_labels as $key => $category) {
            $k++;

            $days       = $values[$key . "_days_per_week"];
            $hours      = $values[$key . "_hours_per_week"];
            $peer_group = $values[$key . "_size_of_peer_group"];
            $start_age  = $values[$key . "_start_age"];
            $end_age    = $values[$key . "_end_age"];

            $tmp = array();

            if ($days == "" || $hours == "" || $peer_group == "" || $start_age == "" || $end_age == "") {
                $errors["section_row" . $k] = $this->indent . "Required: ";

                if ($days == "") {
                    array_push($tmp, "Days per Week");
                }
                if ($hours == "") {
                    array_push($tmp, "Hours per Day");
                }
                if ($peer_group == "") {
                    array_push($tmp, "Size of Peer Group");
                }
                if ($start_age == "") {
                    array_push($tmp, "Start Age");
                }
                if ($end_age == "") {
                    array_push($tmp, "End Age");
                }
            }

            $tmp_size = count($tmp);

            for ($i = 0; $i < $tmp_size; $i++) {
                $errors["section_row" . $k] .= $tmp[$i];

                if ($i != ($tmp_size - 1)) {
                    $errors["section_row" . $k] .= ", ";
                }
            }
        }

        $j = 0;
        foreach ($child_care_questionnaire_labels as $key => $category) {
            $j++;

            if ($days != "" && $hours != "" && $peer_group != "" && $start_age != "" && $end_age != "") {
                $start_age_input = $values[$key . "_start_age"];
                $end_age_input   = $values[$key . "_end_age"];

                if (!ctype_digit($start_age_input) && $start_age_input != "NA") {
                    $errors["section_row" . $j] .= $this->indent . "Start age must be a number or enter NA if 'Not applicable'";
                }

                if (!ctype_digit($end_age_input) && $end_age_input != "NA") {
                    $errors["section_row" . $j] .= $this->indent . "End age must be a number or enter NA if 'Not applicable'";
                }
            }
        }

	if($values["yes_parent_signed"] == 1 && $values["no_parent_signed"] == 1 ){
           $errors["no_parent_signed"] = "Only one box can be checked at the same time";
        }

	if($values["yes_parent_signed"] == 0 && $values["no_parent_signed"] == 0 ){
		$errors["yes_parent_signed"] = "One box must be checked";
		$errors["no_parent_signed"] = "One box must be checked";
	}

        return $errors;
	}

        function validate_page2($values)
        {
        $errors = [];

        if ($values["pg2_did_you_do_free_play_session_today"] != "yes") {
            $this->validate_empty_subquestions($values, ["pg2_free_play_session_time_specify_hour"], $errors);
            $this->validate_empty_subquestions($values, ["pg2_free_play_session_time_specify_minute"], $errors);
            $this->validate_empty_subquestions($values, ["pg2_free_play_session_time_specify_period"], $errors);
        }

        if ($values["pg2_how_is_child_feeling_today"] != "sick") {
            $this->validate_empty_subquestions($values, ["pg2_feeling_sick_specify"], $errors);
        }

        if ($values["pg2_primary_language"] != "other") {
            $this->validate_empty_subquestions($values, ["pg2_primary_language_specify"], $errors);
        }
                
        return $errors;
	}

	function lena_rules($values)
    {
                //--------------------------------------------------------------------//
        // Validate that there are no duplicates in the set of files chosen   //
        // with the file choosers on the current page                        //
        //--------------------------------------------------------------------//
  
      $chosen = array();
        foreach (self::$FILE_FIELDS as $k => $v) {
            //---------------------------------------------//
            // If the associated file chooser was used and //
            // the chooser is on the current page          //
            //---------------------------------------------//
            if ($v['page'] == $this->page) {
                if ($values["{$k}_lena"]['name'] != '') {
                    $fname = $values["{$k}_lena"]['name'];
		    if (isset($chosen[$fname])) {
                        $errors["{$k}_lena"] = "A file with name $fname is already selected in section '{$chosen[$fname]}'. Please choose another file";
                    } else {
                        $chosen[$fname] = $v['name'];
                    }
                }
            }
        }

        //-----------------------------//
        // Validate all required files //
        //-----------------------------//
        foreach (self::$FILE_FIELDS as $k => $v) {
            if (isset($errors["{$k}_lena"])) {
                continue;
            }

            //---------------------------------------------//
            // If the associated file chooser was used and //
            // the chooser is on the current page          //
            //---------------------------------------------//
            if ($v['page'] != $this->page) {
                continue;
            }

            $db =& Database::singleton();
            // Check that a file for $k already exists in the DB
            $fileAlreadyUploaded = $db->pselectOne(
                "SELECT $k FROM {$this->table} WHERE CommentID=:CommentID",
                array('CommentID' => $this->getCommentID())
            );

            // File chooser for $k was not used but there's already a file in the DB
            // for $k: all good
            if ($fileAlreadyUploaded && $values["{$k}_lena"]['name'] == '') {
                continue;
            }

            // File chooser was used to specify the same file as the one in the DB
            // for $k: that's an update and that's OK
            if (!is_null($fileAlreadyUploaded) && $values["{$k}_lena"]['name'] == $fileAlreadyUploaded) {
                continue;
            }

            // File chooser for $k was not used and no file in the DB for $k: error
            if ($values["{$k}_lena"]['name'] == '' && $v['required']) {
                $errors["{$k}_lena"] = 'You must select a file to upload';
                //----------------------------------------------//
                // The file chooser associated to $k was used   //
                // (i.e a file for $k is supplied)              //
                //----------------------------------------------//
            } else {
                //-----------------------------------------------------------------//
                // Check that there is not already a file with the same name       //
                // in the media module.                                            //
                //-----------------------------------------------------------------//
                $query = "SELECT 1 FROM media WHERE file_name=:fileName";
                $fileAlreadyExists = $db->pselectOne(
                    $query,
                    array('fileName' => $values["{$k}_lena"]['name'])
                );

                if ($fileAlreadyExists) {
                    $errors["{$k}_chooser"] = "A file with name {$values["{$k}_lena"]['name']} "
                                            . "has already been uploaded in the database. Please choose another one";
                }
            } // else
        } // foreach

        return $errors;
    }
	
}
?>
