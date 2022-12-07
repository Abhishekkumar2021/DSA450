/*
Given an array Arr[] that contains N integers (may be positive, negative or zero). Find the product of the maximum product subarray.

Example 1:

Input:
N = 5
Arr[] = {6, -3, -10, 0, 2}
Output: 180
Explanation: Subarray with maximum product
is [6, -3, -10] which gives product as 180.
Example 2:

Input:
N = 6
Arr[] = {2, 3, 4, 5, -1, 0}
Output: 120
Explanation: Subarray with maximum product
is [2, 3, 4, 5] which gives product as 120.

Hint: The idea is to traverse the array. While traversing, keep track of the maximum product value ending at the current position (max_ending_here). Also keep track of the minimum product value ending at the current position (min_ending_here). These values are maintained separately because the product of a negative number with a negative number is positive. Below is the algorithm to find the maximum product subarray.

Traverse the array. For every element in the array, maintain the maximum product ending at the current position (max_ending_here). Update this maximum product by multiplying it with the current element. If the current element is zero, then the maximum product cannot end here, make it 1. Compare this value with the maximum product calculated so far and update the maximum product accordingly (max_so_far). This is done to handle the case when the array has all positive integers. If the current element is negative, then the minimum product ending at the current position (min_ending_here) could be either the current element or the product of the current element and the previous minimum product ending at the current position. Update this minimum product accordingly. Compare the updated minimum product with the maximum product calculated so far and update the maximum product accordingly (max_so_far).


*/

#include<bits/stdc++.h>
using namespace std;

int maxProduct(int *arr, int n) {
    // code here
    int max_ending_here = 1;
    int min_ending_here = 1;
    int max_so_far = 1;
    for(int i=0; i<n; i++){
        if(arr[i]>0){
            max_ending_here *= arr[i];
            min_ending_here = min(min_ending_here*arr[i], 1);
        }
        else if(arr[i]==0){
            max_ending_here = 1;
            min_ending_here = 1;
        }
        else{
            int temp = max_ending_here;
            max_ending_here = max(min_ending_here*arr[i], 1);
            min_ending_here = temp*arr[i];
        }
        if(max_so_far<max_ending_here) max_so_far = max_ending_here;
    }
    return max_so_far;
}

int main(){
    int arr[] = {6, -3, -10, 0, 2};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout<<maxProduct(arr, n)<<endl;
    return 0;
}