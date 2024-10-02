//
// Created by Dmytro Lazarenko on 02.10.2024.
//

#include <iostream>
#include <sstream>
#include "CLI.h"

CLI::CLI() = default;

void CLI::run() {
    std::string commandLine;
    std::cout << "Shapes Blackboard\n";
    std::cout << "Type 'help' to get a list of commands.\n";
    while (true) {
        std::cout << "> ";

        std::getline(std::cin, commandLine);

        if (commandLine == "exit") {
            break;
        }

        app.executeCommand(commandLine);
    }
}
