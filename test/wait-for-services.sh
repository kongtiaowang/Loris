#!/usr/bin/env bash

# Wrapper script which waits until MySQL and Selenium are up and serving requests.

set -euo pipefail

cmd="$@"

timeout=300  # Timeout in 300 seconds
elapsed=0

echo "Waiting for MySQL..."

while ! mysqladmin ping -h db -u SQLTestUser --password="TestPassword" --silent ; do
  sleep 1
  elapsed=$((elapsed + 1))
  echo "Elapsed time: $elapsed seconds"
done

echo "MySQL is alive"


if [ -v SELENIUM_REQUIRED ]; 
then
  echo "Waiting for Selenium..."
  until $(curl --output /dev/null --silent --head --fail http://selenium:4444/wd/hub); do
    sleep 1
  done
  echo "Selenium is alive"
fi

exec $cmd
