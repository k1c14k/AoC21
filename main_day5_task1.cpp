#include <iostream>
#include <fstream>
#include <memory>
#include "classes/point.h"
#include "classes/line.h"
#include "classes/plane.h"
#include "util/plane_util.h"

int main() {
    std::ifstream infile("input/input_5_1.txt");

    auto plane = load_plane(infile);

    int more_than_two_lines = 0;

    for (int x = plane->get_min_x(); x <= plane->get_max_x(); x++)
        for (int y = plane->get_min_y(); y <= plane->get_max_y(); y++) {
            auto p = std::make_unique<Point>(x, y);
            if (plane->check_collisions(p.get()))
                more_than_two_lines++;
            p.reset();
        }

    std::cout << more_than_two_lines << std::endl;

    return 0;
}
