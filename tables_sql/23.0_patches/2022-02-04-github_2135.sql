ALTER TABLE Saliva_Collection_Tracking_Form
    CHANGE sq1 subject_need_collection enum('yes','no','0'),
    CHANGE sq2 subject_how_collected enum('At_Visit','Via_Mail'),
    CHANGE sq3a subject_kit_used varchar(100),
    CHANGE sq3 subject_visit_collection_date date,
    CHANGE sq4 subject_visit_mailed_to_UNC date,
    CHANGE sq4_status subject_visit_mailed_to_UNC_status varchar(100),
    CHANGE sq5 subject_visit_tracking_number varchar(255),
    CHANGE sq6 subject_mail_receive varchar(255),
    CHANGE sq8 subject_mail_tracking_number varchar(255),
    CHANGE pq1 proband_need_collection enum('yes','no','0'),
    CHANGE pq2 proband_need_signed_consent enum('yes','no','0'),
    CHANGE pq3a proband_kit_used varchar(100),
    CHANGE pq3 proband_consent varchar(255),
    CHANGE pq6 proband_how_collected varchar(255),
    CHANGE pq7 proband_visit_collection_date date,
    CHANGE pq8 proband_visit_tracking_number varchar(255),
    CHANGE pq9 proband_visit_mailed_to_UNC date,
    CHANGE pq9_status proband_visit_mailed_to_UNC_status varchar(100),
    CHANGE pq10 proband_mail_receive varchar(255),
    CHANGE pq_tracking_no proband_mail_tracking_number varchar(255),
    CHANGE mq1 mother_need_collection enum('yes','no','0'),
    CHANGE mq2 mother_how_collected enum('At_Visit','Via_Mail'),
    CHANGE mq3 mother_visit_collection_date date,
    CHANGE mq4 mother_visit_mailed_to_UNC date,
    CHANGE mq4_status mother_visit_mailed_to_UNC_status varchar(100),
    CHANGE mq5 mother_visit_tracking_number varchar(255),
    CHANGE mq6 mother_mail_receive varchar(255),
    CHANGE mq_tracking_no mother_mail_tracking_number varchar(255),
    CHANGE fq1 father_need_collection enum('yes','no','0'),
    CHANGE fq2 father_how_collected varchar(100),
    CHANGE fq3 father_visit_collection_date date,
    CHANGE fq4 father_visit_mailed_to_UNC date,
    CHANGE fq4_status father_visit_mailed_to_UNC_status varchar(100),
    CHANGE fq5 father_visit_tracking_number varchar(255),
    CHANGE fq6 father_mail_receive varchar(255),
    CHANGE fq_tracking_no father_mail_tracking_number varchar(255),
    CHANGE aq1 delivered_to_lab varchar(255),
    CHANGE other_date_delivered delivered_to_lab_date varchar(100),
    CHANGE other_staff_delivered delivered_to_lab_by varchar(100),
    CHANGE aq2 have_family_id varchar(255),
    CHANGE aq3 family_id varchar(255);

# To update the parameter table so that the dictionary builder
# doesn't need to be run
UPDATE parameter_type
    SET Name='Saliva_Collection_Tracking_Form_subject_need_collection',
        SourceField='subject_need_collection'
WHERE Name='Saliva_Collection_Tracking_Form_sq1';

UPDATE parameter_type
SET Name='Saliva_Collection_Tracking_Form_subject_how_collected',
    SourceField='subject_how_collected'
WHERE Name='Saliva_Collection_Tracking_Form_sq2';

UPDATE parameter_type
SET Name='Saliva_Collection_Tracking_Form_subject_kit_used',
    SourceField='subject_kit_used'
WHERE Name='Saliva_Collection_Tracking_Form_sq3a';

UPDATE parameter_type
SET Name='Saliva_Collection_Tracking_Form_subject_visit_collection_date',
    SourceField='subject_visit_collection_date'
WHERE Name='Saliva_Collection_Tracking_Form_sq3';

UPDATE parameter_type
SET Name='Saliva_Collection_Tracking_Form_subject_visit_mailed_to_UNC',
    SourceField='subject_visit_mailed_to_UNC'
WHERE Name='Saliva_Collection_Tracking_Form_sq4';

