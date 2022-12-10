/*
Given two arrays a1, a2 of size n and m respectively. The task is to check whether array b is a subset of array a or not. Both the arrays can be both unsorted or sorted. It may be assumed that elements in both array are distinct.
*/

#include <bits/stdc++.h>
using namespace std;

string isSubset(int a1[], int a2[], int n, int m) {
    unordered_map<int,int> map;
    for (int i = 0; i < n; i++) {
        map[a1[i]]++;
    }
    for (int i = 0; i < m; i++) {
        if(map[a2[i]] == 0)
            return "No";
        else map[a2[i]]--;
    }
    return "Yes";
}

string isSubUsingSorting(int a1[], int a2[], int n, int m) {
    sort(a1, a1+n);
    sort(a2, a2+m);
    int i = 0, j = 0;
    while(i < n && j < m) {
        if(a1[i] < a2[j])
            i++;
        else if(a1[i] == a2[j]) {
            i++;
            j++;
        }
        else
            return "No";
    }
    if(j < m)
        return "No";
    return "Yes";
}

string isSubUsingSet(int a1[], int a2[], int n, int m) {
    unordered_set<int> set;
    for (int i = 0; i < n; i++) {
        set.insert(a1[i]);
    }
    for (int i = 0; i < m; i++) {
        if(set.find(a2[i]) == set.end())
            return "No";
    }
    return "Yes";
}

string isSubUsingSet2(int a1[], int a2[], int n, int m) {
    unordered_set<int> set(a1, a1+n);
    for (int i = 0; i < m; i++) {
        if(set.find(a2[i]) == set.end())
            return "No";
    }
    return "Yes";
}


int main() {

}