#include "Plane.h"

int Plane::created = 0;
int Plane::baseTime = 0;

Plane::Plane() {
    if (created == 0) {
        setArrivalTime();
    }
    else {
        ArrivalTimeAdded();
    }
    v_landed = false;
    landingTime = -1;
    created++;
}

void Plane::PrintArrivalTime() {
    cout << "The arrival time of the plane is ";
    if (arrivalTime / 60 < 10) {
        cout << "0";
    }
    cout << arrivalTime / 60 << ":";
    if (arrivalTime % 60 < 10) {
        cout << "0";
    }
    cout << arrivalTime % 60 << endl;
    
}

void Plane::setlanded(bool x)
{
    v_landed = x;
}

int Plane::getArrivalTime2()
{
    return arrivalTime2;
}

int Plane::getArrivalTime() {
    return arrivalTime;
}

int Plane::getLandingTime() {
    return landingTime;
}

void Plane::setArrivalTime() {
    int x, y;
    x = rand() % (24 - 0) + 0;
    y = rand() % (60 - 0) + 0;
    arrivalTime = x * 60 + y;
    arrivalTime2 = arrivalTime;
    
    baseTime = arrivalTime;
}

void Plane::ArrivalTimeAdded() {
    int x, y;
    x = rand() % (6 - 0) + 0;
    y = rand() % (60 - 0) + 0;
    int total = x * 60 + y+baseTime;
    arrivalTime2 = total;
    if (total > 1440) {
        total = total - 1440;
    }
    arrivalTime = total;
}

int Plane::getBaseTime()
{
    return baseTime;
}

int Plane::getWaitTime()
{
    return waittime;
}

int Plane::getServiceTime()
{
    return servicetime;
}



void Plane::setWaitTime()
{
    waittime = rand() % (30 - 5) + 5;

}

void Plane::setServiceTime()
{
   servicetime = rand() % (30 - 10) + 10;
}

void Plane::setLandingTime(int x)
{
    landingTime = x;
}

bool Plane::landed()
{
    return v_landed;
}