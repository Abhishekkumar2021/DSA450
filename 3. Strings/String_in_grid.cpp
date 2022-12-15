/*
Given a 2D grid of n*m of characters and a word, find all occurrences of given word in grid. A word can be matched in all 8 directions at any point. Word is said be found in a direction if all characters match in this direction (not in zig-zag form). The 8 directions are, horizontally left, horizontally right, vertically up, vertically down and 4 diagonal directions.
 

Example 1:

Input: grid = {{a,b,c},{d,r,f},{g,h,i}},
word = "abc"
Output: {{0,0}}
Explanation: From (0,0) one can find "abc"
in horizontally right direction.
Example 2:

Input: grid = {{a,b,a,b},{a,b,e,b},{e,b,e,b}}
,word = "abe"
Output: {{0,0},{0,2},{1,0}}
Explanation: From (0,0) one can find "abe" in 
right-down diagonal. From (0,2) one can
find "abe" in left-down diagonal. From
(1,0) one can find "abe" in Horizontally right 
direction.
 

Your Task:
You don't need to read or print anyhting, Your task is to complete the function searchWord() which takes grid and word as input parameters and returns a list containg the positions from where the word originates in any direction. If there is no such position then returns an empty list.

Note: The returning list should be lexicographically smallest. If the word can be found in multiple directions strating from the same coordinates, the list should contain the coordinates only once. 
 

Expected Time Complexity: O(n*m*k) where k is constant
Exected Space Complexity: O(1)
 

Constraints:
1 <= n <= m <= 100
1 <= |word| <= 10

Hint:
1. Use a function to check if the word is present in a particular direction.
Next, call this function for all 8 directions.
*/

#include<bits/stdc++.h>
using namespace std;

/**
 * @brief 
 * 
 * @param grid - 2D grid of characters
 * @param i - row number
 * @param j - column number
 * @param word - word to be searched
 * @param n - number of rows
 * @param m - number of columns
 * @param k - index of word
 * @param l - direction, possible values are 1,2,3,4,5,6,7,8
 * @return true 
 * @return false 
 */

bool isPresent(vector<vector<char>> &grid, int i, int j, string &word, int n, int m, int k, int l){
    if(k == word.size())
        return true;
    if(i < 0 || j < 0 || i >= n || j >= m || grid[i][j] != word[k])
        return false;
    bool ans = false;
    if(l == 1){
        ans = isPresent(grid, i, j + 1, word, n, m, k + 1, l);
        if(ans) return true;
    }
    else if(l == 2){
        ans = isPresent(grid, i + 1, j + 1, word, n, m, k + 1, l);
        if(ans) return true;
    }
    else if(l == 3){
        ans = isPresent(grid, i + 1, j, word, n, m, k + 1, l);
        if(ans) return true;
    }
    else if(l == 4){
        ans = isPresent(grid, i + 1, j - 1, word, n, m, k + 1, l);
        if(ans) return true;
    }
    else if(l == 5){
        ans = isPresent(grid, i, j - 1, word, n, m, k + 1, l);
        if(ans) return true;
    }
    else if(l == 6){
        ans = isPresent(grid, i - 1, j - 1, word, n, m, k + 1, l);
        if(ans) return true;
    }
    else if(l == 7){
        ans = isPresent(grid, i - 1, j, word, n, m, k + 1, l);
        if(ans) return true;
    }
    else if(l == 8){
        ans = isPresent(grid, i - 1, j + 1, word, n, m, k + 1, l);
        if(ans) return true;
    }
    return false;
}

/**
 * @brief 
 * 
 * @param grid - 2D grid of characters
 * @param word - word to be searched
 * @return vector<vector<int>> - list of positions from where the word originates in any direction
 */

vector<vector<int>> searchWord(vector<vector<char>> &grid, string &word){
    int n = grid.size();
    int m = grid[0].size();
    vector<vector<int>> ans;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            for(int k = 1; k <= 8; k++){
                if(isPresent(grid, i, j, word, n, m, 0, k)){
                    ans.push_back({i, j});
                    break;
                }
            }
        }
    }
    return ans;
}