/*
Problem Statement: You are given a sorted array containing N integers and a number X, 
you have to find the occurrences of X in the given array.

Example 1:
Input: N = 7,  X = 3 , array[] = {2, 2 , 3 , 3 , 3 , 3 , 4}
Output: 4
Explanation: 3 is occurring 4 times in the given array so it is our answer.

Example 2:
Input: N = 8,  X = 2 , array[] = {1, 1, 2, 2, 2, 2, 2, 3}
Output: 5
Explanation: 2 is occurring 5 times in the given array so it is our answer.
*/
#include<bits/stdc++.h>
using namespace std;

int findFirstOccurrence(vector<int>& arr, int x){
    int n = arr.size();
    
    int low = 0, high = n-1;
    int ans = -1;
    while(low <= high){
        int mid = low + (high - low)/2;

        if(arr[mid] == x){
            ans = mid;
            high = mid - 1;
        }
        else if(arr[mid] > x) high = mid - 1;
        else low = mid + 1;
    }
    return ans;
}

int findLastOccurrence(vector<int>& arr, int x){
    int n = arr.size();
    
    int low = 0, high = n-1;
    int ans = -1;
    while(low <= high){
        int mid = low + (high-low)/2;

        if(arr[mid] == x){
            ans = mid;
            low = mid + 1;
        }
        else if(arr[mid] > x) high = mid - 1;
        else low = mid + 1;
    }
    return ans;
}

int countOccurrences(vector<int>& arr, int x){
    int first = findFirstOccurrence(arr, x);

    if(first == -1) return 0; // element x doesn't exists, occurrence 0.

    int last = findLastOccurrence(arr, x);

    int count = last - first + 1;
    return count;
}

int main(){
    vector<int> arr = {2, 2, 3, 3, 3, 3, 4};
    int x = 3;

    int freq = countOccurrences(arr, x);
    cout << freq << endl;

    return 0;
}