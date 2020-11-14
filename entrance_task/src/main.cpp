#include <iostream>
#include <string>
#include <sstream>
#include "stringbase.h"
#include "stringhelper.h"

#define DELIMITER "\t"
char *delimeter = "\t";

using sol::StringBase;

void print(char *str) {
    std::cout << str << std::endl;
}

void printData(const StringBase &base) {
    printStrings(base.getData(), delimeter);
}

int main() {
    print("Enter the string:");

    std::string input;

    std::getline(std::cin, input);

    StringBase sbase;
    for (auto a : parseString(input, delimeter)) {
        sbase.push(a);
    }

    /* Read user data till 'exit' command */
    while (true) {
        print("Next command:");
        std::string command;
        std::cin >> command;

        if (command == "insert") {
            std::string str;
            std::cin >> str;

            unsigned ind;
            std::cin >> ind;

            sbase.insert(str, ind);
        } else if (command == "change") {
            std::string str;
            std::cin >> str;

            unsigned ind;
            std::cin >> ind;

            sbase.change(str, ind);
        } else if (command == "remove") {
            unsigned ind;
            std::cin >> ind;
            sbase.remove(ind);
        } else {
            break;
        }
        printData(sbase);
    }

    return 0;
}
