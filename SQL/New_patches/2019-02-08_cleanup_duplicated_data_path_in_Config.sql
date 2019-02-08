-- Remove entries for mincPath, data and imagePath from the Config table
DELETE
FROM Config
WHERE ConfigID IN (
  SELECT ID
  FROM ConfigSettings
  WHERE Name IN ('mincPath', 'data', 'imagePath')
);

-- Remove entries for mincPath, data and imagePath from the ConfigSettings table
DELETE
FROM ConfigSettings
WHERE Name IN ('mincPath', 'data', 'imagePath');

-- Update the parent of dataDirBasePath to be in the Path section instead of the
-- imaging pipeline section of the Config module
UPDATE ConfigSettings
SET Parent=(SELECT ID FROM (SELECT * FROM ConfigSettings) AS X WHERE Name='Paths')
WHERE Name='dataDirBasePath';


