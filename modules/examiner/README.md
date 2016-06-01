# Examiner Override

This module is overridden in IBIS for the special case of the mullen certification. The mullen is an instrument split into 5+ sections where each section should be certified separately.

Due to the current code and database structure, since certifications are associated to a specific instrument. the override adds a tag to the examiner certified for a subsection of mullen and then checks for that tag when fetching all certified examiners.

This module should no longer be overridden as of 17.0 with the new Examiner module arriving.