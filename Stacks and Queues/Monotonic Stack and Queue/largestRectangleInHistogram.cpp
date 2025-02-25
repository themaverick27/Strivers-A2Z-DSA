/*
Problem Statement: Given an array of integers heights representing the histogram's bar height where the width of each bar is 1, 
return the area of the largest rectangle in the histogram.

Example 1:
Input: heights = [2,1,5,6,2,3]
Output: 10

Example 2:
Input: heights = [2,4]
Output: 4
*/
#include<bits/stdc++.h>
using namespace std;

vector<int> nextSmaller(vector<int>& arr){
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

vector<int> previousSmaller(vector<int>& arr){
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

int largestRectangleArea(vector<int>& arr){
    int n = arr.size();

    // Appraoch-2: Optimised the previous appraoch, computing nse and pse on the go - single stack
    // Time Complexity: O(2*n) and Space Complexity: O(n)
    stack<int> st;
    int maxArea = 0;

    int nse = n, pse = -1, idx = -1;
    for(int i = 0; i < n; i++){
        while(!st.empty() && (arr[st.top()] > arr[i])){
            idx = st.top();
            st.pop();
            // compute the pse and nse on the go
            nse = i;
            pse = (st.empty()) ? -1 : st.top();

            maxArea = max(maxArea, arr[idx] * (nse - pse - 1));
        }
        st.push(i);
    }
    // if there are elements left in the stack
    while(!st.empty()){
        nse = n;
        idx = st.top();
        st.pop();

        pse = (st.empty()) ? -1 : st.top();
        maxArea = max(maxArea, arr[idx] * (nse - pse - 1));
    }
    return maxArea;



    // Approach-1: precomputing nse and pse using two stacks
    // Time Complexity: O(n) and Space Complexity: O(n)
    /*
    vector<int> nse = nextSmaller(arr);
    vector<int> pse = previousSmaller(arr);

    int maxArea = 0;
    for(int i = 0; i < n; i++){
        int area = (arr[i] * (nse[i] - pse[i] - 1));

        maxArea = max(maxArea, area);
    }
    return maxArea;
    */
}

int main(){
    vector<int> arr {2, 1, 5, 6, 2, 3};

    int ans = largestRectangleArea(arr);
    cout << ans << endl;

    return 0;
}