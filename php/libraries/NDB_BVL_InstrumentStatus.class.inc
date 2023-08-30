<?php declare(strict_types=1);
/**
 * Class for managing the status of instrument flags
 *
 * PHP Version 7
 *
 * @category Main
 * @package  Behavioural
 * @author   Loris Team <loris.mni@bic.mni.mcgill.ca>
 * @license  http://www.gnu.org/licenses/gpl-3.0.txt GPLv3
 * @link     https://www.github.com/aces/Loris/
 */

/**
 * Behavioural instrument status class
 *
 * This class provides management tools for the status flags of instruments
 * in the NeuroDB framework.
 *
 * @category Main
 * @package  Behavioural
 * @author   Loris Team <loris.mni@bic.mni.mcgill.ca>
 * @license  http://www.gnu.org/licenses/gpl-3.0.txt GPLv3
 * @link     https://www.github.com/aces/Loris/
 */
class NDB_BVL_InstrumentStatus
{
    /**
     * Instrument instance CommentID
     */
    var $_commentID;

    /**
     * Status array
     */
    var $_status;

    /**
     * The set of valid options for the data entry flag
     */
    var $_dataEntryOptions = array(
        null,
        'In Progress',
        'Complete',
    );

    /**
     * The set of valid options for the administration flag
     */
    var $_administrationOptions = array(
        null,
        'None',
        'Partial',
        'All',
    );

    /**
     * The set of valid options for the validity flag
     */
    var $_validityOptions = array(
        null,
        'Valid',
        'Questionable',
        'Invalid',
    );

    /**
     * The set of valid options for the exclusion flag
     */
    var $_exclusionOptions = array(
        null,
        'Fail',
        'Pass',
    );

    /**
     * Loads the object with the current status of the instrument
     *
     * @param string $commentID the CommentID identifying the data to load
     *
     * @return void
     */
    function select(string $commentID): void
    {
        // set the _commentID property
        $this->_commentID = $commentID;

        $db = \NDB_Factory::singleton()->database();

        // get candidate data from database
        $query = "SELECT SessionID, Data_entry, Administration, Validity, Exclusion
            FROM flag
            WHERE CommentID=:CID";
        $row = $db->pselectRow($query, array('CID' => $this->_commentID));
        // IBIS SPECIFIC OVERRIDE CODE
        // Remove this due to issue with not all flag rows having DDE row
        /*
        if (is_null($row)) {
            throw new \LorisException(
                'No information exists in the database for the specified '
                . 'CommentID. Cannot build InstrumentStatus object'
            );
        }
        */
        // IBIS SPECIFIC OVERRIDE CODE ENDS HERE

        // store the statuses into the _status property
        $this->_status = $row;
    } // end function select()

    /**
     * Gets the SessionID of the current instrument
     *
     * @return int
     * @access public
     */
    public function getSessionID(): int
    {
        return intval($this->_status['SessionID']);
    }

    /**
     * Gets the current data entry status of the instrument
     *
     * @return string|null the current data entry status.
     */
    function getDataEntryStatus(): ?string
    {
        if ($this->_status === null && !empty($this->_commentID)) {
            $this->select($this->_commentID);
        }
        return $this->_status['Data_entry'];
    }

    /**
     * Gets the current administration status of the instrument
     *
     * @return string|null the current administration status.
     */
    function getAdministrationStatus(): ?string
    {
        return $this->_status['Administration'];
    }

    /**
     * Gets the current validity status of the instrument
     *
     * @return string|null the current validity status.
     */
    function getValidityStatus(): ?string
    {
        return $this->_status['Validity'];
    }

    /**
     * Gets the current exclusion status of the instrument
     *
     * @return string|null the current exclusion status.
     *
     */
    function getExclusionStatus(): ?string
    {
        return $this->_status['Exclusion'];
    }

    /**
     * Sets the current data entry status of the instrument
     *
     * @param string|null $status the new status from the set (NULL,
     *                    'In Progress','Not Complete','Complete')
     *
     * @return void
     *
     * @throws LorisException if the database update fails.
     * @throws Exception if $this->_commentID is not set.
     * @throws Exception if the status passed as aregument is invalid.
     */
    function setDataEntryStatus(?string $status): void
    {
        if (!isset($this->_commentID)) {
            throw new Exception("No instrument instance selected");
        }

        if (!in_array($status, $this->_dataEntryOptions)) {
            throw new Exception('Invalid data entry status');
        }

        $GLOBALS['DB']->update(
            'flag',
            array('Data_entry' => $status),
            array('CommentID' => $this->_commentID)
        );

        $this->select($this->_commentID);

        // Run the ConflictDetector if the new status is Complete
        if ($status == 'Complete') {
            $principalCommentId = (strpos($this->_commentID, 'DDE') === false
                ? $this->_commentID
                : substr($this->_commentID, 4)
            );
            $DDECommentId = 'DDE_' . $principalCommentId;

            $query = $GLOBALS['DB']->pselect(
                "SELECT Data_entry FROM flag
                WHERE CommentID=:PCID OR CommentID=:DDECID",
                array(
                    'PCID'   => $principalCommentId,
                    'DDECID' => $DDECommentId,
                )
            );

            // Run ConflictDetector if Data_entry of SDE and DDE are both Complete
            $count = 0;
            foreach ($query as $dataEntryStatus) {
                if ($dataEntryStatus['Data_entry'] == 'Complete') {
                    $count++;
                }
                if ($count > 1) {
                    $instrumentName = NDB_BVL_Battery::getInstrumentNameForCommentId(
                        $principalCommentId
                    );

                    ConflictDetector::clearConflictsForInstance($principalCommentId);
                    $diff = ConflictDetector::detectConflictsForCommentIds(
                        $instrumentName,
                        $principalCommentId,
                        $DDECommentId
                    );
                    ConflictDetector::recordUnresolvedConflicts($diff);
                }
            }
        }

        // Remove conflicts for SDE & DDE form from the
        // Conflict Resolver if new status is 'In Progress'
        // IBIS Override (or maybe bug fix?): setting the data entry to null should
        // delete the unresolved conflicts, if any (this is used by the move instrument
        // button)
        if (is_null($this->getDataEntryStatus()) || $status == 'In Progress') {
            $deleteWhere1 = array('CommentId1' => $this->_commentID);
            $deleteWhere2 = array('CommentId2' => $this->_commentID);
            $GLOBALS['DB']->delete('conflicts_unresolved', $deleteWhere1);
            $GLOBALS['DB']->delete('conflicts_unresolved', $deleteWhere2);
        }

    }

