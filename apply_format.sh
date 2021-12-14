#!/bin/bash

find hw1_processlib hw2_loglib -iname "*.h" -o -iname "*.cpp" | xargs clang-format -i
