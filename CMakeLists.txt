cmake_minimum_required(VERSION 3.23)
project(Game_of_Life)

set(CMAKE_CXX_STANDARD 20)

add_executable(Game_of_Life main.cpp Utility/Input_parser.cpp Utility/Input_parser.h World/World.cpp World/World.h World/Rules.cpp World/Rules.h)
