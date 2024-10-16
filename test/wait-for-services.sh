#!/usr/bin/env bash

# Wrapper script which waits until MySQL and Selenium are up and serving requests.

set -euo pipefail

cmd="$@"

if [ -v SELENIUM_REQUIRED ]; 
then
  echo "Waiting for Selenium..."
  until $(curl --output /dev/null --silent --head --fail http://selenium:4444/wd/hub); do
    sleep 1
  done
  echo "Selenium is alive"
fi

exec $cmd
