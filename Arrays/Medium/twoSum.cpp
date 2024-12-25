/*
Problem Statement: Given an array of integers arr[] and an integer target. Return indices of the two numbers such that their sum is equal to the target. Otherwise, we will return {-1, -1}.

1st variant: Return YES if there exist two numbers such that their sum is equal to the target. Otherwise, return NO.
2nd variant: Return indices of the two numbers such that their sum is equal to the target. Otherwise, we will return {-1, -1}.

Note: You are not allowed to use the same element twice. Example: If the target is equal to 6 and num[1] = 3, then nums[1] + nums[1] = target is not a solution.

Example 1:
Input Format: N = 5, arr[] = {2,6,5,8,11}, target = 14
Result: YES (for 1st variant)
       [1, 3] (for 2nd variant)
Explanation: arr[1] + arr[3] = 14. So, the answer is “YES” for the first variant and [1, 3] for 2nd variant.

Example 2:
Input Format: N = 5, arr[] = {2,6,5,8,11}, target = 15
Result: NO (for 1st variant)
	[-1, -1] (for 2nd variant)
Explanation: There exist no such two numbers whose sum is equal to the target.
*/
#include<bits/stdc++.h>
using namespace std;

// variant-2: Return indices of the two numbers such that their sum is equal to the target. Otherwise, we will return {-1, -1}.
vector<int> twoSumm(vector<int>& arr, int target){
    int n = arr.size();

    // Approach-2: Hashmap
    // Time Complexity: O(n*log n) - if we use ordered map and Space Complexity: O(n)
    // Time Complexity: O(n) - if we use unordered map, worst case O(n*n) and Space Complexity: O(n)
    map<int, int> mpp;
    for(int i = 0; i < n; i++){
        int num = arr[i];
        int required = target - num;
        if(mpp.find(required) != mpp.end()){
            return {mpp[required], i};
        }
        mpp[num] = i;
    }
    return {-1, -1};


    // Approach-1: picking an element and searching for another element that sums equal to target
    // Time Complexity: O(n*n) and Space Complexity: O(n)
    /*
    vector<int> ans;
    for(int i = 0; i < n; i++){
        for(int j = i+1; j < n; j++){
            if((arr[i] + arr[j]) == target){
                ans.push_back(i);
                ans.push_back(j);
                return ans;
            }
        }
    }
    return {-1, -1};
    */
}


// variant-1: Return true if there exist two numbers such that their sum is equal to the target. Otherwise, return false.
bool twoSum(vector<int>& arr, int target){
    int n = arr.size();

    // Approach-3: Greedy Approach
    // Time Complexity: O(n) + O(n*log n) and Space Complexity: O(1)
    sort(begin(arr), end(arr));

    int left = 0, right = n-1;
    while(left < right){
        if((arr[left] + arr[right]) < target) left++;
        else if((arr[left] + arr[right]) > target) right--;
        else return true;  
    }
    return false;

    // Approach-2: Hashmap
    // Time Complexity: O(n*log n) - if we use ordered map and Space Complexity: O(n)
    // Time Complexity: O(n) - if we use unordered map, worst case O(n*n) and Space Complexity: O(n)
    /*
    map<int, int> mpp;
    for(int i = 0; i < n; i++){
        int num = arr[i];
        int required = target - num;
        if(mpp.find(required) != mpp.end()){
            return true;
        }
        mpp[num] = i;
    }
    return false;
    */


    // Approach-1: picking an element and searchig for another element that sums equal to target
    // Time Complexity: O(n*n) and Space Complexity: O(1)
    /*
    for(int i = 0; i < n; i++){
        for(int j = i+1; j < n; j++){
            if((arr[i] + arr[j]) == target) return true;
        }
    }
    return false;
    */

}

int main(){
    vector<int> arr = {2, 6, 5, 8, 11};
    int target = 14;

    // variant-1
    //twoSum(arr, target);

    // variant-2
    vector<int> ans = twoSumm(arr, target);
    cout << ans[0] << " " << ans[1] << endl;
    
    return 0;
}