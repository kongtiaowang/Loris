-- Addresses Redmine 18054
-- Populates data from spreadsheet into ISPC_tracking_form for 54 UNC candidates
-- Fix column name typo

ALTER TABLE IPSC_tracking_form CHANGE `IPSC_consent_data` `IPSC_consent_date` date default NULL;

-- Update 1
UPDATE
    IPSC_tracking_form
SET
    Data_entry_completion_status = 'Complete',
    Date_taken = '2018-06-12',
    recruiter_asked_blood_draw = 'yes',
    ipsc_notes = "Waiting for ECHO, gave verbal consent"
WHERE
    CommentID LIKE '730091UNC0003%';

-- Update 2
UPDATE
    IPSC_tracking_form
SET
    Data_entry_completion_status = 'Complete',
    Date_taken = '2018-07-16',
    recruiter_asked_blood_draw = 'yes'
WHERE
    CommentID LIKE '145656UNC0006%';

-- Update 3
UPDATE
    IPSC_tracking_form
SET
    Data_entry_completion_status = 'Complete',
    recruiter_asked_blood_draw = 'yes',
    blood_draw_location = 'site',
    blood_draw_date = '2019-06-20'
WHERE
    CommentID LIKE '792210UNC0013%';

-- Update 4
UPDATE
    IPSC_tracking_form
SET
    Data_entry_completion_status = 'Complete',
    Date_taken = '2019-03-28',
    recruiter_asked_blood_draw = 'yes',
    blood_draw_location = 'take_home_kit_sent',
    ipsc_notes = 'I don''t anticipate them mailing it back in but they might come back for ECHO'
WHERE
    CommentID LIKE '396346UNC0035%';

-- Update 5
UPDATE
    IPSC_tracking_form
SET
    Data_entry_completion_status = 'Complete',
    Date_taken = '2018-10-26',
    recruiter_asked_blood_draw = 'no',
    ipsc_notes = 'Did not respond to me, maybe do ECHO'
WHERE
    CommentID LIKE '155712UNC0016%';

-- Update 6
UPDATE
    IPSC_tracking_form
SET
    Data_entry_completion_status = 'Complete',
    recruiter_asked_blood_draw = 'yes',
    blood_draw_location = 'site',
    blood_draw_date = '2019-05-03'
WHERE
    CommentID LIKE '236316UNC0023%';

-- Update 7
UPDATE
    IPSC_tracking_form
SET
    Data_entry_completion_status = 'Complete',
    recruiter_asked_blood_draw = 'yes'
WHERE
    CommentID LIKE '836214UNC0033%';

-- Update 8
UPDATE
    IPSC_tracking_form
SET
    Data_entry_completion_status = 'Complete',
    recruiter_asked_blood_draw = 'yes',
    blood_draw_location = 'site',
    blood_draw_date = '2019-05-01'
WHERE
    CommentID LIKE '927772UNC0018%';

-- Update 9
UPDATE
    IPSC_tracking_form
SET
    Data_entry_completion_status = 'Complete',
    recruiter_asked_blood_draw = 'yes'
WHERE
    CommentID LIKE '167672UNC0021%';

-- Update 10
UPDATE
    IPSC_tracking_form
SET
    Data_entry_completion_status = 'Complete',
    Date_taken = '2019-06-24',
    recruiter_asked_blood_draw = 'yes',
    ipsc_notes = 'Parent gave verbal consent, child refused assent'
WHERE
    CommentID LIKE '845807UNC0050%';

-- Update 11
UPDATE
    IPSC_tracking_form
SET
    Data_entry_completion_status = 'Complete',
    Date_taken = '2018-11-05',
    recruiter_asked_blood_draw = 'yes',
    ipsc_notes = 'Waiting for ECHO, gave verbal consent'
WHERE
    CommentID LIKE '950194UNC0022%';

-- Update 12
UPDATE
    IPSC_tracking_form
SET
    Data_entry_completion_status = 'Complete',
    Date_taken = '2018-10-22',
    recruiter_asked_blood_draw = 'yes',
    ipsc_notes = 'Waiting for ECHO, gave verbal consent'
WHERE
    CommentID LIKE '649998UNC0031%';

-- Update 13
UPDATE
    IPSC_tracking_form
