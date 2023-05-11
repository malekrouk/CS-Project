#include "Airport.h"

int Airport::totalWaitTime = 0;

Airport::Airport()
{
	
	interArrivalTime = 6;
	Queue<Plane> planes;
	int QueueLimit = rand() % (30 - 10) + 10;

}

void Airport::exitAirQueue()
{
	while (!AirQueue.isFull(AirQueueLimit))
	{
		do
		{
			time++;

		} while (time != AirQueue.viewFront().getArrivalTime());
		LandingQueue.insertFront(AirQueue.viewFront());
		AirQueue.removeFront();
	}
}

void Airport::service()
{
	LandingQueue.viewFront().setServiceTime();
	 LandingQueue.viewFront().setWaitTime();
	 totalWaitTime+= LandingQueue.viewFront().getWaitTime();


}

void Airport::exitLandingQueue()
{
	if (time == LandingQueue.viewFront().getArrivalTime() + LandingQueue.viewFront().getServiceTime() + LandingQueue.viewFront().getWaitTime())
	{
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
}

Queue<Plane> Airport::getAirQueue()
{
	return AirQueue;
}

void Airport::clock() {
	 time = AirQueue.viewFront().getBaseTime();
	exitAirQueue();
	numPlanesLanded++;

	
}

void Airport::printLog()
{

}

