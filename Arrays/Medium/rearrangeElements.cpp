/*
Variety-1
Problem Statement: There’s an array ‘A’ of size ‘N’ with an equal number of positive and negative elements. Without altering the relative order of positive and negative elements, you must return an array of alternately positive and negative values.

Variety-2
Problem Statement: There’s an array ‘A’ of size ‘N’ with positive and negative elements (not necessarily equal). Without altering the relative order of positive and negative elements, you must return an array of alternately positive and negative values. The leftover elements should be placed at the very end in the same order as in array A.

Note: Start the array with positive elements.

Example 1:
Input: arr[] = {1,2,-4,-5}, N = 4
Output: 1 -4 2 -5
Explanation:  Positive elements = 1,2 and Negative elements = -4,-5
To maintain relative ordering, 1 must occur before 2, and -4 must occur before -5.

Example 2:
Input: arr[] = {1,2,-3,-1,-2, 3}, N = 6
Output: 1 -3 2 -1 3 -2
Explanation:  Positive elements = 1,2,3 and Negative elements = -3,-1,-2
To maintain relative ordering, 1 must occur before 2, and 2 must occur before 3. Also, -3 should come before -1, and -1 should come before -2.
*/
#include<bits/stdc++.h>
using namespace std;

// variant-2: not equal number of positive and negative elements
vector<int> rearrangeElements2(vector<int>& arr){
    int n = arr.size();

    // Approach-1: storing the positive and negative elements separately in a array, and then putting back it to original array.
    // Time Complexity: O(n) + O(n) and Space Complexity: O(n)
    vector<int> pos;
    vector<int> neg;

    for(int i = 0; i < n; i++){
        if(arr[i] >= 0) pos.push_back(arr[i]);
        else neg.push_back(arr[i]);
    }

    // if the number of positives are more than negatives
    if(pos.size() > neg.size()){
        // store elements alternatively till the number of positives and negatives are equal
        for(int i = 0; i < neg.size(); i++){
            arr[2*i] = pos[i];
            arr[2* + 1] = neg[i];
        }
        // remaining extra positives 
        int index = neg.size()*2;
        for(int i = neg.size(); i < pos.size(); i++){
            arr[index] = pos[i];
            index++;
        }
    }
    else{
        // if the number of negatives are more than positives
        // store elements alternatively till the number of positives and negatives are equal
        for(int i = 0; i < pos.size(); i++){
            arr[2*i] = pos[i];
            arr[2*i + 1] = neg[i];
        }
        // remaining extra negatives
        int index = pos.size()*2;
        for(int i = pos.size(); i < neg.size(); i++){
            arr[index] = neg[i];
            index++;
        }
    }
    return arr;

}

// variant-1: equal number of positive and negative elements
vector<int> rearrangeElements(vector<int>& arr){
    int n = arr.size();

    // Approach-2: start traversing the array such that whenever we see the first positive element, it occupies the space at 0 and then posIndex increases by 2 (alternate places), and similarly for negative index.
    // Time Complexity: O(n) and Space Complexity: O(n)
    vector<int> ans(n,0);

    int posIndex = 0, negIndex = 1;
    for(int i = 0; i < n; i++){
        if(arr[i] >= 0){
            ans[posIndex] = arr[i];
            posIndex += 2;
        }
        else{
            ans[negIndex] = arr[i];
            negIndex += 2;
        }
    }
    return ans;
    

    // Approach-1: storing the positive and negative elements separately in a array, and then putting back it to original array
    // Time Complexity: O(n) + O(n/2) and Space Complexity: O(n)
    /*
    vector<int> pos;
    vector<int> neg;

    for(int i = 0; i < n; i++){
        if(arr[i] >= 0) pos.push_back(arr[i]);
        else neg.push_back(arr[i]);
    }

    for(int i = 0; i < n/2; i++){
        arr[2*i] = pos[i];
        arr[2*i + 1] = neg[i]; 
    }
    return arr;
    */

}

int main(){
    vector<int> arr = {9, 4, -2, -1, 5, -5, -3, 2};

    vector<int> ans = rearrangeElements(arr);
    // printing the ans
    for(int i = 0; i < ans.size(); i++){
        cout << ans[i] << " ";
    }

    return 0;
}