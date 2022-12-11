/*
Given a string S, find the longest palindromic substring in S. Substring of string S: S[ i . . . . j ] where 0 ≤ i ≤ j < len(S). Palindrome string: A string which reads the same backwards. More formally, S is palindrome if reverse(S) = S. Incase of conflict, return the substring which occurs first ( with the least starting index).


Example 1:

Input:
S = "aaaabbaa"
Output: aabbaa
Explanation: The longest Palindromic
substring is "aabbaa".
Example 2:

Input: 
S = "abc"
Output: a
Explanation: "a", "b" and "c" are the 
longest palindromes with same length.
The result is the one with the least
starting index.

Your Task:
You don't need to read input or print anything. Your task is to complete the function longestPalin() which takes the string S as input and returns the longest palindromic substring of S.


Expected Time Complexity: O(|S|2).
Expected Auxiliary Space: O(1).


Constraints:
1 ≤ |S| ≤ 10^3

Hint:
1. The idea is to generate all even length and odd length palindromes and keep track of the longest palindrome seen so far.
2. To generate odd length palindrome, fix a centre and expand in both directions for longer palindromes.
3. To generate even length palindrome, fix two centre ( low and high ) and expand in both directions for longer palindromes.

*/

#include<bits/stdc++.h>
using namespace std;

string longestPalin (string s) {
    int n = s.length();
    int start = 0, end = 0;
    for(int i = 0; i < n; i++){
        int l = i, r = i;
        while(l >= 0 && r < n && s[l] == s[r]){
            if(r - l > end - start){
                start = l;
                end = r;
            }
            l--;
            r++;
        }
        l = i, r = i + 1;
        while(l >= 0 && r < n && s[l] == s[r]){
            if(r - l > end - start){
                start = l;
                end = r;
            }
            l--;
            r++;
        }
    }
    return s.substr(start, end - start + 1);
}