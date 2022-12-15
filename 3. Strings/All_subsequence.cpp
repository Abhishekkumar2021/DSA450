/*
You are given a string s. You need to print all the possible subsequences of the given string.
Example 1:
Input: abc
Output: a ab abc ac b bc c
Explanation: There are 7 subsequences of string abc.

Example 2:
Input: abbc
Output: a ab abb abbc abc ac bbc b bc c
Explanation: There are 13 subsequences of string abbc.
*/

#include <bits/stdc++.h>
using namespace std;

void printSubsequence(string input, string output)
{
    if (input.empty())
    {
        cout << output << " ";
        return;
    }
    printSubsequence(input.substr(1), output);
    printSubsequence(input.substr(1), output + input[0]);
}

void getUniqueSubsequence(string input, string output, unordered_set<string> &s)
{
    if (input.empty())
    {
        s.insert(output);
        return;
    }
    getUniqueSubsequence(input.substr(1), output, s);
    getUniqueSubsequence(input.substr(1), output + input[0], s);
}

int main()
{
    string input;
    cin >> input;
    string output = "";
    printSubsequence(input, output);
    cout << endl;
    unordered_set<string> s;
    getUniqueSubsequence(input, output, s);
    for (auto i : s)
        cout << i << " ";
    return 0;
}