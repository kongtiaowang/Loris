#!/usr/bin/env bash

# Wrapper script which waits until MySQL and Selenium are up and serving requests.

set -euo pipefail

cmd="$@"

max_attempts=10
attempt=0

echo "Waiting for mysqld..."

# Loop to check MySQL connection
while ! mysqladmin ping -h db -u SQLTestUser --password="TestPassword" --silent; do
  sleep 1
  attempt=$((attempt + 1))
  
  # Check if maximum attempts reached
  if [ "$attempt" -ge "$max_attempts" ]; then
    echo "MySQL did not respond after $max_attempts attempts. Creating a flag for GitHub Actions..."
    
    # Create a flag file to signal GitHub Actions
    echo "MySQL not started" > /tmp/mysql_error_flag
    break
  fi
done

if [ -v SELENIUM_REQUIRED ]; 
then
  echo "Waiting for Selenium..."
  until $(curl --output /dev/null --silent --head --fail http://selenium:4444/wd/hub); do
    sleep 1
  done
  echo "Selenium is alive"
fi

exec $cmd
