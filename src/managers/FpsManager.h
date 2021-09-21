//
// Created by eitan on 17-Sep-21.
//

#ifndef GUI_TEST_FPSMANAGER_H
#define GUI_TEST_FPSMANAGER_H

#include <SFML/System/Clock.hpp>

class FPSManager {
public:
    static sf::Clock m_clock;

    const static sf::Time targetTimePerFrame;

    static void update();

    static float getFps();
    static sf::Time getDeltaTime();
private:
    FPSManager() = default;

    static float m_fps;
    constexpr const static float m_targetFps{60.f};

    static sf::Time m_deltaTime;
};

#endif //GUI_TEST_FPSMANAGER_H
