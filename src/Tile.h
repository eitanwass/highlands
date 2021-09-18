//
// Created by eitan on 17-Sep-21.
//

#ifndef GUI_TEST_TILE_H
#define GUI_TEST_TILE_H

#include <SFML/Graphics.hpp>

class Tile: public sf::Drawable, public sf::Transformable {
public:
    Tile(sf::Vector2f (&verts)[4]);
    Tile(int x_index, int y_index);
    Tile(sf::Vector2i &indexes);
private:
    void draw(sf::RenderTarget &target, sf::RenderStates states) const override;
    sf::VertexArray m_vertices;

    float m_height = 50.f;
    float m_width = 100.f;
};

#endif //GUI_TEST_TILE_H
