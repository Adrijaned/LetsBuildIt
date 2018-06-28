//
// Created by adrijarch on 6/28/18.
//

#include "World.hpp"
#include "const.hpp"

World::World() {
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

b2Body *World::createPerson(b2Vec2 position) {
    b2BodyDef personDef;
    personDef.position = position;
    personDef.type = b2_dynamicBody;
    personDef.fixedRotation = true;
    b2Body *person = world->CreateBody(&personDef);
    b2CircleShape personShape;
    personShape.m_radius = tileSizeMetres / 2;
    personShape.m_p.SetZero();
    b2FixtureDef fixtureDef;
    fixtureDef.shape = &personShape;
    fixtureDef.density = 1.0f;
    fixtureDef.friction = 0.3f;
    fixtureDef.restitution = 0.1f;
    person->CreateFixture(&fixtureDef);
    return person;
}

void World::step() {
    world->Step(1/60.0f, 6, 2);
}
