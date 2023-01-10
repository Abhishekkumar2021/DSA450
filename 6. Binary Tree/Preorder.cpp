#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node *left, *right;
    Node(int data){
        this->data = data;
        left = right = NULL;
    }
};


void preOrder(Node* root, vector<int> &ans){
    if(root == NULL)
        return;

    ans.push_back(root->data);
    preOrder(root->left, ans);
    preOrder(root->right, ans);
}

vector<int> preorder(Node* root){
    vector<int> ans;
    if(root==NULL) return ans;
    stack<Node*> s;
    s.push(root);
    while(!s.empty()){
        Node* temp = s.top();
        s.pop();
        ans.push_back(temp->data);
        if(temp->right) s.push(temp->right);
        if(temp->left) s.push(temp->left);
    }
    return ans;
}