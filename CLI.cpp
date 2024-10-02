//
// Created by Dmytro Lazarenko on 02.10.2024.
//

#include <iostream>
#include <sstream>
#include "CLI.h"

CLI::CLI() = default;

void printHelp() {
    std::cout << "Available commands:" << std::endl;
    std::cout << "draw" << std::endl;
    std::cout << "list" << std::endl;
    std::cout << "shapes" << std::endl;
    std::cout << "add <shape> <parameters>" << std::endl;
    std::cout << "undo" << std::endl;
    std::cout << "clear" << std::endl;
    std::cout << "save <file-path>" << std::endl;
    std::cout << "load <file-path>" << std::endl;
    std::cout << "exit" << std::endl;
}

void printShapes() {
    std::cout << "Available shapes and their parameters:" << std::endl;
    std::cout << "circle <x> <y> <radius>" << std::endl;
    std::cout << "rectangle <x> <y> <width> <height>" << std::endl;
    std::cout << "triangle <x1> <y1> <x2> <y2> <x3> <y3>" << std::endl;
}

void CLI::run() {
    std::string commandLine;
    std::cout << "Shapes Blackboard\n";
    std::cout << "Type 'help' to get a list of commands.\n";
    while (true) {
        std::cout << "> ";

        std::getline(std::cin, commandLine);
        if (commandLine.empty()) {
            printHelp();
            continue;
        }

        std::stringstream ss(commandLine);
        std::string command;
        ss >> command;
        if (command == "exit") {
            break;
        }

        app.executeCommand(command);
    }
}
