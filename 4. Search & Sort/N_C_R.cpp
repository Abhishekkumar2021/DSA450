/*
 Write a function to calculate nCr. ( nCr = (n!) / (r! * (n-r)!) )

 Approach:
    1. Create a 2D array of size (n+1)*(r+1)
    2. Initialize the first row and first column with 1
    3. For each cell, calculate the value by adding the value of the cell above it and the cell to the left of it
    4. Return the value at the bottom right corner of the array
*/

#include <bits/stdc++.h>
using namespace std;

int nCr(int n, int r){
    int dp[n+1][r+1];
    for(int i = 0; i <= n; i++){
        for(int j = 0; j <= min(i, r); j++){
            if(j == 0 || j == i){
                dp[i][j] = 1;
            }else{
                dp[i][j] = dp[i-1][j-1] + dp[i-1][j];
            }
        }
    }
    return dp[n][r];
}
