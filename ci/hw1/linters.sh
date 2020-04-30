# cpplint
cpplint --filter=-legal/copyright,-readability/todo,-build/include_subdir,-build/header_guard,-readability/casting --linelength=120 hw1_processlib/processlib/src/* hw1_processlib/processlib/include/* hw1_processlib/samples/echo-server/src/*

# cppcheck
cppcheck --includes-file=hw1_processlib/processlib/include --enable=all --error-exitcode=1 --suppress=missingIncludeSystem hw1_processlib/processlib/src hw1_processlib/samples/echo-server/src
