/*
You are given a string S of 2N characters consisting of N ‘[‘ brackets and N ‘]’ brackets. A string is considered balanced if it can be represented in the for S2[S1] where S1 and S2 are balanced strings. We can make an unbalanced string balanced by swapping adjacent characters. Calculate the minimum number of swaps necessary to make a string balanced.
Note - Strings S1 and S2 can be empty.

 

Example 1:

Input  : []][][
Output : 2
Explanation :
First swap: Position 3 and 4
[][]][
Second swap: Position 5 and 6
[][][]

 

Example 2:

Input : [[][]]
Output : 0 
Explanation:
String is already balanced.
 

Your Task:

You don't need to read input or print anything. Your task is to complete the function minimumNumberOfSwaps() which takes the string S and return minimum number of operations required to balance the bracket sequence.

 

Expected Time Complexity: O(N).
Expected Auxiliary Space: O(1).

 

Constraints:

1<= |S|<=100000

*/

#include<bits/stdc++.h>
using namespace std;

int minSwaps(string s){
    int n = s.size();
    int open = 0, close = 0;
    int ans = 0;
    int defect = 0;
    for(int i = 0; i < n; i++){
        if(s[i] == '['){
            open++;
            if(defect > 0){
                ans += defect;
                defect--;
            }
        }
        else{
            close++;
            defect = close - open;
        }

    }

}
