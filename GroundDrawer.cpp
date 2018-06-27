//
// Created by adrijaneddebian on 4/26/18.
//

#include "GroundDrawer.hpp"
#include "const.hpp"

GroundDrawer::GroundDrawer() {
    vertexArray.resize(defaultHeightTiles * defaultWidthTiles * 4);
    vertexArray.setPrimitiveType(sf::Quads);
    groundTypesArray2D = new GroundTypes *[defaultWidthTiles];
    groundTexture.loadFromFile("res/tex.png");
    for (int x = 0; x < defaultWidthTiles; ++x) {
        groundTypesArray2D[x] = new GroundTypes[defaultHeightTiles];
        for (int y = 0; y < defaultHeightTiles; ++y) {
            groundTypesArray2D[x][y] = static_cast<GroundTypes>(random1000() % 2);
            sf::Vertex *quad = &vertexArray[(x * defaultHeightTiles + y) * 4];
            quad[0].position = sf::Vector2f(x * tileSize, y * tileSize);
            quad[1].position = sf::Vector2f(x * tileSize + tileSize, y * tileSize);
            quad[2].position = sf::Vector2f(x * tileSize + tileSize, y * tileSize + tileSize);
            quad[3].position = sf::Vector2f(x * tileSize, y * tileSize + tileSize);
            quad[0].texCoords = sf::Vector2f(groundTypesArray2D[x][y] * tileSize, 0);
            quad[1].texCoords = sf::Vector2f(groundTypesArray2D[x][y] * tileSize + tileSize, 0);
            quad[2].texCoords = sf::Vector2f(groundTypesArray2D[x][y] * tileSize + tileSize, tileSize);
            quad[3].texCoords = sf::Vector2f(groundTypesArray2D[x][y] * tileSize, tileSize);
        }
    }
}

void GroundDrawer::draw(sf::RenderTarget &target, sf::RenderStates) const {
    target.draw(vertexArray, &groundTexture);
}
