/*
Given a row wise sorted matrix of size R*C where R and C are always odd, find the median of the matrix.

Example 1:

Input:
R = 3, C = 3
M = [[1, 3, 5], 
     [2, 6, 9], 
     [3, 6, 9]]
Output: 5
Explanation: Sorting matrix elements gives 
us {1,2,3,3,5,6,6,9,9}. Hence, 5 is median. 
 

Example 2:

Input:
R = 3, C = 1
M = [[1], [2], [3]]
Output: 2
Explanation: Sorting matrix elements gives 
us {1,2,3}. Hence, 2 is median.

Hint:
1) First find the minimum and maximum element in the matrix.
2) Then use binary search on the range from minimum to maximum element to find the median.

Approach:
1) First find the minimum and maximum element in the matrix.
2) Then use binary search on the range from minimum to maximum element to find the median.
3) For every mid, count the number of elements less than or equal to mid.
4) If the count is less than or equal to half the total number of elements, the median lies on the right side of mid.
5) Else, the median lies on the left side of mid.

*/

#include<bits/stdc++.h>
using namespace std;

int getMedian(vector<vector<int>> &matrix, int r, int c){
    int min = INT_MAX;
    int max = INT_MIN;
    for(int i=0; i<r; i++){ 
        if(matrix[i][0] < min){
            min = matrix[i][0];
        }
        if(matrix[i][c-1] > max){
            max = matrix[i][c-1];
        }
    }
    int desired = (r*c+1)/2;
    while(min < max){
        int mid = min + (max-min)/2;
        int place = 0;
        for(int i=0; i<r; i++){
            place += upper_bound(matrix[i].begin(), matrix[i].end(), mid) - matrix[i].begin();
        }
        if(place < desired){
            min = mid+1;
        }
        else{
            max = mid;
        }
    }
    return min;
}

int main(){
    int r, c;
    cin >> r >> c;
    vector<vector<int>> matrix(r, vector<int>(c));
    for(int i=0; i<r; i++){
        for(int j=0; j<c; j++){
            cin >> matrix[i][j];
        }
    }
    cout << getMedian(matrix, r, c) << endl;
    return 0;
}