/*
Problem Statement: Given an integer N and an array of size N-1 containing N-1 numbers between 1 to N. Find the number(between 1 to N), that is not present in the given array.

Example 1:
Input Format: N = 5, array[] = {1,2,4,5}
Result: 3
Explanation: In the given array, number 3 is missing. So, 3 is the answer.

Example 2:
Input Format: N = 3, array[] = {1,3}
Result: 2
Explanation: In the given array, number 2 is missing. So, 2 is the answer.
*/

#include<bits/stdc++.h>
using namespace std;

int missingNumber(vector<int>& arr, int N){

    // Approach-3: using xor properties
    // Time Complexity: O(n) and Space Complexity: O(1)
    int xor1 = 0, xor2 = 0;
    for(int i = 0; i < arr.size(); i++){
        xor1 ^= arr[i];
        xor2 ^= (i+1);
    }
    xor2 ^= N;
    int missing = xor1 ^ xor2;
    return missing;

    // Approach-2: using sum formula
    // Time Complexity: O(n) and Space Complexity: O(1)
    /*
    int naturalSum = N*(N+1)/2;
    int elementSum = 0;

    for(int i = 0; i < arr.size(); i++){
        elementSum += arr[i];
    }
    int missing = naturalSum - elementSum;
    return missing;
    */


    // Approach-1: using Hashing
    // Time Complexity: O(2*n) and Space Complexity: O(n)
    /*
    int hash[N+1] = {0};

    for(int i = 0; i < N-1; i++){
        hash[arr[i]]++;
    }

    for(int i = 1; i < N-1; i++){
        if(hash[i] == 0) return i;
    }
    return -1;
    */

}

int main(){
    vector<int> arr = {1, 2, 4, 5};
    int N = 5;

    int ans = missingNumber(arr, N);
    cout << "Missing Number: " << ans << endl;

    return 0;
}