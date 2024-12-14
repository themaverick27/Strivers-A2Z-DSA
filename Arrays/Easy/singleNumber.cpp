/*
Problem Statement: Given a non-empty array of integers arr, every element appears twice except for one. Find that single one.

Example 1:
Input Format: arr[] = {2,2,1}
Result: 1
Explanation: In this array, only the element 1 appear once and so it is the answer.

Example 2:
Input Format: arr[] = {4,1,2,1,2}
Result: 4
Explanation: In this array, only element 4 appear once and the other elements appear twice. So, 4 is the answer.
*/

#include<bits/stdc++.h>
using namespace std;

int singleNumber(vector<int>& arr){
    int n = arr.size();

    // Approach-3: using xor properties
    // Time Complexity: O(n) and Space Complexity: O(1)
    int xor1 = 0;
    for(int i = 0; i < n; i++){
        xor1 ^= arr[i];
    }
    return xor1;

    // Approach-2: using Map
    // Time Complexity: O(N*logM) + O(M) and Space Complexity: O(M) - where M is the size of map i.e (N/2)+1
    /*
    map<int, int> mpp;
    for(int i = 0; i < n; i++){
        mpp[arr[i]]++;
    }
    for(auto it: mpp){
        if(it.second == 1) return it.first;
    }
    return -1; // dummy return
    */

    // Approach-1: Hashing
    // Time Complexity: O(3*n) and Space Complexity: O(maxElement+1)
    /*
    int maxElement = -1;
    for(int i = 0; i < n; i++){
        if(arr[i] > maxElement) maxElement = arr[i];
    }

    int hash[maxElement + 1] = {0};
    for(int i = 0; i < n; i++){
        hash[arr[i]]++;
    }

    for(int i = 1; i < n; i++){
        if(hash[i] == 1) return i;
    }
    return -1; // dummy return
    */
}

int main(){

    vector<int> arr = {4, 1, 2, 2, 1, 5, 4};
    
    int ans = singleNumber(arr);
    cout << "Single number: " << ans << endl;

    return 0;
}