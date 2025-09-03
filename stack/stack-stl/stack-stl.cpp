#include <iostream>
#include <stack>
using namespace std;

int main()
{
    stack<int> myStack;
    myStack.push(1);
    myStack.push(2);
    myStack.push(3);
    cout << "The top element is: " << myStack.top() << endl;
    myStack.pop();
    cout << "After popping, the top element is: " << myStack.top() << endl;

    if (!myStack.empty())
    {
        cout << "The stack is not empty" << endl;
    }

    cout << "The stack size is:" << myStack.size() << endl;

    return 0;
}