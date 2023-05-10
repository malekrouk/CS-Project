//#include "Queue.h"
//
//template <class T>
//Queue<T>::Queue()
//{
//	first = NULL;
//	last = NULL;
//	counter = 0;
//}
//
//template <class T>
//void Queue<T>::insertRear(T n)
//{
//	if (first == NULL)
//	{
//		first = new Node<T>;
//		first->value = n;
//		first->back = NULL;
//		first->next = NULL;
//		last = first;
//	}
//	else
//	{
//		Node<T>* temp = new Node<T>;
//		temp->value = n;
//		temp->back = last;
//		temp->next = NULL;
//		last->next = temp;
//		last = temp;
//	}
//	counter++;
//}
//
//template<class T>
//void Queue<T>::insertFront(T n)
//{
//	if (isEmpty())
//	{
//		first = new Node<T>;
//		first->value = n;
//		first->next = NULL;
//		first->back = NULL;
//		last = first;
//	}
//	else
//	{
//		Node<T>* temp = new Node<T>;
//		temp->value = n;
//		temp->next = first;
//		temp->back = NULL;
//		first->back = temp;
//		first = temp;
//	}
//	counter++;
//}
//
//template <class T>
//void Queue<T>::insertAfter(T v, Node<T>* curr)
//{
//	Node<T>* temp = new Node<T>;
//	temp->value = v;
//	temp->back = curr;
//	temp->next = curr->next;
//	curr->next = temp;
//	if (temp->next != NULL)
//		temp->next->back = temp;
//	counter++;
//}
//
//template <class T>
//void Queue<T>::removeRear()
//{
//	if (last == NULL) // Queue is empty
//	{
//		cout << "List is empty." << endl;
//		return;
//	}
//
//	if (last == first) // Only one node in list
//	{
//		delete last;
//		last = NULL;
//		first = NULL;
//		counter--;
//		return;
//	}
//
//	Node<T>* temp = last->back; // Second to last node
//	delete last;
//	temp->next = NULL;
//	last = temp;
//	counter--;
//}
//
//template <class T>
//void Queue<T>::removeFront()
//{
//	if (last == NULL) // Queue is empty
//	{
//		cout << "List is empty." << endl;
//		return;
//	}
//
//	if (last == first) // Only one node in list
//	{
//		delete first;
//		last = NULL;
//		first = NULL;
//		counter--;
//		return;
//	}
//
//	Node<T>* temp = first->next; // Second node
//	delete first;
//	temp->back = NULL;
//	first = temp;
//	counter--;
//}
//
//template<class T>
//bool Queue<T>::isEmpty()
//{
//	if (first == NULL)
//		return true;
//	return false;
//}
//
//template<class T>
//T Queue<T>::viewFront()
//{
//	if (isEmpty())
//	{
//		cout << "Queue is Empty" << endl;
//		return T();
//	}
//	cout << first->value << endl;
//	return first->value;
//}
//
//template<class T>
//T Queue<T>::viewRear()
//{
//	if (isEmpty())
//	{
//		cout << "Queue is Empty" << endl;
//		return T();
//	}
//	cout << last->value << endl;
//	return last->value;
//}
//
//template<class T>
//int Queue<T>::length()
//{
//	cout << "Length of the Queue is: " << counter << endl;
//	return counter;
//}
//
//template <class T>
//void Queue<T>::print()
//{
//	Node<T>* temp;
//	temp = first;
//	cout << "THE QUEUE IS AS FOLLOWS:" << endl;
//	while (temp != NULL)
//	{
//		cout << temp->value << endl;
//		temp = temp->next;
//	}
//}
//
//template<class T>
//bool Queue<T>::isFull(int t)
//{
//	if (counter == t)
//		return true;
//	return false;
//}
//
//template<class T>
//void Queue<T>::sort()
//{
//	Node<T>* current = last;
//	Node<T>* prev = nullptr;
//	Node<T>* temp = nullptr;
//	bool swapped = false;
//
//	if (isEmpty())
//		return;
//
//	do {
//		swapped = false;
//		current = last;
//		while (current->next != nullptr) {
//			if (current->value > current->next->value) {
//				temp = current->next;
//				current->next = current->next->next;
//				temp->next = current;
//
//				if (prev == nullptr) {
//					last = temp;
//				}
//				else {
//					prev->next = temp;
//				}
//				prev = temp;
//				swapped = true;
//			}
//			else {
//				prev = current;
//				current = current->next;
//			}
//		}
//	} while (swapped);
//}
//
//
//
