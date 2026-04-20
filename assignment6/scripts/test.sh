#!/usr/bin/env sh

./stack_rpn | diff -u ../scripts/stack_rpn.out -
