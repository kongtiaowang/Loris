UPDATE  flag f
JOIN Vineland_DS_Infant ds ON (ds.CommentID=f.CommentID AND f.CommentID NOT LIKE 'DDE%' AND f.test_name='Vineland_DS_Infant') 
JOIN session s   ON(s.ID=f.sessionID) 
JOIN flag f2 on (s.ID=f2.sessionID AND f2.CommentID NOT LIKE 'DDE%' AND f2.test_name='Vineland_SA')
JOIN Vineland_SA ON (f2.CommentID=Vineland_SA.CommentID)
SET 
f.Data_entry=f2.Data_entry
Where 
f.Data_entry is NULL
