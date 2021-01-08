#!/usr/bin/env bash

# Wrapper script which waits until MySQL and Selenium are up and serving requests.

set -euo pipefail

cmd="$@"

echo "Waiting for mysqld..."
while ! mysqladmin ping -h db -u SQLTestUser --password="TestPassword" --silent ; do
  sleep 1
done
if [ -v SELENIUM_REQUIRED ]; 
then
  echo "Waiting for Selenium..."
  while [[ "$(curl -s -o /dev/null -w ''%{http_code}'' selenium:4444/status)" != "200" ]]; do 
    sleep 1
  done
  echo "Selenium is alive"
fi
exec $cmd
