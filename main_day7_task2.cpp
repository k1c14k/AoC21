#include <map>
#include <iostream>
#include <algorithm>
#include "include/common_util.h"
#include "include/fuel_util.h"


int main() {
    std::ifstream infile("input/input_7_1.txt");

    auto input = read_csi(infile);

    int cheapest_pos = find_cheapest_position(input, [](int a) { return (1 + a) * a / 2; });

    std::cout << calculate_cost(input, cheapest_pos, [](int a) { return (1 + a) * a / 2; }) << std::endl;

    return 0;
}
