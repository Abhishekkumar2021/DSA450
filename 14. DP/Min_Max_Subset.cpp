/*
    Given an array of integers, The task is to -
    1. Find the minimum subset sum difference i.e divide the array into two subset such that maximum sum of one subset is minimum.
*/

#include<bits/stdc++.h>
using namespace std;

int minSubsetSumDiff(int arr[], int n, int target){
    int dp[n+1][target+1];
    memset(dp, 0, sizeof(dp));

    for(int i=0; i<=n ;i++) dp[i][0] = true;

    for(int i=1; i<=n; i++){
        for(int j=1; j<=target; j++){
            if(arr[i-1] <= j){
                dp[i][j] = dp[i-1][j-arr[i-1]] || dp[i-1][j];
            }
            else dp[i][j] = dp[i-1][j];
        }
    }

    int minDiff = INT_MAX;
    for(int i=0; i<=target/2; i++){
        if(dp[n][i]){
            minDiff = min(minDiff, target - 2*i);
        }
    }

    return minDiff;
}

