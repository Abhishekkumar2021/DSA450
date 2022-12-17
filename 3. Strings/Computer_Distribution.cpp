/*
Mr. X runs an internet cafe which has 'K' computers. His internet cafe has 'N' customers who can come anytime throughout the day. Initially, all the 'K' computers are available for customer use. When a customer enters the cafe he first checks whether any available computer is there. If he finds one he starts using it and it is marked unavailable. When he leaves the cafe that computer is again marked as available. If the customer is not able to find any available computer he leaves the cafe immediately.
You are given an integer array 'ARR' in which each value occurs exactly 2 times, the index of the first occurrence of any value denotes the arrival time of the customer while the second occurrence denotes the departing time of the customer. Your task is to find the no. of customers who were not able to find any available computer and had to leave the cafe immediately.

Example 1:
Input:
arr = [1,2,3,2,3,1], N=3, K=2

Output:
1 comes -> get a computer
2 comes -> get a computer
3 comes -> no computer available
2 leaves -> computer available = 1
3 leaves -> no effect
1 leaves -> computer available = 2

Ans = 1
*/

#include <bits/stdc++.h>
using namespace std;

int countCustomers(vector<int> &arr, int k)
{
    //    Write your code here
    int n = arr.size();
    int cnt = 0;
    unordered_map<int,int> m;
    for(int i=0; i<n; i++){
        if(m[arr[i]]==-1) cnt++;
        else if(m[arr[i]]==0){
            if(k>0){
                k--;
                m[arr[i]] = 1;
            } 
            else{
                m[arr[i]] = -1;
            } 
        }
        else if(m[arr[i]]==1){
            m[arr[i]] = 0;
            k++;
        }
    }
    return cnt;
}
