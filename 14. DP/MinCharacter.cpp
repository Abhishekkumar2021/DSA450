/*
    Given a string find the minimum number of characters to be inserted at the beginning of the string to make it a palindrome.
    Approach:
        1. Find the longest palindromic subsequence.
        2. The minimum number of characters to be inserted at the beginning of the string to make it a palindrome = length of string - length of longest palindromic subsequence.
*/ 

#include<bits/stdc++.h>
using namespace std;

int minInsertion(string s, int n){
    string rev = s;
    reverse(rev.begin(), rev.end());
    int dp[n+1][n+1];
    for(int i=0; i<=n; i++){
        for(int j=0; j<=n; j++){
            if(i==0 || j==0)
                dp[i][j] = 0;
            else if(s[i-1] == rev[j-1])
                dp[i][j] = 1 + dp[i-1][j-1];
            else
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
        }
    }
    return n - dp[n][n];
}

int main(){
    string s = "AACECAAAA";
    int n = s.length();

}