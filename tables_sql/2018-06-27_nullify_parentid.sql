-- New ParentID with random 6 digits has to be updated for more security. So for the updated key generation logic to work; we want to nullify the column
UPDATE candidate SET ParentID=NULL;