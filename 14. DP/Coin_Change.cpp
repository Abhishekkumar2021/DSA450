#include<bits/stdc++.h>
using namespace std;

int f(int amount, vector<int> currency, int n){
    if(amount==0){
        return 1;
    }
    if(n==0){
        return 0;
    }
    if(currency[n-1]<=amount){
        return f(amount-currency[n-1],currency,n) + f(amount,currency,n-1);
    }
    else{
        return f(amount,currency,n-1);
    }
}

int countWays(int amount, vector<int> currency){
    int n = currency.size();
    return f(amount,currency,n);
}

int tabulation(int amount, vector<int> currency){
    int n = currency.size();
    vector<vector<int>> dp(n+1,vector<int>(amount+1,0));
    for(int i=0;i<=n;i++){
        dp[i][0] = 1;
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=amount;j++){
            if(currency[i-1]<=j){
                dp[i][j] = dp[i-1][j] + dp[i][j-currency[i-1]];
            }
            else{
                dp[i][j] = dp[i-1][j];
            }
        }
    }
    return dp[n][amount];
}