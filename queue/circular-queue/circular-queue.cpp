#include <iostream>
using namespace std;
#define SIZE 5

class CircularQueue
{
    int items[SIZE], front, rear;

public:
    CircularQueue() : front(-1), rear(-1)
    {
    }
    bool isFull()
    {
        return (rear + 1) % SIZE == front;
    }
    bool isEmpty()
    {
        return front == -1;
    }
    void enQueue(int data)
    {
        if (isFull())
        {
            cout << "Queue is full" << std::endl;
        }
        else
        {
            if (front == -1)
                front = 0;
            rear = (rear + 1) % SIZE;
            items[rear] = data;
            cout << data << " inserted into queue" << std::endl;
        }
    }

    void deQueue()
    {
        if (isEmpty())
        {
            cout << "Queue is empty" << endl;
        }
        else
        {
            cout << items[front] << "removed from q" << endl;
            if (front == rear)
            {
                front = -1;
                rear = -1;
            }
            else
            {
                front = (front + 1) % SIZE;
            }
        }
    }
    void display()
    {
        if (isEmpty())
        {
            cout << "Queue is empty" << std::endl;
            return;
        }
        cout << "Queue elements are: ";
        if (rear >= front)
        {
            for (int i = front; i <= rear; i++)
                cout << items[i] << " ";
        }
        else
        {
            for (int i = front; i < SIZE; i++)
                cout << items[i] << " ";
            for (int i = 0; i <= rear; i++)
                cout << items[i] << " ";
        }
        cout << endl;
    }
};

int main()
{
    CircularQueue cq;
    cq.enQueue(1);
    cq.enQueue(2);
    cq.enQueue(3);
    cq.enQueue(4);
    cq.deQueue();
    cq.enQueue(5);
    cq.enQueue(6);
    cq.enQueue(7);
    cq.display();
    cq.deQueue();
    cq.deQueue();
    cq.display();
    return 0;
}