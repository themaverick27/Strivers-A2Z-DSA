/*
Problem Statement: Print name n times without using loops.

Example 1:
Input: 5
Output: GFG GFG GFG GFG GFG 

Example 2:
Input: 3
Output: GFG GFG GFG
*/
#include<bits/stdc++.h>
using namespace std;

// recursive appraoch
void printName(int cnt, int n){
    if(cnt > n) return;

    cout << "GFG" << endl;
    printName(cnt+1, n);
}

int main(){
    int n;
    cout << "Enter times (n): ";
    cin >> n;

    printName(1, n);

    return 0;
}
// Time Complexity: O(n)
// Space Complexity: O(n) - stack space 