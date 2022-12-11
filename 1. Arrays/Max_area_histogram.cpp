/*
Find the largest rectangular area possible in a given histogram where the largest rectangle can be made of a number of contiguous bars. For simplicity, assume that all bars have the same width and the width is 1 unit, there will be N bars height of each bar will be given by the array arr.

Example 1:

Input:
N = 7
arr[] = {6,2,5,4,5,1,6}
Output: 12
Explanation: 


Example 2:

Input:
N = 8
arr[] = {7 2 8 9 1 3 6 5}
Output: 16
Explanation: Maximum size of the histogram 
will be 8  and there will be 2 consecutive 
histogram. And hence the area of the 
histogram will be 8x2 = 16.
Your Task:
The task is to complete the function getMaxArea() which takes the array arr[] and its size N as inputs and finds the largest rectangular area possible and returns the answer.

Expected Time Complxity : O(N)
Expected Auxilliary Space : O(N)

Constralong longs:
1 ≤ N ≤ 10^6
1 ≤ arr[i] ≤ 10^12

Approach:
1. Create an empty stack.
2. Start from first bar, and do following for every bar ‘hist[i]’ where ‘i’ varies from 0 to n-1.
…..a) If stack is empty or hist[i] is higher than the bar at top of stack, then push ‘i’ to stack.
…..b) If this bar is smaller than the top of stack, then keep removing the top of stack while top of the stack is greater. Let the removed bar be hist[tp]. Calculate area of rectangle with hist[tp] as smallest bar. For hist[tp], the ‘left index’ is previous (previous to tp) item in stack and ‘right index’ is ‘i’ (current index).
3. If the stack is not empty, then one by one remove all bars from stack and do step 2.b for every removed bar.

Below is the implementation of the above approach:
*/

#include<bits/stdc++.h>
using namespace std;

vector<long long> nextSmallerToLeft(long long arr[], long long n){
    vector<long long> v;
    stack<long long> s;
    for(long long i=0; i<n; i++){
        if(s.empty()){
            v.push_back(-1);
        }
        else if(!s.empty() && arr[s.top()] < arr[i]){
            v.push_back(s.top());
        }
        else if(!s.empty() && arr[s.top()] >= arr[i]){
            while(!s.empty() && arr[s.top()] >= arr[i]){
                s.pop();
            }
            if(s.empty()){
                v.push_back(-1);
            }
            else{
                v.push_back(s.top());
            }
        }
        s.push(i);
    }
    return v;
}

vector<long long> nextSmallerToRight(long long arr[], long long n){
    vector<long long> v;
    stack<long long> s;
    for(long long i=n-1; i>=0; i--){
        if(s.empty()){
            v.push_back(n);
        }
        else if(!s.empty() && arr[s.top()] < arr[i]){
            v.push_back(s.top());
        }
        else if(!s.empty() && arr[s.top()] >= arr[i]){
            while(!s.empty() && arr[s.top()] >= arr[i]){
                s.pop();
            }
            if(s.empty()){
                v.push_back(n);
            }
            else{
                v.push_back(s.top());
            }
        }
        s.push(i);
    }
    reverse(v.begin(), v.end());
    return v;
}


long long getMaxArea(long long arr[], long long n)
{
    // Your code here
    vector<long long> left = nextSmallerToLeft(arr, n);
    vector<long long> right = nextSmallerToRight(arr, n);
    long long max_area = 0;
    for(long long i=0; i<n; i++){
        long long area = arr[i] * (right[i] - left[i] - 1);
        max_area = max(max_area, area);
    }
    return max_area;
}

long long getMaxArea2(long long arr[], long long n)
{
    // Your code here
    stack<long long> s;
    long long max_area = 0;
    long long i=0;
    while(i<n){
        if(s.empty() || arr[s.top()] <= arr[i]){
            s.push(i);
            i++;
        }
        else{
            long long top = s.top();
            s.pop();
            long long area = arr[top] * (s.empty() ? i : i-s.top()-1);
            max_area = max(max_area, area);
        }
    }
    while(!s.empty()){
        long long top = s.top();
        s.pop();
        long long area = arr[top] * (s.empty() ? i : i-s.top()-1);
        max_area = max(max_area, area);
    }

    return max_area;
}