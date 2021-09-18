//
// Created by eitan on 18-Sep-21.
//

#include <iostream>
#include <string>
#include "Game.h"
#include "../managers/FpsManager.h"

sf::Vector2f cameraControl(sf::RenderWindow* window) {
    sf::Vector2i mousePos = sf::Mouse::getPosition(*window);
    sf::Vector2f windowSize = window->getView().getSize();

    sf::Vector2f edgeMovement{};
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

    return edgeMovement;
}

Game::Game(): m_window(sf::RenderWindow(sf::VideoMode(800, 600), "Title")),
              m_mainCamera(&m_window) {
//    m_window.setVerticalSyncEnabled(true);

    for (int x = 3; x < 13; x++) {
        for (int y = 3; y < 13; y++) {
            m_tiles[(x - 3) * 10 + (y - 3)] = new Tile(x, y);
        }
    }
};

void Game::run() {
    sf::Time timeSinceLastUpdate = sf::Time::Zero;
    while (m_window.isOpen()) {
        FPSManager::update();
        timeSinceLastUpdate += FPSManager::getDeltaTime();

        while (timeSinceLastUpdate > FPSManager::targetTimePerFrame) {
            timeSinceLastUpdate -= FPSManager::targetTimePerFrame;
            processEvents();
            update(FPSManager::targetTimePerFrame);
        }
        render();
    }
}

void Game::processEvents() {
    sf::Event event{};
    while (m_window.pollEvent(event)) {
        switch (event.type) {
            case sf::Event::Closed:
                m_window.close();
                break;
            case sf::Event::KeyPressed:
                if (event.key.code == sf::Keyboard::Q) {
                    m_window.close();
                }
                break;
            // TODO: Add dynamic event system (e.g: player signs to call function when mouse is clicked)
            default:
                break;
        }
    }
}

void Game::update(sf::Time deltaTime) {
    int fps = (int)FPSManager::getFps();

    m_window.setTitle(std::to_string(fps));

    sf::Vector2f cameraMovementDelta = cameraControl(&m_window);
    cameraMovementDelta *= deltaTime.asSeconds();
    m_mainCamera.move(cameraMovementDelta);
}

void Game::render() {
    m_window.clear();

    for (Tile* tile: m_tiles) {
        m_window.draw(*tile);
    }

    m_window.draw(m_player);

    m_window.display();
}