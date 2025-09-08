#include <iostream>
#include <queue>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;
};

void breadthFirstSearch(Node *root)
{
    if (root == nullptr)
    {
        return;
    }

    queue<Node *> q;

    q.push(root);

    while (!q.empty())
    {
        Node *currentNode = q.front();
        q.pop();

        cout << currentNode->data << " ";

        // Enqueue children (if they exist)
        if (currentNode->left != nullptr)
        {
            q.push(currentNode->left);
        }
        if (currentNode->right != nullptr)
        {
            q.push(currentNode->right);
        }
    }
}

int main()
{
    Node *root = new Node{8}; //layer 1
    root->left = new Node{1}; //layer 2
    root->right = new Node{3}; //layer 2
    root->left->left = new Node{4}; //layer 3
    root->left->right = new Node{5}; //layer 3
    breadthFirstSearch(root);
    cout << endl;
    return 0;
}