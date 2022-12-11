/*
Given a string s and two strings a, b check if s is a valid shuffle of a and b.
Example 1:
Input: s = "XY", a = "X", b = "Y"
Output: 1
Explanation: s is a valid shuffle of a and b.

Example 2:
Input: s = "XXY", a = "XXZ", b = "XXY"
Output: 0
Explanation: s is not a valid shuffle of a and b.

*/

#include<bits/stdc++.h>
using namespace std;

bool isValidShuffle(string s, string a, string b){
    if(s.length() != a.length() + b.length())
        return false;
    unordered_map<char, int> mp;
    for(int i = 0; i < s.length(); i++)
        mp[s[i]]++;
    for(int i = 0; i < a.length(); i++)
        mp[a[i]]--;
    for(int i = 0; i < b.length(); i++)
        mp[b[i]]--;
    for(auto i : mp)
        if(i.second != 0)
            return false;
    return true;
}