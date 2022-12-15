/*
Write a function to find the longest common prefix string amongst an array of strings.

If there is no common prefix, return an empty string "".

 

Example 1:

Input: strs = ["flower","flow","flight"]
Output: "fl"
Example 2:

Input: strs = ["dog","racecar","car"]
Output: ""
Explanation: There is no common prefix among the input strings.
 

Constraints:

1 <= strs.length <= 200
0 <= strs[i].length <= 200
strs[i] consists of only lowercase English letters.

Hint:
Vertical scanning OR Using Trie

*/

#include<bits/stdc++.h>
using namespace std;

class TrieNode{
public:
    TrieNode* children[26];
    bool isEnd;
    TrieNode(){
        for(int i = 0; i < 26; i++)
            children[i] = NULL;
        isEnd = false;
    }
};

class Trie{
public:
    TrieNode* root;
    Trie(){
        root = new TrieNode();
    }
    void insert(string s){
        TrieNode* curr = root;
        for(int i = 0; i < s.size(); i++){
            int index = s[i] - 'a';
            if(curr->children[index] == NULL)
                curr->children[index] = new TrieNode();
            curr = curr->children[index];
        }
        curr->isEnd = true;
    }
    string longestCommonPrefix(){
        TrieNode* curr = root;
        string ans = "";
        while(curr != NULL){
            int count = 0;
            int index = -1;
            for(int i = 0; i < 26; i++){
                if(curr->children[i] != NULL){
                    count++;
                    index = i;
                }
            }
            if(count == 1 && curr->isEnd == false){
                ans += (char)(index + 'a');
                curr = curr->children[index];
            }
            else
                break;
        }
        return ans;
    }
};

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        Trie* trie = new Trie();
        for(int i = 0; i < strs.size(); i++)
            trie->insert(strs[i]);
        return trie->longestCommonPrefix();
    }
};