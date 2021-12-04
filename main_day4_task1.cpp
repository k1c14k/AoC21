#include <iostream>
#include <set>
#include <vector>
#include "classes/bingo_board.h"
#include "util/bingo_board_util.h"

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
        for (auto &board: boards) {
            if (board.check(draw)) {
                std::cout << board.score() * draw << std::endl;

                return 0;
            }
        }
    }

    return 0;
}
