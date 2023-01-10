/*
Given a binary tree of size N, find its reverse level order traversal. ie- the traversal must begin from the last level.

Example 1:

Input :
        1
      /   \
     3     2

Output: 3 2 1
Explanation:
Traversing level 1 : 3 2
Traversing level 0 : 1
Example 2:

Input :
       10
      /  \
     20   30
    / \ 
   40  60

Output: 40 60 20 30 10
Explanation:
Traversing level 2 : 40 60
Traversing level 1 : 20 30
Traversing level 0 : 10

Your Task: 
You dont need to read input or print anything. Complete the function reverseLevelOrder() which takes the root of the tree as input parameter and returns a list containing the reverse level order traversal of the given tree.


Expected Time Complexity: O(N)
Expected Auxiliary Space: O(N)


Constraints:
1 ≤ N ≤ 10^4

Hint:
1. Use a queue to store the nodes of the tree.
2. Use a stack to store the nodes of the tree.
3. Traverse the tree in level order fashion and push the nodes into the stack.
4. Pop the elements from the stack and store them in a list.
5. Return the list.
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

vector<int> reverseLevelOrder(Node *root){
    vector<int> ans;
    if(root == NULL) return ans;
    queue<Node*> q;
    stack<Node*> s;
    q.push(root);
    while(!q.empty()){
        Node* temp = q.front();
        q.pop();
        s.push(temp);
        if(temp->right) q.push(temp->right);
        if(temp->left) q.push(temp->left);
    }
    while(!s.empty()){
        ans.push_back(s.top()->data);
        s.pop();
    }
    return ans; 
}

vector<int> reverseLevelOrder2(Node *root)
{
    // code here
    vector<int> ans;
    map<int, vector<int>> mp;
    queue<pair<int, Node*>> pq;
    pq.push({0, root});
    while(!pq.empty()){
        pair<int, Node*> p = pq.front();
        pq.pop();
        int level = p.first;
        Node* node = p.second;
        mp[level].push_back(node->data);
        if(node->left) pq.push({level+1, node->left});
        if(node->right) pq.push({level+1, node->right});
    }
    int level = mp.size() - 1;
    while(level!=-1){
        for(auto &x: mp[level]) ans.push_back(x);
        level--;
    }
    return ans;
    
    
}