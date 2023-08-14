<?php

// Function for live environment settings
function chargebee_portal_admin_settings($form, &$form_state) {
  // Define the form for live environment settings
  $form['chargebee_live_api_key'] = array(
    '#type' => 'textfield',
    '#title' => t('Live API Key'),
    '#default_value' => variable_get('chargebee_live_api_key', ''),
  );
  $form['chargebee_live_portal_url'] = array(
    '#type' => 'textfield',
    '#title' => t('Live Portal URL'),
    '#default_value' => variable_get('chargebee_live_portal_url', ''),
  );

  $form['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Save Configuration'),
  );

  return $form;
}

// Submit handler for live environment settings
function chargebee_portal_admin_settings_submit($form, &$form_state) {
  variable_set('chargebee_live_portal_url', $form_state['values']['chargebee_live_portal_url']);
  variable_set('chargebee_live_api_key', $form_state['values']['chargebee_live_api_key']);
  drupal_set_message(t('Configuration saved.'));
}

// New function for testing settings
function chargebee_portal_admin_testing_settings($form, &$form_state) {
  // If the form has been submitted, use the submitted values.
  $test_url = isset($form_state['input']['test_url']) ? $form_state['input']['test_url'] : variable_get('chargebee_portal_test_url', '');
  $test_api_key = isset($form_state['input']['test_api_key']) ? $form_state['input']['test_api_key'] : variable_get('chargebee_portal_test_api_key', '');
  $test_chargebee_user_id = isset($form_state['input']['test_chargebee_user_id']) ? $form_state['input']['test_chargebee_user_id'] : variable_get('chargebee_portal_test_chargebee_user_id', '');

  $form['testing_environment'] = array(
    '#type' => 'fieldset',
    '#title' => t('Testing Environment'),
    '#collapsible' => TRUE,
    '#collapsed' => FALSE,
  );

  $form['testing_environment']['test_url'] = array(
    '#type' => 'textfield',
    '#title' => t('Test URL'),
    '#description' => t('The endpoint URL for the Chargebee testing environment.'),
    '#default_value' => $test_url, // Use variable directly
  );

  $form['testing_environment']['test_api_key'] = array(
    '#type' => 'textfield',
    '#title' => t('Test API Key'),
    '#description' => t('The API key for the Chargebee testing environment.'),
    '#default_value' => $test_api_key, // Use variable directly
  );

  $form['testing_environment']['test_chargebee_user_id'] = array(
    '#type' => 'textfield',
    '#title' => t('Test Chargebee User ID'),
    '#description' => t('The Chargebee User ID to use for testing.'),
    '#default_value' => $test_chargebee_user_id, // Use variable directly
  );

  $form['testing_environment']['test_button'] = array(
    '#type' => 'submit',
    '#value' => t('Run Test'),
    '#submit' => array('chargebee_portal_run_test_submit'),
  );

  return $form;
}

function chargebee_portal_run_test_submit($form, &$form_state) {
  $test_url = $form_state['values']['test_url'];
  $test_api_key = $form_state['values']['test_api_key'];
  $test_chargebee_user_id = $form_state['values']['test_chargebee_user_id'];

  // Save the values for future use.
  variable_set('chargebee_portal_test_url', $test_url);
  variable_set('chargebee_portal_test_api_key', $test_api_key);
  variable_set('chargebee_portal_test_chargebee_user_id', $test_chargebee_user_id);

  // Run the test using the provided parameters.
  $result = chargebee_portal_create_session($test_chargebee_user_id, $test_api_key, $test_url);

  if ($result) {
    drupal_set_message(t('Test succeeded! Result: @result', array('@result' => print_r($result, TRUE))));
  } else {
    // Get additional error information.
    $error_details = isset($result['error_details']) ? $result['error_details'] : 'No additional details available.';
    $logs_link = l(t('Check the logs for details.'), 'admin/reports/dblog');
    $message = format_string('Test failed! Error details: @error_details. !logs_link', array('@error_details' => $error_details, '!logs_link' => $logs_link));
    drupal_set_message($message, 'error');
  }
}




