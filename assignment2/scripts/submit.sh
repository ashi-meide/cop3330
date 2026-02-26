#!/usr/bin/env sh

tar -czf ../sphere.tar.gz \
    makefile              \
    sphere.cpp            \
    sphere.h
$READTAR '../sphere.tar.gz'
