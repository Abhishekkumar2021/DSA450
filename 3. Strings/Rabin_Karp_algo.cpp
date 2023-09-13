/*
Rabin Karp Algorithm for Pattern Searching:
Given a text txt[0..n-1] and a pattern pat[0..m-1], write a function search(char pat[], char txt[]) that prints all occurrences of pat[] in txt[]. You may assume that n > m.

Example 1. 
Input:  txt[] = "THIS IS A TEST TEXT"
        pat[] = "TEST"
Output: Pattern found at index 10

Example 2. 
Input:  txt[] =  "AABAACAADAABAABA"
        pat[] =  "AABA"
Output: Pattern found at index 0
        Pattern found at index 9
        Pattern found at index 12


Algorithm:
1. Calculate the hash value of pattern and first window of text.
2. Now match the hash value of pattern with hash value of current window of text.
3. Calculate hash value for next window of text: Remove leading digit, add trailing digit.
4. Repeat step 2 and 3 until end of text.

Time Complexity: O(n+m)
Space Complexity: O(1)


What is a good hash function?
A good hash function should have following properties.
1. Easy to compute: It should be easy to compute and must not become an intractable problem.
2. Uniform distribution: It should provide a uniform distribution across the hash table and should not result in clustering.
3. Less collisions: Collisions occur when pairs of elements are mapped to same hash value. These should be avoided.


What is the hash function used in Rabin Karp Algorithm?
The hash function used in Rabin Karp Algorithm is:
hash(pat[0..m-1]) = pat[0]*d^(m-1) + pat[1]*d^(m-2) + ... + pat[m-1]
hash(txt[s+1..s+m]) = (d*(hash(txt[s..s+m-1]) - txt[s]*d^(m-1)) + txt[s+m])%q

where d is the number of characters in the input alphabet
*/

#include<bits/stdc++.h>
using namespace std;

void searchNaive(string pat, string txt){
    int m = pat.length();
    int n = txt.length();
    for(int i=0; i<=n-m; i++){
        int j;
        for(j=0; j<m; j++){
            if(txt[i+j] != pat[j])
                break;
        }
        if(j==m)
            cout<<"Pattern found at index "<<i<<endl;
    }
}

void searchRabinKarp(string pat, string txt){
    int n = txt.length();
    int m = pat.length();
    int p = 0; // hash value for pattern
    int t = 0; // hash value for txt
    int h = 1;
    int d = 256; // no. of characters in input alphabet
    int q = 101; // a prime number
    for(int i=0; i<m-1; i++)
        h = (h*d)%q;
    for(int i=0; i<m; i++){
        p = (d*p + pat[i])%q;
        t = (d*t + txt[i])%q;
    }
    for(int i=0; i<=n-m; i++){
        if(p==t){
            int j;
            for(j=0; j<m; j++){
                if(txt[i+j] != pat[j])
                    break;
            }
            if(j==m)
                cout<<"Pattern found at index "<<i<<endl;
        }
        if(i<n-m){
            t = (d*(t - txt[i]*h) + txt[i+m] + q)%q;
        }
    }
}