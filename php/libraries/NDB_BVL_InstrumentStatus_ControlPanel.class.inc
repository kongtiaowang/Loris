<?php declare(strict_types=1);
/**
 * File contains NDB_BVL_InstrumentStatus_ControlPanel class
 *
 * PHP Version 7
 *
 * @category Main
 * @package  Behavioural
 * @author   Loris Team <loris.mni@bic.mni.mcgill.ca>
 * @license  http://www.gnu.org/licenses/gpl-3.0.txt GPLv3
 * @link     https://www.github.com/aces/Loris/
 */
use LORIS\StudyEntities\Candidate\CandID;

/**
 * Behavioural instrument status control panel class
 *
 * This class provides the management GUI for the status flags
 * of instruments in the NeuroDB framework.
 *
 * @category Main
 * @package  Behavioural
 * @author   Loris Team <loris.mni@bic.mni.mcgill.ca>
 * @license  http://www.gnu.org/licenses/gpl-3.0.txt GPLv3
 * @link     https://www.github.com/aces/Loris/
 */
class NDB_BVL_InstrumentStatus_ControlPanel extends NDB_BVL_InstrumentStatus
{
    public $tpl_data;
    public $ValidityEnabled;
    public $ValidityRequired;
    protected $instrument;

    protected CandID $candID;
    protected SessionID $sessionID;

    protected string $testname;
    protected ?string $subtest;

    protected $loris;

    // Whether the control panel was used to move a survey from visit A
    // to visit B, thereby triggering a deletion of the survey from visit
    // A.
    private $instrumentWasDeleted;

    /**
     * Construct a controller for the instrument status control panel
     *
     * @param string  $testname  The instrument name being managed
     * @param string  $commentid The commentID being loaded
     * @param CandID  $candid    The candidate who this instrument belongs to
     * @param int     $sessionid The session at which the instrument took place
     * @param ?string $subtest   The page of the instrument being accessed
     */
    function __construct(
        \LORIS\LorisInstance $loris,
        string $testname,
        string $commentid,
        CandID $candid,
        SessionID $sessionid,
        ?string $subtest
    ) {
        $this->loris      = $loris;
        $this->candID     = $candid;
        $this->testname   = $testname;
        $this->_commentID = $commentid;
        $this->sessionID  = $sessionid;
        $this->subtest    = $subtest;
        $this->instrumentWasDeleted = false;
    }

    /**
     * Tells whether the instrument had to be deleted as a result of being moved
     * from one visit to another (this only happens for surveys).
     *
     * @return bool if the instrument was deleted, false otherwise.
     */
    function instrumentWasDeleted() : bool
    {
        return $this->instrumentWasDeleted;
    }

    /**
     * Generates the HTML to display the set of buttons for the instrument
     * status flags
     *
     * @return string The HTML to render to the client
     */
    function display(): string
    {
        if (empty($this->_commentID)) {
            throw new Exception("No instrument instance selected");
        }

        if ($this->instrumentWasDeleted()) {
            return "";
        }

        $this->tpl_data['candID']    = $this->candID ?? '';
        $this->tpl_data['sessionID'] = $this->sessionID;
        $this->tpl_data['commentID'] = $this->_commentID;
        $this->tpl_data['test_name'] = $this->testname;
        $this->tpl_data['subtest']   = $this->subtest ?? '';

        // get the files path
        $config = \NDB_Config::singleton();
        $base   = $config->getSetting('base');

        // the instrument exists
        $InstrumentPath = $base."project/instruments/NDB_BVL_Instrument_"
            .$this->testname
            .".class.inc";
        $LinstPath      = $base."project/instruments/"
            .$this->testname
            .".linst";
        if (file_exists($InstrumentPath)
            || file_exists($LinstPath)
        ) {
            // include the instrument's class, if it's an old school instrument.
            if (file_exists($InstrumentPath)) {
                include_once $InstrumentPath;
            }
            // create an instance of the instrument
	    $instrument = NDB_BVL_Instrument::factory(
		$this->loris,    
                $this->testname,
                $this->_commentID,
                $this->subtest ?? ''
            );

            $this->instrument = $instrument;

            $this->ValidityEnabled  = $instrument->ValidityEnabled;
            $this->ValidityRequired = $instrument->ValidityRequired;

            // generate the subtest list
            $list = $instrument->getSubtestList();
            $this->tpl_data['subtests'] = $list;
        }

        if (empty($this->subtest)) {
            $hasAccess = $this->_hasAccess();

            if ($this->getDataEntryStatus() == null && $hasAccess) {
                $this->setDataEntryStatus('In Progress');
            }

            // generate the administration flag buttons
            $this->tpl_data['access']['administration']
                = $this->_displayAdministration();

            // generate the data entry flag buttons
            $this->tpl_data['access']['data_entry']
                = $this->_displayDataEntry();

            // generate the validity flag buttons
            if ($this->ValidityEnabled == true) {
                $this->tpl_data['access']['validity'] = $this->_displayValidity();
            }

            $user = User::singleton();
            if ($config->getSetting('InstrumentResetting')
                && $this->getDataEntryStatus() != 'Complete'
            ) {
                if ($user->hasPermission('send_to_dcc')) {
                    $this->tpl_data['InstrumentResetting'] = true;
                }
            }

          //  if ($config->getSetting('InstrumentMoving') && $user->hasPermission('candidate_parameter_edit')) {
          //      $this->tpl_data['InstrumentMoving'] = true;
           // }
        }

        $this->tpl_data['InstrumentMoveActions'] = $this->getInstrumentMoveActions();

        $smarty = new Smarty_NeuroDB;
        $smarty->assign($this->tpl_data);
        $html = $smarty->fetch("instrumentstatus_controlpanel.tpl");
        return $html;
    }

