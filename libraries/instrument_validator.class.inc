<?php
/**
 * This file contains validations and appropriate error messages for certain instrument questions
 * Specifically, checks for valid age and grade inputs and
 * adds validations for q's that (don't) need to be answered, based on the answer of a previous question
 *
 * PHP Version 7
 *
 */
trait instrument_validator {
	// Checks if age is between 0 and 100, or NA (use for Adults, and for Teacher forms)
	function validate_age ($values, $key, &$errors) {

		if (isset($values[$key])) {

			$user_input = $values[$key];

			// Not an "integer" and is not NA
			if (!ctype_digit($user_input) && $user_input != "NA") {
				$errors[$key] = "Specify age between 0 and 100 or NA.";
			}

			// Is greater than 100 or is less than 0
			if ($user_input > 100 || $user_input < 0) {
				$errors[$key] = "Specify age between 0 and 100 or NA.";
			}
		}
	}

	// Checks if age is between 0 and 100 (no NA option)
	function validate_child_age ($values, $key, &$errors) {

		if (isset($values[$key])) {

			$user_input = $values[$key];

			// Not an "integer"
			if (!ctype_digit($user_input)) {
				$errors[$key] = "Specify age between 0 and 100.";
			}

			// Is greater than 100 or is less than 0
			if ($user_input > 100 || $user_input < 0) {
				$errors[$key] = "Specify age between 0 and 100.";
			}
		}
	}

	// Checks if grade is between 1 and 12, K, Not Answered
	function validate_grade ($values, $key, &$errors) {

		if (isset($values[$key])) {

			$user_input = $values[$key];

			// Not an "integer" and is not K or NA
			if (!ctype_digit($user_input) && $user_input != "NA" && $user_input != "K") {
				$errors[$key] = "Specify grade between 1 and 12 or K, or NA if you wish to not answer.";
			}

			// Is greater than 100 or is less than 0
			if (ctype_digit($user_input) && ($user_input > 12 || $user_input < 1)) {
				$errors[$key] = "Specify grade between 1 and 12 or K, or NA if you wish to not answer.";
			}
		}
	}

	// Checks if grade is between 1 and 12, K or Not Attending
	function validate_grade_NA ($values, $key, &$errors) {

		if (isset($values[$key])) {

			$user_input = $values[$key];

			// Not an "integer" and is not K or NA
			if (!ctype_digit($user_input) && $user_input != "NA" && $user_input != "K") {
				$errors[$key] = "If child is attending school, specify grade between 1 and 12 or K. If child is not attending, enter NA.";
			}

			// Is greater than 100 or is less than 0
			if (ctype_digit($user_input) && ($user_input > 12 || $user_input < 1)) {
				$errors[$key] = "If child is attending school, specify grade between 1 and 12 or K. If child is not attending, enter NA.";
			}
		}
	}

	// In instrument class, if lead question has specific answer that leads to non required subquestions, call this fxn
	function validate_empty_subquestions ($values, $keys, &$errors, $msg = "") {

		foreach ($keys as $key) {
			if (isset($values[$key]) && $values[$key] != "") {
				if ($msg == "") {
					$errors[$key] = "This field should be left blank OR response in the related question should be changed.";
				} else {
					$errors[$key] = $msg;
				}
			}
	    }
	}

	// Checks if input is an int between $min and $max or NA
	function validate_numeric ($values, $key, &$errors, $min, $max) {

		if (isset($values[$key])) {

			$user_input = $values[$key];

			if (!ctype_digit($user_input) && $user_input != "NA") {
				$errors[$key] = "Specify a number between " . $min . " and " . $max . ", or NA.";
			}

			if (ctype_digit($user_input) && ($user_input > $max || $user_input < $min)) {
				$errors[$key] = "Specify a number between " . $min . " and " . $max . ", or NA.";
			}
		}
	}

	// Checks if input is a number (int or float) between $min and $max
	function validate_numeric_strict ($values, $key, &$errors, $min, $max) {

		if (isset($values[$key])) {

			$user_input = $values[$key];

			if (!is_numeric($user_input)) {
				$errors[$key] = "Specify a number between " . $min . " and " . $max;
			}

			if (is_numeric($user_input) && ($user_input > $max || $user_input < $min)) {
				$errors[$key] = "Specify a number between " . $min . " and " . $max;
			}
		}
	}
    function validate_numeric_strict_group ($values, $key, &$errors, $min, $max, $group, $label='raw score') {

        if (isset($values[$key])) {

            $user_input = $values[$key];

            if (!is_numeric($user_input)) {
                $errors[$group] = ucfirst($label) . " should be between " . $min . " and " . $max;
            }

            if (is_numeric($user_input) && ($user_input > $max || $user_input < $min)) {
                $errors[$group] = ucfirst($label) . " should be between " . $min . " and " . $max;
            }
        }
    }

	// Checks if input is a number (int or float) greater than or equal to 0
	function validate_positive_numeric ($values, $key, &$errors,$group) {

		if (isset($values[$key])) {

			$user_input = $values[$key];

			if (!is_numeric($user_input)) {
				$errors[$group] = "Specify a positive number";
			}

			if (is_numeric($user_input) && $user_input < 0) {
				$errors[$group] = "Specify a positive number";
			}
		}
	}

	// Checks if input is a number (int or float) greater than or equal to 0
	function validate_zip_code ($values, $key, &$errors, $group) {

		if (isset($values[$key]) && $values[$key] != '') {

			if (!preg_match('/^[0-9]{5}$/', $values[$key])) {
				$errors[$group] = 'Please enter a valid 5 digit zip code';
		    }
		}
	}
}
?>
