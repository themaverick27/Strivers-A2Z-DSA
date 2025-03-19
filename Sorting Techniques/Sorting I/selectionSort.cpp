#include<bits/stdc++.h>
using namespace std;

void selectionSort(int arr[], int n){
    
    for(int i = 0; i < n-1; i++){
        int minIndex = i; 
        for(int j = i+1; j < n; j++){
            if(arr[j] < arr[minIndex]){
                minIndex = j; 
            }
        }
        swap(arr[minIndex], arr[i]);
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

    selectionSort(arr, n);

    cout << "Array after sorting (selection sort): ";
    for(int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }
    return 0;
}
// Time Complexity: O(n*n)
// Space Complexity: O(1)