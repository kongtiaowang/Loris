-- Update participant_status_options labels for withdrawal.
UPDATE participant_status_options
    SET Description='Withdrew - Data can still be used'
    WHERE ID='14';

UPDATE participant_status_options
    SET Description='Withdrew Consent - DO NOT USE DATA'
    WHERE ID='15';
