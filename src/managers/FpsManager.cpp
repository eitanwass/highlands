//
// Created by eitan on 17-Sep-21.
//

#include <iostream>
#include "FpsManager.h"

sf::Clock FPSManager::m_clock = sf::Clock();

const sf::Time FPSManager::targetTimePerFrame = sf::seconds(1.f / FPSManager::m_targetFps);

float FPSManager::m_fps = 0;

sf::Time FPSManager::m_deltaTime = sf::Time::Zero;


void FPSManager::update() {
    m_deltaTime = m_clock.restart();
    m_fps = 1.f / m_deltaTime.asSeconds();
};

float FPSManager::getFps() {
    return m_fps;
};

sf::Time FPSManager::getDeltaTime() {
    return m_deltaTime;
};