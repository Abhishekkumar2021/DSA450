#include<bits/stdc++.h>
using namespace std;

template<typename T>
class TreeNode{
public:
    T data;
    TreeNode<T> *left, *right;
    TreeNode(T data){
        this->data = data;
        left = right = NULL;
    }
};

int height(TreeNode<int>* root){
    if(root == NULL)
        return 0;
    return 1 + max(height(root->left), height(root->right));
}

int width(TreeNode<int>* root){
    TreeNode<int>* temp = root;
    int ans = 0;
    while(temp != NULL){
        ans++;
        temp = temp->right;
    }
    temp = root;
    while(temp != NULL){
        ans++;
        temp = temp->left;
    }
    return ans - 1;
}

vector<vector<string>> printTree(TreeNode<int>* root){
    vector<vector<string>> ans;
    
    return ans;
}

int main(){
    TreeNode<int>* root = new TreeNode<int>(1);
    root->left = new TreeNode<int>(2);
    root->right = new TreeNode<int>(3);
    root->left->left = new TreeNode<int>(4);
    root->left->right = new TreeNode<int>(5);
    root->right->left = new TreeNode<int>(6);
    root->right->right = new TreeNode<int>(7);
}
