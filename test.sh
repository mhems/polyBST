#!/usr/bin/env bash

for file in *
do
    if [ -d $file ]; then
        pushd . &> /dev/null
        cd $file &> /dev/null
        echo "Testing $file:"
        ./runtests.sh
        popd &> /dev/null
    fi
done
