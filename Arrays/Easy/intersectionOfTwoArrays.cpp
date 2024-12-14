/*
Problem statement: You are given two arrays 'A' and 'B' of size 'N' and 'M' respectively. 
Both these arrays are sorted in non-decreasing order. You have to find the intersection of these two arrays.

Note: Intersection of two arrays is an array that consists of all the common elements occurring in both arrays.

Example 1:
Input: n = 5, m = 5, arr1[] = {1,2,3,4,5} , arr2[] = {2,3,4,4,5}
Output: {2,3,4,5}

Example 2:
Input: n = 10, m = 7, arr1[] = {1,2,3,4,5,6,7,8,9,10}, arr2[] = {2,3,4,4,5,11,12}
Output: {2,3,4,5}
*/

#include<bits/stdc++.h>
using namespace std;

vector<int> intersectionOfTwoArrays(vector<int>& arr1, int m, vector<int>& arr2, int n){
    // Approach-2: two pointers - both arrays arr1 and arr2 should be sorted
    // Time Complexity: O(min(m+n)) and Space Complexity: O(1) - not considering the ans array space
    vector<int> ans;
    int i = 0, j = 0;
    while(i < m && j < n){
        if(arr1[i] < arr2[j]){
            i++;
        }
        else if(arr1[i] > arr2[j]){
            j++;
        }
        else{
            ans.push_back(arr1[i]);
            i++;
            j++;
        }
    }
    return ans;

    // Approach 1 - By keeping track of elements
    // Time Complexity: O(m*n) and Space Complexity: O(n2) - worst case
    /*
    int visited[n] = {0};
    vector<int> ans;
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            if(a[i] == b[j] && visited[j] == 0){
                ans.push_back(a[i]);
                visited[j] = 1;
                break;
            }
            if(b[j] > a[i]) break; // only for sorted array
        }
    }
    printAnswer(ans);
    */
}

int main(){

    vector<int> arr1 = {1, 2, 3, 4, 5};
    vector<int> arr2 = {2, 3, 4, 4, 5};

    int m = arr1.size();
    int n = arr2.size();
    vector<int> ans = intersectionOfTwoArrays(arr1, m, arr2, n);
    cout << "Intersection of arr1 and arr2: " << endl;
    for(auto& x: ans){
        cout << x << " ";
    }

    return 0;
}