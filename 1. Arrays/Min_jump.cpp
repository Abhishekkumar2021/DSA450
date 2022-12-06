/*
Given an array of N integers arr[] where each element represents the max length of the jump that can be made forward from that element. Find the minimum number of jumps to reach the end of the array (starting from the first element). If an element is 0, then you cannot move through that element.

Note: Return -1 if you can't reach the end of the array.


Example 1:

Input:
N = 11 
arr[] = {1, 3, 5, 8, 9, 2, 6, 7, 6, 8, 9} 
Output: 3 
Explanation:  
First jump from 1st element to 2nd 
element with value 3. Now, from here 
we jump to 5th element with value 9, 
and from here we will jump to the last. 
Example 2:

Input :
N = 6
arr = {1, 4, 3, 2, 6, 7}
Output: 2 
Explanation: 
First we jump from the 1st to 2nd element 
and then jump to the last element.

Expected Time Complexity: O(N)
Expected Space Complexity: O(1)
*/

#include<bits/stdc++.h>
using namespace std;

int getMinJumps(int arr[], int n){
    if(n==1) 
        return 0;
    if(arr[0]==0)
        return -1;
    int jumps = 0; // number of jumps
    int maxReach = arr[0]; // max reach of current jump
    int steps = arr[0]; // steps left in current jump
    for(int i = 1; i < n; i++){
        if(i == n - 1){
            jumps++;
            break;
        }
        maxReach = max(maxReach, i + arr[i]);
        steps--;
        if(steps == 0){
            jumps++;
            if(i >= maxReach){
                return -1;
            }
            steps = maxReach - i;
        }
    }
    return jumps;
}

int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cout<<getMinJumps(arr,n)<<endl;
}

/*
Approach:
The idea is to use greedy approach. We start from the first element and we keep on jumping as far as we can. We keep on updating the farthest we can reach. If we reach the end or the farthest we can reach is 0, then we return the number of jumps required. If we are not able to reach the end after the complete traversal, then we return -1. 

Time Complexity: O(N)
Space Complexity: O(1)

Understand the code:
1. If the length of the array is 1, then the number of jumps required is 0.
2. If the first element is 0, then we cannot move forward and we return -1.
3. We initialize the number of jumps as 0, the maximum reach as the value of the first element and the steps left in the current jump as the value of the first element.
4. We start traversing the array from the second element.
5. If we have reached the end of the array, we increment the number of jumps and break out of the loop.
6. We update the maximum reach. The maximum reach is the maximum of the current maximum reach and the sum of the current element and the index of the current element.
7. We decrement the steps left in the current jump as we have used a step to reach the current element.
8. If no more steps are left (i.e. steps=0), then we must have used a jump. So, we increment the number of jumps.
9. If the current maxReach is less than or equal to the current index, then it is not possible to reach the end from here hence we return -1.
10. We initialize the steps to the maximum reach minus the current index as the number of steps to reach the maximum index from the current index.
11. If we have not reached the end of the array, we repeat the steps from 5 to 10.
*/


 


