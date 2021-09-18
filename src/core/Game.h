//
// Created by eitan on 18-Sep-21.
//

#ifndef HIGHLANDS_GAME_H
#define HIGHLANDS_GAME_H

#include <SFML/Graphics.hpp>
#include "Camera.h"
#include "../Tile.h"
#include "../Player.h"

class Game {
public:
    Game();
    void run();
private:
    void processEvents();
    void update();
    void render();

    sf::RenderWindow m_window;
    Camera m_mainCamera;

    Tile* m_tiles[100] = {};
    Player m_player{};
};


#endif //HIGHLANDS_GAME_H
