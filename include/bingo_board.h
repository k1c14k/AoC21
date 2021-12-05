//
// Created by marek on 04.12.2021.
//

#ifndef AOC21_BINGO_BOARD_H
#define AOC21_BINGO_BOARD_H


#include <vector>

class BingoBoard {

public:
    explicit BingoBoard(std::vector<int> data);

    [[maybe_unused]] void display();

    bool check(int draw);

    unsigned long score();

    [[maybe_unused]] void display_checks();

private:
    int cell[5][5]{};
    bool checks[5][5]{};

    bool row_wins(int row);

    bool column_wins(int column);

    bool wins();
};


#endif //AOC21_BINGO_BOARD_H
