/*
Problem Statement: Given an integer N, check whether it is prime or not. 
A prime number is a number that is only divisible by 1 and itself and the total number of factors is 2.

Example 1:
Input: N = 2
Output: Prime Number

Example 2:
Input: N =10
Output: Not a Prime Number
*/

#include<bits/stdc++.h>
using namespace std;

bool checkPrime(int n){
    // Approach-2: finding factors in O(sqrt(n)) time
    // Time Complexity: O(sqrt(n)) and Space Complexity: O(1)
    if(n <= 1) return false; 

    int cnt = 0;
    for(int i = 1; i*i <= n; i++){
        if(n % i == 0){
            cnt += 1;
            if((n/i) != i) cnt += 1;
        }
    }
    return (cnt == 2);


    // Approach-1: 
    // Time Complexity: O(n) and Space Complexity: O(1)
    /*
    if(n <= 1) return false;

    for(int i = 2; i < n; i++){
        if(n % i == 0) return false;
    }
    return true;
    */
}

int main(){
    int n;
    cin >> n;

    if(checkPrime(n))
        cout << "Prime Number" << endl;
    else 
        cout << "Not a Prime Number" << endl;
    
        return 0;
}