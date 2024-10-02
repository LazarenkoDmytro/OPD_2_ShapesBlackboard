//
// Created by Dmytro Lazarenko on 02.10.2024.
//

#pragma once


#include <vector>
#include "Shape.h"

class Board {
private:
    std::vector<std::vector<char>> grid;
    std::vector<std::shared_ptr<Shape>> shapes;
public:
    void draw() const;

    void addShape(std::shared_ptr<Shape> shape);

    void removeLastShape();

    void clear();

    void save(std::string filePath) const;

    [[nodiscard]] bool load(std::string filepath);

    void listShapes() const;

    void setPixel(int x, int y, char c);

    void drawLine(int x1, int y1, int x2, int y2);
};
