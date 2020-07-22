<?php
/**
 * This script addresses Redmine 18028 and does the following:
 * Splits and migrates pspq_1 data into pspq_SelfReport_mom and pspq_InformantReport_mom_on_dad
 * Splits and migrates pspq_2 data into pspq_SelfReport_dad and pspq_InformantReport_dad_on_mom
 *
 * PHP Version 7
 *
 * @category Main
 * @package  Loris
 * @author   Suzanne Lee <suzannelee.mcin@gmail.com>
 * @license  http://www.gnu.org/licenses/gpl-3.0.txt GPLv3
 * @link     https://www.github.com/aces/Loris/
 */

set_include_path(get_include_path().":../../libraries:../../../php/libraries:");

require_once __DIR__ . "/../../../vendor/autoload.php";
require_once "Database.class.inc";

$client = new NDB_Client();
$client->makeCommandLine();
$client->initialize('../../config.xml');

$db =& Database::singleton();

$confirm =false;

if (!empty($argv[1]) && $argv[1] == 'confirm') {
    $confirm = true;
}

$config = NDB_Config::singleton();
$db     = Database::singleton();

// All columns in the SelfReport tables
$pspq_self_cols = array(
                   "UserID",
                   "Examiner",
                   "Testdate",
                   "Data_entry_completion_status",
                   "Date_taken",
                   "Candidate_Age",
                   "Window_Difference",
                   "respondent_age",
                   "respondent",
                   "respondent_other",
                   "respondent_gender",
                   "q1_like_being_otherpeople",
                   "q2_hard_wordsout_smoothly",
                   "q3_comfortable_unexpectedchanges",
                   "q4_hard_avoid_sidetrack",
                   "q5_information_than_socialize",
                   "q6_talkinto_tryingnew",
                   "q7_intune_conversation",
                   "q8_warmup_unfamiliarplace",
                   "q9_enjoy_socialsituations",
                   "q10_voice_flat_monotone",
                   "q11_disconnected_outofsync_convo",
                   "q12_easy_approach",
                   "q13_strongneed_sameness",
                   "q14_others_dont_understand",
                   "q15_flexible",
                   "q16_situations_meetnew_people",
                   "q17_talktoomuch_certain_topics",
                   "q18_conversation_tobe_polite",
                   "q19_lookforward_newthings",
                   "q20_speak_tooloud_softly",
                   "q21_tell_someone_not_interested",
                   "q22_hardtime_change_routine",
                   "q23_good_smalltalk",
                   "q24_act_myways",
                   "q25_connecting_people",
                   "q26_peoplefrustrated",
                   "q27_conversation_boresme",
                   "q28_warmfriendly_others",
                   "q29_longpauses_conversations",
                   "q30_alter_dailyroutine",
                   "q31_alone_ratherthan_withothers",
                   "q32_losetrack_talking",
                   "q33_follow_routine",
                   "q34_change_topic",
                   "q35_doingthings_knownway",
                   "q36_enjoy_chatting",
                  );

// All columns in the InformantReport tables
$pspq_informant_cols = array(
                        "UserID",
                        "Examiner",
                        "Testdate",
                        "Data_entry_completion_status",
                        "Date_taken",
                        "Candidate_Age",
                        "Window_Difference",
                        "respondent_age",
                        "respondent",
                        "respondent_other",
                        "respondent_gender",
                        "informant_confidence",
                        "informant",
                        "informant_other",
                        "informant_gender",
                        "qi1_like_being_otherpeople",
                        "qi2_hard_wordsout_smoothly",
                        "qi3_comfortable_unexpectedchanges",
                        "qi4_hard_avoid_sidetrack",
                        "qi5_information_than_socialize",
                        "qi6_talkinto_tryingnew",
                        "qi7_intune_conversation",
                        "qi8_warmup_unfamiliarplace",
                        "qi9_enjoy_socialsituations",
                        "qi10_voice_flat_monotone",
                        "qi11_disconnected_outofsync_convo",
                        "qi12_easy_approach",
                        "qi13_strongneed_sameness",
                        "qi14_others_dont_understand",
                        "qi15_flexible",
                        "qi16_situations_meetnew_people",
                        "qi17_talktoomuch_certain_topics",
                        "qi18_conversation_tobe_polite",
                        "qi19_lookforward_newthings",
                        "qi20_speak_tooloud_softly",
                        "qi21_tell_someone_not_interested",
                        "qi22_hardtime_change_routine",
                        "qi23_good_smalltalk",
                        "qi24_act_myways",
                        "qi25_connecting_people",
                        "qi26_peoplefrustrated",
                        "qi27_conversation_boresme",
                        "qi28_warmfriendly_others",
                        "qi29_longpauses_conversations",
                        "qi30_alter_dailyroutine",
                        "qi31_alone_ratherthan_withothers",
                        "qi32_losetrack_talking",
                        "qi33_follow_routine",
                        "qi34_change_topic",
                        "qi35_doingthings_knownway",
                        "qi36_enjoy_chatting",
                        "comments",
                       );

