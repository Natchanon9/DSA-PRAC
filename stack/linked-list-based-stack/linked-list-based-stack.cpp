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

class Stack
{
private:
    Node *top;

public:
    Stack()
    {
        this->top = nullptr;
    }
    void push(int data)
    {
        Node *newNode = new Node(data);
        newNode->data = data;
        //Lastest node link -> top addr(before newNode)
        newNode->next = top;
        top = newNode;
        cout << data << " Pushed into stack\n";
    }
    int pop()
    {
        if (top == nullptr)
        {
            cout << "Stack Underflow" << std::endl;
            return 0;
        }
        Node *temp = top;
        int poppedVal = temp->data;
        top = top->next;
        delete temp;
        return poppedVal;
    }
    int peek()
    {
        if (!isEmpty())
        {
            return top->data;
        }
        else
        {
            cout << "Stack is empty" << std::endl;
            return -1;
        }
    }
    bool isEmpty() { return top == nullptr; }
};
int main()
{

    Stack s;
    s.push(10);
    s.push(20);
    cout << "Top element is " << s.peek() << std::endl;
    cout << "Popped from stack: " << s.pop() << std::endl;
    return 0;
}