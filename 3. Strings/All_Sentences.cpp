/*
Recursively print all sentences that can be formed from list of word lists
Input: {{"you", "we"},
        {"have", "are"},
        {"sleep", "eat", "drink"}}

Output:
  you have sleep
  you have eat
  you have drink
  you are sleep
  you are eat
  you are drink
  we have sleep
  we have eat
  we have drink
  we are sleep
  we are eat
  we are drink 
*/

#include <bits/stdc++.h>
using namespace std;

void print(vector<vector<string>> &v, vector<string> &s, int i){
    if(i==v.size()){
        for(int j=0; j<s.size(); j++) cout<<s[j]<<" ";
        cout<<endl;
        return;
    }
    for(int j=0; j<v[i].size(); j++){
        s.push_back(v[i][j]);
        print(v,s,i+1);
        s.pop_back();
    }
}

int main() {
    vector<vector<string>> v = {{"you", "we"},
                                {"have", "are"},
                                {"sleep", "eat", "drink"}};
    vector<string> s;
    print(v,s,0);
    return 0;
}