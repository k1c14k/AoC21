//
// Created by marek on 04.12.2021.
//

#ifndef AOC21_BINGO_BOARD_H
#define AOC21_BINGO_BOARD_H


#include <vector>
#include <array>

class BingoBoard {

public:
    explicit BingoBoard(std::vector<int> data);

    [[maybe_unused]] void display();

    bool check(int draw);

    long score();

    [[maybe_unused]] void display_checks();

private:
    std::array<std::array<int, 5>, 5> cell{};
    std::array<std::array<bool, 5>, 5> checks{};

    bool row_wins(int row);

    bool column_wins(int column);

    bool wins();
};


#endif //AOC21_BINGO_BOARD_H
