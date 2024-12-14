/*
Problem Statement: Given an array and a sum k, we need to print the length of the longest subarray that sums to k.

Example 1:
Input Format: N = 3, k = 5, array[] = {2,3,5}
Result: 2
Explanation: The longest subarray with sum 5 is {2, 3}. And its length is 2.

Example 2:
Input Format: N = 5, k = 10, array[] = {2,3,5,1,9}
Result: 3
Explanation: The longest subarray with sum 10 is {2, 3, 5}. And its length is 3.
*/

#include<bits/stdc++.h>
using namespace std;

int longestSubarray(vector<int>& arr, int target){
    int n = arr.size();

    // Approach-4: using two pointer
    // Time Complexity: O(2*n) and Space Complexity: O(1)
    int left = 0, right = 0;
    long long sum = arr[0];
    int maxLength = 0;
    while(right < n){
        while(left <= right && sum > target){
            sum -= arr[left];
            left++;
        }
        if(sum == target){
            maxLength = max(maxLength, right-left+1);
        }
        right++;
        if(right < n) sum += arr[right];
    }
    return maxLength;

    // Approach-3: using hashmap & prefix sum
    // Time Complexity: O(n*log n) - if we use ordered map and Space Complexity: O(n)
    // Time Complexity: O(n) - if we unordered map but in the worst case it goes O(n*n) and Space Complexity: O(1)
    /*
    map<long long, int> preSumMap;
    long long sum = 0;
    int maxLength = 0;
    for(int i = 0; i < n; i++){
        sum += arr[i];
        if(sum == target){
            maxLength = max(maxLength, i+1);
        } 

        long long remaining = sum - target;
        if(preSumMap.find(remaining) != preSumMap.end()){
            int len = i - preSumMap[remaining];
            maxLength = max(maxLength, len);
        }
        if(preSumMap.find(sum) == preSumMap.end()){
            preSumMap[sum] = i;
        }
    }
    return maxLength;
    */


    // Approach-2: slight modification in the prevoius approach
    // Time Complexity: O(N*N) and Space Complexity: O(1)
    /*
    int maxLength = 0;
    for(int i = 0; i < n; i++){
        long long sum = 0;
        for(int j = i; j < n; j++){
            sum += arr[j];
            if(sum == target) maxLength = max(maxLength, j-i+1);
        }
        
    }
    return maxLength;
    */

    // Approach-1: generating all possible subarray and finding the longest subarray with sum k
    // Time Complexity: O(N*N*N) approx and Space Complexity: O(1)
    /*
    int maxLength = 0;
    for(int i = 0; i < n; i++){
        for(int j = i; j < n; j++){
            long long sum = 0;
            for(int k = i; k <= j; k++){
                sum += arr[k];
            }
            if(sum == target) maxLength = max(maxLength, j-i+1);
        }
    }
    return maxLength;
    */
}

int main(){

    vector<int> arr= {2, 3, 5, 1, 9};
    int target = 10;

    int ans = longestSubarray(arr, target);
    cout << "Longest Subaaray with sum k (positives): " << ans << endl;

    return 0;
}