/*
Given a string S, check if it is palindrome or not.

Example 1:
Input: S = "abba"
Output: 1
Explanation: S is a palindrome
*/

#include<bits/stdc++.h>
using namespace std;

bool isPalindromeUsingTwoPointer(string &str){
    int start = 0;
    int end = str.length()-1;
    while(start < end){
        if(str[start] != str[end]){
            return false;
        }
        start++;
        end--;
    }
    return true;
}

bool isPalindromeUsingRecursion(string &str, int start, int end){
    if(start >= end){
        return true;
    }
    if(str[start] != str[end]){
        return false;
    }
    return isPalindromeUsingRecursion(str, start+1, end-1);
}

bool isPalindromeUsingLoop(string &str){
    for(int i=0; i<str.length()/2; i++){
        if(str[i] != str[str.length()-i-1]){
            return false;
        }
    }
    return true;
}

bool isPalindromeUsingSTL(string &str){
    string rev = str;
    reverse(rev.begin(), rev.end());
    return (str == rev);
}

bool isPalindromeUsingStack(string &str){
    stack<char> st;
    for(int i=0; i<str.length(); i++){
        st.push(str[i]);
    }
    for(int i=0; i<str.length(); i++){
        if(str[i] != st.top()){
            return false;
        }
        st.pop();
    }
    return true;
}

int main(){
    string str = "abba";
    cout << isPalindromeUsingTwoPointer(str) << endl;
    str = "abba";
    cout << isPalindromeUsingRecursion(str, 0, str.length()-1) << endl;
    str = "abba";
    cout << isPalindromeUsingLoop(str) << endl;
    str = "abba";
    cout << isPalindromeUsingSTL(str) << endl;
    str = "abba";
    cout << isPalindromeUsingStack(str) << endl;
    return 0;
}