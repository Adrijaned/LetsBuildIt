//
// Created by adrijarch on 6/28/18.
//

#ifndef LETSBUILD_WORLD_H
#define LETSBUILD_WORLD_H

#include "Box2D/Box2D.h"

class World {
    b2World *world;
    b2Body *worldBorder;
public:
    World();
    b2Body *createPerson(b2Vec2 position);
    void step();
};


#endif //LETSBUILD_WORLD_H
