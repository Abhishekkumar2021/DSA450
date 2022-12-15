/*
Given a string in roman no format (s)  your task is to convert it to an integer . Various symbols and their values are given below.
I 1
V 5
X 10
L 50
C 100
D 500
M 1000

Example 1:

Input:
s = V
Output: 5
Example 2:

Input:
s = III 
Output: 3
Your Task:
Complete the function romanToDecimal() which takes a string as input parameter and returns the equivalent decimal number. 

Expected Time Complexity: O(|S|), |S| = length of string S.
Expected Auxiliary Space: O(1)

Constraints:
1<=roman no range<=3999

Hint:
The numbers in the array are in decreasing order. So whenever the current number is smaller than the previous number, we subtract the current number from the sum. Otherwise, we add the current number to the sum.


*/

#include<bits/stdc++.h>
using namespace std;

int value(char c){
    if(c == 'I')
        return 1;
    if(c == 'V')
        return 5;
    if(c == 'X')
        return 10;
    if(c == 'L')
        return 50;
    if(c == 'C')
        return 100;
    if(c == 'D')
        return 500;
    if(c == 'M')
        return 1000;
    return -1;
}


//Example: XIX - 19
int romanToDecimal(string &str) {
    int n = str.size();
    int ans = 0;
    for(int i = 0; i < n; i++){
        if(i + 1 < n && value(str[i]) < value(str[i + 1]))
            ans -= value(str[i]);
        else
            ans += value(str[i]);
    }
    return ans;
}

int main(){
    int t;
    cin >> t;
    while(t--){
        string str;
        cin >> str;
        cout << romanToDecimal(str) << endl;
    }
    return 0;
}

