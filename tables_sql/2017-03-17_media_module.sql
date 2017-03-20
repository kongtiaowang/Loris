INSERT IGNORE INTO user_perm_rel (`userID`, `permID`) VALUES (
  (SELECT ID FROM users WHERE UserID like '%gluneau%'), (SELECT permID FROM permissions WHERE code = 'media_write')
);


INSERT IGNORE INTO user_perm_rel (`userID`, `permID`) VALUES (
  (SELECT ID FROM users WHERE UserID like '%gluneau%'), (SELECT permID FROM permissions WHERE code = 'media_read')
);

INSERT INTO `media` (`session_id`, `instrument`, `date_taken`, `comments`, `file_name`, `file_type`, `data_dir`, `uploaded_by`, `hide_file`, `date_uploaded`)
VALUES (SELECT 
    as session_id
    `Instrument` as instrument,
    `Date_taken` as date_taken,
    `comments`,
    `File_name` as file_name,
    `File_type` as file_type,
    `Data_dir` as data_dir,
    `uploaded_by`,
    `hide_video` as hide_file,
    `Date_uploaded` as date_uploaded
FROM `videos`);

-- Not considered `PSCID`, `visitLabel`, `File_size`, `For_site`, `multipart`, `EARLI`,
