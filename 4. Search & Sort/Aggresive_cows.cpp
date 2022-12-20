/*
Given an array of length ‘N’, where each element denotes the position of a stall. Now you have ‘N’ stalls and an integer ‘K’ which denotes the number of cows that are aggressive. To prevent the cows from hurting each other, you need to assign the cows to the stalls, such that the minimum distance between any two of them is as large as possible. Return the largest minimum distance.
Eg

array: 1,2,4,8,9  &  k=3
O/P: 3
Explaination: 1st cow at stall 1 , 2nd cow at stall 4 and 3rd cow at stall 8

Hint: Binary Search

Approach:
1.  Sort the array
2.  Find the minimum distance between any two cows
3.  Find the maximum distance between any two cows
4.  Apply binary search on the range of minimum and maximum distance
5.  Check if the current distance is possible or not
6.  If possible, then check if the current distance is greater than the previous distance
7.  If yes, then update the previous distance
8.  If not, then check for the next distance
9.  If not possible, then check for the next distance
10. Return the previous distance

*/

#include <bits/stdc++.h>
using namespace std;

bool isPossible(int arr[], int n, int k, int mid){
    int cnt = 1;
    int last = arr[0];
    for(int i=1; i<n; i++){
        if(arr[i]-last>=mid){
            cnt++;
            last = arr[i];
        }
        if(cnt==k) return true;
    }
    return false;
}

int solve(int arr[], int n, int k){
    sort(arr, arr+n);
    int minDist = INT_MAX;
    int maxDist = arr[n-1]-arr[0];
    for(int i=1; i<n; i++){
        minDist = min(minDist, arr[i]-arr[i-1]);
    }
    int ans = 0;
    int low = minDist;
    int high = maxDist;
    while(low<=high){
        int mid = (low+high)/2;
        if(isPossible(arr, n, k, mid)){
            ans = mid;
            low = mid+1;
        }
        else{
            high = mid-1;
        }
    }
    return ans;
}

int main() {
    int arr[] = {1,2,4,8,9};
    int n = sizeof(arr)/sizeof(arr[0]);
    int k = 3;
    cout<<solve(arr, n, k);
    return 0;
}