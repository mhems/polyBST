#!/usr/bin/env bash

function create() {
    lang=$1
    if [ -d $lang ]; then
        pushd .
        cd $lang
        touch runtests.sh Makefile
        chmod +x runtests.sh
        echo "populated $lang"
        popd
    fi
}

for lang in "$@"
do
    create $lang
done
