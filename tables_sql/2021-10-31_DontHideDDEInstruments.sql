-- ----------------------------------------------------------------------------------------
-- Assigns the correct parent ID to setting IssueTrackerDataPath. The erroneous value was
-- "hidding" the list of DDE instruments defined by DoubleDataEntryInstruments and made it 
-- unaccessible/uneditable.
-- ----------------------------------------------------------------------------------------

UPDATE ConfigSettings
SET Parent = (
    SELECT ID
    FROM (
        SELECT *
        FROM ConfigSettings
    ) ConfigSettingsCopy
    WHERE Name='paths'
)
WHERE Name='IssueTrackerDataPath';
