/*
Problem Statement: You are given a sorted array arr of distinct values and a target value x. You need to search for the index of the target value in the array.
If the value is present in the array, then return its index. Otherwise, determine the index where it would be inserted in the array while maintaining the sorted order.

Example 1:
Input Format: arr[] = {1,2,4,7}, x = 6
Output: 3
Explanation: 6 is not present in the array. So, if we will insert 6 in the 3rd index(0-based indexing), the array will still be sorted. {1,2,4,6,7}.

Example 2:
Input Format: arr[] = {1,2,4,7}, x = 2
Output: 1
Explanation: 2 is present in the array and so we will return its index i.e. 1.
*/
#include<bits/stdc++.h>
using namespace std;

int searchInsertPosition(vector<int>& arr, int x){
    int n = arr.size();

    int low = 0, high = n-1;
    int ans = -1;
    while(low <= high){
        int mid = low + (high - low)/2;

        if(arr[mid] >= x){
            ans = mid; // can be the answer
            high = mid - 1; // look for smaller index on the left
        }
        else{
            low = mid + 1; // look on the right
        }
    }
    return ans;
}

int main(){
    vector<int> arr = {1, 2, 4, 7};
    int x = 6;

    int idx = searchInsertPosition(arr, x);
    cout << idx << endl;

    return 0;
}