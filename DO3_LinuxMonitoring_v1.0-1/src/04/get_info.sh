#!/bin/bash

font=('' '\033[97m' '\033[91m' '\033[92m' '\033[94m' '\033[95m' '\033[30m')
back=('' '\033[107m' '\033[101m' '\033[102m' '\033[104m' '\033[105m' '\033[40m')
color=('' 'white' 'red' 'green' 'blue' 'purple' 'black')

function from_default() {
  local result=$1
  if [[ $1 == "default" ]]
  then
    result=$2
  fi
  echo $result
}

function style(){
  box1=$(from_default $1 6)
  box2=$(from_default $2 1)
  echo -e "${back[$box1]}${font[$box2]}$3\033[0m"
}

echo "$(style $1 $2 "HOSTNAME")=$(style $3 $4 $HOSTNAME)"
echo "$(style $1 $2 "TIMEZONE")=$(style $3 $4 $(timedatectl | grep zone | awk '{print $3}') UTC $(date +%:::z))"
echo "$(style $1 $2 "USER")=" $(style $3 $4 $USER)
echo "$(style $1 $2 "OS")="$(style $3 $4 $(cat /etc/issue | awk '{print $1 $2 $3}'))
echo "$(style $1 $2 "DATE")=" $(style $3 $4 $(TZ="Europe/Moscow" date "+%d %B %Y %T"))
echo "$(style $1 $2 "UPTIME")=" $(style $3 $4 $(uptime -p))
echo "$(style $1 $2 "UPTIME_SEC")=" $(style $3 $4 $(cat /proc/uptime | awk '{print $1}'))
echo "$(style $1 $2 "IP")=" $(style $3 $4 $(ip --brief address show | awk '{print $3}' | cut -d'/' -f1))
echo "$(style $1 $2 "MASK")=" $(style $3 $4 $(ifconfig | grep broadcast | awk '{print $4}'))
echo "$(style $1 $2 "GATEWAY")=" $(style $3 $4 $(ip r | grep default | awk '{print $3}'))
echo "$(style $1 $2 "RAM_TOTAL")=$(style $3 $4 $(cat /proc/meminfo | grep MemTotal | awk '{print $2/(1024*1024)}' OFMT="%.3f") GB)"
echo "$(style $1 $2 "RAM_USED")=$(style $3 $4 $(cat /proc/meminfo | grep MemAvailable | awk '{print $2/(1024*1024)}' OFMT="%.3f") GB)"
echo "$(style $1 $2 "RAM_FREE")=$(style $3 $4 $(cat /proc/meminfo | grep MemFree | awk '{print $2/(1024*1024)}' OFMT="%.3f") GB)"
echo "$(style $1 $2 "SPACE_ROOT")=$(style $3 $4 $(sudo df -k / | grep / | awk '{print $2/1024}' OFMT="%.2f") MB)"
echo "$(style $1 $2 "SPACE_ROOT_USED")=$(style $3 $4 $(sudo df -k / | grep / | awk '{print $3/1024}' OFMT="%.2f") MB)"
echo "$(style $1 $2 "SPACE_ROOT_FREE")=$(style $3 $4 $(sudo df -k / | grep / | awk '{print $4/1024}' OFMT="%.2f") MB)"

echo "Column 1 background = $1 (${color[$(from_default $1 6)]})"
echo "Column 1 font color = $2 (${color[$(from_default $2 1)]})"
echo "Column 2 background = $3 (${color[$(from_default $3 6)]})"
echo "Column 2 font color = $4 (${color[$(from_default $4 1)]})"
