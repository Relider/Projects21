#!/bin/bash

font=('\033[97m' '\033[91m' '\033[92m' '\033[94m' '\033[95m' '\033[30m')
back=('\033[107m' '\033[101m' '\033[102m' '\033[104m' '\033[105m' '\033[40m')
brk='\033[0m'

function style(){
  echo -e "${back[$1]}${font[$2]}$3\033[0m"
}

echo "$(style $1-1 $2-1 "HOSTNAME")=$(style $3-1 $4-1 $HOSTNAME)"
echo "$(style $1-1 $2-1 "TIMEZONE")=$(style $3-1 $4-1 $(timedatectl | grep zone | awk '{print $3}') UTC $(date +%:::z))"
echo "$(style $1-1 $2-1 "USER")=" $(style $3-1 $4-1 $USER)
echo "$(style $1-1 $2-1 "OS")="$(style $3-1 $4-1 $(cat /etc/issue | awk '{print $1 $2 $3}'))
echo "$(style $1-1 $2-1 "DATE")=" $(style $3-1 $4-1 $(TZ="Europe/Moscow" date "+%d %B %Y %T"))
echo "$(style $1-1 $2-1 "UPTIME")=" $(style $3-1 $4-1 $(uptime -p))
echo "$(style $1-1 $2-1 "UPTIME_SEC")=" $(style $3-1 $4-1 $(cat /proc/uptime | awk '{print $1}'))
echo "$(style $1-1 $2-1 "IP")=" $(style $3-1 $4-1 $(ip --brief address show | awk '{print $3}' | cut -d'/' -f1))
echo "$(style $1-1 $2-1 "MASK")=" $(style $3-1 $4-1 $(ifconfig | grep broadcast | awk '{print $4}'))
echo "$(style $1-1 $2-1 "GATEWAY")=" $(style $3-1 $4-1 $(ip r | grep default | awk '{print $3}'))
echo "$(style $1-1 $2-1 "RAM_TOTAL")=$(style $3-1 $4-1 $(cat /proc/meminfo | grep MemTotal | awk '{print $2/(1024*1024)}' OFMT="%.3f") GB)"
echo "$(style $1-1 $2-1 "RAM_USED")=$(style $3-1 $4-1 $(cat /proc/meminfo | grep MemAvailable | awk '{print $2/(1024*1024)}' OFMT="%.3f") GB)"
echo "$(style $1-1 $2-1 "RAM_FREE")=$(style $3-1 $4-1 $(cat /proc/meminfo | grep MemFree | awk '{print $2/(1024*1024)}' OFMT="%.3f") GB)"
echo "$(style $1-1 $2-1 "SPACE_ROOT")=$(style $3-1 $4-1 $(sudo df -k / | grep / | awk '{print $2/1024}' OFMT="%.2f") MB)"
echo "$(style $1-1 $2-1 "SPACE_ROOT_USED")=$(style $3-1 $4-1 $(sudo df -k / | grep / | awk '{print $3/1024}' OFMT="%.2f") MB)"
echo "$(style $1-1 $2-1 "SPACE_ROOT_FREE")=$(style $3-1 $4-1 $(sudo df -k / | grep / | awk '{print $4/1024}' OFMT="%.2f") MB)"
