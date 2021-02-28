#include <iostream>
#include <sstream>
#include <memory>
#include "stringbase.h"
#include "stringhelper.h"

void printData(const sbaselib::StringBase *base) {
    sbaselib::printStrings(base->getData(), "\t");
}

int main() {
    auto sbase = std::make_unique<sbaselib::StringBase>();

    std::string_view delimeter = "\t";
    std::cout << "Enter the string:" << std::endl;

    std::string input;
    std::getline(std::cin, input);

    
    for (auto &a : sbaselib::parseString(input, delimeter)) {
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
        printData(sbase.get());
    }

    return 0;
}
