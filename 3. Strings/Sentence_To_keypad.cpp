/*
Given a sentence in the form of a string, convert it into its equivalent mobile numeric keypad sequence. 

Input:
S = "GEEKSFORGEEKS"
Output:
4333355777733366677743333557777
*/

#include <bits/stdc++.h>
using namespace std;

string printSequence(string str);

int main() {
    string s;
    cin >> s;
    cout << printSequence(s) << endl;
    return 0;
}

string printSequence(string str) {
    string ans = "";
    int n = str.length();
    map<char, pair<int, int>> m;
    m['a'] = {2, 1};
    m['b'] = {2, 2};
    m['c'] = {2, 3};
    m['d'] = {3, 1};
    m['e'] = {3, 2};
    m['f'] = {3, 3};
    m['g'] = {4, 1};
    m['h'] = {4, 2};
    m['i'] = {4, 3};
    m['j'] = {5, 1};
    m['k'] = {5, 2};
    m['l'] = {5, 3};
    m['m'] = {6, 1};
    m['n'] = {6, 2};
    m['o'] = {6, 3};
    m['p'] = {7, 1};
    m['q'] = {7, 2};
    m['r'] = {7, 3};
    m['s'] = {7, 4};
    m['t'] = {8, 1};
    m['u'] = {8, 2};
    m['v'] = {8, 3};
    m['w'] = {9, 1};
    m['x'] = {9, 2};
    m['y'] = {9, 3};
    m['z'] = {9, 4};
    m[' '] = {0, 1};
    for (int i = 0; i < n; i++) {
        char ch = tolower(str[i]);
        int x = m[ch].first;
        int y = m[ch].second;
        for (int j = 0; j < y; j++) {
            ans += (x + '0');
        }
    }
    return ans;
}