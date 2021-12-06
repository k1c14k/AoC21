#include <iostream>
#include <fstream>

int main() {
    std::ifstream infile("input/input_2_1.txt");
    std::string command;
    int parameter;
    int depth = 0;
    int position = 0;
    int aim = 0;

    while (infile >> command >> parameter) {
        if (command == "forward") {
            position += parameter;
            depth += aim * parameter;
        } else if (command == "down") aim += parameter;
        else if (command == "up") aim -= parameter;
    }

    std::cout << depth * position << std::endl;
    return 0;
}
