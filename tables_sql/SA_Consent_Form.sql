CREATE TABLE `SA_Consent_Form` (
`CommentID` varchar(255) NOT NULL default '',

                            `UserID` varchar(255) default NULL,

                            `Date_taken` date DEFAULT NULL,

                            `Examiner` varchar(255) default NULL,

                            `Testdate` timestamp DEFAULT CURRENT_TIMESTAMP ON UPDATE CURRENT_TIMESTAMP,

                            `Data_entry_completion_status` enum('Incomplete','Complete') NOT NULL default 'Incomplete',
`SA_consent` enum('yes','no') default NULL,
`data_collection` varchar(255) default NULL,
PRIMARY KEY  (`CommentID`)

              ) ENGINE=InnoDB DEFAULT CHARSET=utf8;


INSERT INTO test_names(Test_name, Full_name, Sub_Group, isDirectEntry) VALUES('SA_Consent_Form', "IBIS SA Consent Form", 6, 1);
INSERT INTO instrument_subtests (Test_name, Subtest_name, Description, Order_number) VALUES ('SA_Consent_Form', 'SA_Consent_Form_page2', "Page2", 1);


INSERT INTO `consent`(`Name`,`Label`) VALUES ('SA_consent', 'SA Consent');

cd /var/www/loris/htdocs/js
ln -s ../../project/instruments/js/SA_consent.js
ln -s ../../project/instruments/js/SA_consent_final_submit.js

cd /var/www/loris/smarty/templates/email
ln -s ../../../project/templates/email/SA_consent.tpl

cd /var/www/loris/htdocs
ln -s ../project/tools/UpdateSAConsent.php
ln -s ../project/modules/environment_residential_history/ajax/UpdateSAConsent.php

cd /var/www/loris/htdocs/images
ln -s ../../project/instruments/images/IBIS_Consent_SA_PHI_HR.pdf
ln -s ../../project/instruments/images/IBIS_Consent_SA_PHI_LR.pdf
ln -s ../../project/instruments/images/IBIS_Consent_SA_SEA_HR.pdf
ln -s ../../project/instruments/images/IBIS_Consent_SA_SEA_LR.pdf
ln -s ../../project/instruments/images/IBIS_Consent_SA_STL_HR.pdf
ln -s ../../project/instruments/images/IBIS_Consent_SA_STL_LR.pdf
ln -s ../../project/instruments/images/IBIS_Consent_SA_UNC_HR.pdf
ln -s ../../project/instruments/images/IBIS_Consent_SA_UNC_LR.pdf