/*
Problem Statement: Given an array of size n, write a program to check if the given array is sorted in (ascending / Increasing / Non-decreasing) order or not. If the array is sorted then return True, Else return False.

Note: Two consecutive equal values are considered to be sorted.

Example 1:
Input: N = 5, array[] = {1,2,3,4,5}
Output: True
Explanation: The given array is sorted i.e Every element in the array is smaller than or equals to its next values, So the answer is True.

Example 2:
Input: N = 5, array[] = {5,4,6,7,8}
Output: False.
Explanation: The given array is Not sorted i.e Every element in the array is not smaller than or equal to its next values, So the answer is False.
Here element 5 is not smaller than or equal to its future elements.
*/

#include<bits/stdc++.h>
using namespace std;

bool checkArraySorted(vector<int>& arr){
    int n = arr.size();

    // Approach-1: using single iteration and comparison
    // Time Complexity: O(n) and Space Complexity: O(1)
    for(int i = 1; i < n; i++){
        if(arr[i-1] > arr[i]) return false;
    }
    return true;
}

int main(){
    vector<int> arr = {1, 2, 7, 4, 5};
    if(checkArraySorted(arr)){
        cout << "Array is sorted" << endl;
    } else{
        cout << "Array is not sorted" << endl;
    }
    return 0;
}