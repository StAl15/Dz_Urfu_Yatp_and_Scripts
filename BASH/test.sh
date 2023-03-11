# !/bin/bash
IFS=:
for path in $PATH; do
    filepath="$path/$1"
    
    # -x FILE - True, если FILE существует и является исполняемым.
    # -a and
    #-f FILE - True, если FILE существует и является обычным файлом (не каталогом или устройством).

    if [ -f "$filepath" -a -x "$filepath" ]; then
        echo "$filepath"
        exit 42
    fi
done

# for (( i=1; i<10; i++ ))
# do
#     echo $i
# done

# # simple while
# i=0
# while [ $i -lt 10 ]; do

# done

# echo "Hello $1"
# first=1
# second=1
# third=2
# count=3

# if [[ $1 -eq 1 ]] || [[ $1 -eq 2 ]]
# then
#     echo "1"
#     exit 0
# fi

# if [[ $1 -eq 3 ]]
# then
#     echo "1"
#     exit 0
# fi
# if [[ $1 -gt 92 ]]
# then
#     # echo "1.2200160415122E+19"
#     echo "max value: 9223372036854775807"
#     exit 0
# fi

# if [[ $1 -gt 3 ]]
# then
#     while [ $count -lt $1 ]
#         do
#             first=$(($second))
#             second=$(($third))
#             third=$(($first + $second))
#             count=$(($count + 1))
#             # echo "$count: $third"
#         done
# fi
# echo "$third"