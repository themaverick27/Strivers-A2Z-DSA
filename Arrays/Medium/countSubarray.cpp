/*
Problem Statement: Given an array of integers and an integer k, return the total number of subarrays whose sum equals k.

Note: A subarray is a contiguous non-empty sequence of elements within an array.

Example 1:
Input Format: N = 4, array[] = {3, 1, 2, 4}, k = 6
Result: 2
Explanation: The subarrays that sum up to 6 are [3, 1, 2] and [2, 4].

Example 2:
Input Format: N = 3, array[] = {1,2,3}, k = 3
Result: 2
Explanation: The subarrays that sum up to 3 are [1, 2], and [3].
*/
#include<bits/stdc++.h>
using namespace std;

int countSubarrayWithSumK(vector<int> &arr, int k){
    int n = arr.size();

    // Approach-2: concept of prefix sum and Hashmap
    // Time Complexity: O(n*log n) - if we use ordered map and Space Complexity: O(n)
    // Time Complexity: O(n) - if we unordered map but in the worst case it goes O(n*n) and Space Complexity: O(1)
    map<int, int> mpp;
    mpp[0] = 1;

    int count = 0;
    long long prefixSum = 0;
    for(int i = 0; i < n; i++){
        prefixSum += arr[i];
        long long moreNeeded = prefixSum - k;

        count += mpp[moreNeeded];
        mpp[prefixSum] += 1; // update the count of prefix sum in the map
    }
    return count;


    // Approach-1: find all possible subarray
    // Time Complexity: O(n*n) and Space Complexity: O(1)
    /*
    int count = 0;
    for(int i = 0; i < n; i++){
        int sum = 0;
        for(int j = i; j < n; j++){
            sum += arr[j];

            if(sum == k) count++;
        }
    }
    return count;
    */
}

int main(){
    vector<int> arr = {1, 2, 3, 1, 1, 2, 2, 3, 5, 7, 8, 2};
    int target = 5;

    int count = countSubarrayWithSumK(arr, target);
    cout << "Total number of subarrays with sum equals to k is: " << count << endl;

    return 0;
}