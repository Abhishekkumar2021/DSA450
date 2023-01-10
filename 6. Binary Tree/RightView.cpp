#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left, *right;
    Node(int data)
    {
        this->data = data;
        left = right = NULL;
    }
};

vector<int> rightView(Node *root)
{
    vector<int> ans;
    if (root == NULL)
        return ans;
    queue<Node *> q;
    q.push(root);
    while (!q.empty())
    {
        int n = q.size();
        for (int i = 0; i < n; i++)
        {
            Node *temp = q.front();
            q.pop();
            if (i == n - 1)
                ans.push_back(temp->data);
            if (temp->left)
                q.push(temp->left);
            if (temp->right)
                q.push(temp->right);
        }
    }
    return ans;
}

vector<int> rightView2(Node *root)
{
    // Your Code here
    vector<int> ans;
    if (root == NULL)
        return ans;
    queue<pair<Node *, int>> q;
    q.push({root, 0});
    int level = -1;
    while (!q.empty())
    {
        Node *temp = q.front().first;
        int l = q.front().second;
        q.pop();
        if (l > level)
        {
            ans.push_back(temp->data);
            level = l;
        }
        if (temp->right)
            q.push({temp->right, l + 1});
        if (temp->left)
            q.push({temp->left, l + 1});
    }

    return ans;
}