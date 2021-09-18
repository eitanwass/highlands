//
// Created by eitan on 18-Sep-21.
//

#ifndef HIGHLANDS_PLAYER_H
#define HIGHLANDS_PLAYER_H

#include <SFML/Graphics.hpp>

class Player: public sf::Drawable, public sf::Transformable {
public:
    Player();
private:
    void draw(sf::RenderTarget &target, sf::RenderStates states) const override;

    sf::Vector2f position = sf::Vector2f(0.f, 0.f);

    sf::CircleShape avatar;
};


#endif //HIGHLANDS_PLAYER_H
