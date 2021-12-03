#include <iostream>
#include <fstream>

int main() {
    std::ifstream infile("input/input_1_1.txt");
    int previous, next, increases = 0;
    infile >> previous;

    while (infile >> next) {
        if (next > previous) increases++;
        previous = next;
    }

    std::cout << increases << std::endl;
    return 0;
}
