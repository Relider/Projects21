#!/bin/bash

if ! [[ -z $4 || -n $5 || $1 -gt 6 || $1 -lt 1 ||  $2 -gt 6 || $2 -lt 1  ||  $3 -gt 6 || $3 -lt 1 ||  $4 -gt 6 || $4 -lt 1 ]]
then
  if ! [[ $1 == $2 || $3 == $4 ]]
  then
    chmod +x ./get_info.sh
    chmod +x ./main.sh
    sudo ./get_info.sh $1 $2 $3 $4
  else
    echo "Error: ivalid value, run the script again?"
  fi
else
  echo "Error: invalid input"
fi