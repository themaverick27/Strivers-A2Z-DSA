#include<bits/stdc++.h>
using namespace std;

int partition(vector<int>& arr, int low, int high){
    int pivot = arr[low]; // first element as pivot 
    int i = low;
    int j = high;

    while(i < j){
        // find the first element which is greater than pivot from left
        while(arr[i] <= pivot && i <= high-1){
            i++;
        }

        // find the first element which is smaller than pivot from right
        while(arr[j] > pivot && j >= low+1){
            j--;
        }

        if(i < j) swap(arr[i], arr[j]);
    }
    swap(arr[low], arr[j]);
    return j; // partition index
}


void quickSort(vector<int>& arr, int low, int high){
    if(low < high){
        int partitionIndex = partition(arr, low, high);;
        
        quickSort(arr, low, partitionIndex-1);
        quickSort(arr, partitionIndex+1, high);
    }
}

int main(){
    vector<int> arr = {4, 1, 3, 9, 7};

    cout << "Array before sorting: ";
    for(int i = 0; i < arr.size(); i++){
        cout << arr[i] << " ";
    }
    cout << endl;

    quickSort(arr, 0, arr.size()-1);

    cout << "Array after sorting (quick sort): ";
    for(int i = 0; i < arr.size(); i++){
        cout << arr[i] << " ";
    }

    return 0;
}
// Time Complexity: O(n* log n)
// Space Complexity: O(1)