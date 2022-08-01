#include "rand_engine.h"


Rand_Engine::Rand_Engine(){
    unsigned seed1 = std::chrono::system_clock::now().time_since_epoch().count();
    mt = new std::mt19937(seed1);
}

Rand_Engine::~Rand_Engine(){
    delete mt;
}

int Rand_Engine::dice(int faces){
    return abs(mt->operator()()) % faces ;
}