#include<bits/stdc++.h>
using namespace std;

void merge(vector<int>& arr, int low, int mid, int high){
    vector<int> temp;
    int left = low;
    int right = mid+1;

    while(left <= mid && right <= high){
        if(arr[left] <= arr[right]){
            temp.push_back(arr[left]);
            left++;
        }
        else{
            temp.push_back(arr[right]);
            right++;
        }
    }

    // if right part exhausted
    while(left <= mid){
        temp.push_back(arr[left]);
        left++;
    }

    // if left part exhausted
    while(right <= high){
        temp.push_back(arr[right]);
        right++;
    }

    // copying the elements into original array
    for(int i = low; i <= high; i++){
        arr[i] = temp[i - low];
    }
}


void mergeSort(vector<int>& arr, int low, int high){
    if(low >= high) return;

    int mid = (low + high)/2;
    mergeSort(arr, low, mid);
    mergeSort(arr, mid+1, high);

    merge(arr, low, mid, high);
}


int main(){
    vector<int> arr = {4, 1, 3, 9, 7};

    cout << "Array before sorting: ";
    for(int i = 0; i < arr.size(); i++){
        cout << arr[i] << " ";
    }
    cout << endl;

    mergeSort(arr, 0, arr.size()-1);

    cout << "Array after sorting (merge sort): ";
    for(int i = 0; i < arr.size(); i++){
        cout << arr[i] << " ";
    }

    return 0;
}
// Time Complexity: O(n* log n)
// Space Complexity: O(n) - temp array