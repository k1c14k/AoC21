#include <iostream>
#include <set>
#include <vector>
#include "include/bingo_board.h"
#include "include/bingo_board_util.h"

long iterate_boards(std::vector<BingoBoard> &boards, int draw);

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
        auto result = iterate_boards(boards, draw);

        if (result != -1) {
            std::cout << result << std::endl;
            return 0;
        }
    }

    return 0;
}

long iterate_boards(std::vector<BingoBoard> &boards, int draw) {
    auto board = boards.begin();
    while (board < boards.end()) {
        if (board->check(draw)) {
            if (boards.size() > 1) {
                boards.erase(board);
                continue;
            } else {
                return board->score() * draw;
            }
        }
        ++board;
    }

    return -1;
}
