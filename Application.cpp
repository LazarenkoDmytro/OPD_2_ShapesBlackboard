//
// Created by Dmytro Lazarenko on 02.10.2024.
//

#include "Application.h"
#include "Circle.h"
#include "Rectangle.h"
#include "Triangle.h"


void Application::executeCommand(const std::string &commandLine) {
    std::stringstream ss(commandLine);
    std::string command;
    ss >> command;
    if (command == "draw") {
        board.draw();
    } else if (command == "list") {
        board.listShapes();
    } else if (command == "shapes") {
//        printShapes();
    } else if (command == "add") {
        std::string shapeType;
        ss >> shapeType;
        if (shapeType == "circle") {
            int x, y, radius;
            ss >> x >> y >> radius;
            if (ss.fail()) {
                std::cout << "Invalid parameters for circle." << std::endl;
                return;
            }
            auto shape = std::make_shared<Circle>(x, y, radius);
            board.addShape(shape);
        } else if (shapeType == "rectangle") {
            int x, y, width, height;
            ss >> x >> y >> width >> height;
            if (ss.fail()) {
                std::cout << "Invalid parameters for rectangle." << std::endl;
                return;
            }
            auto shape = std::make_shared<Rectangle>(x, y, width, height);
            board.addShape(shape);
        } else if (shapeType == "triangle") {
            int x1, y1, x2, y2, x3, y3;
            ss >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
            if (ss.fail()) {
                std::cout << "Invalid parameters for triangle." << std::endl;
                return;
            }
            auto shape = std::make_shared<Triangle>(x1, y1, x2, y2, x3, y3);
            board.addShape(shape);
        } else {
            std::cout << "Unknown shape type: " << shapeType << std::endl;
        }
    } else if (command == "undo") {
        board.removeLastShape();
    } else if (command == "clear") {
        board.clear();
    } else if (command == "save") {
        std::string filePath;
        ss >> filePath;
        if (filePath.empty()) {
            std::cout << "Please provide a file path." << std::endl;
            return;
        }
        board.save(filePath);
    } else if (command == "load") {
        std::string filePath;
        ss >> filePath;
        if (filePath.empty()) {
            std::cout << "Please provide a file path." << std::endl;
            return;
        }
        if (!board.load(filePath)) {
            std::cout << "Failed to load board from file." << std::endl;
        }
    } else {
        std::cout << "Unknown command: " << command << std::endl;
        std::cout << "Type 'help' for a list of commands." << std::endl;
    }
}
