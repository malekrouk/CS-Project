#include <iostream>
#include "Plane.h"
#include "Queue.h"
using namespace std;
#ifndef Airport_h
#define Airport_h
class Airport {
public:
    Queue<Plane> AirQueue;
    int numPlanesLanded =0;
     int totalWaitTime =0;
    int AirQueueLimit = rand() % (15 - 10) + 10;
     int time=0;
     int basetime=0;




public:
    Airport();
    float averageWait();
    void service();
    int getAirQueueLimit();
    void PopulateAirQueue();
    Queue<Plane> getAirQueue();
    void clock();
    void runsim();
};
#endif
