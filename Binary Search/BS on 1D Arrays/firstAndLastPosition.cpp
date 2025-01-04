/*
Problem Statement: Given a sorted array arr with possibly some duplicates, the task is to find the first and last occurrences of an element x in the given array.

Note: If the number x is not found in the array then return both the indices as -1.

Example 1:
Input: arr[] = [1, 3, 5, 5, 5, 5, 67, 123, 125], x = 5
Output: [2, 5]
Explanation: First occurrence of 5 is at index 2 and last occurrence of 5 is at index 5.

Example 2:
Input: arr[] = [1, 3, 5, 5, 5, 5, 7, 123, 125], x = 7
Output: [6, 6]
Explanation: First and last occurrence of 7 is at index 6.

Example 3:
Input: arr[] = [1, 2, 3], x = 4
Output: [-1, -1]
Explanation: No occurrence of 4 in the array, so, output is [-1, -1].
*/
#include<bits/stdc++.h>
using namespace std;

int findFirstOccurrence(vector<int>& arr, int x){
    int n = arr.size();

    // Time Complexity: O(log n) and Space Complexity: O(1)
    int low = 0, high = n-1;
    int ans = -1;

    while(low <= high){
        int mid = low + (high-low)/2;

        if(arr[mid] == x){
            ans = mid; // might be first occurrence
            high = mid - 1; // look on the left for smaller index
        }
        else if(arr[mid] > x) high = mid - 1; // look on the right
        else low = mid + 1; // look on the left
    }
    return ans;
}

int findLastOccurrence(vector<int>& arr, int x){
    int n = arr.size();

    // Time Complexity: O(log n) and Space Complexity: O(1)
    int low = 0, high = n-1;
    int ans = -1;
    while(low <= high){
        int mid = low + (high-low)/2;

        if(arr[mid] == x){
            ans = mid; // might be last occurrence
            low = mid + 1; // look on the right for greater index
        }
        else if(arr[mid] > x) high = mid - 1; // look on the left
        else low = mid + 1; // look on the left
    }
    return ans;
}

int main(){
    vector<int> arr = {1, 3, 5, 5, 5, 5, 67, 123, 125};
    int x = 5;

    int first = findFirstOccurrence(arr, x);
    cout << "first occurrence of " << x << " is at index: " << first << endl;

    int last = findLastOccurrence(arr, x);
    cout << "last occurrence of " << x << " is at index: " << last << endl;

    return 0;
}