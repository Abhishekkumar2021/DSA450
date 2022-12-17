/*
Maimum path sum in a matrix
Three directions movement:
1. Left Diagonal
2. Right Diagonal
3. Straight Down

*/

#include <bits/stdc++.h>
using namespace std;

int f(int i, int j, vector<vector<int>> &mat, vector<vector<int>> &dp){
    if(i<0 || j<0 || j>=mat[0].size())
        return INT_MIN;
    if(i == mat.size()-1)
        return mat[i][j];
    if(dp[i][j] != -1)
        return dp[i][j];
    int ans = INT_MIN;
    ans = max(ans, f(i+1, j, mat, dp));
    ans = max(ans, f(i+1, j+1, mat, dp));
    ans = max(ans, f(i+1, j-1, mat, dp));
    return dp[i][j] = ans + mat[i][j];
}

int maxPath(vector<vector<int>> &mat)
{
    int ans = INT_MIN;
    vector<vector<int>> dp(mat.size(), vector<int>(mat[0].size(), -1));
    for(int i=0; i<mat[0].size(); i++){
        ans = max(ans, f(0, i, mat, dp));
    }
    return ans;
}



/*

Ques - What is wrong in this code logic?
Ans - The logic is correct but the code is not optimized. The code is not optimized because we are calling the function recursively for every element in the first row. We can optimize the code by calling the function only once for every element in the first row and storing the result in a vector. Then we can use the stored result to calculate the result for the next row.

*/