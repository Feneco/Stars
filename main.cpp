#include <ncurses.h>
#include <thread>
#include "lib/sky.h"
#include "lib/rand_engine.h"

void loop(Sky& sky, bool& proceed){
    while(proceed) {
        sky.tick();
        napms(1000/13);
        refresh();
    }
}


int main(int, char**) {

    WINDOW* iscr = initscr();
    if(iscr==nullptr) {
        return 1;
    }
    noecho();
    cbreak();
    raw();
    curs_set(0);
    int height, width;
    getmaxyx(stdscr, height, width);

    Rand_Engine* random = new Rand_Engine();
    Sky sky(random, height, width);

    bool proceed = true;
    std::thread main_loop(loop, std::ref(sky), std::ref(proceed));
    timeout(-1);
    char ch;
    while(1){
        ch = getch();
        if(ch=='q') break;
    }
    proceed = false;
    main_loop.join();

    echo();
    nocbreak();
    noraw();
    curs_set(1);
    endwin();
    return 0;
}
