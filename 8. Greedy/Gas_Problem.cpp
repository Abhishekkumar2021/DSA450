/*
Given N gas stations along a circular route, where the amount of gas at station i is gas[i]. You have a car with an unlimited gas tank and it costs cost[i] of gas to travel from station i to its next station (i+1). You begin the journey with an empty tank at one of the gas stations.
Return the starting gas station's index if you can travel around the circuit once in the clockwise direction, otherwise return -1.

Note:
If there exists a solution, it is guaranteed to be unique.
Both input arrays are non-empty and have the same length.
Each element in the input arrays is a non-negative integer.


Example:
Input 1 -
gas[]  = {1,2,3,4,5}
cost[] = {3,4,5,1,2}

Output 1 - 3

Hint:
1. If car starts at A and can not reach B. Any station between A and B can not reach B.(B is the first station that A can not reach.)
2. If the total number of gas is bigger than the total number of cost. There must be a solution.

*/

#include<bits/stdc++.h>
using namespace std;

int startIndex(vector<int> gas, vector<int> cost){
    int n = gas.size();
    int totalGas = 0;
    int totalCost = 0;
    for(int i=0; i<n; i++){
        totalCost += cost[i];
        totalGas += gas[i];
    }
    if(totalCost>totalGas) return -1;
    int currDiff = 0;
    int ans = 0;
    for(int i=0; i<n; i++){
        currDiff += gas[i] - cost[i];
        if(currDiff<0){
            currDiff = 0;
            ans = (i+1)%n;
        }
    }
    return ans;
}