    /**
     * Gets all the possible move instrument actions that the user can choose to
     * take.
     *
     * @return array the list of possible move instrument actions.
     *
     * @throws ConfigurationException if one of the configuration parameters needed by this function
     *                                could not be retrieved.
     * @throws DatabaseException if any of the database transactions done during execution of this
     *                           function fails.
     * @throws NotFound
     * @throws Exception
     */
    function getInstrumentMoveActions() : array
    {
        $moveInstrumentActions = [];
        $fromTimepoint = TimePoint::singleton(new \SessionID(strval($this->sessionID)));

        $candidate     = Candidate::singleton($this->candID);
        $db            = \NDB_Factory::singleton()->database();
        $isDirectEntry = $db->pselectOne(
            "SELECT IsDirectEntry FROM test_names WHERE test_name=:testname",
            [ 'testname' => $this->testname ]
        );

        // Foreach visit created for the candidate
        foreach ($candidate->getListOfVisitLabels() as $toSessionID => $toVisitLabel) {
            // Skip the current visit
            if (strval($toSessionID) != strval($this->sessionID)) {
                $toTimepoint = TimePoint::singleton(new \SessionID(strval($toSessionID)));
                $toBattery   = new NDB_BVL_Battery();
                $toBattery->selectBattery(new \SessionID(strval($toSessionID)));

                $toCommentID = $toBattery->getCommentIdForInstrument($this->testname);
                if (!is_null($toCommentID)) {
                    $toInstrument = NDB_BVL_Instrument::factory($this->testname, $toCommentID);
                }
                // Build the properties of the move action associated with moving
                // the instrument to visit $toVisitLabel
                $moveInstrumentActions[] = [
                    // The comment ID that the instrument with the same name as the current one
                    // has at visit $toVisitLabel (null if there are none)
                    'TO_COMMENTID'       => $toCommentID,
                    // The ID of the visit the instrument is moved TO
                    'TO_SESSIONID'       => $toSessionID,
                    // CandID for the moved instrument
                    'CANDID'             => $this->candID,

                    // The label of the visit the instrument is moved FROM
                    'FROM_VISIT_LABEL'   => $fromTimepoint->getVisitLabel(),
                    // The stage of the visit the instrument is moved FROM
                    'FROM_VISIT_STAGE'   => $fromTimepoint->getCurrentStage(),
                    // The PSC of the visit the instrument is moved FROM
                    'FROM_VISIT_PSC'     => $fromTimepoint->getPSC(),
                    // The ID of the visit the instrument is moved FROM
                    'FROM_SESSIONID'     => $fromTimepoint->getSessionID(),

                    // The label of the visit the instrument is moved TO
                    'TO_VISIT_LABEL'     => $toVisitLabel,
                    // The stage of the visit the instrument is moved TO
                    'TO_VISIT_STAGE'     => $toTimepoint->getCurrentStage(),
                    // The stage of the visit the instrument is moved TO
                    'TO_VISIT_PSC'       => $toTimepoint->getPSC(),

                    // Whether the moved instrument is direct entry or not
                    'IS_DIRECT_ENTRY'    => $isDirectEntry,
                    // Whether the moved instrument is a prser or not
                    'IS_PARSER'          => $this->instrument->isParser(),

                    // Whether the instrument is part of the standard battery of tests administered
                    // at $toVisitLabel
                    'IN_BATTERY'         => $isDirectEntry
                        ? isset($toBattery->getAdministrableSurveys()[$this->testname])
                        : !is_null($toCommentID),
                    // Whether the corresponding instrument at $toVisitLabel has been edited
                    // (false if there is no corresponding instrument at $toVisitLabel)
                    'TO_INSTRUMENT_EDITED' => !is_null($toCommentID) && $toInstrument->isEdited()
                ];
            }
        }

        return $moveInstrumentActions;
    }

