/*
Given a string s, rearrange the characters of s so that any two adjacent characters are not the same.

Return any possible rearrangement of s or return "" if not possible.

 

Example 1:

Input: s = "aab"
Output: "aba"
Example 2:

Input: s = "aaab"
Output: ""
 

Constraints:

1 <= s.length <= 500
s consists of lowercase English letters.

Hint: 
1. Count the frequency of each character.
2. Sort the characters by frequency.
3. Add the most frequent character first, then the second most frequent character, and so on.
4. If the most frequent character has a frequency greater than (n+1)/2, then it is not possible to rearrange the string.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string reorganizeString(string s) {
        int n = s.size();
        vector<int> count(26, 0);
        for (char c : s) {
            count[c - 'a']++;
        }
        priority_queue<pair<int, char>> pq;
        for (int i = 0; i < 26; i++) {
            if (count[i] > 0) {
                pq.push({count[i], i + 'a'});
            }
        }
        string ans = "";
        while (pq.size() > 1) {
            /*
                Q. Why we are popping two elements and then pushing them back?
                A. Because we want to make sure that the most frequent character is not adjacent to itself.
            */
            auto p1 = pq.top();
            pq.pop();
            auto p2 = pq.top();
            pq.pop();
            ans += p1.second;
            ans += p2.second;
            if (--p1.first > 0) {
                pq.push(p1);
            }
            if (--p2.first > 0) {
                pq.push(p2);
            }
        }
        if (pq.size() > 0) {
            if(pq.top().first > 1)
                return "";
            else
                ans += pq.top().second;
        }
        
        return ans;
    }
};