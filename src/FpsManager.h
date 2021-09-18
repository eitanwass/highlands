//
// Created by eitan on 17-Sep-21.
//

#ifndef GUI_TEST_FPSMANAGER_H
#define GUI_TEST_FPSMANAGER_H

#include <SFML/System/Clock.hpp>

class FPSManager {
public:
    static sf::Clock m_clock;

    static sf::Time previousTime;
    static sf::Time currentTime;

    static float m_fps;

    static void Update();

    static float getFps();
private:
    FPSManager() = default;
};

#endif //GUI_TEST_FPSMANAGER_H
