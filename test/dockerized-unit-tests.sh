#!/usr/bin/env bash
set -euo pipefail

if [ -v DEBUG ];
then
    CONTAINER=unit-tests-debug
else
    CONTAINER=unit-tests
fi
docker-compose up --build
docker-compose run -T --rm ${CONTAINER} vendor/bin/phpunit --configuration test/phpunit.xml --testsuite LorisUnitTests $*
