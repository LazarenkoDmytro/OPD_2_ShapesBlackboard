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
    Board();

    void draw();

    void addShape(const std::shared_ptr<Shape>& shape);

    void removeLastShape();

    void clear();

    void save(const std::string& filePath) const;

    [[nodiscard]] bool load(const std::string& filepath);

    void listShapes() const;

    void setPixel(int x, int y, char c);

    void drawLine(int x1, int y1, int x2, int y2);
};
