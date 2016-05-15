#!/usr/bin/env bash

function create() {
    lang=$1
    if [ -d $lang ]; then
        pushd . &> /dev/null
        cd $lang &> /dev/null
        touch runtests.sh Makefile
        chmod +x runtests.sh
        echo "populated $lang"
        popd &> /dev/null
    fi
}

for lang in "$@"
do
    create $lang
done
