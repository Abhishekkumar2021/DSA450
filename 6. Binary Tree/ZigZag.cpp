/*
Given a Binary Tree. Find the Zig-Zag Level Order Traversal of the Binary Tree.

 

Example 1:

Input:
        1
      /   \
     2     3
    / \   /  \
   4   5 6    7
Output:
1 3 2 4 5 6 7
Example 2:

Input:
           7
        /     \
       9       7
     /  \     /   
    8    8   6     
   /  \
  10   9 
Output:
7 7 9 8 8 6 9 10 
 

Your Task:
You don't need to read input or print anything. Your task is to complete the function zigZagTraversal() which takes the root node of the Binary Tree as its input and returns a list containing the node values as they appear in the Zig-Zag Level-Order Traversal of the Tree.

 

Expected Time Complexity: O(N).
Expected Auxiliary Space: O(N).

 

Constraints:
1 <= N <= 104
*/

#include<bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node* left;
    Node* right;
    Node(int val)
    {
        data = val;
        left = NULL;
        right = NULL;
    }
};

vector <int> zigZagTraversal(Node* root){
    vector<int> ans;
    if(root == NULL)
        return ans;
    map<int, vector<int>> mp;
    queue<pair<Node*, int>> q;
    q.push({root, 0});
    while(!q.empty()){
        Node* node = q.front().first;
        int level = q.front().second;
        q.pop();
        mp[level].push_back(node->data);
        if(node->left)
            q.push({node->left, level+1});
        if(node->right)
            q.push({node->right, level+1});
    }

    for(auto it: mp){
        if(it.first % 2 == 0){
            for(int i=0; i<it.second.size(); i++)
                ans.push_back(it.second[i]);
        }
        else{
            for(int i=it.second.size()-1; i>=0; i--)
                ans.push_back(it.second[i]);
        }
    }
    return ans;
}

vector<int> zigZagTraversalUsingStacks(Node* root){
    vector<int> ans;
    if(root == NULL)
        return ans;
    stack<Node*> s1;
    stack<Node*> s2;
    s1.push(root);
    while(!s1.empty() || !s2.empty()){
        while(!s1.empty()){
            Node* node = s1.top();
            s1.pop();
            ans.push_back(node->data);
            if(node->left)
                s2.push(node->left);
            if(node->right)
                s2.push(node->right);
        }
        while(!s2.empty()){
            Node* node = s2.top();
            s2.pop();
            ans.push_back(node->data);
            if(node->right)
                s1.push(node->right);
            if(node->left)
                s1.push(node->left);
        }
    }
    return ans;
}
