#include "stars.h"


const std::vector<char> Star::charmap({'.', '+', '*', 'x', 'X', '#'});

Star::Star(Rand_Engine* random, int y, int x) 
: random(random), y(y), x(x) {
    toggle_shine();
}

void Star::toggle_shine() {
    if(random->dice(100) < 5){
        shining ^= 1;
    }
}

void Star::shine() {
    toggle_shine();
    if(shining){
        int dice = random->dice(charmap.size());
        char c = charmap.at(dice);
        mvprintw(y, x, "%c", c);
    } else {
        mvprintw(y, x, " ");
    }
}