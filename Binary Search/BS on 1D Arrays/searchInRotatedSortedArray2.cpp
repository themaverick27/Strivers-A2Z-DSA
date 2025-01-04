/*
Problem Statement: Given an integer array arr of size N, sorted in ascending order (may contain duplicate values) and a target value k. 
Now the array is rotated at some pivot point unknown to you. Return True if k is present and otherwise, return False. 

Example 1:
Input: arr = [7, 8, 1, 2, 3, 3, 3, 4, 5, 6], k = 3
Output: True
Explanation: The element 3 is present in the array. So, the answer is True.

Example 2:
Input: arr = [7, 8, 1, 2, 3, 3, 3, 4, 5, 6], k = 10
Output: False
Explanation: The element 10 is not present in the array. So, the answer is False.
*/
#include<bits/stdc++.h>
using namespace std;

bool searchElement(vector<int>& arr, int k){
    int n = arr.size();

    // Approach-2: Binary Search
    // Time Complexity: O(log n) and Space Complexity: O(1)
    int low = 0, high = n-1;
    while(low <= high){
        int mid = low + (high-low)/2;

        if(arr[mid] == k) return true;

        // edge case - due to duplicates
        if(arr[low] == arr[mid] && arr[mid] == arr[high]){
            low += 1;
            high -= 1;
            continue;
        }

        // left part is sorted
        if(arr[low] <= arr[mid]){
            if(arr[low] <= k && k <= arr[mid]){
                high = mid - 1;
            }
            else{
                low = mid + 1;
            }
        }
        // right part is sorted
        else{
            if(arr[mid] <= k && k <= arr[high]){
                low = mid + 1;
            }
            else{
                high = mid - 1;
            }

        }

    }
    return false;




    // Approach-1: Linear Search
    // Time Complexity: O(n) and Space Complexity: O(1)
}

int main(){
    vector<int> arr = {7, 8, 1, 2, 3, 3, 3, 4, 5, 6};
    int k = 3;

    searchElement(arr, k);

    return 0;
}