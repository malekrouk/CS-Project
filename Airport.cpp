#include "Airport.h"

int Airport::totalWaitTime = 0;
int Airport::time = 0;
int Airport::basetime = 0;

Airport::Airport()
{
	
	interArrivalTime = 6;
	Queue<Plane> planes;
	int QueueLimit = rand() % (30 - 10) + 10;

}

void Airport::exitAirQueue()
{
    
    
    if (!LandingQueue.isFull(LandingQueueLimit)) {
        LandingQueue.insertFront(AirQueue.viewFront());
        cout << "Plane # " << numPlanesLanded + 1 << " Landed at: ";
        AirQueue.viewFront().PrintArrivalTime();
        AirQueue.removeFront();


        numPlanesLanded++;
    }
}

void Airport::service()
{
    
    int wait = LandingQueue.viewFront().getWaitTime();
    int service = LandingQueue.viewFront().getServiceTime();
    
    cout << "Service #" << numPlanesLanded << " started at : ";
    if ((LandingQueue.viewFront().getArrivalTime() + wait) / 60 < 10) {
        cout << "0";
    }
    cout << (LandingQueue.viewFront().getArrivalTime() + wait) / 60 << ":";
    if ((LandingQueue.viewFront().getArrivalTime() + wait) % 60 < 10) {
        cout << "0";
    }
    cout << (LandingQueue.viewFront().getArrivalTime() + wait) % 60;
    
    cout << "   Wait Time = " << wait << endl;
    totalWaitTime += wait;
    

    if (time == LandingQueue.viewFront().getArrivalTime() + service + wait)
    {
        cout << "Service #" << numPlanesLanded + 1<< " Ended at : " << ( + wait + LandingQueue.viewFront().getArrivalTime()) / 60 << " : " << (service + wait + LandingQueue.viewFront().getArrivalTime()) % 60;
        cout << endl;
        LandingQueue.removeFront();

    }

}




float Airport::averageWait()
{
	if (numPlanesLanded == 0)
		return 0;
	return float(totalWaitTime / numPlanesLanded);
}



int Airport::getAirQueueLimit()
{
	return AirQueueLimit;
}

void Airport::PopulateAirQueue()
{
	Plane* planes = new Plane[AirQueueLimit];

	for (int i = 0; i < AirQueueLimit; i++)
	{
		AirQueue.insertRear(planes[i]);
	}
    AirQueue.sort();
    AirQueue.dealWithClashes();
    time = AirQueue.viewFront().getBaseTime();
    basetime = AirQueue.viewFront().getBaseTime();
    
}

Queue<Plane> Airport::getAirQueue()
{
	return AirQueue;
}

void Airport::clock() {
    if (time <= basetime + 360) {
        if (time == AirQueue.viewFront().getArrivalTime()) {
            
            exitAirQueue();
        }
        time++;
    }
    
}

void Airport::runsim()
{
    PopulateAirQueue();


    for (int i = basetime; i < basetime + 360; i++) {

        if (i == AirQueue.viewFront().getArrivalTime()) {
            clock();
            service();
        }
    }
    
        
    

    cout << "Average wait Time is " << averageWait() << endl;
}

        


