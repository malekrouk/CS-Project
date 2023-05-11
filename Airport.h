#include <iostream>
#include "Plane.h"
#include "Queue.h"
using namespace std;
#ifndef Airport_h
#define Airport_h
class Airport {
private:
    Queue<Plane> AirQueue;
    Queue<Plane> LandingQueue;
    int numPlanesLanded =0;
    static int totalWaitTime;
    float interArrivalTime;
    int AirQueueLimit = rand() % (30 - 10) + 10;
    int LandingQueueLimit = 1;
    int time;




public:
    Airport();
    void printLog();
    float averageWait();
    void exitAirQueue();
    void exitLandingQueue();
    void service();
    int getAirQueueLimit();
    void PopulateAirQueue();
    Queue<Plane> getAirQueue();
    void clock();
};
#endif
