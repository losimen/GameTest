cmake_minimum_required(VERSION 3.21)
project(GameTest)

set(CMAKE_CXX_STANDARD 14)

find_package(SDL2 REQUIRED)
find_package(SDL2_image REQUIRED)

add_executable(GameTest main.cpp Game.cpp)
target_link_libraries(GameTest PRIVATE SDL2::SDL2 SDL2_image::SDL2_image)
