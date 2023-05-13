#include <iostream>
#include "Plane.h"
using namespace std;
#ifndef Queue_h
#define Queue_h 

template <class T>
struct Node
{
    Plane value;
    
    Node<T>* back;
    Node<T>* next;
};

template <class T>
class Queue
{
private:
    Node<T>* first;
    Node<T>* last;
    int counter;
    int index = 0;

public:
    Queue()
    {
        first = NULL;
        last = NULL;
        counter = 0;
    }
    bool isEmpty()
    {
        if (first == NULL)
            return true;
        return false;
    }
    void insertRear(T n)
    {
        if (first == NULL)
        {
            first = new Node<T>;
            first->value = n;
            first->back = NULL;
            first->next = NULL;
            last = first;
        }
        else
        {
            Node<T>* temp = new Node<T>;
            temp->value = n;
            temp->back = last;
            temp->next = NULL;
            last->next = temp;
            last = temp;
        }
        counter++;
    }
    void insertFront(T n)
    {
        if (isEmpty())
        {
            first = new Node<T>;
            first->value = n;
            first->next = NULL;
            first->back = NULL;
            last = first;
        }
        else
        {
            Node<T>* temp = new Node<T>;
            temp->value = n;
            temp->next = first;
            temp->back = NULL;
            first->back = temp;
            first = temp;
        }
        counter++;
    }
    void insertAfter(T v, Node<T>* curr)
    {
        Node<T>* temp = new Node<T>;
        temp->value = v;
        temp->back = curr;
        temp->next = curr->next;
        curr->next = temp;
        if (temp->next != NULL)
            temp->next->back = temp;
        counter++;
    }
    void removeRear()
    {
        if (last == NULL) // Queue is empty
        {
            cout << "List is empty." << endl;
            return;
        }

        if (last == first) // Only one node in list
        {
            delete last;
            last = NULL;
            first = NULL;
            counter--;
            return;
        }

        Node<T>* temp = last->back; // Second to last node
        delete last;
        temp->next = NULL;
        last = temp;
        counter--;
    }

    void removeFront()
    {
        if (last == NULL) // Queue is empty
        {
            cout << "List is empty." << endl;
            return;
        }

        if (last == first) // Only one node in list
        {
            delete first;
            last = NULL;
            first = NULL;
            counter--;
            return;
        }

        Node<T>* temp = first->next; // Second node
        delete first;
        temp->back = NULL;
        first = temp;
        counter--;
    }
    T viewFront()
    {
        if (isEmpty())
        {
            cout << "Queue is Empty" << endl;
            return T();
        }
        return first->value;
    }
    T viewRear()
    {
        if (isEmpty())
        {
            cout << "Queue is Empty" << endl;
            return T();
        }
        return last->value;
    }
    int length()
    {
        cout << "Length of the Queue is: " << counter << endl;
        return counter;
    }
    void print()
    {
        if (isEmpty())
        {
            cout << "Queue is Empty" << endl;
            return;
        }

        Node<T>* temp;
        temp = first;
        cout << "THE QUEUE IS AS FOLLOWS:" << endl;
        while (temp != NULL)
        {
            temp->value.PrintArrivalTime();
            temp = temp->next;
        }
    }

    bool isFull(int t)
    {
        if (counter == t)
            return true;
        return false;
    }

    void sort()
    {
        quickSort(first, last);
    }

    Node<T>* partition(Node<T>* low, Node<T>* high)
    {
        int pivot;
        pivot = high->value.getArrivalTime2();
        Node<T>* i = low->back;

        for (Node<T>* j = low; j != high; j = j->next)
        {
            if (j->value.getArrivalTime2() <= pivot)
            {
                i = (i == NULL) ? low : i->next;
                swap(i->value, j->value);
            }
        }

        i = (i == NULL) ? low : i->next;
        swap(i->value, high->value);
        return i;
    }

    void quickSort(Node<T>* low, Node<T>* high)
    {
        if (high != NULL && low != high && low != high->next)
        {
            Node<T>* p = partition(low, high);
            quickSort(low, p->back);
            quickSort(p->next, high);
        }
    }

    void dealWithClashes()
    {

        Node<T>* u = first;
       
        u = first;
        int bef = u->value.getArrivalTime2();
        if (u)
            u = u->next;
        while (u) {
            if (u->value.getArrivalTime2() - bef <= 10) u->value.setArrivalTime2(bef + 11);
            bef = u->value.getArrivalTime2();
            u = u->next;
        }
        Node<T>* temp;
        temp = first;
        cout << "THE QUEUE IS AS FOLLOWS:" << endl;
        while (temp != NULL)
        {
            if (temp->value.getArrivalTime2() > 1440)
            {
                temp->value.setArrivetime(temp->value.getArrivalTime2() - 1440);
            }
            temp = temp->next;
        }
        

       
    }





     
    ~Queue() {} //destructor
};

#endif