#!/bin/bash
source check.sh
check_input $@

if [[ $? -eq 0 ]]
then
LettersForFiles=$5
LettresForFolders=$3
FolderName=$LettresForFolders
ScriptStartTime=$(date +%d%m%y)
touch ./filecreate.log
for ((j=1; j<=$2; j++))
 do
      FolderAdition="$(echo ${LettresForFolders:0:1})"
      FolderName=$FolderAdition$FolderName

      while [[ ${#FolderName} -lt 4  ]]
      do
          FolderName=$FolderAdition$FolderName
      done
      mkdir $1/$FolderName"_"$ScriptStartTime
      FileName="$(echo "$LettersForFiles" | awk -F "." '{print $1}')"
      FileExt="$(echo "$LettersForFiles" | awk -F "." '{print $2}')"
   for ((i=1; i<=$4; i++))
     do
     FileAddition="$(echo ${LettersForFiles:0:1})"
     FileName=$FileAddition$FileName
        while [[ ${#FileName} -lt 4  ]]
        do
              FileName=$FileAddition$FileName
        done
     FreeDiskSpace=$(df / | tail -n 1  | awk '{print $4}')
        if [[ $FreeDiskSpace -gt 1000000 ]]
         then
               if [[ ${#FileName} -le 252 ]]
               then
                  file_volume=$(echo $FileSize*1000 | bc -l)
                  base64 /dev/urandom | head -c $file_volume > $1/$FolderName"_"$ScriptStartTime/$FileName"_"$ScriptStartTime.$FileExt
                  echo "$1/$FolderName"_"$ScriptStartTime/$FileName"_"$ScriptStartTime.$FileExt"  $(date "+%d%m%y %H:%M:%S") $6 >> ./filecreate.log
               else
                  echo " Too many files and too few letters "
                  exit 1
               fi
         else
         echo "No enough free space on \ "
         exit 1
         fi
      done
   done
fi