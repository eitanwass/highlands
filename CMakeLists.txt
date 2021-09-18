cmake_minimum_required(VERSION 3.21)
project(highlands)

set(CMAKE_CXX_STANDARD 20)

add_executable(highlands src/main.cpp src/Tile.cpp src/Tile.h src/core/Camera.cpp src/core/Camera.h src/managers/FpsManager.cpp src/managers/FpsManager.h src/Player.cpp src/Player.h src/core/Game.cpp src/core/Game.h)

include_directories(/usr/include/X11)
find_package(SFML COMPONENTS system window graphics network audio REQUIRED)
target_link_libraries(${PROJECT_NAME} sfml-graphics sfml-audio)
target_link_libraries(${PROJECT_NAME} X11)
