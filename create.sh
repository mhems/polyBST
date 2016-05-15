#!/usr/bin/env bash

function create() {
    lang=$1
    if [ -d $lang ]; then
        pushd .
        cd $lang
        mkdir src tests
        touch runtests.sh Makefile
        echo "populated $lang"
        popd
    fi
}

for lang in "$@"
do
    create $lang
done
