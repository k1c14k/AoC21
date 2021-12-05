//
// Created by marek on 05.12.2021.
//

#ifndef AOC21_POINT_H
#define AOC21_POINT_H


class Point {

public:
    Point(int x, int y);

    [[maybe_unused]] void display() const;

    [[nodiscard]] int get_x() const;

    [[nodiscard]] int get_y() const;

private:
    int x;
    int y;
};


#endif //AOC21_POINT_H
