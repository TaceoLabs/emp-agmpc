#!/usr/bin/env bash

EXEC="build/bin/test_sha256"
NUM_PARTIES=16

rm -rf out
mkdir out

for i in $(seq 1 $(($NUM_PARTIES - 1)))
do
    echo "Running party $i"
    echo  $EXEC $i $NUM_PARTIES 2
    $EXEC $i $NUM_PARTIES 2 > out/party$i.txt &
done

echo "Running party $NUM_PARTIES"
echo  $EXEC $NUM_PARTIES $NUM_PARTIES 2
$EXEC $NUM_PARTIES $NUM_PARTIES 2 > out/party$NUM_PARTIES.txt
