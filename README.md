# Park Slope Food Coop Orientation System

This repo contains the code that runs the Park Slope Food Coop's orientation site.

## Installation

You can install it by following these directions:

 * Ensure you have a recent version of drush installed (5.10 should work)
 * Create a MySQL database and username/password combination
 * Create an apache (or any web server) configuration
 * Clone this repo: 
```
git clone https://github.com/jmcclelland/ort.git 
```
 * Install drupal (replace the items in capital with appropriate values from your developer instance)
```
drush site-install --account-mail='YOU@EXAMPLE.ORG' --account-name='admin' --account-pass='admin' --db-url='mysql://DBUSER:DBPASS@localhost/DBNAME'
```
 * If you get an error along the lines of "Multibyte string input conversion in PHP is active and must be disabled." then follow these directions for a debian-based operating system: create a file in the directory /etc/php5/conf.d called local.ini with the content:
```
[mbstring]
mbstring.http_input = pass
mbstring.http_output = pass
```
 * Install the psfc_orientation_features module (this will install all orientation depencies) and the psfc_user_fields (which is designed to be share by other PSFC drupal sites)
```
drush en psfc_orientation_features psfc_user_fields
```
 * Disable comments. Disabling them as part of our setup causes a bug when running simple test. Sigh.
```
drush dis comment
```
 * You won't be able to really test until you have some orientations scheduled. This usually happens when the cron job runs, so you may want to trigger that manually:
```
drush core-cron
```

## Testing

This project comes with some unit tests.

To run tests, take the following steps:

 * Enable the simpletest module
 * Go to: /admin/config/development/testing
 * Put a check in the PSFC checkbox and click "Run Tests"
 * Get a cup of coffee and wait.
