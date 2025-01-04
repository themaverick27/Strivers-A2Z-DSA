/*
Problem Statement: Given an integer array arr of size N, sorted in ascending order (with distinct values). 
Now the array is rotated between 1 to N times which is unknown. Find how many times the array has been rotated. 

Example 1:
Input: arr = [4,5,6,7,0,1,2,3]
Output: 4
Explanation: The original array should be [0,1,2,3,4,5,6,7]. So, we can notice that the array has been rotated 4 times.

Example 2:
Input: arr = [3,4,5,1,2]
Output: 3
Explanation: The original array should be [1,2,3,4,5]. So, we can notice that the array has been rotated 3 times.
*/
#include<bits/stdc++.h>
using namespace std;

int findKRotation(vector<int>& arr){
    int n = arr.size();

    // Approach-2: Binary Search 
    // Time Complexity: O(log n) and Space Complexity: O(1)
    int low = 0, high = n-1;
    int ans = INT_MAX;
    int idx = -1;

    while(low <= high){
        int mid = low + (high-low)/2;

        if(arr[low] < arr[high]){
            if(arr[low] <= ans){
                ans = arr[low];
                idx = low;
            }
            break;
        }

        // left part is sorted
        if(arr[low] <= arr[mid]){
            if(arr[low] <= ans){
                ans = arr[low];
                idx = low;
            }
            low = mid + 1;
        }
        // right part is sorted
        else{
            if(arr[mid] <= ans){
                ans = arr[mid];
                idx = mid;
            }
            high = mid - 1;
        }
    }
    return idx;

    

    // Approach-1: Linear Search
    // Time Complexity: O(n) and Space Complexity: O(1)
}

int main(){
    vector<int> arr = {4, 5, 6, 7, 0, 1, 2, 3};

    int ans = findKRotation(arr);
    cout << ans << endl;

    return 0;
}