SET
    Data_entry_completion_status = 'Complete',
    Date_taken = '2018-11-07',
    recruiter_asked_blood_draw = 'yes',
    ipsc_notes = 'Waiting for ECHO, gave verbal consent'
WHERE
    CommentID LIKE '220411UNC0027%';

-- Update 14
UPDATE
    IPSC_tracking_form
SET
    Data_entry_completion_status = 'Complete',
    Date_taken = '2019-02-18',
    recruiter_asked_blood_draw = 'yes'
WHERE
    CommentID LIKE '302575UNC0040%';

-- Update 15
UPDATE
    IPSC_tracking_form
SET
    Data_entry_completion_status = 'Complete',
    recruiter_asked_blood_draw = 'yes',
    blood_draw_location = 'site',
    blood_draw_date = '2019-05-13'
WHERE
    CommentID LIKE '856858UNC0045%';

-- Update 16
UPDATE
    IPSC_tracking_form
SET
    Data_entry_completion_status = 'Complete',
    Date_taken = '2019-09-23',
    recruiter_asked_blood_draw = 'yes'
WHERE
    CommentID LIKE '389321UNC0048%';

-- Update 17
UPDATE
    IPSC_tracking_form
SET
    Data_entry_completion_status = 'Complete',
    recruiter_asked_blood_draw = 'yes',
    blood_draw_location = 'take_home_kit_sent',
    blood_draw_date = '2019-07-09'
WHERE
    CommentID LIKE '713824UNC0046%';

-- Update 18
UPDATE
    IPSC_tracking_form
SET
    Data_entry_completion_status = 'Complete',
    recruiter_asked_blood_draw = 'yes',
    blood_draw_location = 'site',
    blood_draw_date = '2019-11-01'
WHERE
    CommentID LIKE '413692UNC0054%';

-- Update 19
UPDATE
    IPSC_tracking_form
SET
    Data_entry_completion_status = 'Complete',
    Date_taken = '2018-10-08',
    recruiter_asked_blood_draw = 'no',
    ipsc_notes = 'Did not respond to me, maybe do ECHO'
WHERE
    CommentID LIKE '841306UNC0049%';

-- Update 20
UPDATE
    IPSC_tracking_form
SET
    Data_entry_completion_status = 'Complete',
    Date_taken = '2019-06-12',
    recruiter_asked_blood_draw = 'yes',
    ipsc_notes = 'afraid of needles'
WHERE
    CommentID LIKE '515353UNC0059%';

-- Update 21
UPDATE
    IPSC_tracking_form
SET
    Data_entry_completion_status = 'Complete',
    recruiter_asked_blood_draw = 'yes',
    blood_draw_location = 'site',
    blood_draw_date = '2019-10-11'
WHERE
    CommentID LIKE '540777UNC0070%';

-- Update 22
UPDATE
    IPSC_tracking_form
SET
    Data_entry_completion_status = 'Complete',
    recruiter_asked_blood_draw = 'yes',
    ipsc_notes = 'hates needles'
WHERE
    CommentID LIKE '600014UNC0073%';

-- Update 23
UPDATE
    IPSC_tracking_form
SET
    Data_entry_completion_status = 'Complete',
    recruiter_asked_blood_draw = 'yes',
    blood_draw_location = 'site',
    blood_draw_date = '2019-03-14'
WHERE
    CommentID LIKE '910593UNC0076%';

-- Update 24
UPDATE
    IPSC_tracking_form
SET
    Data_entry_completion_status = 'Complete',
    Date_taken = '2018-08-30',
    recruiter_asked_blood_draw = 'yes',
    ipsc_notes = 'waiting for ECHO, gave verbal consent'
WHERE
    CommentID LIKE '389521UNC0077%';

-- Update 25
UPDATE
    IPSC_tracking_form
SET
    Data_entry_completion_status = 'Complete',
    Date_taken = '2019-01-21',
    recruiter_asked_blood_draw = 'no',
    ipsc_notes = 'did not respond to me, maybe do ECHO'
WHERE
    CommentID LIKE '420719UNC0078%';

-- Update 26
UPDATE
    IPSC_tracking_form
SET
    Data_entry_completion_status = 'Complete',
    recruiter_asked_blood_draw = 'yes',
    blood_draw_location = 'site',
    blood_draw_date = '2019-04-18'
WHERE
    CommentID LIKE '568175UNC0084%';

