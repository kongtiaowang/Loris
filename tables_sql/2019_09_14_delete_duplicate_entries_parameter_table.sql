-- Removing Duplicate key issues
DELETE from parameter_type_category_rel where ParameterTypeID IN (select ParameterTypeID from parameter_type where Name
IN('csbs_emotion_eye_gaze_weighted','csbs_communication_weighted',
'csbs_gestures_weighted','csbs_sounds_weighted','csbs_words_weighted','csbs_understanding_weighted','csbs_object_use_weighted'));

DELETE FROM `parameter_type` WHERE `Name`='csbs_emotion_eye_gaze_weighted';
DELETE FROM `parameter_type` WHERE `Name`='csbs_communication_weighted';
DELETE FROM `parameter_type` WHERE `Name`='csbs_gestures_weighted';
DELETE FROM `parameter_type` WHERE `Name`='csbs_sounds_weighted';
DELETE FROM `parameter_type` WHERE `Name`='csbs_words_weighted';
DELETE FROM `parameter_type` WHERE `Name`='csbs_understanding_weighted';
DELETE FROM `parameter_type` WHERE `Name`='csbs_object_use_weighted';
