/*
Given an array, task is to rotate array by d elements leftward where d is less than or equal to size of array.

Input:
The first line of input contains an integer T denoting the number of test cases. Then T test cases follow. Each test case contains an integer n denoting the size of the array. The next line contains n space separated integers forming the array. The last line contains d.

Output:
Print the modified array.

Constraints:
1<=T<=200
1<=n<=1000
1<=a[i]<=1000
1<=d<=n

Example:
Input:
2
5
1 2 3 4 5
2
10
2 4 6 8 10 12 14 16 18 20
3

Output:
3 4 5 1 2
8 10 12 14 16 18 20 2 4 6

Explanation:
Testcase 1: 1 2 3 4 5 when rotated by 2 elements, it becomes 3 4 5 1 2.
Testcase 2: 2 4 6 8 10 12 14 16 18 20 when rotated by 3 elements, it becomes 8 10 12 14 16 18 20 2 4 6.

*/

#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int arr[n];
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        int d;
        cin>>d;
        int temp[d];
        for(int i=0;i<d;i++){
            temp[i] = arr[i];
        }
        for(int i=d;i<n;i++){
            arr[i-d] = arr[i];
        }
        for(int i=0;i<d;i++){
            arr[n-d+i] = temp[i];
        }
        for(int i=0;i<n;i++){
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    }

}