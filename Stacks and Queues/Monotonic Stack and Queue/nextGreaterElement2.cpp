/*
Problem Statement: Given a circular integer array nums (i.e., the next element of nums[nums.length - 1] is nums[0]), return the next greater number for every element in nums.

The next greater number of a number x is the first greater number to its traversing-order next in the array, which means you could search circularly to find its next greater number. 
If it doesn't exist, return -1 for this number.

Example 1:
Input: nums = [1,2,1]
Output: [2,-1,2]
Explanation: The first 1's next greater number is 2. The number 2 can't find next greater number. The second 1's next greater number needs to search circularly, which is also 2.

Example 2:
Input: nums = [1,2,3,4,3]
Output: [2,3,4,-1,4]
*/
#include<bits/stdc++.h>
using namespace std;

vector<int> nextGreaterElement(vector<int>& arr){
    int n = arr.size();

    // Approach-3: using stack (Monotonic Stack) - traverse from the end two times, as the array is circular
    // Time Complexity: O(n) approx and Space Complexity: O(n)
    /*
    vector<int> ans(n, -1);
    stack<int> st;
    for(int i = n-1; i >= 0; i--){
        while(!st.empty() && (st.top() <= arr[i])){
            st.pop();
        }

        if(st.empty()) ans[i] = -1;
        else ans[i] = st.top();

        st.push(arr[i]);
    }
    // traverse again from the back and update (if any) next grater element, as the array is circular 
    for(int i = n-1; i >= 0; i--){
        while(!st.empty() && (st.top() <= arr[i])){
            st.pop();
        }

        if(st.empty()) ans[i] = -1;
        else ans[i] = st.top();

        st.push(arr[i]);
    }
    return ans;
    */


    // Approach-2: using stack (Monotonic Stack) - hypothetical doubling the array (as the array is circular) and then finding the next greater element
    // Time Complexity: O(n) approx and Space Complexity: O(n)
    /*
    vector<int> ans(n, -1);
    stack<int> st;

    for(int i = 2 * n - 1; i >= 0; i--){
        
        while(!st.empty() && (st.top() <= arr[i % n])){
            st.pop();
        }

        if(i < n){
            ans[i] = (st.empty()) ? -1 : st.top();
        }
        st.push(arr[i % n]);
    }
    return ans;
    */


    // Approach-1: using nested loops
    // Time Complexity: O(n*n) and Space Complexity: O(n) - to store and return the ans
    /*
    vector<int> ans(n, -1);
    for(int i = 0; i < n; i++){
        int ele = arr[i];
        for(int j = i+1; j <= (i + n-1); j++){

            int idx = j % n;
            if(arr[idx] > ele){
                ans[i] = arr[idx];
                break;
            }
        }
    }
    return ans;
    */
}

int main(){
    vector<int> arr = {1, 2, 3, 4, 3};

    vector<int> ans = nextGreaterElement(arr);
    for(int i = 0; i < ans.size(); i++){
        cout << ans[i] << " ";
    }

    return 0;
}