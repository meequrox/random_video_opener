#include "directory.hpp"

int main() {
    mqr::directory d;
    d.printInfo();
    d.openRandomFile();

    return 0;
}
