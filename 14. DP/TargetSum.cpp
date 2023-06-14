#include<bits/stdc++.h>
using namespace std;

int countSubsets(vector<int> &arr, int target){
    int n = arr.size();
    vector<vector<int>> dp(n+1, vector<int>(target+1, 0));
    for(int i=0; i<=n; i++){
        for(int j = 0; j<=target; j++){
            if(j==0) dp[i][j] = 1;
            else if(i==0) dp[i][j] = 0;
            else{
                if(arr[i-1] <= j){
                    dp[i][j] = dp[i-1][j-arr[i-1]] + dp[i-1][j];
                }
                else dp[i][j] = dp[i-1][j];
            }
        }
    }
    return dp[n][target];
}

int countSubsetWithGivenDiff(vector<int> &arr, int diff){
    int n = arr.size();
    int sum = 0;
    for(int i=0; i<n; i++) sum += arr[i];
    int s1 = (sum + diff)/2;
    return countSubsets(arr, s1);
}

int numberOf01ways(vector<int> &arr, int target){
    return countSubsetWithGivenDiff(arr, target);
}