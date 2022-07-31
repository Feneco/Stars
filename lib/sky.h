#pragma once

#include <vector>
#include <random>
#include <curses.h>
#include "rand_engine.h"
#include "pieceofsky.h"
#include "stars.h"


class Sky{
private:
    int height, width;
    std::vector<Piece_Of_Sky *> pieces;
    Rand_Engine* random;
public:
    Sky(Rand_Engine*, int height, int width);
    void tick();
};