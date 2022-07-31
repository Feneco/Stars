#include "utilities.h"

int clamp(int x, int lo, int hi){
    if(x<lo) return lo;
    if(x>hi) return hi;
    return x;
}

int min(int a, int b){
    if(a<b) return a;
    return b;
}

int max(int a, int b){
    if(a>b) return a;
    return b;
}