#include <iostream>
#include <map>
#include "include/common_util.h"
#include "include/lanternfish_common.h"

int main() {
    std::ifstream infile("input/input_6_1.txt");

    auto input = read_csi(infile);


    auto lanternfish_count = breed_lanternfish(input, 80);

    std::cout << lanternfish_count << std::endl;

    return 0;
}
