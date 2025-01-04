/*
Problem Statement: Given an array of N integers. Every number in the array except one appears twice. 
Find the single number in the array.

Example 1:
Input: arr[] = {1,1,2,2,3,3,4,5,5,6,6}
Output: 4
Explanation: Only the number 4 appears once in the array.

Example 2:
Input: arr[] = {1,1,3,5,5}
Output: 3
Explanation: Only the number 3 appears once in the array.
*/
#include<bits/stdc++.h>
using namespace std;

int singleElement(vector<int>& arr){
    int n = arr.size();
    // Approach-3: Binary Search
    // Time Complexity: O(log n) and Space Complexity: O(1)

    // edge case
    if(n == 1) return arr[0];
    if(arr[0] != arr[1]) return arr[0]; // first element is single element
    if(arr[n-1] != arr[n-2]) return arr[n-1]; // last element is single element

    int low = 1, high = n-2;
    while(low <= high){
        int mid = low + (high-low)/2;

        if(arr[mid] != arr[mid-1] && arr[mid] != arr[mid+1]) return arr[mid];

        if((mid % 2 == 0) && (arr[mid] == arr[mid+1]) || (mid % 2 == 1 && arr[mid] == arr[mid-1])){
            // we are in the left part
            low = mid + 1; // single element is on the right side
        }
        else{
            // we are in the right part
            high = mid - 1; // single element is on the left side
        }
    }
    return -1; // dummy return




    // Approach-2: using XOR properties
    // Time Complexity: O(n) and Space Complexity: O(1)
    /*
    int single = 0;
    for(int i = 0; i < n; i++){
        single ^= arr[i];
    }
    return single;
    */


    // Approach-1: by checking previous and next element (as sorted array)
    // Time Complexity: O(n) and Space Complexity: O(1)
    /*
    if(n == 1) return arr[0];

    for(int i = 0; i < n; i++){
        if(i == 0){
            if(arr[i] != arr[i+1]) return arr[i];
        }
        else if(i == n-1){
            if(arr[i] != arr[i-1]) return arr[i];
        }
        if(arr[i] != arr[i-1] && arr[i] != arr[i+1])
            return arr[i];
    }
    return -1; // dummy return
    */

}

int main(){
    vector<int> arr = {1, 1, 2, 2, 3, 3, 4, 5, 5, 6, 6};

    int ans = singleElement(arr);
    cout << ans << endl;

    return 0;
}