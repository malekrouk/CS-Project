#include <iostream>
#include "Plane.h"
#include "Queue.h"
using namespace std;

class Airport {
private:
    Queue<Plane> landingQueue;
    bool runwayFree;
    int totalTime;
    int numPlanesLanded;
    int totalWaitTime;
    int Tmax;
    int Tlanding;
    float deltaT;

public:
    Airport(int maxTime, int landingTime, float interArrivalTime);
    void printLog(int time, int numArrivals, int numWaiting);
    float averageWait(int waitTotal, int jobcount);
    void exitLine(int t, int& waitTotal, int& jobcount);
    void service(int t, int Tr, int& waitTotal, int& jobcount);
    void arrival(int t);
};