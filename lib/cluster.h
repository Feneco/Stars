#ifndef CLUSTER_INCLUDE_GUARD
#define CLUSTER_INCLUDE_GUARD

#include <curses.h>
#include <vector>
#include "pieceofsky.h"
#include "rand_engine.h"
#include "utilities.h"


class Cluster : public Piece_Of_Sky {
private:
    int radius;
    int y, x;
    static const std::vector<char> charmap;
    static const float gamma;
    std::vector<int> star_power;
    Rand_Engine* random;
    float gaussianKernel(int y, int x);
public:
    Cluster(Rand_Engine*, int y, int x);
    void shine();
};

#endif /* CLUSTER_INCLUDE_GUARD */
