// Question Link => https://www.codingninjas.com/codestudio/guided-paths/competitive-programming/content/148627/offering/1792828

#include<bits/stdc++.h>
using namespace std;

void run(vector<vector<bool>> &arr, int i, int j, string path, vector<string> &paths, vector<vector<bool>> &visited)
{
    if(i < 0 || j < 0 || i >= arr.size() || j >= arr[0].size() || arr[i][j] == false || visited[i][j] == true)
        return;

    if(i == arr.size() - 1 && j == arr[0].size() - 1)
    {
        paths.push_back(path);
        return;
    }

    visited[i][j] = true;

    run(arr, i + 1, j, path + "D", paths, visited);
    run(arr, i, j - 1, path + "L", paths, visited);
    run(arr, i, j + 1, path + "R", paths, visited);
    run(arr, i - 1, j, path + "U", paths, visited);

    visited[i][j] = false;
}

vector<string> findAllPaths( vector<vector<bool>> &arr)
{
    //    Write your code here.
    int n = arr.size();
    int m = arr[0].size();
    vector<string> ans;
    string path = "";
    int i = 0, j = 0;

    vector<vector<bool>> visited(n, vector<bool>(m, false));
    run(arr, i, j, path, ans, visited);

    return ans;
}