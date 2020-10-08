#!/bin/bash

for i in {0..19}
do
    p_output=$(./program < "tests/test$i.txt")
    p_output="$(cat tests/test$i.txt) $p_output $(cat tests/test$i.ans)"
    echo "Test $i:"
    echo $p_output | ./check | ./verdict
done 


