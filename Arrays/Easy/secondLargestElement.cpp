/*
Problem Statement: Given an array, find the second smallest and second largest element in the array. Print ‘-1’ in the event that either of them doesn’t exist.

Example 1:
Input: [1,2,4,7,7,5]
Output: Second Smallest: 2 Second Largest: 5
Explanation: The elements are as follows 1,2,3,5,7,7 and hence second largest of these is 5 and second smallest is 2.

Example 2:
Input: [1]
Output: Second Smallest: -1 Second Largest: -1
Explanation: Since there is only one element in the array, it is the largest and smallest element present in the array. There is no second largest or second smallest element present.
*/

#include<bits/stdc++.h>
using namespace std;

int secondSmallestElement(vector<int>& arr){
    int n = arr.size();

    // Approach-2: using smallest and sSmallest varibles & single loop
    // Time Complexity: O(n) and Space Complexity: O(1)
    if(n < 2) return -1;

    int smallest = INT_MAX;
    int sSmallest = INT_MAX;

    for(int i = 0; i < n; i++){
        if(arr[i] < smallest){
            sSmallest = smallest;
            smallest = arr[i];
        }
        else if(arr[i] < sSmallest && arr[i] != smallest) sSmallest = arr[i];
    }
    return sSmallest;

    // Approach-1 using sorting and traversing
    // Time Complexity: O(n*log n))+ O(n) and Space Complexity: O(1)
    /*
    if(n < 2) return -1;

    sort(arr, arr+n);

    int smallest = arr[0];
    int sSmallest = INT_MAX;
    for(int i = 1; i < n; i++){
        if(arr[i] != smallest){
            sSmallest = arr[i];
            return sSmallest;
        }
    }
    return -1;
    */
}

int secondLargestElement(vector<int>& arr){
    int n = arr.size();

    // Approach-2: using largest and slargest varibles & single loop
    // Time Complexity: O(n) and Space Complexity: O(1)
    int largest = -1;
    int slargest = -1; 
    for(int i = 0; i < n; i++){
        if(arr[i] > largest){
            slargest = largest;
            largest = arr[i];
        }
        else if(arr[i] > slargest && arr[i] != largest){
            slargest = arr[i];
        }
    }
    return slargest;

    // Approach-1: using Sorting
    // Time Complexity: O(n*log n) + O(n) and Space Complexity: O(n)
    /*
    sort(begin(arr), end(arr));

    int largest = arr[n-1];
    for(int i = n-1; i >= 0; i--){
        if(arr[i] != largest) return arr[i];
    }
    return -1;
    */

   // Approach-2: using largest and slargest variables
   // Time Complexity: O(2*n) and Space Complexity: O(1)
   /*
   int largest = -1;
   int slargest = -1;
   // finding the largest element
   for(int i = 0; i < n; i++){
        if(arr[i] > largest) largest = arr[i];
   } 
    // finding the second largest element
   for(int i = 0; i < n; i++){
        if(arr[i] > slargest && arr[i] != largest){
            slargest = arr[i];
        }
   }
   return slargest;
   */

}

int main(){
    vector<int> arr = {1, 2, 4, 7, 7, 5};
    int sLargest = secondLargestElement(arr);
    cout << "Second Largest Element: " << sLargest << endl;

    int sSmallest = secondSmallestElement(arr);
    cout << "Second Smallest Element: " << sSmallest << endl;

    return 0;
}