-- ===============================================================================================
--
-- Changes all fields of the form time_entered_room_* to type time (was varchar(100))
-- in form mri_parameter_ep.
--
-- ===============================================================================================


ALTER TABLE mri_parameter_ep CHANGE COLUMN time_entered_room_1 time_entered_room_1 time DEFAULT NULL;
ALTER TABLE mri_parameter_ep CHANGE COLUMN time_entered_room_2 time_entered_room_2 time DEFAULT NULL;
ALTER TABLE mri_parameter_ep CHANGE COLUMN time_entered_room_3 time_entered_room_3 time DEFAULT NULL;
ALTER TABLE mri_parameter_ep CHANGE COLUMN time_entered_room_4 time_entered_room_4 time DEFAULT NULL;
