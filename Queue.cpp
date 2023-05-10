#include "Queue.h"

template <class T>
Queue<T>::Queue()
{
	first = NULL;
	last = NULL;
	counter = 0;
}

template <class T>
void Queue<T>::insertRear(T n)
{
	if (first == NULL)
	{
		first = new Node;
		first->value = n;
		first->back = NULL;
		first->next = NULL;
		last = first;
	}
	else
	{
		Node* temp = new Node;
		temp->value = n;
		temp->back = last;
		last->next = temp;
		last = temp;


	}
	counter++;
}
template<class T>
void Queue<T>::insertFront(T n)
{
	if (isEmpty())
	{
		first->value = n;
		first->next = NULL;
		first->back = NULL;
		last = first;
	}
	else
	{
		Node temp = new Node;
		temp->next = first;
		first->back = temp;
		temp->back = NULL;
		first = temp;
	}
	counter++;
}

template <class T>
void Queue<T>::insertAfter(T v, Node<T>* curr)
{
	Node* temp = new Node;
	temp->value = v;
	temp->back = curr;
	temp->next = curr->next;
	curr->next = temp;
	if (temp->next != NULL)
		temp->next->back = temp;
	counter++;

}

template <class T>
void Queue<T>::removeRear()
{
	if (last == NULL) // Queue is empty
	{
		cout << "List is empty." << endl;
		return;
	}

	if (last == first) // Only one node in list
	{
		last = NULL;
		first = NULL;
		counter--;
		return;
	}

	Node* temp = last->back; // Second to last node
	temp->next = NULL;
	last = temp;
	counter--;
}

template <class T>
void Queue<T>::removeFront()
{
	if (last == NULL) // Queue is empty
	{
		cout << "List is empty." << endl;
		return;
	}

	if (last == first) // Only one node in list
	{
		last = NULL;
		first = NULL;
		counter--;
		return;
	}

	Node* temp = first->next; // Second node
	temp->back = NULL;
	first = temp;
	counter--;
}

template<class T>
bool Queue<T>::isEmpty()
{
	if (first == NULL)
		return true;
	return false;
}
template<class T>
T Queue<T>::viewFront()
{
	if (isEmpty())
	{
		cout << "Queue is Empty" << endl;
		return;
	}
	cout << first->value << endl;
	return first->value;
}
template<class T>
T Queue<T>::viewRear()
{
	if (isEmpty())
	{
		cout << "Queue is Empty" << endl;
		return;
	}
	cout << last->value << endl;
	return last->value;
}
template<class T>
int Queue<T>::length()
{
	cout << "Length of the Queue is: " << counter << endl;
	return counter;
}
template <class T>
void Queue<T>::print()
{
	Node* temp;
	temp = first;
	cout << "THE QUEUE IS AS FOLLOWS:" << endl;
	while (temp != NULL)
	{
		cout << temp->value << endl;
		temp = temp->next;
	}

}

template <class T>
Queue<T>::~Queue()
{
	delete first;
	delete last;
}
