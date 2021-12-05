#include <iostream>
#include <fstream>
#include <memory>
#include "include/point.h"
#include "include/line.h"
#include "include/plane.h"
#include "include/plane_util.h"

int main() {
    std::ifstream infile("input/input_5_1.txt");

    auto plane = load_plane(infile, true);

    std::cout << plane->count_collisions() << std::endl;

    return 0;
}
