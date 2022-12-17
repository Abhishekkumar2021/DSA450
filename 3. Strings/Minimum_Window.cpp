/*
Given two strings S and P. Find the smallest window in the string S consisting of all the characters(including duplicates) of the string P.  Return "-1" in case there is no such window present. In case there are multiple such windows of same length, return the one with the least starting index. 

Example 1:

Input:
S = "timetopractice"
P = "toc"
Output: 
toprac
Explanation: "toprac" is the smallest
substring in which "toc" can be found.
Example 2:

Input:
S = "zoomlazapzo"
P = "oza"
Output: 
apzo
Explanation: "apzo" is the smallest 
substring in which "oza" can be found.
Your Task:
You don't need to read input or print anything. Your task is to complete the function smallestWindow() which takes two string S and P as input paramters and returns the smallest window in string S having all the characters of the string P. In case there are multiple such windows of same length, return the one with the least starting index. 

Expected Time Complexity: O(|S|)
Expected Auxiliary Space: O(1)

Constraints: 
1 ≤ |S|, |P| ≤ 10^5
*/
#include<bits/stdc++.h>
using namespace std;

class Solution
{
    public:
    //Function to find the smallest window in the string s consisting
    //of all the characters of string p.
    string smallestWindow (string s, string p)
    {
        // Your code here
        int freq[256]={0};
        int m = p.size();
        for(int i=0; i<m; i++){
            freq[p[i]]++;
        }
        int start = -1;
        int min_length = INT_MAX;
        int curr_count = 0;
        int curr_freq[256] = {0};
        int j = 0;
        for(int i=0; i<s.size(); i++){
            curr_freq[s[i]]++;

            if(curr_freq[s[i]] <= freq[s[i]]) curr_count++;
            
            if(curr_count == m){
                while(curr_freq[s[j]]>freq[s[j]]){
                    curr_freq[s[j]]--;
                    j++;
                } 
                int len = i - j + 1;
                if(len<min_length){
                    min_length = len;
                    start = j;
                }
            }
            
        }
        if(start == -1) return "-1";
        return s.substr(start, min_length);   
    }
};