/*
Given three arrays sorted in increasing order. Find the elements that are common in all three arrays.
Note: can you take care of the duplicates without using any additional Data Structure?

Example 1:

Input:
n1 = 6; A = {1, 5, 10, 20, 40, 80}
n2 = 5; B = {6, 7, 20, 80, 100}
n3 = 8; C = {3, 4, 15, 20, 30, 70, 80, 120}
Output: 20 80
Explanation: 20 and 80 are the only
common elements in A, B and C.

Hint:
1. The idea is to use three index variables i, j and k,
initially pointing to the first element of A, B and C respectively.

*/

#include<bits/stdc++.h>
using namespace std;

int getCount(vector<int> a, vector<int> b, vector<int> c){
    int i=0,j=0,k=0;
    int count = 0;
    while(i<a.size() && j<b.size() && k<c.size()){
        if(a[i]==b[j] && b[j]==c[k]){
            count++;
            i++;
            j++;
            k++;
        }
        else if(a[i]<b[j]){
            i++;
        }
        else if(b[j]<c[k]){
            j++;
        }
        else{
            k++;
        }
    }
    return count;
}

//handling duplicates
int getCountHandlingDuplicates(vector<int> a, vector<int> b, vector<int> c){
    unordered_set<int> s;
    int i=0,j=0,k=0;
    while(i<a.size() && j<b.size() && k<c.size()){
        if(a[i]==b[j] && b[j]==c[k]){
            s.insert(a[i]);
            i++;
            j++;
            k++;
        }
        else if(a[i]<b[j]){
            i++;
        }
        else if(b[j]<c[k]){
            j++;
        }
        else{
            k++;
        }
    }
    return s.size();
}

int main(){
    vector<int> a = {1, 5, 10, 20, 40, 80};
    vector<int> b = {6, 7, 20, 80, 100};
    vector<int> c = {3, 4, 15, 20, 30, 70, 80, 120};
    cout<<getCount(a,b,c)<<endl;
    cout<<getCountHandlingDuplicates(a,b,c)<<endl;
    return 0;
}