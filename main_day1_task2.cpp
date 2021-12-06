#include <iostream>
#include <fstream>
#include <array>

int main() {
    std::ifstream infile("input/input_1_1.txt");
    int previous;
    int next;
    int increases = 0;
    std::array<int, 3> frame{};
    int next_frame = 0;
    infile >> frame[0];
    infile >> frame[1];
    infile >> frame[2];
    previous = frame[0] + frame[1] + frame[2];

    while (infile >> frame[next_frame]) {
        next = frame[0] + frame[1] + frame[2];
        if (next > previous) increases++;
        next_frame = ++next_frame % 3;
        previous = next;
    }

    std::cout << increases << std::endl;
    return 0;
}
