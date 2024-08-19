#!/bin/bash

input=$1
if ! [[ -n "$input" && ${input:${#input}-1:1} == "/" ]]; then
    echo "$Error: invalid input"
    exit 1
fi

if ! [ -d "$input" ]; then
    echo "directory is not real"
    exit 2
fi

if ! [ -r "$input" ]; then
    echo "directory is unavailable for reading"
    exit 3
fi

if ! [ "$(sudo find $input -mindepth 1)" ]; then
    echo "directory is empty"
    exit 4
fi

chmod +x ./get_info.sh
sudo ./get_info.sh $input
