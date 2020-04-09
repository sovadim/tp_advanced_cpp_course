# cpplint
cpplint --filter=-legal/copyright,-readability/todo,-build/include_subdir,-build/header_guard,-readability/casting --linelength=120 hw2/loglib/src/* hw2/loglib/include/* hw2/samples/demo/src/*

# cppcheck
cppcheck --includes-file=hw2/loglib/include --enable=all --error-exitcode=1 --suppress=missingIncludeSystem hw2/loglib/src hw2/samples/demo/src
