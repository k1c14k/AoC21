#include <iostream>
#include "include/octopus_map.h"
#include "include/octopus_util.h"

int main() {
    std::ifstream infile("input/input_11_1.txt");

    OctopusMap map = load_map(infile);

    int iteration = 0;
    while (true) {
        iteration++;
        if (map.perform_flash()) {
            std::cout << iteration << std::endl;
            break;
        }
    }

    return 0;
}

