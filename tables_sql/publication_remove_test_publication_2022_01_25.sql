
Delete from publication_collaborator_rel where PublicationCollaboratorID IN (select LeadInvestigatorID from publication WHERE Title='Paper_Test_Test') and PublicationID IN (select PublicationID from publication WHERE Title='Paper_Test_Test') ;

DELETE FROM publication WHERE Title='Paper_Test_Test';


Delete from publication_collaborator_rel where PublicationCollaboratorID IN (select LeadInvestigatorID from publication WHERE Title='Test') and PublicationID IN (select PublicationID from publication WHERE Title='Test') ;

DELETE FROM publication WHERE Title='Test';


Delete from publication_collaborator_rel where PublicationCollaboratorID IN (select LeadInvestigatorID from publication WHERE Title='Test_test') and PublicationID IN (select PublicationID from publication WHERE Title='Test_test') ;

DELETE FROM publication WHERE Title='Test_test';


Delete from publication_collaborator_rel where PublicationCollaboratorID IN (select LeadInvestigatorID from publication WHERE Title='test_test_leigh') and PublicationID IN (select PublicationID from publication WHERE Title='test_test_leigh') ;

DELETE FROM publication WHERE Title='test_test_leigh';

Delete from publication_collaborator_rel where PublicationCollaboratorID IN (select LeadInvestigatorID from publication WHERE Title='Test_test_test') and PublicationID IN (select PublicationID from publication WHERE Title='Test_test_test') ;

DELETE FROM publication WHERE Title='Test_test_test';


Delete from publication_collaborator_rel where PublicationCollaboratorID IN (select LeadInvestigatorID from publication WHERE Title='A longitudinal MRI study of subcortical brain development in infants who develop autism and infants with fragile X syndrome.') and PublicationID IN (select PublicationID from publication WHERE Title='A longitudinal MRI study of subcortical brain development in infants who develop autism and infants with fragile X syndrome.') ;

DELETE FROM publication WHERE Title='A longitudinal MRI study of subcortical brain development in infants who develop autism and infants with fragile X syndrome.';


Delete from publication_collaborator_rel where PublicationCollaboratorID IN (select LeadInvestigatorID from publication WHERE Title='An initial description of 24 month brain areas and their patterns of functional connectivity.') and PublicationID IN (select PublicationID from publication WHERE Title='An initial description of 24 month brain areas and their patterns of functional connectivity.') ;

DELETE FROM publication WHERE Title='An initial description of 24 month brain areas and their patterns of functional connectivity.';


Delete from publication_collaborator_rel where PublicationCollaboratorID IN (select LeadInvestigatorID from publication WHERE Title='Appreciating Temporal Heterogeneity in Autism.') and PublicationID IN (select PublicationID from publication WHERE Title='Appreciating Temporal Heterogeneity in Autism.') ;

DELETE FROM publication WHERE Title='Appreciating Temporal Heterogeneity in Autism.';

