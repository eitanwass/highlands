//
// Created by eitan on 17-Sep-21.
//

#ifndef GUI_TEST_CAMERA_H
#define GUI_TEST_CAMERA_H

#include <SFML/Graphics.hpp>

class Camera {
public:
    Camera(sf::RenderWindow* window);

    void move(float x, float y);
    void move(sf::Vector2i);
private:
    sf::RenderWindow* m_window;
    float m_cameraSpeed = 100.f;
};
#endif //GUI_TEST_CAMERA_H
