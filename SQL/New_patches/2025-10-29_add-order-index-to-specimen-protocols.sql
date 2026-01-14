-- Step 1: Add column only if not exists
ALTER TABLE biobank_specimen_protocol_attribute_rel
ADD COLUMN IF NOT EXISTS OrderIndex INT UNSIGNED NULL;

-- Step 2: Populate ONLY rows that are NULL
SET @r := -1;
SET @g := NULL;

UPDATE biobank_specimen_protocol_attribute_rel AS t1
INNER JOIN (
    SELECT
        SpecimenProtocolID,
        SpecimenAttributeID,
        @r := IF(@g = SpecimenProtocolID, @r + 1, 0) AS new_OrderIndex,
        @g := SpecimenProtocolID
    FROM biobank_specimen_protocol_attribute_rel
    WHERE OrderIndex IS NULL
    ORDER BY SpecimenProtocolID, SpecimenAttributeID
) AS ranked
ON t1.SpecimenProtocolID = ranked.SpecimenProtocolID
AND t1.SpecimenAttributeID = ranked.SpecimenAttributeID
SET t1.OrderIndex = ranked.new_OrderIndex
WHERE t1.OrderIndex IS NULL;

-- Step 3: Add UNIQUE constraint only if missing
ALTER TABLE biobank_specimen_protocol_attribute_rel
ADD CONSTRAINT UK_SpecimenProtocolId_OrderIndex
UNIQUE (SpecimenProtocolID, OrderIndex);

-- Step 4: Enforce NOT NULL (safe now)
ALTER TABLE biobank_specimen_protocol_attribute_rel
MODIFY OrderIndex INT UNSIGNED NOT NULL;

