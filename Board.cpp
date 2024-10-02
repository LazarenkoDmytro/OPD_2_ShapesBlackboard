//
// Created by Dmytro Lazarenko on 02.10.2024.
//

#include <fstream>
#include "Board.h"
#include "Shape.h"

const int BOARD_WIDTH = 80;
const int BOARD_HEIGHT = 25;
const char EMPTY_CELL = ' ';

Board::Board() : grid(BOARD_HEIGHT, std::vector<char>(BOARD_WIDTH, EMPTY_CELL)) {}

void Board::draw() {
    for (auto &row: grid) {
        std::fill(row.begin(), row.end(), EMPTY_CELL);
    }

    for (const auto &shape: shapes) {
        shape->draw(*this);
    }

    std::cout << '+' << std::string(BOARD_WIDTH, '-') << '+' << std::endl;
    for (const auto &row: grid) {
        std::cout << '|' << std::string(row.begin(), row.end()) << '|' << std::endl;
    }

    std::cout << '+' << std::string(BOARD_WIDTH, '-') << '+' << std::endl;
}

void Board::addShape(const std::shared_ptr<Shape> &shape) {
    for (auto &existingShape: shapes) {
        if (existingShape->isEqual(shape)) {
            std::cout << "Shape already exists" << std::endl;
            return;
        }

        shapes.push_back(shape);
    }
}

void Board::removeLastShape() {
    if (shapes.empty()) {
        std::cout << "No shapes to remove" << std::endl;
        return;
    }

    shapes.pop_back();
}

void Board::clear() {
    shapes.clear();
}

void Board::save(const std::string &filePath) const {
    std::ofstream out(filePath);
    if (!out) {
        std::cerr << "Cannot open file " << filePath << std::endl;
        return;
    }

    for (const auto &shape: shapes) {
        shape->save(out);
    }

    out.close();
    std::cout << "Saved to " << filePath << std::endl;
}

bool Board::load(const std::string &filepath) {
    std::ifstream in(filepath);
    if (!in) {
        std::cerr << "Cannot open file " << filepath << std::endl;
        return false;
    }

    clear();

    while (auto shape = Shape::load(in)) {
        shapes.push_back(shape);
    }

    in.close();
    std::cout << "Loaded from " << filepath << std::endl;

    return true;
}

void Board::listShapes() const {
    for (const auto &shape: shapes) {
        std::cout << "ID: " << shape->getID() << ": " << shape->getInfo() << std::endl;
    }
}

void Board::setPixel(int x, int y, char c) {
    if (x >= 0 && x < BOARD_WIDTH && y >= 0 && y < BOARD_HEIGHT) {
        grid[y][x] = c;
    }
}

void Board::drawLine(int x1, int y1, int x2, int y2) {
    int dx = std::abs(x2 - x1);
    int sx = x1 < x2 ? 1 : -1;
    int dy = -std::abs(y2 - y1);
    int sy = y1 < y2 ? 1 : -1;
    int err = dx + dy;
    int e2;
    while (true) {
        setPixel(x1, y1, '*');
        if (x1 == x2 && y1 == y2) {
            break;
        }

        e2 = 2 * err;
        if (e2 >= dy) {
            err += dy;
            x1 += sx;
        }
        if (e2 <= dx) {
            err += dx;
            y1 += sy;
        }
    }
}
