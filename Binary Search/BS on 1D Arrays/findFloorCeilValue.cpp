/*
Problem Statement: You're given an sorted array arr of n integers and an integer x. Find the floor and ceiling of x in arr[0..n-1].

Note: The floor of x is the largest element in the array which is smaller than or equal to x.
The ceiling of x is the smallest element in the array greater than or equal to x.

Example 1:
Input: n = 6, arr[] ={3, 4, 4, 7, 8, 10}, x = 5
Output: 4 7
Explanation: The floor of 5 in the array is 4, and the ceiling of 5 in the array is 7.

Example 2:
Input: n = 6, arr[] ={3, 4, 4, 7, 8, 10}, x = 8
Output: 8 8
Explanation: The floor of 8 in the array is 8, and the ceiling of 8 in the array is also 8.
*/
#include<bits/stdc++.h>
using namespace std;

int findFloor(vector<int>& arr, int x){
    int n = arr.size();

    // Time Complexity: O(log n) and Space Complexity: O(1)
    int low = 0, high = n-1;
    int ans = -1;

    while(low <= high){
        int mid = low + (high-low)/2;

        if(arr[mid] <= x){
            ans = arr[mid];
            low = mid + 1;
        }
        else{
            high = mid - 1;
        }
    }
    return ans;
}

int findCeil(vector<int>& arr, int x){
    int n = arr.size();

    // Time Complexity: O(log n) and Space Complexity: O(1)
    int low = 0, high = n-1;
    int ans = -1;

    while(low <= high){
        int mid = low + (high-low);

        if(arr[mid] >= x){
            ans = arr[mid]; // can be my answer 
            high = mid - 1; // look for smaller value on the left
        }
        else{
            low = mid + 1; // look on the right
        }
    }
    return ans;
}

int main(){
    vector<int> arr = {3, 4, 4, 7, 8, 10};
    int x = 5;

    int floor = findFloor(arr, x);
    cout << "floor value of " << x << " is: " << floor << endl;

    int ceil = findCeil(arr, x);
    cout << "ceil value of " << x << " is: " << ceil << endl;

    return 0;
}