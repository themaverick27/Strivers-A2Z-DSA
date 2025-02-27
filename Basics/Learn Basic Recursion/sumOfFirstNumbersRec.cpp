/*
Problem statement: Given a number N, find out the sum of the first N natural numbers.

Example 1:
Input: N = 5
Output: 15
Explanation: 1+2+3+4+5=15

Example 2:
Input: N = 6
Output: 21
Explanation: 1+2+3+4+5+6=15
*/
#include<bits/stdc++.h>
using namespace std;

// recursive approach - parameterised 
int sumNaturalNumbers(int sum, int i){
    if(i < 1) return sum;

    sumNaturalNumbers(sum + i, i-1);
}

// recursive approach - functional 
int sumFirstNaturalNumbers(int n){
    if(n == 1) return 1;

    return n + sumFirstNaturalNumbers(n-1);
}


int main(){
    int n;
    cout << "Enter n: ";
    cin >> n;

    int total = sumNaturalNumbers(0, n); // parameterised
    cout << total << endl;
    
    /*
    int total = sumFirstNaturalNumbers(n); // functional
    cout << total << endl;
    */

    return 0;
}
// Time Complexity: O(n)
// Space Complexity: O(n) - stack space