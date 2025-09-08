#include <iostream>
#include <stack>

using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;
};

void depthFirstSearchIterative(Node *root)
{
    if (root == nullptr)
    {
        return;
    }

    stack<Node *> s;
    s.push(root);

    while (!s.empty())
    {
        Node *currentNode = s.top();
        s.pop();
        // preorder (root->left->right)
        cout << currentNode->data << " ";

        if (currentNode->right != nullptr)
        {
            s.push(currentNode->right);
        }
        if (currentNode->left != nullptr)
        {
            s.push(currentNode->left);
        }
    }
}

int main()
{

    Node *root = new Node{1};
    root->left = new Node{2};
    root->right = new Node{3};
    root->left->left = new Node{4};
    root->left->right = new Node{5};

    depthFirstSearchIterative(root);
    cout << endl;

    return 0;
}
