/*
Given a binary matrix M of size n X m. Find the maximum area of a rectangle formed only of 1s in the given matrix.

Example 1:

Input:
n = 4, m = 4
M[][] = {{0 1 1 0},
         {1 1 1 1},
         {1 1 1 1},
         {1 1 0 0}}
Output: 8
Explanation: For the above test case the
matrix will look like
0 1 1 0
1 1 1 1
1 1 1 1
1 1 0 0
the max size rectangle is 
1 1 1 1
1 1 1 1
and area is 4 *2 = 8.
Your Task: 
Your task is to complete the function maxArea which returns the maximum size rectangle area in a binary-sub-matrix with all 1’s. The function takes 3 arguments the first argument is the Matrix M[ ] [ ] and the next two are two integers n and m which denotes the size of the matrix M. 

Expected Time Complexity : O(n*m)
Expected Auixiliary Space : O(m)

Constraints:
1<=n,m<=1000
0<=M[][]<=1


*/


#include<bits/stdc++.h>
using namespace std;

int maxHistogram(vector<int> arr){
    int n = arr.size();
    stack<int> s;
    int max_area = 0;
    int i=0;
    while(i<n){
        if(s.empty() || arr[s.top()] <= arr[i]){
            s.push(i);
            i++;
        }
        else{
            int top = s.top();
            s.pop();
            int area = arr[top] * (s.empty() ? i : i-s.top()-1);
            max_area = max(max_area, area);
        }
    }
    while(!s.empty()){
        int top = s.top();
        s.pop();
        int area = arr[top] * (s.empty() ? i : i-s.top()-1);
        max_area = max(max_area, area);
    }
    return max_area;
}

int maxArea(vector<vector<int>> M, int n, int m) {
    vector<int> arr(m, 0);
    int max_area = 0;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(M[i][j] == 0){
                arr[j] = 0;
            }
            else{
                arr[j] += M[i][j];
            }
        }
        max_area = max(max_area, maxHistogram(arr));
    }
    return max_area;
}

int main(){
    int n, m;
    cin>>n>>m;
    vector<vector<int>> M(n, vector<int>(m, 0));
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin>>M[i][j];
        }
    }
    cout<<maxArea(M, n, m)<<endl;
    return 0;
}