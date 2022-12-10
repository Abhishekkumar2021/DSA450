/*
Given an array of integers (A[])  and a number x, find the smallest subarray with sum greater than the given value. If such a subarray do not exist return 0 in that case.

Note: The answer always exists. It is guaranteed that x doesn't exceed the summation of a[i] (from 1 to N).

Example 1:

Input:
A[] = {1, 4, 45, 6, 0, 19}
x  =  51
Output: 3
Explanation:
Minimum length subarray is 
{4, 45, 6}

Example 2:
Input:
A[] = {1, 10, 5, 2, 7}
   x  = 9
Output: 1
Explanation:
Minimum length subarray is {10}


*/

#include <bits/stdc++.h>
using namespace std;

int getMinLength(int a[], int n, int x){
    int sum = 0;
    int ans = INT_MAX;
    int i = 0;
    int j = 0;
    while(j<n){
        sum += a[j];
        while(sum>x){
            if(sum>x){
                ans = min(ans, j-i+1);
            }
            sum -= a[i];
            i++;
        }
        j++;
    }
    return ans;
}


int main() {
    int n, x;
    cin >> n >> x;
    int a[n];
    for(int i = 0;i<n;i++){
        cin >> a[i];
    }
}