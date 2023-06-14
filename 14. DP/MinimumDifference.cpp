#include<bits/stdc++.h>
using namespace std;

int countSubsets(vector<int> &arr){
    int n = arr.size();
    int target = 0;
    for(int i=0; i<n; i++) target += arr[i];
    vector<vector<bool>> dp(n+1, vector<bool>(target+1, 0));
    for(int i=0; i<=n; i++){
        for(int j = 0; j<=target; j++){
            if(j==0) dp[i][j] = 1;
            else if(i==0) dp[i][j] = 0;
            else{
                if(arr[i-1] <= j){
                    dp[i][j] = dp[i-1][j-arr[i-1]] || dp[i-1][j];
                }
                else dp[i][j] = dp[i-1][j];
            }
        }
    }
    
    int ans = INT_MAX;
    for(int i=0; i<=target; i++){
        if(dp[n][i]) ans = min(ans, abs(target - 2*i));
    }

    return ans;
}