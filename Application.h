//
// Created by Dmytro Lazarenko on 02.10.2024.
//

#pragma once


#include <string>
#include "Board.h"

class Application {
private:
    Board board;
public:
    void executeCommand(const std::string &commandLine);
};
