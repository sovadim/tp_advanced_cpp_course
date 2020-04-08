# cpplint
cpplint --filter=-legal/copyright,-readability/todo,-build/include_subdir,-build/header_guard,-readability/casting --linelength=120 hw1/processlib/src/* hw1/processlib/include/* hw1/samples/echo-server/src/*

# cppcheck
cppcheck --includes-file=hw1/processlib/include --enable=all --error-exitcode=1 --suppress=missingIncludeSystem hw1/processlib/src hw1/samples/echo-server/src
