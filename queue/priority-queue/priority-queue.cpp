#include <iostream>
using namespace std;

class Node
{

public:
    int data;
    int priority;
    Node *next;

    Node(int d, int p) : data(d), priority(p), next(nullptr)
    {
    }
};
class PriorityQueue
{
    Node *head;

public:
    PriorityQueue() : head(nullptr)
    {
    }
    void enQueue(int d, int p)
    {
        Node *newNode = new Node(d, p);
        if (head == nullptr || head->priority > p)
        {
            newNode->next = head;
            head = newNode;
        }
        else
        {
            Node *temp = head;
            while (temp->next != nullptr && temp->next->priority <= p)
            {
                temp = temp->next;
            }
            newNode->next = temp->next;
            temp->next = newNode;
        }
    }
    void deQueue()
    {
        if (head == nullptr)
        {
            cout << "Queue is empty" << endl;
            return;
        }
        Node *temp = head;
        cout << temp->data << " dequeued" << endl;
        head = head->next;
        delete temp;
    }
    void display()
    {
        if (head == nullptr)
        {
            cout << "Queue is empty" << endl;
            return;
        }
        Node *temp = head;
        while (temp != nullptr)
        {
            std::cout << temp->data << "(" << temp->priority << ") ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main()
{

    PriorityQueue pq;
    pq.enQueue(1, 2);
    pq.enQueue(2, 2);
    pq.enQueue(3, 1);
    pq.enQueue(4, 2);

    pq.display();
    pq.deQueue();

    pq.display();
    return 0;
}