/*
Given an array of integers. Find the Inversion Count in the array.

Inversion Count: For an array, inversion count indicates how far (or close) the array is from being sorted. If array is already sorted then the inversion count is 0. If an array is sorted in the reverse order then the inversion count is the maximum.
Formally, two elements a[i] and a[j] form an inversion if a[i] > a[j] and i < j.


Example 1:

Input: N = 5, arr[] = {2, 4, 1, 3, 5}
Output: 3
Explanation: The sequence 2, 4, 1, 3, 5
has three inversions (2, 1), (4, 1), (4, 3).
Example 2:

Input: N = 5
arr[] = {2, 3, 4, 5, 6}
Output: 0
Explanation: As the sequence is already
sorted so there is no inversion count.
Example 3:

Input: N = 3, arr[] = {10, 10, 10}
Output: 0
Explanation: As all the elements of array
are same, so there is no inversion count.
Your Task:
You don't need to read input or print anything. Your task is to complete the function inversionCount() which takes the array arr[] and the size of the array as inputs and returns the inversion count of the given array.

Expected Time Complexity: O(NLogN).
Expected Auxiliary Space: O(N).

Hint:
The idea is to use Merge Sort to count inversions in an array.

Approach:
The idea is similar to merge sort, divide the array into two equal or almost equal halves in each step until the base case is reached. Create a function merge for merging two halves. Make a call for each half. While merging two halves, keep track of inversions at the same time. Inversion will occur when left half element is greater than the right half element. If inversion occurs, then there are (mid – i) inversions. Because left and right subarrays are sorted, so all the remaining elements in left-subarray (arr[i+1], arr[i+2] … arr[mid]) will be greater than the element arr[j].

Time Complexity: O(nlogn)
*/

#include <bits/stdc++.h>
using namespace std;

long long merge(long long arr[], long long temp[], long long left, long long mid, long long right)
{
    long long i, j, k;
    long long inv_count = 0;
 
    i = left; /* i is index for left subarray*/
    j = mid;  /* j is index for right subarray*/
    k = left; /* k is index for resultant merged subarray*/
    while ((i <= mid - 1) && (j <= right))
    {
        if (arr[i] <= arr[j])
        {
            temp[k++] = arr[i++];
        }
        else
        {
            temp[k++] = arr[j++];
 
            inv_count = inv_count + (mid - i);
        }
    }
 
    /* Copy the remaining elements of left subarray
     (if there are any) to temp*/
    while (i <= mid - 1)
        temp[k++] = arr[i++];
 
    /* Copy the remaining elements of right subarray
     (if there are any) to temp*/
    while (j <= right)
        temp[k++] = arr[j++];
 
    /*Copy back the merged elements to original array*/
    for (i=left; i <= right; i++)
        arr[i] = temp[i];
 
    return inv_count;
}

long long _mergeSort(long long arr[], long long temp[], long long left, long long right)
{
    long long mid, inv_count = 0;
    if (right > left)
    {
        mid = (right + left)/2;

        inv_count  = _mergeSort(arr, temp, left, mid);
        inv_count += _mergeSort(arr, temp, mid+1, right);

        inv_count += merge(arr, temp, left, mid+1, right);
    }
    return inv_count;
}

long long mergeSort(long long arr[], long long array_size)
{
    long long temp[array_size];
    return _mergeSort(arr, temp, 0, array_size - 1);
}

int main()
{
    long long t;
    cin>>t;
    while(t--)
    {
        long long n;
        cin>>n;
        long long arr[n];
        for(long long i=0;i<n;i++)
        {
            cin>>arr[i];
        }
        cout<<mergeSort(arr,n)<<endl;
    }
    return 0;
}

 
