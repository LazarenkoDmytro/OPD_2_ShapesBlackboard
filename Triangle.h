//
// Created by Dmytro Lazarenko on 02.10.2024.
//

#pragma once


#include "Shape.h"

class Triangle : public Shape {
private:
    int x1, y1, x2, y2, x3, y3;
public:
    Triangle(int x1, int y1, int x2, int y2, int x3, int y3);

    [[nodiscard]] int getID() const override;

    void draw(Board &board) const override;

    [[nodiscard]] bool isEqual(std::shared_ptr<Shape> other) const override;

    [[nodiscard]] std::string getInfo() const override;

    void save(std::ostream &out) const override;

    static std::shared_ptr<Shape> load(std::istream &in);
};
