/*
Given binary string str of length N. The task is to find the maximum count of consecutive substrings str can be divided into such that all the substrings are balanced i.e. they have an equal number of 0s and 1s. If it is not possible to split str satisfying the conditions then return -1.

Example 1:

Input:
S = "0100110101"
Output: 4
Explanation: 
The required substrings are 01, 0011, 01 and 01.

Example 2:

Input:
S = "0111100010"
Output: 3
 

Your Task:  
You don't need to read input or print anything. Your task is to complete the function maxSubStr() which takes a string S and returns an integer as output.

Expected Time Complexity: O(N)
Expected Auxiliary Space: O(1)

 

Constraints:
1 <= S.length <= 10^5

Hint For maximum length of balanced substring:
The idea is to traverse the string and maintain a variable count which will store the difference between the number of 0s and 1s. If the count becomes 0, then we have found a balanced substring. If the count is not 0, then we will store the count in a map. If the count is already present in the map, then it means that the substring from the previous occurrence of count to the current index is balanced. If the count is not present in the map, then we will store the count in the map. After the traversal of the string, we will return the maximum size of the balanced substring.

*/

#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    int maxSubStr(string s)
    {
        int count = 0;
        int n = s.length();
        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            if (s[i] == '0')
                count++;
            else
                count--;
            if(i==n-1 && count!=0) return -1;
            if (count == 0){
                ans++;
                count = 0;
            }
        }
        return ans;
    }
};

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;
        Solution ob;
        cout << ob.maxSubStr(s) << endl;
    }
    return 0;
}


int maxLengthbalancedSubStr(string s, int n)
{
    int count = 0;
    int max = 0;
    unordered_map<int, int> m;
    for (int i = 0; i < n; i++)
    {
        if (s[i] == '0')
            count++;
        else
            count--;
        if (count == 0)
            max = i + 1;
        else if (m.find(count) != m.end())
            max = max > i - m[count] ? max : i - m[count];
        else
            m[count] = i;
    }
    return max;
}