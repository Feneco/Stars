#include "sky.h"


Sky::Sky(Rand_Engine* random, int height, int width) 
: random(random), height(height), width(width) {
    for(int j = 0; j<height; j++) {
        for(int i = 0; i<width; i++) {
            if((random->get() % 100) <= 2) {
                stars.push_back(new Star(random, j, i));
            }
        }
    }
}

void Sky::tick() {
    for(Star* c : stars){
        c->shine();
    }
}