if ($confirm === false) {
    /*
    * PSPQ1 (FIRST HALF OF QUESTIONS) --> pspq_SelfReport_mom
    * PSPQ1 (SECOND HALF OF QUESTIONS) --> pspq_InformantReport_mom_on_dad
    */

    // Get TestIDs for PSPQ Mom instruments
    $test_id_pspq_1   = 77;
    $test_id_self_mom = 167;
    $test_id_informant_mom_on_dad = 169;

    // All pspq_1 comment ids
    $pspq_1_comment_ids_array = $db->pselect(
        "SELECT
            CommentID
        FROM
            pspq_1
        ",
        array()
    );

    foreach ($pspq_1_comment_ids_array as $cid) {
        $is_dde = false;

        // CommentID containing the TestID of pspq_1
        $old_cid = $cid["CommentID"];

        // Temporarily remove DDE_
        if (substr($old_cid, 0, 4) == "DDE_") {
            $is_dde  = true;
            $old_cid = str_replace("DDE_", "", $old_cid);
        }

        $new_cid_self_report      = replaceTestID($old_cid, $test_id_pspq_1, $test_id_self_mom);
        $new_cid_informant_report = replaceTestID($old_cid, $test_id_pspq_1, $test_id_informant_mom_on_dad);

        // Put DDE_ back
        if ($is_dde) {
            $old_cid = "DDE_" . $old_cid;
            $new_cid_self_report      = "DDE_" . $new_cid_self_report;
            $new_cid_informant_report = "DDE_" . $new_cid_informant_report;
        }

        $row = $db->pselectRow(
            "SELECT
                *
            FROM
                pspq_1
            WHERE CommentID = :old_cid
            ",
            array("old_cid" => $old_cid)
        );

        // pspq_1 has "other" option for gender, while the newer pspq instruments don't
        if ($row["respondent_gender"] == "other") {
            $row["respondent_gender"] = null;
        }
        if ($row["informant_gender"] == "other") {
            $row["informant_gender"] = null;
        }

        // pspq_1 contains some empty strings which will cause errors when migrating the data
        foreach ($pspq_self_cols as $col) {
            if ($row[$col] == '') {
                $row[$col] = null;
            }
        }
        foreach ($pspq_informant_cols as $col) {
            if ($row[$col] == '') {
                $row[$col] = null;
            }
        }

        // Insert data into pspq_SelfReport_mom
        $db->insert(
            "pspq_SelfReport_mom",
            array(
             "CommentID"                        => $new_cid_self_report,
             "UserID"                           => $row["UserID"],
             "Examiner"                         => $row["Examiner"],
             "Testdate"                         => $row["Testdate"],
             "Data_entry_completion_status"     => $row["Data_entry_completion_status"],
             "Date_taken"                       => $row["Date_taken"],
             "Candidate_Age"                    => $row["Candidate_Age"],
             "Window_Difference"                => $row["Window_Difference"],
             "respondent_age"                   => $row["respondent_age"],
             "respondent"                       => $row["respondent"],
             "respondent_other"                 => $row["respondent_other"],
             "respondent_gender"                => $row["respondent_gender"],
             "q1_like_being_otherpeople"        => $row["q1_like_being_otherpeople"],
             "q2_hard_wordsout_smoothly"        => $row["q2_hard_wordsout_smoothly"],
             "q3_comfortable_unexpectedchanges" => $row["q3_comfortable_unexpectedchanges"],
             "q4_hard_avoid_sidetrack"          => $row["q4_hard_avoid_sidetrack"],
             "q5_information_than_socialize"    => $row["q5_information_than_socialize"],
             "q6_talkinto_tryingnew"            => $row["q6_talkinto_tryingnew"],
             "q7_intune_conversation"           => $row["q7_intune_conversation"],
             "q8_warmup_unfamiliarplace"        => $row["q8_warmup_unfamiliarplace"],
             "q9_enjoy_socialsituations"        => $row["q9_enjoy_socialsituations"],
             "q10_voice_flat_monotone"          => $row["q10_voice_flat_monotone"],
             "q11_disconnected_outofsync_convo" => $row["q11_disconnected_outofsync_convo"],
             "q12_easy_approach"                => $row["q12_easy_approach"],
             "q13_strongneed_sameness"          => $row["q13_strongneed_sameness"],
             "q14_others_dont_understand"       => $row["q14_others_dont_understand"],
             "q15_flexible"                     => $row["q15_flexible"],
             "q16_situations_meetnew_people"    => $row["q16_situations_meetnew_people"],
             "q17_talktoomuch_certain_topics"   => $row["q17_talktoomuch_certain_topics"],
             "q18_conversation_tobe_polite"     => $row["q18_conversation_tobe_polite"],
             "q19_lookforward_newthings"        => $row["q19_lookforward_newthings"],
             "q20_speak_tooloud_softly"         => $row["q20_speak_tooloud_softly"],
             "q21_tell_someone_not_interested"  => $row["q21_tell_someone_not_interested"],
             "q22_hardtime_change_routine"      => $row["q22_hardtime_change_routine"],
             "q23_good_smalltalk"               => $row["q23_good_smalltalk"],
             "q24_act_myways"                   => $row["q24_act_myways"],
             "q25_connecting_people"            => $row["q25_connecting_people"],
             "q26_peoplefrustrated"             => $row["q26_peoplefrustrated"],
             "q27_conversation_boresme"         => $row["q27_conversation_boresme"],
             "q28_warmfriendly_others"          => $row["q28_warmfriendly_others"],
             "q29_longpauses_conversations"     => $row["q29_longpauses_conversations"],
             "q30_alter_dailyroutine"           => $row["q30_alter_dailyroutine"],
             "q31_alone_ratherthan_withothers"  => $row["q31_alone_ratherthan_withothers"],
             "q32_losetrack_talking"            => $row["q32_losetrack_talking"],
             "q33_follow_routine"               => $row["q33_follow_routine"],
             "q34_change_topic"                 => $row["q34_change_topic"],
             "q35_doingthings_knownway"         => $row["q35_doingthings_knownway"],
             "q36_enjoy_chatting"               => $row["q36_enjoy_chatting"],
            )
        );

        // Insert data into pspq_InformantReport_mom_on_dad
        $db->insert(
            "pspq_InformantReport_mom_on_dad",
            array(
             "CommentID"                         => $new_cid_informant_report,
             "UserID"                            => $row["UserID"],
             "Examiner"                          => $row["Examiner"],
             "Testdate"                          => $row["Testdate"],
             "Data_entry_completion_status"      => $row["Data_entry_completion_status"],
             "Date_taken"                        => $row["Date_taken"],
             "Candidate_Age"                     => $row["Candidate_Age"],
             "Window_Difference"                 => $row["Window_Difference"],
             "respondent_age"                    => $row["respondent_age"],
             "respondent"                        => $row["respondent"],
             "respondent_other"                  => $row["respondent_other"],
             "respondent_gender"                 => $row["respondent_gender"],
             "informant_confidence"              => $row["informant_confidence"],
             "informant"                         => $row["informant"],
             "informant_other"                   => $row["informant_other"],
             "informant_gender"                  => $row["informant_gender"],
             "qi1_like_being_otherpeople"        => $row["qi1_like_being_otherpeople"],
             "qi2_hard_wordsout_smoothly"        => $row["qi2_hard_wordsout_smoothly"],
             "qi3_comfortable_unexpectedchanges" => $row["qi3_comfortable_unexpectedchanges"],
             "qi4_hard_avoid_sidetrack"          => $row["qi4_hard_avoid_sidetrack"],
             "qi5_information_than_socialize"    => $row["qi5_information_than_socialize"],
             "qi6_talkinto_tryingnew"            => $row["qi6_talkinto_tryingnew"],
             "qi7_intune_conversation"           => $row["qi7_intune_conversation"],
             "qi8_warmup_unfamiliarplace"        => $row["qi8_warmup_unfamiliarplace"],
             "qi9_enjoy_socialsituations"        => $row["qi9_enjoy_socialsituations"],
             "qi10_voice_flat_monotone"          => $row["qi10_voice_flat_monotone"],
             "qi11_disconnected_outofsync_convo" => $row["qi11_disconnected_outofsync_convo"],
             "qi12_easy_approach"                => $row["qi12_easy_approach"],
             "qi13_strongneed_sameness"          => $row["qi13_strongneed_sameness"],
             "qi14_others_dont_understand"       => $row["qi14_others_dont_understand"],
             "qi15_flexible"                     => $row["qi15_flexible"],
             "qi16_situations_meetnew_people"    => $row["qi16_situations_meetnew_people"],
             "qi17_talktoomuch_certain_topics"   => $row["qi17_talktoomuch_certain_topics"],
             "qi18_conversation_tobe_polite"     => $row["qi18_conversation_tobe_polite"],
             "qi19_lookforward_newthings"        => $row["qi19_lookforward_newthings"],
             "qi20_speak_tooloud_softly"         => $row["qi20_speak_tooloud_softly"],
             "qi21_tell_someone_not_interested"  => $row["qi21_tell_someone_not_interested"],
             "qi22_hardtime_change_routine"      => $row["qi22_hardtime_change_routine"],
             "qi23_good_smalltalk"               => $row["qi23_good_smalltalk"],
             "qi24_act_myways"                   => $row["qi24_act_myways"],
             "qi25_connecting_people"            => $row["qi25_connecting_people"],
             "qi26_peoplefrustrated"             => $row["qi26_peoplefrustrated"],
             "qi27_conversation_boresme"         => $row["qi27_conversation_boresme"],
             "qi28_warmfriendly_others"          => $row["qi28_warmfriendly_others"],
             "qi29_longpauses_conversations"     => $row["qi29_longpauses_conversations"],
             "qi30_alter_dailyroutine"           => $row["qi30_alter_dailyroutine"],
             "qi31_alone_ratherthan_withothers"  => $row["qi31_alone_ratherthan_withothers"],
             "qi32_losetrack_talking"            => $row["qi32_losetrack_talking"],
             "qi33_follow_routine"               => $row["qi33_follow_routine"],
             "qi34_change_topic"                 => $row["qi34_change_topic"],
             "qi35_doingthings_knownway"         => $row["qi35_doingthings_knownway"],
             "qi36_enjoy_chatting"               => $row["qi36_enjoy_chatting"],
             "comments"                          => $row["comments"],
            )
        );

        $session_id = getSessionID($old_cid, "pspq_1", $db);

        // If the session_id type is not a string, the original commentid does not exist in the flag table
        if (gettype($session_id) === "string") {
            $flag_fields = $db->pselectRow(
                "SELECT
                    Data_entry, Administration, Validity, Exclusion, Flag_status, UserID, Testdate, Data
                FROM
                    flag
                WHERE
                    CommentID = :old_cid
                AND
                    Test_name = :tname
                ",
                array(
                 "old_cid" => $old_cid,
                 "tname"   => 'pspq_1',
                )
            );

            $db->insert(
                "flag",
                array(
                 'SessionID'      => $session_id,
                 'Test_name'      => 'pspq_SelfReport_mom',
                 'CommentID'      => $new_cid_self_report,
                 'Data_entry'     => $flag_fields["Data_entry"],
                 'Administration' => $flag_fields["Administration"],
                 'Validity'       => $flag_fields["Validity"],
                 'Exclusion'      => $flag_fields["Exclusion"],
                 'Flag_status'    => $flag_fields["Flag_status"],
                 'UserID'         => $flag_fields["UserID"],
                 'Testdate'       => $flag_fields["Testdate"],
                 'Data'           => $flag_fields["Data"],
                )
            );

            $db->insert(
                "flag",
                array(
                 'SessionID'      => $session_id,
                 'Test_name'      => 'pspq_InformantReport_mom_on_dad',
                 'CommentID'      => $new_cid_informant_report,
                 'Data_entry'     => $flag_fields["Data_entry"],
                 'Administration' => $flag_fields["Administration"],
                 'Validity'       => $flag_fields["Validity"],
                 'Exclusion'      => $flag_fields["Exclusion"],
                 'Flag_status'    => $flag_fields["Flag_status"],
                 'UserID'         => $flag_fields["UserID"],
                 'Testdate'       => $flag_fields["Testdate"],
                )
            );
        }
    }

    /*
    * PSPQ2 (FIRST HALF OF QUESTIONS) --> pspq_SelfReport_dad
    * PSPQ2 (SECOND HALF OF QUESTIONS) --> pspq_InformantReport_dad_on_mom
    */

    // Get TestIDs for PSPQ Dad instruments
    $test_id_pspq_2   = 78;
    $test_id_self_dad = 166;
    $test_id_informant_dad_on_mom = 168;

    // All pspq_2 comment ids
    $pspq_2_comment_ids_array = $db->pselect(
        "SELECT
            CommentID
        FROM
            pspq_2
        ",
        array()
    );

    foreach ($pspq_2_comment_ids_array as $cid) {
        $is_dde = false;

        // CommentID containing the TestID of pspq_2
        $old_cid = $cid["CommentID"];

        // Temporarily remove DDE_
        if (substr($old_cid, 0, 4) == "DDE_") {
            $is_dde  = true;
            $old_cid = str_replace("DDE_", "", $old_cid);
        }

        $new_cid_self_report      = replaceTestID($old_cid, $test_id_pspq_2, $test_id_self_dad);
        $new_cid_informant_report = replaceTestID($old_cid, $test_id_pspq_2, $test_id_informant_dad_on_mom);

        // Put DDE_ back
        if ($is_dde) {
            $old_cid = "DDE_" . $old_cid;
            $new_cid_self_report      = "DDE_" . $new_cid_self_report;
            $new_cid_informant_report = "DDE_" . $new_cid_informant_report;
        }

        $row = $db->pselectRow(
            "SELECT
                *
            FROM
                pspq_2
            WHERE CommentID = :old_cid
            ",
            array("old_cid" => $old_cid)
        );

        // pspq_2 has "other" option for gender, while the newer pspq instruments don't
        if ($row["respondent_gender"] == "other") {
            $row["respondent_gender"] = null;
        }
        if ($row["informant_gender"] == "other") {
            $row["informant_gender"] = null;
        }

        // pspq_2 contains some empty strings which will cause errors when migrating the data
        foreach ($pspq_self_cols as $col) {
            if ($row[$col] == '') {
                $row[$col] = null;
            }
        }
        foreach ($pspq_informant_cols as $col) {
            if ($row[$col] == '') {
                $row[$col] = null;
            }
        }

        // Insert data into pspq_SelfReport_dad
        $db->insert(
            "pspq_SelfReport_dad",
            array(
             "CommentID"                        => $new_cid_self_report,
             "UserID"                           => $row["UserID"],
             "Examiner"                         => $row["Examiner"],
             "Testdate"                         => $row["Testdate"],
             "Data_entry_completion_status"     => $row["Data_entry_completion_status"],
             "Date_taken"                       => $row["Date_taken"],
             "Candidate_Age"                    => $row["Candidate_Age"],
             "Window_Difference"                => $row["Window_Difference"],
             "respondent_age"                   => $row["respondent_age"],
             "respondent"                       => $row["respondent"],
             "respondent_other"                 => $row["respondent_other"],
             "respondent_gender"                => $row["respondent_gender"],
             "q1_like_being_otherpeople"        => $row["q1_like_being_otherpeople"],
             "q2_hard_wordsout_smoothly"        => $row["q2_hard_wordsout_smoothly"],
             "q3_comfortable_unexpectedchanges" => $row["q3_comfortable_unexpectedchanges"],
             "q4_hard_avoid_sidetrack"          => $row["q4_hard_avoid_sidetrack"],
             "q5_information_than_socialize"    => $row["q5_information_than_socialize"],
             "q6_talkinto_tryingnew"            => $row["q6_talkinto_tryingnew"],
             "q7_intune_conversation"           => $row["q7_intune_conversation"],
             "q8_warmup_unfamiliarplace"        => $row["q8_warmup_unfamiliarplace"],
             "q9_enjoy_socialsituations"        => $row["q9_enjoy_socialsituations"],
             "q10_voice_flat_monotone"          => $row["q10_voice_flat_monotone"],
             "q11_disconnected_outofsync_convo" => $row["q11_disconnected_outofsync_convo"],
             "q12_easy_approach"                => $row["q12_easy_approach"],
             "q13_strongneed_sameness"          => $row["q13_strongneed_sameness"],
             "q14_others_dont_understand"       => $row["q14_others_dont_understand"],
             "q15_flexible"                     => $row["q15_flexible"],
             "q16_situations_meetnew_people"    => $row["q16_situations_meetnew_people"],
             "q17_talktoomuch_certain_topics"   => $row["q17_talktoomuch_certain_topics"],
             "q18_conversation_tobe_polite"     => $row["q18_conversation_tobe_polite"],
             "q19_lookforward_newthings"        => $row["q19_lookforward_newthings"],
             "q20_speak_tooloud_softly"         => $row["q20_speak_tooloud_softly"],
             "q21_tell_someone_not_interested"  => $row["q21_tell_someone_not_interested"],
             "q22_hardtime_change_routine"      => $row["q22_hardtime_change_routine"],
             "q23_good_smalltalk"               => $row["q23_good_smalltalk"],
             "q24_act_myways"                   => $row["q24_act_myways"],
             "q25_connecting_people"            => $row["q25_connecting_people"],
             "q26_peoplefrustrated"             => $row["q26_peoplefrustrated"],
             "q27_conversation_boresme"         => $row["q27_conversation_boresme"],
             "q28_warmfriendly_others"          => $row["q28_warmfriendly_others"],
             "q29_longpauses_conversations"     => $row["q29_longpauses_conversations"],
             "q30_alter_dailyroutine"           => $row["q30_alter_dailyroutine"],
             "q31_alone_ratherthan_withothers"  => $row["q31_alone_ratherthan_withothers"],
             "q32_losetrack_talking"            => $row["q32_losetrack_talking"],
             "q33_follow_routine"               => $row["q33_follow_routine"],
             "q34_change_topic"                 => $row["q34_change_topic"],
             "q35_doingthings_knownway"         => $row["q35_doingthings_knownway"],
             "q36_enjoy_chatting"               => $row["q36_enjoy_chatting"],
            )
        );

        // Insert data into pspq_InformantReport_dad_on_mom
        $db->insert(
            "pspq_InformantReport_dad_on_mom",
            array(
             "CommentID"                         => $new_cid_informant_report,
             "UserID"                            => $row["UserID"],
             "Examiner"                          => $row["Examiner"],
             "Testdate"                          => $row["Testdate"],
             "Data_entry_completion_status"      => $row["Data_entry_completion_status"],
             "Date_taken"                        => $row["Date_taken"],
             "Candidate_Age"                     => $row["Candidate_Age"],
             "Window_Difference"                 => $row["Window_Difference"],
             "respondent_age"                    => $row["respondent_age"],
             "respondent"                        => $row["respondent"],
             "respondent_other"                  => $row["respondent_other"],
             "respondent_gender"                 => $row["respondent_gender"],
             "informant_confidence"              => $row["informant_confidence"],
             "informant"                         => $row["informant"],
             "informant_other"                   => $row["informant_other"],
             "informant_gender"                  => $row["informant_gender"],
             "qi1_like_being_otherpeople"        => $row["qi1_like_being_otherpeople"],
             "qi2_hard_wordsout_smoothly"        => $row["qi2_hard_wordsout_smoothly"],
             "qi3_comfortable_unexpectedchanges" => $row["qi3_comfortable_unexpectedchanges"],
             "qi4_hard_avoid_sidetrack"          => $row["qi4_hard_avoid_sidetrack"],
             "qi5_information_than_socialize"    => $row["qi5_information_than_socialize"],
             "qi6_talkinto_tryingnew"            => $row["qi6_talkinto_tryingnew"],
             "qi7_intune_conversation"           => $row["qi7_intune_conversation"],
             "qi8_warmup_unfamiliarplace"        => $row["qi8_warmup_unfamiliarplace"],
             "qi9_enjoy_socialsituations"        => $row["qi9_enjoy_socialsituations"],
             "qi10_voice_flat_monotone"          => $row["qi10_voice_flat_monotone"],
             "qi11_disconnected_outofsync_convo" => $row["qi11_disconnected_outofsync_convo"],
             "qi12_easy_approach"                => $row["qi12_easy_approach"],
             "qi13_strongneed_sameness"          => $row["qi13_strongneed_sameness"],
             "qi14_others_dont_understand"       => $row["qi14_others_dont_understand"],
             "qi15_flexible"                     => $row["qi15_flexible"],
             "qi16_situations_meetnew_people"    => $row["qi16_situations_meetnew_people"],
             "qi17_talktoomuch_certain_topics"   => $row["qi17_talktoomuch_certain_topics"],
             "qi18_conversation_tobe_polite"     => $row["qi18_conversation_tobe_polite"],
             "qi19_lookforward_newthings"        => $row["qi19_lookforward_newthings"],
             "qi20_speak_tooloud_softly"         => $row["qi20_speak_tooloud_softly"],
             "qi21_tell_someone_not_interested"  => $row["qi21_tell_someone_not_interested"],
             "qi22_hardtime_change_routine"      => $row["qi22_hardtime_change_routine"],
             "qi23_good_smalltalk"               => $row["qi23_good_smalltalk"],
             "qi24_act_myways"                   => $row["qi24_act_myways"],
             "qi25_connecting_people"            => $row["qi25_connecting_people"],
             "qi26_peoplefrustrated"             => $row["qi26_peoplefrustrated"],
             "qi27_conversation_boresme"         => $row["qi27_conversation_boresme"],
             "qi28_warmfriendly_others"          => $row["qi28_warmfriendly_others"],
             "qi29_longpauses_conversations"     => $row["qi29_longpauses_conversations"],
             "qi30_alter_dailyroutine"           => $row["qi30_alter_dailyroutine"],
             "qi31_alone_ratherthan_withothers"  => $row["qi31_alone_ratherthan_withothers"],
             "qi32_losetrack_talking"            => $row["qi32_losetrack_talking"],
             "qi33_follow_routine"               => $row["qi33_follow_routine"],
             "qi34_change_topic"                 => $row["qi34_change_topic"],
             "qi35_doingthings_knownway"         => $row["qi35_doingthings_knownway"],
             "qi36_enjoy_chatting"               => $row["qi36_enjoy_chatting"],
             "comments"                          => $row["comments"],
            )
        );

        $session_id = getSessionID($old_cid, "pspq_2", $db);

        // If the session_id type is not a string, the original commentid does not exist in the flag table
        if (gettype($session_id) === "string") {
            $flag_fields = $db->pselectRow(
                "SELECT
                    Data_entry, Administration, Validity, Exclusion, Flag_status, UserID, Testdate, Data
                FROM
                    flag
                WHERE
                    CommentID = :old_cid
                AND
                    Test_name = :tname
                ",
                array(
                 "old_cid" => $old_cid,
                 "tname"   => 'pspq_2',
                )
            );

            $db->insert(
                "flag",
                array(
                 'SessionID'      => $session_id,
                 'Test_name'      => 'pspq_SelfReport_dad',
                 'CommentID'      => $new_cid_self_report,
                 'Data_entry'     => $flag_fields["Data_entry"],
                 'Administration' => $flag_fields["Administration"],
                 'Validity'       => $flag_fields["Validity"],
                 'Exclusion'      => $flag_fields["Exclusion"],
                 'Flag_status'    => $flag_fields["Flag_status"],
                 'UserID'         => $flag_fields["UserID"],
                 'Testdate'       => $flag_fields["Testdate"],
                 'Data'           => $flag_fields["Data"],
                )
            );

            $db->insert(
                "flag",
                array(
                 'SessionID'      => $session_id,
                 'Test_name'      => 'pspq_InformantReport_dad_on_mom',
                 'CommentID'      => $new_cid_informant_report,
                 'Data_entry'     => $flag_fields["Data_entry"],
                 'Administration' => $flag_fields["Administration"],
                 'Validity'       => $flag_fields["Validity"],
                 'Exclusion'      => $flag_fields["Exclusion"],
                 'Flag_status'    => $flag_fields["Flag_status"],
                 'UserID'         => $flag_fields["UserID"],
                 'Testdate'       => $flag_fields["Testdate"],
                )
            );
        }
    }

    echo "\nRun this tool again with the argument 'confirm'\n";
}

