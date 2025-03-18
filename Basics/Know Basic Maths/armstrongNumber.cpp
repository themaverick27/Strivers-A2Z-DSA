/*
Problem Statement: Given an integer N, return true it is an Armstrong number otherwise return false.

Armstrong Number: An Amrstrong number is a number that is equal to the sum of its own digits each raised to the power of the number of digits.

Example 1:
Input: N = 153
Output: True
Explanation: 13+53+33 = 1 + 125 + 27 = 153

Example 2:
Input: N = 371
Output: True
Explanation: 33+53+13 = 27 + 343 + 1 = 371
*/

#include<bits/stdc++.h>
using namespace std;

bool armstrongNumber(int n){

    // Approach-1: extract digit concept
    // Time Complexity: O(log10(n) + 1) and Space Complexity: O(1)
    int totalDigits = (int) (log10(n) + 1);
    cout << totalDigits << " ";

    int dup = n;
    int sum = 0;
    while(n != 0){
        int digit = n % 10;
        sum += pow(digit, totalDigits);
        n = n / 10;
    }

    return (sum == dup);
}

int main(){
    int n;
    cin >> n;

    if(armstrongNumber(n))
        cout << "Armstrong Number" << endl;
    else
        cout << "Not Armstrong Number" << endl;

    return 0;
}