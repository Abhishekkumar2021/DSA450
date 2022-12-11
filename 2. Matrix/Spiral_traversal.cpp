/*
Given a matrix of size r*c. Traverse the matrix in spiral form.

Example 1:

Input:
r = 4, c = 4
matrix[][] = {{1, 2, 3, 4},
           {5, 6, 7, 8},
           {9, 10, 11, 12},
           {13, 14, 15,16}}
Output: 
1 2 3 4 8 12 16 15 14 13 9 5 6 7 11 10
Explanation:

Example 2:

Input:
r = 3, c = 4  
matrix[][] = {{1, 2, 3, 4},
           {5, 6, 7, 8},
           {9, 10, 11, 12}}
Output: 
1 2 3 4 8 12 11 10 9 5 6 7
Explanation:
Applying same technique as shown above, 
output for the 2nd testcase will be 
1 2 3 4 8 12 11 10 9 5 6 7.
*/

#include<bits/stdc++.h>
using namespace std;

vector<int> spirallyTraverse(vector<vector<int> > matrix, int r, int c) 
{
    int dir = 1;
    int top = 0, bottom = r-1, left = 0, right = c-1;
    vector<int> ans;

    while(top <= bottom && left <= right)
    {
        if(dir == 1)
        {
            for(int i = left; i <= right; i++)
                ans.push_back(matrix[top][i]);
            top++;
        }
        else if(dir == 2)
        {
            for(int i = top; i <= bottom; i++)
                ans.push_back(matrix[i][right]);
            right--;
        }
        else if(dir == 3)
        {
            for(int i = right; i >= left; i--)
                ans.push_back(matrix[bottom][i]);
            bottom--;
        }
        else if(dir == 4)
        {
            for(int i = bottom; i >= top; i--)
                ans.push_back(matrix[i][left]);
            left++;
        }
        dir = (dir % 4) + 1;
    }
    return ans;
}

int main()
{
    int r, c;
    cin >> r >> c;
    vector<vector<int> > matrix(r, vector<int>(c));
    for(int i = 0; i < r; i++)
        for(int j = 0; j < c; j++)
            cin >> matrix[i][j];
    vector<int> ans = spirallyTraverse(matrix, r, c);
    for(int i = 0; i < ans.size(); i++)
        cout << ans[i] << " ";
    cout << endl;
}