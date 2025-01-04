/*
Problem Statement: Given an array of length N. Peak element is defined as the element greater than both of its neighbors. 
Formally, if 'arr[i]' is the peak element, 'arr[i - 1]' < 'arr[i]' and 'arr[i + 1]' < 'arr[i]'. 
Find the index(0-based) of a peak element in the array. If there are multiple peak numbers, return the index of any peak number.

Note: For the first element, the previous element should be considered as negative infinity as well as for the last element, the next element should be considered as negative infinity.

Example 1:
Input: arr[] = {1,2,3,4,5,6,7,8,5,1}
Output: 7
Explanation: In this example, there is only 1 peak that is at index 7.

Example 2:
Input: arr[] = {1,2,1,3,5,6,4}
Output: 1
Explanation: In this example, there are 2 peak numbers that are at indices 1 and 5. We can consider any of them.

Example 3:
Input: arr[] = {5, 4, 3, 2, 1}
Output: 0
Explanation: In this example, there is only 1 peak that is at the index 0.
*/
#include<bits/stdc++.h>
using namespace std;

int peakElementIndex(vector<int>& arr){
    int n = arr.size();

    // Approach-2: Binary Search
    // Time Complexity: O(log n) and Space Complexity: O(1)
    if(n == 1) return 0;
    if(arr[0] > arr[1]) return 0;
    if(arr[n-2] < arr[n-1]) return n-1;

    int low = 1, high = n-2;
    while(low <= high){
        int mid = low + (high-low)/2;

        if(arr[mid-1] < arr[mid] && arr[mid] > arr[mid+1]) return mid;

        if(arr[mid] > arr[mid-1]){
            // we are on the left part, peak element is on the right side
            low = mid + 1;
        }
        else{
            // we are on the right part or arr[mid] is common point, peak element is on the left side
            high = mid - 1;
        }
    }
    return -1; // dummy return



    // Approach-1: Linear Search
    // Time Complexity: O(n) and Space Complexity: O(1)
    /*
    for(int i = 0; i < n; i++){
        if((i == 0 || arr[i-1] < arr[i]) && (i == n-1 || arr[i] > arr[i+1])) return i;
    }
    return -1; // dummy return
    */
}

int main(){
    vector<int> arr = {1, 2, 3, 4, 5, 6, 7, 8, 5, 1};

    int ans = peakElementIndex(arr);
    cout << ans << endl;

    return 0;
}