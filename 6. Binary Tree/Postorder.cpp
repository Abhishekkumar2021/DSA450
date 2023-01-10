#include<bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *left, *right;
    Node(int data) {
        this->data = data;
        left = right = NULL;
    }
};

void postorder(Node *root, vector<int> & ans) {
    if (root == NULL) return;
    postorder(root->left, ans);
    postorder(root->right, ans);
    ans.push_back(root->data);
}

vector<int> postOrder(Node* root) {
    vector<int> ans;
    if (root == NULL) return ans;
    // post order traversal using 2 stacks
    stack<Node*> s1, s2;
    s1.push(root);
    while (!s1.empty()) {
        Node* temp = s1.top();
        s1.pop();
        s2.push(temp);
        if (temp->left) s1.push(temp->left);
        if (temp->right) s1.push(temp->right);
    }
    while (!s2.empty()) {
        ans.push_back(s2.top()->data);
        s2.pop();
    }
}

