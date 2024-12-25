/*
Problem Statement: Given an array, print all the elements which are leaders. 

Note: A Leader is an element that is greater than all of the elements on its right side in the array.

Example 1:
Input: arr = [4, 7, 1, 0]
Output: 7 1 0
Explanation: Rightmost element is always a leader. 7 and 1 are greater than the elements in their right side.

Example 2:
Input: arr = [10, 22, 12, 3, 0, 6]
Output: 22 12 6
Explanation: 6 is a leader. In addition to that, 12 is greater than all the elements in its right side (3, 0, 6), also 22 is greater than 12, 3, 0, 6.
*/
#include<bits/stdc++.h>
using namespace std;

vector<int> arrayLeaders(vector<int>& arr){
    int n = arr.size();

    // Approach-2: start traversing from the end & move towards the left. Whenever we encounter a new element, we check with the greatest element obtained so far.
    // Time Complexity: O(n) and Space Complexity: O(1)
    vector<int> ans;
    ans.push_back(arr[n-1]);
    int maxx = arr[n-1];
    for(int i = n-2; i >= 0; i--){
        if(arr[i] < maxx) continue;
        else{
            ans.push_back(arr[i]);
            maxx = arr[i];
        }
    }
    // reverse(begin(ans), end(ans)); // depends how we want the ans (from the start or from the end leaders)
    return ans;


    // Approach-1: pick each element compare to the right values
    // Time Complexity: O(n*n) and Space Complexity: O(n) - for storing & returning the answer
    /*
    vector<int> ans;
    for(int i = 0; i < n; i++){
        int flag = 0;
        for(int j = i+1; j < n; j++){
            if(arr[i] < arr[j]){
                flag = 1;
                break;
            }
        }
        if(flag == 0) ans.push_back(arr[i]);
    }
    return ans;
    */

}

int main(){
    vector<int> arr = {10, 22, 12, 3, 0, 6};

    vector<int> ans = arrayLeaders(arr);
    // printing the ans
    for(int i = 0; i < ans.size(); i++){
        cout << ans[i] << " ";
    }

    return 0;
}