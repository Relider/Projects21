#!/bin/bash

function check_input(){
   input_valid=0
   len=$3
   if [ $# -eq 6 ]
   then
        if ! [[ -d $1 ]]
            then
                echo "Wrong path or filename "
                exit 1
            fi
            if ! [[ $2 =~ ^[0-9]+$ ]]
            then
                echo "Wrong number of folders "
                exit 1
            fi
            if ! [[ $3 =~ ^[a-z]+$ ]]
            then
                echo "Wrong name folders "
                exit 1
            elif ! [[ ${#len} -le 7 ]]
            then
                echo "Too much leters number for folders name "
                exit 1
            fi
            if ! [[ $4 =~ ^[0-9]+$ ]]
            then
                echo "Wrong number of files "
                exit 1
            fi
            if ! [[ $5 =~ ^[a-z]&&[.]+$ ]]
            then
                echo "Wrong name of files "
                exit 1
            fi
            if [[ $6 =~ ^[0-9]+[k]+[b]$ ]]
            then
                FileSize=$6
                FileSize=$(echo ${FileSize:0:-2})
                if [[ $FileSize -gt 100 ]]
                then
                echo "The file size must be less than 100 kb"
                exit 1
                fi
            else
                echo "wrong file size format"
                exit 1
            fi
    else
        input_valid=1
        echo "Wrong input arguments number "
   fi
   return $input_valid
}