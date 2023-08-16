#!/bin/bash

source $(dirname "$0")/../../.test/test.sh

BINARY=meteo
OUTPUT=/tmp/output.txt
TIMEOUT=60
SKIPPED=0


init_feedback "Esercizio lettori-scrittori"


compile_and_run $BINARY $OUTPUT $TIMEOUT


perl -n -e 'BEGIN { $val1=0; $val2=0; $val3="no"}  if(/scrittura:\sTemperatura=(-?\d+),\sUmidità=(\d+),\sPioggia=(\w+)/) { $val1=$1; $val2=$2; $val3=$3; }  if(/lettura:\sTemperatura=(-?\d+),\sUmidità=(\d+),\sPioggia=(\w+)/) { if($1!=$val1 || $2!=$val2 || $3 ne $val3) { exit(1); } }' $OUTPUT

if [ $? -ne 0 ]
then
    failure "L'esecuzione non accede al buffer in ordine corretto"
fi


static_analysis


success