    /**
     * Saves changes to the flags based on interaction with the control panel
     *
     * @return bool Whether a user has access to the module and the instrument
     *              is not locked.
     */
    function  save(): bool
    {
        $hasAccess = $this->_hasAccess();
        // don't do anything if the instrument is locked
        if (!$hasAccess) {
            return false;
        }
        if (isset($_POST['ClearInstrument'])) {
            $user = User::singleton();
            if ($user->hasPermission('send_to_dcc')) {
                $instrument = \NDB_BVL_Instrument::factory(
                    $this->testname,
                    $this->_commentID,
                    $this->subtest ?? ''
                );
                $instrument->clearInstrument();
                return false;
            } else {
                return false;
            }
        }

        if (isset($_POST['InstrumentMoveActionSelect'])) {
            $this->handleInstrumentMovePost();
            return false;
        }

        // get control panel selections from _REQUEST
        $possibleFlags = array(
            'setDataEntry',
            'setAdministration',
            'setValidity',
        );
        $flagsToSave   = array_intersect($possibleFlags, array_keys($_REQUEST));
        // make sure there are at least one flag to save
        if (is_array($flagsToSave) && count($flagsToSave) > 0) {
            foreach ($flagsToSave AS $flagToSave) {
                $method = $flagToSave . "Status";
                $this->$method($_REQUEST[$flagToSave]);
            }
        }
        return true;
    }

    /**
     * Handles the POST request to move an instrument from a visit to another.
     *
     * @return void
     *
     * @throws ConfigurationException if one of the configuration parameters needed by this function
     *                                could not be retrieved.
     * @throws DatabaseException if any of the database transactions done during execution of this
     *                           function fails.
     */
    function handleInstrumentMovePost() : void
    {
        // Check that instrument moving is enabled and that the user has permission
        // to use that feature
        $user = User::singleton();
        $config = \NDB_Config::singleton();
    //    if (!$config->getSetting('InstrumentMoving') || !$user->hasPermission('candidate_parameter_edit')) {
    //        header("HTTP/1.1 403 Forbidden");
    //        exit;
    //    }

        $db = \NDB_Factory::singleton()->database();
        $db->beginTransaction();

        try {
            // Ensure there a POST parameter InstrumentMoveActionSelect
            if (!isset($_POST['InstrumentMoveActionSelect'])) {
                throw new Exception("No parameter 'InstrumentMoveActionSelect' in POST request");
            }

            $instrumentMoveAction = json_decode($_POST['InstrumentMoveActionSelect'], true);
            $toCommentID          = $instrumentMoveAction['TO_COMMENTID'] ?? null;

            // If there's no corresponding instrument at vTo
            if (is_null($toCommentID)) {
                // If the vTo visit label was not specified
                if (is_null($instrumentMoveAction['TO_VISIT_LABEL'] ?? null)) {
                    throw new Exception(
                        "Array 'InstrumentMoveActionSelect' in POST request should contain a non-null TO_VISIT_LABEL"
                    );
                }

                // Create a corresponding instrument at vTo
                $toCommentID =
                    $this->createInstrument($this->candID, $this->testname, $instrumentMoveAction['TO_VISIT_LABEL']);
                $instrumentMoveAction['TO_COMMENTID'] = $toCommentID;
            }

            // Move instrument data and statuses from the instrument at vFrom to the instrument
            // at vTo. Do the same thing for the associated DDE instruments
            $this->moveInstrumentAndStatuses($this->_commentID, $toCommentID);
            $this->moveInstrumentAndStatuses("DDE_$this->_commentID", "DDE_$toCommentID");

            $this->afterInstrumentMoved($instrumentMoveAction);
            $db->commit();
        } catch (Exception $e) {
            // Something went wrong: display error message, rollback the database transactions
            // and return an HTTP 500 response
            error_log(
                sprintf("POST request to move Instrument %s failed: %s", $this->_commentID, $e->getMessage())
            );

            http_response_code(500);
            exit(json_encode(['message' => $e->getMessage()]));
        }
    }

