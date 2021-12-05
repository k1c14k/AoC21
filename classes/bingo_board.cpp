//
// Created by marek on 04.12.2021.
//

#include <iostream>
#include "../include/bingo_board.h"

BingoBoard::BingoBoard(std::vector<int> *data) {
    for (int i = 0; i < 25; i++) {
        this->cell[i / 5][i % 5] = data->at(i);
    }
}

[[maybe_unused]] void BingoBoard::display() {
    for (auto &i: cell) {
        for (int j: i)
            std::cout << j << " ";
        std::cout << std::endl;
    }
}

bool BingoBoard::check(int draw) {
    bool result = false;
    for (int i = 0; i < 5; i++)
        for (int j = 0; j < 5; j++) {
            if (cell[i][j] == draw) {
                result = true;
                checks[i][j] = true;
            }
        }
    return result && this->wins();
}

bool BingoBoard::wins() {
    for (int i = 0; i < 5; i++) {
        if (this->row_wins(i))
            return true;
        if (this->column_wins(i))
            return true;
    }

    return false;
}

bool BingoBoard::row_wins(int row) {
    return std::all_of(checks[row], checks[row] + 5, [](auto b) { return b; });
}

bool BingoBoard::column_wins(int column) {
    return std::all_of(checks, checks + 5, [&column](auto row) { return row[column]; });
}

unsigned long BingoBoard::score() {
    unsigned long result = 0;

    for (int i = 0; i < 5; i++)
        for (int j = 0; j < 5; j++)
            if (!checks[i][j]) result += cell[i][j];

    return result;
}

[[maybe_unused]] void BingoBoard::display_checks() {
    for (auto &i: checks) {
        for (int j: i)
            std::cout << (j ? "X" : "O") << " ";
        std::cout << std::endl;
    }
}
