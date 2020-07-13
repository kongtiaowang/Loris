<?php
/**
 * This script addresses Redmine 18028 and does the following:
 * Splits pspq_1 into pspq_self_report_mom and pspq_informant_report_mom_on_dad
 * Splits pspq_2 into pspq_self_report_dad and pspq_informant_report_dad_on_mom
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

if ($confirm === false) {
    // makes 2 copies of the original pspq_1 instrument table & its contents
    $db->run("CREATE TABLE pspq_self_report_mom LIKE `pspq_1`");
    $db->run("INSERT INTO pspq_self_report_mom SELECT * FROM `pspq_1`");
    $db->run("CREATE TABLE pspq_informant_report_mom_on_dad LIKE `pspq_1`");
    $db->run("INSERT INTO pspq_informant_report_mom_on_dad SELECT * FROM `pspq_1`");

    // makes 2 copies of the original pspq_2 instrument table & its contents
    $db->run("CREATE TABLE pspq_self_report_dad LIKE `pspq_2`");
    $db->run("INSERT INTO pspq_self_report_dad SELECT * FROM `pspq_2`");
    $db->run("CREATE TABLE pspq_informant_report_dad_on_mom LIKE `pspq_2`");
    $db->run("INSERT INTO pspq_informant_report_dad_on_mom SELECT * FROM `pspq_2`");

    // Updates test_names table
    // pspq_1 --> pspq_self_report_mom, pspq_2 --> pspq_self_report_dad
    $db->run("UPDATE test_names SET Test_name = 'pspq_self_report_mom' WHERE Test_name = 'pspq_1'");
    $db->run("UPDATE test_names SET Test_name = 'pspq_self_report_dad' WHERE Test_name = 'pspq_2'");
    $db->run("UPDATE test_names SET Full_name = 'PSPQ (Self Report - Mom)' WHERE Test_name = 'pspq_self_report_mom'");
    $db->run("UPDATE test_names SET Full_name = 'PSPQ (Self Report - Dad)' WHERE Test_name = 'pspq_self_report_dad'");

    // Updates test_battery table
    $db->run("UPDATE test_battery SET Test_name = 'pspq_self_report_mom' WHERE Test_name = 'pspq_1'");
    $db->run("UPDATE test_battery SET Test_name = 'pspq_self_report_dad' WHERE Test_name = 'pspq_2'");

    // Updates flag table
    $db->run("UPDATE flag SET Test_name = 'pspq_self_report_mom' WHERE Test_name = 'pspq_1'");
    $db->run("UPDATE flag SET Test_name = 'pspq_self_report_dad' WHERE Test_name = 'pspq_2'");

    // Updates instrument_subtests table
    // pspq_self_report_mom:
    $db->run("DELETE FROM instrument_subtests WHERE Test_name = 'pspq_1' AND Subtest_name = 'pspq_1_page4'"); // deletes informant page
    $db->run("DELETE FROM instrument_subtests WHERE Test_name = 'pspq_1' AND Subtest_name = 'pspq_1_page5'"); // deletes informant page
    $db->run("DELETE FROM instrument_subtests WHERE Test_name = 'pspq_1' AND Subtest_name = 'pspq_1_page6'"); // deletes informant page
    $db->run("UPDATE instrument_subtests SET Subtest_name = 'pspq_self_report_mom_page1' WHERE Test_name = 'pspq_1' AND Order_number = 1");
    $db->run("UPDATE instrument_subtests SET Subtest_name = 'pspq_self_report_mom_page2' WHERE Test_name = 'pspq_1' AND Order_number = 2");
    $db->run("UPDATE instrument_subtests SET Description = 'Respondent Page1' WHERE Test_name = 'pspq_1' AND Order_number = 1");
    $db->run("UPDATE instrument_subtests SET Description = 'Respondent Page2' WHERE Test_name = 'pspq_1' AND Order_number = 2");
    $db->run("UPDATE instrument_subtests SET Test_name = 'pspq_self_report_mom' WHERE Test_name = 'pspq_1'");
    // pspq_self_report_dad:
    $db->run("DELETE FROM instrument_subtests WHERE Test_name = 'pspq_2' AND Subtest_name = 'pspq_2_page4'"); // deletes informant page
    $db->run("DELETE FROM instrument_subtests WHERE Test_name = 'pspq_2' AND Subtest_name = 'pspq_2_page5'"); // deletes informant page
    $db->run("DELETE FROM instrument_subtests WHERE Test_name = 'pspq_2' AND Subtest_name = 'pspq_2_page6'"); // deletes informant page
    $db->run("UPDATE instrument_subtests SET Subtest_name = 'pspq_self_report_dad_page1' WHERE Test_name = 'pspq_2' AND Order_number = 1");
    $db->run("UPDATE instrument_subtests SET Subtest_name = 'pspq_self_report_dad_page2' WHERE Test_name = 'pspq_2' AND Order_number = 2");
    $db->run("UPDATE instrument_subtests SET Description = 'Respondent Page1' WHERE Test_name = 'pspq_2' AND Order_number = 1");
    $db->run("UPDATE instrument_subtests SET Description = 'Respondent Page2' WHERE Test_name = 'pspq_2' AND Order_number = 2");
    $db->run("UPDATE instrument_subtests SET Test_name = 'pspq_self_report_dad' WHERE Test_name = 'pspq_2'");

    // At this point, the pspq_self_report instruments will work, but have the extra informant columns
    // pspq_1 and pspq_2 no longer work, but the tables are still in the DB

    // Insert pspq_informant_report instruments
    // mom_on_dad:
    $db->run("INSERT INTO test_names (Test_name, Full_name, Sub_Group, isDirectEntry) VALUES ('pspq_informant_report_mom_on_dad', 'PSPQ (Informant Report - Mom on Dad)', 6, 0)");
    $db->run("INSERT INTO instrument_subtests (Test_name, Subtest_name, Description, Order_number) VALUES ('pspq_informant_report_mom_on_dad','pspq_informant_report_mom_on_dad_page1', 'Informant Page1', 1)");
    $db->run("INSERT INTO instrument_subtests (Test_name, Subtest_name, Description, Order_number) VALUES ('pspq_informant_report_mom_on_dad','pspq_informant_report_mom_on_dad_page2', 'Informant Page2', 2)");
    $db->run("INSERT INTO instrument_subtests (Test_name, Subtest_name, Description, Order_number) VALUES ('pspq_informant_report_mom_on_dad','pspq_informant_report_mom_on_dad_page3', 'Informant Page3', 3)");
    $db->run("INSERT INTO test_battery (Test_name, AgeMinDays, AgeMaxDays, Active, Stage, SubprojectID, Visit_label, CenterID) VALUES ('pspq_informant_report_mom_on_dad', '0', '0', 'Y', 'Visit', NULL, NULL, NULL)");
    // dad_on_mom:
    $db->run("INSERT INTO test_names (Test_name, Full_name, Sub_Group, isDirectEntry) VALUES ('pspq_informant_report_dad_on_mom', 'PSPQ (Informant Report - Dad on Mom)', 6, 0)");
    $db->run("INSERT INTO instrument_subtests (Test_name, Subtest_name, Description, Order_number) VALUES ('pspq_informant_report_dad_on_mom','pspq_informant_report_dad_on_mom_page1', 'Informant Page1', 1)");
    $db->run("INSERT INTO instrument_subtests (Test_name, Subtest_name, Description, Order_number) VALUES ('pspq_informant_report_dad_on_mom','pspq_informant_report_dad_on_mom_page2', 'Informant Page2', 2)");
    $db->run("INSERT INTO instrument_subtests (Test_name, Subtest_name, Description, Order_number) VALUES ('pspq_informant_report_dad_on_mom','pspq_informant_report_dad_on_mom_page3', 'Informant Page3', 3)");
    $db->run("INSERT INTO test_battery (Test_name, AgeMinDays, AgeMaxDays, Active, Stage, SubprojectID, Visit_label, CenterID) VALUES ('pspq_informant_report_dad_on_mom', '0', '0', 'Y', 'Visit', NULL, NULL, NULL)");

    // At this point, pspq_informant_report instruments won't work because the comment ids don't use the correct test id

    // Get Test IDs of each instrument
    $tid_self_rep_mom        = $db->pselectOne(
        "SELECT ID FROM test_names WHERE Test_name = 'pspq_self_report_mom'",
        array()
    );
    $tid_info_rep_mom_on_dad = $db->pselectOne(
        "SELECT ID FROM test_names WHERE Test_name = 'pspq_informant_report_mom_on_dad'",
        array()
    );
    $tid_self_rep_dad        = $db->pselectOne(
        "SELECT ID FROM test_names WHERE Test_name = 'pspq_self_report_dad'",
        array()
    );
    $tid_info_rep_dad_on_mom = $db->pselectOne(
        "SELECT ID FROM test_names WHERE Test_name = 'pspq_informant_report_dad_on_mom'",
        array()
    );

    // Get CommentIDs of pspq_informant_report_mom_on_dad
    $comment_id_array_mom = $db->pselect(
        "SELECT
            CommentID
        FROM
            pspq_informant_report_mom_on_dad
        ",
        array()
    );

    // Replace the CommentID and insert new CommentID into flag table for pspq_informant_report_mom_on_dad
    foreach ($comment_id_array_mom as $cid) {
        $is_dde = false;

        $old_cid = $cid["CommentID"];

        if (substr($old_cid, 0, 4) == "DDE_") {
            $is_dde  = true;
            $old_cid = str_replace("DDE_", "", $old_cid);
        }

        $new_cid = replaceTestID($old_cid, $tid_self_rep_mom, $tid_info_rep_mom_on_dad);

        if ($is_dde) {
            $old_cid = "DDE_" . $old_cid;
            $new_cid = "DDE_" . $new_cid;
        }

        $db->update(
            "pspq_informant_report_mom_on_dad",
            array('CommentID' => $new_cid),
            array('CommentID' => $old_cid)
        );

        $session_id = getSessionID($old_cid, "pspq_self_report_mom", $db);

        // If the session_id type is not a string, the original commentid does not exist in the flag table
        if (gettype($session_id) === "string") {
            $flag_fields = $db->pselectRow(
                "SELECT
                    Data_entry, Testdate, Administration, Validity, Exclusion, Flag_status, UserID
                FROM
                    flag
                WHERE
                    CommentID = :old_cid
                AND
                    Test_name = :tname
                ",
                array(
                 "old_cid" => $old_cid,
                 "tname"   => 'pspq_self_report_mom',
                )
            );

            $db->insert(
                "flag",
                array(
                 'SessionID'      => $session_id,
                 'Test_name'      => 'pspq_informant_report_mom_on_dad',
                 'CommentID'      => $new_cid,
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

    // Get CommentIDs of pspq_informant_report_dad_on_mom
    $comment_id_array_dad = $db->pselect(
        "SELECT
            CommentID
        FROM
            pspq_informant_report_dad_on_mom
        ",
        array()
    );

    // Replace the CommentID and insert new CommentID into flag table for pspq_informant_report_dad_on_mom
    foreach ($comment_id_array_dad as $cid) {
        $is_dde = false;

        $old_cid = $cid["CommentID"];

        if (substr($old_cid, 0, 4) == "DDE_") {
            $is_dde  = true;
            $old_cid = str_replace("DDE_", "", $old_cid);
        }

        $new_cid = replaceTestID($old_cid, $tid_self_rep_dad, $tid_info_rep_dad_on_mom);

        if ($is_dde) {
            $old_cid = "DDE_" . $old_cid;
            $new_cid = "DDE_" . $new_cid;
        }

        $db->update(
            "pspq_informant_report_dad_on_mom",
            array('CommentID' => $new_cid),
            array('CommentID' => $old_cid)
        );

        $session_id = getSessionID($old_cid, "pspq_self_report_dad", $db);

        // If the session_id type is not a string, the original commentid does not exist in the flag table
        if (gettype($session_id) === "string") {
            $test_date = $db->pselectOne(
                "SELECT
                    Testdate
                FROM
                    flag
                WHERE
                    CommentID = :old_cid
                AND
                    Test_name = :tname
                ",
                array(
                 "old_cid" => $old_cid,
                 "tname"   => 'pspq_self_report_dad',
                )
            );

            $db->insert(
                "flag",
                array(
                 'CommentID' => $new_cid,
                 'SessionID' => $session_id,
                 'Test_name' => 'pspq_informant_report_dad_on_mom',
                 'Testdate'  => $test_date,
                )
            );
        }
    }

    echo "\nRun this tool again with the argument 'confirm'\n";
}

if ($confirm) {
    // Delete informant columns from pspq_self_report_mom
    $db->run("ALTER TABLE pspq_self_report_mom DROP COLUMN informant_age");
    $db->run("ALTER TABLE pspq_self_report_mom DROP COLUMN informant_age_status");
    $db->run("ALTER TABLE pspq_self_report_mom DROP COLUMN informant");
    $db->run("ALTER TABLE pspq_self_report_mom DROP COLUMN informant_other");
    $db->run("ALTER TABLE pspq_self_report_mom DROP COLUMN informant_other_status");
    $db->run("ALTER TABLE pspq_self_report_mom DROP COLUMN informant_gender");
    $db->run("ALTER TABLE pspq_self_report_mom DROP COLUMN qi1_like_being_otherpeople");
    $db->run("ALTER TABLE pspq_self_report_mom DROP COLUMN qi2_hard_wordsout_smoothly");
    $db->run("ALTER TABLE pspq_self_report_mom DROP COLUMN qi3_comfortable_unexpectedchanges");
    $db->run("ALTER TABLE pspq_self_report_mom DROP COLUMN qi4_hard_avoid_sidetrack");
    $db->run("ALTER TABLE pspq_self_report_mom DROP COLUMN qi5_information_than_socialize");
    $db->run("ALTER TABLE pspq_self_report_mom DROP COLUMN qi6_talkinto_tryingnew");
    $db->run("ALTER TABLE pspq_self_report_mom DROP COLUMN qi7_intune_conversation");
    $db->run("ALTER TABLE pspq_self_report_mom DROP COLUMN qi8_warmup_unfamiliarplace");
    $db->run("ALTER TABLE pspq_self_report_mom DROP COLUMN qi9_enjoy_socialsituations");
    $db->run("ALTER TABLE pspq_self_report_mom DROP COLUMN qi10_voice_flat_monotone");
    $db->run("ALTER TABLE pspq_self_report_mom DROP COLUMN qi11_disconnected_outofsync_convo");
    $db->run("ALTER TABLE pspq_self_report_mom DROP COLUMN qi12_easy_approach");
    $db->run("ALTER TABLE pspq_self_report_mom DROP COLUMN qi13_strongneed_sameness");
    $db->run("ALTER TABLE pspq_self_report_mom DROP COLUMN qi14_others_dont_understand");
    $db->run("ALTER TABLE pspq_self_report_mom DROP COLUMN qi15_flexible");
    $db->run("ALTER TABLE pspq_self_report_mom DROP COLUMN qi16_situations_meetnew_people");
    $db->run("ALTER TABLE pspq_self_report_mom DROP COLUMN qi17_talktoomuch_certain_topics");
    $db->run("ALTER TABLE pspq_self_report_mom DROP COLUMN qi18_conversation_tobe_polite");
    $db->run("ALTER TABLE pspq_self_report_mom DROP COLUMN qi19_lookforward_newthings");
    $db->run("ALTER TABLE pspq_self_report_mom DROP COLUMN qi20_speak_tooloud_softly");
    $db->run("ALTER TABLE pspq_self_report_mom DROP COLUMN qi21_tell_someone_not_interested");
    $db->run("ALTER TABLE pspq_self_report_mom DROP COLUMN qi22_hardtime_change_routine");
    $db->run("ALTER TABLE pspq_self_report_mom DROP COLUMN qi23_good_smalltalk");
    $db->run("ALTER TABLE pspq_self_report_mom DROP COLUMN qi24_act_myways");
    $db->run("ALTER TABLE pspq_self_report_mom DROP COLUMN qi25_connecting_people");
    $db->run("ALTER TABLE pspq_self_report_mom DROP COLUMN qi26_peoplefrustrated");
    $db->run("ALTER TABLE pspq_self_report_mom DROP COLUMN qi27_conversation_boresme");
    $db->run("ALTER TABLE pspq_self_report_mom DROP COLUMN qi28_warmfriendly_others");
    $db->run("ALTER TABLE pspq_self_report_mom DROP COLUMN qi29_longpauses_conversations");
    $db->run("ALTER TABLE pspq_self_report_mom DROP COLUMN qi30_alter_dailyroutine");
    $db->run("ALTER TABLE pspq_self_report_mom DROP COLUMN qi31_alone_ratherthan_withothers");
    $db->run("ALTER TABLE pspq_self_report_mom DROP COLUMN qi32_losetrack_talking");
    $db->run("ALTER TABLE pspq_self_report_mom DROP COLUMN qi33_follow_routine");
    $db->run("ALTER TABLE pspq_self_report_mom DROP COLUMN qi34_change_topic");
    $db->run("ALTER TABLE pspq_self_report_mom DROP COLUMN qi35_doingthings_knownway");
    $db->run("ALTER TABLE pspq_self_report_mom DROP COLUMN qi36_enjoy_chatting");
    $db->run("ALTER TABLE pspq_self_report_mom DROP COLUMN comments_informant");
    $db->run("ALTER TABLE pspq_self_report_mom DROP COLUMN informant_confidence");
    $db->run("ALTER TABLE pspq_self_report_mom DROP COLUMN informant_child_other");
    $db->run("ALTER TABLE pspq_self_report_mom DROP COLUMN informant_child");

    // Delete informant columns from pspq_self_report_dad
    $db->run("ALTER TABLE pspq_self_report_dad DROP COLUMN informant_age");
    $db->run("ALTER TABLE pspq_self_report_dad DROP COLUMN informant_age_status");
    $db->run("ALTER TABLE pspq_self_report_dad DROP COLUMN informant");
    $db->run("ALTER TABLE pspq_self_report_dad DROP COLUMN informant_other");
    $db->run("ALTER TABLE pspq_self_report_dad DROP COLUMN informant_other_status");
    $db->run("ALTER TABLE pspq_self_report_dad DROP COLUMN informant_gender");
    $db->run("ALTER TABLE pspq_self_report_dad DROP COLUMN qi1_like_being_otherpeople");
    $db->run("ALTER TABLE pspq_self_report_dad DROP COLUMN qi2_hard_wordsout_smoothly");
    $db->run("ALTER TABLE pspq_self_report_dad DROP COLUMN qi3_comfortable_unexpectedchanges");
    $db->run("ALTER TABLE pspq_self_report_dad DROP COLUMN qi4_hard_avoid_sidetrack");
    $db->run("ALTER TABLE pspq_self_report_dad DROP COLUMN qi5_information_than_socialize");
    $db->run("ALTER TABLE pspq_self_report_dad DROP COLUMN qi6_talkinto_tryingnew");
    $db->run("ALTER TABLE pspq_self_report_dad DROP COLUMN qi7_intune_conversation");
    $db->run("ALTER TABLE pspq_self_report_dad DROP COLUMN qi8_warmup_unfamiliarplace");
    $db->run("ALTER TABLE pspq_self_report_dad DROP COLUMN qi9_enjoy_socialsituations");
    $db->run("ALTER TABLE pspq_self_report_dad DROP COLUMN qi10_voice_flat_monotone");
    $db->run("ALTER TABLE pspq_self_report_dad DROP COLUMN qi11_disconnected_outofsync_convo");
    $db->run("ALTER TABLE pspq_self_report_dad DROP COLUMN qi12_easy_approach");
    $db->run("ALTER TABLE pspq_self_report_dad DROP COLUMN qi13_strongneed_sameness");
    $db->run("ALTER TABLE pspq_self_report_dad DROP COLUMN qi14_others_dont_understand");
    $db->run("ALTER TABLE pspq_self_report_dad DROP COLUMN qi15_flexible");
    $db->run("ALTER TABLE pspq_self_report_dad DROP COLUMN qi16_situations_meetnew_people");
    $db->run("ALTER TABLE pspq_self_report_dad DROP COLUMN qi17_talktoomuch_certain_topics");
    $db->run("ALTER TABLE pspq_self_report_dad DROP COLUMN qi18_conversation_tobe_polite");
    $db->run("ALTER TABLE pspq_self_report_dad DROP COLUMN qi19_lookforward_newthings");
    $db->run("ALTER TABLE pspq_self_report_dad DROP COLUMN qi20_speak_tooloud_softly");
    $db->run("ALTER TABLE pspq_self_report_dad DROP COLUMN qi21_tell_someone_not_interested");
    $db->run("ALTER TABLE pspq_self_report_dad DROP COLUMN qi22_hardtime_change_routine");
    $db->run("ALTER TABLE pspq_self_report_dad DROP COLUMN qi23_good_smalltalk");
    $db->run("ALTER TABLE pspq_self_report_dad DROP COLUMN qi24_act_myways");
    $db->run("ALTER TABLE pspq_self_report_dad DROP COLUMN qi25_connecting_people");
    $db->run("ALTER TABLE pspq_self_report_dad DROP COLUMN qi26_peoplefrustrated");
    $db->run("ALTER TABLE pspq_self_report_dad DROP COLUMN qi27_conversation_boresme");
    $db->run("ALTER TABLE pspq_self_report_dad DROP COLUMN qi28_warmfriendly_others");
    $db->run("ALTER TABLE pspq_self_report_dad DROP COLUMN qi29_longpauses_conversations");
    $db->run("ALTER TABLE pspq_self_report_dad DROP COLUMN qi30_alter_dailyroutine");
    $db->run("ALTER TABLE pspq_self_report_dad DROP COLUMN qi31_alone_ratherthan_withothers");
    $db->run("ALTER TABLE pspq_self_report_dad DROP COLUMN qi32_losetrack_talking");
    $db->run("ALTER TABLE pspq_self_report_dad DROP COLUMN qi33_follow_routine");
    $db->run("ALTER TABLE pspq_self_report_dad DROP COLUMN qi34_change_topic");
    $db->run("ALTER TABLE pspq_self_report_dad DROP COLUMN qi35_doingthings_knownway");
    $db->run("ALTER TABLE pspq_self_report_dad DROP COLUMN qi36_enjoy_chatting");
    $db->run("ALTER TABLE pspq_self_report_dad DROP COLUMN comments_informant");
    $db->run("ALTER TABLE pspq_self_report_dad DROP COLUMN informant_confidence");
    $db->run("ALTER TABLE pspq_self_report_dad DROP COLUMN informant_child_other");
    $db->run("ALTER TABLE pspq_self_report_dad DROP COLUMN informant_child");

    // Delete self columns from pspq_informant_report_mom_on_dad
    $db->run("ALTER TABLE pspq_informant_report_mom_on_dad DROP COLUMN q1_like_being_otherpeople");
    $db->run("ALTER TABLE pspq_informant_report_mom_on_dad DROP COLUMN q2_hard_wordsout_smoothly");
    $db->run("ALTER TABLE pspq_informant_report_mom_on_dad DROP COLUMN q3_comfortable_unexpectedchanges");
    $db->run("ALTER TABLE pspq_informant_report_mom_on_dad DROP COLUMN q4_hard_avoid_sidetrack");
    $db->run("ALTER TABLE pspq_informant_report_mom_on_dad DROP COLUMN q5_information_than_socialize");
    $db->run("ALTER TABLE pspq_informant_report_mom_on_dad DROP COLUMN q6_talkinto_tryingnew");
    $db->run("ALTER TABLE pspq_informant_report_mom_on_dad DROP COLUMN q7_intune_conversation");
    $db->run("ALTER TABLE pspq_informant_report_mom_on_dad DROP COLUMN q8_warmup_unfamiliarplace");
    $db->run("ALTER TABLE pspq_informant_report_mom_on_dad DROP COLUMN q9_enjoy_socialsituations");
    $db->run("ALTER TABLE pspq_informant_report_mom_on_dad DROP COLUMN q10_voice_flat_monotone");
    $db->run("ALTER TABLE pspq_informant_report_mom_on_dad DROP COLUMN q11_disconnected_outofsync_convo");
    $db->run("ALTER TABLE pspq_informant_report_mom_on_dad DROP COLUMN q12_easy_approach");
    $db->run("ALTER TABLE pspq_informant_report_mom_on_dad DROP COLUMN q13_strongneed_sameness");
    $db->run("ALTER TABLE pspq_informant_report_mom_on_dad DROP COLUMN q14_others_dont_understand");
    $db->run("ALTER TABLE pspq_informant_report_mom_on_dad DROP COLUMN q15_flexible");
    $db->run("ALTER TABLE pspq_informant_report_mom_on_dad DROP COLUMN q16_situations_meetnew_people");
    $db->run("ALTER TABLE pspq_informant_report_mom_on_dad DROP COLUMN q17_talktoomuch_certain_topics");
    $db->run("ALTER TABLE pspq_informant_report_mom_on_dad DROP COLUMN q18_conversation_tobe_polite");
    $db->run("ALTER TABLE pspq_informant_report_mom_on_dad DROP COLUMN q19_lookforward_newthings");
    $db->run("ALTER TABLE pspq_informant_report_mom_on_dad DROP COLUMN q20_speak_tooloud_softly");
    $db->run("ALTER TABLE pspq_informant_report_mom_on_dad DROP COLUMN q21_tell_someone_not_interested");
    $db->run("ALTER TABLE pspq_informant_report_mom_on_dad DROP COLUMN q22_hardtime_change_routine");
    $db->run("ALTER TABLE pspq_informant_report_mom_on_dad DROP COLUMN q23_good_smalltalk");
    $db->run("ALTER TABLE pspq_informant_report_mom_on_dad DROP COLUMN q24_act_myways");
    $db->run("ALTER TABLE pspq_informant_report_mom_on_dad DROP COLUMN q25_connecting_people");
    $db->run("ALTER TABLE pspq_informant_report_mom_on_dad DROP COLUMN q26_peoplefrustrated");
    $db->run("ALTER TABLE pspq_informant_report_mom_on_dad DROP COLUMN q27_conversation_boresme");
    $db->run("ALTER TABLE pspq_informant_report_mom_on_dad DROP COLUMN q28_warmfriendly_others");
    $db->run("ALTER TABLE pspq_informant_report_mom_on_dad DROP COLUMN q29_longpauses_conversations");
    $db->run("ALTER TABLE pspq_informant_report_mom_on_dad DROP COLUMN q30_alter_dailyroutine");
    $db->run("ALTER TABLE pspq_informant_report_mom_on_dad DROP COLUMN q31_alone_ratherthan_withothers");
    $db->run("ALTER TABLE pspq_informant_report_mom_on_dad DROP COLUMN q32_losetrack_talking");
    $db->run("ALTER TABLE pspq_informant_report_mom_on_dad DROP COLUMN q33_follow_routine");
    $db->run("ALTER TABLE pspq_informant_report_mom_on_dad DROP COLUMN q34_change_topic");
    $db->run("ALTER TABLE pspq_informant_report_mom_on_dad DROP COLUMN q35_doingthings_knownway");
    $db->run("ALTER TABLE pspq_informant_report_mom_on_dad DROP COLUMN q36_enjoy_chatting");
    $db->run("ALTER TABLE pspq_informant_report_mom_on_dad DROP COLUMN comments");

    // Delete self columns from pspq_informant_report_dad_on_mom
    $db->run("ALTER TABLE pspq_informant_report_dad_on_mom DROP COLUMN q1_like_being_otherpeople");
    $db->run("ALTER TABLE pspq_informant_report_dad_on_mom DROP COLUMN q2_hard_wordsout_smoothly");
    $db->run("ALTER TABLE pspq_informant_report_dad_on_mom DROP COLUMN q3_comfortable_unexpectedchanges");
    $db->run("ALTER TABLE pspq_informant_report_dad_on_mom DROP COLUMN q4_hard_avoid_sidetrack");
    $db->run("ALTER TABLE pspq_informant_report_dad_on_mom DROP COLUMN q5_information_than_socialize");
    $db->run("ALTER TABLE pspq_informant_report_dad_on_mom DROP COLUMN q6_talkinto_tryingnew");
    $db->run("ALTER TABLE pspq_informant_report_dad_on_mom DROP COLUMN q7_intune_conversation");
    $db->run("ALTER TABLE pspq_informant_report_dad_on_mom DROP COLUMN q8_warmup_unfamiliarplace");
    $db->run("ALTER TABLE pspq_informant_report_dad_on_mom DROP COLUMN q9_enjoy_socialsituations");
    $db->run("ALTER TABLE pspq_informant_report_dad_on_mom DROP COLUMN q10_voice_flat_monotone");
    $db->run("ALTER TABLE pspq_informant_report_dad_on_mom DROP COLUMN q11_disconnected_outofsync_convo");
    $db->run("ALTER TABLE pspq_informant_report_dad_on_mom DROP COLUMN q12_easy_approach");
    $db->run("ALTER TABLE pspq_informant_report_dad_on_mom DROP COLUMN q13_strongneed_sameness");
    $db->run("ALTER TABLE pspq_informant_report_dad_on_mom DROP COLUMN q14_others_dont_understand");
    $db->run("ALTER TABLE pspq_informant_report_dad_on_mom DROP COLUMN q15_flexible");
    $db->run("ALTER TABLE pspq_informant_report_dad_on_mom DROP COLUMN q16_situations_meetnew_people");
    $db->run("ALTER TABLE pspq_informant_report_dad_on_mom DROP COLUMN q17_talktoomuch_certain_topics");
    $db->run("ALTER TABLE pspq_informant_report_dad_on_mom DROP COLUMN q18_conversation_tobe_polite");
    $db->run("ALTER TABLE pspq_informant_report_dad_on_mom DROP COLUMN q19_lookforward_newthings");
    $db->run("ALTER TABLE pspq_informant_report_dad_on_mom DROP COLUMN q20_speak_tooloud_softly");
    $db->run("ALTER TABLE pspq_informant_report_dad_on_mom DROP COLUMN q21_tell_someone_not_interested");
    $db->run("ALTER TABLE pspq_informant_report_dad_on_mom DROP COLUMN q22_hardtime_change_routine");
    $db->run("ALTER TABLE pspq_informant_report_dad_on_mom DROP COLUMN q23_good_smalltalk");
    $db->run("ALTER TABLE pspq_informant_report_dad_on_mom DROP COLUMN q24_act_myways");
    $db->run("ALTER TABLE pspq_informant_report_dad_on_mom DROP COLUMN q25_connecting_people");
    $db->run("ALTER TABLE pspq_informant_report_dad_on_mom DROP COLUMN q26_peoplefrustrated");
    $db->run("ALTER TABLE pspq_informant_report_dad_on_mom DROP COLUMN q27_conversation_boresme");
    $db->run("ALTER TABLE pspq_informant_report_dad_on_mom DROP COLUMN q28_warmfriendly_others");
    $db->run("ALTER TABLE pspq_informant_report_dad_on_mom DROP COLUMN q29_longpauses_conversations");
    $db->run("ALTER TABLE pspq_informant_report_dad_on_mom DROP COLUMN q30_alter_dailyroutine");
    $db->run("ALTER TABLE pspq_informant_report_dad_on_mom DROP COLUMN q31_alone_ratherthan_withothers");
    $db->run("ALTER TABLE pspq_informant_report_dad_on_mom DROP COLUMN q32_losetrack_talking");
    $db->run("ALTER TABLE pspq_informant_report_dad_on_mom DROP COLUMN q33_follow_routine");
    $db->run("ALTER TABLE pspq_informant_report_dad_on_mom DROP COLUMN q34_change_topic");
    $db->run("ALTER TABLE pspq_informant_report_dad_on_mom DROP COLUMN q35_doingthings_knownway");
    $db->run("ALTER TABLE pspq_informant_report_dad_on_mom DROP COLUMN q36_enjoy_chatting");
    $db->run("ALTER TABLE pspq_informant_report_dad_on_mom DROP COLUMN comments");

    // Keeping original tables just in case
    // $db->run("DROP TABLE pspq_1");
    // $db->run("DROP TABLE pspq_2");

    echo "\nScript complete\n";
}

/**
 * Replaces the TestID in CommentID
 *
 * @param string $comment_id  The existing CommentID that we want to change
 * @param int    $old_test_id The TestID in $comment_id
 * @param int    $new_test_id The TestID we want to use
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

    // At this point, we know that $trimmed = session id . subprojectid . testid

    // Get length of the old test id
    $old_test_id_length = strlen($old_test_id);
    $old_length_neg     = $old_test_id_length * -1;

    // now we have the session and subproject id
    $session_and_subproject_id = substr($trimmed, 0, $old_length_neg);

    // NEW comment id will be the same as the old one but with the new test id
    $comment_id_new = $candid . $pscid . $session_and_subproject_id . $new_test_id . $time;

    return $comment_id_new;
}

// Given a CommentID and test_name, return session
/**
 * Gets SessionID from flag
 *
 * @param string   $comment_id CommentID used in WHERE clause
 * @param string   $test_name  Test Name used in used in WHERE clause
 * @param Database $db         Database Singleton
 *
 * @return string SessionID
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