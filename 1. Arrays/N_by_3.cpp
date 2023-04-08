/*
Given an array of integers, each element occurs thrice in the array except one. Find that element.
*/

#include<bits/stdc++.h>
using namespace std;

int findElement(vector<int> &arr){
    int ans = 0;
    int n = arr.size();
    for(int i=0; i<32; i++){
        int count = 0;
        int element = 0;
        for(int j=0; j<n; j++){
            if((arr[j]>>i) & 1) count ++;
        }
        if(count%3==1){
            ans |= (1<<i);
        }
    }
    return ans;
}

int main(){
    vector<int> arr = {0,0,1,0};
    cout << findElement(arr) << endl;
    return 0;
}