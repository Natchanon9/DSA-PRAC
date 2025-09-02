#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node(int data)
    {
        this->data = data;
        this->next = nullptr;
    }
};

void printList(Node *node)
{
    Node *temp = node;

    cout << "singly circular linked list" << " " << endl;
    do
    {
        cout << node->data << " ";
        node = node->next;
    } while (node != temp);
};
int main()
{
    Node *head = new Node(1);
    Node *second = new Node(2);
    Node *third = new Node(3);
    Node *tail = new Node(5);

    head->next = second;
    second->next = third;
    third->next = tail;
    tail->next = head;

    printList(head);
    return 0;
}