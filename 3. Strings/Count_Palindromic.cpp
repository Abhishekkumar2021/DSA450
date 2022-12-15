/*
Given a string str of length N, you have to find number of palindromic subsequence (need not necessarily be distinct) present in the string str.
Note: You have to return the answer module 109+7;
 

Example 1:

Input: 
Str = "abcd"
Output: 
4
Explanation:
palindromic subsequence are : "a" ,"b", "c" ,"d"
 

Example 2:

Input: 
Str = "aab"
Output: 
4
Explanation:
palindromic subsequence are :"a", "a", "b", "aa"
 

Your Task:
You don't need to read input or print anything. Your task is to complete the function countPs() which takes a string str as input parameter and returns the number of palindromic subsequence.
 

Expected Time Complexity: O(N*N)
Expected Auxiliary Space: O(N*N)


Constraints:
1<=length of string str <=1000

Approach:
1. Recursive Approach:
    1. If left > right, return 0
    2. If left == right, return 1
    3. If s[left] == s[right], return countPs(s, left + 1, right) + countPs(s, left, right - 1) + 1
    4. Else, return countPs(s, left + 1, right) + countPs(s, left, right - 1) - countPs(s, left + 1, right - 1)

2. DP Approach:
    1. dp[i][j] = number of palindromic subsequence in s[i..j]
    2. dp[i][i] = 1
    3. for len = 2 to n:
        for i = 0 to n - len + 1:
            j = i + len - 1
            if s[i] == s[j]:
                dp[i][j] = dp[i + 1][j] + dp[i][j - 1] + 1
            else:
                dp[i][j] = dp[i + 1][j] + dp[i][j - 1] - dp[i + 1][j - 1]
    4. return dp[0][n - 1]


*/

#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007

int getPalindromicSubsequenceCount(string s, int left, int right) {
    if(left > right) {
        return 0;
    }
    if(left == right) {
        return 1;
    }

    if(s[left] == s[right]) {
        return getPalindromicSubsequenceCount(s, left + 1, right) + getPalindromicSubsequenceCount(s, left, right - 1) + 1;
    } else {
        return getPalindromicSubsequenceCount(s, left + 1, right) + getPalindromicSubsequenceCount(s, left, right - 1) - getPalindromicSubsequenceCount(s, left + 1, right - 1);
    }
    
}

int getPalindromicSubsequenceCount(string s) {
    int n = s.length();
    int dp[n][n];
    memset(dp, 0, sizeof(dp)); // dp[i][j] = number of palindromic subsequence in s[i..j]
    for(int i=0; i<n; i++) {
        dp[i][i] = 1;
    }

    for(int len=2; len<=n; len++) {
        for(int i=0; i<n-len+1; i++) {
            int j = i + len - 1;
            if(s[i] == s[j]) {
                dp[i][j] = (dp[i + 1][j] + dp[i][j - 1] + 1) % MOD;
            } else {
                dp[i][j] = (dp[i + 1][j] + dp[i][j - 1] - dp[i + 1][j - 1]) % MOD;
            }
        }
    }

    return dp[0][n - 1];
}