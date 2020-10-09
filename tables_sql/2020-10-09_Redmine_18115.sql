ALTER TABLE asd_peds CHANGE q1_speech q1_speech_likert enum('1','2','3') default NULL;
ALTER TABLE asd_peds CHANGE q2_eye_contact q2_eye_contact_likert enum('1','2','3') default NULL;
ALTER TABLE asd_peds CHANGE q3_vocalizations q3_vocalizations_likert enum('1','2','3') default NULL;
ALTER TABLE asd_peds CHANGE q4_play q4_play_likert enum('1','2','3') default NULL;
ALTER TABLE asd_peds CHANGE q5_body_movements q5_body_movements_likert enum('1','2','3') default NULL;
ALTER TABLE asd_peds CHANGE q6_gestures q6_gestures_likert enum('1','2','3') default NULL;
ALTER TABLE asd_peds CHANGE q7_sensory q7_sensory_likert enum('1','2','3') default NULL;

ALTER TABLE asd_peds ADD q1_speech_dichotomous enum('1','3') default NULL AFTER q1_speech_likert;
ALTER TABLE asd_peds ADD q2_eye_contact_dichotomous enum('1','3') default NULL AFTER q2_eye_contact_likert;
ALTER TABLE asd_peds ADD q3_vocalizations_dichotomous enum('1','3') default NULL AFTER q3_vocalizations_likert;
ALTER TABLE asd_peds ADD q4_play_dichotomous enum('1','3') default NULL AFTER q4_play_likert;
ALTER TABLE asd_peds ADD q5_body_movements_dichotomous enum('1','3') default NULL AFTER q5_body_movements_likert;
ALTER TABLE asd_peds ADD q6_gestures_dichotomous enum('1','3') default NULL AFTER q6_gestures_likert;
ALTER TABLE asd_peds ADD q7_sensory_dichotomous enum('1','3') default NULL AFTER q7_sensory_likert;