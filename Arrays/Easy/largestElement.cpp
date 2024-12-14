/*
Problem Statement: Given an array, we have to find the largest element in the array.

Example 1:
Input: arr[] = {2,5,1,3,0};
Output: 5
Explanation: 5 is the largest element in the array. 

Example2:
Input: arr[] = {8,10,5,7,9};
Output: 10
Explanation: 10 is the largest element in the array. 
*/

#include<bits/stdc++.h>
using namespace std;

int smallestElement(vector<int>& arr){
    int n = arr.size();

    // Approach-2: using min variable
    // Time Complexity: O(n) and Space Complexity: O(1)
    int minimum = INT_MAX;
    for(int i = 0; i < n; i++){
        if(arr[i] < minimum) minimum = arr[i];
    }
    return minimum;


    // Approach-1: using Sorting
    // Time Complexity: O(n*log n) and Space Complexity: O(n)
    /*
    sort(begin(arr), end(arr));
    return arr[0];
    */
}

int largestElement(vector<int>& arr){
    int n = arr.size();

    // Approach-2: using largest variable
    // Time Complexity: O(n) and Space Complexity: O(1)
    int largest = INT_MIN;
    for(int i = 0; i < n; i++){
        if(arr[i] > largest){
            largest = arr[i];
        }
    }
    return largest;

    // Approach-1: using Sorting
    // Time Complexity: O(n*log n) and Space Complexity: O(n)
    /* 
    sort(begin(arr), end(arr));
    return arr[n-1];
    */
}

int main(){
    vector<int> arr = {2, 5, 1, 3, 0};
    int ans = largestElement(arr);
    cout << "Largest Element: " << ans << endl;

    /*
    int ans = smallestElement(arr);
    cout << "Smallest Element: " << ans << endl;
    */

    return 0;
}