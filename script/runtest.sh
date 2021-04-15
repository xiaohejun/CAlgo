#!/bin/bash

curDir=$(cd "$(dirname "$0")";pwd)
baseDir=$(cd "$curDir/../";pwd)

cd $baseDir
find . -name "*.gcda" -print0 | xargs -0 rm
if [ ! -d "build" ]; then
    mkdir build
fi

buildDir=$baseDir/build
cd $buildDir
cmake ..
make

./test/CAlgoTests