/*
Problem Statement: Given an integer N. Print the Fibonacci series up to the Nth term.

Example 1:
Input: N = 5
Output: 0 1 1 2 3 5
Explanation: 0 1 1 2 3 5 is the fibonacci series up to 5th term.(0 based indexing)

Example 2:
Input: 6
Output: 0 1 1 2 3 5 8
Explanation: 0 1 1 2 3 5 8 is the fibonacci series upto 6th term.(o based indexing)
*/

#include<bits/stdc++.h>
using namespace std;

// recursive approach
int fibo(int n){
    if(n == 0 || n == 1) return n;

    return fibo(n-1) + fibo(n-2);
}

int main(){
    int n;
    cout << "Enter N: ";
    cin >> n;

    cout << fibo(n);
}
// Time Complexity: O(2^n) approx 
// Space Complexity: O(n) - stack space