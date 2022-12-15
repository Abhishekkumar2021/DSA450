/*
Given an array nums[] of size n, where nums[i] denotes the number of characters in one word. Let K be the limit on the number of characters that can be put in one line (line width). Put line breaks in the given sequence such that the lines are printed neatly.
Assume that the length of each word is smaller than the line width. When line breaks are inserted there is a possibility that extra spaces are present in each line. The extra spaces include spaces put at the end of every line except the last one. 

You have to minimize the following total cost where total cost = Sum of cost of all lines, where cost of line is = (Number of extra spaces in the line)2.

Example 1:

Input: nums = {3,2,2,5}, k = 6
Output: 10
Explanation: Given a line can have 6
characters,
Line number 1: From word no. 1 to 1
Line number 2: From word no. 2 to 3
Line number 3: From word no. 4 to 4
So total cost = (6-3)2 + (6-2-2-1)2 = 32+12 = 10.
As in the first line word length = 3 thus
extra spaces = 6 - 3 = 3 and in the second line
there are two word of length 2 and there already
1 space between two word thus extra spaces
= 6 - 2 -2 -1 = 1. As mentioned in the problem
description there will be no extra spaces in
the last line. Placing first and second word
in first line and third word on second line
would take a cost of 02 + 42 = 16 (zero spaces
on first line and 6-2 = 4 spaces on second),
which isn't the minimum possible cost.
Example 2:

Input: nums = {3,2,2}, k = 4
Output: 5
Explanation: Given a line can have 4 
characters,
Line number 1: From word no. 1 to 1
Line number 2: From word no. 2 to 2
Line number 3: From word no. 3 to 3
Same explaination as above total cost
= (4 - 3)2 + (4 - 2)2 = 5.

Your Task:
You don't need to read or print anyhting. Your task is to complete the function solveWordWrap() which takes nums and k as input paramater and returns the minimized total cost.
 

Expected Time Complexity: O(n2)
Expected Space Complexity: O(n)
 

Constraints:
1 ≤ n ≤ 500
1 ≤ nums[i] ≤ 1000
max(nums[i]) ≤ k ≤ 2000

Hint:
The idea is to place line breaks in a way that minimizes the total cost. Total cost of a line is zero if the line is empty and infinite if the line is longer than the given line width. The total cost of a line is proportional to the square of the number of extra spaces in the line. The total cost of a paragraph is the sum of costs of all lines. The problem can be solved using dynamic programming. The idea is to compute the total cost in bottom up manner using the optimal substructure property of the given problem. We start from the last word, and recursively calculate the optimal solution for the remaining words. To calculate the optimal cost of the last line, we try all words that can fit in the last line one by one. The minimum of all these values is the optimal cost of last line. We recursively calculate the optimal cost of other lines using the calculated optimal cost of last line. Finally, we return the sum of optimal cost of all lines.
*/


#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solveWordWrap(vector<int>nums, int k) 
    { 
        int n = nums.size();
        int dp[n+1];
        dp[0] = 0; // it stores the minimum cost for the first i words
        for(int i=1;i<=n;i++){
            int sum = 0;
            int minCost = INT_MAX;
            for(int j=i;j>=1;j--){
                sum += nums[j-1];
                if(sum > k) break;
                int cost = (k-sum)*(k-sum) + dp[j-1];
                minCost = min(minCost,cost);
            }
            dp[i] = minCost;
        }
        return dp[n];
    } 
};