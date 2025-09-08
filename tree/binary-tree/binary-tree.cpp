#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;
    Node(int data) : data(data), left(nullptr), right(nullptr)
    {
    }
};

class BinaryTree
{
private:
    Node *root;
    Node *insertRecursive(Node *node, int data)
    {
        if (node == nullptr)
        {
            return new Node(data);
        }
        if (data < node->data)
        {
            node->left = insertRecursive(node->left, data);
        }
        else
        {
            node->right = insertRecursive(node->right, data);
        }
        return node;
    }
    void inorderTraversal(Node *root)
    {
        if (root == nullptr)
        {
            return;
        }
        inorderTraversal(root->left);
        cout << root->data << " ";
        inorderTraversal(root->right);
    }

public:
    BinaryTree() : root(nullptr)
    {
    }
    void insertBinaryTree(int data)
    {
        root = insertRecursive(root, data);
    }
    void display(){
        inorderTraversal(root);
    }
};

int main()
{
    BinaryTree bt;
    bt.insertBinaryTree(7);
    bt.insertBinaryTree(1);
    bt.insertBinaryTree(5);
    bt.insertBinaryTree(12);
    bt.insertBinaryTree(2);
    bt.insertBinaryTree(1);
 
    bt.display();
    return 0;
}