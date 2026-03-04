#!/usr/bin/env sh

./polynomial | diff -u ../scripts/polynomial.out -
