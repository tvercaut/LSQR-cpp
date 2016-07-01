#!/bin/csh
echo "RUNNING " $*
valgrind \
 --sim-hints=lax-ioctls \
 --trace-children=yes \
 -v \
 --tool=memcheck \
 --leak-check=yes \
 --show-reachable=yes \
  $* |& tee /tmp/lsqrValgrind.txt
