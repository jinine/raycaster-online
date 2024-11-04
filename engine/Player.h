#ifndef PLAYER_H
#define PLAYER_H

#include <cmath>
#include "Map.h"

class Player {
public:
    float x, y, angle;
    float moveSpeed, rotateSpeed;

    Player();
    void handleInput(float elapsedTime, const Map& map);
};

#endif // PLAYER_H
