//
// Created by Dmytro Lazarenko on 02.10.2024.
//

#include "Shape.h"
#include "Circle.h"
#include "Rectangle.h"
#include "Triangle.h"

int counter = 0;

Shape::Shape() {
    id = ++counter;
}

Shape::~Shape() = default;

int Shape::getID() const {
    return id;
}

std::shared_ptr<Shape> Shape::load(std::istream &in) {
    std::string line;
    if (!std::getline(in, line)) return nullptr;

    std::istringstream ss(line);
    std::string type;
    ss >> type;
    if (type == "Circle") {
        return Circle::load(ss);
    } else if (type == "Rectangle") {
        return Rectangle::load(ss);
    } else if (type == "Triangle") {
        return Triangle::load(ss);
    } else {
        return nullptr;
    }
}
