#!/bin/bash

if [ -n "$1" ] && [ -z "$2" ]
then
  regex="^[+-]?[0-9]+([.][0-9]+)?$"
  if ! [[ $1 =~ $regex ]]
  then
    echo "$1"
  else
    echo "Error: invalid input"
  fi
else
  echo "Error: invalid parameters"
fi