if ($confirm) {
    // Remove pspq_1
    $db->run("DELETE FROM instrument_subtests WHERE Test_name = 'pspq_1'");
    $db->run("DELETE FROM test_names WHERE Test_name = 'pspq_1'");
    $db->run("DELETE FROM test_battery WHERE Test_name = 'pspq_1'");
    $db->run("DELETE FROM flag WHERE Test_name = 'pspq_1'");

    // Remove pspq_2
    $db->run("DELETE FROM instrument_subtests WHERE Test_name = 'pspq_2'");
    $db->run("DELETE FROM test_names WHERE Test_name = 'pspq_2'");
    $db->run("DELETE FROM test_battery WHERE Test_name = 'pspq_2'");
    $db->run("DELETE FROM flag WHERE Test_name = 'pspq_2'");

    // Keeping tables just in case
    // $db->run("DROP TABLE pspq_1");
    // $db->run("DROP TABLE pspq_2");

    echo "\nScript complete\n";
}

/**
 * Gets TestID from test_names table
 *
 * @param string   $test_name Test name of instrument
 * @param Database $db        Database Singleton
 *
 * @return int TestID
 */
function getTestID($test_name, $db)
{
    $test_id = $db->pselectOne(
        "SELECT
            ID
        FROM
            test_names
        WHERE
            Test_name = :test_name
        ",
        array("test_name" => $test_name)
    );

    return $test_id;
}