-- Update 27
UPDATE
    IPSC_tracking_form
SET
    Data_entry_completion_status = 'Complete',
    recruiter_asked_blood_draw = 'yes',
    blood_draw_location = 'site',
    blood_draw_date = '2019-11-05'
WHERE
    CommentID LIKE '364850UNC0087%';

-- Update 28
UPDATE
    IPSC_tracking_form
SET
    Data_entry_completion_status = 'Complete',
    recruiter_asked_blood_draw = 'yes',
    blood_draw_location = 'site',
    blood_draw_date = '2019-09-11'
WHERE
    CommentID LIKE '641078UNC0091%';

-- Update 29
UPDATE
    IPSC_tracking_form
SET
    Data_entry_completion_status = 'Complete',
    recruiter_asked_blood_draw = 'yes',
    blood_draw_location = 'site',
    blood_draw_date = '2019-08-23'
WHERE
    CommentID LIKE '429591UNC0092%';

-- Update 30
UPDATE
    IPSC_tracking_form
SET
    Data_entry_completion_status = 'Complete',
    recruiter_asked_blood_draw = 'yes',
    blood_draw_location = 'site',
    blood_draw_date = '2019-06-04'
WHERE
    CommentID LIKE '595729UNC0096%';

-- Update 31
UPDATE
    IPSC_tracking_form
SET
    Data_entry_completion_status = 'Complete',
    Date_taken = '2020-02-20',
    recruiter_asked_blood_draw = 'yes',
    blood_draw_location = 'site',
    blood_draw_date = '2020-02-21',
    ipsc_notes = 'Upcoming visit - dad anticipates them being okay with it'
WHERE
    CommentID LIKE '867271UNC0097%';

-- Update 32
UPDATE
    IPSC_tracking_form
SET
    Data_entry_completion_status = 'Complete',
    recruiter_asked_blood_draw = 'yes',
    blood_draw_location = 'site',
    blood_draw_date = '2019-04-22'
WHERE
    CommentID LIKE '798424UNC0101%';

-- Update 33
UPDATE
    IPSC_tracking_form
SET
    Data_entry_completion_status = 'Complete',
    Date_taken = '2019-02-25',
    recruiter_asked_blood_draw = 'yes'
WHERE
    CommentID LIKE '119906UNC0104%';

-- Update 34
UPDATE
    IPSC_tracking_form
SET
    Data_entry_completion_status = 'Complete',
    recruiter_asked_blood_draw = 'yes',
    blood_draw_location = 'site',
    blood_draw_date = '2019-08-07'
WHERE
    CommentID LIKE '983222UNC0106%';

-- Update 35
UPDATE
    IPSC_tracking_form
SET
    Data_entry_completion_status = 'Complete',
    Date_taken = '2020-02-17',
    recruiter_asked_blood_draw = 'yes',
    blood_draw_location = 'site',
    blood_draw_date = '2020-02-18',
    ipsc_notes = 'Upcoming visit - mom anticipates them being okay with it'
WHERE
    CommentID LIKE '903923UNC0107%';

-- Update 36
UPDATE
    IPSC_tracking_form
SET
    Data_entry_completion_status = 'Complete',
    Date_taken = '2019-10-16',
    recruiter_asked_blood_draw = 'no',
    ipsc_notes = 'did not respond to me, maybe do ECHO'
WHERE
    CommentID LIKE '174982UNC0115%';

-- Update 37
UPDATE
    IPSC_tracking_form
SET
    Data_entry_completion_status = 'Complete',
    Date_taken = '2020-03-02',
    recruiter_asked_blood_draw = 'yes'
WHERE
    CommentID LIKE '868632UNC0119%';

-- Update 38
UPDATE
    IPSC_tracking_form
SET
    Data_entry_completion_status = 'Complete',
    recruiter_asked_blood_draw = 'yes',
    blood_draw_location = 'site',
    blood_draw_date = '2019-05-06'
WHERE
    CommentID LIKE '911817UNC0111%';

-- Update 39
UPDATE
    IPSC_tracking_form
SET
    Data_entry_completion_status = 'Complete',
    recruiter_asked_blood_draw = 'yes',
    blood_draw_location = 'site',
    blood_draw_date = '2019-05-10'
WHERE
    CommentID LIKE '710567UNC0121%';

-- Update 40
UPDATE
    IPSC_tracking_form
