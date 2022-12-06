/*
You are given an array, you have to find the kth maximum and minimum element in the array.
Constraints:
1 <= T <= 50
1 <= N <= 10^4
1 <= K <= N
-10^9 <= arr[i] <= 10^9


Input:
N = 5
arr[] = {1, 2, 3, 4, 5}
K = 2
Output: 4 2
Explanation: The 2nd maximum element is 4 and the 2nd minimum element is 2.

Input:
N = 7
arr[] = {2, 3, 1, 4, 6, 5, 7}
K = 3
Output: 5 3
Explanation: The 3rd maximum element is 5 and the 3rd minimum element is 3.

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
    int k;
    cin>>k;
    sort(arr, arr+n);
    cout<<arr[n-k]<<" "<<arr[k-1]<<"\n";
}