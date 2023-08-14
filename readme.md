# Chargebee Portal Integration Module

This Drupal module provides integration with the Chargebee payment portal. It includes configuration settings for both live and testing environments, allowing administrators to easily manage and test Chargebee portal sessions.

## Installation

1. Upload the `chargebee_portal` module to your Drupal modules directory.
2. Enable the module via the Drupal administration interface or using Drush.

## Configuration

Navigate to the configuration page at `/admin/config/services/chargebee_portal` to set up the module.

### Live Environment

In the "Live Environment" section, you can configure the following settings:

- **Live API Key**: Enter the API key for the Chargebee live environment. You can obtain this key from [Chargebee's API keys page](https://yourdomain.chargebee.com/apikeys_and_webhooks/api) (replace `yourdomain` with your specific domain).
- **Live Portal URL**: Enter the endpoint URL for the Chargebee live environment. Example format: `https://yourdomain.chargebee.com/api/v2/portal_sessions`.

### Testing Environment

In the "Testing Environment" section, you can configure settings for testing the integration:

- **Test URL**: Enter the endpoint URL for the Chargebee testing environment.
- **Test API Key**: Enter the API key for the Chargebee testing environment.
- **Test Chargebee User ID**: Enter a Chargebee User ID to use for testing.

You can then click the "Run Test" button to perform a test using the provided parameters. The result of the test will be displayed as a message.

## Documentation

Further documentation and API details can be found at [Chargebee API Documentation](https://apidocs.chargebee.com/docs/api/portal_sessions).

## Support

For any issues or support related to this module, please contact the module maintainer or refer to the official Drupal community forums.

## License

This module is licensed under the GNU General Public License, version 2 or later.
