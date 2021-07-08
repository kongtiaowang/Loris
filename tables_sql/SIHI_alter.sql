ALTER TABLE SIHI CHANGE i_q4_if_yes_select_source i_q4_if_yes_select_source enum("non_professional","non_medical_proffesional","pediatrician","sleep_specialist") AFTER i_q4_seek_information_to_help_child_sleep_better;
ALTER TABLE SIHI CHANGE i_q4_if_sleep_specialist i_q4_if_sleep_specialist enum("short_term","long_term") AFTER i_q4_if_yes_select_source;
ALTER TABLE SIHI CHANGE i_q5_if_yes_select i_q5_if_yes_select enum("behavioral_intervention","nonpharmacological_medical","medication","dietary_supplements") AFTER i_q5_did_child_receive_intervention;
ALTER TABLE SIHI CHANGE i_q5_if_medication_select_which_medicine_your_child_used i_q5_if_medication_select_which_medicine_your_child_used enum("melatonin","clonidine","trazodone","mirtazapine","risperidone","quetiapine","zolpidem","zaleplon","temazepam","eszopiclone","clonazepam") AFTER i_q5_if_yes_select;

ALTER TABLE SIHI CHANGE ii_q4_if_yes_select_source ii_q4_if_yes_select_source enum("non_professional","non_medical_proffesional","pediatrician","sleep_specialist") AFTER ii_q4_seek_information_to_help_child_sleep_better;
ALTER TABLE SIHI CHANGE ii_q4_if_sleep_specialist ii_q4_if_sleep_specialist enum("short_term","long_term") AFTER ii_q4_if_yes_select_source;
ALTER TABLE SIHI CHANGE ii_q5_if_yes_select ii_q5_if_yes_select enum("behavioral_intervention","nonpharmacological_medical","medication","dietary_supplements") AFTER ii_q5_did_child_receive_intervention;
ALTER TABLE SIHI CHANGE ii_q5_if_medication_select_which_medicine_your_child_used ii_q5_if_medication_select_which_medicine_your_child_used enum("melatonin","clonidine","trazodone","mirtazapine","risperidone","quetiapine","zolpidem","zaleplon","temazepam","eszopiclone","clonazepam") AFTER ii_q5_if_yes_select;

ALTER TABLE SIHI CHANGE iii_q4_if_yes_select_source iii_q4_if_yes_select_source enum("non_professional","non_medical_proffesional","pediatrician","sleep_specialist") AFTER iii_q4_seek_information_to_help_child_sleep_better;
ALTER TABLE SIHI CHANGE iii_q4_if_sleep_specialist iii_q4_if_sleep_specialist enum("short_term","long_term") AFTER iii_q4_if_yes_select_source;
ALTER TABLE SIHI CHANGE iii_q5_if_yes_select iii_q5_if_yes_select enum("behavioral_intervention","nonpharmacological_medical","medication","dietary_supplements") AFTER iii_q5_did_child_receive_intervention;
ALTER TABLE SIHI CHANGE iii_q5_if_medication_select_which_medicine_your_child_used iii_q5_if_medication_select_which_medicine_your_child_used enum("melatonin","clonidine","trazodone","mirtazapine","risperidone","quetiapine","zolpidem","zaleplon","temazepam","eszopiclone","clonazepam") AFTER iii_q5_if_yes_select;

ALTER TABLE SIHI CHANGE iv_q4_if_yes_select_source iv_q4_if_yes_select_source enum("non_professional","non_medical_proffesional","pediatrician","sleep_specialist") AFTER iv_q4_seek_information_to_help_child_sleep_better;
ALTER TABLE SIHI CHANGE iv_q4_if_sleep_specialist iv_q4_if_sleep_specialist enum("short_term","long_term") AFTER iv_q4_if_yes_select_source;
ALTER TABLE SIHI CHANGE iv_q5_if_yes_select iv_q5_if_yes_select enum("behavioral_intervention","nonpharmacological_medical","medication","dietary_supplements") AFTER iv_q5_did_child_receive_intervention;
ALTER TABLE SIHI CHANGE iv_q5_if_medication_select_which_medicine_your_child_used iv_q5_if_medication_select_which_medicine_your_child_used enum("melatonin","clonidine","trazodone","mirtazapine","risperidone","quetiapine","zolpidem","zaleplon","temazepam","eszopiclone","clonazepam") AFTER iv_q5_if_yes_select;

ALTER TABLE SIHI CHANGE v_q4_if_yes_select_source v_q4_if_yes_select_source enum("non_professional","non_medical_proffesional","pediatrician","sleep_specialist") AFTER v_q4_seek_information_to_help_child_sleep_better;
ALTER TABLE SIHI CHANGE v_q4_if_sleep_specialist v_q4_if_sleep_specialist enum("short_term","long_term") AFTER v_q4_if_yes_select_source;
ALTER TABLE SIHI CHANGE v_q5_if_yes_select v_q5_if_yes_select enum("behavioral_intervention","nonpharmacological_medical","medication","dietary_supplements") AFTER v_q5_did_child_receive_intervention;
ALTER TABLE SIHI CHANGE v_q5_if_medication_select_which_medicine_your_child_used v_q5_if_medication_select_which_medicine_your_child_used enum("melatonin","clonidine","trazodone","mirtazapine","risperidone","quetiapine","zolpidem","zaleplon","temazepam","eszopiclone","clonazepam") AFTER v_q5_if_yes_select;

