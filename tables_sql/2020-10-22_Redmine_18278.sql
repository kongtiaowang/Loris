-- Redmine 18278
ALTER TABLE `TSI_EP` MODIFY COLUMN `inf_devfactors_q11b_if_weaned_how_long_breastfeed` enum('yes','no','weaned','not_weaned','not_answered') default NULL;

UPDATE `TSI_EP` SET `inf_devfactors_q11b_if_weaned_how_long_breastfeed` = CASE
    WHEN `inf_devfactors_q11b_if_weaned_how_long_breastfeed` = 'yes' THEN 'weaned'
    WHEN `inf_devfactors_q11b_if_weaned_how_long_breastfeed` = 'no' THEN 'not_weaned'
    WHEN `inf_devfactors_q11b_if_weaned_how_long_breastfeed` = 'not_answered' THEN 'not_answered'
    END
WHERE `inf_devfactors_q11b_if_weaned_how_long_breastfeed` in ('yes','no','weaned','not_weaned','not_answered');

ALTER TABLE `TSI_EP` MODIFY COLUMN `inf_devfactors_q11b_if_weaned_how_long_breastfeed` enum('weaned','not_weaned','not_answered') default NULL;