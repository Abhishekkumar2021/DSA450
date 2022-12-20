/*
Given an array of n distinct elements. Find the minimum number of swaps required to sort the array in strictly increasing order.


Example 1:

Input:
nums = {2, 8, 5, 4}
Output:
1
Explaination:
swap 8 with 4.
Example 2:

Input:
nums = {10, 19, 6, 3, 5}
Output:
2
Explaination:
swap 10 with 3 and swap 19 with 5.

Your Task:
You do not need to read input or print anything. Your task is to complete the function minSwaps() which takes the nums as input parameter and returns an integer denoting the minimum number of swaps required to sort the array. If the array is already sorted, return 0. 


Expected Time Complexity: O(nlogn)
Expected Auxiliary Space: O(n)


Constraints:
1 ≤ n ≤ 10^5
1 ≤ numsi ≤ 10^6

Hint:
1. Sort the array and store the original index of each element in a map.
2. Now traverse the array and check if the element is at its correct position or not. If not, then swap it with the element at its correct position and increment the count of swaps.
*/

#include<bits/stdc++.h>
using namespace std;

int minSwaps(vector<int>&nums){
    int n = nums.size();
    vector<int> temp = nums;
    sort(temp.begin(), temp.end());
    unordered_map<int, int> mp;
    for(int i = 0; i < n; i++){
        mp[temp[i]] = i;
    }
    int ans = 0;
    int i=0;
    while(i<n){
        if(nums[i] != temp[i]){
            ans++;
            int correctIndex = mp[nums[i]];
            swap(nums[i], nums[correctIndex]);
        }
        else{
            i++;
        }
    }
    return ans;
}