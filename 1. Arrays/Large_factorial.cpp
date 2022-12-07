/*
Given a number N. The task is to find the factorial of the number.

Example 1:
Input: N = 5
Output: 120

Example 2:
Input: N = 10
Output: 3628800

*/

#include<bits/stdc++.h>
using namespace std;

vector<int> factorial(int n){
    vector<int> ans;
    int carry = 0;
    ans.push_back(1);
    for(int i=2; i<=n; i++){
        for(int j=0; j<ans.size(); j++){
            int mul = ans[j]*i + carry;
            ans[j] = mul%10;
            carry = mul/10;
        }
        while(carry){
            ans.push_back(carry%10);
            carry /= 10;
        }
    }
    reverse(ans.begin(), ans.end());
    return ans;
}

int main(){
    int n;
    cin>>n;
    vector<int> ans = factorial(n);
    for(auto x: ans) cout<<x;
    return 0;
}

