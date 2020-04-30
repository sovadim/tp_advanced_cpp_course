# cpplint
cpplint --filter=-legal/copyright,-readability/todo,-build/include_subdir,-build/header_guard,-readability/casting --linelength=120 hw2_loglib/loglib/src/* hw2_loglib/loglib/include/* hw2_loglib/samples/demo/src/*

# cppcheck
cppcheck --includes-file=hw2_loglib/include --enable=all --error-exitcode=1 --suppress=missingIncludeSystem hw2_loglib/src hw2_loglib/samples/demo/src
