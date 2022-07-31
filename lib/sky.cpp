#include "sky.h"


Sky::Sky(Rand_Engine* random, int height, int width) : random(random), height(height), width(width) {
    for(int i=0; i<(height*width); i++) {
        int r = (random->get() % 5000);
        if( r < 50) {
            pieces.push_back(new Star(random)); 
        } else { 
            pieces.push_back(new Black());
        }
    }
}

void Sky::tick(){
    for(int y = 0; y<height; y++) {
        for(int x = 0; x<width; x++) {
            char c = pieces.at(y * height + x)->get_char();
            mvprintw(y, x, "%c", c);
        }
    }
}