/*
Problem Statement: Given a sorted array of N integers and an integer x, write a program to find the lower bound of x.

Note: The lower bound algorithm finds the first or the smallest index in a sorted array where the value at that index is greater than or equal to a given key i.e. x.
The lower bound is the smallest index, ind, where arr[ind] >= x. But if any such index is not found, the lower bound algorithm returns n i.e. size of the given array.

Example 1:
Input Format: N = 4, arr[] = {1,2,2,3}, x = 2
Output: 1
Explanation: Index 1 is the smallest index such that arr[1] >= x.

Example 2:
Input Format: N = 5, arr[] = {3,5,8,15,19}, x = 9
Output: 3
Explanation: Index 3 is the smallest index such that arr[3] >= x.
*/
#include<bits/stdc++.h>
using namespace std;

int lowerBound(vector<int>& arr, int x){
    int n = arr.size();

    // Approach-2: Binary Search
    // Time Complexity: O(log n) and Space Complexity: O(1)
    int low = 0, high = n-1;
    int idx = n;
    
    while(low <= high){
        int mid = low + (high-low)/2;

        if(arr[mid] >= x){
            idx = mid; // can be my answer
            high = mid - 1; // look for smaller index on the left
        }
        else{
            low = mid + 1; // look on thr right
        }
    }
    return idx;


    // Approach-1: Linear Search 
    // Time Complexity: O(n) and Space Complexity: O(1)
}

int main(){

    vector<int> arr = {3, 5, 8, 15, 19};
    int x = 9;

    int ans = lowerBound(arr, x);
    cout << ans << endl;

    // C++ STL
    int index = lower_bound(arr.begin(), arr.end(), x) - arr.begin(); 
    cout << "lower bound of x at index: " << index << endl;

    return 0;
}