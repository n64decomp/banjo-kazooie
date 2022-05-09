#!/bin/bash

./tools/m2ctx.py $1

sed -i 's/\[\]/\[0\]/g' ctx.c
sed -i 's/sizeof(long)/8/g' ctx.c
