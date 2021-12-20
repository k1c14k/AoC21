#include <iostream>
#include "include/octopus_map.h"
#include "include/octopus_util.h"

int main() {
    std::ifstream infile("input/input_11_1.txt");

    OctopusMap map = load_map(infile);

    for (int i = 0; i < 100; i++)
        map.perform_flash();

    std::cout << map.get_flashes() << std::endl;

    return 0;
}

