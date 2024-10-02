#include <iostream>
#include "Circle.h"

int main() {
    std::cout << "Hello, World!" << std::endl;

    Circle circle(1, 2, 3);
    std::cout << circle.getID() << std::endl;

    Circle circle2(1, 2, 3);
    std::cout << circle2.getID() << std::endl;

    return 0;
}
