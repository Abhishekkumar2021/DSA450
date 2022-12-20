/*
Stickler the thief wants to loot money from a society having n houses in a single line. He is a weird person and follows a certain rule when looting the houses. According to the rule, he will never loot two consecutive houses. At the same time, he wants to maximize the amount he loots. The thief knows which house has what amount of money but is unable to come up with an optimal looting strategy. He asks for your help to find the maximum money he can get if he strictly follows the rule. Each house has a[i]amount of money present in it.

Example 1:

Input:
n = 6
a[] = {5,5,10,100,10,5}
Output: 110
Explanation: 5+100+5=110
Example 2:

Input:
n = 3
a[] = {1,2,3}
Output: 4
Explanation: 1+3=4
Your Task:
Complete the functionFindMaxSum()which takes an array arr[] and n as input which returns the maximum money he can get following the rules

Expected Time Complexity:O(N).
Expected Space Complexity:O(N).

Constraints:
1 ≤ n ≤ 10^4
1 ≤ a[i] ≤ 10^4
*/

#include <bits/stdc++.h>
using namespace std;

int FindMaxSum(int arr[], int n){
    int dp[n];
    dp[0] = arr[0];
    dp[1] = max(arr[0], arr[1]);
    for(int i = 2; i < n; i++){
        dp[i] = max(dp[i-1], dp[i-2] + arr[i]);
    }
    return dp[n-1];
}