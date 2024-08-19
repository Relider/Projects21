#!/bin/bash
START=$(date +%s%N)

echo "Total number of folders (including all nested ones) = "$(sudo find "$1" -type d |wc -l)
echo "TOP 5 folders of maximum size arranged in descending order (path and size):"
for (( i=1; i <= 5; i++ )) 
do 
  echo $i" - "$(du "$1" -h * | sort -rh | head -"$i" | tail -n 1 | awk '{print $2 ", " $1}' )
done
echo "Total number of files = "$(sudo find "$1" -type f |wc -l)
echo "Number of:"
echo "Configuration files (with the .conf extension) = "$(sudo find $1 -name "*.conf" | wc -l)
echo "Text files = "$(sudo find $1 -name "*.txt" | wc -l)
echo "Executable files = "$(sudo find $1 -type f -executable | wc -l)
echo "Log files (with the extension .log) = "$(sudo find $1 -name "*.log" | wc -l)
echo "Archive files = "$(sudo find $1 -name "*.zip" -o -name "*.tar" -o -name "*.7z" -o -name "*.rar" | wc -l)
echo "Symbolic links = "$(sudo find $1 -type l | wc -l)
echo "TOP 10 files of maximum size arranged in descending order (path, size and type):"
for (( i=1; i <= 10; i++ )) 
do 
  echo -n $i" - "$(sudo find "$1" -type f -exec du -ah {} + | sort -rh | head -"$i" | tail -n 1 | awk '{print $2 ", " $1 ", "}' )
  string=$(sudo find "$1" -type f -exec du -ah {} + | sort -rh | head -"$i" | tail -n 1 | awk '{print $2}' )
  echo " "${string:$(expr index "$string" .)}
done
echo "TOP 10 executable files of the maximum size arranged in descending order (path, size and MD5 hash of file):"
for (( i=1; i <= 10; i++ )) 
do 
  echo -n $i" - "$(sudo find "$1" -type f -exec du -ah {} + | sort -rh | head -"$i" | tail -n 1 | awk '{print $2 ", " $1 ", "}' )
  string=$(sudo find "$1" -executable -exec du -ah {} + | sort -rh | head -"$i" | tail -n 1 | awk '{print $2}' )
  echo " "$(sha256sum "$string" | awk '{print $1}')
done
END=$(date +%s%N)
DIFF=$((($END-$START)/100000000))
echo "Script execution time (in seconds) = $(($DIFF/10)).${DIFF:$(expr index "$DIFF" .)}"
