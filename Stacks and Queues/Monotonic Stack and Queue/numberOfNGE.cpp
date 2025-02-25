/*
Problem Statement: Given an array of N integers and Q queries of indices. For each query indices[i], 
determine the count of elements in arr that are strictly greater than arr[indices[i]] to its right (after the position indices[i]).

Example 1:
Input: arr[] = [3, 4, 2, 7, 5, 8, 10, 6], queries = 2, indices[] = [0, 5]
Output:  [6, 1]
Explanation: The next greater elements to the right of 3(index 0) are 4,7,5,8,10,6. The next greater elements to the right of 8(index 5) is only 10.

Example 2:
Input: arr[] = [1, 2, 3, 4, 1], queries = 2, indices[] = [0, 3]
Output:  [3, 0]
Explanation: The count of numbers to the right of index 0 which are greater than arr[0] is 3 i.e. (2, 3, 4). Similarly, the count of numbers to the right of index 3 which are greater than arr[3] is 0, since there are no greater elements than 4 to the right of the array.
*/
#include<bits/stdc++.h>
using namespace std;

int countNGE(vector<int>& arr, int idx){
    int count = 0;
    int ele = arr[idx];
    for(int i = idx + 1; i < arr.size(); i++){
        if(arr[i] > ele) count++;
    }
    return count;
}

vector<int> numberOfNGE(vector<int>& arr, int q, vector<int>& indices){
    int n = arr.size();

    // Approach-1: picking an element one by one and counting the nge 
    // Time Complexity: O(n*q) approx and Space Complexity: O(1)
    vector<int> ans;
    for(int i = 0; i < q; i++){
        int count = countNGE(arr, indices[i]);
        ans.push_back(count);
    }
    return ans;
}

int main(){
    vector<int> arr = {3, 4, 2, 7, 5, 8, 10, 6};
    int queries = 2;
    vector<int> indices = {0, 5};

    vector<int> ans = numberOfNGE(arr, queries, indices);
    for(int i = 0; i < ans.size(); i++){
        cout << ans[i] << " ";
    }

    return 0;
}