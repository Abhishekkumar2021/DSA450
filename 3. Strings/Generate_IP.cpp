/*
Given a string S containing only digits, Your task is to complete the function genIp() which returns a vector containing all possible combinations of valid IPv4 IP addresses and takes only a string S as its only argument.
Note: Order doesn't matter. A valid IP address must be in the form of A.B.C.D, where A, B, C, and D are numbers from 0-255. The numbers cannot be 0 prefixed unless they are 0.


For string 11211 the IP address possible are 
1.1.2.11
1.1.21.1
1.12.1.1
11.2.1.1

Example 1:

Input:
S = 1111
Output: 1.1.1.1
Example 2:

Input:
S = 55
Output: -1

Your Task:

Your task is to complete the function genIp() which returns a vector containing all possible combinations of valid IPv4 IP addresses or -1 if no such IP address could be generated through the input string S, the only argument to the function.

Expected Time Complexity: O(N * N * N * N)
Expected Auxiliary Space: O(N * N * N * N)

Constraints:
1<=N<=16
here, N = length of S.
S only contains digits(i.e. 0-9)

*/

#include<bits/stdc++.h>
using namespace std;

vector<string> genIp(string &s){
    int n = s.size();
    vector<string> ans;
    for(int i = 1; i < n - 2; i++){
        for(int j = i + 1; j < n - 1; j++){
            for(int k = j + 1; k < n; k++){
                string a = s.substr(0, i);
                string b = s.substr(i, j - i);
                string c = s.substr(j, k - j);
                string d = s.substr(k, n - k);
                if(a.size() > 3 || b.size() > 3 || c.size() > 3 || d.size() > 3)
                    continue;
                if((a[0] == '0' && a.size() > 1) || (b[0] == '0' && b.size() > 1) || (c[0] == '0' && c.size() > 1) || (d[0] == '0' && d.size() > 1))
                    continue;
                int x = stoi(a);
                int y = stoi(b);
                int z = stoi(c);
                int w = stoi(d);
                if(x >= 0 && x <= 255 && y >= 0 && y <= 255 && z >= 0 && z <= 255 && w >= 0 && w <= 255){
                    string temp = a + "." + b + "." + c + "." + d;
                    ans.push_back(temp);
                }
            }
        }
    }
    return ans;
}