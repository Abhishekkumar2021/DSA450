/*
Given an array of integers, every element appears twice except for two elements which appear once. Find those two elements.
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> f(vector<int> arr){
    int n = arr.size();
    int x = 0;
    for(int i=0; i<n; i++){
        x = x ^ arr[i];
    }

    int pos = 0;
    while((x & 1) != 1){
        pos++;
        x = x >> 1;
    }

    int mask = 1 << pos;

    int first = 0;
    for(int i=0; i<n; i++){
        if((arr[i] & mask) > 0){
            first = first ^ arr[i];
        }
    }
    int second = first ^ x;
    vector<int> ans;
    ans.push_back(first);
    ans.push_back(second);
}

int main(){
    vector<int> arr = {1, 2, 3, 2, 3, 1, 5, 7};
    vector<int> ans = f(arr);
    for(int i=0; i<ans.size(); i++){
        cout << ans[i] << " ";
    }
    return 0;
}