#include <iostream>
#include <fstream>

int main() {
    std::ifstream infile("input/input_2_1.txt");
    std::string command;
    int parameter;
    int depth = 0;
    int position = 0;

    while (infile >> command >> parameter) {
        if (command == "forward") position += parameter;
        else if (command == "down") depth += parameter;
        else if (command == "up") depth -= parameter;
    }

    std::cout << depth * position << std::endl;
    return 0;
}
