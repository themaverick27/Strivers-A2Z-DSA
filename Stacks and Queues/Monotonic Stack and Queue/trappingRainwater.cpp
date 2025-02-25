/*
Problem Statement: Given n non-negative integers representing an elevation map where the width of each bar is 1.
compute how much water it can trap after raining.

Example 1: 
Input: height = [0,1,0,2,1,0,1,3,2,1,2,1]
Output: 6

Example 2:
Input: height = [4,2,0,3,2,5]
Output: 9
*/
#include<bits/stdc++.h>
using namespace std;

int trapWater(vector<int>& height){
    int n = height.size();

    // Approach-2: Two pointers 
    // Time Complexity: O(n) and Space Complexity: O(1)
    int lmax = height[0]; 
    int rmax = height[n-1];

    int left = 1;
    int right = height.size() - 2;

    int ans = 0;
    while(left <= right){
        if(lmax <= rmax){
            ans += max(0, lmax - height[left]); 

            lmax = max(lmax, height[left]); // update the leftmax
            left++;
        }
        else{
            ans += max(0, rmax - height[right]);

            rmax = max(rmax, height[right]); // update the rightmax
            right--;
        }
    }
    return ans;


    // Approach-1: using prefix and suffix max array
    // Time Complexity: O(3*n) and Space Complexity: O(2*n)
    /*
    vector<int> prefix(n);
    prefix[0] = height[0];
    for(int i = 1; i < n; i++){
        prefix[i] = max(prefix[i-1], height[i]);
    }

    vector<int> suffix(n);
    suffix[n-1] = height[n-1];
    for(int i = n-2; i >= 0; i--){
        suffix[i] = max(suffix[i+1], height[i]);
    }

    int total = 0;
    for(int i = 0; i < n; i++){
        int leftMax = prefix[i];
        int rightMax = suffix[i];

        if(height[i] < leftMax && height[i] < rightMax){
            total += min(leftMax, rightMax) - height[i];
        }
    }
    return total;
    */
}


int main(){
    vector<int> height = {0,1,0,2,1,0,1,3,2,1,2,1};

    int ans = trapWater(height);
    cout << ans << endl;

    return 0;
}