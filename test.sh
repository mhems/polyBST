#!/usr/bin/env bash

for file in *
do
    if [ -d $file ]; then
        pushd . &> /dev/null
        cd $file &> /dev/null
        echo "Testing $file:"
        ./runtests.sh
        if [ $? -ne 0 ]; then
            echo "tests for $file failed"
        fi
        popd &> /dev/null
    fi
done
