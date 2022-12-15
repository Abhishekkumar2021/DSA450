/*
Given a string A and a dictionary of n words B, find out if A can be segmented into a space-separated sequence of dictionary words.

Note: From the dictionary B each word can be taken any number of times and in any order.
Example 1:

Input:
n = 12
B = { "i", "like", "sam",
"sung", "samsung", "mobile",
"ice","cream", "icecream",
"man", "go", "mango" }
A = "ilike"
Output:
1
Explanation:
The string can be segmented as "i like".

Example 2:

Input:
n = 12
B = { "i", "like", "sam",
"sung", "samsung", "mobile",
"ice","cream", "icecream", 
"man", "go", "mango" }
A = "ilikesamsung"
Output:
1
Explanation:
The string can be segmented as 
"i like samsung" or "i like sam sung".
 

Your Task:
Complete wordBreak() function which takes a string and list of strings as a parameter and returns 1 if it is possible to break words, else return 0. You don't need to read any input or print any output, it is done by driver code.


Expected time complexity: O(s2)

Expected auxiliary space: O(s) , where s = length of string A

 

Constraints:
1 ≤ N ≤ 12
1 ≤ s ≤ 1100 , where s = length of string A

Hint:
Use dynamic programming to solve this problem. Create a dp array of size n+1 where dp[i] represents whether s[0..i-1] can be segmented into dictionary words or not. Initialize all values in dp[] as false. Traverse the dp[] array from left to right. For every index i, traverse all the words in the dictionary. For every word, check if the word is present at the current index i in the dp array. If the word is present, then check if the word can be segmented further. If the word can be segmented further, then mark the current index i in the dp array as true. If the word cannot be segmented further, then mark the current index i in the dp array as false. Finally, return the value of the last index of the dp array.

*/

#include<bits/stdc++.h>
using namespace std;


class Solution{
    public:
    int wordBreak(string A, vector<string> &B) {
        //code here
        int n=A.length();
        vector<bool> dp(n+1,false);
        dp[0]=true;
        for(int i=1;i<=n;i++){
            for(int j=0;j<i;j++){
                if(dp[j] && find(B.begin(),B.end(),A.substr(j,i-j))!=B.end()){
                    dp[i]=true;
                    break;
                }
            }
        }
        return dp[n];
    }

    // This will not work at all ! Remember this
    int wordBreakUsingSet(string A, vector<string> &B) {
        //code here
        int n=A.length();
        unordered_set<string> s;
        for(int i=0;i<B.size();i++){
            s.insert(B[i]);
        }
        string str = "";
        for(int i=0;i<n;i++){
            str += A[i];
            if(s.find(str)!=s.end()){
                str = "";
            }
        }
        if(str==""){
            return 1;
        }
        return 0;
    }
};

/*
Dry Run:
A = "ilikesamsung"
B = { "i", "like", "sam", "sung", "samsung", "mobile", "ice","cream", "icecream", "

n = 12
dp[] = {true, false, false, false, false, false, false, false, false, false, false, false, false}

i = 1
j = 0
dp[1] = true

*/