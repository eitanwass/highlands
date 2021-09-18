cmake_minimum_required(VERSION 3.21)
project(highlands)

set(CMAKE_CXX_STANDARD 20)

add_executable(highlands src/main.cpp src/Tile.cpp src/Tile.h src/Camera.cpp src/Camera.h src/FpsManager.cpp src/FpsManager.h)

include_directories(/usr/include/X11)
find_package(SFML COMPONENTS system window graphics network audio REQUIRED)
target_link_libraries(${PROJECT_NAME} sfml-graphics sfml-audio)
target_link_libraries(${PROJECT_NAME} X11)
