#!/usr/bin/env bash

for file in *
do
    if [ -d $file ]; then
        pushd .
        cd $file
        echo "Testing $file:"
        ./runtests.sh
        popd
    fi
done
