#include "sky.h"


Sky::Sky(Rand_Engine* random, int height, int width) 
: random(random), height(height), width(width) {
    for(int j = 0; j<height; j++) {
        for(int i = 0; i<width; i++) {
            if((random->dice(1000)) <= 50) {
                stars.push_back(new Star(random, j, i));
            } else if((random->dice(1000)) <= 3){
                stars.push_back(new Cluster(random, j, i));
            }
        }
    }
}

void Sky::tick() {
    for(Piece_Of_Sky* c : stars) {
        c->shine();
    }
}