#include <iostream>
#include <string>
#include <SFML/Graphics.hpp>
#include "Tile.h"
#include "Camera.h"
#include "FpsManager.h"
#include "Player.h"

void cameraControl(sf::RenderWindow* window, Camera* cam) {
    sf::Vector2i mousePos = sf::Mouse::getPosition(*window);
    sf::Vector2f windowSize = window->getView().getSize();

    sf::Vector2i edgeMovement{};
    float borderMargin = 30.f;
    if (mousePos.x < borderMargin && mousePos.x > 0) {
        // Left
        edgeMovement.x = -1;
    }
    else if (mousePos.x > windowSize.x - borderMargin && mousePos.x < windowSize.x) {
        // Right
        edgeMovement.x = 1;
    }

    if (mousePos.y < borderMargin && mousePos.y > 0) {
        // Top
        edgeMovement.y = -1;
    }
    else if (mousePos.y > windowSize.y - borderMargin && mousePos.y < windowSize.y) {
        // Bottom
        edgeMovement.y = 1;
    }

    cam->move(edgeMovement);
}

int main() {
    // For x11 gui forwarding
    setenv("DISPLAY", "127.0.0.1:0.0", false);

    sf::RenderWindow window(sf::VideoMode(512, 512), "Title");
    Camera cam(&window);

    Player p{};

    Tile* tiles[100] = {};
    for (int x = 3; x < 13; x++) {
        for (int y = 3; y < 13; y++) {
            tiles[(x - 3) * 10 + (y - 3)] = new Tile(x, y);
        }
    }

    sf::Event event{};
    while (window.isOpen()) {
        FPSManager::Update();
        float fps = FPSManager::getFps();

        window.setTitle(std::to_string((int)fps));

        cameraControl(&window, &cam);

        while (window.pollEvent(event)) {
            switch (event.type) {
                case sf::Event::Closed:
                    window.close();
                    break;
                case sf::Event::KeyPressed:
                    if (event.key.code == sf::Keyboard::Q) {
                        window.close();
                    }
                    break;
                case sf::Event::MouseButtonPressed:
                    if (event.mouseButton.button == sf::Mouse::Left) {
                        p.setPosition(window.mapPixelToCoords(sf::Mouse::getPosition(window)));
                    }
                default:
                    break;
            }
        }
        window.clear();
        for (Tile* tile: tiles) {
            window.draw(*tile);
        }
        window.draw(p);
        window.display();
    }
    return 0;
}
