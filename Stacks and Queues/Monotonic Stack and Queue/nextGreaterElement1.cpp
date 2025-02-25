/*
Problem Statement: Given an array arr[] of integers, the task is to find the next greater element for each element of the array in order of their appearance in the array. Next greater element of an element in the array is the nearest element on the right which is greater than the current element.
If there does not exist next greater of current element, then next greater element for current element is -1. For example, next greater of the last element is always -1.

Example 1:
Input: arr[] = [1, 3, 2, 4]
Output: [3, 4, 4, -1]
Explanation: The next larger element to 1 is 3, 3 is 4, 2 is 4 and for 4, since it doesn't exist, it is -1.

Example 2: 
Input: arr[] = [6, 8, 0, 1, 3]
Output: [8, -1, 1, 3, -1]
Explanation: The next larger element to 6 is 8, for 8 there is no larger elements hence it is -1, for 0 it is 1 , for 1 it is 3 and then for 3 there is no larger element on right and hence -1.

Example 3: 
Input: arr[] = [10, 20, 30, 50]
Output: [20, 30, 50, -1]
Explanation: For a sorted array, the next element is next greater element also exxept for the last element.
*/
#include<bits/stdc++.h>
using namespace std;

int findGreater(vector<int>& nums, int idx, int ele){
    int n = nums.size();

    // find the next greater element from that next index
    for(int i = idx+1; i < n; i++){
        if(nums[i] > ele) return nums[i];
    }
    return -1; // no greater element exists
}

vector<int> nextGreaterElement(vector<int> &nums){
    int n = nums.size();

    // Approach-2: Monotonic stack
    // Time Complexity: O(2*n) and Space Complexity: O(n) 
    stack<int> st;
    vector<int> ans(n);

    for(int i = n-1; i >= 0; i--){
        
        while(!st.empty() && (st.top() <= nums[i])){
            st.pop();
        }

        if(st.empty()) ans[i] = -1; // no next greater element exists
        else ans[i] = st.top();

        st.push(nums[i]);
    }
    return ans;



    // Approach-1: pick element from nums1 array, and find the next greater element in the second array. Do it for every element of nums1 array.
    // Time Complexity: O(m*n) and Space Complexity: O(m) - to store & return the ans
    /*
    vector<int> ans;
    for(int i = 0; i < n; i++){
        int ele = nums[i];

        int greater = findGreater(nums, i, ele); // function to find the greater element in nums2 array
        ans.push_back(greater);
    }
    return ans;
    */
  
}

int main(){
    vector<int> nums = {1, 3, 4, 2};

    vector<int> ans = nextGreaterElement(nums);
    for(int i = 0; i < ans.size(); i++){
        cout << ans[i] << " ";
    }

    return 0;
}