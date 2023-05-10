#include "Plane.h"
#include "Airport.h"

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

int Plane::getArrivalTime() {
    cout << "The arrival time of the plane is ";
    if (arrivalTime / 60 < 10) {
        cout << "0";
    }
    cout << arrivalTime / 60 << ":";
    if (arrivalTime % 60 < 10) {
        cout << "0";
    }
    cout << arrivalTime % 60 << endl;
    return arrivalTime;
}

int Plane::getLandingTime() {
    return landingTime;
}

void Plane::setArrivalTime() {
    int x, y;
    x = generateRandomNumber<int>(1, 24);
    y = generateRandomNumber<int>(0, 60);
    arrivalTime = x * 60 + y;
    baseTime = arrivalTime;
}

void Plane::ArrivalTimeAdded() {
    int x, y;
    x = generateRandomNumber<int>(1, 6);
    y = generateRandomNumber<int>(0, 60);
    int newTime = baseTime + x * 60 + y;
    arrivalTime = newTime;
}
