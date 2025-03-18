/*
Problem Statement: Given an integer N, return all divisors of N.
A divisor of an integer N is a positive integer that divides N without leaving a remainder.

Example 1:
Input: N = 36
Output: [1, 2, 3, 4, 6, 9, 12, 18, 36]

Example 2:
Input: N =12
Output: [1, 2, 3, 4, 6, 12]
*/

#include<bits/stdc++.h>
using namespace std;

void printFactors(int n){

    // Approach-2: factors in sqrt(n) time
    // Time Complexity: O(sqrt(n)) and Space Complexity: O(1)
    for(int i = 1; i*i <= n; i++){
        if(n % i == 0){
            cout << i << " ";
            if((n/i) != i){
                cout << (n/i) << " ";
            }
        }
    }
    

    // Approach-1: iterating 1 to n
    // Time Complexity: O(n) and Space Complexity: O(1)
    /*
    for(int i = 1; i <= n; i++){
        if(n % i == 0){
            cout << i << " ";
        }
    }
    */
}

int main(){
    int n;
    cin >> n;

    printFactors(n);

    return 0;
}