#!/bin/bash
echo "-----Menu-----:"
echo "1. Ascending Order"
echo "2.Dscending order"
echo "3.exit"
echo "Enter your choice:"
read ch

case $ch in
    1)
     echo "Enter the numbers"
     read -a arr
     len=${#arr[@]}

     for ((i=0;i<len-1;i++))
     do
        for ((j=0;j<len-i-1;j++))
        do 
           if [ ${arr[j]} -gt ${arr[j+1]} ];
           then
            temp=${arr[j]}  #there should not be any space
            arr[j]=${arr[j+1]}
            arr[j+1]=$temp
        fi
        done
    done

    echo "Sorted numbers are: ${arr[@]}"
    ;;

    2)
    echo "Enter the numbers:"
    read -a arr

    len=${#arr[@]} #no space between = and ${#arr[@]}

    for ((i=0;i<len-1;i++))
    do
        for ((j=0;j<len-i-1;j++))
        do
            if [ ${arr[j+1]} -gt ${arr[j]} ];
            then
                temp=${arr[j]}
                arr[j]=${arr[j+1]}
                arr[j+1]=$temp
            fi
        done
    done
    echo "So sorte elements are : ${arr[@]}"
    ;;

    3)
    echo "Exiting....."
    exit;;

    *)
    echo "please select valid choice"
    ;;

esac
# chmod +x 1.sh
# ./1.sh or sh 1.sh