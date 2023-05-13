#include <iostream>
#include "Plane.h"
#include "Queue.h"
#include "Airport.h"
#include <string>

using namespace std;

#include <ctime>
#include <cstdlib>

void randomize_seed()
{
    unsigned int seed = static_cast<unsigned int>(std::time(nullptr));
    std::srand(seed);
}


int main()
{
    randomize_seed();
    
    Airport x;
    

    x.runsim();

    return 0;
}