/*
Given a string S. The task is to print all unique permutations of the given string in lexicographically sorted order.

 

Example 1:

Input: ABC
Output:
ABC ACB BAC BCA CAB CBA
Explanation:
Given string ABC has permutations in 6 
forms as ABC, ACB, BAC, BCA, CAB and CBA .
Example 2:

Input: ABSG
Output:
ABGS ABSG AGBS AGSB ASBG ASGB BAGS 
BASG BGAS BGSA BSAG BSGA GABS GASB 
GBAS GBSA GSAB GSBA SABG SAGB SBAG 
SBGA SGAB SGBA
Explanation:
Given string ABSG has 24 permutations.
 

Your Task:  
You don't need to read input or print anything. Your task is to complete the function find_permutaion() which takes the string S as input parameter and returns a vector of string in lexicographical order.

 

Expected Time Complexity: O(n! * n)

Expected Space Complexity: O(n)

Hint:
The idea is to fix one character at a time and recur for the remaining characters. 

*/

#include <bits/stdc++.h>
using namespace std;

void permute(string s, int idx,vector<string> &ans)
{
    if(idx==s.size())
    {
        ans.push_back(s);
        return;
    }
    for(int i=idx;i<s.size();i++)
    {
        swap(s[i],s[idx]);
        permute(s,idx+1,ans);
        swap(s[i],s[idx]);
    }
}

vector<string> find_permutation(string S)
{
    vector<string> ans;
    int idx = 0;
    permute(S,idx,ans);
    return ans;
}

int main()
{
    string input;
    cin >> input;
    vector<string> ans = find_permutation(input);
    for(auto i:ans)
        cout<<i<<" ";
    return 0;
}
