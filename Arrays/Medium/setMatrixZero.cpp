/*
Problem Statement: Given a matrix if an element in the matrix is 0 then you will have to set its 
entire column and row to 0 and then return the matrix.

Examples 1:
Input: matrix=[[1,1,1],[1,0,1],[1,1,1]]
Output: [[1,0,1],[0,0,0],[1,0,1]]
Explanation: Since matrix[2][2]=0.Therfore the 2nd column and 2nd row wil be set to 0.

Example 2: 
Input: matrix=[[0,1,2,0],[3,4,5,2],[1,3,1,5]]
Output: [[0,0,0,0],[0,4,5,0],[0,3,1,0]]
Explanation: Since matrix[0][0]=0 and matrix[0][3]=0. Therefore 1st row, 1st column and 4th column will be set to 0
*/
#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> markRow(vector<vector<int>> &matrix, int n, int m, int i){
    for(int j = 0; j < m; j++){
        if(matrix[i][j] != 0) matrix[i][j] = -1;
    }
}

vector<vector<int>> markColumn(vector<vector<int>> &matrix, int n, int m, int j){
    for(int i = 0; i < n; i++){
        if(matrix[i][j] != 0) matrix[i][j] = -1;
    }
}

vector<vector<int>> zeroMatrix(vector<vector<int>> &matrix, int n, int m){

        // Approach-3: Optimal
        // Time Complexity: O(2*(N*M)) and Space Complexity: O(1)
        int col0 = 1;
        // step 1: Traverse the matrix and mark 1st row & col accordingly:
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (matrix[i][j] == 0) {
                    // mark i-th row:
                    matrix[i][0] = 0;

                    // mark j-th column:
                    if (j != 0)
                        matrix[0][j] = 0;
                    else
                        col0 = 0;
                }
            }
        }
        // Step 2: Mark with 0 from (1,1) to (n-1, m-1):
        for (int i = 1; i < n; i++) {
            for (int j = 1; j < m; j++) {
                if (matrix[i][j] != 0) {
                    // check for col & row:
                    if (matrix[i][0] == 0 || matrix[0][j] == 0) {
                        matrix[i][j] = 0;
                    }
                }
            }
        }
        //step 3: Finally mark the 1st col & then 1st row:
        if (matrix[0][0] == 0) {
            for (int j = 0; j < m; j++) {
                matrix[0][j] = 0;
            }
        }
        if (col0 == 0) {
            for (int i = 0; i < n; i++) {
                matrix[i][0] = 0;
            }
        }
        return matrix;



        // Approach-2:
        // Time Complexity: O(2*(N*M)) and Space Complexity: O(n) + O(m)
        /*
        int row[n] = {0};
        int col[m] = {0};
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(matrix[i][j] == 0){
                    row[i] = 1;
                    col[j] = 1;
                }
            }
        }

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(row[i] == 1 || col[j] == 1){
                    matrix[i][j] = 0;
                }
            }
        }
        return arr;
        */


        // Approach-1: 
        // Time Complexity: O((N*M)*(N+M) + (N*M)) and Space Complexity: O(1)
        /*
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(arr[i][j] == 0){
                    markRow(arr, n, m, i);
                    markColumn(arr, n, m, j);
                }
            }
        }

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(arr[i][j] == -1){
                    arr[i][j] == 0;
                }
            }
        }
        return arr;
        */
}

int main(){
    
    vector<vector<int>> matrix = {{1, 1, 1}, {1, 0, 1}, {1, 1, 1}};
    int n = matrix.size();
    int m = matrix[0].size();
    vector<vector<int>> matrix = zeroMatrix(matrix, n, m);

    return 0;
}