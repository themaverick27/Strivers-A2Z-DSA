/*
Problem Statement: Given an integer array arr of size N, sorted in ascending order (with distinct values). 
Now the array is rotated between 1 to N times which is unknown. Find the minimum element in the array. 

Example 1:
Input: arr = [4,5,6,7,0,1,2,3]
Output: 0
Explanation: Here, the element 0 is the minimum element in the array.

Example 2:
Input: arr = [3,4,5,1,2]
Output: 1
Explanation: Here, the element 1 is the minimum element in the array.
*/
#include<bits/stdc++.h>
using namespace std;

int minimumElement(vector<int>& arr){
    int n = arr.size();

    // Approach-2: Binary Search
    // Time Complexity: O(log n) and Space Complexity: O(1)
    int low = 0, high = n-1;
    int ans = INT_MAX;

    while(low <= high){
        int mid = low + (high-low)/2;

        if(arr[low] <= arr[high]){
            ans = min(ans, arr[low]);
            break;
        }

        // left part is sorted
        if(arr[low] <= arr[mid]){
            ans = min(ans, arr[low]);
            low = mid + 1;
        }
        // right part is sorted
        else{
            ans = min(ans, arr[mid]);
            high = mid - 1;

        }
    }
    return ans;



    // Approach-1: Linear Search
    // Time Complexity: O(n) and Space Complexity: O(1)
}

int main(){
    vector<int> arr = {4, 5, 6, 7, 0, 1, 2, 3};

    int ans = minimumElement(arr);
    cout << ans << endl;

    return 0;
}