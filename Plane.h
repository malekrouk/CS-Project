#include <iostream>
#include <time.h>
#ifndef Plane_h
#define Plane_h

using namespace std;

class Plane {
private:
    int arrivalTime;
    int landingTime;
    bool v_landed;
    int waittime;
    int servicetime;
    static int created;
    static int baseTime;
    int arrivalTime2;


public:
    bool operator>(const Plane& other) const {
        return this->arrivalTime > other.arrivalTime;
    }
    Plane();



    void PrintArrivalTime();
    int getArrivalTime();
    int getArrivalTime2();
    int getLandingTime();
    void setLandingTime(int t);
    void setArrivalTime();
    void setArrivalTime(int i);
    void setlanded(bool);
    bool landed();
    void ArrivalTimeAdded();
    int getBaseTime();
    int getWaitTime();
    int getServiceTime();
    
    void setArrivalTime2(int x);
    void setArrivetime(int y);



};

#endif