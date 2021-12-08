#include <iostream>
#include <fstream>
#include <vector>
#include <numeric>
#include "include/display.h"


int main() {
    std::ifstream infile("input/input_8_1.txt");
    std::vector<Display> displays;
    std::string ln;

    while (std::getline(infile, ln)) {
        displays.emplace_back(ln);
    }

    auto answer = std::accumulate(displays.begin(), displays.end(), 0, [](int a, Display b) {
        return a + b.count_1478();
    });

    std::cout << answer << std::endl;

    return 0;
}
