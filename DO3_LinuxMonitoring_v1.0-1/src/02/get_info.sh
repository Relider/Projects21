#!/bin/bash

echo "HOSTNAME = " $HOSTNAME
echo "TIMEZONE = " $(timedatectl | grep zone | awk '{print $3}') UTC $(date +%:::z)
echo "USER = " $USER
echo "OS = " $(cat /etc/issue | awk '{print $1 $2 $3}')
echo "DATE = " $(TZ="Europe/Moscow" date "+%d %B %Y %T")
echo "UPTIME = " $(uptime -p)
echo "UPTIME_SEC = " $(cat /proc/uptime | awk '{print $1}')
echo "IP = " $(ip --brief address show | awk '{print $3}' | cut -d'/' -f1)
echo "MASK = " $(ifconfig | grep broadcast | awk '{print $4}')
echo "GATEWAY = " $(ip r | grep default | awk '{print $3}')
echo "RAM_TOTAL = $(cat /proc/meminfo | grep MemTotal | awk '{print $2/(1024*1024)}' OFMT="%.3f") GB"
echo "RAM_USED = $(cat /proc/meminfo | grep MemAvailable | awk '{print $2/(1024*1024)}' OFMT="%.3f") GB"
echo "RAM_FREE = $(cat /proc/meminfo | grep MemFree | awk '{print $2/(1024*1024)}' OFMT="%.3f") GB"
echo "SPACE_ROOT = $(sudo df -k / | grep / | awk '{print $2/1024}' OFMT="%.2f") MB"
echo "SPACE_ROOT_USED = $(sudo df -k / | grep / | awk '{print $3/1024}' OFMT="%.2f") MB"
echo "SPACE_ROOT_FREE = $(sudo df -k / | grep / | awk '{print $4/1024}' OFMT="%.2f") MB"
