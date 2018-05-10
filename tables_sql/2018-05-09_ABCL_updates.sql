-- Modify enum values
-- Add the required new one
ALTER TABLE ABCL
CHANGE COLUMN `b_contact_with_close_friends`
`b_contact_with_close_friends` ENUM('less_than_1','0', '1', '2', '3') NULL DEFAULT NULL ;
ALTER TABLE ABCL
CHANGE COLUMN `d_how_many_times_do_family_or_friends_visit`
`d_how_many_times_do_family_or_friends_visit` ENUM('less_than_1','0', '1', '2', '3') NULL DEFAULT NULL ;

-- Update the data
UPDATE ABCL SET b_contact_with_close_friends='0'
WHERE b_contact_with_close_friends='less_than_1' ;
UPDATE ABCL SET d_how_many_times_do_family_or_friends_visit='0'
WHERE d_how_many_times_do_family_or_friends_visit='less_than_1' ;

-- Remove the no more needed enum value
ALTER TABLE ABCL
CHANGE COLUMN `b_contact_with_close_friends`
`b_contact_with_close_friends` ENUM('0', '1', '2', '3') NULL DEFAULT NULL ;
ALTER TABLE ABCL
CHANGE COLUMN `d_how_many_times_do_family_or_friends_visit`
`d_how_many_times_do_family_or_friends_visit` ENUM('0', '1', '2', '3') NULL DEFAULT NULL ;
