//
// Created by adrijarch on 6/28/18.
//

#include "World.hpp"
#include "const.hpp"

World::World(b2Vec2 size) {
    b2Vec2 gravity(0, 0);
    world = new b2World(gravity);
    b2BodyDef worldBorderBodyDef;
    worldBorderBodyDef.position.SetZero();
    worldBorder = world->CreateBody(&worldBorderBodyDef);
    b2Vec2 *worldCorners = new b2Vec2[4]{
            {0,                                  0},
            {0,                                  defaultHeightTiles * tileSizeMetres},
            {defaultWidthTiles * tileSizeMetres, defaultHeightTiles * tileSizeMetres},
            {defaultWidthTiles * tileSizeMetres, 0}
    }; // left down corner is [0, 0], all other positions are positive.
    b2ChainShape worldBorderShape;
    worldBorderShape.CreateLoop(worldCorners, 4);
    worldBorder->CreateFixture(&worldBorderShape, 0);
}
