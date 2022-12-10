/*
You are given an array prices where prices[i] is the price of a given stock on the ith day.

Find the maximum profit you can achieve. You may complete at most two transactions.

Note: You may not engage in multiple transactions simultaneously (i.e., you must sell the stock before you buy again).

 

Example 1:

Input: prices = [3,3,5,0,0,3,1,4]
Output: 6
Explanation: Buy on day 4 (price = 0) and sell on day 6 (price = 3), profit = 3-0 = 3.
Then buy on day 7 (price = 1) and sell on day 8 (price = 4), profit = 4-1 = 3.
Example 2:

Input: prices = [1,2,3,4,5]
Output: 4
Explanation: Buy on day 1 (price = 1) and sell on day 5 (price = 5), profit = 5-1 = 4.
Note that you cannot buy on day 1, buy on day 2 and sell them later, as you are engaging multiple transactions at the same time. You must sell before buying again.
Example 3:

Input: prices = [7,6,4,3,1]
Output: 0
Explanation: In this case, no transaction is done, i.e. max profit = 0.
 

Constraints:

1 <= prices.length <= 10^5
0 <= prices[i] <= 10^5

Hint:
1. This problem is similar to "Best Time to Buy and Sell Stock". But this time you may complete at most two transactions.
2. One simple thought is to divide the array into two parts and find the maximum profit for each part. Then combine them together. However, this will not work if the two parts overlap.
3. To solve this problem, we need to think about the "cumulative" profit. That is, if we know the maximum profit of prices[0:i] and the maximum profit of prices[i:n-1], then we can combine them together to get the maximum profit of prices[0:n-1].
4. To achieve this, we need to scan the array from left to right and record the maximum profit of prices[0:i]. Then scan the array from right to left and record the maximum profit of prices[i:n-1]. Finally, combine them together.

https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iii/
*/

#include<bits/stdc++.h>
using namespace std;

int maxProfit(vector<int>& prices, int left, int right){
    int profit = 0;
    int mini = prices[left];
    for(int i = left+1; i <= right; i++){
        if(prices[i]<mini)
            mini = prices[i];
        else if(prices[i]-mini > profit)
            profit = prices[i]-mini;
    }
    
    return profit;
}


int maxProfitTwoTransactions(vector<int>& prices) {
    int n = prices.size();
    if(n==0)
        return 0;
    
    int profit = 0;
    for(int i=0; i<n; i++){
        profit = max(profit, maxProfit(prices, 0, i) + maxProfit(prices, i+1, n-1));
    } 
    return profit;
}
int main(){
    vector<int> prices = {3,3,5,0,0,3,1,4};
    cout<<maxProfitTwoTransactions(prices);
    return 0;
}