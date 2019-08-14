#!/bin/bash

echo --- TODO -----

if [ $# -eq 1 ]
then
  dir=$1

  tmp=$(mktemp)
  cat $dir/.todo | while read task
  do
    echo $task > $tmp
    cat $dir/.langs | while read lang
    do
      if [ ! -e $dir/$task.$lang ]
      then
        echo "  $lang" >> $tmp
      fi
    done

    out=`cat $tmp`
    if [ "$out" != "$task" ]
    then
      cat $tmp
      echo
    fi
  done

  rm $tmp
fi
