#!/usr/bin/env sh

tar -czf ../proj4.tar.gz \
        makefile         \
        polynomial.cpp   \
        polynomial.h
$READTAR '../proj4.tar.gz'
