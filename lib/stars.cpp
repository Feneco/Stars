#include "stars.h"


const std::vector<char> Star::charmap({'.', '+', '*', 'x', 'X', '#', '@'});

Star::Star(Rand_Engine* random, int y, int x) 
: random(random), y(y), x(x) {
    toggle_shine();
    brightness = 0;
}

void Star::toggle_shine() {
    if(random->dice(100) < 5){
        shining ^= 1;
    }
}

void Star::shine() {
    toggle_shine();
    if(shining) {
        int dice = random->dice(5);
        brightness += (dice - 2);
        brightness = clamp(brightness, 0, charmap.size()-1);
        char c = charmap.at(brightness);
        mvprintw(y, x, "%c", c);
    } else {
        mvprintw(y, x, ".");
    }
}