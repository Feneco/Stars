#ifndef CLUSTER_INCLUDE_GUARD
#define CLUSTER_INCLUDE_GUARD

#include <ncurses.h>
#include <vector>
#include "pieceofsky.h"
#include "rand_engine.h"
#include "utilities.h"


class Cluster : public Piece_Of_Sky {
private:
    static const std::vector<char> charmap;
    Rand_Engine* random;
    int y, x;
    int radius;
    float gamma;
    std::vector<int> star_power;
    float gaussianKernel(int y, int x);
    int convert_xy_to_i(int y, int x);

public:
    Cluster(Rand_Engine*, int y, int x);
    void shine();
    
};

#endif /* CLUSTER_INCLUDE_GUARD */
