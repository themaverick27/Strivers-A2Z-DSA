/*
Problem Statement: Given an array of integers, find the nearest smaller number for every element such that the smaller element is on the left side.

Example 1:
Input: arr[] = {1, 6, 4, 10, 2, 5}
Output: {-1, 1, 1, 4, 1, 2}

Example 2: 
Input: arr[] = {1, 3, 0, 2, 5}
Output:    {-1, 1, -1, 0, 2}
*/
#include<bits/stdc++.h>
using namespace std;

int findSmaller(vector<int>& arr, int idx, int ele){
    int n = arr.size();

    for(int i = idx-1; i >= 0; i--){
        if(arr[i] < ele) return arr[i];
    }
    return -1;
}

vector<int> previousSmallerElement(vector<int>& arr){
    int n = arr.size();

    // Approach-2: using stack
    // Time Complexity: O(n) and Space Complexity: O(n)
    vector<int> pse(n);
    stack<int> st;
    for(int i = 0; i < n; i++){
        while(!st.empty() && (st.top() >= arr[i])){
            st.pop();
        }
        if(st.empty()) pse[i] = -1;
        else pse[i] = st.top();

        st.push(arr[i]);
    }
    return pse;


    // Approach-1: traverse and pick an element from the back, and find the previous smaller 
    // Time Complexity: O(n*n) and Space Complexity: O(1)
    /*
    vector<int> pse(n);
    for(int i = n-1; i >= 0; i--){
        int ele = arr[i];

        int smaller = findSmaller(arr, i, ele);
        pse[i] = smaller;
    }
    return pse;
    */
}

int main(){
    vector<int> arr = {1, 5, 0, 3, 4, 5};

    vector<int> ans = previousSmallerElement(arr);
    for(int i = 0; i < ans.size(); i++){
        cout << ans[i] << " ";
    }

    return 0;
}