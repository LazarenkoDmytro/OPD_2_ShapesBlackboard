//
// Created by Dmytro Lazarenko on 02.10.2024.
//

#pragma once


#include "Shape.h"

class Rectangle : public Shape {
private:
    int x;
    int y;
    int width;
    int height;
public:
    Rectangle(int x, int y, int width, int height);

    [[nodiscard]] int getID() const override;

    void draw(Board &board) const override;

    [[nodiscard]] bool isEqual(std::shared_ptr<Shape> other) const override;

    [[nodiscard]] std::string getInfo() const override;

    void save(std::ostream &out) const override;

    static std::shared_ptr<Shape> load(std::istream &in);
};
