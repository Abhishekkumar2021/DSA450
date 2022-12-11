/*
Given two strings a, b check if a is a rotation of b.
Example 1:
Input: a = "ABCD", b = "CDAB"
Output: 1
Explanation: a is a rotation of b.

*/

#include<bits/stdc++.h>
using namespace std;

int isRotation(string a, string b){
    if(a.length() != b.length())
        return 0;
    string temp = a + a;
    if(temp.find(b) != string::npos)
        return 1;
    return 0;
}

int main(){
    string a, b;
    cin>>a>>b;
    cout<<isRotation(a, b);
    return 0;
}
