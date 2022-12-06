/*
Given an array Arr[] of size L and a number N, you need to write a program to find if there exists a pair of elements in the array whose difference is N.

Example 1:

Input:
L = 6, N = 78
arr[] = {5, 20, 3, 2, 5, 80}
Output: 1
Explanation: (2, 80) have difference of 78.
Example 2:

Input:
L = 5, N = 45
arr[] = {90, 70, 20, 80, 50}
Output: -1
Explanation: There is no pair with difference of 45.
Your Task:
You need not take input or print anything. Your task is to complete the function findPair() which takes array arr, size of the array L and N as input parameters and returns True if required pair exists, else return False.

Expected Time Complexity: O(L* Log(L)).
Expected Auxiliary Space: O(1).

Constraints:
1<=L<=10^4 
1<=Arr[i]<=10^5 

0<=N<=10^5
*/

#include<bits/stdc++.h>
using namespace std;
bool findPairUsingMap(int arr[], int size, int n){
    //code
    map<int, int> m;
    for(int i=0; i<size; i++){
        m[arr[i]]++;
    }
    for(int i=0; i<size; i++){
        if(n!=0 && arr[i]<=n && m.find(arr[i]+n)!=m.end()) return true;
        else if(n!=0 && m.find(arr[i]-n)!=m.end()) return true;
        else if(n==0 && m[arr[i]]>1) return true;
    }
    return false; 
}

bool findPairUsingSorting(int arr[], int size, int n){
    //code
    sort(arr, arr+size);
    int i=0, j=1;
    while(i<size && j<size){
        if(i!=j && arr[j]-arr[i]==n) return true;
        else if(arr[j]-arr[i]<n) j++;
        else i++;
    }
    return false;
}

int main(){
    int n, k;
    cin >> n >> k;
    int arr[n];
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    cout << findPairUsingMap(arr, n, k) << endl;
    cout << findPairUsingSorting(arr, n, k) << endl;
}
