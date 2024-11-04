#ifndef MAP_H
#define MAP_H

#include <string>

class Map {
private:
    std::wstring mapLayout;

public:
    static const int height = 16;
    static const int width = 16;

    Map();
    wchar_t getTile(int x, int y) const;
};

#endif // MAP_H
