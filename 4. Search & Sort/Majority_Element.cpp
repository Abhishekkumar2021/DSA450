/*
Given an array A of N elements. Find the majority element in the array. A majority element in an array A of size N is an element that appears more than N/2 times in the array.
 

Example 1:

Input:
N = 3 
A[] = {1,2,3} 
Output:
-1
Explanation:
Since, each element in 
{1,2,3} appears only once so there 
is no majority element.
Example 2:

Input:
N = 5 
A[] = {3,1,3,3,2} 
Output:
3
Explanation:
Since, 3 is present more
than N/2 times, so it is 
the majority element.

Your Task:
The task is to complete the function majorityElement() which returns the majority element in the array. If no majority exists, return -1.
 

Expected Time Complexity: O(N).
Expected Auxiliary Space: O(1).
 

Constraints:
1 ≤ N ≤ 10^7
0 ≤ Ai ≤ 10^6
*/

#include<bits/stdc++.h>
using namespace std;

int getMajorityElementusingmap(int arr[], int n)
{
    unordered_map<int, int> mp;
    for(int i=0; i<n; i++)
    {
        mp[arr[i]]++;
    }
    for(auto i: mp)
    {
        if(i.second > n/2)
        {
            return i.first;
        }
    }
    return -1;
}

int getMajorityElementusingMoore(int arr[], int n)
{
    int res = 0, count = 1;
    for(int i=1; i<n; i++)
    {
        if(arr[res] == arr[i])
        {
            count++;
        }
        else
        {
            count--;
        }
        if(count == 0)
        {
            res = i;
            count = 1;
        }
    }
    count = 0;
    for(int i=0; i<n; i++)
    {
        if(arr[res] == arr[i])
        {
            count++;
        }
    }
    if(count <= n/2)
    {
        res = -1;
    }
    return res;
}

/*
What is the concept of Moore's Voting Algorithm?
Moore's Voting Algorithm is a technique to find the majority element in an array. It is a two-step process. First, we find the candidate for majority element. Then, we check if the candidate is actually a majority element. The first step gives the element that may be majority element in the array. If there is a majority element in an array, then this step will definitely return majority element, otherwise, it will return candidate for majority element. The second step is to check if the element obtained from the above step is majority element. This step is necessary as there might be no majority element.

*/