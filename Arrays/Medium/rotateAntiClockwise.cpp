/*
Given a n*n square matrix mat[][], rotate it by 90 degrees in counterclockwise direction without using any extra space.

Example 1:
Input: mat[][] = [[1, 2, 3], [4, 5, 6], [7, 8, 9]]
Output: [[3, 6, 9], [2, 5, 8], [1, 4, 7]]
Explanation: Rotate the matrix simply by 90 degree anti-clockwise and return the matrix

Example 2:
Input: mat[][] = [[1,  2,  3,  4], [5,  6,  7,  8], [9, 10, 11, 12], [13, 14, 15, 16]]
Output: [[4, 8, 12, 16],  [3, 7, 11, 15], [2, 6, 10, 14], [1, 5, 9, 13]]
Explanation: Rotate the matrix simply by 90 degree anti-clockwise and return the matrix
*/
#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> rotateAntiClockwise(vector<vector<int>> &matrix){
    int n = matrix.size();

    // Approach-2: Observation - by reversing rows and taking transpose
    // Time Complexity: O(2*N*N) approx and Space Complexity: O(1)
    for(int i = 0; i < n; i++){
        reverse(matrix[i].begin(), matrix[i].end());
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < i; j++){
            swap(matrix[i][j], matrix[j][i]); // transpose
        }
    }
    return matrix;


    // Approach-1: by taking a temp matrix and copying values into it
    // Time Complexity: O(N*N) and Space Complexity: O(N*N)
    /*
    vector<vector<int>> ans(n, vector<int>(n,0));

    for(int i = 0; i < n; i++){
        for(int j = n-1; j >= 0; j--){
            ans[n-j-1][i] = matrix[i][j];
        }
    }
    return ans;
    */
}

int main(){

    vector<vector<int>> matrix = {{1, 2, 3}, {4,5,6}, {7,8,9}};
    int n = matrix.size();

    vector<vector<int>> ans = rotateAntiClockwise(matrix);

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}