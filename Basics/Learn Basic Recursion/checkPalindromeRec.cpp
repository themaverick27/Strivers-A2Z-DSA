/*
Problem Statement: Given a string, check if the string is palindrome or not.
A string is said to be palindrome if the reverse of the string is the same as the string.

Example 1:
Input: “ABCDCBA”
Output: Palindrome
Explanation: String when reversed is the same as string.

Example 2:
Input: “LAPTOP”
Output: Not Palindrome
Explanation: String when reversed is not the same as string.
*/
#include<bits/stdc++.h>
using namespace std;

// recursive approach
bool checkPalindrome(string& str, int i, int n){
    if(i >= (n/2)) {
        return true;
    }

    // not same char, not a palindrome string
    if(str[i] != str[n-i-1]){
        return false;
    }
    return checkPalindrome(str, i+1, n);
}


int main(){
    string s = "madam";
    
    if(checkPalindrome(s, 0, s.size())){
        cout << "Palindrome" << endl;
    }
    else cout << "Not Palindrome" << endl;
    
    return 0;
}
// Time Complexity: O(n/2) precisely
// Space Complexity: O(n) - stack space