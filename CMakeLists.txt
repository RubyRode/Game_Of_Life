cmake_minimum_required(VERSION 3.23)
project(Game_of_Life)

set(CMAKE_CXX_STANDARD 20)


add_executable(Game_of_Life main.cpp Include/Utility/Input_parser.cpp Include/Utility/Input_parser.h Include/World/World.cpp Include/World/World.h Include/World/Rules.cpp Include/World/Rules.h)
