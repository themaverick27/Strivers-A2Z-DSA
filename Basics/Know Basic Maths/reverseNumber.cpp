/*
Problem Statement: Given a signed 32-bit integer x, return x with its digits reversed. 
If reversing x causes the value to go outside the signed 32-bit integer range [-2^31, 2^31 - 1], then return 0.

Note: Assume the environment does not allow you to store 64-bit integers (signed or unsigned).

Example 1:
Input: x = 123
Output: 321

Example 2:
Input: x = -123
Output: -321

Example 3:
Input: x = 120
Output: 21
*/

#include<bits/stdc++.h>
using namespace std;

int reverseNumber(int n){

    // Approach-1: extract digit concept
    // Time Complexity: O(log10(n) + 1) and Space Complexity: O(1)
    int rev = 0;
    while(n != 0){
        int digit = n % 10;
        // Checking for overflow/underflow before updating rev 
        if((rev > INT_MAX/10) || (rev < INT_MIN/10)) return 0;
        rev = (rev * 10) + digit;
        n = n / 10;
    }
    return rev;
}

int main(){
    int n;
    cin >> n;

    int rev = reverseNumber(n);
    cout << rev << endl;

    return 0;
}