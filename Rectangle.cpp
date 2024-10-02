//
// Created by Dmytro Lazarenko on 02.10.2024.
//

#include "Rectangle.h"

Rectangle::Rectangle(int x, int y, int width, int height) : x(x), y(y), width(width), height(height) {}

int Rectangle::getID() const {
    return Shape::getID();
}

void Rectangle::draw(Board &board) const {
    for (int i = x; i < x + width; i++) {
        board.setPixel(i, y, '*');
        board.setPixel(i, y + height - 1, '*');
    }

    for (int i = y; i < y + height; i++) {
        board.setPixel(x, i, '*');
        board.setPixel(x + width - 1, i, '*');
    }
}

bool Rectangle::isEqual(std::shared_ptr<Shape> other) const {
    auto *otherRectangle = dynamic_cast<Rectangle *>(other.get());
    if (otherRectangle) {
        return x == otherRectangle->x && y == otherRectangle->y && width == otherRectangle->width &&
               height == otherRectangle->height;
    }

    return false;
}

std::string Rectangle::getInfo() const {
    return "Rectangle " + std::to_string(x) + " " + std::to_string(y) + " " + std::to_string(width) + " " +
           std::to_string(height);
}

void Rectangle::save(std::ostream &out) const {
    out << getInfo() << std::endl;
}

std::shared_ptr<Shape> Rectangle::load(std::istream &in) {
    int x, y, width, height;
    in >> x >> y >> width >> height;

    if (in.fail()) {
        return nullptr;
    }

    return std::make_shared<Rectangle>(x, y, width, height);
}
