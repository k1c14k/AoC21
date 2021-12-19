#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include "include/chunk_parser.h"

int main() {
    std::ifstream infile("input/input_10_1.txt");
    std::string ln;
    std::vector<ulong> incomplete_scores;

    while (std::getline(infile, ln)) {
        ChunkParser chunk(ln);
        ulong incompleteScore = chunk.get_incomplete_score();
        if (incompleteScore > 0)
            incomplete_scores.push_back(incompleteScore);
    }

    std::sort(incomplete_scores.begin(), incomplete_scores.end());

    std::cout << incomplete_scores.at(incomplete_scores.size() / 2) << std::endl;

    return 0;
}

