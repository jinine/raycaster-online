#include "Player.h"
#include <windows.h>

Player::Player() : x(8.0f), y(8.0f), angle(0.0f), moveSpeed(5.0f), rotateSpeed(0.8f) {}

void Player::handleInput(float elapsedTime, const Map& map) {
    if (GetAsyncKeyState((unsigned short)('A')) & 0x8000)
        angle -= (rotateSpeed) * elapsedTime;
    if (GetAsyncKeyState((unsigned short)('D')) & 0x8000)
        angle += (rotateSpeed) * elapsedTime;

    if (GetAsyncKeyState((unsigned short)('W')) & 0x8000) {
        float newX = x + cosf(angle) * moveSpeed * elapsedTime;
        float newY = y + sinf(angle) * moveSpeed * elapsedTime;
        if (map.getTile(newX, newY) != '#') {
            x = newX;
            y = newY;
        }
    }

    if (GetAsyncKeyState((unsigned short)('S')) & 0x8000) {
        float newX = x - cosf(angle) * moveSpeed * elapsedTime;
        float newY = y - sinf(angle) * moveSpeed * elapsedTime;
        if (map.getTile(newX, newY) != '#') {
            x = newX;
            y = newY;
        }
    }
}
