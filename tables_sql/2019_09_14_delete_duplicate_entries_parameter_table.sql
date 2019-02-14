-- Removing Duplicate key issues
DELETE FROM `parameter_type` WHERE `Name`='csbs_emotion_eye_gaze_weighted';
DELETE FROM `parameter_type` WHERE `Name`='csbs_communication_weighted';
DELETE FROM `parameter_type` WHERE `Name`='csbs_gestures_weighted';
DELETE FROM `parameter_type` WHERE `Name`='csbs_sounds_weighted';
DELETE FROM `parameter_type` WHERE `Name`='csbs_words_weighted';
DELETE FROM `parameter_type` WHERE `Name`='csbs_understanding_weighted';
DELETE FROM `parameter_type` WHERE `Name`='csbs_object_use_weighted';
