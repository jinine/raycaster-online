#include <windows.h>
#include <iostream>
#include <string>
#include <chrono>
#include "Player.h"
#include "Map.h"
#include "Raycaster.h"

using namespace std;

int nScreenWidth = 120;
int nScreenHeight = 40;

int main() {
    wchar_t* screen = new wchar_t[nScreenWidth * nScreenHeight];
    HANDLE hConsole = CreateConsoleScreenBuffer(GENERIC_READ | GENERIC_WRITE, 0, NULL, CONSOLE_TEXTMODE_BUFFER, NULL);
    SetConsoleActiveScreenBuffer(hConsole);
    DWORD dwBytesWritten = 0;

    Map gameMap;
    Player player;
    Raycaster raycaster;

    auto tp1 = chrono::high_resolution_clock::now();

    while (true) {
        auto tp2 = chrono::high_resolution_clock::now();
        chrono::duration<float> elapsedTime = tp2 - tp1;
        tp1 = tp2;

        // Player controls
        player.handleInput(elapsedTime.count(), gameMap);

        // Ray-casting
        raycaster.castRays(screen, player, gameMap, nScreenWidth, nScreenHeight);

        screen[nScreenWidth * nScreenHeight - 1] = '\0';
        WriteConsoleOutputCharacterW(hConsole, screen, nScreenWidth * nScreenHeight, { 0, 0 }, &dwBytesWritten);
        Sleep(50);
    }

    delete[] screen;
    return 0;
}
