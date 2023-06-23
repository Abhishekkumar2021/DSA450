#include <bits/stdc++.h>
using namespace std;

// // Tree Node
// struct Node
// {
//     int data;
//     Node* left;
//     Node* right;

//     Node(int x){
//         data = x;
//         left = right = NULL;
//     }
// };

// vector<int> bottomRightView(struct Node *root){
//     vector<int> ans;
//     if(root == NULL) return ans;
//     queue<Node*> q;
//     q.push(root);
//     q.push(NULL);

//     while(!q.empty()){
//         Node* front = q.front();
//         q.pop();
//         if(front == NULL){
//             if(!q.empty()) q.push(NULL);
//         }
//         else{
//             Node* curr = front;
//             int x = 0;
//             while(curr != NULL){
//                 x = curr->data;
//                 if(curr->left != NULL) q.push(curr->left);
//                 curr = curr->right;
//             }
//             ans.push_back(x);
//         }
//     }
//     return ans;
// }
template <typename T>
class BinaryTreeNode
{
public:
    T data;
    BinaryTreeNode<T> *left;
    BinaryTreeNode<T> *right;

    BinaryTreeNode(T data)
    {
        this->data = data;
        left = NULL;
        right = NULL;
    }
};

vector<int> bottomRightView(BinaryTreeNode<int>* root) {
    vector<int> ans;
    if(root == NULL) return ans;
    queue<pair<BinaryTreeNode<int>*, int>> q;
    q.push({root, 0});
    q.push({NULL, 0});
    map<int, int> m;

    while(!q.empty()){
        pair<BinaryTreeNode<int>*, int> front = q.front();
        q.pop();
        if(front.first == NULL){
            if(!q.empty()) q.push({NULL, 0});
        }
        else{
            m[front.second] = front.first->data;
            if(front.first->right != NULL) q.push({front.first->right, front.second});
            if(front.first->left != NULL) q.push({front.first->left, front.second+1});
        }
    }
    for(auto i:m) ans.push_back(i.second);
    reverse(ans.begin(), ans.end());
    return ans;
}