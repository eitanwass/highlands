//
// Created by eitan on 17-Sep-21.
//

#include "Camera.h"
#include "../managers/FpsManager.h"

Camera::Camera(sf::RenderWindow *window) {
    m_window = window;
    sf::View view(sf::Vector2f(0.f, 0.f), sf::Vector2f(window->getSize()));
    window->setView(view);
};

void Camera::move(float x, float y) {
    sf::Vector2f deltaVector(x, y);
    deltaVector *= m_cameraSpeed;

    sf::View view = m_window->getView();
    view.move(deltaVector);
    m_window->setView(view);
}

void Camera::move(sf::Vector2f v) {
    return Camera::move(v.x, v.y);
}