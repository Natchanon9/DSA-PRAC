#include <iostream>
using namespace std;
#define MAX_SIZE 100

class Stack
{
private:
    int top;
    int arr[MAX_SIZE];

public:
    Stack()
    {
        top = -1;
    };

    void push(int x)
    {
        if (top >= (MAX_SIZE - 1))
        {
            cout << "Stack overflow" << endl;
        }
        else
        {
            arr[++top] = x;
            cout << x << " pushed into stack\n";
        }
    }
    int pop()
    {
        if (top < 0)
        {
            cout << "Stack underflow" << endl;
            return 0;
        }
        else
        {
            int x = arr[top--];
            return x;
        }
    }
    int peek()
    {
        if (top < 0)
        {
            cout << "Stack is empty" << endl;
            return 0;
        }
        else
        {
            int x = arr[top];
            return x;
        }
    }
    bool isEmpty()
    {
        return (top < 0);
    }
};

int main()
{
    Stack s;
    s.push(1);
    s.push(2);
    s.push(3);

    cout << "Top element is: " << s.peek() << endl;
    cout << "Popped from stack: " << s.pop() << endl;
    cout << "Is empty: " << s.isEmpty() << endl;
    return 0;
}