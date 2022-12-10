/*
Given an array arr[] of N non-negative integers representing the height of blocks. If width of each block is 1, compute how much water can be trapped between the blocks during the rainy season. 
 

Example 1:

Input:
N = 6
arr[] = {3,0,0,2,0,4}
Output:
10
Explanation: 

Example 2:

Input:
N = 4
arr[] = {7,4,0,9}
Output:
10
Explanation:
Water trapped by above 
block of height 4 is 3 units and above 
block of height 0 is 7 units. So, the 
total unit of water trapped is 10 units.
Example 3:

Input:
N = 3
arr[] = {6,9,9}
Output:
0
Explanation:
No water will be trapped.

Approach: 
1. Find the maximum height of the bar from the left end upto an index i in the array left_max.
2. Find the maximum height of the bar from the right end upto an index i in the array right_max.
3. Iterate over the height array and update ans:
    Add min(max_left[i],max_right[i])−height[i] to ans

Time Complexity: O(N)
Space Complexity: O(N)

*/

#include <bits/stdc++.h>
using namespace std;

int trappingWater(int arr[], int n){
    int left[n];
    int right[n];
    int water = 0;
    left[0] = arr[0];
    for(int i = 1;i<n;i++){
        left[i] = max(left[i-1], arr[i]);
    }
    right[n-1] = arr[n-1];
    for(int i = n-2;i>=0;i--){
        right[i] = max(right[i+1], arr[i]);
    }
    for(int i = 0;i<n;i++){
        water += min(left[i], right[i]) - arr[i];
    }
    return water;
}

int main() {
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int a[n];
        for(int i = 0;i<n;i++){
            cin >> a[i];
        }
        cout << trappingWater(a, n) << endl;
    }
    return 0;
}

