#include <iostream>
using namespace std;

#define SIZE 5

class Queue
{
    int items[SIZE], front, rear;

public:
    Queue() : front(-1), rear(-1)
    {
    }
    bool isFull()
    {
        return rear == SIZE - 1;
    }
    bool isEmpty()
    {
        return front == -1;
    }
    void enQueue(int data)
    {
        if (isFull())
        {
            cout << "Queue is full" << endl;
        }
        else
        {
            if (front == -1)
            {
                front = 0;
            }
            items[++rear] = data;
            cout << data << " inserted" << endl;
        }
    }
    int deQueue()
    {
        if (isEmpty())
        {
            cout << "Queue is empty" << endl;
            return -1;
        }
        else
        {
            int element = items[front];
            if (front >= rear)
            {
                front = -1;
                rear = -1;
            }
            else
            {
                front = front + 1;
            }

            cout << element << " dequeued" << endl;
            return element;
        }
    }
    void display()
    {
        if (isEmpty())
        {
            cout << "Queue is empty" << endl;
        }
        else
        {
            for (int i = front; i <= rear; i++)
            {
                cout << items[i] << endl;
            }
            cout << endl;
        }
    }
};

int main()
{
    Queue q;
    q.enQueue(1);
    q.enQueue(2);
    q.enQueue(3);
    q.enQueue(4);
    q.enQueue(5);
    q.enQueue(6);

    q.display();
    q.deQueue();
    q.deQueue();
    q.deQueue();
    q.display();
    return 0;
}