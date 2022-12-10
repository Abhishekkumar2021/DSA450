/*
Given an array of size n and a range [a, b]. The task is to partition the array around the range such that array is divided into three parts.
1) All elements smaller than a come first.
2) All elements in range a to b come next.
3) All elements greater than b appear in the end.
The individual elements of three sets can appear in any order. You are required to return the modified array.


Example 1:

Input: 
n = 5
A[] = {1, 2, 3, 3, 4}
[a, b] = [1, 2]
Output: 1
Explanation: One possible arrangement is:
{1, 2, 3, 3, 4}. If you return a valid
arrangement, output will be 1.


Example 2:

Input: 
n = 3 
A[] = {1, 2, 3}
[a, b] = [1, 3]
Output: 1
Explanation: One possible arrangement 
is: {1, 2, 3}. If you return a valid
arrangement, output will be 1.

Hint:
The idea is to use 3-way partitioning process of QuickSort. In this process, we consider the first element as pivot. We traverse the array from left and right, while moving elements smaller than pivot to the beginning of the array and moving elements greater than pivot to the end of the array. Finally, we place pivot at its correct position in sorted array. The problem is to consider the range [a, b] as pivot elements. We can solve this problem in O(n) time using 3-way partitioning process of QuickSort.

Approach:
1. Initialize three variables start = 0, end = n-1, index = 0.
2. Iterate while index is less than or equal to end.
3. If the element at index is smaller than a, then swap the element with the element at start and increment start and index.
4. If the element at index is greater than b, then swap the element with the element at end and decrement end.
5. If the element at index is in range a to b, then just increment index.
6. Print the modified array.
*/

#include <bits/stdc++.h>
using namespace std;

void threeWayPartition(int arr[], int n, int a, int b)
{
    int start = 0;
    int end = n-1;
    int index = 0;
    while(index<=end){
        if(arr[index]<a){
            swap(arr[index], arr[start]);
            start++;
            index++;
        }
        else if(arr[index]>b){
            swap(arr[index], arr[end]);
            end--;
        }
        else{
            index++;
        }
    }
}

int main()
{
    int n;
    cin>>n;
    int arr[n];
    for(int i = 0;i<n;i++){
        cin>>arr[i];
    }
    int a, b;
    cin>>a>>b;
    threeWayPartition(arr, n, a, b);
    for(int i = 0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}