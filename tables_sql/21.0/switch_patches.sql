-- switching to major 21.0
ALTER TABLE `candidate`
    CHANGE COLUMN `CenterID` `RegistrationCenterID` integer unsigned NOT NULL DEFAULT '0';

ALTER TABLE `candidate` CHANGE COLUMN Gender Sex enum('Male','Female');

ALTER TABLE `candidate` CHANGE COLUMN ProbandGender ProbandSex enum('Male','Female');

ALTER TABLE `tarchive` CHANGE PatientGender PatientSex varchar(255);
-- switching back to developer branch
  ALTER TABLE `candidate`
    CHANGE COLUMN `RegistrationCenterID` `CenterID` integer unsigned NOT NULL DEFAULT '0';

    ALTER TABLE `candidate` CHANGE COLUMN Sex Gender enum('Male','Female');

ALTER TABLE `candidate` CHANGE COLUMN ProbandSex ProbandGender enum('Male','Female');

ALTER TABLE `tarchive` CHANGE  PatientSex  PatientGender varchar(255);
