#include<bits/stdc++.h>
using namespace std;

bool isExist(int arr[], int idx, int target){
    if(target == 0) return true;
    if(idx < 0) return false;

    // 2 choices
    // 1. include the current element
    // 2. exclude the current element

    // 1. include the current element
    if(arr[idx] <= target){
        bool include = isExist(arr, idx-1, target-arr[idx]);
        if(include) return true;
    }

    // 2. exclude the current element
    bool exclude = isExist(arr, idx-1, target);
    if(exclude) return true;
}

bool isExistDP(int arr[], int n, int target){
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

    return dp[n][target];
}


bool isSubsetSum(int arr[], int n, int target){
    return isExist(arr, n-1, target);
}


int main(){
    int arr[] = {2, 3, 7, 8, 10};
    int n = sizeof(arr)/sizeof(arr[0]);
    int target = 11;
    if(isSubsetSum(arr, n, target)) cout<<"Yes";
    else cout<<"No";
}