#include "cluster.h"

const std::vector<char> Cluster::charmap({' ', '.', '+', '*', 'x', 'X', '#', '@'});

float Cluster::gaussianKernel(int y, int x) {
    float b =  - (pow(x, 2) + pow(y, 2)) 
               / (2 * pow(gamma, 2));
    return exp(b);
}

int Cluster::convert_xy_to_i(int y, int x){
    int total_radius = 2*radius+1;
    int newx = x + radius;
    int newy = y + radius;
    int coordinates = newy * total_radius + newx;
    return coordinates;
}

Cluster::Cluster(Rand_Engine* r, int y, int x)
: random(r), y(y), x(x) {
    radius = random->dice(3);
    radius = clamp(radius, 1, 3);
    float gamma_values[] = {0.7, 1.2, 1.7};
    gamma = gamma_values[radius-1];

    for(int x=-radius; x<=radius; x++) {
        for(int y=-radius; y<=radius; y++) {
            star_power.push_back(gaussianKernel(y, x) * (charmap.size()-1));
        }
    }
}

void Cluster::shine(){
    for(int x=-radius; x<=radius; x++) {
        for(int y=-radius; y<=radius; y++) {
            int dice = random->dice(2);
            int power = dice + star_power.at(convert_xy_to_i(y, x));
            char c = charmap.at(clamp(power, 0, charmap.size()-1));
            mvprintw(y+this->y, x+this->x, "%c", c);
        }
    }
}
