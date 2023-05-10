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
    Node<T>* first;
    Node<T>* last;
    int counter;

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
        cout << first->value << endl;
        return first->value;
    }    
    T viewRear()
    {
        if (isEmpty())
        {
            cout << "Queue is Empty" << endl;
            return T();
        }
        cout << last->value << endl;
        return last->value;
    }   
    int length()
    {
        cout << "Length of the Queue is: " << counter << endl;
        return counter;
    }   
    void print()
    {
        Node<T>* temp;
        temp = first;
        cout << "THE QUEUE IS AS FOLLOWS:" << endl;
        while (temp != NULL)
        {
            cout << temp->value << endl;
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

        Node<T>* partition(Node<T>*low, Node<T>*high)
        {
            T pivot = high->value;
            Node<T>* i = low->back;

            for (Node<T>* j = low; j != high; j = j->next)
            {
                if (j->value <= pivot)
                {
                    i = (i == NULL) ? low : i->next;
                    swap(i->value, j->value);
                }
            }

            i = (i == NULL) ? low : i->next;
            swap(i->value, high->value);
            return i;
        }

        void quickSort(Node<T>*low, Node<T>*high)
        {
            if (high != NULL && low != high && low != high->next)
            {
                Node<T>* p = partition(low, high);
                quickSort(low, p->back);
                quickSort(p->next, high);
            }
        }

     
    ~Queue() {} //destructor
};

