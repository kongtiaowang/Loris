ALTER TABLE m_chat_rf ADD `q18_example_how_you_know_child_understands_you` text default NULL AFTER `q18_understand_tell_something`;
ALTER TABLE m_chat_rf ADD `q18_example_how_you_know_child_understands_you_status` enum('not_answered') default NULL AFTER `q18_example_how_you_know_child_understands_you`;
ALTER TABLE m_chat_rf ADD `q18_does_example_indicate_understand_without_nonverbal_cues` enum('yes','no') default NULL AFTER `q18_example_how_you_know_child_understands_you_status`;