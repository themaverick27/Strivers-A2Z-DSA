#include<bits/stdc++.h>
using namespace std;

void insertionSort(int arr[], int n){
    
    for(int i = 1; i < n-1; i++){
        int j = i;
        while(j > 0 && arr[j-1] > arr[j]){
            swap(arr[j-1], arr[j]);
            j--;
        }
    }
}


int main(){ 
    int arr[] = {4, 1, 3, 9, 7};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Array before sorting: ";
    for(int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }
    cout << endl;

    insertionSort(arr, n);

    cout << "Array after sorting (insertion sort): ";
    for(int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }
    return 0;
}
// Time Complexity: O(n*n) - average and worst case, O(n) - best case (if the input array is already in sorted order)
// Space Complexity: O(1)