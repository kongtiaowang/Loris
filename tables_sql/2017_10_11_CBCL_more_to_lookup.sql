-- Add new column to CBCL lookup table
ALTER TABLE `CBCL_lookup` ADD COLUMN `Score_Interpretation` VARCHAR(50) DEFAULT NULL;
-- Update  CBCL lookup for dsm scales for Empirical scales
UPDATE `CBCL_lookup` SET `Score_Interpretation` = CASE
    WHEN  T >= 70 THEN 'Clinical Range'
    WHEN (T >= 65 && T <= 69) THEN 'Borderline Clinical Range'
    ELSE 'Normal Range'
    END
WHERE Type LIKE '%dsm%';
-- Update CBCL lookup for dsm scales
UPDATE `CBCL_lookup` SET `Score_Interpretation` = CASE
    WHEN  T >= 64 THEN 'Clinical Range'
    WHEN (T >= 60 && T <= 63) THEN 'Borderline Clinical Range'
    ELSE 'Normal Range'
    END
WHERE Type NOT LIKE '%dsm%';
-- Adding corresponding score columns
ALTER TABLE `CBCL` ADD COLUMN `emotional_si` VARCHAR(45) DEFAULT NULL;
ALTER TABLE `CBCL` ADD COLUMN `anxious_si` VARCHAR(45) DEFAULT NULL;
ALTER TABLE `CBCL` ADD COLUMN `somatic_si` VARCHAR(45) DEFAULT NULL;
ALTER TABLE `CBCL` ADD COLUMN `withdrawn_si` VARCHAR(45) DEFAULT NULL;
ALTER TABLE `CBCL` ADD COLUMN `sleep_si` VARCHAR(45) DEFAULT NULL;
ALTER TABLE `CBCL` ADD COLUMN `attention_si` VARCHAR(45) DEFAULT NULL;
ALTER TABLE `CBCL` ADD COLUMN `aggressive_si` VARCHAR(45) DEFAULT NULL;
ALTER TABLE `CBCL` ADD COLUMN `internal_si` VARCHAR(45) DEFAULT NULL;
ALTER TABLE `CBCL` ADD COLUMN `external_si` VARCHAR(45) DEFAULT NULL;
ALTER TABLE `CBCL` ADD COLUMN `total_si` VARCHAR(45) DEFAULT NULL;
ALTER TABLE `CBCL` ADD COLUMN `dsm_affective_si` VARCHAR(45) DEFAULT NULL;
ALTER TABLE `CBCL` ADD COLUMN `dsm_anxiety_si` VARCHAR(45) DEFAULT NULL;
ALTER TABLE `CBCL` ADD COLUMN `dsm_mental_si` VARCHAR(45) DEFAULT NULL;
ALTER TABLE `CBCL` ADD COLUMN `dsm_attention_si` VARCHAR(45) DEFAULT NULL;
ALTER TABLE `CBCL` ADD COLUMN `dsm_oppose_si` VARCHAR(45) DEFAULT NULL;