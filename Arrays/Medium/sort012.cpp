/*
Problem Statement: Given an array consisting of only 0s, 1s, and 2s. Write a program to in-place sort the array 
without using inbuilt sort functions. ( Expected: Single pass-O(N) and constant space)

Example 1:
Input: nums = [2,0,2,1,1,0]
Output: [0,0,1,1,2,2]

Example 2:
Input: nums = [2,0,1]
Output: [0,1,2]

Example 3:
Input: nums = [0]
Output: [0]
*/
#include<bits/stdc++.h>
using namespace std;

void sort012(vector<int>& arr){
    int n = arr.size();

    // Approach-3: Dutch National Flag (DNF) Algorithm
    // Time Complexity: O(n) and Space Complexity: O(1)
    int low = 0, mid = 0, high = n-1;
    while(mid <= high){
        if(arr[mid] == 0){
            swap(arr[mid], arr[low]);
            low++;
            mid++;
        }
        else if(arr[mid] == 1){
            mid++;
        }
        else{
            swap(arr[mid], arr[high]);
            high--;
        }
    }

    // Approach-2: using three variables
    // Time Complexity: O(2*n) and Space Complexity: O(1)
    /*
    int countZero = 0, countOne = 0, countTwo = 0;
    // counting the number of occurrences or each 0, 1, 2
    for(int i = 0; i < n; i++){
        if(arr[i] == 0) countZero++;
        else if(arr[i] == 1) countOne++;
        else countTwo++;
    }
    // manually adding 0, 1, 2 with their counts
    for(int i = 0; i < countZero; i++){
        arr[i] = 0;
    }
    for(int i = countZero; i < (countZero + countOne); i++){
        arr[i] = 1;
    }
    for(int i = (countZero + countOne); i < n; i++){
        arr[i] = 2;
    }
    return;
    */


    // Approach-1: using in-built sorting method
    // Time Complexity: O(n*log n) and Space Complexity: O(n)
    /*
    sort(begin(arr), end(arr));
    return;
    */

}

int main(){
    vector<int> arr = {2, 0, 2, 1, 1, 0};

    sort012(arr);
    for(int i = 0; i < arr.size(); i++){
        cout << arr[i] << " ";
    }

    return 0;
}