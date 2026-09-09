-- Guarded so this patch is safe to apply whether or not the change is
-- already present in the base schema (SQL/0000-00-00-schema.sql is kept in
-- sync with this patch) and safe to re-run, on both MySQL and MariaDB.
SET @col_exists := (
  SELECT COUNT(*)
  FROM information_schema.columns
  WHERE table_schema = DATABASE()
    AND table_name = 'candidate'
    AND column_name = 'DoD_precision'
);
SET @stmt := IF(@col_exists = 0,
  'ALTER TABLE candidate ADD COLUMN DoD_precision enum(''known_full'',''known_year_month'',''known_year'',''unknown'') DEFAULT NULL AFTER DoD',
  'SELECT 1');
PREPARE stmt FROM @stmt;
EXECUTE stmt;
DEALLOCATE PREPARE stmt;
