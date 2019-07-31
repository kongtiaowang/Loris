alter table BSRC change indgrp_occupationaltherapy indgrp_occupationaltherapy varchar(255);
alter table BSRC change indgrp_physicaltherapy indgrp_physicaltherapy varchar(255);
alter table BSRC change indgrp_speechlangtherapy indgrp_speechlangtherapy varchar(255);
alter table BSRC change indgrp_behaviorintervention indgrp_behaviorintervention varchar(255);

-- Redmine 16417
UPDATE candidate SET Active='N' WHERE PSCID='PHI0279' ;