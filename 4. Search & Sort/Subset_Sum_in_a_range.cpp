/*
Given a sequence of N (1 ≤ N ≤ 34) numbers S1, ..., SN (-20,000,000 ≤ Si ≤ 20,000,000), determine how many subsets of S (including the empty one) have a sum between A and B (-500,000,000 ≤ A ≤ B ≤ 500,000,000), inclusive.

Input
The first line of standard input contains the three integers N, A, and B. The following N lines contain S1 through SN, in order.

Output
Print a single integer to standard output representing the number of subsets satisfying the above property. Note that the answer may overflow a 32-bit integer.

Example
Input:
3 -1 2
1
-2
3

Output:
5
The following 5 subsets have a sum between -1 and 2:

0 = 0 (the empty subset)
1 = 1
1 + (-2) = -1
-2 + 3 = 1
1 + (-2) + 3 = 2

*/

#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> subsetSum(vector<int> arr, int target){
    int n = arr.size();
    vector<vector<int>> dp(n+1, vector<int>(target+1, false));
    for(int i=0; i<=n; i++){
        dp[i][0] = 1;
    }
    for(int i=1; i<=n; i++){
        for(int j=1; j<=target; j++){
            if(j>=arr[i-1]){
                dp[i][j] = dp[i-1][j] + dp[i-1][j-arr[i-1]];
            }else{
                dp[i][j] = dp[i-1][j];
            }
        }
    }
    return dp;
}

int main() {
    int n, a, b;
    cin >> n >> a >> b;
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }

    // Method 1: Brute Force
    // int ans = 0;
    // for (int i = 0; i < (1 << n); i++) {
    //     int sum = 0;
    //     for (int j = 0; j < n; j++) {
    //         if (i & (1 << j)) {
    //             sum += v[j];
    //         }
    //     }
    //     if (sum >= a && sum <= b) {
    //         ans++;
    //     }
    // }
    // cout << ans << endl;

    // Method 2: DP
    int ans = 0;
    vector<vector<int>> dp = subsetSum(v, b);
    for(int i=a; i<=b; i++){
        ans += dp[n][i];
    }
    cout << ans << endl;
    return 0;
}   