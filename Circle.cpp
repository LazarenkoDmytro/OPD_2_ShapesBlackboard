//
// Created by Dmytro Lazarenko on 02.10.2024.
//

#include "Circle.h"

Circle::Circle(int x, int y, int radius) : x(x), y(y), radius(radius) {}

int Circle::getID() const {
    return Shape::getID();
}

void Circle::draw(Board &board) const {
    int xi = 0;
    int yi = radius;
    int delta = 1 - radius;

    while (xi <= yi) {
        board.setPixel(x + xi, y + yi, '*');
        board.setPixel(x + xi, y - yi, '*');
        board.setPixel(x - xi, y + yi, '*');
        board.setPixel(x - xi, y - yi, '*');
        board.setPixel(x + yi, y + xi, '*');
        board.setPixel(x + yi, y - xi, '*');
        board.setPixel(x - yi, y + xi, '*');
        board.setPixel(x - yi, y - xi, '*');

        if (delta < 0) {
            delta += 2 * xi + 3;
        } else {
            delta += 2 * (xi - yi) + 5;
            yi--;
        }
        xi++;
    }
}

bool Circle::isEqual(std::shared_ptr<Shape> other) const {
    auto *otherCircle = dynamic_cast<Circle *>(other.get());
    if (otherCircle) {
        return x == otherCircle->x && y == otherCircle->y && radius == otherCircle->radius;
    }

    return false;
}

std::string Circle::getInfo() const {
    return "Circle " + std::to_string(x) + " " + std::to_string(y) + " " + std::to_string(radius);
}

void Circle::save(std::ostream &out) const {
    out << getInfo() << std::endl;
}

std::shared_ptr<Shape> Circle::load(std::istream &in) {
    int x, y, radius;
    in >> x >> y >> radius;

    if (in.fail()) {
        return nullptr;
    }

    return std::make_shared<Circle>(x, y, radius);
}
