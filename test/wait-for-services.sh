#!/usr/bin/env bash

# Wrapper script which waits until MySQL and Selenium are up and serving requests.

set -euo pipefail

cmd="$@"

echo "Waiting for mysqld..."
timeout=60  # Timeout in seconds
elapsed=0
interval=1  # Check interval in seconds

while ! mysqladmin ping -h db -u SQLTestUser --password="TestPassword" --silent; do
  sleep "$interval"
  elapsed=$((elapsed + interval))
  
  if [ "$elapsed" -ge "$timeout" ]; then
    echo "MySQL did not respond within $timeout seconds. Outputting container logs..."
    # Adjust 'container_name' to your actual container name
    docker logs db
    exit 1
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
