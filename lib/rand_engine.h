#ifndef RAND_ENGINE_INCLUDE_GUARD
#define RAND_ENGINE_INCLUDE_GUARD

#include <chrono>
#include <random>

class Rand_Engine{
private:
    std::mt19937* mt;
    
public:
    Rand_Engine();
    ~Rand_Engine();
    int dice(int faces);

};

#endif /* RAND_ENGINE_INCLUDE_GUARD */
