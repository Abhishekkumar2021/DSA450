/*
Given a string 's'. The task is to find the smallest window length that contains all the characters of the given string at least one time.
For eg. A = aabcbcdbca, then the result would be 4 as of the smallest window will be dbca.

 

Example 1:

Input : "AABBBCBBAC"
Output : 3
Explanation : Sub-string -> "BAC"
Example 2:
Input : "aaab"
Output : 2
Explanation : Sub-string -> "ab"
 
Example 3:
Input : "GEEKSGEEKSFOR"
Output : 8
Explanation : Sub-string -> "GEEKSFOR"
 


Your Task:  
You don't need to read input or print anything. Your task is to complete the function findSubString() which takes the string  S as input and returns the length of the smallest such window of the string.


Expected Time Complexity: O(256.N)
Expected Auxiliary Space: O(256)

 

Constraints:
1 ≤ |S| ≤ 105
String may contain both type of English Alphabets.

Approach:

We will use sliding window technique to solve this problem. We will maintain a window of characters which contains all the characters of given string. We will maintain two pointers, one will point to the start of the window and other will point to the end of the window. We will maintain a frequency array to keep track of the frequency of characters in the window. We will also maintain a count variable which will keep track of the number of distinct characters in the window. We will traverse the string from left to right and keep on adding the characters in the window. We will also keep on updating the frequency array and count variable. When the count variable becomes equal to the number of distinct characters in the string, we will try to minimize the window by removing the characters from the left side of the window. We will keep on doing this until the count variable becomes less than the number of distinct characters in the string. We will keep on updating the answer variable with the minimum length of the window.
*/

#include<bits/stdc++.h>
using namespace std;

int findSubString(string str){
    int n = str.size();
    int ans = INT_MAX;
    int cnt = 0;
    int freq[256] = {0};
    for(int i = 0; i < n; i++){
        if(freq[str[i]] == 0)
            cnt++;
        freq[str[i]]++;
    }
    int i = 0, j = 0;
    int curr_cnt = 0;
    int curr_freq[256] = {0};
    while(j < n){
        curr_freq[str[j]]++;
        if(curr_freq[str[j]] == 1)
            curr_cnt++;
        if(curr_cnt == cnt){
            while(curr_freq[str[i]] > 1){
                curr_freq[str[i]]--;
                i++;
            }
            int len = j - i + 1;
            ans = min(ans, len);
        }
        j++;
    }
    return ans;
}

/*
Dry Run:

str = AABBBCBBAC
cnt = 3, ans = INT_MAX = 2147483647

i = 0, j = 0
curr_freq['A']++
curr_freq['A'] = 1
curr_cnt = 1

i = 0, j = 1
curr_freq['A']++
curr_freq['A'] = 2
curr_cnt = 1

i = 0, j = 2
curr_freq['B']++
curr_freq['B'] = 1
curr_cnt = 2

i = 0, j = 3
curr_freq['B']++
curr_freq['B'] = 2
curr_cnt = 2

i = 0, j = 4
curr_freq['B']++
curr_freq['B'] = 3
curr_cnt = 2

i = 0, j = 5
curr_freq['C']++
curr_freq['C'] = 1
curr_cnt = 3

-> Inside while loop
i = 0
curr_freq['A'] = 2
curr_freq['A']--

i = 1
curr_freq['A'] = 1

curr_freq['A'] = 1 --> condition fails
ans = min(ans, 5) = 5

i = 1, j = 6
curr_freq['B']++
curr_freq['B'] = 4
curr_cnt = 3

-> Inside while loop
i = 1
curr_freq['A'] = 1 --> condition fails


i = 1, j = 7
curr_freq['B']++
curr_freq['B'] = 5
curr_cnt = 3

--> Inside while loop
i = 1
curr_freq['A'] = 1 --> condition fails

i = 1, j = 8
curr_freq['A']++
curr_freq['A'] = 2
curr_cnt = 3

--> Inside while loop
i = 1
curr_freq['A'] = 2
curr_freq['A']--

i = 2
curr_freq['A'] = 1 --> condition fails

ans = min(ans, 7) = 5

i = 2, j = 9
curr_freq['C']++
curr_freq['C'] = 2
curr_cnt = 3

--> Inside while loop
i = 2
curr_freq['B'] = 5 
curr_freq['B']--

i = 3
curr_freq['B'] = 4
curr_freq['B']--

i = 4
curr_freq['B'] = 3
curr_freq['B']--

i = 5
curr_freq['C'] = 2
curr_freq['C']--

i = 6
curr_freq['B'] = 2
curr_freq['B']--

i = 7
curr_freq['B'] = 1 --> condition fails
len = j-i+1 = 9-7+1 = 3
ans = min(ans, 3) = 3

*/