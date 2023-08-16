#!/bin/bash

source $(dirname "$0")/../../.test/test.sh

BINARY=prodcons
OUTPUT=/tmp/output.txt
TIMEOUT=30
SKIPPED=0


init_feedback "Esercizio prelievi multipli"

compile_and_run $BINARY $OUTPUT $TIMEOUT


perl -n -e 'BEGIN{$counter=0; @produced=(); @consumed=(); } if(/Produzione:\sval=(\d+)/) { $counter++; push @produced,$1; } if(/Prima\sconsumazione/ && $counter<2) { exit(0); } if(/(?:Prima|Seconda)\sconsumazione:\sval_\d=(\d+)/) { $counter--; push @consumed,$1; } if($counter>10 || $counter<0) { exit(1); } END { if($#produced!=$#consumed) { exit(1); }  for $i(0..$#produced) { if($produced[$i]!=$consumed[$i]){ exit(1); } } }' $OUTPUT

if [ $? -ne 0 ]
then
    failure "L'esecuzione non rispetta l'ordine corretto delle produzioni e delle consumazioni"
fi


static_analysis


success


