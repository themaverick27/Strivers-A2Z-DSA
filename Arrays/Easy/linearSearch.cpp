/*
Problem Statement: Given an array, and an element num the task is to find if num is present in the given array or not. 
If present print the index of the element or print -1.

Example 1:
Input Format: arr[]= 1 2 3 4 5, num = 3
Output: 2
Explanation: 3 is present in the 2nd index

Example 2:
Input Format: arr[]= 5 4 3 2 1, num = 5
Output: 0
Explanation: 5 is present in the 0th index
*/

#include<bits/stdc++.h>
using namespace std;

bool linearSearch(vector<int>& arr, int target){
    // Time Complexity: O(n) and Space Complexity: O(1)
    int n = arr.size();
    for(int i = 0; i < n; i++){
        if(arr[i] == target) return true;
    }
    return false;
}

int main(){
    vector<int> arr = {7, 12, 48, 35, 67};
    int target = 35;

    linearSearch(arr, target);

    return 0;
}
