/*
You have been given a 2-D matrix ‘MAT’ of size ‘N’ x ‘N’ i.e. N rows and N columns. Your task is to find the maximum value of ‘MAT[a][b]’ - ‘MAT[c][d]’ over all possible indices (0 <= ‘a’, ‘b’, ‘c’, ‘d’ < ‘N’) such that . ‘a’ > ‘c’ and ‘b’ > ‘d’.

For example:
MAT[3][3] = {{1,2,3}
             {4,5,6}
             {7,8,9}
            }


In this example, to maximise the value of ‘MAT[a][b]’ - ‘MAT[c][d]’ fulfilling the given conditions on indices (‘a’ > ‘c’ and ‘b’ > ‘d’), we take ‘a’ = 2, ‘b’ = 2, ‘c’ = 0 and ‘d’ = 0 .  So, ‘MAT[a][b]’ = 9 and ‘MAT[c][d]’ = 1 and the value of ‘MAT[a][b]’ - ‘MAT[c][d]’ => 9 - 1 = 8 which is maximum among all possible combinations.
Input Format:
The first line of input contains an integer 'T' which denotes the number of test cases or queries to be run. Then the test cases follow.
The first line of each test case contains one integer ‘N’ representing the number of rows (or columns) of the square matrix ‘MAT’.
The next ‘N’ lines of each test case contain ‘N’ single space-separated integers denoting the values of ‘MAT’.

Output Format :
For each test case, print the maximum value of ‘MAT[a][b]’ - ‘MAT[c][d]’ over all possible choices of indices i.e. 0 <= ‘a’, ‘b’, ‘c’, ‘d’ < ‘N’ such that  ‘a’ > ‘c’ and ‘b’ > ‘d’.

Print the output of each test case in a separate line.
Note:

You do not need to print anything; it has already been taken care of. Just implement the given function.
Constraints:
1 <= ‘T’ <= 100
2 <= ‘N’ <= 100
-10^5 <= ‘MAT[i][j]’ <= 10^5

Time Limit : 1 second

Hint:
For each index (‘a’, ‘b’) in the matrix, find the maximum value of ‘MAT[a][b]’ - ‘MAT[c][d]’ over all possible choices of indices (‘c’, ‘d’) such that  ‘a’ > ‘c’ and ‘b’ > ‘d’.

Effecient Approach:
The idea is to find the maximum value of ‘MAT[a][b]’ - ‘MAT[c][d]’ over all possible choices of indices (‘c’, ‘d’) such that  ‘a’ > ‘c’ and ‘b’ > ‘d’. We can do this by finding the maximum value of ‘MAT[a][b]’ over all possible choices of indices (‘a’, ‘b’) and then subtracting the minimum value of ‘MAT[c][d]’ over all possible choices of indices (‘c’, ‘d’) such that  ‘a’ > ‘c’ and ‘b’ > ‘d’ from the maximum value of ‘MAT[a][b]’ over all possible choices of indices (‘a’, ‘b’).


*/

#include<bits/stdc++.h>
using namespace std;

int getDifference(vector<vector<int>>& mat, int i, int j, int n){
    int maxi = INT_MIN;
    for(int k=i+1; k<n; k++){
        for(int l=j+1; l<n; l++){
            maxi = max(maxi, mat[k][l] - mat[i][j]);
        }
    }
    return maxi;
}

int findMaxValueNaive(vector<vector<int>>& mat, int n){
    int maxi = INT_MIN;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            maxi = max(maxi, getDifference(mat, i, j, n)); 
        }
    }
    return maxi;
}

// Condition must be followed: a > c and b > d
int findMaxValue(vector<vector<int>>& mat, int n){
    vector<vector<int>> preprocess(n, vector<int>(n, 0));
    preprocess[n-1][n-1] = mat[n-1][n-1];
    for(int i=n-2; i>=0; i--){
        preprocess[i][n-1] = max(preprocess[i+1][n-1], mat[i][n-1]);
        preprocess[n-1][i] = max(preprocess[n-1][i+1], mat[n-1][i]);
    }
    for(int i=n-2; i>=0; i--){
        for(int j=n-2; j>=0; j--){
            preprocess[i][j] = max({preprocess[i+1][j], preprocess[i][j+1], mat[i][j]});
        }
    }

    int maxi = INT_MIN;
    for(int i=0; i<n-1; i++){
        for(int j=0; j<n-1; j++){
            maxi = max(maxi, preprocess[i+1][j+1] - mat[i][j]);
        }
    }
    return maxi;
}