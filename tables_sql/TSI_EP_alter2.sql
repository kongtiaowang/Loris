ALTER TABLE TSI_EP CHANGE COLUMN if_reviewed_decision_status if_reviewed_decision_status enum('review_not_done','not_answered') default NULL;
ALTER TABLE TSI_EP CHANGE COLUMN date_received_exclusion_review_decision_status date_received_exclusion_review_decision_status enum('review_not_done','not_answered') default NULL;
UPDATE TSI_EP SET if_reviewed_decision_status = "review_not_done" WHERE if_reviewed_decision_status = "not_answered";
UPDATE TSI_EP SET date_received_exclusion_review_decision_status = "review_not_done" WHERE date_received_exclusion_review_decision_status = "not_answered";
ALTER TABLE TSI_EP CHANGE COLUMN if_reviewed_decision_status if_reviewed_decision_status enum('review_not_done') default NULL;
ALTER TABLE TSI_EP CHANGE COLUMN date_received_exclusion_review_decision_status date_received_exclusion_review_decision_status enum('review_not_done') default NULL;

