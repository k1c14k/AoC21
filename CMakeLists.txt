cmake_minimum_required(VERSION 3.21)
project(AoC21)

set(CMAKE_CXX_STANDARD 23)

add_executable(AoC21_day1_task1 main_day1_task1.cpp)
add_executable(AoC21_day1_task2 main_day1_task2.cpp)
add_executable(AoC21_day2_task1 main_day2_task1.cpp)
add_executable(AoC21_day2_task2 main_day2_task2.cpp)
add_executable(AoC21_day3_task1 main_day3_task1.cpp)
add_executable(AoC21_day3_task2 main_day3_task2.cpp)
add_executable(AoC21_day4_task1 main_day4_task1.cpp classes/bingo_board.cpp classes/bingo_board.h util/bingo_board_util.cpp util/bingo_board_util.h)
add_executable(AoC21_day4_task2 main_day4_task2.cpp classes/bingo_board.cpp classes/bingo_board.h util/bingo_board_util.cpp util/bingo_board_util.h)
