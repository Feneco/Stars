#include <ncurses.h>
#include "lib/sky.h"
#include "lib/rand_engine.h"

int main(int, char**) {

    WINDOW* iscr = initscr();
    if(iscr==nullptr) {
        return 1;
    }
    noecho();
    cbreak();
    int height, width;
    getmaxyx(stdscr, height, width);

    Rand_Engine* random = new Rand_Engine();
    Sky sky(random, height, width);

    while(1){
        sky.tick();
        napms(1000/13);
        refresh();
    }
    endwin();
}
