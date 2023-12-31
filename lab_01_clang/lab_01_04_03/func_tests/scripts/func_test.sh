#!/bin/bash

if [ ! -f ../../app.exe ]; then
    echo "В проекте нет файла app.exe"
    exit 1
fi

# Позитивные тесты

positive_tests=($(ls ../data | grep "^pos_")) 
length=${#positive_tests[@]}
count=1
errors=0
echo  \#\#\#\#\#\#\#\#\#\#\#\#\#\#
echo POSITIVE TESTS
echo \#\#\#\#\#\#\#\#\#\#\#\#\#\#
echo
for ((i = 0; i<$length; i=i+2))
do
    ./pos_case.sh "../data/${positive_tests[$i]}" "../data/${positive_tests[$i+1]}"

    if [[ $? =~ 0  ]]; then
        echo POSITIVE TEST$count: PASSED
    else
        echo POSITIVE TEST$count: FAILED
        errors=$(($errors+1))
    fi
    
    count=$(($count+1))
done
echo

# Негативные тесты

negative_tests=($(ls ../data | grep "^neg_[0-9][0-9]_in.txt$")) 
length=${#negative_tests[@]}
i=0
count=1
echo \#\#\#\#\#\#\#\#\#\#\#\#\#\#
echo NEGATIVE TESTS
echo \#\#\#\#\#\#\#\#\#\#\#\#\#\#
echo
for ((i = 0; i<$length; i++))
do
    ./neg_case.sh "../data/${negative_tests[i]}"
    if [[ $? =~ 0  ]]; then
        echo NEGATIVE TEST$count: PASSED
    else
        echo NEGATIVE TEST$count: FAILED
        errors=$(($errors+1))

    fi
    
    count=$(($count+1))
done
echo

echo \#\#\#\#\#\#\#\#\#\#\#\#\#\#
echo RESULT
echo \#\#\#\#\#\#\#\#\#\#\#\#\#\#
echo  
if [[ $errors =~ 0 ]]; then
    echo TESTS PASSED.
    exit 0
else
    echo TESTS FAILED.
    exit $errors
fi
