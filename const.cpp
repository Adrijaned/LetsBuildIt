//
// Created by adrijaneddebian on 4/26/18.
//

#include <random>
#include "const.hpp"

unsigned const int defaultWindowWidth = 500;
unsigned const int defaultWindowHeight = 500;
unsigned const int defaultWidthTiles = 50;
unsigned const int defaultHeightTiles = 50;
unsigned const int tileSizePixels = 64;
const float32 tileSizeMetres = 0.5f;
const float32 maxMoveSpeed = 2;
std::random_device r;
std::default_random_engine e1(r());
std::uniform_int_distribution<int> uniform_dist1000(0, 999);
int random1000() {
    return uniform_dist1000(e1);
}