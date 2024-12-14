/*
Problem Statement: Given two sorted arrays, arr1, and arr2 of size n and m. Find the union of two sorted arrays.

The union of two arrays can be defined as the common and distinct elements in the two arrays.NOTE: Elements in the union should be in ascending order.

Example 1:
Input: n = 5, m = 5, arr1[] = {1,2,3,4,5} , arr2[] = {2,3,4,4,5}
Output: {1,2,3,4,5}
Explanation: 
Common Elements in arr1 and arr2  are:  2,3,4,5
Distnict Elements in arr1 are : 1
Distnict Elemennts in arr2 are : No distinct elements.
Union of arr1 and arr2 is {1,2,3,4,5} 

Example 2:
Input: n = 10, m = 7, arr1[] = {1,2,3,4,5,6,7,8,9,10}, arr2[] = {2,3,4,4,5,11,12}
Output: {1,2,3,4,5,6,7,8,9,10,11,12}
Explanation:
Common Elements in arr1 and arr2  are:  2,3,4,5
Distnict Elements in arr1 are : 1,6,7,8,9,10
Distnict Elemennts in arr2 are : 11,12
Union of arr1 and arr2 is {1,2,3,4,5,6,7,8,9,10,11,12} 
*/

#include<bits/stdc++.h>
using namespace std;

vector<int> unionOfTwoSortedArrays(vector<int>& arr1, int m, vector<int>& arr2, int n){

    // Approach-3: using two pointers - both arrays should be sorted
    // Time Complexity: O(m+n) and Space Complexity: O(1) - not counting the unionArray ans space
    vector<int> unionArray;
    int i = 0, j = 0;
    while(i < m && j < n){
        if(arr1[i] <= arr2[j]){
            if(unionArray.size() == 0 || unionArray.back() != arr1[i]){
                unionArray.push_back(arr1[i]);
            }
            i++;
        } else{
            if(unionArray.size() == 0 || unionArray.back() != arr2[j]){
                unionArray.push_back(arr2[j]);
            }
            j++;
        }
    }
    // if arr1 exhausted then
    while(j < n){
        if(unionArray.back() != arr2[j]){
            unionArray.push_back(arr2[j]);
        }
        j++;
    }
    // if arr2 exhausted then
    while(i < m){
        if(unionArray.back() != arr1[i]){
            unionArray.push_back(arr1[i]);
        }
        i++;
    }
    return unionArray;

    // Appraoch-2: using set
    // Time Complexity: O((m+n)log(m+n)) and Space Complexity: O(1) - not considering the unionArray space
    /*
    set<int> st;
    vector<int> unionArray;
    for(int i = 0; i < m; i++){
        st.insert(arr1[i]);
    }
    for(int i = 0; i < n; i++){
        st.insert(arr2[i]);
    }
    for(auto& it: st){
        unionArray.push_back(it);
    }
    return unionArray;
    */


    // Approach-1: using map
    // Time Complexity: O((m+n)log(m+n) and Space Complexity: O(1) - not considering the unionArray space
    /*
    map<int, int> mpp;
    vector<int> unionArray;
    for(int i = 0; i < m; i++){
        mpp[arr1[i]]++;
    }
    for(int i = 0; i < n; i++){
        mpp[arr2[i]]++;
    }
    for(auto& it: mpp){
        unionArray.push_back(it.first);
    }
    return unionArray;
    */
}

vector<int> unionOfTwoArrays(int a[], int m, int b[], int n){
    // Approach-1 using set 
    // Time Complexity: O((m+n) log(m+n)) and Space Complexity: O(m+n) {If Space of Union ArrayList is considered})
    set < int > s;
    vector < int > ans;
    for(int i = 0; i < n; i++)
        s.insert(a[i]);
    for(int i = 0; i < m; i++)
        s.insert(b[i]);
    for (auto & it: s)
        ans.push_back(it);
    
    return ans;
}

int main(){

    vector<int> arr1 = {1, 2, 3, 4, 5};
    vector<int> arr2 = {2, 3, 4, 4, 5};

    int m = arr1.size();
    int n = arr2.size();
    vector<int> ans = unionOfTwoSortedArrays(arr1, m, arr2, n);
    cout << "Union of arr1 and arr2: " << endl;
    for(auto& x: ans){
        cout << x << " ";
    }

    // unionOfTwoArrays(arr1, m, arr2, n);

    return 0;
}