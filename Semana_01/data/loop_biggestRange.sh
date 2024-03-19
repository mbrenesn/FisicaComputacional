#!/bin/bash

for dir in alexander Bert Frank_Richard
do
  echo "The biggest range in" ${dir} " is:" `./biggestRange.sh ${dir}`
done

