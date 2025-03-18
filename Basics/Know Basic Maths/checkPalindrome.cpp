/*
Problem Statement: Given an integer x, return true if x is a palindrome, and false otherwise.

Example 1:
Input: x = 121
Output: true

Example 2:
Input: x = -121
Output: false
Explanation: From left to right, it reads -121. From right to left, it becomes 121-. Therefore it is not a palindrome.

Example 3:
Input: x = 10
Output: false
Explanation: Reads 01 from right to left. Therefore it is not a palindrome.
*/

#include<bits/stdc++.h>
using namespace std;

bool checkPalindrome(int n){
    // Approach-1: extracting digits concept
    // Time Complexity: O(log10(n) + 1) and Space Complexity: O(1)
    if(n < 0 || (n != 0 && n % 10 == 0)) return false;

    int copy = n;
    int rev = 0;
    while(n != 0){
        rev = (rev * 10) + (n % 10);
        n = n / 10;
    }

    return (copy == rev);

}

int main(){
    int n;
    cin >> n;

    if(checkPalindrome(n))
        cout << "Palindrome" << endl;
    else 
        cout << "Not Palindrome" << endl;

    return 0;
}