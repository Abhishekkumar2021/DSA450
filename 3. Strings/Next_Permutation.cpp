/*
Implement the next permutation, which rearranges the list of numbers into Lexicographically next greater permutation of list of numbers. If such arrangement is not possible, it must be rearranged to the lowest possible order i.e. sorted in an ascending order. You are given an list of numbers arr[ ] of size N.

Example 1:

Input: N = 6
arr = {1, 2, 3, 6, 5, 4}
Output: {1, 2, 4, 3, 5, 6}
Explaination: The next permutation of the 
given array is {1, 2, 4, 3, 5, 6}.
Example 2:

Input: N = 3
arr = {3, 2, 1}
Output: {1, 2, 3}
Explaination: As arr[] is the last 
permutation. So, the next permutation 
is the lowest one.
Your Task:
You do not need to read input or print anything. Your task is to complete the function nextPermutation() which takes N and arr[ ] as input parameters and returns a list of numbers containing the next permutation.

Expected Time Complexity: O(N)
Expected Auxiliary Space: O(1)

Constraints:
1 ≤ N ≤ 10000

Hint:
1. Start from the right most digit and find the first digit that is smaller than the digit next to it.
2. Now find the smallest digit on right side of (i-1)'th digit that is greater than number[i-1]
3. Swap the above found two digits, and sort the digits after (i-1) in ascending order.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
    vector<int> nextPermutation(int n, vector<int> arr){
        int i=n-1;
        while(i>0 && arr[i-1]>=arr[i]) i--;
        if(i==0){
            reverse(arr.begin(),arr.end());
            return arr;
        }
        int j=n-1;
        while(arr[j]<=arr[i-1]) j--;
        swap(arr[i-1],arr[j]);
        reverse(arr.begin()+i,arr.end());
        return arr;
    }
};