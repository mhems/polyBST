#!/usr/bin/env bash

function create() {
    lang=$1
    if [ ! -d $lang ]; then
        mkdir $lang
        cd $lang &> /dev/null
        cat << EOF > runtests.sh
#!/usr/bin/env bash


EOF
        chmod +x runtests.sh
        echo "populated $lang"
        cd ..
    fi
}

for lang in "$@"
do
    create $lang
done
