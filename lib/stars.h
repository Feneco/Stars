#ifndef STARS_INCLUDE_GUARD
#define STARS_INCLUDE_GUARD

#include <curses.h>
#include <vector>
#include "pieceofsky.h"
#include "rand_engine.h"
#include "utilities.h"


class Star : public Piece_Of_Sky {
private:
    bool shining;
    int brightness;
    int y, x;
    static const std::vector<char> charmap;
    void toggle_shine();
    Rand_Engine* random;

public:
    Star(Rand_Engine*, int y, int x);
    void shine();
};

#endif /* STARS_INCLUDE_GUARD */
