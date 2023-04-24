#include <iostream>
using namespace std;

class Plane {
private:
    int arrivalTime;
    int landingTime;
    bool landed;

public:
    Plane() { arrivalTime =generateRandomNumber() ; }
    int getArrivalTime() { return arrivalTime; }
    int getLandingTime() { return landingTime; }
    void setLandingTime(int t) { landingTime = t; }
    float generateRandomNumber();
    bool landed();

};
