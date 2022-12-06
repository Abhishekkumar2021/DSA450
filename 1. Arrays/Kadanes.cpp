/*  
You are given an array, You need to find the maximum sum of a subarray. A subarray is a contiguous part of the array.
Input Format:
First line contains an integer N - the size of the array. The next line contains N integers - the elements of the array.
Constraints:
1 <= N <= 100000
-100000 <= A[i] <= 100000
Output Format
Print the maximum sum of a subarray.
Sample Input
5
1 2 3 -2 5
Sample Output
9
Time Limit: 1 sec
*/

#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int maxSum = INT_MIN, currSum = 0;
    for(int i=0;i<n;i++){
        currSum += arr[i];
        if(currSum>maxSum){
            maxSum = currSum;
        }
        if(currSum<0){
            currSum = 0;
        }
    }
}