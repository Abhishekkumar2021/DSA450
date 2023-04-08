#include<bits/stdc++.h>
using namespace std;

int longestCommonSubsequenceHelper(string a, string b, int i, int j){
    if(i<0 || j<0) return 0;

    // Two cases are possible
    // 1. If the last character of both the strings are same
    // 2. If the last character of both the strings are different

    if(a[i] == b[j]) return 1 + longestCommonSubsequenceHelper(a, b, i-1, j-1);
    else return max(longestCommonSubsequenceHelper(a, b, i-1, j), longestCommonSubsequenceHelper(a, b, i, j-1));
}

int longestCommonSubsequence(string text1, string text2) {
    int n = text1.size();
    int m = text2.size();
    return longestCommonSubsequenceHelper(text1, text2, n-1, m-1);
}

int longestCommonSubstring(string text1, string text2) {
    int n = text1.size();
    int m = text2.size();
    int dp[n+1][m+1];
    int ans = 0;
    for(int i=0; i<=n; i++){
        for(int j=0; j<=m; j++){
            if(i==0 || j==0) dp[i][j] = 0;
            else if(text1[i-1] == text2[j-1]){
                dp[i][j] = 1 + dp[i-1][j-1];
                ans = max(ans, dp[i][j]);
            }
            else dp[i][j] = 0;
        }
    }
    return ans;
}

int longestCommonSubstringHelper(string text1, string text2, int n, int m, int count) {
    if(n == 0 || m == 0) {
        return count;
    }
    if(text1[n-1] == text2[m-1]) {
        count = longestCommonSubstringHelper(text1, text2, n-1, m-1, count+1);
    }
    count = max(count, max(longestCommonSubstringHelper(text1, text2, n-1, m, 0), longestCommonSubstringHelper(text1, text2, n, m-1, 0)));
    return count;
}

int longestCommonSubstring(string text1, string text2) {
    int n = text1.size();
    int m = text2.size();
    int ans = longestCommonSubstringHelper(text1, text2, n, m, 0);
    return ans;
}

int main(){
    string a = "AGGTAB";
    string b = "GXTXAYB";

    // Ans = 4
}