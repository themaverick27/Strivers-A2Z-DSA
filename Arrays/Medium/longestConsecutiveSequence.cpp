/*
Problem Statement: You are given an array of ‘N’ integers. 
You need to find the length of the longest sequence which contains the consecutive elements.

Example 1:
Input: [100, 200, 1, 3, 2, 4]
Output: 4
Explanation: The longest consecutive subsequence is 1, 2, 3, and 4.

Example 2:
Input: [3, 8, 5, 7, 6]
Output: 4
Explanation: The longest consecutive subsequence is 5, 6, 7, and 8.
*/
#include<bits/stdc++.h>
using namespace std;

bool linearSearch(vector<int>& arr, int x){
    for(int i = 0; i < arr.size(); i++){
        if(arr[i] == x) return true;
    }
    return false;
}


int longestConsecutiveSequence(vector<int>& arr){
    int n = arr.size();

    // Approach-3: using set data strucutre, we will focus solely on finding sequences only for those numbers that can be the starting numbers of the sequences
    // Time Complexity: O(3*n) and Space Complexity: O(n)
    if(n == 0) return 0; // edge case

    unordered_set<int> st;
    int longest = 1;
    for(int i = 0; i < n; i++){
        st.insert(arr[i]);
    }

    for(auto it: st){
        if(st.find(it-1) == st.end()){
            int count = 1;
            int x = it;
            while(st.find(x+1) != st.end()){
                count += 1;
                x += 1;
            }
            longest = max(longest, count);
        }
    }
    return longest;




    // Approach-2: using sorting (here, we are distorting (changing) the original array)
    // Time Complexity: O(n*log n) + O(n) and Space Complexity: O(1)
    /*
    if(n == 0) return 0; // edge case
    sort(begin(arr), end(arr));

    int lastSmaller = INT_MIN;
    int count = 0, longest = 1;
    for(int i = 0; i < n; i++){
        if(arr[i]-1 == lastSmaller){
            // arr[i] is the next consecutive element in the current sequence
            count++;
            lastSmaller = arr[i];
        }
        else if(arr[i] != lastSmaller){
            // it indicates that arr[i] cannot be a part of the current sequence. So, we will start a new sequence from arr[i]
            lastSmaller = arr[i];
            count = 1;
        }
        longest = max(longest, count);
    }
    return longest;
    */


    
    // Approach-1: For every element num, do a linear search for its next element (consecutive) x+1, x+2, x+3, and so on.
    // Time Complexity: O(n*n) and Space Complexity: O(1)
    /*
    if(n == 0) return 0; // edge case

    int longest = 1;
    for(int i = 0; i < n; i++){
        int num = arr[i];
        int len = 1;
        while(linearSearch(arr, num+1) == true){
            len += 1;
            num += 1;
        }
        longest = max(longest, len);
    }
    return longest;
    */
}

int main(){
    vector<int> arr = {100, 200, 1, 3, 2, 4};

    int ans = longestConsecutiveSequence(arr);
    cout << "Longest Consecutive Sequence: " << ans << endl;

    return 0;
}