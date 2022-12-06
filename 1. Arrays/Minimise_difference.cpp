/*
Given an array arr[] denoting heights of N towers and a positive integer K.

For each tower, you must perform exactly one of the following operations exactly once.

a) Increase the height of the tower by K
b) Decrease the height of the tower by K
Find out the minimum possible difference between the height of the shortest and tallest towers after you have modified each tower.

You can find a slight modification of the problem here.
Note: It is compulsory to increase or decrease the height by K for each tower. After the operation, the resultant array should not contain any negative integers.

Example 1:

Input:
K = 2, N = 4
Arr[] = {1, 5, 8, 10}
Output:
5
Explanation:
The array can be modified as {3, 3, 6, 8}. 
The difference between the largest and the smallest is 8-3 = 5.

Example 2:

Input:
K = 3, N = 5
Arr[] = {3, 9, 12, 16, 20}
Output:
11
Explanation:
The array can be modified as {6, 12, 9, 13, 17}. 
The difference between the largest and the smallest is 17-6 = 11. 

Hint: 
The idea is to sort the array and then find the difference between the maximum and minimum element in the array.
 
Time Complexity: O(NlogN)
Space Complexity: O(1)
*/
#include <bits/stdc++.h>
using namespace std;

int getMinDiff(vector<int> arr, int n, int k) {
    vector<pair<int, int>> v;
    for (int i = 0; i < n; i++) {
        if (arr[i] - k >= 0)
            v.push_back({arr[i] - k, i});
        v.push_back({arr[i] + k, i});
    }
    sort(v.begin(), v.end());
    int ans = v[n - 1].first - v[0].first;
    int left = 0, right = 0;
    int elements = 0;
    vector<int> freq(n, 0);
    while (right < v.size()) {
        if (elements < n) {
            if (freq[v[right].second] == 0)
                elements++;
            freq[v[right].second]++;
            right++;
        }
        if (elements == n) {
            ans = min(ans, v[right - 1].first - v[left].first);
            freq[v[left].second]--;
            if (freq[v[left].second] == 0)
                elements--;
            left++;
        }
    }
    return ans;

}

int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int k;
    cin>>k;
    cout<<getMinDiff(arr,n,k)<<endl;
}

/*
Dry run -
arr[] = {1, 5, 8, 10}
n = 4
k = 2

ans = 10 - 1 = 9
small = 1 + 2 = 3
big = 10 - 2 = 8

i = 1
subtract = 5 - 2 = 3
add = 5 + 2 = 7
subtract >= small || add <= big
3 >= 3 || 7 <= 8
true
*/