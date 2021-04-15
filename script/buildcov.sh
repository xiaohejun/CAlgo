#!/bin/bash

curDir=$(cd "$(dirname "$0")";pwd)
baseDir=$(cd "$curDir/../";pwd)

cd $baseDir
if [ ! -d "build" ]; then
    cd $curDir
    ./runtest.sh
fi

covfileDir=$baseDir/build/test/CMakeFiles/CAlgoTests.dir/__/src
cd $covfileDir
lcov --capture --directory . --output-file CAlgoTests.info --test-name CAlgoTests
genhtml CAlgoTests.info --output-directory $baseDir/output --title "CAlgoTests COV" --show-details --legend