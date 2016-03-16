#!/bin/bash

JRE_LIBDIR=/usr/lib/jvm/jdk1.7.0_51/jre/lib/amd64/server
BOOST_LIBDIR=/home/matzke/mounts/GS-CAD/boost/1.50/gcc-4.8.4-default/lib

ROSE_HOME=/home/matzke/mounts/GS-CAD/ROSE/sources/devel/_build/installed

export LD_LIBRARY_PATH=$JRE_LIBDIR:$BOOST_LIBDIR:$ROSE_HOME/lib

if [ "$1" = "make" ]; then
    shift
    exec make ROSE_HOME=$ROSE_HOME "$@"
fi

exec "$@"
