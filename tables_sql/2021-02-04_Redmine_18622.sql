ALTER TABLE SA_Intervention_History CHANGE occupational_therapy_individual_group occupational_therapy_individual_group enum('individual','group') default NULL;
ALTER TABLE SA_Intervention_History CHANGE physical_therapy_individual_group physical_therapy_individual_group enum('individual','group') default NULL;
ALTER TABLE SA_Intervention_History CHANGE speech_language_therapy_individual_group speech_language_therapy_individual_group enum('individual','group') default NULL;
ALTER TABLE SA_Intervention_History CHANGE comprehensive_behavioral_individual_group comprehensive_behavioral_individual_group enum('individual','group') default NULL;
ALTER TABLE SA_Intervention_History CHANGE other_individual_group other_individual_group enum('individual','group') default NULL;