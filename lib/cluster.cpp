#include "cluster.h"

const std::vector<char> Cluster::charmap({' ', ' ', '.', '+', '*', 'x', 'X', '#'});
const float Cluster::gamma = 1.0;

float Cluster::gaussianKernel(int y, int x) {
    float b = -(pow(x, 2) + pow(y, 2))/(2 * pow(gamma, 2));
    return exp(b);
}

int Cluster::clamp(int x, int min, int max){
    if(x < min) return min;
    if(x > max) return max;
    return x;
}

Cluster::Cluster(Rand_Engine* r, int y, int x)
: random(r), y(y), x(x) {
    radius = random->dice(3);
    if(radius == 0) {
        radius = 1;
    }

    for(int x=-radius; x<=radius; x++) {
        for(int y=-radius; y<=radius; y++) {
            int sp = random->dice(charmap.size());
            star_power.push_back(sp * gaussianKernel(x, y));
        }
    }
}

void Cluster::shine(){
    for(int x=-radius; x<=radius; x++) {
        for(int y=-radius; y<=radius; y++) {
            int total_radius = 2*radius+1;
            int newx = x + radius;
            int newy = y + radius;
            int coordinates = newy * total_radius + newx;

            int dice = random->dice(3);
            int power = dice + star_power.at(coordinates) * gaussianKernel(y, x);

            char c = charmap.at(clamp(power, 0, charmap.size()-1));
            mvprintw(y+this->y, x+this->x, "%c", c);
        }
    }
}
