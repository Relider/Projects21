#!/bin/bash
 
function value_of_conf() {
  local result=$1
  result=${result:${#result}-2:1}
  if [[ $result == "=" ]]
  then
    result="default"
  fi
  echo $result
}

n1=$(value_of_conf $(cat color.conf | grep column1_background))
n2=$(value_of_conf $(cat color.conf | grep column1_font_color))
n3=$(value_of_conf $(cat color.conf | grep column2_background))
n4=$(value_of_conf $(cat color.conf | grep column2_font_color))
if [[ $n1 -ge 1 && $n1 -le 6 || $n1 -eq "default" ]] && [[ $n2 -ge 1 && $n2 -le 6 || $n2 -eq "default" ]] && [[ $n3 -ge 1 && $n3 -le 6 || $n3 -eq "default" ]] && [[ $n4 -ge 1 && $n4 -le 6 || $n4 -eq "default" ]]
then 
  if ! [[ $n1 == $n2 && $n1 -ne "default" || $n3 == $n4&& $n3 -ne "default" ]]
  then
    if [ -f ./get_info.sh ]; then
      sudo ./get_info.sh $n1 $n2 $n3 $n4
    else
      echo "Error: file get_info.sh not found"
    fi
  else
    echo "Error: invalid value, run the script again?"
  fi
else
  echo "Error: invalid data"
fi
