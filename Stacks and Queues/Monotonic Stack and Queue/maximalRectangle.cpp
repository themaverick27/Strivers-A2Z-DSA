/*
Problem Statement: Given a rows x cols binary matrix filled with 0's and 1's, 
find the largest rectangle containing only 1's and return its area.

Example 1:
Input: matrix = [["1","0","1","0","0"],["1","0","1","1","1"],["1","1","1","1","1"],["1","0","0","1","0"]]
Output: 6

Example 2:
Input: matrix = [["0"]]
Output: 0

Example 3:
Input: matrix = [["1"]]
Output: 1
*/
#include<bits/stdc++.h>
using namespace std;

// function to calculate largest rectangle area in histogram
int largestRectangleArea(vector<int>& arr){
    int n = arr.size();
    stack<int> st;
    int maxArea = 0;
    int idx, curr;
    for(int i = 0; i < n; i++){      
        while (!st.empty() && (arr[st.top()] >= arr[i])){
            idx = st.top(); 
            st.pop();

            int width = st.empty() ? i : i - st.top() - 1;
            maxArea = max(maxArea,  arr[idx] * width);
        }
        st.push(i);
    }
    // if there are elements left in the stack
    while (!st.empty()) {
        idx = st.top(); 
        st.pop();

        curr = arr[idx] * (st.empty() ? n : n - st.top() - 1);
        maxArea = max(maxArea, curr);
    }
    return maxArea;
}

int maximalRectangle(vector<vector<int>>& matrix) {
    int n = matrix.size();
    int m = matrix[0].size();

    // Approach-1: Using Largest Rectangular Area in a Histogram
    // Time Complexity: O(n*m) and Space Complexity: O(m)
    vector<int> arr(m, 0);
    int ans = 0;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++) {
            if(matrix[i][j]==1){
                arr[j]++;
            }
            else arr[j] = 0;
        }
        ans = max(ans, largestRectangleArea(arr));
    }    
    return ans;
}

int main(){
    vector<vector<int>> mat = {
        {1, 0, 1, 0, 0},
        {1, 0, 1, 1, 1},
        {1, 1, 1, 1, 1},
        {1, 0, 0, 1, 0}
    };

    int ans = maximalRectangle(mat);
    cout << ans << endl;

    return 0;
}