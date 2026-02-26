#!/usr/bin/env sh

tar -tzf "$1" | tree --fromfile .
printf "\357\200\214 Created $(basename "$1") for submission."
