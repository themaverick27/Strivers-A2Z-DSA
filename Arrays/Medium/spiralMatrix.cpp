/*
Given an m x n matrix, return all elements of the matrix in spiral order.

Example 1:
Input: matrix = [[1,2,3],[4,5,6],[7,8,9]]
Output: [1,2,3,6,9,8,7,4,5]
Explanation: The output of matrix in spiral form.

Example 2:
Input: matrix = [[1,2,3,4],[5,6,7,8],[9,10,11,12]]
Output: [1,2,3,4,8,12,11,10,9,5,6,7]
Explanation: The output of matrix in spiral form.
*/
#include<bits/stdc++.h>
using namespace std;

vector<int> spiralMatrix(vector<vector<int>> &matrix){
    int n = matrix.size();
    int m = matrix[0].size();

    // Approach-1: using boundary conditions (four loops)
    // Time Complexity: O(N*M) and Space Complexity: O(1)
    vector<int> ans;
    int top = 0, bottom = n-1, left = 0, right = m-1;

    while(top <= bottom && left <= right){
        // moving left to right
        for(int i = left; i <= right; i++){
            ans.push_back(matrix[top][i]);
        }
        top++;

        // moving top to bottom
        for(int i = top; i <= bottom; i++){
            ans.push_back(matrix[i][right]);
        }
        right--;

        // moving right to left
        if(top <= bottom){
            for(int i = right; i >= left; i--){
                ans.push_back(matrix[bottom][i]);
            }
            bottom--;
        }

        // moving bottom to top
        if(left <= right){
            for(int i = bottom; i >= top; i--){
                ans.push_back(matrix[i][left]);
            }
            left++;
        }
    }
    return ans;

}

int main(){
    vector<vector<int>> matrix = {{1,2,3}, {4,5,6}, {7,8,9}};
    int n = matrix.size();

    vector<int> ans = spiralMatrix(matrix);

    for(int i = 0; i < ans.size(); i++){
            cout << ans[i] << " ";
    }

    return 0;
}