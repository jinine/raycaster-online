#include <random>
#include "Map.h"

Map::Map() {

    int width = 16;
    int height = 16;
    
    mapLayout.resize(width * height, L'#');

    std::mt19937 rng(std::random_device{}());
    std::uniform_int_distribution<int> tileDist(0, 100);

    for (int y = 1; y < height - 1; y++) {
        for (int x = 1; x < width - 1; x++) {
            int randomValue = tileDist(rng);

            if (randomValue < 70) {
                mapLayout[y * width + x] = L' ';
            } else if (randomValue < 85) {
                mapLayout[y * width + x] = L'#'; 
            } else {
                mapLayout[y * width + x] = L'*'; 
            }
        }
    }
    for (int i = 0; i < width; i++) {
        mapLayout[i] = mapLayout[(height - 1) * width + i] = L'#';
        mapLayout[i * width] = mapLayout[i * width + (width - 1)] = L'#';
    }
}

wchar_t Map::getTile(int x, int y) const {
    if (x < 0 || x >= width || y < 0 || y >= height) {
        return '#';
    }
    return mapLayout[y * width + x];
}
