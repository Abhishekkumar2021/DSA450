/*
Given an m x n binary matrix filled with 0's and 1's, find the largest square containing only 1's and return its area.

 

Example 1:


Input: matrix = [["1","0","1","0","0"],["1","0","1","1","1"],["1","1","1","1","1"],["1","0","0","1","0"]]
Output: 4
Example 2:


Input: matrix = [["0","1"],["1","0"]]
Output: 1
Example 3:

Input: matrix = [["0"]]
Output: 0
 

Constraints:

m == matrix.length
n == matrix[i].length
1 <= m, n <= 300
matrix[i][j] is '0' or '1'.

Hint:
1. If we know the maximum size of square sub-matrix of 1's ending at (i, j), we can determine the maximum size of square sub-matrix of 1's ending at (i+1, j+1) in constant time.
2. Let's define dp(i, j) as the maximum size of square sub-matrix of 1's ending at (i, j), then we have the following state equations:
dp(i, j)=min(dp(i−1, j), dp(i−1, j−1), dp(i, j−1))+1
3. The answer is the area of the largest square sub-matrix of 1's, i.e. max(i,j)∗max(i,j).
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<vector<int>> dp(n, vector<int>(m, 0));
        for(int i=0; i<n; i++) dp[i][0] = matrix[i][0] - '0';
        for(int j=0; j<m; j++) dp[0][j] = matrix[0][j] - '0';
        for(int i=1; i<n; i++){
            for(int j=0; j<m; j++){
                if(matrix[i][j] == '1'){
                    dp[i][j] = min(dp[i-1][j], min(dp[i-1][j-1], dp[i][j-1])) + 1;
                }
            }
        }
        int ans = 0;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                ans = max(ans, dp[i][j]);
            }
        }
        return ans*ans;
    }
};