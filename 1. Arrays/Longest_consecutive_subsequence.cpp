/*
Given an array of positive integers. Find the length of the longest sub-sequence such that elements in the subsequence are consecutive integers, the consecutive numbers can be in any order.
 

Example 1:

Input:
N = 7
a[] = {2,6,1,9,4,5,3}
Output:
6
Explanation:
The consecutive numbers here
are 1, 2, 3, 4, 5, 6. These 6 
numbers form the longest consecutive
subsquence.
Example 2:

Input:
N = 7
a[] = {1,9,3,10,4,20,2}
Output:
4
Explanation:
1, 2, 3, 4 is the longest
consecutive subsequence.
*/

#include<bits/stdc++.h>
using namespace std;

int getLongestConsecutive(vector<int> arr){
    int n = arr.size();
    sort(arr.begin(), arr.end());
    int ans = 0;
    int count = 1;
    for(int i=1; i<n; i++){
        if(arr[i] == arr[i-1]) continue;
        if(arr[i] == arr[i-1]+1){
            count++;
        }
        else{
            ans = max(ans, count);
            count = 1;
        }
    }
    ans = max(ans, count);
    return ans;
}

int getLongestUsingSet(vector<int> arr){
    int n = arr.size();
    unordered_set<int> s;
    for(int i=0; i<n; i++){
        s.insert(arr[i]);
    }
    int ans = 0;
    for(int i=0; i<n; i++){
        if(s.find(arr[i]-1) == s.end()){
            int j = arr[i];
            while(s.find(j) != s.end()){
                j++;
            }
            ans = max(ans, j-arr[i]);
        }
    }
}

int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    cout<<getLongestConsecutive(arr)<<endl;
    return 0;
}