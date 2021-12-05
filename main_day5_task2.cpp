#include <iostream>
#include <fstream>
#include <memory>
#include "classes/point.h"
#include "classes/line.h"
#include "classes/plane.h"
#include "util/plane_util.h"

int main() {
    std::ifstream infile("input/input_5_1.txt");

    auto plane = load_plane(infile, true);

    std::cout << plane->count_collisions() << std::endl;

    return 0;
}
