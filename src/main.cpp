#include <iostream>
#include <string>
#include <SFML/Graphics.hpp>
#include "Tile.h"
#include "Camera.h"
#include "FpsManager.h"

int main() {
    setenv("DISPLAY", "127.0.0.1:0.0", true);
    sf::RenderWindow window(sf::VideoMode(512, 512), "Title");
    Camera cam(&window);

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
        std::cout << "fps =" << fps << std::endl; // flooring it will make the frame rate a rounded number

        sf::Vector2i mousePos = sf::Mouse::getPosition(window);
        window.setTitle(std::to_string(mousePos.x) + ", " + std::to_string(mousePos.y));

        sf::Vector2i edgeMovement{};
        float borderMargin = 30.f;
        if (mousePos.x < borderMargin && mousePos.x > 0) {
            // Left
            edgeMovement.x = -1;
        }
        else if (mousePos.x > window.getView().getSize().x - borderMargin && mousePos.x < window.getView().getSize().x) {
            // Right
            edgeMovement.x = 1;
        }

        if (mousePos.y < borderMargin && mousePos.y > 0) {
            // Top
            edgeMovement.y = -1;
        }
        else if (mousePos.y > window.getView().getSize().y - borderMargin && mousePos.y < window.getView().getSize().y) {
            // Bottom
            edgeMovement.y = 1;
        }

        cam.move(edgeMovement);

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
                default:
                    break;
            }
        }
        window.clear();
        for (Tile* tile: tiles) {
            window.draw(*tile);
        }
        window.display();
    }
    return 0;
}
