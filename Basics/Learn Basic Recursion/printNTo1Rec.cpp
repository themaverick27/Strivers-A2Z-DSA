/*
Problem Statement: Print numbers from N to 1 (space separated) without the help of loops.

Example 1:
Input: N = 10
Output: 10 9 8 7 6 5 4 3 2 1

Example 2:
Input: N = 5
Output: 5 4 3 2 1
*/
#include<bits/stdc++.h>
using namespace std;

// recursive approach
void printNumbers(int i, int n){
    if(i == 0) return;

    cout << i << endl;
    printNumbers(i-1, n);
}

int main(){
    int n;
    cout << "Enter n: ";
    cin >> n;

    printNumbers(n, n);

    return 0;
}
// Time Complexity: O(n)
// Space Complexity: O(n) - stack space