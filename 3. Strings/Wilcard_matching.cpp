/*
Given two strings pattern and str where pattern string may contain pattern card characters and str string is a normal string. Determine if the two strings match. The following are the allowed pattern card characters in first string :-

* --> This character in string pattern can be replaced by any sequence of characters, it can also be replaced by an empty string.
? --> This character in string pattern can be replaced by any one character.
Example 1:

Input: pattern = ge*ks
       str = geeks
Output: Yes
Explanation: Replace the '*' in pattern string 
with 'e' to obtain str "geeks".
Example 2:

Input: pattern = ge?ks*
       str = geeksforgeeks
Output: Yes
Explanation: Replace '?' and '*' in pattern string with
'e' and 'forgeeks' respectively to obtain str 
"geeksforgeeks"

Your Task:
You don't need to read input or print anything. Your task is to complete the function match() which takes the string pattern and str as input parameters and returns true if the string pattern can be made equal to the string str, otherwise, returns false.

Expected Time Complexity: O(length of pattern string * length of str string)
Expected Auxiliary Space: O(length of pattern string * length of str string)

Constraints:
1<=length of the two string<=10^3 
*/

#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
    bool f(string &pattern, string &str, int i, int j,vector<vector<int>> &dp){
        if(i<0 && j<0) return true;
        if(i<0 && j>=0) return false;
        if(i>=0 && j<0){
            for(int k=0; k<=i; k++){
                if(pattern[k]!='*') return false;
            }
            return true;
        }
        if(dp[i][j]!=-1) return dp[i][j];
        if(pattern[i]==str[j] || pattern[i] == '?') return dp[i][j] = f(pattern, str, i-1, j-1,dp);
        if(pattern[i]=='*') return dp[i][j] = f(pattern, str, i-1, j,dp) || f(pattern, str, i, j-1,dp);
        return dp[i][j] = false;
    }
    bool match1(string pattern, string str){
        int n = pattern.size();
        int m = str.size();
        vector<vector<int>> dp(n, vector<int>(m, -1));
        return f(pattern, str, n-1, m-1,dp);
    }
    bool match(string pattern, string str){
        int n = pattern.size();
        int m = str.size();
        vector<vector<bool>> dp(n+1, vector<bool>(m+1, false));
        dp[0][0] = true;
        for(int i=1; i<=n; i++){
            if(pattern[i-1]=='*') dp[i][0] = dp[i-1][0];
        }
        for(int i=1; i<=n; i++){
            for(int j=1; j<=m; j++){
                if(pattern[i-1]==str[j-1] || pattern[i-1]=='?') dp[i][j] = dp[i-1][j-1];
                else if(pattern[i-1]=='*') dp[i][j] = dp[i-1][j] || dp[i][j-1];
            }
        }
        return dp[n][m];
    }
        
};
