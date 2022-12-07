/*
Given an array of positive and negative numbers. Find if there is a subarray (of size at-least one) with 0 sum.

Example 1:

Input:
5
4 2 -3 1 6

Output: 
Yes

Explanation: 
2, -3, 1 is the subarray 
with sum 0.
Example 2:

Input:
5
4 2 0 1 6

Output: 
Yes

Explanation: 
0 is one of the element 
in the array so there exist a 
subarray with sum 0.
*/

#include<bits/stdc++.h>
using namespace std;

bool subArrayExists(int arr[], int n)
{
    //Your code here
    int sum[n] = {0};
    sum[0] = arr[0];
    
    for(int i=1; i<n; i++) sum[i] = arr[i] + sum[i-1];
    map<int, int> m;
    m.insert({0, -1});
    for(int i=0; i<n; i++){
        if(m.find(sum[i])!=m.end()) return true;
        else m.insert({sum[i], i});
    }
    return false;
    
}

bool subArrayExists2(int arr[], int n)
{
    //Your code here
    int sum = 0;
    map<int, int> m;
    m.insert({0, -1});
    for(int i=0; i<n; i++){
        sum += arr[i];
        if(m.find(sum)!=m.end()) return true;
        else m.insert({sum, i});
    }
    return false;
}

int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0; i<n; i++) cin>>arr[i];
    cout<<subArrayExists(arr, n);
    return 0;
}