#!/bin/bash

EDGES=$1
TX_DATA_FILE=roadNet-TX.txt
C_DATA_FILE=src/main/c/data.h
RESOURCES_DIR=src/main/resources
mkdir -p $RESOURCES_DIR

echo Data generation with $EDGES edges

if [ ! -f $RESOURCES_DIR/$TX_DATA_FILE ]; then
  curl -o $RESOURCES_DIR/$TX_DATA_FILE.gz https://snap.stanford.edu/data/$TX_DATA_FILE.gz
  gzip -d $RESOURCES_DIR/$TX_DATA_FILE.gz
fi

python scripts/gen-data.py $EDGES $RESOURCES_DIR/$TX_DATA_FILE $RESOURCES_DIR/data.txt

# Generate C data file

echo \#include \"std.h\">$C_DATA_FILE
echo \#define EDGES_COUNT $EDGES >>$C_DATA_FILE
echo "const i32 edges_data[(EDGES_COUNT+2)*2] = {">>$C_DATA_FILE
cat $RESOURCES_DIR/data.txt>>$C_DATA_FILE
echo '};'>>$C_DATA_FILE