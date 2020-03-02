Suppose that you are in the project directory after you get the new files,

You should run `tables_sql/libraries/feedback_mri_comments_ibis.sql` in the DB via mysql.

Then you should run composer install under the base directory to install a PHP class.

`cd ..`
`composer install`

Now, you are in the base directory, you need to create a symbolic link under the `htdocs` (which is the `htdocs` subdirectory under base directory) pointing to
`project/htdocs/feedback_mri_popup_ibis.php`

The command could be:

`cd htdocs`
`ln -s ../project/htdocs/feedback_mri_popup_ibis.php feedback_mri_popup_ibis.php`
