/*
Given an array of N integers, and an integer K, find the number of pairs of elements in the array whose sum is equal to K.

Input:
The first line of input contains an integer T denoting the number of test cases. Then T test cases follow. Each test case contains two integers N and K denoting the size of the array and the sum respectively. The next line contains N space separated integers denoting the elements of the array.

Output:
Print the number of pairs of elements in the array whose sum is equal to the K.

Constraints:
1<=T<=100
1<=N<=100000
1<=K<=1000
1<=A[i]<=1000

*/

#include<bits/stdc++.h>
using namespace std;

int getCountUsingMap(int arr[],int n,int k){
    unordered_map<int,int> m;
    int count = 0;
    for(int i=0;i<n;i++){
        if(m.find(k-arr[i])!=m.end()){
            count+=m[k-arr[i]];
        }
        m[arr[i]]++;
    }
    return count;
}

// This assumes that no element is repeated in the array
int getCountUsingTwoPointer(int arr[],int n,int k){
    sort(arr,arr+n);
    int count = 0;
    int i=0,j=n-1;
    while(i<j){
        if(arr[i]+arr[j]==k){
            count++;
            i++;
            j--;
        }
        else if(arr[i]+arr[j]>k){
            j--;
        }
        else{
            i++;
        }
    }
    return count;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        int n,k;
        cin>>n>>k;
        int arr[n];
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        cout<<getCountUsingMap(arr,n,k)<<endl;
    }
}