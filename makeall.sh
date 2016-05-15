#!/usr/bin/env bash

for file in *
do
    if [ -d $file ]; then
        pushd .
        cd $file
        make
        popd
    fi
done
