/*
Given an m x n matrix, find all common elements present in all rows in O(mn) time and one traversal of matrix.

Example: 

Input:
mat[4][5] = {{1, 2, 1, 4, 8},
             {3, 7, 8, 5, 1},
             {8, 7, 7, 3, 1},
             {8, 1, 2, 7, 9},
            };

Output: 
1 8 or 8 1
8 and 1 are present in all rows.

*/

#include<bits/stdc++.h>
using namespace std;

vector<int> commonElements(vector<vector<int>> &matrix, int r, int c){
    unordered_map<int, unordered_set<int>> mp;
    for(int i=0; i<r; i++){
        for(int j=0; j<c; j++){
            mp[matrix[i][j]].insert(i);
        }
    }
    vector<int> ans;
    for(auto it=mp.begin(); it!=mp.end(); it++){
        if(it->second.size() == r){
            ans.push_back(it->first);
        }
    }

    return ans;

}

int main(){
    vector<vector<int>> matrix = {{1, 2, 1, 4, 8},
                                  {3, 7, 8, 5, 1},
                                  {8, 7, 7, 3, 1},
                                  {8, 1, 2, 7, 9}};
    int r = matrix.size();
    int c = matrix[0].size();
    vector<int> ans = commonElements(matrix, r, c);
    for(int i=0; i<ans.size(); i++){
        cout << ans[i] << " ";
    }
    return 0;
}