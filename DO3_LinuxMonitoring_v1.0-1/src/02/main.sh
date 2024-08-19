#!/bin/bash

sudo ./get_info.sh
echo "write date's in file?(y/n)"
read answer
if [[ "$answer" == 'y' || "$answer" == 'Y' ]]
then
  filename=$(TZ="Europe/Moscow" date "+%d_%m_%y_%H_%M_%S")
  file="$filename.status"
  echo "$(sudo ./get_info.sh)" >> $file
fi