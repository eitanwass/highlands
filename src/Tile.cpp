//
// Created by eitan on 17-Sep-21.
//

#include "Tile.h"

Tile::Tile(sf::Vector2f (&verts)[4]) {
    m_vertices = sf::VertexArray(sf::Quads, 4);
    for (int i = 0; i < 4; ++i) {
        m_vertices[i].position = verts[i];
    }

    m_vertices[0].color = sf::Color(220, 220, 220);
};

Tile::Tile(int x_index, int y_index) {
    m_vertices = sf::VertexArray(sf::Quads, 4);

    sf::Vector2f verts[4] = {
            sf::Vector2f((x_index - y_index) * (m_width / 2), (y_index + x_index + 1) * (m_height / 2)),
            sf::Vector2f((x_index - y_index + 1) * (m_width / 2), (y_index + x_index) * (m_height / 2)),
            sf::Vector2f((x_index - y_index) * (m_width / 2), (y_index + x_index - 1) * (m_height / 2)),
            sf::Vector2f((x_index - y_index - 1) * (m_width / 2), (y_index + x_index) * (m_height / 2))
    };

    new (this) Tile(verts);
};

Tile::Tile(sf::Vector2i &indexes): Tile(indexes.x, indexes.y) {};

void Tile::draw(sf::RenderTarget &target, sf::RenderStates states) const {
    states.transform *= getTransform();
    target.draw(m_vertices);
};