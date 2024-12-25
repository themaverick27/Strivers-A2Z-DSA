/*
Problem Statement: Given an array Arr[] of integers, rearrange the numbers of the given array into the 
lexicographically next greater permutation of numbers.

If such an arrangement is not possible, it must rearrange to the lowest possible order (i.e., sorted in ascending order).

Example 1 :
Input format: arr[] = {1,3,2}
Output: arr[] = {2,1,3}
Explanation: All permutations of {1,2,3} are {{1,2,3} , {1,3,2}, {2,13} , {2,3,1} , {3,1,2} , {3,2,1}}. So, the next permutation just after {1,3,2} is {2,1,3}.

Example 2:
Input format: arr[] = {3,2,1}
Output: arr[] = {1,2,3}
Explanation: As we see all permutations of {1,2,3}, we find {3,2,1} at the last position. So, we have to return the topmost permutation.
*/
#include<bits/stdc++.h>
using namespace std;

vector<int> nextPermutation(vector<int>& arr){
    int n = arr.size();

    // Approach-3: Implementation of next_permutation (Optimal)
    // Time Complexity: O(3*n) and Space Complexity: O(1)
    int index = -1;
    // find the break point
    for(int i = n-2; i >= 0; i--){
        if(arr[i] < arr[i+1]){
            index = i;
            break;
        }
    }
    // if the index is -1, then just reverse the array (edge case)
    if(index == -1){
        reverse(begin(arr), end(arr));
        return arr;
    }
    // find closet greater element on the right side
    for(int i = n-1; i > index; i--){
        if(arr[i] > arr[index]){
            swap(arr[i], arr[index]);
            break;
        }
    }
    // now sort the remaining right side 
    sort(begin(arr) + index + 1, end(arr));
    return arr;



    // Approach-2: using inbuit (STL) method
    /*
    next_permutation(begin(arr), end(arr));
    return arr;
    */

    // Approach-1: Generating all possible permuatations
    // Time Complexity: O(n!*n) and Space Complexity: O(1), we are not using any extra space except stack spaces for recursion calls.
    /*
    1. Generate all possible permutations (in sorted order).
    2. do a linear search to find the given permutation.
    3. return the next index permutation, that will be the ans.
        (if the next index doesn't exists, return the first index permutation)
    */
}

int main(){
    vector<int> arr = {2, 1, 3};
    nextPermutation(arr);

    for(int i = 0; i < arr.size(); i++){
        cout << arr[i] << " ";
    }

    return 0;
}