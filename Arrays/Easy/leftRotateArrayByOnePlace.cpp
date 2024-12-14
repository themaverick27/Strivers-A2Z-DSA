/*
Problem Statement: Given an array of N integers, left rotate the array by one place.

Example 1:
Input: N = 5, array[] = {1,2,3,4,5}
Output: {2,3,4,5,1}
Explanation: Since all the elements in array will be shifted toward left by one so ‘2’ will now become the 
first index and and ‘1’ which was present at first index will be shifted at last.

Example 2:
Input: N = 1, array[] = {3}
Output: 3
Explanation: Here only element is present and so the element at first index will be shifted to last index which is also by the way the first index.
*/

#include<bits/stdc++.h>
using namespace std;

void rightRotate(vector<int>& arr){
    int n = arr.size();

    // Approach-1:
    // Time Complexity: O(n) and Space Complexity: O(1)
    int temp = arr[n-1];
    for(int i = n-1; i > 0; i--){
        arr[i] = arr[i-1];
    }
    arr[0] = temp;
}

void leftRotate(vector<int>& arr){
    int n = arr.size();

    // Approach-1: 
    // Time Complexity: O(n) and Space Complexity: O(1)
    int temp = arr[0];
    for(int i = 1; i < n; i++){
        arr[i-1] = arr[i];
    }
    arr[n-1] = temp;
}

int main(){
    vector<int> arr = {1, 2, 3, 4, 5};

    leftRotate(arr);

    // rightRotate(arr);

    // printing the array after rotation
    for(int i = 0; i < arr.size(); i++){
        cout << arr[i] << " ";
    }

    return 0;
}