UPDATE parameter_type
SET Name='Saliva_Collection_Tracking_Form_subject_visit_mailed_to_UNC_status',
    SourceField='subject_visit_mailed_to_UNC_status'
WHERE Name='Saliva_Collection_Tracking_Form_sq4_status';

UPDATE parameter_type
SET Name='Saliva_Collection_Tracking_Form_subject_visit_tracking_number',
    SourceField='subject_visit_tracking_number'
WHERE Name='Saliva_Collection_Tracking_Form_sq5';

UPDATE parameter_type
SET Name='Saliva_Collection_Tracking_Form_subject_mail_receive',
    SourceField='subject_mail_receive'
WHERE Name='Saliva_Collection_Tracking_Form_sq6';

UPDATE parameter_type
SET Name='Saliva_Collection_Tracking_Form_subject_mail_tracking_number',
    SourceField='subject_mail_tracking_number'
WHERE Name='Saliva_Collection_Tracking_Form_sq8';

UPDATE parameter_type
SET Name='Saliva_Collection_Tracking_Form_proband_need_collection',
    SourceField='proband_need_collection'
WHERE Name='Saliva_Collection_Tracking_Form_pq1';

UPDATE parameter_type
SET Name='Saliva_Collection_Tracking_Form_',
    SourceField='proband_need_signed_consent'
WHERE Name='Saliva_Collection_Tracking_Form_pq2';

UPDATE parameter_type
SET Name='Saliva_Collection_Tracking_Form_proband_kit_used',
    SourceField='proband_kit_used'
WHERE Name='Saliva_Collection_Tracking_Form_pq3a';

UPDATE parameter_type
SET Name='Saliva_Collection_Tracking_Form_proband_consent',
    SourceField='proband_consent'
WHERE Name='Saliva_Collection_Tracking_Form_pq3';

UPDATE parameter_type
SET Name='Saliva_Collection_Tracking_Form_proband_how_collected',
    SourceField='proband_how_collected'
WHERE Name='Saliva_Collection_Tracking_Form_pq6';

UPDATE parameter_type
SET Name='Saliva_Collection_Tracking_Form_proband_visit_collection_date',
    SourceField='proband_visit_collection_date'
WHERE Name='Saliva_Collection_Tracking_Form_pq7';

UPDATE parameter_type
SET Name='Saliva_Collection_Tracking_Form_proband_visit_tracking_number',
    SourceField='proband_visit_tracking_number'
WHERE Name='Saliva_Collection_Tracking_Form_pq8';

UPDATE parameter_type
SET Name='Saliva_Collection_Tracking_Form_proband_visit_mailed_to_UNC',
    SourceField='proband_visit_mailed_to_UNC'
WHERE Name='Saliva_Collection_Tracking_Form_pq9';

UPDATE parameter_type
SET Name='Saliva_Collection_Tracking_Form_proband_visit_mailed_to_UNC_status',
    SourceField='proband_visit_mailed_to_UNC_status'
WHERE Name='Saliva_Collection_Tracking_Form_pq9_status';

UPDATE parameter_type
SET Name='Saliva_Collection_Tracking_Form_proband_mail_receive',
    SourceField='proband_mail_receive'
WHERE Name='Saliva_Collection_Tracking_Form_pq10';

UPDATE parameter_type
SET Name='Saliva_Collection_Tracking_Form_proband_mail_tracking_number',
    SourceField='proband_mail_tracking_number'
WHERE Name='Saliva_Collection_Tracking_Form_pq_tracking_no';

UPDATE parameter_type
SET Name='Saliva_Collection_Tracking_Form_mother_need_collection',
    SourceField='mother_need_collection'
WHERE Name='Saliva_Collection_Tracking_Form_mq1';

UPDATE parameter_type
SET Name='Saliva_Collection_Tracking_Form_mother_how_collected',
    SourceField='mother_how_collected'
WHERE Name='Saliva_Collection_Tracking_Form_mq2';

UPDATE parameter_type
SET Name='Saliva_Collection_Tracking_Form_mother_visit_collection_date',
    SourceField='mother_visit_collection_date'
WHERE Name='Saliva_Collection_Tracking_Form_mq3';

