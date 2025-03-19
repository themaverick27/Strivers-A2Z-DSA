#include<bits/stdc++.h>
using namespace std;

void insertionSortRec(vector<int>& arr, int i, int n){
    // base case
    if (i == n) return;

    int j = i;
    while(j > 0 && arr[j - 1] > arr[j]){
        swap(arr[j-1], arr[j]);
        j--;
    }

    insertionSortRec(arr, i + 1, n);
}


int main(){
    vector<int> arr = {4, 1, 3, 9, 7};

    cout << "Array before sorting: ";
    for(int i = 0; i < arr.size(); i++){
        cout << arr[i] << " ";
    }
    cout << endl;

    insertionSortRec(arr, 0, arr.size());

    cout << "Array after sorting (insertion sort): ";
    for(int i = 0; i < arr.size(); i++){
        cout << arr[i] << " ";
    }

    return 0;
}
// Time Complexity: O(n*n) - average and worst case, O(n) - best case (if the input array is already in sorted order)
// Space Complexity: O(1)