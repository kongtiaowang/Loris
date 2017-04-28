-- Delete duplicate entry for ciss V06 in test battery to solve the issue in future
DELETE FROM nihaceProd.test_battery WHERE ID=1306 ;


 /* SELECT MAX(flag.CommentID), session.Visit_label,session.ID,flag.Test_Name
FROM flag JOIN session On(session.ID=flag.SessionID) and flag.Test_name='ciss'
and session.Visit_label= 'V06' and session.SubprojectID=11 GROUP BY session.ID
HAVING COUNT(session.ID)>2; */

-- Found out the session IDs with duplicate ciss entries by the above query, so we have to delete those latest extra formed duplicate entries

--  candID=855669 & sessionID=5387 &pscid=dcc2002
DELETE FROM `ciss` WHERE CommentID='855669dcc2002538711871493337171';
DELETE FROM `ciss` WHERE CommentID='DDE_855669dcc2002538711871493337171';
DELETE FROM `flag` WHERE CommentID='855669dcc2002538711871493337171';
DELETE FROM `flag` WHERE CommentID='DDE_855669dcc2002538711871493337171';

-- candID=685468 & sessionID=5390 & pscid=dcc2000
DELETE FROM `ciss` WHERE CommentID='685468dcc2000539011871493337602';
DELETE FROM `ciss` WHERE CommentID='DDE_685468dcc2000539011871493337602';
DELETE FROM `flag` WHERE CommentID='685468dcc2000539011871493337602';
DELETE FROM `flag` WHERE CommentID='DDE_685468dcc2000539011871493337602';

-- candID= 647411&sessionID=5391 & pscid= dcc2003
DELETE FROM `ciss` WHERE CommentID='647411dcc2003539111871493337975';
DELETE FROM `ciss` WHERE CommentID='DDE_647411dcc2003539111871493337975';
DELETE FROM `flag` WHERE CommentID='647411dcc2003539111871493337975';
DELETE FROM `flag` WHERE CommentID='DDE_647411dcc2003539111871493337975';