UPDATE parameter_type
SET Name='Saliva_Collection_Tracking_Form_mother_visit_mailed_to_UNC',
    SourceField='mother_visit_mailed_to_UNC'
WHERE Name='Saliva_Collection_Tracking_Form_mq4';

UPDATE parameter_type
SET Name='Saliva_Collection_Tracking_Form_mother_visit_mailed_to_UNC_status',
    SourceField='mother_visit_mailed_to_UNC_status'
WHERE Name='Saliva_Collection_Tracking_Form_mq4_status';

UPDATE parameter_type
SET Name='Saliva_Collection_Tracking_Form_mother_visit_tracking_number',
    SourceField='mother_visit_tracking_number'
WHERE Name='Saliva_Collection_Tracking_Form_mq5';

UPDATE parameter_type
SET Name='Saliva_Collection_Tracking_Form_mother_mail_receive',
    SourceField='mother_mail_receive'
WHERE Name='Saliva_Collection_Tracking_Form_mq6';

UPDATE parameter_type
SET Name='Saliva_Collection_Tracking_Form_mother_mail_tracking_number',
    SourceField='mother_mail_tracking_number'
WHERE Name='Saliva_Collection_Tracking_Form_mq_tracking_no';

UPDATE parameter_type
SET Name='Saliva_Collection_Tracking_Form_father_need_collection',
    SourceField='father_need_collection'
WHERE Name='Saliva_Collection_Tracking_Form_fq1';

UPDATE parameter_type
SET Name='Saliva_Collection_Tracking_Form_father_how_collected',
    SourceField='father_how_collected'
WHERE Name='Saliva_Collection_Tracking_Form_fq2';

UPDATE parameter_type
SET Name='Saliva_Collection_Tracking_Form_father_visit_collection_date',
    SourceField='father_visit_collection_date'
WHERE Name='Saliva_Collection_Tracking_Form_fq3';

UPDATE parameter_type
SET Name='Saliva_Collection_Tracking_Form_father_visit_mailed_to_UNC',
    SourceField='father_visit_mailed_to_UNC'
WHERE Name='Saliva_Collection_Tracking_Form_fq4';

UPDATE parameter_type
SET Name='Saliva_Collection_Tracking_Form_father_visit_mailed_to_UNC_status',
    SourceField='father_visit_mailed_to_UNC_status'
WHERE Name='Saliva_Collection_Tracking_Form_fq4_status';

UPDATE parameter_type
SET Name='Saliva_Collection_Tracking_Form_father_visit_tracking_number',
    SourceField='father_visit_tracking_number'
WHERE Name='Saliva_Collection_Tracking_Form_fq5';

UPDATE parameter_type
SET Name='Saliva_Collection_Tracking_Form_father_mail_receive',
    SourceField='father_mail_receive'
WHERE Name='Saliva_Collection_Tracking_Form_fq6';

UPDATE parameter_type
SET Name='Saliva_Collection_Tracking_Form_father_mail_tracking_number',
    SourceField='father_mail_tracking_number'
WHERE Name='Saliva_Collection_Tracking_Form_fq_tracking_no';

UPDATE parameter_type
SET Name='Saliva_Collection_Tracking_Form_delivered_to_lab',
    SourceField='delivered_to_lab'
WHERE Name='Saliva_Collection_Tracking_Form_aq1';

UPDATE parameter_type
SET Name='Saliva_Collection_Tracking_Form_delivered_to_lab_date',
    SourceField='delivered_to_lab_date'
WHERE Name='Saliva_Collection_Tracking_Form_other_date_delivered';

UPDATE parameter_type
SET Name='Saliva_Collection_Tracking_Form_delivered_to_lab_by',
    SourceField='delivered_to_lab_by'
WHERE Name='Saliva_Collection_Tracking_Form_other_staff_delivered';

UPDATE parameter_type
SET Name='Saliva_Collection_Tracking_Form_have_family_id',
    SourceField='have_family_id'
WHERE Name='Saliva_Collection_Tracking_Form_aq2';

UPDATE parameter_type
SET Name='Saliva_Collection_Tracking_Form_family_id',
    SourceField='family_id'
WHERE Name='Saliva_Collection_Tracking_Form_aq3';
