//
// Created by Dmytro Lazarenko on 02.10.2024.
//

#include "Application.h"
#include "Circle.h"
#include "Rectangle.h"
#include "Triangle.h"

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

void addCircle(Board &board, std::stringstream &ss) {
    int x, y, radius;
    ss >> x >> y >> radius;
    if (ss.fail()) {
        std::cout << "Invalid parameters for circle." << std::endl;
        return;
    }
    auto shape = std::make_shared<Circle>(x, y, radius);
    board.addShape(shape);
}

void addRectangle(Board &board, std::stringstream &ss) {
    int x, y, width, height;
    ss >> x >> y >> width >> height;
    if (ss.fail()) {
        std::cout << "Invalid parameters for rectangle." << std::endl;
        return;
    }
    auto shape = std::make_shared<Rectangle>(x, y, width, height);
    board.addShape(shape);
}

void addTriangle(Board &board, std::stringstream &ss) {
    int x1, y1, x2, y2, x3, y3;
    ss >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
    if (ss.fail()) {
        std::cout << "Invalid parameters for triangle." << std::endl;
        return;
    }
    auto shape = std::make_shared<Triangle>(x1, y1, x2, y2, x3, y3);
    board.addShape(shape);
}

void addShape(Board &board, std::stringstream &ss) {
    std::string shapeType;
    ss >> shapeType;
    if (shapeType == "circle") {
        addCircle(board, ss);
    } else if (shapeType == "rectangle") {
        addRectangle(board, ss);
    } else if (shapeType == "triangle") {
        addTriangle(board, ss);
    } else {
        std::cout << "Unknown shape type: " << shapeType << std::endl;
    }
}

void saveBoard(const Board &board, std::stringstream &ss) {
    std::string filePath;
    ss >> filePath;
    if (filePath.empty()) {
        std::cout << "Please provide a file path." << std::endl;
        return;
    }
    board.save(filePath);
}

void loadBoard(Board &board, std::stringstream &ss) {
    std::string filePath;
    ss >> filePath;
    if (filePath.empty()) {
        std::cout << "Please provide a file path." << std::endl;
        return;
    }
    if (!board.load(filePath)) {
        std::cout << "Failed to load board from file." << std::endl;
    }
}

void Application::executeCommand(const std::string &commandLine) {
    std::stringstream ss(commandLine);
    std::string command;
    ss >> command;
    if (command == "help") {
        printHelp();
    } else if (command == "draw") {
        board.draw();
    } else if (command == "list") {
        board.listShapes();
    } else if (command == "shapes") {
        printShapes();
    } else if (command == "add") {
        addShape(board, ss);
    } else if (command == "undo") {
        board.removeLastShape();
    } else if (command == "clear") {
        board.clear();
    } else if (command == "save") {
        saveBoard(board, ss);
    } else if (command == "load") {
        loadBoard(board, ss);
    } else {
        std::cout << "Unknown command: " << command << std::endl;
        std::cout << "Type 'help' for a list of commands." << std::endl;
    }
}
