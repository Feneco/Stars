#ifndef RAND_ENGINE_INCLUDE_GUARD
#define RAND_ENGINE_INCLUDE_GUARD

#include <chrono>
#include <random>

class Rand_Engine{
private:
    std::mt19937* mt;
public:
    Rand_Engine(){
        unsigned seed1 = std::chrono::system_clock::now().time_since_epoch().count();
        mt = new std::mt19937(seed1);
    }
    ~Rand_Engine(){
        delete mt;
    }
    int dice(int faces){
        return abs(mt->operator()()) % faces ;
    }
};

#endif /* RAND_ENGINE_INCLUDE_GUARD */
