//
// Created by eitan on 17-Sep-21.
//

#include "FpsManager.h"

sf::Clock FPSManager::m_clock = sf::Clock();

sf::Time FPSManager::previousTime = sf::Time();
sf::Time FPSManager::currentTime = sf::Time();

float FPSManager::m_fps = 0;


void FPSManager::Update() {
    currentTime = m_clock.getElapsedTime();
    m_fps = 1.f / (currentTime.asSeconds() - previousTime.asSeconds()); // the asSeconds returns a float
    previousTime = currentTime;
};

float FPSManager::getFps() {
    return m_fps;
};