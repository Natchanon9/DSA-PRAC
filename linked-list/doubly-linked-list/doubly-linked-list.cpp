#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node *prev;
    Node(int data)
    {
        this->data = data;
        this->prev = nullptr;
        this->next = nullptr;
    }
};

void printList(Node *node)
{
    cout << "forward: " << endl;
    while (node != nullptr)
    {
        cout << node->data << " " << endl;
        node = node->next;
    }
};

void printReverseList(Node *node)
{
    cout << "reverse: " << endl;
    while (node != nullptr)
    {
        cout << node->data << " " << endl;
        node = node->prev;
    }
};
int main()
{
    
    Node *head = new Node(1);
    Node *second = new Node(2);
    Node *third = new Node(3);
    head->next = second;
    second->prev = head;
    second->next = third;
    third->prev = second;

    printList(head);
    printReverseList(third);
    return 0;
}