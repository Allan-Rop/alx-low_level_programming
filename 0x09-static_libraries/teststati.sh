#!/bin/bash
gcc -c *.h
ar rc libmy.a *.o
ranlib libmy.a
