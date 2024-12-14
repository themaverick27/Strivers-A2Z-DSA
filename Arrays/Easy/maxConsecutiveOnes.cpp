/*
Problem Statement: Given an array that contains only 1 and 0 return the count of maximum consecutive ones in the array.

Example 1:
Input: prices = {1, 1, 0, 1, 1, 1}
Output: 3
Explanation: There are two consecutive 1’s and three consecutive 1’s in the array out of which maximum is 3.

Example 2:
Input: prices = {1, 0, 1, 1, 0, 1} 
Output: 2
Explanation: There are two consecutive 1's in the array. 
*/

#include<bits/stdc++.h>
using namespace std;

int maxConsecutiveOnes(vector<int>& arr){
    int n = arr.size();

    // Approach-1: 
    // Time Complexity: O(n) and Space Complexity: O(1)
    int count = 0, maxCount = 0;
    for(int i = 0; i < n; i++){
        if(arr[i] == 1){
            count++;
        } else{
            count = 0;
        }
        maxCount = max(maxCount, count);
        
    }
    return maxCount;
}

int main(){
    vector<int> arr = {1, 1, 0, 1, 1, 1, 0};

    int ans = maxConsecutiveOnes(arr);
    cout << "Maximum consecutive ones: " << ans << endl;

    return 0;
}