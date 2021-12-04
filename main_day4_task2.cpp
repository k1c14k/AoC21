#include <iostream>
#include <fstream>
#include <set>
#include <vector>
#include "classes/bingo_board.h"

std::vector<int> read_draws(std::ifstream &input);

std::vector<int> *read_board_data(std::ifstream &input);

int main() {
    std::ifstream infile("input/input_4_1.txt");
    std::vector<int> draws = read_draws(infile);
    std::vector<BingoBoard> boards;

    std::vector<int> *boardData = read_board_data(infile);
    while (boardData) {
        boards.push_back(*(new BingoBoard(boardData)));
        boardData = read_board_data(infile);
    }

    for (auto draw: draws) {
        auto board = boards.begin();
        while (board < boards.end()) {
            if (board->check(draw)) {
                if (board->wins()) {
                    if (boards.size() > 1) {
                        boards.erase(board);
                    } else {
                        std::cout << board->score() * draw << std::endl;
                        return 0;
                    }
                } else
                    ++board;
            } else
                ++board;
        }
    }

    return 0;
}

std::vector<int> *read_board_data(std::ifstream &input) {
    auto *result = new std::vector<int>();
    int line;

    for (int i = 0; (i < 25) && (input >> line); i++) {
        result->push_back(line);
    }

    if (result->size() == 25)
        return result;
    else
        return nullptr;
}

std::vector<int> read_draws(std::ifstream &input) {
    std::vector<int> result;
    std::string line;
    input >> line;
    size_t pos;
    while ((pos = line.find(',')) != std::string::npos) {
        result.push_back(std::stoi(line.substr(0, pos)));
        line.erase(0, pos + 1);
    }
    result.push_back(std::stoi(line));

    return result;
}
