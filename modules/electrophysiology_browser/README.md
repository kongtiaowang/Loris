# Electrophysiology Browser

## Purpose

The electrophysiology browser is intended to allow users to view candidate
electrophysiology (EEG, MEG...) sessions collected for a study.

## Intended Users

The primary types of users are:
1. Electrophysiology researchers who want to know details about the inserted datasets
2. Site coordinators or researchers ensuring the uploaded electrophysiology have
been correctly inserted into LORIS.

## Scope

The electrophysiology browser displays electrophysiology datasets that have been
inserted into LORIS from a BIDS collection. Derived or processed electrophysiolgy
datasets can also be accessed via this module.

NOT in scope at the moment:

Viewing capabilities of the electrophysiology datasets. This will be a feature
added later on.

## Permissions

The electrophysiology browser uses the following permissions. Anyone of them is 
sufficient to have access to the module.

electrophysiology_browser_view_allsites
  - This permission gives the user access to all electrophysiology datasets present in the database
  
electrophysiology_browser_view_site
  - This permission gives the user access to electrophysiology datasets from their own site(s) only