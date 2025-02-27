/*
Problem Statement: Print 1 To N Without Loop. Print numbers from 1 to n without the help of loops.

Example 1:
Input: n = 10
Output: 1 2 3 4 5 6 7 8 9 10

Example 2:
Input: n = 5
Output: 1 2 3 4 5
*/
#include<bits/stdc++.h>
using namespace std;

// recursive approach
void printNumbers(int i, int n){
    if(i > n) return;

    cout << i << endl;
    printNumbers(i+1, n);
}

int main(){
    int n;
    cout << "Enter n: ";
    cin >> n;

    printNumbers(1, n);

    return 0;
}
// Time Complexity: O(n)
// Space Complexity: O(n) - stack space