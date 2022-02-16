---
name: 'Creating a new instrument '
about: How to create a new instrument or change an instrument
title: instrument guide
labels: ''
assignees: ''

---

**The following tasks need to be completed to create a new instrument or change an instrument.**

- [ ]  1. Code the instrument in PHP (instrument scroe file if it needs)
`         Create an instrument file based on NDB_BVL_Instrument_TEMPLATE.class.inc.
`
`         Change an instrument file based on an exsiting instrument.
`
- [ ] 2.Populate instrument metadata tables
```
 Test names
 ie. `"INSERT INTO test_names (Test_name, Full_name, Sub_group) VALUES ('$test', '$name', '1');`
 Test subgroups
 ie. `INSERT INTO test_subgroups (ID,Subgroup_name) VALUES (1,'Subgroup_name');`
 Test battery
 ie. `INSERT INTO test_battery (Test_name, AgeMinDays, AgeMaxDays, Active, Stage, SubprojectID, Visit_label, CenterID) VALUES ('$test', '1', '99999', 'Y', 'Visit', '1', '2', NULL);`
```
- [ ] 3. Generate the MySQL table
```
cd /var/www/loris/tools
find ../project/instruments/NDB_BVL_Instrument_$TESTNAME.class.inc | php quickform_parser.php 
find ../project/instruments/NDB_BVL_Instrument_$TESTNAME.class.inc | php generate_tables_sql.php
```
- [ ]  4. Populate missing instrument into Loris instance
```
cd /var/www/loris/tools
 * php assign_missing_instruments.php [Visit_label] [confirm]
 * or
 * php assign_missing_instruments.php  [confirm]

```

- [ ] 5. Test the instrument

> Test all pages load properly.
> Test the project list, subproject list, visits for this instrument.
> Test the save function, ensure everything saves.
> Test the insrument in the DQT module, ensure it is easy to query in the DQT.

- [ ]  6. Use the NDA standard naming.