    /**
     * Updates the database tables from other modules after an instrument is moved.
     *
     * @param array $instrumentMoveAction instrument move properties.
     *
     * @return void
     *
     * @throws ConfigurationException
     * @throws DatabaseException
     * @throws NotFound
     */
    function afterInstrumentMoved(array $instrumentMoveAction) : void
    {
        $db = \NDB_Factory::singleton()->database();
        $fromCommentID = $this->_commentID;
        $toCommentID   = $instrumentMoveAction['TO_COMMENTID'];
        $toSessionID   = $instrumentMoveAction['TO_SESSIONID'];

        //===================================//
        // Update table participant_accounts //
        //===================================//
        if ($instrumentMoveAction['IS_DIRECT_ENTRY']) {
            // If there is a survey in table participant account with comment ID $toCommentID
            //   delete it.
            // Afterwards, modify the survey with comment ID $fromCommentID so that it
            //   now has 'CommentID' = $toCommentID and 'SessionID' = $toSessionID.
            // Note that we have to perform the deletion first otherwise we might end up with
            //   two surveys with comment ID $toCommentID after the update if there already
            //   was one with comment ID = $toCommentID.
            $db->delete("participant_accounts", ['CommentID' => $toCommentID]);
            $db->update(
                "participant_accounts",
                ['CommentID' => $toCommentID, 'SessionID' => $toSessionID], ['CommentID' => $fromCommentID]
            );
            $fromInstrument = NDB_BVL_Instrument::factory($this->testname, $this->_commentID);
            if (!$fromInstrument->usesJSONData()) {
                $db->delete($this->testname, ['CommentID' => $fromCommentID]);
                $db->delete($this->testname, ['CommentID' => "DDE_$fromCommentID"]);
            }
            $db->delete('flag', ['CommentID' => $fromCommentID]);
            $db->delete('flag', ['CommentID' => "DDE_$fromCommentID"]);


            $this->instrumentWasDeleted = true;
        }

        //===================================//
        // Update table reliability          //
        //===================================//
        $db->update(
            "reliability", ['CommentID' => $toCommentID], ['CommentID' => $fromCommentID]
        );

        //==============================================================//
        // Setting the correct instrument statuses after the move will  //
        // regenerate the unresolved conflicts for the "from" and "to"  //
        // records                                                      //
        //==============================================================//

        //========================================================//
        // Replace references to the "from" instrument in tables  //
        // conflicts_resolved and conflicts_unresolved with       //
        // references to the "to" instrument                      //
        //========================================================//
        $db->update(
            "conflicts_resolved",
            ['CommentID1' => $toCommentID, 'CommentID2' => "DDE_$toCommentID"],
            ['CommentID1' => $fromCommentID]
        );

        //====================================//
        // Update table feedback_bvl_thread   //
        //====================================//
        $db->delete('feedback_bvl_thread', ['CommentID' => $toCommentID]);
        $db->update(
            "feedback_bvl_thread",
            ['CommentID' => $toCommentID, 'SessionID' => $toSessionID],
            ['CommentID' => $fromCommentID]
        );

        //======================//
        // Update table media   //
        //======================//
        $db->update(
            "media",
            ['session_id' => $toSessionID],
            ['session_id' => $this->sessionID, 'instrument' => $this->testname]
        );

        $pscid = $db->pselectOne(
            "SELECT PSCID FROM candidate where CandID=:candid",
            ['candid' => $instrumentMoveAction['CANDID']]
        );

        //===================================//
        // Update table document_repository  //
        //===================================//
        $db->update(
            "document_repository",
            ['visitLabel' => $instrumentMoveAction['TO_VISIT_LABEL']],
            ['Instrument' => $this->testname, 'visitLabel' => $instrumentMoveAction['FROM_VISIT_LABEL'], 'PSCID' => $pscid]
        );

    }