    /**
     * Sets the current administration status of the instrument
     *
     * @param string|null $status the new status from the set
     *                    (NULL, 'None','Partial','All')
     *
     * @return void
     *
     * @throws LorisException if the database update fails.
     * @throws Exception if $this->_commentID is not set.
     * @throws Exception if the status oassed as argument is invalid.
     */
    function setAdministrationStatus(?string $status): void
    {
        if (!isset($this->_commentID)) {
            throw new Exception("No instrument instance selected");
        }

        if (!in_array($status, $this->_administrationOptions)) {
            throw new Exception('Invalid administration status');
        }

        $GLOBALS['DB']->update(
            'flag',
            array('Administration' => $status),
            array('CommentID' => $this->_commentID)
        );
        $this->select($this->_commentID);
    }

    /**
     * Sets the current validity status of the instrument
     *
     * @param string|null $status the new status from the set
     *                    (NULL, 'Questionable', 'Invalid', 'Valid')
     *
     * @return void
     *
     * @throws LorisException if the database update fails.
     * @throws Exception if $this->_commentID is not set.
     * @throws Exception if the status oassed as argument is invalid.
     */
    function setValidityStatus(?string $status): void
    {
        if (!isset($this->_commentID)) {
            throw new Exception("No instrument instance selected");
        }

        if (!in_array($status, $this->_validityOptions)) {
            throw new Exception('Invalid administration status');
        }

        $GLOBALS['DB']->update(
            'flag',
            array('Validity' => $status),
            array('CommentID' => $this->_commentID)
        );
        $this->select($this->_commentID);
    }

    /**
     * Sets the current exclusion status of the instrument
     *
     * @param string|null $status the new status from the set (NULL, 'Fail', 'Pass')
     *
     * @return void
     *
     * @throws LorisException if the database update fails.
     * @throws Exception if $this->_commentID is not set.
     * @throws Exception if the status oassed as argument is invalid.
     */
    function setExclusionStatus(?string $status): void
    {
        if (!isset($this->_commentID)) {
            throw new Exception("No instrument instance selected");
        }

        if (!in_array($status, $this->_exclusionOptions)) {
            throw new Exception('Invalid exclusion status');
        }

        $GLOBALS['DB']->update(
            'flag',
            array('Exclusion' => $status),
            array('CommentID' => $this->_commentID)
        );
        $this->select($this->_commentID);
    }

    /**
     * Copies the values of all statuses (administration, validity, exclusion and data entry)
     * to another NDB_BVL_InstrumentStatus instance, overwriting the current values they have.
     *
     * @throws Exception if the comment ID of the status passed as argument is NULL.
     * @throws Exception if the status instance passed as argument is $this.
     * @throws Exception if the select function was not invoked on $this before invoking this function.
     */
    function copyTo(NDB_BVL_InstrumentStatus $statusTo) : void
    {
        // Validate argument and current object state
        if ($statusTo === $this) {
            throw new Exception("Status values cannot be copied onto themselves");
        }

        if (is_null($statusTo->_commentID)) {
            throw new Exception("Invalid statusTo argument to copyStatusesTo: _commentID field is null");
        }

        if (is_null($this->_commentID)) {
            throw new Exception("Cannot invoke copyStatusesTo before a select is done");
        }

        // Copy all the statuses from $this to $statusTo
        $statusTo->setAdministrationStatus($this->getAdministrationStatus());
        $statusTo->setDataEntryStatus($this->getDataEntryStatus());
        $statusTo->setExclusionStatus($this->getExclusionStatus());
        $statusTo->setValidityStatus($this->getValidityStatus());
    }

    /**
     * Sets the administration, exclusion, validity and data entry statuses to null.
     *
     * @throws Exception if the operation could not be executed successfully.
     */
    function resetStatuses() : void
    {
        $this->setAdministrationStatus(null);
        $this->setExclusionStatus(null);
        $this->setValidityStatus(null);
        $this->setDataEntryStatus(null);
    }
}
