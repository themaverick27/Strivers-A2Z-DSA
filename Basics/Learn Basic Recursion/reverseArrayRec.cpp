/*
Problem Statement: You are given an array. The task is to reverse the array and print it. 

Example 1:
Input: N = 5, arr[] = {5,4,3,2,1}
Output: {1,2,3,4,5}

Example 2:
Input: N=6 arr[] = {10,20,30,40}
Output: {40,30,20,10}
*/
#include<bits/stdc++.h>
using namespace std;

// swapping using single pointer - recursive approach
void reverseTheArray(vector<int>& arr, int i){
    if(i >= arr.size()/2) return;

    swap(arr[i], arr[arr.size() - i - 1]);
    reverseTheArray(arr, i+1);
}


// swapping using two pointers - recursive approach
void reverseArray(vector<int>& arr, int i, int j){
    if(i > j) return;

    swap(arr[i], arr[j]);
    reverseArray(arr, i+1, j-1);
}


int main(){
    vector<int> arr = {1, 2, 3, 4, 2};
    int n = arr.size();

    // swapping using two pointers
    // Time Complexity: O(n) - two pointers and Space Complexity: O(n) - stack space 
    // reverseArray(arr, 0, n-1); 

    // swapping using single pointer
    // Time Complexity: O(n/2) - two pointers and Space Complexity: O(n) - stack space
    reverseTheArray(arr, 0);


    // printing the array
    for(int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }

    return 0;
}
