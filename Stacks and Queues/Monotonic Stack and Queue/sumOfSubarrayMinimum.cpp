/*
Problem Statement: Given an array of integers arr, find the sum of min(b), where b ranges over every (contiguous) subarray of arr. 
Since the answer may be large, return the answer modulo 10^9 + 7.

Example 1:
Input: arr = [3,1,2,4]
Output: 17
Explanation: Subarrays are [3], [1], [2], [4], [3,1], [1,2], [2,4], [3,1,2], [1,2,4], [3,1,2,4]. 
Minimums are 3, 1, 2, 4, 1, 1, 2, 1, 1, 1. Total Sum is 17.

Example 2:
Input: arr = [11,81,94,43,3]
Output: 444
*/
#include<bits/stdc++.h>
using namespace std;

vector<int> findNSE(vector<int>& arr){
    int n = arr.size();

    stack<int> st; 
    vector<int> nse(n);
    for(int i = n-1; i >= 0; i--){
        while(!st.empty() && (arr[st.top()] > arr[i])){
            st.pop();
        }
        if(st.empty()) nse[i] = n;
        else nse[i] = st.top();

        st.push(i);
    }
    return nse;
}

vector<int> findPSE(vector<int>& arr){
    int n = arr.size();

    stack<int> st; 
    vector<int> pse(n);
    for(int i = 0; i < n; i++){
        while(!st.empty() && (arr[st.top()] >= arr[i])){
            st.pop();
        }
        if(st.empty()) pse[i] = -1;
        else pse[i] = st.top();

        st.push(i);
    }
    return pse;
}


int sumOfSubarrayMinimum(vector<int>& arr){
    int n = arr.size();

    // Approach-2: using stack - finding nse and pse with indices and calculating individual element contribution as minimum in the subarray
    // Time Complexity: O(n) approx and Space Complexity: O(n) approx
    
    vector<int> nse = findNSE(arr);
    vector<int> pse = findPSE(arr);

    int mod = (int) (1e9 + 7);
    long long ans = 0;
    for(int i = 0; i < n; i++){
        int left = i - pse[i];
        int right = nse[i] - i;

        ans = (ans + (right * left * 1LL * arr[i]) % mod) % mod;
    }
    return ans;



    // Approach-1: using two nested loops - generating all possible subarray and updating mininum element
    // Time Complexity: O(n*n) approx and Space Complexity: O(1)
    /*
    int ans = 0;
    int mod = (int) (1e9 + 7);

    for(int i = 0; i < n; i++){
        int minElement = arr[i];
        for(int j = i; j < n; j++){
            minElement = min(minElement, arr[j]);

            ans = (ans + minElement) % mod;
        }
    }
    return ans;
    */
}

int main(){
    vector<int> arr = {3, 1, 2, 4};

    int ans = sumOfSubarrayMinimum(arr);
    cout << ans << endl;

    return 0;
}