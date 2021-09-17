-- Remove old OWL AND MANTIS LINKS FROM IBIS WEBPAGE
DELETE FROM ExternalLinks
    WHERE LinkText IN ('Report a Bug (Mantis)', 'Document repository (OWL)');
