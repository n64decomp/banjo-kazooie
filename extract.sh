#!/bin/bash

VERSIONS=(USA_10 USA_11 JP PAL)


echo 'Building BK tools...'
cd tools/bk_tools
make
echo 'Tools built!'
cd ../..

#extract roms
if ./tools/bk_tools/bk_extract -r baseroms; then
    for ver in "${VERSIONS[@]}" ; do
        echo "$ver"
	if [ -d "bin/$ver" ]; then
	    mkdir -p "asm/$ver"
	fi
    done
fi

