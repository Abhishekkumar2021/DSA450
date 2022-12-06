/*
Given an array which consist of only 0, 1 and 2. Sort the array without using any sorting algo.
Input:
N = 5
arr[] = {0 2 1 2 0}
Output: 0 0 1 2 2
Explanation: 0s 1s and 2s are segregated

Input:
N = 3
arr[] = {0 1 0}
Output: 0 0 1

Input:
N = 4
arr[] = {1 2 0 1}
Output: 0 1 1 2

Constraints:
1 <= N <= 10^6
0 <= A[i] <= 2

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
    int low=0, mid=0, high=n-1;
    while(mid<=high){
        if(arr[mid]==0){
            swap(arr[low], arr[mid]) ;
            low++;
            mid++;
        }
        else if(arr[mid]==1){
            mid++;
        }
        else{
            swap(arr[mid], arr[high]);
            high--;
        }
    }
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
}

/*
Dry run -
Input:
N = 5
arr[] = {0 2 1 2 0}
Output: 0 0 1 2 2

low=0, mid=0, high=4
here, arr[mid] == 0 so swap(arr[low], arr[mid]) and increment low and mid
arr[] = {0 2 1 2 0}

low=1, mid=1, high=4
here, arr[mid] == 2 so swap(arr[mid], arr[high]) and decrement high
arr[] = {0 0 1 2 2}

low=1, mid=1, high=3
here, arr[mid] == 0 so swap(arr[low], arr[mid]) and increment low and mid
arr[] = {0 0 1 2 2}

low=2, mid=2, high=3
here, arr[mid] == 1 so increment mid
arr[] = {0 0 1 2 2}

low=2, mid=3, high=3
here, arr[mid] == 2 so decrement high
arr[] = {0 0 1 2 2}

low=2, mid=3, high=2
here, mid>high so break the loop
*/