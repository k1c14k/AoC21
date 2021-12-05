#include <iostream>
#include <set>
#include <vector>
#include "include/bingo_board.h"
#include "include/bingo_board_util.h"

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
                if (boards.size() > 1) {
                    boards.erase(board);
                    continue;
                } else {
                    std::cout << board->score() * draw << std::endl;
                    return 0;
                }
            }
            ++board;
        }
    }

    return 0;
}
