#ifndef SKY_INCLUDE_GUARD
#define SKY_INCLUDE_GUARD

#include <vector>
#include <random>
#include <curses.h>
#include "rand_engine.h"
#include "pieceofsky.h"
#include "stars.h"
#include "cluster.h"


class Sky{
private:
    Rand_Engine* random;
    int height, width;
    std::vector<Piece_Of_Sky*> stars;

public:
    Sky(Rand_Engine*, int height, int width);
    void tick();
    
};

#endif /* SKY_INCLUDE_GUARD */
