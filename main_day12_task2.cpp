#include <iostream>
#include <fstream>
#include "include/cave_paths.h"

int main() {
    std::ifstream infile("input/input_12_1.txt");

    CavePaths paths;
    std::string ln;
    while (std::getline(infile, ln) && !ln.empty()) {
        paths.add_path(ln);
    }

    std::cout << paths.get_paths_count(true) << std::endl;

    return 0;
}

