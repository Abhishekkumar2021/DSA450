/*
Given an  of size N, and given an integer K, reverse the array from index K to N-1.
 
Input:
N = 5, K = 2
arr[] = {1, 2, 3, 4, 5}
Output: 1 2 5 4 3

Input:
N = 8, K = 4
arr[] = {1, 2, 3, 4, 5, 6, 7, 8}
Output: 1 2 3 4 8 7 6 5

Expected Time Complexity: O(N)
Expected Auxiliary Space: O(1)
*/

#include<bits/stdc++.h>
using namespace std;

int main(){
    int n, k;
    cin>>n>>k;
    int arr[n];
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    // Using standard library function
    reverse(arr+k, arr+n);

    // Without using standard library function
    int i=k, j=n-1;
    while(i<j){
        swap(arr[i], arr[j]);
        i++;
        j--;
    }

    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }
}
