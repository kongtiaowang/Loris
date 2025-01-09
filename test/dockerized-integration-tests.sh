#!/usr/bin/env bash
set -x  # Print each command before execution
set -e  # Exit on any error
set -euo pipefail

# Core integration tests
docker compose run -T --rm integration-tests vendor/bin/phpunit --configuration test/phpunit.xml --testsuite LorisCoreIntegrationTests,LorisModuleIntegrationTests
