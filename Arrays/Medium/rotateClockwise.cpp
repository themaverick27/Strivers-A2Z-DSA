/*
Problem Statement: Given a matrix, your task is to rotate the matrix 90 degrees clockwise.

Example 1:
Input: [[1,2,3],[4,5,6],[7,8,9]]
Output: [[7,4,1],[8,5,2],[9,6,3]]
Explanation: Rotate the matrix simply by 90 degree clockwise and return the matrix.

Example 2:
Input: [[5,1,9,11],[2,4,8,10],[13,3,6,7],[15,14,12,16]]
Output: [[15,13,2,5],[14,3,4,1],[12,6,8,9],[16,7,10,11]]
Explanation: Rotate the matrix simply by 90 degree clockwise and return the matrix.
*/
#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> rotateClockwise(vector<vector<int>> &matrix){
    int n = matrix.size();

    // Approach-2: Observation - by transpose and reversing the rows
    // Time Complexity: O(2*N*N) approx and Space Complexity: O(1)
    for(int i = 0; i < n-1; i++){
        for(int j = 0; j < i; j++){
            swap(matrix[i][j], matrix[j][i]); // transpose
        }
    }
    // reversing each rows of matrix
    for(int i = 0; i < n; i++){
        reverse(matrix[i].begin(), matrix[i].end());
    }
    return matrix;


    // Approach-1: by taking another matrix and copying values into it
    // Time Complexity: O(N*N) and Space Complexity: O(N*N)
    /*
    vector<vector<int>> ans(n, vector<int>(n, 0));

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            ans[j][m-i-1] = matrix[i][j];
        }
    }
    return ans;
    */
}

int main(){

    vector<vector<int>> matrix = {{1,2,3}, {4,5,6}, {7,8,9}};
    int n = matrix.size();

    vector<vector<int>> ans = rotateClockwise(matrix);

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}