/**
 * Replaces the TestID in CommentID
 *
 * @param string $comment_id  The existing CommentID that we want to change
 * @param int    $old_test_id The TestID currently used in the CommentID
 * @param int    $new_test_id The TestID we want to use in the NEW CommentID
 *
 * @return string CommentID with new test ID
 */
function replaceTestID($comment_id, $old_test_id, $new_test_id)
{
    $candid = substr($comment_id, 0, 6);    // get first 6 chars
    $pscid  = substr($comment_id, 6, 7);    // get next 7 chars
    $time   = substr($comment_id, -10, 10); // get last 10 chars

    $trimmed = str_replace($time, "", $comment_id);         // removes time (last 10 chars)
    $trimmed = str_replace($candid . $pscid, "", $trimmed); // removes candid and pscid

    // $trimmed contains: session id . subprojectid . testid

    // Get length of the old test id
    $old_test_id_length = strlen($old_test_id);
    $old_length_neg     = $old_test_id_length * -1;

    // Remove old test id
    $session_and_subproject_id = substr($trimmed, 0, $old_length_neg);

    // NEW comment id
    $comment_id_new = $candid . $pscid . $session_and_subproject_id . $new_test_id . $time;

    return $comment_id_new;
}

/**
 * Gets SessionID from flag
 *
 * @param string   $comment_id CommentID used in WHERE clause
 * @param string   $test_name  Test Name used in used in WHERE clause
 * @param Database $db         Database Singleton
 *
 * @return int SessionID
 */
function getSessionID($comment_id, $test_name, $db)
{
    $sess_id = $db->pselectOne(
        "SELECT
            SessionID
        FROM
            flag
        WHERE
            CommentID = :cid
        AND
            Test_name = :tname
        ",
        array(
         "cid"   => $comment_id,
         "tname" => $test_name,
        )
    );

    return $sess_id;
}
?>