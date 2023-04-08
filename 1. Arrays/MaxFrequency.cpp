/*
Given an array of integers, one element is having a frequency of greater then N/2 find such element.
Moor's Voting Algorithm
*/

#include<bits/stdc++.h>
using namespace std;

int getMax(vector<int> &arr){
    int element = arr[0];
    int count = 1;
    int n = arr.size();
    for(int i=1; i<n; i++){
        if(element == arr[i]) count++;
        else count--;
        if(count == 0){
            element = arr[i];
            count = 1;
        }
    }
    if(count <= 0) return -1;
    int ans = 0;
    for(int i=0; i<n; i++) if(arr[i] == element) ans++;
    if(ans>=n/2) return element;
    return -1; 
}

int main(){
    vector<int> arr = {1,2,3,4,4,4,4,5,6,4,2};
    cout << getMax(arr) << endl;
}