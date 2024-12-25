/*
Problem Statement: Given an integer array arr, find the contiguous subarray (containing at least one number) which
has the largest sum and returns its sum and prints the subarray.

Example 1:
Input: arr = [-2,1,-3,4,-1,2,1,-5,4] 
Output: 6 
Explanation: [4,-1,2,1] has the largest sum = 6. 

Examples 2:
Input: arr = [1] 
Output: 1 
Explanation: Array has only one element and which is giving positive sum of 1.
*/
#include<bits/stdc++.h>
using namespace std;

void printSubarray(vector<int>& arr){
    int n = arr.size();
    // print the subarray with maximum sum
    int maxSum = INT_MIN;
    int sum = 0;

    int start = 0;
    int ansStart = -1, ansEnd = -1; // to keep track of the subarray
    for(int i = 0; i < n; i++){
        if(sum == 0) start = i;
        sum += arr[i];

        if(sum > maxSum){ 
            maxSum = sum;
            ansStart = start;
            ansEnd = i;
        }

        if(sum < 0) sum = 0;
    }

    //printing the subarray:
    cout << "The subarray is: ";
    for (int i = ansStart; i <= ansEnd; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int maximumSubarraySum(vector<int>& arr){
    int n = arr.size();

    // Approach-3: Kadane's Algorithm
    // Time Complexity: O(n) and Space Complexity: O(1)
    long long sum = 0;
    long long maxiSum = LONG_MIN;
    for(int i = 0; i < n; i++){
        sum += arr[i];

        if(sum < 0){
            sum = 0;
        }
        maxiSum = max(maxiSum, sum);
    }
    return maxiSum;

    // Approach-2: Optimising the brute (approach-1)
    // Time Complexity: O(n*n) and Space Complexity: O(1)
    /*
    int maxSum = INT_MIN;
    for(int i = 0; i < n; i++){
        int sum = 0;
        for(int j = i; j < n; j++){
            sum += arr[j];

            maxSum = max(maxSum, sum);
        }
    }
    return maxSum;
    */

    // Approach-1: finding all the possible subarray and checking the maximum sum
    // Time Complexity: O(n*n*n) and Space Complexity: O(1)
    /*
    int maxSum = INT_MIN;
    for(int i = 0; i < n; i++){
        for(int j = i; j < n; j++){
            int sum = 0;
            for(int k = i; k <= j; k++){
                sum += arr[k];
            }
            maxSum = max(maxSum, sum);
        }
    }
    return maxSum;
    */
}

int main(){
    vector<int> arr = {-2, 1, -3, 4, -1, 2, 1, -5, 4};

    int ans = maximumSubarraySum(arr);
    cout << "Maximum sum: " << ans << endl;

    return 0;
}