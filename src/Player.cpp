//
// Created by eitan on 18-Sep-21.
//

#include "Player.h"

Player::Player() {
    avatar = sf::CircleShape(10.f);
    avatar.setFillColor(sf::Color::Green);
}

void Player::draw(sf::RenderTarget &target, sf::RenderStates states) const {
    states.transform *= getTransform();
    target.draw(avatar, states);
};
