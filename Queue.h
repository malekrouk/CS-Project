#include <iostream>
using namespace std;

template <class T>
struct Node
{
	T value;
	Node<T>* back;
	Node<T>* next;

};

template <class T>
class Queue
{

private:
	Node<T>* first, * last; int counter;

public:
	Queue(); //default constructor
	void insertRear(T n); //insert node at the end of the queue
	void insertFront(T n); //insert node at the front
	void insertAfter(T, Node<T>*); //insert node after a specific node
	void removeRear(); //remove node from the end of the queue
	void removeFront(); //remove node from the front of the queue
	bool isEmpty(); //checks if queue is empty
	T viewFront(); //returns and outputs the value at the front of the queue
	T viewRear();//returns and outputs the value at the end of the queue
	int length(); //returns and outputs the length of the queue
	void print(); //print all the nodes in the queue
	~Queue(); //destructor



};

