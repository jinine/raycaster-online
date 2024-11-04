#include "Raycaster.h"

void Raycaster::castRays(wchar_t* screen, const Player& player, const Map& map, int screenWidth, int screenHeight) {
    float fFOV = 3.14159 / 4.0;
    float fDepth = 16.0f;

    for (int x = 0; x < screenWidth; x++) {
        float fRayAngle = (player.angle - fFOV / 2.0f) + ((float)x / (float)screenWidth) * fFOV;
        float fDistanceToWall = 0.0f;
        bool bHitWall = false;

        float fEyeX = cosf(fRayAngle);
        float fEyeY = sinf(fRayAngle);

        while (!bHitWall && fDistanceToWall < fDepth) {
            fDistanceToWall += 0.1f;
            int nTestX = (int)(player.x + fEyeX * fDistanceToWall);
            int nTestY = (int)(player.y + fEyeY * fDistanceToWall);

            if (map.getTile(nTestX, nTestY) == '#') {
                bHitWall = true;
            }
        }

        int nCeiling = (float)(screenHeight / 2.0) - screenHeight / ((float)fDistanceToWall);
        int nFloor = screenHeight - nCeiling;

        short nWallShade;
        if (fDistanceToWall <= fDepth / 4.0f)        nWallShade = 0x2588;
        else if (fDistanceToWall <= fDepth / 3.0f)   nWallShade = 0x2593;
        else if (fDistanceToWall <= fDepth / 2.0f)   nWallShade = 0x2592;
        else if (fDistanceToWall < fDepth)           nWallShade = 0x2591;
        else                                         nWallShade = ' ';

        for (int y = 0; y < screenHeight; y++) {
            if (y < nCeiling)
                screen[y * screenWidth + x] = ' ';
            else if (y >= nCeiling && y <= nFloor)
                screen[y * screenWidth + x] = nWallShade;
            else {
                float b = 1.0f - (((float)y - screenHeight / 2.0f) / ((float)screenHeight / 2.0f));
                short nFloorShade;
                if (b < 0.25)      nFloorShade = '#';
                else if (b < 0.5)  nFloorShade = 'x';
                else if (b < 0.75) nFloorShade = '.';
                else if (b < 0.9)  nFloorShade = '-';
                else               nFloorShade = ' ';
                screen[y * screenWidth + x] = nFloorShade;
            }
        }
    }
}
