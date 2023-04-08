#include<bits/stdc++.h>
using namespace std;

int lowerBound(vector<int> arr, int target){
    int n = arr.size();
    int low = 0;
    int high = n-1;
    while(low<=high){
        int mid = (low+high)/2;
        if(arr[mid]>=target){
            high = mid-1;
        }else{
            low = mid+1;
        } 
    }
    return low;
}

int upperBound(vector<int> arr, int target){
    int n = arr.size();
    int low = 0;
    int high = n-1;
    while(low<=high){
        int mid = (low+high)/2;
        if(arr[mid] <= target){
            low = mid+1;
        }else{
            high = mid-1;
        }
    }
    return low;
}

int main(){
    vector<int> arr = {1,2,3,4,5,5,5,5,6,7,8,9,10};
    int target = 5;
    cout<<lowerBound(arr,target)<<endl;
    cout<<upperBound(arr,target)<<endl;
    return 0;
}