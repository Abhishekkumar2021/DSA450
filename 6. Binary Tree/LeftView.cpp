/*
Given a Binary Tree, print Left view of it. Left view of a Binary Tree is set of nodes visible when tree is visited from Left side. The task is to complete the function leftView(), which accepts root of the tree as argument.

Left view of following tree is 1 2 4 8.

          1
       /     \
     2        3
   /     \    /    \
  4     5   6    7
   \
     8   

Example 1:

Input:
   1
 /  \
3    2
Output: 1 3

Example 2:

Input:

Output: 10 20 40
Your Task:
You just have to complete the function leftView() that returns an array containing the nodes that are in the left view. The newline is automatically appended by the driver code.
Expected Time Complexity: O(N).
Expected Auxiliary Space: O(N).

Constraints:
0 <= Number of nodes <= 100
1 <= Data of a node <= 1000
*/

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


vector<int> leftView(Node *root){
    vector<int> ans;
    if(root == NULL) return ans;
    queue<Node*> q;
    q.push(root);
    while(!q.empty()){
        int n = q.size();
        for(int i=0; i<n; i++){
            Node* temp = q.front();
            q.pop();
            if(i==0) ans.push_back(temp->data);
            if(temp->left) q.push(temp->left);
            if(temp->right) q.push(temp->right);
        }
    }
    return ans;
}

vector<int> leftViewUsingLevel(Node *root){
    vector<int> ans;
    if(root == NULL) return ans;
    queue<pair<Node*, int>> q;
    q.push({root, 0});
    int level = -1;
    while(!q.empty()){
        Node* temp = q.front().first;
        int l = q.front().second;
        q.pop();
        if(l > level){
            ans.push_back(temp->data);
            level = l;
        }
        if(temp->left) q.push({temp->left, l+1});
        if(temp->right) q.push({temp->right, l+1});
    }

    return ans;
}