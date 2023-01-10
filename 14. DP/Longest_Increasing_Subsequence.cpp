#include<bits/stdc++.h>
using namespace std;

int LCS(vector<int> arr,vector<int> brr){
    int n = arr.size();
    int m = brr.size();

    vector<vector<int>> dp(n+1,vector<int>(m+1,0));

    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(arr[i-1]==brr[j-1]){
                dp[i][j] = 1 + dp[i-1][j-1];
            }
            else{
                dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
            }
        }
    }
    return dp[n][m];
}

int LIS(vector<int> arr){
    vector<int> brr = arr;
    sort(brr.begin(),brr.end());
    return LCS(arr,brr);
}

int LIS_2(vector<int> arr){
    int n = arr.size();
    vector<int> dp(n,1);
    int ans = 1;
    for(int i=1;i<n;i++){
        for(int j=0;j<i;j++){
            if(arr[i]>arr[j]){
                dp[i] = max(dp[i],1+dp[j]);
            }
        }
        ans = max(ans,dp[i]);
    }
    return ans;
}
