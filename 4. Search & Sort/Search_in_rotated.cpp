/*
There is an integer array nums sorted in ascending order (with distinct values).

Prior to being passed to your function, nums is possibly rotated at an unknown pivot index k (1 <= k < nums.length) such that the resulting array is [nums[k], nums[k+1], ..., nums[n-1], nums[0], nums[1], ..., nums[k-1]] (0-indexed). For example, [0,1,2,4,5,6,7] might be rotated at pivot index 3 and become [4,5,6,7,0,1,2].

Given the array nums after the possible rotation and an integer target, return the index of target if it is in nums, or -1 if it is not in nums.

You must write an algorithm with O(log n) runtime complexity.

 

Example 1:

Input: nums = [4,5,6,7,0,1,2], target = 0
Output: 4
Example 2:

Input: nums = [4,5,6,7,0,1,2], target = 3
Output: -1
Example 3:

Input: nums = [1], target = 0
Output: -1
 

Constraints:

1 <= nums.length <= 5000
-104 <= nums[i] <= 104
All values of nums are unique.
nums is an ascending array that is possibly rotated.
-104 <= target <= 10^4

Hint:
1. Think about how you would solve the problem in non-rotated sorted array.
2. Combine that solution with the condition that nums is rotated.

Approach:
1. Find the pivot element
Question: How to find the pivot element?
Answer: The pivot element is the element which is greater than the next element. If there is no pivot element, then the array is not rotated.

2. Apply binary search on the two subarrays

*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int pivot = -1;
        for(int i=0; i<n-1; i++){
            if(nums[i]>nums[i+1]){
                pivot = i;
                break;
            }
        }
        if(pivot==-1){
            return binarySearch(nums, 0, n-1, target);
        }
        if(nums[pivot]==target) return pivot;
        if(target>=nums[0]) return binarySearch(nums, 0, pivot-1, target);
        return binarySearch(nums, pivot+1, n-1, target);
    }
    
    int binarySearch(vector<int>& nums, int l, int r, int target){
        while(l<=r){
            int mid = l + (r-l)/2;
            if(nums[mid]==target) return mid;
            else if(nums[mid]>target) r = mid-1;
            else l = mid+1;
        }
        return -1;
    }
};