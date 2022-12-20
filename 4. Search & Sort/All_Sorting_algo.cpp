#include<bits/stdc++.h>
using namespace std;

int selectionSort(vector<int> &arr){
    int n = arr.size();
    int count = 0;
    for(int i=0; i<n-1; i++){
        int min = i;
        for(int j=i+1; j<n; j++){
            if(arr[j] < arr[min]){
                min = j;
            }
        }
        if(min != i){
            swap(arr[i], arr[min]);
            count++;
        }
    }
    return count;
}

int bubbleSort(vector<int> &arr){
    int n = arr.size();
    int count = 0;
    for(int i=0; i<n-1; i++){
        for(int j=0; j<n-i-1; j++){
            if(arr[j] > arr[j+1]){
                swap(arr[j], arr[j+1]);
                count++;
            }
        }
    }
    return count;
}

int insertionSort(vector<int> &arr){
    int n = arr.size();
    int count = 0;
    for(int i=1; i<n; i++){
        int key = arr[i];
        int j = i-1;
        while(j>=0 && arr[j]>key){
            arr[j+1] = arr[j];
            j--;
            count++;
        }
        arr[j+1] = key;
    }
    return count;
}

int merge(vector<int> &arr, int l, int m, int r){
    int n1 = m-l+1;
    int n2 = r-m;
    int count = 0;
    int L[n1], R[n2];
    for(int i=0; i<n1; i++){
        L[i] = arr[l+i];
    }
    for(int i=0; i<n2; i++){
        R[i] = arr[m+1+i];
    }
    int i=0, j=0, k=l;
    while(i<n1 && j<n2){
        if(L[i] <= R[j]){
            arr[k] = L[i];
            i++;
        }
        else{
            arr[k] = R[j];
            j++;
            count += n1-i;
        }
        k++;
    }
    while(i<n1){
        arr[k] = L[i];
        i++;
        k++;
    }
    while(j<n2){
        arr[k] = R[j];
        j++;
        k++;
    }
    return count;
}

int mergeSort(vector<int> &arr, int l, int r){
    int count = 0;
    if(l<r){
        int m = l+(r-l)/2;
        count += mergeSort(arr, l, m);
        count += mergeSort(arr, m+1, r);
        count += merge(arr, l, m, r);
    }
    return count;
}

int partition(vector<int> &arr, int l, int r){
    int pivot = arr[r];
    int i = l-1;
    for(int j=l; j<r; j++){
        if(arr[j] < pivot){
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i+1], arr[r]);
    return i+1;
}

int quickSort(vector<int> &arr, int l, int r){
    int count = 0;
    if(l<r){
        int p = partition(arr, l, r);
        count += quickSort(arr, l, p-1);
        count += quickSort(arr, p+1, r);
        count += r-l;
    }
    return count;
}

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int> arr(n);
        for(int i=0; i<n; i++){
            cin >> arr[i];
        }
        int count = 0;
        // count = selectionSort(arr);
        // count = bubbleSort(arr);
        // count = insertionSort(arr);
        // count = mergeSort(arr, 0, n-1);
        count = quickSort(arr, 0, n-1);
        cout << count << endl;
    }
    return 0;
}

