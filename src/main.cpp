#include <iostream>

#include "directory.hpp"

int main() {
    mqr::directory d;

    d.printInfo();
    d.openRandomFile();

    return EXIT_SUCCESS;
}
