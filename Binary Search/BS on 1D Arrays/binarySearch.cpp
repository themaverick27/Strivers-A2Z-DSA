/*
Problem Statement: Given a sorted array arr and an integer k, find the position(0-based indexing) at which k is present in the array using binary search.

Note: If multiple occurrences are there, please return the smallest index.

Example 1:
Input: arr[] = [1, 2, 3, 4, 5], k = 4
Output: 3
Explanation: 4 appears at index 3.

Example 2:
Input: arr[] = [11, 22, 33, 44, 55], k = 445
Output: -1
Explanation: 445 is not present.

Example 3:
Input: arr[] = [1, 1, 1, 1, 2], k = 1
Output: 0
Explanation: 1 appears at index 0.
*/
#include<bits/stdc++.h>
using namespace std;

// recursive implementation of Binary Search
int BS(vector<int>& arr, int target, int low, int high){

    if(low > high) return -1; // base case
    
    int mid = low + (high-low)/2;
    if(arr[mid] == target) return mid;
    else if(arr[mid] > target) {
        return BS(arr, target, low, mid-1);
    }
    else{
        return BS(arr, target, mid + 1, high);
    }
}

// iterative implementation of Binary Search
int binarySearch(vector<int>& arr, int target){
    int n = arr.size();

    // Binary Search Algorithm (Iterative)
    // Time Complexity: O(log n) and Space Complexity: O(1)

    int low = 0, high = n-1;
    while(low <= high){
        int mid = low + (high-low)/2;

        if(arr[mid] == target){
            return mid;
        }
        else if(arr[mid] > target){
            high = mid - 1;
        }
        else{
            low = mid + 1;
        }
    }
    return -1;
}

int main(){
    vector<int> arr = {3, 4, 6, 7, 9, 12, 16, 17};
    int target = 6;

    int index = binarySearch(arr, target);
    cout << "Element at index: " << index << endl;

    // int idx = BS(arr, target, 0, arr.size() - 1);
    // cout << "Element at index: " << idx << endl;

    // C++ STL
    bool res = binary_search(arr.begin(), arr.end(), target);
    if(res) cout << "target element is present!" << endl;
    else cout << "target element is not present!" << endl;

    return 0;
}