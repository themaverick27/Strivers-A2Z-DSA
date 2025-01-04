/*
Problem Statement: Given an integer array arr of size N, sorted in ascending order (with distinct values) and a target value k. 
Now the array is rotated at some pivot point unknown to you. Find the index at which k is present and if k is not present return -1.

Example 1:
Input Format: arr = [4,5,6,7,0,1,2,3], k = 5
Result: 4
Explanation: Here, the target is 0. We can see that 0 is present in the given rotated sorted array, nums. Thus, we get output as 4, which is the index at which 0 is present in the array.

Example 2:
Input Format: arr = [4,5,6,7,0,1,2], k = 3
Result: -1
Explanation: Here, the target is 3. Since 3 is not present in the given rotated sorted array. Thus, we get the output as -1.
*/
#include<bits/stdc++.h>
using namespace std;

int searchElement(vector<int>& arr, int k){
    int n = arr.size();

    // Approach-2: Binary Search 
    // Time Complexity: O(log n) and Space Complexity: O(1)
    int low = 0, high = n-1;
    while(low <= high){
        int mid = low + (high- low)/2;

        if(arr[mid] == k) return mid;

        // left part is sorted
        if(arr[low] <= arr[mid]){ 
            if(arr[low] <= k && k <= arr[mid]){
                high = mid - 1; // element exists
            }
            else low = mid + 1; // element doesn't exists
        }
        // right part is sorted
        else{
            if(arr[mid] <= k && k <= arr[high]){
                low = mid + 1; // element exists
            }
            else{
                high = mid - 1; // element doesn't exists
            }
        }
    }
    return -1;

    // Approach-1: Linear Search
    // Time Complexity: O(n) and Space Complexity: O(1)

}

int main(){
    vector<int> arr = {4, 5, 6, 7, 0, 1, 2, 3};
    int k = 0;

    int ans = searchElement(arr, k);
    cout << ans << endl;

    return 0;
}