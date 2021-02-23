#include <iostream>
#include <sstream>
#include <memory>
#include "stringbase.h"
#include "stringhelper.h"

using sol::StringBase;

void printData(const StringBase &base) {
    printStrings(base.getData(), "\t");
}

int main() {
    auto sbase = std::make_unique<StringBase>();

    const std::string delimeter = "\t";
    std::cout << "Enter the string:" << std::endl;

    std::string input;
    std::getline(std::cin, input);

    
    for (auto &a : parseString(input, delimeter)) {
        sbase->push(a);
    }

    /* Read user data till the 'exit' command */
    while (true) {
        std::string command;
        std::cin >> command;

        if (command == "insert") {
            std::string str;
            std::cin >> str;

            size_t ind;
            std::cin >> ind;

            sbase->insert(str, ind);
        } else if (command == "change") {
            std::string str;
            std::cin >> str;

            size_t ind;
            std::cin >> ind;

            sbase->change(str, ind);
        } else if (command == "remove") {
            size_t ind;
            std::cin >> ind;
            sbase->remove(ind);
        } else {
            break;
        }
        printData(sbase);
    }

    return 0;
}
