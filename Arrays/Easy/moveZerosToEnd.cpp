/*
Problem Statement: You are given an array of integers, your task is to move all the zeros in the array to the end of the array and move non-negative integers to the front by maintaining their order.

Example 1:
Input: 1 ,0 ,2 ,3 ,0 ,4 ,0 ,1
Output: 1 ,2 ,3 ,4 ,1 ,0 ,0 ,0
Explanation: All the zeros are moved to the end and non-negative integers are moved to front by maintaining order

Example 2:
Input: 1, 2, 0, 1, 0, 4, 0
Output: 1, 2, 1, 4, 0, 0, 0
Explanation: All the zeros are moved to the end and non-negative integers are moved to front by maintaining order
*/

#include<bits/stdc++.h>
using namespace std;

void moveZerosToEnd(vector<int>& arr){
    int n = arr.size();

    // Approach-2: Two pointers
    // Time Complexity: O(n) and Space Complexity: O(1)
    int j = -1;
    for(int i = 0; i < n; i++){
        if(arr[i] == 0){
            j = i;
            break;
        }
    }
    if(j == -1) return;
    for(int i = j+1; i < n; i++){
        if(arr[i] != 0){
            swap(arr[i], arr[j]);
            j++;
        }
    }


    // Approach-1: using an extra array
    // Time Complexity: O(2*n) and Space Complexity: O(n)
    /*
    // store all the non-zero element into temp array
    vector<int> temp;
    for(int i = 0; i < n; i++){
        if(arr[i] != 0)
            temp.push_back(arr[i]);
    }

    int count = temp.size();
    // put all the non-zero element to the starting of the org array
    for(int i = 0; i < count; i++){
        arr[i] = temp[i];
    }
    // manually add the remainig position with 0
    for(int i = count; i < n; i++){
        arr[i] = 0;
    }
    */
}

int main(){
    vector<int> arr = {1, 0, 2, 3, 0, 4, 0};

    moveZerosToEnd(arr);

    // printing the array
    for(int i = 0; i < arr.size(); i++){
        cout << arr[i] << " ";
    }

    return 0;
}