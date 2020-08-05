
-- Convert all Perl regex that contain the case-insensitive modifier 'i'
UPDATE Config
SET Value=CONCAT('(?i)', SUBSTRING(Value FROM 2 FOR LENGTH(Value)-3))
WHERE ConfigID=(SELECT ID FROM ConfigSettings WHERE Name='patientIDRegex')
AND Value LIKE '/%/i';

-- Removes the leading and trailing forward slashes from every regex that do not contain any modifier
UPDATE Config
SET Value=SUBSTRING(Value FROM 2 FOR LENGTH(Value)-2)
WHERE ConfigID=(SELECT ID FROM ConfigSettings WHERE Name='patientIDRegex')
AND Value LIKE '/%/';

-- Convert all Perl regex that contain the case-insensitive modifier 'i'
UPDATE Config
SET Value=CONCAT('(?i)', SUBSTRING(Value FROM 2 FOR LENGTH(Value)-3))
WHERE ConfigID=(SELECT ID FROM ConfigSettings WHERE Name='patientNameRegex')
AND Value LIKE '/%/i';

-- Removes the leading and trailing forward slashes from every regex that do not contain any modifier
UPDATE Config
SET Value=SUBSTRING(Value FROM 2 FOR LENGTH(Value)-2)
WHERE ConfigID=(SELECT ID FROM ConfigSettings WHERE Name='patientNameRegex')
AND Value LIKE '/%/';

-- Convert all Perl regex that contain the case-insensitive modifier 'i'
UPDATE Config
SET Value=CONCAT('(?i)', SUBSTRING(Value FROM 2 FOR LENGTH(Value)-3))
WHERE ConfigID=(SELECT ID FROM ConfigSettings WHERE Name='LegoPhantomRegex')
AND Value LIKE '/%/i';

-- Removes the leading and trailing forward slashes from every regex that do not contain any modifier
UPDATE Config
SET Value=SUBSTRING(Value FROM 2 FOR LENGTH(Value)-2)
WHERE ConfigID=(SELECT ID FROM ConfigSettings WHERE Name='LegoPhantomRegex')
AND Value LIKE '/%/';

-- Convert all Perl regex that contain the case-insensitive modifier 'i'
UPDATE Config
SET Value=CONCAT('(?i)', SUBSTRING(Value FROM 2 FOR LENGTH(Value)-3))
WHERE ConfigID=(SELECT ID FROM ConfigSettings WHERE Name='LivingPhantomRegex')
AND Value LIKE '/%/i';

-- Removes the leading and trailing forward slashes from every regex that do not contain any modifier
UPDATE Config
SET Value=SUBSTRING(Value FROM 2 FOR LENGTH(Value)-2)
WHERE ConfigID=(SELECT ID FROM ConfigSettings WHERE Name='LivingPhantomRegex')
AND Value LIKE '/%/';





-- Add 'path' and 'web_path' to DataType enum. The first should represent an
-- arbitrary path used in LORIS. 'web_path' should represent a full path
-- that is reachable by the web-server i.e. Apache. Paths of type 'web_path'
-- will be validated when configured from the front-end and will throw errors
-- if not reachable by the server.
ALTER TABLE ConfigSettings MODIFY COLUMN DataType enum('text','boolean','email','instrument','textarea','scan_type','lookup_center','path','web_path');
UPDATE ConfigSettings SET DataType='web_path' where Name IN ('imagePath', 'base', 'data', 'extLibs', 'mincPath', 'DownloadPath', 'IncomingPath', 'MRICodePath', 'MRIUploadIncomingPath', 'GenomicDataPath', 'mediaPath', 'dataDirBasepath');
UPDATE ConfigSettings SET DataType='path' WHERE Name IN ('log', 'MRICodePath', 'tarchiveLibraryDir', 'get_dicom_info', 'niak_path');






INSERT INTO ConfigSettings
  (
    Name,
    Description,
    Visible,
    AllowMultiple,
    DataType,
    Parent,
    Label,
    OrderNumber
  )
  SELECT
    'reference_scan_type_for_defacing',
    'Scan type to use as a reference for registration when defacing anatomical images (typically a T1W image)',
    1,
    0,
    'scan_type',
    ID,
    'Scan type to use as a reference for defacing (typically a T1W image)',
    22
  FROM
    ConfigSettings
  WHERE
    Name="imaging_pipeline";
INSERT INTO ConfigSettings
  (
    Name,
    Description,
    Visible,
    AllowMultiple,
    DataType,
    Parent,
    Label,
    OrderNumber
  )
  SELECT
    'modalities_to_deface',
    'Modalities for which defacing should be run and defaced image inserted in the database',
    1,
    1,
    'scan_type',
    ID,
    'Modalities on which to run the defacing pipeline',
    23
  FROM
    ConfigSettings
  WHERE
    Name="imaging_pipeline";

INSERT INTO Config (ConfigID, Value) SELECT ID, 't1'    FROM ConfigSettings WHERE Name="reference_scan_type_for_defacing";
INSERT INTO Config (ConfigID, Value) SELECT ID, 'flair' FROM ConfigSettings WHERE Name="modalities_to_deface";
INSERT INTO Config (ConfigID, Value) SELECT ID, 't1'    FROM ConfigSettings WHERE Name="modalities_to_deface";
INSERT INTO Config (ConfigID, Value) SELECT ID, 't2'    FROM ConfigSettings WHERE Name="modalities_to_deface";
INSERT INTO Config (ConfigID, Value) SELECT ID, 'pd'    FROM ConfigSettings WHERE Name="modalities_to_deface";






INSERT INTO parameter_type_category_rel (ParameterTypeID, ParameterTypeCategoryID)
  SELECT DISTINCT ParameterTypeID, ParameterTypeCategoryID
  FROM   parameter_type, parameter_type_category ptc
  WHERE  SourceFrom="parameter_file" AND ptc.Name="MRI Variables";


INSERT INTO parameter_type_category (Name, Type)
  VALUES ('Electrophysiology Variables', 'Metavars');

INSERT INTO parameter_type_category_rel (ParameterTypeID, ParameterTypeCategoryID)
  SELECT DISTINCT ParameterTypeID, ParameterTypeCategoryID
  FROM   parameter_type, parameter_type_category ptc
  WHERE  SourceFrom="physiological_parameter_file" AND ptc.Name="Electrophysiology Variables";