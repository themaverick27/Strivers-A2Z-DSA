/*
Problem Statement: Given a number X, print its factorial. To obtain the factorial of a number, 
it has to be multiplied by all the whole numbers preceding it. More precisely X! = X*(X-1)*(X-2) … 1.

Note: X is always a positive number. 

Example 1:
Input: X = 5
Output: 120
Explanation: 5! = 5*4*3*2*1

Example 2:
Input: X = 3
Output: 6
Explanation: 3!=3*2*1
*/
#include<bits/stdc++.h>
using namespace std;

// recursive appraoch - parameterised
int factorial(int total, int n){
    if(n == 1) return total;

    factorial(total * n, n-1);
}

// recursive appraoch - functional
int fact(int n){
    if(n == 1) return 1;

    return n * fact(n-1);
}

int main(){
    int n;
    cout << "Enter n: ";
    cin >> n;

    int ans = factorial(1, n); // parameterised
    cout << ans << endl;

    /*
    int ans = fact(n); // functional
    cout << ans << endl;
    */
}
// Time Complexity: O(n)
// Space Complexity: O(n) - stack space