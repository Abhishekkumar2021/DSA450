/*
Given a string of characters, find the length of the longest proper prefix which is also a proper suffix.

NOTE: Prefix and suffix can be overlapping but they should not be equal to the entire string.

Example 1:

Input: s = "abab"
Output: 2
Explanation: "ab" is the longest proper 
prefix and suffix. 
Example 2:

Input: s = "aaaa"
Output: 3
Explanation: "aaa" is the longest proper 
prefix and suffix. 
Your task:
You do not need to read any input or print anything. The task is to complete the function lps(), which takes a string as input and returns an integer.

Expected Time Complexity: O(|s|)
Expected Auxiliary Space: O(|s|)

Constraints:
1 ≤ |s| ≤ 105
s contains lower case English alphabets

Hint:
1. Create a lps[] array of size n, that will hold the longest prefix suffix values for the pattern.
2. The idea is to keep track of the length of the longest prefix suffix value (we use len variable for this purpose) and also use a loop to traverse through the given string.
3. If the characters at the current index (i) and the index corresponding to the value of len in the lps[] array (i.e., lps[len]) are equal, we increment len by 1 and store this value in lps[i].
4. If the characters are not equal, we check if len is not equal to 0. If it is not equal to 0, we update len to the value of lps[len-1] and repeat the process.
5. If len is equal to 0, we store 0 in lps[i] and move forward in the loop.
6. Finally, we return the value of lps[n-1], where n is the length of the given string.
*/

#include<bits/stdc++.h>
using namespace std;

int lps(string s){
    int n = s.length();
    int lps[n];
    lps[0] = 0;
    int len = 0;
    int i = 1;
    while(i<n){
        if(s[i] == s[len]){
            len++;
            lps[i] = len;
            i++;
        }
        else if(len == 0){
            lps[i] = 0;
            i++;
        }
        else{
            len = lps[len-1];
        }
    }
    return lps[n-1];
}

/*
Dry Run:
Give me a best example in which i can understand this problem
s = "acbadacbab"
lps = [0, 0, 0, 0, 1, 2, 3, 0, 1, 2]

i = 1
len = 0
s[i] = 'c', s[len] = 'a' => len = 0
lps[1] = 0

i = 2
len = 0
s[i] = 'b', s[len] = 'a' => len = 0
lps[2] = 0

i = 3
len = 0
s[i] = 'a', s[len] = 'a' => len = 1
lps[3] = 1

i = 4
len = 1
s[i] = 'd', s[len] = 'c' => len = 0
lps[4] = 0

i = 5
len = 0
s[i] = 'a', s[len] = 'a' => len = 1
lps[5] = 1

i = 6
len = 1
s[i] = 'c', s[len] = 'c' => len = 2
lps[6] = 2

i = 7
len = 2
s[i] = 'b', s[len] = 'b' => len = 3
lps[7] = 3

i = 8
len = 3
s[i] = 'a', s[len] = 'a' => len = 4
lps[8] = 4

i = 9
len = 4
s[i] = 'b', s[len] = 'd' => len = 0



*/