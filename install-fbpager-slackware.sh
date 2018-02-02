#!/bin/sh
# This script compiles fbpager on Slackware 14.2.
./configure "$@"
make
automake --add-missing
./configure "$@"
echo=echo make install
