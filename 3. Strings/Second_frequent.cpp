/*
Given a sequence of strings, the task is to find out the second most repeated (or frequent) string in the given sequence.

Note: No two strings are the second most repeated, there will be always a single string.

Example 1:

Input:
N = 6
arr[] = {aaa, bbb, ccc, bbb, aaa, aaa}
Output: bbb
Explanation: "bbb" is the second most 
occurring string with frequency 2.

â€‹Example 2:

Input: 
N = 6
arr[] = {geek, for, geek, for, geek, aaa}
Output: for
Explanation: "for" is the second most
occurring string with frequency 2.

Your Task:
You don't need to read input or print anything. Your task is to complete the function secFrequent() which takes the string array arr[] and its size N as inputs and returns the second most frequent string in the array.


Expected Time Complexity: O(N*max(|Si|).
Expected Auxiliary Space: O(N*max(|Si|).


Constraints:
1<=N<=10^3
*/

#include<bits/stdc++.h>
using namespace std;

string secFrequent(string arr[], int n){
    unordered_map<string, int> mp;
    for(int i = 0; i < n; i++)
        mp[arr[i]]++;
    int max1 = INT_MIN, max2 = INT_MIN;
    string ans1, ans2;
    for(auto it : mp){
        if(it.second > max1){
            max2 = max1;
            ans2 = ans1;
            max1 = it.second;
            ans1 = it.first;
        }
        else if(it.second > max2){
            max2 = it.second;
            ans2 = it.first;
        }
    }
    return ans2;
}