/*
Problem Statement: Given two integers N1 and N2, find their greatest common divisor (GCD or HCF).

GCD: The Greatest Common Divisor of any two integers is the largest number that divides both integers.

Example 1:
Input: N1 = 9, N2 = 12            
Output: 3
Explanation: factors of 9: 1, 3, 9 and factors of 12: 1, 2, 3, 4, 6, 12
Common Factors: 1, 3 out of which 3 is the greatest hence it is the GCD.

Example 2:
Input: N1 = 20, N2 = 15                
Output: 5
Explanation: factors of 20: 1, 2, 4, 5 and factors of 15: 1, 3, 5
Common Factors: 1, 5 out of which 5 is the greatest hence it is the GCD.
*/

#include<bits/stdc++.h>
using namespace std;

int gcd(int n1, int n2){

    // Approach-2: Eculidean Algorithm
    // Time Complexity: O(logX(min(n1, n2))) and Space Complexity: O(1)
    int ans = 1;
    while(n1 > 0 && n2 > 0){
        if(n1 > n2) n1 = n1 % n2;
        else n2 = n2 % n1;
    }

    if(n1 == 0) return n2;
    return n1;


    // Approach-1: 
    // Time Complexity: O(min(n1, n2)) and Space Complexity: O(1)
    /*
    int ans = 1;
    for(int i = 1; i <= min(n1, n2); i++){
        if(n1 % i == 0 && n2 % i == 0){
            ans = i;
        }
    }
    return ans;
    **/
}


int main(){
    int num1, num2;
    cin >> num1 >> num2;

    int ans = gcd(num1, num2);
    cout << ans << endl;

    return 0;
}