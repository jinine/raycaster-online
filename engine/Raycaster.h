#ifndef RAYCASTER_H
#define RAYCASTER_H

#include "Player.h"
#include "Map.h"

class Raycaster {
public:
    void castRays(wchar_t* screen, const Player& player, const Map& map, int screenWidth, int screenHeight);
};

#endif //RAYCASTER_H
