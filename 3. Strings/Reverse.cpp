/*
Given a string str, the task is to reverse the string str.
*/

#include<bits/stdc++.h>
using namespace std;

void reverseUsingStack(string &str){
    stack<char> st;
    for(int i=0; i<str.length(); i++){
        st.push(str[i]);
    }
    for(int i=0; i<str.length(); i++){
        str[i] = st.top();
        st.pop();
    }
}

void reverseUsingRecursion(string &str, int start, int end){
    if(start >= end){
        return;
    }
    swap(str[start], str[end]);
    reverseUsingRecursion(str, start+1, end-1);
}

void reverseUsingTwoPointer(string &str){
    int start = 0;
    int end = str.length()-1;
    while(start < end){
        swap(str[start], str[end]);
        start++;
        end--;
    }
}

void reverseUsingSTL(string &str){
    reverse(str.begin(), str.end());
}

void reverseUsingLoop(string &str){
    for(int i=0; i<str.length()/2; i++){
        swap(str[i], str[str.length()-i-1]);
    }
}

int main(){
    string str = "GeeksforGeeks";
    reverseUsingStack(str);
    cout << str << endl;
    str = "GeeksforGeeks";
    reverseUsingRecursion(str, 0, str.length()-1);
    cout << str << endl;
    str = "GeeksforGeeks";
    reverseUsingTwoPointer(str);
    cout << str << endl;
    str = "GeeksforGeeks";
    reverseUsingSTL(str);
    cout << str << endl;
    str = "GeeksforGeeks";
    reverseUsingLoop(str);
    cout << str << endl;
    return 0;
}

