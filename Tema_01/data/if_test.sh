#!/bin/bash

cd ${1}
for filename in *
do
  if [ "$filename" == "NOTES" ]
  then
    echo "I'm a NOTES file."
  fi
done
