/*
Given a number n. The task is to find the smallest number whose factorial contains at least n trailing zeroes.

Example 1:

Input:
n = 1
Output: 5
Explanation : 5! = 120 which has at
least 1 trailing 0.
Example 2:

Input:
n = 6
Output: 25
Explanation : 25! has at least
6 trailing 0.

User Task:
Complete the function findNum() which takes an integer N as input parameters, and returns the answer.

Expected Time Complexity: O(log2 N * log5 N).
Expected Auxiliary Space: O(1).

Constraints:
1 <= n <= 104

Hint:
The idea is to use binary search. We start with a range of possible values for the answer. We check if the factorial of the middle element of the range has at least n trailing zeroes. If it does, we continue the search in the left half of the range, otherwise we continue in the right half. The search ends when the left and right ends of the range meet. The answer is the left end of the range.
*/

#include<bits/stdc++.h>
using namespace std;

int findTrailingZeros(int n){
    int cnt = 0;
    while(n){
        cnt += n/5;
        n /= 5;
    }
    return cnt;
}

int findNum(int n) {
    // code here
    int low = 0;
    int high = 5*n; //Why? - Because 5*n! has at least n trailing zeroes.
    int ans = -1;
    while(low<=high){
        int mid = low + (high-low)/2;
        if(findTrailingZeros(mid)>=n){
            ans = mid;
            high = mid-1;
        }
        else{
            low = mid+1;
        }
    }
    return ans;
}