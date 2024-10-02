//
// Created by Dmytro Lazarenko on 02.10.2024.
//

#pragma once


#include <memory>
#include <iostream>
#include <sstream>
#include "Board.h"

class Shape {
protected:
    int id = 1;
public:
    Shape();

    virtual ~Shape();

    [[nodiscard]] virtual int getID() const;

    virtual void draw(Board &board) const = 0;

    [[nodiscard]] virtual bool isEqual(std::shared_ptr<Shape> other) const = 0;

    [[nodiscard]] virtual std::string getInfo() const = 0;

    virtual void save(std::ostream &out) const = 0;

    static std::shared_ptr<Shape> load(std::istream &in);
};
