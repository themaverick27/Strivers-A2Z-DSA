/*
Problem Statement: You are given an integer array nums. The range of a subarray of nums is the difference between the largest and smallest element in the subarray.
Return the sum of all subarray ranges of nums.

Example 1:
Input: nums = [1,2,3]
Output: 4
Explanation: The 6 subarrays of nums are the following:
[1], range = largest - smallest = 1 - 1 = 0 
[2], range = 2 - 2 = 0
[3], range = 3 - 3 = 0
[1,2], range = 2 - 1 = 1
[2,3], range = 3 - 2 = 1
[1,2,3], range = 3 - 1 = 2
So the sum of all ranges is 0 + 0 + 0 + 1 + 1 + 2 = 4.

Example 2:
Input: nums = [1,3,3]
Output: 4
*/
#include<bits/stdc++.h>
using namespace std;

long long sumOfSubarrayRanges(vector<int>& arr){
    int n = arr.size();

    // Approach-2: using stack 
    // Sum of subarray minimum -> finding nse and pse with indices and calculating individual element contribution as minimum in the subarray
    // Sum of subarray maximum -> finding nge and pgee with indices and calculating individual element contribution as maximum in the subarray
    // Time Complexity: O(n) approx and Space Complexity: O(n) approx

    long long sum = 0;
    stack<int> st;

    vector<int> pse(n, -1);
    vector<int> nse(n, n);
    vector<int> pge(n, -1);
    vector<int> nge(n, n);

    // previous smaller element
    for(int i = 0; i < n; i++){
        while(!st.empty() && (arr[st.top()] >= arr[i])) st.pop();

        if(st.empty()) pse[i] = -1;
        else pse[i] = st.top();

        st.push(i);
    }
    while(!st.empty()) st.pop();

    // next smaller elemet
    for(int i = n-1; i >= 0; i--){
        while(!st.empty() && (arr[st.top()] > arr[i])) st.pop();

        if(st.empty()) nse[i] = n;
        else nse[i] = st.top();

        st.push(i);
    }
    while(!st.empty()) st.pop();

    // previous greater element
    for(int i = 0; i < n; i++){
        while(!st.empty() && (arr[st.top()] <= arr[i])) st.pop();

        if(st.empty()) pge[i] = -1;
        else pge[i] = st.top();

        st.push(i);
    }
    while(!st.empty()) st.pop();

    // next greater element
    for(int i = n-1; i >= 0; i--){
        while(!st.empty() && (arr[st.top()] < arr[i])) st.pop();

        if(st.empty()) nge[i] = n;
        else nge[i] = st.top();

        st.push(i);
    }
    while(!st.empty()) st.pop();

    for(int i = 0; i < n; i++){
        long long leftMin = i - pse[i];
        long long rightMin = nse[i] - i;
        long long leftMax = i - pge[i];
        long long rightMax = nge[i] - i;

        sum += ((leftMax * rightMax) - (leftMin * rightMin)) * arr[i];
    }
    return sum;
    

    // Approach-1: using nested loops - generating all possible subarray
    // Time Complexity: O(n*n) approx and Space Complexity: O(1)
    /*
    long long ans = 0;
    for(int i = 0; i< n; i++){
        int minElement = arr[i];
        int maxElement = arr[i];
        for(int j = i; j < n; j++){
            minElement = min(minElement, arr[j]);
            maxElement = max(maxElement, arr[j]);

            ans += (maxElement - minElement);
        }
    }
    return ans;
    */
}


int main(){
    vector<int> arr = {1, 3, 3};

    long long ans = sumOfSubarrayRanges(arr);
    cout << ans << endl;

    return 0;
}