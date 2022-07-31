#pragma once

#include <vector>
#include "pieceofsky.h"
#include "rand_engine.h"


class Star : public Piece_Of_Sky{
private:
    bool shining;
    int index;
    static const std::vector<char> charmap;
    void toggle_shine();
    Rand_Engine* random;

public:
    Star(Rand_Engine*);
    char get_char();
};

class Black : public Piece_Of_Sky {
public:
    char get_char();
};