#include "stars.h"


const std::vector<char> Star::charmap({'.', '+', '*', 'x', 'X', '#'});

Star::Star(Rand_Engine* random) :random(random) {
    toggle_shine();
    index = 0;
}

void Star::toggle_shine() {
    int toggle_shine = random->get();
    if(toggle_shine % 100 < 5){
        shining ^= 1;
    }
}

char Star::get_char() {
    toggle_shine();
    if (shining) {
        return charmap[random->get() % charmap.size()];
    } else {
        return ' ';
    }
}


char Black::get_char(){
    return ' ';
}