/*
Given an array of strings, return all groups of strings that are anagrams. The groups must be created in order of their appearance in the original array. Look at the sample case for clarification.

Note: The final output will be in lexicographic order.


Example 1:

Input:
N = 5
words[] = {act,god,cat,dog,tac}
Output:
act cat tac 
god dog
Explanation:
There are 2 groups of
anagrams "god", "dog" make group 1.
"act", "cat", "tac" make group 2.
Example 2:

Input:
N = 3
words[] = {no,on,is}
Output: 
is
no on
Explanation:
There are 2 groups of
anagrams "is" makes group 1.
"no", "on" make group 2.

Your Task:
The task is to complete the function Anagrams() that takes a list of strings as input and returns a list of groups such that each group consists of all the strings that are anagrams.


Expected Time Complexity: O(N*|S|*log|S|), where |S| is the length of the strings.
Expected Auxiliary Space: O(N*|S|), where |S| is the length of the strings.


Constraints:
1<=N<=100

1<= |S|<=10

Hint:
1. Create a map of string and vector of strings. The string will be the sorted version of the string in the vector. The vector will contain all the strings that are anagrams of each other.
*/


#include <bits/stdc++.h>
using namespace std;

class Solution{
    public:
    vector<vector<string>> Anagrams(vector<string>& string_list) 
    {
        // Your Code Here
        vector<vector<string>> res;
        unordered_map<string, vector<string>> mp;
        for(auto s: string_list){
            string temp = s;
            sort(temp.begin(), temp.end());
            mp[temp].push_back(s);
        }
        for(auto it: mp){
            res.push_back(it.second);
        }
        return res;
    }
};

