<?php
/**
 * This file implements a class used for detecting conflicts for an instrument.
 *
 * PHP Version 7
 *
 * @category Main
 * @package  Loris
 * @author   Unknown(Samir?) <example@example.com>
 * @license  http://www.gnu.org/licenses/gpl-3.0.txt GPLv3
 * @link     https://www.github.com/aces/Loris-Trunk/
 */

/**
 * Implements a serious of helper functions for detecting/creating/managing the
 * conflicts_resolved table used by Loris's conflict resolver
 *
 * @category Main
 * @package  Loris
 * @author   Unknown(Samir?) <example@example.com>
 * @license  http://www.gnu.org/licenses/gpl-3.0.txt GPLv3
 * @link     https://www.github.com/aces/Loris-Trunk/
 */
class ConflictDetector
{

    /**
     * Detects of there are any conflicts between 2 given CommentIDs
     *
     * @param string $instrumentName The instrument being checked
     * @param string $commentId1     The first data entry CommentID
     * @param string $commentId2     The second data entry CommentID
     *
     * @return array An array of differences between the 2 data entry
     *               points.
     */
    static function detectConflictsForCommentIds(
        string $instrumentName,
        string $commentId1,
        string $commentId2
    ): array {
        if(\NDB_BVL_Battery::getInstrumentNameForCommentId($commentId1) != $instrumentName) {
            throw new InvalidArgumentException(
                "Instrument with comment ID $commentId1 is not of type $instrumentName"
            );
        }

        if(\NDB_BVL_Battery::getInstrumentNameForCommentId($commentId2) != $instrumentName) {
            throw new InvalidArgumentException(
                "Instrument with comment ID $commentId2 is not of type $instrumentName"
            );
        }

        $diffResult = array();

        // Get data entry status for $commentId1
        $status = new NDB_BVL_InstrumentStatus();
        $status->select($commentId1);
        if ($status->getDataEntryStatus() != 'Complete') {
            return $diffResult;
        }

        // Get data entry status for $commentId2
        $status = new NDB_BVL_InstrumentStatus();
        $status->select($commentId2);
        if ($status->getDataEntryStatus() != 'Complete') {
            return $diffResult;
        }

        // Create the instrument instance for $commentId1
        $instance1 = NDB_BVL_Instrument::factory(
            $instrumentName,
            $commentId1,
            ''
        );

        // Create the instrument instance for $commentId2
        $instance2 = NDB_BVL_Instrument::factory(
            $instrumentName,
            $commentId2,
            ''
        );

        // Run the diff
        $diffResult = self::diff($instance1, $instance2);

        // Return the diff result
        return $diffResult;
    }

    /**
     * Stores unresolved conflicts into the conflicts_unresolved table
     *
     * @param array $diffResult The output of detectConflictsForCommentIds
     *
     * @return void As a side-effect inserts into database.
     */
    static function recordUnresolvedConflicts(array $diffResult): void
    {
        foreach ($diffResult as $diffLine) {
            \NDB_Factory::singleton()->database()->replace('conflicts_unresolved', $diffLine);
        }

    }

    /**
     * Removes recorded conflicts from the conflicts_unresolved table
     * for a given line. Used before recording new conflicts into the
     * table to ensure that old/resolved conflicts don't stay around.
     *
     * @param array $diffLine The row to be removed from conflicts_unresolved
     *                        table
     *
     * @return void As a side-effect deletes from database
     */
    function clearConflictsForField(array $diffLine): void
    {
        $deleteWhere = array(
            'TableName'      => $diffLine['TableName'],
            'ExtraKeyColumn' => $diffLine['ExtraKeyColumn'],
            'ExtraKey1'      => $diffLine['ExtraKey1'],
            'ExtraKey2'      => $diffLine['ExtraKey2'],
            'FieldName'      => $diffLine['FieldName'],
            'CommentId1'     => $diffLine['CommentId1'],
            'CommentId2'     => $diffLine['CommentId2'],
        );

        \NDB_Factory::singleton()->database()->delete('conflicts_unresolved', $deleteWhere);
    }

    /**
     * Removes all conflicts for a given CommentID, so that we
     * can start from a clean state when inserting new comments
     *
     * @param string $commentId The commentID to remove conflicts for
     *
     * @return void As a side-effect deletes from database
     */
    static function clearConflictsForInstance(string $commentId): void
    {
        \NDB_Factory::singleton()->database()->delete(
            'conflicts_unresolved',
            array('CommentId1' => $commentId)
        );
    }

    /**
     * Determines if there are any conflicts for the given CommentID
     *
     * @param string $commentId The CommentID to check
     *
     * @return boolean True if there are conflicts that exist, false otherwise
     */
    static function isInstrumentInstanceInConflictState(string $commentId): bool
    {
        $conflictCount = \NDB_Factory::singleton()->database()->pselectOne(
            "SELECT COUNT(*) FROM conflicts_unresolved WHERE CommentId1=:CID",
            array('CID' => $commentId)
        );
        return ($conflictCount != 0);
    }

    /**
     * Examines two instances of an instrument and builds the list of fields with different
     * values. Note that these are ignored during this process:
     *
     *  - Fields in the instrument's _doubleDataEntryDiffIgnoreColumns array.
     *  - The text and textarea fields.
     *
     * @param NDB_BVL_Instrument $i1 First instrument instance
     * @param NDB_BVL_Instrument $i2 Second instrument instance
     *
     * @return array names of the fields with different values
     * @throws NotFound
     */
    static function diff(NDB_BVL_Instrument $i1, NDB_BVL_Instrument $i2) : array
    {
        $i1Class = get_class($i1);
        $i2Class = get_class($i2);
        if ($i1Class != $i2Class || ($i1->testName != $i2->testName)) {
            throw new InvalidArgumentException("Both instrument instances are not of the same type");
        }

        // Create an instance of the isntrument not tied to any comment ID
        $testName = $i1->testName;
        $emptyInstrument = NDB_BVL_Instrument::factory($testName, "", "");

        // Create all pages so that the internal instrument form is fully built
        // This is already done in the factory for LINST instruments
        if (get_class($emptyInstrument) != "Loris\Behavioural\NDB_BVL_Instrument_LINST") {
            $instrumentSubtests = $emptyInstrument->getSubtestList();
            foreach ($instrumentSubtests as $subtest) {
                $emptyInstrument->page = $subtest['Name'];
                $emptyInstrument->_setupForm();
            }
        }

        // Load both instance's data
        $i1InstanceData = NDB_BVL_Instrument::loadInstanceData($i1);
        $i2InstanceData = NDB_BVL_Instrument::loadInstanceData($i2);

        // Get all text and text areas in the internal instrument form
        $textElements  = $emptyInstrument->form->getTextElements();
        $scoreElements = $emptyInstrument->form->getScoreElements();

        // Build the list of fields that differ
        $diff = [];
        foreach ($i1InstanceData AS $column1 => $value1) {
            if (!in_array($column1, $i1->_doubleDataEntryDiffIgnoreColumns)
                && !in_array($column1, $textElements)
                && !in_array($column1, $scoreElements)
            ) {
                if ($i2InstanceData[$column1] != $value1) {
                    $diff[] = [
                        'TableName'      => $i1->table,
                        'FieldName'      => $column1,
                        'CommentId1'     => $i1->getCommentID(),
                        'Value1'         => $value1,
                        'CommentId2'     => $i2->getCommentID(),
                        'Value2'         => $i2InstanceData[$column1],
                        'ExtraKey1'      => '',
                        'ExtraKey2'      => '',
                    ];
                }
            }
        }

        // Return the diffs
        return $diff;
    }
}

