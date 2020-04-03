# cpplint
cpplint --filter=-legal/copyright,-readability/todo,-build/include_subdir,-build/header_guard,-readability/casting --linelength=120 hw1/src/* hw1/include/*

# cppcheck
cppcheck --includes-file=hw1/include --enable=all --error-exitcode=1 --suppress=missingIncludeSystem hw1/src