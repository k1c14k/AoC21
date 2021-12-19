#include <iostream>
#include <fstream>
#include "include/chunk_parser.h"

int main() {
    std::ifstream infile("input/input_10_1.txt");
    std::string ln;
    ulong corrupted_score = 0;

    while (std::getline(infile, ln)) {
        ChunkParser chunk(ln);
        corrupted_score += chunk.get_corrupted_score();
    }

    std::cout << corrupted_score << std::endl;

    return 0;
}

