//
// Created by Dmytro Lazarenko on 02.10.2024.
//

#include "Triangle.h"

Triangle::Triangle(int x1, int y1, int x2, int y2, int x3, int y3) : x1(x1), y1(y1), x2(x2), y2(y2), x3(x3), y3(y3) {}

int Triangle::getID() const {
    return Shape::getID();
}

void Triangle::draw(Board &board) const {
    board.drawLine(x1, y1, x2, y2);
    board.drawLine(x2, y2, x3, y3);
    board.drawLine(x3, y3, x1, y1);
}

bool Triangle::isEqual(std::shared_ptr<Shape> other) const {
    auto otherTriangle = std::dynamic_pointer_cast<Triangle>(other);
    if (otherTriangle) {
        return x1 == otherTriangle->x1 && y1 == otherTriangle->y1 &&
               x2 == otherTriangle->x2 && y2 == otherTriangle->y2 &&
               x3 == otherTriangle->x3 && y3 == otherTriangle->y3;
    }

    return false;
}

std::string Triangle::getInfo() const {
    return "Triangle " + std::to_string(x1) + " " + std::to_string(y1) + " " +
           std::to_string(x2) + " " + std::to_string(y2) + " " +
           std::to_string(x3) + " " + std::to_string(y3);
}

void Triangle::save(std::ostream &out) const {
    out << getInfo() << std::endl;
}

std::shared_ptr<Shape> Triangle::load(std::istream &in) {
    int x1, y1, x2, y2, x3, y3;
    in >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;

    if (in.fail()) {
        return nullptr;
    }

    return std::make_shared<Triangle>(x1, y1, x2, y2, x3, y3);
}
