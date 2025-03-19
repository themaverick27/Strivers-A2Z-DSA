#include<bits/stdc++.h>
using namespace std;

void bubbleSortRec(vector<int>& arr, int n){
    // base case
    if(n == 1) return;

    for(int j = 0; j < n - 1; j++){
        if(arr[j] > arr[j + 1]){
            swap(arr[j], arr[j+1]);
        }
    }

    bubbleSortRec(arr, n - 1);
}


int main(){
    vector<int> arr = {4, 1, 3, 9, 7};

    cout << "Array before sorting: ";
    for(int i = 0; i < arr.size(); i++){
        cout << arr[i] << " ";
    }
    cout << endl;

    bubbleSortRec(arr, arr.size());

    cout << "Array after sorting (bubble sort): ";
    for(int i = 0; i < arr.size(); i++){
        cout << arr[i] << " ";
    }

    return 0;
}
// Time Complexity: O(n*n) - average and worst case, O(n) - best case (if the input array is already in sorted order)
// Space Complexity: O(1)