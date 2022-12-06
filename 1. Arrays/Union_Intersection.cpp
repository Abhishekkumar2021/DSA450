/*
You are given two arrays A and B. You need to print the union and intersection of the two arrays.
Input Format:
First line contains an integer N - the size of the first array. The next line contains N integers - the elements of the first array. The next line contains an integer M - the size of the second array. The next line contains M integers - the elements of the second array.

Constraints:
1 <= N, M <= 10^5
-10^9 <= A[i], B[i] <= 10^9

Output Format:
Print the union and intersection of the two arrays. The union and intersection should be printed in sorted order.

Sample Input:
5
1 2 3 4 5
4
1 2 3 4
Sample Output:
1 2 3 4 5
1 2 3 4

Time Limit: 1 sec

*/

#include<bits/stdc++.h>
using namespace std;

vector<int> getIntersection(vector<int> a, vector<int> b){
    vector<int> v;
    int i=0, j=0;
    while(i<a.size() && j<b.size()){
        if(i>=1 && a[i]==a[i-1]){
            i++;
            continue;
        }
        if(j>=1 && b[j]==b[j-1]){
            j++;
            continue;
        }

        if(a[i]==b[j]){
            v.push_back(a[i]);
            i++;
            j++;
        }
        else if(a[i]<b[j]){
            i++;
        }
        else{
            j++;
        }
    }
    
    return v;
}

vector<int> getUnion(vector<int> a, vector<int> b){
    vector<int> v;
    int i=0, j=0;
    while(i<a.size() && j<b.size()){
        if(a[i]==b[j]){
            v.push_back(a[i]);
            i++;
            j++;
        }
        else if(a[i]<b[j]){
            v.push_back(a[i]);
            i++;
        }
        else{
            v.push_back(b[j]);
            j++;
        }
    }
    while(i<a.size()){
        v.push_back(a[i]);
        i++;
    }
    while(j<b.size()){
        v.push_back(b[j]);
        j++;
    }
    return v;
}

vector<int> getIntersectionUsingSet(vector<int> a, vector<int> b){
    vector<int> v;
    set<int> s;
    for(int i=0;i<a.size();i++){
        s.insert(a[i]);
    }
    for(int i=0;i<b.size();i++){
        if(s.find(b[i])!=s.end()){
            v.push_back(b[i]);
        }
    }
    return v;
}

vector<int> getUnionUsingSet(vector<int> a, vector<int> b){
    vector<int> v;
    set<int> s;
    for(int i=0;i<a.size();i++){
        s.insert(a[i]);
    }
    for(int i=0;i<b.size();i++){
        s.insert(b[i]);
    }
    for(auto it=s.begin();it!=s.end();it++){
        v.push_back(*it);
    }
    return v;
}

int getIntersectionUsingMap(vector<int> a, vector<int> b){
    map<int, int> m;
    for(int i=0;i<a.size();i++){
        m[a[i]]++;
    }
    for(int i=0;i<b.size();i++){
        m[b[i]]++;
    }
    int count = 0;
    for(auto it=m.begin();it!=m.end();it++){
        if(it->second>1){
            count++;
        }
    }
    return count;
}
int getUnionUsingMap(vector<int> a, vector<int> b){
    map<int, int> m;
    for(int i=0;i<a.size();i++){
        m[a[i]]++;
    }
    for(int i=0;i<b.size();i++){
        m[b[i]]++;
    }
    return m.size();
}

int getIntersectionUsingInbuiltFunction(vector<int> a, vector<int> b){
    vector<int> v;
    set_intersection(a.begin(), a.end(), b.begin(), b.end(), back_inserter(v));
    return v.size();
}

int getUnionUsingInbuiltFunction(vector<int> a, vector<int> b){
    vector<int> v;
    set_union(a.begin(), a.end(), b.begin(), b.end(), back_inserter(v));
    return v.size();
}

int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int m;
    cin>>m;
    vector<int> brr(m);
    for(int i=0;i<m;i++){
        cin>>brr[i];
    }
    sort(arr.begin(), arr.end());
    sort(brr.begin(), brr.end());
    vector<int> ans_intersection = getIntersection(arr, brr);
    vector<int> ans_union = getUnion(arr, brr);
} 