#!/bin/bash

find entrance_task hw1_processlib hw2_loglib -iname "*.h" -o -iname "*.cpp" | xargs clang-format -i
