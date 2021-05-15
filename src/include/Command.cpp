#include "Command.h"

void InputIntNumberCommand::execute() {
    std::string text;
    while (true) {
        std::cin >> text;
        bool isNumber = true;
        for (auto c : text) {
            if (c < '0' || c > '9') {
                isNumber = false;
                break;
            }
        }
        if (!isNumber) {
            std::cout << "Wrong number! Try again\n";
        } else {
            break;
        }
    }
    number = 0;
    for (auto c : text) {
        number = number * 10 + c - '0';
    }
}

void PrintTextCommand::execute() {
    std::cout << text;
}