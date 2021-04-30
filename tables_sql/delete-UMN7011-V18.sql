
DELETE FROM issues WHERE sessionID = (SELECT ID FROM session WHERE CandID='856337' AND Visit_label='V18');

DELETE FROM session WHERE CandID='856337' and Visit_label='V18';
