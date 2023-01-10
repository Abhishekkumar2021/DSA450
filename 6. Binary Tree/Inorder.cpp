/*
Given the root of a binary tree, return the inorder traversal of its nodes' values.
*/

#include <bits/stdc++.h>
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

vector<int> inorderTraversal(Node* root) {
    vector<int> ans;
    if(root == NULL) return ans;
    stack<Node*> s;
    Node* curr = root;
    while(curr != NULL || !s.empty()){
        while(curr != NULL){
            s.push(curr);
            curr = curr->left;
        }
        curr = s.top();
        s.pop();
        ans.push_back(curr->data);
        curr = curr->right;
    } 
    return ans;
}