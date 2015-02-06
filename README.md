#Park Slope Food Coop Orientation System

This repo contains the code that runs the Park Slope Food Coop's orientation site.

You can install it by following these directions:

 * Ensure you have a recent version of drush installed (5.10 should work)
 * Create a MySQL database and username/password combination
 * Create an apache (or any web server) configuration
 * Check out the drupal-7 branch:
```
git checkout drupal-7 
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
 * You won't be able to really test until you have some orientations scheduled. This usually happens when the cron job runs, so you may want to trigger that manually:
```
drupal core-cron
```
