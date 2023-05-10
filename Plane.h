#include <iostream>
#include <time.h>
#ifndef Plane_h
#define Plane_h

using namespace std;
template <class T>
T generateRandomNumber(int i, int j)
{
    return rand() % (j - i) + i;
}
class Plane {
private:
    int arrivalTime;
    int landingTime;
    bool v_landed;
    int waittime;
    static int created;
    static int baseTime;


public:
    bool operator>(const Plane& other) const {
        return this->arrivalTime > other.arrivalTime;
    }
    Plane();
    int getArrivalTime();
    int getLandingTime();
    void setLandingTime(int t) { landingTime = t; }
    void setArrivalTime();
    void setlanded();
    bool landed();
    void ArrivalTimeAdded();
   

   

};

#endif