/*
Problem Statement: Given an array of integers, rotating array of elements by k elements either left or right.

Example 1:
Input: N = 7, array[] = {1,2,3,4,5,6,7} , k=2 , right
Output: 6 7 1 2 3 4 5
Explanation: array is rotated to right by 2 position .

Example 2:
Input: N = 6, array[] = {3,7,8,9,10,11} , k=3 , left 
Output: 9 10 11 3 7 8
Explanation: Array is rotated to left by 3 position.
*/

#include<bits/stdc++.h>
using namespace std;

void reversal(vector<int>& arr, int start, int end){
    while(start <= end){
        int temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;

        start++;
        end--;
    }
}

void rightRotateByK(vector<int>& arr, int k){
    int n = arr.size();

    // Approach-2: using reversal algorithm - observation
    // Time Complexity: O(n) and Space Complexity: O(1)
    k = k % n;
    // reverse the last k elements
    reversal(arr, n-k, n-1);
    // reverse the remaining n-k elements
    reversal(arr, 0, n-k-1);
    // reverse the whole array
    reversal(arr, 0, n-1);

    // Approach-1: using temp array
    // Time Complexity: O(n+k) and Space Complexity: O(k)
    /*
    k = k % n;

    int temp[k];
    // storing the last k elements in temp array
    for(int i = n-k; i < n; i++){
        temp[i+k-n] = arr[i];
    }
    // right rotating the first n-k elements
    for(int i = n-1; i > 0; i--){
        arr[i] = arr[i-k];
    }
    // putting back the k elements in the front from temp array
    for(int i = 0; i < k; i++){
        arr[i] = temp[i];
    }
    */
}

void leftRotateByK(vector<int>& arr, int k){
    int n = arr.size();

    // Approach-2: using reversal algorithm - observation
    // Time Complexity: O(n) and Space Complexity: O(1)
    k = k % n;
    // reverse the first k elements
    reversal(arr, 0, k-1);
    // reverse the remaining n-k elements
    reversal(arr, k, n-1);
    // reverse the whole array
    reversal(arr, 0, n-1);


    // Approach-1: using temp array
    // Time Complexity: O(n+k) and Space Complexity: O(k)
    /*
    k = k % n;

    int temp[k];
    // stroing the first k elements in the temp array
    for(int i = 0; i < k; i++){
        temp[i] = arr[i];
    }
    // left rotation of the rest element in the array
    for(int i = k; i < n; i++){
        arr[i-k] = arr[i];
    }
    // putting the temp array element to the end
    for(int i = n-k; i < n; i++){
        arr[i] = temp[i+k-n];
    }
    */

}

int main(){
    vector<int> arr = {1, 2, 3, 4, 5, 6, 7};
    int k = 2;

    leftRotateByK(arr, k);

    // rightRotateByK(arr, k);

    // printing the array after rotation
    for(int i = 0; i < arr.size(); i++){
        cout << arr[i] << " ";
    }

    return 0;
}