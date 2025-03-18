/*
Problem Statement: Given an integer N, return the number of digits in N.

Example 1:
Input: N = 12345
Output: 5

Example 2:
Input: N = 7789
Output: 4
*/

#include<bits/stdc++.h>
using namespace std;

int countDigits(int n){

    // Approach2: The logarithmic base 10 of a positive integers gives the number of digits in n.
    // Time Complexity: O(1) and Space Complexity: O(1)
    int cnt = (int) (log10(n) + 1);
    return cnt;

    
    // Approach-1: extract digit concept
    // Time Complexity: O(log10(n)+1) and Space Complexity: O(1)
    /*
    int count = 0;
    while(n != 0){
        count += 1;
        n = n / 10;
    }
    return count;
    */
}

int main(){
    int n;
    cin >> n;

    int digits = countDigits(n);
    cout << digits << endl;

    return 0;
}