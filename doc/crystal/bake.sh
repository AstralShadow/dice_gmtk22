#!/bin/bash

for color in {"black","blue","green","red","white","yellow"};
do
    files=$(ls $color*.png | sort -t '-' -n -k 2 | tr '\n' ' ')
    echo $files
    montage $files -background none -tile x1 -geometry 100x100x0x0 sheet_$color.png
done