    /**
     * Adds an instrument instance to a given visit.
     *
     * @param CandID $candid the candidate ID targeted by this operation.
     * @param string $testName name of the instrument to create.
     * @param string $visitLabel label of the visit in which the instrument should be
     *                           created.
     *
     * @return string the comment ID of the newly created instrument.
     *
     * @throws DatabaseException if any of the database transactions done to perform this task fail.
     * @throws Exception if visit $visitLabel does not exists for candidate $candid.
     * @throws Exception if the instrument to create already exists at $visitLabel.
     * @throws Exception if the creation fails for any other reason than the ones listed above.
     */
    function createInstrument(CandID $candid, string $testName, string $visitLabel): string
    {
        $candidate = Candidate::singleton($candid);
        $sessionID = array_search($visitLabel, $candidate->getListOfVisitLabels());
        if ($sessionID === false) {
            throw new Exception("No such visit $visitLabel for candidate " . $candidate->getCandID());
        }

        $battery = new NDB_BVL_Battery();
        $battery->selectBattery($sessionID);
        if (!is_null($battery->getCommentIdForInstrument($testName))) {
            throw new Exception("Instrument $testName already exists at session $sessionID");
        }

        try {
            return $battery->addInstrument($testName);
        } catch (Exception $e) {
            throw new Exception(
                sprintf(
                    "Instrument %s could not be added to visit %s of %s: %s",
                    $this->testname, $visitLabel, $candidate->getCandID(), $e->getMessage()
                )
            );
        }
    }

    /**
     * Moves the data and statuses from instrument $fromCommentID to instrument
     * $toCommentID. After the move, the data and statuses of the instrument $fromCommentID
     * will be reverted to their default values.
     *
     * @param string $fromCommentID comment ID of the instrument for which the data and statuses
     *                              should be moved.
     * @param string $toCommentID comment ID of the instrument to which the data and statuses
     *                            should be moved.
     *
     * @return void
     *
     * @throws Exception if anything goes wrong during this function call.
     */
    function moveInstrumentAndStatuses(string $fromCommentID, string $toCommentID) : void
    {
        $instrumentFrom = NDB_BVL_Instrument::factory($this->testname, $fromCommentID);

        $instrumentFrom->copyTo($toCommentID);

        $instrumentToStatus = new \NDB_BVL_InstrumentStatus();
        $instrumentToStatus->select($toCommentID);
        $instrumentFromStatus = new \NDB_BVL_InstrumentStatus();
        $instrumentFromStatus->select($fromCommentID);
        $instrumentFromStatus->copyTo($instrumentToStatus);

        $instrumentFromStatus->resetStatuses();
        $instrumentFrom->clearInstrument();
    }

    /**
     * Generates the HTML to display the set of buttons for the data entry flag
     *
     * @return bool Whether a user has access, Has the side-effect of
     *                  modifying front-end content.
     */
    function _displayDataEntry(): bool
    {
        $hasAccess = $this->_hasAccess();

        // loop through the options
        $i = 0;
        foreach ($this->_dataEntryOptions AS $option) {
            // skip the null case
            if (is_null($option)) {
                continue;
            }

            $this->tpl_data['data_entry'][$i]['label'] = $option;

            // highlight the current option if it's the current status
            if ($this->getDataEntryStatus() == $option) {
                $this->tpl_data['data_entry'][$i]['icon'] = 'far fa-check-square';
            } elseif ($hasAccess && $this->getAdministrationStatus()) {
                // make the option a link unless this field is locked
                // the field is locked if the Administration flag has not
                // been set or the instrument is locked
                $showLink = true;
                $Validity = $this->getValidityStatus();
                if ($Validity == null
                    && $this->instrument->ValidityRequired == true
                    && $this->getAdministrationStatus() != 'None'
                ) {
                    $showLink = false;
                    if ($option == 'Complete') {
                        $this->tpl_data['data_entry'][$i]['tooltip']
                            = "To enable link, Validity option must be selected";
                    }
                }

                if ($option == 'In Progress') {
                    $showLink = true;
                } elseif ($option == 'Complete'
                    && $this->getAdministrationStatus() == 'All'
                ) {
                    // run the data entry logic test
                    if (isset($this->instrument)) {
                        if ($showLink == true) {
                            $CompStatus
                                = $this->instrument->getDataEntryCompletionStatus();

                            $showLink = $CompStatus == 'Complete';

                            if (!$showLink) {
                                $this->tpl_data['data_entry'][$i]['tooltip']
                                    = "To enable link, required fields must be
                                      filled in";
                            }
                        }
                    }
                }

                if ($showLink) {
                    // construct the URL
                    $this->tpl_data['data_entry'][$i]['showlink'] = true;
                }
            } else {
                $this->tpl_data['data_entry'][$i]['icon']    = 'fas fa-times';
                $this->tpl_data['data_entry'][$i]['tooltip']
                    = "To enable link, Administration option must be selected";
            }
            $i++;
        }
        return $hasAccess;
    }

