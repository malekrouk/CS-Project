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
    // Create a queue of planes
    Airport x;
    x.PopulateAirQueue();
    
    
    
    // Add planes to the queue

    
    x.getAirQueue().sort();
    // Sort the queue by arrival time
   

    // Print the sorted queue
    x.getAirQueue().print();

    return 0;
}
