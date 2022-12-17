/*
Given a non-empty array nums containing only positive integers, find if the array can be partitioned into two subsets such that the sum of elements in both subsets is equal.

 

Example 1:

Input: nums = [1,5,11,5]
Output: true
Explanation: The array can be partitioned as [1, 5, 5] and [11].
Example 2:

Input: nums = [1,2,3,5]
Output: false
Explanation: The array cannot be partitioned into equal sum subsets.
 

Constraints:

1 <= nums.length <= 200
1 <= nums[i] <= 100
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool f(vector<int> &nums, int i, int sum, vector<vector<int>> &dp){
        if(sum==0) return true;
        if(i<0 || sum<0) return false;
        if(dp[i][sum]!=-1) return dp[i][sum];
        return dp[i][sum] = f(nums,i-1,sum-nums[i],dp) || f(nums,i-1,sum,dp);
    }
    bool subsetExist(vector<int> &nums, int sum){
        int n = nums.size();
        vector<vector<int>> dp(n+1,vector<int>(sum+1,-1));
        for(int i=0;i<n;i++) dp[i][0] = true;
        for(int i=1;i<=sum;i++) dp[0][i] = false;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=sum;j++){
                if(nums[i-1]<=j) dp[i][j] = dp[i-1][j-nums[i-1]] || dp[i-1][j];
                else dp[i][j] = dp[i-1][j];
            }
        }
        return dp[n][sum];
    }
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        for(int i=0;i<n;i++) sum += nums[i];
        if(sum%2) return false;
        sum /= 2;
        vector<vector<int>> dp(n,vector<int>(sum+1,-1));
        return f(nums,n-1,sum,dp);
    }
};