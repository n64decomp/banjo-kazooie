#!/bin/bash

./tools/m2ctx.py $1

sed -i 's/sizeof(long)/8/g' ctx.c
