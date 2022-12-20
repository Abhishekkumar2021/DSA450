/*
Given a string S with repeated characters. The task is to rearrange characters in a string such that no two adjacent characters are the same.
Note: The string has only lowercase English alphabets and it can have multiple solutions. Return any one of them.

Example 1:

Input : str = "geeksforgeeks"
Output: 1
Explanation: All the repeated characters of the
given string can be rearranged so that no 
adjacent characters in the string is equal.
Any correct rearrangement will show a output
of 1.
Example 2:

Input : str = "bbbbb"
Output: 0
Explanation: Repeated characters in the string
cannot be rearranged such that there should not
be any adjacent repeated character.
Your task :
You don't have to read input or print anything. Your task is to complete the functionrearrangeString() which takes the string as input and returns the modified string. If the string cannot be modified return "-1".
Note:The generatedoutput is 1 if the string is successfully rearranged and is 0 if rearranging is not possible.
 
Expected Time Complexity : O(NlogN), N = length of String
Expected Auxiliary Space : O(number of english alphabets)
 
Constraints :
1 <= length of string <= 104
*/

#include<bits/stdc++.h>
using namespace std;

int rearrangeString(string str){
    // Your code here
    int n = str.length();
    int freq[26] = {0};
    for(int i=0;i<n;i++){
        freq[str[i]-'a']++;
    }
    priority_queue<pair<int,char>> pq;
    for(int i=0;i<26;i++){
        if(freq[i]>0){
            pq.push({freq[i],i+'a'});
        }
    }
    string ans = "";
    pair<int,char> prev = {-1,'#'};
    while(!pq.empty()){
        pair<int,char> curr = pq.top();
        pq.pop();
        ans += curr.second;
        if(prev.first>0){
            pq.push(prev);
        }
        curr.first--;
        prev = curr;
    }
    if(ans.length()==n){ 
        return 1;
    }
    return 0;
}