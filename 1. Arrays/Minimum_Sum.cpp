/*
Given an array Arr of size N such that each element is from the range 0 to 9. Find the minimum possible sum of two numbers formed using the elements of the array. All digits in the given array must be used to form the two numbers.


Example 1:

Input:
N = 6
Arr[] = {6, 8, 4, 5, 2, 3}
Output: 604
Explanation: The minimum sum is formed 
by numbers 358 and 246.

Example 2:

Input:
N = 5
Arr[] = {5, 3, 0, 7, 4}
Output: 82
Explanation: The minimum sum is 
formed by numbers 35 and 047.

Your Task:
You don't need to read input or print anything. Your task is to complete the function solve() which takes arr[] and n as input parameters and returns the minimum possible sum. As the number can be large, return string presentation of the number without leading zeroes.
 

Expected Time Complexity: O(N*logN)
Expected Auxiliary Space: O(1)


Constraints:
1 ≤ N ≤ 107
0 ≤ Arri ≤ 9
*/

#include<bits/stdc++.h>
using namespace std;

class Solution{
public:
    string add(string a, string b){
        string ans = "";
        int i = a.length() - 1;
        int j = b.length() - 1;
        int carry = 0;
        while(i >= 0 || j >= 0){
            int sum = carry;
            if(i >= 0){
                sum += a[i] - '0';
                i--;
            }
            if(j >= 0){
                sum += b[j] - '0';
                j--;
            }
            carry = sum / 10;
            sum = sum % 10;
            ans += to_string(sum);
        }
        if(carry){
            ans += to_string(carry);
        }
        reverse(ans.begin(), ans.end());
        //handling zeroes
        int idx = 0;
        while(idx < ans.length() && ans[idx] == '0'){
            idx++;
        }
        ans = ans.substr(idx);
        return ans;
    }
    string solve(int arr[], int n) {
        // code here
        string a = "";
        string b = "";
        sort(arr, arr + n);
        int idx = 0;
        while(idx<n){
            a += to_string(arr[idx]);
            idx++;
            if(idx >= n){
                break;
            }
            b += to_string(arr[idx]);
            idx++;
        }
        string ans = add(a, b);
        return ans;
    }
};