#include<bits/stdc++.h>
using namespace std;

void bubbleSort(int arr[], int n){
    for(int i = n-1; i > 0; i--){
        for(int j = 0; j < i; j++){
            if(arr[j] > arr[j+1]){
                swap(arr[j], arr[j+1]);
            }
        }
    }
}

void optimisedBubbleSort(int arr[], int n){
    for(int i = n-1; i > 0; i--){
        bool didSwap = false;
        for(int j = 0; j < i; j++){
            if(arr[j] > arr[j+1]){
                swap(arr[j], arr[j+1]);
                didSwap = true;
            }
        }
        if(didSwap == false){
            break;
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

    bubbleSort(arr, n);

    cout << "Array after sorting (bubble sort): ";
    for(int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }
    return 0;
}
// Time Complexity: O(n*n) - average and worst case, O(n) - best case (if the input array is already in sorted order)
// Space Complexity: O(1)