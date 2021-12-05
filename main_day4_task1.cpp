#include <iostream>
#include <set>
#include <vector>
#include "include/bingo_board.h"
#include "include/bingo_board_util.h"

int main() {
    std::ifstream infile("input/input_4_1.txt");
    std::vector<int> draws = read_draws(infile);
    std::vector<BingoBoard> boards;

    std::vector<int> boardData = read_board_data(infile);
    while (boardData.size() == 25) {
        boards.emplace_back(boardData);
        boardData = read_board_data(infile);
    }

    for (auto draw: draws) {
        for (auto &board: boards) {
            if (board.check(draw)) {
                std::cout << board.score() * draw << std::endl;

                return 0;
            }
        }
    }

    return 0;
}
