/*
Given two strings s and t. Return the minimum number of operations required to convert s to t.
The possible operations are permitted:

Insert a character at any position of the string.
Remove any character from the string.
Replace any character from the string with any other character.
 

Example 1:

Input: 
s = "geek", t = "gesek"
Output: 1
Explanation: One operation is required 
inserting 's' between two 'e's of str1.
Example 2:

Input : 
s = "gfg", t = "gfg"
Output: 
0
Explanation: Both strings are same.
 

Your Task:
You don't need to read or print anything. Your task is to complete the function editDistance() which takes strings s and t as input parameters and returns the minimum number of operation to convert the string s to string t. 


Expected Time Complexity: O(|s|*|t|)
Expected Space Complexity: O(|s|*|t|)


Constraints:
1 ≤ Length of both strings ≤ 100
Both the strings are in lowercase.
*/

#include<bits/stdc++.h>
using namespace std;


class Solution{
    public:
    int editDistanceRecursion(string s, string t, int m, int n){
        if(m==0) return n;
        if(n==0) return m;
        if(s[m-1]==t[n-1]) return editDistanceRecursion(s,t,m-1,n-1);
        int insert = editDistanceRecursion(s,t,m,n-1);
        int remove = editDistanceRecursion(s,t,m-1,n);
        int replace = editDistanceRecursion(s,t,m-1,n-1);
        return 1+min({insert,remove,replace});
    }

    int editDistance(string s, string t) 
    { 
        int m = s.length();
        int n = t.length();
        int dp[m+1][n+1];
        for(int i=0;i<=m;i++){
            for(int j=0;j<=n;j++){
                if(i==0) dp[i][j] = j;
                else if(j==0) dp[i][j] = i;
                else if(s[i-1]==t[j-1]) dp[i][j] = dp[i-1][j-1];
                else{
                    int insert = dp[i][j-1];
                    int remove = dp[i-1][j];
                    int replace = dp[i-1][j-1];
                    dp[i][j] = 1+min({insert,remove,replace});
                }
            }
        }
        return dp[m][n];
    }
};