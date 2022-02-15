#!/bin/bash
# Set LD_LIBRARY_PATH to program local libraries path prior to execution

SCRIPT_DIR=$( cd -- "$( dirname -- "${BASH_SOURCE[0]}" )" &> /dev/null && pwd ) # Get script location's absolute path

LIB_PATH=$SCRIPT_DIR/lib/ # Append library directory to script location
echo "Setting LD_LIBRARY_PATH to "$LIB_PATH
export LD_LIBRARY_PATH=$LIB_PATH # Send appended variable to environment

./build/astroTrack # Start program within shell containing modified environment