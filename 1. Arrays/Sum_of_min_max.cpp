/*
You are given an array, and you need to find the sum of minimum and maximum elements in the array.
Input:
N = 5
arr[] = {1, 2, 3, 4, 5}
Output: 6
Explanation: The minimum element is 1 and the maximum element is 5. Their sum is 6.

Input:
N = 7
arr[] = {2, 3, 1, 4, 6, 5, 7}
Output: 8
Explanation: The minimum element is 1 and the maximum element is 7. Their sum is 8.

Expected Time Complexity: O(N)
Expected Auxiliary Space: O(1)
*/

#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    // without using standard library function
    int mini = arr[0], maxi = arr[0];
    for(int i=0; i<n; i++){
        mini = min(mini, arr[i]);
        maxi = max(maxi, arr[i]);
    }
    cout<<mini+maxi<<"\n";

    // using standard library function
    cout<<*min_element(arr, arr+n) + *max_element(arr, arr+n)<<"\n";
}