    /**
     * Generates the HTML to display the set of buttons for the administration flag
     *
     * @return bool Whether a user has access, Has the side-effect of
     *                  modifying front-end content.
     */
    function _displayAdministration(): bool
    {
        $hasAccess = $this->_hasAccess();

        $dataEntry = $this->getDataEntryStatus();

        // loop through the options
        $i = 0;
        foreach ($this->_administrationOptions AS $option) {
            // skip the null case
            if (is_null($option)) {
                continue;
            }

            $this->tpl_data['administration'][$i]['label'] = $option;

            // highlight the current option if it's the current status
            if ($this->getAdministrationStatus() == $option) {
                $this->tpl_data['administration'][$i]['icon']
                    = 'far fa-check-square';
            } elseif ($hasAccess
                && $dataEntry != 'Complete'
                && $dataEntry != 'Not Complete'
            ) {
                // make the option a link unless this field is locked
                // the field is locked if the Data_entry flag has been set
                // or the instrument is locked

                // construct the URL
                $this->tpl_data['administration'][$i]['showlink'] = true;
            } else {
                // block the button
                $this->tpl_data['administration'][$i]['icon'] = 'fas fa-times';
            }
            $i++;
        }

        return $hasAccess;
    }

    /**
     * Generates the HTML to display the set of buttons for the validity flag
     *
     * @return bool Whether a user has access, Has the side-effect of
     *                  modifying front-end content.
     */
    function _displayValidity(): bool
    {
        $hasAccess = $this->_hasAccess();

        $validityStatus    = $this->getValidityStatus();
        $data_entry_status = $this->getDataEntryStatus();

        // loop through the options
        $i = 0;
        foreach ($this->_validityOptions AS $option) {
            // skip the null case
            if (is_null($option)) {
                continue;
            }

            $this->tpl_data['validity'][$i]['label'] = $option;

            // highlight the current option if it's the current status
            if ($validityStatus == $option) {
                $this->tpl_data['validity'][$i]['icon'] = 'far fa-check-square';
            } else {
                if ($data_entry_status == 'Complete') {
                    $this->tpl_data['validity'][$i]['showLink'] = false;
                } else {
                    $this->tpl_data['validity'][$i]['showLink'] = true;
                }
            }
            $i++;
        }

        return $hasAccess;
    }

    /**
     * Generates the HTML to display the set of buttons for the exclusion flag
     *
     * @return bool Whether a user has access, Has the side-effect of
     *                  modifying front-end content.
     */
    function _displayExclusion(): bool
    {
        $hasAccess = $this->_hasAccess();

        $exclusionStatus = $this->getExclusionStatus();

        // loop through the options
        $i = 0;
        foreach ($this->_exclusionOptions AS $option) {
            // skip the null case
            if (is_null($option)) {
                continue;
            }

            $this->tpl_data['exclusion'][$i]['label'] = $option;

            // highlight the current option if it's the current status
            if ($exclusionStatus == $option) {
                $this->tpl_data['exclusion'][$i]['icon'] = 'far fa-check-square';
            }
            $i++;
        }

        return $hasAccess;
    }

    /**
     * Determines if the current instrument statuses should be locked due
     * to being sent to dcc unless there exists feedback.
     *
     * @return boolean
     */
    function _hasAccess(): bool
    {
        // get user object
        $user = \User::singleton();

        // make a timepoint object
        $timePoint = \TimePoint::singleton($this->sessionID);

        // make sure user belongs to same site as timepoint
        if (!$user->hasPermission('data_entry')
            || !in_array(
                $timePoint->getData('CenterID'),
                $user->getData('CenterIDs')
            )
        ) {
            return false;
        }

        // make a feedback object
        $feedback = \NDB_BVL_Feedback::singleton(
            $user->getData('UserID'),
            null,
            null,
            $this->_commentID
        );

        // find out the current worst feedback thread status
        $maxThreadStatus = $feedback->getMaxThreadStatus(false);

        // statuses are locked if the timepoint is submitted and there is no
        // open feedback
        return (!$timePoint->isSubmitted() || $maxThreadStatus == 'opened');
    }
}
