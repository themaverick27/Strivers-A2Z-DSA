/*
Problem Statement: Given an integer array sorted in non-decreasing order, remove the duplicates in place such that each unique element appears only once. The relative order of the elements should be kept the same.
If there are k elements after removing the duplicates, then the first k elements of the array should hold the final result. It does not matter what you leave beyond the first k elements.

Note: Return k after placing the final result in the first k slots of the array.

Example 1:
Input: arr[1,1,2,2,2,3,3]
Output: arr[1,2,3,_,_,_,_]
Explanation: Total number of unique elements are 3, i.e[1,2,3] and Therefore return 3 after assigning [1,2,3] in the beginning of the array.

Example 2:
Input: arr[1,1,1,2,2,3,3,3,3,4,4]
Output: arr[1,2,3,4,_,_,_,_,_,_,_]
Explanation: Total number of unique elements are 4, i.e[1,2,3,4] and Therefore return 4 after assigning [1,2,3,4] in the beginning of the array.
*/

#include<bits/stdc++.h>
using namespace std;

int removeDuplicates(vector<int>& arr){
    int n = arr.size();

    // Approach-2: using Two pointers
    // Time Complexity: O(n) and Space Complexity: O(1)
    int i = 0;
    for(int j = 1; j < n; j++){
        if(arr[j] != arr[i]){
            arr[i+1] = arr[j];
            i++;
        } 
    }
    return (i+1);


    // Approach-1: using set data structure
    // Time Complexity: O(n*log n) + O(n) and Space Complexity: O(n)
    /*
    set<int> st;
    for(int i = 0; i < n; i++){
        st.insert(arr[i]);
    }

    int k = st.size();
    int i = 0;
    for(auto it: st){
        arr[i++] = it;
    }
    return k;
    */

}

int main(){
    vector<int> arr = {1, 1, 2, 2, 2, 3, 3};
    int uniqueElement = removeDuplicates(arr);
    cout << uniqueElement << endl;

    cout << "The array after remving duplicate element is: ";
    for(int i = 0; i < uniqueElement; i++){
        cout << arr[i] << " ";
    }

    return 0;
}