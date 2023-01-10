#include<bits/stdc++.h>
using namespace std;

// Tree Node
struct Node
{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int x)
    {
        data = x;
        left = NULL;
        right = NULL;
    }
};

void mirror(Node* node) 
{
    if(node == NULL) return;
    mirror(node->left);
    mirror(node->right);
    swap(node->left, node->right);
}

void inorder(Node* node)
{
    if(node == NULL) return;
    inorder(node->left);
    cout << node->data << " ";
    inorder(node->right);
}

int main()
{
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    inorder(root);
    cout << endl;
    mirror(root);
    inorder(root);
    cout << endl;
    return 0;
}