SET
    Data_entry_completion_status = 'Complete',
    Date_taken = '2018-08-27',
    recruiter_asked_blood_draw = 'yes',
    ipsc_notes = 'waiting for ECHO, gave verbal consent'
WHERE
    CommentID LIKE '974849UNC0120%';

-- Update 41
UPDATE
    IPSC_tracking_form
SET
    Data_entry_completion_status = 'Complete',
    Date_taken = '2018-07-25',
    recruiter_asked_blood_draw = 'yes',
    ipsc_notes = 'waiting for ECHO, gave verbal consent'
WHERE
    CommentID LIKE '218286UNC0122%';

-- Update 42
UPDATE
    IPSC_tracking_form
SET
    Data_entry_completion_status = 'Complete',
    recruiter_asked_blood_draw = 'yes',
    ipsc_notes = 'no assent'
WHERE
    CommentID LIKE '623831UNC0143%';

-- Update 43
UPDATE
    IPSC_tracking_form
SET
    Data_entry_completion_status = 'Complete',
    Date_taken = '2019-01-07',
    recruiter_asked_blood_draw = 'yes'
WHERE
    CommentID LIKE '622437UNC0137%';

-- Update 44
UPDATE
    IPSC_tracking_form
SET
    Data_entry_completion_status = 'Complete',
    recruiter_asked_blood_draw = 'yes',
    blood_draw_location = 'site',
    blood_draw_date = '2019-04-24'
WHERE
    CommentID LIKE '710239UNC0154%';

-- Update 45
UPDATE
    IPSC_tracking_form
SET
    Data_entry_completion_status = 'Complete',
    recruiter_asked_blood_draw = 'yes'
WHERE
    CommentID LIKE '768690UNC0146%';

-- Update 46
UPDATE
    IPSC_tracking_form
SET
    Data_entry_completion_status = 'Complete',
    recruiter_asked_blood_draw = 'yes',
    blood_draw_location = 'take_home_kit_sent',
    ipsc_notes = 'Sent home with a kit, likely return for ECHO'
WHERE
    CommentID LIKE '443805UNC0148%';

-- Update 47
UPDATE
    IPSC_tracking_form
SET
    Data_entry_completion_status = 'Complete',
    recruiter_asked_blood_draw = 'yes',
    ipsc_notes = 'hates medical environments'
WHERE
    CommentID LIKE '216279UNC0150%';

-- Update 48
UPDATE
    IPSC_tracking_form
SET
    Data_entry_completion_status = 'Complete',
    Date_taken = '2018-07-30',
    recruiter_asked_blood_draw = 'no',
    ipsc_notes = 'did not respond to me, maybe do ECHO'
WHERE
    CommentID LIKE '309070UNC0192%';

-- Update 49
UPDATE
    IPSC_tracking_form
SET
    Data_entry_completion_status = 'Complete',
    recruiter_asked_blood_draw = 'yes'
WHERE
    CommentID LIKE '817034UNC0186%';


-- Update 50
UPDATE
    IPSC_tracking_form
SET
    Data_entry_completion_status = 'Complete',
    recruiter_asked_blood_draw = 'yes',
    blood_draw_location = 'site',
    blood_draw_date = '2019-07-30'
WHERE
    CommentID LIKE '496765UNC0188%';

-- Update 51
UPDATE
    IPSC_tracking_form
SET
    Data_entry_completion_status = 'Complete',
    recruiter_asked_blood_draw = 'yes'
WHERE
    CommentID LIKE '486701UNC0194%';

-- Update 52
UPDATE
    IPSC_tracking_form
SET
    Data_entry_completion_status = 'Complete',
    recruiter_asked_blood_draw = 'yes',
    blood_draw_location = 'site',
    blood_draw_date = '2019-11-21'
WHERE
    CommentID LIKE '388210UNC0201%';

-- Update 53
UPDATE
    IPSC_tracking_form
SET
    Data_entry_completion_status = 'Complete',
    recruiter_asked_blood_draw = 'yes'
WHERE
    CommentID LIKE '583629UNC0214%';

-- Update 54
UPDATE
    IPSC_tracking_form
SET
    Data_entry_completion_status = 'Complete',
    recruiter_asked_blood_draw = 'yes'
WHERE
    CommentID LIKE '257550UNC0216%';