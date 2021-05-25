-- ------------------------------------------------------------------------
--
-- Updates the list of examiners: adds Jaclyn Gunderson and Pang Chaxiong.
-- Both examiners will be associated to the UMN site.
--
-- ------------------------------------------------------------------------


INSERT INTO `examiners` (`full_name`, `radiologist`, `active`, `pending_approval`) VALUES ("Jaclyn Gunderson", 0, 'Y', 'N');
INSERT INTO `examiners` (`full_name`, `radiologist`, `active`, `pending_approval`) VALUES ("Pang Chaxiong", 0, 'Y', 'N');

INSERT INTO `examiners_psc_rel` (`examinerID`, `centerID`, `active`, `pending_approval`) SELECT `examinerID`, 11, 'Y', 'N' FROM `examiners` WHERE `full_name` = "Jaclyn Gunderson";
INSERT INTO `examiners_psc_rel` (`examinerID`, `centerID`, `active`, `pending_approval`) SELECT `examinerID`, 11, 'Y', 'N' FROM `examiners` WHERE `full_name` = "Pang Chaxiong";
