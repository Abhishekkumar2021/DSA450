/*
You are given an array of integers. You need to print the array after shifting all the negative elements to the left side and positive elements to the right side. The order of positive and negative numbers need not to be maintained.

Input Format:
First line contains an integer N - the size of the array. The next line contains N integers - the elements of the array.

Constraints:
1 <= N <= 100000
-100000 <= A[i] <= 100000

Output Format
Print the array after shifting all the negative elements to the left side and positive elements to the right side.

Sample Input
5
-12 11 -13 -5 6
Sample Output
-12 -13 -5 11 6

Time Limit: 1 sec

*/

#include<bits/stdc++.h>
using namespace std;

void moveNegative(int arr[], int n){
    int j=0;
    for(int i=0;i<n;i++){
        if(arr[i]<0){
            swap(arr[i],arr[j]);
            j++;
        }
    }
}

void moveNegativeMaintainOrder(int arr[], int n){
    int j=0;
    for(int i=0;i<n;i++){
        if(arr[i]<0){
            if(i!=j){
                int temp = arr[i];
                for(int k=i;k>j;k--){
                    arr[k] = arr[k-1];
                } 
                arr[j] = temp;
            }
            j++;
        } 
    }
}

int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    moveNegative(arr,n);
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}
