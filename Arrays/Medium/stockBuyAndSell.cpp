/*
Problem Statement: You are given an array of prices where prices[i] is the price of a given stock on an ith day.
You want to maximize your profit by choosing a single day to buy one stock and choosing a different day in the future to sell that stock. 
Return the maximum profit you can achieve from this transaction. If you cannot achieve any profit, return 0.

Note: That buying on day 2 and selling on day 1 is not allowed because you must buy before you sell.

Example 1:
Input: prices = [7,1,5,3,6,4]
Output: 5
Explanation: Buy on day 2 (price = 1) and sell on day 5 (price = 6), profit = 6-1 = 5.

Example 2:
Input: prices = [7,6,4,3,1]
Output: 0
Explanation: In this case, no transactions are done and the max profit = 0
*/
#include<bits/stdc++.h>
using namespace std;

int maxProfit(vector<int>& arr){
    int n = arr.size();

    // Approach-2: if you are selling on the ith day,then you buy on the minimum price from 1st to (i-1)th day.
    // Time Complexity: O(n) and Space Complexity: O(1)
    int maxProfit = 0;
    int minPrice = arr[0];
    for(int i = 1; i < n; i++){
        int cost = arr[i] - minPrice;
        maxProfit = max(maxProfit, cost);
        // keeping the track of the minimum of the left side
        minPrice = min(minPrice, arr[i]);
    }
    return maxProfit;


    // Appraoch-1: track every transaction & maintain a variable maxProfit to store the max value among all transactions
    // Time Complexity: O(n*n) approx and Space Complexity: O(1)
    /*
    int profit = 0;
    int maxProfit = 0;
    for(int i = 0; i < n; i++){
        for(int j = i+1; j < n; j++){
            if(arr[j] > arr[i]){
                profit = arr[j] - arr[i];
            }
            maxProfit = max(maxProfit, profit);
        }
    }
    return maxProfit;
    */
}

int main(){
    vector<int> arr = {7, 1, 5, 3, 6, 4};

    int ans = maxProfit(arr);
    cout << ans << endl;
    
    return 0;
}