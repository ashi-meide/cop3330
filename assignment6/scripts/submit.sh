#!/usr/bin/env sh

tar -czf ../proj6.tar.gz   \
        Stack.h            \
        Stack.hpp          \
        evaluateRPN.h      \
        evaluateRPN.hpp    \
        makefile
$READTAR '../proj6.tar.gz'
