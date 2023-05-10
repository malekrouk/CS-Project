#include <iostream>
#include "Plane.h"
#include "Queue.h"

using namespace std;


int main() {
	srand(time(NULL));
    Queue<int> q;
    int x=7, z=9, y=3, v=1;
    q.insertRear(v);
    q.insertRear(y);
    q.insertRear(x);
    q.insertRear(z);
    q.sort(); // sort the queue
    q.print();
	return 0;

}