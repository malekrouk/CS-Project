#include "Airport.h"



Airport::Airport()
{}




void Airport::service()
{
    int w;
    while (time < basetime + 360 && !AirQueue.isEmpty())
    {
        
            if (time == AirQueue.viewFront().getArrivalTime2())
            {
                cout << "Plane #" << numPlanesLanded + 1 << " Landed at -> ";
                if (AirQueue.viewFront().getArrivalTime() / 60 < 10)
                    cout << "0"; 
                cout<< AirQueue.viewFront().getArrivalTime() / 60 <<":";
                if (AirQueue.viewFront().getArrivalTime() % 60 < 10)
                    cout << "0"; 
                cout<< AirQueue.viewFront().getArrivalTime() % 60 << endl;
                w = AirQueue.viewFront().getWaitTime();
                numPlanesLanded++;
               do
                   time++;
               while (time != AirQueue.viewFront().getArrivalTime2() + w);
                   cout << "Plane #" << numPlanesLanded << " Service Started at: -> ";
                       if ((AirQueue.viewFront().getArrivalTime() +w) / 60 < 10)
                           cout << "0";
                   cout << (AirQueue.viewFront().getArrivalTime() +w )/ 60 << ":";
                   if ((AirQueue.viewFront().getArrivalTime() +w) % 60 < 10)
                       cout << "0";
                   cout << (AirQueue.viewFront().getArrivalTime() + w) % 60;
               cout << "     Wait Time = " << w << endl;
               totalWaitTime += w;
               AirQueue.removeFront();
            }
        

            time++;
            
    }

    }





float Airport::averageWait()
{
	if (numPlanesLanded == 0)
		return 0;
	return float(totalWaitTime) / float(numPlanesLanded);
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
    
        time++;
    }
    


void Airport::runsim()
{
    PopulateAirQueue();


    service();
    cout << "Average wait Time is " << averageWait() << endl;

    }
    
        
    



        


