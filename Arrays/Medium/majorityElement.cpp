/*
Problem Statement: Given an array of N integers, write a program to return an element that occurs more than N/2 times 
in the given array. You may consider that such an element always exists in the array.

Example 1:
Input: N = 3, nums[] = {3,2,3}
Output: 3
Explanation: When we just count the occurrences of each number and compare with half of the size of the array, you will get 3 for the above solution. 

Example 2:
Input: N = 7, nums[] = {2,2,1,1,1,2,2}
Output: 2
Explanation: After counting the number of times each element appears and comparing it with half of array size, we get 2 as result.

Example 3:
Input: N = 10, nums[] = {4,4,2,4,3,4,4,3,2,4}
Explanation: After counting the number of times each element appears and comparing it with half of array size, we get 4 as result.
Output: 4
*/
#include<bits/stdc++.h>
using namespace std;

int majorityElement(vector<int>& arr){
    int n = arr.size();

    // Approach-3: Moore's Voting Algorithm
    // Time Complexity: O(n) and Space Complexity: O(1)
    int count = 0;
    int ele;
    for(int i = 0; i < n; i++){
        if(count == 0){
            ele = arr[i];
            count = 1;
        }
        else if(arr[i] == ele){
            count++;
        }
        else{
            count--;
        }
    }
    return ele;



    // Approach-2: Hashmap
    // Time Complexity: O(n*log n) + O(n) and Space Complexity: O(n)
    /*
    map<int, int> freq;
    for(int i = 0; i < n; i++){
        freq[arr[i]]++;
    }

    for(auto x: freq){
        if(x.second > (n/2)) return x.first;
    }
    return -1;
    */



    // Approach-1: pick an element and count its occurrence by linear search
    // Time Complexity: O(n*n) approax and Space Complexity: O(1)
    /*
    for(int i = 0; i < n; i++){
        int count = 0;
        for(int j = 0; j < n; j++){
            if(arr[j] == arr[i]) count++;
        }
        if(count > (n/2)) return arr[i];
    }
    return -1;
    */

}

int main(){
    vector<int> arr = {2, 2, 1, 1, 1, 2, 2};

    int ans = majorityElement(arr);
    cout << "majority element: " << ans << endl;
    return 0;
}